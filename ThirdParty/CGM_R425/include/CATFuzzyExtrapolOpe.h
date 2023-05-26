// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : ZUT
//
// DESCRIPTION  : Extrapolation of skins.
//                Some borders and internal details may be skipped.
//
//=============================================================================
// Creation ZUT January 2009
//=============================================================================

#ifndef CATFuzzyExtrapolOpe_H
#define CATFuzzyExtrapolOpe_H

#include "AdvTrimOpe.h"
#include "CATTopOperator.h"

#include "CATMathDef.h"
#include "ListPOfCATVertex.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "CATPersistentOperator.h"

class CATString;
class CATBody;
class CATPersistentBody;
class CATPersistentCellInfra;
class CATEdge;
class CATShell;

class CATFuzzyExtrapolImpl;

/**
 * Class representing an operator that extrapolates a shell body with respect to surface curvature.
 * Some border and internal details may be skipped for robustness purpose.
 *<br>The edges to be extrapolated must belong to the boundary of the shell.
 *<br>The extrapolation values can be different for each edge. A positive
 * value defines an extrapolation along the outside direction of the shell.
 *<br>Target bodies can be defined instead of distances.
 *<br>The extrapolation gives a result that is continuous in curvature.
 * To use it:
 * <ul>
 * <li>Create it with the <tt>CATCreateFuzzyExtrapolOpe</tt> global function.
 * <li>Tune it with appropriate options, using the <tt>SetXxx</tt> methods. 
 * <li>Run it
 * <li>Get the resulting body, using the <tt>GetResult</tt> method. If you do not want 
 * to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
 * geometric factory, after the operator deletion.
 *<li>Delete it after use  with the usual C++ <tt>delete</tt> operator.
 *</ul> 
 */
class ExportedByAdvTrimOpe CATFuzzyExtrapolOpe : public CATPersistentOperator
{
  CATCGMVirtualDeclareClass(CATFuzzyExtrapolOpe);

public:

  /**
  * Destructor
  */
  virtual ~CATFuzzyExtrapolOpe();

  /**
  * Appends a list of edges to extrapolate.
  * It replaces the current value of an already selected edges by <tt>iExtrapolValue</tt>.
  * @param iBoundaryEdges
  * The list of edges to append.
  * @param iExtrapolValue
  * The common extrapolation value for all the edges of the <tt>iBoundaryEdges</tt> list.
  */
  void Append( const CATLISTP(CATEdge) & iBoundaryEdges, CATLength iExtrapolValue ) ;

  /**
  * Appends an edge to extrapolate.
  * It replaces the current value of an already selected edges by <tt>iExtrapolValue</tt>.
  * @param iBoundaryEdge
  * The edge to append.
  * @param iExtrapolValue
  * The extrapolation value for the <tt>iBoundaryEdge</tt> edge.
  */
  void Append( CATEdge * iBoundaryEdge, CATLength iExtrapolValue ) ;

  /**
  * Appends a target body for a boundary edge
  * so that the boundary will be extrapolated enough to reach the body.
  * Several target bodies can be defined for a same edge.
  * @param iBoundaryEdge
  * The edge to append
  * @param iTargetBody
  * A target body for <tt>iBoundaryEdge</tt>.
  * @param iTargetShell
  * A specific shell of the iTargetBody
  */
  void Append( CATEdge * iBoundaryEdge, CATBody * iTargetBody, CATShell * iTargetShell = NULL);

  /**
  * Appends a target body for a list of edges
  * so that the boundary will be extrapolated enough to reach the body.
  * Several target bodies can be defined for a same edge.
  * @param iBoundaryEdges
  * The list of edges to append
  * @param iTargetBody
  * A target body for edges from <tt>iBoundaryEdges</tt> list.
  * @param iTargetShell
  * A specific shell of the iTargetBody
  */
  void Append( const CATLISTP(CATEdge) & iBoundaryEdges, CATBody * iTargetBody, CATShell * iTargetShell = NULL);
  
  /**
  * Appends a wire to extrapolate.
  * It appends a wire to extrapolate of <tt>iExtrapolValue</tt>.
  * @param iWire
  * The wire body to extrapolate
  * @param iExtrapolValue
  * The extrapolation value for the <tt>iWire</tt> wire.
  */
  void Append( CATBody * iWire, CATLength iExtrapolValue);

    /**
  * Appends a target body for a wire input
  * so that the boundary will be extrapolated enough to reach the body.
  * Several target bodies can be defined for a same wire.
  * @param iWire
  * The wire body to extrapolate
  * @param iTargetBody
  * A target body for <tt>iWire</tt>.
  * @param iTargetShell
  * A specific shell of the iTargetBody
  */
  void Append( CATBody * iWire, CATBody * iTargetBody, CATShell * iTargetShell = NULL);

