// ----------------------------------------------------------------------------
//  COPYRIGHT DASSAULT SYSTEMES 2005
// ----------------------------------------------------------------------------
//  CATIA Framework Visualization
// ----------------------------------------------------------------
//  Abstract    : 
// ----------------------------------------------------------------
//  Usage       : 
// ----------------------------------------------------------------
//  Inheritance : None
// ----------------------------------------------------------------
//  Main APIs   :
// ----------------------------------------------------------------------------
//
// C++

// This header file contains settings definition.
// 1. Label Settings.
// 2. Show/NoShow of Secondary curves
// 3. Grid Curves Display Mode
// 4. Grid Element Selection ID

#ifndef CATVis3DGridDef_H
#define CATVis3DGridDef_H

#include "CATUnicodeString.h"
#include "CATBoolean.h"
#include "CATGraphicAttributeSet.h"

// Label settings
// The structure holds the grid curve label settings.  The structure 
// is useful in customizing label according to the applications’ requirements.
// Two instances of the structure to be derived, one for horizontal curves
// and other for vertical curves.
struct CATVis3DGridLabelSettings
{
  CATBoolean _mLabelActive;          // Boolean to set/unset Label. Default is False.
  CATUnicodeString _mLabelFixedTxt;  // Stores the Label Text..
  enum Orientation                   // Orientation represents whether label
  {                                  // to be displayed horizontally, vertically 
    Orientation_HORIZONTAL = 0,      // or along with the axis (horizontal label 
    Orientation_VERTICAL,            // for horizontal curve and vertical label for vertical curve).
    Orientation_ALONG_THE_AXIS,      // Default value being horizontal label.  
  } _mOrientation;

  CATGraphicAttributeSet _mLabelGA;  // Stores the Graphical Attributes of the label.
  CATUnicodeString _mLabelFontName;  // Stores the font name of the label.  Default value is “Verdana”.

  enum LabelPosOnScreen              // Set the position of the labels on the screen.
  {                                  //                                                                 CATFontServices
    LabelPosOnScreen_START = 0,      // START represents lower extremity of grid curve.
    LabelPosOnScreen_END,            // END represents higher extremity of of the grid curve.
    LabelPosOnScreen_BOTH            // Both represents requirement of label on either ends.
  } _mLabelPosOnScreen;              // Default is BOTH

  enum LabelPosOnGridCurve           // Set the location of the labels on the grid curve.
  {                                  
    LabelPosOnGridCurve_LEFT = 0,    // LEFT   represents the anchor position LEFT  for Vertical (V) Curves and anchor position TOP    for Horizontal (U) Curves.
    LabelPosOnGridCurve_RIGHT,       // RIGHT  represents the anchor position RIGHT for Vertical (V) Curves and anchor position BOTTOM for Horizontal (U) Curves.
    LabelPosOnGridCurve_MIDDLE       // MIDDLE represents the anchor position BASE  for both Vertical (V) and Horizontal (U) Curves.
  } _mLabelPosOnGridCurve;           // Default position on grid curve is LEFT.

  // Start IIX - Jan 07 - Highlight: 3D Grid for GSD 
  float _mScaleFactorForTxt;         // Scale factor for Label Text.
  // End IIX - Jan 07 - Highlight: 3D Grid for GSD 
  float _mHeight;               // float to set the label font height 
  CATBoolean _mDumpForXML;      // boolean to decide dumping the labels or not for labelsample application
  // Structure CONSTRUCTOR
  CATVis3DGridLabelSettings( void ): _mLabelActive        (FALSE),
                                     _mLabelFixedTxt      (NULL),
                                     _mOrientation        (Orientation_ALONG_THE_AXIS),
                                     _mLabelFontName      ("Verdana"),
                                     _mLabelPosOnScreen   (LabelPosOnScreen_BOTH),
                                     _mLabelPosOnGridCurve(LabelPosOnGridCurve_LEFT),
                                     _mScaleFactorForTxt  (1.0f),
                                     _mHeight             (10.f),
                                     _mDumpForXML         (FALSE)
                                                                       

  {
  }

  ~CATVis3DGridLabelSettings(){ }

};

// Grid Curves Show/No-Show
// Grid - Automatic Scaling
// Curves can be either Fixed in number or Dynamic in nature.
// ALWAYS  -> Curves are fixed in number.
// DYNAMIC -> Curves vary depending on the space between curves.
enum CATVis3DGridCurvesShow
{
  CATVis3DGridCurvesShow_ALWAYS  = 0,     // Always fixed number of curves will be drawn as per Unit and NbSecCurves settings
  CATVis3DGridCurvesShow_DYNAMIC,         // Number of curves are adjusted to have better display and not to overload visualization
  CATVis3DGridCurvesShow_DYNAMIC_PRIM_FXD, // Number of curves are adjusted to have better display and not to overload visualization with
                                           // primary curves being fixed to the value initialized.
  // Start IIX - Jan 07 - Highlight: 3D Grid for GSD 
  CATVis3DGridCurvesShow_DYNAMIC_PRIM_MAX_NO // Number of curves are reduced by a specific factor, when curves in any direction exceeds user-defined limit.
  // End IIX - Jan 07 - Highlight: 3D Grid for GSD 
};

