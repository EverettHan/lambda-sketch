//===================================================================
// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCDSEngineImp.h
// CDS driver implementation
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// 08.12.05 FCX Creation                                          FCX
// xx.04.07 JSX Modification / Replay / IntegrationSweep
// 07 06 07 jsx SetLocalFrame
// 20 01 09 JSX Ajout de _CstrMarkTable
// 02 09 09 JSX Ajout de GetPrecomputedParams
// 09/03/11 JSX Prise en compte des cleaned Guides
//              Ajout de _Guides2CleanedGuide_Tag _Guides2CleanedGuide_Ptr;
// 16/01/18 NLD Mise au propre. Smart indent
//              XScale: IsConstantLaw() recoit la contrainte associée à la loi
// 24/01/18 NLD Suppression SetInitialSection() à deux arguments qui n'existe plus dans la classe mère
// 14/12/18 NLD Deplacement des marquages <@SetMeFree> avant les methodes,
//              pour comparaison aisée CATCDSEngine.h CATCDSEngineImp.h
//              Marquages CATCDSEngineOverriding
//              pour comparabilité complète CATCDSEngine.h CATCDSEngineImp.h
// 19/12/18 NLD Argument previsionnel iLine à ComputeCurve
// 20/12/18 NLD ComputeCurve() recoit en sus de la tangente le point extremité de la courbe precedente
// 02/01/19 NLD Ajout ManageCSTolerances() pour isolation du douteux code de trafic des tolerances
//              Ajout _OKToleranceManagement
//===================================================================


#ifndef CATCDSEngineImp_H
#define CATCDSEngineImp_H

#include "CATDataType.h"
#include "CATBoolean.h"
#include "CATMathInterval.h"

#include "CATCrvLimits.h"

#include "VarSweepDriver.h"
#include "CATCDSVarSweepDriver.h"
#include "CATCDSVarSweepGossip.h"

#include "CATCGMOutput.h"
#include "CATSweepSolverEngine.h"

#include "CATCDSListP.h"
#include "CATICDSEntity.h"

#include "CATListOfCATGeometries.h"

#include "CATIAV5Level.h"

class CATICDSFullDOFJoint;
class CATICDSBBoxEquation;
class CATSweepSpineAxis;

class CATFrFMovingFrame;
class CATKnotVector;
class CATBody;
class CATCDSVarSweepDriverImp;
class CATICDSVariable;
class CATICDSAdvanced;
class CATICDSRigidSet;
class CATICDSGeometryLeaf;
class CATICDSJoint;
class CATICDSSketch;
class CATICDSAxis;
class CATCDSString;
//class CATCDSMarching;
class CSMark;
class CATLaw;
class CATICDSFactory;
class CATICDSCoincidence;
class CATICDSGeomConstraint;
class CATSweepLaw;
class CATSweepSpineEquation;
class CATFrFNurbsMultiForm;
class CATICDSPoint2D;
class CATICDSLine2D;
class CATFrFCompositeCurve;
class CATCurve;
class CATGeoFactory;
class CATICDSGeomDimConstraint;
class CATFrFCoupling;
class CATSoftwareConfiguration;
class CATFrFSmoothedComb;
class CATSweepStreamTool;
class CATICDSSimulationMarching;
class CATICDSSkin;
class CATICDSCurve;
class CATICDSSkinParam;
class CATICDSSurface;

// WARNING: Also defined in CATSweepStreamTool.h
// FCX 05.2021 : activated in CXR32/R424
#if defined(CATIAV5R32) || defined(CATIAR424)
#define MIGRATION_SWEEP_TO_CATCDSGMINFRA_SKIN
#define MIGRATION_SWEEP_TO_CATCDSGMINFRA_CURVE
#endif

#ifdef MIGRATION_SWEEP_TO_CATCDSGMINFRA_SKIN
class CATSkinGMImp;
class CATSkinParamGMImp;
#else
class CATSkinCGMImp;
class CATSkinParamCGMImp;
#endif

#ifdef MIGRATION_SWEEP_TO_CATCDSGMINFRA_CURVE
class CATCSPropagationCurveGMImp;
#else
class CATCSCurveCGMImp;
#endif

CATCDSLISTP_DECLARE(CATICDSEntity);

//===================================================================
#include "CATListPV.h"
#define CATLISTP_Append            // Request the methods to create
//#define CATLISTP_RemoveValue
//#define CATLISTP_RemoveAll
#include "CATLISTP_Declare.h"      // Include macros
//class CATICDSEntity;
//CATLISTP_DECLARE(CATICDSEntity);         // Declare the collection class

