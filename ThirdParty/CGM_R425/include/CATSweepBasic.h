#ifndef CATSweepBasic_H
#define CATSweepBasic_H
// =======================================================================================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
// 08 04 08 FDS Creation
// 08 12 09 NLD Definition d'une nomenclature pour les classes utilitaires du sweep, la plupart exportees
//              SpecCell  devient CATSweepSpecCell
//              Tableau   devient CATSweepArrayOfSpecCell
//              Spec      devient CATSweepSpec
//              Brep      devient CATSweepBRep
//              BrepCell  devient CATSweepBRepCell
//              Journal   devient CATSweepJournal
// 16 03 10 NLD Ajout _ExtrudedCntCellInError _ExtrudedProfCellInError et GetExtrudedCellsInError()
//              Ajout ThrowIntBadGeometry()
//              Ajout GeoExtrudeEdgeCurvePOECS() pour isolation du code de gestion des POECs
// 19 03 10 NLD Ajout _LoopOnC0Error, SetLoopOnC0Error()
//              CommonAllocAndInit() remplace CommonAlloc()
//              Ajout enumeration CATSweepBasicInternalType
//              _TypeSweep est renomme _InternalSweepType et n'est plus accessible
//              Les constructeurs recoivent iInternalSweepType
//              Ajout de SetInternalSweepType()
//              (j'aurais meme du carrement faire migrer les appelants sur un SetSweepType())
//              Ajout CATSweepBasic_MaxDimCnt (=2) et CATSweepBasic_MaxDimProfile (=3)
//              et meme CATSweepBasic_MaxDimCntXDimProfile (=6)
//              Ajout _AllExtrudedCntCellsInError, _AllExtrudedProfCellsInError
//              et GetAllExtrudedCellsInError()
// 14 09 10 NLD Ajout GeoExtrudeSafe()
// 17 06 11 NLD Ajout _TopDataNoReport
// 24 06 11 NLD Ajout macro CATSweepBasic_MyBrepIndex()
// 06 08 13 OID Add _PreproJournal specific from the operation from intial to final profile. Not Activated CGM_Versionning_Sweep_SeparatePreproJournal
// 14 08 13 OID Add _ExtrusionJournal specific to the extrusion of the final profile. CGM_Versionning_Sweep_IsolateExtrusionJournal
// 03 07 14 OID Move code of IsVertexOnRevolAxis from CATSweepRelimit3 to CATSweeBasic
// 28 06 17 NLD Smart indent
//              All methods including private ones declared before all data
// =======================================================================================================================================
// This basic class is designed for non manifold extrusion ( CATPrismBasic , CATRevolBasic for CVM )
// The "SetSurfacicResult" is mandatory for this kind of extrusion
// =======================================================================================================================================


//=============================================================================
#include "BO0SWEEPLight.h"
#include "CATMathAxis.h"
#include "CATMathInline.h"
#include "CATTopOperator.h"
#include "CATTopDefine.h"
#include "CATTopData.h"
#include "CATListOfInt.h"
#include "CATListOfCATSurfaces.h"
#include "ListPOfCATCell.h"
//
//=============================================================================
class CATGeoFactory;
class CATCGMJournalList;
class CATTopData;
class CATBody;
class CATDomain;
class CATCell;
class CATVertex;
class CATEdge;
class CATEdgeCurve;
class CATFace;
class CATLoop;
class CATMathVector;
class CATCrvParam;
class CATCrvLimits;
class CATSweepSpec;
class CATSweepBRep;
class CATSweepJournal;
class CATSweepSpecCell;
class CATSweepBRepCell;
class CATSurParam;
class CATSweepGeo2Def;
//=============================================================================

enum CATSweepType
{ UnknownType, PrismType, RevolType, OffsetType, SweepType, AdvancedPrismType};

// Type interne special pour gerer les anciennes valeurs en dur
enum CATSweepBasicInternalType
{ CATSweepBasicInternalType_0Sweep         = 0,
  CATSweepBasicInternalType_1Prism         = 1,
  CATSweepBasicInternalType_2Revol         = 2,
  CATSweepBasicInternalType_3Offset        = 3,
  CATSweepBasicInternalType_5AdvancedPrism = 5
};
//
//
//--------------------------------------------------------------------------
  #define CATSweepBasic_ListPOfCATSurface CATLISTP(CATSurface)
  #define CATSweepBasic_ListPOfCATCell    CATLISTP(CATCell)
