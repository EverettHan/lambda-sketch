#ifndef CATIScriptServices_h
#define CATIScriptServices_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "AutomationItf.h"
#include "IUnknown.h"
#include "CATScriptLanguage.h"
#include "CATUnicodeString.h"
#include "CATString.h"
#include "CATSetOfCATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListOfITypeLib.h"

class CATIScriptDefaults;
class CATIScriptContainers;
class CATIScriptUIServices;
class CATScriptRef;

/**
 * Interface to provide access to the scripting API.
 * @author: Jean-Francois Doue (JDU)
 */
class CATIScriptServices : public IUnknown
{
	public:

		/**
		 * Returns the object used to manage the users settings for scripting.
		 */
		virtual HRESULT __stdcall GetScriptingDefaults(
			CATIScriptDefaults*& oDefaults) = 0;
            
		/**
		 * Returns a list of all the opened script containers.
         * IMPORTANT: in the general case, one should call CreateContainersManager instead to retrieve an empty list.
		 */
		virtual HRESULT __stdcall GetContainers(
			CATIScriptContainers*& oContainers) = 0;

		/**
		 * Returns a list of all the opened script containers.
		 */
		virtual HRESULT __stdcall GetUIServices(
			CATIScriptUIServices*& oServices) = 0;


		/**
		 * Get all the known scripting languages.
		 */
		virtual HRESULT __stdcall GetAllScriptingLanguages(
			CATSetOfCATUnicodeString& oLanguages) = 0;

		/**
		 * Get all the scripting languages supported
		 * on the platform on which the call is made.
		 */
		virtual HRESULT __stdcall GetSupportedScriptingLanguages(
			CATSetOfCATUnicodeString& oLanguages) = 0;

		/**
		 * Returns a list which contains all the type libraries.
		 * (external type libraries and runtime view type libraries).
		 */
		virtual HRESULT __stdcall GetAllTypeLibs(
			CATListOfCATUnicodeString& oNames,
			CATListOfITypeLib& oLibs) = 0;

				/**
		 * Encodes a reference in a CATUnicodeString. This string can
		 * then be stored, making the reference persistent.
		 */
		virtual HRESULT __stdcall EncodeReference(
			CATScriptRef* iReference,
			CATUnicodeString& oEncodedRef) = 0;

		/**
		 * Decodes a reference which has been encoded as a CATUnicodeString. 
		 * This method can be used to revive a reference which has been
		 * archived to persistent storage.
		 */
		virtual HRESULT __stdcall DecodeReference(
			const CATUnicodeString& iEncodedRef,
			CATScriptRef*& oReference) = 0;

		/**
		 * Retrieves the object which corresponds to
		 * the supplied reference.
		 */
		virtual HRESULT __stdcall ResolveReference(
			CATScriptRef* iReference,
			IUnknown*& oObject) = 0;
            
        /**
         * CreateContainersManager.
         * Returns a new container manager instance. Release must be done by the caller.
         */
        virtual HRESULT __stdcall CreateContainersManager(CATIScriptContainers*& oContainers) = 0;
};

/**
 * Give access to a global <tt>CATIScriptServices</tt> object.
 */
extern HRESULT ExportedByCATAutoItf GetScriptServices(CATIScriptServices*& oScriptServices);

extern "C" const IID IID_CATIScriptServices;

#endif // CATIScriptServices_h