//===================================================================
#define CATCDSEngineOverriding // vide ici; N.B #undef à la fin du fichier
class ExportedByVarSweepDriver CATCDSEngineImp
{
public: 
             CATCDSEngineImp        (CATCDSVarSweepDriver       *  iDriver,
                                     CATBoolean                    ToBeRemoved);

  virtual ~CATCDSEngineImp();

  void       SetCGMEnv              (CATSoftwareConfiguration   *  iConfig,
                                     CATGeoFactory              *  iFactory)CATCDSEngineOverriding ;


  // Set imposed by FreeForm
  //=============================
  // ci-dessous la chaine FREE est un marquage JSX280507 indiquant semble-t-il
  // les appels faits par FreeForm autrement dit par le moteur du loft.
  // Je l'ajoute pour SetInitialSection(), SetGetInfo() qui n'existaient pas à ce moment là
  // Je le remplace par <@SetMeFree>
  // Commentaire NLD180118
  //                                                                                                // <@SetMeFree>
  void       SetMaxDomain           (CATMathInterval            *  iMaxDomain) CATCDSEngineOverriding ;

  //                                                                                                // <@SetMeFree>
  void       SetMovingFrame         (CATFrFMovingFrame          *  iSweepMvFrame,
                                     CATFrFCoupling             *  iCoupling    ,
                                     CATLONG32                     IdCCV        ) CATCDSEngineOverriding ;

  //                                                                                                // <@SetMeFree>
  void       SetLocalFrame          (CATFrFSmoothedComb         *  iSmoothNormal,
                                     CATFrFCompositeCurve       *  iNormalCCV   ) CATCDSEngineOverriding ;

  //                                                                                                // <@SetMeFree>
  void       SetNewGuides           (CATLONG32                     iNbGuides,
                                     CATBody                   **  iOldGuide,
                                     CATBody                   **  iNewGuide) CATCDSEngineOverriding ;

  //                                                                                                // <@SetMeFree>
  void       SetProfileKnotVector   (CATLONG32                     iNbProfileEdges,
                                     CATKnotVector             **  iTabKnotVector ) CATCDSEngineOverriding ;

  //                                                                                                // <@SetMeFree>
  void       SetInitialSection      (int                           iNbInitialSections,
                                     double                     *  iSectionsParams   ,
                                     int                           iNbProfileEdges   ,
                                     CATFrFNurbsMultiForm     ***  iImposedSections  ,
                                     CATBoolean                    isClosed          ) CATCDSEngineOverriding ;

  // Declare a CDS le probleme en mix2D/3D, renconverge les sketch si necessaire
  // et realise la simulation (au sens du simulation marching de CDS). Renvoie :
  // 0 en cas de succes, 1 en cas d'echec de la simulation, 2 en cas d'echec de
  // la reconvergence (ou bien le sketch n'est pas propre ou bien on a des soucis lors
  // de la conversion en mix2D3D), 3 en cas d'exception levée par une methode appellee
  //                                                                                                // <@SetMeFree>
  void       Solve                  (CATLONG32                   & oResultCode) CATCDSEngineOverriding ;

  // Evals

  //                                                                                                // <@SetMeFree>
  void       EvalCompositeCurve     (double                        iT           ,
                                     CATFrFCompositeCurve       *& oFinalSection) CATCDSEngineOverriding ;


  //                                                                                                // <@SetMeFree> (Shape)
  CATBoolean GetConstraintArray     (int                        *& ioPointsContinuity,
                                     int                         & ioNbPoints        ) CATCDSEngineOverriding ;

  //                                                                                                // <@SetMeFree>
  void       GetPrecomputedParams   (CATListOfDouble             & L) CATCDSEngineOverriding ;

  //                                                                                                // <@SetMeFree>
  CATBoolean SetGetInfo             (CATLONG32                     iS1G0       , // (1 : Set, 0 : Get)
                                    CATSweepSolverEngine::InfoType iInfoType   ,
                                     CATLONG32                  *& odataLONG32 ,
                                     double                     *& odataDOUBLE ) CATCDSEngineOverriding ;

    //
    // Methodes pour CGMReplay
    // -----------------------

  void       Dump                   (CATCGMOutput                & os);

public :
  void       GetDataFromDriver      ();// JSX en public : Necessaire avant le Solve() pour sauver le _CS dans le CGMReplay 
  // Options pour gerer le marching et simuler le marching v5 pour valider les SweepVar V5 dans les FW CGM 
//CATLONG32  GetMarchingLevel       ();
//void       SetMarchingLevel      (CATLONG32                      iMarchingLevel);

private:
  HRESULT    ManagePositioning      ();

