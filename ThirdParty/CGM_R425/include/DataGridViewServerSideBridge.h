
// COPYRIGHT Dassault Systemes 2023

#pragma once 

#include <VisuDialog.h>
#include <CATBaseUnknown.h>
#include <CATBaseUnknown_WR.h>
#include <nlohmann/json.hpp>
#include <functional>
#include <vector>
#include <CATBaseUnknown_WR.h>

class CATSYPAbstractDataSource;
class CATSYPModelChangedEventArgs;
class CATSYPSelectionChangedEventArgs;

class ExportedByVisuDialog DataGridViewServerSideBridge : public CATBaseUnknown
{
  CATDeclareClass;

public:

  DataGridViewServerSideBridge(std::function<void(const nlohmann::json &, CATBaseUnknown* i_pWidget)> i_runJavaScript, CATBaseUnknown* i_pWidget);

  /**
   * @brief Set the Data Source object
   * 
   * @param i_pDataSource 
   */
  void SetDataSource(CATSYPAbstractDataSource* i_pDataSource);
  
  HRESULT HandleJavaScriptCommand(const std::string& i_commandName, const nlohmann::json& i_jsonInput, std::function<void(nlohmann::json &)> i_successCallback = NULL);

  void RequireLoadedRows(std::function<void(nlohmann::json&)> i_successCallback);

  void RequireColumnsInformation(std::function<void(nlohmann::json&)> i_successCallback);

  void InitWebContent();

  void SetColumnsInformation(const nlohmann::json& i_columnsInfo);

  CATBaseUnknown* GetWidget() const { return (CATBaseUnknown*)CATBaseUnknown_var(_widgetWR); }

protected:

  /**
   * DataGridViewServerSideBridge Destructor.
   */
  virtual ~DataGridViewServerSideBridge();
 
private:

  DataGridViewServerSideBridge() = delete;
  DataGridViewServerSideBridge(DataGridViewServerSideBridge &) = delete;
  DataGridViewServerSideBridge& operator=(DataGridViewServerSideBridge&) = delete;

  /* Call javascript method from native */
  void _CallJSOnDGV(const std::string& i_functionName, const nlohmann::json& iJson);

  void _ReactOnWebQuery(nlohmann::json i_jsonResult, const nlohmann::json &i_jsonContext, const std::string &i_jsCommand);

  void _OnModelChanged(CATBaseUnknown * i_pSender, CATSYPModelChangedEventArgs* i_pArgs);
  void _OnSelectionChanged(CATBaseUnknown * i_pSender, CATSYPSelectionChangedEventArgs* i_pArgs);

  CATSYPAbstractDataSource* _pDataSource;

  class WinTransaction
  {
  public:

    WinTransaction(){}
    WinTransaction(const std::string& i_jsCall, const nlohmann::json& i_jsCallArgs, std::function<void(nlohmann::json&)> i_successCallback);
    WinTransaction(const WinTransaction& i_transaction);

    void Start(DataGridViewServerSideBridge &i_dgv);
    void ReceiveAnswer(DataGridViewServerSideBridge &i_dgv, const nlohmann::json& i_jsonAnswer);
    std::string GetId() const;


    std::string winId;
    std::string jsCall;
    nlohmann::json jsCallArgs;
    nlohmann::json jsonAnswer;
    std::function<void(nlohmann::json&)> successCallback;
    std::string status;//NotStarted/QuerySent/Answered
    std::string type;//WebQuery/WinQuery
  };

  void AddWinTransaction(const WinTransaction& i_transaction);
  void EndWinTransaction(const std::string& i_id, const nlohmann::json& i_jsonAnswer);

  std::map<std::string, WinTransaction > _winTransactionsMap;

  class WebTransactionOperation
  {
    public:
      WebTransactionOperation(const std::string& i_commandName, const nlohmann::json &i_input);
      virtual ~WebTransactionOperation() {}

      virtual nlohmann::json Fixup(DataGridViewServerSideBridge &i_bridge, const nlohmann::json &i_input, bool i_force=false) = 0;
      virtual void Request()
      {
        _requestCount++;
      }
      void CloseRequest(DataGridViewServerSideBridge& i_bridge);

      std::string commandName;

    protected:

      nlohmann::json _originalInput;
      nlohmann::json _corrections;
      int _requestCount;
  };

  std::map<std::string, WebTransactionOperation*> _webTransactionOperationsMap;
  std::function<void(const nlohmann::json &, CATBaseUnknown* i_pWidget)> _runJavaScript;
  nlohmann::json _columnsInfo;
  bool _initFlag;
  CATBaseUnknown_WR _widgetWR;

  friend class TstsDataGridViewClass;
  friend class WebTransactionOperation;
  friend class WebModelChangeTransaction;
  friend class WebSelectionChangeTransaction;
};
