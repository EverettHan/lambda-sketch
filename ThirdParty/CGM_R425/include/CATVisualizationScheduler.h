// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATVisualizationScheduler.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Apr 2003  Creation: jov
//===================================================================
#ifndef CATVisualizationScheduler_H
#define CATVisualizationScheduler_H

#include "SGInfra.h"
#include "CATVisualizationResources.h"
#include <mutex>
#include <functional>
#include <atomic>

#if defined (_LINUX_SOURCE) || defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE)
#ifndef _NO_X11_SOURCE
#include <Xm/Xm.h>
#endif
#endif

class CATGraphicWindow;
class CATSupport;
class CATFrameManager;
class CATCacheOfDestroyedElements;
class CATGraphicPrimitive;
class CATGraphicMaterial;
class VisMaterialApplication;
class VisMaterial;
class CATMaterialIBLParameters;
class CATVisuContextManager;
class CATVizPrimitive;
class CATVizVertexBuffer;
class CATVizPrimitiveSet;
class l_CATVisFilter;
class VisPrimitive;
class VisRawBuffer;
class vDrawInformation;
class vIVertexAssembly;
class IVisTexturePtr;
class IVisTexture;
class CATVisualizationDeferredScheduler;
class CATFrameManager;
class CATPassIterator;
class vDrawDescDeferredDestroyer;
class CATVizResourcePool;
//-----------------------------------------------------------------------

/**
 *
 */
class ExportedBySGInfra CATVisualizationScheduler
{
public:
  typedef std::function<void()> GenericDelayedDestructor;

  // Standard destructor
  // -------------------
  virtual ~CATVisualizationScheduler();

  void Draw(CATSupport *i_prGW);
  void DrawRequest(CATGraphicWindow *i_prGW);
  void DrawDeferredRequest(CATGraphicWindow *i_prGW = nullptr);
  void DoDrawJob();
  void AddRef();
  void Release();

  void SetNewAlgoOnGW(CATGraphicWindow* i_prGW);
  static void SetCacheOfDestroyedElements(CATCacheOfDestroyedElements* i_pCache);
  static CATCacheOfDestroyedElements* RenewCacheOfDestroyedElements();
  static unsigned long ReleaseSafelyCacheOfDestroyedElements(CATCacheOfDestroyedElements* i_pCache);
  static inline CATCacheOfDestroyedElements* GetCacheOfDestroyedElements() { return _s_pCurrentCache; }
  static inline CATCacheOfDestroyedElements* GetReleasingCacheOfDestroyedElements() { return _s_pReleasingCache; }


  //accessor
  inline short GetMultithreadFlag() const;
  /**
  * Call with +1 to increase count.
  * Call with -1 to decrease count.
  * When count is == 0, mutex is not active.
  * When count is > 0, mutex is active.
  */
  inline void IncrementMultithreadFlag(const short iAddedValue);
  CATFrameManager* GetFrameManager();

  inline CATVizResourcePool* GetResourcePool();

  void LockDrawRequest(int iIsLock);
  int  IsDrawLocked();

  static CATVisualizationScheduler* GetInstance();
  static CATVisualizationScheduler* CreateInstance();
  static CATVisuContextManager* GetContextManager();
  static CATVisuContextManager* IsThereAContextManager();
  static void LockCachedDestructions();
  static void UnlockCachedDestructions();
  static int DestroyGP(CATGraphicPrimitive *i_pGP);
  static int DestroyMaterial(CATGraphicMaterial *i_pMaterial);
  static int DestroyMaterial(VisMaterial *i_pMaterial);
  static int DestroyMaterialApplication(VisMaterialApplication *i_pMaterialApplication);
  static int DestroyIBLParameters(CATMaterialIBLParameters *i_pParams);
  static int DestroyVizPrimitive(CATVizPrimitive *i_pVizPrimitive);
  static int DestroyVertexBuffer(CATVizVertexBuffer *i_pVertexBuffer);
  static int DestroyPrimitiveSet(CATVizPrimitiveSet *i_pPrimitiveSet);
  static int DestroyMallocedFloat(float *i_pFloat);
  static int DestroyNewedFloat(float *i_pFloat);
  static int DestroyFilter(l_CATVisFilter *i_pFilter);
  static int DestroyVisPrimitive(VisPrimitive *i_pVisPrimitive);
  static int DestroyVisRawBuffer(VisRawBuffer *i_pVisRawBuffer);
  static int DestroyDrawInformation(vDrawInformation *i_pDrawInformation);
  static int DestroyVertexAssembly(vIVertexAssembly *i_pVertexAssembly);
  static int DestroyIVisTexture(IVisTexture* i_pTexture);
  static int DestroyDrawDescDeferredDestroyer(vDrawDescDeferredDestroyer* i_pDrawDescDeferredDestroyer);

