/* -*-C++-*-*/
#ifndef CATHLRCoSubEdge_H
#define CATHLRCoSubEdge_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2012
//
// CATHLRCoSubEdge 
//
// DESCRIPTION :
//
// occurrence of a part of CATHLREdge inside a loop for the HLR after subdivision of a face by the silhouettes
//
// Main Methods :
//  
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Nov. 12 DPS Creation            
//
//=============================================================================


#include "HLRTopology.h"

#include "CATHLRCoedge.h"

#include "CATCrvParam.h"


class CATHLREdge;
class CATHLRPCurve;
class CATHLRVertex;

class ExportedByHLRTopology CATHLRCoSubEdge : public CATHLRCoedge
{
public:

//=============================================================================
// CONSTRUCTOR
//=============================================================================
/** Constructor with a PCurve, a sense and Vertices lying on a original Edge with global CrvParam (on the CATHLRCurve of the edge)
 */
  CATHLRCoSubEdge(CATHLRPCurve * iPCurve, CATHLREdge * iOriginalEdge, CATLONG32 iSense, 
                  CATHLRVertex * iStartVtxInLoop, CATHLRVertex * iEndVtxInLoop, CATCrvParam &iStartCrvPar, CATCrvParam  &iEndCrvPar);


//=============================================================================
// METHODS
//=============================================================================

  virtual CATHLRVertex * GetStartVertexInLoop(CATCrvParam * iStartParamInLoop);
  virtual CATHLRVertex * GetEndVertexInLoop(CATCrvParam * iEndParamInLoop);


//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:

  CATHLRVertex         * _StartVtxInLoop;
  CATHLRVertex         * _EndVtxInLoop;
  CATCrvParam            _StartCrvPar;
  CATCrvParam            _EndCrvPar;
};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================


#endif
