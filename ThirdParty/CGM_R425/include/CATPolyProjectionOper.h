// COPYRIGHT DASSAULT SYSTEMES 2008
//===================================================================
//
// CATPolyProjectionOper.h
// Header definition of CATPolyProjectionOper.
// Projection of a point sur CATIPolyMesh.
//
//===================================================================
// Usage notes: This operator has been optimized in reverse context,
//              for very big meshes. This optimization is made by 
//              voxelization or pixelization of the triangles to limite
//              the number of triangles considered by the projection.
//              This optimization is also made by saving some  proper
//              caracteristics of triangles.
//              This initialization may take time, for very big meshes,
//              that's why it is not a good idea to create a new operator 
//              each time you need to project a point onto a mesh.
//===================================================================
// 18-dec-2018 - JLH - Suppression du paramètre iSortActiveTriangles de la syntaxe LoadTargets
//    Feb 2011 - DNR - Creation
//===================================================================

#ifndef CATPolyProjectionOper_H
#define CATPolyProjectionOper_H

//Pour l'export
#include "ExportedByPolyhedralOperatorsRvs.h"

#include "CATListOfInt.h"
#include "CATBooleanDef.h"

class CATLISTP(CATIPolySurface);
class CATMathPoint;
class CATMathVector;
class CATIPolyMesh;

class ExportedByPolyhedralOperatorsRvs CATPolyProjectionOper
{
  
  public:

    enum CATPolyProjectionType { 
      OnNothing,
      OnPoint,
      OnVertex,
      OnEdge,
      OnTriangle
    } ;

    enum CATPolyProjectionPosition {
      NoProjection,
      OnBoundary,
      OnTarget // OnSurface
    };

    enum CATPolyProjectionMode {
      Normal,             // Normal to the surface, set by default.
      AlongOneDirection,  // Along a direction computation made by pixelisation
      AlongDirections     // Along a direction computation made using voxelisation.
    } ;

    /**
     * Virtual destructor.
     */
    virtual ~CATPolyProjectionOper();


    /**
     * Constructor.
     */
    static CATPolyProjectionOper* NewOperator();

    /**
     * Virtual SetProjectionMode.
     * @param imode : 0 -> Normal projection
     *                1 -> Along a direction computation made by pixelisation
     *                     Used when the direction is fixed once. In this case
     *                     if you change the direction, the pixelization will be
     *                     recomputed.
     *                2 -> Along a direction computation made using voxelisation.
     *                     used when the direction may change along the life of the
     *                     projector. The optimization uses a voxelization computed once.
     */
    virtual void SetProjectionMode(int imode) = 0;

    /**
     * Virtual SetProjectionDirection.
     * @param iDirX , iDirY, iDirZ : The projection direction vector.
     */
    virtual void SetProjectionDirection(float iDirX, float iDirY, float iDirZ) = 0;
    virtual void SetProjectionDirection(double iDirX, double iDirY, double iDirZ) = 0;

    /**
     * Virtual LoadTargets.
     *
     * @param iObjects : List of CATIPolyMesh, targets for the projection.
     *                   In the case of one element of the liste 
     *                   is not a CATIPolyMesh, it will be ignored.
     *
     * @param iSortActiveTriangles : Not used with CATIPolyMesh.
     *
     * @return
     * Computation status
     * <ul>
     * <li><tt>TRUE</tt> : no error occured.
     * <li><tt>>FALSE</tt> : an error occured.
     * </ul>
     */
    virtual boolean LoadTargets (CATLISTP(CATIPolySurface) &iObjects) = 0;

    /**
     * Virtual Run.
     *
     * @param iPoint : The point to be projected onto the meshe(s).
     *
     * @return
     * Computation status : Boolean.
     * <ul>
     * <li><tt>TRUE</tt> : the projection has been computed.
     * <li><tt>>FALSE</tt> : an error occured.
     * </ul>
     */
    virtual boolean Run (const CATMathPoint &iPoint) = 0;
    virtual boolean Run (const float  iCoords[3]) = 0;
    virtual boolean Run (const double iCoords[3]) = 0;

