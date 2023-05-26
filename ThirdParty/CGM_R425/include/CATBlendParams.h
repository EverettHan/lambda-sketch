#ifndef CATBlendParams_h
#define CATBlendParams_h

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "Fillet.h"
#include "CATCreateEndingShell.h"
#include "CATCreateShellForPunch.h"

#include "CATFilletReconfigFillFunction.h"
#include "CATFilletExportManager.h"
#include "CATDynFilletRibbon.h"
#include "ListPOfCATDynFilletBlendVertex.h"
#include "CATListOfKeepEdges.h"
#include "ListPOfCATEdge.h"
#include "CATLISTP_CATMathVector.h"
#include "ListPOfCATBody.h"
#include "CATMathPoint.h"
#include "CATBlendParamsDef.h"
#include "CATMathInline.h"

#include "CATTopoOpeCallBacks.h"

class CATBlendVertex;

#include "CATSafe.h"
CATSafeDefine(CATBlendParams);

class ExportedByFillet CATBlendParams
{
public:
  //------------------------------------------------------------------------------
  // Constructors
  //------------------------------------------------------------------------------
  CATBlendParams();

  CATBlendParams(CATBlendParams & iToCopy);

  CATBlendParams & operator = (const CATBlendParams & iParams);

  CATBlendParams(int                  iSegmentationMode1,     // 1 Trim, 2 No Trim, 3 WithTraceOnSupport
                 int                  iSegmentationMode2,     // 1 Trim, 2 No Trim, 3 WithTraceOnSupport   
                 int                  iStartRelimMode,        // 1 Max, 2 Min
                 int                  iStartMaxOption,        // 1 None, 2 Pline, 3 Spline
                 int                  iEndRelimMode,          // 1 Max, 2 Min
                 int                  iEndMaxOption,          // 1 None, 2 Pline, 3 Spline
                 int                  iNotchRelimMode,        // 1 Max, 2 Min
                 int                  iSewingOption,          // 0 Default, 1 Reverse
                 int                  iEdgeReporting,         // 0 Default, 1 InternalEdgeReporting
                 int                  iPropagAutoMode,        // 0 Default, 1 StopOnFillet
                 int                  iKeepEdgeMode,          // 0 Default, 1 Implicit
                 int                  iKeepEdgeConvexityMode, // 0 Default, 1 Every convexity
                 CATCreateEndingShell iCreateEndingShellFct,
                 void*                iDataForEndingShellFct=NULL); 

  INLINE int                           GetSewingOption                () const { return _SewingOption             ; } ;
  INLINE int                           GetEdgeReporting               () const { return _EdgeReporting            ; } ;
  INLINE int                           GetPropagAutoMode              () const { return _PropagAutoMode           ; } ;
  INLINE int                           GetKeepEdgeMode                () const { return _KeepEdgeMode             ; } ;
  INLINE int                           GetKeepEdgeConvexityMode       () const { return _KeepEdgeConvexityMode    ; } ;
  INLINE CATCreateEndingShell          GetCreateEndingShellFunction   () const { return _CreateEndingShellFct     ; } ;
  INLINE void*                         GetDataForEndingShell          () const { return _DataForEndingShellFct    ; } ;
  INLINE CATFilletReconfigFillFunction GetReconfigFillFunction        () const { return _ReconfigFillFct          ; } ;
  INLINE CATFilletExportManagerCreate  GetFilletExportManagerCreate   () const { return _FilletExportManagerCreate; } ;
  INLINE CATBoolean                    GetInnerTwistFill              () const { return _InnerTwistFill           ; } ;
  INLINE CATBoolean                    GetNoSimplif                   () const { return _NoSimplif                ; } ;
  INLINE CATListOfKeepEdges&           GetKeepEdges                   ()       { return _KeepEdges                ; } ;
  INLINE int                           GetToolType                    () const { return _ToolType                 ; } ;
  INLINE CATFilletRadiusType           GetFilletRadiusType            () const { return _RadiusType               ; } ;
  INLINE int                           GetFaceFaceFilletInitMode      () const { return _FaceFaceInitMode         ; } ;
  INLINE CATCreateShellForPunch        GetCreateShellForPunchFunction () const { return _CreateShellForPunchFct   ; } ;
  INLINE void*                         GetDataForShellForPunch        () const { return _DataForShellForPunchFct  ; } ;
  INLINE CATBoolean                    GetCreateZeroSetbackDiabolo    () const { return _ZeroSetbackDiabolo       ; } ;

