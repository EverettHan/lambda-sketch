#ifndef CATOmbStorageManager_H
#define CATOmbStorageManager_H

// System
#include "CATUnicodeString.h"
// SystemTS
#include "CATBoolean.h"
#include "CATSysSimpleHashTable.h"
// CATPLMIdentification
#include "CATComponentId.h"
// ObjectModelerCollection
#include "CATOmxOHMap.h"
#include "CATOmxSet.h"
#include "CATOmxSR.h"
// ObjectModelerBase
#include "AC0XXLNK.h"
#include "CATIDocId.h"
#include "CATOmbStorageInfo.h"
#include "CATOmbStorageManagerEnum.h"

class CATStorage;
class CATILockBytes;
class CATILockBytes2;

/**
* @level Protected
* @usage U1
*/

/**
* This class is managing storages of a V5 Document during a save/load operation. 
* <b>Role</b>
* This class is in charge of opening and managing the life cycle to any storages required during a load/save operation. 
* It involved opening the storages, closing, commiting or aborting them. 
* 
*/
class ExportedByAC0XXLNK CATOmbStorageManager
{
public:    


    /** 
    * Static method to retrieve the manager with the given key if it exists. 
    *
    * <br><b>Role</b>: We look for an already known OmbStorageManager with the given Key. If a OmbStorageManager is found, 
    * it is returned and its counter is incremented. 
    *
    * @param iAccessKey [in]
    *   The key of the OmbStgManager to retrieve
    * @param oOmbStorageManager [out]
    *   The retrieved ombStorageManager
    *
    * @return
    *   <code>S_OK</code>   OmbStorageManager found for this key
    *   <code>E_FAIL</code> OmbStorageManager not found. 
    *
    */
    static HRESULT RetrieveOmbStorageManager(const CATUnicodeString& iAccessKey,CATOmbStorageManager*& oOmbStorageManager,CATOmbRootStgContext iRootStgContext);


    /** 
    * Static Method to create a OmbStorageManager for document in File Environment.
    *
    * <br><b>Role</b>: This method first checks if no storage manager exists for the given key, otherwise it asserts. 
    * Then it creates the now OmbStorageManager and returns it. 
    *
    * @param iAccessKey [in]
    *   The key of the OmbStgManager to retrieve
    * @param iFilePath [in]
    *   The path to where the stream of the document is phisically located. 
    *
    * @return
    *   A Non NULL pointer to a new CATOmbStorageManager
    *
    */
    static inline CATOmbStorageManager* CreateOmbStorageManager(const CATUnicodeString& iAccessKey,const CATUnicodeString& iFilePath,CATOmbRootStgContext iRootStgContext)
    {
      return CreateOmbStorageManager(iAccessKey,iFilePath,NULL,NULL,iRootStgContext);
    }

    /** 
    * Static Method to create a OmbStorageManager for document in PDM Environment.
    *
    * <br><b>Role</b>: This method first checks if no storage manager exists for the given key, otherwise it asserts. 
    * Then it creates the now OmbStorageManager and returns it. 
    *
    * @param iAccessKey [in]
    *   The key of the OmbStgManager to retrieve
    * @param iILB [in]
    *   Ths ILB in which the streal of the document can be found.
    * @param ipDocId [in]
    *   This ipDocId contains data for error message creation
    *
    * @return
    *   A Non NULL pointer to a new CATOmbStorageManager
    *
    */
    static inline CATOmbStorageManager* CreateOmbStorageManager(const CATUnicodeString& iAccessKey,CATILockBytes* iILB,CATIDocId * ipDocId, CATOmbRootStgContext iRootStgContext)
    {
      return CreateOmbStorageManager(iAccessKey,NULL,iILB,ipDocId,iRootStgContext);
    }

    static CATOmbStorageManager* CreateOmbStorageManager(const CATUnicodeString& iAccessKey,const CATUnicodeString& iFilePath,CATILockBytes* iILB,CATIDocId * ipDocId, CATOmbRootStgContext iRootStgContext);
  

