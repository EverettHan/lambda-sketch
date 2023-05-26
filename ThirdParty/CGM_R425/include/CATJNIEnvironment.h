#ifndef CATJNIEnvironment_h
#define CATJNIEnvironment_h

// CATJavaBridge framework
#include "CATJNIBridge.h"
#include "CATjni.h"
#include "CATListOfCATJavaVMOption.h"

// System framework
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATBoolean.h"

/**
 * Class to access and position various environment variables.
 * @author David Morisot (DMO)
 */
class ExportedByCATJNIBridge CATJNIEnvironment {
	public:

		/**
		 * Checks for the presence of a correct installed Jdk and jre 
		 * in the specified directory path.
		 * Retrieves the OS-specific jvm shared library path.
		 * Returns S_OK if a correct Jdk + jre is installed, E_FAIL otherwise.
		 */
		static HRESULT CheckInstalledJdk(const CATUnicodeString& iPath, CATBoolean iNeedFullBlownJdk, CATUnicodeString& oJvmPath);

		// Creating VMs

		/**
		 * Creates a new JVM, with the specified options or the default options
		 * obtained by calling GetDefaultJVMOptions if no options are specified.
		 * Because of JNI restrictions, only one JVM is allowed per process.
		 * @param oJNIEnv
		 * The JVM Java environment pointer
		 * @param iJdkPath
		 * The path to use for the Jdk, equivalent to the JAVA_HOME variable (must be valid)
		 * @param iOptions
		 * The options to use to create the JVM
		 * @param iInitThreadDispatcher
		 * TRUE if the thread dispatcher must be initialized now, FALSE otherwise.
		 * The thread dispatcher is used to run a CATJNICallback in the application's main thread.
		 * @param iNeedFullBlownJdk
		 * TRUE if a full blown JDK with javac is required, FALSE if a JRE is sufficient.
		 */
		static HRESULT CreateJNIEnv(
			JNIEnv*& oJNIEnv,
			JavaVM*& oJavaVM,
			const CATUnicodeString& iJdkPath,
			const CATListOfCATJavaVMOption& iOptions = CATListOfCATJavaVMOption(),
			CATBoolean iInitThreadDispatcher = FALSE,
			CATBoolean iNeedFullBlownJdk = FALSE);

		/**
		 * Retrieves the current JVM, or creates one by calling CreateJNIEnv if
		 * no JVM has been created yet. If the JVM is created, the options used
		 * for creation are obtained by calling GetDefaultJVMOptions.
		 * The same JVM is returned every time. The JVM used is the one obtained 
		 * by calling GetJdkPath().
		 * If the JVM is already created, but the calling thread is not attached
		 * to it, AttachCurrentThread is called.
		 * @param oJNIEnv
		 * The JVM Java environment pointer
		 */
		static HRESULT GetJNIEnv(
			JNIEnv** oJNIEnv);

		/**
		 * Returns TRUE if a JVM is running, FALSE otherwise.
		 * If a JVM is running, this method retrieves the used Jdk path.
		 */
		static CATBoolean JvmIsRunning(CATUnicodeString& oJdkPath);

		/**
		 * Returns TRUE if a JVM is running, FALSE otherwise.
		 */
		static CATBoolean JvmIsRunning();

		/**
		 * Returns the Jdk path used to create JVMs, or an empty string if no
		 * JVM has been created yet.
		 */
		static CATUnicodeString GetUsedJdkPath();


		// Managing JVM options

		/**
		 * Retrieves the default options used to create a JVM.
		 * @param oOptions
		 * the default options used to create a JVM.
		 */
		static HRESULT GetDefaultJVMOptions(
			CATListOfCATJavaVMOption& oOptions);

		/**
		 * Retrieves an option by its name in a list of Java VM options. The option
		 * is considered to match if the passed option name is contained in the
		 * CATJavaVMOption.optionString field.
		 * @param iOptions
		 * the option list
		 * @param iOptionName
		 * the name of the option to retrieve.
		 * @param oOption
		 * the option value.
		 */
		static HRESULT FindJavaVMOption(
			const CATListOfCATJavaVMOption& iOptions,
			const CATUnicodeString& iOptionName,
			CATJavaVMOption& oOption);

		/**
		 * Removes an option from a list of Java VM options. The method will
		 * fail if the option is not actually in the list.
		 * @param iOptions
		 * the option list
		 * @param iOptionName
		 * the name of the option to retrieve
		 */
		static HRESULT RemoveJavaVMOption(
			CATListOfCATJavaVMOption& ioOptions,
			const CATUnicodeString& iOptionName);

		/**
		 * Sets an option in a list of Java VM options
		 * @param iOptions
		 * the option list
		 * @param iOption
		 * the option to add
		 */
		static HRESULT SetJavaVMOption(
			CATListOfCATJavaVMOption& ioOptions,
			const CATJavaVMOption& iOption);

		/**
		 * Creates a string representing the VM options and their values.
		 */
		static CATUnicodeString DumpJavaVMOptions(
			const CATListOfCATJavaVMOption& iOptions);


		// Utility functions for valuating commonly used options

		/**
		 * Retrieves all the code/bin directories of the runtime view
		 * @param oDirectories
		 * the code/bin directories of the runtime view
		 */
		static HRESULT GetRuntimeViewBinDirectories(
			CATListOfCATUnicodeString& oDirectories);

