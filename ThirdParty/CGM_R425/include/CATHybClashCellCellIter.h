#ifndef _CATHybClashCellCellIter_h
#define _CATHybClashCellCellIter_h

#include "CATCGMRefCounted.h"    // derivation
#include "Autocheck.h"              // ExportedBy

#include "CATSysBoolean.h"

class CATCell;
#include "CATPGMHybClashCellCellIter.h"

class ExportedByAutocheck CATHybClashCellCellIter : public CATPGMHybClashCellCellIter // CATCGMRefCounted
{
  
public:

  // Life Cycle Management
  // ---------------------
  // No constructor
  // This class is instanciated by the CATHybClashBodyChecker during Run().
  
  // *********************************************************************************************
  // PLEASE USE Release function TO REMOVE THE OPERATOR INSTANCE
  // *********************************************************************************************

public:

  // Iterator services
  // -----------------
  virtual void Begin()=0;
  virtual CATBoolean End()=0;
  virtual void operator ++()=0;

public:

  // Data access
  // -----------

  /*
   * Method to retrieve CATCells for the current couple.
   * Int value must be 1 or 2 : the position of the cell in the couple.
   */
  virtual CATCell* GetCell(int) = 0;

};

#endif
