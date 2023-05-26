// COPYRIGHT DASSAULT SYSTEMES 2016, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshEnvelope.h
// Header definition of CATPolyMeshEnvelope
//
// This class contains the function that calculates a polyhedral envelope mesh 
// (dilation then erosion) from an input polygonal mesh.
//===================================================================
//===================================================================
//
// July 2016  Creation: H7W
//===================================================================

#ifndef CATPolyMeshEnvelope_H
#define CATPolyMeshEnvelope_H

#include "CATFuzzyPolyOper.h" // Exported By
#include "CATErrorDef.h"      // HRESULT
#include "CATTolerance.h"     // CATTolerance
#include "CATBoolean.h"       // TRUE / FALSE
#include "CATSysBoolean.h"

#include "CATMathBox.h"
#include "CATListOfInt.h"

#include "CATCGMSTDSafeIncludeStart.h"
#include <vector>
#include "CATCGMSTDSafeIncludeEnd.h"

#include "CATCGMScaleCategoryDef.h" // enum CATCGMScaleCategory

class CATSoftwareConfiguration;
class CATMathPoint;
class CATIPolyMesh;
class CATIPolyFactory;

class CATCGMProgressBar;

class PolyTrianglesPartitionCell;
class CATPolyVoxelPath;

// Phoenix
class PolyMeshEnvelope_CATechExt;
class CATechExt;

/**
* This class performs a polyhedral envelope mesh from an input polygonal mesh.<br>
**/
class ExportedByCATFuzzyPolyOper CATPolyMeshEnvelope 
{

public:

  //==============================================================================
  // Destructor 
  //==============================================================================
  /**
  * Standard destructor.<br>
  **/
  virtual ~CATPolyMeshEnvelope() {};


  // Returns the maximal deviation of the computed mesh according to exact offset value
  virtual double GetMaxDeviation() = 0;

  /** 
  * Returns the error code when the fuzzy offset fails.
  * See CATFuzError for the definitions of the various errors.
  * Returns CATFuzError::eNoError when there is no error.
  */
  virtual int GetError() const = 0;

  //==============================================================================
  // Public set optional methods to customize the behavior
  //==============================================================================

  // optional method to reduce offset result inside a specific box 
  virtual void SetActiveBoundingBox(const CATMathPoint& iMinPoint, const CATMathPoint& iMaxPoint) = 0; // InputMesh Box by default

  virtual void SetOffsetZeroMode(const int iOffsetZeroMode) = 0;

  // optional service - internal use only
  virtual void SetInclusionMode(const int iInclusionMode) = 0; // 0 by default

  // When multithreaded dual contouring is enabled, will decimate
  // the generated mesh using the provided chordal deviation
  virtual void SetDecimationMode(const int iDecimationMode) = 0; // 0 by default
  virtual void ActivateMultiTaskDecimation(const double iChordalDeviation) = 0; // 0. by default

  // Activate the Dubious Data Management consists in 3 actions :
  // 1. Enable undefined signs during CPT, (no sense in case of unsigned distance fields)
  // 2. then report the dubious status on triangles closed to undefined distance fields, (no sense in case of unsigned distance fields)
  // 3. then clean the result mesh, removing dubious triangles which compose unexpected connected subset.
  virtual void ActivateDubiousDataManagement() = 0;

  // SetStratPropagationPoint
  // By default the Wrapper operator propagate the front from the corner of the Octree (0, 0, 0).
  // The result is always the external envelope.
  // In order to obtain an inner envelope, an other start point have to be set by this method.
  virtual void SetStartPropagationPoint(CATMathPoint iStartPoint) = 0;


  /**
  * Sets the callback instance that is called to track progress during the Run () method.
  **/
  virtual void SetCallback(CATCGMProgressBar* callback) = 0;

  virtual HRESULT GetVoxelSizeFromExpectedDepth(double & oVoxelSize) = 0;
  virtual HRESULT GetExpectedDepthFromVoxelSize(int & oExpectedDepth) = 0;

  virtual CATListOfInt & GetLevelOfInclusion() = 0;

  //virtual void GetAllVoxelInGivenDirection(const CATPolyVoxelPath &idifVx, int ikp, int iVoxelDepthMax, std::vector<CATPolyVoxelPath> &oListVx) = 0;
  
  //==============================================================================
  // Run method 
  //==============================================================================

  /**
  * Performs the polyhedral fuzzy offset.
  **/
  virtual HRESULT Run() = 0;

  virtual void * GetDEnvelopeSubMeshContext() = 0;
	
  /**
  * no doc
  * PlayBack/Phoenix implementation
  */ 
  virtual CATechExt * HasPhoenixExtension(CATBoolean iForceCreation=FALSE) = 0;
};

