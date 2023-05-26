/* -*-c++-*- */

//=============================================================================
// Copyright Dassault Systemes 1997-2011, all rights reserved
//=============================================================================
//
// CATDynSolidFillet :
//
//=============================================================================
// Usage notes:
//=============================================================================
//      1997     Creation
// Sep. 2009     CATBlendG2Section                            H. Leban
//=============================================================================
#ifndef CATDynSolidFillet_H_
#define CATDynSolidFillet_H_

#include "CATDynFillet.h"
#include "CATDynFilletRibbon.h"
#include "BOIMPOPE.h"
#include "CATDynSolidXCGM.h"

#include "ListPOfCATBody.h"
#include "ListPOfCATShell.h"
#include "CATCGMNewArray.h"

#include "CATFilletVariousParameters.h"
#include "CATDynFilletVertexRibbonOrder.h"
#include "CATMathPoint.h" // Help Point option
#include "CATLISTP_CATMathPoint.h"
#include "CATLISTP_CATMathDirection.h"
#include "CATDynEdgeFilletRibbon.h"
#include "CATListOfDouble.h"
#include "CATTopoOpeCallBacks.h"


class CATVariableFilletSpineTools;
class CATBlendParams;
class CATParting;
class CATFilletCrossPartingLinker;
class CATRibbonsReorderTracker;
class CATMultiRibbonFillet;
class CATBody;
class CATShell;
class CATDomain;
class CATCGMJournalList;
class CATEdgeRibbon;
class CATBlendVertexSpec;
class CATBlendVertex;
class CATContextForFastRun;
class CATDynFilletContextForFastRun;
class CATConnexComponentManager;
class CATDrawerCollector;
class CATConnectTool;


class ExportedByBOIMPOPE CATDynSolidFilletCGM : public CATDynSolidXCGM
{
 public:
  CATDynSolidFilletCGM (CATGeoFactory &     iContainer,
                        CATTopData &        iData,
                        CATBody *           iPart=NULL);

  CATCGMNewClassArrayDeclare;        // Pool allocation

  ~CATDynSolidFilletCGM();
  
  int RunOperator();
  
  void Append ( CATDynFaceFaceFilletRibbon* )  ;
  void Append ( CATDynEdgeFilletRibbon* )      ;
  void Append ( CATDynRemoveFaceFilletRibbon* );

  void AddLimitingElement (CATBody* iBody, CATDomain* iSkin , const CATOrientation iOrientation, 
                           const int iSmartCrossParting=0, CATFilletReconfigFillFunction iFillFct=NULL);
  void AddLimitingElement (CATBody* iBody, CATDomain* iSkin, 
                                           const CATOrientation iOrientation, 
                                           CATDynEdgeFilletRibbon * iFilletSpec,
                                           CATBlendVertexSpec *iSpecBV);

  // This function will add a limiting element in case of a deadlock 
  // configuration
  void AddLimitingElement( CATBody* iBody, CATDomain* iSkin, 
				                   const CATOrientation iOrientation, 
                           CATDynEdgeFilletRibbon * iFilletSpec,
                           CATDynEdgeFilletRibbon *iSpecDL);

  void CreateLimitingBodiesFrom(const CATLISTP(CATMathPoint) &iPoints, const CATLISTP(CATMathDirection) &iDirections, const CATListOfInt * iListOfInfo = NULL); //REN Wk 9 2016. For FastUpdate
  void CreateLimitingElementIfNeeded();

  void CreateCallBackForG1Tracks();

  //Start methods for VertexBlend relative setback
  HRESULT ConvertSetbacksFromRelativeToAbsolute(const CATLISTP(CATDynEdgeFilletRibbon) & iRibbonsList,
                                                const CATListOfDouble * iRelativeSetbacks,
                                                CATListOfDouble & ioAbsoluteSetbacks,
                                                CATLISTP(CATEdge) & ioEdgesList,
                                                CATListOfDouble & ioRatioList,
                                                CATListOfInt & ioDirectionList,
                                                CATMathPoint * iCommonVtxMathPoint = NULL);  
  //End methods for VertexBlend relative setback

