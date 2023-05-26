/* -*-C++-*- */

#ifndef CATlsoTransformFaceContext_H
#define CATlsoTransformFaceContext_H
/*  
=============================================================================

RESPONSABLE  : L Marini

DESCRIPTION  : Donnees contextuelles pour l'operateur TransformFace

=============================================================================
*/

#include "AdvTrimOpe.h"
#include "CATlsoPersistentContext.h"
#include "CATMathTransformation.h"
#include "CATMathInline.h"
#include "ListPOfCATPersistentBodies.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATPersistentFaces.h"
#include "ListPOfListPOfCATCell.h"
#include "CATLISTP_CATMathTransformation.h"
#include "CATListOfShort.h"
#include "CATDataType.h"
#include "CATTopFacReplSurfDef.h"
#include "ListPOfCATPersistentCells.h"
#include "CATFaceHashTable.h"

class CATBody;
class CATPersistentExtTopOperator;
class CATPersistentBody;
class CATlsoTransformFaceInputDomain;
class CATGMLiveShapeRunOptions;
class CATCGMHashTableWithAssoc;
class CATlsoRevolPrismData;
class CATlsoTransformFaceInputCellList;

// Configuartion Type
#define TransformConfigurationType CATlsoTransformFaceContext::ConfigurationType

// Input Type
#define ConnectedInputType                      CATlsoTransformFaceContext::InputType
#define ConnectedInputTransformationType        CATlsoTransformFaceContext::TRANSFORMATION
#define ConnectedInputSkinResultType            CATlsoTransformFaceContext::SKINRESULT
#define ConnectedInputSurfaceType               CATlsoTransformFaceContext::SURFACE
#define ConnectedInputSurfaceWithTranfoType     CATlsoTransformFaceContext::SURFACEWITHTRANSFORMATION

// Separate surface mode
#define CATGMTFSeparateSurface CATlsoTransformFaceContext::SeparateSurfaceMode
#define CATGMTFSeparateSurfaceDeactivated CATlsoTransformFaceContext::SEPARATE_SURFACE_DEACTIVATED
#define CATGMTFSeparateSurfaceNeedToActivate CATlsoTransformFaceContext::SEPARATE_SURFACE_NEED_TO_ACTIVATE
#define CATGMTFSeparateSurfaceActivated CATlsoTransformFaceContext::SEPARATE_SURFACE_ACTIVATED

class ExportedByAdvTrimOpe CATlsoTransformFaceContext : public CATlsoPersistentContext
{

public:
  
  // surcharge de new
  CATCGMNewClassArrayDeclare;
  
  // constructeur a partir d'un CATBody initial, d'un CATTopOperator 
  CATlsoTransformFaceContext(CATBody                      & iBody,
                             CATPersistentExtTopOperator  * iLiveShapeExtTopOperator,
                             CATBoolean                     iReplaceBasicContext=TRUE);

  // constructeur a partir d'une factory initial, d'un CATTopOperator 
  CATlsoTransformFaceContext(CATGeoFactory                & iFactory,
                             CATPersistentExtTopOperator  & iLiveShapeExtTopOperator,
                             CATBoolean                     iReplaceBasicContext=TRUE);

  // destructeur 
  ~CATlsoTransformFaceContext();

  // Methodes de cast
  // ---------------------------
  CATlsoTransformFaceContext *      CastToTransformFaceContext();

  // ------------------
  // ConfigurationType
  // ------------------
  enum ConfigurationType { NOT_COMPUTED=-1,
                           UNKNOWN_CONFIGURATION=0,
                           DEPRESSION,
                           PROTRUSION,
                           FULL_DOMAIN,
                           SMOOTH_CONTACT,
                           SURFACIC_CVM,
                           DEPRESSION_OR_PROTRUSION,
                           DEPRESSION_UNREMOVABLE,
                           PROTRUSION_UNREMOVABLE,
                           PLAN_FOR_THICKNESS,
                           CYLINDER_FOR_THICKNESS,
                           SPHERE_FOR_THICKNESS,
                           MOVING_DRAW,
                           DEPRESSION_COMPLEMENTARY_REMOVABLE,
                           PROTRUSION_COMPLEMENTARY_REMOVABLE,
                           MIXED_DREPRESSION_PROTRUSION_REMOVABLE,
                           REVOLPRISM,
                           ALMOST_PROTRUSION_REMOVABLE,
                           REVOLPRISM_SYSTEM,
                           DEPRESSION_WITH_INNER_PROTRUSION,
                           PROTRUSION_WITH_INNER_DEPRESSION,
                           TOKEEPCELLS

  };

