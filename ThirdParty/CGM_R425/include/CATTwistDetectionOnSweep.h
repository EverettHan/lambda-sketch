// COPYRIGHT DASSAULT SYSTEMES 2000
//=============================================================================
//
// CATTwistDetectionOnSweep :
//
//=============================================================================
//
// Usage notes:
// to do
// sample of use :
// to provide
//
// Attention : _DimPt = 4 signifie que la forme est rationnelle et que l'on va
//                         interpoler les poids.
//             _DimPt = 3 signifie
//                         - soit que la forme n'est pas rationnelle
//                         - soit que la forme est rationnelle mais que ses poids
//                         sont constants dans le sens d'avancee, et que l'on ne va donc
//                         pas les interpoler.
//
// Remarque : fonctionnement naturel : on s'arrete au premier twist trouve sur le domaine
//            pour le mode untwist, on va chercher tous les twists sur le domaine en question
//            (appel a CATTwistDetectionOnSweep sur un domaine)
//=============================================================================
//   /12/00 CCK Creation
//   /12/02 JSX Ajout de GetInfoOnTwist
//   /03/03 CCK Ajout du mode de rebroussement (pour l'offset curve 3d)
//   /03/03 CCK Ajout du mode untwist (pour NLD)
//   /04/03 CCK Changement de _SurfTwisted en _ListOfTwistedSurf (pour le mode UnTwist,
//              on veut toutes les surfaces twistees)
//   /07/03 CCK Ajout de SetDiscontinuity(CATListOfInt iDiscontinuity);
// 17/10/03 CCK Mise en place de OptionConfigData pour mieux gerer les evolutions du code 
//               en fonction des var de versioning -> de la config
// 22/10/03 CCK IsTooSharp(), _Sharp
// 07/11/03 CCK DoNotMicroCurvatureCheck() => le check de microcoubure n'est utile que pour les loft
//              dans les autres cas, il est preferable de le debrancher pour eviter des flags de twist
//              abusifs pres des pointes (Sweep629 - Sweep527 : sweep circle avec loi de rayon : Ri414154)
// 11/01/07 NLD Distinction twist/wrap; ajout IsWrapped() ajout _Wrap
//              et nouveau mode SetWrapMode(2)
// 09/12/09 NLD Definition de nomenclature pour les #define partages:
//              TwistDetection_Boolean devient CATSweepTwistDetectionOnSweep_Boolean
// 25/01/10 NLD _CurvatureTol est renommée _CurvatureRadiusTolerance
//              SetCurvatureTolerance() est renommée SetCurvatureRadiusTolerance()
// 08/02/10 NLD Changement de la bizarre signature de VisuForm()
// 13/01/11 NLD Migration sur CATCGMOperator pour beneficier de l'infrastructure d'analyse CPU
//              de CATCGMOperatorSpecialImplementation
//              (anciennement: derivation de CATCGMVirtual)
// 14/01/11 NLD Ajout DiagType et SetDiag() pour point d'arret
// 07/07/11 NLD Ajout _OperatorId, GetOperatorId(), GetDefaultOperatorId()
// 09/11/12 NLD Ajout MultiFormPointsCopy() pour factoriser les modifications par les poids
//              Ajout EnhancedGetGlobalEquation()
// 13/11/12 NLD Detection() devient RunDetectionOld()
//              Mise au propre
//              Reordonnancement logique des donnees
//              _Options est renommee _ConfigOptions
//              Ajout _CGMLevel
//              Structuration des autres options d'entree: Ajout _InputOptions
// 17/02/14 NLD Un bon nettoyage de l'interface
//              - Reordonnancement et mise au propre
//              - Passage de public en protected pour
//                - RunDetection() et RunDetectionOld()
//                - IsFormTwisted(), ChangeParameter(), ComputeTwist()
//              - Smart indent
//              - Inactivation de SetLevel() jamais utilise
//              - Passage par adresse de la liste de SetDiscontinuity()
//              - (_Level, _ErrorProg, _TestsOnForms) passent dans _ConfigOptions
//              - _TwistedPtcrl est renomme _TwistedPCtrl (ulterieurement _TwistedPointIndex)
//              Prevision CGMReplay:
//              - Ajout _LoadedFromReplay
//              - Ajout WriteInput(), DumpOutput(), WriteOutput(), ValidateOutput()
//              - Ajout CATTwistDetectionOnSweepAccess
//              - Ajout GetCATSweepCanonicSurfaceDetectorDefaultOperatorId()
//              - Ajout   de ComputeSurfBetween2Forms()
//              Regroupement des indicateurs d'analyse dans une structure _AnaDiag
// 20/02/14 NLD Factorisation des services de gestion des zones de twist et de rebroussement
//              - Declaration d'une structure AreaData
//              - Regroupement dans _WrapArea de
//                _WrapInitShapeParam  (devenant _WrapArea._InitShapeParam)  (et ulterieurement _WrapArea._IniSHParam)
//                _WrapEndShapeParam   (devenant _WrapArea._EndShapeParam)   (et ulterieurement _WrapArea._EndSHParam)
//                _WrapInitMFParam     (devenant _WrapArea._InitMFParam)     (et ulterieurement _WrapArea._IniMFParam)
//                _WrapEndMFParam      (devenant _WrapArea._EndMFParam)
//                _NumberOfWrapCurve   (devenant _WrapArea._CurveNumber)
//              - Regroupement dans _TwistArea de
//                _TwistInitShapeParam (devenant _TwistArea._InitShapeParam) (et ulterieurement _TwistArea._IniSHParam)
//                _TwistEndShapeParam  (devenant _TwistArea._EndShapeParam)  (et ulterieurement _TwistArea._EndSHParam)
//                _TwistInitMFParam    (devenant _TwistArea._InitMFParam)    (et ulterieurement _TwistArea._IniMFParam)
//                _TwistEndMFParam     (devenant _TwistArea._EndMFParam)
//                (ajout de                      _TwistArea._CurveNumber, sans pertinence)
//              - Ajout de StoreArea() et GetAreaInfo()
// 21/02/14 NLD Ajout _AreaManagementV2
//              ParamForUnTwistMode() est renommee StoreTwistArea()
//              AddWrapParam()        est renommee StoreWrapArea()
//              Ajout _TolObject
// 24/02/14 NLD Renommage de _LoadedFromReplay en _LoadedFromReplayVersion
//              Demelage des notations encore une fois tres confuses, non coherentes et non explicites (comme dans la Spine, "en moins pire")
//              (i servant a tout et a rien)
//              - distinction index et numero
//              - explicitation des fonctionnalites des methodes
//              - introduction de notations IndexForm1, IndexForm2, NumForm1, NumnForm2, en local ou en argument
// 25/02/14 NLD Renommages (pour nomenclature homogene et alignements d'ecriture)
//              - de _InitShapeParam en _IniSHParam
//              - de _EndShapeParam  en _EndSHParam
//              - de _InitMFParam    en _IniMFParam
//              Autres renommages
//              - de _TwistedPCtrl   en _TwistedPointIndex
// 03/03/14 NLD Ajout _State avec _RunDone, _ReadOutputNumber, _DumpOutputNumber
// 07/03/14 NLD Ajout _Dim4_OldMode et _Dim4_NewMode
// 11/03/14 NLD Ajout HasMicroCurvature()
// 21/03/14 NLD Renommages salutaires en *MicroRadiusCurvature* des *MicroCurvature* ayant echappe a l'operation du 25/01/10
//              (sur suggestion du cousin)
//              (y compris mon recent HasMicroCurvature() tombant dans le piege des erreurs de nomenclatures ambiants)
//              - DoMicroCurvatureCheck() en SetMicroCurvatureRadiusCheck()
//              - HasMicroCurvature()     en HasMicroCurvatureRadius()
//              - _DoMicroCurvatureCheck en _DoMicroCurvatureRadiusCheck
// 06/01/16 NLD IsFormSharp() remplace IsFormePointe()
//              _FormSharp remplace _FormePointe
// 05/08/19 NLD Ajout FillMFPoints()
//              Ajout _RecomputeFormPoints
// 07/08/19 NLD Reordonnancement des arguments de IsTwistedInSpineDirection()
//=============================================================================
#ifndef CATTwistDetectionOnSweep_H
#define CATTwistDetectionOnSweep_H

