#ifndef CATShellOperatorPlus_H
#define CATShellOperatorPlus_H
//---------------------------------------------------------------------
// CATShellOperatorPlus
// 
// Implementation de l'operateur de shell (coque).
//
//
// COPYRIGHT DASSAULT SYSTEMES  1999
// 
// 25 05 2000  Modification : je fais deriver l'operateur CATShellOperator
// de CATTopOperator pour beneficier d'un mecanisme generique de gestion
// de versions.
//---------------------------------------------------------------------

#include "CATMathDef.h"
#include "CATCleverOffset.h"
#include "ListPOfCATFace.h"
#include "CATCGMJournalInfo.h"
#include "CATTopOperator.h"
#include "CATTopologicalOperator.h"
#include "CATShellOperator.h"

class CATBody;
class CATFace;
class CATCGMJournalList;
class CATCGMJournalItem;
class CATTopData;
class CAThkShellScenario;
class CATlsoProgressBarManager;
class CATString;

/**
* Interface representing the topological operator of shell.
* A shell operation is available on bodies containing volumes: it corresponds to
* two thickness operations on the body, with two different
* offset values, followed by a subtraction between
* the results of the thickness operations.
* As all the topological operators, the input objects are not modified. The resulting body is
* a new one, that you can get by using the <tt>CATShellOperatorPlus::GetResult</tt> method.
* To use it:
* <ul>
* <li>Create it with the <tt>CATCreateShellOperatorPlus</tt> global function.
* <li>Tune it with appropriate options, using the <tt>SetXxx</tt> methods.
* <li>Run it
* <li>Get the resulting GetResult method. If you do not want
* to keep these resulting body, use the @href CATICGMContainer#Remove method to remove them from the
* geometric factory, after the operator deletion.
* <li>Release the operator with the <tt>Release</tt> method after use.
* </ul>
*/
class ExportedByCATCleverOffset CATShellOperatorPlus : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATShellOperatorPlus);
public:

  /**
  * @nodoc
  * Default constructor
  */
  CATShellOperatorPlus(CATBody           * iBody,
    CATTopData        * iTopData,
    CATLength           iInternalOffsetValue,
    CATLength           iExternalOffsetValue);

  /**
  * @nodoc
  */
  CATShellOperatorPlus(const CATShellOperatorPlus & iShellOrig);

  /**
  * @nodoc
  */
  CATShellOperatorPlus & operator= (const CATShellOperatorPlus & iShellRight);

  virtual ~CATShellOperatorPlus();


  /**
  * Specifies the list of faces to be removed.
  * @param iOpenFaces
  * The list of faces
  */
  void AppendOpening(const CATLISTP(CATFace) &iOpenFaces);

  /**
  * Modifies the offset values for a list of faces of the body to shell.
  * @param iSpecialOffset
  * A list of faces.
  * @param iInternalSpecialOffset
  * The list of the corresponding internal offsets.
  * @param iExternalSpecialOffset
  * The list of the corresponding external offsets.
  */
  void AppendSpecialOffset(const CATLISTP(CATFace) &iSpecOffsetFaces, 
    CATLength iInternSpecialOffsetValue,
    CATLength iExternSpecialOffsetValue);

  /**
  * Runs the operator
  */
  int Run();


  /**
  * Returns the pointer to the resulting body.
  * @return
  * The pointer to the resulting body, <tt>NULL</tt> if the operation failed. 
  * If you do not want to keep the resulting body, 
  * use the @href CATICGMContainer#Remove method to remove it from the 
  * geometric factory, after the operator deletion.
  */
  CATBody* GetResult();

  /**
  * @nodoc
  * @nocgmitf
  */
  virtual int RunOperator();
  /**
  * @nodoc
  * @param iFacesToRemove
  * @param iExternalThick (0/1)
  * 
  */
  void SetMandatoryFacesToRemove( const CATLISTP(CATFace) &iFacesToRemove,
    short iExternalThick );

  /**
  * @nodoc
  * @param oTrickyFaces
  * @param iExternalThick (0/1)
  * 
  */
  void GetTrickyFaces(CATLISTP(CATFace) &oTrickyFaces, short iExternalThick);

  /**
  * @nodoc
  * @param oFacesToIgnore 
  * @param iExternalThick (0/1)
  * 
  */
  void GetFacesToIgnore(CATLISTP(CATFace) &oFacesToIgnore, short iExternalThick);

  /**
  * @nodoc
  * @param oReverseMatterOutputFaces 
  * 
  */
  void GetReverseMatterOutputFaces(CATLISTP(CATFace) &oReverseMatterOutputFaces);

  /**
  * @nodoc
  *
  */
  int GetNbReverseMatterOutputFacesBeforeRemoval();

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
  * @nodoc
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
  void SetApproxOffsetMode(short iApproxOffsetMode, short iPostProRequired=0);

  /**
  * @nodoc
  * Defines the tolerance for C1 approximation 
  * @param iTolC1
  * </dl>
  */
  void SetToleranceForApproxC1(double iTolC1);

  /**
  * @nodoc
  * Defines the tolerance for C2 approximation 
  * @param iTolC2
  * </dl>
  */
  void SetToleranceForApproxC2(double iTolC2);

  /**
  * @nodoc
  * Defines whether propagation of opening faces should be activated or not
  * By default, it is enabled.
  * @param iPropagation
  * </dl>
  */
  void SetOpeningFacesPropagation(CATBoolean iPropagation);

  /**
  * @nodoc
  * Defines whether propagation of special offset faces should be activated or not
  * By default, it is enabled.
  * @param iPropagation
  * </dl>
  */
  void SetSpecialOffsetFacesPropagation(CATBoolean iPropagation);

  /**
  * @nodoc
  * Defines whether geometrical and topological simplification in post-treatment 
  *   should be activated or not.
  * By default, it is disabled.
  * @param iLevel
  * </dl>
  */
  void SetSimplificationLevel(short iLevel);

  /**
  * @nodoc @nocgmitf 
  * Collision reseach mode.
  * @param iCollisionLevel
  *<dl>
  *<dt><tt>0</tt></dt><dd> Local collisions research only (perfos default mode). 
  *<dt><tt>1</tt></dt><dd> Global collisions research (costly).
  *</dl>
  */
  void SetCollisionResearch(short iCollisionLevel);

  /**
  * Sets the OffsetMixte options. <br> 
  * @param iWithRegul
  * <dl><dt><tt>1</tt><dd> Regularization of "tricky faces" with diagnosis.
  *     <dt><tt>0</tt><dd> No regularization</dl>
  */
  void SetOffsetMixte(CATBoolean iWithRegul);

  /**
  * Requires a local smoothing of a face when this face cannot be offsetted as a whole.
  * This option can result in additional faces. It can only be activated when the 
  * SetOffsetMixte method is used to ask for a surface "regularization".
  * @param iLocalRegul
  * <dl><dt><tt>TRUE</tt><dd> The local regularization is activated.
  *     <dt><tt>FALSE</tt><dd> The local regularization is not activated.</dl>
  **/
  void SetLocalRegularization(CATBoolean iLocalRegul);

  /**
  * Sets the deviation allowed by the user. 
  * @param iDeviation
  * The value of the deviation. This value must be positive.				
  */
  void SetDeviationAllowed(CATLength iDeviation);

  /**
  * Sets the deviation mode.
  * @param iWithDeviation
  * <dl><dt><tt>TRUE</tt><dd> the regularizator uses the deviation value which is specified by the user.
  *     <dt><tt>FALSE</tt><dd> the regularizator does not use the user value (default value). 
  * </dl>
  **/
  void SetDeviationMode(CATBoolean iWithDeviation);

  /**
  * Asks for a constant thickness for the resulting shell when one of the offset values is null.
  * Applies only when the regularization is activated (SetOffsetMixte)
  * @param iConstantThickness
  * <dl><dt><tt>TRUE</tt><dd> Default mode: the smoothed/regularized face with null offset is keep in the resulting shell
  *     <dt><tt>FALSE</tt><dd> The input face with null offset is not modified.</dl>
  **/
  void SetConstantThickness(CATBoolean iConstantThickness=TRUE);

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

  /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual void ReadInput(CATCGMStream  & ioStream,int VersionOfStream, short iNumReplayVersion=1);

  // Stream / Unstream (methodes surchargees pour CGMReplay)
  /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual void Stream(CATCGMStream  & ioStr, short iNumReplayVersion=1);

  /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual void Unstream(CATCGMStream  & ioStr, CATGeoFactory * iFacto,
    CATTopOperator * iOpeToUpdate, short iNumReplayVersion=1);

  /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual void Dump( CATCGMOutput& s ) ;

  /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual const  CATString * GetOperatorId();

  /** @nodoc @nocgmitf ID pour CGMReplay */
  static const CATString * GetDefaultOperatorId();


