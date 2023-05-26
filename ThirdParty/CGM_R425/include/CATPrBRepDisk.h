/* -*-C++-*- */
#ifndef CATPrBRepDisk_H
#define CATPrBRepDisk_H
// COPYRIGHT DASSAULT SYSTEMES 2016

//===================================================================
//===================================================================
//
// CATPrBRepDisk: BRep piece associated to a disk, dedicated to Similar analysis
//
//===================================================================
//===================================================================
// Dec 2016    Creation                         R. Rorato
//===================================================================

#include "CATPrBRep.h"
#include "ListPOfCATFace.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATCGMNewArray.h"
#include "AdvOpeInfra.h"

class ExportedByAdvOpeInfra CATPrBRepDisk : public CATPrBRep
{
  public:
  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  CATPrBRepDisk(CATPrContext& iContext, const ListPOfCATFace& iFaces, const CATPositiveLength iRadius, const CATMathPoint& iCenter, CATMathVector& iNormal);

  CATCGMNewClassArrayDeclare;        // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  ~CATPrBRepDisk();

  //------------------------------------------------------------------------------
  // Forbidden
  //------------------------------------------------------------------------------
  CATPrBRepDisk(CATPrBRepDisk& iRep);
  CATPrBRepDisk& operator= (const CATPrBRepDisk& iRep);

  //------------------------------------------------------------------------------
  // Returns Geometric Representation
  //------------------------------------------------------------------------------
  void GetOwnedCells(CATLISTP(CATCell) &oCells, CATListOfInt* oOrns = NULL);

  //------------------------------------------------------------------------------
  // Data Access
  //------------------------------------------------------------------------------
  const CATMathPoint& GetCenter() const;
  const CATMathVector& GetNormal() const;

private:

  //------------------------------------------------------------------------------
  // Dump internal data
  //------------------------------------------------------------------------------
  void Dump(CATCGMOutput& ioOS);

  //------------------------------------------------------------------------------
  // Safe Cast
  //------------------------------------------------------------------------------
  CATPrBRepDisk* GetAsPrBRepDisk();

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
  CATPositiveLength _Radius;
  CATMathPoint      _Center;
  CATMathVector     _Normal;
};

#endif