// =============================================================================
// Creates an instance of CATPolyMeshEnvelope operator 
// This is the constructor of the polyhedral offset operator that should be used.
//  @param iSoftwareConfiguration
//    The software configuration to respect versioning(always the more recent version if NULL)
//  @param iTol
//    The Tolerance is required in order to declare the scale of the global scene and to be consistent with the offset mesh result.
//  @param iInputMesh
//    The input polyhedral mesh from which the offset mesh is calculated.
//  @param oResultMesh
//    The result mesh.This should be an empty mesh that will be filled in
//    during computation of the offset.
//  @param iOffsetValue
//    The offset to apply on the InputMesh to compute the result mesh.
//  @param iClientMaxDeviation
//    The maximal deviation allowed by the client.
//==============================================================================
ExportedByCATFuzzyPolyOper CATPolyMeshEnvelope* CATCreateCATPolyMeshEnvelope(CATSoftwareConfiguration * iSoftwareConfiguration,
                                                                              const CATTolerance & iTol,
                                                                              const CATIPolyMesh &iInputMesh,
                                                                              CATIPolyMesh &oResultMesh,
                                                                              double iOffsetValue,
                                                                              double iClientMaxDeviation);

// =============================================================================
// Creates an instance of CATPolyMeshEnvelope operator 
// This is an other constructor of the polyhedral offset operator that should be used.
//  @param iSoftwareConfiguration
//    The software configuration to respect versioning(always the more recent version if NULL)
//  @param iTol
//    The Tolerance is required in order to declare the scale of the global scene and to be consistent with the offset mesh result.
//  @param iInputMesh
//    The input polyhedral mesh from which the offset mesh is calculated.
//  @param oResultMesh
//    The result mesh.This should be an empty mesh that will be filled in
//    during computation of the offset.
//  @param iOffsetValue
//    The offset to apply on the InputMesh to compute the result mesh.
//  @param iClientExpectedDepth
//    The depth of the octree allowed by the client(between 6 and 12 for a representative result).
//    This parameter define the quality level of the offset operation.
//==============================================================================
ExportedByCATFuzzyPolyOper CATPolyMeshEnvelope* CATCreateCATPolyMeshEnvelope(CATSoftwareConfiguration * iSoftwareConfiguration,
                                                                              const CATTolerance & iTol,
                                                                              const CATIPolyMesh &iInputMesh,
                                                                              CATIPolyMesh &oResultMesh,
                                                                              double iOffsetValue,
                                                                              int iClientExpectedDepth);

// =============================================================================
// Creates an instance of CATPolyMeshEnvelope operator 
// This is the constructor of the polyhedral offset operator that should be used.
//  @param iSoftwareConfiguration
//    The software configuration to respect versioning(always the more recent version if NULL)
//  @param iSceneScaleCategory
//    The ScaleCategory is required in order to declare the scale of the global scene and to be consistent with the offset mesh result.
//  @param iInputMesh
//    The input polyhedral mesh from which the offset mesh is calculated.
//  @param oResultMesh
//    The result mesh.This should be an empty mesh that will be filled in
//    during computation of the offset.
//  @param iOffsetValue
//    The offset to apply on the InputMesh to compute the result mesh.
//  @param iClientMaxDeviation
//    The maximal deviation allowed by the client.
//==============================================================================
ExportedByCATFuzzyPolyOper CATPolyMeshEnvelope* CATCreateCATPolyMeshEnvelope(CATSoftwareConfiguration * iSoftwareConfiguration,
                                                                              CATCGMScaleCategory iSceneScaleCategory,
                                                                              const CATIPolyMesh &iInputMesh,
                                                                              CATIPolyMesh &oResultMesh,
                                                                              double iOffsetValue,
                                                                              double iClientMaxDeviation);

// =============================================================================
// Creates an instance of CATPolyMeshEnvelope operator 
// This is an other constructor of the polyhedral offset operator that should be used.
//  @param iSoftwareConfiguration
//    The software configuration to respect versioning(always the more recent version if NULL)
//  @param iSceneScaleCategory
//    The ScaleCategory is required in order to declare the scale of the global scene and to be consistent with the offset mesh result.
//  @param iInputMesh
//    The input polyhedral mesh from which the offset mesh is calculated.
//  @param oResultMesh
//    The result mesh.This should be an empty mesh that will be filled in
//    during computation of the offset.
//  @param iOffsetValue
//    The offset to apply on the InputMesh to compute the result mesh.
//  @param iClientExpectedDepth
//    The depth of the octree allowed by the client(between 6 and 12 for a representative result).
//    This parameter define the quality level of the offset operation.
//==============================================================================
ExportedByCATFuzzyPolyOper CATPolyMeshEnvelope* CATCreateCATPolyMeshEnvelope(CATSoftwareConfiguration * iSoftwareConfiguration,
                                                                              CATCGMScaleCategory iSceneScaleCategory,
                                                                              const CATIPolyMesh &iInputMesh,
                                                                              CATIPolyMesh &oResultMesh,
                                                                              double iOffsetValue,
                                                                              int iClientExpectedDepth);


#endif

