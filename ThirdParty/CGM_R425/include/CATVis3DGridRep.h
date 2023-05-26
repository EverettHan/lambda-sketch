// ----------------------------------------------------------------------------
//  COPYRIGHT DASSAULT SYSTEMES 2005
// ----------------------------------------------------------------------------
//  CATIA Framework Visualization
// ----------------------------------------------------------------
//  Abstract    : Rep for 3D Grid
// ----------------------------------------------------------------
//  Usage       : This is an abstract class.  User would instantiate
//                this rep to make full use of 3D grid.  Interfaces
//                provided with this rep is listed below.
// ----------------------------------------------------------------
//  Inheritance : None
// ----------------------------------------------------------------
//  Main APIs   :     CreateGrid();                 - Returns a 3D-Grid Rep.  Overloaded static function
//                    SetGridPlane();
//                    GetGridPlane();
//                    SetUnit();
//                    GetUnit();
//                    SetNbSecCurves();
//                    GetNbSecCurves();
//                    SetGraphicAttribute();
//                    GetGraphicAttribute();
//                    GetGridElemInvariantId();
//                    GetGridElemModelInfo();
//                    SetIntsPtSymbol();
//                    GetIntsPtSymbol();
//                    SetShadingView();
//                    GetShadingView();
//                    SetGridDisplayFurtiveMode();
//                    GetGridDisplayFurtiveMode();
//                    SetEdgeType();
//                    GetEdgeType();
//                    SetClippingPlaneArea();       - Overloaded
//                    GetClippingPlaneArea();       - Overloaded
//                    SetGridCurvesShow();
//                    GetGridCurvesShow();
//                    GetCurveDisplayMode();
//                    SetCurveDisplayMode();
//                    SetLabelSettings();
//                    GetLabelSettings();
// ----------------------------------------------------------------------------
//// C++
// This class represents a 3D Grid.

#ifndef CATVis3DGridRep_H
#define CATVis3DGridRep_H

#include "CATVis3DGrid.h"
#include "CATVis3DGridDef.h"

// VisualizationBase
#include "CAT3DRep.h"
#include "CATSymbolType.h"

class l_CATVis3DGridRep;

// System
class CATMathDirectionf;
class CATMathPoint2Df;    
class CATMathPointf;

class ExportedByCATVis3DGrid CATVis3DGridRep : public CAT3DRep
{
private:                                                                                        
  friend class l_CATVis3DGridRep;

private:              
  // Constructor
  CATVis3DGridRep();

public:
  // Destructor
  ~CATVis3DGridRep(void);

  // Grid Factory - Virtual Constructor
  static CATVis3DGridRep* CreateGrid( const CATMathPointf &iOrg,            // Grid Plane Origin 
                                      const CATMathDirectionf &iU,          // Grid Plane U axis
                                      const CATMathDirectionf &iV,          // Grid Plane V axis
                                      float iUUnit, float iVUnit,           // Distance between 2 successive primary curves in U and V directions respectively.
                                      int iUNbSecCurves, int iVNbSecCurves, // No. of secondary curves between primary curves in U and V directions respectively.
                                      const CATBoolean iIsOrtho = TRUE,   // Option for Grid Type. Default TRUE (for ORTHO).                    
                                      const CATBoolean iAllowLabelHeightChange = FALSE //option to allow/disallow label font height change                                    
                                    );

  // Function with default values
  static CATVis3DGridRep* CreateGrid( const CATMathPointf &iOrg,            // Grid Plane Origin 
                                      const CATMathDirectionf &iU,          // Grid Plane U axis
                                      const CATMathDirectionf &iV,          // Grid Plane V axis
                                      const CATBoolean iIsOrtho = TRUE,     // Option for Grid Type. Default TRUE (for ORTHO).                    
                                      const CATBoolean iAllowLabelHeightChange = FALSE //option to allow/disallow label font height change
                                    );

  // Set/Get plane definition
  virtual void SetGridPlane( const CATMathPointf &iOrg,  const CATMathDirectionf &iU, const CATMathDirectionf &iV) = 0;
  virtual void GetGridPlane( CATMathPointf &oOrg,  CATMathDirectionf &oU, CATMathDirectionf &oV) = 0;

  // Distance between consecutive primary curves in U and V direction
  virtual void SetUnit( const float &iUUnit, const float &iVUnit) = 0;
  virtual void GetUnit( float &oUUnit, float &oVUnit) = 0;

  // Controls number of secondary curves between 2 primary curves
  // For example, if unit is 100.000 and number of secondary curves is 5,
  // distance between 2 secondary curves would be 20.000
  virtual void SetNbSecCurves( const int &iUNbSecCurves, const int &iVNbSecCurves) = 0;
  virtual void GetNbSecCurves( int &oUNbSecCurves, int &oVNbSecCurves) = 0;