#define CATTwistDetectionOnSweep_ForceIsRecordable "En cours NLD180214"

#include <FrFOpeSur.h>

class CATGeoFactory;
class CATFrFNurbsMultiForm;
class CATMathSetOfPointsND;
class CATFrFMovingFrame;
class CATMathPoint;
class CATSweepTwistFunctionX;
class CATMathInterval;
class CATSplineCurve;
class CATMathFunctionX;
class CATNurbsSurface;
class CATSoftwareConfiguration;

class CATTwistDetectionOnSweepAccess;
class CATTwistDetectionOnSweepStreamer;
class CATTwistDetectionOnSweepOutputData;

#include <CATString.h>
#include <CATDataType.h>
#include <CATBoolean.h>
#include <CATListOfDouble.h>
#include <CATListOfInt.h>

#include <CATTolerance.h>

#include <CATCGMVirtual.h>
#include <CATCGMOperator.h>
#include <CATCGMOperatorDebug.h>


#include <CATListOfCATSurfaces.h>

//-----------------------------------------------------------------------------
// Tupes locaux
//-----------------------------------------------------------------------------
// Je definis mes booleens locaux car le type CATBoolean est non imprimable,
// non consultable au debugger
#define CATSweepTwistDetectionOnSweep_Boolean int

// Je supprime cette antiquite. NLD131112
//typedef enum
//{
//  OnlyUDir,
//  OnlyVDir,
//  BothDir
//} CATTwistDetectionDir;

