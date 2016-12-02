package org.lastools;

import java.io.Closeable;

public abstract class NativeObject implements Closeable {
	/**
	 * Native pointer. Depending on the type, this will either be a pointer
	 * directly to the object or a smart pointer.
	 */
	long ptr;

	NativeObject() {
		LASlibJNI.incrementAlloc(getClass(), 1);
	}

	/**
	 * Manually disposes of the native resources associated with this object
	 * (versus waiting for finalization).
	 */
	public final void close() {
		if (ptr != 0) {
			long ptrLocal = ptr;
			ptr = 0;
			dealloc(ptrLocal);
			LASlibJNI.incrementAlloc(getClass(), -1);
		}
	}

	/**
	 * @deprecated Implementation moved to close() for try-with-resources
	 *             compatibility
	 */
	@Deprecated
	public final void dispose() {
		close();
	}

	/**
	 * @return true if the native resources associated with this object have
	 *         been destroyed
	 */
	public final boolean isDisposed() {
		return ptr == 0;
	}

	@Override
	protected final void finalize() throws Throwable {
		super.finalize();
		close();
	}

	/**
	 * Called on finalize and dispose to dealloc the pointer if != 0
	 * 
	 * @param ptr
	 */
	abstract void dealloc(long ptr);
}