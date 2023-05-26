#ifndef CATPGMPolySteepestSlopeOperator_h_
#define CATPGMPolySteepestSlopeOperator_h_

// COPYRIGHT DASSAULT SYSTEMES 2019

#include "CATPolyhedralOperatorsInterfaces.h"

#include "CATSysErrorDef.h"

class CATIPolyMesh;
class CATMathVector;
struct CATPolyWatershedCallback;
class CATTolerance;

/*
1 - Instanciate operator 
2 - Call run method
3 - if its return S_OK, each call to GetSlopeAtTriangle returns the steepest slope (unit vector)
*/
class ExportedByCATPolyhedralOperatorsInterfaces CATPGMPolySteepestSlopeOperator
{
public:
  /**
   * Destructor
   */
  virtual ~CATPGMPolySteepestSlopeOperator();

  //------------------ creation of the operator
  static CATPGMPolySteepestSlopeOperator *CreateInstance(
    const CATIPolyMesh &iMesh,
    const CATTolerance &iTolObject);

  // Enable to know the current computation state 
  virtual void SetProgressCallback(CATPolyWatershedCallback *iCB) = 0;

  virtual HRESULT Run() = 0;

  virtual HRESULT GetSlopeAtTriangle(
    const int iNumTriangle,
    CATMathVector &oSlope) const = 0;

protected:
  /**
   * Constructor
   */
  CATPGMPolySteepestSlopeOperator();

};

#endif /* CATPGMPolySteepestSlopeOperator_h_ */
