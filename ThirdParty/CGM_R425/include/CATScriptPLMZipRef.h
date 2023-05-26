#ifndef CATScriptPLMZipRef_h
#define CATScriptPLMZipRef_h

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "AutomationItf.h"

#include "CATScriptRef.h"

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

class CATScriptPLMZipRefItf;
class CATBinary;

/**
 * Class to represent a reference to a script container into a PLM context.
 * Author: JBX
 */

class CATBaseUnknown;
 
class ExportedByCATAutoItf CATScriptPLMZipRef : public CATScriptRef {

     public:
		CATDeclareClass;

		/**
		 * Destructor.
		 */
		virtual ~CATScriptPLMZipRef();
   
                /**
		 * Returns the PLMIKbaZippedFolder object.
		 */
                virtual CATUnicodeString GetDisplayName();

                
                /**
		 * Returns the PLMIKbaZippedFolder list of attribute name.
		 */
                virtual HRESULT GetPLMAttributeNames(CATListOfCATUnicodeString * oAttributeNames);


                /**
		 * Returns the PLMIKbaZippedFolder list of attribute value
		 */
                virtual HRESULT GetPLMAttributeValues(CATListOfCATUnicodeString * oAttributeValues);

                       
                /**
		 * Returns the PLMIKbaZippedFolder object, that can be NULL !
         * IMPORTANT: it is the responsibility of the caller to AddRef the pointer.
		 */
                virtual HRESULT GetPLMObject(CATBaseUnknown *& oPLMObject);
                
         // ++IK8
         virtual HRESULT Equals(CATScriptRef &iScriptRef, bool &oEqual);
         // --IK8
         
         // INTERNAL USE ONLY BEGIN
         /**
          * GetDisplayNameFallback.
          * Returns a display name with a fixed format.
          * GetDisplayName returns this name as a fall-back when the customizable display name cannot be retrieved (CATIAlias::GetAlias), for e.g. if the underlying PLM object cannot be loaded.
          * WARNING: DO NOT USE AS AN IDENTIFIER!
          * NOTE: whereas GetDisplayName may return the same value as GetDisplayNameFallback, the opposite is not true.
          */
         virtual HRESULT GetDisplayNameFallback(CATUnicodeString &oFallbackDisplayName);
         // INTERNAL USE ONLY END

     protected:
		/**
		 * Constructor.
		 */
        CATScriptPLMZipRef(CATScriptPLMZipRefItf *iImpl);

        /**
         * Implementation factory.
         */
        static CATScriptPLMZipRefItf * CreateImpl(CATListOfCATUnicodeString * iPLMAttributeNames, 
                                                    CATListOfCATUnicodeString * iPLMAttributeValues, 
                                                    CATUnicodeString * iDisplayName, 
                                                    CATBaseUnknown *iPLMZipObject);
        static CATScriptPLMZipRefItf * CreateImpl(CATBaseUnknown *iPLMZipObject);

private:
    // Members
    CATScriptPLMZipRefItf *_impl;
};

#endif // CATScriptPLMZipRef_h

