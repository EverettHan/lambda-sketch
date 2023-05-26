#ifndef CATVisGPUStorageManager_H
#define CATVisGPUStorageManager_H

// Copyright Dassault Systemes 2005

#include "SGInfra.h"

#include "CATMutex.h"
#include "CATVisGPUStorage.h"
#include "list.h"
#include "CATVisBaseEnv.h"

#define INVALID_STORAGEID      0x7fffffff  //max value for a 31 bits unsigned int 

class CATVisuContext;

/**
  *  This class is dedicated to the memory management of objects (hereafter named storages) that can be stored directly 
  *  into the GPU memory space: it mainly focuses on OpenGL display lists and OpenGL vertex buffer objects, but other usages 
  *  can be implemented. It is linked to a @href CATVisuContext object that represents the context in which storages are created.
  */
extern unsigned short IsOpenGLExtensionPresent(const char *);

class ExportedBySGInfra CATVisGPUStorageManager
{

public:

  // Gpu resource type for new render engine
  static const unsigned int s_VertexStreamType = 0;
  static const unsigned int s_IndexStreamType = 1;
  static const unsigned int s_PrimitiveType = 2;
  static const unsigned int s_RawBufferType = 3;
  
  /**
   *  Creates a new @href CATVisGPUStorageManager associated to the specified @href CATVisuContext.
   */
  CATVisGPUStorageManager(CATVisuContext* ipContext);
  virtual ~CATVisGPUStorageManager();
  
  /**
   *  Specifies the number of memory spaces the @href CATVisGPUStorageManager manages. 
   *  The memory allocated for storages creation is shared among all memory spaces.
   *  By default, there is only one memory space managed by the @href CATVisGPUStorageManager.
   *  Warning! This method has to be called once and for all before any storage is created.
   */
  static void SetNumberOfMemorySpaceToManage(unsigned int iNumberOfMemorySpace);

  /**
   *  Retrieves the number of memory spaces the @href CATVisGPUStorageManager manages. 
   */
  static unsigned int GetNumberOfMemorySpaceManaged();

  /**
   *  Creates a new @href CATVisGPUStorage associated to this manager.
   *  If iStorageID is equal to zero, a new ID is generated; otherwise, the storage memory of the manager may be increased in order
   *  to be able to handle the specified storage ID; this ID is then returned unchanged.
   */
  unsigned int CreateStorage(unsigned int iStorageID, unsigned int iMemorySpace=0);

  /**
   *  Returns the @href CATVisGPUStorage object specified by the iStorageID
   *  input parameter.
   *  This method returns a NULL pointer if the ID is not handled by the
   *  manager.
   */
   CATVisGPUStorage* GetStorage(unsigned int iStorageID, unsigned int iMemorySpace=0);

  /**
   *  Call this method to increase the frame counter associated to
   *  the manager.
   */
   void IncreaseFrameCounter(void);

  /**
   *  Retrieves the frame counter associated to the manager.
   */
   unsigned short GetFrame();

  /**
   *  Updates the frame counter associated to the storage which ID
   *  is specified by the iStorageID input parameter.
   */
  inline void UpdateFrameCounterOnStorage(unsigned int iStorageID, unsigned int iMemorySpace=0);

  /**
   *  When a storage is associated to the manager, its free memory size
   *  is decreased by that of the new storage to handle.
   */
  inline void DecreaseMemFree(float iSize);

  /**
   *  When a storage is removed from the manager, its free memory size
   *  is increased by that of the removed storage.
   */
  inline void IncreaseMemFree(float iSize);

  /** no doc
  */
  inline void setMemFree(float memFree);

  /**
   *  Checks if the manager has enough free memory left, to create a new
   *  storage which size is specified by the iSize input parameter.
   *  This method returns 0 if there is not enough free memory left.
   *  Otherwise, the free memory left value is returned.
   */
  inline float CheckMemFree(float iSize);

  /**
   *  Call this method to explicitly ask the manager to refresh all the
   *  storages it manages (if iFlag is not equal to zero), or to confirm that
   *  all the storages have been refreshed (if iFlag is equal to zero).
   */
  inline void RefreshStorages(unsigned int iFlag);

