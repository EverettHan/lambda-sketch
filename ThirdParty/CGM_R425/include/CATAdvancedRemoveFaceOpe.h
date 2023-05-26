// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : ZUT
//
// DESCRIPTION  : CATAdvancedRemoveFaceOpe
//    Class defining a topological operator which removes a set of faces from a volume or a skin.
//
//=============================================================================
// Creation ZUT October 2012
//=============================================================================

#ifndef CATAdvancedRemoveFaceOpe_H
#define CATAdvancedRemoveFaceOpe_H

#include "CATPersistentOperator.h"
#include "CATCleverOffset.h"
#include "ListPOfCATFace.h"
#include "CATTopDefine.h"

class CATAdvancedRemoveFaceImpl;
class CATFace;
class CATBody;

/**
 * Class defining a topological operator which removes a set of faces from a volume or a skin.<br>
 * This operator does not change the dimension of the body: a volume remains a volume, a skin remains a skin.<br>
 * Note that the specified faces to be removed are not propagated, you need to provide a consistent set of faces.
 * The operation completes when the body can be closed by extrapolation of the faces which were adjacent to
 * the ones removed. Neighbouring faces extrapolations should not generate any tangency configuration.<br>
 * Unlike CATIPGMRemoveFace operator, CATIPGMPersistentOperator is able to apply special treatments
 * when it is judged necessary for the operation to succeed. For instance, local regularization can be applied
 * in order to avoid twisting of extrapolated geometries.<br>
 * To use this operator, you must:
 * <ul>
 * <li>Create it with the <tt>CATPGMCreateAdvancedRemoveFaceOpe</tt> global function
 * <li>Tune it with appropriate options, using the <tt>SetXxx</tt> or <tt>Append</tt> methods.
 * <li>Run it
 * <li>Get the result with the <tt>GetResult</tt> method. If you do not want to keep the resulting body,
 *    use the @href CATICGMContainer#Remove method to remove it from the geometric factory, after the operator deletion.
 * <li>Release the operator with the <tt>Release</tt> method after use.
 * </ul>
 */
class ExportedByCATCleverOffset CATAdvancedRemoveFaceOpe : public CATPersistentOperator
{
  CATCGMVirtualDeclareClass(CATAdvancedRemoveFaceOpe);

public:

  /**
  * Destructor
  */
  virtual ~CATAdvancedRemoveFaceOpe();

  /**
  * Appends a list of faces to be removed.
  * @param iFacesToRemove
  * The list of pointers to faces to remove.
  */
  void Append( const CATLISTP(CATFace) & iFacesToRemove );

  /**
  * Appends a limiting body related to a face to be partially removed.
  * The limiting body must be mono-shell mono-face.
  * @param iFaceToRemove
  * The face to relimit.
  * @param iLimitingBody
  * The limiting body.
  * @param iOri
  * The orientation related to the shell indicating the side to remove.
  */
  void AppendLimiting( CATFace * iFaceToRelimit, CATBody * iLimitingBody, CATOrientation iOri );

  /**
  * Allow a local smoothing of a tricky faces
  * @param iAllowLocalRegul
  * 0 - Regularization is disabled
  * 1 - Allow the operator to apply a regularization on the input body to avoid surfaces to twist when extrapolated.
  *     This mode is used by default at the creation of the operator.
  **/
  void SetAllowLocalRegularization( short iAllowLocalRegularization );

  /**
  * Sets the deviation allowed by the user.
  * @param iDeviation
  * Represents the maximum value of the deviation. This value must be positive.
  * Default value is 100 * factory resolution
  **/
  void SetDeviationAllowed( CATLength iDeviation );

  /**
  * Returns the complete list of faces when the operation cannot fully complete .
  * The list can include faces that could not be removed but also pathological closing faces.
  * @param oAllTrickyFaces
  * The list of tricky faces
  * @param oAllDiags
  * The list of diagnoses.
  */
  void GetAllTrickyFaces( CATLISTP(CATFace) & oAllTrickyFaces, CATListOfInt & oAllDiags );

  /**
  * @nodoc
  * Appends a list of faces allowed to be removed
  * @param iCandidateFace
  * The list of pointers to faces to potentially remove.
  */
  void AppendCandidate( const CATLISTP(CATFace) & iCandidateFaces );

  /**
  * @nodoc
  * Indicates that specified faces to remove are all fillets
  * @param iRemoveFilletsMode = 1 enables fillet dedicated treatments.
  * This mode is disabled by default.
  */
  void SetRemoveFilletsMode( short iRemoveFilletsMode = 1 );

  /**
  * @nodoc
  * Performance mode.
  * Allow the use of performance optimizations if operation is judged localized enough.
  * Available only for fillet removal.
  */
  void SetTryLocalRemoveFace( short iTryLocalRemoveFace );

