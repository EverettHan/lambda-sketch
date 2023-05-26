/* -*-C++-*- */
#ifndef CATPrBRepHole_H
#define CATPrBRepHole_H
// COPYRIGHT DASSAULT SYSTEMES 2014

//===================================================================
//===================================================================
//
// CATPrBRepHole: BRep piece associated to a hole, dedicated to Similar analysis
//
//===================================================================
//===================================================================
// Dec 2014    Creation                         R. Rorato
//===================================================================

#include "CATPrBRep.h"
#include "ListPOfCATFace.h"
#include "CATMathPoint.h"
#include "CATCGMNewArray.h"
#include "AdvOpeInfra.h"

class ExportedByAdvOpeInfra CATPrBRepHole : public CATPrBRep
{
  public:
  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  CATPrBRepHole(CATPrContext& iContext, const unsigned char iSurfaceTypeId, const ListPOfCATFace& iFaces, const CATPositiveLength iRadius1, const CATPositiveLength iRadius2, const CATMathPoint& iPt1, const CATMathPoint& iPt2);

  CATCGMNewClassArrayDeclare;        // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  ~CATPrBRepHole();

  //------------------------------------------------------------------------------
  // Forbidden
  //------------------------------------------------------------------------------
  CATPrBRepHole(CATPrBRepHole& iRep);
  CATPrBRepHole& operator= (const CATPrBRepHole& iRep);

  //------------------------------------------------------------------------------
  // Returns Geometric Representation
  //------------------------------------------------------------------------------
  void GetOwnedCells(CATLISTP(CATCell) &oCells, CATListOfInt* oOrns = NULL);

private:

  //------------------------------------------------------------------------------
  // Dump internal data
  //------------------------------------------------------------------------------
  void Dump(CATCGMOutput& ioOS);

  //------------------------------------------------------------------------------
  // Safe Cast
  //------------------------------------------------------------------------------
  CATPrBRepHole* GetAsPrBRepHole();

  //------------------------------------------------------------------------------
  // IsEqual based on Specifications
  //------------------------------------------------------------------------------
  CATBoolean IsEqualBasedOnSpecGlobal(const CATMathTransformation& iTransfo, CATPrBRep& iRep, const double& iTolForAngleTest, const double& iTolForSquareLengthTest); 

  //------------------------------------------------------------------------------
  // Compute Trihedrons specific to this class
  //------------------------------------------------------------------------------
  virtual CATTrdSet* ComputeTrihedrons();

  //------------------------------------------------------------------------------
  // Get Surface Type Id specific to this class
  //------------------------------------------------------------------------------
  unsigned char GetSurfaceTypeId();

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private :

  ListPOfCATFace    _Faces;
  CATPositiveLength _Radius[2];
  CATMathPoint      _Point[2];
  unsigned char     _SurfaceTypeId;
};

#endif