//--------------------------------------------------------------------------
//
class ExportedByBO0SWEEPLight CATSweepBasic : public CATTopOperator
{

public :
// -----

  // Constructeur a partir d'un Body
                              CATSweepBasic                    (      CATGeoFactory        *  iGeoFactory                  ,
                                                                      CATTopData           *  iData                        ,
                                                                      CATBody              *  iProfBody                    ,
                                                                      CATBody              *  iCntBody                     ,
                                                                      CATSweepBasicInternalType
                                                                                              iInternalSweepType           = CATSweepBasicInternalType_0Sweep
                                                               );

  // constructeur a partir d'un CATBody
                              CATSweepBasic                    (      CATGeoFactory        *  iGeoFactory                  ,
                                                                      CATBody              *  iProfBody                    ,
                                                                      CATBody              *  iCntContour                  ,
                                                                      CATCGMJournalList    *  iReport                      = NULL,
                                                                      CATSweepBasicInternalType iInternalSweepType         = CATSweepBasicInternalType_0Sweep
                                                               );

  // Destructeur 
  virtual                    ~CATSweepBasic                    ();

    
  // Run 
  virtual int                 Run                              ();

  // fonction membre de recuperation du resultat
          CATBody           * GetResult                        () ;

  // SetBooleanForSurface : take into account boolean body for surface reutilisation only 
  // ( active for basic extrude only , else use SetBoolean method )
          void                SetBooleanForSurface             (      CATBody              *  iTrimBody                    );

  // SetSurfacic : set the surfacic mode to generate shells as result instead of volume after shell extrusion 
  // This mode is mandatory for basic non manifold extrusion and not applicable to standard extrusion
  // RemoveExtremityFaces :
  // - 0 : standard mode ( keep all faces )
  // - 1 : remove bottom face
  // - 2 : remove top face
  // - 3 ! remove bottom and top faces
          void                SetSurfacicResult                (const int                     iRemoveExtremityFaces        = 0 );

  // ???? fonction membre de verification des inputs
          CATSweepType        GetSweepType                     ();
          CATBody           * GetCenter                        ();
   INLINE CATBody           * GetProfile                       (); 
          CATCGMJournalList * GetExtrusionJournal              ();

          void                SetInternalSweepType             (      CATSweepBasicInternalType iInternalSweepType);
  //
  // lecture de l'axe ( cas revol seulement )
    const CATMathAxis       & GetAxis                          ();

   static CATBoolean          IsVertexOnRevolAxis              (      CATVertex              *  iVertex           ,
                                                                      CATMathAxis             & iMathAxis         ,
                                                                      double                    iTolerance        );

          CATBoolean          IsVertexOnRevolAxis              (      CATVertex              *  iVertex           );

  // Methodes de gestion ( internal , do not use , CATRevol - CATRevolBasic code sharing )
          void                AddLoop                          (      CATLoop                *  newloop           );

          void                RemoveLoop                       (      CATLoop                *  iLoop             );

          CATSweepSpecCell  * GetCenter                        (      CATCell                *  iCntCell          );

          CATSweepSpecCell  * GetProfile                       (      CATCell                *  iProfCell         );

          CATSweepBRepCell  * GetBrepCell                      (      CATSweepSpecCell       *  iCntSpec          ,
                                                                      CATSweepSpecCell       *  iProfSpec         );

          CATSweepBRepCell  * GetBrepCell                      (      CATCell                *  iBCell            );

          CATDomain         * DomainExtrude                    (      CATDomain              *  iDomain           ,
                                                                      int                       iDimCntCell       ,
                                                                      CATCell                *  iBCell            ,
                                                                      CATDomain              *  iBDomainOuter     );

          CATOrientation      GetOrientation                   (      CATCell                *  CntCell           ,
                                                                      CATCell                *  ProfCell          );

          CATSide             GetSide                          (      CATOrientation            BOrient           ,
                                                                      CATSide                   iSide             ,
                                                                      CATCell                *  iCntCell          );

  // Special ExtendedC0 NLD Mars2010
  //
  // 1) demande de boucler jusqu'a la derniere erreur C0
  //    pour en avoir la liste
          void                SetLoopOnC0Error                 ();

