// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//=================================================================================
// CATConeSupportFilletImpl:
//  Interface of fillet operator around cone or cylinder supports for additive manufacturing 
//=================================================================================
// 10 07 2020 TAT3 Creation 
// 


#ifndef CATConeSupportFillet_H
#define CATConeSupportFillet_H
#include "AdvTopoOpeItf.h"

// Math
#include "CATMathPoint.h"
#include "CATMathVector.h"

// Base
#include "CATSupportFillet.h"
#include "CATDynFilletRadius.h"

// Declare these op for clean functions
class CATTopRevol;
class CATTopWire;
class CATTopSkin;
class CATDynFillet;
class CATICGMCloseOperator;
class CATICGMDynBoolean;

/**
 * Operator to create the fillet at the bottom intersection of a cone with the z=0 level (representing the tray of the 3D printer).
 */
class ExportedByAdvTopoOpeItf CATConeSupportFillet : public CATSupportFillet {
public:
  CATConeSupportFillet(CATGeoFactory *iFactory, CATSoftwareConfiguration *config);
  
  virtual ~CATConeSupportFillet();
  
  void SetTopConeDefinition(const CATMathPoint &iTopCenter, const CATMathPoint &iBottomCenter, const CATAngle &iAngle, const double &iTopRadius);
  
  int RunOperator();

  /* Getters */
  CATMathPoint GetTopCenter() const;
  CATMathPoint GetBottomCenter() const;
  CATMathVector GetTopBottomVector() const;
  CATAngle GetInnerAngle() const;
  double GetTopRadius() const;

  //static const CATString * GetDefaultOperatorId() { return &_OperatorId; }

protected:
  CATMathPoint _TopCenter;
  CATMathPoint _BottomCenter;
  CATMathVector _TopBottomVector;
  CATAngle _InnerAngle;
  double _TopRadius;

  /* For CGMReplay */
  
  ///** @nodoc @nocgmitf (CGMReplay Mandatory) */
  //static CATString _OperatorId;

  ///** @nodoc @nocgmitf (CGMReplay Mandatory) */
  //const CATString * GetOperatorId();

  ///** @nodoc @nocgmitf (CGMReplay Mandatory) */
  //CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream) ;
  //
  ///** @nodoc @nocgmitf (CGMReplay Mandatory) */
  //void WriteInput(CATCGMStream & Str) ;

  ///** @nodoc @nocgmitf (CGMReplay) */
  //void WriteOutput(CATCGMStream & Str);

  //void RequireDefinitionOfInputAndOutputObjects();

  ///** @nodoc @nocgmitf (CGMReplay) */
  //CATBoolean ValidateOutput(CATCGMStream & Str, CATCGMOutput & os, int VersionNumber);

  ///** @nodoc @nocgmitf */
  //void Dump(CATCGMOutput& os);
private:

/** Check Input */
  int CheckInput();

/** Create the body corresponding to the top support cone. */
  int CreateInputCone();

/** Compute Bottom Contour of the Fillet. */
  int ComputeBottomContour();

/** Create Tray. */
  int CreateTray();

/** Builds the fillet between Support and tray. */
  int FilletOperation();

//============================================================================
// Post Processing Fillet
//============================================================================

/**
 * Main function of the post-processing step.
 *
 */
  int PostProcess();

/* 
 * Retrieves the face of the raw fillet that lies on the tray (to be removed)
 */
  CATFace * GetFaceLyingOnTray();

/** 
 * Remove the one face from the fillet returns a new body that contains only the remainder 
 */
  int RemoveFaceInBody();

/** 
 * Reclose the body
 */
  int CloseBody(CATBody *&pToClose);

/** 
 * Relimit the upper part by a horizontal plane
 */
  int HorizontalCut();

/** 
 * Substracts an inner cone to leave a "shell" of _Thickness width. 
 */
  int RemoveInnerCone();

//============================================================================
// Operators Cleaning
//============================================================================

/* Cleaning for CreateCone */
  void CleanCreateCone(CATCurve *&pLine, CATTopWire * &topWireOp, CATBody *&profileBody, CATTopRevol * &topRevol);
  void CleanRemoveBody(CATICGMDynBoolean *& pRemovalOpe, CATBody *& iBodyB);
  void CleanCreateTray(CATTopSkin* &iTopSkinOp, CATPlane *&iTrayPlane);
  void CleanFilletOperation(CATLISTP(CATFace) &iFaceToFillet, CATLISTP(CATDynFilletRadius) &iFilletList, CATDynFillet *&pFilletOperator);
  void CleanCloseBody(CATICGMCloseOperator *& pCloseOpe);

  //============================================================================
  // Utilities      Face Selection within a body
  //============================================================================
  enum CATFaceTypeSelection {
    CylinderFace,
    NotPlaneFace,
    PlaneFace
  };

/** 
 * Appends iBodyFace to oSelectedfaces if it matches type.
 * @param type 0 to select CATCylinderType, 1 to select Not CATPlaneType
 * @return oSelectedFaces list of the faces corresponding to be added to
 * @param iBodyFace CATFace to test type.
 */
  void SelectFacesOfType(CATFaceTypeSelection type, CATLISTP(CATFace)& oSelectedFaces, CATFace* iBodyFace, CATBoolean verb = FALSE);


/** 
 * Select Faces of iBody that match the type.
 * @paramint type 0 to select CATCylinderType, 1 to select Not CATPlaneType
 * @return oSelectedFaces List of the faces corresponding to the type.
 * @param iBody Input CATBody containing the faces.
 */
  int SelectFacesInBody(CATFaceTypeSelection type, CATLISTP(CATFace)& oSelectedFaces, CATBody *iBody, CATBoolean verb);

/* Computes the projection of U on the plane (V, W) */
  CATMathVector Project(const CATMathVector &iU, const CATMathVector &iV, const CATMathVector &iW);

  //============================================================================
  // Utilities      Factoring Operations between Run steps 
  //============================================================================

/* Create a cone from two points and one axis. */
  CATBody *CreateCone(CATMathPoint &iP1, CATMathPoint &iP2, CATMathAxis &iAxis);

/* Performs Boolean difference (removal) of iBodyB from iBodyA */
  CATBody *RemoveBody(CATBody* &iBodyA, CATBody *&iBodyB, CATBoolean iDeleteB = FALSE);
  CATAngle _AxisAngle;  // Angle between Cone Axis and Horizontal plane.

  //============================================================================
  // Perforation      Exchange data to perforation operator
  //============================================================================

  CATBody *_BottomContour;

  CATBody *_InnerCone;

};

inline  CATMathPoint CATConeSupportFillet::GetTopCenter() const {
  return _TopCenter;
}

inline  CATMathPoint CATConeSupportFillet::GetBottomCenter() const {
  return _BottomCenter;
}

inline CATMathVector CATConeSupportFillet::GetTopBottomVector() const {
  return _TopBottomVector;
}

inline CATAngle CATConeSupportFillet::GetInnerAngle() const {
  return _InnerAngle;
}

inline double CATConeSupportFillet::GetTopRadius() const {
  return _TopRadius;
}

/** 
 * @brief global function to create instance of ConeSupportFillet.
 * @param iFactory Pointer to the geometry factory that create the result bodies.
 * @param iConfig Pointer to the software configuraiton.
*/
ExportedByAdvTopoOpeItf CATConeSupportFillet *CATCreateConeSupportFillet(CATGeoFactory *iFactory,  CATSoftwareConfiguration *config);

#endif

