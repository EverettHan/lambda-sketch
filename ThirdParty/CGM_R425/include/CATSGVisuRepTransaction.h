#pragma once

#include "SGInfra.h"

#include "CATStdLib.h"
#include "CATBoolean.h"

class CATSGVisuTransactionImpl;
class CATSGVisuRepTransactionImpl;
class CATRep;


class ExportedBySGInfra CATSGVisuRepTransaction
{
public:
  /*
  Sets optimized mode for representation display
  When this mode is active, representation drawing order will not depend on scene graph order anymore.
  In the quality manager, there is a setting to 
  This is only supported with CAT3DCustomRep.
  */
  HRESULT SetOptimizedMode(CATBoolean iSet);

  /** @return TRUE if the optimized mode has been activated for the representation */
  CATBoolean IsInOptimizedMode() const;

  /** @return The internal implementation with private services, DO NOT USE! */
  CATSGVisuRepTransactionImpl& GetImpl();

private:
	// all ctor/dtor are private: this cannot be instantiated by anything but a CATSGVisuTransactionImpl
  CATSGVisuRepTransaction();
  CATSGVisuRepTransaction(CATRep & iRep);
  CATSGVisuRepTransaction(const CATSGVisuRepTransaction &);
  virtual ~CATSGVisuRepTransaction();

  friend class CATSGVisuTransactionImpl;

  CATSGVisuRepTransactionImpl* _Impl;
  CATRep& _Rep;
};
