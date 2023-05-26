// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : ZUT
//
// DESCRIPTION  : This operator plugs - partially or totally - holes of a skin.
//                
//=============================================================================
// Creation ZUT March 2009
//=============================================================================

#ifndef CATSkinHolePlugOpe_H
#define CATSkinHolePlugOpe_H

#include "AdvTrimOpe.h"
#include "CATPersistentOperator.h"

#include "CATMathDef.h"
#include "ListPOfCATEdge.h"

class CATString;
class CATBody;
class CATEdge;
class CATPersistentBody;
class CATPersistentCellInfra;

class CATSkinHolePlugImpl;

class ExportedByAdvTrimOpe CATSkinHolePlugOpe : public CATPersistentOperator
{
  CATCGMVirtualDeclareClass(CATSkinHolePlugOpe);

public:

  //-----------------------------------------------------
  // Constructor: use the CATCreateSkinHolePlugOpe method
  //-----------------------------------------------------
  CATSkinHolePlugOpe( CATGeoFactory         * iFactory,
                      CATTopData            * iTopData,
                      CATSkinHolePlugImpl   * iImpl );

  //-----------
  // Destructor
  //-----------
  virtual ~CATSkinHolePlugOpe();

  /**
  * Appends an edge which belongs to an outer boundary of the skin.
  * @param iOuterBoundaryEdge
  * The edge to append.
  */
  void AppendEdgeFromOuterBoundary( CATEdge * iEdgeFromOuterBoundary );

  /**
  * Appends a list of edges which belong to outer boundaries of the skin.
  * @param iOuterBoundaryEdges
  * The list of edges to append.
  */
  void AppendEdgesFromOuterBoundaries( const CATLISTP(CATEdge) & iEdgesFromOuterBoundaries );

  /**
  * Appends an edge which belongs to a skin hole boundary.
  * @param iHoleBoundaryEdge
  * The list of edges to append.
  */
  void AppendEdgeFromHoleToRemove( CATEdge * iEdgeFromHoleToRemove );

  /**
  * Appends a list of edges which belong to skin holes boundaries.
  * @param iHoleBoundaryEdges
  * The edge to append.
  */
  void AppendEdgesFromHolesToRemove( const CATLISTP(CATEdge) & iEdgesFromHolesToRemove );

  /**
  * Indicates whether all skin holes should be removed or not
  * @param iPlugAllHoles
  * When ON (>0), operator tries to plug all skin holes
  */
  void SetPlugAllHoles( short iPlugAllHoles );
  
  /**
  * Indicates whetheronly explicit inner loops should be removed or not
  * @param iPlugOnlyExplicitInnerLoops
  * When ON (>0), operator only tries to plug explicit inner loops holes
  */
  void SetPlugOnlyExplicitInnerLoops(short iPlugOnlyExplicitInnerLoops);

  /**
  * Runs <tt>this</tt> operator.
  */
  int RunOperator();

  /** @nodoc */
  void GetTrickyEdges( CATLISTP(CATEdge) & oTrickyEdges ) const;

  /** @nodoc */
  void SetRequiredExtrapolationValue( CATEdge * iFreeBorderEdge, double iExtrapolationValue );

  //------------------
  // CGMReplay methods
  //------------------
  /** @nodoc ID for CGMReplay */
  static const CATString * GetDefaultOperatorId();

  /** @nodoc ID for CGMReplay */
  const CATString * GetOperatorId();

  /** @nodoc for  CGMReplay */
  CATExtCGMReplay * IsRecordable( short & LevelOfRuntime, short & VersionOfStream );

  /** @nodoc for CGMReplay */
  void WriteInput( CATCGMStream  & Str );

  /** @nodoc for CGMReplay */
  void ReadInput( CATCGMStream  & ioStr, int VersionOfStream);

  /** @nodoc for CGMReplay */
  void Dump( CATCGMOutput& os ) ;

  /** @nodoc for CGMReplay */
  void DumpOutput( CATCGMOutput &os );

  /** @nodoc for CGMReplay */
  void RequireDefinitionOfInputAndOutputObjects();

  /** @nodoc for CGMReplay */
  void SetCGMMode( short iCGMMode );

protected:

  CATSkinHolePlugImpl * GetSkinHolePlugImpl() const;
};

// ----------------------
// CATCreateSkinHolePlug
// ----------------------
ExportedByAdvTrimOpe CATSkinHolePlugOpe * CATCreateSkinHolePlugOpe(CATGeoFactory & iFactory,
                                                                   CATTopData    & iTopData,
                                                                   CATBody       & iReferenceBody);

ExportedByAdvTrimOpe CATSkinHolePlugOpe * CATCreateSkinHolePlugOpe( CATGeoFactory          & iFactory,
                                                                    CATTopData             & iTopData,
                                                                    CATPersistentBody      & iInputPersistentBody,
                                                                    CATPersistentCellInfra & iPersistentCellInfra );



#endif
