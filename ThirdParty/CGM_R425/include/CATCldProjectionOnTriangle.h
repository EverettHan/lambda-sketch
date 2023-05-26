//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2005
//==============================================================================================================
// File: CATCldProjectionOnTriangle.h
//==============================================================================================================
// Usage:
//==============================================================================================================
// 31-Jan-2022 - JLH - Portage Linux :
//                     Suppression des warnings et des erreurs de compilation en mode non-permissif.
// 04-Sep-2006 - DNR - Ajout méthode Project(point sur triangle suivant une direction)
// 18-May-2005 - JLH - Création
//==============================================================================================================

#ifndef CATCldProjectionOnTriangle_h
#define CATCldProjectionOnTriangle_h

#include "ExportedByCATCloudBasicResources.h"

#include "CATBooleanDef.h"

/**
 * Projection operator on a triangle.hod...
 */

class ExportedByCATCloudBasicResources CATCldProjectionOnTriangle
{
public:

  /** 
   * Constructor.
   * @param iCoordsA[3] [in]
   *   Coordinates of the first vertex of the triangle.
   * @param iCoordsB[3] [in]
   *   Coordinates of the second vertex of the triangle.
   * @param iCoordsC[3] [in]
   *   Coordinates of the third vertex of the triangle.
   */
  CATCldProjectionOnTriangle (const double iCoordsA[3],
                              const double iCoordsB[3],
                              const double iCoordsC[3]) ;

  virtual ~CATCldProjectionOnTriangle() ;

  /** 
   * Returns the square distance from the given point to the plane of the triangle.
   * @param iToProj[3] [in]
   *   Coordinates of the point.
   * @return
   *   Square distance
   */
  double SquareDistanceToPlane (const double  iToProj[3]) const ;

  /**
   * Projects a point on the triangle plane.
   * @param iToProj[3] [in]
   *   Coordinates of the point to be projected.
   * @param oProjec[3] [out]
   *   Coordinates of the projection.
   * @param oUVW[3] [out]
   *   Barycentric coordinates of the projection in regards on the triangles vertices.
   * @param oType [out]
   *   Type (dimension) of the projection: <br>
   *   <ul>
   *   <li>0: on a vertex.
   *   <li>1: on an edge.
   *   <li>2: in the triangle.
   *   </ul>
   * @param oNum [out]
   *   Relative index of the vertice (resp. the edge) if the projection is on a vertex (resp. an edge).<br>
   *   <ul>
   *   <li>0: if on vertex A or edge [AB]
   *   <li>1: if on vertex B or edge [BC]
   *   <li>2: if on vertex C or edge [CA]
   *   </ul>
   * @return
   *   <tt>TRUE</tt> if there is a projection, <tt>FALSE</tt> otherwise.
   */
  boolean Project (const double  iToProj[3],
                   double        oProjec[3],
                   double        oUVW[3],
                   int          &oType,
                   int          &oNum) const ;

  /**
   * Projects a point on the triangle plane.
   * @param iToProj[3] [in]
   *   Coordinates of the point to be projected.
   * @param iWDir[3] [in]
   *   Direction of the projection.
   * @param oProjec[3] [out]
   *   Coordinates of the projection.
   * @param oUVW[3] [out]
   *   Barycentric coordinates of the projection in regards on the triangles vertices.
   * @param oType [out]
   *   Type (dimension) of the projection: <br>
   *   <ul>
   *   <li>0: on a vertex.
   *   <li>1: on an edge.
   *   <li>2: in the triangle.
   *   </ul>
   * @param oNum [out]
   *   Relative index of the vertice (resp. the edge) if the projection is on a vertex (resp. an edge).<br>
   *   <ul>
   *   <li>0: if on vertex A or edge [AB]
   *   <li>1: if on vertex B or edge [BC]
   *   <li>2: if on vertex C or edge [CA]
   *   </ul>
   * @return
   *   <tt>TRUE</tt> if there is a projection, <tt>FALSE</tt> otherwise.
   */
  boolean Project (const double  iToProj[3],
                   const double  iUDir[3],
                   const double  iVDir[3],
                   const double  iWDir[3],
                   double        oProjec[3],
                   double        oUVW[3],
                   int          &oType,
                   int          &oNum) const ;

protected:

  CATCldProjectionOnTriangle() ;

  void _Initialize (const double iCoordsA[3],
                    const double iCoordsB[3],
                    const double iCoordsC[3]) ;

  double _A[3], _B[3], _C[3] ;
  double _AB[3], _AC[3], _N[3] ;
  double _ABAB, _ABAC, _ACAC, _BCBC ;
  double _Delta ; // Delta = 1./N.N
  unsigned int _AcuteInA :  1 ;
  unsigned int _AcuteInB :  1 ;
  unsigned int _AcuteInC :  1 ;

public:
  unsigned int _UserData : 29 ; // Data for the user !
} ;

#endif
