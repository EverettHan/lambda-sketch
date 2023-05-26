#ifndef CATSYPWatcher_h
#define CATSYPWatcher_h

// COPYRIGHT Dassault Systemes 2021

// VisuImmersiveDialog framework
#include <IntroInfra.h>

// IntrospectionInfrastructure framework
#include <CATISYPIntrospectable.h>
#include <nlohmann/json_fwd.hpp>

// System framework
#include <CATBoolean.h>
#include <CATBaseUnknown_WR.h>

// UIVCoreTools
#include <CATSYPSimpleEventListener.h>

#include <string>

#define UI_TRANSACTIONS "UITransactions"
#define UI_MODEL "UIModel"
#define DEFAULT_STACK_ID "DefaultStack"

class CATBaseUnknown;
class CATISYPWatchable_var;
class CATSYPEvent;

/**
 * Class used to dispatch events when the CATSYPWatcher log a transaction or flush a transactionStackId
 */
class ExportedByIntroInfra CATSYPWatcherDispatcher : public CATSYPSimpleEventListener
{

public:
  /**
   * Event sent when a transaction is pushed.
   */
  static CATSYPEvent* TransactionAdded();

  /**
   * Event sent when a transaction stack is flushed.
   */
  static CATSYPEvent* Flushed();
};

/**
 * Class used to log all the User Interface changes (widget creation, widget destruction, layout modifications)
 */
class ExportedByIntroInfra CATSYPWatcher
{
public:

  /**
   * Logs a watchable object addition to the displayed user interface.
   * @param i_spWatchable
   * The added watchable object
   * @param i_transactionStackId
   * The transaction stack identifier
   * @param i_force
   * Specifies whether the object addition must be logged even if the object is alreay registered, or not.
   */
  static HRESULT LogObjectAddition(
    const CATISYPWatchable_var& i_spWatchable, 
    const std::string& i_transactionStackId = DEFAULT_STACK_ID,
    CATBoolean i_force = FALSE);

  /**
   * Logs a watchable object removal.
   * @param i_spWatchable
   * The removed watchable object
   * @param i_transactionStackId
   * The transaction stack identifier
   */
  static HRESULT LogObjectRemoval(
    const CATISYPWatchable_var& i_spWatchable, 
    const std::string& i_transactionStackId = DEFAULT_STACK_ID);

  /**
   * Logs a window or widget introspectable property value change.
   * @param i_pObject
   * The object on which the property value has changed
   * @param i_propertyName
   * The introspectable property name
   * @param i_transactionStackId
   * The transaction stack identifier
   */
  static HRESULT LogPropertyValueChange(
    CATBaseUnknown* i_pObject, 
    const std::string& i_propertyName, 
    const std::string& i_transactionStackId = DEFAULT_STACK_ID);

  /**
  * Logs a window or widget generic property value change.
  * @param i_pObject
  * The object on which the property value has changed
  * @param i_propertyName
  * The generic property name
  * @param i_jsonUIModel
  * The JSON model of the value to log
  * @param i_transactionStackId
  * The transaction stack identifier
  */
  static HRESULT LogGenericPropertyValueChange(
    CATBaseUnknown* i_pObject,
    const std::string& i_propertyName,
    const nlohmann::json& i_jsonUIModel,
    const std::string& i_transactionStackId = DEFAULT_STACK_ID);


  // TODO: remove this method once runJavascript mecanism is handled differently
  static HRESULT LogFunction(
    CATBaseUnknown* i_pObject, 
    const nlohmann::json& i_functionInfo, 
    const std::string& i_transactionStackId = DEFAULT_STACK_ID);

  /**
   * Logs a widget constraints change.
   * @param i_pObject
   * The given object
   * @param i_pParentObject
   * The parent object that constrains the object
   * @param i_transactionStackId
   * The transaction stack identifier
   */
  static HRESULT LogConstraintsChange(
    CATBaseUnknown* i_pObject, 
    CATBaseUnknown* i_pParentObject, 
    const std::string& i_transactionStackId = DEFAULT_STACK_ID);

