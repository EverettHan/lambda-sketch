/* -*-c++-*- */
#ifndef CATDynSolidDraft_H
#define CATDynSolidDraft_H

#include "CATDynDraft.h"
#include "CATDynCNEXT.h"
#include "CATDRepExtTopOperator.h"
#include "CATDynDraftDomain.h"
#include "CATTopRibDef.h"
#include "ListPOfCATBody.h"
#include "ListPOfCATEdge.h"
#include "CATListOfInt.h"
#include "CATListOfCATPlanes.h"
#include "CATListOfCATSurfaces.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATVertex.h"
#include "ListPOfCATDomain.h"
#include "CATDraftParams.h"
#include "CATCreateDynAdvancedFilletFunction.h"

#include "BOIMPOPE.h"

#include "CATTopOpPrevisualization.h"  // pour enum previsu

class CATDomain;
class CATMultiDraft;
class CATDraft;
class CATMultiRibbonFillet;
class CATGenericHealing;
class CATAutomaticDraftContext;
class CATDynDraftContextForFastRun;
class CATCX_AuthorizedAnomaliesForCGMOperator;
class CATSoftwareConfiguration;

#include "CATDynDraftReorderZone.h" // SOU : 2004:3:9

//GapFill Integration
#include "CATBSDGapFillFunction.h"

class ExportedByBOIMPOPE CATDynSolidDraftCGM : public CATDRepExtTopOperator
{
  public :
  CATDynSolidDraftCGM ( CATGeoFactory &                    iContainer,
                        CATTopData &                       iData,
                        CATBody*                           iPart,
                        const CATDynDraftType              iType,
                        CATDynDraftFillFunction            iImplicitFillFct,
                        CATCreateDynAdvancedFilletFunction iCreateDynAdvFilletFunction=0,
                        CATBSDGapFillFunction          iGapFillFunction =0);

  public :

  CATDynSolidDraftCGM ( CATGeoFactory &    iContainer,
                        CATBody       *    iPart,
                        CATSoftwareConfiguration *iConfig,
                        const CATDynDraftType iType,
                        CATDynDraftFillFunction iImplicitFillFct,
                        CATCGMJournalList* journal=NULL);

  public :
  virtual ~CATDynSolidDraftCGM();

  CATCGMNewClassArrayDeclare;        // Pool allocation

  public :
  int Run();
  int RunOperator();

  private:
  int Run2(CATBoolean         iTrueMultiRibMode, 
           CATCGMJournalList *iJournal);

  public :
  virtual void Add (CATBody           *PartingElement,
                    CATOrientation     PartingOrientation = CATOrientationUnknown,
                    CATBoolean         IsPartingUntil     = FALSE) ;

  public :
  virtual void Add (CATSurface        *PartingSurface,
                    CATOrientation     PartingOrientation = CATOrientationUnknown,
                    CATBoolean         IsPartingUntil     = FALSE) ;

  public :
  virtual void Add (CATPlane          *PartingPlane,
                    CATOrientation     PartingOrientation = CATOrientationUnknown,
                    CATBoolean         IsPartingUntil     = FALSE) ;

  public :
  virtual void AddLimiting (CATBody           *iLimitingElement,
                            CATOrientation     iLimitingOrientation = CATOrientationUnknown,
                            CATBoolean         iLimitingUntil       = FALSE) ;

  public :
  virtual CATOrientation GetCalculatedOrientationOnParting() ;

  public :
  virtual void Add (CATDynDraftDomain *DraftDomain    ) ;

  public :
  virtual void Add (CATDynDraftDomain        *iDraftDomain1,
                    CATDynDraftDomain        *iDraftDomain2,
                    CATDynDraftBothSidesType  iBothSidesType = CATDrivingDriven,
                    double                    iIdealRadius   = 0.0);
  
  public :
  virtual void SetPrevisualizationOnly ();
  
  public :
  virtual void SetPrevisualizationMode (CATDynDraftPrevisualization iMode);

  public:
  void GetParametersForDynFilteringOfAnomalies(CATCX_AuthorizedAnomaliesForCGMOperator *piAuthorizedAnomaliesForCGMOperator);
  

  public :
  CATDynDraftFillFunction GetUntwistDraftFillFunction () const;
  
  public :
  CATBoolean IsUntwistDraftFillFunctionUsed () const;
              
  public :
  //We will get error if fill function is set with SetAutomaticUntwistMode
  void SetUntwistDraftFillFunction (CATDynDraftFillFunction iFillFct);

  public :
  virtual void SetJunctionMode (CATBoolean iJunctionMode);

