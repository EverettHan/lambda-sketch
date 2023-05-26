#ifndef CATRemoveFacePlus_h
#define CATRemoveFacePlus_h

// COPYRIGHT DASSAULT SYSTEMES 2006

/**
 * Class defining the topological operator that removes given faces on a body.
 * <br>The CATRemoveFace operator does not change the dimension of the body: a volume becomes a volume,
 * Nowadays it is only available for 3D Body. ( 2D not supported )
 * Explicit list of faces to remove should be given. ( Not any propagation is done accordng to continuities ).
 * Use limitiations are :
 *   1) Body can be closed by extrapolation af adjacent faces to remove one.
 *   2) Extrapolation of adjacent faces should not generate tangent configuration.
 *
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
#include "CATMathDef.h"
#include "CATMathInline.h"
#include "Thick.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATBody.h"
#include "CATListOfCATCells.h"
#include "CATListOfInt.h"
#include "CATDRepOperator.h"
#include "CATString.h"
#include "CATRemoveFace.h"
#include "ListPOfListPOfCATCell.h"

class CATBody;
class CATFace;
class CATRemoveFace;
class CATGeoFactory;
class CATCGMJournalInfo;
class CATCGMOutput;
class CATTopData;
class CATSurface;
class CATlsoProgressBarManager;
class CATError;


class ExportedByThick CATRemoveFacePlus : public CATDRepOperator
{
public:

  // Constructor: do not use, use CATCreateRemoveFacePlus instead
  CATRemoveFacePlus(CATTopData * iTopData, CATBody * iBody, CATLISTP(CATFace) &iFacesToRemove);

  // Destructor
  ~CATRemoveFacePlus();

  /**
  * Appends a list of faces to remove
  * @param iFacesToRemove
  * The list of pointers to faces to remove.
  */
  void Append(const CATLISTP(CATFace) &iFacesToRemove);

  /**
 * Appends a limiting body mono-shll mono-face related to a face
 * @param iFaceToRemove
 * The face to relimit.
 * @param iLimitingBody
 * The limiting body.
 * @param iOri
 * The orientation related to the shell on the side to remove.
 */
  void AppendLimiting(CATFace *iFaceToRelimit, CATBody *iLimitingBody, CATOrientation iOri);

  /**
  * Enables or disables twist detection.
  * @param iTwistDetection
  * 0 - Twist detection is disabled : result body may lie on twisted surfaces.
  *     This mode is used by default at the creation of the operator.
  * 1 - Twist detection is enabled : face removal fails if at least one of the extrapolated surfaces is twisted
  */
  void SetTwistDetection(short iTwistDetection);

  /**
  * Roof Revit
  * @param iRoofRevit = 1 to activate the option.
  */
  void SetRoofRevit(short iRoofRevit=1);

  /**
  * @nodoc
  * Indicates that specified faces to remove are all fillets
  * @param iRemoveFilletsMode = 1 enables fillet dedicated treatments.
  * This mode is disabled by default.
  */
  void SetRemoveFilletsMode(short iRemoveFilletsMode=1);

  /**
  * Appends a list of faces allowed to be removed
  * @param iFacesToRemove
  * The list of pointers to faces to potentially remove.
  */
  void AppendCandidate(const CATLISTP(CATFace) &iFacesToRemove);

  /**
  * Defines the state of the resulting body.
  * @param iOnOrOff
  * The state of the resulting body. 
  */
  void SetFreezeMode(CATBodyFreezeMode iOnOrOff);

  /**
  * permet au client d'indiquer si l'on va ajouter (iMatterDirection = 1)
  * ou supprimer (iMatterDirection = -1) de la matiere pour obtenir
  * le resultat du RemoveFace.
  */
  void SetMatterDirection(short iMatterDirection);


  /**
  * option spécifique pour AutoDraft. 
  * essaie d'enlever les paquets de faces connexes séparément si sortie en 
  * erreur avec toutes les faces.
  */
  void SetPartialRemoveFaceAllowed(short iPartialRemoveFaceAllowed);

  /**
  * Optimisation pour les operations de suppression tres localisees.
  * Actuellement limitee a la suppression de fillets exclusivement.
  */
  void SetTryLocalRemoveFace(short iTryLocalRemoveFace);

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
  * Returns the pointer to the resulting body.
  * @return
  * The pointer to the resulting body, <tt>NULL</tt> if the operation failed. 
  * If you do not want to keep the resulting body, 
  * use the @href CATICGMContainer#Remove method to remove it from the 
  * geometric factory, after the operator deletion.
  */
  CATBody* GetResult();

  int Run();

  virtual int RunOperator();

  /**
  * Returns the list of CATFace that couldn't be removed.
  */
  void GetTrickyFaces(CATLISTP(CATFace) &oTrickyFaces, short iFacesToRemoveOnly = 1);

  /**
  * Returns the list of CATFace that couldn't be removed and their associated diagnoses.
  * Unreliable if partial RemoveFace is allowed
  */
  void GetAllTrickyFaces(CATLISTP(CATFace) &oAllTrickyFaces, CATListOfInt &oAllDiags, short iFacesToRemoveOnly = 1);
  
  /**
   * Get the list of faces for which matter side has been reversed.
   * @param oReverseMatterOutputFaces
   * The list of reversed faces.
   */
   void GetReverseMatterOutputFaces(CATLISTP(CATFace) & oReverseMatterOutputFaces);

  //-----------------------------------------------------------------------
  //- Gestion pour CGMReplay
  //-----------------------------------------------------------------------  
  /** @nocgmitf definition des Objets  ...*/
  void RequireDefinitionOfInputAndOutputObjects();

  /** @nocgmitf declaration integre au CGMReplay */
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);

  /** @nocgmitf ID pour CGMReplay */
  virtual void WriteInput(CATCGMStream  & ioStr);

  virtual void ReadInput(CATCGMStream  & ioStr,int VersionOfStream, short iNumReplayVersion=1);

  /** @nocgmitf ID pour CGMReplay */
  virtual void Dump( CATCGMOutput& s ) ;

  /** @nocgmitf ID pour CGMReplay */
  virtual void DumpOutput(CATCGMOutput &os);

  /** @nocgmitf ID pour CGMReplay */
  CATCGMOperator::CATCheckDiagnostic CheckOutput( CATCGMOutput & oStr );

  /** @nocgmitf ID pour CGMReplay */
  static const CATString * GetDefaultOperatorId() { return & _OperatorName; };

