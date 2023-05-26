#ifndef CATBodyTessellator_h
#define CATBodyTessellator_h

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 


#include "CATDataType.h"
#include "TessAPI.h"
#include "CATMathConstant.h"
#include "CATCGMVirtual.h"

class CATBody;
class CATVertex;
class CATEdge;
class CATFace;
class CATMathPoint;
class CATMathSetOfPointsND;
class CATTessPointIter;
class CATTessStripeIter;
class CATTessFanIter;
class CATTessPolyIter;
class CATTessTrianIter;
class CATTessEdgeIter;

/**
 * Class defining a Tessellation operator on a body.
 * <br> This operator computes a discretized geometry on the skin of a body, as triangles and bars.
 * The extremities of the bars are called points. Three parameters tune the tessellation result:
 * <dl>
 * <dt> Sag </dt><dd> Defines the maximum distance between a bar and the object to tessellate
 * <dt> Step </dt><dd> Defines the maximum length of a bar. If not defined, the step is infinite 
 * (this parameter is unused)
 * <dt> Angle </dt><dd> Defines the maximum angle between the normals at each bar end. 
 * The minimum accepted value for Angle is PI/16.
 * </dl>
 * The Tessellation operator follows the scheme of all the CGM operators:
 * <ul>
 * <li> Create an operator instance,
 * <li> Run,
 * <li> Recover the results by the means of iterators,
 * <li> Delete the operator instance. The deletion of the operator leads to the deletion
 * of the iterators and the arrays of results.
 * </ul>
 */

class ExportedByTessAPI CATBodyTessellator: public CATCGMVirtual
{
  CATCGMVirtualDeclareClass(CATBodyTessellator);
public:
  /**
   * Constructs a CATBodyTessellator with an infinite step.
   * @param iBody
   * The body to tessellate.
   * @param iSag
   * The Sag value.
   * @param iAngle
   * The Angle value in radian. PI/16 < Angle < PI
   */
  CATBodyTessellator(CATBody * iBody,
                     double    iSag,
                     double    iAngle=CATPIBY4);

  ~CATBodyTessellator();

  /**
   * Defines a finite step for <tt>this</tt> CATBodyTessellator.
   * @param iStep
   * The Step value.
   */
  void SetStep(double iStep);

  /**
   * Runs <tt>this</tt> CATBodyTessellator.
   */
  void Run();

  /**
   * Retrieves the result associated with a topological vertex of the input body.
   * @param iVertex
   * The pointer to a vertex of the input body.
   * @param oMathPoint
   * The corresponding CATMathPoint.
   */
  void GetVertex(CATVertex * iVertex, CATMathPoint * oMathPoint);

  /**
   * Retrieves the results associated with a topological edge of the input body.
   * @param iEdge
   * The pointer to an edge of the input body.
   * @param oMathPoints
   * The pointer to the created CATMathSetOfPointsND. This set contains the points (as 3 Cartesian coordinates)
   * of the resulting tessellation.
   * @param oCrvParams
   * The pointer to the created CATMathSetOfPointsND. This set contains the points (as a CATCrvParam on the
   * underlying edge curve)
   * of the resulting tessellation.
   */
  void GetEdge  (CATEdge * iEdge,
                 CATMathSetOfPointsND ** oMathPoints,
                 CATMathSetOfPointsND ** oCrvParams);

  /**
   * Retrieves the results (in doubles) associated with a topological edge of the input body.
   * @param iEdge
   * The pointer to an edge of the input body.
   * @param oNumberOfPoints
   * The number of points of the resulting tessellation.
   * @param oPointData
   * The array of the resulting points. This array is allocated by the <tt>GetEdge</tt>
   * method. The j-th coordinate of the i-th point is
   * <tt>oPointData[3*(i-1)+j-1]</tt>. 
   */
  void GetEdge  (CATEdge * iEdge, CATLONG32 &oNumberOfPoints, double ** oPointData);

   /**
   * Retrieves the result (in floats) associated with a topological edge of the input body.
   * @param iEdge
   * The pointer to an edge of the input body.
   * @param oNumberOfPoints
   * The number of points of the resulting tessellation.
   * @param oPointData
   * The array of the resulting points. This array is allocated by the <tt>GetEdge</tt>
   * method. The j-th coordinate of the i-th point is
   * <tt>oPointData[3*(i-1)+j-1]</tt>.
   * of the resulting tessellation.
   */
  void GetEdge  (CATEdge * iEdge, CATLONG32 &oNumberOfPoints, float  ** oPointData);

  /**
   * Retrieves the tessellation point numbers on an edge relative to an adjacent face point.
   * @param iEdge
   * The pointer to an edge of the input body.
   * @param oEdgeIter
   * The pointer to the created CATTessEdgeIterator. 
   */
  void GetEdge(CATEdge               * iEdge,
               CATTessEdgeIter      ** oEdgeIter);

   /**
   * Retrieves the results associated with a topological face of the input body.
   * <br> All the output iterators are allocated by the <tt>GetFace</tt> method,
   * and are deleted when the operator is deleted. 
   * <br><b>Note</b>: The results do not necessarily contain all types of tessellation
   * objects for a single body. You can have no isolated triangles or no triangle strips
   * in a tessellated body. For a example, for a degenerated face with a small width, 
   * the result can be made up of two vertices. 
   * @param iFace
   * The pointer to a face of the input body.
   * @param oPlane
   * Retrieves <tt>1</tt> if the face is planar, <tt>0</tt> otherwise.
   * @param oPoints
   * The pointer to the created CATTessPointIter, to retrieve the computed points. 
   * @param oStrips
   * The pointer to the created CATTessStripeIter, to retrieve the computed triangle strips. 
   * @param oFans
   * The pointer to the created CATTessFanIter, to retrieve the computed triangle fans. 
   * @param oPolygons
   * The pointer to the created CATTessPolyIter, to retrieve the computed polygons. 
   * @param oTriangles
   * The pointer to the created CATTessTrianIter, to retrieve the isolated triangles. 
   * @param oSide
   * The face orientation.
   * <br><b>Legal values</b>: <tt>1</tt> if the face orientation is outwards, <tt>-1</tt> if it is inwards.
   */
  void GetFace(CATFace * iFace,
               CATBoolean         & oPlane,
               CATTessPointIter  ** oPoints,
               CATTessStripeIter ** oStrips,
               CATTessFanIter    ** oFans,
               CATTessPolyIter   ** oPolygons,
               CATTessTrianIter  ** oTriangles,
               short              * oSide = (short *) 0);

protected:  
  void * _Tessellator;
};

#endif