  // ------------------
  // InputType
  // ------------------
  enum InputType { UNKNOWN_INPUT=0,
                   SKINRESULT,
                   TRANSFORMATION,
                   SURFACE,
                   SURFACEWITHTRANSFORMATION };

  // ------------------
  // InputType
  // ------------------
  enum SeparateSurfaceMode {SEPARATE_SURFACE_DEACTIVATED = 1,
                            SEPARATE_SURFACE_NEED_TO_ACTIVATE,
                            SEPARATE_SURFACE_ACTIVATED };

  // ------------------------
  // Set Methodes from Input
  // ------------------------
  void SetMathTransformation(const CATMathTransformation &iTransformation);

  void SetRevolPrismData (CATlsoRevolPrismData &iRevolPrismData) ;

  // Duplicate Mode Methode
  void SetNbDuplicatedInstances(const CATLONG32 & iNbInstances, CATBoolean iDRepPattern);

  // Paste Mode Methodes
  void SetFixedBodyForPasteMode(CATBody * iFixedBody);
  void SetFixedPersistentBodyForPasteMode(CATPersistentBody * iFixedPersistentBody);
  void SetExplicitPasteType(CATLONG32 iExplicitPasteType);
  void SetIntersectionSolving(CATBoolean iIntersectionSolving);
  void SetPowerClosedMode(CATBoolean iPowerClosedMode);
  void SetPatternPowerClosedMode(CATBoolean iPatternPowerClosedMode);
  void SetTryToCloseWithPasteMode(CATBoolean iTryToClose);
  void SetCloningMode(CATBoolean iClone=TRUE);  // = Live Duplication
  void SetIsoTopologicalBuildOnly(CATBoolean iIsoTopoBuild);
  void SetInputForInstances(const CATLISTP(CATMathTransformation) & iInstanceTransformationList,
                            const CATListOfShort                  & iInstanceNumberList); // this list is parallel with iMathTransformationList);

  // For NonManifold
  INLINE void SetFromNonManifoldLump(const CATBoolean iFromNonManifoldLump);

  // Methode used to give a tolerance to the FlexiblePlus operator.
  INLINE void SetGapCreationTolerance(double iTol);

  // Use only for CATIA Switch Geometry + Call only FlexibleBrep operator.
  INLINE void SetFRSConfiguration(CATFacReplSurfConfigType iType);

  virtual void SetBestResultPersistentBody(CATPersistentBody * iPersistentBody,
                                           CATCGMJournalList * iJournal);

  // -------------------------------
  // Set Methodes from Computation
  // -------------------------------
  void SetPersistBodyWithoutFacesToModify(CATPersistentBody * iPersistBodyWithoutFacesToModify);
  void SetDatumisedPersistentBody(CATPersistentBody * iDatumisedPersistentBody);
  void SetInputWorkPersistentBody(CATPersistentBody * iInputWorkPersistentBody);
  void SetInputPersistentBodyWithRibbons(CATPersistentBody * iInputPersistentBodyWithRibbons);
  void SetRltDomainPersistentBodyForHybridResult(CATPersistentBody * iResultDomainPBodyForHybridResult);
  void SetSurfacicResultPersistentBodyForHybridInput(CATPersistentBody * iSurfacicResultPersistentBodyForHybridInput);
  INLINE void SetSimplifyFaceMode(CATBoolean iSimplifyFace);
  INLINE void SetRunOptions(CATGMLiveShapeRunOptions* iRunOptions);
  INLINE void SetTopologicalRebuildLevel(CATLONG32 iTopoRebuildLevel);
  INLINE void SetDRepPatternPrivateData(CATBoolean iDRepPatternPrivateData);
  INLINE void  SetForceToFALSEDRepPatternPrivateData(CATBoolean iForceToFALSEDRepPatternPrivateData);
  INLINE void SetPatternEdition(); // JJ3 pour edition de reference
  INLINE void SetNeedToRebuild(CATLONG32 iNeedToRebuild); // //VB7 surfacic Pattern
  void SetPBodyToExtrapolateForRefPattern(CATPersistentBody * iPBodyToExtrapolateForRefPattern);
  INLINE void SetNeedLaydownInitMode(CATBoolean iNeedLaydownInitMode);
  INLINE void SetTrustMatterSideMode(CATBoolean iTrustMatterSideMode);
  INLINE void SetToKeepPCellList(ListPOfCATPersistentCells & iToKeepPCellList);
  INLINE void SetSeparateSurfaceMode (CATGMTFSeparateSurface iSeparateSurfaceMode);

