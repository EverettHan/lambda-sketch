#ifndef CATThickPlus_H
#define CATThickPlus_H

// COPYRIGHT DASSAULT SYSTEMES  2010

#include "CATMathDef.h"
#include "ListPOfCATBody.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "CATListOfCATCells.h"
#include "CATListOfDouble.h"
#include "CATCleverOffset.h"
#include "CATGeoToTopOperator.h"
#include "CATTopOperator.h"
#include "CATCGMJournal.h"
#include "CATString.h"
#include "CATIACGMLevel.h" // CATIAR422 ...

class CATThick;
class CATRegul;
class CATBody;
class CATFace;
class CATEdge;
class CATGeoFactory;
class CATCGMJournalList;
class CATCGMJournalInfo;
class CATCGMOutput;
class CATBorderDerivationCleanerOpe;
class CATICGMTopOperator;
class CATlsoProgressBarManager;
class CATTopOpInError;
class CATContextForFastRun;
class CATThickPlusContextForFastRun;

/**
* Operator to blow or shrink the faces of a volume.
* Each face may have its own offset value. The offset values
* may be negative: the body is shrunk.
* This operator can also be used to offset a shell. In this case, it is recommended to use the
* SetSharpBorderMode API with the optimization parameter.
* As all the topological operators, the input objects are not modified. The resulting body is
* a new one to retrieve by using the <tt> CATICGMThickPlus::GetResult</tt> method.
* To use it:
* <ul>
* <li>Create it with the <tt> CATICGMCreateThickPlus </tt> global function.
* <li>Tune it with appropriate options, using the <tt>SetXxx</tt> methods. 
* <li>Run it
* <li>Get the result in body with the <tt>GetResult</tt> method. If you do not want 
* to keep these resulting body, use the @href CATICGMContainer#Remove method to remove them from the 
* geometric factory, after the operator deletion.
* <li>Release the operator with the <tt>Release</tt> method after use.
* </ul> 
*/
class ExportedByCATCleverOffset CATThickPlus : public CATTopOperator
{

  CATCGMVirtualDeclareClass(CATThickPlus);
public:

  /**
  * Constructs a CATThickPlus operator.
  * @param iBody
  * The pointer to the body to offset. 
  * @param iTopData
  */
  CATThickPlus( CATTopData * iTopData, CATBody* iBody );


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
    * @nodoc
  * Appends a face to offset in UpTo mode.
  * @param iFace
  * The pointer to the face to offset in direction of <tt>iTargetBody</tt>.
  * @param iTargetBody
  * The pointer to the target body.
  */

  void Append(CATFace * iFace, CATBody* iTargetBody);


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
  * @nodoc
  * Defines the boundary G0 derivation behaviour in Offset/ThickenOp operator.
  * @param iForceG0Distortion
  * <dl>
  * <dt><tt>0</tt></dt><dd> Natural G0 derivation : each edge of the boundary is offset 
  *                        according to its normal support direction, then junction edges 
  *                        ared added to close the offset boundary when adjacent edges 
  *                        aren't connected to each others anymore after offset.
  * This mode is used by default at the creation of the operator.
  * <dt><tt>1</tt></dt><dd> Force G0 distortion : each edge of the boundary is offset
  *                        according to normal support direction, then a distortion is applied
  *                        to make adjacent edges still connected to each others, 
  *                        without any junction edge.
  * </dl>
  * @param iDistortionOption
  * <dl>
  * <dt><tt> -1 </tt></dt><dd>    MIN : distortion is drived by surface area minimisation,
  *                                    only one boundary edge is modified by vertex.
  * <dt><tt>  0 </tt></dt><dd> MEDIUM : distortion is computed on the 2 adjacent boundary
  *                                    edges around each boundary vertex
  * This mode is used by default at the creation of the operator.
  * <dt><tt> +1 </tt></dt><dd>    MAX : distortion is drived by surface area maximisation,
  *                                    only one boundary edge is modified by vertex.
  * </dl>
  */
  void SetG0DerivationBehaviourOnBoundary(int iForceG0Distortion, int iDistortionOption=0);

