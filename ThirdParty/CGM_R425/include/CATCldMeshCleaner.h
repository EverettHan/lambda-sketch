//=====================================================================================================================
// COPYRIGHT Dassault Systemes 2011
//=====================================================================================================================
// CATCldMeshCleaner.h
//=====================================================================================================================
// 09-Dec-2021 - JLH - Ajout du concept de vertex géométriquement non-manifold.
// 24-Jan-2019 - JLH - Ajout de FixNonOrientableTriangles.
//    Apr-2011 : DNR : Creation à partir de CATCldMeshCleanerOpr de JLH.
//=====================================================================================================================

#ifndef CATCldMeshCleaner_H
#define CATCldMeshCleaner_H

#include "ExportedByCATCldMeshCleaner.h"
#include "CATCGMBucketsDcl.h"
#include "CATCGMBucketsDef.h"

#include "math.h"
#include <set>

class ExportedByCATCldMeshCleaner CATCldMeshCleaner
{
  public:
  CATCGMBucketsDeclare (Int, int) ;

  public:
    class T_Mesh {
    public:
        virtual unsigned char IsOrientable () const = 0 ;
        /*
        * GetNbPoints : Get the number of points of the mesh.
        */
        virtual int GetNbPoints () const = 0 ;
        /*
        * GetNbPoints : Get the number of points of the mesh.
        */
        virtual void AddPoint (const double iCoords[3], int& oNumPoint) = 0 ;
        /*
        * IsActive : Check if the iNoPoint 'th' point is active.
        */
        virtual  unsigned char IsActive (const int iNoPoint) const = 0;
        /*
        * GetFreeVertices : Get the vertices on a boundary of the mesh.
        */
        virtual  unsigned char  GetFreeVertices (int& NbVertices, int*& oVertices, const unsigned char iOnlyActive = 1) const = 0;
        /*
        * GetUnreferencedVertices : Get the vertices which are not referenced in a triangle of the mesh.
        */
        virtual  unsigned char  GetUnreferencedVertices (int& NbVertices, int*& oVertices, const unsigned char iOnlyActive = 1) const = 0;
        /*
        * GetCoords : Get the coordinates of iNoPoint 'th' point of the mesh.
        */
        virtual void GetCoords (const int iNoPoint, double    oCoords[3]) const = 0;
        /*
        * GetNonManifoldEdges : Get the Non Manifold Edges of the mesh.
        */
        virtual  unsigned char  GetNonManifoldEdges (int& NbEdg, int*& oEdges, const unsigned char iOnlyActive = 1) const = 0;
        /*
        * GetFreeEdges : Get the free edges of the mesh.
        */
        virtual unsigned char GetFreeEdges (int& NbEdg, int*& oEdges, const unsigned char iOnlyActive = 1) const = 0;
        /*
        * GetNbTriangles : Get the number of triangles of the mesh.
        */
        virtual int GetNbTriangles () const = 0 ;
        /*
        * IsTriangleToBeTreated : Check if the iNoTriangle 'th' IsTriangleToBeTreated.
        */
        virtual unsigned char IsTriangleActive (const int iNoTriangle) const = 0;
        virtual unsigned char IsTriangleValid (const int iNoTriangle) const = 0;
        /*
        * GetTriangle : Get the description of the iNoTriangle 'th' triangle of the mesh.
        * oParameters : - oNoVertices[3] the indices the 3 vertices of the triangle.  
        *               - oNoConnexes[3] the 3 neighbour triangles of the iNoTriangle 'th' triangle. 
        */
        virtual void GetTriangle (const int      iNoTriangle,
                                  int            oNoVertices[3],
                                  int            oNoConnexes[3],
                                  unsigned char& oOrientation) const = 0 ;
        /*
        * GetTriangle : Get the description of the iNoTriangle 'th' triangle of the mesh.
        * oParameters : - oNoVertices[3] the indices the 3 vertices of the triangle.  
        *               - oOrientation the orientation of the iNoTriangle 'th' triangle. 
        */
        //virtual void GetTriangle (const int iNoTriangle,
        //                          int       oNoVertices[3],
        //                          unsigned char oOrientation) const = 0 ;
        /*
        * GetNeighbours : Get the neighbour triangles of the iNoVertex 'th' vertex.
        * returns the number of the triangles.  
        * oParameters   : oNoTriangles the triangles indices.
        *                 oNoTriangles must be deleted by the caller.
        */
        virtual int GetNeighbours ( const int     iNoVertex,
                                    int*&         oNoTriangles) const = 0;
        /*
        * UpdateTriangle : Uppdate the triangle iNoTriangle with new vertices in iNoVertices.
        * oParameters    : iNoTriangle the triangles to be updated.
        *                  iNoVertices the new indices of vertices.
        */

