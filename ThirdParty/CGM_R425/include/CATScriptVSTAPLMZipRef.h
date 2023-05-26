#ifndef CATScriptVSTAPLMZipRef_h
#define CATScriptVSTAPLMZipRef_h

// COPYRIGHT DASSAULT SYSTEMES 2007

/**
 * Class to represent a reference to a PLM VSTA script container.
 */

#include "AutomationItf.h"
#include "CATScriptPLMZipRef.h"
#include "CATScriptLanguage.h"

class CATScriptPLMZipRefItf;

class ExportedByCATAutoItf CATScriptVSTAPLMZipRef : public CATScriptPLMZipRef 
{
    public:

  CATDeclareClass;
  
  /**
   * Factory method.
   * Deprecated, do not use.
   */
  static HRESULT CreateReference(CATListOfCATUnicodeString * iPLMAttributeNames, CATListOfCATUnicodeString * iPLMAttributeValues,
								 CATBaseUnknown * iPLMObject, CATScriptLanguage iSelectedLanguage, CATUnicodeString &iDisplayName, 
								 CATScriptVSTAPLMZipRef*& oReference);
  
  /**
   * Factory method.
   */
  static HRESULT CreateReference(CATBaseUnknown * iPLMObject, CATScriptLanguage iLanguage, CATScriptVSTAPLMZipRef*& oReference);
  
  /**
   * Destructor.
   */
  virtual ~CATScriptVSTAPLMZipRef();  
  
  /**
   * The authorized script language
   */
  HRESULT GetScriptLanguage(CATScriptLanguage &oLanguage);
  
     private:

  /**
   * Constructor.
   */
  CATScriptVSTAPLMZipRef(CATScriptPLMZipRefItf *iImpl, CATScriptLanguage iLanguage);
  
  // Members
  CATScriptLanguage _AssocLanguage;

};

#endif // CATScriptVSTAPLMZipRef_h