  /**
  * Selects all the edges of the shell boundary and sets to them a common extrapolation value.
  * @param iExtrapolValue
  * The new current extrapolation value for all the edges of the shell boundary.
  * Only for input given as edges
  */
  void SetDefaultExtrapolationValue( CATLength iExtrapolValue );

  /**
  * Selects all the edges of the shell boundary and add to them a common target Body.
  * @param iTargetBody
  * The new current target body for all the edges of the shell boundary.
  * Only for input given as edges
  */
  void AppendDefault( CATBody * iTargetBody );

  /**
  * Defines the propagation mode of the extrapolation value.
  * @param iPropagationMode
  * <dl>
  * <dt><tt>0</tt></dt><dd> No propagation of the extrapolation value.
  * <dt><tt>1</tt></dt><dd> Defines the automatic definition of the extrapolation value on an edge
  * to the one of its tangential adjacent edges.
  * This mode is used by default at the creation of the operator.
  * </dl>
  * Only for input given as edges
  */
  void SetPropagationMode( short iPropagationMode );

  /**
  * Defines whether the result should contain the whole extrapolated surface or only the extrapolated area.
  * @param iKeepOnlyExtrapolatedArea
  *<dl>
  *<dt><tt>0</tt></dt><dd> The whole extrapolated surface is returned.
  * This mode is used by default at the creation of the operator.
  *<dt><tt>1</tt></dt><dd> The result contains the extrapolated area only.
  *</dl>
  */
  void SetKeepOnlyExtrapolatedArea( short iKeepOnlyExtrapolatedArea );

  /**
  * Defines whether holes should be removed from the skin or not
  * @param iRemoveHoles
  *<dl>
  *<dt><tt>0</tt></dt><dd> No special treatment for holes
  * This mode is used by default at the creation of the operator.
  *<dt><tt>1</tt></dt><dd> All detected holes are removed from the skin.
  *<dt><tt>2</tt></dt><dd> Remove holes whose boundaries include specified edges to extrapolate.
  *<dt><tt>3</tt></dt><dd> Leave intact holes whose boundaries are made of edges to extrapolate.
  * The other holes remain intact too.
  *</dl>
  * Only for C2 continuity
  */
  void SetRemoveHoles( short iRemoveHoles );

  /**
  * Enables or disables twist detection.
  * @param iTwistDetection
  * <dl>
  * <dt><tt>0</tt></dt><dd> Twist detection is disabled : result skin may lie on twisted surfaces.
  * This mode is used by default at the creation of the operator.
  * <dt><tt>1</tt></dt><dd> Twist detection is enabled : extrapolation is not possible if a twist is detected.
  * </dl>
  */
  void SetTwistDetection(short iTwistDetection);

  /**
  * @nodoc
  * Defines whether UpThrough TargetBody option must be activated or not
  * @param iUpThroughBody
  *<dl>
  *<dt><tt>0</tt></dt><dd> Usual Run.
  * This mode is used by default at the creation of the operator.
  *<dt><tt>1</tt></dt><dd> Extrapol through all target if input laid down on target
  *</dl>
  */
  void SetUpThroughBody( short iUpThroughBody );

  /**
  * Enables or disables deviation checking.
  * @param iWithDeviation
  * <dl>
  * <dt><tt>1</tt><dd> Check if surface deviations are below maximum value.
  * This value can be provided by the user through <tt>SetDeviationAllowed</tt> method.
  * Default value is the factory resolution
  * <dt><tt>0</tt><dd> No deviation checking is performed
  * This mode is used by default at the creation of the operator.
  * </dl>
  * Only for C2 continuity
  **/

  void SetDeviationMode(short iDeviationMode);

  /**
  * Defines the maximum deviation value allowed by the user.
  * @param iDeviation
  * The value of the deviation. This value must be positive.
  * Only for C2 continuity
  */
  void SetDeviationAllowed(CATLength iMaxDeviation);

  /**
  * Enables or disables Tolerance checking.
  * @param itoleranceMode
  * <dl>
  * <dt><tt>1</tt><dd> Check if wire target for extrapol is facing input skin at given tolerance
  * This value can be provided by the user through <tt>SetToleranceAllowed</tt> method.
  * Default value is the factory resolution * 100
  * <dt><tt>0</tt><dd> No tolerance checking is performed under resolution * 100
  * This mode is used by default at the creation of the operator.
  * </dl>
  **/
  void SetToleranceModeForWireTarget(short itoleranceMode);

