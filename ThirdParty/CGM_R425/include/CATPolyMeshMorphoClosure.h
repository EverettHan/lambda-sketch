// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshMorphoClosure.h
// Header definition of CATPolyMeshMorphoClosure
//
// This class contains the function that calculates a polyhedral morphological closure mesh 
// (dilation then erosion) from an input polygonal mesh.
//===================================================================
//===================================================================
//
// July 2006  Creation: DPS, CHU
// December 2018  Rearchi: H7W
//===================================================================
#ifndef CATPolyMeshMorphoClosure_H
#define CATPolyMeshMorphoClosure_H

#include "CATFuzzyPolyOper.h" // Exported By
#include "CATErrorDef.h"      // HRESULT
#include "CATTolerance.h"     // CATTolerance
#include "CATBoolean.h"       // TRUE / FALSE

class CATSoftwareConfiguration;
class CATIPolyMesh;
class CATPolyULONG32Pool;

class CATCGMProgressBar;

class CATIPolyFactory;

/**
* This class performs a polyhedral morphological closure mesh from an input polygonal mesh.<br>
**/

class ExportedByCATFuzzyPolyOper CATPolyMeshMorphoClosure 
{

public:

  //==============================================================================
  // Destructor 
  //==============================================================================
  /**
  * Standard destructor.<br>
  **/
  virtual ~CATPolyMeshMorphoClosure() {};


  //==============================================================================
  // Public set optional methods to customize the behavior
  //==============================================================================

  /**
  * Sets the callback instance that is called to track progress during the Run () method.
  **/
  virtual void SetCallback(CATCGMProgressBar* callback) = 0;

  virtual void SetMedianMeshMode(int iMedianMeshMode) = 0;

  virtual void SetErosionCleanMode(int iCleanMode) = 0;

  virtual void SetDilationRoundedBorderMode(int iRoundedBorderMode) = 0;

  virtual void SetDilationExtendedBorderMode(int iExtendedBorderMode) = 0;

  virtual void SetErosionExtendedBorderMode(int iExtendedBorderMode) = 0;

  virtual void SetOutsideDilationTagMode(int iEnableMode) = 0;


  //==============================================================================
  // Run method 
  //==============================================================================

  /**
  * Performs the polyhedral fuzzy offset.
  **/
  virtual HRESULT Run() = 0;
	

  virtual CATBoolean IsVtxOutsideDilation(int iVtxTag) = 0;


  virtual CATIPolyMesh & GetResultMesh() = 0;
  virtual double GetDilationValue() = 0;
  virtual double GetVoxelSize() = 0;

};

//==============================================================================
/* Creates an instance of CATPolyMeshMorphoClosure operator
* This is the constructor of the morpho closure operator that should be used.
* @param iSoftwareConfiguration
*   The software configuration to respect versioning (always the more recent version if NULL)
* @param iTol
*   The Tolerance is required in order to declare the scale of the global scene and to be consistent with the offset mesh result.
* @param iInputMesh
*   The input polyhedral mesh from which the closure mesh is calculated.
* @param oResultMesh
*   The result mesh.  This should be an empty mesh that will be filled in
*   during computation of the closure.
* @param iDilationValue
*   The offset to apply on the d-envelope during Dilation.
* @param iVoxelSize
*   The size of the leaf elements in the VRep (Octree with recorded distances)
*/
ExportedByCATFuzzyPolyOper CATPolyMeshMorphoClosure * CATCreateCATPolyMeshMorphoClosure(CATSoftwareConfiguration * iSoftwareConfiguration,
                                                                                        const CATTolerance & iTol,
                                                                                        const CATIPolyMesh &iInputMesh,
                                                                                        CATIPolyMesh &oResultMesh,
                                                                                        double iDilationValue,
                                                                                        double iVoxelSize);
//==============================================================================
/* Creates an instance of CATPolyMeshMorphoClosure operator
* This is the constructor of the morpho closure operator that should be used.
* @param iSoftwareConfiguration
*   The software configuration to respect versioning (always the more recent version if NULL)
* @param iSceneScaleCategory
*   The ScaleCategory is required in order to declare the scale of the global scene and to be consistent with the offset mesh result.
* @param iInputMesh
*   The input polyhedral mesh from which the closure mesh is calculated.
* @param oResultMesh
*   The result mesh.  This should be an empty mesh that will be filled in
*   during computation of the closure.
* @param iDilationValue
*   The offset to apply on the d-envelope during Dilation.
* @param iVoxelSize
*   The size of the leaf elements in the VRep (Octree with recorded distances)
*/
ExportedByCATFuzzyPolyOper CATPolyMeshMorphoClosure * CATCreateCATPolyMeshMorphoClosure(CATSoftwareConfiguration * iSoftwareConfiguration,
                                                                                        CATCGMScaleCategory iSceneScaleCategory,
                                                                                        const CATIPolyMesh &iInputMesh,
                                                                                        CATIPolyMesh &oResultMesh,
                                                                                        double iDilationValue,
                                                                                        double iVoxelSize);

#endif
