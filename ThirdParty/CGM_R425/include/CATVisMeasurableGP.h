// COPYRIGHT Dassault Systemes 2001
//===================================================================
//
// CATVisMeasurableGP.h
//   Class for measurement on Graphic Primitives.
//
//===================================================================
//
// May 2001  Creation: LJE
//
//===================================================================
/**
* @CAA2Level L1
* @CAA2Usage U1
*/

#ifndef CATVisMeasurableGP_H
#define CATVisMeasurableGP_H

#include "CATBaseUnknown.h"
#include "SGInfra.h"

class CATMathPoint;
class CATMathVector;
class CATMathPlane;
class CATGraphicPrimitive;


/**
 * The geometric type of the Graphic Primitive.
 * @param Unknown
 *    Unknown type
 * @param Plane
 *    A Plane
 * @param Cylinder
 *    A Cylinder
 * @param Cone
 *    A Cone
 * @param Sphere
 *    A Sphere
 * @param Line
 *    A Line
 * @param Circle
 *    A Circle
 * @param Torus
 *    A Torus
 * @see CATGraphicPrimitive
 */
enum CATVisMeasurableType {
  Unknown,
  Plane,
  Cylinder,
  Cone,
  Sphere,
  Line,
  Circle,
  Torus,
};

//-----------------------------------------------------------------------

/**
 * Class for measurement on Graphic Primitives.
 */
class ExportedBySGInfra CATVisMeasurableGP
{
  public:
  
    /**
     * Constructor.
     * @param ipGP
     *   The graphic primitive to use for setting / getting measurement properties.
     */
    CATVisMeasurableGP(CATGraphicPrimitive *& ipGP);
  
    /** @nodoc */
    virtual ~CATVisMeasurableGP();
    
    /**
     * Retrieves the type of the Graphic Primitive.
     * @param oType
     *   The @href CATVisMeasurableType of the GraphicPrimitive.
     * @return
     *   S_OK if everything went fine, E_FAIL otherwise
     */
    HRESULT GetType(CATVisMeasurableType & oType);
    
    /**
     * Defines the GP as an unknown geometry.
     * @return
     *   S_OK if everything went fine, E_FAIL otherwise
     */
    HRESULT SetUnknown();
    
    /**
     * Retrieves the plane definition if the GP is a plane.
     * @param ioPlane
     *   The plane.
     * @return
     *   S_OK if everything went fine, E_FAIL otherwise
     */
    HRESULT GetPlane(CATMathPlane & ioPlane);
    
    /**
     * Defines the GP as a plane and sets the plane definition.
     * @param iPlane
     *   The plane.
     * @return
     *   S_OK if everything went fine, E_FAIL otherwise
     */
    HRESULT SetPlane(CATMathPlane & iPlane);

    /**
     * Retrieves the cylinder definition if the GP is a cylinder.
     * @param ioPoint
     *   The point.
     * @param ioAxis
     *   The axis.
     * @param oRadius
     *   The radius.
     * @return
     *   S_OK if everything went fine, E_FAIL otherwise
     */
    HRESULT GetCylinder(CATMathPoint & ioPoint, CATMathVector & ioAxis, double & oRadius);

    /**
     * Defines the GP as a cylinder and sets the cylinder definition.
     * @param iPoint
     *   The point.
     * @param iAxis
     *   The axis.
     * @param iRadius
     *   The radius.
     * @return
     *   S_OK if everything went fine, E_FAIL otherwise
     */
    HRESULT SetCylinder(CATMathPoint & iPoint, CATMathVector & iAxis, double & iRadius);
    
    /**
     * Retrieves the cone definition if the GP is a cone.
     * @param ioApex
     *   The apex point.
     * @param ioAxis
     *   The axis.
     * @param oSemiAngle
     *   The semi-angle.
     * @return
     *   S_OK if everything went fine, E_FAIL otherwise
     */
    HRESULT GetCone(CATMathPoint & ioApex, CATMathVector & ioAxis, double & oSemiAngle);
    
    /**
     * Defines the GP as a cone and sets the cone definition.
     * @param iApex
     *   The apex point.
     * @param iAxis
     *   The axis.
     * @param iSemiAngle
     *   The semi-angle.
     * @return
     *   S_OK if everything went fine, E_FAIL otherwise
     */
    HRESULT SetCone(CATMathPoint & iApex, CATMathVector & iAxis, double & iSemiAngle);
    
    /**
     * Retrieves the sphere definition if the GP is a sphere.
     * @param ioCenter
     *   The center point.
     * @param oRadius
     *   The radius.
     * @return
     *   S_OK if everything went fine, E_FAIL otherwise
     */
    HRESULT GetSphere(CATMathPoint & ioCenter, double & oRadius);
    
    /**
     * Defines the GP as a sphere and sets the sphere definition.
     * @param iCenter
     *   The center point.
     * @param iRadius
     *   The radius.
     * @return
     *   S_OK if everything went fine, E_FAIL otherwise
     */
    HRESULT SetSphere(CATMathPoint & iCenter, double & iRadius);