  // Set Methodes for SHM
  // ------------------------
  INLINE void SetAlwaysWallForSmoothContact(CATBoolean iBoolValue); 

  // ------------------------
  // Get Methodes from input
  // ------------------------
  CATBoolean                   GetDeltaShapeMode() const;
  INLINE CATBoolean            GetPasteModeOnly() const;
  INLINE CATBoolean            GetDuplicateModeOnly() const;
  INLINE CATBoolean            GetEditPatternMode() const;

  INLINE CATBoolean            GetPasteMode() const;
  INLINE CATBoolean            GetPowerClosedMode() const;
  INLINE CATBoolean            GetPatternPowerClosedMode() const;
  INLINE CATBody *             GetFixedBodyForPasteMode() const;
  INLINE CATPersistentBody *   GetDatumisedPersistentBody() const;
  INLINE CATPersistentBody *   GetFixedPersistentBodyForPasteMode() const;
  INLINE ConfigurationType     GetExplicitConfigurationTypeForPasteMode() const;
  INLINE CATBoolean            GetTryToCloseForPasteMode() const;
  INLINE CATBoolean            GetCloningMode() const;
  INLINE CATBoolean            GetIsoTopologicalBuildOnly() const;
  INLINE CATBoolean            GetDuplicateMode() const;
  INLINE CATBoolean            GetDRepPattern(CATBoolean iForceDRepPatternOnly = FALSE) const;
  INLINE CATBoolean            GetDRepPatternPrivateData() const;
  INLINE CATBoolean            GetForceToFALSEDRepPatternPrivateData() const;
  INLINE const CATMathTransformation & GetTransformation() const;
  INLINE CATLONG32             GetNbInstances() const;
  INLINE CATLONG32             GetNeedToRebuild() const; //VB7 surfacic Pattern
  INLINE CATBoolean            GetSimplifyFaceMode() const;
  INLINE CATBoolean            GetFromNonManifoldLump();
  INLINE CATGMLiveShapeRunOptions * GetRunOptions() const;
  INLINE CATLONG32             GetTopologicalRebuildLevel() const;
  short                        GetNumberPatternInstance(int iNumBrotherInstance) const;
  CATMathTransformation &      GetTransformationPatternInstance(int iNumBrotherInstance) const;
  INLINE double                    GetGapCreationTolerance() const;
  INLINE CATFacReplSurfConfigType  GetFRSConfiguration() const;
  INLINE CATBoolean            GetIntersectionSolving() const;
  CATlsoTransformFaceInputCellList * RetrieveRevolPrismData(CATCell * iCell, CATlsoRevolPrismData & oRevolPrismData) const;
  INLINE CATBoolean            GetNeedLaydownInitMode() const;
  INLINE CATBoolean            GetTrustMatterSideMode() const;
  INLINE void                  GetToKeepPCellList(ListPOfCATPersistentCells & oToKeepPCellList);
  INLINE CATGMTFSeparateSurface GetSeparateSurfaceMode () const;

// -------------
  // Get Methodes
  // -------------
  CATPersistentBody        * GetPersistBodyWithoutFacesToModify() const;
  INLINE CATPersistentBody * GetInputWorkPersistentBody() const;
  INLINE CATPersistentBody * GetInputPersistentBodyWithRibbons() const;
  INLINE CATPersistentBody * GetRltDomainPersistentBodyForHybridResult() const;
  INLINE CATPersistentBody * GetSurfacicResultPersistentBodyForHybridInput() const;
  INLINE CATBoolean          GetPatternEdition() const; // JJ3 pour edition de reference

