#pragma once

#include <UIVCoreTools.h>
#include <CATSYPEventArgs.h>
#include <nlohmann/json.hpp>
#include <functional>
#include <CATSYPDataSourceParameters.h>

class ExportedByUIVCoreTools CATSYPSelectionChangedEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;
  public:
    /** 
   * Initialize this class.
   *
   * @param i_pEvent the dispatched event. Can't be @c NULL. 
   */
  CATSYPSelectionChangedEventArgs(CATSYPEvent * i_pEvent, const CATSYPDataSourceParameters::SelectionChangeParameters& i_parameters, std::function<void(nlohmann::json &)> i_successCallback);

  /** Destroy this class. */
  virtual ~CATSYPSelectionChangedEventArgs();

  const CATSYPDataSourceParameters::SelectionChangeParameters& GetParameters() const { return _parameters; }

  std::function<void(nlohmann::json &)> GetSuccessCallback(){return _successCallback;}

private:
   /** Copy constructor. */
  CATSYPSelectionChangedEventArgs (CATSYPSelectionChangedEventArgs &) = delete;
   /** Assignment operator. */
  CATSYPSelectionChangedEventArgs& operator=(CATSYPSelectionChangedEventArgs&) = delete;
  
  CATSYPDataSourceParameters::SelectionChangeParameters _parameters;
  std::function<void(nlohmann::json &)> _successCallback;
};