typedef enum {CATTwistDetectionMultiFormPointsCopy_Copy             = 1,
              CATTwistDetectionMultiFormPointsCopy_DivideByWeight   = 2,
              CATTwistDetectionMultiFormPointsCopy_MultiplyByWeight = 3
             }CATTwistDetectionMultiFormPointsCopy_Code;

//-----------------------------------------------------------------------------
class ExportedByFrFOpeSur CATTwistDetectionOnSweep : public CATCGMOperator
{
  friend class CATTwistDetectionOnSweepAccess;
  friend class CATTwistDetectionOnSweepStreamer;
  friend class CATTwistDetectionOnSweepOutputData;
  //---------------------------------------------------------------------------
 public:
  //---------------------------------------------------------------------------
  
                                 CATTwistDetectionOnSweep     (       CATGeoFactory           *  iFactory          ,
                                                                      CATMathSetOfPointsND    *  iParameters       ,
                                                                      CATMathSetOfPointsND    *  iNewParameters    ,
                                                                      CATFrFNurbsMultiForm    *  iForms            ,
                                                                      CATMathSetOfPointsND    *  iTangents         ,
                                                                      CATMathSetOfPointsND    *  iSecondDerivatives);

  virtual                       ~CATTwistDetectionOnSweep     ();

          const CATString*       GetOperatorId();
          const CATString*       GetDefaultOperatorId         ();

          //    CATTwistDetectionOnSweepAccess* GetAccess     ();

  // Run() et RunOperator() renvoient 1 si une erreur a eu lieu dans le traitement, 0 sinon
  // Attention : notion independante de la notion de twist
  CATCGMOperatorDebugDeclareRun(CATTwistDetectionOnSweep, CATCGMOperator);

  virtual       int              RunOperator                  ();

  // Gestion du niveau de l'operateur
  // 1) par        SetLevel() (DO NOT USE) (Not used)
  //      void             SetLevel(CATLONG32 iLevel);
  // 2) par   SetSoftwareConfiguration()
                void             SetSoftwareConfiguration     (       CATSoftwareConfiguration *  iSoftwareConfig  );

  // La definition d'un moving frame est quasi indispensable. NLD170214
                void             SetMovingFrame               (       CATFrFMovingFrame        *  iMF              );