    /** 
    * Decrements the counter of OmbStorageManager and if necessary frees it. 
    *
    * <br><b>Role</b>: 
    * When counter reaches 0, this method closes all the opened storage and deletes the manager from memory. 
    *  
    * @return
    *   <code>S_OK</code>   Storages are closed and manager is removed. 
    *   <code>E_FAIL</code> unexpected error. 
    *
    */
    HRESULT Remove();


    /**
    * Returns wether a Storage is already known as opened. 
    * @param [in] iStorageUuid
    *     The storage Uuid
    * @param {out] oOpen
    *      <ul> <li> TRUE : the storage is already opened
    *      <li> </ul> FALSE : the storage is not opened. 
    * @return S_OK. 
    */
    HRESULT IsStorageAlreadyOpened(const CATUnicodeString& iStorageUuid,DWORD iReadWriteMode,CATBoolean& oOpen) const;

    /**
    * Returns wether a Storage is already known as opened. 
    * @param [in] iStorage
    *           the storage to check
    * @param [out] oOpen
    *      <ul> <li>  TRUE : the storage is already opened
    *      <li> </ul> FALSE : the storage is not opened. The storage should be closed. 
    * @return S_OK. 
    */
    HRESULT IsStorageAlreadyOpened(CATStorage& iStorage,DWORD iReadWriteMode,CATBoolean& oOpen) const;

    /**
    * Registers a newly opened storage to the CATOmbStorageManager. 
    * An opened storage already registered should not be reregistered. 
    * @param [in] iStorageUuid
    *           The uuid of the storage.
    * @param [in] iStorage
    *           The opened storage.
    * @return S_OK.
    */
    HRESULT RegisterStorageToManager(const CATUnicodeString& iStorageUuid, CATStorage& iStorage,DWORD iReadWriteMode);

    /**
    * Registers a newly opened storage to the CATOmbStorageManager. 
    * An opened storage already registered should not be reregistered. 
    * If possible call the method with the storage uuid. 
    * 
    * @param [in] iStorage
    *           The opened storage.
    * @return S_OK.
    */
    HRESULT RegisterStorageToManager(CATStorage& iStorage,DWORD iReadWriteMode);

    /**
    * Decrements the open counter, if open counters reaches 0, the storage is closed. 
    * @param [in] iStorageUuid 
    *             The Storage uuid.
    * @return
    * <ul>
    *   <li> S_OK : the storage has been closed with success.
    *   <li> E_FAIL : unexpected error while closing the storage/the storage has been closed but was not registered. 
    * </ul>
    */
    HRESULT CloseAStorage(const CATUnicodeString& iStorageUuid);

    /**
    * Decrements the open counter, if open counters reaches 0, the storage is closed. 
    * @param [in] iStorage 
    *             The Storage to be closed.
    * @return
    * <ul>
    *   <li> S_OK : the storage has been closed with success.
    *   <li> E_FAIL : unexpected error while closing the storage/the storage has been closed but was not registered. 
    * </ul>
    */
    HRESULT CloseAStorage(CATStorage& iStorage);

    /**
    * Returns the storage with the given uuid if already opened. 
    * @param [in] iStorageUuid
    *             The storage uuid. 
    * @param [out] opStorage 
    *             The opened storage
    * @return
    * <ul>
    *   <li> S_OK   : the opened storage
    *   <li> E_FAIL : no storage with given uuid is knwon as opened. 
    * </ul>
    */
    HRESULT GetOpenedStorage(const CATUnicodeString& iStorageUuid, CATStorage*& opStorage); 


    /** 
    * Retrieves the opened root Storage in Warmstart mode or opens it in this mode. 
    *
    * <br><b>Role</b>: In WarmStart mode, we are streaming the document in file in a dedicated cache. 
    * Therefore we must use the rollFilePath to open the root storage. 
    * If Storage was already opened in a different mode, the rootstorage and all its substorages are closed first.  
    *
    * This method generates CATSaveLoadError when the rootStorage cannot be opened. 
    *
    * @param opStorage [out]
    *   The retrieved/opened root storage. 
    * @param iFlag [in]
    *    Option for file creation
    *
    * @return
    *   <code>S_OK</code>   The root storage has been correctly opened. 
    *   <code>E_FAIL</code> unexpected error. 
    *   <code>E_xxx</code>  Error code explaining the reason why the root storage cannot be opened. 
    *
    */
    HRESULT OpenRootStorageForWarmstart(CATStorage*& opStorage, DWORD iFlag = 0);