  /**
  * @nodoc
  * Defines if procedural Offset surfaces must be approximated and
  * replaced by NurbsSurface.
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
  void SetApproxOffsetMode(short iApproxOffsetMode, short iPostProRequired=0);

  /**
  * @nodoc
  * Defines the tolerance for C1 approximation. 
  * @param iTolC1
  * </dl>
  */
  void SetToleranceForApproxC1(double iTolC1);

  /**
  * @nodoc
  * Defines the tolerance for C2 approximation.
  * @param iTolC2
  * The tolerance.
  */
  void SetToleranceForApproxC2(double iTolC2);

  /**
  * Deactivates tangent propagation of offset values.
  */
  void SetPropagationOff();

  /**
  * @nodoc	 
  * Activates tangent propagation of offset values.
  */
  void SetPropagationOn();

  /**
 * @nodoc
 */
  void SetUpToMode(short iUpToMode);

  /** 
  * @nodoc 
  */
  void SetDiffMode(short iDiffMode);

  /** 
  * @nodoc 
  */
  void SetSimplificationMode(short iSimplifMode);

/**
 * @nodoc
 * @nocgmitf
 * Internal use.
 */
  void SetJournalForBioffsetFaceFromInternalEdge(short iJournalForBioffsetFace);

  /**
  * @nodoc
  * Defines the state of the resulting body.
  * @param iOnOrOff
  * The state of the resulting body. 
  */
  void SetFreezeMode(CATBodyFreezeMode iOnOrOff);

  // Destructor (memory is freed and model is cleaned, the resulting body is kept.
  virtual ~CATThickPlus();

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

  /**
  * Modifies the type of the journal items created during <tt>this</tt> CATThickPlus operation.
  * @param iTypeForFaceCreation
  * The item type.
  * @param iAdditionalInfo
  * The pointer to an additional information. If <tt>NULL</tt>, no additional information is added.
  */
  void SetJournalTypeForFaceOffset(CATCGMJournal::Type  iTypeForFaceCreation,
    CATCGMJournalInfo  * iAdditionalInfo=NULL);


  /**
  * @nodoc
  * Internal use.
  */
  void SetThickBoundaryMappingRequired(short iThickBoundaryMappingRequired);


  /**
  * @nodoc
  * @param iFacesToRemove
  * 
  */
  void SetMandatoryFacesToRemove(const CATLISTP(CATFace) &iFacesToRemove, short iAllOffsetAreNull=0);

  /**
  * @nodoc
  * @param oTrickyFaces
  * 
  */
  void GetTrickyFaces(CATLISTP(CATFace) &oTrickyFaces);

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

  /**
  * @nodoc
  * @param oNotInverseRazorBladeFaces
  * 
  */
  void GetNotInverseRazorBladeFaces(CATLISTP(CATFace) &oNotInverseRazorBladeFaces);

  /**
  * @nodoc
  * @nocgmitf
  * @param oInitReverseMatterFaces
  * 
  */
  void GetInitReverseMatterFaces(CATLISTP(CATFace) &oInitReverseMatterFaces);

  /**
  * @nodoc @nocgmitf
  * Internal use. internal run
  */
  virtual int RunOperator();

  /**
  * Sets the OffsetMixte options. <br> 
  * <b>Legal Values</b>:<br>
  *	<ul>
  *	<li><tt>iWithRegul</tt>: Activates the regularisation of tricky faces with a regularisation diagnosis <br>
  * <li><tt>iRemoveTrickyOnlyThenRegul</tt> : Default value: FALSE.
  * If this option is activated, it changes the behaviour of GetTrickyFaces().
  * If there are non regularisable tricky faces, the method
  * GetTrickyFaces() gives only the non regularisable tricky
  * faces. If there are not non regularisable tricky faces,
  * then GetTrickyFaces gives regularisable tricky faces that
  * fail.<br>
  *	</ul>
  * <b>NOTE</b>: iRemoveTrickyOnlyThenRegul should be activated just if you use
  * CATThickPlus in iterative mode with remove faces.
  *
  **/ 
  void SetOffsetMixte(CATBoolean iWithRegul, CATBoolean iRemoveTrickyOnlyThenRegul=FALSE);