  public :
  virtual void SetJournalInfoMode (CATDynDraft::JournalInfoMode iInfoMode = CATDynDraft::SingleOp);

  public :
  virtual CATDynValidShellType ValidateShellOutput (CATLISTP(CATBody) &oListBody);

  public:
  void SetHealer(CATGenericHealing* iHealer);

  //------------------------------------------------------------------------------
  // Set the continuity level for the resulting geometry:
  // 0 - point continuity (G0)
  // 1 - tangency continuity (G1)
  //------------------------------------------------------------------------------
  public:
  void SetContinuityLevel(const int               iContinuityLevel,
                          const CATPositiveLength iTolerance = 0.0);

  //------------------------------------------------------------------------------
  // Set conical reflect line mode
  // Method is dedicated for CATTopReflectLine operator only
  // Method needs to be called before Run()
  //------------------------------------------------------------------------------
  public:
  void SetConicalReflectMode(CATBody *iOriginPt) { _ConicalReflectOriginPt = iOriginPt; }

  //Live Draft
  virtual void AddDeclarativeManifoldAgents(CATCellManifoldsManager& iCellManifoldsManager,
                                            ListPOfCATBody &iListOfInputBodies, 
                                            ListPOfCATBody &iListOfNoCopyInputBodies,
                                            CATBody * iOutputBody, 
                                            CATCGMJournalList* iTopOpJournal);

  //------------------------------------------------------------------------------
  // VoB 
  //------------------------------------------------------------------------------
  public:
  virtual CATBoolean IsVoBSupported();
  //------------------------------------------------------------------------------
  // CGMReplay 
  //------------------------------------------------------------------------------
  public :
  static const CATString *GetDefaultOperatorId() { return &_OperatorId; }

 protected:
  static CATString _OperatorId;
  const CATString * GetOperatorId() const;

 public:
  void             RequireDefinitionOfInputAndOutputObjects();
  void             WriteInput(CATCGMStream &ioStream);
  void             Dump(CATCGMOutput &os);

  //------------------------------------------------------------------------------
  // Authorized members only
  //------------------------------------------------------------------------------
  protected :
  CATBody*                    _Part;
  CATDynDraftType             _DraftType;
  CATBody*                    _InputPartingBody;
  CATSurface*                 _InputPartingSurface;
  CATPlane*                   _InputPartingPlane;
  CATLISTP(CATBody)           _LimitingBodies;
  CATOrientation              _PartingOrientation;
  CATListOfInt                _LimitingOrientations;
  CATListOfInt                _LimitingUntil;
  CATBoolean                  _PartingUntil;
  CATLISTP(CATDynDraftDomain) _DraftDomains;
  CATBoolean                  _UnionMode;
  CATBoolean                  _ThrowErr;
  CATListPV                   _PartingData;        // donnee membre pour des fins MLK 
  CATListPV                   _ListeFacesLimiting; // idem


  //------------------------------------------------------------------------------
  // Internal structures
  //------------------------------------------------------------------------------
  private :
  struct CATDraftDomainData
  {
    CATBody                    *NeutralBody;
    CATDomain                  *NeutralDomain;
    ListPOfCATFace              NeutralFaces;
    CATBoolean                  NeedToRemoveNeutralBody;
    CATBoolean                  NeedToRemoveNeutralFaces;
    CATBoolean                  NeutralEqParting;
    CATDraftParams              Params;
    CATDraftType                Type;
    CATDynDraftDomainType       DomainType;
    ListPOfCATFace              InitialFaces;
    CATDomain                  *InitialDomain;
    CATListPV                   GroupOfInitialFaces;
    ListPOfCATEdge              NeutralEdges;
    CATListOfInt                NeutralEdgesOrient;
  };

  //------------------------------------------------------------------------------
  // initialize the contents of a DraftDomainData structure
  //------------------------------------------------------------------------------
  private :
  void Initialize(CATDraftDomainData &iDraftDomainData);

  //------------------------------------------------------------------------------
  // Lecture des domaines
  //------------------------------------------------------------------------------
  private :
  CATBoolean ReadDraftDomains(CATGeoFactory      *iFactory,
                              CATCGMJournalList *iJournal,
                              CATBody            *iPartingBody,
                              ListPOfCATFace     &iPartingFaces,
                              CATDomain          *iPartingDomain,
                              CATLONG32               &oNbDomains,
                              CATDraftDomainData  oDraftDomainData[CATTopDraftMaxNbDirections]);

