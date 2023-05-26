#ifndef CATSGSYPCheck_H
#define CATSGSYPCheck_H



#include <CATMutex.h>
#include <CATSGSYPMutexLocker.h>

#include "SGInfraCoreTools.h"

/**
 * @nodoc
 * @ingroup groupUIVCoreToolsInstanceCounter
 * A counter of instances that can be used to debug leaks in application.
 * See @ref CREATE_INSTANCE_COUNTER, @ref INC_INSTANCE_COUNTER and
 * @ref DEC_INSTANCE_COUNTER macros that should be used to use this class.
 *
 * @see CREATE_INSTANCE_COUNTER
 * @see INC_INSTANCE_COUNTER
 * @see DEC_INSTANCE_COUNTER
 */
class ExportedBySGInfraCoreTools CATSGSYPCheckInstanceCounter
{
private:
  /**
  * Initialize the instance counter for a given class.
  * @param i_className the name of the class. Note that this value
  * must be a static string. It won't be copied and only a reference
  * will be kept by this class. Consequently if the given string
  * is not a static string, the caller must ensure that the given
  * string is kept in memory until the destructor of this class is
  * called. Since this class is meant to be used with a static string
  * this restriction is not very important.
  */
  CATSGSYPCheckInstanceCounter(const char *i_className);
public:
  /**
  * Check if module static objects have been destoryed (for example at
  * program exit).
  *
  * @return @c !=0 if static objects have been destroyed. In that
  * case calling @ref #GetInstantiateMutex or @ref
  * #InstantiateCounter will both return @c NULL and counters should
  * not be used anymore.
  */
  static int AreModuleStaticsDestroyed();

  /**
  * A shared mutex that should be used by called of @ref
  * #InstantiateCounter to ensure that it is called only once.
  *
  * This function must not be called after destruction of static
  * objects in the module. Use @ref #AreModuleStaticsDestroyed before
  * calling this method.
  *
  * @return the mutex, @c NULL if the statics of the module have been
  * destroyed (at program exit).
  *
  * @see CREATE_INSTANCE_COUNTER
  * @see #InstantiateCounter
  * @see #AreModuleStaticsDestroyed
  */
  static CATMutex *GetInstantiateMutex();

  /**
  * Create a counter for the given class and add it the the global
  * list of counters to be checked and destroyed when the shared
  * libraries containing the implementation of this class is
  * unlodaded.
  *
  * Note that for a given class this function should only be called
  * once. To ensure this specification is true, it may be necessary
  * to use a mutex in the calling code (see @ref
  * CREATE_INSTANCE_COUNTER). The mutex returned by @ref
  * #GetInstantiateMutex may be used.
  *
  * This function must not be called after destruction of static
  * objects in the module. Use @ref #AreModuleStaticsDestroyed before
  * calling this method.
  *
  * After calling this method, the caller should ensure that @ref
  * #Unreference is called at the destruction of static objects of
  * the module that implements the class using the counter. This will
  * trigger the destruction of the counters list when all counters
  * are unreferenced. This delay in the destruction of counters
  * prevents wrong detection of leaks for static objects. <b>Warning:
  * not calling @ref #Unreference will prevent counters from being
  * effective.</b>
  *
  * @param i_className the name of the class. Note that this value
  * must be a static string. It won't be copied and only a reference
  * will be kept by this class. Consequently if the given string
  * is not a static string, the caller must ensure that the given
  * string is kept in memory until the destructor of this class is
  * called. Since this class is meant to be used with a static string
  * this restriction is not very important.
  *
  * @return the new counter instance. The return object must NOT be
  * deleted by the caller. Its lifecycle will be handled by the
  * shared library containing the implementation of @ref
  * CATSGSYPCheckInstanceCounter class. Use @ref
  * #AreModuleStaticsDestroyed to know when the returned objects
  * should not be used anymore. Returns @c NULL if the static of the
  * module have been destroyed (at program exit).
  *
  * @see #GetInstantiateMutex
  * @see CREATE_INSTANCE_COUNTER
  * @see #AreModuleStaticsDestroyed
  * @see #Unreference
  */
  static CATSGSYPCheckInstanceCounter *InstantiateCounter(const char *i_className);

