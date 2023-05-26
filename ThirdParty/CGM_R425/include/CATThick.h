#ifndef CATThick_H
#define CATThick_H

// COPYRIGHT DASSAULT SYSTEMES  1999

#include "CATMathDef.h"
#include "CATMathInline.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "CATListOfCATCells.h"
#include "CATListOfDouble.h"
#include "CATListOfInt.h"
#include "Thick.h"
#include "CATGeoToTopOperator.h"
#include "CATTopOperator.h"
#include "CATString.h"

#define THICK_FASTRUN_FOURRUNFORONEFAST 1

class CATOpThick;
class CATBody;
class CATFace;
class CATEdge;
class CATVertex;
class CATCurve;
class CATBaseHealing;
class CATGeoFactory;
class CATMathPoint;
class CATCGMJournalList;
class CATCGMJournalInfo;
class CATCGMOutput;
class CATError;
class CATlsoProgressBarManager;
class CATContextForFastRun;
class CATThickContextForFastRun;
class CAThkBackupDataFastRun;

/**
 * Class defining the topological operator that offsets a body.
 * <br>The CATThick operator does not change the dimension of the body: a volume becomes a volume,
 * a skin becomes a skin. It is possible to choose the faces to offset, and the offset values
 * can change from one face to another. The offset specification is propagated on the adjacent faces,
 * if their common edge is smooth. In case of conflict, the last specification is used.
 * <br> The offset values must be consistent with the curvature of the input surface, to avoid
 * twisted geometry.
 *<br>
 * The CATThick operator follows the global frame of the topological operators 
 * and satisfies the smart mechanism: the
 * input body is not modified. A new resulting body is created, 
 * sharing as much data as possible with the input body. A CATThick operator is not streamble.
 * To use it:
 *<ul>
 * <li>Create it with the constructor
 * <li>Tune it with appropriate options, using the <tt>SetXxx</tt> or <tt>Append</tt> methods.
 * <li>Run it
 * <li>Get the result with the <tt>GetResult</tt> method. If you do not want 
 * to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
 * geometric factory, after the operator deletion.
 *<li><tt>delete</tt> it after use.
 *</ul> 
 */  
class ExportedByThick CATThick : public CATTopOperator
{

  CATCGMVirtualDeclareClass(CATThick);
public:

/**
	* Constructs a CATThick operator.
	* @param iBody
	* The pointer to the body to offset. 
	* @param iTopData
	*/
  CATThick( CATTopData * iTopData, CATBody* iBody, short iExtrapolMode=0 );

/**
  * Do not use. 
	*/
  CATThick( CATBody* iBody, CATCGMJournalList * iJournal = NULL );

/**
 * Copy constructor.
 * Do not use, it throws an error.
 */
  CATThick(CATThick& iOperator);

/**
* @nodoc 
 * Affectation operator.
 * Do not use, it throws an error.
 */
  CATThick& operator=(const CATThick & iOperator);

/**
 * Appends a list of faces to offset by a common offset value.
 * @param iFacesToOffset
 * The list of pointers to faces to offset with <tt>iOffsetValue</tt>.
 * @param iOffsetValue
 * The offset value.
 */
  void Append(const CATLISTP(CATFace) &iFacesToOffset, CATLength iOffsetValue ) ;

/**
 * Appends a face to offset.
 * @param iFace
 * The pointer to the face to offset with <tt>iOffsetValue</tt>.
 * @param iOffsetValue
 * The offset value.
 */
  void Append(CATFace* iFaceToOffset, CATLength iOffsetValue ) ;

/**
 * Defines the default offset value for all the faces of the input body.
 * <br>The <tt>Append</tt> methods can still be used after this method to
 * locally modify the default on some faces.
 * @param iOffsetValue
 * The default offset value.
 */
  void SetDefaultOffsetValue( CATLength iOffsetValue );

/**
  * Defines how borders are transformed in the neighborhood of sharp edges.
  * @param iSharpBorderOptimisation
  * <br><b>Legal values:</b>
  * <dl><dt>0</dt><dd>Optimization not required
  * <dt>1</dt><dd>Optimization required (Skin handled like a Volume)
  * </dl>
  */
 void SetSharpBorderMode(short iSharpBorderOptimisation);

/**
  * Defines if procedural Offset surfaces must be approximated and
  * replaced by NurbsSurface
	* @param iApproxOffsetMode
	* <br><b>Legal values:</b>
  * <dl><dt>0</dt><dd>Approximation not required
  * <dt>1</dt><dd>Approximation required in C1 mode
  * <dt>2</dt><dd>Approximation required in C2 mode
  * @param iPostProRequired
  * <br><b>Legal values:</b>
  * <dl><dt>0</dt><dd>Approximation required during Offset algorithm
  * <dt>1</dt><dd>Approximation required after Offset algorithm
  * </dl>
  */
 void SetApproxOffsetMode(short iApproxOffsetMode, short iPostProRequired=1);
 
/**
  * Defines the tolerance for C1 approximation 
	* @param iTolC1
  * </dl>
  */
 void SetToleranceForApproxC1(double iTolC1);

/**
  * Defines the tolerance for C2 approximation 
	* @param iTolC2
  * </dl>
  */
 void SetToleranceForApproxC2(double iTolC2);

/**
 * @nodoc
 * Internal use. 
 */
  void SetPropagationOff();

/**
 * @nodoc	 
 * Internal use.
 */
  void SetPropagationOn();

/**
 * @nodoc	 
 * Internal use.
 */
  void SetHealingGeoExclusiveManager(CATBaseHealing * iHealingGeoToManageExclusively);

/**
 * @nodoc
 * @nocgmitf
 * Internal use.
 */
  void SetJournalForBioffsetFaceFromInternalEdge(short iJournalForBioffsetFace);