  INLINE CATTopoOpeCallBacks* GetGeomCallBackFunction        () const { return _TopoCallBackForGeom          ; } ;


  INLINE void SetSewingOption             ( const int                     iSewingOption                  ) { _SewingOption              = iSewingOption                  ; } ;
  INLINE void SetEdgeReporting            ( const int                     iEdgeReporting                 ) { _EdgeReporting             = iEdgeReporting                 ; } ;
  INLINE void SetPropagAutoMode           ( const int                     iPropagAutoMode                ) { _PropagAutoMode            = iPropagAutoMode                ; } ;
  INLINE void SetKeepEdgeMode             ( const int                     iKeepEdgeMode                  ) { _KeepEdgeMode              = iKeepEdgeMode                  ; } ;
  INLINE void SetKeepEdgeConvexityMode    ( const int                     iKeepEdgeConvexityMode         ) { _KeepEdgeConvexityMode     = iKeepEdgeConvexityMode         ; } ;
  INLINE void SetCreateEndingShellFunction( CATCreateEndingShell          iCreateEndingShellFunction     ) { _CreateEndingShellFct      = iCreateEndingShellFunction     ; } ;
  INLINE void SetDataForEndingShell       ( void*                         iDataForEndingShell            ) { _DataForEndingShellFct     = iDataForEndingShell            ; } ;
  INLINE void SetReconfigFillFunction     ( CATFilletReconfigFillFunction iReconfigFillFunction          ) { _ReconfigFillFct      = iReconfigFillFunction      ; } ;
  INLINE void SetFilletExportManagerCreate( CATFilletExportManagerCreate  iFilletExportManagerCreate     ) { _FilletExportManagerCreate = iFilletExportManagerCreate     ; } ;
  INLINE void SetInnerTwistFill           ( const CATBoolean              iInnerTwistFill                ) { _InnerTwistFill            = iInnerTwistFill                ; } ;
  INLINE void SetNoSimplif                (                                                              ) { _NoSimplif                 = TRUE                           ; } ;
  INLINE void SetToolType                 ( const int                     iToolType                      ) { _ToolType                  = iToolType                      ; } ;
  INLINE void SetFilletRadiusType         ( const CATFilletRadiusType     iRadiusType                    ) { _RadiusType                = iRadiusType                    ; } ;
  INLINE void SetCreateShellForPunchFunction( CATCreateShellForPunch      iCreateShellForPunchFct        ) { _CreateShellForPunchFct    = iCreateShellForPunchFct        ; } ;
  INLINE void SetDataForShellForPunch       ( void*                       iDataForShellForPunch          ) { _DataForShellForPunchFct   = iDataForShellForPunch          ; } ;

  INLINE void SetGeomCallBackFunction     ( CATTopoOpeCallBacks* iGeomCallBackFunction          ) { _TopoCallBackForGeom      = iGeomCallBackFunction      ; } ;

  int    GetRelimitationMode         (int iExtremity) const;
  void   SetRelimitationMode         (const int iRelimitationMode, int iExtremity);
  int    GetMaxOption                (int iExtremity) const;
  void   SetMaxOption                (const int iMaxOption, int iExtremity);
  int    GetMinOption                (int iExtremity) const;
  void   SetMinOption                (const int iMinOption, int iExtremity);

