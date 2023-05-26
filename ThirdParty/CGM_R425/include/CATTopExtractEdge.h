/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATTopExtractEdge:
// Class for the operator that clones the geometry of input CATEdge (POEC and
// EdgeCurve) and creates a new CATEdge on the brand new geometry. Operator clones
// only the necessary POEC.
//
//=============================================================================
// Usage Notes:
//
// If list of CATEdge refers to more than one element, user can make an
// assembly of the cloned CATEdge with DoEdgeAssembly() method.
//=============================================================================
// Sep. 99   Creation                                   L. Mahe
//=============================================================================
#ifndef CATTopExtractEdge_h
#define CATTopExtractEdge_h

#include "BasicTopology.h"
#include "CATTopOperator.h"
#include "CATGeoToTopOperator.h"
#include "CATListOfCATCells.h"
#include "CATTopDef.h"
#include "CATString.h"

class CATCurve;
class CATEdgeCurve;
class CATTopWire;
class CATCloneManager;
class CATTopologicalOperator;
class CATHybOperator;
class CATBody;
class CATEdge;

//-----------------------------------------------------------------------------
class ExportedByBasicTopology CATTopExtractEdge : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopExtractEdge);
  public :
    //-------------------------------------------------------------------------
    // Constructor/Destructor
    //-------------------------------------------------------------------------
    CATTopExtractEdge(CATGeoFactory     * iFactory,
                      CATTopData        * iTopData,
                      CATEdge           * iEdge,
                      CATBodyFreezeMode   iMode = CATBodyFreezeOff);

    CATTopExtractEdge(CATGeoFactory     * iFactory,
                      CATTopData        * iTopData,
                      CATLISTP(CATCell) * iEdges,
                      CATBodyFreezeMode   iMode = CATBodyFreezeOff);

    virtual ~CATTopExtractEdge();

    //-------------------------------------------------------------------------
    // Operator management
    //-------------------------------------------------------------------------
    int  Run();
    void DoEdgeAssembly();

  /** @nodoc @nocgmitf */
    static const CATString *GetDefaultOperatorId() { return &_OperatorId; }
  
  protected :

    // CGM Replay
    static CATString  _OperatorId;
    const  CATString *GetOperatorId();
    CATExtCGMReplay  *IsRecordable( short &LevelOfRuntime, short &VersionOfStream );
    void              WriteInput( CATCGMStream  &ioStream );
    void              Dump( CATCGMOutput &os ) ;
    int               RunOperator();
    void              RequireDefinitionOfInputAndOutputObjects();
};
#endif
