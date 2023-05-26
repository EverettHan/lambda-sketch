#ifndef CATViewWatcher_h
#define CATViewWatcher_h

// COPYRIGHT Dassault Systemes 2021

// VisuImmersiveDialog framework
#include <CATView.h>
#include <CATSYPWatcher.h>

// IntrospectionInfrastructure framework
#include <CATISYPIntrospectable.h>
#include <nlohmann/json.hpp>

// System framework
#include <CATBoolean.h>
#include <CATBaseUnknown_WR.h>

#include <string>

class CATBaseUnknown;
class CATISYPWatchable_var;
class CATUnicodeString;
class CATDialog;

/**
 * Class used to log all the User Interface changes (widget creation, widget destruction, layout modifications)
 */
class ExportedByCATView CATViewWatcher: public CATSYPWatcher
{
public:

  /*
   * Loads (if needed) the CATView properties json file.
   */
  static void LoadCATViewModel();

  /*
   * Get the CATView properties json file.
   */
  static nlohmann::json GetCATViewToGenericModel();

  /**
   * Logs a watchable object addition to the displayed user interface.
   * @param i_spWatchable
   * The added watchable object
   */
  static HRESULT LogObjectAddition(const CATISYPWatchable_var& i_spWatchable);

  /**
   * Logs a watchable object removal.
   * @param i_spWatchable
   * The removed watchable object
   */
  static HRESULT LogObjectRemoval(const CATISYPWatchable_var& i_spWatchable);

  /**
   * Logs a watchable object property calue change.
   * @param i_spWatchable
   * The watchable object whose a property value changed.
   * @param i_propertyName
   * The name of property which changed its value.
   */
  static HRESULT LogPropertyValueChange(CATBaseUnknown * i_pObject, const std::string& i_propertyName);

  /**
   * Clears all the logged transactions and the map of registered objects.
   */
  static void Clear();

  /**
   * Returns TRUE if no pending transaction has been logged, FALSE otherwise.
   */
  static CATBoolean IsEmpty();

  /**
   * Flushes and returns in a JSON object all the logged transactions.
   */
  static nlohmann::json Flush();

  static void PlugCATViewsInDlgStructure(nlohmann::json & dlgJSON);

protected:

  /**
   * Logs a transaction with the given name and introspectable object.
   */
  static HRESULT _LogTransaction(const std::string& i_transactionName, const CATISYPWatchable_var& i_spWatchable);

  CATViewWatcher();
  ~CATViewWatcher();

private:

  static nlohmann::json * GetItemValueInJSONFromId(nlohmann::json & transactionArray, std::string searchedId);
  static nlohmann::json* SearchForElementById(nlohmann::json * pTransaction, std::string CATViewFatherDialogId);

  static nlohmann::json s_CATViewToGenericModel;

};

#endif // CATViewWatcher_h