  // 2) Rend l'eventuel couple  de cellules cause de l'erreur d'extrusion
          void                GetExtrudedCellsInError          (      CATCell                *& oCntCell          ,
                                                                      CATCell                *& oProfCell         ) ;

  // 3) Rend tous les couples de cellules causes d'erreurs d'extrusion (si SetLoopOnC0Error() appele au prealable)
          void                GetAllExtrudedCellsInError       (      CATSweepBasic_ListPOfCATCell& oCntCells     ,
                                                                      CATSweepBasic_ListPOfCATCell& oProfCells
                                                               );

          void                SetJournal                       (      CATCGMJournalList      *  iJournal          );

protected :
  // Journaling des ordres de suivi des elements topologiques
  virtual void                Report                           (      CATBoolean                iHasContextualLimits,
                                                                      short                     iRelimJournalMode );

  // nettoyage de l'environnement
  virtual void                Clear                            ();
  virtual void                Clear2                           ();

  // Clear Basique
          void                ClearBasic                       ();

  // Common Allocations and initializations
          void                CommonAllocAndInit               (      CATGeoFactory          *  iGeoFactory       ,
                                                                      CATBody                *  iProfBody         ,
                                                                      CATBody                *  iCntBody          );

  // Creation d'une center curve bidon
  virtual CATBody           * SweepCnt                         (      CATGeoFactory          *  iGeoFactory       ) = 0;
  virtual CATBody           * SweepProf                        (      CATGeoFactory          *  iGeoFactory       );

  // declaration de la center curve dans son ensemble a l'ExtrudeDef pour 
  // le Sweep generalise avant le remplissage de la geometrie
  virtual void                SetCenter                        ();

  // Extrusion topologique

          CATSweepBRepCell  * TopoExtrude                      (      CATSweepSpecCell       *  iSpecCnt          ,
                                                                      CATSweepSpecCell       *  iProfSpec         );

          CATSweepBRepCell  * TopoExtrude                      (      CATSweepSpecCell       *  iCntSpec          ,
                                                                      CATSweepSpecCell       *  iProfSpec         ,
                                                                      CATCell                *  BCell             ,
                                                                      CATSide                   Side              , 
                                                                      CATDomain              *  BDomain           );

          CATDomain         * TopoExtrude                      (      CATDomain              *  iCntManif         ,
                                                                      CATDomain              *  iProfManif        );

          CATBody           * TopoExtrude                      (      CATBody                *  iCntBody          ,
                                                                      CATBody                *  iProfBody         );

  // Acces au body de travail courant
          CATBody           * GetWorkingBody                   () ;

  virtual CATDomain         * TopoMerge                        (      CATDomain              *  iCntManif         ,
                                                                      CATDomain              *  iProfManif        ,
                                                                      CATDomain              *  iManifold         );

  // Gestion des degenerescences du profile
  virtual void                MakeSelfSafe                      ();

  virtual void                FixDegenerateCells                ();

  virtual int                 IsDegenerate                      (     CATCell                *  iCell             );

  virtual int                 IsDegenerate                      (     CATDomain              *  iDomain           );

  virtual void                PostGeoExtrude                    ();
  
  // Gestion de la non-isotopologie
  virtual CATBoolean          IsCenterVertexC1                  (     CATVertex              *  iCntVertex        );

  virtual void                GetCenterEdgeLimits               (     CATEdge                *  iCntEdge          ,
                                                                      CATCrvLimits            & ioCenterEdgeLimits);

  // extrusion geometrique
          void                GetPointOnFace                    (     CATFace                *  iFace             ,
		                                                                CATSurParam             & oSurParam         );
  virtual void                GeoExtrude                        ();

  virtual void                GeoExtrude                        (     CATSweepBRepCell       *  iBrepCell         );

  virtual void                GeoExtrudeLate                    (     CATSweepBRepCell       *  iBrepCell         );

          void                GeoExtrudeSafe                    (     CATSweepBRepCell       *  iBrepCell         ,
                                                                      int                       iLate             ,
                                                                      CATError               *& oError            );

          void                GeoExtrudeEdgeCurvePOECS          (     CATSweepBRepCell       *  ptrBrepCell       ,
                                                                      CATCell                *  BCell             ,
                                                                      CATEdgeCurve           *  edgeCurve         );

  // Methodes de gestion 
          void                CreateBrep                        ();

