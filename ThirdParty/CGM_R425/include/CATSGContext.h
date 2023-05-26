#ifndef CATSGContext_H
#define CATSGContext_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "SGComposites.h"

#include "CATIOLogger.h"

#include "CATSGResourcesManager.h"
#include "CATSGCompositesFactory.h"

#include "CATSGCompositeRing.h"
#include "CATSGComposite.h"

#include "CATSGManager.h"
#include "CATIOAtomics.h"

#include "CATSGOptionManager.h"
#include "CATSGProfiler.h"
#include "CATSGPLMHelper.h"
#include "CATCompThreadLocalStorage.h"
#include "CATIOManager.h"

#include <stdio.h>
#include <atomic>
#include <mutex>
#include <vector>

#if (defined(DEBUG) || defined(_DEBUG))
#define SG_COMPOSITES_DEBUG
#endif // DEBUG

class CATSGContext;

/**
 * This class is meant to be a singleton that everyone can access from everywhere. It will
 * also bear several managers that might be usefull to bring in context specific behaviors.
 */
class ExportedBySGComposites CATSGContext
{
protected:
  CATSGContext();
  ~CATSGContext();
public:
  inline int AddRef()
  {
      return _refCount.fetch_add(1) + 1;
  }
  inline int Release()
  {
      int rc = _refCount.fetch_sub(1) - 1;
      if (rc <= 0)
          delete this;
      return rc;
  }

  /**
   * Set an association between something and a SG context.
   * See GetExternalAssocation for further details on why you should do so.
   */
  static HRESULT SetExternalAssociation(void* iExt, CATSGContext* iContext);

  /**
   * Removes the association between something and an sg context.
   * See GetExternalAssociation for further information.
   */
  static HRESULT RemoveExternalAssociation(void* iExt, CATSGContext* iContext);

  /**
   * Use this method to retrieve a specific sg context that you might have previously associated
   * with... something. This method is for example used to retrieve a specific sg context that
   * would have been associated with a specific viewpoint by a workbench that need a context
   * to handle that specific viewpoint.
   * The association must have been put in place through SetExternalAssociation before !
   */
  static HRESULT GetExternalAssociation(void* iExt, CATSGContext*& oAssociatedContext);

  /**
   * Performs the association between an execution context and a sg context.
   * Check comments of Create method for further details.
   */
  static HRESULT SetAssociation(CATExContext iCtx, CATSGContext* iContext);

  /**
   * Removes an association between the execution context and a sg context.
   * Check comments of Create method for further details.
   */
  static HRESULT RemoveAssociation(CATExContext iCtx);

  /**
   * Use this method to create a new instance of a CATSGContext that you can
   * associate with whatever you need using SetExternalAssociation or to a specific
   * thread or flow of execution with SetAssociation. Clearly if you use SetAssociation
   * this should most probably be done for a specific period of time and you should take
   * care removing the association when appropriate.
   */
  static CATSGContext* Create();

  /**
   * Release all static contexts (including s_default, s_nre, and s_other).
   */
  static void TerminateAllContexts();

  /**
   * Use this static method to get the current context associated with the specified execution context.
   * In practice the execution context is something more or less associated with each thread or execution flow thus
   * you should use this method only in places where you know you want to retrieve the execution
   * context associated with the current stack or flow of execution....
   *
   * This method will return only contexts that have been explicitly associated with the thread or flow of execution
   * by a call to SetAssociation.
   *
   * If there is no such association in place then you will get the default / fall back context which is the context
   * you will also always get through CATSGContext::Get(0).
   * So if you know you are in a situation where you don't want or should not fall back on the default you can test
   * it through IsDefault method.
   */
  static CATSGContext& Get(CATExContext iCtx);

  /**
   * See comments in Get static method.
   */
  bool IsDefault() { return (this == s_default); }

  /**
   * This method allows you to set the desired resource manager. The resource manager
   * provides central services to manage resources used by the scene graph (avoid caching stuff
   * several times....)
   */
  HRESULT SetSGResourcesManager(CATSGResourcesManagerPtr iIOManager);

  /**
   * This method will return to you the resource manager. If you don't plan to reclaim ownership of
   * it which I assume you won't, you should be careful to assign this to a local scoped ref to the ptr.
   */
  CATSGResourcesManagerPtr& GetSGResourcesManager();