  /**
  * Appends a face to offset in UpTo mode.
  * @param iFace
  * The pointer to the face to offset in direction of <tt>iTargetBody</tt>.
  * @param iTargetBody
  * The pointer to the target body.
  */
  void Append(CATFace* iOffsetFace, CATBody * iTargetBody);

  /**
 * @nodoc
 * @nocgmitf
 * Internal use.
 */
  void Append(CATLISTP(CATFace) &iOffsetFaces, CATBody * iTargetBody);

/**
 * Defines the state of the resulting body.
 * @param iOnOrOff
 * The state of the resulting body. 
 */
  void SetFreezeMode(CATBodyFreezeMode iOnOrOff);

  /**
 * @nodoc
 */
  void SetSimplificationMode(short iSimplificationMode);

//======================================================================================================
// SkinExtrapolation only
// *=*=*=*=*=*=*=*=*=*=*=*

/**
 * Appends a list of edges to extrapolate.
 * It replaces the current value of an already selected edges by <tt>iExtrapolValue</tt>.
 * @param iBoundaryEdges
 * The list of edges to append.
 * @param iExtrapolValue
 * The common extrapolation value for all the edges of the <tt>iBoundaryEdges</tt> list.
 */
  void Append(const CATLISTP(CATEdge) &iBoundaryEdges, CATLength iExtrapolValue ) ;

/**
 * Appends an edge to extrapolate.
 * It replaces the current value of an already selected edges by <tt>iExtrapolValue</tt>.
 * @param iBoundaryEdge
 * The edge to append.
 * @param iExtrapolValue
 * The extrapolation value for the <tt>iBoundaryEdge</tt> edge.
 */
  void Append(CATEdge* iBoundaryEdge, CATLength iExtrapolValue ) ;

/**
 * Selects all the edges of the shell boundary and sets to them a common extrapolation value.
 * @param iExtrapolValue
 * The new current extrapolation value of the already selected edges.
 */
  void SetDefaultExtrapolationValue( CATLength iExtrapolValue);

/**
 * Defines the relimitation mode from all boundary extremities in SkinExtrapolation operator.
 * @param iExtremitiesMode
 *<dl>
 *<dt><tt>0</tt></dt><dd> Extrapolate adjacent edges to cut the offset boundary.
 * This mode is used by default at the creation of the operator.
 *<dt><tt>1</tt></dt><dd> Add junction edges in normal direction of boundary extremities
 *</dl>
 */
  void SetExtremitiesMode(int iExtremitiesMode);

/**
 * Defines the boundary G0 derivation behaviour in Offset/ThickenOp operator.
 * @param iForceG0Distortion
 *<dl>
 *<dt><tt>0</tt></dt><dd> Natural G0 derivation : each edge of the boundary is offset 
 *                        according to its normal support direction, then junction edges 
 *                        ared added to close the offset boundary when adjacent edges 
 *                        aren't connected to each others anymore after offset.
 * This mode is used by default at the creation of the operator.
 *<dt><tt>1</tt></dt><dd> Force G0 distortion : each edge of the boundary is offset
 *                        according to normal support direction, then a distortion is applied
 *                        to make adjacent edges still connected to each others, 
 *                        without any junction edge.
 *</dl>
 * @param iDistortionOption
 *<dl>
 *<dt><tt> -1 </tt></dt><dd>    MIN : distortion is drived by surface area minimisation,
 *                                    only one boundary edge is modified by vertex.
 *<dt><tt>  0 </tt></dt><dd> MEDIUM : distortion is computed on the 2 adjacent boundary
 *                                    edges around each boundary vertex
 * This mode is used by default at the creation of the operator.
 *<dt><tt> +1 </tt></dt><dd>    MAX : distortion is drived by surface area maximisation,
 *                                    only one boundary edge is modified by vertex.
 *</dl>
 */
  void SetG0DerivationBehaviourOnBoundary(int iForceG0Distortion, int iDistortionOption=0);

