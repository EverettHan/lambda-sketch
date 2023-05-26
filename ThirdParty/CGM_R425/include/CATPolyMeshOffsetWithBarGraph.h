// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshOffsetWithBarGraph.h
// Header definition of CATPolyMeshOffsetWithBarGraph
//
// This class contains the function that calculates an offset mesh from 
// an input polygonal mesh. (Polyhedral offset only.)
//===================================================================
//===================================================================
//
// July 2017  Creation: H7W
//===================================================================
#ifndef CATPolyMeshOffsetWithBarGraph_H
#define CATPolyMeshOffsetWithBarGraph_H

#ifndef _MOBILE_SOURCE

#include "CATFuzzyPolyOper.h" // Exported By
#include "CATErrorDef.h"      // HRESULT
#include "CATVRepType.h"
#include "CATTolerance.h"
#include "CATBoolean.h"
#include "CATSysBoolean.h"

class CATSoftwareConfiguration;
class CATMathPoint;
class LatticeNBModel;
class CATIPolyMesh;

class CATCGMProgressBar;

// Phoenix
class CATechExt;


/**
* This class performs a polyhedral fuzzy offset from a polygonal mesh.<br>
**/

class ExportedByCATFuzzyPolyOper CATPolyMeshOffsetWithBarGraph
{

public:


  //==============================================================================
  // Destructor 
  //==============================================================================
  /**
  * Standard destructor.<br>
  **/
  virtual ~CATPolyMeshOffsetWithBarGraph() {};



  //==============================================================================
  // Public set optional methods to customize the behavior
  //==============================================================================

  // optional method to reduce offset result inside a specific box 
  virtual void SetActiveBoundingBox(const CATMathPoint& iMinPoint, const CATMathPoint& iMaxPoint) = 0; // InputMesh Box by default

  // mandatory method to close the offset envelope around the initial boundaries 
  //virtual void SetRoundedBorderMode(const int iRoundedBorderMode) = 0; // 0 by default

  // Optional service - internal use only
  //virtual void SetExtendedBorderMode(const int iExtendedBorderMode) = 0; // 0 by default

  // Smooth jointure between bars of lattices using Metaball, Soft union, Gaussian, or Gaussian with iso-volume smoothing.
  // Metaball and Soft Union act during the computation of the distance field by combining distances
  // to primitives instead of always taking the minimum. They differ in the way the distances are combined.
  // However the tend to create blobs at jointures between bars nit only in concave regions.
  // Gaussian smoothing applies a gaussian blur to the distance field after computation.
  // The Gaussian iso-volume option allows to change the isocut value of the distance field after applying
  // Gaussian smoothing to try retaining a volume as similar as possible to the volume of the non-smoothed mesh.
  virtual void SetSmoothingMode(CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl) = 0;

  // Limit the result by a mesh or Add mesh to the result
  virtual void SetBooleanMode(CATVRepType::BooleanMode iBooleanMode) = 0;

  // Activates multithreaded Dual Contouring (tessellation of the isosurface)
  virtual  void ActivateMultiTaskMode() = 0;

  // When multithreaded dual contouring is enabled, will decimate
  // the generated mesh using the provided chordal deviation
  virtual  void ActivateMultiTaskDecimation(const double iChordalDeviation) = 0;

  virtual  void ActivateProgressiveCPT( unsigned int iNbThreads ) = 0;

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
  * no doc
  * PlayBack/Phoenix implementation
  */ 
  virtual CATechExt * HasPhoenixExtension(CATBoolean iForceCreation=FALSE) = 0;

};

#endif



//==============================================================================
// Constructor 
//==============================================================================
/**
* This is the constructor of the polyhedral offset operator that should be used.
* @param iSoftwareConfiguration
*   The software configuration to respect versioning (always the more recent version if NULL)
* @param iPolyFactory
*   The factory to allow generation of worker mesh during operation
* @param iInputMesh
*   The input polyhedral mesh from which the offset mesh is calculated.
* @param oResultMesh
*   The result mesh.  This should be an empty mesh that will be filled in
*   during computation of the offset.
* @param iOffsetValue
*   The offset to apply on the InputMesh to compute the result mesh.
* @param iClientMaxDeviation
*   The maximal deviation allowed by the client.
* @param iTol
*    to customize scalability parameters (extreme scale context only)
*/
ExportedByCATFuzzyPolyOper CATPolyMeshOffsetWithBarGraph* CATCreateCATPolyMeshOffsetWithBarGraph(CATSoftwareConfiguration * iSoftwareConfiguration,
                                                                                                  const CATTolerance & iTol,
                                                                                                  const LatticeNBModel &iInputBarGraph,
                                                                                                  CATIPolyMesh &oResultMesh,
                                                                                                  double iOffsetValue,
                                                                                                  double iClientMaxDeviation,
                                                                                                  CATIPolyMesh *iLimitMesh = NULL);

