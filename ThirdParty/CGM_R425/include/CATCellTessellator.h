#ifndef CATCellTessellator_h
#define CATCellTessellator_h

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "CATIACGMLevel.h"
#include "CATDataType.h"
#include "TessAPI.h"
#include "CATMathConstant.h"
#include "CATTessOutputMode.h"
#include "CATCGMVirtual.h"

class CATVertex;
class CATEdge;
class CATFace;
class CATCell;
class CATMathPoint;
class CATMathSetOfPointsND;
class CATTessPointIter;
class CATTessStripeIter;
class CATTessFanIter;
class CATTessPolyIter;
class CATTessTrianIter;
class CATBody;

/**
 * Class defining a Tessellation operator on a cell.
 * <br> This operator discretizes a face geometry as triangles and an edge geometry as bars.
 * The extremities of the bars are called points. Three parameters tune the tessellation result:
 * <dl>
 * <dt> Sag </dt><dd> Defines the maximum distance between a bar and the object to tessellate
 * <dt> Step </dt><dd> Defines the maximum length of a bar. If not defined, the step is infinite 
 * (this parameter is unused)
 * <dt> Angle </dt><dd> Defines the maximum angle between the normals at each bar end. 
 * </dl>
 * The Tessellation operator follows the scheme of all the CGM operators:
 * <ul>
 * <li> Create an operator instance,
 * <li> Add other cells to tessellate in the same operation,
 * <li> Run,
 * <li> Recover the results by the means of iterators,
 * <li> Delete the operator instance. The deletion of the operator leads to the deletion
 * of the iterators and the arrays of results.
 * </ul>
 */
class ExportedByTessAPI CATCellTessellator: public CATCGMVirtual
{
  CATCGMVirtualDeclareClass(CATCellTessellator);
public:

  /**
  * Constructs a CATCellTessellator with an infinite step.
  * @param iReferenceBody
  * A reference body containing all faces which will be submitted to the CATCellTessellator by AddFace method, if this body
  * is not provided (null pointer), triangles originating from different faces may be oriented in opposite directions.
  * This body will not be used to tessellate edges, it may be null in this case.
  * @param iSag
  * The Sag value.
  * @param iAngle
  * The Angle value in radian.
  */
  CATCellTessellator(CATBody * iReferenceBody,
                     double    iSag,
                     double    iAngle=CATPIBY4);

  /**
  * Constructs a CATCellTessellator with an infinite step.
  * @param iReferenceBody
  * A reference body containing all faces which will be submitted to the CATCellTessellator by AddFace method, if this body
  * is not provided (null pointer), triangles originating from different faces may be oriented in opposite directions.
  * This body will not be used to tessellate edges, it may be null in this case.
  * @param iCell
  * The edge or face to tessellate
  * @param iSag
  * The Sag value.
  * @param iAngle
  * The Angle value in radian.
  */
  CATCellTessellator(CATBody * iReferenceBody,
                     CATCell * iCell, 
                     double    iSag,                     
                     double    iAngle=CATPIBY4);

   /**
   * Constructs a CATCellTessellator with an infinite step.
   * @param iSag
   * The Sag value.
   * @param iAngle
   * The Angle value in radian.
   */
  CATCellTessellator(double iSag,
                     double iAngle=CATPIBY4);

   /**
   * Constructs a CATCellTessellator with an infinite step.
   * @param iCell
   * The edge or face to tessellate
   * @param iSag
   * The Sag value.
   * @param iAngle
   * The Angle value in radian.
   */
  CATCellTessellator(CATCell * iCell,
                     double    iSag,
                     double    iAngle=CATPIBY4);


  ~CATCellTessellator();

 /**
   * Defines a finite step for <tt>this</tt> CATCellTessellator.
   * @param iStep
   * The Step value.
   */
  void SetStep(double iStep);

#ifdef CATIACGMV5R20
   /**
   * Defines Output mode for triangulation. Defaults to mixed output.
   * 
   */
  void SetOutputMode( CATTessOutputMode iMode = CATTessOutputMixed );
#endif

   /**
   * Adds another face to <tt>this</tt> CATCellTessellator.
   * @param iFace
   * The pointer to another face to tessellate in the same operation.
   */
  void AddFace(CATFace* iFace);

   /**
   * Adds another edge to <tt>this</tt> CATCellTessellator.
   * @param iEdge
   * The pointer to another edge to tessellate in the same operation.
   */
  void AddEdge(CATEdge* iEdge);
  
  /**
   * Runs <tt>this</tt> CATCellTessellator.
   */
  void Run();

   /**
   * Retrieves the result associated with a topological vertex of the input cells.
   * @param iVertex
   * The pointer to a vertex of the input cells.
   * @param oMathPoint
   * The corresponding CATMathPoint.
   */
  void GetVertex(CATVertex * iVertex, CATMathPoint * oMathPoint);

   /**
   * Retrieves the results associated with a topological edge of the input cells.
   * @param iEdge
   * The pointer to an edge among the input cells.
   * @param oMathPoints
   * The pointer to the created CATMathSetOfPointsND pointer. This set contains the points (as 3 Cartesian coordinates)
   * of the resulting tessellation.
   * @param oCrvParams
   * The pointer to the created CATMathSetOfPointsND pointer. This set contains the points (as a CATCrvParam on the
   * underlying edge curve)
   * of the resulting tessellation.
   */
  void GetEdge  (CATEdge * iEdge,
                 CATMathSetOfPointsND ** oMathPoints,
                 CATMathSetOfPointsND ** oCrvParams);

      /**
   * Retrieves the results (in doubles) associated with a topological edge of the input cells.
   * @param iEdge
   * The pointer to an edge among the input cells.
   * @param oNumberOfPoints
   * The number of points of the resulting tessellation.
   * @param oPointData
   * The array of the resulting points. This array is allocated by the <tt>GetEdge</tt>
   * method. The j-th coordinate of the i-th point is
   * <tt>oPointData[3*(i-1)+j-1]</tt>. 
   */
  void GetEdge  (CATEdge * iEdge, CATLONG32 &oNumberOfPoints, double ** oPointData);

    /**
   * Retrieves the result (in floats) associated with a topological edge of the input cells.
   * @param iEdge
   * The pointer to an edge among the input cells.
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
   * Retrieves the results associated with a topological face of the input cells.
   * <br> All the output iterators are allocated by the <tt>GetFace</tt> method,
   * and are deleted when the operator is deleted.
   * @param iFace
   * The pointer to a face among the input cells.
   * @param oPlane
   * Retrieves <tt>1</tt> if the face is planar, <tt>0</tt> otherwise.
   * @param oPoints
   * The pointer to the created pointer to a CATTessPointIterator, to retrieve the computed points. 
   * @param oStrips
   * The pointer to the created pointer to a CATTessStripIterator, to retrieve the computed triangle strips. 
   * @param oStrips
   * The pointer to the created pointer to a CATTessFanIterator, to retrieve the computed triangle fans. 
   * @param oStrips
   * The pointer to the created pointer to a CATTessPolygonIterator, to retrieve the computed polygons. 
   * The pointer to the created CATTessPolygonIterator, to retrieve the computed polygons. 
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