  // Options de detection
  // --------------------
  // Definition du mode Untwist: Calcul des zones de twist
  // On renverra alors les parametres entre lesquels le twist est detecte
  // (parmi les parametres donnes en entree a la detection de twist)
                void             SetUnTwistMode              (        CATLONG32                   iUnTwistMode    );

  // Mode de detection de rebroussement (pour l'untwist de courbes 3D)
  // Le mode 1 fait qu'un rebroussement est vu comme un twist
  // Les parametres de rebroussement sont optimaux (independant de l'interpolation)
  // Le mode 2 fait que l'on detecte les twists, et les rebroussements en plus
  // avec un indicateur particulier rendu par IsWrapped()
  // ce mode est plus couteux car il fait le calcul de twist integralement
  // au lieu de le remplacer par le calcul de rebroussement
                void             SetWrapMode                  (       CATLONG32                   iWrapMode        );

  // Detection des rebroussements seulement -> pour surfaces de balayage
  // iOnlyTurnBack = 1 => Si rebroussement => Erreur renvoyée
  // iOnlyTurnBack = 0 => On detecte le twist : si rebroussement, mais pas
  //                      de twist => pas d'erreur renvoyée
  // iOnlyTurnBack = 0 par defaut
                void             SetCheckOnlyTurnBack         (       CATLONG32                   iOnlyTurnBack    );

  // Voir Commentaire en haut de ce .h (Ri 414154)
  // iCheck = 0 -> pas de check de la microcourbure 
  // iCheck = 1 -> check de la microcourbure -> C'est la valeur par defaut
                void             SetMicroCurvatureRadiusCheck (       int                         iCheck           );

  // iIsADraftType = TRUE si le sweep est un sweep draft, FALSE sinon
  // Mis a FALSE par defaut
                void             SetSweepDraftType           (        CATBoolean                  iIsADraftType    );

  // Definition de la tolerance sur le rayon de courbure
  //   (la valeur par defaut de l'operateur est de 10 fois la resolution)
                void             SetCurvatureRadiusTolerance (        double                      iCurvatureRadiusTolerance);


  //  Position des discontinuites:
  //    Necessaire pour ne pas detecter de twist sur les limites des domaines C2. 
  //    (aux discontinuités le meme parametre apparait deux fois avec des derivées differentes )
  // (Commentaire issu de CATGeneralizedSweepSurfaceCx2 le 170214)
                void             SetDiscontinuity            (const   CATListOfInt              & iDiscontinuity   );


  // Interrogation des resultats de detection
  // ----------------------------------------
                CATBoolean       IsTwisted                   ();

                CATBoolean       IsWrapped                   ();

                CATBoolean       IsTooSharp                  ();

                CATBoolean       IsTurningBack               ();

                CATNurbsSurface* GetTwistedSurf              ();
                void             GetTwistedSurf              (         CATLISTP(CATSurface)     & oListOfTwistedSurf); // dans le cas untwist, on les veut toutes

  // Information sur le lieu de twist
                void             GetInfoOnTwist              (         CATLONG32                  ioTwistedDomain[2] , // index de multi-forms.      NLD240214
                                                                       CATLONG32                & oTwistedPCtrl      );// index de point de controle NLD260214



                void             GetInfoForUnTwist           (         CATLONG32                & oNbTwistIntervals      ,
                                                                       double                  *& ioTwistInitParamMF     ,
                                                                       double                  *& ioTwistEndParamMF      ,
                                                                       double                  *& ioTwistInitParamOnShape,
                                                                       double                  *& ioTwistEndParamOnShape );

