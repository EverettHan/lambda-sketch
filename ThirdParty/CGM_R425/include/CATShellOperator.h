#ifndef CATShellOperator_H
#define CATShellOperator_H
//---------------------------------------------------------------------
// CATShellOperator
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
#include "CATMathInline.h"
#include "ListPOfCATFace.h"
#include "CATListOfInt.h"
#include "Thick.h"
#include "CATCGMJournalInfo.h"
#include "CATTopOperator.h"
#include "CATTopologicalOperator.h"
#include "CATSubdIntersectingFunction.h"
#include "CATString.h"
#include "CATShellOperatorExt.h"

class CATBody;
class CATFace;
class CATOpThick;
class CAThkPilot;
class CATCGMJournalList;
class CATCGMJournalItem;
class CATTopData;
class CAThkShellScenario;
class CATShlXFacAttrib;
class CATlsoProgressBarManager;

class ExportedByThick CATShellOperator : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATShellOperator);
public:
  
  // constructeur a partir d'un CATBody et 2 valeurs d'offsets a appliquer
  //  par defaut a toutes les faces (aucune face d'ouverture par defaut) 
  CATShellOperator(CATBody           * iBody, 
                   CATLength           iInternalOffsetValue = 0.0,
                   CATLength           iExternalOffsetValue = 0.0,
                   CATCGMJournalList * iJournal=NULL );
  CATShellOperator(CATBody           * iBody,
                   CATTopData        * iTopData,
                   CATLength           iInternalOffsetValue = 0.0,
                   CATLength           iExternalOffsetValue = 0.0 );
  
  // copy constructeur et affectation (lancent une exception)
  // ne pas les appeler
  CATShellOperator(const CATShellOperator & iShellOrig);
  CATShellOperator & operator= (const CATShellOperator & iShellRight);

  // destructeur (le body resultat est conserve, mais on libere la memoire)
  virtual ~CATShellOperator();

  // remise a jour des valeurs d'offset
  INLINE void SetInternalDefaultOffset(CATLength iInternalOffsetValue);
  INLINE void SetExternalDefaultOffset(CATLength iExternalOffsetValue);

  // Ajout de faces dans la liste privee de faces d'ouverture _OpenFaceList
  void AppendOpening(const CATLISTP(CATFace) &iOpenFaces);

  // Ajout de la liste des faces d'ouverture propagee sur le body initial
  // quand on fait un regularisation et que l'option ConstantThickness est off
  // (ie booleen avec le body initial)
  void AppendUnregularizedOpening(const CATLISTP(CATFace) &iUnregularizedOpenFaces);

  // Ajout d'une liste de faces a offsets speciaux
  // dans le tableau prive de listes _SpecialFaceListPtr
  // et enregistrement de ces offsets dans les tableaux _SpecialOffsetPtr[]
  void AppendSpecialOffset(const CATLISTP(CATFace) &iSpecOffsetFaces, 
                           CATLength iInternSpecialOffsetValue,
                           CATLength iExternSpecialOffsetValue);

  // Fonction de filtre des intersections booleennes de faces pour un passage
  // par pointeur sur fonction, en remplacement des anciens attributs
  static CATSubdIntersectionType FacesIntersectionType(CATFace* iFace1, CATFace* iFace2);


  // Execution de l'operation Shell (RunOperator ne doit servir qu'en mode
  // CGMReplay)
  int Run();


  // Recuperation du Body initial 
  CATBody* GetInitialBody();

  // body non regularise pour faire le booleen avec le vrai body initial
  // quand l'option ConstantThickness est off dans l'operateur CATShellOperatorPlus
  // avec regularisation.
  void SetUnregularizedBody(CATBody* iUnregularizedBody);

  CATBody* GetUnregularizedBody();

/**
 * @nodoc
 * @param iFacesToRemove
 * @param iExternalThick (0/1)
 * 
 */
  void SetMandatoryFacesToRemove( const CATLISTP(CATFace) &iFacesToRemove,
                                  short iExternalThick );

  void GetOpenFaceListAfterPropag(CATLISTP(CATFace) &oOpenFaces);

/**
 * @nodoc
 * @param oTrickyFaces
 * @param iExternalThick (0/1)
 * 
 */
  void GetTrickyFaces(CATLISTP(CATFace) &oTrickyFaces, short iExternalThick, short iMixRegulDiagForbidden=0);

