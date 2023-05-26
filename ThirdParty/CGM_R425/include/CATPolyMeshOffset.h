// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshOffset.h
// Header definition of CATPolyMeshOffset
//
// This class contains the function that calculates an offset mesh from 
// an input polygonal mesh. (Polyhedral offset only.)
//===================================================================
//===================================================================
//
// July 2006  Creation: DPS, CHU
// December 2018  Rearchi: H7W
//===================================================================
#ifndef CATPolyMeshOffset_H
#define CATPolyMeshOffset_H

#include "CATFuzzyPolyOper.h" // Exported By
#include "CATErrorDef.h"      // HRESULT
#include "CATTolerance.h"
#include "CATBoolean.h"
#include "CATSysBoolean.h"

#include "CATCGMScaleCategoryDef.h" // enum CATCGMScaleCategory

class CATSoftwareConfiguration;
class CATMathBox;
class CATMathPoint;
class CATIPolyMesh;
class CATIPolyFactory;

class CATCGMProgressBar;

// Phoenix
class PolyMeshOffset_CATechExt;
class CATechExt;


/**
* This class performs a polyhedral fuzzy offset from a polygonal mesh.<br>
**/

class ExportedByCATFuzzyPolyOper CATPolyMeshOffset 
{

public:

  //==============================================================================
  // Destructor 
  //==============================================================================
  /**
  * Standard destructor.<br>
  **/
  virtual ~CATPolyMeshOffset() {};

  //==============================================================================
  // Public set optional methods to customize the behavior
  //==============================================================================

  // optional method to reduce offset result inside a specific box 
  virtual void SetActiveBoundingBox(const CATMathPoint& iMinPoint, const CATMathPoint& iMaxPoint) = 0; // InputMesh Box by default

  // mandatory method to close the offset envelope around the initial boundaries 
  virtual void SetRoundedBorderMode(const int iRoundedBorderMode) = 0; // 0 by default

  // SetBothSides
  // Mandatory method to generate offset in both sides (to compute envelope) 
  // If the argument "iDisconnectSides" is set to 1, the result mesh will be composed by 
  // 2 disconnected Sub Mesh, one for the negative side and another one for the positive side
  virtual void SetBothSides(const int iBothSides, int iDisconnectSides=0) = 0; // 0 by default

  // Optional service - internal use only
  virtual void SetExtendedBorderMode(const int iExtendedBorderMode) = 0; // 0 by default

  // Activates multithreaded Dual Contouring (tessellation of the isosurface)
  virtual void ActivateMultiTaskMode() = 0;

  // When multithreaded dual contouring is enabled, will decimate
  // the generated mesh using the provided chordal deviation
  //
  // -> Default mode : decimation under control : it ensure that the decimation will
  // not generate auto-intersection or other default in the resulting mesh.
  // -> If desactivated, the decimation does not do any checks and is much faster
  // BUT the mesh may need to be healed (or at least checked) after the dual. 
  //  There may be intersecting triangles + there is no check on the number of triangles of volumes
  //  and thus, some volume can be planar (only 3 or 2 triangles) when they are small in comparison to the ChordalDeviation.
  //  In the worse case, really small cavities can disapear.
  virtual void ActivateMultiTaskDecimation(const double iChordalDeviation, CATBoolean iDecimationUnderControl = TRUE) = 0;

  // Activate the Dubious Data Management consists in 3 actions :
  // 1. Enable undefined signs during CPT, (no sense in case of unsigned distance fields)
  // 2. then report the dubious status on triangles closed to undefined distance fields, (no sense in case of unsigned distance fields)
  // 3. then clean the result mesh, removing dubious triangles which compose unexpected connected subset.
  virtual void ActivateDubiousDataManagement() = 0;


  /**
  * Sets the callback instance that is called to track progress during the Run () method.
  **/
  virtual void SetCallback(CATCGMProgressBar* callback) = 0;

  virtual HRESULT GetVoxelSizeFromExpectedDepth(double & oVoxelSize) = 0;
  virtual HRESULT GetExpectedDepthFromVoxelSize(int & oExpectedDepth) = 0;

  //==============================================================================
  // Run method 
  //==============================================================================

  /**
  * Performs the polyhedral fuzzy offset.
  **/
  virtual HRESULT Run() = 0;
	
  /**
   *Returns the maximal deviation of the computed mesh according to exact offset value
   **/
  virtual double GetMaxDeviation() = 0;

  /**
  * Returns the error code when the fuzzy offset fails.
  * See CATFuzError for the definitions of the various errors.
  * Returns CATFuzError::eNoError when there is no error.
  */
  virtual int GetError() const = 0;

  /**
   * Call back for CPT in case of DEnvelope with 2 distinct components to prepare the Median Mesh 
   **/
  virtual void * GetDEnvelopeSubMeshContext() = 0;


  /**
  * no doc
  * PlayBack/Phoenix implementation
  */ 
  virtual CATechExt * HasPhoenixExtension(CATBoolean iForceCreation=FALSE) = 0;

