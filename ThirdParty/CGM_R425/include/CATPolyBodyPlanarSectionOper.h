// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyPlanarSectionOper.h
//
//===================================================================
// April 2009  Creation: NDO
//===================================================================
#ifndef CATPolyBodyPlanarSectionOper_H
#define CATPolyBodyPlanarSectionOper_H

#include "PolyBodyBVHOperators.h"
#include "CATErrorDef.h"
#include "CATMapOfPtrToPtr.h"
#include "CATMathVector.h"

class CATPolyExactArithmetic;
class CATPolyBody;
class CATIPolySurfaceIterator;
class CATIPolyCurveIterator;
class CATIPolyMesh;
class CATIPolyCurve;
class CATPolyFaceIterator;
class CATMapOfPtrToPtr;
class CATPolySpatialPartition2D;

class CATMathTransformation;
class CATMathPlane;

class CATPolyPolygon2D;
class CATPolyPolygonVertex3DPositionLayer;
class CATPolyPolygonBarSurfaceLayer;
class CATPolyBooleanOper2D;
class CATPolyBodyPlanarSectionOperObserver;
class CATSoftwareConfiguration;
class CATechExt;


/**
 * This operator calculates a planar section of a CATPolyBody and returns the result in the form of a polygon 2D
 * with attribute layers (coordinates of points 3D and layer of bar support.)
 */
class ExportedByPolyBodyBVHOperators CATPolyBodyPlanarSectionOper
{

public:

  CATPolyBodyPlanarSectionOper (const CATPolyExactArithmetic& iExactArithmetic,
                                const CATPolyBody& iPolyBody,
                                const CATMathTransformation* iBodyPosition = 0,
                                const CATSoftwareConfiguration* iSoftConfig = 0);

  CATPolyBodyPlanarSectionOper (const CATPolyExactArithmetic& iExactArithmetic,
                                const CATPolyBody& iPolyBody,
                                bool iBodyIsVolume,  // Redundant with CATPolyBody's attribute.
                                const CATMathTransformation* iBodyPosition = 0,
                                const CATSoftwareConfiguration* iSoftConfig = 0);

  ~CATPolyBodyPlanarSectionOper ();

public:

  /**
   * Set the half thickness of the plane used for sectioning.  
   * All points within this distance to the plane will be considered on the plane.
   * This parameter can be set before any call to the Run method.
   * By default, the plane does not have a thickness (thickness = 0).
   */
  inline void SetHalfThickness (const double iHalfThickness);

public:

  /**
   * Performs a planar section of the CATPolyBody instance by the plane.
   * The result is a polygon (CATPolyPolygon2D) with a geometry layer of 3D coordinates associated to the 
   * vertices.  The caller is responsible of the life cycle of the returned polygon and position layer.
   * (Delete must be called on these objects.)
   * @param  iPlane
   *   The section plane.
   * @param oPolygon
   *   The result of the section: a CATPolyPolygon2D object.
   * @param oPolygonVertexPositionLayer
   *   The layer of vertex position associated to the result polygon.
   * @param partition
   *   Possible spatial partition to speed-up the computation. Its bounding box
   *   should wrap the entire result polygon geometry.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> if the planar section is successful and there is an intersection between the plane and the object.
   *   <li> <tt>S_FALSE</tt> if the planar section is successful and there is no intersection between the plane and the object.
   *   <li> <tt>E_FAIL</tt> (or other error code) if there is an error.  In the method returns a polygon and a layer, then
   *     there is an intersection between the plane and the object but the computation of the result failed.
   *     (The result should still be a valid polygon but not a valid section.)
   * </ul>
   */
  HRESULT Run (const CATMathPlane& iPlane, 
               CATPolyPolygon2D*& oPolygon, 
               CATPolyPolygonVertex3DPositionLayer*& oPolygonVertexPositionLayer,
               CATPolyPolygonBarSurfaceLayer*& oPolygonBarSurfaceLayer,
               CATPolySpatialPartition2D * partition = 0);

  /**
   * Performs a planar section of the CATPolyBody instance by the plane iterating through a set of CATIPolySurface.
   * The result is a polygon (CATPolyPolygon2D) with a geometry layer of 3D coordinates associated to the 
   * vertices.  The caller is responsible of the life cycle of the returned polygon and position layer.
   * (Delete must be called on these objects.)
   * @param  iPlane
   *   The section plane.
   * @param iSurfaceIterator
   *   The iterator of CATIPolySurface to be processed by the section operator.
   * @param oPolygon
   *   The result of the section: a CATPolyPolygon2D object.
   * @param oPolygonVertexPositionLayer
   *   The layer of vertex position associated to the result polygon.
   * @param partition
   *   Possible spatial partition to speed-up the computation. Its bounding box
   *   should wrap the entire result polygon geometry.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> if the planar section is successful and there is an intersection between the plane and the object.
   *   <li> <tt>S_FALSE</tt> if the planar section is successful and there is no intersection between the plane and the object.
   *   <li> <tt>E_FAIL</tt> (or other error code) if there is an error.  In the method returns a polygon and a layer, then
   *     there is an intersection between the plane and the object but the computation of the result failed.
   *     (The result should still be a valid polygon but not a valid section.)
   * </ul>
   */
  HRESULT Run (const CATMathPlane& iPlane, CATIPolySurfaceIterator& iSurfaceIterator,
    CATPolyPolygon2D*& oPolygon,
    CATPolyPolygonVertex3DPositionLayer*& oPolygonVertexPositionLayer,
    CATPolyPolygonBarSurfaceLayer*& oPolygonBarSurfaceLayer,
    CATPolySpatialPartition2D* partition = 0);

