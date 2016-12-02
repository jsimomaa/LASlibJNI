/*
 * globals.c
 *
 *  Created on: Dec 1, 2016
 *      Author: jani
 */

//// -- Globals

static bool initialized = false;
static jclass
	CLASS_NATIVEOBJECT,
	CLASS_LASREADER,
	CLASS_LASHEADER,
	CLASS_LASPOINT;
static jclass
	CLASS_STRING,
	CLASS_DOUBLE,
	CLASS_INTEGER,
	CLASS_BOOLEAN,
	CLASS_LONG,
	CLASS_HASHSET;
static jmethodID
	CTOR_NATIVEOBJECT,
	CTOR_PARAMETERS,
	METHOD_DOUBLE_VALUEOF,
	METHOD_INTEGER_VALUEOF,
	METHOD_BOOLEAN_VALUEOF,
	METHOD_LONG_VALUEOF,
	CTOR_HASHSET,
	METHOD_HASHSET_ADD;
static jfieldID
	FIELD_PTR;
//	FIELD_BOX2D_MINX,
//	FIELD_BOX2D_MINY,
//	FIELD_BOX2D_MAXX,
//	FIELD_BOX2D_MAXY;


void throw_error(JNIEnv* env, const char* msg) {
	jclass clazz=env->FindClass("java/lang/Error");
	env->ThrowNew(clazz, msg);
}

void throw_runtime_exception(JNIEnv* env, const char* msg) {
	jclass clazz=env->FindClass("java/lang/RuntimeException");
	env->ThrowNew(clazz, msg);
}

void throw_java_exception(JNIEnv* env, std::exception& e) {
	jclass clazz=env->FindClass("java/lang/RuntimeException");
	env->ThrowNew(clazz, e.what());
}

#define ASSERT_INITIALIZED if (!initialized) throw_error(env, "Library not initialized")
#define TO_POINTER(ptr) ((void*)ptr)
#define FROM_POINTER(ptr) ((jlong)ptr)

inline static jlong ASSERT_LONG_POINTER(jlong ptr) {
	if (!ptr) {
		throw std::runtime_error("Object is no longer valid");
	}
	return ptr;
}

// Exception handling
#define PREAMBLE try {
#define TRAILER(v) } catch (std::exception& e) { throw_java_exception(env, e); return v;}
#define TRAILER_VOID } catch (std::exception& e) { throw_java_exception(env, e); return; }

// Pointer access macros
#define LOAD_OBJECT_POINTER(object) ((void*)(ASSERT_LONG_POINTER(env->GetLongField(object, FIELD_PTR))))
#define LOAD_LASREADER_POINTER(object) (static_cast<LASreader*>(LOAD_OBJECT_POINTER(object)))
#define LOAD_LASHEADER_POINTER(object) (static_cast<LASheader*>(LOAD_OBJECT_POINTER(object)))
#define LOAD_LASPOINT_POINTER(object) (static_cast<LASpoint*>(LOAD_OBJECT_POINTER(object)))


static void init_class(JNIEnv* env, const char* name, jclass& classref) {
	classref=(jclass)env->NewGlobalRef(env->FindClass(name));
	if (!classref) {
		std::string message("Unable to initialize class: ");
		throw std::runtime_error(message + name);
	}
}

static jfieldID lookup_field(JNIEnv* env, jclass c, const char* name, const char* sig)
{
	jfieldID ret=env->GetFieldID(c, name, sig);
	if (!ret) {
		std::string message("Unable to find field: ");
		throw std::runtime_error(message + name + ", Signature: " + sig);
	}
	return ret;
}

static jmethodID lookup_method(JNIEnv* env, jclass c, const char* name, const char* sig)
{
	jmethodID ret=env->GetMethodID(c, name, sig);
	if (!ret) {
		std::string message("Unable to find method: ");
		throw std::runtime_error(message + name + ", Signature: " + sig);
	}
	return ret;
}

static jmethodID lookup_static_method(JNIEnv* env, jclass c, const char* name, const char* sig)
{
	jmethodID ret=env->GetStaticMethodID(c, name, sig);
	if (!ret) {
		std::string message("Unable to find method: ");
		throw std::runtime_error(message + name + ", Signature: " + sig);
	}
	return ret;
}

static bool init_ids(JNIEnv* env) {
	// Load NativeObject classes
	init_class(env, "org/lastools/NativeObject", CLASS_NATIVEOBJECT);
	init_class(env, "org/lastools/LASReader", CLASS_LASREADER);
	init_class(env, "org/lastools/LASHeader", CLASS_LASHEADER);
	init_class(env, "org/lastools/LASPoint", CLASS_LASPOINT);

	// Ptr
	CTOR_NATIVEOBJECT=lookup_method(env, CLASS_NATIVEOBJECT, "<init>", "()V");
	FIELD_PTR=lookup_field(env, CLASS_NATIVEOBJECT, "ptr", "J");

	// String
	init_class(env, "java/lang/String", CLASS_STRING);

	// Integer
	init_class(env, "java/lang/Integer", CLASS_INTEGER);
	METHOD_INTEGER_VALUEOF=lookup_static_method(env, CLASS_INTEGER, "valueOf", "(I)Ljava/lang/Integer;");

	init_class(env, "java/lang/Boolean", CLASS_BOOLEAN);
	METHOD_BOOLEAN_VALUEOF=lookup_static_method(env, CLASS_BOOLEAN, "valueOf", "(Z)Ljava/lang/Boolean;");

	init_class(env, "java/lang/Long", CLASS_LONG);
	METHOD_LONG_VALUEOF=lookup_static_method(env, CLASS_LONG, "valueOf", "(J)Ljava/lang/Long;");

	// Double
	init_class(env, "java/lang/Double", CLASS_DOUBLE);
	METHOD_DOUBLE_VALUEOF=lookup_static_method(env, CLASS_DOUBLE, "valueOf", "(D)Ljava/lang/Double;");

	// HashSet
	init_class(env, "java/util/HashSet", CLASS_HASHSET);
	CTOR_HASHSET=lookup_method(env, CLASS_HASHSET, "<init>", "()V");
	METHOD_HASHSET_ADD=lookup_method(env, CLASS_HASHSET, "add", "(Ljava/lang/Object;)Z");

	// Box2d
//	init_class(env, "mapnik/Box2d", CLASS_BOX2D);
//	FIELD_BOX2D_MINX=lookup_field(env, CLASS_BOX2D, "minx", "D");
//	FIELD_BOX2D_MINY=lookup_field(env, CLASS_BOX2D, "miny", "D");
//	FIELD_BOX2D_MAXX=lookup_field(env, CLASS_BOX2D, "maxx", "D");
//	FIELD_BOX2D_MAXY=lookup_field(env, CLASS_BOX2D, "maxy", "D");

	return true;
}

class refjavastring {
	JNIEnv* env;
	jstring js;
	jboolean isCopy;
public:
	const char* stringz;
	bool isnull;

	refjavastring(JNIEnv* env, jstring js) {
		this->env=env;
		this->js=js;
		if (js) {
			stringz=env->GetStringUTFChars(js, &isCopy);
			isnull=false;
		} else {
			stringz="";
			isnull=true;
			isCopy=0;
		}
	}
	~refjavastring() {
		if (isCopy) {
			env->ReleaseStringUTFChars(js, stringz);
		}
	}
};


