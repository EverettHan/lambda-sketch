#ifndef CATPLMXmlIdentification_H
#define CATPLMXmlIdentification_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
/**
* XML identification Services
*/
/* 

/**
 * @level Protected
 * @usage U1       
 */

/**
*  Description  : Access XML identification from Identificators of objects and reverse
*/
#include "CATBaseUnknown.h"

#include "CATPLMIdentificationAccess.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListPtrCATIAdpPLMIdentificator.h"

class ExportedByCATPLMIdentificationAccess CATPLMXmlIdentification
{
public:

   //------------------------------------------------------------------------
  //  BLA BLA BLA BLA ....
  //------------------------------------------------------------------------

  /** 
  * Empty Constructor
  * */
  CATPLMXmlIdentification();

  /**
  * Destructor
  */
  ~CATPLMXmlIdentification();
 
  //------------------------------------------------------------------------
  // Getter  ....
  //------------------------------------------------------------------------
 

  /** 
  * Get XML IDs from Identificators of the objects in session
  * 
  * @param iListofObjectsIDs
  *   the list of objects Identificators in session
  * 
  * @param oListOfXMLIDs
  *   the returned corresponding list of XMLIDs 
  *    
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT GetXMLIDsFromIdentificators(CATLISTP(CATIAdpPLMIdentificator)& iListofObjectsIDs, CATListOfCATUnicodeString& oListOfXMLIDs);
 

  /** 
  * Get Identificators of the session objects from XMLIDs
  * 
  * @param iListOfXMLIDs
  *   the list of XMLIDs
  * 
  * @param oListofObjectsIDs
  *	  the returned corresponding list of identificators 
  *    
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT GetIdentificatorsFromXMLIDs(CATListOfCATUnicodeString& iListOfXMLIDs, CATLISTP(CATIAdpPLMIdentificator)& oListofObjectsIDs);


  /** 
  * Get Identificators of the session objects from XMLIDs
  * 
  * @param iListOfXMLIDs
  *   the list of XMLIDs
  * 
  * @param oListofObjectsIDs
  *	  the returned corresponding list of identificators 
  *    
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT RetrieveAssociatedIds(CATListOfCATUnicodeString& iListOfXMLIDs, CATLISTP(CATIAdpPLMIdentificator)& oListofObjectsIDs);


  /** 
  * Get XML IDs from Identificators of the objects in session
  * 
  * @param iListofObjectsIDs
  *   the list of objects Identificators in session
  * 
  * @param oListOfXMLIDs
  *   the returned corresponding list of XMLIDs 
  *    
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT RetrieveAssociatedXMLIds(CATLISTP(CATIAdpPLMIdentificator)& iListofObjectsIDs, CATListOfCATUnicodeString& oListOfXMLIDs);

};

  

#endif
