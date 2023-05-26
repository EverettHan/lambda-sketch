/* -*-C++-*- */

#ifndef CATCVMGeoFreeDrag_H
#define CATCVMGeoFreeDrag_H

// COPYRIGHT DASSAULT SYSTEMES 2008

//===================================================================
//===================================================================
//
// CATCVMGeoFreeDrag
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// September 2008    Creation                         ASE
//===================================================================

#include "CATCVMGeoOperators.h"
#include "CATCVMGeoOperator.h"
#include "CATBoolean.h"
#include "ListPOfCATCVMGeometry.h"
#include "ListPOfCATCVMInstancePath.h"

class CATCVMGeoContainer;
class CATCVMGeometry;
class CATMathVector;
class CATCVMInstancePath;

class ExportedByCATCVMGeoOperators CATCVMGeoFreeDrag : public CATCVMGeoOperator
{
  CATCGMVirtualDeclareClass(CATCVMGeoFreeDrag);
  //------------------------------------------------------------------------------
  // Create a free drag operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoFreeDrag* Create(CATCVMGeoContainer *iCVMGeoContainer,
                                   CATTopData         *iTopData);
  static CATCVMGeoFreeDrag* Create(CATCVMInstancePath *iCVMInstancePath,
                                   CATTopData         *iTopData);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMGeoFreeDrag(CATCVMGeoContainer   *iCVMGeoContainer,
                    CATTopData           *iTopData,
                    CATCVMGeoOperatorExt *iExtensible);
  CATCVMGeoFreeDrag(CATTopData           *iTopData,
                    CATCVMGeoOperatorExt *iExtensible);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  public:
  virtual ~CATCVMGeoFreeDrag();

  //------------------------------------------------------------------------------
  // Add a cell for free drag
  //------------------------------------------------------------------------------
  public:
  virtual void AddCell(CATCVMGeometry *iCell,
                       CATMathVector  &iVector);

  //------------------------------------------------------------------------------
  // Set last run mode (FALSE per default)
  //------------------------------------------------------------------------------
  public:
  virtual void SetLastRunMode(CATBoolean iLastRunMode,
                              CATBoolean iCommitResult = TRUE);

  //------------------------------------------------------------------------------
  // CGM Internal Use
  //------------------------------------------------------------------------------
  public:
  static const CATString *GetDefaultOperatorId();

  //------------------------------------------------------------------------------
  // Enable or disable filtering of the selected cells (default enabled)
  //------------------------------------------------------------------------------
  public:
  void SetSelectionFiltering(CATBoolean);

};
#endif