  /**
  * @nodoc @nocgmitf
  * Do not use - under developement.
  **/
  void SetG0Hermetization(short iG0Hermetization);

  /**
  * @nodoc @nocgmitf
  * Do not use - under developement.
  **/
  void SetG0HermetizationTarget(double iG0HermetizationTargetValue);

  /**
  * @nodoc @nocgmitf
  * Do not use - under developement.
  **/
  void SetG1Smoothing(short iG1Smoothing);

  /**
  * @nodoc @nocgmitf
  * Do not use - under developement.
  **/
  void SetG1SmoothingTarget(CATAngle iG1SmoothingTargetValue);

  void SetPartialExtrapolationAllowed(short iPartialExtrapolationAllowed);

/**
 * @nodoc
 * Mode de reconstruction robuste des bords de skin extrapolee
 */
  void SetApproximateExtrapolationLevel(short iApproximateExtrapolationLevel);

/**
 * Defines the specification of relimitation from one boundary extremity.
 * @param iVtxExtremity
 * The vertex extremity of the boundary to offset
 * @param iSpecifiedMode
 *<dl>
 *<dt><tt>0</tt></dt><dd> Extrapolate adjacent edge from iVtxExtremity to cut the offset boundary.
 * This mode is used by default at the creation of the operator.
 *<dt><tt>1</tt></dt><dd> Add junction edges from iVtxExtremity in specified direction.
 *</dl>
 * @param iGuideCurve
 * The Curve which defines the specified direction. 
 * <br> This curve has to be lying on the boundary support to extrapolate.
 * <br> If param iGuideCurve is NULL, the specified direction is normal to the boundary from iVtxExtremity
 */
  void SetExtremitySpecification(CATVertex * iVtxExtremity,
                                 int iSpecifiedMode, 
                                 CATCurve * iGuideCurve=NULL);

/**
 * @nodoc
 * Defines whether the result should contain the whole extrapolated surface or only the extrapolated area.
 * @param iKeepOnlyExtrapolatedArea
 *<dl>
 *<dt><tt>0</tt></dt><dd> The whole extrapolated surface is returned.
 * This mode is used by default at the creation of the operator.
 *<dt><tt>1</tt></dt><dd> The result contains the extrapolated area only.
 *</dl>
 */
  void SetKeepOnlyExtrapolatedArea(short iKeepOnlyExtrapolatedArea);

//======================================================================================================

  
  // Destructor (memory is freed and model is cleaned, the resulting body is kept.
  virtual ~CATThick();

  /**
	 * Runs <tt>this</tt> operator.
	 */
  int Run() ;