  //------------------------------------------------------------------------------
  // Generate one-sided draft operations
  //------------------------------------------------------------------------------
  private :
  void GenerateOneSidedDraftOperations (CATMultiDraft      *iMultiDraft,
                                        CATDraftDomainData &iDraftDomainData,
                                        int                 iParting,
                                        CATBody            *iPartingBody, 
                                        ListPOfCATFace     &iPartingFaces,
                                        CATDomain          *iPartingDomain,
                                        CATOrientation      iPartingOrientation,
                                        CATLONG32                iPartingContext,
                                        CATBoolean          iIsPartingUntil,
                                        CATLISTP(CATBody)  &iLimitingBodies,    
                                        CATListOfInt       &iLimitingOrientations,
                                        CATListOfInt       &iIsLimitingUntil,
                                        int                 iDrftDom,
                                        CATCGMJournalList *iJournal = NULL);

  //------------------------------------------------------------------------------
  // Generate BothSides draft operations
  //------------------------------------------------------------------------------
  private :
  void GenerateBothSidesDraftOperations (CATMultiRibbonFillet *iMRF,
                                         CATDraftDomainData   &iDraftDomainData1,
                                         CATDraftDomainData   &iDraftDomainData2,
                                         int                   iParting,
                                         CATBody              *iPartingBody, 
                                         ListPOfCATFace       &iPartingFaces,
                                         CATDomain            *iPartingDomain,
                                         CATOrientation        iPartingOrientation,
                                         CATLONG32                  iPartingContext,
                                         CATBoolean            iIsPartingUntil,
                                         CATLISTP(CATBody)    &iLimitingBodies,
                                         CATLISTP(CATDomain)  &iLimitingDomains,
                                         CATListOfInt         &iLimitingOrientations);

  //------------------------------------------------------------------------------
  // Execution de l'operateur MultiDraft
  //------------------------------------------------------------------------------
  private :
  void ExecuteMultipleDraft(CATMultiDraft     *iMultiDraft,
                            CATBody           *iResult,
                            CATCGMJournalList *iJournal);

  //------------------------------------------------------------------------------
  // Execution de l'operateur MultiBothSidesDraft
  //------------------------------------------------------------------------------
  private :
  void ExecuteMultipleBothSidesDraft(CATMultiRibbonFillet  *iMRF,
                                     CATBody              *&ioResult);

  
  //------------------------------------------------------------------------------
  //Topological healing on result body
  //------------------------------------------------------------------------------
  private :
  // healing for gaps
  CATBoolean HealMRFResult( CATBody *&ioResult);
  // healing for sharp edges
  CATBoolean GenericHealMRFResult( CATBody *&ioResult);

  private :
  CATDynDraftFillFunction      _UntwistFillFct;
  CATBSDGapFillFunction        _UntwistGapFillFct;
  CATBoolean                   _IsUntwistFillFctUsed;
  CATBoolean                   _JunctionMode;
  CATBoolean                   _IsJunctionModeUsed;
  CATBoolean                   _BothSidesMode;
  CATDynDraftBothSidesType     _BothSidesType;
  double                       _IdealRadius;
  CATTopOpPrevisualization     _Previsu;
  CATDynDraft::JournalInfoMode _JournalInfoMode;  
  CATBody *                    _ErrorBody;
  int                          _ReLaunch;
  CATOrientation               _CalcPartingOri;

  CATGenericHealing*           _Healer;
  int                          _ContinuityLevel;
  //BQJ Start
  double                       _PartingElemAdjTol; 
  int                          _NbUserLimitingElemForSecondAttempt;
  CATLISTP(CATGeometry)        _allCapFaces;
  CATBoolean                   _IsSecondAttempt;
  CATCGMJournalList    *       _TempHealerJournal;
  CATBoolean                   _IsFirstAndLastTwisted;
  //BQJ End

  // PFV 2004:01:16
  CATMultiRibbonFillet *       _MRF;
  //CATMultiDraft        *       _MD;
  //CATMultiDraft         *      _MD[2]; //D1A
  CATMultiDraft         *      _MD[3]; //DSH1 2021 : to support NDir Draft with 3 Pull Directions
    
  CATLISTP(CATBody)            _iBodies_NCGM;
  //CATDraftDomainData           _DraftDomainData[CATTopDraftMaxNbDirections];
  CATDraftDomainData   *       _DraftDomainData; //D1A
  CATCGMJournalList    *       _PrivateJournal;
  
  ListPOfCATFace               _PartingFaces;
  CATBody              *       _PartingBody; 
  CATDomain            *       _PartingDomain;
    