  INLINE void       SetPatternDuplication(CATBoolean iPatternDuplication);
  INLINE CATBoolean GetPatternDuplication() const;
  INLINE void       SetHasToReplicate(CATBoolean iHasToReplicate);
  INLINE CATBoolean GetHasToReplicate() const;
  INLINE CATPersistentBody * GetPBodyToExtrapolateForRefPattern() const;
  INLINE CATBoolean GetAlwaysWallForSmoothContact() const;

  void GetAllSkinResultBodies(ListPOfCATBody & oBodyList);

  // -------------
  // Compute Methodes
  // -------------
  void CompleteListWithCellManifoldData(const ListPOfCATFace & iInputFaceList,
                                        ListPOfCATFace & oInputFaceListCompleted) const;

  virtual void CreateOneTranformFaceResultDomain(CATlsoTransformFaceInputDomain * iTFInputDomain,
                                                 CATLONG32 iNumInstance);

  virtual void CleanAllTransformFaceResultDomain();
  virtual void CleanAllTransformFaceConnectedInputCells ();
  virtual void CleanAllTransformFaceInputDomain ();

  // The ListOfMovingCellList is the list of connexe area with the same transformation.
  // The iDirectMovingCellListOnInput is the list of cell selected by user.
  void GetListOfMovingCellAreaOnInput(ListPOfListPOfCATCell & oListOfMovingCellListOnInput,
                                      ListPOfCATCell        & iDirectMovingCellListOnInput);

  void GetExtrapolatedPersistentBodies(CATLISTP(CATPersistentBody) & ioExtrapolatedPersistentBodies);

  CATBoolean HasRevolPrism();

  void GetPersistentBodiesNecessaryForNextRun(ListPOfCATPersistentBodies &oPersistentBodiesNecessaryForNextRun) const;

  CATCGMHashTableWithAssoc * GetHashTableInputPersistentFaceList(short iFilterKey=0);

  void GetInstanceTransformationList(CATLISTP(CATMathTransformation) & oInstanceTransfoList);

  void GetInstanceNumberList(CATListOfShort & oInstanceTrNumberList);

  //VB7 W41 2019 Local Build
  CATBoolean ThisRunIsLocal() const;
  CATBoolean IsActivatedLocalRun() const;
  void DeclareRunAsLocal(ListPOfCATPersistentFaces * iLocalInputPFaceList=NULL);
  void UnDeclareRunAsLocal();
  //CATPersistentBody * GetComplementaryPBodyForLocalBuild(CATBoolean iWithCrownOption=TRUE);
  CATBody * GetLocalComplementaryBodyForLocalBuild(CATMathBox & iModifiedMathBox);
  CATPersistentBody * GetLocalBuildPBody(CATPersistentBody * iRefPBody=NULL);
  //void GetAdditionalPFaceListForLocalBuild(ListPOfCATPersistentFaces & oAdditionalPFaceList);

  // ----------
  // Dump
  // ----------
  friend CATCGMOutput& operator << (CATCGMOutput& s, const CATlsoTransformFaceContext& iOpe);
  void Dump( CATCGMOutput& os ) const;

  // acces aux administrateurs d'objets algorithmiques
  INLINE CATlsoChainMaster * GetInputDomainAdmin() const;         // "TFIDom"  7
  INLINE CATlsoChainMaster * GetResultDomainAdmin() const;        // "TFRDom"  7
  INLINE CATlsoChainMaster * GetInputFacesListAdmin() const;      // "IFList"  6
  INLINE CATlsoChainMaster * GetInputEdgeListAdmin() const;       // "IEList"  6
  INLINE CATlsoChainMaster * GetInputVertexListAdmin() const;     // "IVList"  6
  INLINE CATlsoChainMaster * GetConnectedInputCellAdmin() const;  // "ICC"     3
  INLINE CATlsoChainMaster * GetInvariantSelectionAdmin() const;  // "InvSel"  6
 
private:

  // copy constructeur et operateur = (lancent une exception)
  CATlsoTransformFaceContext(CATlsoTransformFaceContext& iOrig);
  CATlsoTransformFaceContext& operator= (const CATlsoTransformFaceContext& iRight);

  // Chaines d'objets algorithmiques specifiques
  // 0  InputDomainAdmin;
  // 1  ResultDomainAdmin;
  
  // En cas d'ajout, merci de mettre a jour le nombre d'admins : _NbAdmin dans le constructeur

