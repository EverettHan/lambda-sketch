#ifndef CATSimplifyParallelTool_H
#define CATSimplifyParallelTool_H

// COPYRIGHT DASSAULT SYSTEMES  2001

#include "ParallelLight.h"
#include "CATTopOperator.h"
//
class CATBody;
class CATWireTopOp;
class CATCGMJournalList;
//class Map3D2D; // Modified By : SUH : 2003:6:27
#include "ListPOfCATEdge.h"
#include "ListPOfCATVertex.h"

class ExportedByParallelLight CATSimplifyParallelTool : public CATTopOperator
{
  public :
  /** @nodoc */
  CATSimplifyParallelTool(CATGeoFactory* iFactory, CATTopData* iData);

  virtual ~CATSimplifyParallelTool();

  #ifdef OldSimplifVxByVx
  virtual CATLONG32 SimplifyFacesBounding(CATBody * SupportBody,
                                    CATWireTopOp * Operateur, CATBody * BodIni, CATBody *BodParallIni,
                                    CATBody *&BodyParallSimplify, CATListOfInt *&ioTwistedEdges)=0;
  #endif

  virtual void SetJournalToStore(CATCGMJournalList * iJourn)=0;

  virtual void GetJournalToStore(CATCGMJournalList * & oJourn)=0;
  virtual void Duplicate (CATSimplifyParallelTool *& IdenticalSimplify)=0;


// Start : SUH : 2003:4:11
  virtual CATBody* CleanWire(CATBody * iWire, CATBody * iSupport, CATLISTP(CATCell) * iCellsToFix,
                             const double iTol, const double iAngleTol, const double iCR[2],
                             double &oMaxReachedDeformation, CATLISTP(CATEdge) * oDescendEdges = 0,
                             CATLISTP(CATVertex) * oMappedVtx = 0, CATLISTP(CATVertex) * oDMappedVtx = 0) = 0;
// End : SUH : 2003:4:11


};


#endif