  CATBoolean                   _NeedToRemovePartingBody  ;
  CATBoolean                   _NeedToRemovePartingFaces ;
  
  CATBody              *       _result ;
  int                          _RunDone ; // Legal values : 0 = Run Not Done Yet, 1 = Run OK, 2 = Run KO
  CATBoolean                   _CleanUpDone;
  CATBody              *       _OldCreationBody;
  CATBody                     *_ConicalReflectOriginPt; // added by AJD for conical reflect line
  // End pfv 2004:01:16

  CATCreateDynAdvancedFilletFunction _CreateDynAdvFilletFunction;

  //------------------------------------------------------------------------------
  // Protection temporaire contre l'echec de la propagation du ruban dans
  // les cas ou la face neutre est unique et a plus d'une arete commune
  // avec l'une des faces a depouiller
  //
  // (DomainIndex commence a 0)
  //------------------------------------------------------------------------------
  private :
  void CreateNewNeutralFaceIfNecessary(CATGeoFactory* iFactory
                                      ,CATCGMJournalList *iJournal
                                      ,CATDraftDomainData& ioDraftDomainData
                                      ,const CATMathDirection& iDraftDirection
                                      ,CATLISTP(CATCell)* iAuxNeutralFaces=0 //SOU for BSD Neutral
                                      ,CATBody * iNeutralBody=0); //PFV for multiface neutral extrapolation

  //------------------------------------------------------------------------------
  // Service de CreateNewNeutralFaceIfNecessary :
  // - rend le ratio a passer a CATExtandSurLimits dans le cas d'une face
  //   neutre de surface non plane. Prend en compte l'encombrement du body
  //   a drafter.
  //------------------------------------------------------------------------------
  private :
  double GetExtandFactor
   (CATGeoFactory          *iFactory,
    CATFace                *iInitialFace, 
    CATBody                *iInitiaBody,
    const CATMathDirection *iDraftDirections     = NULL,
    int                     iNbDraftDirections   = 0,
    double                  iBodyBoxInflateRatio = 1);

  //------------------------------------------------------------------------------
  // Create faces from a given surface
  //------------------------------------------------------------------------------
  private :
  void CreateFacesFromSurface (CATGeoFactory            *iGeoFactory,
                               CATSurface               *iSurface,
                               CATBody                  *iInitialBody,
                               CATFace                  *iInitialFace,
                               CATLONG32                 iBoxScalingFactor,
                               CATBody                 *&oBody,
                               CATDomain               *&oDomain,
                               ListPOfCATFace           &oFaces,
                               CATBodyFreezeMode         iBodyFreezeMode      = CATBodyFreezeOn,
                               CATCGMJournalList        *iJournal             = NULL,
                               const CATMathDirection   *iDraftDirections     = NULL,
                               int                       iNbDraftDirections   = 0,
                               double                    iBodyBoxInflateRatio = 1);

  //------------------------------------------------------------------------------
  // Check if a given surface has already been used in the Parting element
  //
  // Please note:
  // iPartingFaceIndex, if provided (between 1 and [number of Parting faces], is
  // the index of the Parting face with which to compare the surface
  // if iPartingFaceIndex is 0, the surface is NOT compared with any of the
  // Parting faces
  //------------------------------------------------------------------------------
  private :
  CATBoolean IsSurfaceUsedInPartingElement (CATSurface *iSurface,
                                            CATLONG32        iPartingFaceIndex = 0);

  //------------------------------------------------------------------------------
  // Nettoyage des elements neutres crees
  //------------------------------------------------------------------------------
  private :
  void CleanUpDraftDomainData (CATGeoFactory      *iFactory,
                               CATDraftDomainData &iDraftDomainData);

  //------------------------------------------------------------------------------
  // Nettoyage des Parting elements crees
  //------------------------------------------------------------------------------
  private :
  void CleanUpCreatedPartingElements (CATGeoFactory       *iFactory,
                                      CATCGMJournalList   *iJournal,
                                      ListPOfCATFace      &ioPartingFaces,
                                      CATBody            *&ioPartingBody,
                                      CATDomain          *&ioPartingDomain,
                                      CATBoolean           iNeedToRemovePartingBody,
                                      CATBoolean           iNeedToRemovePartingFaces);