/**
 * @nodoc
 * @param oFacesToIgnore 
 * @param iExternalThick (0/1)
 * 
 */
  void GetFacesToIgnore(CATLISTP(CATFace) &oFacesToIgnore, short iExternalThick);

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
 * @param iExternalThick (0/1)
 * 
 */
  void GetFacesToRegularise(CATLISTP(CATFace) &oFacesToRegularise, CATListOfInt &oDiag, short iExternalThick);

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
  * @param oNotInverseRazorBladeFaces 
  * 
  */
  void GetInitReverseMatterFaces(CATLISTP(CATFace) &oInitReverseMatterFaces);

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
  * Defines whether propagation of opening faces should be activated or not
  * By default, it is enabled.
  * @param iPropagation
  * </dl>
  */
 void SetOpeningFacesPropagation(CATBoolean iPropagation);

 /**
  * Defines whether propagation of special offset faces should be activated or not
  * By default, it is enabled.
  * @param iPropagation
  * </dl>
  */
 void SetSpecialOffsetFacesPropagation(CATBoolean iPropagation);

  /**
  * Defines whether geometrical and topological simplification in post-treatment 
  *   should be activated or not.
  * By default, it is disabled.
  * @param iLevel
  * </dl>
  */
  void SetSimplificationLevel(short iLevel);
  short GetSimplificationLevel() const;

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

   /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual void Dump( CATCGMOutput& os ) ;

   /** @nodoc @nocgmitf ID pour CGMReplay */
  static const CATString * GetDefaultOperatorId() { return & _OperatorName; };


   /* @nodoc @nocgmitf */
  virtual void ReadInput(CATCGMStream  & ioStream,int VersionOfStream, short iNumReplayVersion=1);

  /* @nodoc @nocgmitf */
  virtual int RunOperator();

  short _CurrentThickIndex;

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
  //virtual CATShellOperatorContextForFastRun* GetShellOperatorContextForFastRun(CATBoolean iGetOnly = FALSE);


	//KY1 : 10-12-2010	
	/**	@nodoc @nocgmitf */
	const  CATString  *GetOperatorId();
	
private:

  // Operator generic name 
  static CATString _OperatorName;

  // methode d'attribution d'offsets sur toutes les faces du body
  // iThickInd valant 0 pour la peau interieure (1er  thickness)
  // iThickInd valant 1 pour la peau exterieure (2eme thickness)
  void PutThickOffsetAttributeOnFaces(short iThickInd);

  // Prise en compte des faces a retirer des offset pour gerer
  // les degenerescences locales eventuelles
  // on ressort une valeur 1 s'il y a des faces a retirer.
  short ActivateFacesToRemove( short iThickNum );

  // Methodes de nettoyage des B-Reps apres le booleen (attributs)
  CATBoolean ComputeNeedForBiOffsetFaces(CATOpThick & iThickOp);
  void PutAttributeForBooleanOnBiOffsetFaces(CATOpThick & iThickOp);
  void DeleteAttributesForBoolean();
  void DeleteAttributesOnInitialBody();
  void DeleteAttributesOnResultBodies( short * iThicknessUtile );

  void JournalPostProcessor( CATCGMJournalList * iReport,
                             CATCGMJournalList * iTopLevelReport );
  CATCGMJournalItem * GetDeletionJournalItem( CATCGMJournalList * iTopLevelReport,
                                              CATGeometry       * iGeometry );


  // body initial
  CATBody   * _InitialBody;

  CATBody   * _UnregularizedBody;

  // maitrise du Pilot par l'operateur courant
  // qui le "prete" temporairement aux 2 OpThick
  CAThkPilot * _Pilot;

  // Operateur Thickness :
  CATOpThick * _ThickOp[2];

  // Option de non-propagation des faces
  CATBoolean _OpeningFacesPropagation;

  CATBoolean _SpecialOffsetFacesPropagation;

  // Scenario
  CAThkShellScenario * _ShellScenario;

  CATLength   _InternalOffset,_ExternalOffset;

  CATLISTP(CATFace) _OpenFaceList;

  // Liste de toutes les faces d'ouverture, une fois la propagation des 
  // faces selectionnees par l'utilisateur faite (remplie au debut de shell
  // dans SetOffset)
  CATLISTP(CATFace) _OpenFaceListAfterPropagation;

  // liste deja propagee de faces d'ouverture pour le 2nd appel a l'operateur Shell
  // quand on fait une regularisation et que l'option ConstantThickness est off 
  // (booleen avec body non regularise)
  CATLISTP(CATFace) _UnregularizedOpenFaces;

  // Attribut qui sert a ne declencher les calculs d'intersections de faces
  // que sur les faces d'ouverture (pour optimiser l'utilisation du booleen).
  //int  _AttributeKeyForFaceFaceIntersections;  
  // l'ancien attribut est desormais remplace par un attribut CGM nouvelle generation
  // Un seul et meme attribut sera cree pour toutes les faces d'ouverture et leurs images.
  CATShlXFacAttrib * _XFacAttrib;

  // Attribut qui sert determiner le positionnement face/volume logiquement
  int  _AttributeKeyForFaceVsVolPosition;

  // JBX 18/8/99 Pb mlk, on gere la creation et la destruction des journalinfo.
  CATCGMJournalInfo * _JournalInfo[2];

  // Operateur topologique pour l' operation booleenne de soustraction du shell.
  // Je mets cette donnee ici pour qu' elle se detruise bien apres Throw sous
  // UNIX.
  CATTopologicalOperator * _TopologicalOperator;

  // Journal du booleen
  CATCGMJournalList * _BooleanJournal;

  // Journal de l'offset
  CATCGMJournalList * _LocalJournal;

  // Gestion des progress bars
  CATlsoProgressBarManager * _ProgressBarManager;

  // Dump
  friend CATCGMOutput& operator<< (CATCGMOutput& s, const CATShellOperator& iOpe);

};

// methodes INLINE :
ExportedByThick INLINE void CATShellOperator::SetInternalDefaultOffset(CATLength iInternalOffset)
     {_InternalOffset = iInternalOffset; }
ExportedByThick INLINE void CATShellOperator::SetExternalDefaultOffset(CATLength iExternalOffset)
     {_ExternalOffset = iExternalOffset; }

#endif