  CATBoolean HasLimitingBody() { return _LimitingBodies.Size() > 0 ? 1 : 0; }
  CATBoolean HasSmartCrossingLimitingBody(); 

  void SetCrossPartingLinker(CATFilletCrossPartingLinker* iLinker=NULL);

  void SetRibbonsReorderTracker(CATRibbonsReorderTracker* iTracker); 

  void GetSplittingElements (int iSupport, CATLISTP(CATGeometry)&oElementsList, CATListOfInt& oSides);

  static const CATString * GetDefaultOperatorId() { return & _OperatorId; };

  void SetVertexBlendList (CATLISTP(CATDynFilletBlendVertex) &iVertexBlendList);

  void SetVertexRibbonOrderList( CATLISTP(CATDynFilletVertexRibbonOrder) &iVertexRibbonOrderList );
  CATBoolean HasVertexRibbonOrder();

  CATDynBlendVertexDiag *CreateVertexBlendDiag(int iVertexBlendIndex);

  CATBoolean HasVertexBlending();

  void SetContinuityLevel(const int iContinuityLevel, const CATPositiveLength iTolerance=0.);

  void SetFlatEnding();

  void SetRadiusLawMode(const int iRadiusLawMode);
  void SetSpineTools(CATVariableFilletSpineTools * iSpineTools); //cwm 21nov05

  void SetFilletExportManagerCreate(CATFilletExportManagerCreate  iFilletExportManagerCreate);

  void SetFilletVariousParameters(const CATFilletVariousParameters* iFilletParams);

  CATBoolean IsMultiRibbonSafeModeActive();
  void SetMultiRibbonSafeMode (CATBoolean iMultiRibbonSafeMode);

  void SetCreateZeroSetbackDiabolo( CATBoolean iZeroSetbackDiabolo );

  void SetFilletIntersectionMode ();
  
  void SetFilletLongPropagation ();

  void SetKeepFeature( CATBoolean iKeepFeature );

  void SetVariableJointEnabled( CATBoolean iVariableJoint );

  void SetSmoothCornerPreferred( CATBoolean iSmoothCorner );

  // Activate support curvature control to filter ribbons crossing support skin 
  void SetSupportCurvatureCheck();

  // Activate new tritangent fillet algorithm (for autofillet)
  void SetDoubleCircleTritangentFilletMode();

  void UseKeepEdgeSameConvexityModeForImplicitKeepEdges(CATBoolean iUseKeepEdgeSameConvexityMode);

  virtual void AddDeclarativeManifoldAgents(CATCellManifoldsManager& iCellManifoldsManager,
    ListPOfCATBody &iListOfInputBodies, 
    ListPOfCATBody &iListOfNoCopyInputBodies, 
    CATBody * iOutputBody, 
    CATCGMJournalList* iTopOpJournal);

  // IZE wk. 01 2010 IR 021460 Some checks are too restrictive for SheetMetal configurations
  void SetUnplugChecksForSheetMetal(CATBoolean iUnplugChecksForSheetMetal);

  virtual CATBoolean IsVoBSupported();

  static int GetBSFStreamLevel();

  CATBody * GetFilletResult();

protected:
  virtual CATShell * GetInputShell(CATBody &iBody);

 private:

  void SetFaceFaceOptions (CATDynFaceFaceFilletRibbon *R, CATBlendParams *params);
  void SetFaceFaceOptions (CATDynRemoveFaceFilletRibbon *R, CATBlendParams *params);
  
  int RunOnOneSideOfParting(const CATOrientation iPartingOrientation);
  int RunOnBothSidesOfParting(CATBody* iPartingBody, CATDomain* iPartingShell);