  /**
   * Performs a planar section of the CATPolyBody instance by the plane iterating only through a subset of its CATIPolyCurve.
   * The result is a polygon (CATPolyPolygon2D) with a geometry layer of 3D coordinates associated to the 
   * vertices.  The caller is responsible of the life cycle of the returned polygon and position layer.
   * (Delete must be called on these objects.)
   * @param  iPlane
   *   The section plane.
   * @param iCurveIterator
   *   The iterator of CATIPolyCurve that are processed by the section operator.
   * @param oPolygon
   *   The result of the section: a CATPolyPolygon2D object.
   * @param oPolygonVertexPositionLayer
   *   The layer of vertex position associated to the result polygon.
   * @param partition
   *   Possible spatial partition to speed-up the computation. Its bounding box
   *   should wrap the entire result polygon geometry.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> if the planar section is successful and there is an intersection between the plane and the object.
   *   <li> <tt>S_FALSE</tt> if the planar section is successful and there is no intersection between the plane and the object.
   *   <li> <tt>E_FAIL</tt> (or other error code) if there is an error.  In the method returns a polygon and a layer, then
   *     there is an intersection between the plane and the object but the computation of the result failed.
   *     (The result should still be a valid polygon but not a valid section.)
   * </ul>
   */
  HRESULT Run (const CATMathPlane& iPlane, CATIPolyCurveIterator& iCurveIterator,
               CATPolyPolygon2D*& oPolygon, 
               CATPolyPolygonVertex3DPositionLayer*& oPolygonVertexPositionLayer,
               CATPolySpatialPartition2D * partition = 0);

public:

   /** Sets an observer that needs to listen to operator events
   *  If a previous observer is already set, then it will be replaced with the lastest obersver
   *@param iObserver: The observer that is to be set.
   */
  void SetObserver(CATPolyBodyPlanarSectionOperObserver * iObserver);

  /** Gets the current observer
   *@return current observer
   */
  CATPolyBodyPlanarSectionOperObserver * GetObserver() const;

private:

  const CATPolyExactArithmetic& _ExactArithmetic;
  const CATSoftwareConfiguration *_SoftConfig;  // Software configuration (no AddRef/Release on this instance.)

  const CATPolyBody& _PolyBody;
  bool _BodyIsVolume;
  const CATMathTransformation* _BodyPosition;
  int _SignOfDeterminant;

private:

  CATMathVector _PlaneNormal;
  CATMapOfPtrToPtr _MapMeshToIntersector;

  double _HalfThickness;       // Half-thickness of the plane.

  bool _CheckBoundingBox;

  CATPolyBodyPlanarSectionOperObserver * _Observer;
  CATechExt * _PhoenixExtension;

private:

  void DeleteIntersectors ();

  HRESULT ComputeSection (CATIPolySurfaceIterator& iSurfaceIterator,
                          const CATMathPlane& iPlane, 
                          CATPolyBooleanOper2D& iBooleanOper,
                          CATPolyPolygonVertex3DPositionLayer& iVertexPositionLayer,
                          CATPolyPolygonBarSurfaceLayer& iBarSurfaceLayer);

  HRESULT ComputeSection (const CATIPolyMesh& iMesh,
                          const CATMathPlane& iPlane, 
                          CATPolyBooleanOper2D& iBooleanOper,
                          CATPolyPolygonVertex3DPositionLayer& iVertexPositionLayer,
                          CATPolyPolygonBarSurfaceLayer& iBarSurfaceLayer,
                          unsigned int iFaceID);

  HRESULT ComputeSection (CATIPolyCurveIterator& iCurveIterator,
                         const CATMathPlane& iPlane, 
                         CATPolyPolygon2D& iPolygon,
                         CATPolyPolygonVertex3DPositionLayer& iVertexPositionLayer);

  HRESULT ComputeSection (const CATIPolyCurve& iCurve,
                          const CATMathPlane& iPlane, 
                          CATPolyPolygon2D& iPolygon,
                          CATPolyPolygonVertex3DPositionLayer& iVertexPositionLayer);

};

#endif


inline void CATPolyBodyPlanarSectionOper::SetHalfThickness (const double iHalfThickness)
{
  _HalfThickness = iHalfThickness;
}