  // Attention : pour avoir acces aux infos sur le rebroussement, il faut avoir active
  // le mode de detection de rebroussements : SetWrapMode
  // ioWrapInitParamMF et ioWrapEndParamMF sont a detruire par l'appelant
  // - oNbWrapIntervals est le nombre d'intervalles de rebroussements detectes
  // - ioWrapInitParamMF est le tableau de tous les parametres de debut de rebroussement
  // - ioWrapEndParamMF est le tableau de tous les parametres de fin de rebroussement
  // - ioWrapInitParamMF et ioWrapEndParamMF sont de longueur oNbWrapIntervals
  // - ioNumberOfWrapCurve est le numero de la courbe (interpolee en pt/tgt/d2) ou
  // le rebroussement est detecte
                void             GetInfoOnWrap               (         CATLONG32                & oNbWrapIntervals       ,
                                                                       double                  *& ioWrapInitParamMF      ,
                                                                       double                  *& ioWrapEndParamMF       ,
                                                                       double                  *& ioWrapInitParamOnShape ,
                                                                       double                  *& ioWrapEndParamOnShape  ,
                                                                       int                     *& ioNumberOfWrapCurve    );

  

  //-----------------------------------------------------------------------
  //- Gestion Mode Record 
  //-----------------------------------------------------------------------  
  // EN COURS NLD170214
  /** @nodoc @nocgmitf */
  CATExtCGMReplay    * IsRecordable  (short        & LevelOfRuntime ,
                                      short        & VersionOfStream);
  /** @nodoc @nocgmitf */
  virtual void         WriteInput    (CATCGMStream & os);
  /** @nodoc @nocgmitf */
  virtual void         WriteOutput   (CATCGMStream & os);
  /** @nodoc @nocgmitf */
  virtual CATBoolean   ValidateOutput(CATCGMStream & ioStream, CATCGMOutput & os, int VersionNumber = 1);
  /** @nodoc @nocgmitf */
  virtual void         Dump          (CATCGMOutput & os ) ;
  /** @nodoc @nocgmitf */
  virtual void         DumpOutput    (CATCGMOutput & os);
  /** @nodoc @nocgmitf */
  virtual void         DumpOutput    (CATCGMStream & ioStream, CATCGMOutput & os, int VersionNumber = 1);
  /** @nodoc @nocgmitf */
  virtual CATCGMOperator::CATCheckDiagnostic CheckOutput(CATCGMOutput & os);

  //---------------------------------------------------------------------------
 protected:
  //---------------------------------------------------------------------------

 typedef enum{DiagNone    =  0,
              DiagTwist   =  1, DiagWrap   =  2, DiagTurningBack   =  3,  DiagSharp   =  4,
              DiagNoTwist = -1, DiagNoWrap = -2, DiagNoTurningBack = -3,  DiagNoSharp = -4
             }SweepTwistType;

  struct AreaData
    {
     CATListOfDouble                         _IniSHParam;
     CATListOfDouble                         _EndSHParam;
     CATListOfDouble                         _IniMFParam;
     CATListOfDouble                         _EndMFParam;
     CATListOfInt                            _CurveNumber;       // numero de la courbe qui presente un twist/rebroussement dans le sens de la spine
    };

  // Old methode -> comme RunDetection
          int RunDetectionOld            (      double                                    *  VTgtIni        ,
                                                double                                    *  VTgtEnd        ,
                                                double                                    *  V2dIni         ,
                                                double                                    *  V2dEnd         );
  // nouvelle version de RunDetectionOld -> je me libere de tout le versionning
  // qui rend illisible le code
          int RunDetection               (      double                                    *  VTgtIni        ,
                                                double                                    *  VTgtEnd        ,
                                                double                                    *  Vd2Ini         ,
                                                double                                    *  Vd2End         );

  // Calcul du changement parametrique lineaire
          int  ChangeParameter           (const double                                    *  PtrParams    ,
                                                double                                     & a            ,
                                                double                                     & b            ,
                                                CATMathInterval                           *& CurrentDomain);

          void ComputeTwist              (const CATMathPoint                               & PtIni     ,
                                          const CATMathPoint                               & PtEnd     ,
                                                double                                       weightIni ,
                                                double                                       weightEnd ,
                                                double                                    *  VTgtIni   ,
                                                double                                    *  VTgtEnd   ,
                                                double                                    *  Vd2Ini    ,
                                                double                                    *  Vd2End    ,
                                                double                                       DeltaParam, 
                                                int                                          k         ,
                                                double                                       a         ,
                                                double                                       b         ,
                                                double                                    *  Px        ,
                                                double                                    *  Py        ,
                                                double                                    *  Pz        );

