#ifndef CATHLRExactSceneComputer_H
#define CATHLRExactSceneComputer_H 

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2010
//
// CATHLRExactSceneComputer
//
// DESCRIPTION :
//
//    Implementation du CATAdvancedHLRExact avec traitement des clash en amont
//
//
//=============================================================================
#include "HLREngine.h"        // ExportedBy
#include "CATErrorDef.h"

#include "CATBoolean.h"
#include "CATSysBoolean.h"
#include "CATIAV5Level.h"

class CATHLRContainerEntity;
class CATHLRResultBrowser;
class CATHLREntity;

class CATTolerance;
class CATSoftwareConfiguration;
class CATMathTransformation;
class CATBaseUnknown;
class CATBody;
class CATEdge;
class CATFace;
class CATPolyBody;
class CATPolyEdge;
class CATSetOfInt;
class CATCrvParam;
class CATMathPoint;
class CATMathVector;
class CATMathDirection;
class CATMapOfPtrToPtr;

#ifdef CATIAR212
//typedef void (*HLRSilhouetteBuilderCB) (const void * iContext, int iEntityId, void * iHLREdge, CATFace * iFaceSupportSilh, CATMathSetOfPoints& iPoints);
typedef void (*HLRClashSilhComputerCB) (const void * iContext);
#endif

// -----------------------------------------------------------------------------
class ExportedByHLREngine CATHLRExactSceneComputer
{

public:

  // =============================================================================
  // REQUIRED CREATOR FOR ALL CLIENTS
  // iConfig is MANDATORY, returns NULL if iconfig==NULL
  static CATHLRExactSceneComputer * CreateExactSceneComputer(CATSoftwareConfiguration * iConfig, const CATTolerance &iSceneTol);


  virtual ~CATHLRExactSceneComputer();


  // ===================================================
  // SCENE Management

  // Ajout d'une entite V5(instance CATBody positionne) dans la scene.
  virtual void AddBody(CATBody * iBody, CATMathTransformation * iTransformation, int iClientID, int iPriorityGroup = 0) = 0;

  // Ajout d'une entite V4(instance model V4 positionne) dans la scene.
  virtual void AddV4Model(CATBaseUnknown * iV4Model, CATMathTransformation * iTransformation, int iClientID, int iPriorityGroup = 0) = 0;

  // Ajout d'une entite polyedrique dans la scene.
  virtual void AddPolyBody(CATPolyBody * iPolyBody, CATMathTransformation * iTransformation, int iClientID, int iPriorityGroup = 0, CATMapOfPtrToPtr * ipMapOfPolyCellToCell=NULL) = 0;

  // Possibility to change the Priority of Group for an entity which is already recorded
  // returns E_FAIL if the EntityID doesn't match with any entity
  virtual HRESULT UpdateEntityGroupPriority(int iHLREntityID, int iNewGroupPriority) = 0;


  // Specification des entites actives dans la scene
  // Par defaut, toutes sont actives (etat initial) 
  // sauf celles dont on demande explicitement la desactivation dans la liste iEntitiesIDToDisable
  // Cette liste des entites a desactiver doit etre exhaustive : toute entite prealablement desactivee mais non presente dans cette liste
  // sera reactivée a l'appel de cette methode.
  // Corollaire : Pour réactiver toutes les entites, rappeler cette methode avec une liste vide !
  virtual void UpdateSceneForHLRComputation(CATSetOfInt * iEntitiesIDToDisable=NULL) = 0;

  // Idem pour activer/desactiver une entite sans toucher aux autres
  virtual HRESULT UpdateEntityActivationStatus(int iHLREntityID, CATBoolean iEntityActivation) = 0;

  virtual void SetClientSceneTolerance(const CATTolerance &iClientTol) = 0;


  // ===================================================
  // VIEW Management

  virtual void SetViewPoint(const CATMathPoint &iPt) = 0;

  virtual void SetTargetPoint(const CATMathPoint &iPt) = 0;

  virtual void SetViewDirection(const CATMathDirection &iDir) = 0;

  virtual void SetAutoHideInfoStatus(CATBoolean iAutoHideInfoRequired) = 0;