private:
  
  //-----------------------------------------------------------------------
  //- Private methods
  //-----------------------------------------------------------------------  

  INLINE void SetCGMMode(short iCGMMode);

  void SetResult(CATBody *iResultBody);

  void GetLocalTrickyFaces(CATRemoveFace *iRemoveFace, CATLISTP(CATFace) &oTrickyFaces, short iUpdate = 0);
  void GetLocalTrickyFaces(CATRemoveFacePlus *iRemoveFacePlus, CATLISTP(CATFace) &oTrickyFaces, short iUpdate = 0);

  void GetLocalReverseMatterOutputFaces(CATRemoveFace *iRemoveFace, CATLISTP(CATFace) & oReverseMatterOutputFaces);

  /**
   * Append list of reverse matter faces.
   * @param iReverseMatterOutputFaces New list to append.
   * @param ipJournal If not NULL, updates list of reverse matter faces (both previous and new ones) according to the journal.
   */
  void AppendReverseMatterOutputFaces( const CATLISTP(CATFace) &iReverseMatterOutputFaces,
                                       CATCGMJournalList * ipJournal = NULL );

  // Check de validite d'un body result partiel
  // Renvoie 1 si body valide , 0 sinon
  short CheckLocalResult( CATBody * iResultBody, CATBody * iInputBody, CATTopOperator * iOperator );

  // Utilitaire : recupere l'image dans le journal de iFace.
  CATFace * GetImageInJournal(CATFace *iInitFace);

  // Utilitaire : Recupere la liste de faces connexes a iTrickyFace dans iCurrentTrickyFacesList
  void GetConnexFacesInList(CATLISTP(CATFace) &ioConnexFacesList, CATLISTP(CATFace) &iCurrentTrickyFacesList);
  void GetConnexFacesInListNewImpl(CATLISTP(CATFace) &ioConnexFacesList, CATLISTP(CATFace) &iCurrentTrickyFacesList);
  void GetConnexFacesInListOldImpl(CATLISTP(CATFace) &ioConnexFacesList, CATLISTP(CATFace) &iCurrentTrickyFacesList);

  // Utilitaire : Ces 2 faces sont-elles voisines ? (au moins une edge commune)
  short AreNeighborFaces(CATFace *iFace1, CATFace *iFace2);

  // Utilitaire : renvoie l'ensemble des faces de la liste et voisines de la face donnee
  void GetNeighborFacesInList( CATFace * iFace, CATLISTP(CATFace) & iListOfFaces, CATLISTP(CATFace) & oListOfNeighborFaces );

  // Utilitaire : iFace est-elle voisine de l'une des faces de iFaceList ?
  short IsFaceNeighborToOneFaceInList(CATFace *iFace, CATLISTP(CATFace) &iFaceList);

  void CreateProgressBarManager();

  void InitializeVoBTool( CATTopOperator * iOperator );

  void InitializeFirstRemoveFace();

  short RunSecondRemoveFace( CATBody           *  iInputBody,
                             CATLISTP(CATFace)  & iListOfFacesToRemove,
                             CATLISTP(CATFace)  & iListOfCandidateFaces,
                             CATLISTP(CATFace)  & iListOfLimitedFaces,
                             CATLISTP(CATBody)  & iListOfLimitingBodies,
                             CATListOfInt       & iListOfOriToKeep,
                             CATBody           *& oResultBody,
                             CATCGMJournalList *& oJournal,
                             CATLISTP(CATFace)  & oListOfTrickyFaces,
                             CATLISTP(CATFace)  & oReverseMatterOutputFaces,
                             short                iUpdateGlobalTrickyFacesList=1 );

  //-----------------------------------------------------------------------
  //- Private methods for LocalRemoveFace
  //-----------------------------------------------------------------------  

  // Tentative de Run optimise pour des operations tres locales
  // Renvoie 1 si ok, 0 sinon
  short TryLocalRemoveFace();

  // Tentative de Run optimise lorsque le contour de la selection forme une loop interne a une face
  // Renvoie 1 si ok, 0 sinon
  short TryInnerLoopRemoval();

  //-----------------------------------------------------------------------
  //- Private data members
  //-----------------------------------------------------------------------  

  // Operator generic name 
  static CATString    _OperatorName;

  CATBody           * _InitialBody;
  CATBody           * _ResultBody;
  short               _MatterDirection;
  short               _PartialRemoveFaceAllowed;

  CATRemoveFace *     _RemoveFace;

  short               _NbFacesToRemove;
  short               _NbCandidateFacesToRemove;
  ListPOfCATFace      _ListOfFacesToRemove;  
  ListPOfCATFace      _ListOfCandidateFacesToRemove;
  ListPOfCATFace      _AllTrickyFaces;
  CATListOfInt        _AllDiagList; // liste parallele a _AllTrickyFaces
  ListPOfCATFace      _ReverseMatterOutputFaces;

  short               _NbLimitingSurfaces;
  ListPOfCATFace      _ListOfLimitedFaces;
  ListPOfCATBody      _ListOfLimitingBodies;
  CATListOfInt        _ListOfOriToKeepForLimitingBody;

  short               _RoofRevit;
  short               _RemoveFilletsMode;
  short               _TwistDetection;

  short               _TryLocalRemoveFace; // Lancement du Run optimise pour les operations locales

  short               _CGMMode;

  short               _DeltaShapeComputation;

  short               _HasMaxExtrapolValue;
  double              _MaxExtrapolValue;

  CATBodyFreezeMode   _freezeMode; // Should we freeze the output body?

  CATCGMJournalInfo * _JournalInfo; // Information to add in topological journal events

  CATlsoProgressBarManager * _ProgressBarManager;  // A ProgressBar manager

  CATLONG32           _CallNum;

  // Classe amie
  friend class CATLocalRemoveFaceEngine;
};

// methodes INLINE

INLINE void CATRemoveFacePlus::SetCGMMode(short iCGMMode) {
  _CGMMode = iCGMMode; }

INLINE void CATRemoveFacePlus::SetTryLocalRemoveFace(short iTryLocalRemoveFace) {
  _TryLocalRemoveFace = iTryLocalRemoveFace; }

/**
* Creates a CATRemoveFacePlus operator.
* @param iTopData
* A pointer to the topological data.
* @param iBody
* A pointer to the body.
* @param iFacesToRemove
* The list of faces to be removed.
* @return 
* The operator.
*/
ExportedByThick CATRemoveFacePlus * CATCreateRemoveFacePlus( CATTopData        * iTopData,
                                                             CATBody           * iBody,
                                                             CATLISTP(CATFace) & iFacesToRemove );

#endif