  //------------------------------------------------------------------------------
  // Determination du Parting Element
  //------------------------------------------------------------------------------
  private :
  void GetPartingElement (CATGeoFactory      *iFactory,
                          CATCGMJournalList  *iJournal,
                          CATBody            *&oPartingBody,
                          ListPOfCATFace      &oPartingFaces,
                          CATDomain          *&oPartingDomain,
                          CATLONG32                &oPartingContext,
                          CATOrientation      &oPartingOrientation,
                          int                 &oParting,
                          CATBoolean          &oNeedToRemovePartingBody,
                          CATBoolean          &oNeedToRemovePartingFaces,
                          CATBoolean          &oIsPartingUntil);

  //------------------------------------------------------------------------------
  // Recup Limitings
  //------------------------------------------------------------------------------
  private:
  int GetLimitingElements(CATLISTP(CATBody)   &oLimitingBodies,
                          CATLISTP(CATDomain) &oLimitingDomains,
                          CATListOfInt        &oLimitingOrientations,
                          CATListOfInt        &oLimitingUntil);

  //------------------------------------------------------------------------------
  // Recup orientation d'un elt limiting
  //------------------------------------------------------------------------------
  private :
  void GetLimitingOrientation (CATBody         *iLimitingBody,
                               CATOrientation  &oLimitingOrientation);

  //------------------------------------------------------------------------------
  // Recuperer l'element neutre du DraftDomain en cours
  //------------------------------------------------------------------------------
  private :
  void GetNeutralElement (CATLONG32                iDomain,
                          CATGeoFactory      *iFactory,
                          CATBody            *iPartingBody,
                          ListPOfCATFace     &iPartingFaces,
                          CATDomain          *iPartingDomain,
                          CATDraftDomainData &ioDraftDomainData);

  //------------------------------------------------------------------------------
  // Sort groups of adjacent Faces sharing a common smooty Edge
  //------------------------------------------------------------------------------
  private :
  void SortFaces(CATBody               * iBody,
                 CATDynDraftDomainType & iDomainType,
                 ListPOfCATFace        & iRibbonFaces,
                 CATListPV             & oGroupOfFaces,
                 CATBody               * iNtrlBody=NULL); //D1A : added iNtrlBody

//------------------------------------------------------------------------------
// Retrieves the position of all a group of RibbonFaces sharing a least one
// smooth edge
//------------------------------------------------------------------------------
  private :
  void GetAdjacentRibbonFaces(CATBody        * iBody,
                              CATFace        * iFace, 
                              ListPOfCATFace & iRibbonFaces,
                              CATListOfInt   * oGroupOfFaces);
  
  //------------------------------------------------------------------------------
  // Union between different lumps
  //------------------------------------------------------------------------------
  private :
  void UniteLumps(CATMultiDraft      *iMD,
                  CATCGMJournalList  *iJournal);

  //------------------------------------------------------------------------------
  // Set the Union mode
  //------------------------------------------------------------------------------
  private :
  void SetUnionMode(CATBoolean iUnionMode);

  //------------------------------------------------------------------------------
  // Get the Union mode
  //------------------------------------------------------------------------------
  private :
  CATBoolean GetUnionMode();

  //------------------------------------------------------------------------------
  // Ajout du resultat avec reference
  //------------------------------------------------------------------------------
  private :
  void SetReferenceResult (CATBody *iResult);


  // Start : SOU : 2003:9:23
  private:
  CATBoolean TrimSewTriangularBodies(CATMultiDraft *iMD,CATCGMJournalList *iJournal);

  CATBoolean TrimSewBodies(CATBody * iBody, CATBody *&iBodyToSew, ListPOfCATFace &iCoveredFaces
                           ,CATCGMJournalList *iJournal, const CATBoolean &iFreezeReuslt
                           ,CATBody * &oResultBody );
  // End : SOU : 2003:9:23

  // pfv : 2004:01:16
  private:
  void CleanUp();

  public:
  virtual CATBody* GetResult();
  // End pfv : 2004:01:16


  // Start : SOU : 2004:3:9
  public:
  //Get the number of twist zones that caused the failure of draft operation
  int GetNumberOfTwistZones();

  //Get the reorder zone corresponding to a given twist zone index and given CATDynDraftReorderZoneParams 
  CATBoolean GetReorderZone(const int &iReorderZoneIndex, CATDynDraftReorderZone* &oReorderZone
                            ,CATDynDraftReorderZoneParams* iReorderParams = 0
                            ,CATDynDraftReorderZoneParams** ioDefaultReorderParams = 0);
                                  
  //to be used before Run()
  CATBoolean SetReorderZone(CATDynDraftReorderZone *iReorderZone);

  //to be used before Run()
  CATBoolean SetReorderZone2(CATDynDraftReorderZone *iReorderZone);

