
#ifndef __CATOmxMlkTracker_h__
#define __CATOmxMlkTracker_h__

// System
#include "IUnknown.h" // HRESULT, IUnknown
// ObjectModelerCollection
#include "CATOmxPortability.h"

#if OMX_CODE_PHASE == 1
// ObjectModelerCollection
#include "CATSysAtomicCounter.h" // CATSysAtomic
#define OMX_MLK_ATOMIC_PRE_INC(v) (CATSysAtomic::pre_inc(v))
#define OMX_MLK_ATOMIC_PRE_DEC(v) (CATSysAtomic::pre_dec(v))
#else
// SystemTS
#include "DSYSysAtomic.h" // get_atomic_ref
#define OMX_MLK_ATOMIC_PRE_INC(v) (dsy::get_atomic_ref(v).fetch_add(1, std::memory_order_relaxed) + 1)
#define OMX_MLK_ATOMIC_PRE_DEC(v) (dsy::get_atomic_ref(v).fetch_sub(1, std::memory_order_acq_rel) - 1)
#endif

// Basic usage.
// Intrusmenting the class MyClass.
//
// MyClass.h
// ---------
//   class MyClass : public BaseClassOfMyClass
//   {
//   public:
//     MyClass::MyClass(...);
//     MyClass::MyClass(MyClass const & iOther);
//     MyClass::~MyClass();
//     
//     ULONG __stdcall MyClass::AddRef();
//     ULONG __stdcall MyClass::Release();
//   };
//
// MyClass.cpp
// -----------
//   OMX_MLK_TRACKER_DEFINE(MyClass);
//
//   MyClass::MyClass(...)
//   {
//     // Either (if the class does NOT have a "tag" member data):
//     OMX_MLK_TRACKER_CREATE(MyClass, this, MyClass::MetaObject());
//     // or (if the class DOES have a "tag" member data):
//     OMX_MLK_TRACKER_CREATE_AND_SET_TAG(MyClass, this, MyClass::MetaObject(), m_Tag);
//     (...)
//   }
//   MyClass::MyClass(MyClass const & iOther)
//   {
//     // Either (if the class does NOT have a "tag" member data):
//     OMX_MLK_TRACKER_CREATE(MyClass, this, MyClass::MetaObject());
//     // or (if the class DOES have a "tag" member data):
//     OMX_MLK_TRACKER_CREATE_AND_SET_TAG(MyClass, this, MyClass::MetaObject(), m_Tag);
//     (...)
//   }
//   MyClass::~MyClass()
//   {
//     (...)
//     OMX_MLK_TRACKER_DESTROY(MyClass, this);
//   }
//
//   ULONG __stdcall MyClass::AddRef()
//   {
//     OMX_MLK_TRACKER_ADDREF(MyClass, *this, m_cRef);
//     return BaseClassOfMyClass::AddRef();
//   }
//   ULONG __stdcall MyClass::Release()
//   {
//     OMX_MLK_TRACKER_RELEASE(MyClass, *this, m_cRef);
//     return BaseClassOfMyClass::Release();
//   }

/** Tracker definition macro. */
#define OMX_MLK_TRACKER_DEFINE(cls) \
  OMX_MLK_TRACKER_BEGIN_DEFINE(cls); \
  OMX_MLK_TRACKER_END_DEFINE(cls)

