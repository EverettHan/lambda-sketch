// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : ZUT
//
// DESCRIPTION  : Class defining the topological operator that removes 
//                given Edges on a body.
//                
//=============================================================================
// Creation ZUT March 2009
//=============================================================================

#ifndef CATRemoveEdgePlusOpe_H
#define CATRemoveEdgePlusOpe_H

#include "Thick.h"
#include "CATTopOperator.h"

#include "CATTopDefine.h"
#include "ListPOfCATEdge.h"
#include "CATListOfDouble.h"

class CATBody;
class CATEdge;
class CATRemoveEdgePlusImpl;

/**
 * Class defining the topological operator that removes given Edges on a body.
 */  
class ExportedByThick CATRemoveEdgePlusOpe : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATRemoveEdgePlusOpe);
  
public:

  //-------------------------------------------------------
  // Constructor: use the method CATCreateRemoveEdgePlusOpe
  //-------------------------------------------------------
  CATRemoveEdgePlusOpe( CATGeoFactory         * iFactory,
                        CATTopData            * iTopData,
                        CATRemoveEdgePlusImpl * iImpl );

  //-----------
  // Destructor
  //-----------
  virtual ~CATRemoveEdgePlusOpe();

  /**
   * Appends an edge to remove
   * @param iEdgeToRemove
   * The edge to remove.
   */
  void Append(CATEdge * iEdgeToRemove);

  /**
   * Appends a list of Edges to remove
   * @param iEdgesToRemove
   * The list of pointers to Edges to remove.
   */
  void Append(const CATLISTP(CATEdge) & iEdgesToRemove);

  /**
   * Propagate edge list according to tangency : 1 = ON, 0 = OFF.
   */
  void SetPropagationMode(short iPropagationMode);


  /**
  * Defines if removed edges should be kept in the result body
  * @param iKeepBorderEdges
  * 0 : OFF
  * 1 : ON
  */
  void SetKeepBorderEdges(short iKeepBorderEdges);

  /**
   * @nodoc
   * If ON, RemoveEdge Operator tries to independently remove connected subsets of edges
   * when RemoveEdge call on all the edges fails
   * @param iPartialRemoveEdgeAllowed
   * 0 - Partial result is disabled
   * 1 - The operator returns a best result on which a maximum number of edges has been removed.
   *     Consistency between the result and the list of tricky edges is guaranteed :
   *     The same operation without the tricky edges would return the exact same result.
   * 2 - Same as 1, but without the consistency check (performances)
   */
  void SetPartialRemoveEdgeAllowed(short iPartialRemoveEdgeAllowed);

  /**
   * Returns the list of CATEdge that couldn't be removed.
   */
  void GetAllTrickyEdges(CATLISTP(CATEdge) & oAllTrickyEdges);

  /**
   * Run the operator
   */
  int Run();

  //------------------
  // For SkinHolePlug
  //------------------
  /** @nocgmitf */
  void SetPartialRunOnly( short iPartialRunOnly );
  /** @nocgmitf */
  void SetFaceMatterSideReversalAllowed(short iFaceMatterSideReversalAllowed);
  /** @nocgmitf */
  void Append(CATEdge * iEdgeToRemove, double iExtrapolVal);
  /** @nocgmitf */
  void Append(const CATLISTP(CATEdge) & iEdgesToRemove, double iExtrapolVal);
  /** @nocgmitf */
  void Append(const CATLISTP(CATEdge) & iEdgesToRemove, const CATListOfDouble & iExtrapolValList);

  //-------------------
  // For RemoveFaceG1G2
  //-------------------
  /** @nocgmitf */
  void SetMaxExtrapolValue(double iMaxExtrapolValue);

  /**
  * @nocgmitf
  * internal RemoveFaceG1G2 option only.
  */
  void SetCouplingMode(short iCouplingMode);

  //------------------
  // CGMReplay methods
  //------------------
  /** @nocgmitf ID pour CGMReplay */
  void SetCGMMode( short iCGMMode );

  /** @nocgmitf ID pour CGMReplay */
  static const CATString * GetDefaultOperatorId();

  /** @nocgmitf ID pour CGMReplay */
  const CATString * GetOperatorId();

  /** @nocgmitf declaration integre au CGMReplay */
  CATExtCGMReplay * IsRecordable( short & LevelOfRuntime, short &VersionOfStream );

  /** @nocgmitf pour CGMReplay */
  void WriteInput( CATCGMStream  & Str );

  /** @nocgmitf pour CGMReplay */
  void ReadInput( CATCGMStream  & ioStr, int VersionOfStream );

  /** @nocgmitf pour CGMReplay */
  void Dump( CATCGMOutput& os ) ;

  /** @nocgmitf ID pour CGMReplay */
  void DumpOutput( CATCGMOutput &os );

  /** @nocgmitf definition des Objets  ...*/
  void RequireDefinitionOfInputAndOutputObjects();

protected:

  /**
  * Runs <tt>this</tt> operator.
  */
  int RunOperator();

  CATRemoveEdgePlusImpl * GetRemoveEdgePlusImpl();
};

// -----------------------
// CATCreateRemoveEdgePlus
// -----------------------
ExportedByThick CATRemoveEdgePlusOpe * CATCreateRemoveEdgePlusOpe( CATGeoFactory & iFactory,
                                                                   CATTopData    & iTopData,
                                                                   CATBody       & iReferenceBody );

// -----------------------
// CATCreateRemoveEdgePlus
// -----------------------
ExportedByThick CATRemoveEdgePlusOpe * CATCreateRemoveEdgePlusOpe( CATGeoFactory * iFactory,
                                                                   CATTopData    * iTopData,
                                                                   CATBody       * iReferenceBody );

#endif
