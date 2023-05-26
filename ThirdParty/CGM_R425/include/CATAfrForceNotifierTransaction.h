#ifndef CATAfrForceNotifierTransaction__H
#define CATAfrForceNotifierTransaction__H

#include <CATAfrFoundation.h>
#include <functional>
#include <CATCommand.h>

/**
 * Helper undefined CATCommand that creates a send / receive transaction before
 * executing the given function.
 * It is useful when a CATStateCommand needs to be created and the context
 * doesn't contain a send / receive transaction (otherwise, the CATStateCommand
 * will not be executed properly).
 */
class ExportedByCATAfrFoundation CATAfrForceNotifierTransaction : public CATCommand
{
  CATDeclareClass;
public:
  /**
   * Constructor
   *
   * @param i_function the function to execute. It is a function has no return
   * type and that takes no parameters.
   */
  explicit CATAfrForceNotifierTransaction(std::function<void ()> i_function);
  /**
   * Destructor
   */
  virtual ~CATAfrForceNotifierTransaction();

  /**
   * Execute the function stored by this command.
   */
  void RunCommand();

private:
  // Not implemented
  CATAfrForceNotifierTransaction();
  CATAfrForceNotifierTransaction(const CATAfrForceNotifierTransaction &);
  CATAfrForceNotifierTransaction& operator=(const CATAfrForceNotifierTransaction &);

  /**
   * Callback called when a send / receive transaction has to be created before
   * executing the function. This callback will run the function.
   */
  void RunCB (CATCommand * sendObject,
              CATNotification * evt,
              CATCommandClientData data);

  /** Function to execute in a send / receive transaction */
  std::function<void ()> m_func;
};

#endif