  static bool IsStoredGP(CATGraphicPrimitive* i_pGP);
  static bool IsStoredMaterial(CATGraphicMaterial* i_pMaterial);
  static bool IsStoredMaterial(VisMaterial* i_pMaterial);
  static bool IsStoredMaterialApplication(VisMaterialApplication* i_pMaterialApplication);
  static bool IsStoredIBLParameters(CATMaterialIBLParameters* i_pParams);
  static bool IsStoredVizPrimitive(CATVizPrimitive* i_pVizPrimitive);
  static bool IsStoredVertexBuffer(CATVizVertexBuffer* i_pVertexBuffer);
  static bool IsStoredPrimitiveSet(CATVizPrimitiveSet* i_pPrimitiveSet);
  static bool IsStoredMallocedFloat(float* i_pFloat);
  static bool IsStoredNewedFloat(float* i_pFloat);
  static bool IsStoredFilter(l_CATVisFilter* i_pFilter);
  static bool IsStoredVisPrimitive(VisPrimitive* i_pVisPrimitive);
  static bool IsStoredVisRawBuffer(VisRawBuffer* i_pVisRawBuffer);
  static bool IsStoredDrawInformation(vDrawInformation* i_pDrawInformation);
  static bool IsStoredVertexAssembly(vIVertexAssembly* i_pVertexAssembly);
  static bool IsStoredIVisTexture(IVisTexture* i_pTexture);
  static bool IsStoredDrawDescDeferredDestroyer(vDrawDescDeferredDestroyer* i_pDrawDescDeferredDestroyer);
  // @return true if any frame still nedds a draw
  static bool NeedDrawEvent();

  static int RegisterGenericDelayedDestructor(GenericDelayedDestructor iDestructor);

#if defined (_LINUX_SOURCE) || defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE)
#ifndef _NO_X11_SOURCE
  void SetAppContext(XtAppContext appContext);
#endif
#endif

private:
  // Private constructor. Use GetInstance() instead, to obtain the singleton object.
  // -------------------------------------------------------------------------------
  CATVisualizationScheduler();
  // Copy constructor and equal operator
  // -----------------------------------
  CATVisualizationScheduler(CATVisualizationScheduler &);
  CATVisualizationScheduler& operator=(CATVisualizationScheduler&);

  static std::atomic<CATVisualizationScheduler*> _pInstance;

  CATFrameManager* _paFrameManager;

  CATMutex _multithreadFlagMutex;
  std::atomic<short> _multithreadFlag;
  short _updateState;
  short _onCulling;
  short _updateStateSave;
  short _onCullingSave;

  int   _cRef;

  static CATVisuContextManager* GetVisuContextManager();
  static unsigned long __ReleaseCacheOfDestroyedElements(CATCacheOfDestroyedElements* i_pCache);
  static void __SetCacheOfDestroyedElements(CATCacheOfDestroyedElements* i_pCache);

protected:
  static CATCacheOfDestroyedElements* _s_pCurrentCache;
  static CATCacheOfDestroyedElements* _s_pReleasingCache;
  static short _s_cacheManuallyLocked;
  static std::recursive_mutex _s_mutex;
  static CATVisuContextManager* _pVisuContextManager;
  //Useful to known whether or not a draw request is taken into account or not. 
  int _IsDrawLocked;
};

//-----------------------------------------------------------------------

inline short CATVisualizationScheduler::GetMultithreadFlag() const
{
  return _multithreadFlag;
}

inline void CATVisualizationScheduler::IncrementMultithreadFlag(const short iAddedValue)
{
  CATMutexFastLock(&_multithreadFlagMutex);
  _multithreadFlag += iAddedValue;
  CATMutexFastUnlock(&_multithreadFlagMutex);
}

inline CATVizResourcePool* CATVisualizationScheduler::GetResourcePool()
{
  return nullptr;
}

#endif