  /**
  * Decrement the internal count of usage of counters. When it
  * reaches 0 (i.e. when all code that have created counters have
  * called this function and when the static objects of this module
  * are destroyed) the leaks are displayed. Subsequent calls to @ref
  * INC_INSTANCE_COUNTER and @ref DEC_INSTANCE_COUNTER are then
  * simply printed as warning in the @c stderr.
  *
  * <b>Warning: not calling this function after call of @ref
  * #InstantiateCounter will prevent counters from being
  * effective.</b>
  *
  * This function must only be called from a destructor of a static
  * object; it is not thread-safe.
  */
  static void Unreference(const char *i_className);

  /**
  * This destructor will print a message in stdout if the number
  * of instances is !=0.
  * Note that is has to be stdout and not stderr since when printing
  * in stderr, the message is not visible in the .traces output file
  * of tests.
  */
  ~CATSGSYPCheckInstanceCounter();

  /**
  * Increment the count of instances.
  * This method is thread-safe.
  */
  void IncrementCount();

  /**
  * Decrement the count of instances.
  * This method is thread-safe.
  */
  void DecrementCount();

  /**
  * Print an error.
  *
  * Used by macros to report errors; for example usage of counters
  * after destruction of static objects.
  *
  * @param i_err the error message (a prefix will be appended
  * specifying that it is printed by this class). Can't be @c NULL.
  */
  static void Error(const char *i_err);
private:
  CATSGSYPCheckInstanceCounter(const CATSGSYPCheckInstanceCounter &);
  CATSGSYPCheckInstanceCounter &operator=(const CATSGSYPCheckInstanceCounter &);
private:
  /** mutex serializing accesses to the state of this component */
  CATMutex _mutex;
  /** the number of instances; guarded by @ref #_mutex mutex */
  CATLONG64 _instanceCount;
  /** name of the class; the variable must be a pointer on a
  *  static string so there is no need to destroy it. */
  const char *_pClassName;
};

/**
 * @nodoc
 * @ingroup groupUIVCoreToolsInstanceCounter
 * This class will call @ref CATSGSYPCheckInstanceCounter#Unreference
 * with @a i_className when it is destroyed if the variable @a
 * i_staticVar is not @c NULL.
 *
 * This class is used by @ref CREATE_INSTANCE_COUNTER macro to call
 * the @c Unreference for the counter.
 *
 * @see CREATE_INSTANCE_COUNTER
 */
class ExportedBySGInfraCoreTools CATSGSYPCheckInstanceCounterUnreferencer
{
public:
  /**
  * @param i_className a static string (no copy is made by this class)
  *
  * @param i_staticVar a reference on the static variable defined by
  * @ref CREATE_INSTANCE_COUNTER.
  */
  CATSGSYPCheckInstanceCounterUnreferencer(const char *i_className, CATSGSYPCheckInstanceCounter *&i_staticVar);

  /**
  * Call @ref CATSGSYPCheckInstanceCounter#Unreference if @a _staticVar
  * is not @c NULL.
  */
  ~CATSGSYPCheckInstanceCounterUnreferencer();
private:
  /** the name of the class */
  const char * const _className;

  /** the static variable; we use pointer of pointer and not reference
  of pointer since with a reference of pointer mkCheckSource
  expects us to set is to @c NULL in destructor... */
  CATSGSYPCheckInstanceCounter ** _pStaticVar;
};

// Note that *_INSTANCE_COUNTER are only defined if CNEXT_CLIENT is not
// defined. That means that these macros will only generate code when
// compiling using the -dev command line option of mkmk.
#ifndef CNEXT_CLIENT
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsInstanceCounter
 * Create a function that returns an instance counter for the given
 * class name.
 *
 * We use a function instead of using a static pointer to ensure that
 * we don't depend on the initialization order of static.
 *
 * When the static object this macro creates will be destroyed (i.e.
 * when the shared library containing @ref CATSGSYPCheckInstanceCounter
 * is unloaded), if the number of instances is not 0, a debug message
 * will printed to stdout.
 *
 * @param i_className the name of the class (without "").
 *
 * @see INC_INSTANCE_COUNTER
 * @see DEC_INSTANCE_COUNTER
 */
