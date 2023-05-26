/* -*-C++-*-*/
#ifndef CATHLRSilhouetteComputer_H
#define CATHLRSilhouetteComputer_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2008
//
// CATHLRSilhouetteComputer
//
// DESCRIPTION :
//
//    Motor for the extraction of all silhouettes and computation of their visibility
//
//
//=============================================================================
// Abstract Class     : No
//=============================================================================
//
// History
//
// Dec. 2008   Dominique PREVOST (DPS)    Creation            
//
//=============================================================================

//============================================================
// Other includes
//------------------------------------------------------------ 

#include "HLREngine.h"                    // ExportedBy
#include "CATErrorDef.h"                  // define HRESULT
#include "CATBoolean.h"                   // define FALSE
#include "CATCGMScaleCategoryDef.h"       // enum CATCGMScaleCategory


//============================================================
// Forward declarations
//------------------------------------------------------------ 
class CATHLRSilhouetteComputerImpl;

class CATSoftwareConfiguration;
class CATMathTransformation;
class CATBody;
class CATMathPoint;
class CATMathDirection;
class CATMathPlane;
class CATMathVector;
class CATHLRViewRay;
class CATCrvParam;
class CATSurParam;
class CATHLREdge;
class CATCell;
class CATHLRContainerEntity;
class CATTolerance;


//============================================================
// CLASS DEFINITION
//------------------------------------------------------------ 
class ExportedByHLREngine CATHLRSilhouetteComputer
{
public:

  //=============================================================================
  // CONSTRUCTORS AND DESTRUCTOR
  //=============================================================================
  
  // iConfig IS MANDATORY : the method Create returns NULL if iConfig is NULL
  static CATHLRSilhouetteComputer * CreateHLRSilhouetteComputer(CATSoftwareConfiguration * iConfig, CATCGMScaleCategory iSceneScaleCategory);

  /**
  * Destructor
  */
  virtual ~CATHLRSilhouetteComputer();



  //=============================================================================
  // METHODS
  //=============================================================================

  // Adding a CATBody with an associated matrix.
  // Returns the EntityId = number of the Body in the recorded list (number from 1 to n)
  // (a body can be recorded twice (or more) with different matrix, with each time a different EntityId)
  virtual int AddEntity(CATBody * iBody, CATMathTransformation *iMatrixPosition = 0, int iPriorityGroup = 0) = 0;


  // Allow the caller to set the best TargetPoint
  // This call is not mandatory but very usefull in conical mode to define the best plane which splits the 3DSpace into 2 halfs.
  // (plane containing the view point and defined by [iTargetPt - iObserverPt] as Normal direction)
  // -> In conical mode, the scene has to be contained by only one 3DSpace half, 
  //    without any contact with this plane
  // -> Possible to set the Target point in cylindrical mode to make more stable the projection plane
  virtual void SetClientTargetPoint(const CATMathPoint &iTargetPt) = 0;

  // 3D mode and conical view
  virtual void SetViewPoint(const CATMathPoint &iObserverPt, bool ibConical = TRUE) = 0;


  // 3D mode and cylindrical view
  virtual void SetViewDirection(const CATMathDirection &iDir) = 0;


  // Force the activation of reflect research by HLR itself
  // (default behaviour consists in deactivating reflect research in HLR)
  // THIS CALL IS MANDATORY IF THERE IS AT LEAST A FACE WITH MIXT ORIENTATION VERSUS OBSERVER
  virtual void EnableReflectComputation() = 0;

  // Disable the activation of reflect research by HLR itself
  // (default behaviour consists in deactivating reflect research in HLR)
  // THIS CALL IS ONLY ALLOWED IF THERE IS NO FACE WITH MIXT ORIENTATION VERSUS OBSERVER
  virtual void DisableReflectComputation() = 0;




  // *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=
  // Starts really the computation of the HLR
  virtual HRESULT Run() = 0;


  // *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=
  // Retrieve Input Data