          CATNurbsSurface*
              ComputeSurfBetween2Forms         (int                                          NumForm1             , // ancienne notation i
                                                double                                       ParamIni             ,
                                                double                                       ParamEnd             );

          int ComputeAndOffsetSurfBetween2Forms(int                                          NumForm1             , // ancienne notation i
                                                double                                       ParamIni             ,
                                                double                                       ParamEnd             );

          // Dit si on a un rebroussement entre deux formes
          int  IsTwistedInSpineDirection       (int                                          NumForm1             , // NLD240214 ancienne notation i
                                                double                                       a                    ,
                                                double                                       b                    ,
                                                double                                       ParamIni             ,
                                                double                                       ParamEnd             ,
                                                double                                       NewParamIni          ,
                                                double                                       NewParamEnd          ,
                                                double                                       ParamInitMF          ,
                                                double                                    *  VTgtInit             ,
                                                double                                    *  VTgtEnd              ,
                                                double                                    *  Vd2Init              ,
                                                double                                    *  Vd2End               ,
                                                int                                        & oPointe              );

          // (Calcul entre deux formes)
          int  CoherenceBetweenProfilDir       (int                                          NumForm1             , // ancienne notation i
                                                double                                       ParamIni             ,
                                                double                                       ParamEnd             ,
                                                double                                       NewParamIni          ,
                                                double                                       NewParamEnd          ,
                                                CATMathFunctionX                          *  Form1x               ,
                                                CATMathFunctionX                          *  Form1y               ,
                                                CATMathFunctionX                          *  Form1z               ,
                                                CATMathFunctionX                          *  Form2x               ,
                                                CATMathFunctionX                          *  Form2y               ,
                                                CATMathFunctionX                          *  Form2z               ); 

          // Remplissage du tableau des points associés à la forme d'index indexForm
          // MFPoints est alloué si nul en entrée
          // il est toujours rempli (meme si non nul en entrée)
          // (le but étant de permettre al boucle sur les formes en réutilisant la meme allocation)
          void FillMFPoints                    (int                                          iIndexForm           ,
                                                CATMathPoint                             *&  MFPoints             );


          int  IsFormSharp                     (int                                          iIndexForm           , // NLD240214 ancienne notation i 
                                                CATMathPoint                              *  MFPoints             ,
                                                int                                        & oCtrPtConfused       ,
                                                double                                    *  VTgtInit             );

          int  HasMicroCurvatureRadius         (CATFrFNurbsMultiForm*                        iMultiForm           );

          int  IsFormTwisted             (      int                                          iIndexForm           , // NLD240214 ancienne notation i
                                                double                                       iParamIniMF          ,
                                                int                                       *  iFormePointe         ,
                                                double                                    *  VTgtInit             ,
                                                CATMathPoint                              *  iMFPoints            );

          int  IsPseudoFormCusped              (CATFrFNurbsMultiForm                      *  PseudoForm           ,
                                                double                                       ParamMF              );



          // Calcul d'une pseudo-forme entre les formes de numeros NumForm1 et NumForm1+1
          void ComputePseudoForm               (int                                          NumForm1             , // ancienne notation i
                                                double                                       a                    ,
                                                double                                       b                    ,
                                                double                                       NewParamIni          ,
                                                double                                       NewParamEnd          ,
                                                double                                    *  VTgtInit             ,
                                                double                                    *  VTgtEnd              ,
                                                double                                    *  Vd2Init              ,
                                                double                                    *  Vd2End               ,
                                                CATFrFNurbsMultiForm                      *  PseudoForm           );


          void NettoyageDetection              (int                                          num                  ,
                                                CATMathFunctionX                         **  FormEquation         ,
                                                CATFrFNurbsMultiForm                      *  PseudoForm           ,
                                                CATFrFNurbsMultiForm                      *  FormTamponStandard   = NULL);