        virtual void UpdateTriangle ( const int  iNoTriangle, 
                                      int        iNoVertices[3]) = 0;
        /*
        * RemoveTriangle : Remove the triangle iNoTriangle.
        * oParameters    : iNoTriangle the triangles to be removed.
        */

        virtual void RemoveTriangle ( const int  iNoTriangle) = 0;

        inline void ComputeTriangleNormal (const int        iNoTriangle,
                                           double           oNormal[3]) const
        {
          oNormal[0] = 0. ;
          oNormal[1] = 0. ;
          oNormal[2] = 0. ;

          int TriangleVtx[3];
          int Connexes[3];
          unsigned char orient;
          GetTriangle(iNoTriangle, TriangleVtx,Connexes,orient);
          double Vtx1[3], Vtx2[3], Vtx3[3], V12[3], V13[3], Nor[3];

          GetCoords(TriangleVtx[0] , Vtx1);
          GetCoords(TriangleVtx[1] , Vtx2);
          GetCoords(TriangleVtx[2] , Vtx3);

          V12[0] = Vtx2[0] - Vtx1[0] ;
          V12[1] = Vtx2[1] - Vtx1[1] ;
          V12[2] = Vtx2[2] - Vtx1[2] ;
          V13[0] = Vtx3[0] - Vtx1[0] ;
          V13[1] = Vtx3[1] - Vtx1[1] ;
          V13[2] = Vtx3[2] - Vtx1[2] ;
          Nor[0] = V12[1]*V13[2] - V12[2]*V13[1] ;
          Nor[1] = V12[2]*V13[0] - V12[0]*V13[2] ;
          Nor[2] = V12[0]*V13[1] - V12[1]*V13[0] ;

          double Norme = Nor[0]*Nor[0] + Nor[1]*Nor[1] + Nor[2]*Nor[2] ;
          if (Norme > 0.) {
            double ratio = 1./sqrt(Norme);
            oNormal[0] = Nor[0] * ratio;
            oNormal[1] = Nor[1] * ratio;
            oNormal[2] = Nor[2] * ratio;
          } else {
            oNormal[0] = 0. ;
            oNormal[1] = 0. ;
            oNormal[2] = 0. ;
          }
        }

    };
    CATCldMeshCleaner( T_Mesh *iMesh);
    ~CATCldMeshCleaner();

     int GetCorruptedTriangles ( int*&               oTriangles,
                                 const unsigned char iOnlyActive = 1);

    /**
     * Returns the duplicated triangles of the given mesh.<br>
     * Two triangles are said duplicated when they share the same vertices.
     * @param iMesh
     * The mesh to treat.
     * @param oTriangles
     * Indices array (with buckets mechanism) of the duplicated triangles.<br>
     * <b>CAUTION 1:</b> If two or more triangles are in fact the same, the first found in the
     * mesh will not be in the array because it is considered as the reference.<br>
     * <b>CAUTION 2:</b> The array will not be reinitialized and triangles will be appended to it.
     * @param iOnlyActive
     * If <tt>TRUE</tt>, the research will be done only on the active triangles.
     * @return
     * The number of corrupted triangles.
     */
    int GetDuplicatedTriangles ( int*&               oTriangles,
                                 const unsigned char iOnlyActive = 1) ;

