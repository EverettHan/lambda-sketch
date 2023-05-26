// COPYRIGHT DASSAULT SYSTEMES 1998 
//==========================================================================
//
// CATTopologicalTessTool:
// Interface class of the TopologicalTessTool.
//
//==========================================================================
//
// Usage notes:
// This class is utility for tesselation of topological elements
//
// iSetOfPoints is given as input and is not deleted 
// by destructor of this class.
//
//========================================================================== 
// May 98  Creation                                   Olivier SCHOUTTETEN
//========================================================================== 

#ifndef CATTopologicalTessTool_H
#define CATTopologicalTessTool_H

#include "PowerTopologicalOpe.h"
#include "CATTessStore.h"

class CATMathSetOfPointsND;
class CATTessSettings;

//-----------------------------------------------------------------------------
class ExportedByPowerTopologicalOpe CATTopologicalTessTool : public CATTessStore
{
    public :
    CATTopologicalTessTool(CATMathSetOfPointsND * iSetOfPoints,CATTessSettings * iTessSettings); 

    ~CATTopologicalTessTool();

    void StoreVertex(CATVertex    * iVertex,
                     CATMathPoint * iMathPoint,
                     CATBoolean     iNew, 
                     CATFace      * iBoundedFace,
                     CATLONG32      iPointNumberInFace);
                   
    void StoreEdge(CATEdge               * iEdge,
                   CATBoolean              iNew,
                   CATLONG32               iNumberOfPoints,
                   CATMathSetOfPointsND  * iMathPoints,
                   CATMathSetOfPointsND  * iCrvParams, 
                   CATFace               * iBoundedFace,
                   CATLONG32             * iPointNumberInFace);

    void StoreFace(CATFace            * iFace,
                   CATBoolean           iNew,
                   CATBoolean           iVolume,
                   CATSide              iSide,
                   CATBoolean           iPlane,
                   CATLONG32            iNumberOfPoints,
                   CATTessPointIter   * iPoints,
                   CATLONG32            iNumberOfStrips,
                   CATTessStripeIter  * iStrips,
                   CATLONG32            iNumberOfFans,
                   CATTessFanIter     * iFans,
                   CATLONG32            iNumberOfPolygons,
                   CATTessPolyIter    * iPolygons,
                   CATLONG32            iNumberOfTriangles,
                   CATTessTrianIter   * iTriangles );

    CATMathSetOfPointsND * GetSetOfPoints();

    private :

    CATMathSetOfPointsND * _SetOfPoints;
    CATTessSettings      * _TessSettings;
};
#endif