  HRESULT    ManageUseEdges         ();

  HRESULT    ManageLaws             ();

  HRESULT    ManageProfileInformation();

  HRESULT    ManageGeometries       (); // FCX 05.2010

  void       DbgStreamInNCGM        (); // FCX 07.2010 DEBUG

  void       AddIntersectionWithWireUseEdge
                                    (CATICDSGeometryLeaf        *  iCSGeo,
                                     CATBody                    *  iGuide);

  void       AddIntersectionWithSkinUseEdge
                                    (CATICDSGeometryLeaf        *  iCSGeo,
                                     CATBody                    *  iSkin,
                                     CATICDSGeometryLeaf        *  iExtr1,
                                     CATICDSGeometryLeaf        *  iExtr2);

  void       EraseFromProfile       (int                           iNb,
                                     CATICDSGeometryLeaf       **  iGL);

  void       ComputeCurve           (CATICDSPoint2D             *  iFirstPoint ,
                                     CATICDSPoint2D             *  iSecondPoint,
                                     CATICDSLine2D              *  iLine       , // Line en cas d'absence de points; proto NLD191218
                                     CATICDSGeometryLeaf        *  iGLCurve    ,
                                     double                        iStartParam ,
                                     double                        iEndParam   ,
                                     CATBoolean                    PrevEndUse  , // anciennement UseOfTangentInfo
                               const CATMathPoint                & PrevEndPt   , // ajout NLD201218
                               const CATMathVector               & PrevEndDir  , // anciennement PreviousTangdir
                                     int                           InitialOrient,
                                     CATCurve                   *& oCurve      ,
                                     CATCrvLimits                & oLimits     ,
                                     CATLONG32                   & oCrvOrient  ,
                                     CATLONG32                   & oSuppOrient );

  CATBoolean IsConstantLaw           (CATLaw                    *  iLaw,
                                      CATICDSGeomConstraint     *  iConstraint);

  CATBoolean ComputeHelpParameters   (CATICDSGeomConstraint     *  iOldConstraint,
                                      CATICDSGeomConstraint     *  iNewConstraint);

  CATBoolean GetHelpParameters       (CATICDSGeomConstraint     *  iOldConstraint,
                                      CATICDSGeometryLeaf       *  GeomUE,
                                      CATMathPoint               & HelpPoint);

  void       EvalCompositeCurvePrivate(double                      iT,
                                       CATFrFCompositeCurve     *& oFinalSection); 
  CATBoolean IsAValidCase             ();

  // FCX 05.2010 : a remplacer par la fonctionalite ReplaceObject de CDS !
  void       ReplaceConstraints            (CATICDSGeometryLeaf       *  iOldGL,
                                            CATICDSGeometryLeaf       *  iNewGL);

  void       ReplaceGeometryInProfile      (CATICDSGeometryLeaf       *  iOldGL,
                                            CATICDSGeometryLeaf       *  iNewGL);

  // FCX 09.2010
  void       EraseMarkFromTable            (CATICDSEntity             *  iEntity,
                                            CSMark                   **  iMarkTable,
                                            CATLONG32                    iNbMarks);

  // FCX 11.2010
  int        Reconverge                    ();
  void       FixMarchingParameter          (CATBoolean                   iFix);

  // FCX 01.2011
  void       ReplaceConstraintInLawTable   (CATICDSGeomConstraint     *  iOldConstraint,
                                            CATICDSGeomConstraint     *  iNewConstraint);

  // FCX 03.2011
  void       ComputeConstraintLists        (CATICDSGeometryLeaf       *  iCSGeo,
                                            CATICDSGeometryLeaf       *  iExtr1,
                                            CATICDSGeometryLeaf       *  iExtr2,
                                            CATCDSLISTP(CATICDSEntity) & oListTangencyOnUE,
                                            CATCDSLISTP(CATICDSEntity) & oListConstrOnUE,
                                            CATCDSLISTP(CATICDSEntity) & oListConstrCoExtremityUE,
                                            CATCDSLISTP(CATICDSEntity) & oListConstrCo,
                                            CATCDSLISTP(CATICDSEntity) & oListConstrTa,
                                            CATCDSLISTP(CATICDSEntity) & oListConstrOnExtremity1,
                                            CATCDSLISTP(CATICDSEntity) & oListConstrOnExtremity2);

