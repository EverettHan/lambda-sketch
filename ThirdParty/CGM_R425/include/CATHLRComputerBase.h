/* -*-C++-*-*/
#ifndef CATHLRComputerBase_H
#define CATHLRComputerBase_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRComputerBase
//
// DESCRIPTION :
/**
 * Main object that computes the HLR.
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Nov. 2001 LAT  Creation
//=============================================================================

// For Windows NT
#include "HLRModele.h"
#include "CATHLREdge.h" // definition of CATHLREdgeIdType

// Other includes
#include "CATHLRBodyId.h"
#include "CATBody.h"
#include "CATHLRConstant.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATCGMVirtual.h"
#include "CATDataType.h" // define CATINTPTR

#include "CATCGMScaleCategoryDef.h" // enum CATCGMScaleCategory

class CATBaseUnknown;
class CATPolyBody;
class CATHLRBuilderEntityBase;
class CATHLRContainerEntity; 
class CATHLRInternalMotor; 
class CATHLRPartOfEdge;
class CATHLRResultBrowserBase;
class CATHLRTransformation;
class CATMathDirection;
class CATSoftwareConfiguration;
class CATTolerance;

// tcx 13 03 2008
class HLR_CATechExt;
class CATechExt;

typedef int (*HLRTransparencyFunction) 
(CATINTPTR iEdgeId, CATHLREdge::CATHLREdgeIdType iEdgeType, int iSubEdgeOutlineType,
 void * iEntity, CATHLRBodyId iBodyId, void * iEntityContextData);


typedef void (*HLRReplaceCGMByPolyData) 
(CATBaseUnknown * iCGMBody, CATHLRBodyId iBodyId, const void * iCGMContext,
 void * &oPolyEntity, int &oIsPolyBodyElseBaseUnknown, int &oInheritanceMode, const void * &oPolyContext);

typedef enum
{
    Standard = 0,                  // Hiding and hidden
    AlwaysVisible,               // Hiding and not hidden
    Transparent,                 // Hidden and not hiding
    TransparentAndAlwaysVisible  // Not hinding and not hidden
}
CATHLRComputerFlag;

class ExportedByHLRModele CATHLRComputerBase: public CATCGMVirtual
{
public:

  enum CATHLRInputEntityType { BaseUnknownEntityType, PersistentPolyBodyType, TempPolyBodyType, PolyBodyIdType };


//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Default constructor
 */
  CATHLRComputerBase(CATSoftwareConfiguration * iConfig = 0, CATCGMScaleCategory iSceneScaleCategory = ScaleNotSet);

/**
 * Destructor
 */
  virtual ~CATHLRComputerBase();

//=============================================================================
// ADDING-REMOVING AN OBJECT
//=============================================================================
/** Adds a new object ( kind of CATBaseUnknown ) in the list of object to draw. Returns the identifier of
 * the body.
 */
  // xlu : internal management
  virtual CATHLRBodyId AddBody(void * iBodyToCompute,
                               const CATMathTransformation *iMatrixPosition = NULL,
                               const CATHLRComputerFlag iHidingFlag = Standard);
  
/** Adding an object ( kind of CATBaseUnknown ) with an associated matrix.
 */
  virtual CATHLRBodyId AddBody(void * iBodyToCompute, 
                               const CATMathTransformation & iMatrixPosition,
                               const CATHLRComputerFlag iHidingFlag = Standard);

 /** Adding a CATPolyBody with an associated matrix and a ContextData (not mandatory)
  * iInheritanceMode makes ComputerBase master of PolyBody Life Management
  */
  CATHLRBodyId AddPolyBodyInContext(CATPolyBody * iPolyBodyToCompute,
                                    const CATMathTransformation * iMatrixPosition,
                                    const int iInheritanceMode = 0,
                                    const void * iPolyContextData = NULL);


/** Resets the list of bodies on which the HLR will be computed.
 */
  virtual void Reset();

/** Gets the number of bodies.
 */
  CATLONG32 GetCountBodies() const;

/** Gets the contextual Scale Category of the input Scene.
 */
  inline CATCGMScaleCategory GetSceneScaleCategory();

/** Gets the body from its number.
 * <BR> @iIdxBody starts at 0 and is lower or equal to GetCountBodies()-1 .
 * <BR> If the identity of the body is required, provide a pointer on it as a second
 * argument.
 */
  virtual void * GetBodyAsVoid(CATLONG32 iIdxBody, CATHLRBodyId * oIdentity = 0L) const;