    /**
     * Returns the non-manifold edges of the given mesh.<br>
     * An edge is said non-manifold if it is shared by more than two triangles.
     * @param iMesh
     * The mesh to treat.
     * @param oEdges
     * Array (with buckets mechanism) of the non-manifold edges.<br>
     * <b>CAUTION:</b> The array will not be reinitialized and non-manifold edges will be appended to it.
     * @param iOnlyActive
     * If <tt>TRUE</tt>, the research will be done only on the active triangles.
     * @return
     * The number of non-manifold edges.
     */
    int GetNonManifoldEdges ( int*&                oEdges,
                              const unsigned char  iOnlyActive = 1) ;

    /**
     * Returns the non-Referenced vertices of the given mesh.<br>
     * A vertex is said non-referenced if there is no triangle of the mesh referencing this vertex.
     * @param oVertices
     * Indices array (with buckets mechanism) of the non-manifold vertices.<br>
     * <b>CAUTION:</b> The array will not be reinitialized and vertices will be appended to it.
     * @param iOnlyActive
     * If <tt>TRUE</tt>, the research will be done only on the active vertices.
     * @return
     * The number of non-manifold edges.
     */

    int GetNonReferencedVertices (int*&               oVertices,
                                  const unsigned char iOnlyActive = 1) ;
    /**
     * Returns the non-manifold vertices of the given mesh.<br>
     * A vertex is said non-manifold if its neighbour triangles give two or more connected zones.
     * @param iMesh
     * The mesh to treat.
     * @param oVertices
     * Indices array (with buckets mechanism) of the non-manifold vertices.<br>
     * <b>CAUTION:</b> The array will not be reinitialized and vertices will be appended to it.
     * @param iOnlyActive
     * If <tt>TRUE</tt>, the research will be done only on the active vertices.
     * @return
     * The number of non-manifold edges.
     */
    int GetNonManifoldVertices (int*&               oVertices,
                                const unsigned char iOnlyActive = 1) ;

    /**
     * Returns the different connected zones of the given mesh.<br>
     * @param iMesh
     * The mesh to treat.
     * @param oZones
     * Array (with buckets mechanism) of the connected zones.<br>
     * <b>CAUTION:</b> The array will not be reinitialized and triangles will be appended to it.
     * @param iOnlyActive
     * If <tt>TRUE</tt>, the research will be done only on the active triangles.
     * @return
     * The number of connected zones.
     */
    int GetConnectedZones (int*&               oZones,
                           const unsigned char iOnlyActive = 1) ;

    void GetConnectedZones (int*&               oZones,
                            int&                 oNbZones,
                            const unsigned char  iOnlyActive);

    /**
     * Returns all the triangles of a connected zone of the given mesh defined by one of its triangle.<br>
     * @param iMesh
     * The mesh to treat.
     * @param iFirstTriangle
     * The adress of one of the triangles.
     * @param oTriangles
     * Indices array (with buckets mechanism) of the connected triangles.<br>
     * <b>CAUTION:</b> The array will not be reinitialized and triangles will be appended to it.
     * @param iOnlyActive
     * If <tt>TRUE</tt>, the research will be done only on the active triangles.
     * @return
     * The number of connected triangles.
     */
    int GetConnectedTriangles ( const int           iFirstTriangle,
                                int*&               oTriangles,
                                const unsigned char iOnlyActive = 1) ;

    /**
     * Returns all the triangles surrounding one triangle which fit an angle criterion (between their normals and that of this triangle).<br>
     * @param iMesh
     * The mesh to treat.
     * @param iFirstTriangle
     * The adress of one of the triangles.
     * @param iLimit
     * The limit (cosinus of the angle).
     * @param oTriangles
     * Indices array (with buckets mechanism) of the connected triangles.<br>
     * <b>CAUTION:</b> The array will not be reinitialized and triangles will be appended to it.
     * @param iOnlyActive
     * If <tt>TRUE</tt>, the research will be done only on the active triangles.
     * @return
     * The number of connected triangles.
     */
    int GetConnectedTriangles ( const int           iFirstTriangle,
                                const double        iLimit,
                                int*&               oTriangles,
                                const unsigned char iOnlyActive = 1) ;