  /**
   * Clearly not allowed at this time. Will return an E_INVALIDSTATE !
   */
  HRESULT SetSGCompositesFactory(CATSGCompositesFactoryPtr iCompositesFactory);

  /**
   * Will return the factory through which you should allocate your composites as well
   * as all the CATSGComposites (array) that you might want to use in your code.
   */
  CATSGCompositesFactoryPtr& GetSGCompositesFactory();

  /**
   * This method let's 'client' code provide it's own scene manager so that it can
   * customize the current behavior. Obviously we don't everyone to fight to provide
   * it's own manager. So before setting your own please check if there is already
   * a manager in place. If there is please try to see which one it is and find an
   * appropriate solution with the people in charge of that manager. I will be happy
   * to know about it also if you face that type of situation.
   */
  HRESULT SetSGManager(CATSGManagerPtr iSceneManager);

  /**
   * Method to get the currently set scene manager if there is one.
   */
  CATSGManagerPtr& GetSGManager();

  /**
   * Method to specify the IO manager to be used. Use this with care, there is
   * already a default IO manager set and other client code might expect the
   * behavior of that default IOManager. So before setting your one, like for scene manager
   * please come and see me to discuss what you want to achieve.
   */
  HRESULT SetIOManager(CATIOManagerPtr iIOManager);

  /**
   * Method will return the currently set IOManager. There is a default one provided
   * so if no client code did set anything on the context you will still get that default
   * IOManager.
   */
  CATIOManagerPtr& GetIOManager();

  /**
   * TODO: Change this. We want a TimeManager with more functionality instead of this.
   */
  std::int64_t          GetTimeStamp();

  /**
   * @nodoc
   */
  HRESULT SetSGOptionManager(CATSGOptionManagerPtr iSGOptionManager);

  /**
  * @nodoc
  */
  CATSGOptionManagerPtr& GetSGOptionManager();

  /**
  * @nodoc
  */
  HRESULT SetThreadLocalStorage(CATCompThreadLocalStoragePtr iTLS);

  /**
  * @nodoc
  */
  CATCompThreadLocalStoragePtr& GetThreadLocalStorage();

  /**
   * Sometime you need a little help from above your head :).
   * The CATSGPLMHelper is just that, a formalization of what
   * the scene graph might wnat to get back about the model
   * which gave birth to the current scene graph nodes.
   * Because the SG should not have dependencies on these model
   * layers it is fair to allow the SG to get back information only
   * through a CATSGPLMHelper that only a model a applicative
   * layer might have chosed to provide and on which they will
   * retain full control.
   */
  HRESULT SetSGPLMHelper(CATSGPLMHelperPtr iPLMHelper);

  /**
   * See comments in SetSGPLMHelper. This method allows you to retrieve
   * any CATSGPLMHelper that might have been provided by a model or applicative
   * layer.
   */
  CATSGPLMHelperPtr& GetSGPLMHelper();

  /**
   * Allows anyone to set a specific profiler to match it's needs. Will
   * have to respect the CATSGProfiler interface though :).
   */
  HRESULT SetSGProfiler(CATSGProfilerPtr iProfiler);

  /**
   * Returns the CATSGProfiler currently attached to the context. It
   * might be useful both to profile execution time while developing
   * but might also provided interesting services while running if you
   * need to tune some values or your behaviors based on how long it
   * takes to perform specific actions.
   *
   * The CATSGProfiler also act as a provider of time related information
   * (ex. current time) and as a factory for timers.
   */
  CATSGProfilerPtr& GetSGProfiler();

#ifdef SG_COMPOSITES_DEBUG
  /**
  * Log an error message to debugger console.
  */
  HRESULT LogError(const char* iErrorMsg)
  {
      _logger.LogI(iErrorMsg);
      _logger.LogI("\n");
      return S_OK;
  }
  HRESULT LogError(const char* iErrorMsg, CATSG::int32 iValue)
  {
      _logger.LogI(iErrorMsg, iValue);
      return S_OK;
  }
  HRESULT LogError(const char* iErrorMsg, CATSG::uint32 iValue)
  {
      _logger.LogI(iErrorMsg, iValue);
      return S_OK;
  }
  HRESULT LogError(const char* iErrorMsg, const char* iInfo)
  {
      _logger.LogI(iErrorMsg);
      _logger.LogI(iInfo);
      _logger.LogI("\n");
      return S_OK;
  }
  HRESULT LogError(const char* iErrorMsg, double iValue1, double iValue2, double iValue3)
  {
      _logger.LogI(iErrorMsg, iValue1, iValue2, iValue3);
      return S_OK;
  }
  HRESULT LogError(const char* iErrorMsg, double iValue)
  {
      _logger.LogI(iErrorMsg, iValue);
      return S_OK;
  }
#else // SG_COMPOSITES_DEBUG
  HRESULT LogError(const char* iErrorMsg) { return S_FALSE; }
  HRESULT LogError(const char* iErrorMsg, CATSG::int32 iValue) { return S_FALSE; }
  HRESULT LogError(const char* iErrorMsg, CATSG::uint32 iValue) { return S_FALSE; }
  HRESULT LogError(const char* iErrorMsg, const char* iInfo) { return S_FALSE; }
  HRESULT LogError(const char* iErrorMsg, double iValue1, double iValue2, double iValue3) { return S_FALSE; }
  HRESULT LogError(const char* iErrorMsg, double iValue) { return S_FALSE; }
#endif // SG_COMPOSITES_DEBUG

