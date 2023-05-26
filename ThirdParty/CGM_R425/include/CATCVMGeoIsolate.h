
/* -*-C++-*- */

#ifndef CATCVMGeoIsolate_H
#define CATCVMGeoIsolate_H

// COPYRIGHT DASSAULT SYSTEMES 2007

//===================================================================
//===================================================================
//
// CATCVMGeoIsolate
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// December 2007    Creation                         FDN
//===================================================================

#include "CATCVMGeoOperators.h"
#include "CATCVMGeoOperator.h"
#include "CATCVMComponent.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "ListPOfCATCVMSystem.h"

class CATCVMGeoContainer;
class CATCVMReference;
class CATCVMInstancePath;

class ExportedByCATCVMGeoOperators CATCVMGeoIsolate : public CATCVMGeoOperator
{
  //------------------------------------------------------------------------------
  // Create a EditInPlace operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoIsolate *Create(CATCVMInstancePath *iCVMInstancePath, CATTopData *iTopData);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMGeoIsolate(CATTopData           *iTopData,
                   CATCVMGeoOperatorExt *iExtensible);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  public:
  virtual ~CATCVMGeoIsolate();

  //------------------------------------------------------------------------------
  // Set the destination unfolded component
  //------------------------------------------------------------------------------
  //public:
  //HRESULT SetUnfoldedComponent(CATCVMComponent *iUnfoldedComponent);

  //------------------------------------------------------------------------------
  // Add the instance path to be isolated
  //------------------------------------------------------------------------------
  public:
  HRESULT SetInstancePath(CATCVMInstancePath *iInstancePath);

  public:
  static const CATString *GetDefaultOperatorId();
};
#endif