  int    GetNotchRelimitMode         () const;
  INLINE void   SetNotchRelimitMode(int iRelimitationMode) { _NotchRelimMode = iRelimitationMode; };
  int    GetSegmentationMode         (int iSupport=0) const;
  void   SetSegmentationMode         (const int iSegmentationMode, int iSupport=0);
  void   SetFaceFaceFilletInitMode ( const CATDynFilletFaceFaceInitMode     iMode);

  ListPOfCATEdge & GetEdgesForMax    (int &oMaxOption);
  void   SetEdgesForMax              ( ListPOfCATEdge& iEdges, int iMaxOption);

  void   SetFacesForMinRelimitation  ( ListPOfCATFace& iFaces );
  ListPOfCATFace & GetFacesForMin    ();


  void SetBlendVertex(CATLISTP(CATDynFilletBlendVertex) &iList);
  INLINE CATBlendVertex * GetBlendVertex(int iNum) { return (CATBlendVertex*)_BlendVertices[iNum]; };
  INLINE int GetBlendVertexNumber() { return _BlendVertices.Size(); };

  // renvoie vrai si le fillet de vertex est actif
  INLINE CATBoolean GetVertexBlending() { return _BlendVertices.Size() != 0; };
  CATBoolean IsNewSWCornerFillet ();
  INLINE void SetCornerFilletVersion (int iCornerFilletVersion) { _NewCornerFilletVersion = iCornerFilletVersion; };

  // temporaire fillet de vertex
  void SetVertexBlending(CATBoolean iOn);
  CATBoolean GetVertexBlendingSetback();
  void SetVertexBlendingSetback(CATBoolean iOn);
  void SetVertexBlendingFromEnv();
  // fin temporaire fillet de vertex

  void SetCreateZeroSetbackDiabolo( CATBoolean iOn );
  // ContinuityMode
  void SetContinuityMode(int iContinuityMode);
  int GetContinuityMode();

  // Flat Ending
  INLINE void SetFlatEnding(const CATBoolean iFlatEnding = TRUE) { _FlatEnding = iFlatEnding; };
  INLINE CATBoolean GetFlatEnding() const { return _FlatEnding; };

  // Keep Feature
  void SetKeepFeature( const CATBoolean iKeepFeature = FALSE );
  CATBoolean GetKeepFeature() const;
  void SetLoopsToAvoidInKeepFeature( const CATListPtrCATDomain &iLoops );
  CATListPtrCATDomain GetLoopsToAvoidInKeepFeature() const;

  // variable joint 
  void SetVariableJointEnabled( const CATBoolean iVariableJoint = FALSE );
  CATBoolean GetVariableJointEnabled() const;

  void SetBestInInSelectionPoint(const CATMathPoint &iBestInInSelectionPoint);
  CATBoolean GetBestInInSelectionPoint(CATMathPoint &oBestInInSelectionPoint);

  // Fillet Section Type
  void    SetFilletSectionType(int iSectionType, double iConicParameter=0.5); 
  INLINE int GetFilletSectionType() const { return _FilletSectionType; };
  double  GetConicParameter() const;

  // Support curvature check
  void SetSupportCurvatureCheck(CATBoolean iOn = TRUE);
  INLINE CATBoolean GetSupportCurvatureCheck() { return _SupportCurvatureCheck; };

  // Double circle tritangent fillet (for autofillet)
  void SetDoubleCircleTritangentFilletMode(CATBoolean iOn = TRUE);
  CATBoolean GetDoubleCircleTritangentFilletMode();

  INLINE void SetAutomaticKeepEdgeMode(CATBoolean iOn = TRUE) {_AutomaticKeepEdgeMode = iOn;};
  INLINE CATBoolean GetAutomaticKeepEdgeMode() const {return _AutomaticKeepEdgeMode;};

