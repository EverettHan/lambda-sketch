// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
//
// CATSweepSolverEngine:
// It is a service to access a driver.
// The driver has to derive this class
//
//                                                    Jean SALOUX
//=============================================================================
// Usage notes:
//
//
//=============================================================================
// 13 10 05 JSX,
//          NLD Creation
// 03 05 06 NLD Mise en place d'une infrastructure pour CGMReplay
//              Ajout de
//              _SweepSolverEngineOperatorId
//              GetOperatorId()
//              GetVersionNumber()
//              AddAllInputObjects()
//              WriteAllInput()
//              CATLoadInFactoryCATSweepSolverEngine()
// 09 05 06 NLD Ajout de GetListOfInputObjects()
// 14 09 06 NLD Pour CDS, ajout argument iCoupling a SetMovingFrame()
//              la methode n'est plus virtuelle pure  pour eviter probleme
//              de compilation des classes filles a cause du changement de signature
// 31 05 07 JSX Suppression de EvalForm 
// 03 06 07 JSX Ajout de SetCGMEnv
// 07 06 07 jsx SetLocalFrame
// 08 06 07 jsx Ajout argument iDCcv � SetMovingFrame()
// 15 06 07 JSX Ajout SetInitialSection
// 09 09 09 JSX Ajout GetPrecomputedParams
// 29 09 09 JSX Ajout GetConstraintArray
// 02 10 09 cpt Deplacement dans GMOperatorsInterfaces
// 27 03 13 NLD Definition de CATCDSMarchingLevel, CATCDSMarchingLevel500, CATCDSMarchingLevel600
// 15 01 18 NLD Smart indent
// 16 01 18 NLD SetMovingFrame() redevient virtuelle pure
//              les deux seules derivations �tant desormais conformes � la signature actuelle
//              SetMovingFrame() en mode CATIPGM* est supprim� car d'aucune utilit� potentielle
// 24 01 18 NLD Suppression de Eval() (obsolete sans impl�mentation depuis 2006)
// 21 03 18 NLD Ajout GetLaws() pour homogeneisation topologique RoadDesign
// 28 04 20 NLD Ajout SetMinWLawMaxWLaw()
// 15 03 21 NLD Ajout argument oLawsDefinedOnFullSpine � GetLaws()
//=============================================================================

#ifndef CATSweepSolverEngine_H
#define CATSweepSolverEngine_H

#include "CATGMOperatorsInterfaces.h"
#include "CATCGMVirtual.h"
//#include "CATMathCurveFunction.h"
//#include "CATListOfCATMathCurveFunction.h" 
//#include "CATListOfInt.h"
//#include "ListVOfLong.h"
//#include "CATCurve.h"
#include "CATBoolean.h"
#include <CATString.h>

class CATMathPlane ;
class CATMathVector;
class CATMathInterval;

class CATKnotVector;
class CATFrFNurbsMultiForm ;
class CATGeoFactory;
class CATICGMObject;
class CATBody;

class CATFrFMovingFrame;
//class CATIPGMFrFMovingFrame;
class CATFrFCoupling;
class CATIPGMFrFCoupling;
class CATFrFCompositeCurve;
class CATFrFSmoothedComb;

#include <CATCGMStream.h>
#include <CATCGMOutput.h>

#define CATSweepSolverEngine_ListPOfCATICGMObject CATLISTP(CATICGMObject)