  virtual int GetNbEntities() = 0;

  virtual CATHLRContainerEntity * GetEntities() = 0;

  // Retrieve the entity (CATBody + Matrix) from the input Id (returned by AddEntity method)
  // ioMatrixPosition, if not NULL, allows to retrieve Matrix associated to the CATBody.
  // In this option, the pointer (*oMatrixPosition) has to be given as NULL by the caller (not allocated)
  // If there is no matrix associated to the body for the current entity, the output (*oMatrixPosition) is given back as NULL
  // Else, (*oMatrixPosition) is allocated by the called method, THEN IT HAS TO BE DEALLOCATED BY THE CALLER
  virtual CATBody * RetrieveEntity(int iEntityId, CATMathTransformation ** ioMatrixPosition=0) = 0;


  // S_OK if conical, else S_FALSE
  virtual HRESULT GetViewPoint(CATMathPoint &oViewPt) = 0;

  // S_OK if defined by caller of CATSilhouetteComputer, else S_FALSE
  virtual HRESULT GetClientTargetPoint(CATMathPoint &oTargetPt) = 0;

  // S_OK if cylindrical, else S_FALSE
  virtual HRESULT GetViewDirection(CATMathDirection &oViewDir) = 0;

  // returns 1 if the method EnableReflectComputation has been called, else 0
  virtual int IsReflectComputationRequired() = 0;

  virtual const CATSoftwareConfiguration * GetSoftwareConfiguration() = 0;

  virtual CATCGMScaleCategory GetSceneScaleCategory() = 0;


  // -------------------------------------------------------------------------
  // Returns the computed HLR parameters from the scene box and input ViewPoint/ViewDirection
  virtual HRESULT GetComputedHLRViewParameters(CATMathPoint &oObserver, CATMathPoint &oTarget,
                                               CATMathVector &oUpVector, CATMathVector &oRightVector) = 0;


  // -------------------------------------------------------------------------
  // Returns the computed HLR plane used for internal projection
  virtual HRESULT GetComputedHLRViewPlane(CATMathPlane &oViewPlane) = 0;


  // -------------------------------------------------------------------------
  // Returns the computed HLR tolerances from the scene factories CATTolerance
  virtual HRESULT GetComputedHLRViewTolerances(double &oSAG, double &oResolution) = 0;

  // -------------------------------------------------------------------------
  // Returns the set of tolerances used during the HLR computation
  // This Scale category depends on the input scale and on the bodies factories scale. (the biggest one)
  virtual const CATTolerance & GetSceneTolerance() = 0;

 
  // Returns the number of entities which contains silhouette edges
  virtual int GetNbResultEntities() = 0;
 

  // *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=
  // Iterator to get the information results about silhouette edges
  // *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=

  // PLEASE, CARE THE WAY TO CALL THE DIFFERENT ITERATOR SERVICES, LIKE THIS:
  // while (S_OK==GoToNextResultEntity(...))  | or use the Bypass : if (S_OK==ForceIterOnResultEntity(...)
  // {                                        | 
  //   while (S_OK==GoToNextCellSupport(...)) | or use the Bypass : if (S_OK==ForceIterOnCellSupport(...)
  //   {
  //     while (S_OK==GoToNextSilhouetteOnCell(...))
  //     {
  //       while (S_OK==GoToNextPartOfSilhouette(...))
  //       {
  //         ...
  //       }
  //     }
  //   }
  // }


  // -------------------------------------------------------------------------
  // DEPTH 1
  // Returns the current entity which contains silhouette edges
  // oEntityId is the identifier of the contextual entity,
  // in accordance with the signature of AddBody (number from 1 to n)
  // OUTPUT VARIABLEs VALUEs HAVE NO SENSE IF RETURNS S_FALSE
  virtual HRESULT GoToNextResultEntity(int & oEntityId, int & oNbCellSupport) = 0;

