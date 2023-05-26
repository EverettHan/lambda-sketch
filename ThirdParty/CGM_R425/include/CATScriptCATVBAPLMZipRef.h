#ifndef CATScriptCATVBAPLMZipRef_h
#define CATScriptCATVBAPLMZipRef_h

// COPYRIGHT DASSAULT SYSTEMES 2007

/**
 * Class to represent a reference to a PLM CATVBA script container.
 */

#include "AutomationItf.h"
#include "CATScriptPLMZipRef.h"

class CATScriptPLMZipRefItf;

class ExportedByCATAutoItf CATScriptCATVBAPLMZipRef : public CATScriptPLMZipRef {

	 public:
  
  CATDeclareClass;
                 
  /**
   * Factory method.
   * Deprecated, do not use.
   */
  static HRESULT CreateReference(CATListOfCATUnicodeString * iPLMAttributeNames, CATListOfCATUnicodeString * iPLMAttributeValues,
								 CATBaseUnknown * iPLMObject, CATUnicodeString &iDisplayName, CATScriptCATVBAPLMZipRef*& oReference);

  /**
   * Factory method.
   */
  static HRESULT CreateReference(CATBaseUnknown * iPLMObject, CATScriptCATVBAPLMZipRef*& oReference);
  
  /**
   * Destructor.
   */
  virtual ~CATScriptCATVBAPLMZipRef();  

private:

  /**
   * Constructor.
   */
  CATScriptCATVBAPLMZipRef(CATScriptPLMZipRefItf *iImpl);

};

#endif // CATScriptCATVBAPLMZipRef_h