  // ------------------------------
  // Internal Data from Input
  // -------------------------------
  CATMathTransformation _Transformation;
  CATLONG32             _NbInstances;
  CATLONG32             _NeedToRebuild; //vb7 01/08/2011 surfacic pattern rebuild
  CATBoolean            _DuplicateMode;
  CATBoolean            _DRepPattern;
  CATBoolean            _DRepPatternPrivateData;
  CATBoolean            _ForceToFALSEDRepPatternPrivateData;
  CATBoolean            _PasteMode;
  CATBoolean            _PowerClosedMode;
  CATBoolean            _PatternPowerClosedMode;
  CATBody             * _FixedBodyForPasteMode;
  CATPersistentBody   * _FixedPersistentBodyForPasteMode;
  ConfigurationType     _ExplicitConfigurationTypeForPasteMode;
  CATBoolean            _CloningMode;
  CATBoolean            _TryToCloseForPasteMode;
  CATBoolean            _IsoTopologicalBuildOnly;
  CATLISTP(CATMathTransformation) _InstanceTransformationList;
  CATListOfShort                  _InstanceNumberList;
  CATBoolean            _FromNonManifoldLump;
  CATBoolean            _SimplifyFaceMode;
  CATGMLiveShapeRunOptions  * _RunOptions; // Pour gerer les check du flexible, uniquement dans le cas de CATIA Live Shape
  double                   _GapCreationTolerance;  // for FaceReplaceSurface
  CATFacReplSurfConfigType _FRSConfiguration;      // for FaceReplaceSurface
  CATPersistentBody   * _PBodyToExtrapolateForRefPattern;
  CATBoolean            _IntersectionSolving;
  //VB7 - W23 - 2015 - For CircularShape operator - False by default
  CATBoolean            _NeedLaydownInitMode;
  CATBoolean            _TrustMatterSideMode;
  //VB7 - W12 - 2018 - For Trim Operator
  ListPOfCATPersistentCells  _ToKeepPCellList;
  //PPU7 - W14 - 2022 - IR-891600: To avoid internal error if multiple CATSurface in CATlsoTransformFaceConnectedInputCells::CreateResultSkinPresistentBodyFromSurface
  CATGMTFSeparateSurface        _SeparateSurfaceMode;

  // -------------------------------
  // Internal Data from Computation
  // -------------------------------
  CATPersistentBody   * _PersistBodyWithoutFacesToModify;
  CATPersistentBody   * _InputWorkPersistentBody;
  CATPersistentBody   * _InputPersistentBodyWithRibbons;
  CATPersistentBody   * _DatumisedPersistentBody;
  CATPersistentBody   * _RltDomainPersistentBodyForHybridResult;
  CATPersistentBody   * _SurfacicResultPersistentBodyForHybridInput;
  CATLONG32             _TopoRebuildLevel;
  CATBoolean            _PatternEdition; // JJ3 pour edition de reference
  CATBoolean            _PatternDuplication;
  CATBoolean            _AlwaysWallForSmoothContact;

  CATBoolean            _HasToReplicate;
};

// Implementations INLINE

// Acces aux administrateurs d'objets algorithmiques specifiques
INLINE CATlsoChainMaster * CATlsoTransformFaceContext::GetInputDomainAdmin() const { 
  return _AdminTab[0];     }

INLINE CATlsoChainMaster * CATlsoTransformFaceContext::GetResultDomainAdmin() const { 
  return _AdminTab[1];     }

INLINE CATlsoChainMaster * CATlsoTransformFaceContext::GetInputFacesListAdmin() const { 
  return _AdminTab[2];     }

INLINE CATlsoChainMaster * CATlsoTransformFaceContext::GetInputEdgeListAdmin() const { 
  return _AdminTab[3];     }

INLINE CATlsoChainMaster * CATlsoTransformFaceContext::GetInputVertexListAdmin() const { 
  return _AdminTab[4];     }

INLINE CATlsoChainMaster * CATlsoTransformFaceContext::GetConnectedInputCellAdmin() const { 
  return _AdminTab[5];     }

INLINE CATlsoChainMaster * CATlsoTransformFaceContext::GetInvariantSelectionAdmin() const { 
  return _AdminTab[6];     }

// ------------------------------------------------------------------------
// SetDRepPatternPrivateData
// ------------------------------------------------------------------------
INLINE void CATlsoTransformFaceContext::SetDRepPatternPrivateData(CATBoolean iDRepPatternPrivateData) {
  _DRepPatternPrivateData = iDRepPatternPrivateData;}

