#ifndef CATWireTools_h
#define CATWireTools_h

// COPYRIGHT DASSAULT SYSTEMES 1999

//#include "CATDynOperator.h"
#include "CATTopOperator.h"
#include "PrimitivesLight.h"
#include "CATTopDef.h"

class CATGeoFactory;
class CATBody;
class CATEdge;
class CATVertex;
class CATCurve;
class CATWire;
class CATCGMJournalList;

class ExportedByPrimitivesLight CATWireTools : public CATTopOperator
{
public:

  //  Creates a new Wire Adding a New Edge After Specified Vertex
  //  The body must only contain a single wire 
  //  The extrapolation can be made in "Replace Mode" by given the 
  //  edge to replace. In this case, the edge must be the first or 
  //  the last edge of the wire, and the vertex must correspond to 
  //  connecting place.

  CATWireTools(CATGeoFactory*    factory,
    CATTopData * iData,
	       CATBody*          iBody,
	       CATVertex*        iConnectVertex,
	       CATCurve*         iExtrapolationCurve,
	       CATEdge*          iEdgeToReplace);
  
  ~CATWireTools();
  
  int Run();

  CATVertex* GetNewVertex(); // permet de savoir ce qu'est devenu le iConnectVertex
                             // apres l'operation (et doit donc etre lance apres le Run() )
  
  CATVertex * GetOtherVertex(); // Permet de savoir quel est l'autre vertex cree (LAT)

private:

  CATBody*          _InputBody;
  CATBody*          _ResultBody;
  CATWire*          _Wire;
  CATVertex*        _JunctionVx;
  CATVertex*        _ConnectVx;
  CATVertex*        _OtherEndVertex;
  CATEdge*          _EdgeToReplace;
  CATCurve*         _ExtrapolationCurve;   
};
#endif