  // Set/Get graphic attributes to the Grid curves.
  virtual void SetGraphicAttribute( const CATGraphicAttributeSet &iPrimaryCurveGA, const CATGraphicAttributeSet &iSecondaryCurveGA) = 0;
  virtual void GetGraphicAttribute( CATGraphicAttributeSet &oPrimaryCurveGA, CATGraphicAttributeSet &oSecondaryCurveGA) = 0;

  // Set/Get graphic attributes on specific curves or crosses selected
  virtual void SetGraphicAttribute ( const CATVis3DGridElemId &iInvariantSubElementId, const CATGraphicAttributeSet &iSpecialCurveGA ) = 0;
  /**** Temp commented due to problems in build
  virtual void GetGraphicAttribute ( CATVis3DGridElemId &oInvariantSubElementId, CATGraphicAttributeSet &oSpecialCurveGA ) = 0;
  *****/
  
  // XK7 openGrid API ++ 
  // This method will use to toggle between open grid and closed grid 
  virtual void SetOpenGridState(CATBoolean iOpenGridBorder) = 0;
  virtual CATBoolean GetOpenGridState() = 0;

  // This method will use to define tolerance to reject gridoutline which is close to the border
  virtual void  SetGridBorderTolerance(float iGridBorderTolerance) = 0;
  virtual float GetGridBorderTolerance() = 0;
  // XK7 openGrid API --
  
  // Method returns invariant (is constant for life time of grid) Grid element identification
  virtual void GetGridElemInvariantId( int iSubElementId, CATVis3DGridElemId &oInvariantSubElementId) = 0;
  virtual void GetGridElemInvariantId( list<int> iSubElementIdList, CATVis3DGridElemId &oInvariantSubElementId) = 0;

  // Method returns the structure containing model information for given sub element id
  virtual void GetGridElemModelInfo( int iSubElemId, CATVis3DGridElemModelInfo  &oGridElemModelInfo ) = 0;

  // Method returns the structure containing model information for given sub element id list
  virtual void GetGridElemModelInfo( list<int> iSubElementIdList, CATVis3DGridElemModelInfo  &oGridElemModelInfo ) = 0;

  // Method returns the structure containing model information for given invariant sub element id
  virtual void GetGridElemModelInfo( const CATVis3DGridElemId &iInvariantSubElementId, CATVis3DGridElemModelInfo  &oGridElemModelnfo ) = 0;

  // Set/Get Intersection Point Symbol - Choose any symbol as Intersection Point from CATSymbolType
  // For optimal performance, use non-bitmap symbols.  eg. DOT
  virtual void SetIntsPtSymbol( const CATSymbolType &iSymbol ) = 0;
  virtual void GetIntsPtSymbol( CATSymbolType &oSymbol ) = 0;

  // Set/Get Methods to control ShadingView
  virtual void SetShadingViewFlag( const CATBoolean iIsShadingViewEnabled ) = 0;
  virtual void GetShadingViewFlag( CATBoolean &oIsShadingViewEnabled ) = 0;
  virtual void SetShadingViewGA( const CATGraphicAttributeSet &iGAForUpperFace, const CATGraphicAttributeSet &iGAForLowerFace ) = 0;
  virtual void GetShadingViewGA( CATGraphicAttributeSet &oGAForUpperFace, CATGraphicAttributeSet &oGAForLowerFace ) = 0;

  // Furtive Mode
  // This mode allows the end user to specify if he always wants the grid to be displayed, or
  // if he wants grid to be displayed only when it is parallel to the screen plane
  // TRUE for furthive mode on
  // Default : furtive mode is off
  virtual void SetGridDisplayFurtiveMode ( const CATBoolean iIsFurtiveModeOn) = 0;
  virtual void GetGridDisplayFurtiveMode ( CATBoolean &oIsFurtiveModeOn) = 0;

  // Edge Type
  // set Edge Type on or off.
  // Legal Values: 1(Edge type is on),  0(Edge type is off)
  virtual void SetEdgeType (const unsigned int iOnOff) = 0;
  // get type of the Edge(on or off)
  virtual unsigned int GetEdgeType () = 0;
  
  // Clipping planes option.
  virtual void SetClippingPlaneFlag( const CATBoolean iIsClippingPlaneEnabled ) = 0;
  virtual void GetClippingPlaneFlag( CATBoolean &oIsClippingPlaneEnabled ) = 0;
  virtual void SetFlagClippingPlaneArea( const CATBoolean iClippingPlaneAreaFlag ) = 0;
  virtual void GetFlagClippingPlaneArea( CATBoolean &oClippingPlaneAreaFlag ) = 0;
  virtual void SetFlagClippingPlaneEquation( const CATBoolean iClippingPlaneEqnFlag ) = 0;
  virtual void GetFlagClippingPlaneEquation( CATBoolean &oClippingPlaneEqnFlag ) = 0;
  // User defined clipping area; defined with planes.
  // Plane is defined by plane equation aX + bY + cZ + d = 0
  // 4 planes define the clipping bound
  // Default : Grid is clipped by viewing frustum
  virtual void SetClippingPlaneArea( const float a[4], const float b[4], const float c[4], const float d[4] ) = 0;
  virtual void GetClippingPlaneArea( float a[4], float b[4], float c[4], float d[4]) = 0;