// ------------------------------------------------------------------------
// SetForceToFALSEDRepPatternPrivateData
// ------------------------------------------------------------------------
INLINE void CATlsoTransformFaceContext::SetForceToFALSEDRepPatternPrivateData(CATBoolean iForceToFALSEDRepPatternPrivateData) {
 _ForceToFALSEDRepPatternPrivateData = iForceToFALSEDRepPatternPrivateData;}

// ------------------------------------------------------------------------
// GetPasteMode
// ------------------------------------------------------------------------
INLINE CATBoolean CATlsoTransformFaceContext::GetPasteMode() const {
  return _PasteMode; }

// ------------------------------------------------------------------------
// GetPowerClosedMode
// ------------------------------------------------------------------------
INLINE CATBoolean CATlsoTransformFaceContext::GetPowerClosedMode() const {
  return _PowerClosedMode; }

// ------------------------------------------------------------------------
// GetPatternPowerClosedMode
// ------------------------------------------------------------------------
INLINE CATBoolean CATlsoTransformFaceContext::GetPatternPowerClosedMode() const {
  return _PatternPowerClosedMode; }

// ------------------------------------------------------------------------
// GetFixedBodyForPasteMode
// ------------------------------------------------------------------------
INLINE CATBody * CATlsoTransformFaceContext::GetFixedBodyForPasteMode() const {
  return _FixedBodyForPasteMode; }

// ------------------------------------------------------------------------
// GetFixedPersistentBodyForPasteMode
// ------------------------------------------------------------------------
INLINE CATPersistentBody * CATlsoTransformFaceContext::GetFixedPersistentBodyForPasteMode() const {
  return _FixedPersistentBodyForPasteMode; }

// ------------------------------------------------------------------------
// GetExplicitConfigurationTypeForPasteMode
// ------------------------------------------------------------------------
INLINE TransformConfigurationType CATlsoTransformFaceContext::GetExplicitConfigurationTypeForPasteMode() const {
  return _ExplicitConfigurationTypeForPasteMode; }

// ------------------------------------------------------------------------
// GetTryToCloseForPasteMode
// ------------------------------------------------------------------------
INLINE CATBoolean CATlsoTransformFaceContext::GetTryToCloseForPasteMode() const {
  return _TryToCloseForPasteMode; }

// ------------------------------------------------------------------------
// GetCloningMode
// ------------------------------------------------------------------------
INLINE CATBoolean CATlsoTransformFaceContext::GetCloningMode() const {
  return _CloningMode; }

// ------------------------------------------------------------------------
// GetIsoTopologicalBuildOnly
// ------------------------------------------------------------------------
INLINE CATBoolean CATlsoTransformFaceContext::GetIsoTopologicalBuildOnly() const {
  return _IsoTopologicalBuildOnly; }

// ------------------------------------------------------------------------
// GetDuplicateMode
// ------------------------------------------------------------------------
INLINE CATBoolean CATlsoTransformFaceContext::GetDuplicateMode() const {
  return _DuplicateMode; }

// ------------------------------------------------------------------------
// GetDRepPattern
// ------------------------------------------------------------------------
INLINE CATBoolean CATlsoTransformFaceContext::GetDRepPattern(CATBoolean iForceDRepPatternOnly) const
{
  if (iForceDRepPatternOnly)
    return _DRepPattern;
  else
    return (_DRepPattern && _DRepPatternPrivateData);
}

// ------------------------------------------------------------------------
// GetDRepPatternPrivateData
// ------------------------------------------------------------------------
INLINE CATBoolean CATlsoTransformFaceContext::GetDRepPatternPrivateData() const {
  return _DRepPatternPrivateData; }

// ------------------------------------------------------------------------
// GetForceToFALSEDRepPatternPrivateData
// ------------------------------------------------------------------------
INLINE CATBoolean CATlsoTransformFaceContext::GetForceToFALSEDRepPatternPrivateData() const {
  return _ForceToFALSEDRepPatternPrivateData;}

// ------------------------------------------------------------------------
// GetTransformation
// ------------------------------------------------------------------------
INLINE const CATMathTransformation & CATlsoTransformFaceContext::GetTransformation() const {
  return _Transformation; }