    /**
     * Virtual GetResult.
     *
     * @param oPoint : The projected point computed.
     *
     * @return
     * CATPolyProjectionPosition
     * <ul>
     * <li><tt>NoProjection</tt> : No projection has been computed.
     * <li><tt>>OnBoundary</tt> : The projection is on the boundary of the mesh.
     * <li><tt>>OnTarget</tt> : The projection is on the mesh.
     * </ul>
     *
     */
    virtual CATPolyProjectionPosition GetResult (CATMathPoint &oPoint) = 0;
    virtual CATPolyProjectionPosition GetResult (float  oPoint[3]) = 0;
    virtual CATPolyProjectionPosition GetResult (double oPoint[3]) = 0;

    /**
     * Virtual GetNormal.
     *
     * @param oNormal : The normale vector to the mesh computed at the projected point.
     *
     */
    virtual boolean GetNormal (CATMathVector &oNormal) = 0;
    virtual boolean GetNormal (float  oNormal[3]) = 0;
    virtual boolean GetNormal (double oNormal[3]) = 0;

    /**
     * Virtual GetInfos.
     *
     * @param oNumLocal : Number of the vertex or the edge of the triangle concerned by the projection.
     *
     *                  If oType is OnVertex oNumLocal will be the number of the vertex of the triangle :
     *                           Vtx[2]         |            Vtx[2]         |            Vtx[2]         |
     *                            *             |             *             |             o             |
     *                           / \            |            / \            |            / \            |
     *                          /   \           |           /   \           |           /   \           |
     *                         /     \          |          /     \          |          /     \          |
     *                 Vtx[0] o-------* Vtx[1]  |  Vtx[0] *-------o Vtx[1]  |  Vtx[0] *-------* Vtx[1]  |
     *                                          |                           |                           |
     *                    oNumLocal will be 0   |    oNumLocal will be 1    |    oNumLocal will be 2    |
     *                ----------------------------------------------------------------------------------|
     *                   If oType is OnEdge oNumLocal will be the number of the vertex of the triangle :|
     *                                                                                                  |
     *                           Vtx[2]         |            Vtx[2]         |            Vtx[2]         |
     *                            *             |             *             |             *             |
     *                           / \            |            / \            |            / \            |
     *                          /   \           |           /   o           |           o   \           |
     *                         /     \          |          /     \          |          /     \          |
     *                 Vtx[0] *---o---* Vtx[1]  |  Vtx[0] *-------* Vtx[1]  |  Vtx[0] *-------* Vtx[1]  |
     *                                          |                           |                           |
     *                    oNumLocal will be 0   |    oNumLocal will be 1    |    oNumLocal will be 2    |
     *
     * @param oNumTriangle : Number of the triangle concerned by the projection.
     *
     * @param oSupport  : The mesh concerned by the projection (Necessary when several meshes are set in LoadTargets).
     *
     * @param oType     : Say the situation where the projection has been computed.
     *                    it can be :       OnNothing,
     *                                      OnVertex,
     *                                      OnEdge,
     *                                      OnTriangle
     *
     */
    virtual void GetInfos(int& NumLocal, int& NumGlobal, CATIPolyMesh*& Support,
                                         CATPolyProjectionOper::CATPolyProjectionType& Type) const = 0;

    /**
     * Virtual RemoveTriangle / AddTriangle : Modification of the Target.
     *         It allows to continue to use the same projector instance 
     *         even after modification of one of the targets. 
     *         Usefull to save computation time.
     *
     * @param iTarget : The modified mesh.
     *
     * @param iNoTriangle : The modified Triangle.
     *
     */
    virtual boolean RemoveTriangle(CATIPolyMesh* iTarget,int iNoTriangle) = 0;
    virtual boolean AddTriangle(CATIPolyMesh* iTarget,int iNoTriangle) = 0;


};

#endif