  // for keep feature
  void SetKeepFeature( CATBoolean iKeepFeature );

  //to be used before Run()
  //By default automatic untwist mode is off
  //one can activate it by using iAutoUntwistMode=TRUE
  //We will get error if activated together with SetUntwistDraftFillFunction
  void SetAutomaticUntwistMode(CATBoolean iAutoUntwistMode); 

  void SetAutomaticGapFillMode(CATBoolean iAutoGapFillMode); 

  //iOffset = the offset used to modify the limits of default twist zones  on neutral wire (mm). 1mm is the default offset
  void SetAutomaticUntwistOffset(double iAutoUntwistOffset); 

  static void ReadReorderZone(CATGeoFactory* iFactory, CATCGMStream &Str, CATCGMODTScaleManager* iODTScaleManager, CATDynDraftReorderZone* &oZone, CATDynDraftReorderZoneParams* &oParam);

  static void WriteReorderZone(CATDynDraftReorderZone* iZone, CATCGMStream &Str);

  protected:

  CATLISTP(CATDynDraftReorderZone)          _SetReorderZones; 
  CATLISTP(CATDynDraftReorderZone)          _SetReorderZones2; //D1A
  CATBoolean                                _KeepFeature;
  CATBoolean                                _IsAdvanced; //TRUE if the interface is for Draft Reorder
  CATDynDraftFillFunction                   _ImplicitUntwistFillFct;
  CATBoolean                                _AutoUntwistMode;//if it is TRUE then automatic untwist is attempted using appropriate fat parameters
  CATBoolean                                _AutoGapFillMode; //if it is TRUE then automatic gap fill is attempted 
  double                                    _UntwistOffset;// the offset used to modify the limits of default twist zones  on neutral wire (mm) default value is 1.0 mm
  CATAutomaticDraftContext*                 _AutomaticDraftContext;
  CATBoolean _OptimizedDomainStructure;
  CATBoolean _FilterBorderSolution;

  private:
  void ReInitialise(); //to initialise data members which have been modified because of Run2

  void CleanResultBody(CATBody *iBody);
  // End : SOU : 2004:3:9
  
  // pfv : 2004:03:26
  public:
  int GetNumberOfLimitingElements();
  void GetLimitingElement(int iNumber, double iShift, CATBody *& oLimitingElement, CATOrientation &oOrientation, double *oGapFillData = NULL);
  // End pfv


  // Start : SOU : 2004:9:7
  private:
  CATBoolean CheckTentProblem( CATFace* iNeutralFace, const CATMathVector &iExtrusionDir,CATFace* iSupportFace
                              , const CATListPV &iExtrusionUnits, const CATMathDirection &iPullDir, CATAngle iDraftAngle
                              , const CATListOfInt &iStartSubProfiles, const CATListOfInt &iEndSubProfiles
                              , const CATListOfInt &iNumSharpCommonEdges
                              , CATBoolean iIsExtrudedHole=FALSE ); //DSH1 March 2015 For IR-338355. New parameter iIsExtrudedHole added.
  // End : SOU : 2004:9:7

  //pfv 2005:12:06
  public:
  void SetAutomaticDraftContext(CATAutomaticDraftContext *iContext);
  // end pfv
  void SetOptimizeDomainStructure();
  void FilterBorderSolution();
  void SetVolumetricSweepMode(const CATMathVector &iFirstVector, const CATMathVector &iSecondVector);
  void EnableSurfaceSolutions() { _EnableSurfaceSolutions = TRUE; }; // S9L : Silhouette : ER-047062 : Meyer Werft

  // Start : BQJ : 2007:03:12
  private:
  void UpdateJournalForMaximumBSD(CATBody *ResultBody, CATCGMJournalList *tempJournal);
  CATLISTP(CATBody)           _IntermediateBodies;
  
  public:
  CATCGMJournalList* GetTempHealerJournal();
  protected:
  CATBoolean GetFirstAndLastTwisted();
  // end BQJ

  //-----------------------------------------------------------------------
  // Fast Update
  //-----------------------------------------------------------------------  
   public :
   CATContextForFastRun*           GetContextForFastRun();
   CATDynDraftContextForFastRun*   GetDynDraftContextForFastRun();
   CATContextForFastRun*           GetOrCreateContextForFastRun();
   CATDynDraftContextForFastRun*   GetOrCreateDynDraftContextForFastRun();
   CATBody*                        GetInputBody(); 

   /** @nodoc @nocgmitf */
   void SetInputBody(CATBody * iInputBody) {_Part = iInputBody;}

