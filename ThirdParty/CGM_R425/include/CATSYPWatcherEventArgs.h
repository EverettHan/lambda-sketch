#pragma once

#include "IntroInfra.h"
#include <CATSYPEventArgs.h>

#include <string>

//-----------------------------------------------------------------------

class ExportedByIntroInfra CATSYPWatcherEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;
public:
  /**
    * Initialize this class.
    *
    * @param i_pEvent the event dispatched. Can't be @c NULL.
    *
    * @param i_transactionStackId The transaction stack identifier
    */
  CATSYPWatcherEventArgs(CATSYPEvent* i_pEvent, const std::string& i_transactionStackId);

  /** Destroy this class */
  virtual ~CATSYPWatcherEventArgs();

  /**
   * Get the transaction stack identifier.
   */
   inline std::string GetTransactionStackId() { return _transactionStackId;  };

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATSYPWatcherEventArgs(CATSYPWatcherEventArgs&);
  CATSYPWatcherEventArgs& operator=(CATSYPWatcherEventArgs&);

  std::string _transactionStackId;
};

//-----------------------------------------------------------------------