	/**
     * Retrieves the torus definition if the GP is a torus.
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
    HRESULT GetTorus(CATMathPoint & ioPoint, CATMathVector & ioAxis, double & oMajorRadius, double & oMinorRadius);

    /**
     * Defines the GP as a torus and sets the torus definition.
     * @param iPoint
     *   The point.
     * @param iAxis
     *   The axis.
     * @param iMajorRadius
     *   The major radius.
	 * @param iMinorRadius
     *   The minor radius.
     * @return
     *   S_OK if everything went fine, E_FAIL otherwise
     */
    HRESULT SetTorus(CATMathPoint & iPoint, CATMathVector & iAxis, double & iMajorRadius, double & iMinorRadius);
    
    /**
     * Retrieves the line definition if the GP is a line.
     * @param ioSttPoint
     *   The start point.
     * @param ioEndPoint
     *   The end point.
     * @return
     *   S_OK if everything went fine, E_FAIL otherwise
     */
    HRESULT GetLine(CATMathPoint & ioSttPoint, CATMathPoint & ioEndPoint);
    
    /**
     * Defines the GP as a line and sets the line definition.
     * @param iSttPoint
     *   The start point.
     * @param iEndPoint
     *   The end point.
     * @return
     *   S_OK if everything went fine, E_FAIL otherwise
     */
    HRESULT SetLine(CATMathPoint & iSttPoint, CATMathPoint & iEndPoint);
    
    /**
     * Retrieves the circle definition if the GP is a circle.
     * @param ioCenter
     *   The center point.
     * @param ioAxis
     *   The axis.
     * @param oRadius
     *   The radius.
     * @return
     *   S_OK if everything went fine, E_FAIL otherwise
     */
    HRESULT GetCircle(CATMathPoint & ioCenter, CATMathVector & ioAxis, double & oRadius);
    
    /**
     * Defines the GP as a circle and sets the circle definition.
     * @param iCenter
     *   The center point.
     * @param iAxis
     *   The axis.
     * @param iRadius
     *   The radius.
     * @return
     *   S_OK if everything went fine, E_FAIL otherwise
     */
    HRESULT SetCircle(CATMathPoint & iCenter, CATMathVector & iAxis, double & iRadius);


  private:

    /** @nodoc */
    HRESULT ReadType(int iSize, char * icString, CATVisMeasurableType & oType);
    /** @nodoc */
    HRESULT WriteUnknown(int & oSize, char *& ocString);
    /** @nodoc */
    HRESULT ReadPlane(int iSize, char * icString, CATMathPlane & ioPlane);
    /** @nodoc */
    HRESULT WritePlane(CATMathPlane & iPlane, int & oSize, char *& ocString);
    /** @nodoc */
    HRESULT ReadCylinder(int iSize, char * icString, CATMathPoint & ioPoint, CATMathVector & ioAxis, double & oRadius);
    /** @nodoc */
    HRESULT WriteCylinder(CATMathPoint & iPoint, CATMathVector & iAxis, double & iRadius, int & oSize, char *& ocString);
    /** @nodoc */
    HRESULT ReadCone(int iSize, char * icString, CATMathPoint & ioApex, CATMathVector & ioAxis, double & oSemiAngle);
    /** @nodoc */
    HRESULT WriteCone(CATMathPoint & iApex, CATMathVector & iAxis, double & iSemiAngle, int & oSize, char *& ocString);
    /** @nodoc */
    HRESULT ReadSphere(int iSize, char * icString, CATMathPoint & ioCenter, double & oRadius);
    /** @nodoc */
    HRESULT WriteSphere(CATMathPoint & iCenter, double & iRadius, int & oSize, char *& ocString);
	/** @nodoc */
    HRESULT ReadTorus(int iSize, char * icString, CATMathPoint & ioPoint, CATMathVector & ioAxis, double & oMajorRadius, double & oMinorRadius);
    /** @nodoc */
    HRESULT WriteTorus(CATMathPoint & iPoint, CATMathVector & iAxis, double & iMajorRadius, double & iMinorRadius, int & oSize, char *& ocString);
    /** @nodoc */
    HRESULT ReadLine(int iSize, char * icString, CATMathPoint & ioSttPoint, CATMathPoint & ioEndPoint);
    /** @nodoc */
    HRESULT WriteLine(CATMathPoint & iSttPoint, CATMathPoint & iEndPoint, int & oSize, char *& ocString);
    /** @nodoc */
    HRESULT ReadCircle(int iSize, char * icString, CATMathPoint & ioCenter, CATMathVector & ioAxis, double & oRadius);
    /** @nodoc */
    HRESULT WriteCircle(CATMathPoint & iCenter, CATMathVector & iAxis, double & iRadius, int & oSize, char *& ocString);

    /** @nodoc */
    HRESULT ReadHeader(int iSize, char * icString, int & oVersion, int & oType);
    /** @nodoc */
    HRESULT WriteHeader(int iVersion, int iType, int iSize, char *& ocString);

    /** @nodoc */
    int SizeOfInteger();
    /** @nodoc */
    HRESULT ReadInteger(int iNbInteger, int iSize, char * icString, int oInteger[]);
    /** @nodoc */
    HRESULT WriteInteger(int iNbInteger, int iInteger[], int iSize, char *& ocString);
    /** @nodoc */
    int SizeOfDouble();
    /** @nodoc */
    HRESULT ReadDouble(int iNbDouble, int iSize, char * icString, double oDouble[]);
    /** @nodoc */
    HRESULT WriteDouble(int iNbDouble, double iDouble[], int iSize, char *& ocString);

    /** @nodoc */
    CATGraphicPrimitive * _pGP;          // Graphic Primitive

};

//-----------------------------------------------------------------------

#endif
