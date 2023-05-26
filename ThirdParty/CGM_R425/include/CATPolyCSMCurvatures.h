// COPYRIGHT DASSAULT SYSTEMES 2011
//===================================================================
//
// CATPolyCSMCurvatures.h
// Header definition of CATPolyCSMCurvatures.
//
//===================================================================
//
// Usage notes:
//   CSM -> Method used to compute the curvature caracteristics : 
//                  Cohen-Steiner & Morvan. 
//   This method is interesting in reverse context, for noisy 
//   meshes. It take into account a ring distance defining a sphere 
//   in which the triangles and the vertices balance the result.
//   To work correctly, the input mesh has to be dense enough.
//
//===================================================================
//
//  Feb 2011  Creation: DNR
//===================================================================

#ifndef CATPolyCSMCurvatures_H
#define CATPolyCSMCurvatures_H

#include "ExportedByPolyhedralOperatorsRvs.h"

class CATIPolyMesh ;
class CATMathVector;


class ExportedByPolyhedralOperatorsRvs CATPolyCSMCurvatures
{
  
  public:

    /**
     * Constructor.
     */
    static CATPolyCSMCurvatures* NewOperator();

    /**
     * Virtual destructor.
     */
     virtual ~CATPolyCSMCurvatures();

    /**
     * Virtual LoadMesh.
     * @param iPolyMesh : Mesh to be be considered.
     *
     */
    virtual void LoadMesh (CATIPolyMesh* iPolyMesh) = 0;

    /**
     * Virtual GetCurvatures.
     *
     * @param iVertex       : Number of the vertex where to compute the curvature values.
     * @param iRadiusRing   : Radius ring diameter value.
     * @param oMinCurvature : Minimum curvature value.
     * @param oMaxCurvature : Maximum curvature value.
     * @param oVectKmin     : Minimum curvature direction.
     * @param oMaxCurvature : Maximum curvature direction.
     *
     * Return value : 0 -> the computation is OK.
     *                else an error occured.
     */
    virtual int GetCurvatures( const int iVertex , 
                               double iRadiusRing ,
                               double & oMinCurvature , 
                               double & oMaxCurvature ,
                               CATMathVector & oVectKmin ,
                               CATMathVector & oVectKmax) = 0;

};

#endif
