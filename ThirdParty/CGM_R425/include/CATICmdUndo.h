#ifndef CATICmdUndo_H
#define CATICmdUndo_H

/* COPYRIGHT DASSAULT SYSTEMES 1999 */

#include "IUnknown.h"

/**
 * Undo Management in a command.
 * The interface an object must implement to manage undo/redo.
 */
class CATICmdUndo : public IUnknown
{

public:

  /**
  * Performs treatments to undo what has been done in the command.
  * This method is called before the transactionnal model undo.
  */ 
  virtual HRESULT BeforeUndo () = 0;
  
  /**
  * Performs treatments to redo what has been undone in the command.
  * This method is called before the transactionnal model redo.
  */ 
  virtual HRESULT BeforeRedo () = 0;
  
  /**
  * Performs treatments to undo what has been done in the command.
  * This method is called after the transactionnal model undo.
  */ 
  virtual HRESULT AfterUndo () = 0;
  
  /**
  * Performs treatments to redo what has been undone in the command.
  * This method is called after the transactionnal model redo.
  */ 
  virtual HRESULT AfterRedo () =0;
  
};

/* 8ad32bcc-a17f-0000-0280-030b09000000 */
extern "C" const IID IID_CATICmdUndo;

#endif
