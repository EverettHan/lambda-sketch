// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATSectionSolverEngine:
// Utility for sweep section computation by external solver
//
//                                                    Nicolas LOCHARD
//=============================================================================
// Usage notes:
//
//
//=============================================================================
// 21 07 99 NLD,CPL Creation
// 18 01 01 CPL Set and Get Over Sampling
// 17 10 03 NLD Ajout NeedsFastEval()
// 19 10 05 JSX Ajout de GetSweepSolverEngine()
// 24 10 05 JSX Ajout de SetSweepSolverEngine()
// 03 05 06 NLD Mise en place d'une infrastructure pour CGMReplay
//              Ajout de
//              _SectionSolverEngineOperatorId
//              GetOperatorId()
//              GetSharedlib()
//              GetVersionNumber()
//              AddAllInputObjects()
//              WriteAllInput()
//              CATLoadInFactoryCATSectionSolverEngine()
//              Dump()
//              GetSharedlib()
//              La classe n'est plus virtuelle; ajout d'un constructeur, pour possibilit� de
//              l'utiliser comme receptacle d'un CATSweepSolverEngine, sans autre fonctionnalit� et donn�e
// 05 05 06 NLD Ajout iEngineOwnership � SetSweepSolverEngine()
//              (et ajout de _SweepSolverEngine, _SweepSolverOwnership;
//              il y a divergence de la signature avec la derivation CATSweepDebug, et doublon incoherent de donn�e
//              ce que je regle le 230118; commentaire tardif NLD230118)
// 09 05 06 NLD Ajout de GetListOfInputObjects()
// 22 05 07 JSX Implementation du GetEvalMode dans le cpp
// 27 10 09 NLD Ajout CATSectionSolverEvalMode pour enumeration des valeurs possibles
//              du mode d'evaluation
// 04 11 10 JSX Suppression de SetBreakInfo
// 10 03 11 NLD Specialisation eventuelle pour SweepUnspec
//              Ajout CATSectionSolverEvalMode_Unspec,
//              Ajout CATSectionSolverEvalMode_UnknownMode
//              Ajout ForceEvalMode() et _ForcedEvalMode
//              Ajout ModifyTransformation()
//              (et livraison d'une vieille architecture inactive non finalis�e de SubCGMReplay)
//              Toutes les m�thodes implement�es ici descendent dans l'impl�mentation
//              (SetOrientations(), SetTangents(), SetMovingFrame(), SetOverSampling(), GetOverSampling(),
//               NeedFastEval(), EvalSection(), EvalSectionData())
// 22/05/17 NLD Ajout SetMasterGuide()
// 26/03/18 NLD SetMovingFrame() en mode CATIPGM* est supprim� car d'aucune utilit� potentielle
// 06/05/19 NLD NeedFastEval() mode 2 (fort) (en essai)
//              Ajout �num�ration CATSectionSolverFastEvalMode
//              Ajout _FastEvalMode
//              Ajout argument iFastEvalMode � SetSweepSolverEngine()
//=============================================================================

#ifndef CATSectionSolverEngine_H
#define CATSectionSolverEngine_H

#include <CATIACGMLevel.h>

// remarque: les NurbsMultiForm ont ete reorientees avant l'appel
// a l'evaluateur de maniere a ce que la fin de l'une soit le debut de
// la suivante

// remarque: cette classe doit permettre 
//  - de realiser une implementation du sweep variationnel
//  - de realiser de maniere externe les mises en continuite pour les lofts

#include "CATGMOperatorsInterfaces.h"

#include "CATDataType.h"
#include "CATMathConstant.h"
#include "CATCGMVirtual.h"
#include "CATSweepSolverEngine.h"
#include "CATCGMOutput.h"
#include <CATString.h>
#include <CATCGMStream.h>
#ifdef CATSectionSolverEngine_ActiveCGMSubReplay
#include <CATCGMSubReplay.h>
#endif
class CATFrFNurbsMultiForm ;
class CATMathPlane ;
class CATMathVector;
// class CATIPGMFrFMovingFrame;
class CATIPGMBreakInfo;
class CATFrFMovingFrame;
class CATBreakInfo;
class CATICGMObject;
#include <CATListOfCATICGMObjects.h>
class CATGeoFactory;
//#include "CATSectionSolverData.h"
class CATSectionSolverData;
//class CATSweepSolverEngine;