  void ModifyJournalForFastRunFilletWithLimElements();//REN Wk 14 2016 For Fillet fastrun with planar limiting elements
  // JQS - functions to create an appropriate shape of pt/dir limiting element for edge fillet 
  int LocateEdge( ListPOfCATEdge& iEdges, CATMathPoint& iPosition, double &oDistance ); //JQS determine index of edge in list that is closest to given point
  CATBody * CreateShapeForPtDirLimitingElement( CATPlane * LPln );
  //-----------------------------------------------------------------------  
  // Dynamic Customization
  //-----------------------------------------------------------------------  
 private :
  int GetCreateShapeForPlanarLimitingVariable();

  //Topological healing on result body
  CATBoolean HealFilletResult(const CATLISTP(CATBody) &iInputBodies, CATCGMJournalList *ioPrivateJournal);

  //Generic (G1) healing on result body
  CATBoolean GenericHealFilletResult(CATCGMJournalList *ioJournal);

  void ComputeCrossPartingOrientation();

  CATCompositeLaw* SmoothDistanceLaw(CATCompositeLaw * iLaw); // SZK  04:01:21

  void AddLimitingsForBV(CATBody *iResultBody); //JMA 04/03/2009

  CATEdgeRibbon *GetEdgeRibbonFromSpecsOld (CATBody * iResul, CATEdge *iEdge, CATLISTP(CATDynFilletRibbon) *iEdgeFilletsNotToLookAt, CATDynEdgeFilletRibbon *&oFoundSpec,
    CATListPV &oRadiusAlloues);

  CATEdgeRibbon *GetEdgeRibbonFromSpecs (CATBody * iResul, CATEdge *iEdge, CATLISTP(CATDynFilletRibbon) *iEdgeFilletsNotToLookAt, CATDynEdgeFilletRibbon *&oFoundSpec,
      CATListPV &oRadiusAlloues);

  // Two new functions to deal with deadlock configuration
  void AddLimitingsForDeadlock( CATBody *iResultBody, CATLISTP(CATDynFilletRibbon) &iDeadLockRibs );
  CATBoolean DetectDeadlock( CATBody *iResultBody, CATLISTP(CATDynFilletRibbon) &oDeadLockRibs );
	  
  void SetRunWithDeadlock();
  CATBoolean RunWithDeadlock();

  //JMA for SW 02/06/2009
  int  GetCornerFilletVersion ();
  void AddBlendsOnVertices (CATBody *iInput, CATBody *&iBody, CATGeoFactory* iFactory,
                            CATSoftwareConfiguration* iConfig,
                            CATCGMJournalList       * iJournal,
                            CATFilletReconfigFillFunction iFillFunction,
                            int iSmode);
  void CleanLimitingsForBV();
  void CleanBlendVertex(CATBlendVertex*ibv = NULL);
  void UpdateBV (CATGeoFactory* iFactory,
                 CATSoftwareConfiguration* iConfig,
                 CATCGMJournalList       * iJournal,
                 CATSmartBodyDuplicator  * iDuplicator);

  void ReorderInitEdgeForStopOnCorner(CATBody& iBody, ListPOfCATEdge& ioEdges);

  void ModifyErrorMessageForVertexBlend(CATError * &iError, CATListOfInt & iBEIndex); //REN Wk 17 2017
  void FindMappingBetweenRibbonsAndSortedEdgesOfBlendVertices(int iNbEFillets, CATListOfInt & ioBEIndex); //REN Wk 19 2017

  //---------------------------------------------------------------------------
  // Data
  //---------------------------------------------------------------------------
 private:
  CATFilletCrossPartingLinker*  _CrossPartingLinker;
  CATRibbonsReorderTracker*     _RibbonsReorderTracker;
  int                           _ContinuityLevel;
  int							              _RadiusLawMode;
  CATFilletVariousParameters *  _FilletVariousParams;
  CATVariableFilletSpineTools  *_SpineTools; //cwm 21nov05
  double                        _Tolerance;