  /**
   * Triangles are not generated by dual contouring in areas in which the distance values encoded in the octree are not
   * consistent enough. In some situation you might still want to be a bit more tolerant about that, default value
   * is 1.1 , it is recommended that you don't set values above 2.0.
   */
  virtual void SetAllowedDistanceDisturbanceFactor(const double iAllowedDistanceDisturbanceFactor) = 0;

  /**
   * Returns the allowed distance disturbance factor, see SetAllowedDistanceDisturbanceFactor.
   */
  virtual double GetAllowedDistanceDisturbanceFactor() = 0;

  /**
   * Set the dual contouring mode. Should be CUSTOMDISTANCECHECK if you want to specify allowed distance disturbance
   * factor yourself. Other wise passing:
   * STRICTDISTANCECHECK would reset allowed distance factor to 1.1 (the default value)
   * COARSEDISTANCECHECK would set it to 1.9
   */
  virtual void SetDualContouringMode(const int iDualContouringMode) = 0;

  /**
   * Returns the dual contouring mode. If Custom you will have to check exact value of AllowedDistanceDisturbanceFactor.
   */
  virtual int GetDualContouringMode() = 0;
};

// =============================================================================
// Creates an instance of CATPolyMeshOffset operator 
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
//  @param iTol
//     to customize scalability parameters(extreme scale context only)
//==============================================================================
ExportedByCATFuzzyPolyOper CATPolyMeshOffset* CATCreateCATPolyMeshOffset(CATSoftwareConfiguration * iSoftwareConfiguration,
                                                                          const CATTolerance & iTol,
                                                                          const CATIPolyMesh &iInputMesh,
                                                                          CATIPolyMesh &oResultMesh,
                                                                          double iOffsetValue,
                                                                          double iClientMaxDeviation);

// =============================================================================
// Creates an instance of CATPolyMeshOffset operator 
// This is an other constructor of the polyhedral offset operator that should be used.
// @param iSoftwareConfiguration
//   The software configuration to respect versioning(always the more recent version if NULL)
// @param iTol
//   The Tolerance is required in order to declare the scale of the global scene and to be consistent with the offset mesh result.
// @param iInputMesh
//   The input polyhedral mesh from which the offset mesh is calculated.
// @param oResultMesh
//   The result mesh.This should be an empty mesh that will be filled in
//   during computation of the offset.
// @param iOffsetValue
//   The offset to apply on the InputMesh to compute the result mesh.
// @param iClientExpectedDepth
//   The depth of the octree allowed by the client(between 6 and 12 for a representative result).
// This parameter define the quality level of the offset operation.
// @param iTol
//    to customize scalability parameters(extreme scale context only)
//==============================================================================
ExportedByCATFuzzyPolyOper CATPolyMeshOffset* CATCreateCATPolyMeshOffset(CATSoftwareConfiguration * iSoftwareConfiguration,
                                                                          const CATTolerance & iTol,
                                                                          const CATIPolyMesh &iInputMesh,
                                                                          CATIPolyMesh &oResultMesh,
                                                                          double iOffsetValue,
                                                                          int iClientExpectedDepth);

// =============================================================================
// Creates an instance of CATPolyMeshOffset operator 
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
//  @param iTol
//     to customize scalability parameters(extreme scale context only)
//==============================================================================
ExportedByCATFuzzyPolyOper CATPolyMeshOffset* CATCreateCATPolyMeshOffset(CATSoftwareConfiguration * iSoftwareConfiguration,
                                                                          CATCGMScaleCategory iSceneScaleCategory,
                                                                          const CATIPolyMesh &iInputMesh,
                                                                          CATIPolyMesh &oResultMesh,
                                                                          double iOffsetValue,
                                                                          double iClientMaxDeviation);

// =============================================================================
// Creates an instance of CATPolyMeshOffset operator 
// This is an other constructor of the polyhedral offset operator that should be used.
// @param iSoftwareConfiguration
//   The software configuration to respect versioning(always the more recent version if NULL)
// @param iSceneScaleCategory
//   The ScaleCategory is required in order to declare the scale of the global scene and to be consistent with the offset mesh result.
// @param iInputMesh
//   The input polyhedral mesh from which the offset mesh is calculated.
// @param oResultMesh
//   The result mesh.This should be an empty mesh that will be filled in
//   during computation of the offset.
// @param iOffsetValue
//   The offset to apply on the InputMesh to compute the result mesh.
// @param iClientExpectedDepth
//   The depth of the octree allowed by the client(between 6 and 12 for a representative result).
// This parameter define the quality level of the offset operation.
// @param iTol
//    to customize scalability parameters(extreme scale context only)
//==============================================================================
ExportedByCATFuzzyPolyOper CATPolyMeshOffset* CATCreateCATPolyMeshOffset(CATSoftwareConfiguration * iSoftwareConfiguration,
                                                                          CATCGMScaleCategory iSceneScaleCategory,
                                                                          const CATIPolyMesh &iInputMesh,
                                                                          CATIPolyMesh &oResultMesh,
                                                                          double iOffsetValue,
                                                                          int iClientExpectedDepth);

#endif
