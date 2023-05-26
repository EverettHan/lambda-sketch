#ifndef GOEOptimizableParameterUI_H
#define GOEOptimizableParameterUI_H

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "GraphicsOptimizer.h"

#include "CATDlgFrame.h"
#include "CATErrorDef.h"

class GOEOptimizableParameterValue;

/**
 * Base class to define the user interface associated to a Graphics Optimizable Parameter.
 */
class ExportedByGraphicsOptimizer GOEOptimizableParameterUI : public CATDlgFrame
{
  CATDeclareClass;

public:  

  virtual ~GOEOptimizableParameterUI();

  /**
   * This method is called when it is necessary to create the user interface associated 
   * to a Graphics Optimizable Parameter.
   */
  HRESULT CreateUserInterface();

  /**
   * Call this method to retrieve the value contained inside the user interface associated 
   * to a Graphics Optimizable Parameter.
   * The content of the @href GOEOptimizableParameterValue is left to the charge of the inherited class.
   * Warning! The returned @href GOEOptimizableParameterValue is allocated in this method; it HAS TO BE DELETED by caller.
   */
  virtual HRESULT GetValue(GOEOptimizableParameterValue** opValue) = 0;

  /**
   * Call this method to modify the value contained inside the user interface associated 
   * to a Graphics Optimizable Parameter.
   * The content of the @href GOEOptimizableParameterValue has to be compatible with the inherited class expectations.
   */
  virtual HRESULT SetValue(GOEOptimizableParameterValue* ipValue) = 0;

protected:

  /**
   * The user interface constructor.
   * This method is protected so that only inherited classes can call it.
   */
  GOEOptimizableParameterUI(CATDialog *iParent, const CATString& iObjectName);

  /**
   * This method is called only once to fill the frame enclosing the parameter user interface.
   */
  virtual HRESULT FillFrame(CATDlgFrame* ipFrame) = 0;

private:

  /**
  * Copy not allowed.
  */
  GOEOptimizableParameterUI(const GOEOptimizableParameterUI&);
  GOEOptimizableParameterUI& operator=(const GOEOptimizableParameterUI&);

  CATBoolean _bFrameFilled;
};

#endif
