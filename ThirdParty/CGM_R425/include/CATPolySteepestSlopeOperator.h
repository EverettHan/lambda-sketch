#ifndef CATPolySteepestSlopeOperator_h__
#define CATPolySteepestSlopeOperator_h__

//===================================================================
// COPYRIGHT Dassault Systemes 2017
//===================================================================
// CATPolySteepestSlopeOperator.h
// Header definition of class CATPolySteepestSlopeOperator
//===================================================================
//
// Usage notes: Compute the Steepest Slope (as vector) at each triangle
//
//===================================================================
// HISTORIQUE :
// 12.07.2019 : RAQ : Génération interfaces
// 18/02/2017 : NUA : Creation
//===================================================================
// export
#include "CATIAV5Level.h"
#include "ExportedByCATPolyWatershedOperators.h"

//Interface
#ifdef CATIAR422
#include "CATPGMPolySteepestSlopeOperator.h"
#endif  //CATIAR422

// Error handling
#include "CATSysErrorDef.h"

class CATIPolyMesh;
class CATMathVector;
class CATTolerance;
struct CATPolyWatershedCallback;

/*
1 - Instanciate operator 
2 - Call run method
3 - if its return S_OK, each call to GetSlopeAtTriangle returns the steepest slope (unit vector)
*/

#ifdef CATIAR422
class ExportedByCATPolyWatershedOperators CATPolySteepestSlopeOperator : public CATPGMPolySteepestSlopeOperator
#else
class ExportedByCATPolyWatershedOperators CATPolySteepestSlopeOperator
#endif  //CATIAR422
{
public:
  //------------------ creation of the operator
  static CATPolySteepestSlopeOperator * CreateInstance(const CATIPolyMesh & iMesh, const CATTolerance & iTolObject);
  
  virtual ~CATPolySteepestSlopeOperator() {}
  
  // Enable to know the current computation state 
  virtual void SetProgressCallback(CATPolyWatershedCallback * iCB) = 0;

  virtual HRESULT Run() = 0;

  virtual HRESULT GetSlopeAtTriangle(const int iNumTriangle, CATMathVector & oSlope) const = 0;

};
#endif // CATPolySteepestSlopeOperator_h__