//=============================================================================
// Modes d'evaluation
//=============================================================================
// Indique si l'evaluation est faite en utilisant CATSectionSolverData
// = -2 : UNKNOWN
// = -1 : Prise  en  compte  des tolerances en point et tangence  (GSD ne donne pas le "SamplingRatio")
// =  0 : mode avec Multiform    (Old Archi n'est plus utilise par GSD au moins inf a R16)
// =  1 : mode avec CATSectionSolverData (New archi)              (GSD donne un taux d'overSampling)
// =  2 : special sweep UNSPEC via ModifyTransformation           (ajout NLD100311)
//  600 : MODE V6 Eval NON Disponible (replay de sweep CDS ) il faut utiliser l'archi sweepCDS
//=============================================================================
// N.B valeurs en dur dans CATGSMSketchEval::GetEvalMode() 
typedef enum {CATSectionSolverEvalMode_OldWithMultiForm =  0, // ne pas changer cette valeur, utilisee en dur par l'appli
              CATSectionSolverEvalMode_WithOverSampling =  1, // ne pas changer cette valeur, utilisee en dur par l'appli
              CATSectionSolverEvalMode_WithTolerance    = -1, // ne pas changer cette valeur, utilisee en dur par l'appli
              CATSectionSolverEvalMode_Unspec           =  2, // ne pas utiliser la valeur mais l'identificateur
              CATSectionSolverEvalMode_UnknownMode      = -2, // ne pas utiliser la valeur mais l'identificateur
              CATSectionSolverEvalMode_V6ProtoCDS       =600
             }CATSectionSolverEvalMode;

//=============================================================================
// Modes relatif au FastEval (NeedFastEval)
//=============================================================================
// ATTENTION: susceptible d'enregistrement dans le stream CGMReplay
typedef enum {CATSectionSolverFastEvalMode_0None        = 0,
              CATSectionSolverFastEvalMode_1Light       = 1,
              CATSectionSolverFastEvalMode_2Forced      = 2  // Nouveau mode NLD060519 pour perfos sweep subgrade
             }CATSectionSolverFastEvalMode;
#define CATSectionSolverFastEvalMode_Default CATSectionSolverFastEvalMode_1Light
//=============================================================================
class ExportedByCATGMOperatorsInterfaces

