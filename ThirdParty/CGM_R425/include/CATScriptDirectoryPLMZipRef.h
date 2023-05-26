#ifndef CATScriptDirectoryPLMZipRef_h
#define CATScriptDirectoryPLMZipRef_h

// COPYRIGHT DASSAULT SYSTEMES 2007

/**
 * Class to represent a reference to a directory script container.
 */

#include "AutomationItf.h"
#include "CATScriptPLMZipRef.h"

class CATScriptPLMZipRefItf;

class ExportedByCATAutoItf CATScriptDirectoryPLMZipRef : public CATScriptPLMZipRef {
  
     public:
  
  CATDeclareClass;
  
  /**
   * Factory method.
   * Deprecated, do not use.
   */
  static HRESULT CreateReference(CATListOfCATUnicodeString * iPLMAttributeNames, CATListOfCATUnicodeString * iPLMAttributeValues,
								 CATBaseUnknown * iPLMObject, CATUnicodeString &iDisplayName, CATScriptDirectoryPLMZipRef*& oReference);
  
  /**
   * Factory method.
   */
  static HRESULT CreateReference(CATBaseUnknown * iPLMObject, CATScriptDirectoryPLMZipRef*& oReference);
  
  /**
   * Destructor.
   */
  virtual ~CATScriptDirectoryPLMZipRef(); 
  
     private:

  /**
   * Constructor.
   */
  CATScriptDirectoryPLMZipRef(CATScriptPLMZipRefItf *iImpl);
};

#endif // CATScriptDirectoryPLMZipRef_h

