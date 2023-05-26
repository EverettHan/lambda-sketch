/* -*-c++-*- */
#ifndef CATIDocument_h
#define CATIDocument_h

// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @level Protected 
 * @usage U3
 */

#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATDocument.h"

class CATIDocEnvironment;
class CATDocument;
class CATIDocId; 

#include "AD0XXBAS.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByAD0XXBAS IID IID_CATIDocument;
#else
extern "C" const IID IID_CATIDocument;
#endif


/**
* Interface allowing access to a document's unique identification information
* DRL: WARNING R13 Some object other than document may support CATIDocument as well (i.e. ASMProduct & co)
* INTENT IS R14 CATIDocument will inherit from CATIDocumentProxy instead of current inheritance
*/
class ExportedByAD0XXBAS CATIDocument: public CATBaseUnknown
{
public: 

  CATDeclareInterface;

  public:

  /** 
  * Returns the type of the document.
  *<br><b>Note:</b>Type may be known even if the StorageName is undefined (or no suffix)  
  */
  virtual CATUnicodeString GetType () const =0;

  /**
    *  Retrieves the document's Id element.
	*  @param oDocId
	*         The returned document Id element. 
    */
  virtual HRESULT GetDocId(CATIDocId ** oDocId) = 0;

  /** 
  * Returns the complete access name of the document.
  *<br><b>Note:</b>The complete access name is: path + name of the document + suffix where: 
  * <br>Might be different from DisplayName (the name of the document is displayed in the document's window)
  * <br>
  * <br>The path is the complete path of the file which should comply with CATStdLib System access.   
  */

  virtual CATUnicodeString StorageName () const =0;

  /** 
  * Returns the display name of the document.
  *<br><b>Note:</b>The display name might be different from storage name (as storage name might be meaningless for user) 
  *<br> For instance it could be just the name of the document, not the whole path (environment are dealing with meaningfull user name)
  */
  virtual CATUnicodeString DisplayName () const =0;

  /** @nodoc  for migration reasons, might be withrawn  (use DocId)*/
  virtual HRESULT GetDocEnvironment(CATIDocEnvironment ** oDocEnvironment) = 0;

  /** @nodoc  for migration reasons, might be withrawn */
  virtual CATDocument* GetCATDocument() =0; 
};

CATDeclareHandler(CATIDocument, CATBaseUnknown);


#endif