    /**   
    * Retrieves the opened root Storage for read or opens it in this mode. 
    *
    * <br><b>Role</b>: 
    * Check if root storage is already opened on Read or ReadWrite mode and returns it. 
    * Otherwise, opens the root storage for Read. 
    *
    * This method generates CATSaveLoadError when the rootStorage cannot be opened if iRaiseError==TRUE. 
    * During Load of an assembly, error should not be raised if one element cannot be opened. 
    * Error will be catched and throwned as a warning later in the open process. 
    *
    * @param opStorage [out]
    *   The retrieved/opened root storage. 
    * @param iRaiseError [in]
    *   A boolean to control wether error should be raised if root storage cannot be opened. 
    *   <ul><li>   TRUE  : Error is raised.
    *   <li></ul>  FALSE : Error is not raised.
    *     
    * @return
    *   <code>S_OK</code>   The root storage has been correctly opened. 
    *   <code>E_FAIL</code> unexpected error. 
    *   <code>E_xxx</code>  Error code explaining the reason why the root storage cannot be opened. 
    *
    */
    HRESULT OpenRootStorageForRead(CATStorage*& opStorage, CATOmbOnRootStorageError iRule = CATOmbRaiseErrorAndAbort);


    /** 
    * Retrieves the opened root Storage for Read/Write or opens it in this mode. 
    *
    * <br><b>Role</b>:
    * Check if root storage is already opened for ReadWrite mode and returns it. 
    * Otherwise, opens the root storage for Read/Write. When opened in this mode a backup file is created. 
    * Ie : if another stream exists at the given location, the stream will be renamed temporarly. 
    * The temporaty stream will be opened to perform the copy of unloaded Storages. 
    * If storage is commited, the backup file will be removed. If the root storage is aborted, the backup file will
    * replace the current file. 
    *
    * @param opStorage [out]
    *   The retrieved/opened root storage. 
    * @param iFlag [in]
    *    Option for file creation (Support of Large File)
    *
    * @return
    *   <code>S_OK</code>   The root storage has been correctly opened. 
    *   <code>E_FAIL</code> unexpected error. 
    *   <code>E_xxx</code>  Error code explaining the reason why the root storage cannot be opened. 
    *
    */
    HRESULT OpenRootStorageForSave(CATStorage*& opStorage, DWORD iFlag = 0);

    /** 
    * Retrieves the opened root Storage for Read/Write or opens it in this mode. 
    *
    * <br><b>Role</b>:
    * Check if root storage is already opened for ReadWrite mode and returns it. 
    * Otherwise, opens the root storage for Read/Write. When opened in this mode a backup file is created. 
    * Ie : if another stream exists at the given location, the stream will be renamed
    * The temporaty stream will NOT be opened. No need of this tream to perform the copy.  
    * If storage is commited, the backup file will be removed. If the root storage is aborted, the backup file will
    * replace the current file. 
    *
    * @param opStorage [out]
    *   The retrieved/opened root storage.
    * @param iNeedToCopyDRM [in]
    *   Do we need to keep current document DRM or should we ask the DRM user-exit to provide a new set of DRM.
    * @param iSourceOfDRMId
    *   Only us if iNeedToCopyDRM==TRUE : Id to access the DRM that have to be copied
    * @param iFlag [in]
    *    Option for file creation (Support of Large File)
    *
    * @return
    *   <code>S_OK</code>   The root storage has been correctly opened. 
    *   <code>E_FAIL</code> unexpected error. 
    *   <code>E_xxx</code>  Error code explaining the reason why the root storage cannot be opened. 
    *
    */
    HRESULT OpenRootStorageForSaveAs(CATStorage*& opStorage,CATBoolean iNeedToCopyDRM,CATUnicodeString& iSourceOfDRMId, DWORD iFlag = 0);