 /**
 * Returns the pointer to the resulting body.
 * @return
 * The pointer to the resulting body, <tt>NULL</tt> if the operation failed. 
 * If you do not want to keep the resulting body, 
 * use the @href CATICGMContainer#Remove method to remove it from the 
 * geometric factory, after the operator deletion.
 */
  CATBody* GetResult() ;

  void GetEdgesToExtrapolAfterPropagation(CATLISTP(CATEdge) &oEdgesAfterPropag, 
    CATListOfDouble &oValuesAfterPropag);

/**
 * Modifies the type of the journal items created during <tt>this</tt> CATThick operation.
 * @param iTypeForFaceCreation
 * The item type.
 * @param iAdditionalInfo
 * The pointer to an additional information. If <tt>NULL</tt>, no additional information is added.
 */
  void SetJournalTypeForFaceOffset(CATCGMJournal::Type  iTypeForFaceCreation,
                                   CATCGMJournalInfo  * iAdditionalInfo=NULL);

  /**
  * @nodoc
  * Enables or disables twist detection.
  * @param iTwistDetection
  *<dl>
  *<dt><tt>0</tt></dt><dd> Twist detection is disabled : result body may lie on twisted surfaces.
  * This mode is used by default at the creation of the operator.
  *<dt><tt>1</tt></dt><dd> Twist detection is enabled : twists are not allowed on the result body.
  *</dl>
  */
  void SetTwistDetection(short iTwistDetection);

  /**
  * @nodoc
  * Enables or disables deviation checking.
  * @param iWithDeviation
  * <dl>
  * <dt><tt>1</tt><dd> Check if surface deviations are below maximum value.
  * This value can be provided by the user through <tt>SetDeviationAllowed</tt> method.
  * Default value is the factory resolution
  * <dt><tt>0</tt><dd> No deviation checking is performed
  * This mode is used by default at the creation of the operator.
  * </dl>
  **/
  void SetDeviationMode(short iDeviationMode);

  /**
  * @nodoc
  * Defines the maximum deviation value allowed by the user.
  * @param iDeviation
  * The value of the deviation. This value must be positive.
  */
  void SetDeviationAllowed(CATLength iMaxDeviation);

  /**
  * @nodoc 
  * Collision reseach mode.
  * @param iCollisionLevel
  *<dl>
  *<dt><tt>0</tt></dt><dd> Local collisions research only (perfos default mode). 
  *<dt><tt>1</tt></dt><dd> Global collisions research (costly).
  *<dt><tt>2</tt></dt><dd> No collision research (cheap, isotopological run).
  *</dl>
  */
  void SetCollisionResearch(short iCollisionLevel);


/**
 * @nodoc
 * Internal use.
 */
  void SetFinalDimension(short iFinalDimension);

/**
 * @nodoc
 * Internal use.
 */
  void SetThickBoundaryMappingRequired(short iThickBoundaryMappingRequired);

/**
 * @nodoc
 * Internal use.
 */
  void SetExtrapolationMode(short iExtrapolMode);

  /**
 * @nodoc
 * Internal use.
 */
  INLINE CATBody* GetInitialBody() const;

/**
 * @nodoc
 * @param iFacesToRemove
 * 
 */
  void SetMandatoryFacesToRemove(const CATLISTP(CATFace) &iFacesToRemove, short iAllOffsetAreNull=0);

  /**
 * @nodoc
 * @param iFacesToRemove
 * 
 */
  void SetCandidateFacesToRemove(const CATLISTP(CATFace) &iFacesToRemove, short iAllOffsetAreNull=0);

  /**
 * @nodoc
 * Internal use.
 * 
 */
  void SetKeepBorderEdgeCurves();

/**
 * @nodoc
 * @param oTrickyFaces
 * 
 */
  void GetTrickyFaces(CATLISTP(CATFace) &oTrickyFaces, short iMixRegulDiagForbidden=0);

  /**
  * @nodoc
  * Internal use.
  * 
  */
  void GetAllTrickyEdges(CATLISTP(CATEdge) &oAllTrickyEdges);