  // ramassage des surfaces
          void                CoOperandsFillSurface             (     CATBody                *  iBody             ,
                                                                      CATLISTP(CATSurface)    & ioListSurface     );

  // Fermeture des Loops
          void                CloseLoops                        ();

  // Nettoyage des fat edges
          void                CleanFatEdges                     ();

  // ConvertIntoSurfacic
          void                ConvertIntoSurfacic               ();

  // Emission d'une erreur interne BadGeometry
          void                ThrowIntBadGeometry               ();


  // Datas members
  // --------

private :
  CATLONG32                    _InternalSweepType;    // remplace _TypeSweep

protected :

  // CATLONG32                 _TypeSweep;            // voir _InternalSweepType
  CATMathAxis                  _Axis;                 // cas revol seulement

  //======================Journal Data=======================================
  CATTopData                   _TopData;
  CATTopData                   _TopDataNoReport;      // for operations needing no report
  CATCGMJournalList          * _Report;               // General Report
  CATSweepJournal            * _Journal;              // General Journal
  CATSweepJournal            * _PreproJournal;        // Journal For Preprocessing operations
  CATSweepJournal            * _ExtrusionJournal;     // Journal of the extrusion only from the final profile to the non relimited extrusion
  CATSweepJournal            * _CurrentJournalToUse;  // A pointer to the journal to use
  //=========================================================================

  CATGeoFactory              * _GeoFactory;           // Factory
  CATSweepGeo2Def            * _ExtrudeDef;

  CATBody                    * _ProfBodyInitial;
  CATBody                    * _CntContourInitial;

  CATBody                    * _ProfBody;             // Profil
  CATBody                    * _CntContour;           // Contour
  CATCell                    * _IdentityCell;

  // structure du profile 
  CATSweepSpec               * _Profile;

  // structure de la center curve
  CATSweepSpec               * _Center;

  // Structure du Brep genere
  #define CATSweepBasic_MaxDimCnt            2
  #define CATSweepBasic_MaxDimProfile        3
  #define CATSweepBasic_MaxDimCntXDimProfile 6
  CATSweepBRep               * _Brep [CATSweepBasic_MaxDimCnt][CATSweepBasic_MaxDimProfile];//[2][3];  // [DimCenter*Dimprofile]
 
  // to remember the loops (for closing them at the end
  CATLoop                   ** _AllLoops;
  int                          _NbLoops;
  int                          _NbAllocLoops;

  // body resultat
  CATBoolean                   _RemoveResults;
  CATBody                    * _ResultBody;
  CATBoolean                   _freezemode;

  // For CVM
  CATBoolean                   _SurfacicMode;
  int                          _RemoveExtremityFaces;

  // donnees pour thin solid
  CATBoolean                   _ThinSolidMode;

  CATSweepBasic_ListPOfCATSurface* _ExistingSurface;

  // Mode de traitement des discontinuites
  CATLONG32                    _DiscontinuityTreatmentMode;
  int                          _LoopOnC0Error;

  // Mode de traitement des discontinuites
  CATCGMJournalList          * _CenterCuttingReport;
  CATLONG32                    _WorkingDomain;
  CATBody                   ** _CenterDomains;
  CATBody                   ** _LocalSkins;
  CATSweepSpec              ** _MyCenters;

  // Indexage de _MyBrep
  #define CATSweepBasic_MyBrepIndex(IndDom,IndCnt,IndProfile)                                    \
   (IndDom*CATSweepBasic_MaxDimCntXDimProfile + IndCnt*CATSweepBasic_MaxDimProfile + IndProfile) //
  CATSweepBRep              ** _MyBrep;

  CATLONG32                    _NbDomains;
  CATListOfInt                 _OriginCenterIsClosed;

  //CATSweepBRepCell         * _ExtrudedCellInError;
  CATCell                    * _ExtrudedCntCellInError;
  CATCell                    * _ExtrudedProfCellInError;
  CATSweepBasic_ListPOfCATCell _AllExtrudedCntCellsInError;
  CATSweepBasic_ListPOfCATCell _AllExtrudedProfCellsInError  ;

};

//-----------------------------------------------------------------------------
// Lecture du profile
//-----------------------------------------------
INLINE CATBody * CATSweepBasic::GetProfile ()
{
 return _ProfBody; 
}

#endif

  



