  INLINE void UseKeepEdgeSameConvexityModeForImplicitKeepEdges(CATBoolean iUseKeepEdgeSameConvexityMode = TRUE);
  INLINE CATBoolean HasKeepEdgeSameConvexityModeForImplicitKeepEdgesToBeUse() const;

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  virtual ~CATBlendParams();

/* Needed in the future for fillet with init/exit
  void SetFilletStartPoint(int iFilletSupport, CATBody *iStartPoint, CATMathVector *iFilletDirection);
  void GetFilletStartPoint(int iFilletSupport, CATBody *&oStartPoint, CATMathVector *&oFilletDirection);
  void SetFilletEndPoint(int iFilletSupport, CATBody *iEndPoint);
  void GetFilletEndPoint(int iFilletSupport, CATBody *&oEndPoint);
  */

  void SetRelimitationDisabled(CATBoolean iRelimitationDisabled);
  INLINE CATBoolean IsRelimitationDisabled() { return _RelimitationDisabled; };
  void SetSuperMaxOptionEnabled(CATBoolean iSuperMaxOptionEnabled);
  INLINE CATBoolean IsSuperMaxOptionEnabled() { return _SuperMaxOption; };
  void AddSupportJournalInfo(CATBoolean iAddSupportJournalInfo);
  CATBoolean ShouldAddSupportJournalInfo();

  //Fillet Intersection Mode
  void SetFilletIntersectionMode();
  INLINE int  GetFilletIntersectionMode() { return _FilletIntersectionMode; };
  
  //Fillet Intersection Mode
  void SetFilletLongPropagation();
  INLINE int  GetFilletLongPropagation() { return _FilletLongPropagation; };

  // Corner mode
  void SetCornerMode(const int iCornerMode);
  INLINE int GetCornerMode() const { return _CornerMode; };

  // Smooth corner preferred
  void SetSmoothCornerPreferred( const CATBoolean iSmoothCornerPreferred = FALSE );
  CATBoolean GetSmoothCornerPreferred() const;

  //
  void DisableFatEdgesSimplification();
  int  FatEdgesSimplificationPredicate();

  void SetHelpPoint(const CATMathPoint &iHelpPoint); // Help Point option
	CATMathPoint GetHelpPoint() const; // Help Point option
  INLINE CATBoolean HelpPointIsActivated() const { return _helpPointIsActivated; } ; // Help Point option

  void SetStoppingFaces( const ListPOfCATFace &iListOfStopFaces );
  ListPOfCATFace GetStoppingFaces() const;
  INLINE CATBoolean HasStoppingFaces() const { return _ListOfStopFaces.Size() ? TRUE : FALSE; };

  void SetPreserveExtremitiesForSheetMetal();
  CATBoolean GetPreserveExtremitiesForSheetMetal();


  //------------------------------------------------------------------------------
  // Private Data
  //------------------------------------------------------------------------------
  private :
  int _SegmentationMode1;      // 1 Trim, 2 No Trim, 3 WithTraceOnSupport
  int _SegmentationMode2;      // 1 Trim, 2 No Trim, 3 WithTraceOnSupport

  int _StartRelimMode;         // 1 Max, 2 Min
  int _StartMaxOption;         // 1 None, 2 Pline, 3 Spline
  int _StartMinOption;         // 1 None, 2 Punch
  int _EndRelimMode;           // 1 Max, 2 Min
  int _EndMaxOption;           // 1 None, 2 Pline, 3 Spline
  int _EndMinOption;           // 1 None, 2 Punch

  int _NotchRelimMode;         // 1 Max, 2 Min
  
  int _SewingOption;           // 0 Default, 1 Reverse
  int _EdgeReporting;          // 0 Default, 1 InternalEdgeReporting
  int _PropagAutoMode;         // 0 Default, 1 StopOnFillet
  int _KeepEdgeMode;           // 0 Default, 1 Implicit
  int _KeepEdgeConvexityMode;  // 0 Default, 1 Allow every convexity
  int _FaceFaceInitMode;       // 0 Default, 1 Allow multi solution

