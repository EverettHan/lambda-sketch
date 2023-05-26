/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2002

#ifndef CATOmbDocPropertyServices_H
#define CATOmbDocPropertyServices_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2002

/** 
* @level Private
* @usage U1
*/

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
#include "CATDocumentsInSession.h"
#include "CATListOfCATUnicodeString.h"
class CATDocument;
class CATIDocId;

/**
* @nodoc
* Services to create, remove and modify properties embedded in documents.
* <b>Role:</b> Properties are persistent data attached to documents. 
* It is possible to read the properties of a document without loading it using its DocId. 
* However modifications of properties requires to load the embedding document.
* <br><br>There is one method for creating or modify a property of a given document:
* <ul>
* <li>@href #SetValue </li>
* </ul>
* There is one method for reading a property value:
* <ul>
* <li>@href #GetValue </li>
* </ul>
*  There are two methods for removing properties a document:
* <ul>
* <li>@href #Remove </li>
* <li>@href #RemoveAll </li>
* </ul>
* There is one method for reading all property names of a given document:
* <ul>
* <li>@href #GetAllNames </li>
* </ul>
*/

class ExportedByAC0XXLNK CATOmbDocPropertyServices
{
public:

 /**
* @nodoc
  * Set the value of a given property in a given document.
  * <br><b>Role:</b> used to assign a value to a property, specified by its name in a given document.
  * This method can also be used to modify a property with the same name by changing its value.
  * @param iDoc
  *      The document in which the property will be added. 
  * @param iPropertyName 
  *      The name of the property  to set.
  * @param iValue
  *      The property value.
  * @return
  *		 S_OK : The operation suceeded.
  *	<br> E_FAIL : The  operation failed.
  */
 static HRESULT  SetValue(CATDocument* iDoc, const CATUnicodeString iPropertyName, const CATUnicodeString iValue);

 /**
* @nodoc
  * Retrieves the value of a given property in a document.
  * @param iDocId
  *      The document identification of the document containing the property. 
  * @param iPropertyName 
  *      The property name.
  * @param oValue
  *      The property value.
  * @return
  *		 S_OK : The operation suceeded.
  *	<br> E_FAIL : The  operation failed.
  */
 static HRESULT  GetValue(CATIDocId* iDocId, const CATUnicodeString iPropertyName, CATUnicodeString& oValue);

 /**
* @nodoc
  * Retrieves all the property names of a given document.
  * @param iDocId
  *      The document. 
  * @param oListOfPropertiesNames
  *      The list of all property names of the document.
  * @return
  *		 S_OK : The operation suceeded.
  *	<br> E_FAIL : The  operation failed.
  */
 static HRESULT  GetAllNames(CATIDocId* iDocId, CATLISTV(CATUnicodeString)& oListOfPropertiesNames);

  /**
* @nodoc
  * Removes a given property in a document.
  * @param iDoc
  *      The document identification of the document in which the property will be deleted. 
  * @param iPropertyName 
  *      The name of the property to delet.
  * @return
  *		 S_OK : The operation suceeded.
  *	<br> E_FAIL : The  operation failed.
  */
 static HRESULT  Remove(CATDocument* iDoc, const CATUnicodeString iPropertyName);

  /**
* @nodoc
  * Removes all the properties of a given document.
  * @param iDoc
  *      The document in which the properties will be deleted. 
  * @return
  *		 S_OK : The operation suceeded.
  *	<br> E_FAIL : The  operation failed.
  */
 static HRESULT  RemoveAll(CATDocument* iDoc);

private:

 CATOmbDocPropertyServices();

 ~CATOmbDocPropertyServices();

};

#endif