/** Gets the body from its number, if its type is CATBaseUnknown
 * <BR> @iIdxBody starts at 0 and is lower or equal to GetCountBodies()-1 .
 * <BR> If the identity of the body is required, provide a pointer on it as a second
 * argument.
 */
  CATBaseUnknown * GetBodyAsBaseUnknown(CATLONG32 iIdxBody, CATHLRBodyId * oIdentity) const;

/** Gets the body from its number, if its type is CATPolyBody
 * <BR> @iIdxBody starts at 0 and is lower or equal to GetCountBodies()-1 .
 * <BR> If the identity of the body is required, provide a pointer on it as a second
 * argument.
 */
  CATPolyBody * GetBodyAsPolyBody(CATLONG32 iIdxBody, CATHLRBodyId * oIdentity) const;


  /** to make restitution of ContextData associated to an input entity (Rep, Body, PolyBody ...)
  * <BR> @iBodyId is the CATHLRBodyId returned by methods AddBodyInContext(), AddPolyBodyInContext()
  */
  const void * GetBodyContextData(CATHLRBodyId &iBodyId);


  /** to prevent HLRComputerBase from wrongly casting a deleted object (PolyBody *, CATBaseUnknown *)
  * <BR> @iBodyId is the CATHLRBodyId returned by methods AddBodyInContext(), AddPolyBodyInContext()
  */
  void SetEntityDeletionStatus(CATHLRBodyId &iBodyId);

  /** to get the logical occlusion of an entity (PolyBody *, CATBaseUnknown *)
  * <BR> @iBodyId is the CATHLRBodyId returned by methods AddBodyInContext(), AddPolyBodyInContext() ...
  */
  int IsEntityOccluded(CATHLRBodyId iEntityId);

//=============================================================================
// SET AND GET METHODS
//=============================================================================
/** Sets the SoftwareConfiguration for versionning
 */
  virtual void SetCGMSoftwareConfiguration(CATSoftwareConfiguration * iConfig);

/** Sets the view parameters : the orserver is the position of the eyes of the one
 * that looks at the scene, the target defines the plane of projection, as being
 * orthogonal to the line that passes by the observer and the target. The third
 * parameter sets the Type of projection ( Conical of Cylindrical).
 */
  virtual void SetViewParameters(const CATMathPoint             & iObserver,
                                 const CATMathPoint             & iTarget, 
                                 CATHLRConstant::TypeProjection   iTypeProjection);

  inline void GetViewParameters(CATMathPoint                    & oObserver,
                                CATMathPoint                    & oTarget, 
                                CATHLRConstant::TypeProjection  & oTypeOfView);

/** Sets the views parameters assuming the type of view is cylindrical
 */
  virtual void SetViewParameters(const CATMathDirection & iSight);

/** Sets the up vector
 */
  virtual void SetUpVector(const CATMathVector & iUpVector);

/** Defines the Clipping Window in the plane of projection, for the computation of the HLR.
 */
  virtual void SetClippingWindow(double iClippingWindow[4]);


//=============================================================================
// COMPUTATION MANAGEMENT
//-----------------------------------------------------------------------------
/** Selects the mode for the computation.
 */
  void SetDCubedMode();
  void SetExactMode();
  void SetPolyhedricMode();
  void SetHRVMode();
  void SetTiledHRVMode();

/**
 * @nodoc
 * Internal use : specialized setting for HRV mode
 */
  virtual void SetMaxTileDichotomyLevel(int iMaxDichotomyLevel);

/** Specific method if no real computation is asked (the result is all the edges
 * of the model set to visible). Note that this is only valable for the next
 * computation
 */
  void SetToNoRealComputation();

/** Sets/unsets the mode to Visu ( the computer is a bit faster)
 * <BR> Default mode is non visu mode.
 */
  void SetVisuMode();
  void UnsetVisuMode();

/** Sets/unsets the mode to concatenate bars in the CATVisHLRRender (Rep Only)
 * <BR> Default mode is non VisBarConcatenation.
 */
  void SetVisBarConcatenation();
  inline int GetVisBarConcatenationMode();

