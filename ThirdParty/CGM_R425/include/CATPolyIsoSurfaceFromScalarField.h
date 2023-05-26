// COPYRIGHT DASSAULT SYSTEMES 2020, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyIsoSurfaceFromScalarField.h
// Header definition of CATPolyIsoSurfaceFromScalarField
//
//  This class contains the functions that create an fill a VRep from
// a scalar field. Then call an operator on the VRep to create a mesh.
//===================================================================
//===================================================================
//
// September 2020  Creation: RBU3
//===================================================================
#ifndef CATPolyIsoSurfaceFromScalarField_H
#define CATPolyIsoSurfaceFromScalarField_H

#include "CATFuzzyPolyOper.h" // Exported By
#include "CATErrorDef.h"      // HRESULT
#include "CATTolerance.h"
#include "CATBoolean.h"
#include "CATSysBoolean.h"

class CATSoftwareConfiguration;
class CATIPolyMesh;

class CATCGMProgressBar;

/**
* This class create and fill a VRep from a ScalarField. then call an operator on it
* to generate a mesh.<br>
**/

class ExportedByCATFuzzyPolyOper CATPolyIsoSurfaceFromScalarField
{

public:

  //==============================================================================
  // Destructor 
  //==============================================================================
  /**
  * Standard destructor.<br>
  **/
  virtual ~CATPolyIsoSurfaceFromScalarField() {};

  //==============================================================================
  // Public set optional methods to customize the behavior
  //==============================================================================

  /**
  * Set the min and max value to be added to the VRep.
  * Allow this operator to generate a sparse VRep and thus optimised the creation of the mesh.
  * @param iMinBound
  *   The minimum value to add to the VRep. All the scalar strictly below it will not be added to the VRep.
  * @param iMaxBound
  *   The maximum value to add to the VRep. All the scalar strictly above it will not be added to the VRep.
  */
  virtual void SetMinAndMaxBound(double iMinBound, double iMaxBound) = 0;

  /**
  * Set only the min value to be added to the VRep with no max value.
  * Allow this operator to generate a sparse VRep and thus optimised the creation of the mesh.
  * @param iMinBound
  *   The minimum value to add to the VRep. All the scalar strictly below it will not be added to the VRep.
  */
  virtual void SetMinBound(double iMinBound) = 0;

  /**
  * Set only the max value to be added to the VRep with no min value.
  * Allow this operator to generate a sparse VRep and thus optimised the creation of the mesh.
  * @param iMaxBound
  *   The maximum value to add to the VRep. All the scalar strictly above it will not be added to the VRep.
  */
  virtual void SetMaxBound(double iMaxBound) = 0;

  /**
  * Sets the callback instance that is called to track progress during the Run () method.
  **/
  virtual void SetCallback(CATCGMProgressBar* callback) = 0;

  //==============================================================================
  // Run method 
  //==============================================================================

  /**
  * Create and Fill the VRep, then call the Dual Contouring to create a mesh
  **/
  virtual HRESULT Run() = 0;

  /**
  * Returns the error code when the fuzzy offset fails.
  * See CATFuzError for the definitions of the various errors.
  * Returns CATFuzError eNoError when there is no error.
  */
  virtual int GetError() const = 0;

};

// =============================================================================
// Creates an instance of CATPolyIsoSurfaceFromScalarField operator 
// This is the constructor of the VRep builder from a ScalarField operator that should be used.
//  @param iSoftwareConfiguration
//    The software configuration to respect versioning(always the more recent version if NULL)
//  @param iTol
//    The Tolerance is required in order to declare the scale of the global scene and to be consistent with the offset mesh result.
//  @param iScalarField
//    The input scalarField from which the VRep is filled with, stored in an array.
//    Its size must be egal to dimX*dimY*dimZ. 
//      iScalarField[0] = (x0, y0, z0), iScalarField[1] = (x0, y0, z1) ... iScalarField[dimZ] = (x0, y1, z0) ... iScalarField[dimY * dimZ] = (x1, y0, z0)
//  @param iDimField
//    The dimension of the scalar field according to each direction (x, y, z)
//  @param iOrigin
//    The position in space of the first point of the scalar field.
//  @param iStepBetweenScalar
//    The step in space between each value in the scalar field. MUST be the same in all direction.
//  @param oResultMesh
//    The result mesh.This should be an empty mesh that will be filled in
//    during computation of the offset.
//==============================================================================
ExportedByCATFuzzyPolyOper CATPolyIsoSurfaceFromScalarField* CATCreateCATPolyIsoSurfaceFromScalarField(CATSoftwareConfiguration * iSoftwareConfiguration,
  const CATTolerance & iTol,
  float *iInputScalarField,
  const int iDimField[3],
  const double iOrigin[3],
  double iStepBetweenScalar,
  double iIsoValue,
  CATIPolyMesh &oResultMesh);

#endif
