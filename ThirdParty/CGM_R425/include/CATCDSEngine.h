//===================================================================
// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCDSEngine.h
// CDS driver for Variational Sweep
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// 25 10 05 FCX Creation                                          FCX
// 07 06 07 jsx SetLocalFrame
// 30 11 16 ??? (FIXPARTCDSP2)
//              Ajout CATCDSOverride
// 24 01 18 NLD Suppression Eval() inactif depuis 2006
//              Suppression SetInitialSection() à deux arguments qui n'existe plus dans la classe mère
//              Reordonnancement conforme à la classe mère
//              Mise au propre   conforme à la classe mère de ce pur chantier
// 14 12 18 NLD Remplacement des marquages CATCDSOverride par CATCDSEngineOverriding
//              (marquages qui étaient presents sur toutes les méthodes mis à part constructeur et destructeur)
//              pour retour à la comparabilité avec CATCDSEngineImp.h
//              qui en est l'implémentation, mais n'en derive pas
//===================================================================

#ifndef CATCDSEngine_H
#define CATCDSEngine_H

#include "CATCDSVirtual.h"
#include "CATBoolean.h"
#include "VarSweepDriver.h"
#include "CATSweepSolverEngine.h"

class CATCDSVarSweepDriver;
class CATFrFMovingFrame;
class CATKnotVector;
class CATBody;
class CATMathInterval;
class CATCDSEngineImp;
class CATFrFNurbsMultiForm;
class CATFrFCompositeCurve;
class CATFrFCoupling;


// pour construire depuis un fichier
//CATLoadInFactoryXXX
// ou XXX designe le nom de ta classe derivee, rendu par GetOperatorId()

class CATCDSEngine;

#define CATLoadInFactoryCATCDSEngineDeclaration                                  \
CATCDSEngine* CATLoadInFactoryCATCDSEngine(      CATGeoFactory*  iFactory       ,\
                                                 CATCGMStream  & Str            ,\
                                           const short           VersionOfStream)//

extern "C"  ExportedByVarSweepDriver CATLoadInFactoryCATCDSEngineDeclaration;

#define CATCDSEngineOverriding CATCDSOverride // ici pour override de la classe CATSweepSolverEngine; N.B #undef à la fin du fichier

class ExportedByVarSweepDriver CATCDSEngine : public CATSweepSolverEngine
{
public: 
                       CATCDSEngine        (CATCDSVarSweepDriver      * iDriver              ,
                                            CATBoolean                  iToBeRemoved         = FALSE);

  virtual             ~CATCDSEngine();

            void       SetCGMEnv           (CATSoftwareConfiguration  *  iConfig             ,
                                            CATGeoFactory             *  iFactory            ) CATCDSEngineOverriding ;


    // Domaine ( defaut 0 1)
            void       SetMaxDomain        (CATMathInterval           *  iMaxDom             ) CATCDSEngineOverriding ;

            void       SetMovingFrame      (CATFrFMovingFrame         *  iSweepMvFrame       ,
                                            CATFrFCoupling            *  iCoupling           ,
                                            CATLONG32                    IdCCV               ) CATCDSEngineOverriding ;
    // 
    // Determine le LocalFrame
    //
            void       SetLocalFrame       (CATFrFSmoothedComb        *  iSmoothNormal       ,
                                            CATFrFCompositeCurve      *  iNormalCCV          ) CATCDSEngineOverriding ;

    // 
    // Remplacement des guides
    // 
    // iOldGuides Tableau des guides connues du driver
    // iNewGuides Tableau des guides a utiliser ( apres relimitation, smooth, ..) 
            void       SetNewGuides        (CATLONG32                    iNbGuides           ,
                                            CATBody                  **  iOldGuide           ,
                                            CATBody                  **  iNewGuide           ) CATCDSEngineOverriding ;

    // Definition de la transformation du profile en point 
    // 
            void       SetProfileKnotVector(CATLONG32                    iNbProfileEdges     ,
                                            CATKnotVector            **  iTabKnotVector      ) CATCDSEngineOverriding ;

    // SetInitialSection
            void       SetInitialSection   (int                          iNbInitialSections  ,
                                            double                    *  iSectionsParams     ,
                                            int                          iNbProfileEdges     ,
                                            CATFrFNurbsMultiForm    ***  iImposedSections    ,
                                            CATBoolean                   isClosed            ) CATCDSEngineOverriding ;

    //
    // Solve 
    //
            void       Solve               (CATLONG32                  &  oResultCode        ) CATCDSEngineOverriding ;

    // Evals
            void       EvalCompositeCurve   (double                       iT                 ,
                                             CATFrFCompositeCurve      *& oFinalSection      ) CATCDSEngineOverriding ;

    // Info sur les tolerances pour chaque point du profil
            CATBoolean GetConstraintArray   (int                       *& ioPointsContinuity ,
                                             int                        & ioNbPoints         ) CATCDSEngineOverriding ;

            void       GetPrecomputedParams (CATListOfDouble            & L                  ) CATCDSEngineOverriding ;


  //NLD240118 typedef enum {a,b} SweepDriverInfoType;
            CATBoolean SetGetInfo           (CATLONG32                    iS1G0              , // (1 : Set, 0 : Get)
                                             InfoType                     iInfoType          ,
                                             CATLONG32                 *& odataLONG32        ,
                                             double                    *& odataDOUBLE        ) CATCDSEngineOverriding ;

    //
    // Methodes pour CGMReplay
    // -----------------------
    virtual const CATString * GetOperatorId ()                                                 CATCDSEngineOverriding ;

    // Donne le nom de la sharedlib dans laquelle il faut charger cet objet
    virtual       void        GetSharedlib  (char                      *& sharedlib          ) CATCDSEngineOverriding;

    // Numero de version du stream
    virtual       short       GetVersionNumber()                                               CATCDSEngineOverriding;
  //
  // on construit la liste exaustive des les elements d'entrée
  // #define CATSweepSolverEngine_ListPOfCATICGMObject CATLISTP(CATICGMObject)
    virtual CATSweepSolverEngine_ListPOfCATICGMObject
                              GetListOfInputObjects()                                          CATCDSEngineOverriding ;

    // Methode ecrivant les entrées dans le Stream
    virtual       void        WriteAllInput(CATCGMStream                & Str                ) CATCDSEngineOverriding;

    // Dump des données de l'operateur
    virtual       void        Dump         (CATCGMOutput                & os                 ) CATCDSEngineOverriding;

  //
  // DATA 
  //
public:
private:
  static CATString         _CATCDSEngineOperatorId;
         CATCDSEngineImp * _Imp;

ExportedByVarSweepDriver friend CATLoadInFactoryCATCDSEngineDeclaration;
};

#undef CATCDSEngineOverriding

#endif 