#define SG_CREATE_INSTANCE_COUNTER(i_className)                            \
  static CATSGSYPCheckInstanceCounter *                                   \
  g_pInstanceCounter##i_className = NULL;                               \
                                                                        \
  static CATSGSYPCheckInstanceCounter *                                   \
  g_GetInstanceCounter##i_className() {                                 \
    /* return NULL after destruction of statics */                      \
    if (CATSGSYPCheckInstanceCounter::AreModuleStaticsDestroyed())        \
      return NULL;                                                      \
    CATMutex * const pMutex = CATSGSYPCheckInstanceCounter::GetInstantiateMutex(); \
    if (pMutex == NULL) return NULL; /* sanity check */                 \
    CATSGSYPMutexLocker locker(*pMutex);                                  \
    if (g_pInstanceCounter##i_className == NULL)                        \
      g_pInstanceCounter##i_className = CATSGSYPCheckInstanceCounter::InstantiateCounter(#i_className); \
    return g_pInstanceCounter##i_className;                             \
  }                                                                     \
                                                                        \
  static CATSGSYPCheckInstanceCounterUnreferencer                         \
  g_instanceCounter##i_className##_unref(#i_className, g_pInstanceCounter##i_className);

/**
 * @nodoc
 * @ingroup groupUIVCoreToolsInstanceCounter
 * Increment the instance counter of the given class name.
 * This macro should be used in every constructor of the class.
 *
 * @see CREATE_INSTANCE_COUNTER
 */
#define SG_INC_INSTANCE_COUNTER(i_className)                               \
  do {                                                                  \
    CATSGSYPCheckInstanceCounter * pCounter = g_GetInstanceCounter##i_className(); \
    if (pCounter == NULL)                                               \
      CATSGSYPCheckInstanceCounter::Error("Call to INC_INSTANCE_COUNTER for " \
                                        #i_className                    \
                                        " after the destruction of the counter"); \
    else                                                                \
      pCounter->IncrementCount();                                       \
  } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsInstanceCounter
 * Decrement the instance counter of the given class name.
 * This macro should be used in the destructor of the class.
 *
 * @see CREATE_INSTANCE_COUNTER
 */
#define SG_DEC_INSTANCE_COUNTER(i_className)                               \
  do {                                                                  \
    CATSGSYPCheckInstanceCounter * pCounter = g_GetInstanceCounter##i_className(); \
    if (pCounter == NULL)                                               \
      CATSGSYPCheckInstanceCounter::Error("Call to DEC_INSTANCE_COUNTER for " \
                                        #i_className                    \
                                        " after the destruction of the counter"); \
    else                                                                \
      pCounter->DecrementCount();                                       \
  } while(0)
#else // CNEXT_CLIENT
/* Empty macros when compiling without -dev option of mkmk. */
#define SG_CREATE_INSTANCE_COUNTER(i_className)
#define SG_INC_INSTANCE_COUNTER(i_className)
#define SG_DEC_INSTANCE_COUNTER(i_className)
#endif // CNEXT_CLIENT



/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Function called by FAILURE* macros.
 */
ExportedBySGInfraCoreTools void SG_CheckFailure__(const char *iDiagnostic, const char *iFileName, int iLineNb, const char *iMessage);
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Function called by CHECK_TRUE* macros if the condition is false.
 */
ExportedBySGInfraCoreTools void SG_Check_TRUE_Failed__(const char *iExpression, const char *iFileName, int iLineNb, const char *iMessage);
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Function called by CHECK_POINTER* macros if the pointer is NULL.
 */
ExportedBySGInfraCoreTools void SG_Check_Pointer_Failed__(const char *iExpression, const char *iFileName, int iLineNb, const char *iMessage);
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Function called by CHECK_HANDLER* macros if the handler is NULL_var.
 */
ExportedBySGInfraCoreTools void SG_Check_Handler_Failed__(const char *iExpression, const char *iFileName, int iLineNb, const char *iMessage);

#ifdef _MOBILE_SOURCE

#include "CATSGSYPCheckMobile.h"

#else

/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * An assertion that always fails.
 * Note that is not not exactly an assertion since it does not check a condition.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#FAILURE.2A_Macros for details
 */
#define SG_FAILURE(iDiagnostic) SG_CheckFailure__(iDiagnostic, __FILE__, __LINE__, NULL)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * An assertion that always fails with a message.
 * Note that is not not exactly an assertion since it does not check a condition.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#FAILURE.2A_Macros for details
 */