/** Sets/unsets the halo to Visu (breaks visible segments befor esegments intersections)
 * <BR> Default mode is non halo mode.
 */
  void SetHaloMode(int iMode);

/** Defines the sag for the computation of the HLR.
 * THE BEST TO DO IS TO NOT USE THIS METHOD ANYMORE, BUT, IF YOU USE IT , PLEASE ...
 * Keep in mind that this Sag is dimensionless which is consistent with the 3DAccurracy in Tools/Options/Visualization/Performances
 * That means the unity depends on the scale (1 mm in case of NS, 100 mm for LS etc...)
 * Then, 0.2 value means 0.2mm in NS, 20mm in LS, 2m in ELS etc...
 */
  void SetSag(double iClientDimensionlessSAG);


/** Sets/unsets the output of the hidden lines.
 * <BR> Default mode computes the hidden lines.
 */
  void SetOutputHiddenLines();
  void UnsetOutputHiddenLines();


/** DEPRECATED : Do not Use
 * Provide external functions to:
 *  compute the occlusion of elements in the scene
 *  give occluded elements to be discarded from HLR input scene
 */
  void SetOcclusionFunction(void (*iComputeOcclusion )(void * iContext,
                                                       CATHLRContainerEntity *iScene,
                                                       const CATMathPoint&  iObserver, 
                                                       const CATMathPoint&  iTarget,
                                                       const CATMathVector& iUpVector,
                                                       const CATMathVector& iRightVector, 
                                                       int) ,
                            int  (*iIsElementOccluded)(void * iContext,
                                                       int iTag_Element, 
                                                       int iTag_Entity,
                                                       const CATHLRTransformation * iPositionOfEntity),
                            void * iContext=0);


/** External function used to:
 * disable visibility of some SubEdges (smooth edge application filter for example)
 * In case of polyhedral HLR Computer with PolyBodies, this function allows to
 * visualize as hidden the first edge which is occluded by another one that 
 * application would like to disable (smooth edge which is not an outline for example)
 * iSubEdgeOutlineType : 
 * 0 if not outline, 1 if outline but 2 if the outline is occluded by its own adjacent face
 */
  void SetTransparencyFunction(HLRTransparencyFunction iSetTransparencyOfSubEdge);

  HLRTransparencyFunction GetTransparencyFunction();


  // pointeur sur fonction statique de type HLRTransparencyFunction
  // On rend transparente toute edge silhouette occludee par sa propre face
  // iSubEdgeOutlineType : 
  // 0 if not outline, 1 if outline but 2 if the outline is occluded by its own adjacent face
  static int SetTransparencyIfOccludedByFace(CATINTPTR iEdgeId, CATHLREdge::CATHLREdgeIdType iEdgeType, int iSubEdgeOutlineType,
                                             void * iEntity, CATHLRBodyId iBodyId, void * iEntityContextData);



  /** External function used in case of polyhedral MotorV4 
  * to retrieve polyedral data associated to exact CGM data, both 
  * 1. to avoid deprecated polyedral convertion by tessellation
  * 2. to allow transparency options, and GP attributes by filiation
  */
  void SetReplaceCGMByPolyDataFunction(HLRReplaceCGMByPolyData iReplaceCGMByPolyDataFunction);


//=============================================================================
// DOING THE COMPUTATION AND GETTING THE RESULT
//=============================================================================
/** Do the computation
 */
  virtual void Compute();

/** Gets the result as a list of parts of edges
 */
  CATHLRResultBrowserBase * GetResultBase() const;

/** Free the result after having read it
 */
  void ReleaseResult();

/** Create a new result (and stores it in the internal motor)
 */
  virtual void ResetResult();

/** Creates the entities
 */
  virtual void CreateEntities();

/** Getting the container of the entities
 */
  CATHLRContainerEntity * GetEntities() const;

//=============================================================================
// For dynamic Debug
//=============================================================================
  static void (* _CreateDebugWindow)(CATHLRComputerBase * iComputer);
  

  // tcx 13 03 2008
  // Phoenix integration (smart extended extension)
  void SetPhoenixExtension(CATechExt *iExtension, CATBoolean iDeleteCATHLRComputer = FALSE );

  CATechExt * HasPhoenixExtension( CATBoolean iForceCreation = FALSE );

  // no doc
  void DeactivateDRW_HLRemoveBackSuperimposedEdges();

  // Enable/Disable the advanced occlusion computation (default is disabled)
  void SetAdvancedOcclusionComputationMode(CATBoolean iEnableAdvancedOcclusion);

  // Gets the advanced occlusion computation mode
  inline CATBoolean GetAdvancedOcclusionComputationMode();

