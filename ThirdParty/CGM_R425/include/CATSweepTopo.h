#ifndef CATSweepTopo_H_
#define CATSweepTopo_H_
/*
// 
// COPYRIGHT DASSAULT SYSTEMES 1999

// Mise en // Mars 2002 JSX

#include "CATSweepDef.h"
#include "CATSweep.h"
#include "ListPOfCATBody.h"
class CATWire;
class CATBody;
class CATMathDirection;
class CATPoint;
class CATPlane;
class CATSurface;
class CATEdge;
class CATMathAxis;
class CATGeoFactory;
class CATEdge;
class CATPoint;
#include "FrFTopologicalOpe.h"
//
// Fonctions Globales
// ------------------
//
// Gets the wire of a wire body
ExportedByFrFTopologicalOpe CATWire * CATSweepGetWire(CATBody & iBodyWire);
//
// Concatenation of 2 Wires: begin = begin + end
ExportedByFrFTopologicalOpe void CATSweepConcatWire(CATBody & IDeb,CATBody & iFin);
ExportedByFrFTopologicalOpe void CATSweepConcatWire(CATWire & IDeb,CATWire & iFin);
//
//
// Evaluates the extremities of a 1d element (edge, wire, BodyWire...)
ExportedByFrFTopologicalOpe CATMathDirection * CATSweepEvalTgMonopare(CATBody & iBody,CATLimit iD);  // Normed Tangent or NULL
ExportedByFrFTopologicalOpe CATMathDirection * CATSweepEvalTgMonopare(CATWire & iWire,CATLimit iD);
ExportedByFrFTopologicalOpe CATMathDirection * CATSweepEvalTgMonopare(CATEdge & iEdge,CATLimit iD);
ExportedByFrFTopologicalOpe CATPoint         * CATSweepEvalPtMonopare(CATBody & iBody,CATLimit iD);
ExportedByFrFTopologicalOpe CATPoint         * CATSweepEvalPtMonopare(CATWire & iWire,CATLimit iD);
ExportedByFrFTopologicalOpe CATPoint         * CATSweepEvalPtMonopare(CATEdge & iEdge,CATLimit iD);

// Creates the bodies C1
ExportedByFrFTopologicalOpe ListPOfCATBody * CATExplodeCenter(CATGeoFactory & iFactory,CATBody & iCenter,int StartAttrib,int EndAttrib);
ExportedByFrFTopologicalOpe ListPOfCATBody * CATExplodeCenter(CATGeoFactory & iFactory, CATWire & iCenter,int StartAttrib,int EndAttrib);

// Creates a median plan between two edges
ExportedByFrFTopologicalOpe CATPlane * CATCreateDiscontPlane(   CATGeoFactory    & iFactory,
                                                                CATEdge            & iEdge1,
                                                                CATOrientation    &iOrient1,
                                                                CATEdge            & iEdge2,
                                                                CATOrientation    & iOrient2);
ExportedByFrFTopologicalOpe CATPlane * CATCreateLimitPlane (    CATGeoFactory        & iFactory,
                                                                CATEdge            & iEdge,
                                                                CATOrientation    & iOrient,
                                                                CATLimit          iD);

// common support of the edges of a  Body
ExportedByFrFTopologicalOpe CATSurface * CATGetBodySupport(CATBody & iBody);
ExportedByFrFTopologicalOpe CATSurface * CATEdgeGetSupport(CATEdge & iEdge);
// DistanceMin Pt Body/wire...
double CATSweepDistanceMin(CATGeoFactory & iFactory,CATPoint & iPoint,CATEdge * iEdge);
double CATSweepDistanceMin(CATGeoFactory & iFactory,CATPoint & iPoint,CATWire * iWire,CATLONG32 & oNumEdge);
double CATSweepDistanceMin(CATGeoFactory & iFactory,CATPoint & iPoint,CATBody * iCenter,CATLONG32 & oNumEdge );
//
//    Selects a point on a body
CATPoint     * CATSweepGetPointOnCell(CATGeoFactory &  iFactory,CATCell * iCell, int iNum);
CATPoint     * CATSweepGetPointOnCell(CATGeoFactory &  iFactory,CATBody * iBody, int iNum);
CATMathPoint * CATSweepGetPointOnBody(CATGeoFactory &  iFactory,CATBody * iBody);
*/
#endif