#define SG_FAILURE_MSG(iDiagnostic, iMessage) SG_CheckFailure__(iDiagnostic, __FILE__, __LINE__, iMessage)

/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a boolean condition (i.e. an int that is considered TRUE if != 0, FALSE if 0) is TRUE.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iBoolean the boolean to test (i.e. an int)
 */
#define SG_CHECK_TRUE(iBoolean) do { if (!(iBoolean)) SG_Check_TRUE_Failed__(#iBoolean, __FILE__, __LINE__, NULL); } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a boolean condition (i.e. an int that is considered TRUE if != 0, FALSE if 0) is TRUE and add a message.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iBoolean the boolean to test (i.e. an int)
 * @param iMessage the message to add to the diagnostic (a const char*).
 */
#define SG_CHECK_TRUE_MSG(iBoolean, iMessage) do { if (!(iBoolean)) SG_Check_TRUE_Failed__(#iBoolean, __FILE__, __LINE__, iMessage); } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a boolean condition (i.e. an int that is considered TRUE if != 0, FALSE if 0) is TRUE,
 * and exit the function by calling "return" if the condition is FALSE.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iBoolean the boolean to test (i.e. an int)
 */
#define SG_CHECK_TRUE_RET(iBoolean) do { if(!(iBoolean)) { SG_Check_TRUE_Failed__(#iBoolean, __FILE__, __LINE__, NULL); return; } } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a boolean condition (i.e. an int that is considered TRUE if != 0, FALSE if 0) is TRUE,
 * and exit the function by calling "return" if the condition is FALSE. It adds a message.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iBoolean the boolean to test (i.e. an int)
 * @param iMessage the message to add to the diagnostic (a const char*).
 */
#define SG_CHECK_TRUE_RET_MSG(iBoolean, iMessage) do { if(!(iBoolean)) { SG_Check_TRUE_Failed__(#iBoolean, __FILE__, __LINE__, iMessage); return; } } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a boolean condition (i.e. an int that is considered TRUE if != 0, FALSE if 0) is TRUE,
 * and exit the function by calling "return" with the specified value if the condition is FALSE.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iBoolean the boolean to test (i.e. an int)
 * @param iVal the value to return (must be of a type compatible with the return type of
 * the function where this macro is used)
 */
#define SG_CHECK_TRUE_RETV(iBoolean, iVal) do { if(!(iBoolean)) { SG_Check_TRUE_Failed__(#iBoolean, __FILE__, __LINE__, NULL); return iVal; } } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a boolean condition (i.e. an int that is considered TRUE if != 0, FALSE if 0) is TRUE,
 * and exit the function by calling "return" with the specified value if the condition is FALSE. It adds a message.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iBoolean the boolean to test (i.e. an int)
 * @param iVal the value to return (must be of a type compatible with the return type of
 * the function where this macro is used)
 * @param iMessage the message to add to the diagnostic (a const char*).
 */
#define SG_CHECK_TRUE_RETV_MSG(iBoolean, iVal, iMessage) do { if(!(iBoolean)) { SG_Check_TRUE_Failed__(#iBoolean, __FILE__, __LINE__, iMessage); return iVal; } } while(0)

/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a pointer is NOT NULL.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iPointer the pointer to test
 */
#define SG_CHECK_POINTER(iPointer) do { const void *pointer = iPointer; if (pointer == NULL) SG_Check_Pointer_Failed__(#iPointer, __FILE__, __LINE__, NULL); } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a pointer is NOT NULL and add a message.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iPointer the pointer to test
 * @param iMessage the message to add to the diagnostic (a const char*).
 */
#define SG_CHECK_POINTER_MSG(iPointer, iMessage) do { const void *pointer = iPointer; if (pointer == NULL) SG_Check_Pointer_Failed__(#iPointer, __FILE__, __LINE__, iMessage); } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a pointer is NOT NULL, and exit the function by calling "return" if the condition is FALSE.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iPointer the pointer to test
 */
#define SG_CHECK_POINTER_RET(iPointer) do { const void *pointer = iPointer; if (pointer == NULL) { SG_Check_Pointer_Failed__(#iPointer, __FILE__, __LINE__, NULL); return;} } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a pointer is NOT NULL, and exit the function by calling "return" if the condition is FALSE.
 * It adds a message.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iPointer the pointer to test
 * @param iMessage the message to add to the diagnostic (a const char*).
 */
