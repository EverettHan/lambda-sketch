/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2007
/**
* @level Protected
* @usage U1
*/

#ifndef CATOmbDocumentPropertiesServices_V1_H
#define CATOmbDocumentPropertiesServices_V1_H // Rajout de l'argument dans la méthode RetrievesPropertiesFromFile
#define CATOmbDocumentPropertiesServices_H

#include "CATOmbSessionService.h"
#include "AC0XXLNK.h"
#include "CATLISTV_CATBaseUnknown.h"

class CATUnicodeString;
class CATListValCATBaseUnknown_var;




/**
* This class provides services to list the properties from a stream located on disk of a document
* 
* 
* <br><b>Role</b>: 
* <p>
* This class has to be instanciated on the stack
* ex : CATOmbDocumentPropertiesServices myObj;
* HR = myObj.Services()
* 
*/
class ExportedByAC0XXLNK CATOmbDocumentPropertiesServices : public CATOmbSessionService
{

public:

  /**
  * Creates the service. 
  *
  * @param ipSessionContext
  *   A pointer to the session to be used as a context for this service. 
  **/
  CATOmbDocumentPropertiesServices(CATOmbSessionContext *ipSessionContext = NULL) : CATOmbSessionService(ipSessionContext) {};

  /**
  * Frees the service ressources. 
  **/
  ~CATOmbDocumentPropertiesServices() {};

  

  
  /** 
  * Retrieves the Properties of document by scanning its stream. 
  *
  * <br><b>Role</b>: This method retrieves the properties of a document by scanning its stream. 
  * This service is dedicated to catalog and catftc files only. 
  * Associated document must not be loaded in session. 
  *
  * @param iFilePath [in]
  *   The file path of the stream to scan
  * @param oPropertiesNames [out]
  *   Names of each properties retrieved
  * @param oProperties [out]
  *   The list of properties retrieved
  *
  * @return
  *   <code>S_OK</code> code succeeded
  *   <code>E_INVALIDARG</code> Document is loaded in session. This is not a catalog file
  *   <code>E_*</code> Unexpected error
  */    
  HRESULT RetrievesPropertiesFromFile(const CATUnicodeString& iFilePath, CATListOfCATUnicodeString& oPropertiesName, CATListValCATBaseUnknown_var& oProperties, CATBoolean iReplayWithAllChecks=1);
  

  /** 
  * Retrieves the Properties of a catalog by scanning its stream. 
  *
  * <br><b>Role</b>: This method retrieves the properties of a catalog by scanning its stream. 
  * This service is dedicated to catalog and catftc files only. 
  * Caller must guarantee the document is not in session. 
  * Same functionnality than RetrievesPropertiesFromFile but it does not require a CATSession
  * Less cheks are performed to improve performance. 
  * 
  *
  * @param iFilePath [in]
  *   The file path of the stream to scan
  * @param oPropertiesNames [out]
  *   Names of each properties retrieved
  * @param oProperties [out]
  *   The list of properties retrieved
  *
  * @return
  *   <code>S_OK</code> code succeeded
  *   <code>E_INVALIDARG</code> This is not a catalog file
  *   <code>E_*</code> Unexpected error
  */    
  static HRESULT RetrievesPropertiesFromCatalogFile(const CATUnicodeString& iFilePath, CATListOfCATUnicodeString& oPropertiesName, CATListValCATBaseUnknown_var& oProperties);
  

};

#endif