  virtual void SetAdvancedOcclusionInfoStatus(CATBoolean iAdvancedOcclusionInfoRequired) = 0;


  // ===================================================
  virtual HRESULT Compute() = 0;

  

  // ===================================================
  
  // S_OK if conical, else S_FALSE
  virtual HRESULT GetViewPoint(CATMathPoint &oViewPt) = 0;

  // S_OK if defined by caller of CATSilhouetteComputer, else S_FALSE
  virtual HRESULT GetClientTargetPoint(CATMathPoint &oTargetPt) = 0;

  // S_OK if cylindrical, else S_FALSE
  virtual HRESULT GetViewDirection(CATMathDirection &oViewDir) = 0;

  virtual CATBoolean GetAutoHideInfoStatus() = 0;

  virtual CATBoolean GetAdvancedOcclusionInfoStatus() = 0;

  virtual const CATSoftwareConfiguration * GetSoftwareConfiguration() = 0;

  virtual const CATTolerance * GetClientTolerance() = 0;

  // ===================================================


  virtual CATHLRResultBrowser * GiveUpHLRResultBrowser() = 0;

  // This method does not set _ResultBrowser to NULL (the previous one does it)
  // We SHOULD NOT have to get the result browser to modify it from an upper level
  // However, we could need some infos to be displayed in the HLRViewer (debug session), and these infos can only be transfered via
  // the result browser
  virtual CATHLRResultBrowser * GetHLRResultBrowser() = 0;

  virtual CATHLRContainerEntity * GetEntities() = 0;

  virtual CATHLREntity * GetHLREntity(int iHLREntityID) = 0;

  virtual HRESULT GetHLRViewParameters(CATMathPoint &oObserver, CATMathPoint &oTarget,
                                       CATMathVector &oUpVector, CATMathVector &oRightVector) = 0;


#ifdef CATIAR212

  // Code specifique au Clash Management
  // -----------------------------------

  virtual CATPolyBody * GetSilhouettePolyBodyLyingOnEntity(int iEntityID, CATMathTransformation *&oTransfo) = 0;
  virtual CATPolyBody * GetMissingEdgesPolyBodyLyingOn(int iEntityID, CATMathTransformation *&oTransfo) = 0;

  virtual HRESULT AppendClashPointOnEdge(int iEdgeEntityId, CATEdge * iEdge, CATCrvParam &iClashParam, 
                                         int iFaceEntityId, void * iClientDataFace) = 0;
  virtual HRESULT AppendClashPointOnEdge(int iEdgeEntityId, void * iDataEdge, CATMathPoint &iClashPoint, 
                                         int iFaceEntityId,  void * iClientDataFace) = 0;
  virtual HRESULT AppendClashPointOnPolyWireEdge(int iEdgeEntityId, CATPolyEdge * iPolySilhEdge, CATMathPoint &iClashPoint, 
                                                 int iFaceEntityId, CATFace * iFace) = 0;


  /** External function used in case of polyhedral MotorV4 
  * to retrieve polyedral data associated to exact CGM data, both 
  * 1. to avoid deprecated polyedral convertion by tessellation
  * 2. to allow transparency options, and GP attributes by filiation
  */
  //virtual void SetHLRSilhouetteBuilderCBFunction(HLRSilhouetteBuilderCB iHLRSilhouetteBuilderFunction) = 0;

  virtual void SetHLRClashSilhComputerCBFunction(HLRClashSilhComputerCB iHLRClashSilhComputerFunction) = 0;

  virtual void SetMacroContext(const void * iContext) = 0;

  virtual void SetClashComputationMode(int iModeToSet) = 0;
  virtual int GetClashComputationMode() = 0;

#endif
    
  virtual void SetOcclusionConfig(CATBoolean iOcclusionConfig) = 0;
  virtual CATBoolean GetOcclusionConfig() = 0;

  // no doc
  virtual void DeactivateDRW_HLRemoveBackSuperimposedEdges() = 0;


protected:

  CATHLRExactSceneComputer();


};

#endif // CATHLRExactSceneComputer_H