    /** 
    * Retrieves the opened root Storage for Read/Write or opens it in this mode. 
    *
    * <br><b>Role</b>:
    * Check if root storage is already opened for ReadWrite mode and returns it. 
    * Otherwise, opens the root storage for Read/Write. When opened in this mode NO backup file is created. 
    * be carefull: in case of error storage can be damaged 
    * @param opStorage [out]
    *   The retrieved/opened root storage. 
    * @param iFlag [in]
    *    Option for file creation (Support of Large File)
    *
    * @return
    *   <code>S_OK</code>   The root storage has been correctly opened. 
    *   <code>E_FAIL</code> unexpected error. 
    *   <code>E_xxx</code>  Error code explaining the reason why the root storage cannot be opened. 
    *
    */
    HRESULT OpenRootStorageForSaveWithDirectAccess(CATStorage*& opStorage, DWORD iFlag = 0);


    /** 
    * Retrieves the open root storage.
    * 
    * <br><b>Role</b>: 
    *   Asserts if the current mode of the RootStorage is not compatible with Save
    *
    * @param opStorage [out]
    *   The retrieved root Storage, it can be null if the rootstorage is not opened. 
    *
    * @return
    *   <code>S_OK</code> Root Storage is opened and returned. 
    *   <code>E_FAIL</code> Root Storage is closed, opStorage==NULL. 
    *
    */
    HRESULT GetRootStorageForSave(CATStorage*& opStorage);

    /** 
    * Closes all known opened storages cancelling any modification if required. 
    *
    * <br><b>Role</b>: This method closes the root storage. All sub Storage are consequently closed. 
    * HastTable containing opened substorages is then updated. 
    *
    * @param iCancelAllModification [in]
    *   <ul><li>  TRUE  : All modifications are canceled. 
    *   <li></ul> FALSE : Modification are saved. 
    *
    * @return
    *   <code>S_OK</code>   close successfull.
    *   <code>E_FAIL</code> unexpected error. 
    *
    */
    HRESULT CloseAllStorages(CATBoolean iCancelAllModification);


    /** 
    * Commits the Root Storage. 
    *
    * <br><b>Role</b>: Modifications that have been took place in the stream are commited. 
    *
    * @return
    *   <code>S_OK</code>   commit successfull.
    *   <code>E_FAIL</code> unexpected error. 
    *
    */
    HRESULT CommitRootStorage();

    /** 
    * Commits the CATIA1 Storage. 
    *
    * <br><b>Role</b>: Modifications that have been took place in the stream are commited. 
    *
    * @return
    *   <code>S_OK</code>   commit successfull.
    *   <code>E_FAIL</code> unexpected error. 
    *
    */
    HRESULT CommitCATIA1Storage();


    /** 
    * Retrieves or opens the CATIA1 storage in the given ReadWrite Mode. 
    *
    * <br><b>Role</b>: If CATIA1 storage alreasy exists and is in the same mode, it is returned. 
    * Otherwise it is opened using the RootStorage. 
    *
    * @param iReadWriteMode [in]
    *   The Read/Write mode in which the CATIA1 storage should be opened. 
    * @param opStorage [out]
    *   The returned CATIA1Storage. 
    *
    * @return
    *   <code>S_OK</code>   CATIA1 Storage retrieved/opened with success
    *   <code>E_FAIL</code> unexpected error. 
    *
    */
    HRESULT RetrieveCATIA1Storage(DWORD iReadWriteMode, CATStorage*& opStorage);

    void PlugComponentId (const CATComponentId& iCompId);

    CATComponentId & GetComponentId();

    void GetStorageContext(CATComponentId& oCompId, CATOmxSR<CATILockBytes2>& oILB2, CATOmxSR<CATIDocId>& oDocId);

    //returns the mode used to open root storage
    DWORD GetRootStorageOpenMode() { return _rootStorageMode; }

private:

    /** 
    * Internal service that open the root storage according to argument computed in the 
    * higher level services such as OpenRootStgforRead. 
    *
    * <br><b>Role</b>: This method performs the system call that opens a RootStorage. 
    *
    * @param iRootStgReadWriteOpenMode [in]
    *   Read/Write Open Mode. 
    * @param iRootStgMode [in]
    *   0 for open, 1 for opening and copying all streams, 2 for append, 3 for cgr documens. 
    * @param opStorage [out]
    *   the opened storage
    * @param iRaiseError [in]
    *   TRUE : Error will be raised if open fails. 
    *   FALSE : error will not be raised even if open fails. 
    *
    * @return
    *   <code>S_OK</code>   The root storage has been correctly opened. 
    *   <code>E_FAIL</code> unexpected error. 
    *   <code>E_xxx</code>  Error code explaining the reason why the root storage cannot be opened. 
    *
    */
    HRESULT OpenRootStorage(DWORD iRootStgReadWriteOpenMode,int iRootStgMode,CATStorage*& opStorage, CATOmbOnRootStorageError iRule = CATOmbRaiseErrorAndAbort);  

    /** 
    * Computes the UUID of the given storage. 
    *
    * <br><b>Role</b>: Computes the UUID of the given storage. 
    *
    * @param iStorage [in]
    *   The storage those uuid is to be retrieved
    * @param oStgUuid [out]
    *   the uuid of the storage
    *
    * @return
    *   <code>S_OK</code>   uuid retrieved successfully
    *   <code>E_FAIL</code> unexpected error. 
    *
    */
    HRESULT GetStorageUuid(CATStorage& iStorage, CATUnicodeString& oStgUuid) const;


    /** 
    * Sends a CALLBack to the DDT in inform it of a failed OpenRootStg. 
    *
    * <br><b>Role</b>: Sends a CALLBack to the DDT in inform it of a failed OpenRootStg. 
    *
    * @param iCBCase [in]
    *   Id of the type of callback to be sent
    * @param StorageNameOfDocInError [inout]
    *   AccessKey of the OmbStorageManager
    * @param ErrorHR [inout]
    *   error code returned by OpenRootStg
    *
    */
    void DebugTool_DispatchCB(int  iCBCase, CATUnicodeString StorageNameOfDocInError, HRESULT ErrorHR);

    /*
    common methode for OpenRootStorageForSave (use iMode=1) and OpenRootStorageForSavePrivWithDirectAccess (use iMode=2)
    */
    HRESULT OpenRootStorageForSavePriv(CATStorage*& opStorage, DWORD iFlag ,int iMode);

    /**
    * Default constructor
    */
    CATOmbStorageManager(const CATUnicodeString& AccessKey,const CATUnicodeString& FilePath,CATILockBytes* ILB,CATIDocId* ipDocId,CATOmbRootStgContext iRootStgContext);

    // Destructor
    virtual ~CATOmbStorageManager();

    CATOmxSet<CATOmbStorageInfo,sharable_manager> _StoragesHT; // Hashtable to keep storage known as opened
    mutable CATOmxSet<CATStorage, naive_manager> _StoragesSet;// Set of opened applicative CATStorages - IR 370750
    CATUnicodeString  _FilePath ;      // FilePath where the stream is located ("" if stream is in an ILB)
    CATUnicodeString  _AccessKey;      // Key to retrieve the OmbStorageManager
    CATOmxSR<CATIDocId>        _pDocId;

    CATOmxSR<CATILockBytes> _ILB;               // ILB where the stream is located (NULL if stream is in File or in an ILB2)
    CATOmxSR<CATILockBytes2> _ILB2;             // ILB where the stream is located (NULL if stream is in File or in an ILB)
    CATOmbRootStgContext _RootStgContext;

    CATStorage* _pRootStorage;         // pointer to the rootstorage
    DWORD _rootStorageMode = 0;
    CATOmbStorageInfo _CATIAStorage;   // pointer to the compound storage. Also keep its open counter. 

    CATOmbRootStgTransaction 	_TypeOfTransactionOnRootStg; // Corresponding Of Storage ( Storage used for roll or not?)    

    int _CounterInUse;                 // Number of time this OmbStorageManager is been used

    CATComponentId _CompId;            // The component being currently processed
};

#endif