  /**
  * Activates/Deactivates local regularisation treatment (which may split faces) to
  * smooth subparts of the non offsetable faces.
  * @param iLocalRegul
  *	<ul>
  *	<li><tt>TRUE</tt>:  Activates local regularisation.
  *	<li><tt>FALSE</tt>: Deactivates local regularisation.
  *	</ul>
  **/
  void SetLocalRegularization(CATBoolean iLocalRegul);

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
  * Sets the deviation allowed by the user. <br> 
  * <b>Legal Values</b>:<br>
  *	<ul>
  *	<li> <tt>iDeviation</tt> : represents the value of the deviation.This
  *	value must be positive.			
  *	</ul>
  * <b>NOTE</b> : If you use this method, the distribution of the tolerances is
  *	determined by the value containing in the file : CATFuzzyOffsetManagerConst.h
  **/
  void SetDeviationAllowed(CATLength iDeviation);

  /**
  * Sets the deviation mode. <br> 
  * <b>Legal Values</b>:<br>
  *	<ul>
  *	<li> <tt>iWithDeviation</tt>: If it's TRUE, then the regularisator uses the derivation value of the user.
  *	If it's FALSE, then the regularisator does not use the derivation value of the user.			
  *	</ul>
  * <b>NOTE</b> : By default the DeviationMode is false.
  **/
  void SetDeviationMode(CATBoolean iWithDeviation);
  
  /**
  * @nodoc 
  * Collision reseach mode.
  * @param iCollisionLevel
  *<dl>
  *<dt><tt>0</tt></dt><dd> Local collisions research only (perfos default mode). 
  *<dt><tt>1</tt></dt><dd> Global collisions research (costly).
  *</dl>
  */
  void SetCollisionResearch(short iCollisionLevel);

  /**
  * @nodoc
  * @nocgmitf
  * Set the Input Tricky Faces. <br>
  * @param iTrickyFaces
  * The list of tricky faces.
  * @param iListDiag
  * The diagnosis of tricky faces.
  * @param iListDiagResult
  * The diagnosis result of tricky faces.
  * @param iJournal
  * The journal of input operator which compute tricky faces.
  * @param iBody
  * The body of input operator which compute tricky faces.
  * 
  */
  void SetInputTrickyFaces(CATLISTP(CATFace) &iListTrickyFaces, 
                           CATListOfInt      &iListDiag,
                           CATListOfInt      &iListDiagResult,
                           CATCGMJournalList *iJournal,
                           CATBody           *iBody);

  /**
  * @nodoc 
  * Sets the partial result mode. <br> 
  * <b>Legal Values</b>:<br>
  *	<ul>
  *	<li> <tt>iPartialResultMode</tt>: If it's equal to 1, then the operator returns the best partial result if full result is not possible.
  *	If it's equal to 0, then the operation returns an error if full result is not possible.			
  *	</ul>
  * <b>NOTE</b> : By default the PartialResultMode is turned to off.
  **/
  void SetPartialResultMode(short iPartialResultMode);
  
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

  //-----------------------------------------------------------------------
  //- Gestion pour CGMReplay
  //-----------------------------------------------------------------------  
  /** @nodoc @nocgmitf definition des Objets  ...*/
  void RequireDefinitionOfInputAndOutputObjects();