  // FCX 03.2011
  void       ManageConstraintsCoExtremityUE(CATICDSGeometryLeaf       *  iCSGeo,
                                            CATCDSLISTP(CATICDSEntity) & iListConstrCoExtremityUE);
  
  // FCX 03.2011
  void       ManageTangencyCoincidence     (CATICDSGeometryLeaf       *  iCSGeo,
                                            CATICDSSkin               *  iSkin3D,
                                            CATCDSLISTP(CATICDSEntity) & ioListTangencyOnUE,
                                            CATCDSLISTP(CATICDSEntity) & ioListConstrOnUE,
                                            CATCDSLISTP(CATICDSEntity) & ioListConstrCo);
  
  // FCX 03.2011
  void       ManageTangencyCoincidence2D   (CATICDSGeometryLeaf       *  iCSGeo        ,
                                            CATCDSLISTP(CATICDSEntity) & ioListConstrTa,
                                            CATCDSLISTP(CATICDSEntity) & iListConstrCo );

  // FCX 03.2011
  void       ManageConstraintsOnUE         (CATICDSGeometryLeaf       *  iCSGeo         ,
                                            CATICDSGeometryLeaf       *  iExtr1         ,
                                            CATICDSGeometryLeaf       *  iExtr2         ,
                                            CATICDSSkin               *  iSkin3D        ,
                                            CATCDSLISTP(CATICDSEntity) & iListConstrOnUE,
                                            CATBoolean                 & oConstraintOnCanonicalUE);

  // FCX 03.2011
  void       ManageConstraintsOnExtremity  (CATICDSGeometryLeaf       *  iCSGeo         ,
                                            CATICDSGeometryLeaf       *  iExtr          ,
                                            CATICDSSkin               *  iSkin3D        ,
                                            CATCDSLISTP(CATICDSEntity) & iListConstrOnExtremity,
                                            CATBoolean                   iConstraintOnCanonicalUE);

  // FCX 03.2011
  CATICDSCurve* ExtractBoundaryCurve       (CATICDSSkin               *  iSkin          ,
                                            CATMathPoint               & iMP            );

  void       ManageCSTolerances            ();

  //=================================================
  //=================================================
  // DATA
  //=================================================
  //=================================================
  public:
  //19/03/07
  //JSX passage en public pour un acces plus facile aux données depuis l'interface (pour le CGMReplay)
  // Solvers ----------------------------------------------

  CATICDSAdvanced             * _CS;
  CATCDSVarSweepDriver        * _Driver;
  CATCDSVarSweepDriverImp     * _DriverImp;
  CATBoolean                    _DriverToBeRemoved;

private:
  CATGeoFactory               * _Factory;
  CATSoftwareConfiguration    * _Config;
  CATICDSFactory              * _pCDSFactory;
  CATICDSSimulationMarching   * _SimulationMarching;

  // marchings (one per domain)
  CATICDSSimulationMarching  ** _SimulationMarchings; 
  CATLONG32                     _MvFrameNbOfDomains;
  CATMathInterval            ** _MvFrameDomains;
  
  // Profile ----------------------------------------------

  CATLONG32                     _NbProfileGeometries;
  CATICDSGeometryLeaf        ** _ProfileGeometryTable;
  CATICDSPoint2D             ** _ProfileGeometryTableStartPt;
  CATICDSPoint2D             ** _ProfileGeometryTableEndPt;
  CATLONG32                     _NbSwProfileEdges;
  CATKnotVector              ** _TabSwKnotVector;
  CATBoolean                    _InvertedProfile;
  CATFrFNurbsMultiForm       ** _InitialSection;
  double                      * _InitialSectionParam;
  CATBoolean                    _CheckedWithInitialSection;
  double                      * _StartParamTable;
  double                      * _EndParamTable;
  CATBoolean                    _CDS_CGM_Link_Initialized;

  // Cleaned Guides relationship
  CATListOfInt                  _Guides2CleanedGuide_Tag;
  CATLISTP(CATGeometry)         _Guides2CleanedGuide_Ptr;

  // CDS Items --------------------------------------------

  CATICDSRigidSet             * _RS1;
  CATICDSRigidSet             * _RS2;
  CATICDSAxis                 * _SkAxis;
  CATICDSVariable             * _TimeVariable;

  // FCX 02.2010 : specifique FullDOFJoint
  CATICDSAxis                 * _FixedAxis;
  CATICDSFullDOFJoint         * _FDJoint;
  CATSweepSpineEquation       * _SpineEq[6];
  
  CATSweepSpineAxis           * _PosAxis;

  // FCX 09.2010
  CATSweepStreamTool          * _StreamTool;