    /**
     * Returns the long triangles of the given mesh.<br>
     * A triangle is said long if one of its edges has a length greater than the given one.
     * @param iMesh
     * The mesh to treat.
     * @param iMaxLength
     * The length criterion to define the long triangles.
     * @param oTriangles
     * Indices array (with buckets mechanism) of the long triangles.<br>
     * <b>CAUTION:</b> The array will not be reinitialized and triangles will be appended to it.
     * @param iOnlyActive
     * If <tt>TRUE</tt>, the research will be done only on the active triangles.
     * @return
     * The number of long triangles.
     */
    int GetLongEdgesTriangles ( const double        iMaxLength,
                                int*&               oTriangles,
                                const unsigned char iOnlyActive = 1) ;

    /**
     * Returns the maximum edge length of the triangles of the given mesh.<br>
     * @param iMesh
     * The mesh to treat.
     * @param iOnlyActive
     * If <tt>TRUE</tt>, the research will be done only on the active triangles.
     * @return
     * The maximum edge length.
     */
    double GetMaxEdgeLength ( const unsigned char iOnlyActive = 1) ;

    /**
     * Returns the thin triangles of the given mesh.<br>
     * A triangle is said thin if one of its angles is less than the given minimum one.
     * @param iMesh
     * The mesh to treat.
     * @param iMinAngle
     * The angle criterion to define the thin triangles.
     * @param oTriangles
     * Indices array (with buckets mechanism) of the thin triangles.<br>
     * <b>CAUTION:</b> The array will not be reinitialized and triangles will be appended to it.
     * @param iOnlyActive
     * If <tt>TRUE</tt>, the research will be done only on the active triangles.
     * @return
     * The number of thin triangles.
     */
    int GetSmallAnglesTriangles ( const double        iMinAngle,
                                  int*&               oTriangles,
                                  const unsigned char iOnlyActive = 1) ;

    /**
     * Returns the connected zones of the given mesh defined by triangles with same orientation.<br>
     * @param iMesh
     * The mesh to treat.
     * @param oZones
     * Array (with buckets mechanism) of the connected zones.<br>
     * <b>CAUTION:</b> The array will not be reinitialized and triangles will be appended to it.
     * @param iOnlyActive
     * If <tt>TRUE</tt>, the research will be done only on the active triangles.
     * @return
     * The number of connected zones.
     */
    int GetOrientedZones ( int*&               oZones,
                           const unsigned char iOnlyActive = 1) ;

    /**
     * Returns all the triangles of a same oriented zone of the given mesh defined by one of its triangle.<br>
     * @param iMesh
     * The mesh to treat.
     * @param iFirstTriangle
     * The adress of one of the triangles.
     * @param oTriangles
     * Indices array (with buckets mechanism) of the connected triangles.<br>
     * <b>CAUTION:</b> The array will not be reinitialized and triangles will be appended to it.
     * @param iOnlyActive
     * If <tt>TRUE</tt>, the research will be done only on the active triangles.
     * @return
     * The number of connected triangles.
     */
    int GetOrientedTriangles ( const int           iFirstTriangle,
                               int*&               oTriangles,
                               const unsigned char iOnlyActive = 1) ;

    /**
     * Returns the non-orientable triangles of the given mesh.<br>
     * The result is given by edges shared by triangles couple with inconsistent orientation.
     * @param iMesh
     * The mesh to treat.
     * @param oEdges
     * Array (with buckets mechanism) of the non-manifold edges.<br>
     * <b>CAUTION:</b> The array will not be reinitialized and non-manifold edges will be appended to it.
     * @param iOnlyActive
     * If <tt>TRUE</tt>, the research will be done only on the active triangles.
     * @return
     * The number of non-manifold edges.
     */
    int GetNonOrientableTriangles ( int*&               oEdges,
                                    const unsigned char iOnlyActive = 1) ;