  /** @nodoc @nocgmitf declaration integre au CGMReplay */
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);

  /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual void DumpOutput(CATCGMOutput &os);

  /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual void WriteInput(CATCGMStream  & os);

  /** @nodoc @nocgmitf ID pour FastUpdate */
  void WriteInputForFastRun(CATCGMStream  & ioStr);

  /** @nodoc @nocgmitf ID pour FastUpdate */
  void WriteNewThickInputs(CATCGMStream  & ioStr);

  /** @nodoc @nocgmitf */
  virtual void ReadInput(CATCGMStream  & ioStream,int VersionOfStream, short iNumReplayVersion=1);

   /** @nodoc @nocgmitf ID pour FastUpdate */
  void ReadNewThickInputs(CATCGMStream  & ioStr, CATGeoFactory * iFacto, CATTopOperator * iOpeToUpdate, short iNumReplayVersion=1 );

  // Stream / Unstream (methodes surchargees pour CGMReplay)
  // S'il faut mettre a jour l'operateur (ex: propager des offsets) au
  // moment de l'unstream, on fournit cet operateur (il s'agit ici
  // forcement d'un CATThick)
  /** @nodoc @nocgmitf */
  virtual void Stream(CATCGMStream  & ioStr, short iNumReplayVersion=1);
  /** @nodoc @nocgmitf */
  virtual void Unstream(CATCGMStream  & ioStr, CATGeoFactory * iFacto,
    CATTopOperator * iOpeToUpdate, short iNumReplayVersion=1);

  // @nocgmitf
  virtual void Unstream(CATCGMStream  & ioStr, CATGeoFactory * iFacto,
    CATICGMTopOperator * iOpeToUpdate, short iNumReplayVersion=1);

  /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual void Dump( CATCGMOutput& s ) ;

  /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual const CATString * GetOperatorId();

  /** @nodoc @nocgmitf ID pour CGMReplay */
  static const CATString * GetDefaultOperatorId();

  //-----------------------------------------------------------------------
  //- Methodes pour Fast Update
  //-----------------------------------------------------------------------  
  /**
  * @nodoc
  * @return [out, CATBaseUnknown#Release]
  */
  //virtual CATContextForFastRun* GetContextForFastRun(CATBoolean iGetOnly = FALSE);

  /**
  * @nodoc
  * @return [out, CATBaseUnknown#Release]
  */
  virtual CATThickPlusContextForFastRun* GetThickPlusContextForFastRun(CATBoolean iGetOnly = FALSE);

  struct UpToFace {
    CATFace *initFace;
    CATLISTP(CATBody) targetBodies;
  };


  //-----------------------------------------------------------------------
  //- Getxxx Methods to retrieve inputs (from the extension, usefull for the delegation mechanism)
  //-----------------------------------------------------------------------    
 
  /** @nodoc @nocgmitf */
  CATBody * GetInitialBody();

  /** @nodoc @nocgmitf */
  CATBoolean GetDefaultOffsetValue(double & oGlobalOffsetValue);

  /** @nodoc @nocgmitf **/
  void GetFacesToOffset(ListPOfCATFace & oSpecialOffsetFaces, CATListOfDouble & oSpecialOffsetValues);

  /** @nodoc @nocgmitf **/
  void GetFacesToRemove(ListPOfCATFace & oFacesToRemove);

  /** @nodoc @nocgmitf **/
  void GetUpToFaces(ListPOfCATFace & oUpToFaces, ListPOfCATBody & oTargetBodies);

  /** @nodoc @nocgmitf **/
  short GetUpToMode();

  /** @nodoc @nocgmitf **/
  short GetDiffMode();

  /** @nodoc @nocgmitf **/
  short GetSimplificationMode();

  /** @nodoc @nocgmitf **/
  short GetPropagationMode();

  /** @nodoc @nocgmitf **/
  CATCGMJournal::Type GetJournalTypeForFaceOffset(CATCGMJournalInfo * & oAdditionalInfo);

#ifdef CATIAR422
  // Polyhedral delegation management
protected:
  //
  virtual int RunExactOperator();
  //
  virtual int RunPolyOperator();
#endif


