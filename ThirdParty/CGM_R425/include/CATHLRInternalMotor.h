/* -*-C++-*-*/
#ifndef CATHLRInternalMotor_H
#define CATHLRInternalMotor_H
#include "DSYExport.h"
//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1999
//
// CATHLRInternalMotor 
//
// DESCRIPTION :
/**
 * Generic motor for the computation of the HLR.
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : Yes
//=============================================================================
//
// History
//
// Feb. 1999 JCH Creation            
// Aug. 1999 HKL Added the virtual ReleaseScene method
// Mar. 2000 HKL Halo mode
// Oct. 2000 TPD Mise en place d'un bloc d'encombrement de la vue
//
//=============================================================================

//=============================================================================
// For Windows NT
//-----------------------------------------------------------------------------
#include "HLRModele.h"

//=============================================================================
// For inheritance and other includes
//-----------------------------------------------------------------------------
#include "CATHLRConstant.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATTolerance.h"


//=============================================================================
// Forward declarations
//-----------------------------------------------------------------------------
class CATHLRContainerEntity;
class CATHLRResultBrowserBase;
class CATMathTransformation;
class CATHLRTransformation;
class CATSoftwareConfiguration;

typedef int (*HLRIsOccludedFunction) 
(void * iContext, int iTag_Element, int iTag_Entity, const CATHLRTransformation * iPositionOfEntity);


//=============================================================================
// CLASS DEFINITION
//=============================================================================
class ExportedByHLRModele CATHLRInternalMotor
{
public:
//============================================================
// CONSTRUCTORS AND DESTRUCTOR
//------------------------------------------------------------
/**
 * Default constructor.
 */
  CATHLRInternalMotor(const CATTolerance & iTol = CATGetDefaultTolerance());

/**
 * Destructor.
 */
  virtual ~CATHLRInternalMotor();

//============================================================
// METHODS
//------------------------------------------------------------ 
/** Sets the SoftwareConfiguration for versionning
 */
  virtual void SetCGMSoftwareConfiguration(CATSoftwareConfiguration * iConfig);

/** If the internal motor knows which type of browser to create, it creates it.
 *  Otherwise return NULL (WARNING)
 */ 
  virtual CATHLRResultBrowserBase * CreateBrowser();


/** Updates the input CATTolerance
 */
  virtual void SetClientCATTolerance(const CATTolerance & iClientTol);


/** Defines the Clipping Window in the plane of projection, for the computation of the HLR.
 */
  inline void SetClippingWindow(double iClippingWindow[4]);

/** Defines other data on the motor.
 * Both iSagForLengthTest and iTolForLengthTest are in millimeter units
 */
  virtual void SetTolParameters(double iSagForLengthTest, double iTolForLengthTest);

/** Sets the parameters of the HLR.
 */
  void SetParameters(CATHLRContainerEntity * iScene,
		                 const CATMathPoint    & iObserver,
                     const CATMathPoint    & iTarget,
                     const CATMathVector   & iUpVector,
                     const CATMathVector   & iRightVector,
                     CATHLRConstant::TypeProjection iPerspective,
                     int                     iIsComputationReal);

/** Sets/unsets the mode (1 means visu mode, 0 means non visu mode)
 */
  inline void SetMode(int iInVisuMode);

/** Sets/unsets the output (1 means output of hidden lines, 0 means the opposite)
 */
  inline void SetOutputMode(int iWithHiddenLines);

/** Sets/unsets the halo mode (1 halo mode on, 0 off)
 */
  inline void SetHaloMode(int iMode);

/** Provide external functions to:
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

/** Starts the computation of the HLR. Returns 0 if OK.
 */ 
  virtual int StartComputation();


/** Reset the results
 */
  // void ResetResult();
  virtual void SetResult( CATHLRResultBrowserBase * iResultBrowser );


/** Removes the previous scene
 */
  virtual void ReleaseScene();


/** no doc
 */
  virtual void DeactivateDRW_HLRemoveBackSuperimposedEdges() {};

  // Possibilité d'activer/désactiver le calcul des informations complémentaires pour les arêtes occludées
  virtual void EnableAdvancedOcclusionComputation() {};
  virtual void DisableAdvancedOcclusionComputation() {};

//============================================================
// READING METHODS
//------------------------------------------------------------ 
/** Gets the container of the entities.
*/
  inline CATHLRContainerEntity * GetEntities() const;

/** Gets the projection type.
 */
  inline CATHLRConstant::TypeProjection GetProjectionType() const;

/** Gets the view transformation.
 */
  inline const CATMathTransformation * GetViewTransformation() const;

