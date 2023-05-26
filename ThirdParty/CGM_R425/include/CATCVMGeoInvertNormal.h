/* -*-C++-*- */

#ifndef CATCVMGeoInvertNormal_H
#define CATCVMGeoInvertNormal_H

// COPYRIGHT DASSAULT SYSTEMES 2009

//===================================================================
//===================================================================
//
// CATCVMGeoInvertNormal
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// April 2009    Creation                         ASE
//===================================================================

#include "CATCVMGeoOperators.h"
#include "CATCVMGeoOperator.h"
#include "CATBoolean.h"
#include "ListPOfCATCVMGeometry.h"
#include "ListPOfCATCVMInstancePath.h"

class CATCVMGeoContainer;
class CATCVMGeometry;
class CATCVMInstancePath;

class ExportedByCATCVMGeoOperators CATCVMGeoInvertNormal : public CATCVMGeoOperator
{
  CATCGMVirtualDeclareClass(CATCVMGeoInvertNormal);
  //------------------------------------------------------------------------------
  // Create an InvertNormal operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoInvertNormal* Create(CATCVMGeoContainer *iCVMGeoContainer,
                                       CATTopData         *iTopData);
  static CATCVMGeoInvertNormal* Create(CATCVMInstancePath *iCVMInstancePath,
                                       CATTopData         *iTopData);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMGeoInvertNormal(CATCVMGeoContainer   *iCVMGeoContainer,
                        CATTopData           *iTopData,
                        CATCVMGeoOperatorExt *iExtensible);
  CATCVMGeoInvertNormal(CATTopData           *iTopData,
                        CATCVMGeoOperatorExt *iExtensible);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  public:
  virtual ~CATCVMGeoInvertNormal();

  //------------------------------------------------------------------------------
  // Add a cell for normal inversion
  //------------------------------------------------------------------------------
  public:
  virtual void AddCell(CATCVMGeometry *iCell);

  //------------------------------------------------------------------------------
  // CGM Internal Use
  //------------------------------------------------------------------------------
  public:
  static const CATString *GetDefaultOperatorId();
};
#endif