CATSectionSolverEngine  : public CATCGMVirtual
 {
  CATCGMVirtualDeclareClass(CATSectionSolverEngine);

  // DATA ================================================
  private:
    CATSweepSolverEngine* _SweepSolverEngine ;
    int                   _SweepSolverOwnership ;
    double              * _ParamToDelete;             // JSX 030609 necessaire � InitializeSections pour faire comme la classe d�riv�e par GSD
    int                   _InstanceIndex;
    int                   _ForcedEvalMode;
    int                   _FastEvalMode;
  protected:
   static CATString  _SectionSolverEngineOperatorId ; // et non betement _OperatorId car on prefere avoir _OperatorId  dans la classe derivee

  // METHODS ================================================
  public: 

                            CATSectionSolverEngine() ;

    virtual                ~CATSectionSolverEngine() ;

    // 1) Methodes a appeler � l'initialisation de l'objet,
    //    avant de cheminer
    // les sections imposees sont definies au prealable, afin que le 
    // solveur puisse par exemple calculer globalement des lois
    // de deformation
    // on indique le parametre (du moving frame) pour chacune des sections
    // !! Attention a la gestoin memoire
    // iParamsForImposedSections : le tableau est donn� au solveur par l'appelant. le solveur fait le delete
    // iImposedSections          : le tableau est conserv" par l'appelant: l'appelant fait le delete
    //
    virtual void            InitializeSections(      int                     iNbImposedSections       ,
                                                     double*                 iParamsForImposedSections,
                                                     int                     iNbElementsPerSection    ,
                                                     CATFrFNurbsMultiForm*** iImposedSections         ,
                                                     CATBoolean              isClosed                 = CATBoolean(0) );

    // Passage des orientations de chaque profile
    // Taille du tableau: iNbImposedSections
    virtual void            SetOrientations   (      CATLONG32             * iOrientations            );

    // Passage du peigne de tangence aux profils extremites:
    //   iFirstOrLast= 0 pour le premier profil
    //   iFirstOrLast= 1 pour le dernier profil
    // Les peignes de tangence peuvent etre utilises 
    // pour le calcul global des lois.

    virtual void             SetTangents       (      int                     iFirstOrLast             ,
                                                const CATMathVector         * iVectors                 ); /* = 0 */;

    // Imposition du MovingFrame

    virtual void             SetMovingFrame    (      CATFrFMovingFrame     * iMovingFrame             ); /* = 0 */;
//  virtual void             SetMovingFrame    (      CATIPGMFrFMovingFrame * iMovingFrame             );

    // Nombre d'echantillons supplementaires a calculer 
    // lors du cheminement

    virtual void             SetOverSampling   (      CATLONG32               iOverSampling            );

    virtual CATLONG32        GetOverSampling   ();

    // 2) Methodes a appeler en cours de cheminement
    ////////////////////////////////////////////////

    // Les informations des BreakPoints ne sont pas toujours utiles.
    // Methode separee de l'Eval. 
    // JSX 041110 Suppression de SetBreakInfo
  //virtual void             SetBreakInfo      (      CATBreakInfo          * iBreakInfo               )
  //////  {}

    // Indique si l'evaluation lors du cheminement necessite un mode rapide
    // (sans solver) ou non
    // (defaut: CATSectionSolverFastEvalMode_1Light)
    // = CATSectionSolverFastEvalMode_0None :
    //      cheminement standard, utilisant le solver pour toutes
    //      les evaluations (comme pour un solver de debug)
    // = CATSectionSolverFastEvalMode_1Light:
    //      cheminement necessitant un mode rapide (comme pour beam)
    //      (mais peut etre desactiv� par le cheminement, en pr�sence d'un solver CDS)
    //      (mode faible)
    // = CATSectionSolverFastEvalMode_2Forced:
    //      cheminement necessitant un mode rapide (comme pour beam)
    //      (mais ne peut PAS etre desactiv� par le cheminement, en pr�sence d'un solver CDS)
    //      (mode fort, NLD060519)
    virtual CATLONG32        NeedFastEval      ();
  
    // Indique si l'evaluation est faite en utilisant CATSectionSolverData
    // voir enumeration CATSectionSolverEvalMode ci-dessus

    virtual CATLONG32        GetEvalMode       ();

    // A VOIR: passage des guides et des parametres sur celles-ci
    // virtual 
    // remarque: on supprimera le passage du plan une fois le movingframe export�
    //          (en fait le movingframe est connu de cette classe depuis des lustres,
    //           mais la derivation CATGSMSketchEval par exemple utilise toujours, au 170118,
    //           iSectionPlane (au lieu de l'obtenir par �valuation en iParam sur le movingframe)
    virtual void             EvalSection      (      double                  iParam                    ,
                                               const CATMathPlane          & iSectionPlane             ,
                                                     CATFrFNurbsMultiForm**  iInitialSection           ,
                                                     CATFrFNurbsMultiForm**  oFinalSection             )/* = 0 */ ;




    virtual void             EvalSectionData  (      double                  iParam                    ,
                                               const CATMathPlane          & iSectionPlane             ,
                                                     CATSectionSolverData *  ioSectionData             );

    // Force le mode d'evaluation
    // � utiliser en sweep unspec avec CATSectionSolverEvalMode_Unspec
    // pour typer le solver, pour lequel on utilisera alors
    // la methode ModifyTransformation() � chaque �valuation
    virtual void             ForceEvalMode    (      CATSectionSolverEvalMode iForcedEvalMode          );


    // Update by external constraints the current transformation, at current sweeping parameter,
    // transforming input profile to sweeping profile
    // (empty method will give standard result without external constraints)
    // (used only for unspec sweep, when ForceEvalMode(CATSectionSolverEvalMode_Unspec) has
    // been done on dedicated solver
    virtual void             ModifyTransformation
                                              (      double                  iT                        , // current sweeping parameter (between 0.0 and 1.0)
                                               const CATMathAxis&            iLocalAxis                , // current local axis system
                                                     CATCurve*               iGuideCurve               , // current guiding curve
                                               const CATCrvParam&            iGuideCrvParam            , // current parameter on guide
                                                     CATMathTransformation & ioTransfo                   // current transformation
                                              );

    // Get d'un SweepSolver
    // Cette methode permet de passer le driver CDS au Sweep,
    // On conserve cependant l'architecture actuelle :
    //  on peut toujours evaluer avec la classe de GSD d�riv�e de SectionSolverEngine
    // mais si on le peut, on branche CDS grace au SweepSolverEngine qui pointe sur le driver (puis sur CDS)
    //
    // SweepSolverEngine est virtuelle il faut instancier la classe deriv�e d�finie dans le driver CDS
    //
    // en retour si oEngine est null, il n'y a pas de SweepSolver
    virtual void             GetSweepSolverEngine(   CATSweepSolverEngine *& oEngine                   ) ;

    // Definition du SweepSolver
    // - eventuellement on en donne la propriet� � cet objet
    // - eventuellement on force le mode FastEval qui sera rendu par NeedFastEval()
    virtual void             SetSweepSolverEngine(   CATSweepSolverEngine *  iEngine                   ,
                                                     int                     iSweepSolverOwnership     = 0,
                                                     int                     iFastEvalMode             = CATSectionSolverFastEvalMode_Default) ;

    // Changement de guide (en cas d'extrapolation par exemple)
    // Protocole et regles d'appel en cours de definition;
    // par commodite pour le Solver on passe aussi la guide de reference,
    // dont le stockage dans le solve n'est donc pas necessaire. NLD290517
    virtual void             SetMasterGuide      (   CATFrFCompositeCurve *  iGuideRef                 ,
                                                     CATFrFCompositeCurve *  iGuideNew                 );

    // Methodes pour CGMReplay
    // -----------------------
    virtual const CATString* GetOperatorId       () ;

    // Donne le nom de la sharedlib dans laquelle il faut charger cet objet
    virtual void             GetSharedlib        (   char                 *& SharedLib                 ) ;

    // Numero de version du stream
    virtual short            GetVersionNumber    () ;

    // Methode ajoutant tous les elements d'entr�e, via des appels � la methode AddInputObject
    // pour chaque element d'entree InputObject
    // la methode devra etre appel�e avec comme arguments InputObject et ioDataForCall
    virtual void             AddAllInputObjects  (   void(*AddInputObject)(CATICGMObject* iiCGMObject, void* iiData),
                                                     void                 *  ioDataForCall             ) ;
    // On peut aussi implementer la methode GetListOfInputObjects() rendant la liste des objets en entr�e;
    // l'implementation par defaut de AddAllInputObjects() utilise cette m�thode
    #define CATSectionSolverEngine_ListPOfCATICGMObject CATLISTP(CATICGMObject)
    virtual CATSectionSolverEngine_ListPOfCATICGMObject GetListOfInputObjects() ;

    // Methode ecrivant les entr�es dans le Stream
    virtual void             WriteAllInput       (   CATCGMStream          & Str                       ) ;

    virtual void             Dump                (   CATCGMOutput          & os                        ) ;

    #ifdef CATSectionSolverEngine_ActiveCGMSubReplay
    virtual CATCGMSubReplay* GetCGMSubReplay()
    {
     return 0 ;
    }
    #endif

 } ;


