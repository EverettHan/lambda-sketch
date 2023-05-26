/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATWireStatus: 
// Tool Box for getting a CATWire status (length, bounding box, elements) 
//
//=============================================================================
// Jun. 99   Creation                                   L. Mahe
//=============================================================================
#ifndef CATWireStatus_h
#define CATWireStatus_h

#include "AnalysisToolsLight.h"
#include "CATHybDef.h"
#include "CATTopDef.h"
#include "CATMathDef.h"
#include "CATPGMWireStatus.h"
#include "CATWireStatusExt.h"

class CATMathVector;

//-----------------------------------------------------------------------------
class ExportedByAnalysisToolsLight CATWireStatus: public CATPGMWireStatus
{
  public :
    //-------------------------------------------------------------------------
    // Constrcutor/Destructor
    //-------------------------------------------------------------------------
    CATWireStatus(CATWire *iWire);
    ~CATWireStatus();     

    //-------------------------------------------------------------------------
    // Elements Access
    //-------------------------------------------------------------------------
    CATEdge * GetFirstEdge(CATOrientation *oOri=NULL);
    CATEdge * GetLastEdge(CATOrientation *oOri=NULL);

    CATVertex * GetFirstVertex();
    CATVertex * GetVertex(CATLONG32 iRank);
    CATVertex * GetLastVertex();

    //-------------------------------------------------------------------------
    // Coordinates Access
    //-------------------------------------------------------------------------
    CATMathPoint  GetFirstCoord();
    CATMathPoint  GetVertexCoord(CATLONG32 iRank);
    CATMathPoint  GetLastCoord();

    //-------------------------------------------------------------------------
    // Geometry Data Access
    //-------------------------------------------------------------------------
    CATCrvParam  GetFirstParamOnEdgeCurve();
    CATCrvParam  GetLastParamOnEdgeCurve();
    void  GetVertexParamOnEdgeCurve(CATLONG32 iRank,CATCrvParam * oParam);

    CATMathVector  GetFirstTangent();
    CATMathVector  GetLastTangent();
    void  GetTangent(CATLONG32 iRank,CATMathVector * oVector);

    CATPositiveLength GetLength();
//    CATWire * DoInvert(CATBody *iTargetBody);
    CATMathBox GetBoundingBox(CATLONG32 iRank);
    CATMathBox GetBoundingBox();
    double GetMaxDimension();// max(Xmax-Xmin, Ymax-Ymin, Zmax-Zmin)

  
  private:

    CATWireStatusExt _Extension;

};
#endif