  /**
   *  Retrieves the refresh flag associated to the manager.
   */
  inline unsigned int RefreshStoragesNeeded();

  

  /**
   *  Call this method to signal the manager that the specified storage can
   *  be deleted.
   */
  void DestroyStorage(unsigned int iStorageID, unsigned int iMemorySpace=0);

  /**
   *  Call this method to signal the manager that all its storages can
   *  be deleted.
   */
  void DestroyAllStorages();

  /**
   *  Call this method to signal the manager that all its unused storages can
   *  be deleted.
   */
  void DestroyAllUnusedStorages();

  /**
   *  Call this method to signal all the created managers that a storage can
   *  be reseted.
   */
  static void sResetStorageInAllManagers(unsigned int iStorageID, unsigned int iMemorySpace=0);
  
  /**
   *  Call this method to signal all the created managers that a storage can
   *  be deleted.
   */
  static void sFreeStorageInAllManagers(unsigned int iStorageID, unsigned int iMemorySpace=0);

  /**
   *  Call this method to find the OpenGLID associated to this storage
   *  
   */
  static unsigned int sGetOGLID(unsigned int iStorageID, unsigned int iMemorySpace=0);

  static void sFreeStorageInAllManagers();

	/**
   * call this method to get the mutex of the class
   *  
   */
  static CATMutex* sGetMutex();

  /*
   * Return the number of storage which concern VBO
   */
  inline void GetNbVBO(unsigned int* NbVBO, unsigned int iMemorySpace);

  /*
   *Return the GPU Memory used for VBO
   */
  inline void GetMemoryUsed(unsigned int* MemeorySize, unsigned int iMemorySpace);

  inline void CancelRefreshRequest() { _RefreshFlag = COMMIT_NEEDED; }
  inline void CommitRefreshIfNeeded() { if (_RefreshFlag==COMMIT_NEEDED) _CommitRefresh = 1; _RefreshFlag=0; }
  inline int CommitRefresh() {  return _CommitRefresh;  }
  inline void FinishedCommit() { _CommitRefresh = 0; }
  inline int RefreshStorageRequested() { 
    if(CATVisBaseEnv::IsNewVisu())
      return 0;
    //-- Volatile renderer
    return _RefreshFlag == REFRESH_NEEDED;
  }

protected:

  enum {
    REFRESH_NEEDED = 1,
    COMMIT_NEEDED = 2,
  };

  static void ResizeReusableStorageArray(unsigned int iStorageID, unsigned int iMemorySpace, int WhichStorage=0);
  static unsigned int CheckForStorageReallocation(unsigned int iCurrentMemorySize, unsigned int iMemorySizeToHandle);

  typedef struct _ReusableStorages
  {
    unsigned int* pStorageID;
    unsigned int uiNbStorages;
    unsigned int uiMemNbStorages;
  } ReusableStorages;

  static ReusableStorages* _spReusableStorages;

  static unsigned int* _spStorageID;
  static unsigned int _sNbMemorySpaceManaged;

  static CATMutex _sMutex;

  static list<CATVisGPUStorageManager> _sListOfStorageManager;

  void ResizeStorageArray(unsigned int iMemorySpace);
  void DestroyStorage(CATVisGPUStorage* pStorageToDestroy);

  float _MemFree;
  unsigned int _RefreshFlag;
  unsigned int _CommitRefresh;

  unsigned short _Frame;  

  CATVisuContext* _pAssociatedContext;

  typedef struct _UsableStorages
  {
    CATVisGPUStorage* pStorage;
    unsigned int uiNbStorages;
    unsigned int uiMemNbStorages;
  } UsableStorages;

  UsableStorages* _pStorages;
 
  static ReusableStorages* _pStorageToDestroy;
  friend class CATFrameManager;
};



