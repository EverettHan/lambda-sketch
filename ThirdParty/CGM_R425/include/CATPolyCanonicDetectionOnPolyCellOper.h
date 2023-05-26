// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCanonicDetectionOnPolyCellOper.h
//
//===================================================================
//
// Usage notes: Find canonics (planes, cylinders, cones, fillets)
// in a PolyBody
// this class allow computation of a PolyBody only for PolyBodyMonoCell(oneFace, one Edge)
// Is created for measure computation operator
//
//===================================================================
//
// Jan 2009 Miénandi N'ZOUTANI
//===================================================================

#ifndef CATPolyCanonicDetectionOnPolyCellOper_H
#define CATPolyCanonicDetectionOnPolyCellOper_H


#include "CATPolyCanonicOperators.h"

#include "CATMathPlane.h"
#include "CATMathPoint.h"
#include "CATMathAxis.h"


class CATPolyBody;
class CATPolyCell;
class CATIPolyCurve;
class CATIPolyCurveVertexIterator;
class CATPolyMathSurface;
class CATPolyMathCurve;


/**
 * Detection of a canonic from the cell of a CATPolyBody.
 */
class ExportedByCATPolyCanonicOperators CATPolyCanonicDetectionOnPolyCellOper
{

public:

  /**
  *  Constructor and Destructor
  */
  CATPolyCanonicDetectionOnPolyCellOper ();
  ~CATPolyCanonicDetectionOnPolyCellOper ();

public:

  /**
   * Fits a canonic to the cell of the CATPolyBody.
   * This methods checks the fitted entity against the geometry of the cell specifically it checks that:
   * <ul>
   *   <li> The distance of the discrete points to the fitted geometry is within the input fitting tolerance.
   *   <li> The sag between the cell and fitted geometries is less or inferior to the sag of the CATPolyBody.
   * </ul>
   * @param iPolyBody
   *   The input CATPolyBody.
   * @param iPolyCell
   *   The cell of the CATPolyBody to be fitted.
   * @param iFittingTolerance
   *   The tolerance between the discrete points from the geometry of the CATPolyBody (from the CATIPolySurface, CATIPolyCurve or CATIPolyPoint) and the fitted entity.
   *   The tolerance has length units.
   * @return
   *   <ul>
   *     <li> <tt>S_OK</tt> a canonic was successfully fitted to the cell of the CATPolyBody.
   *     <li> <tt>S_FALSE</tt> a canonic could not be fitted to the cell of the CATPolyBody within the specified tolerance.
   *     <li> <tt>E_FAIL</tt> an error occured during fitting.
   *   </ul>
   */
  HRESULT Run (const CATPolyBody& iPolyBody, const CATPolyCell& iPolyCell, const double iFittingTolerance);

public:

/** @name Deprecated Methods
    @{ */

  /**
   * Obsolete method.
   * See instead the other Run method.
   */
  HRESULT Run (CATPolyBody& iPolyBody);

  // Should not be calling the four methods below.
  // Caller should figure this out by itself.

  CATBoolean IsASurface (CATPolyBody& iPolyBody);
  CATBoolean IsACurve (CATPolyBody& iPolyBody);
  CATBoolean IsSetOfPoints (CATPolyBody& iPolyBody);
  CATBoolean IsAPoint (CATPolyBody& iPolyBody,CATMathPoint& oPoint );

/** @} */

public:

  HRESULT DetectLine(CATIPolyCurve * ipPolyCurve,CATIPolyCurveVertexIterator* VertexIter,const CATMathPoint& iOrigin,const CATMathVector& iDirection);
  HRESULT IsAPlane(CATMathPlane& oPlane);
  HRESULT IsACylinder(CATMathPoint& oCylinderCenter,CATMathVector& oCylinderAxis, double &oCylinderRadius);
  HRESULT IsASphere(CATMathPoint& oSphereCenter,double& oSphereRadius);
  HRESULT IsATore();
  HRESULT IsACone(CATMathPoint& oConeCenter, CATMathVector& oConeAxis, double&Angle);
  // IsACone method does not return Apex
  HRESULT IsAConeBis(CATMathPoint & oApex, CATMathVector & oAxis, double & oHalfAngle);
  HRESULT IsACircle(CATMathPoint& oCircleCenter,CATMathVector& oCircleAxis, double &oRadius,double &oAngle,double &oLength);
  HRESULT IsALine();
  //HRESULT DecodeSupport(CATIPolySurfaceSupport * iSurfaceSupport);
  HRESULT DecodeSupport(const CATPolyMathSurface * iSurfaceSupport);
  HRESULT DecodeSupport(CATIPolyCurve& iCurve, const CATPolyMathCurve& iMathCurve);

  CATBoolean IsDecorationRead();

private:

  HRESULT IsPolyBodyMonoCell(CATPolyBody& iPolyBody,unsigned int &oNbFaces,unsigned int& oNbEdges,unsigned int& oNbVertices);

  double _SinTolAngulaire;
  double _CircleAngle;
  double _Angle;

  double _CircleRadius;
  double _SphereRadius;
  double _CylinderRadius;

  double _ToleranceSag;

  CATMathPoint _CylinderCenter;
  CATMathPoint _CircleCenter;

  CATMathPoint _ConeCenter;
  CATMathPoint _ConeApex;
  CATMathVector _ConeAxis;

  CATMathPoint _SphereCenter;

  CATMathVector _CylinderAxis;
  CATMathVector _CircleAxis;

  CATMathPlane _Plane;

  unsigned int _NbEdges;
  unsigned int _NbFaces;
  unsigned int _NbVertices;
  CATBoolean   _ReadCanonicDecoration;

  int _Type;


};

#endif
