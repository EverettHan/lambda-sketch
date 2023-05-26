#ifndef CATRibbonHomotopy_H
#define CATRibbonHomotopy_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "Fillet.h"
#include "CATMathPoint.h"
#include "CATPGMRibbonHomotopy.h"

class CATBody;
class CATCurve;
class CATEdge;
class CATGeoFactory;
class CATConnectTool;
class CATConnectStartHomotopy;
class CATTopData;
class CATMathPoint;
class CATFace;
class CATIPGMConnectTool;

//--------------------------------------------------------------------------
// class CATRibbonHomotopy
// -------------------------------------------------------------------------

class ExportedByFillet CATRibbonHomotopy: public CATPGMRibbonHomotopy
{
public :
  
  //--------------------------------------------------------------------------
  // Constructor
  // With an Edge of a Body and a point on this edge,
  // returns the previsu of a fillet or a chamfer. 
  //
  // iRefFace est une face de reference pour la previsu du chamfrein.
  //--------------------------------------------------------------------------
  
  CATRibbonHomotopy(
    CATGeoFactory *iFactory,
    CATTopData *iTopData,
    CATBody *iBody,
    CATEdge *iEdge,
    const CATMathPoint &iPoint,
    const CATConnectTool * iProfilePtr,
    CATFace *iRefFace = NULL );
  
  CATRibbonHomotopy(
    CATGeoFactory *iFactory,
    CATTopData *iTopData,
    CATBody *iBody,
    CATEdge *iEdge,
    const CATMathPoint &iPoint,
    CATIPGMConnectTool * iProfilePtr,
    CATFace *iRefFace = NULL );

  //--------------------------------------------------------------------------
  // Destructor
  //--------------------------------------------------------------------------		
  
  ~CATRibbonHomotopy ();
  
  //--------------------------------------------------------------------------
  // Method GetCurve
  // returns a circle (fillet) or a line (chamfer)
  //--------------------------------------------------------------------------
  
  CATCurve * GetCurve();
  
  //--------------------------------------------------------------------------
  // Method SetHoldCurve
  // Method to set a hold curve for hold curve chamfer type. Hold edge and 
  // chamfer edge need to share the ref face given in constructor. Method
  // needs to be called before the Run Method
  //--------------------------------------------------------------------------
 
  void SetHoldCurve( CATEdge *iHoldEdge );

  //--------------------------------------------------------------------------
  // Method Run
  //--------------------------------------------------------------------------
  
  void Run();
  
  //--------------------------------------------------------------------------
  // Method GetDiagnostic
  // Returns 
  // 0 if there is no solution
  // 1 if there is an exact solution
  // 2 if the solution is obtained with the tangent planes
  //--------------------------------------------------------------------------
  
  CATLONG32 GetDiagnostic();
  

  //-------------------------------------------------------------------------- 
  // Old constructor : Do not use
  //--------------------------------------------------------------------------
  CATRibbonHomotopy(
    CATBody * iBody,
    CATEdge * iEdge,
    const CATMathPoint &iPoint,
    CATGeoFactory *iFactory,
    const CATConnectTool * iProfilePtr,
    CATFace * iRefFace = NULL);

  CATRibbonHomotopy(
    CATBody * iBody,
    CATEdge * iEdge,
    const CATMathPoint &iPoint,
    CATGeoFactory *iFactory,
    CATIPGMConnectTool * iProfilePtr,
    CATFace * iRefFace = NULL);

protected :
  CATBody * _iBody;
  CATEdge * _iEdge;
  CATMathPoint  _iPoint;
  CATFace * _iRefFace;
  CATConnectStartHomotopy * _CoSt;
  CATGeoFactory * _iFactory;
  CATBoolean      _IsValid;

private:
  void Init(
    CATGeoFactory *iFactory,
    const CATConnectTool * iProfilePtr,
    CATIPGMConnectTool * iIProfilePtr,
    CATFace * iRefFace);

  void Init(
    CATGeoFactory *iFactory,
    CATTopData *iTopData,
    CATBody *iBody,
    CATEdge *iEdge,
    const CATMathPoint &iPoint,
    const CATConnectTool * iProfilePtr,
    CATIPGMConnectTool * iIProfilePtr,
    CATFace *iRefFace);

};

#endif