/**
* This is an other constructor of the polyhedral offset operator that should be used.
* @param iSoftwareConfiguration
*   The software configuration to respect versioning (always the more recent version if NULL)
* @param iPolyFactory
*   The factory to allow generation of worker mesh during operation
* @param iInputMesh
*   The input polyhedral mesh from which the offset mesh is calculated.
* @param oResultMesh
*   The result mesh.  This should be an empty mesh that will be filled in
*   during computation of the offset.
* @param iOffsetValue
*   The offset to apply on the InputMesh to compute the result mesh.
* @param iClientExpectedDepth
*   The depth of the octree allowed by the client (between 6 and 12 for a representative result).
* This parameter define the quality level of the offset operation.
* @param iTol
*    to customize scalability parameters (extreme scale context only)
*/
ExportedByCATFuzzyPolyOper CATPolyMeshOffsetWithBarGraph* CATCreateCATPolyMeshOffsetWithBarGraph(CATSoftwareConfiguration * iSoftwareConfiguration,
                                                                                                  const CATTolerance & iTol,
                                                                                                  const LatticeNBModel &iInputBarGraph,
                                                                                                  CATIPolyMesh &oResultMesh,
                                                                                                  double iOffsetValue,
                                                                                                  int iClientExpectedDepth,
                                                                                                  CATIPolyMesh *iLimitMesh = NULL);

//==============================================================================
// Constructor 
//==============================================================================
/**
* This is the constructor of the polyhedral offset operator that should be used.
* @param iSoftwareConfiguration
*   The software configuration to respect versioning (always the more recent version if NULL)
* @param iPolyFactory
*   The factory to allow generation of worker mesh during operation
* @param iInputMesh
*   The input polyhedral mesh from which the offset mesh is calculated.
* @param oResultMesh
*   The result mesh.  This should be an empty mesh that will be filled in
*   during computation of the offset.
* @param iOffsetValue
*   The offset to apply on the InputMesh to compute the result mesh.
* @param iClientMaxDeviation
*   The maximal deviation allowed by the client.
* @param iTol
*    to customize scalability parameters (extreme scale context only)
*/
ExportedByCATFuzzyPolyOper CATPolyMeshOffsetWithBarGraph* CATCreateCATPolyMeshOffsetWithBarGraph(CATSoftwareConfiguration * iSoftwareConfiguration,
                                                                                                  CATCGMScaleCategory iSceneScaleCategory,
                                                                                                  const LatticeNBModel &iInputBarGraph,
                                                                                                  CATIPolyMesh &oResultMesh,
                                                                                                  double iOffsetValue,
                                                                                                  double iClientMaxDeviation,
                                                                                                  CATIPolyMesh *iLimitMesh = NULL);

/**
* This is an other constructor of the polyhedral offset operator that should be used.
* @param iSoftwareConfiguration
*   The software configuration to respect versioning (always the more recent version if NULL)
* @param iPolyFactory
*   The factory to allow generation of worker mesh during operation
* @param iInputMesh
*   The input polyhedral mesh from which the offset mesh is calculated.
* @param oResultMesh
*   The result mesh.  This should be an empty mesh that will be filled in
*   during computation of the offset.
* @param iOffsetValue
*   The offset to apply on the InputMesh to compute the result mesh.
* @param iClientExpectedDepth
*   The depth of the octree allowed by the client (between 6 and 12 for a representative result).
* This parameter define the quality level of the offset operation.
* @param iTol
*    to customize scalability parameters (extreme scale context only)
*/
ExportedByCATFuzzyPolyOper CATPolyMeshOffsetWithBarGraph* CATCreateCATPolyMeshOffsetWithBarGraph(CATSoftwareConfiguration * iSoftwareConfiguration,
                                                                                                  CATCGMScaleCategory iSceneScaleCategory,
                                                                                                  const LatticeNBModel &iInputBarGraph,
                                                                                                  CATIPolyMesh &oResultMesh,
                                                                                                  double iOffsetValue,
                                                                                                  int iClientExpectedDepth,
                                                                                                  CATIPolyMesh *iLimitMesh = NULL);

#endif
