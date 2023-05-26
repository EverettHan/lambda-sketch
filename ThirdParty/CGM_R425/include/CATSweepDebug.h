// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATSweepDebug:
// Utility for dump sweep section
//
//                                                    Christophe Pradal
//=============================================================================
// Usage notes:
//
//
//=============================================================================
// 21 07 99 NLD,CPL Creation
// 14 01 00 NLD _nbEval, _PreviousParam
// 17 10 03 NLD Ajout NeedsFastEval()
//              N.B je la mets inline, comme il y a deja une methode dans ce cas...
// 02 11 04 NLD Ajout de _FastEval de _CreatePoints et de _Traces
//              pour modification du comportement au debugger
//              Ajout de EvalDebug()
//              Suppression des methodes in-line
// 21 09 05 NLD Argument optionnel iNeedFastEval au constructeur
// 27 09 05 JSX Implementation de la methode EvalSectionData ajout de SetSolverData
// 12 10 05 NLD Ajout de _ExternalCCVEvaluator() _ExternalCCVEvaluatorData, SetExternalCCVEvaluator()
//              pour sortir le code personnalisé
//              de EvalSectionData()
// 02 03 06 JSX Ajout de Set/GetSweepSolverEngine pour coverage  : dans .h désolé !
//              (et _TestSolverEngine)
//              (je l'y ai laissé 4 ans c'est bien plus qu'esperé; allez hop, dans le .cpp NLD290611)
//              (et je supprime le 230118, ce que j'aurais du faire le 05/05/06 lors du changement de signature
//               dans la classe mère)
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
// 29 06 11 NLD Ajout _SectionSolverEngine, de type CATSectionSolverEngine,
//              et SetSectionSolverEngine()/GetSectionSolverEngine() pour permettre l'encapsulation
//              d'un vrai solver CDS par un solver de debug
//              (ceci en sus de l'existant _TestSolverEngine de type CATSweepSolverEngine)
//              Les méthodes SetSweepSolverEngine() et GetSweepSolverEngine()
//              descendent dans l'implémentation
//              _TestSolverEngine est renommé _SweepSolverEngine
// 12 07 11 NLD Ajout _CreateClouds
// 18 01 18 NLD Mise au propre. Smart indent
// 23 01 18 NLD Suppression par option de précompilation de
//              _SweepSolverEngine, SetSweepSolverEngine(), GetSweepSolverEngine()
//              au profit des équivalents dans la classe mère
//=============================================================================
#ifndef CATSweepDebug_H
#define CATSweepDebug_H

#include <FrFAdvancedObjects.h>

#include <CATSectionSolverEngine.h>

class CATFrFNurbsMultiForm ;
class CATMathPlane ;
class CATMathVector;
class CATFrFMovingFrame;
class CATFrFCompositeCurve;

#include <CATGeoFactory.h>
#include <CATPlane.h>
#include <CATCartesianPoint.h>

#define CATSweepDebug_NoSpecificSolverEngine "NLD230118 reutilisation donnee/methode de la classe mère"

class ExportedByFrFAdvancedObjects CATSweepDebug : public CATSectionSolverEngine
{
   protected:
   static CATString  _OperatorId ;

   public:

                   CATSweepDebug      (      CATGeoFactory         * iFactory,
                                             int                     iNeedFastEval = 0 );

 virtual          ~CATSweepDebug      ();

         void      InitializeSections
                                      (      int                     iNbImposedSections,
                                             double                * iParamsForImposedSections,
                                             int                     iNbElementsPerSection,
                                             CATFrFNurbsMultiForm*** iImposedSections,
                                             CATBoolean              isClosed );

         void      SetTangents        (      int                     iFirstOrLast,
                                       const CATMathVector         * iVectors );

 // Imposition du MovingFrame
         void      SetMovingFrame     (      CATFrFMovingFrame     * iMovingFrame );

 // 2) Methodes a appeler en cours de cheminement
 // A VOIR: passage des guides et des parametres sur celles-ci
 // virtual 
 // remarque: on supprimera le passage du plan une fois le movingframe exporté
 // Evaluation; architecture initiale
         void      EvalSection        (      double                  iParam         ,
                                       const CATMathPlane          & iSectionPlane  ,
                                             CATFrFNurbsMultiForm**  iInitialSection,
                                             CATFrFNurbsMultiForm**  oFinalSection  );