inline void CATVisGPUStorageManager::UpdateFrameCounterOnStorage(unsigned int iStorageID, unsigned int iMemorySpace)
{
  //++ ODM/OU4/T64 Volatile Renderer

  if(CATVisBaseEnv::IsNewVisu())
    return;

  //-- ODM/OU4/T64 Volatile Renderer

  CATVisGPUStorage* pStorageToUpdate = GetStorage(iStorageID, iMemorySpace);

  if (pStorageToUpdate && pStorageToUpdate->GetFrame() != 0)
  {
    pStorageToUpdate->SetFrame(_Frame);
  }
}

inline void CATVisGPUStorageManager::RefreshStorages(unsigned int iFlag)
{
  _RefreshFlag = iFlag ? REFRESH_NEEDED : 0;
}

inline unsigned int CATVisGPUStorageManager::RefreshStoragesNeeded()
{
  //++ ODM/OU4/T64 Volatile renderer

  if(CATVisBaseEnv::IsNewVisu())
    return 0;

  //-- Volatile renderer

  return _RefreshFlag == COMMIT_NEEDED || _CommitRefresh;
}

inline void CATVisGPUStorageManager::DecreaseMemFree(float iSize)
{
#ifndef GFXMEMAPI
  _MemFree -= iSize;
#endif
}

static int GPU_memInfo=-1;
inline void CATVisGPUStorageManager::IncreaseMemFree(float iSize)
{
#ifndef GFXMEMAPI
  if(GPU_memInfo==-1)
  {
    if (IsOpenGLExtensionPresent("GL_ATI_meminfo"))
      GPU_memInfo = 1;
    else if (IsOpenGLExtensionPresent("GL_NVX_gpu_memory_info"))
      GPU_memInfo = 2;
    else 
      GPU_memInfo = 0;
  }

  if(!GPU_memInfo)
    _MemFree += iSize;
#endif
}

inline void CATVisGPUStorageManager::setMemFree(float memFree)
{
	_MemFree = memFree;
}


inline float CATVisGPUStorageManager::CheckMemFree(float iSize)
{
   if (CATVisBaseEnv::IsVBOInSharedAllowed())
	  return iSize; // function is used as a boolean anyway

#ifdef GFXMEMAPI
   int info[4] = { 0, 0, 0, 0};

   glGetIntegerv( GL_VBO_FREE_MEMORY_ATI, info);
   /*
    printf( "VBO memory info: \n");
    printf( "  %d bytes free\n", info[0]);
    printf( "  %d bytes in largest free block\n", info[1]);
    printf( "  %d bytes free in aux pool\n", info[2]);
    printf( "  %d bytes in largest free block from aux pool\n", info[3]);
    */
   return (float)(info[0]);
#else
  if (iSize > _MemFree) 
  {
    return 0.f;
  }
  else
  {
    return _MemFree;
  }
#endif
}


inline void CATVisGPUStorageManager::GetNbVBO(unsigned int* NbVBO, unsigned int iMemorySpace)
{
  *NbVBO = 0;
  if (_pStorages && iMemorySpace<_sNbMemorySpaceManaged && _pStorages[iMemorySpace].pStorage)
  {
    for(unsigned int j = 0; j<_pStorages[iMemorySpace].uiNbStorages;j++)
    {
      unsigned int storageID = static_cast<unsigned int>(_pStorages[iMemorySpace].pStorage[j].GetID());
      if (storageID!=0 && storageID!=INVALID_STORAGEID)
        (*NbVBO)++;    
    }
  }
}

inline void CATVisGPUStorageManager::GetMemoryUsed(unsigned int* MemeorySize, unsigned int iMemorySpace)
{
  *MemeorySize = 0;
  if (_pStorages && iMemorySpace<_sNbMemorySpaceManaged && _pStorages[iMemorySpace].pStorage)
  {
    for(unsigned int j = 0; j<_pStorages[iMemorySpace].uiNbStorages;j++)
    {
      unsigned int storageID = static_cast<unsigned int>(_pStorages[iMemorySpace].pStorage[j].GetID());
      if (storageID!=0 && storageID!=INVALID_STORAGEID)
        *MemeorySize += _pStorages[iMemorySpace].pStorage[j].GetSize();   
    }
  }
}



#endif

