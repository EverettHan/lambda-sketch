// COPYRIGHT DASSAULT SYSTEMES 2020, ALL RIGHTS RESERVED.
//=================================================================================
// CATMultiSupportFillet:
//  Interface of fillet operator around multiple supports for additive manufacturing 
//=================================================================================
// 10 07 2020 TAT3 Creation 

#ifndef CATMultiSupportFillet_H
#define CATMultiSupportFillet_H

#include "AdvTopoOpeItf.h"
#include "CATTopMultiResult.h"
#include "CATCGMSharedPtr.h"

// Math
#include "CATMathPoint.h"
#include "CATMathVector.h"
// Geo

// Topo
#include "CATCGMOutput.h"

class CATIPolyMesh;


/** @class Virtual Class that manages Filleting operations
* for Additive Supports.
* Specify the Radius of the output fillet and the SAG of
* the output mesh. Then use specialized derived classes
* to apply filleting on different additive support types.
*
*/
class ExportedByAdvTopoOpeItf CATMultiSupportFillet : public CATTopMultiResult {
  CATCGMVirtualDeclareClass(CATMultiSupportFillet);
public:
  CATMultiSupportFillet(CATGeoFactory *iFactory,  CATSoftwareConfiguration *config);

  virtual ~CATMultiSupportFillet();

  /** @brief Define the SAG of the output mesh
  * @param iSAG value of the SAG */
  void SetOutpuMeshSAG(const double iSAG) ;

  /** @brief Define the Fillet radius.
  * @param iRadius Radius of the fillet. */
  void SetFilletRadius(const double iRadius) ;

  /** @brief Define a thickness for the cones.
  * A paralel cone will be removed inside leaving the given thickness. */
  void SetThickness(const double iThickness);

  /** @brief Returns the pointer to the current mesh result. */
  CATIPolyMesh *GetMeshResult() const;

  /** @brief Returns the pointer to the current result body.*/
  CATBody *GetExactResult() const;

  int GetNbOfSupports() const;
  
  /** Support Perforations. @{*/

 /** @brief Peroration Profile
 * @param iSketchProfile 2D Sketch of the perforations.
 * The sketch is assumed to lie on xOz plane centered on O. */
  void SetPerforationProfile(CATBody *iSketchProfile);

  /** @brief Set perforation mode to curvilinear (along the supports border)
   * At the moment, this mode must be used together with a specified depth
   * using <pre> SetPerforationDepth(false, depth) </pre>
   * The perforations are positionned around the bottom contour of the support
   * with no fillet.
   * @param iInterval Interval between consecutive perforations along the contour.
   */
  void SetCurvilinearPerfo(double iInterval);

  /** @brief Set perforation mode to paralel perforations.
   * At the moment, this mode must be used with <pre>SetPerforationDepth(true) </pre>
  * All perforation will be paralel to iAxis.
  * @param iAxis Axis of all the perforations.
  * @param iInterval Periodic distance between two paralel perforations. */
  void SetOneAxisPerfo(const CATMathVector & iAxis, double iInterval);

  /** @brief Set Perforation mode to grid.
    * At the moment, this mode must be used with <pre>SetPerforationDepth(true) </pre>
   * @param iAxis1 1st Axis of the grid axis.
   * @param iAxis2 2nd Axis of the grid axis.
   * @param iInterval1 Periodic distance between the perforations in the first direction.
   * @param iInterval2 Periodic distance between the perforations in the second direction.
  */
  void SetTwoAxisPerfo(const CATMathVector & iAxis1, const CATMathVector& iAxis2, double iInterval1, double iInterval2);

  /** @brief Define one initial position to callibrate the grid or curvilinear perforations.
  * At least one perforation will go through this point, even if the point is outside the support.
  * @param iPosition The position.
  */
  void SetPerforationStart(const CATMathPoint& iPosition);

  /** @brief
  * The depth mode of the perforation between a specified depth or going all the way through the support.
  * If a depth is specified, it is measure from the bottom of the fillet without perforation such that
  * the fillet part is always perforated but the fillet is not counted as part of the depth.
  * @param iUpToLast At the moment, use true for One or Two Axis, use false in curvilinear.
  * @param iDepth If the first param is set to false, the specified depth of the perforation.
  */
  void SetPerforationDepth(CATBoolean iUpToLast, double iDepth = 0.);

  /** @}*/

  /** @brief
  * Runs this operator.
  * To retrieve the resulting bodies, use the iterator on the bodies provided by CATTopMultiResult.
  */
  virtual int Run();

protected:
  // Number of supports
  int _NbOfSupports;

  // SAG of the tesselated results
  double _SAG; 

  // Radius of the fillets
  double _FilletRadius;

  // Thickness of the cones
  double _Thickness;

  // Input Supports
  CATBody **_InputSupports;

  // Output Fillet Lists
  CATCGMSharedPtr<CATIPolyMesh> *_OutputMeshes;
  CATBody **_OutputExactBodies;
  CATSoftwareConfiguration *_SoftwareConfig;

  /* Perforation. */
  /** @{*/

  // Perforation Data

  CATBody * _PerforationProfile;
  double _CurvilinearInterval;
  CATMathVector _PerforationAxis1;
  CATMathVector _PerforationAxis2;
  double _PerforationInterval1;
  double _PerforationInterval2;
  CATMathPoint _PerforationStart;
  CATBoolean _PerforationUpToLast;
  double _PerforationDepth;
  int _PerforationPlacement;
  /** @}*/

    /* CATTopMultiResult */
  //CATLONG32 GetNumberOfResults() const;

  //void BeginningResult();

  //CATBoolean NextResult();

  //void AddResults();


//    // For CGMReplay
///** @nodoc */
//  static CATString _OperatorId;
//
//  /** @nodoc */
//  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
//
//  /** @nodoc */
//  void WriteInput(CATCGMStream  & ioStream);
//
  /** @nodoc */
  void Dump(CATCGMOutput& os);

//
//  /** @nodoc */
//  void RequireDefinitionOfInputAndOutputObjects();
//
//  /** @nodoc */
//  void DumpOutput(CATCGMOutput& os);
//
  /** @nodoc */
  CATCGMOperator::CATCheckDiagnostic  CheckOutput(CATCGMOutput & os);
};

inline void CATMultiSupportFillet::SetPerforationProfile(CATBody * iSketchProfile)
{
  _PerforationProfile = iSketchProfile;
}

inline void CATMultiSupportFillet::SetPerforationStart(const CATMathPoint& iPosition)
{
  _PerforationStart = iPosition;
}

inline void CATMultiSupportFillet::SetPerforationDepth(CATBoolean iUpToLast, double iDepth)
{
  _PerforationUpToLast = iUpToLast;
  _PerforationDepth = iDepth;
}


#endif