  CATCreateEndingShell          _CreateEndingShellFct;
  void*                         _DataForEndingShellFct;

  CATCreateShellForPunch        _CreateShellForPunchFct;
  void*                         _DataForShellForPunchFct;
  
  CATFilletReconfigFillFunction _ReconfigFillFct;
  CATFilletExportManagerCreate  _FilletExportManagerCreate;
  CATBoolean                    _InnerTwistFill;
  CATBoolean                    _NoSimplif;
  CATListOfKeepEdges            _KeepEdges;    // liste des keep edges eventuelles
  int                           _ToolType;     // 0 Sphere (default), 1 circle
  CATFilletRadiusType           _RadiusType;   // (Radius, ChordLength, etc...)

  CATTopoOpeCallBacks*          _TopoCallBackForGeom;


  CATBoolean _VertexBlending;
  CATBoolean _VertexBlendingSetback;

  CATBoolean _ZeroSetbackDiabolo;

  CATLISTP(CATDynFilletBlendVertex) _BlendVertices;

  int _NewCornerFilletVersion;                 // 0 OldVersion, 1 New versionFor SW

  int                            _EdgesMaxOption;     // 1 None, 2 Pline, 3 Spline
  ListPOfCATEdge                 _EdgesForMax;
  ListPOfCATFace                 _FacesForMin;

  CATBoolean _RelimitationDisabled;
  CATBoolean _SuperMaxOption;

  int _ContinuityMode;           // CATBlendG0Continuity=0 (Valeur par defaut), CATBlendG1Continuity=1

  int _FilletIntersectionMode;   //0 : No, 1: Yes
  int _FilletLongPropagation;    //0 : No, 1: Yes
  int _CornerMode;
  CATBoolean _SmoothCornerPreferred; // Activate smooth corner for fillet multiribbon with minimal propagation  

  int _FatEdgesSimplificationPredicate; // 0: False (do not simplify fat edges), 1: True (simplify, default)

  CATBoolean _FlatEnding;        // Activate Flat Shape on Pointing Ends;
  CATBoolean _KeepFeature;       // Activate Keep Feature for fillet and chamfer  
  CATBoolean _VariableJointEnabled;
  CATBoolean    _UseBestInInSelectionPoint;
  CATMathPoint  _BestInInSelectionPoint;

  int     _FilletSectionType; //0: Circular, 1: Conical
  double  _ConicParameter;

  /* Needed in the future for fillet with init/exit
  CATLISTP(CATMathVector)         _PropagationDirection;
  ListPOfCATBody                  _StartPoint;
  ListPOfCATBody                  _EndPoint;
*/  
  CATBoolean _AddSupportJournalInfo;

  CATBoolean _SupportCurvatureCheck;
  CATBoolean _DoubleCircleTritangentFilletMode;
  CATBoolean _AutomaticKeepEdgeMode;

  CATBoolean   _helpPointIsActivated; // Help Point option
  CATMathPoint _helpPoint; // Help Point option

  ListPOfCATFace _ListOfStopFaces;
  CATListPtrCATDomain  _LoopsToAvoidInKeepFeature; // Inner loops not to be assessed for keep feature 

  CATBoolean _UseKeepEdgeSameConvexityModeForImplicitKeepEdges;
  CATBoolean _PreserveExtremitiesForSheetMetal;
};

INLINE void CATBlendParams::UseKeepEdgeSameConvexityModeForImplicitKeepEdges(CATBoolean iUseKeepEdgeSameConvexityMode)
{
  _UseKeepEdgeSameConvexityModeForImplicitKeepEdges = iUseKeepEdgeSameConvexityMode;
}
INLINE CATBoolean CATBlendParams::HasKeepEdgeSameConvexityModeForImplicitKeepEdgesToBeUse() const
{
  return _UseKeepEdgeSameConvexityModeForImplicitKeepEdges;
}



#endif