/** Object creation handling macro, without tag. */
#define OMX_MLK_TRACKER_CREATE(cls, This, Meta) \
  do { \
    CATOmxMlkTracker & tracker = OMX_MLK_TRACKER(cls); \
    CATUINT32 const cls##_MlkTracker_tag = OMX_MLK_ATOMIC_PRE_INC(tracker.m_occurence); \
    if ( cls##_MlkTracker_tag == 1 ) \
      cls##_MlkTracker_Register(tracker, Meta); \
    CATFMIMlkTracker * const leaks = tracker.m_Leaks; \
    if ( leaks ) leaks->OnCreate(*This, cls##_MlkTracker_tag); \
  } while(0)


/** Object creation handling macro, with tag. */
#define OMX_MLK_TRACKER_CREATE_AND_SET_TAG(cls, This, Meta, Tag) \
  do { \
    CATOmxMlkTracker & tracker = OMX_MLK_TRACKER(cls); \
    CATUINT32 const cls##_MlkTracker_tag = OMX_MLK_ATOMIC_PRE_INC(tracker.m_occurence); \
    if ( cls##_MlkTracker_tag == 1 ) \
      cls##_MlkTracker_Register(tracker, Meta); \
    Tag = cls##_MlkTracker_tag; \
    CATFMIMlkTracker * const leaks = tracker.m_Leaks; \
    if ( leaks ) leaks->OnCreate(*This, cls##_MlkTracker_tag); \
  } while(0)

/** Object destruction handling macro. */
#define OMX_MLK_TRACKER_DESTROY(cls, This) \
  do { \
    CATFMIMlkTracker * const leaks = OMX_MLK_TRACKER(cls).m_Leaks; \
    if ( leaks ) leaks->OnDestroy(*This); \
  } while(0)

/** Object AddRef() handling macro. */
#define OMX_MLK_TRACKER_ADDREF(cls, This, Cref) \
  do { \
    CATFMIMlkTracker * const addRefs = OMX_MLK_TRACKER(cls).m_AddRefs; \
    if ( addRefs ) addRefs->OnAddRef(*This, Cref); \
  } while(0)

/** Object Release() handling macro. */
#define OMX_MLK_TRACKER_RELEASE(cls, This, Cref) \
  do { \
    CATFMIMlkTracker * const addRefs = OMX_MLK_TRACKER(cls).m_AddRefs; \
    if ( addRefs ) addRefs->OnRelease(*This, Cref);\
  } while(0)


// Advanced usage.
//
// MyClass.cpp
// -----------
//   static HRESULT MyClassMlkTrackerShouldReport(const CATMetaClass * iMetaObject, const char * iTestFrameworkName)
//   { // Not ready for real activation yet: do not, by default, report the leaks; and limit accidental activation through option files.
//     return S_DISCARD_LIMIT_OVERRIDE;
//   }
//
//   static HRESULT MyClassMlkTrackerPrettyPrint(const IUnknown & iObject, CATOmxMlkTrackerInfoPrinter & ioPrinter)
//   { // WARNING: the process is dying, most objects must have been deleted, do not call any but the most simple methods on iObject or risk a crash!
//     const MyClass & iMyObject = static_cast<const MyClass &>(iObject);
//     ioPrinter.AddInfo("Name", iMyObject.GetName());
//     return S_OK;
//   }
//
//   OMX_MLK_TRACKER_BEGIN_DEFINE(MyClass);
//   OMX_MLK_TRACKER_REGISTER_SHOULDREPORT(&MyClassMlkTrackerShouldReport);
//   OMX_MLK_TRACKER_REGISTER_PRETTYPRINT(&MyClassMlkTrackerPrettyPrint);
//   OMX_MLK_TRACKER_END_DEFINE(MyClass);

/** Tracker definition header macro, for use with the *_REGISTER_* macros. */
#define OMX_MLK_TRACKER_BEGIN_DEFINE(cls) \
  static void cls##_MlkTracker_Register(CATOmxMlkTracker & iThisTracker, CATMetaClass * iMetaObject) \
  { \
    CATOmxMlkTrackerFunctions functions = { OMX_MLK_TRACKER_FUNCTIONS_INIT_VALUES };

/** Pretty-printing function registering macro, see Pretty-printing here-under. */
#define OMX_MLK_TRACKER_REGISTER_PRETTYPRINT(PPFUNC) functions.m_PrettyPrint = PPFUNC

/** Leaks reporting hint function registering macro, see Leaks reporting hint here-under. */
#define OMX_MLK_TRACKER_REGISTER_SHOULDREPORT(SRFUNC) functions.m_ShouldReport = SRFUNC

/** Tracker definition footer macro, for use with the *_REGISTER_* macros. */
#define OMX_MLK_TRACKER_END_DEFINE(cls) \
    CATOmxMlkTracker::Register(iThisTracker, iMetaObject, CATOmxFWString, functions); \
  } \
  CATOmxMlkTracker OMX_MLK_TRACKER(cls)


// Pretty-printing (not litterally though).
// Making the .mlk file more interesting by adding object specific data in the report.

// ObjectModelerCollection
class CATOmxAny;

/** Helper object interface for adding information about leaking objects. */
class CATOmxMlkTrackerInfoPrinter { public: virtual HRESULT AddInfo(const char * iInfoType, const CATOmxAny & iInfoValue) = 0; };

/**
 * Signature for a function used to provide the MlkTracker with additional information to include in the report for leaks.
 * Such a function has to be registered using the OMX_MLK_TRACKER_REGISTER_PRETTYPRINT macro.
 */
typedef HRESULT (*CATOmxMlkTrackerPrettyPrint)(const IUnknown & iObject, CATOmxMlkTrackerInfoPrinter & ioPrinter);


// Leaks reporting hint.
// Reported leaks will appear both in the traces and in the .mlk file and hence most likely will lead to a 111 return code for impacted test cases.
// Discarded leaks, on the other hand, will only appear in the traces in the MlkTracker summary.
// In all cases, the MLK extent can be assessed with OdT impact, see Leaks impact measurement.

// System
class CATMetaClass;

#define S_REPORT_ALLOW_OVERRIDE    ((HRESULT)0x00000000L) // Leaks   WILL   be reported by default, but ANY keywords ("-all", "-fw:", "-IsA:"...) in test frameworks option files will alter this default.
#define S_DISCARD_ALLOW_OVERRIDE   ((HRESULT)0x00000001L) // Leaks will NOT be reported by default, but ANY keywords ("+all", "+fw:", "+IsA:"...) in test frameworks option files will alter this default.
#define S_REPORT_LIMIT_OVERRIDE    ((HRESULT)0x00000002L) // NOT Implemented. Currently reverts to S_REPORT_ALLOW_OVERRIDE.
#define S_DISCARD_LIMIT_OVERRIDE   ((HRESULT)0x00000003L) // Leaks will NOT be reported by default, however (ONLY) the "+IsA:" (or "+type:") keyword in test frameworks option files can alter this default.
#define S_REPORT_PREVENT_OVERRIDE  ((HRESULT)0x00000004L) // NOT intended to ever be implemented. Reverts to S_REPORT_ALLOW_OVERRIDE.
#define S_DISCARD_PREVENT_OVERRIDE ((HRESULT)0x00000005L) // Leaks will NOT be reported, and this behavior will NOT be altered by option files.

/**
 * Signature for a function used to provide the MlkTracker with a runtime hint about what to do with leaks.
 * Such a function has to be registered using the OMX_MLK_TRACKER_REGISTER_SHOULDREPORT macro.
 * @return
 *   S_REPORT_ALLOW_OVERRIDE:    Leaks   WILL   be reported by default, but ANY keywords ("-all", "-fw:", "-IsA:"...) in test frameworks option files will alter this default.
 *   S_DISCARD_ALLOW_OVERRIDE:   Leaks will NOT be reported by default, but ANY keywords ("+all", "+fw:", "+IsA:"...) in test frameworks option files will alter this default.
 *   S_REPORT_LIMIT_OVERRIDE:    NOT Implemented. Currently reverts to S_REPORT_ALLOW_OVERRIDE.
 *   S_DISCARD_LIMIT_OVERRIDE:   Leaks will NOT be reported by default, however (ONLY) the "+IsA:" (or "+type:") keyword in test frameworks option files can alter this default.
 *   S_REPORT_PREVENT_OVERRIDE:  NOT intended to ever be implemented. Reverts to S_REPORT_ALLOW_OVERRIDE.
 *   S_DISCARD_PREVENT_OVERRIDE: Leaks will NOT be reported, and this behavior will NOT be altered by option files.
 */
typedef HRESULT (*CATOmxMlkTrackerShouldReport)(const CATMetaClass * iMetaObject, const char * iTestFrameworkName);


///////////////////////////////////////////////////////////////////
//                                                               //
//    ######  ######    ###   #     #    #    ####### #######    //
//    #     # #     #    #    #     #   # #      #    #          //
//    #     # #     #    #    #     #  #   #     #    #          //
//    ######  ######     #    #     # #     #    #    #####      //
//    #       #   #      #     #   #  #######    #    #          //
//    #       #    #     #      # #   #     #    #    #          //
//    #       #     #   ###      #    #     #    #    #######    //
//                                                               //
// Implementation details.                                       //
// CAUTION: do NOT use/depend on any of the following directly.  //
// Use the macros provided here-above only.                      //
//                                                               //
///////////////////////////////////////////////////////////////////

// ObjectModelerCollection
#include "CATFMIMlkTracker.h"
#include "CATOmxBase.h"
#include "CATOmxMacroExpander.h" // CATOmxFWString
#include "CATOmxPortability.h"


/**
 * @nodoc
 * Signature for a function that will be called when an object AddRef() & Release() calls are to be tracked.
 */
typedef void (*CATOmxMlkTrackerOnTrackedObject)(IUnknown & iData);

/**
 * @nodoc
 * Leaks reporting hint function registering macro, see Leaks reporting hint here-under. */
#define OMX_MLK_TRACKER_REGISTER_ONTRACKEDOBJECT(OTOFUNC) functions.m_OnTrackedObject = OTOFUNC

/**
 * @nodoc
 * Internal ad-hoc structure used to group related parameters.
 */
struct CATOmxMlkTrackerFunctions
{
  CATOmxMlkTrackerOnTrackedObject m_OnTrackedObject;
  CATOmxMlkTrackerPrettyPrint m_PrettyPrint;
  CATOmxMlkTrackerShouldReport m_ShouldReport;
};

// Temporary migration constraint 1: CATPLMDictionary.
#if defined(CATIAR216) && (defined(EnoDicEmofObject_H) || defined(EnoDicClass_h))
#define OMX_MLK_OCCURENCE(cls) (OMX_MLK_TRACKER(cls).m_occurence)
#define OMX_MLK_TRACKER_LEGACY_MEMBERS 1
#define OMX_MLK_TRACKER_FUNCTIONS_INIT_VALUES NULL, iThisTracker.m_PrettyPrintFunction, iThisTracker.m_ShouldTrackFunction
#else
#define OMX_MLK_TRACKER_LEGACY_MEMBERS 0
#define OMX_MLK_TRACKER_FUNCTIONS_INIT_VALUES
#endif

/**
 * @nodoc
 * Internal structure intended to be used to keep a MLK Tracker instance data altogether.
 */
struct CATOmxMlkTracker
{
  // - This structure MUST NOT have a constructor as it is intended to be used as a global variable,
  // and hence will automatically be 0-initialized as per the C standard, and the compiler/linker will most 
  // likely do that by placing it (the global variable) it in the "bss" (or ".bss" or "bss section/segment", 
  // see https://en.wikipedia.org/wiki/.bss article) which is exactly what we need here, otherwise there 
  // could be a "static initialization order fiasco" (https://isocpp.org/wiki/faq/ctors#static-init-order)
  // with static instances of the instrumented class that would start using this structure before its c-tor 
  // is called and overwrites everything.
  // - It MUST NOT have a destructor either since the m_Leaks and m_AddRefs pointers are needed as long as there
  // are still at least one object alive, and the destruction of the last remaining object triggers the clean up.

  CATUINT32 m_occurence;
  CATFMIMlkTracker * m_Leaks;
  CATFMIMlkTracker * m_AddRefs;
#if (OMX_MLK_TRACKER_LEGACY_MEMBERS == 1)
  CATOmxMlkTrackerPrettyPrint m_PrettyPrintFunction;
  CATOmxMlkTrackerShouldReport m_ShouldTrackFunction;
#endif

  ExportedByCATOmxBase static void Register(CATOmxMlkTracker & iThisTracker, CATMetaClass * iMetaObject, const char * iFrameworkName, const CATOmxMlkTrackerFunctions & iTrackerFunctions);

  ExportedByCATOmxBase static const IID IID_CATOmxMlkRefCounter;
};

/** Define the global macro */
#define OMX_MLK_TRACKER(cls) cls##_MlkTracker_Data

// Temporary migration constraint 2: CGMV5Interoperability.
#if defined(CATCGM_OMX_MLK_TRACKER_Impl_h)
#define OMX_MLK_OCCURENCE(cls) (OMX_MLK_TRACKER(cls).m_occurence)
static void CGM_MlkTracker_Register(CATOmxMlkTracker & iThisTracker, CATMetaClass * iMetaObject)
{
  CATOmxMlkTrackerFunctions functions = { };
  CATOmxMlkTracker::Register(iThisTracker, iMetaObject, CATOmxFWString, functions);
}
#endif


#endif // __CATOmxMlkTracker_h__