#ifdef CATSectionSolverEngine_ActiveCGMSubReplay
class ExportedByFrFAdvancedOpeSur CATSectionSolverEngineSubReplay  : public CATCGMSubReplay
 {
  friend class CATSectionSolverEngine ;
  private:
    CATSectionSolverEngine* _SectionSolverEngine ;

  protected:
   static CATString         _SectionSolverEngineOperatorId ; // et non betement _OperatorId car on prefere avoir _OperatorId  dans la classe derivee

  public: 

    CATSectionSolverEngineSubReplay(CATSectionSolverEngine* iSectionSolverEngine)
    {
     _SectionSolverEngine = iSectionSolverEngine ;
    } ;

    ~CATSectionSolverEngineSubReplay()
    {
     _SectionSolverEngine = NULL ;
    } ;
    virtual void CATSectionSolverEngineSubReplay::Dump(CATCGMOutput& os)
    {
     //cgmout<<_SectionSolverEngine->_SectionSolverEngineOperatorId<<cgmendl ;
    }
 } ;
#endif

 //
 // chargement de l'operateur, grace au stream et aux donnees presentes dans la factory
 //===================================================================
 // Definition du type de la fonction
 extern "C"
 {
  typedef CATSectionSolverEngine * CATLoadInFactoryCATSectionSolverEngineExternFunction(      CATGeoFactory* iFactory       ,
                                                                                              CATCGMStream & Str            ,
                                                                                        const short          VersionOfStream);
 }
 // definition de la fonction
 extern "C" 
   ExportedByCATGMOperatorsInterfaces 
          CATSectionSolverEngine* CATLoadInFactoryCATSectionSolverEngine               (      CATGeoFactory* iFactory       ,
                                                                                              CATCGMStream & Str            ,
                                                                                        const short          VersionOfStream);
 //CATLoadInFactoryCATSectionSolverEngineExternFunction CATLoadInFactoryCATSectionSolverEngine ;
#endif