  // Information about cutting cells generated on the supports 
  // GetSplittingElements
  //----------------------------------------------------------
  ListPOfCATCell                _SplitCell;
  CATListOfInt                  _SideKeep;
  CATListOfInt                  _NuSupportForSplitCell;

  CATParting*                  _MultiParting;
  CATMultiRibbonFillet*        _MRF;
  CATBoolean                   _MultiRibbonSafeMode;
  CATBoolean                   _ZeroSetbackDiabolo;
  CATBoolean                   _FilletIntersectionMode;
  CATBoolean                   _FilletLongPropagation;
  CATBoolean                   _FlatEnding;
  CATBoolean                   _KeepFeature;
  CATBoolean                   _VariableJointEnabled;
  CATBoolean                   _SmoothCornerPreferred;
  CATBoolean                   _SupportCurvatureCheck;
  CATBoolean                   _DoubleCircleTritangentFilletMode;
  CATBoolean                   _AutomaticKeepEdgeMode;
  CATBoolean                   _UseKeepEdgeSameConvexityModeForImplicitKeepEdges;

  // Authorized members only
  //----------------------------------------
 protected:
  CATLISTP(CATDynFilletRibbon)      _FaceFaceFillets;
  CATLISTP(CATDynFilletRibbon)      _EdgeFillets;
  CATLISTP(CATDynFilletRibbon)      _RemoveFaceFillets;
  CATLISTP(CATBody)                 _LimitingBodies;
  CATLISTP(CATDomain)               _LimitingDomains;
  CATListOfInt                      _LimitingOrientations;
  CATListOfInt                      _LimitingSmartCrossParting;
  CATLISTP(CATDynFilletBlendVertex) _VertexBlendList;
  CATLISTP(CATDynFilletVertexRibbonOrder) _VertexRibbonOrderList;
  CATListOfInt _LimitingFromPtDir;

  private :
   CATListPV                        _LimitingInfo;
   CATLISTP(CATBody)                _LimitingBodiesForSpec;
   CATLISTP(CATDomain)              _LimitingDomainsForSpec;
   CATListOfInt                     _LimitingOrientationsForSpec;
   //CATLISTP(CATEdge)                _UpdatedEdges;
   ListPOfCATCell                   _UpdatedEdges;
   CATListOfDouble                  _UpdatedSetback;   

 private :
   CATBoolean                    _CreateG1Tracks;
   CATTopoOpeCallBacks *         _TopoCallBackForGeom;

 private:
  CATLISTP(CATDynFilletRibbon)   _OldFaceFaceFillets;
  CATLISTP(CATDynFilletRibbon)   _OldEdgeFillets;
  CATLISTP(CATDynFilletRibbon)   _OldRemoveFaceFillets;
  CATLISTP(CATDynFilletRadius)   _NewFilletRadius;

 private:
  CATLISTP(CATDynFilletRibbon)   _NewEdgeFilletsForDeadlock;
  CATBoolean                     _RunWithDeadlock;

 private:
  CATBoolean _UnplugChecksForSheetMetal;
  CATCGMJournalList * _LocalJournal;

  //-----------------------------------------------------------------------
  //- CGMReplay Implementation
  //-----------------------------------------------------------------------  
  static CATString _OperatorId;
  const CATString * GetOperatorId() const;

 public:
  void Dump( CATCGMOutput& os ) ;
  void RequireDefinitionOfInputAndOutputObjects();
  void WriteInput(CATCGMStream  & ioStream);
  void InsideEdgesRemover();
  static CATCGMOperator* UnStream(CATCGMStream &Str,const short LevelOfRuntime, const short VersionOfStream);
  CATBoolean ValidateTopOutput(CATTopCheckJournal* iEquivalent,CATCGMOutput& os);