  // Use-edges --------------------------------------------

  CSMark                     ** _ShellMarkTable;
  CSMark                     ** _WireMarkTable;
  CSMark                     ** _VertexMarkTable;
  CSMark                     ** _CstrMarkTable;
  CATLONG32                     _NbShellMarks;
  CATLONG32                     _NbWireMarks;
  CATLONG32                     _NbVertexMarks;
  CATLONG32                     _NbCstrMarks;
  CATLONG32                     _Nb3DWires;
  CATICDSGeometryLeaf        ** _3DWireTable;
  CATICDSCoincidence         ** _3DCoincidenceTable;
  CATLONG32                     _Nb3DSkins;
  CATICDSSkin                ** _3DSkinTable;
  CATICDSGeomConstraint      ** _3DConstraintTable;

  // Laws -------------------------------------------------

  CATLONG32                     _NbLaws;
  CATLONG32                     _NbUsedLaws;
  CATLaw                     ** _LawTable;
  CATICDSGeomConstraint      ** _ConstraintTable;
  CATLaw                      * _MvFrToLawParamMapping;
  CATSweepLaw                ** _SweepLawTable;
  CATICDSGeomDimConstraint   ** _VarConstraintTable;

  // Other data -------------------------------------------

  CATBody                     * _Spine;
  CATBoolean                    _GuideEqualsSpine;
  CATFrFMovingFrame           * _SweepMvFrame;
  double                        _MvFrameLength;
  CATFrFCoupling              * _Coupling;
  CATFrFSmoothedComb          * _SmoothNormal;
  CATFrFCompositeCurve        * _NormalCCV;
  CATLONG32                     _IdCcv;
  CATMathInterval               _MaxDomain;// jsx090209 Je supprime ce pointeur sur un micro objet 
  double                        _CSParam;
  int                           _SolveDone;
  short                         _MarchingLevel; // interpolation c0(500) ou classique(600)
  int                           _OKToleranceManagement;
  
  CATListOfInt                  _Profile_EdgeOrientation;

  // Tolerances -------------------------------------------

  double                        _EpsgForSquareLengthTest;
  double                        _EpsgForAngleTest;
  double                        _EpsgForRelativeTest;
  double                        _EpsgForLengthTest;

  CATListPV                     _LEntityToRemove;

  CATLISTP(CATCDSVarSweepGossip) _Gossi;
  CATListOfInt                  _ConnectionCont;

  // CDS helpers -------------------------------------------

  CATICDSSketch               * _pSketch;

  // evaluent les coordonnées 3D d'un point 2D dans le sketch du sweep, nécessitent _pSketch non nul
  CATCDSInline void SketchEvaluate2DPoint        (const double          iaPoint[2], double oaCoords[3]) const;
  CATCDSInline void SketchEvaluate2DPoint        (const CATICDSPoint2D* ipPoint2D , double oaCoords[3]) const;
  
  // evalue une direction 3D d'une direction 2D dans le sketch du sweep, nécessite _pSketch non nul
  CATCDSInline void SketchEvaluate2DDirection    (const double          iaPoint[2], double oaCoords[3]) const;

  // verifie si une entités est 2D, nécessite _CS non nul
  CATCDSInline CATBoolean          Is2D          (const CATICDSGeometryLeaf *ipGeometry) const;
  
  // recupere le nom de debug
  CATCDSInline void                GetName       (const CATICDSEntity       *ipGeometry, CATCDSString &oName) const;

  // recupere l'implementation des implementation CGM d'objets CDS
#ifdef MIGRATION_SWEEP_TO_CATCDSGMINFRA_SKIN
  CATCDSInline CATSkinGMImp     * GetSkinImp     (const CATICDSSkin        *ipSkin) const;
  CATCDSInline CATSkinParamGMImp* GetSkinParamImp(const CATICDSSkinParam   *ipSkin) const;
#else
  CATCDSInline CATSkinCGMImp     * GetSkinImp(const CATICDSSkin        *ipSkin) const;
  CATCDSInline CATSkinParamCGMImp* GetSkinParamImp(const CATICDSSkinParam   *ipSkin) const;
#endif

#ifdef MIGRATION_SWEEP_TO_CATCDSGMINFRA_CURVE
  CATCDSInline CATCSPropagationCurveGMImp  * GetCurveImp    (const CATICDSCurve       *ipCurve) const;
#else
  CATCDSInline CATCSCurveCGMImp  * GetCurveImp(const CATICDSCurve       *ipCurve) const;
#endif
};

#undef CATCDSEngineOverriding

#endif 