  // Force iterator to go on a specific entity
  // iEntityId is the identifier of the contextual entity,
  // in accordance with the signature of AddBody (number from 1 to n)
  virtual HRESULT ForceIterOnResultEntity(int iEntityId, int & oNbCellSupport) = 0;


  // -------------------------------------------------------------------------
  // DEPTH 2
  // Returns the current CATCell (CATEdge or CATFace) oCellSupport
  // = the CGM Topologoly on which oHLREdge is lying on 
  // OUTPUT VARIABLEs VALUEs HAVE NO SENSE IF RETURNS S_FALSE
  virtual HRESULT GoToNextCellSupport(CATCell * &oCellSupport, int & oNbSilhouettes) = 0;

  // Force iterator to go on a specific CATCell
  // iEntityId is the identifier of the contextual entity (Mandatory),
  // in accordance with the signature of AddBody (number from 1 to n)
  // THIS CALL IS POSSIBLE WITHOUT THE DEPTH 1, THANKS TO iEntityId
  virtual HRESULT ForceIterOnCellSupport(CATCell * iCellSupport, int iEntityId, int & oNbSilhouettes) = 0;


  // -------------------------------------------------------------------------
  // DEPTH 3
  // Returns the current HLREdge which contains silhouette parts
  // oCellSupport is the CGM Topologoly on which oHLREdge is lying on (CATEdge or CATFace)
  // oSubCellId is the identifier (number from 1 to n) of the current sub element of the cell
  // In case of CATEdge type, the silhouette number 1 begins at Start Vertex, 
  // and the silhouette number n ends at End Vertex of the edge support.
  // oViewSide is the observed side of the local shadow according to the edge orientation
  // oNbParts is the number of consecutive segments
  // -1 [RIGHT], 0 [NULL], +1 [LEFT], +2 [FULL] (may happen in non-manifold configurations)
  // OUTPUT VARIABLES VALUES HAVE NO SENSE IF RETURNS S_FALSE
  virtual HRESULT GoToNextSilhouetteOnCell(CATHLREdge * &oHLREdge, int &oSubCellId,
                                           int &oViewSide, int &oNbParts) = 0;

  
  // -------------------------------------------------------------------------
  // DEPTH 4
  // Returns the current part of silhouette (on initial edge) / reflect (on initial face).
  // This part is defined by numerical positions of its 2 extremities on the current HLREdge.
  // In case of CATEdge support, oPosVsEdge is the logical adding position versus the CATEdge vertices
  // oPosVsEdge : -1 if coincident to Start Vertex, 0 if inside, +1 if coincident to End Vertex
  // In case of CATFace support, pPosVsFace is the (U,V) position of each extremity on the CATSurface support
  // oViewRay gives information about all points (lying on silhouettes) which are touched by the same ray
  // from the observer in conical case, or parallel to the ViewDirection in cylindrical case.
  // oVisibilityType gives information about the visibility :
  // 0 : VISIBLE , 1 : HIDDEN , 2 : NULL_PROJECT , 3 : OCCLUDED , else : UNKNOWN
  //
  // By construction, the next part is connexe to the previous one (next start point is the previous end point)
  // OUTPUT VARIABLES VALUES HAVE NO SENSE IF RETURNS S_FALSE
  virtual HRESULT GoToNextPartOfSilhouette(CATCrvParam oCrvPar[2], int oPosVsEdge[2], 
                                           CATHLRViewRay * oViewRay[2],
                                           int &oVisibilityType) = 0;
  
  virtual HRESULT GoToNextPartOfSilhouette(CATCrvParam oCrvPar[2], CATSurParam oPosVsFace[2], 
                                           CATHLRViewRay * oViewRay[2],
                                           int &oVisibilityType,
                                           CATSurParam   * oMiddleParam=0) = 0;


  //=============================================================================
  // PROTECTED DATA
  //=============================================================================
protected:

  // Default constructor
  CATHLRSilhouetteComputer();

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================

#endif