  /**
 * @nodoc
 * @param oFacesToIgnore
 * 
 */
  void GetFacesToIgnore(CATLISTP(CATFace) &oFacesToIgnore);

/**
 * @nodoc
 * @param oFacesToRegularise
 * @param oDiag
 * <br><b>Legal values:</b>
 * <dl><dt>0</dt><dd>Regularisation not required [forbidden output value]
 * <dt>1</dt><dd>Optimization required for local curvature problem
 * <dt>2</dt><dd>Optimization required for singular point
 * <dt>3</dt><dd>Optimization required for extrapolation failure
 * </dl>
 */
  void GetFacesToRegularise(CATLISTP(CATFace) &oFacesToRegularise, CATListOfInt &oDiag);

  // nodoc
  void GetReverseMatterOutputFaces(CATLISTP(CATFace) & oReverseMatterOutputFaces);

  // nodoc
  void GetNotInverseRazorBladeFaces(CATLISTP(CATFace) &oNotInverseRazorBladeFaces);

  // nodoc
  void GetInitReverseMatterFaces(CATLISTP(CATFace) &oInitReverseMatterFaces);

  
  //Methode d'acces a la liste des Aretes de decrochement (HookingEdge)pour le traitement de la G0 derivation (fkj)
  ListPOfCATEdge& GetHookingEdgesList();
  
  // 
  static CATBoolean GetErrorLocation(CATDomain* iDomain, CATMathPoint& oLocation);

  /** @nodoc  */
  void SetUpToMode(short iUpToMode);

  /** @nodoc  */
  void SetDiffMode(short iDiffMode);


  //-----------------------------------------------------------------------
  //- Gestion pour CGMReplay
  //-----------------------------------------------------------------------  
   /** @nodoc @nocgmitf definition des Objets  ...*/
   void RequireDefinitionOfInputAndOutputObjects();

   /** @nodoc @nocgmitf declaration integre au CGMReplay */
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);

  /** @nodoc @nocgmitf ID pour CGMReplay */
  void DumpOutput(CATCGMOutput &os);

   /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual void WriteInput(CATCGMStream  & os);

     /** @nodoc @nocgmitf ID pour FastRun */
  virtual void WriteInputForFastRun(CATCGMStream  & os);

   /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual void Dump( CATCGMOutput& os ) ;

   /** @nodoc @nocgmitf ID pour CGMReplay */
  static const CATString * GetDefaultOperatorId() { return & _OperatorName; };


  /** @nodoc @nocgmitf */
  virtual void ReadInput(CATCGMStream  & ioStream,int VersionOfStream, short iNumReplayVersion=1);

	/**
	 * @nodoc @nocgmitf
	 * Internal use. internal run
	 */
  virtual int RunOperator();

  /**
	 * @nodoc @nocgmitf
	 */
  //void SetContextForFastRun(CATContextForFastRun * iContext);


  /**
	 * @nodoc @nocgmitf
	 */
  //CATContextForFastRun * GetContextForFastRun(CATBoolean iGetOnly = FALSE);
  
  /**
	 * @nodoc @nocgmitf
	 */
  /**
   * @return [out, IUnknown#Release]
   */
  CATThickContextForFastRun * GetThickContextForFastRun(CATBoolean iGetOnly = FALSE);

#if THICK_FASTRUN_FOURRUNFORONEFAST
  /** @nodoc @nocgmitf **/
  /* Pour FastRun FourRunForOneFast */
  void SetNewInput(CATBody* iNewInput, CATCGMJournalList* iModifJournal);

  /** @nodoc @nocgmitf **/
  CATBoolean GetDefaultOffset(double& oDefaultOffset); 
  
  /** @nodoc @nocgmitf **/
  void GetFacesToOffset(ListPOfCATFace&  oSpecialOffsetFaces,
                        CATListOfDouble& oSpecialOffsetValues);

  
  /** 
   * @nodoc @nocgmitf
   **/
  CATCGMOperator::CATCheckDiagnostic CheckInput(CATCGMOutput & os);
#endif
  