// ------------------------------------------------------------------------
// GetNbInstances
// ------------------------------------------------------------------------
INLINE CATLONG32 CATlsoTransformFaceContext::GetNbInstances() const {
  return _NbInstances; }


// ------------------------------------------------------------------------
// GetNeedToRebuild
// ------------------------------------------------------------------------
INLINE CATLONG32 CATlsoTransformFaceContext::GetNeedToRebuild() const {
  return _NeedToRebuild; }

// ------------------------------------------------------------------------
// SetFromNonManifoldLump
// ------------------------------------------------------------------------
INLINE void CATlsoTransformFaceContext::SetFromNonManifoldLump(const CATBoolean iFromNonManifoldLump) {
  _FromNonManifoldLump = iFromNonManifoldLump; }

// ------------------------------------------------------------------------
// SetFromNonManifoldLump
// ------------------------------------------------------------------------
INLINE CATBoolean CATlsoTransformFaceContext::GetFromNonManifoldLump() {
 return _FromNonManifoldLump; }


// ------------------------------------------------------------------------
// Get and SetInputWorkPersistentBody
// ------------------------------------------------------------------------
INLINE CATPersistentBody * CATlsoTransformFaceContext::GetInputWorkPersistentBody() const {
  return _InputWorkPersistentBody; }

// ------------------------------------------------------------------------
// Get and SetInputPersistentBodyWithRibbons
// ------------------------------------------------------------------------
INLINE CATPersistentBody * CATlsoTransformFaceContext::GetInputPersistentBodyWithRibbons() const {
  return _InputPersistentBodyWithRibbons; }

// ------------------------------------------------------------------------
// Get and SetSurfacicResultPersistentBodyForVolumicCase
// ------------------------------------------------------------------------
INLINE CATPersistentBody * CATlsoTransformFaceContext::GetRltDomainPersistentBodyForHybridResult() const {
  return _RltDomainPersistentBodyForHybridResult; }

// ------------------------------------------------------------------------
// Get and SetSurfacicResultPersistentBodyForHybridInput
// ------------------------------------------------------------------------
INLINE CATPersistentBody * CATlsoTransformFaceContext::GetSurfacicResultPersistentBodyForHybridInput() const {
  return _SurfacicResultPersistentBodyForHybridInput; }

// ------------------------------------------------------------------------
// Get and SetSimplifyFaceMode
// ------------------------------------------------------------------------
INLINE CATBoolean CATlsoTransformFaceContext::GetSimplifyFaceMode() const {
  return _SimplifyFaceMode; }

INLINE void CATlsoTransformFaceContext::SetSimplifyFaceMode(CATBoolean iSimplifyFaceMode) {
  _SimplifyFaceMode = iSimplifyFaceMode; }

// ------------------------------------------------------------------------
// Get and SetRunOptions
// ------------------------------------------------------------------------
INLINE void CATlsoTransformFaceContext::SetRunOptions(CATGMLiveShapeRunOptions* iRunOptions) {
  _RunOptions = iRunOptions; }

INLINE CATGMLiveShapeRunOptions* CATlsoTransformFaceContext::GetRunOptions() const {
  return _RunOptions; }

// ------------------------------------------------------------------------
// Get and SetTopologicalRebuildLevel
//   0 : no result
//   1 : isotopological rebuild level (Flexible)
//   2 : non-isotopological rebuild level (classical V5: TrimSew, Thickness, Sew)
//   3 : non-isotopological rebuild level (XTrim)
// ------------------------------------------------------------------------
INLINE CATLONG32 CATlsoTransformFaceContext::GetTopologicalRebuildLevel() const {
  return _TopoRebuildLevel; }

INLINE void CATlsoTransformFaceContext::SetTopologicalRebuildLevel(CATLONG32 iTopoRebuildLevel) {
  _TopoRebuildLevel = iTopoRebuildLevel; }

// ------------------------------------------------------------------------
// Get and SetGapCreationTolerance
// ------------------------------------------------------------------------
INLINE double CATlsoTransformFaceContext::GetGapCreationTolerance() const {
return _GapCreationTolerance; }

INLINE void CATlsoTransformFaceContext::SetGapCreationTolerance(double iTol) {
  _GapCreationTolerance = iTol; }