         CATLONG32 GetEvalMode        ();

 // Evaluation: 2eme architecture
 // (en fait en présence d'un CATSectionSolverEngine, les évaluations sont faites directement sur celui-ci; NLD180118)
         void      EvalSectionData    (      double                  iParam         ,
                                       const CATMathPlane          & iSectionPlane  ,
                                             CATSectionSolverData *  ioSectionData  );

 // Indique si l'evaluation lors du cheminement necessite un mode rapide
 // (sans solver) ou non
 // =1 : cheminement necessitant un mode rapide (comme pour beam)
 // =0 : cheminement standard, utilisant le solver pour toutes
 // les evaluations (comme pour un solver de debug)

 virtual CATLONG32 SetSolverData      (      CATSectionSolverData *  iData);

         CATLONG32 NeedFastEval       () ;

         void      EvalDebug          (      CATLONG32             & ioNbEval,
                                             int                   & ioTraces,
                                             int                   & ioCreatePoints,
                                             int                   & ioCreateClouds) ;

 // Definit un evaluateur externe de CCV a appeler dans EvalSectionData en lui transmettant
 // le CATSectionSolverData courant et d'eventuelles autres données spécifiques
         void      SetExternalCCVEvaluator
                    (CATFrFCompositeCurve*(*CCVEvaluator)(CATSectionSolverData* ioSolverData, void* ioSpecificData),
                     void* ioSpecificDataForCall) ;

  #ifndef CATSweepDebug_NoSpecificSolverEngine
         // N.B signature n'ayant pas évolué comme celle de la classe mère; supprimée par define NLD230118
         void      SetSweepSolverEngine(     CATSweepSolverEngine *  iSolverEngine);

         void      GetSweepSolverEngine(     CATSweepSolverEngine *& oSolverEngine);
  #endif
 // Variante pour encapsuler par ce solver de debug un vrai solver de type CATSectionSolverEngine
         void      SetSectionSolverEngine(  CATSectionSolverEngine*  iEngine);

         void      GetSectionSolverEngine(  CATSectionSolverEngine*& oSolverEngine);


 //
 // Methodes pour CGMReplay
 // dérivées de celles de CATSectionSolverEngine
   const CATString* GetOperatorId      () ;

         void      GetSharedlib        (    char                  *& sharedlib) ;
 // Numero de version du stream
         short     GetVersionNumber    () ;

 // Methode ajoutant tous les elements d'entrée, via des appels à la methode AddInputObject
 // pour chaque element d'entree InputObject
 // la methode devra etre appelée avec comme arguments InputObject et ioDataForCall
 virtual void      AddAllInputObjects  (void(*AddInputObject)(CATICGMObject* iiCGMObject, void* iiData), void* ioDataForCall) ;

 // Methode ecrivant les entrées dans le Stream
         void      WriteAllInput       (     CATCGMStream          & Str) ;
         void      Dump                (     CATCGMOutput          & os) ;

 private:
 
   CATGeoFactory          * _Factory;
   CATLONG32                _nbEval ;
   double                   _PreviousParam ;
   CATLONG32                _nbElt;
   CATLONG32                _nbPts;
   CATCartesianPoint     ** _Points;
   CATSectionSolverData   * _SectionData;
   double                 * _ParamsForImposedSections;
   CATFrFCompositeCurve   * (*_ExternalCCVEvaluator)(CATSectionSolverData* ioSolverData, void* ioSpecificData);
   void                   * _ExternalCCVEvaluatorData ;
  #ifndef CATSweepDebug_NoSpecificSolverEngine
   CATSweepSolverEngine   * _SweepSolverEngine;
  #endif
   CATSectionSolverEngine * _SectionSolverEngine;

 public:
   // Données publiques pour CGMReplay. ACCES INTERDIT HORS INFRASTRUCTURE CGMReplay de cette classe
   int                      _FastEval ;
   int                      _CreatePoints ;
   int                      _CreateClouds;
   int                      _Traces ;
   CATPlane               * _Plane;
} ;
#endif 
