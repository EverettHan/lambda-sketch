// COPYRIGHT DASSAULT SYSTEMES 2011
//===================================================================
//
// CATPolyQuickLightCompareOper.h
// Header definition of CATPolyQuickLightCompareOper.
// Comparison of two meshes CATIPolyMesh.
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Feb 2011  Creation: DNR
//===================================================================

#ifndef CATPolyQuickLightCompareOper_H
#define CATPolyQuickLightCompareOper_H

#include "ExportedByPolyhedralOperatorsRvs.h"
#include "CATListOfInt.h"

class CATIPolyMesh;

class ExportedByPolyhedralOperatorsRvs CATPolyQuickLightCompareOper
{
  
  public:

    /**
     * Constructor.
     */
    static CATPolyQuickLightCompareOper* NewOperator();

    /**
     * Virtual destructor.
     */
    virtual ~CATPolyQuickLightCompareOper();

    /**
     * Virtual SetMesh_Data : Initialize the meshes to compare.
     * @param iPolyMeshSrc : SRC mesh.
     *        iSagSrc      : Sag of the SRC mesh.
     *        iPolyMeshRef : REF mesh.
     *        iSagSrc      : Sag of the SRC mesh.
     */

    virtual int SetMesh_Data ( CATIPolyMesh  * iPolyMeshSrc, 
                               double          iSagSrc,
                               CATIPolyMesh  * iPolyMeshRef, 
                               double          iSagRef) = 0;

    /**
     * Virtual GetDiferentiateFaces : Returns the numbers of the faces detected as different.
     * @param - oLstDifFacesSrc : List of the number of different faces found int SRC mesh.
     *        - oLstDifFacesRef : List of the number of different faces found int REF mesh.
     *        
     * Nota : - All duplicated faces in SRC or REF mesh are referenced once.
     *        - All duplicated faces between SRC and REF mesh are not referenced.
     */
    virtual int GetDiferentiateFaces( CATListOfInt & oLstDifFacesSrc, 
                                      CATListOfInt & oLstDifFacesRef) = 0;

    /**
     * Virtual GetDistance_Src_Ref : Returns the zones of the "SRC" mesh detected as different with "REF" mesh.
     *
     * @param - iDistMin   : Minimum distance to be used to compare the faces.
     *        - oNbrVtx    : Number of points of the set of points used to describe the "Dif" and "Equ" zones.
     *        - oTabVtx    : Coordinates (x,y,z) of the points of the set of points. 
     *        - oTabVec    : Distance vectors (Vx,Vy,Vz) computed at each vertices of SRC to reach REF.
     *        - oNbrTriDif : Number of of triangles defining the "Dif" zones.
     *        - oTabTriDif : Array of the indices of points defining the vertices of triangles 
     *                       of the "Dif" zone. (3 vertices by triangle) 
     *        - oNbrTriEqu : Number of of triangles defining the "Equ" zones.
     *        - oTabTriDif : Array of the indices of points defining the vertices of triangles 
     *                       of the "Equ" zone. (3 vertices by triangle) 
     *        
     * Nota : - The allocation of the arrays are done inside the methods, the caller has to delete them after use.
     */
    virtual int GetDistance_Src_Ref ( double   iDistMin, 
                                      int &    oNbrVtx, 
                                      float *& oTabVtx, 
                                      float *& oTabVec, 
                                      int &    oNbrTriDif, 
                                      int *&   oTabTriDif,
                                      int &    oNbrTriEqu, 
                                      int *&   oTabTriEqu) = 0;

    /**
     * Virtual GetDistance_Ref_Src : Returns the zones of the "REF" mesh detected as different with "SRC" mesh.
     *
     * @param - iDistMin   : Minimum distance to be used to compare the faces.
     *        - oNbrVtx    : Number of points of the set of points used to describe the "Dif" and "Equ" zones.
     *        - oTabVtx    : Coordinates (x,y,z) of the points of the set of points. 
     *        - oTabVec    : Distance vectors (Vx,Vy,Vz) computed at each vertices of SRC to reach REF.
     *        - oNbrTriDif : Number of of triangles defining the "Dif" zones.
     *        - oTabTriDif : Array of the indices of points defining the vertices of triangles 
     *                       of the "Dif" zone. (3 vertices by triangle) 
     *        - oNbrTriEqu : Number of of triangles defining the "Equ" zones.
     *        - oTabTriDif : Array of the indices of points defining the vertices of triangles 
     *                       of the "Equ" zone. (3 vertices by triangle) 
     *        
     * Nota : - The allocation of the arrays are done inside the methods, the caller has to delete them after use.
     */

  virtual int GetDistance_Ref_Src ( double   iDistMin, 
                                    int &    oNbrVtx, 
                                    float *& oTabVtx, 
                                    float *& oTabVec, 
                                    int &    oNbrTriDif, 
                                    int *&   oTabTriDif,
                                    int &    oNbrTriEqu, 
                                    int *&   oTabTriEqu) = 0;

};

#endif