/** Gets the eyes position.
 */
  inline void GetObserverPosition(double * oPosition) const;

/** Gets the target position.
 */
  inline void GetTargetPosition(double * oPosition) const;

/** Gets the mode (1 means visu mode, 0 means non visu mode)
 */
  inline int  GetMode();

/** Gets the input SAG (in millimeter units)
 */
  inline double GetSag();

/** Gets the input tolerance
 */
  inline double GetTolerance();

/** Gets the input CATTolerance
 */
  const CATTolerance & GetClientCATTolerance();

/** Gets the Clipping Window in the plane of projection, for the computation of the HLR.
 */
  inline void GetClippingWindow(double * oClippingWindow) const;

  inline HLRIsOccludedFunction GetIsElementOccluded();
  inline void * GetContextForOcclusion();


//============================================================
// INTERNAL DATA
//------------------------------------------------------------
protected:
  CATMathPoint                      _Observer, _Target;
  CATMathVector                     _UpVector, _RightVector;
  CATHLRConstant::TypeProjection    _TypeProjection;
  CATHLRContainerEntity           * _Entities;
  
  // Clipping Window
  double                            _ClippingWindow[4];

  int                               _RealComputation;

// Initial transformation to replace objects in the view.
  CATMathTransformation           * _ViewTransformation;

//  Flags
  int                               _VisuMode;
  int                               _OutputHidden;
  double                            _Sag; // The unity for this Sag is the millimeter
  double                            _Tolerance;
  int                               _HaloMode; 


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

  HLRIsOccludedFunction _IsElementOccluded;
  void                * _ContextForOcclusion;

  // SoftwareConfiguration for versionning
  CATSoftwareConfiguration * _SoftwareConfiguration;

private:
    const CATTolerance              * _ClientTol;
};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================

inline CATHLRContainerEntity * CATHLRInternalMotor::GetEntities() const
{
  return _Entities;
}

//------------------------------------------------------------

inline CATHLRConstant::TypeProjection CATHLRInternalMotor::GetProjectionType() const
{
  return _TypeProjection;
}

//------------------------------------------------------------

inline const CATMathTransformation * CATHLRInternalMotor::GetViewTransformation() const
{
  return _ViewTransformation;
}

//------------------------------------------------------------

inline void CATHLRInternalMotor::GetObserverPosition(double * oPosition) const
{
  _Observer.GetCoord(oPosition);
}

//------------------------------------------------------------

inline void CATHLRInternalMotor::GetTargetPosition(double * oPosition) const
{
  _Target.GetCoord(oPosition);
}


//------------------------------------------------------------

inline void CATHLRInternalMotor::SetMode(int iInVisuMode)
{
  _VisuMode=iInVisuMode;
}

//------------------------------------------------------------

inline void CATHLRInternalMotor::SetOutputMode(int iWithHiddenLines)
{
  _OutputHidden=iWithHiddenLines;
}

//------------------------------------------------------------

inline void CATHLRInternalMotor::SetHaloMode(int iMode)
{
  _HaloMode = iMode;
}

//------------------------------------------------------------

inline int CATHLRInternalMotor::GetMode()
{
  return _VisuMode;
}

//------------------------------------------------------------

inline double CATHLRInternalMotor::GetSag()
{
  return _Sag;
}

//------------------------------------------------------------

inline double CATHLRInternalMotor::GetTolerance()
{
  return _Tolerance;
}


//------------------------------------------------------------


inline void CATHLRInternalMotor::SetClippingWindow(double iClippingWindow[4])
{
  _ClippingWindow[0]  = iClippingWindow[0];
  _ClippingWindow[1]  = iClippingWindow[1];
  _ClippingWindow[2]  = iClippingWindow[2];
  _ClippingWindow[3]  = iClippingWindow[3];
}

inline void CATHLRInternalMotor::GetClippingWindow(double * oClippingWindow) const
{
  oClippingWindow[0]  = _ClippingWindow[0];
  oClippingWindow[1]  = _ClippingWindow[1];
  oClippingWindow[2]  = _ClippingWindow[2];
  oClippingWindow[3]  = _ClippingWindow[3];
}

inline HLRIsOccludedFunction CATHLRInternalMotor::GetIsElementOccluded() {
  return _IsElementOccluded; }

inline void * CATHLRInternalMotor::GetContextForOcclusion() {
  return _ContextForOcclusion; }


extern "C" DSYExport CATHLRInternalMotor * CATHLRCreateExactMotor(const CATTolerance &iSceneTol);


//------------------------------------------------------------

#endif