   /** @nodoc @nocgmitf */
   CATLISTP(CATDynDraftDomain) & GetDraftDomains() {return _DraftDomains;}

   int FastRun();
  // int                           PartialRun(CATBody * ipFastRunResultBody, CATCGMJournalList * ipFastRunJournal);
  // int                           FindArgumentsForFastRun(CATConnexComponentManager *  iEdgesConnexComponentsOI,
  //                                                       CATDrawerCollector *& oRelation_FilletRibbon_ConnexeComponents,
  //                                                       CATDrawerCollector *& oRelation_ConnexeComponent_FilletRibbons
  //                                                       );

  //----------------------------------------------------------
  //Reflect line for Silhoutte
  //----------------------------------------------------------
   public:
   void ExtractIsoCurves() {_ExtractIsoCurves = TRUE;} //D1A: 19-Nov-12

   private:
   CATBoolean _ExtractIsoCurves;  
   //D1A: Start
   CATBoolean _BothSidesTypeIndependent; 
   int _NumTwistsFirstSide;
   CATBoolean CheckDraftDomainsBothSidesIndependent(int inbDomains);
   int FindNumberOfDrafts(int iNbDomains);
   void UpdateInputsForSecondDomain(int iDrftDom, CATGeoFactory      *iFactory,
                                    CATCGMJournalList *iJournal,
                                    CATBody* volatile & ioInBody, CATBody * volatile & ioOutBody, 
                                    CATOrientation & ioPartingOrientation, CATError * volatile iTwistError);
   
   CATListPV _ParamsMultiAngleDraft;
   CATBoolean ComputeDraftParamsForMAD(CATDynDraftRibbon * iDraftRibbon, CATMathDirection * iDirection);
    
   //D1A : Start: Sep 2012
   CATBody * _pInpBody;
   CATBoolean _InitialFacePropag; //To allow/disallow tangent propagation of initial faces to draft

   //D1A: Step Draft: Start: July-Aug 2013
   CATLISTP(CATCell) _PartingEdges; //D1A: 26 June 2013
   CATLISTP(CATCell) _PartingEdgesForDraft2; //D1A: 26 June 2013
   CATLISTP(CATFace) _PartingFacesForStep; //D1A: 26 June 2013 
   CATBoolean ArePartingEdgesOK(int iDrftDom);
   void CreateFaceOnPartingEdge(CATEdge * iPartingEdge, CATFace * iFace, CATLISTP(CATFace) & oListOfFaces, CATCGMJournalList *iJournal);
   void ExtrapolateAndSetPartingForStep(CATBody * iBody, CATCGMJournalList *iJournal);
   void SetNeutralAsPartingBody(int iDrftDom);
   void SetBodiesForStepAsLimitingElemts(CATLISTP(CATBody) & iListOfBodies, int & side, CATCGMJournalList *iJournal);
   CATBoolean UseAsPartingForStep(int iDrftDom);
   void RemoveFacesConfusedWithNeutral(int iDrftDom, CATLISTP(CATCell) & ioListOfFaces);
   void SplitPartingWiresByNeutral(int iDrftDom);
   void CreatePartingFacesForStepDraft(int iDrftDom, 
                                        CATFace *  iInputFace, 
                                        CATLISTP(CATCell) & iListOfEdges, 
                                        int StepSide, 
                                        CATBoolean iUseAsParting,
                                        CATCGMJournalList *iJournal);//D1A: 26 June 2013
   int SecondDraftForStep(int iDrftDom);  
   CATLISTP(CATBody) _BodiesForStep2;
   CATLISTP(CATBody) _BodiesForStep; //D1A: 26 June 2013 
   CATListOfInt _LimitingOri1;
   CATListOfInt _LimitingOri2;
   void RemoveEdgesLyingOnNeutral(CATLISTP(CATCell) & ioListOfEdges, int iDrftDom);
   short _StepDraftMode;
   //Step Draft: End

   public:
   void SetStepDraftMode (CATDynDraft::StepDraftMode iStepDraftMode = CATDynDraft::Perpendicular); 
   CATBoolean _VolSweepMode;
   CATMathVector _FirstVector, _SecondVector;

   public:
   void SetInitialFacePropag (CATBoolean iTgtPropagMode) {_InitialFacePropag = iTgtPropagMode;}
   //D1A: End
   
   void SimplifyDraftOnTransversEdges(CATBoolean iSimplifyDraft) { _SimplifyDraft = iSimplifyDraft; }