// ------------------------------------------------------------------------
// Get and SetFRSConfiguration
// ------------------------------------------------------------------------
INLINE CATFacReplSurfConfigType CATlsoTransformFaceContext::GetFRSConfiguration() const {
  return _FRSConfiguration; }

INLINE void CATlsoTransformFaceContext::SetFRSConfiguration(CATFacReplSurfConfigType iType) {
  _FRSConfiguration = iType; }

// ------------------------------------------------------------------------
// Set and GetPatternEdition    - JJ3 pour edition de reference
// ------------------------------------------------------------------------
INLINE void CATlsoTransformFaceContext::SetPatternEdition() {
  _PatternEdition = TRUE; }

INLINE CATBoolean CATlsoTransformFaceContext::GetPatternEdition() const { 
  return _PatternEdition; }


INLINE void CATlsoTransformFaceContext::SetNeedToRebuild(CATLONG32 iNeedToRebuild) {
  _NeedToRebuild = iNeedToRebuild; }

INLINE CATBoolean CATlsoTransformFaceContext::GetPasteModeOnly() const {
  return (GetPasteMode() && !GetDuplicateMode()); }

INLINE CATBoolean CATlsoTransformFaceContext::GetDuplicateModeOnly() const {
  return (GetDuplicateMode() && !GetPasteMode()); }

INLINE CATBoolean CATlsoTransformFaceContext::GetEditPatternMode() const {
  return (GetPasteMode() && GetDuplicateMode()); }


INLINE void CATlsoTransformFaceContext::SetPatternDuplication(CATBoolean iPatternDuplication) {
  _PatternDuplication = iPatternDuplication; }

INLINE CATBoolean CATlsoTransformFaceContext::GetPatternDuplication() const {
  return _PatternDuplication; }

INLINE void CATlsoTransformFaceContext::SetHasToReplicate(CATBoolean iHasToReplicate) {
  _HasToReplicate = iHasToReplicate; }

INLINE CATBoolean CATlsoTransformFaceContext::GetHasToReplicate() const {
  return _HasToReplicate; }

INLINE CATPersistentBody * CATlsoTransformFaceContext::GetPBodyToExtrapolateForRefPattern() const {
  return _PBodyToExtrapolateForRefPattern;}

INLINE void CATlsoTransformFaceContext::SetAlwaysWallForSmoothContact(CATBoolean iBoolValue) {
  _AlwaysWallForSmoothContact = iBoolValue; }

INLINE CATBoolean CATlsoTransformFaceContext::GetAlwaysWallForSmoothContact() const {
  return _AlwaysWallForSmoothContact; }

INLINE CATPersistentBody * CATlsoTransformFaceContext::GetDatumisedPersistentBody() const {
  return _DatumisedPersistentBody; }

INLINE CATBoolean CATlsoTransformFaceContext::GetIntersectionSolving() const {
  return _IntersectionSolving; }

INLINE void CATlsoTransformFaceContext::SetNeedLaydownInitMode(CATBoolean iNeedLaydownInitMode) {
  _NeedLaydownInitMode = iNeedLaydownInitMode; }

INLINE void CATlsoTransformFaceContext::SetTrustMatterSideMode(CATBoolean iTrustMatterSideMode) {
  _TrustMatterSideMode = iTrustMatterSideMode; }

INLINE CATBoolean CATlsoTransformFaceContext::GetNeedLaydownInitMode() const {
  return _NeedLaydownInitMode; }

INLINE CATBoolean CATlsoTransformFaceContext::GetTrustMatterSideMode() const {
  return _TrustMatterSideMode; }

void CATlsoTransformFaceContext::SetToKeepPCellList(ListPOfCATPersistentCells & iToKeepPCellList)
{
  _ToKeepPCellList = iToKeepPCellList;
}

INLINE void CATlsoTransformFaceContext::SetSeparateSurfaceMode (CATGMTFSeparateSurface iSeparateSurfaceMode)
{
  _SeparateSurfaceMode = iSeparateSurfaceMode;
}

INLINE void CATlsoTransformFaceContext::GetToKeepPCellList(ListPOfCATPersistentCells & oToKeepPCellList)
{
  oToKeepPCellList = _ToKeepPCellList;
}

INLINE CATGMTFSeparateSurface CATlsoTransformFaceContext::GetSeparateSurfaceMode () const
{
  return _SeparateSurfaceMode;
}

#endif