    /**
     * Returns the confused points of the given cloud of points.<br>
     * The result is given by couple of indices <tt>(Confused,With)</tt>.
     * @param iUniCell
     * The <tt>CATCldUniCell</tt> to treat.
     * @param oConfusedPoints
     * Array (with buckets mechanism) of the confused points.<br>
     * <b>CAUTION:</b> The array will not be reinitialized and confudef points will be appended to it.
     * @param iOnlyActive
     * If <tt>TRUE</tt>, the research will be done only on the active points.
     * @return
     * The number of confused points.
     */
    int GetConfusedPoints ( int*&               oConfusedPoints,
                            const unsigned char iOnlyActive = 1) ;
  /**
   * Returns the Free Edges of the given mesh.<br>
   * The result is given by edges is the edges of the triangles which does not have neighbour triangle.
   * @param iMesh
   * The mesh to treat.
   * @param oEdges
   * Array (with buckets mechanism) of the edges.<br>
   * <b>CAUTION:</b> The array will not be reinitialized and free edges will be appended to it.
   * @param iOnlyActive
   * If <tt>TRUE</tt>, the research will be done only on the active triangles.
   * @return
   * The number of free edges.
   */
      int GetFreeEdges ( int*&               oEdges,
                         const unsigned char iOnlyActive = 1) ;
    /**
     * Returns the Free vertices of the given cloud of points.<br>
     * A vertex is said free when it belongs to a free edge</tt>.
     * @param oVertices
     * Array (with buckets mechanism) of the free vertices.<br>
     * <b>CAUTION:</b> The array will not be reinitialized and confudef points will be appended to it.
     * @param iOnlyActive
     * If <tt>TRUE</tt>, the research will be done only on the active points.
     * @return
     * The number of confused vertices.
     */
     int GetFreeVertices ( int*&               oVertices,
                          const unsigned char iOnlyActive = 1) ;
     
    /**
     * Returns the number of layers found in the mesh.<br>
     * @param  oNbTriangles : 
     * the number of triangles forming multi layer on the mesh.<br>
     * @param  oTriangles : 
     * Indices array of integer of the triangles impacted.<br>
     * @param iOnlyActive
     * If <tt>TRUE</tt>, the research will be done only on the active triangles.
     * @return
     * The number of layers.
     */
     int GetMultiLayerTriangles ( int&                oNbTriangles,
                                  int*&               oTriangles,
                                  const unsigned char iOnlyActive = 1);

    /**
     * Fix the confused points described in iConfusedPoints.<br>
     * The result is given by couple of indices <tt>(Confused,With)</tt>.
     * @param iNbPoints
     * Number of point to be fixed.<br>
     * @param iConfusedPoints
     * Array of int of the confused points.<br>
     * @return
     * <tt>1</tt>,If the confused points have been fixed and the mesh is modified.
     * <tt>0</tt>,If the mesh is not modified.
     */
     unsigned char FixConfusedPoints (  const int iNbPoints,
                                        int*&     iConfusedPoints) ;

    /**
     * Fix, by Remove triangle, the iNbTriangles corrupted defined by their
     * indexes in iCorrupted.<br>
     * The result is given by couple of indices <tt>(Confused,With)</tt>.
     * @param iNbTriangles
     * Number of corrupted triangle to be fixed in iCorrupted.<br>
     * @param iCorrupted
     * Array of int of the indexes of corrupted triangles.<br>
     * @return
     * <tt>1</tt>,If the confused points have been fixed and the mesh is modified.
     * <tt>0</tt>,If the mesh is not modified.
     */
     unsigned char FixCorruptedTriangles (const int  iNbTriangles,
                                          int *     &iCorrupted) ;
    /**
     * Fix, by Remove triangle, the iNbTriangles duplicated defined by their
     * indexes in iCorrupted.<br>
     * The result is given by couple of indices <tt>(Confused,With)</tt>.
     * @param iNbTriangles
     * Number of corrupted triangle to be fixed in iCorrupted.<br>
     * @param iCorrupted
     * Array of int of the indexes of corrupted triangles.<br>
     * @return
     * <tt>1</tt>,If the confused points have been fixed and the mesh is modified.
     * <tt>0</tt>,If the mesh is not modified.
     */
     unsigned char FixDuplicatedTriangles (const int  iNbTriangles,
                                           int *     &iDuplicated) ;

    /**
     * Fix all the multi layer of the mesh definied by the multiple triangles.<br>
     * @param iNbTriangles
     * Number of corrupted triangle to be fixed in iCorrupted.<br>
     * @param iDuplicated
     * Array of int of the indexes of Duplicated triangles.<br>
     * @return
     * <tt>1</tt>,If the confused points have been fixed and the mesh is modified.
     * <tt>0</tt>,If the mesh is not modified.
     */
    unsigned char FixMultiLayerTriangles (const int  iNbTriangles,
                                          int *     &iDuplicated) ;

