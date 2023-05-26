#ifndef CATVizMeasurableIterator_H
#define CATVizMeasurableIterator_H

// Base class
#include "CATVizIterator.h"

#include "CATVizIterators.h"

/**
 * The geometric type of the underlying primitive.
 * @param CATVizUnknown
 *    Unknown type
 * @param CATVizPlane
 *    A Plane
 * @param CATVizCylinder
 *    A Cylinder
 * @param Cone
 *    A Cone
 * @param CATVizSphere
 *    A Sphere
 * @param CATVizLine
 *    A Line
 * @param CATVizCircle
 *    A Circle
 * @param CATVizTore
 *    A Tore
 */
enum CATVizMeasurableType
{
  CATVizUnknown,
  CATVizPlane,
  CATVizCylinder,
  CATVizCone,
  CATVizSphere,
  CATVizLine,
  CATVizCircle,
  CATVizTore
};

class CATMathPlane;
class CATMathPoint;
class CATMathVector;

class ExportedByCATVisFoundationIterators CATVizMeasurableIterator : public CATVizIterator
{
   CATVizDeclareClass;
   CATVizDeclareIterator(CATVizMeasurableIterator);

public:

  /**
   * Retrieves the type of the underlying primitive.
   * @param oType
   *   The @href CATVisMeasurableType of the GraphicPrimitive.
   * @return
   *   S_OK if everything went fine, E_FAIL otherwise
   */
   virtual HRESULT GetType(CATVizMeasurableType & oType) = 0;

  /**
   * Retrieves the plane definition if the underlying primitive is a plane.
   * @param ioPlane
   *   The plane.
   * @return
   *   S_OK if everything went fine, E_FAIL otherwise
   */
   virtual HRESULT GetPlane(CATMathPlane & ioPlane) = 0;
   
   /**
   * Retrieves the cylinder definition if the  underlying primitive is a cylinder.
   * @param ioPoint
   *   The point.
   * @param ioAxis
   *   The axis.
   * @param oRadius
   *   The radius.
   * @return
   *   S_OK if everything went fine, E_FAIL otherwise
   */
   virtual HRESULT GetCylinder(CATMathPoint & ioPoint, CATMathVector & ioAxis, double & oRadius) = 0;
   
   /**
   * Retrieves the cone definition if the underlying primitive is a cone.
   * @param ioApex
   *   The apex point.
   * @param ioAxis
   *   The axis.
   * @param oSemiAngle
   *   The semi-angle.
   * @return
   *   S_OK if everything went fine, E_FAIL otherwise
   */
   virtual HRESULT GetCone(CATMathPoint & ioApex, CATMathVector & ioAxis, double & oSemiAngle) = 0;
   
   /**
   * Retrieves the sphere definition if the underlying primitive is a sphere.
   * @param ioCenter
   *   The center point.
   * @param oRadius
   *   The radius.
   * @return
   *   S_OK if everything went fine, E_FAIL otherwise
   */
   virtual HRESULT GetSphere(CATMathPoint & ioCenter, double & oRadius) = 0;
   
   /**
   * Retrieves the line definition if the underlying primitive is a line.
   * @param ioSttPoint
   *   The start point.
   * @param ioEndPoint
   *   The end point.
   * @return
   *   S_OK if everything went fine, E_FAIL otherwise
   */
   virtual HRESULT GetLine(CATMathPoint & ioSttPoint, CATMathPoint & ioEndPoint) = 0;
   
   /**
   * Retrieves the circle definition if the underlying primitive is a circle.
   * @param ioCenter
   *   The center point.
   * @param ioAxis
   *   The axis.
   * @param oRadius
   *   The radius.
   * @return
   *   S_OK if everything went fine, E_FAIL otherwise
   */
   virtual HRESULT GetCircle(CATMathPoint & ioCenter, CATMathVector & ioAxis, double & oRadius) = 0;

   /**
     * Retrieves the torus definition if the underlying primitive is a torus.
     * @param ioPoint
     *   The point.
     * @param ioAxis
     *   The axis.
     * @param oMajorRadius
     *   The major radius.
	 * @param oMinorRadius
     *   The minor radius.
     * @return
     *   S_OK if everything went fine, E_FAIL otherwise
     */
   virtual HRESULT GetTore(CATMathPoint & ioPoint, CATMathVector & ioAxis, double & oMajorRadius, double & oMinorRadius) = 0;
};

#endif