  // Copy of iMultiForm points into oMultiForm with optional modification by weights
          void MultiFormPointsCopy             (CATFrFNurbsMultiForm                      *  iInputMultiForm      ,
                                                int                                          iNumInputForm        ,
                                                CATTwistDetectionMultiFormPointsCopy_Code    iCode                ,
                                                CATFrFNurbsMultiForm                      *  iOutputMultiForm     ,
                                                int                                          iNumOutputForm
                                               );

  // Lecture des equations globales d'une forme directement ou via traitement special rationnel
  // dans la multiforme tampon si elle est fournie
          void EnhancedGetGlobalEquation       (int                                          iNumInputForm        ,
                                                CATFrFNurbsMultiForm                      *  iFormeTamponStandard ,
                                                CATTwistDetectionMultiFormPointsCopy_Code    iCode                ,
                                                CATMathFunctionX                          *& oEqX                 ,
                                                CATMathFunctionX                          *& oEqY                 ,
                                                CATMathFunctionX                          *& oEqZ
                                               );

  // pour le mode untwist
          void StoreTwistArea                  (double                                       iParamIni            ,
                                                double                                       iParamEnd            ,
                                                double                                       ia                   ,
                                                double                                       ib                   ) ;

          void StoreWrapArea                   (double                                       iInitWrap            ,
                                                double                                       iEndWrap             ,
                                                CATLONG32                                    NumCurve             ,
                                                double                                       a                    ,
                                                double                                       b                    );

          void StoreArea                       (double                                       iParamIni            ,
                                                double                                       iParamEnd            ,
                                                CATLONG32                                    NumCurve             ,
                                                double                                       a                    ,
                                                double                                       b                    ,
                                                AreaData                                   & ioArea
                                               );
          void GetAreaInfo               (const AreaData                                   & ioArea               ,
                                                CATLONG32                                  &  oNbIntervals        ,
                                                double                                    *& ioIniParamMF         ,
                                                double                                    *& ioEndParamMF         ,
                                                double                                    *& ioIniParamSH         ,
                                                double                                    *& ioEndParamSH         ,
                                                int                                       *& ioCurveNumber     
                                               );

  //---------------------------------------------------------------------------
  // Debug: traces et visualisation
  //---------------------------------------------------------------------------
  
  // pour du debug
          int  TraceQuintique                  (double                                    *  Px,
                                                double                                    *  Py,
                                                double                                    *  Pz,
                                                double                                       ParamIni,
                                                double                                       ParamEnd);

  // pour du debug
          int TraceQuintiqueMF                 (double                                    *  Px,
                                                double                                    *  Py,
                                                double                                    *  Pz,
                                                double                                       ParamIni,
                                                double                                       ParamEnd);

          int  VisuForm                        (CATFrFNurbsMultiForm                      *  iFormToVisu);// rend le tag. int au lieu de double NLD080210

          void SetDiag                         (SweepTwistType                               iDiag);

  //---------------------------------------------------------------------------
  static CATString                           _OperatorId;

  // Donnees de gestion
  // ------------------
     int                                     _LoadedFromReplayVersion;
     const CATTolerance&                     _TolObject;
  // Variables pour le Versionning
  // -----------------------------
  CATSoftwareConfiguration                 * _SoftwareConfig;
  // Les options liees a la config => au niveau
  struct ConfigOptionData
    {
     //                                                                               // les niveaux
     int                                     _CGMLevel                              ;
     CATLONG32                               _Level                                 ;
     //                                                                               // les declencheurs specifiques
     int                                     _ErrorProg                             ;
     int                                     _TestsOnForms                          ;
     CATSweepTwistDetectionOnSweep_Boolean   _Versioning_DegeneratedPointeDetection ;
     CATSweepTwistDetectionOnSweep_Boolean   _Versioning_CorrectPSF                 ;
     CATSweepTwistDetectionOnSweep_Boolean   _Versioning_Rational                   ;
     int                                     _AreaManagementV2;
     int                                     _RecomputeFormPoints;
    };
  ConfigOptionData _ConfigOptions ;