  /**
  * @nodoc
  * Allow the operator to return a partial result if some subsets
  * of connected faces cannot be removed.
  * Tricky faces can be retrieved by calling GetAllTrickyFaces() method.
  */
  void SetPartialRemoveFaceAllowed( short iPartialRemoveFaceAllowed );

  /**
  * @nocgmitf
  * DO NOT USE
  * Roof Revit
  * @iRoofRevit = 1 to activate the option.
  */
  void SetRoofRevit( short iRoofRevit = 1 );

  /**
  * @nocgmitf
  * DO NOT USE
  * Indicates whether matter should be added (iMatterDirection = 1)
  * or removed (iMatterDirection = -1) to build the result body.
  */
  void SetMatterDirection( short iMatterDirection );

  /**
  * @nodoc
  * Enables or disables twist detection.
  * @param iTwistDetection
  * 0 - Twist detection is disabled : result body may lie on twisted surfaces.
  * 1 - Twist detection is enabled : face removal fails if at least one of the extrapolated surfaces is twisted
  *     This mode is used by default at the creation of the operator.
  */
  void SetTwistDetection( short iTwistDetection );

  /**
  * @nodoc
  * Indicates if the Delta of the RemoveFace has to be computed
  * /!\ Incompatible with Partial mode
  */
  void SetDeltaShapeComputation( short iDeltaShapeComputation );

  /**
  * @nocgmitf
  * Defines a maximum extrapolation length for surrounding edges and surfaces
  */
  void SetMaxExtrapolValue(double iMaxExtrapolValue);

  /**
   * Get the list of faces for which matter side has been reversed.
   * @param oReverseMatterOutputFaces
   * The list of reversed faces.
   */
   void GetReverseMatterOutputFaces(CATLISTP(CATFace) & oReverseMatterOutputFaces);

  //------------------
  // CGMREPLAY METHODS
  //------------------

  /** @nocgmitf ID for CGMReplay */
  static const CATString * GetDefaultOperatorId();

  /** @nocgmitf ID for CGMReplay */
  const CATString * GetOperatorId();

  /** @nocgmitf for  CGMReplay */
  CATExtCGMReplay * IsRecordable( short & oLevelOfRuntime, short & oVersionOfStream );

  /** @nocgmitf for CGMReplay */
  void WriteInput( CATCGMStream  & oStr );

  /** @nocgmitf for CGMReplay */
  void ReadInput( CATCGMStream  & iStr, int iVersionOfStream );

  /** @nocgmitf for CGMReplay */
  void Dump( CATCGMOutput & oStr ) ;

  /** @nocgmitf for CGMReplay */
  void DumpOutput( CATCGMOutput & oStr );

  /** @nocgmitf for CGMReplay */
  void RequireDefinitionOfInputAndOutputObjects();

  /** @nocgmitf for CGMReplay */
  void SetCGMMode( short iCGMMode );

protected:

  /**
  * Runs <tt>this</tt> operator.
  */
  int RunOperator();

  /**
  * Access to the implementation class
  */
  CATAdvancedRemoveFaceImpl * GetRemoveFaceImpl() const;

  /**
  * Protected constructor: use CATCreateAdvancedRemoveFaceOpe instead
  */
  CATAdvancedRemoveFaceOpe( CATGeoFactory             * iFactory,
                            CATTopData                * iTopData,
                            CATAdvancedRemoveFaceImpl * iImpl );

  //------------------------------------------------------------------------------
  // Forbidden (Declared but not Defined) : Copy constructor & assignment operator
  //------------------------------------------------------------------------------
  CATAdvancedRemoveFaceOpe ( const CATAdvancedRemoveFaceOpe & );            // Not Implemented
  CATAdvancedRemoveFaceOpe & operator=( const CATAdvancedRemoveFaceOpe & ); // Not Implemented

  //-----------------
  // FRIEND FUNCTIONS
  //-----------------
  friend ExportedByCATCleverOffset CATAdvancedRemoveFaceOpe * CATCreateAdvancedRemoveFaceOpe( CATGeoFactory & iFactory,
                                                                                              CATTopData    & iTopData,
                                                                                              CATBody       & iReferenceBody );
};

// ---------------------
// CATCreateRemoveFaceOpe
// ---------------------
ExportedByCATCleverOffset CATAdvancedRemoveFaceOpe * CATCreateAdvancedRemoveFaceOpe( CATGeoFactory * iFactory,
                                                                                     CATTopData    * iTopData,
                                                                                     CATBody       * iReferenceBody );

/** @nodoc */
ExportedByCATCleverOffset CATAdvancedRemoveFaceOpe * CATCreateAdvancedRemoveFaceOpe( CATGeoFactory & iFactory,
                                                                                     CATTopData    & iTopData,
                                                                                     CATBody       & iReferenceBody );

#endif /* CATAdvancedRemoveFaceOpe_H */
