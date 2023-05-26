#ifndef CATIPGMBodySymmetryOpe_h_
#define CATIPGMBodySymmetryOpe_h_

// COPYRIGHT DASSAULT SYSTEMES 2023

#include "CATGMOperatorsInterfaces.h"
#include "CATIPGMPersistentOperator.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"

class CATGMBodySymmetryImpl;

extern ExportedByCATGMOperatorsInterfaces IID IID_CATIPGMBodySymmetryOpe;

class ExportedByCATGMOperatorsInterfaces CATIPGMBodySymmetryOpe: public CATIPGMPersistentOperator
{
public:
  /**
   * Constructor
   */
  CATIPGMBodySymmetryOpe();

  //------------------
  // Set methods
  //------------------
  virtual void SetTolerance(double iTolerance) = 0;

  //------------------
  // Get methods
  //------------------
  //Faces
  virtual void GetSymmetricFaceLists(
    CATLISTP(CATFace) &oFirstBodySymmetricFaceList,
    CATLISTP(CATFace) &oSecondBodySymmetricFaceList) = 0;

  virtual void GetNonSymmetricFaceLists(
    CATLISTP(CATFace) &oFirstBodyNonSymmetricFaceList,
    CATLISTP(CATFace) &oSecondBodyNonSymmetricFaceList) = 0;

  //Edges
  virtual void GetSymmetricEdgeLists(
    CATLISTP(CATEdge) &oFirstBodySymmetricEdgeList,
    CATLISTP(CATEdge) &oSecondBodySymmetricEdgeList) = 0;

  virtual void GetNonSymmetricEdgeLists(
    CATLISTP(CATEdge) &oFirstBodyNonSymmetricEdgeList,
    CATLISTP(CATEdge) &oSecondBodyNonSymmetricEdgeList) = 0;

protected:
  /**
   * Destructor
   */
  virtual ~CATIPGMBodySymmetryOpe(); // -> delete can't be called
};

// ----------------------
// CATPGMCreateGMBodySymmetryOpe
// ----------------------
ExportedByCATGMOperatorsInterfaces CATIPGMBodySymmetryOpe *CATPGMCreateGMBodySymmetryOpe(
  CATGeoFactory &iFactory,
  CATTopData &iTopData,
  CATBody &iFirstBody,
  CATBody &iSecondBody,
  CATMathPlane &iMirrorPlane);

#endif /* CATIPGMBodySymmetryOpe_h_ */