  /**
   * Allow the user to retrieve a manager he set by himself on the context
   * using the AddExtraManager method. Please note that managers should be
   * composites with the composition mode 'CATECompositionModeParticular'
   * to signify that they can only be linked to a special ring.
   * Traditional managers (e.g. the SGManager) cannot be retrieved by this
   * method.
   */
  HRESULT GetExtraManager(const CATTraitRawInfo& iManagerTraitRawInfo, CATOnStackBorrowBasePtr& oBorrowedManagerPtr);

  /**
   * Links a manager composite to the context for later use.
   * Common managers (e.g. the SGManager) should be linked using
   * their own methods on the context.
   */
  HRESULT AddExtraManager(CATSGCompositePtr iManagerPtr);

  /**
   * Returns the same CATSGContext everytime it is called. To be used for LDH.
   *
   * Note: AddRef has been called automatically on the shared Context. You need to call Release once you are done with it.
   * Note: If you use SetExternalAssociation, Release will be called automatically at the destruction of CATViewer.
   */
  CATSGContext* GetSharedLDHContext();

private:
    static HRESULT InitDefaultContexts();
    HRESULT InitSGResourcesManager();
    HRESULT InitSGCompositesFactory();
    HRESULT InitIOManager();
    HRESULT InitSGOptionManager();
    HRESULT InitThreadLocalStorage();
    HRESULT InitSGProfiler();

private:
  std::atomic<int> _refCount;

  CATSGCompositeRingPtr         _extraManagers;
  CATSGResourcesManagerPtr      _resourcesManager;
  CATSGCompositesFactoryPtr     _compositesFactory;
  CATIOManagerPtr               _ioManager;
  CATCompThreadLocalStoragePtr  _tls;
  CATSGPLMHelperPtr             _plmHelper;
  CATSGOptionManagerPtr         _optionManager;
  CATSGProfilerPtr              _profiler;
  CATSGManagerPtr               _sgManager;

  static std::once_flag         _defaultContextFlag;
  std::once_flag                _resourcesManagerFlag;
  std::once_flag                _compositesFactoryFlag;
  std::once_flag                _ioManagerFlag;
  std::once_flag                _tlsFlag;
  std::once_flag                _optionManagerFlag;
  std::once_flag                _profilerFlag;

  CATIOLogger _logger;

  static CATSGContext*              s_default; // This context is for more widely used SG customizations with strong performance requirements.
  static CATSGContext*              s_nre; // We have a special one for NRE as by essence they often want to affect all viewpoints...
  static CATSGContext*              s_other; // This context is for temporary or very optional SG customizations.
  static std::vector<CATSGContext*> s_defaults; // <- map of internal associations (ThreadId <-> Context)
  static std::vector<CATExContext>  s_defaultsIds;
  static CATIOAtomicReadWriteLock   s_defaults_lock;
  static std::vector<CATSGContext*> s_defaultsExt; // <- map of external associations (Viewer <-> Context)
  static std::vector<void*>         s_defaultsExtIds;
  static CATIOAtomicReadWriteLock   s_defaultsExt_lock;
  static CATSGContext*              s_sharedLDHContext;
  static CATIOAtomicLock            s_sharedLDHContext_lock;

  std::int64_t              _timerFreqInCountPerMilliSecond;

  CATIOAtomicLock           _sgCtxLock;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // CATSGContext_H