private :

  int Compute();

  int IsotopologicalRun();

  int ComputePartialResult();

  CATBody * TransformIntoSurfacicScenario();

  void UpdateThickOperator(CATTopOperator *iThickOperator);

  void RetrieveFacesOnInputBody(CATLISTP(CATFace) &iRegularizedFaceList, CATLISTP(CATFace) &oInputBodyFaceList);

  short BelongsToTangencyFaceList(CATFace *iFace, CATFace *iFaceToPropagate);

  void BorderDerivationCleanerCall(CATThick* iThickOp);

  int AddRegulTrickyFacesToDiag(CATLISTP(CATFace) & iListTrickyfaces, 
                                CATListOfInt      & iListDiagResultOfTrickyFaces,
                                CATTopOpInError   * iRegulInError);

  CATLONG32 _BeforePropagSize;

  double _OffsetValue;

  short  _DefaultOffsetValueHasBeenSet;

  /** @nodoc */
  CATBody       * _InitialBody;
  /** @nodoc */
  CATBody       * _NewResultBody;
  /** @nodoc */
  CATLONG32       _NbDomains;
  /** @nodoc */
  CATLONG32       _BodyDimension;

  // Propagation mode (0 = off, 1 = on)
  /** @nodoc */
  short           _Propagation;

  /** @nodoc */
  short           _PartialResultMode;

  /** @nodoc */
  short           _TwistDetection;

  // niveau de recherche de collisions : 0 (defaut) : locales, 1 : globales.
  /** @nodoc */
  short           _CollisionLevel;

  short           _UpToMode;

  short           _DiffMode;

  short           _SimplifMode;

  // Main operator
  CATThick    * _Thick;
  CATRegul    * _RegulForOffset;
  CATThick    * _ThickRegul;
  CATBorderDerivationCleanerOpe * _BorderCleanerOp;

  // Should we freeze the output body?
  CATBodyFreezeMode    _freezeMode;

  // Boundary mapping required
  short                _ThickBoundaryMappingRequired;

  // Extrapolation Mode
  short                _ExtrapolationMode;

  // Log calls to SetJournalTypeForFaceInfo (for CGMReplay use)
  short                _JournalTypeHasBeenSet;
  CATCGMJournal::Type  _TypeForFaceCreation;
  short                _JournalForBioffsetFace;

  // Information to add in topological journal events
  CATCGMJournalInfo * _JournalInfo;

  short               _SharpBorderOptimisation;
  // behaviour on G0 boundary => 0:natural derivation | 1:min distortion | 2:medium distortion | 3:max distortion
  short               _G0DistortionSpec;
  short               _ApproxOffsetMode;
  short               _PostApproxRequired;
  double *            _TolApproxC1;
  double *            _TolApproxC2;

  // Liste des faces a valeur d'offset specifique
  CATLISTP(CATFace)   _ListFace;
  // Idem, liste mise a jour apres regularisation
  CATLISTP(CATFace)   _ListRegulFace;
  // Liste des valeurs d'offset, parallele a _ListFace/_ListRegulFace
  CATListOfDouble     _ListVal;

  CATListOfDouble     _ListRegulVal;

  // Liste de faces initialement selectionnées, pour thickness upto
  UpToFace*       _InitUpToFaces;
  CATLONG32       _InitUpToFacesSize;
  CATLONG32       _InitUpToFacesTabMaxSize;

  // Liste des faces dont la supression est demandee en cours d'operation :
  // on extrapolera les faces voisines et on lancera les collisions
  CATLISTP(CATFace)   _ListMandFaceToRemove;
  // Idem, liste mise a jour apres regularisation
  CATLISTP(CATFace)   _ListMandRegulFaceToRemove;

  CATBoolean          _WithRegul; // FALSE : Sans. Par defaut
  // TRUE : Avec Offset Mixte


  CATBoolean          _LocalRegul; // TRUE : nouveau code de regul qui decoupe les faces
  // FALSE : ancien code


  CATLISTP(CATFace)  _TrickyFaces;

  // Liste des tricky faces en entrée (a ne pas regulariser si meme diag)
  CATLISTP(CATFace) _ListInputTrickyFaces;
  CATListOfInt      _ListInputDiagOfTrickyFaces;
  CATListOfInt      _ListInputDiagResultOfTrickyFaces;
  CATCGMJournalList * _InputJournalOfTrickyfaces;
  CATBody           * _InputBodyOfTrickyFaces;

  CATBoolean          _RemoveTrickyOnlyThenRegul;

  // Variable pour le deviation max autorisée par l'utilisateur
  CATLength           _DeviationAllowed;
  CATBoolean          _WithDeviation;

  CATBoolean          _PolyConfig; // to manage forks between exact and poly computation & GetResult
  
  // qualité pour TMC
  short                _G0Hermetization;
  double               _G0HermetizationTargetValue;
  short                _G1Smoothing;
  CATAngle             _G1SmoothingTargetValue;

  CATTopOpInError *   _TopOpInError;

  // Gestion des progress bars
  CATlsoProgressBarManager * _ProgressBarManager;
};
#endif