class ExportedByCATGMOperatorsInterfaces CATSweepSolverEngine : public CATCGMVirtual
  {
  CATCGMVirtualDeclareClass(CATSweepSolverEngine);

   protected:

   static CATString  _SweepSolverEngineOperatorId ; // et non betement _OperatorId car on prefere avoir _OperatorId  dans la classe derivee

   public: 

    virtual           ~CATSweepSolverEngine();

    // 
    virtual void       SetCGMEnv           (CATSoftwareConfiguration  *  iConfig             ,
                                            CATGeoFactory             *  iFactory            ) = 0;

    // Determine si le solver peut etre utilis� pour l'evaluation
    // sinon la construction du sweep utilise CATSectionSolverEngine pour evaluer
  ///  virtual CATBoolean IsAValidCase() = 0;


    // Domaine ( defaut 0 1)
    virtual void       SetMaxDomain        (CATMathInterval           *  iMaxDom             ) = 0;

    //
    // Determine le MovingFrame ( apres lissage, donc donn� par CSS)
    //
    // N.B iDCcv est le coupling index de la guide origine; semble-t-il (voir CATSweepSpineAxis)                 NLD160118
    virtual void       SetMovingFrame      (CATFrFMovingFrame         *  iSweepMvFrame       ,
                                            CATFrFCoupling            *  iCoupling           ,
                                            CATLONG32                    iDCcv               ) = 0; // redevient virtuelle pure NLD160118

    // A propos du SetMovingFrame() avec des CATIPGM*
    // introduction CPT150906
    // suppression  NLD160118
    // n'a jamais pu servir a rien car c'est le moteur du loft CATFrFSweepCrvCrvCx2::InitiateAbstractProfile_RunBeamSolver()
    // qui renseigne le SolverEngine, et il ne connait pas et ne veut pas connaitre les CATIPGM
    // il fait l'appel avec un vrai MovingFrame et un vrai Coupling
    // la methode n'est d'ailleurs pas implement�e dans la seule derivation utile CATCDSEngine
    // c'est d'ailleurs certainement � cause de cette m�thode qu'existe ce maudit CATIPGMFrFMovingFrame
    // et qu'il existe un GetIMovingFrame dans l'op�rateur de sweep
//  virtual void       SetMovingFrame      (CATIPGMFrFMovingFrame     *  iSweepMvFrame       ,
    //                                      CATIPGMFrFCoupling        *  iCoupling           ,
    //                                      CATLONG32                    iDCcv               );
    //

    // 
    // Determine le LocalFrame
    //
    virtual void       SetLocalFrame       (CATFrFSmoothedComb        *  iSmoothNormal       ,
                                            CATFrFCompositeCurve      *  iNormalCCV          );
    // 
    // Remplacement des guides
    // 
    // iOldGuides Tableau des guides connues du driver
    // iNewGuides Tableau des guides a utiliser ( apres relimitation, smooth, ..) 
    virtual void       SetNewGuides        (CATLONG32                    iNbGuides           ,
                                            CATBody                  **  iOldGuide           ,
                                            CATBody                  **  iNewGuide           ) = 0;


    // Definition de la transformation du profile en point 
    // 
    virtual void       SetProfileKnotVector(CATLONG32                    iNbProfileEdges     ,
                                            CATKnotVector            **  iTabKnotVector      ) = 0;

    // SetInit
    virtual void       SetInitialSection   (int                          iNbInitialSections  ,
                                            double                    *  iSectionsParams     ,
                                            int                          iNbProfileEdges     ,
                                            CATFrFNurbsMultiForm    ***  iImposedSections    ,
                                            CATBoolean                   isClosed            )
    {
     ;
    };

    // Laws management
    typedef enum {GetAllLaws            = 1,
                  GetHomogenizationLaws = 2
                 }GetLawQuery;
    // La requete sp�ciale GetHomogenizationLaws permet au solver les lois qui doivent etre prises
    // en compte lors de l'homog�n�isation topologique pour imposer des d�coupes
    // (aux points de non continuit� C1 des lois composites)
    // A noter:
    // - de mani�re g�n�rale les lois du sweep/loft sont d�finies sur un domaine [0, 1]
    //   en correspondance avec la spine relimit�e par les guides lors de l'homog�n�isation
    // - il est cependant possible, et commode, dans les solvers de d�finir les lois sur un domaine [0, 1]
    //   en correspondance avec la spine compl�te
    //   c'est le param�tre de sortie oLawsDefinedOnFullSpine qui va l'indiquer
    // Si l'homog�n�isation restreint le domaine, (raccourcissement par les guides, par les profils extremes),
    // la m�thode SetMinWLawMaxWLaw() sera appel�e.
    // Ceci permettra le cas �ch�ant au solver de transformer le param�tre d'appel
    // de EvalCompositeCurve(), variant sur un domaine [0, 1] correspondant, lui, � la spine r�duite homog�n�is�e,
    // en un param�tre initial pour l'�valuation des lois
    virtual void       GetLaws             (GetLawQuery                   iLawQuery          ,
                                            CATListPV                   & oLaws              ,
                                            int                         & oLawsDefinedOnFullSpine)
    {
     oLaws.RemoveAll();
    }

    //
    // Solve 
    //
    virtual void       Solve               (CATLONG32                  &  oResultCode        ) = 0;

    // Evaluation en un parametre. A utiliser apres l'appel a solve uniquement !
    // iT parametre du MovingFrame
    // oPt n points 3D {x1,y1,z1,x2,y2,z2,x3 ../.. yn,zn} 
    // n est determin� par le nombre de points de controle sur l'ensemble des vecteurs nodaux 
    // OBSOLETE aucun appel, aucune derivation vraiment cod�e. NLD240118
    // a �t� remplac� par EvalForm(JSXxx0507) (suppression (JSX310507))
    // puis par EvalCompositeCurve(JSX080306)
    // je d�branche NLD240118
//  virtual void       Eval                (double                        iT                 ,
//                                          double                     *  oPt                ) = 0;

    // Eval MultiForm
    // oFinalSection est detruite par l'appelant
    // SUPPRESSION JSX 310507 
 // virtual void       EvalForm            (double                        iT                 ,
    //                                      CATFrFNurbsMultiForm      **  iInitialSection    ,
    //                                      CATFrFNurbsMultiForm      **  oFinalSection      )
    //            {return;};

    virtual void       EvalCompositeCurve   (double                       iT                 ,
                                             CATFrFCompositeCurve      *& oFinalSection      )
      {
       return;
      };

  //virtual CATBoolean EvalMathCurves       (double                       iT                 ,
  //                                     CATLISTP(CATMathCurveFunction) & ListMathCurve      ,
  //                                     CATListOfDouble                & ListOfLimits       ,
  //                                     CATListOfLong                  & ListOrientation    )
  //  {return FALSE;};


    // Info sur les tolerances pour chaque point du profil
    virtual CATBoolean GetConstraintArray   (int                       *& ioPointsContinuity ,
                                             int                        & ioNbPoints         ) = 0;


    virtual void       GetPrecomputedParams (CATListOfDouble            & L                  );

    // valeur du niveau de marching CDS (enumeration issue de CATFrFSweepCrvCrvCx2.cpp         le 270313)
    //               N.B ne pas confondre ce 600 et celui defini  dans CATSectionSolverEngine.
    //                   en revanche c'est celui que   je definis dans CATSweepSolverEngine    le 270313
    //                                                                                Nicolas

    typedef enum {CATCDSMarchingLevelNone =   1,// Ajout NLD230118
                  CATCDSMarchingLevel500  = 500,// ne pas changer. valeur definie aussi dans CDS
                  CATCDSMarchingLevel600  = 600 // ne pas changer. valeur definie aussi dans CDS
                 }
                  CATCDSMarchingLevel;

    typedef enum {Validate,            //-Interroge sur la validit� du solveur (
                  MarchingLevel,       //-Interroge le level du marching:
                                       //     1: (mettre 0?) hors CDS ajout pour mise en coherence de tous les sources. NLD230118
                                       //   500: sert a valider avec un cgmreplay l'archi V5 en la simulant ==> non officiel
                                       //   6xx: (600) niveau v6. a priori le solveur n'a pas a imposer le mode de marching qui est un soft distinct
                                       //                         on ne devrait pas modifier le niveau V6.
                  RatioTol_DEPRECATED, //-
                  Discernment          //-Resolution (sur le parametre d'evaluation)
                                       // rend en g�n�ral     l'entier 0
                                       // rend sur declaratif l'entier 1 et dans le double la valeur de Discernment
                                       // commentaires compl�mentaires NLD230118
                 } InfoType;

    virtual       CATBoolean  SetGetInfo    (CATLONG32                    iS1G0              , // (1 : Set, 0 : Get)
                                             InfoType                     iInfoType          ,
                                             CATLONG32                 *& odataLONG32        ,
                                             double                    *& odataDOUBLE        ) =0;

    // Red�finition de l'intervalle d'application des lois
    // (post homog�n�isation)
    // pour reparam�trage implicite de lois globales sur le sous-domaine utile
    // USAGE RESERVE SWEEP/NLD
    // en pratique une �valuation demand�e par l'operateur sweep en iT dans [0, 1] en bijection
    // avec la spine relimit�e pourra alors �ventuellement etre appliqu�e en
    // ParamLaw = _MinWLaw + (iT * (iMaxWLaw - iMinWLaw)
    // selon le comportement d�fini dans le solver d�riv�
    virtual       void SetMinWLawMaxWLaw     (double                      iMinWLaw         ,
                                              double                      iMaxWLaw         )
    {
    }

    //
    // Methodes pour CGMReplay
    // 
    virtual const CATString * GetOperatorId () ;

    // Donne le nom de la sharedlib dans laquelle il faut charger cet objet
    virtual       void        GetSharedlib  (char                      *& sharedlib          ) ;

    // Numero de version du stream
    virtual       short       GetVersionNumber() ;

    // Methode ajoutant tous les elements d'entr�e, via des appels � la methode AddInputObject
    // pour chaque element d'entree InputObject
    // la methode devra etre appel�e avec comme arguments InputObject et ioDataForCall
    virtual       void        AddAllInputObjects(void(*AddInputObject)(CATICGMObject* iiCGMObject, void* iiData),
                                                 void* ioDataForCall);

    // On peut aussi implementer la methode GetListOfInputObjects() rendant la liste des objets en entr�e;
    // l'implementation par defaut de AddAllInputObjects() utilise cette m�thode

    virtual       CATSweepSolverEngine_ListPOfCATICGMObject
                              GetListOfInputObjects() ;

    // Methode ecrivant les entr�es dans le Stream
    virtual       void        WriteAllInput(CATCGMStream                & Str                ) ;

    // Dump des donn�es de l'operateur
    virtual       void        Dump         (CATCGMOutput                & os                 ) ;
  } ;
 //
 // chargement de l'operateur, grace au stream et aux donnees presentes dans la factory
 // Definition du type de la fonction
 extern "C"  
 {
  typedef CATSweepSolverEngine * CATLoadInFactoryCATSweepSolverEngineExternFunction(      CATGeoFactory* iFactory,
                                                                                          CATCGMStream & Str     ,
                                                                                    const short          VersionOfStream);
 }
 // definition de la fonction
 extern "C" ExportedByCATGMOperatorsInterfaces CATSweepSolverEngine*
 CATLoadInFactoryCATSweepSolverEngine(CATGeoFactory* iFactory, CATCGMStream &Str, const short VersionOfStream) ;
 //CATLoadInFactoryCATSweepSolverEngineExternFunction CATLoadInFactoryCATSweepSolverEngine ;
#endif
