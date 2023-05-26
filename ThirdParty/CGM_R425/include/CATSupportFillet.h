// COPYRIGHT DASSAULT SYSTEMES 2020, ALL RIGHTS RESERVED.
//=================================================================================
// CATSupportFillet:
//  Operators to create a fillet around a support for additive manufacturing
//=================================================================================
// 10 07 2020 TAT3 Creation 

#ifndef CATSupportFillet_H
#define CATSupportFillet_H

#include "CATSoftwareConfiguration.h"
#include "CATTopData.h"
#include "CATGeoFactory.h"

#include "CATMathVector.h"
#include "CATBody.h"
#include "CATFace.h"
#include "CATTopOperator.h"

#include "CATIPolyMesh.h"

#include "CATCGMOutput.h"
#include "AdvTopoOpeItf.h"
#include "CATCGMSharedPtr.h"

class CATSupportPerforation;

/**
 * Top level class defining the common fillet and perforation parameters of supports.
 */
class ExportedByAdvTopoOpeItf CATSupportFillet : public CATTopOperator {
  CATCGMVirtualDeclareClass(CATSupportFillet);
public:
  CATSupportFillet(CATGeoFactory *iFactory, CATSoftwareConfiguration *config);
  virtual ~CATSupportFillet();

 /** 
  * @brief Define the SAG of the output mesh
  * @param iSAG value of the SAG 
  */
  void SetOutpuMeshSAG(const double iSAG);

 /** 
  * @brief Define the Fillet radius.
  * @param iRadius Radius of the fillet. 
  */
  void SetFilletRadius(const double iRadius);

/** 
 * @brief Define an inner width from which to remove inner part of the cone. 
 */
  void SetThickness(double iThickness);

/** 
 * @brief Perforation Profile
 * @param iSketchProfile 2D Sketch of the perforations. 
 * The sketch is assumed to lie on xOz plane centered on O. 
 */
  void SetPerforationProfile(CATBody *iSketchProfile);

/** 
 * @brief Set perforation mode to curvilinear (along the supports border)
 * At the moment, this mode must be used together with a specified depth
 * using <pre> SetPerforationDepth(false, depth) </pre>
 * The perforations are positionned around the bottom contour of the support
 * with no fillet.
 * @param iInterval Interval between consecutive perforations along the contour.
 */
  void SetCurvilinearPerfo(double iInterval);

/** 
 * @brief Set perforation mode to paralel perforations.
 * At the moment, this mode must be used with <pre>SetPerforationDepth(true) </pre>
 * All perforation will be paralel to iAxis.
 * @param iAxis Axis of all the perforations.
 * @param iInterval Periodic distance between two paralel perforations. 
 */
  void SetOneAxisPerfo(const CATMathVector & iAxis, double iInterval);

/** 
 * @brief Set Perforation mode to grid.
 * At the moment, this mode must be used with <pre>SetPerforationDepth(true) </pre>
 * @param iAxis1 1st Axis of the grid axis.
 * @param iAxis2 2nd Axis of the grid axis.
 * @param iInterval1 Periodic distance between the perforations in the first direction.
 * @param iInterval2 Periodic distance between the perforations in the second direction.
 */
  void SetTwoAxisPerfo(const CATMathVector & iAxis1, const CATMathVector& iAxis2, double iInterval1, double iInterval2);

/** 
 * @brief Define one initial position to callibrate the grid or curvilinear perforations.
 * At least one perforation will go through this point, even if the point is outside the support.
 * @param iPosition The position.
 */
  void SetPerforationStart(const CATMathPoint& iPosition);

/** 
 * @brief Define the depth mode of the perforation between : a specific depth or entire perforation through the support.
 * If a depth is specified, it is measure from the bottom of the fillet without perforation such that
 * the fillet part is always perforated but the fillet is not counted as part of the depth.
 * @param iUpToLast At the moment, use true for One or Two Axis, use false in curvilinear.
 * @param iDepth If the first param is set to false, the specified depth of the perforation.
 */
  void SetPerforationDepth(CATBoolean iUpToLast, double iDepth = 0.);
  
/** 
 * @brief  Run the operator. 
 */
  int Run();

/** 
 * @brief Return the resulting Mesh corresponding to the set of all fillets. 
 */
  CATIPolyMesh *GetMeshResult() const;

/** 
 * @brief Return the Exact body before tesselation.
 */
  CATBody *GetExactResult();

/** 
 * @brief Equivalent to GetExactResult. 
 */
  CATBody *GetResult();

// //============================================================================
// // Export Functions
// //============================================================================
//   /** @nodoc @nocgmitf */
//  static CATString _OperatorId;
//
//  /** @nodoc @nocgmitf*/
//  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
//
//  /** @nodoc @nocgmitf*/
//  void WriteInput(CATCGMStream  & ioStream);
////
//  /** @nodoc @nocgmitf*/
//  void Dump(CATCGMOutput& os);
//
//  
//    ///** @nodoc @nocgmitf */
//    //void RequireDefinitionOfInputAndOutputObjects() = 0;
//  
//    ///** @nodoc @nocgmitf */
//    //void DumpOutput(CATCGMOutput& os);
//  
//    /** @nodoc @nocgmitf */
//  // CATCGMOperator::CATCheckDiagnostic  CheckOutput(CATCGMOutput & os);
//
//    /* @nocgmitf */
//  static void ReadSupportFilletInput(CATCGMStream & Str, CATLISTP(CATICGMObject) &InputNoCopy, CATSupportFillet &op);

protected:
  CATTopData* _TopData;