private:

  int Compute();

  void PropagateFaceLists();
  void ThrowConflictingOffsetValuesError(CATFace *iFace);
  void ThrowGeneralShellError();
  void Propagate(CATBody *iBody, CATLISTP(CATFace) &iInputFaceList, CATLISTP(CATFace) &oOutputFaceList);

  void GetAlreadyShelledFaceList(CATLISTP(CATFace) &oAlreadyShelledFaceList);

  void SplitInAlreadyShelledAndNotShelledYetBodies(CATLISTP(CATFace) &iAlreadyShelledFaceList, 
    CATBody *&oAlreadyShelledBody, CATBody *&oNotShelledYetBody);

  void RemoveDeletionOrdersInJournal(CATCGMJournalList *&ioJournal);

  void UpdateFaceLists(CATCGMJournalList *iJournal, CATBody *iNewBody);

  void GetImageFacesInJournal(CATCGMJournalList *iJournal, CATFace *iFace, CATLISTP(CATFace) &oImageFaceList);

  CATBody * RunRemoveFace(CATBody *iBody, CATLISTP(CATFace) &iListOfFacesToRemove, short iUpdateLists=0);

  CATBody * RunDiff(CATBody *iFirstBody, CATBody *iSecondBody, short iUpdateLists=0);

  CATBody * RunUnion(CATBody *iFirstBody, CATBody *iSecondBody);

  void UpdateShellOpRegule();

  void JournalPostProcessor(CATCGMJournalList *iRegulJournal);

  // body initial
  CATBody   * _InitialBody;

  CATBody   * _NewResultBody;
  // Operateur Thickness :
  CATShellOperator * _ShellOp;

  // Operateur Thickness :
  CATShellOperator * _ShellOpRegule;

  CATLength  _InternalOffset, _ExternalOffset;

  int _RegulExternal;
  CATLISTP(CATFace) _OpenFaceList;
  CATLISTP(CATFace) _OpenFaceListAfterPropag;
  // Mise a jour de la liste precedente si la regularisation
  // a modifie une Opening Face !
  CATLISTP(CATFace) _OpenFaceListRegul;

  // Liste des faces a valeur d'offset specifique
  CATLISTP(CATFace) _SpecialOffsetFacList;
  CATLISTP(CATFace) _SpecialOffsetFacListAfterPropag;
  // Mise a jour de la liste precedente si la regularisation
  // a modifie une Face a valeur d'offset specifique!
  CATLISTP(CATFace) _SpecialOffsetRegulFacList;
  // Double liste parallele a _SpecialFaceListPtr, 
  // affectant 2 valeurs d'offset specifiques a chaque face de la liste
  CATListOfDouble   _SpecialOffsetValList[2];
  CATListOfDouble   _SpecialOffsetValListAfterPropag[2];

  CATListOfDouble   _SpecialOffsetRegulValList[2];


  // Liste des faces a supprimer : on extrapolera les voisines
  // et on lancera les collisions pour refermer la piece topologiquement
  CATLISTP(CATFace) _MandatFaceToRemoveExt;
  CATLISTP(CATFace) _MandatFaceToRemoveInt;
  // Mise a jour des listes precedentes si la regularisation
  // a modifie une Face a Remover !
  CATLISTP(CATFace) _MandatFaceToRemoveRegulExt;
  CATLISTP(CATFace) _MandatFaceToRemoveRegulInt;

  short               _ApproxOffsetMode;
  short               _PostApproxRequired;
  double            * _TolApproxC1;
  double            * _TolApproxC2;

  CATBoolean          _OpeningFacesPropagation;
  CATBoolean          _SpecialOffsetFacesPropagation;

  short               _SimplificationLevel;

  // niveau de recherche de collisions : 0 (defaut) : locales, 1 : globales.
  /** @nodoc */
  short               _CollisionLevel;

  CATBoolean          _WithRegul; // 1 : Avec Offset Mixte
  // 0 : Sans. Par defaut

  CATBoolean          _LocalRegul; // TRUE : nouveau code de regul qui decoupe les faces
  // FALSE : ancien code

  // Variable pour le deviation max autorisée par l'utilisateur
  CATLength           _DeviationAllowed;
  CATBoolean          _WithDeviation;

  CATBoolean         _ConstantThickness; // 1 : epaisseur constante par defaut
  // 0 : faces d'offset nul identiques aux faces input.

  // Gestion des progress bars
  CATlsoProgressBarManager * _ProgressBarManager;
};

#endif

