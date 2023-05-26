/**
 * @level Protected
 * @usage U1
 */
/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2008 
//-----------------------------------------------------------------------------
// ObjectModelerCATIA Services
// 
//-----------------------------------------------------------------------------
// Usage Notes: restricted use for Fbdi CATProduct with FTA data
//
//-----------------------------------------------------------------------------
// Creation by LHZ - Mars 2008
//-----------------------------------------------------------------------------
#ifndef CATDuplicateContainerRestrictedServices_h
#define CATDuplicateContainerRestrictedServices_h

#include "AC0CATPL.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

class ExportedByAC0CATPL CATDuplicateContainerRestrictedServices
{
public:
  /**
  *  <br><b>Role</b>: Read CATProduct ,create new CATPart and duplicate link Table content
  *
  * @param iProductFilePathFrom [in]
  *    File path of CATProduct to copy
  * @param iPartFilePathTo [in]
  *    File path of CATPart to create
  * @return
  *      Error code of function.
  *      <br><b>Legal values</b>:
  *      <dl>
  *        <dt>S_OK</dt>
  *          <dd> SUCCEEDED.</dd>
  *        <dt>E_FAIL</dt>
  *          <dd> FAILED or Args are incorrect </dd>
  *      </dl>
  **/
  static HRESULT CreateFromAndCopyLinkTable (const CATUnicodeString &iProductFilePathFrom,const CATUnicodeString &iPartFilePathTo);
 
  /**
  *  <br><b>Role</b>: Read the 2 files (CATProduct and CATPart) and duplicate a list of containers in a given list of container fathers
  *
  * @param iProductFilePathFrom [in]
  *    File path of CATProduct containing containers to duplicate
  * @param iPartFilePathTo [in]
  *    File path of CATPart where containers are duplicated
  * @param iListOfStorageToDuplicate [in]
  *    Storage list to duplicate
  * @param iListOfContainerUUIDToDuplicate [in]
  *    UUIDs of container to duplicate
  * @param iListOfContainerUUIDFatherDestination [in]
  *    UUIDs of containers father where to duplicate 
  * @return
  *      Error code of function.
  *      <br><b>Legal values</b>:
  *      <dl>
  *        <dt>S_OK</dt>
  *          <dd>Duplication SUCCEEDED.</dd>
  *        <dt>E_FAIL</dt>
  *          <dd>Duplication FAILED or Args are incorrect </dd>
  *      </dl>
  **/
  static HRESULT DuplicateContainers (const CATUnicodeString &iProductFilePathFrom,const CATUnicodeString &iPartFilePathTo,
    CATListOfCATUnicodeString &iListOfStorageToDuplicate,
    CATListOfCATUnicodeString &iListOfContainerUUIDToDuplicate,
    CATListOfCATUnicodeString &iListOfContainerUUIDFatherDestination);

  /**
  *  <br><b>Role</b>: Read  CATPart and delete a list of Appli containers 
  *
  * @param iPartFilePath [in]
  *    File path of CATPart where to delete containers
  * @param iListOfStorageToDelete [in]
  *    Storage list to delete 
  * @param iListOfContainerUUIDToDelete [in]
  *    UUIDs of containers to Delete in CATPart 
  * @return
  *      Error code of function.
  *      <br><b>Legal values</b>:
  *      <dl>
  *        <dt>S_OK</dt>
  *          <dd>SUCCEEDED.</dd>
  *        <dt>E_FAIL</dt>
  *          <dd>FAILED or Args are incorrect </dd>
  *      </dl>
  **/
  static HRESULT RemoveContainers (const CATUnicodeString &iPartFilePath,
    CATListOfCATUnicodeString &iListOfStorageToDelete,
    CATListOfCATUnicodeString &iListOfContainerUUIDToDelete) ;

  static CATListOfCATUnicodeString* __listProjectFlag ;

private:
  static HRESULT CopyStorage(const CATUnicodeString &iProductFilePathFrom,                                                         
                       const CATUnicodeString &iPartFilePathTo,             
                       CATListOfCATUnicodeString &iListOfStorageToCopy,      
                       CATListOfCATUnicodeString &iListOfStorageToDelete);

};

class CATIProjectFlag_var;
HRESULT CATGetProjectFlagsToWrite (const CATIProjectFlag_var& iRootCont, CATListOfCATUnicodeString& FlagsToSet); 

#endif