//=============================================================================
// INTERNAL DATA
//=============================================================================
protected:

  enum ComputationMode { ExactMode, PolyhedricMode, DCubedMode, HRVMode, TiledHRVMode };


 /** Adding an object with an associated matrix, and a ClientContext,
  * to make restitution of more information during CallBacks (for Rep only)
  */
  CATHLRBodyId AddBodyInContext(void * iBodyToCompute, 
                                const CATMathTransformation * iMatrixPosition, 
                                const void * iRepContextData,
                                CATHLRInputEntityType iBodyType=BaseUnknownEntityType,
                                const CATHLRComputerFlag iHidingFlag = Standard);

    
  // Creation of a new entity from a Body and its context, 
  // to make restitution of more information during CallBacks (Rep only today)
  // default implementation : Create a new entity wihtout Context Data
  // clever implementation in derivated classes
  virtual void CreateNewEntityInContext(void * iBody, 
                                        CATHLRBodyId iBodyIdentity,
		                                    const CATHLRTransformation * iTransformation, 
                                        const void * iEntityContextData,
                                        CATHLRInputEntityType iBodyType,
                                        int iAlwaysVisible);

  CATBaseUnknown * SafeCastBodyToCATBaseUnknown(void * iBody, CATHLRInputEntityType iBodyType);
  CATPolyBody * SafeCastBodyToCATPolyBody(void * iBody, CATHLRInputEntityType iBodyType);

  // Allows CATHLRComputer to check configs (versionning)
  int CheckConfig(int iFlag);

    
  //=============================================================================
  // public structure
  //=============================================================================
  struct CATHLREntityInputData 
  {
    CATHLREntityInputData();
    ~CATHLREntityInputData();
    void                     * _InputEntity;
    CATHLRBodyId               _BodyId;
    CATHLRTransformation     * _Transfo;
    const void               * _ContextData;  // to make restitution of more information during CallBacks
    CATHLRInputEntityType      _InputType;
    int                        _OccludedFlag;
    int                        _AlwaysVisibleFlag;
  };

  // Tableau des entites d'entree avec leur type, transfo et autre ContextData
  CATHLREntityInputData     * _InputEntitiesArray;
  int                         _InputArraySize; // taille d'utilisation du tableau
  int                         _CountObjects;   // nombre d'entites non filtrees, passees au HLR

  CATCGMScaleCategory         _SceneScaleCategory;

  CATMathPoint                _Observer;
  CATMathPoint                _Target;
  CATMathVector               _UpVector;
  CATHLRConstant::TypeProjection _TypeOfView;

  // Mode for the computation
  ComputationMode             _ModeForComputation; 

  // Object that do the effective computation
  CATHLRInternalMotor       * _Motor;

  // Chained list of results (parts of edges)
  CATHLRPartOfEdge          * _FirstResult;

  // Browser of the results
  CATHLRResultBrowserBase   * _Results;

  // All is kept is an array of jele


  // Current Id used.
  CATHLRBodyId                _CurrentId;

  // Id at which the computation starts.
  CATHLRBodyId                _StartId;

  // Container for the entities
  CATHLRContainerEntity     * _ContainerEntity;

  // Flag to see if the list of entities is up to date
  CATLONG32                   _Modified;

  // Flag to see if the computation if real
  CATLONG32                   _IsComputationReal;

  // Flag to see if the computation is in visu mode
  int                         _InVisuMode;

  // Flag to concatenate bars in the CATVisHLRRender (Rep Only)
  int                         _VisBarConcatenation;

  // Flag to see if the output contains the hidden lines
  int                         _OutputHiddenLines;

  // Sag for the computation of the HLR.
  double                      _ClientDimensionlessSAG;
  double                      _HLRComputationSAG;

  // Resolution for the computation of the HLR.
  double                      _Resolution;

  // Clipping Window
  double                      _ClippingWindow[4];

  // External functions used to:
  // compute the occlusion of elements in the scene
  // give occluded elements to be discarded from HLR input scene
  void (*_ComputeOcclusion )(void * iContext,
                             CATHLRContainerEntity * iScene,
                             const CATMathPoint&  iObserver, 
                             const CATMathPoint&  iTarget,
                             const CATMathVector& iUpVector,
                             const CATMathVector& iRightVector, 
                             int iPerspective);
  int  (*_IsElementOccluded)(void * iContext,
                             int iTag_Element, 
                             int iTag_Entity,
                             const CATHLRTransformation * iPositionOfEntity);
  void * _ContextForOcclusion;


  // External function used to:
  // disable visibility of some SubEdges (smooth edge application filter for example)
  // In case of polyhedral HLR Computer with PolyBodies, this function allows to
  // visualize as hidden the first edge which is occluded by another one that 
  // application would like to disable (smooth edge which is not an outline for example)
  HLRTransparencyFunction    _SetTransparencyOfSubEdge;

  // External function used in case of polyhedral MotorV4 
  // to retrieve polyedral data associated to exact CGM data, both 
  // 1. to avoid deprecated polyedral convertion by tessellation
  // 2. to allow transparency options, and GP attributes by filiation
  HLRReplaceCGMByPolyData    _ReplaceCGMDataByPolyData;


  // SoftwareConfiguration for versionning
  CATSoftwareConfiguration * _SoftwareConfiguration;

