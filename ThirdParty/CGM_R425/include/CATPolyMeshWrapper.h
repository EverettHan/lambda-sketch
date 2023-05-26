// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//===============================================================================
//
// CATPolyMeshWrapper.h
// Header definition of CATPolyWrapper
//
// This class contains the function that calculates a polyhedral wrapper mesh 
// from an input polyhedral mesh which is almost closed.
// The size of the greatest hole have to be known and given to the operator.
//===============================================================================
//===============================================================================
//
// February 2018  Creation: H7W
//===============================================================================

#ifndef CATPolyMeshWrapper_H
#define CATPolyMeshWrapper_H

#include "CATFuzzyPolyOper.h" // Exported By
#include "CATErrorDef.h"      // HRESULT
#include "CATTolerance.h"     // CATTolerance

class CATSoftwareConfiguration;
class CATIPolyMesh;
class CATCGMProgressBar;
class CATMathPoint;

/**
* This class performs an external envelope of the input polyhedral mesh.<br>
**/
class ExportedByCATFuzzyPolyOper CATPolyMeshWrapper 
{
  
public :
  //==============================================================================
  // Destructor 
  //==============================================================================
  /**
  * Standard destructor.<br>
  **/
  virtual ~CATPolyMeshWrapper() {};

  // Returns the maximal deviation of the computed mesh according to the input
  virtual double GetMaxDeviation() = 0;

  //==============================================================================
  // Public set optional methods to customize the behavior
  //==============================================================================

  // SetSmoothnessMode
  // If the argument "iSmoothnessMode" is set to 0, the result mesh will be sharp and nearest the input model.
  // If the argument is set to 1, the result mesh will be smoothest but deviation according to the input model will be higher.
  virtual void SetSmoothnessMode(const int iSmoothnessMode) = 0; // 0 by default

  // SetStratPropagationPoint
  // By default the Wrapper operator propagate the front from the corner of the Octree (0, 0, 0).
  // The result is always the external envelope.
  // In order to obtain an inner envelope, an other start point have to be set by this method.
  virtual void SetStartPropagationPoint(CATMathPoint iStartPoint) = 0;


  /**
  * Sets the callback instance that is called to track progress during the Run () method.
  **/
  virtual void SetCallback(CATCGMProgressBar* callback) = 0;

  //==============================================================================
  // Run method 
  //==============================================================================

  /**
  * Performs the polyhedral wrapper operator.
  **/
  virtual HRESULT Run() = 0;
};

// =============================================================================
// Creates an instance of CATPolyMeshWrapper operator 
// This is the constructor of the polyhedral wrapper operator that should be used.
// @param iSoftwareConfiguration
//   The software configuration to respect versioning (always the more recent version if NULL)
// @param iTol
//   To customize scalability parameters
// @param iInputMesh
//   The input polyhedral mesh from which the external envelope mesh is calculated.
// @param oResultMesh
//   The result mesh.  This should be an empty mesh that will be filled in
//   during computation of the wrapping.
// @param iMaxSizeOfHole
//	  The hole maximum size of the input model in order to be closed.
//==============================================================================
ExportedByCATFuzzyPolyOper CATPolyMeshWrapper* CATCreateCATPolyMeshWrapper(CATSoftwareConfiguration * iSoftwareConfiguration,
                                                                            const CATTolerance & iTol,
                                                                            const CATIPolyMesh &iInputMesh,
                                                                            CATIPolyMesh &oResultMesh,
                                                                            double iMaxSizeOfHole);

#endif