		/**
		 * Enum to describe the java levels (values can be OR-ed to form bit masks)
		 * @param JavaClient
		 * jar is is ${OS}/docs/java
		 * @param JavaServer
		 * jar is is ${OS}/docs/javaserver
		 * @param JavaCommon
		 * jar is is ${OS}/docs/javacommon
		 */
		enum JavaLevel {
			JavaClient=0x1,
			JavaServer=0x2,
			JavaCommon=0x4
		};
		/**
		 * Retrieves the full path of all the jars of the runtime view which match 
		 * the supplied pattern
		 * @param iNamePattern
		 * The naming pattern. It supports very limited, regex-like expressions:
		 * <ul>
		 * <li>'|' can be used to specify 'or' of expressions</li>
		 * <li>'*' can be used to specify 'any sequence of characters'</li>
		 * </ul>
		 * for instance:
		 * <br>
		 * CATJsyClassLoader.jar|CATJava*
		 * <br>
		 * means: the runtime view jar called CATJsyClassLoader.jar
		 * or any runtime view jar with a name that begins by CATJava
		 * @param iLevelMask
		 * a bit mask specifying the jars to take into account
		 * @param oJars
		 * the full path of all the jars of the runtime view which match 
		 * the supplied pattern
		 */
		static HRESULT GetRuntimeViewJars(
			const CATUnicodeString& iNamePattern,
			JavaLevel iLevelMask,
			CATListOfCATUnicodeString& oJars);

		/**
		 * Builds the JavaVMOption to specify the -Djava.class.path variable
		 * @param iJars
		 * a list of jars for the option value
		 * @param oOption
		 * the resulting option
		 */
		static HRESULT BuildClasspathOption(
			CATListOfCATUnicodeString& iJars,
			CATJavaVMOption& oOption);

		/**
		 * Builds the JavaVMOption to specify the -Djava.libray.path variable
		 * @param iDirectoryPaths
		 * a list of directories for the option value
		 * @param oOption
		 * the resulting option
		 */
		static HRESULT BuildLibrarypathOption(
			CATListOfCATUnicodeString& iDirectoryPaths,
			CATJavaVMOption& oOption);

		/**
		 * Returns the path of the Jdk specified in the Automation settings.
		 */
		static HRESULT GetSettingsJdkPath(
			CATUnicodeString& oJdkPath);

		/**
		 * Returns the list of paths of the CLASSPATH used to replay java macros.
		 */
		static HRESULT GetClasspath(CATListOfCATUnicodeString& oPaths);

		/**
		 * Returns the concatenation of directories that are added
		 * to the default internal CLASSPATH used to replay
		 * java macros.
		 */
		static HRESULT GetExternalClasspath(CATUnicodeString& oClasspath);

		/**
		 * Returns the jvm path from the Jdk path set in the settings.
		 * (ex. on NT : <Jdk path>\\jre\\bin\\hotspot).
		 */
		static HRESULT GetJvmPath(CATUnicodeString& oJvmPath);

	private:	
		/**
		 * Sets the JVM's state as running or not with the used Jdk path.
		 */
		static void _SetJvmRunning(CATBoolean iRunning, const CATUnicodeString& iJdkPath);

		static CATBoolean _FileExists(const CATUnicodeString& iFilePath);

		static int _DestroyJVM(int iRc);
		
		static long _JVM_Vfprintf(FILE* f, const char* format, va_list args);

		/**
		 * Returns the list of .jar files found in the runtime view.
		 */
		static HRESULT _GetInternalJars(CATListOfCATUnicodeString& oJarsPaths);

#ifdef _WINDOWS_SOURCE
		/**
		 * Returns the executable directory path.
		 */
		static HRESULT _GetExecutableDirPath(CATUnicodeString& oDirPath);
#endif // _WINDOWS_SOURCE

		/**
		 * Returns the jvm shared library name.
		 */
		static CATUnicodeString _GetJvmLibName();

		/**
		 * Returns the list of directories that are added
		 * to the default internal CLASSPATH used to replay
		 * java macros.
		 */
		static HRESULT _GetExternalClasspath(CATListOfCATUnicodeString& oPaths);

		/**
		 * Returns the path concatenation character: ";" or ":"
		 */
		static CATUnicodeString _GetSeparator();

		/**
		 * Returns the directory separator: "/" or "\"
		 */
		static CATUnicodeString _GetSlash();

		/**
		 * Returns the contents of the shared library path environment variable.
		 */
		static CATUnicodeString _GetLibraryPath();

	private:
		static CATBoolean _jarsFound;
		static CATListOfCATUnicodeString _internalJarPaths;
		static CATBoolean _jvmIsRunning;
		static CATUnicodeString _usedJdkPath;

};

extern "C" HRESULT ExportedByCATJNIBridge _CheckInstalledJdk(const CATUnicodeString& iPath, CATUnicodeString& oJvmPath);
extern "C" CATBoolean ExportedByCATJNIBridge _JvmIsRunning(CATUnicodeString& oJdkPath);
extern "C" HRESULT ExportedByCATJNIBridge _GetClasspath(CATListOfCATUnicodeString& oPaths);

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jstring JNICALL Java_com_dassault_1systemes_javabridge_interpreter_ClassPathManager_getExternalClasspath(JNIEnv * env, jclass cls);

#ifdef __cplusplus
}
#endif


#endif // CATJNIEnvironment_h