 private :
  CATBoolean UpdateInputBodyWithParting (CATBody* InputBody, CATBody* iCreationBody, CATCGMJournalList * iJournal, CATBoolean FirstRun=TRUE);
  void GetAllInitialShells (CATBody* InputBody, CATLISTP(CATShell) &InitialShells,int& oSegmentation);
  void UpdateInputs (CATCGMJournalList& iPrivateEdgesJournal, CATBody* InputBody, CATBody* iCreationBody, CATCGMJournalList * iJournal = 0 );
  void RestaureInputData ();
  static void DisplayAndAddManageDeletion(CATExtCGMReplay* iCGMReplay, const int iRibbonNumber, CATDynFilletRibbon* iRibbon, const CATLISTP(CATDynFilletRadius)& iLocalRadii, const CATLISTP(CATEdge)* iEdges);

  CATBoolean _LimitingCreatedFromConstructionDetails;
  CATLISTP(CATMathPoint) _PtsForLimitingBodies;
  CATLISTP(CATMathDirection) _DirsForLimitingBodies;
  CATListOfInt _ListOfUniqueInfo;
  //-----------------------------------------------------------------------
  // Help Point option
  //-----------------------------------------------------------------------  
  private :
   CATBoolean	   _helpPointIsActivated;
   CATMathPoint  _helpPoint;

  public :
    void SetHelpPoint(const CATMathPoint &iHelpPoint);

  //-----------------------------------------------------------------------
  // Fast Update
  //-----------------------------------------------------------------------  
   public :
   CATContextForFastRun*           GetContextForFastRun();
   CATDynFilletContextForFastRun*  GetDynFilletContextForFastRun();
   CATContextForFastRun*           GetOrCreateContextForFastRun();
   CATDynFilletContextForFastRun*  GetOrCreateDynFilletContextForFastRun();
   CATBody*                        GetInputBody();
   int GetNbOfLimitingBody() { return _LimitingBodies.Size(); }
   CATBody * GetLimitingBody(int index) { return (index > 0 && index <= _LimitingBodies.Size()) ? _LimitingBodies[index] : NULL;}
   int                             FastRun(); // Mis ici en attendant que le booléen ne fasse plus appel au code generique. 
   int                             GetFaceFaceFilletsForFastRunSc3(CATCGMHashTable  * iFacesNotTreatedByFastRun, CATLISTP(CATDynFilletRibbon) & oFaceFaceFillets );
   int                             GetEdgeFilletsForFastRunSc3(CATCGMHashTable  * iEdgesNotTreatedByFastRun, CATLISTP(CATDynFilletRibbon) & oEdgeFillets );
   int                             GetRemoveFaceFilletsForFastRunSc3(CATCGMHashTable  * iFacesNotTreatedByFastRun, CATLISTP(CATDynFilletRibbon) & oRemoveFaceFillets );
   int                             PartialRun(CATBody * ipFastRunResultBody, CATCGMJournalList * ipFastRunJournal);
   int                             GetNbFaceFaceFillets();
   int                             GetNbEdgeFillets();
   int                             GetNbRemoveFaceFillets();
   CATBoolean                      ContainsVariableEdgeFillets();
   CATBoolean                      FindCorrespondingInput(CATLISTP(CATFace) &iFacesList);
   int                             FindArgumentsForFastRun(CATConnexComponentManager *  iEdgesConnexComponentsOI,
                                                           CATDrawerCollector *& oRelation_FilletRibbon_ConnexeComponents,
                                                           CATDrawerCollector *& oRelation_ConnexeComponent_FilletRibbons
                                                           );
   void GetSortedRibbonListForPartialRun(CATCGMHashTable * iRibbonsHTForPartialRun, CATLISTP(CATDynFilletRibbon) & ioRibbonsListForPartialRun);


   /*
   Update operator for Chain : change the input body y a new one
   The CATDynFilletRibbons have to be traated separatly
   */
  void UpdateWithNewBody (CATBody* iOldBody, CATBody* iNewBody);
  void GetCATDynRibbons (CATLISTP(CATDynFilletRibbon) &        ListOfRibbons);

};


#endif