  // U and V Spacifies grid range
  //
  //           _|______________|_End
  //            |              |
  //            |              |
  //            |              |
  //           _|______________|_
  //      Start |              |

  // User defined clipping area; parametric boundary on grid plane
  // Default : Grid is clipped by viewing frustum
  virtual void SetClippingPlaneArea( const CATMathPoint2Df &iStart, const CATMathPoint2Df &iEnd ) = 0;
  virtual void GetClippingPlaneArea( CATMathPoint2Df &oStart, CATMathPoint2Df &oEnd) = 0;

  // Set/Get method for Grid Curve Show
  // Default : ALWAYS for primary and Dynamic for secondary curves
  virtual void SetGridCurvesShow( CATVis3DGridCurvesShow iCurvesShow ) = 0;
  virtual void GetGridCurvesShow( CATVis3DGridCurvesShow &oCurvesShow ) = 0;

  // Set/Get method for Curve Display Mode.
  // Default : CurveDisplayMode_CURVE
  virtual void GetCurveDisplayMode( CATVis3DGridCurveDisplayMode &oDisplayMode) = 0; 
  virtual void SetCurveDisplayMode( const CATVis3DGridCurveDisplayMode &iDisplayMode) = 0;  

  // Set/Get method would be used to set/get the settings of grid labels for u curves and v curves.
  // Default: Labels are not active
  virtual void SetLabelSettings(const CATVis3DGridLabelSettings &iUSettings, const CATVis3DGridLabelSettings &iVSettings) = 0;
  virtual void GetLabelSettings(CATVis3DGridLabelSettings &oUSettings, CATVis3DGridLabelSettings &oVSettings) = 0;

  // Function to query whether the grid is Ortho or Radial
  // (according to the last parameter 'iIsOrtho' passed in the CreateGrid function)
  virtual CATBoolean IsOrthoGrid() = 0;
  
  // Start IIX - Jan 07 - Highlight: 3D Grid for GSD 
  // To set and get maximum number of primary lines and automatic scale ratio
  virtual void SetMaxPrimNbAndScaleRatio(int iMaxPrimNb, float iScaleRatio) = 0;
  virtual void GetMaxPrimNbAndScaleRatio(int &oMaxPrimNb, float &oScaleRatio) = 0;

  // Enables or Disables the display of arrows along U and V directions 
  // iMode - the show mode
  // Legal Values: 1 (shown), 0 (not shown)
  virtual void SetAxisSystemShowMode(int iMode) = 0;
  virtual void GetAxisSystemShowMode(int &oMode) = 0;
  
  // set or get the graphic attributes for arrows 
  virtual void SetAxisSystemGA(const CATGraphicAttributeSet &iAxisSysGA) = 0;
  virtual void GetAxisSystemGA(CATGraphicAttributeSet &oAxisSysGA) = 0;
  // End IIX - Jan 07 - Highlight: 3D Grid for GSD 

  // Start IIX - Mar 07 - 3D Grid Requirement for GSD 
  // set or get the Axis system attributes
  //  iLengthIn_mm     - The total arrow length expressed in millimetres, 17 is used by default 
  //  iArrowHeadHeight - The height of the arrow head, default is 3
  //  iShowAxisLabels  - whether to display 'H' and 'V' labels along U and V arrows 
  //                     Legal Values: 1 (shown), 0 (not shown)
  virtual void SetOtherAxisAtributes(const int iLengthIn_mm, const int iArrowHeadHeight = 3,
						 const int iShowAxisLabels = 0 ) = 0;
  virtual void GetOtherAxisAtributes(int &oLengthIn_mm, int &oArrowHeadHeight, int &oShowAxisLabels ) = 0;
  
  // End IIX - Mar 07 -  3D Grid Requirement for GSD 

  // Set and Get methods for Label Height variations 
  virtual void SetLabelHeight(float iLabelFontHeight)=0; 
  virtual void GetLabelHeight(float &oLabelFontHeight)=0; 

  // Allow/disallow changing label font height
  virtual void SetAllowLabelHeightChangeFlag( const CATBoolean iAllowHeightChange)=0;
  virtual void GetAllowLabelHeightChangeFlag( CATBoolean & oIsHeightChangeAllowed)=0;

protected:
  CATVis3DGridRep( const CATVis3DGridRep & );
  CATVis3DGridRep & operator = ( const CATVis3DGridRep & );
};

#endif

