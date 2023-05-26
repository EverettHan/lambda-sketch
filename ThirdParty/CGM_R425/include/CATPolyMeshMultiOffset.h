// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshMultiOffset.h
// Header definition of CATPolyMeshMultiOffset
//
// This class contains the function that calculates multi offset mesh from 
// an input polygonal mesh. (Polyhedral offset only.)
//===================================================================
//===================================================================
//
// September 2006  Creation: DPS, CHU
//===================================================================
#ifndef CATPolyMeshMultiOffset_H
#define CATPolyMeshMultiOffset_H

#include "CATFuzzyPolyOper.h" // Exported By
#include "CATErrorDef.h"      // HRESULT
#include "CATTolerance.h"

class CATSoftwareConfiguration;
class CATVRepTree;
class CATMathBox;
class CATMathPoint;
class CATIPolyMesh;
class CATIPolyFactory;

class CATCGMProgressBar;


/**
* This class performs a polyhedral fuzzy offset from a polygonal mesh.<br>
**/

class ExportedByCATFuzzyPolyOper CATPolyMeshMultiOffset 
{

public:

  //==============================================================================
  // Destructor 
  //==============================================================================
  /**
  * Standard destructor.<br>
  **/
  virtual ~CATPolyMeshMultiOffset() {};


  // Returns the maximal deviation of the computed mesh according to exact offset value
  virtual double GetMaxDeviation() = 0;


  //==============================================================================
  // Public set optional methods to customize the behavior
  // PLEASE, USE Setxxx() METHODS EXCLUSIVELY BEFORE THE FIRST RunOffset() CALL !
  // [ except method SetCallback() which has to be called before each RunOffset() ]
  //==============================================================================

  // optional method to reduce offset result inside a specific box 
  virtual void SetActiveBoundingBox(const CATMathPoint& iMinPoint, const CATMathPoint& iMaxPoint) = 0; // InputMesh Box by default

  // mandatory method to close the offset envelope around the initial boundaries 
  virtual void SetRoundedBorderMode(const int iRoundedBorderMode) = 0; // 0 by default

  // mandatory method to generate offset in both sides (to compute envelope) 
  virtual void SetBothSides(const int iBothSides) = 0; // 0 by default

  // optional service - internal use only
  virtual void SetExtendedBorderMode(const int iExtendedBorderMode) = 0; // 0 by default


  //==============================================================================
  // Run method (to call several times with different offset values)
  // NOTE THAT THE FIRST RunOffset() CALL COMPUTES THE VREP DATA : THE CPU TIME IS MORE IMPORTANT
  //==============================================================================

  /**
  * Sets the callback instance that is called to track progress during one RunOffset() call.
  **/
  virtual void SetCallback(CATCGMProgressBar* callback) = 0;

  /**
  * Performs the polyhedral fuzzy offset.
  **/
  virtual HRESULT RunOffset(double iOffsetValue, CATIPolyMesh &oResultMesh) = 0;

};

//==============================================================================
// Creates an instance of CATPolyMeshMultiOffset operator 
//==============================================================================
/**
* This is the constructor of the polyhedral multi-offset operator.
* @param iSoftwareConfiguration
*   The software configuration to respect versioning (always the more recent version if NULL)
* @param iTol
*   The Tolerance is required in order to declare the scale of the global scene and to be consistent with the offset mesh result.
* @param iInputMesh
*   The input polyhedral mesh from which the offset mesh is calculated.
* @param iOffsetMinValue
*   The minimum value of the offset to apply on the InputMesh
* @param iOffsetMaxValue
*   The maximum value of the offset to apply on the InputMesh
* @param iClientMaxDeviation
*   The maximal deviation allowed by the client
*/
ExportedByCATFuzzyPolyOper CATPolyMeshMultiOffset * CATCreateCATPolyMeshMultiOffset(CATSoftwareConfiguration * iSoftwareConfiguration,
                                                                                    const CATTolerance & iTol,
                                                                                    const CATIPolyMesh &iInputMesh,
                                                                                    double iOffsetMinValue,
                                                                                    double iOffsetMaxValue,
                                                                                    double iClientMaxDeviation);

//==============================================================================
// Creates an instance of CATPolyMeshMultiOffset operator 
//==============================================================================
/**
* This is the constructor of the polyhedral multi-offset operator.
* @param iSoftwareConfiguration
*   The software configuration to respect versioning (always the more recent version if NULL)
* @param iSceneScaleCategory
*   The ScaleCategory is required in order to declare the scale of the global scene and to be consistent with the offset mesh result.
* @param iInputMesh
*   The input polyhedral mesh from which the offset mesh is calculated.
* @param iOffsetMinValue
*   The minimum value of the offset to apply on the InputMesh
* @param iOffsetMaxValue
*   The maximum value of the offset to apply on the InputMesh
* @param iClientMaxDeviation
*   The maximal deviation allowed by the client
*/
ExportedByCATFuzzyPolyOper CATPolyMeshMultiOffset * CATCreateCATPolyMeshMultiOffset(CATSoftwareConfiguration * iSoftwareConfiguration,
                                                                                    CATCGMScaleCategory iSceneScaleCategory,
                                                                                    const CATIPolyMesh &iInputMesh,
                                                                                    double iOffsetMinValue,
                                                                                    double iOffsetMaxValue,
                                                                                    double iClientMaxDeviation);

#endif
