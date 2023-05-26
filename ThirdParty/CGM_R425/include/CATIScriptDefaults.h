#ifndef CATIScriptDefaults_h
#define CATIScriptDefaults_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "IUnknown.h"
#include "CATScriptLanguage.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListOfITypeLib.h"
#include "CATBoolean.h"

/**
 * Interface to manage user settings for the scripting infrastructure.
 * @author: Jean-Francois Doue (JDU)
 */
class CATIScriptDefaults : public IUnknown {
	public:

		/**
		 * Returns the list of type libraries that are to be loaded and
		 * used for scripting.
		 * These type libraries are not located in the runtime view,
		 * since all the type libraries found in the runtime view are
		 * automatically loaded and taken into account.
		 */
		virtual HRESULT __stdcall GetExternalTypeLibs(
			CATListOfCATUnicodeString& oNames,
			CATListOfITypeLib& oLibs) = 0;

		/**
		 * Sets the list of type libraries that are to be loaded and
		 * used for scripting.
		 * These type libraries are not located in the runtime view,
		 * since all the type libraries found in the runtime view are
		 * automatically loaded and taken into account.
		 */
		virtual HRESULT __stdcall SetExternalTypeLibs(
			CATListOfCATUnicodeString& iNames,
			CATListOfITypeLib& iLibs) = 0;

		/**
		 * Returns the editor used to edit programs in the 
		 * supplied language.
		 */
		virtual HRESULT __stdcall GetEditorForLanguage(
			CATScriptLanguage iLanguage, 
			CATUnicodeString& oEditorPath) = 0;

		/**
		 * Specifies the editor used to edit programs in the 
		 * supplied language.
		 */
		virtual HRESULT __stdcall SetEditorForLanguage(
			CATScriptLanguage iLanguage, 
			const CATUnicodeString& iEditorPath) = 0;

		/**
		 * Returns the jdk path.
		 */
		virtual HRESULT __stdcall GetJdkPath(
			CATUnicodeString& oJdkPath) = 0;

		/**
		 * Specifies the jdk path.
		 */
		virtual HRESULT __stdcall SetJdkPath(
			const CATUnicodeString& iJdkPath) = 0;

		/**
		 * Returns the list of paths that will be added
		 * to the default internal CLASSPATH used to replay
		 * java macros.
		 */
		virtual HRESULT __stdcall GetExternalClasspath(
			CATListOfCATUnicodeString& oPaths) = 0;

		/**
		 * Sets the list of paths that will be added
		 * to the default internal CLASSPATH used to replay
		 * java macros.
		 */
		virtual HRESULT __stdcall SetExternalClasspath(
			CATListOfCATUnicodeString& iPaths) = 0;

		/**
		 * Returns the name of RMI server.
		 */
		virtual HRESULT __stdcall GetRMIServerName(
			CATUnicodeString& oName) = 0;

		/**
		 * Sets the name of RMI server.
		 */
		virtual HRESULT __stdcall SetRMIServerName(
			const CATUnicodeString& iName) = 0;

		/**
		 * Returns the port on which the RMI registry runs.
		 */
		virtual HRESULT __stdcall GetRMIRegistryPort(
			unsigned int& oPort) = 0;

		/**
		 * Specify the port on which the RMI registry will run.
		 */
		virtual HRESULT __stdcall SetRMIRegistryPort(
			unsigned int iPort) = 0;

		/**
		 * Returns TRUE if the RMI server for the application
		 * is started automatically when the application starts,
		 * FALSE otherwise
		 */
		virtual HRESULT __stdcall IsRMIServerAutoStarted(
			CATBoolean& oAutoStarted) = 0;

		/**
		 * Specifies if the RMI server for the application
		 * is started automatically when the application starts
		 */
		virtual HRESULT __stdcall SetRMIServerAutoStarted(
			CATBoolean iAutoStarted) = 0;

		/**
		 * Returns the authentication mechanism.
		 */
		virtual HRESULT __stdcall GetAuthenticationMechanism(
			short& oMechanism) = 0;

		/**
		 * Specify the authentication mechanism.
		 */
		virtual HRESULT __stdcall SetAuthenticationMechanism(
			short iMechanism) = 0;

		/**
		 * Returns the LDAP server name.
		 */
		virtual HRESULT __stdcall GetLDAPServerName(
			CATUnicodeString& oServerName) = 0;

		/**
		 * Specify the LDAP server name.
		 */
		virtual HRESULT __stdcall SetLDAPServerName(
			const CATUnicodeString& iServerName) = 0;

		/**
		 * Returns the LDAP server port.
		 */
		virtual HRESULT __stdcall GetLDAPServerPort(
			unsigned int& oPort) = 0;
			
		/**
		 * Specify the LDAP server port.
		 */
		virtual HRESULT __stdcall SetLDAPServerPort(
			unsigned int iPort) = 0;

		/**
		 * Resets the defaults to their original values.
		 */
		virtual HRESULT __stdcall Reset() = 0;

		/**
		 * Returns TRUE if autocommit is enabled, false otherwise.
		 */
		virtual HRESULT __stdcall DoesAutoCommit(
			CATBoolean& oBoolean) = 0;

		/**
		 * Set whether autocommit is enabled. When autocommit is
		 * enabled, any calls to set a new default cause the
		 * default to be committed and the repository saved.
		 */
		virtual HRESULT __stdcall SetAutoCommit(
			CATBoolean iBoolean) = 0;

		/**
		 * Commits but does not save the repository
		 * (useful only when autocommit is disabled).
		 */
		virtual HRESULT __stdcall Commit() = 0;

		/**
		 * Rolls back but does not save the repository
		 * (useful only when autocommit is disabled).
		 */
		virtual HRESULT __stdcall Rollback() = 0;

		/**
		 * Saves the defaults.
		 */
		virtual HRESULT __stdcall Save() = 0;

		/**
		 * Resets the defaults to the values specified
		 * by the administrator.
		 */
		virtual HRESULT __stdcall ResetToAdminValues() = 0;
};


extern "C" const IID IID_CATIScriptDefaults;

#endif

