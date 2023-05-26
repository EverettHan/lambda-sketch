/*
=============================================================================

 COPYRIGHT   : DASSAULT SYSTEMES 1998
 
 DESCRIPTION : CATParallelUtili Operator

=============================================================================
*/
#ifndef CATCATParallelUtili_H
#define CATCATParallelUtili_H

//#include "ExportedByCATFDGImpl.h"
#include "ExportedByPARLight.h"
#include "ParallelLight.h"
#include "CATTopDef.h"
#include "CATTopData.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATListOfInt.h"
#include "ListPOfCATWire.h"

class CATBody;
class CATLaw;
class CATCGMJournalList;
class CATGeoFactory;
class CATWire;
class CATEdge;
class CATCrvParam;
class CATWireTopOp;
class CATDistanceTool;
class CATDomain;


//-----------------------------------------------------------------------------
//  Decode topologie pour les wires
//-----------------------------------------------------------------------------

//Calcule la conxite entre deux wires
enum ConvexValue {Convexe, Concav, Mort, Rebroussement, UnknownConvexVal} ;


ExportedByPARLight
ConvexValue Convexity(CATTopData * iData, CATDistanceTool * iDistTool, CATBody * iShFond,CATBody * iWire1,CATBody * iWire2,
                      CATBody * iParall1, CATBody * iParall2, CATLONG32 ioffset, int ExtrapInfo = 1);

ExportedByPARLight
void SearchFirstSolution(CATGeoFactory * Facto, CATTopData * iData, CATBody * BodyInters,CATBody * BodInters1,CATBody * BodInters2,CATLONG32 Extrema1,CATLONG32 Extrema2,
                         CATBody *& NewBody);

//
// recherche des extremites equivqlentes aux extremites du wire G1 original dans
// le resultat du parallele
CATLONG32 SearchEquivExt(CATTopData * iData, CATBody * SupportBody, CATLaw * radius,CATLaw ** MapLaw1, CATBody * BodIni,CATBody * BodParall,CATWireTopOp * Operateur,
                    CATLONG32 & NumDebWire, CATLONG32 & NumFinWire, CATBody ** oBErr=NULL);
//nouvelle version
CATLONG32 NewSearchEquivExt(CATTopData * iData, CATBody * SupportBody, CATLaw * radius,CATLaw ** MapLaw1, CATBody * BodIni,CATBody * BodParall,CATWireTopOp * Operateur,
                    CATLONG32 & NumDebWire, CATLONG32 & NumFinWire, CATLONG32 *& DescDeb, CATLONG32 *& DescFin, CATBody ** oBErr=NULL,CATDistanceTool * iDistTool=NULL,CATListOfInt * ListOfInvalidDomains=NULL);

int CheckIfExtrOnBorder(CATDomain * CurDom1,CATDomain * CurDom2,CATBody * SupportBody);

//  calcul des l'extrapolation

// assemblage entre le wire parallele inital et ses extrapolations
ExportedByParallelLight
void AssWire(CATGeoFactory * CurFacto, CATTopData * iData, CATBody * iExtrapDeb, CATBody * &WireSol, CATBody * iExtrapFin,
                     CATLONG32 isclosed, CATLONG32 istwisted=0);
//						 CATCGMJournalList * Report, CATLONG32 isclosed);

// assemblage ou trim entre deux paralleles successifs
ExportedByParallelLight
void TrimParallel(CATGeoFactory * CurFacto, CATTopData * iData, CATBody * ShFond, CATBody * Wire1, CATBody * Wire2, CATLaw * radius,
                  CATOrientation offset, CATLONG32 iClosure, CATBody * Parallel1, CATBody * Parallel2,
                  CATBody*& BodyResult, int ExtrapInfo = 1);
//                  CATBody*& BodyResult, CATCGMJournalList * Report, int ExtrapInfo = 1);

// IZE wk. 05 09 IR 0646989 Simplify connex solutions. 
// May be activated in case of ribbons inconsistencies
// due to orientations problems at geometrical level. This version still triggers regressions and is not safe at memory level
// Must be converged in case of need.
//ExportedByPAR
//void MergeConnexWires(CATGeoFactory * iFacto, CATTopData * iData, CATBody * ioCurParallelResult, ListPOfCATWire &ioWires);

#endif