  // Inputs
  CATBody *_TrayBody;
  CATFace *_TrayFace;    // List containing the only one face of the tray.
  CATBody *_InputSupport;
  
  // Outputs
  CATBody *_ExactResult;
  CATCGMSharedPtr<CATIPolyMesh> _MeshResult;
  double _FilletRadius;
  double _SAG;
  
  /* for cone only
  if not null, an inner cone is substracted 
  to the output leaving a thickness*/
  double _Thickness; // Cone only

  /* Stores if the Exact value has been fetched by GetExactResult
  * determines wether to remove it from the factory when deleting operator. */
  CATBoolean _RemoveExact; // A nettoyer

  /* @nodoc Remove a body from the factory and its dependencies.
  */
  void RemoveDependencies(CATICGMObject *pBody);

  // Perforation Data
  CATCGMSharedPtr<CATBody> _PerforationProfile;
  double _PerforationI1;
  double _PerforationI2;
  double _PerforationDepth;
  CATMathPoint _PerforationStart;
  CATMathVector _PerforationAxis1;
  CATMathVector _PerforationAxis2;
  short _PerforationAxisMode;
  CATBoolean _PerforationUpToNext;

  // Perforation Process
  int ApplyPerforations(CATSupportPerforation &iOp);


  /* For Debug*/
  //============================================================================
  // Export Functions
  //============================================================================
  void ExportNCGM(CATLISTP(CATICGMObject) & iObjects, CATUnicodeString iFilename);
  void ExportNCGM(CATBody *iObject, CATUnicodeString iFilename);
  void ExportObj(CATIPolyMesh *iMesh, CATUnicodeString iFilename);

  void StepStatus(CATUnicodeString iStepName, int iRC);
  
  void WriteSupportFilletInput(CATCGMStream &Str);

  /* Tesselates the exact result according to SAG. */
  int TesselateBody();
  CATUnicodeString _SupportFillet_ExportInput;
private:
};

inline void CATSupportFillet::SetOutpuMeshSAG(const double iSAG)
{
  if (!_SupportFillet_ExportInput.IsEmpty())
    cgmout << "CATSupportFillet::SetOutpuMeshSAG(" << iSAG << "); //" << cgmendl;
  _SAG = iSAG;
}

inline void CATSupportFillet::SetFilletRadius(const double iRadius)
{
  if (!_SupportFillet_ExportInput.IsEmpty())
    cgmout << "CATSupportFillet::SetFilletRadius(" << iRadius << "); //" << cgmendl;
  _FilletRadius = iRadius;
}

inline void CATSupportFillet::SetThickness(double iThickness) {
  if (!_SupportFillet_ExportInput.IsEmpty())
    cgmout << "CATSupportFillet::SetThickness(" << iThickness << "); //" << cgmendl;
  _Thickness = iThickness;
}

//
inline CATIPolyMesh * CATSupportFillet::GetMeshResult() const
{
  return _MeshResult.get();
}

inline CATBody * CATSupportFillet::GetExactResult()
{
  _RemoveExact = FALSE;
  return _ExactResult;
}

inline CATBody *CATSupportFillet::GetResult() {
  return GetExactResult();
}
  

#endif