// Curve Display Mode                 
enum CATVis3DGridCurveDisplayMode
{
  CATVis3DGridCurveDisplayMode_CURVE = 0, // Display only curves
  CATVis3DGridCurveDisplayMode_CROSS,     // Display only intersections of curves
  CATVis3DGridCurveDisplayMode_BOTH       // Display both curves and intersections
}; 

// Grid Element Selection ID.
// Following enumeration data holds grid element selection ID.
enum CATVis3DGridElemType
{
  CATVis3DGridElemType_Unknown = 0,         // No element selected
  CATVis3DGridElemType_PrimaryUIsoParam,    // Primary isoparametric curve on U-axis selected.
  CATVis3DGridElemType_PrimaryVIsoParam,    // Primary isoparametric curve on V-axis selected.
  CATVis3DGridElemType_SecondaryUIsoParam,  // Secondary isoparametric curve on U-axis selected.
  CATVis3DGridElemType_SecondaryVIsoParam,  // Secondary isoparametric curve on V-axis selected.
  CATVis3DGridElemType_IntPtPriPri,         // Intersection point of two primary curves.
  CATVis3DGridElemType_IntPtPriSec,         // Intersection point of a U-primary curve and a V-secondary curve.
  CATVis3DGridElemType_IntPtSecPri,         // Intersection point of a U-secondary curve and a V-primary curve.
  CATVis3DGridElemType_IntPtSecSec          // Intersection point of two Secondary curves.
};

// Grid sub element is recognized by id and index. Note that this identification is invariant
// For example...
// 1. id = CATVis3DGridElemType_PrimaryUIsoParam & UIndex = -2 ( VIndex can be ignored)
//           will be primary curve with constant u = -2*iUUnit ( i.e. vertical curve for orthogonal grid)
// 2. id = CATVis3DGridElemType_SecondaryVIsoParam & VIndex = 7 ( UIndex can be ignored)
//          will be Secondary curve with constant v = 7*iVUnit/iVNbSecCurves ( i.e. horizontal curve for
//          orthogonal grid)
// 3. id = CATVis3DGridElemID_IntPtPriSec & UIndex = -2, VIndex = 7
//          will intersection of above 2 curves
struct CATVis3DGridElemId
{
  CATVis3DGridElemType _Type;
  int UIndex;
  int VIndex;

  CATVis3DGridElemId(void)
  {
    _Type  = CATVis3DGridElemType_Unknown;
    UIndex = 0;
    VIndex = 0;
  }
  ~CATVis3DGridElemId(void){}
};

// Following structure provides points and normal information of Grid intersection with viewing direction.
// This is useful for grid element selection.
// one 3D point for selection of intersection of 2 curves,
// two 3D points for selection any curve, 
// one 3D point and one 3D normal for the grid plane, if any
class CATVis3DGridElemModelInfo
{
public:
  enum CATVis3DGridGeomType
  {
    CATVis3DGridPoint=0,
    CATVis3DGridInfiniteLine,
    CATVis3DGridPlane,
    CATVis3DGridArcCircle
  };

  CATVis3DGridElemModelInfo ()
  {
    for(int i = 0; i < 3; i++)
    {
      _mPoint[i]  = 0.f;
      _mDirection[i] = 0.f;
    }
    _mGeometricType = CATVis3DGridInfiniteLine;
  }

  CATVis3DGridElemModelInfo ( float iPoint[3], float iDirection[3])
  {
    int i;
    for(i = 0; i < 3; i++)
        _mPoint[i]  = iPoint[i];
    for(i = 0; i < 3; i++)
        _mDirection[i] = iDirection[i];
  }

  ~CATVis3DGridElemModelInfo()
  {
  }

  CATVis3DGridElemModelInfo& operator =(const CATVis3DGridElemModelInfo &iModelInfo)
  {
    int i;
    for(i = 0; i < 3; i++)
      _mPoint[i]  = iModelInfo._mPoint[i];
    for(i = 0; i < 3; i++)
      _mDirection[i] = iModelInfo._mDirection[i];
    _mGeometricType = iModelInfo._mGeometricType;
    return (*this);
  }

  CATVis3DGridElemModelInfo (const CATVis3DGridElemModelInfo &iModelInfo)
  {
    int i;
    for(i = 0; i < 3; i++)
      _mPoint[i]  = iModelInfo._mPoint[i];
    for(i = 0; i < 3; i++)
      _mDirection[i] = iModelInfo._mDirection[i];
    _mGeometricType = iModelInfo._mGeometricType;
  }

  void SetModelInfoPoint(const float iPoint[3])
  {
    for(int i = 0; i < 3; i++)
      _mPoint[i]  = iPoint[i];
  }

  void GetModelInfoPoint(float oPoint[3])
  {
    for(int i = 0; i < 3; i++)
      oPoint[i] = _mPoint[i];
  }

  void SetModelInfoDirection(const float iDirection[3])
  {
    for(int i = 0; i < 3; i++)
      _mDirection[i]  = iDirection[i];
  }

  void GetModelInfoDirection(float oDirection[3])
  {
    for(int i = 0; i < 3; i++)
      oDirection[i] = _mDirection[i];
  }

  void SetModelInfoGeometricType( const CATVis3DGridGeomType iGeomType )
  {
    _mGeometricType = iGeomType;
  }

  void GetModelInfoGeometricType( CATVis3DGridGeomType &oGeomType )
  {
    oGeomType = _mGeometricType;
  }

private:
  CATVis3DGridGeomType _mGeometricType;
  float _mPoint[3], _mDirection[3];
};

#endif