  // Options et parametres de calcul
  // -------------------------------
  struct InputOptionData
    {
     CATLONG32                               _UnTwistMode;
     CATLONG32                               _WrapMode;
     CATLONG32                               _WrapModeForWarning; // indique que le mode wrap vient seulement en sus pour warnings et non en remplacement
     int                                     _DoMicroCurvatureRadiusCheck;
     CATLONG32                               _OnlyTurnBack;
     CATBoolean                              _IsADraftType;
     double                                  _CurvatureRadiusTolerance;
    };
     InputOptionData                         _InputOptions;

  // Autres entrees
  // --------------

     CATGeoFactory                         * _Factory;

  //                                                  // Les formes et leurs donnees de description
  //                                                  // ------------------------------------------
     CATLONG32                               _EntreeInvalide;
     CATLONG32                               _NbForms;
     CATFrFNurbsMultiForm                  * _Forms;
     CATLONG32                               _DimPt;  // Voir commentaires en debut du fichier
     int                                     _Dim4_OldMode,
                                             _Dim4_NewMode;
     CATLONG32                               _NbPts;

                                                      // Les variables d'etat
   struct StateData
    {
     int                                     _RunDone;
     int                                     _ReadOutputNumber;
     int                                     _DumpOutputNumber;
    };
     StateData                               _State;

                                                      // Les parametres
                                                      // --------------
     CATMathSetOfPointsND                  * _Params;
     CATMathSetOfPointsND                  * _NewParams;

                                                      // Les derivees
                                                      // ------------
     CATMathSetOfPointsND                  * _Deriv;
     CATMathSetOfPointsND                  * _Deriv2nd;
     CATLONG32                               _Dim;    // Dimension de _Deriv, _Deriv2nd, VTgtInit, VTgtEnd, Vd2Init, Vd2End

     CATFrFMovingFrame                     * _MF;

  //                                                  // Ajout pour le C1. Jean
  //                                                  // ----------------
     CATListOfInt                            _Discontinuity; // Numeros des domaines en fin desquels il y a discontinuite, semble-t-il. NLD270214


  // Donnees intermediaires de travail
  // ---------------------------------
     int                                     _CstWeight;

  // Resultats d'analyse
  // -------------------
  struct AnaDiagData
    {
     CATBoolean                              _Twist;
     CATBoolean                              _Wrap;
     CATBoolean                              _Sharp;
     CATBoolean                              _TurnBack;
     int                                   * _FormSharp;         // [_NbForms] (un indicateur par forme) (NLD060116 anciennement _FormePointe)
    };
     AnaDiagData                             _AnaDiag;

     CATLISTP(CATSurface)                    _ListOfTwistedSurf;
     int                                     _OutSurf;           // indique si la ou les surfaces twistees ont ete rendues. NLD260214


  // Ajouts pour le mode de rebroussement
     AreaData                                _WrapArea;

  // Ajouts pour le mode UnTwist => pour Nicolas
     AreaData                                _TwistArea;

  // Ajout pour le Detwistage    => pour Jean
  //                                                             // Position du twist (_TwistedDomain + _TwistedPointIndex)
  //                                                             // -----------------
  //                                                             // - La position est en fait celle du dernier twist detecte
  //                                                             //   (du premier si l'on sort des la premiere detection)
  //                                                             // - Il semble que l'on puisse y avoir des index valides que l'on ait twist ou non
  //                                                             //
  //                                                             // _TwistedDomain: domaine ou se situe le twist
  //                                                             // (encore un truc d'une clarte folle:
  //                                                             // en fait ce sont les index des deux formes entre lesquelles se situe le twist)
  //                                                             //                                                             (NLD260214)
  //                                                             
     CATLONG32                               _TwistedDomain[2];  // domaine ou se situe le twist

     CATLONG32                               _TwistedPointIndex; // Index du point de controle detecte twiste.
                                                                 // Anciennement _TwistedPCtrl, historiquement _TwistedPtcrl

};


//-----------------------------------------------------------------------------
extern "C" ExportedByFrFOpeSur CATString *GetCATTwistDetectionOnSweepDefaultOperatorId();

#endif