    /**
     * Fix all the non orientable triangles given by their shared edges.<br>
     * @param iNbEdges
     * Number of edges shared by two triangles with inconsistent orientation.
     * @param iEdges
     * Array of int of the indexes of Duplicated triangles.<br>
     * @return
     * <tt>1</tt>,If the confused points have been fixed and the mesh is modified.
     * <tt>0</tt>,If the mesh is not modified.
     */
    unsigned char FixNonOrientableTriangles (const int iNbEdges, int * &iEdges) ;

     /**
     * Fix all the small angles triangles  of the mesh dby collapse.<br>
     * @param iNbTriangles
     * Number of corrupted triangle to be fixed in iCorrupted.<br>
     * @param iTriangles
     * Array of int of the indexes of small angle triangles.<br>
     * @return
     * <tt>1</tt>,If the small angle triangles have been fixed and the mesh is modified.
     * <tt>0</tt>,If the mesh is not modified.
     */
   unsigned char CollapseSmallAngles ( const int iNbTriangles, 
                                        int*& iTriangles);

  private:

    /**
     * Returns the fact that a triangle of a given mesh is corrupted or not.
     */
    unsigned char _IsACorruptedTriangle ( const int      iNoTri) ;

    /**
     * Returns the fact that a vertex of a given mesh is non-manifold or not.
     */
    unsigned char _IsANonManifoldVertex (const int iNoVtx) ;
    unsigned char _IsATopologicalNonManifoldVertex (const int iNoVtx) ;
    unsigned char _IsAGeometricalNonManifoldVertex (const int iNoVtx) ;
    void _GetTriangleNeighbours (const int iNoTriangle, std::set<int> &oNoTriangles) ;

    /**
     * Returns the next triangle-indice modulo 3.
     */
    inline  int _Next (const int iIdx) ;

    /**
     * Returns the previous triangle-indice modulo 3.
     */
    inline  int _Prev (const int iIdx) ;

    /**
     * Returns the opposite edge triangle-indice of a vertex given by its triangle-indice.
     */
    inline  int _OppositeEdge (const int iIVtx) ;

    /**
     * Returns the opposite vertex triangle-indice of an edge given by its triangle-indice.
     */
    inline  int _OppositeVertex (const int iIEdg) ;

    void _EdgeCollapse ( const int iVtx1,const int iVtx2);

    void _VertexCollapse (const int iVtxToCollapse);

    CATBoolean _IsANeedle ( const int iNoTri, int& oVertex);


    T_Mesh* _Mesh;

} ;

//--------------------------------------------------------------------------------------------------------------
// Function : _Next
// Purpose  : Returns the next triangle-indice modulo 3.
//--------------------------------------------------------------------------------------------------------------

inline int CATCldMeshCleaner::_Next (const int iIdx)
{
  return (iIdx + 1) % 3 ; // (I+1)%N
}

//--------------------------------------------------------------------------------------------------------------
// Function : _Prev
// Purpose  : Returns the previous triangle-indice modulo 3.
//--------------------------------------------------------------------------------------------------------------

inline int CATCldMeshCleaner::_Prev (const int iIdx)
{
  return (iIdx + 2) % 3 ; // (I+N-1)%N
}

//--------------------------------------------------------------------------------------------------------------
// Function : _OppositeEdge
// Purpose  : Returns the opposite edge triangle-indice of a vertex given by its triangle-indice.
//--------------------------------------------------------------------------------------------------------------

inline int CATCldMeshCleaner::_OppositeEdge (const int iIVtx)
{
  return (iIVtx + 1) % 3 ; // Dans le cas d'un triangle = Next(iITVertex)
}

//--------------------------------------------------------------------------------------------------------------
// Function : _OppositeVertex
// Purpose  : Returns the opposite vertex triangle-indice of an edge given by its triangle-indice.
//--------------------------------------------------------------------------------------------------------------

inline int CATCldMeshCleaner::_OppositeVertex (const int iIEdg)
{
  return (iIEdg + 2) % 3 ; // Dans le cas d'un triangle = Prev(iITEdge)
}

#endif