  /**
  * Defines the maximum tolerance value to consider that the wire target is facing the input body
  * @param iMaxTolerance
  * The value of the tolerance. This value must be positive.
  * Default Value is 100 * factory resolution. Possible value between 0 and 100 * factory resolution
  */
  void SetToleranceAllowedForWireTarget(CATLength iMaxTolerance);

  /**
  * Defines the extrapolation behaviour around the extremities of the selected boundaries
  * @param iExtremitiesMode
  * <dl>
  * <dt><tt>0</tt></dt><dd> The extrapolation sides are tangent to the edges adjacent to the surface boundary
  *  This mode is used by default at the creation of the operator.
  * <dt><tt>1</tt></dt><dd> The extrapolation sides are normal to the original surface boundary.
  * </dl>
  */
  void SetExtremitiesMode( short iExtremitiesMode );

  /**
  * Enables or disables skin relimitation along target bodies.
  * @param iTrimmingMode
  *<dl>
  *<dt><tt>0</tt></dt><dd> The skin is extrapolated enough to reach the target bodies but no trimming is performed.
  * This mode is used by default at the creation of the operator.
  *<dt><tt>1</tt></dt><dd> The extrapolated area is relimited onto the target bodies.
  *<dt><tt>2</tt></dt><dd> The whole extrapolated skin is relimited onto the target bodies.
  *<dt><tt>3</tt></dt><dd> The body is relimited even if the extrapolation failed (InputBody) ONLY WITH VOLUMIC TARGET
  *</dl>
  */
  void SetTargetBodiesTrimmingMode( short iTrimmingMode );

  /**
  * Allows to choose the side kept after trimming (with a volumic target only)
  * @param iSideToKeep
  *<dl>
  *<dt><tt>0</tt></dt><dd> The choice is made automatically.
  * This mode is used by default at the creation of the operator.
  *<dt><tt>1</tt></dt><dd> The skin inside the volume is kept
  *<dt><tt>2</tt></dt><dd> The skin outside the volume is kept
  *</dl>
  */
  void SetSideToKeepAfterTrim( short iSideToKeep );

  /** 
  * Defines the level of approximation allowed for the reconstruction of the surfaces boundaries.
  * The more this level is high, the more boundaries can be approximated and the more robust is the operation.
  * @param iApproximateExtrapolationLevel
  * <dl>
  * <dt><tt>0</tt></dt><dd> The shape of extrapolated boundaries is preserved. Extrapolation distance is respected.
  *  This mode is used by default at the creation of the operator.
  * <dt><tt>1</tt></dt><dd> Some edges from the boundary may be merged and extrapolation distance may not be respected.
  * </dl>
  * Only for C2 continuity
  */
  void SetApproximateExtrapolationLevel(short iApproximateExtrapolationLevel);

  /**
  * @nocgmitf
  * Specific for special mono-surface treatments :
  * Defines expected minimum scale ratio between input surface and output extrapolated surface.
  * Default value is 1.0
  * Only for C2 continuity
  */
  void SetMinScaleRatio( double iMinScaleRatio );

  /**
  * Defines the type of continuity for the extrapolation
  * @param iExtremitiesMode
  * <dl>
  * <dt><tt>1</tt></dt><dd> Tangent mode : G1 continuity
  * <dt><tt>2</tt></dt><dd> Curvature mode : C2 continuity. 
  * This mode is used by default at the creation of the operator.
  * </dl>
  */
  void SetContinuityMode( short iContinuityMode );

  /**
  * @nocgmitf
  * If first attempt of extrapolation fails,
  * then allow the operator a second try with lower extrapolation lengths.
  * This mode is disabled by default at the creation of the operator.
  * Only for C2 continuity
  */
  void SetAllowBackupExtrapolation( short iAllowBackupExtrapolation );

  /**
  * @nodoc
  * Defines the caller when there are specific treatment required 
  * for this caller.
  * @param iSpecificCallerMode
  * <dl>
  * <dt><tt>0</tt></dt><dd> No specific treatment (default)
  * <dt><tt>1</tt></dt><dd> Special Treatment for AutoMidSurface
  * </dl>
  */
  void SetSpecificCallerMode( short iSpecificCallerMode );

