
/* -*-C++-*- */

#ifndef CATCVMGeoExplode_H
#define CATCVMGeoExplode_H

// COPYRIGHT DASSAULT SYSTEMES 2007

//===================================================================
//===================================================================
//
// CATCVMGeoExplode
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

class ExportedByCATCVMGeoOperators CATCVMGeoExplode : public CATCVMGeoOperator
{
  //------------------------------------------------------------------------------
  // Create a EditInPlace operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoExplode *Create(CATCVMInstancePath *iCVMInstancePath,
                                  CATTopData         *iTopData);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMGeoExplode(CATTopData           *iTopData,
                   CATCVMGeoOperatorExt *iExtensible);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  public:
  virtual ~CATCVMGeoExplode();

  //------------------------------------------------------------------------------
  // Set the destination unfolded component
  //------------------------------------------------------------------------------
  public:
  HRESULT SetUnfoldedComponent(CATCVMComponent *iUnfoldedComponent);

  //------------------------------------------------------------------------------
  // Add the instance path to be exploded (explodes the reference of the last instance of
  // this instance path)
  //------------------------------------------------------------------------------
  public:
  HRESULT SetInstancePath(CATCVMInstancePath *iInstancePath);

  //------------------------------------------------------------------------------
  // Add the reference to be exploded
  //------------------------------------------------------------------------------
  private:
  HRESULT SetReference(CATCVMReference *iReference);

  //------------------------------------------------------------------------------
  // Get the resulting systems (input list will be emptyed and then filled with the results)
  //------------------------------------------------------------------------------
  public:
  HRESULT GetResultingSystems(ListPOfCATCVMSystem * ioSystemList);

  public:
  static const CATString *GetDefaultOperatorId();
};
#endif