//------------------------------------------------------------
// Release all the entities
//------------------------------------------------------------
//  void ReleaseEntities();
  CATHLRBuilderEntityBase       * _EntityBuilder;
  
  virtual void NewEntity( void * iBody, CATHLRBodyId iBodyIdentity,
		                      const CATHLRTransformation * iTransformation) = 0;


  virtual void CreateAllEntityBuilders()=0;

  virtual double GetBestTolerance(const CATTolerance  * &oSceneHLRTol);

// Memory data
private:
  int               _Allocated;

  void Reallocate(int iSize);
  void DeleteTransformations();
  // virtual void CreateEntityBuilder() = 0;
  virtual void CreateInternalMotor(const CATTolerance & iTol) = 0;

  
protected:
// Flag to see if the computation is in visu mode
  int               _HaloMode;

  // no doc
  CATBoolean        _DisableDRW_HLRemoveBackSuperimposedEdges;

  // Possibilité d'activer/désactiver le calcul des informations complémentaires pour les arêtes occludées
  CATBoolean        _AdvancedOcclusionMode;

  // xlu
  virtual void CompleteResult();

  // tcx 13 03 2008
  // For Phoenix Tools : a Phoenix pattern
  CATechExt *   _PhoenixHLR;
  // tcx 13 03 2008
  friend class HLR_CATechExt;
  //ky1 16 07 2014
  int _DoJournaling;
 

private:

  // pointeur sur fonction statique de type HLRTransparencyFunction
  // On rend transparente toute edge non silhouette ou toute edge silhouette occludee par sa propre face
  // iSubEdgeOutlineType : 
  // 0 if not outline, 1 if outline but 2 if the outline is occluded by its own adjacent face
  static int SetTransparencyIfNotOutline(CATINTPTR iEdgeId, CATHLREdge::CATHLREdgeIdType iEdgeType, int iSubEdgeOutlineType,
                                         void * iEntity, CATHLRBodyId iBodyId, void * iEntityContextData);


  // pointeur sur fonction statique de type HLRReplaceCGMByPolyData
  static void TessellateCGMBodyAsPolyBody(CATBaseUnknown * iCGMBody, CATHLRBodyId iBodyId, const void * iCGMContext,
    void * &oPolyEntity, int &oIsPolyBodyElseBaseUnknown, int &oInheritanceMode, const void * &oPolyContext);

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================
inline void CATHLRComputerBase::GetViewParameters(CATMathPoint                    & oObserver,
                                                  CATMathPoint                    & oTarget, 
                                                  CATHLRConstant::TypeProjection  & oTypeOfView) {                                          
  oObserver = _Observer; oTarget = _Target; oTypeOfView = _TypeOfView; }

inline int CATHLRComputerBase::GetVisBarConcatenationMode() {
  return _VisBarConcatenation; }

inline CATCGMScaleCategory CATHLRComputerBase::GetSceneScaleCategory() {
  return _SceneScaleCategory; }

inline CATBoolean CATHLRComputerBase::GetAdvancedOcclusionComputationMode() {
  return _AdvancedOcclusionMode; }

#endif