  /**
  * @nodoc
  * Specifies one or several internal edges in order to determine a direction for the extrapolation.
  * The edges will be extrapolated in tangency. It is possible to associate a vertex to each edge
  * to give an orientation to extrapolation.
  * @param iEdgesForDirection
  * The Edges to determine direction for extrapolation.
  * @param iVertexOfEdges
  * The Vertex associated to each Edge for orientation. 
  * Only for G1 continuity
  */
  void SetDirectionnalEdge(const CATLISTP(CATEdge)& iEdgesForDirection, const CATLISTP(CATVertex)& iVertexOfEdges);

  /** @nocgmitf Runs <tt>this</tt> operator */
  int RunOperator();

  /** @nocgmitf */
  void SetKeepBorderEdgeCurves();

  /** @nodoc */
  void SetPartialExtrapolationAllowed( short iPartialExtrapolationAllowed );

  /**
  * @nodoc
  * Enables or disables local mode.
  * @param iLocalMode
  * <dl>
  * <dt><tt>1</tt><dd> Local run enabled.
  * <dt><tt>0</tt><dd> Local mode disabled.
  * </dl>
  */
  void SetLocalMode( short iLocalMode = 1 );

  /** @nocgmitf */
  void SetCGMMode( short iCGMMode );

  /** @nocgmitf Pour AutoFillet */
  void GetReverseMatterOutputFaces( CATLISTP(CATFace) & oReverseMatterOutputFaces );

  /** @nocgmitf */
  void GetTrickyFaces( CATLISTP(CATFace) & oTrickyFaces );

  /** @nodoc */
  void GetTrickyEdges( CATLISTP(CATEdge) & oTrickyEdges );

  //------------------
  // CGMReplay methods
  //------------------
  /** @nocgmitf ID pour CGMReplay */
  static const CATString * GetDefaultOperatorId();

  /** @nocgmitf ID pour CGMReplay */
  const CATString * GetOperatorId();

  /** @nocgmitf Declaration integre au CGMReplay */
  CATExtCGMReplay * IsRecordable( short & LevelOfRuntime, short &VersionOfStream );

  /** @nocgmitf Pour CGMReplay */
  void WriteInput( CATCGMStream  & Str );

  /** @nocgmitf Pour CGMReplay */
  void ReadInput( CATCGMStream  & ioStr, int VersionOfStream);

  /** @nocgmitf Pour CGMReplay */
  void Dump( CATCGMOutput& os ) ;

  /** @nocgmitf ID pour CGMReplay */
  void DumpOutput( CATCGMOutput &os );

  /** @nocgmitf Definition des Objets  ...*/
  void RequireDefinitionOfInputAndOutputObjects();

protected:

  CATFuzzyExtrapolImpl * GetFuzzyExtrapolImpl();

  /**
  * Protected constructor : Do not call directly.
  * Use CATCreateFuzzyExtrapolOpe() instead.
  */
  CATFuzzyExtrapolOpe( CATGeoFactory         * iFactory,
                       CATTopData            * iTopData,
                       CATFuzzyExtrapolImpl  * iImpl );

  //------------------------------------------------------------------------------
  // Forbidden (Declared but not Defined) : Copy constructor & assignment operator
  //------------------------------------------------------------------------------
  CATFuzzyExtrapolOpe ( const CATFuzzyExtrapolOpe & );            // Not Implemented
  CATFuzzyExtrapolOpe & operator=( const CATFuzzyExtrapolOpe & ); // Not Implemented

  //-----------------
  // Friend functions
  //-----------------
  friend ExportedByAdvTrimOpe CATFuzzyExtrapolOpe * CATCreateFuzzyExtrapolOpe( CATGeoFactory & iFactory, CATTopData & iTopData, CATBody & iReferenceBody );
  friend ExportedByAdvTrimOpe CATFuzzyExtrapolOpe * CATCreateFuzzyExtrapolOpe( CATGeoFactory & iFactory, CATTopData & iTopData, CATPersistentBody & iReferenceBody, CATPersistentCellInfra & iPersistentInfra );
};

// ----------------------
// CATCreateFuzzyExtrapol
// ----------------------
ExportedByAdvTrimOpe CATFuzzyExtrapolOpe * CATCreateFuzzyExtrapolOpe( CATGeoFactory & iFactory,
                                                                      CATTopData    & iTopData,
                                                                      CATBody       & iReferenceBody );

/** @nocgmitf */
ExportedByAdvTrimOpe CATFuzzyExtrapolOpe * CATCreateFuzzyExtrapolOpe( CATGeoFactory           & iFactory,
                                                                      CATTopData              & iTopData,
                                                                      CATPersistentBody       & iReferenceBody,
                                                                      CATPersistentCellInfra  & iPersistentInfra );

#endif /* CATFuzzyExtrapolOpe_H */