protected:

  /**
	 * @nodoc
	 * Internal use.  Append (or replace) specification for offseting or extrapolation.   
  */
  void CreateOffsetAndExtrapolAttribute();

  // Operator generic name 
  static CATString _OperatorName;

	/**
	 * @nodoc
	 * Internal use. Get Mapping between skin borders.
	 */
  void GetBorderMapping(CATListOfInt & oCCxSizes, CATListOfInt & oCycleSizes,
    CATLISTP(CATCell) & oInitBd, CATLISTP(CATCell) & oImageBd, 
    CATListOfInt & oImageStartCellNumber,
    CATListOfInt & oImageEndCellNumber) const;

	/**
	 * @nodoc
	 * Internal use. Data Initialisation called by constructors
	 */
  void InitThick(CATBody * iBody, short iExtrapolMode=0);

  /**
	 * @nodoc
	 * Internal use. Fast Update Data initialization.
	 */
  void InitFastRunData();

  /**
	 * @nodoc
	 * Internal use. Retrieve all boundary edges from the input skin
	 */
  void InitListOfBoundaryEdges();

  /**
	 * @nodoc
	 * Internal use.
	 */
  void UpdateInitError( CATError *& ioError );


	 /** @nodoc */
  CATBody       * _InitialBody;
	 /** @nodoc */
  CATLONG32       _NbDomains;
	 /** @nodoc */
  CATLONG32       _BodyDimension;

  // Propagation mode (0 = off, 1 = on)
	 /** @nodoc */
  short           _Propagation;

  // Main operator
	 /** @nodoc */
  CATOpThick    * _OpThick;

  CAThkBackupDataFastRun  *_BackUpData;

  // Should we freeze the output body?
	 /** @nodoc */
  CATBodyFreezeMode _freezeMode;

  // Boundary mapping required
  short _ThickBoundaryMappingRequired;

  // Extrapolation Mode
  short _ExtrapolationMode;

  // FastRun Allowed
  short _FastRunAllowed;

  // Log calls to SetJournalTypeForFaceInfo (for CGMReplay use)
  short                _JournalTypeHasBeenSet;
  CATCGMJournal::Type  _TypeForFaceCreation;

  // Information to add in topological journal events
	 /** @nodoc */
  CATCGMJournalInfo * _JournalInfo;


  // Local topological journal.
  CATCGMJournalList * _LocalJournal;

  // Error thrown during initialization
  CATError * _InitError;

  // Gestion des progress bars
  CATlsoProgressBarManager * _ProgressBarManager;

  // Edges bords de skin (Liste a usage interne)
  CATLISTP(CATCell) * _ListOfBoundaryEdges;

  /**
	 * @nodoc
	 * Internal use. Global function used to get border mapping.
	 */
  friend ExportedByThick 
  void GetSkinBorderMapping(const CATThick    * iOpe,
                            CATListOfInt      & oCCxSizes, 
                            CATListOfInt      & oCycleSizes,
                            CATLISTP(CATCell) & oInitBdCell, 
                            CATLISTP(CATCell) & oImageBdCell,
                            CATListOfInt      & oImageStartCellNumber, 
                            CATListOfInt      & oImageEndCellNumber);
  
	/**
	 * @nodoc
	 * Internal use. Global function used to merge two border-mappings.
	 */
  friend ExportedByThick 
  void MergeMappings(const CATThick    * iOpe1,
                     const CATThick    * iOpe2,
                     CATListOfInt      & oCCxSizes,
                     CATListOfInt      & oCycleSizes,
                     CATLISTP(CATCell) & oInitBdCell,
                     CATLISTP(CATCell) & oImageBdCell,
                     CATListOfInt      & oImageStartCellNumber,
                     CATListOfInt      & oImageEndCellNumber,
                     short             & oMergeDiag);

  /**
	 * @nodoc
	 * Internal use. Global function used to get border mapping info.
	 */
  friend ExportedByThick 
  short IsIsoTopologicalBorderResult(const CATThick    * iOpe);
  
  /**
	 * @nodoc
	 * Internal use.
	 */
  friend CATCGMOutput& operator<< (CATCGMOutput& s, const CATThick& iOpe);

};

INLINE CATBody * CATThick::GetInitialBody() const { 
  return _InitialBody; }

#endif
