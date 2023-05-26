#ifndef CATJNIUtilities_h
#define CATJNIUtilities_h

// COPYRIGHT DASSAULT SYSTEMES 2001

// CATJavaBridge framework
#include "CATJNIBridge.h"
#include "CATjni.h"

// AutomationInterfaces framework
#include "CATScriptError.h"

/**
 * A set of utility functions relative to JNI.
 * @author: David Morisot (DMO)
 */
class ExportedByCATJNIBridge CATJNIUtilities {
	public:
  
		/**
		 * Calls the java garbage collector.
		 */
		static HRESULT CallGarbageCollector(
			JNIEnv *env);

		/**
		 * Clears the potential pending JNI exception.
		 * This prevents the JVM from being in an unstable state.
		 */
		static HRESULT ClearPendingException(
			JNIEnv *env);

		/**
		 * Checks for potential pending JNI exception and creates a CATScriptError if one exists.
		 * Returns E_FAIL if no error has been created.
		 */
		static HRESULT CheckError(
			JNIEnv *env, 
			CATScriptError *& oError);

		/**
		 * Creates a CATScriptError from the given JNI exception.
		 * Returns E_FAIL if no error has been created.
		 */
		static HRESULT CreateErrorFromException(
			JNIEnv *env, 
			jthrowable jniExc, 
			CATScriptError *& oError);

#ifdef _WINDOWS_SOURCE
		/**
		 * Redirects the java output to fix a bug with JNI on Windows to 
		 * make the System.out and System.err print correctly on the console.
		 */
		static HRESULT RedirectJavaOutput(JNIEnv *env);
#endif // _WINDOWS_SOURCE

};

#endif // CATJNIUtilities_h

