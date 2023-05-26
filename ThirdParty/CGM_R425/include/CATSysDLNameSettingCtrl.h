//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2003                                         
//===========================================================================
//                                                                           
//  CATCacheSetting                                                 
//                                                                           
//  Usage Notes: Class Definition                                             
//===========================================================================
//  Creation fevrier  2003                                 adt         	
//===========================================================================
#ifndef __CATSYSDLNAMESETTINGCTRL
#define __CATSYSDLNAMESETTINGCTRL
#include "JS0STDLIB.h"
#include "CATBaseUnknown.h"   
#include "CATSysSettingController.h"
#include "CATSysMacroSettingCtrl.h"

// COPYRIGHT DASSAULT SYSTEMES 2003



class CATUnicodeString;
class CATSettingInfo;
class CATSysSimpleHashTable;
class CATDLName;



class ExportedByJS0STDLIB CATSysDLNameSettingCtrl
  :public CATSysSettingController
{
  CATDeclareSettingCtrl(CAT,Sys,DLName);
  /** @nodoc */
  CATDeclareCBEvent(Updated);
  friend class CATDLName;
  
public :
  virtual ~CATSysDLNameSettingCtrl();
  
  HRESULT Initialize();
  HRESULT ResetToAdminValues(char** iAttList=NULL, int iNbAtt=0);
  HRESULT SaveRepository(const char *tmp=0);
  HRESULT Rollback();
  HRESULT Commit(int iNoEvent);
  
/**
 * Retrieves if one has the right to create new DLNames.
 * <br><b>Role</b>:  Retrieves the value of the parameter describing if one has 
 * the right to create new DLNames in the current list.
 * @param oRight
 *     TRUE if the creation is authorized.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT GetDLNameCreationRight (unsigned char &oRight);
  

/**
 * Sets the creation right.
 * <br><b>Role</b>:  Sets the right to create new DLNames in the current list.
 * @param iRight
 *     TRUE if the creation is authorized, FALSE to forbid it
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT SetDLNameCreationRight (unsigned char iRight);


/**
 * Retrieves the state of the parameter DLNameCreationRight
 * <br><b>Role</b>:  Retrieves the state of the parameter describing if one has 
 * the right to create new DLNames in the current list.
 * @param oInfo
 *     Address of an object CATSettingInfo.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT GetDLNameCreationRightInfo (CATSettingInfo *oInfo);
  
/**
 * Locks or unlocks the parameter DLNameCreationRight
 * <br><b>Role</b>:  Locks or unlocks the parameter describing if one has 
 * the right to create new DLNames in the current list,if the  operation is 
 * allowed in the current administrated environment. In user mode  this method
 * will always return E_FAIL.
 * @param iLocked
 *	the locking operation to be performed
 *	<b>Legal values</b>:
 *	<br><tt>1 :</tt>   to lock the parameter.
 * 	<br><tt>0:</tt>   to unlock the parameter.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT SetDLNameCreationRightLock (unsigned char iLock);


/**
 * Retrieves if one has the right to create new Root DLNames.
 * <br><b>Role</b>:  Retrieves the value of the parameter describing if one has 
 * the right to create new Root DLNames in the current list.
 * @param oRight
 *     TRUE if the creation is authorized.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT GetRootDLNameCreationRight (unsigned char &oRight);
  

/**
 * Sets the creation right.
 * <br><b>Role</b>:  Sets the right to create new DLNames in the current list.
 * @param iRight
 *     TRUE if the creation is authorized, FALSE to forbid it
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT SetRootDLNameCreationRight (unsigned char iRight);


/**
 * Retrieves the state of the parameter RootDLNameCreationRight
 * <br><b>Role</b>:  Retrieves the state of the parameter describing if one has 
 * the right to create new Root DLNames in the current list.
 * @param oInfo
 *     Address of an object CATSettingInfo.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT GetRootDLNameCreationRightInfo (CATSettingInfo *oInfo);
  
/**
 * Locks or unlocks the parameter RootDLNameCreationRight
 * <br><b>Role</b>:  Locks or unlocks the parameter describing if one has 
 * the right to create new Root DLNames in the current list,if the  operation is 
 * allowed in the current administrated environment. In user mode  this method
 * will always return E_FAIL.
 * @param iLocked
 *	the locking operation to be performed
 *	<b>Legal values</b>:
 *	<br><tt>1 :</tt>   to lock the parameter.
 * 	<br><tt>0:</tt>   to unlock the parameter.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT SetRootDLNameCreationRightLock (unsigned char iLock);


/**
 * Retrieves the list of the DLNames.
 * <br><b>Role</b>: Retrieves the list of the defined DLNames.
 * @param oNbDLname
 *	The number of defined DLNames.
 * @param oTabDLName
 *	The array of DLNames
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 *	<br><tt>E_OUTOFMEMORY:</tt> on allocation failure
 * 	<br><tt>E_FAIL:</tt>  on other failures
*/
  HRESULT GetDLNameList ( unsigned int *oNbDLname,
			  CATUnicodeString **&oTabDLName);


/**
 * Retrieves the list of the Sub-DLNames.
 * <br><b>Role</b>: Retrieves the list of the DLNames created in a given DLName.
 * @param iDLName
 *      The Father DLName. if iDLName=NULL all DLNames created at the root level
 *      are return.
 * @param oNbDLname
 *	The number of defined DLNames.
 * @param oTabDLName
 *	The array of DLNames
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 *	<br><tt>E_OUTOFMEMORY:</tt> on allocation failure
 * 	<br><tt>E_FAIL:</tt>  on other failures
*/
  HRESULT GetDLNameSubList ( CATUnicodeString* iDLName,
			     unsigned int *oNbDLname,
			     CATUnicodeString **&oTabDLName);

/**
 * Retrieves the mapping between a logical name and the physical path.
 * <br><b>Role</b>: Retrieves the mapping between a logical name and 
 * the physical path.
 * @param iDLName
 *	the logical name.
 * @param oRealNameUnix
 *	the real physical path corresponding to the logical name on Unix.
 * @param oRealNameNT
 *	the real physical path corresponding to the logical name on Windows.
 *@param iFather
 *	if applicable the Name of the parent DLName
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  HRESULT GetDLNameExp(const CATUnicodeString *iDLName, 
		       CATUnicodeString **oRealNameUnix,
		       CATUnicodeString **oRealNameNT,
		       CATUnicodeString **oFather);
  
/**
 * Retrieves the mapping between a logical name and the physical path.
 * <br><b>Role</b>: Retrieves the mapping between a logical name and 
 * the physical path expressed in a literal format.
 * @param iDLName
 *	the logical name.
 * @param oRealNameUnix
 *	the real physical path corresponding to the logical name on Unix.
 * @param oRealNameNT
 *	the real physical path corresponding to the logical name on Windows.
 *@param iFather
 *	if applicable the Name of the parent DLName
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  HRESULT GetDLName(const CATUnicodeString *iDLName, 
		    CATUnicodeString **oRealNameUnix,
		    CATUnicodeString **oRealNameNT,
		    CATUnicodeString **oFather);

/**
 * Sets the mapping between a logical name and the physical path.
 * <br><b>Role</b>: Sets the value of the cache maximum size in Mo
 * @param iDLName
 *	the logical name.
 * @param oRealNameUnix
 *	the real physical path corresponding to the logical name on Unix.
 * @param oRealNameNT
 *	the real physical path corresponding to the logical name on Windows.
 *@param iFather
 *	if applicable the Name of the parent DLName
 *@param iVerifDirectory
 *	if VerifDirectory is set the existence of the directory on the current
 *      platform will be check.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  HRESULT SetDLName(const CATUnicodeString *iDLName, 
		    const CATUnicodeString *iRealNameUnix,
		    const CATUnicodeString *iRealNameNT,
		    const CATUnicodeString *iFather,
		    int iVerifDirectory=0);
  
  
/**
 * Retrieves the state of the for a given DLName.
 * @param oInfo
 *	Address of an object CATSettingInfo.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  HRESULT GetDLNameInfo (const CATUnicodeString *iDLName,
			 CATSettingInfo* oInfo);
  
/** 
 * Locks or unlocks the DLName
 * <br><b>Role</b>: Locks or unlocks the given DLName if the
 * operation is allowed in the current administrated environment. In user mode 
 * this method will always return E_FAIL.
 * @param iLocked
 *	the locking operation to be performed
 *	<b>Legal values</b>:
 *	<br><tt>1 :</tt>   to lock the parameter.
 * 	<br><tt>0:</tt>   to unlock the parameter.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  HRESULT SetDLNameLock (const CATUnicodeString *iDLName,
			 unsigned char iLock);


/**
 * Remove a logical name.
 * <br><b>Role</b>: Remove a DLName in the current set if it is possible.
 * @param iDLName
 *	the logical name.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  HRESULT RemoveDLName(const CATUnicodeString *iDLName);

/**
 * Rename an existing DLName.
 * <br><b>Role</b>: Rename a DLName in the current set if it is possible.
 * @param iDLName
 *	the logical name to rename.
 * @param iNewName
 *	the new logical name.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  HRESULT RenameDLName(const CATUnicodeString *iDLName,
		       const CATUnicodeString *iNewName);




 HRESULT RetrieveDLNameInfo(const CATUnicodeString *iDLName,
			    int iType, CATUnicodeString *ioStr=0,
			    void** oMode=0, DWORD *oType=0 );


 HRESULT ReversePathToDLName( CATUnicodeString *iPath, 
			      CATUnicodeString **oDLName );
 HRESULT GetDLNameNumber (unsigned int* oNumber); 

 virtual HRESULT Dump(char **iList=NULL, unsigned int iNb=0);
  

};




#endif


