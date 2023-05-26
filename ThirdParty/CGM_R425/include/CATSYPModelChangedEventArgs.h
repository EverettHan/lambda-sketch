#pragma once

#include <UIVCoreTools.h>
#include <CATSYPEventArgs.h>
#include <nlohmann/json.hpp>
#include <functional>

class ExportedByUIVCoreTools CATSYPModelChangedEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;
  public:
    /** 
   * Initialize this class.
   *
   * @param i_pEvent the dispatched event. Can't be @c NULL. 
   */
  CATSYPModelChangedEventArgs(CATSYPEvent * i_pEvent, const nlohmann::json& i_transactions, std::function<void(nlohmann::json &)> i_successCallback);

  /** Destroy this class. */
  virtual ~CATSYPModelChangedEventArgs();

  const nlohmann::json& GetTransactions() const {return _transactions;}
  std::function<void(nlohmann::json &)> GetSuccessCallback(){return _successCallback;}

private:
   /** Copy constructor. */
  CATSYPModelChangedEventArgs (CATSYPModelChangedEventArgs &) = delete;
   /** Assignment operator. */
  CATSYPModelChangedEventArgs& operator=(CATSYPModelChangedEventArgs&) = delete;
  
  nlohmann::json _transactions;
  std::function<void(nlohmann::json &)> _successCallback;
};