  /**
   * Flushes and returns in a JSON object all the logged transactions.
   * @param i_transactionStackId
   * The transaction stack identifier
   */
  static nlohmann::json Flush(const std::string& i_transactionStackId = DEFAULT_STACK_ID);

  /**
   * Returns TRUE if no pending transaction has been logged, FALSE otherwise.
   * @param i_transactionStackId
   * The transaction stack identifier
   */
  static CATBoolean IsEmpty(const std::string& i_transactionStackId = DEFAULT_STACK_ID);

  /**
   * Computes a string identifier for the given object.
   * This identifier is only valid for the current session.
   */
  static std::string ComputeIdentifier(CATBaseUnknown* i_pObject);

  /**
   * Registers the given object and returns its computed identifier.
   */
  static std::string RegisterObject(CATBaseUnknown* i_pObject);

  /**
   * Returns the registered object from the given identifier.
   * Warning: no AddRef has been done on the returned object
   */
  static CATBaseUnknown* GetRegisteredObject(const std::string& i_identifier);

  /**
   * Unregisters the given watchable object.
   */
  static HRESULT UnregisterObject(CATBaseUnknown* i_pObject);

  /**
   * Unregisters all registered objects.
   */
  static HRESULT UnregisterRegisteredObjects();

  /**
   * Returns TRUE if the given object is registered, FALSE otherwise.
   */
  static CATBoolean IsRegistered(CATBaseUnknown* i_pObject);

  /**
   * Clears all the logged transactions and the map of registered objects.
   * @param i_transactionStackId
   * The transaction stack identifier
   */
  static void Clear(const std::string& i_transactionStackId = DEFAULT_STACK_ID);

  /**
   * Disables the watcher logging.
   */
  static INLINE void DisableLogging() { s_loggingDisabled++; };

  /**
   * Enables the watcher logging.
   */
  static INLINE void EnableLogging() { s_loggingDisabled--; };

  /**
  * Returns TRUE if the watcher logging is disabled, FALSE otherwise.
  */
  static INLINE CATBoolean IsLoggingDisabled() { return (s_loggingDisabled > 0); };

  /**
  * Retrieves the object used to dispatch event whenever an action is store or flushed on the CATSYPWatcher
  */
  static INLINE CATSYPWatcherDispatcher* GetDispatcher() { return s_pDispatcher; };
  

protected:

  /**
  * Add a transaction in the transaction stack identified as i_transactionStackId.
  */
  static HRESULT _AddTransaction(nlohmann::json& i_transaction, const std::string& i_transactionStackId = DEFAULT_STACK_ID);

  /**
   * Logs a transaction with the given name and introspectable object.
   */
  static HRESULT _LogTransaction(const std::string& i_transactionName, const CATISYPWatchable_var& i_spWatchable, const std::string& i_transactionStackId = DEFAULT_STACK_ID);

  /**
   * Returns the transaction stack identified by i_transactionStackId.
   */
  static nlohmann::json& _GetStack(const std::string& i_transactionStackId = DEFAULT_STACK_ID);

  /**
   * Returns the UITransactions in transaction stack identified by i_transactionStackId.
   */
  static nlohmann::json& _GetTransactions(const std::string& i_transactionStackId = DEFAULT_STACK_ID);

  CATSYPWatcher();
  ~CATSYPWatcher();

private:
  /** Called by CATVidSessionCleaner at the end of the application*/
  static void CleanSYPWatcherOnExit();
  friend class CATVidSessionCleaner;

  static bool _IsPropertyWatchable(const CATISYPIntrospectable_var& i_spIntrospectable, const std::string& i_propertyName);
  static nlohmann::json s_transactions;
  static std::map<void*, CATBaseUnknown_WR> *s_pRegisteredObjects;
  static int s_loggingDisabled;
  static CATBoolean s_debug;
  static CATSYPWatcherDispatcher *s_pDispatcher;
};

#endif // CATSYPWatcher_h