   private:
     //D1A: Check if new neutral is required to be created, in case of TrueMultiRibbon mode 
     void CreateNewNeutralForTMRifRequired(int iDrftDomain, CATGeoFactory *iFactory, CATMathDirection & iPullDir, CATFace* iNeutralFace); //D1A: 18-April-2013

   //D1A Start: 26-Sept-13: IR-132819
   //Checks all faces to draft are co-planar only when, there is single neutral Face having CATPlaneType 
   //Surface Geometry and there is atleast one common edge between Neutral and face to draft.
   CATBoolean AreAllFacesToDraftCoplanar( CATDraftDomainData & iDraftDomainData,CATLISTP(CATCell)* iAuxNeutralFaces );

   //checks two faces are coplanar or not
   //should be called only when both faces have CATPlaneType Surface Geometry
   CATBoolean AreFacesCoplanar( CATFace *iFirstFace,CATFace *iSecondFace );

   //Check if there is atleast one common edge between Neutral and Faces to Draft.
   CATBoolean IsAtleastOneCommonEdge( CATDraftDomainData & iDraftDomainData,CATLISTP(CATCell)* iAuxNeutralFaces );
   //D1A End: 26-Sept-13: IR-132819

private:
  // S9L : TMC issue : Use of Thick Operator : Start
  //------------------------------------------------------------------------------
  // Add pseudo parting
  //------------------------------------------------------------------------------
  void AddPseudoParting(CATMultiDraft *iMD);
  //------------------------------------------------------------------------------
  // Apply thickness
  //------------------------------------------------------------------------------
  void ApplyThickness(CATMultiDraft *iMD);
  // S9L : TMC issue : Use of Thick Operator : End

  CATBoolean _IsMultiInputDraft; //D1A: Feb 2014
  CATListPV * _PartingDataForEachDomain;
  // S9L : Draft Untwist Enhancement : Start
	// Split GeoNuplets after identifying the twist zone around twist params by duplicating geometry
	// This will create a new Nuplet which isolates twisted zones in the form of a separate GeoNuplets 
	// to be discarded for surface fill
	CATBoolean _SplitAroundTwistZone;
	CATListOfInt _RlmTwistedNuplets;
  // S9L : Draft Untwist Enhancement : End
  
  CATBoolean _EnableSurfaceSolutions; // S9L : Silhouette : ER-047062 : Meyer Werft
  CATBoolean _SimplifyDraft;

  private:
    CATBoolean _ExternalNtrl;
    void SortInitialFace(CATBody* &ipBody, ListPOfCATFace & ioInitialFaces, ListPOfCATFace & ioNeutralFaces); //DSH1 Feb 2020
    void GenerateDraftOperationsForMultiInputDraft(CATMultiDraft *iMultiDraft, CATDraftDomainData &iDraftDomainData); //D1A 2020

    //D1A start Nov 2020: Added for Hole For Volume Draft AddRemove cases very large angle failures
    CATBoolean IsPossibleHoleForVolumeCase(CATBoolean iThickCase = 1);
    void CalculateOffsetValueForThickness(CATMultiDraft *ipMD);
    void CreateNewInputBodyReducedHeightForHFVcase(int iDrftDom, CATGeoFactory * ipFactory, CATCGMJournalList * ipJournal);
    void UpdateDraftDomainData(CATCGMJournalList * ipJournal, int iDrftDom);
    void ThickenOutputBodyForHFVCase(CATGeoFactory *ipFactory, CATCGMJournalList * ipJournal);
    double _OffsetValueForHFVcase;
    CATFace * _FaceToOffsetInThick;    
    //D1A end Nov 2020
    CATBoolean _PossibleHoleForVolumeCase; //D1A Aug 2021

 //DSH1 Start Dec 2021 : NDir for TMC HFV
    CATBoolean _HFV_MultiInput; 
    CATBoolean _NeedOrderAgnosticResult;

  public:
    void NeedOrderAgnosticResult(CATBoolean iValue = TRUE);
  private:
    //Sort DraftDomainData according to stable pulling direction order
    void SortDraftDomainData();
 //DSH1 End Dec 2021
    void ProcessJournalForAddRemoveConfig(CATCGMJournalList *&ioDirJournal); //DSH1 Nov 2022

    void ProcessJournalForUniqueInfo(CATCGMJournalList*& ioDirJournal);//DSH1 April 2023 : IR-964182
    void UpdateInfoForDraftedFaces(CATCGMJournalList *&ioJournal);//DSH1 April 2023 : IR-964182
};
#endif
//automate:10/09/01:suppression include de CATSkinOperator.h
//automate:10/09/01:suppression include de CATListOfInt.h