#define SG_CHECK_POINTER_RET_MSG(iPointer, iMessage) do { const void *pointer = iPointer; if (pointer == NULL) { SG_Check_Pointer_Failed__(#iPointer, __FILE__, __LINE__, iMessage); return; } } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a pointer is NOT NULL, and exit the function by calling "return" with the specified
 * value if the condition is FALSE.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iPointer the pointer to test
 * @param iVal the value to return (must be of a type compatible with the return type of
 * the function where this macro is used)
 */
#define SG_CHECK_POINTER_RETV(iPointer, iVal) do { const void *pointer = iPointer; if (pointer == NULL) { SG_Check_Pointer_Failed__(#iPointer, __FILE__, __LINE__, NULL); return iVal; } } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a pointer is NOT NULL, and exit the function by calling "return" with the specified
 * value if the condition is FALSE. It adds a message.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iPointer the pointer to test
 * @param iVal the value to return (must be of a type compatible with the return type of
 * the function where this macro is used)
 * @param iMessage the message to add to the diagnostic (a const char*).
 */
#define SG_CHECK_POINTER_RETV_MSG(iPointer, iVal, iMessage) do { const void *pointer = iPointer; if (pointer == NULL) { SG_Check_Pointer_Failed__(#iPointer, __FILE__, __LINE__, iMessage); return iVal;} } while(0)

/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a handler is NOT NULL_var.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iHandler the handler to test
 */
#define SG_CHECK_HANDLER(iHandler) do { const CATBaseUnknown *pointer = iHandler; if (pointer == NULL_var) SG_Check_Handler_Failed__(#iHandler, __FILE__, __LINE__, NULL); } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a handler is NOT NULL_var and add a message.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iHandler the handler to test
 * @param iMessage the message to add to the diagnostic (a const char*).
 */
#define SG_CHECK_HANDLER_MSG(iHandler, iMessage) do { const CATBaseUnknown *pointer = iHandler; if (pointer == NULL_var) SG_Check_Handler_Failed__(#iHandler, __FILE__, __LINE__, iMessage); } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a handler is NOT NULL_var, and exit the function by calling "return" if the condition is FALSE.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iHandler the handler to test
 */
#define SG_CHECK_HANDLER_RET(iHandler) do { const CATBaseUnknown *pointer = iHandler; if (pointer == NULL_var) { SG_Check_Handler_Failed__(#iHandler, __FILE__, __LINE__, NULL); return;} } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a handler is NOT NULL_var, and exit the function by calling "return" if the condition is FALSE.
 * It adds a message.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iHandler the handler to test
 * @param iMessage the message to add to the diagnostic (a const char*).
 */
#define SG_CHECK_HANDLER_RET_MSG(iHandler, iMessage) do { const CATBaseUnknown *pointer = iHandler; if (pointer == NULL_var) { SG_Check_Handler_Failed__(#iHandler, __FILE__, __LINE__, iMessage); return; } } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a handler is NOT NULL_var, and exit the function by calling "return" with the specified
 * value if the condition is FALSE.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iHandler the handler to test
 * @param iVal the value to return (must be of a type compatible with the return type of
 * the function where this macro is used)
 */
#define SG_CHECK_HANDLER_RETV(iHandler, iVal) do { const CATBaseUnknown *pointer = iHandler; if (pointer == NULL_var) { SG_Check_Handler_Failed__(#iHandler, __FILE__, __LINE__, NULL); return iVal; } } while(0)
 /**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a handler is NOT NULL_var, and exit the function by calling "return" with the specified
 * value if the condition is FALSE. It adds a message.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iHandler the handler to test
 * @param iVal the value to return (must be of a type compatible with the return type of
 * the function where this macro is used)
 * @param iMessage the message to add to the diagnostic (a const char*).
 */
#define SG_CHECK_HANDLER_RETV_MSG(iHandler, iVal, iMessage) do { const CATBaseUnknown *pointer = iHandler; if (pointer == NULL_var) { SG_Check_Handler_Failed__(#iHandler, __FILE__, __LINE__, iMessage); return iVal;} } while(0)

#endif // _MOBILE_SOURCE

#endif // CATSGSYPCheck_H
