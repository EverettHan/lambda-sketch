/* -*-C++-*-*/
#ifndef CATHLRResultBrowser_H
#define CATHLRResultBrowser_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRResultBrowser 
//
// DESCRIPTION :
/**
 * Object to browse the results of the HLR.
 * <BR> The result is obtained using the Id of the objects that has been returned
 * by the CATHLRComputer when using the method AddObject().
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : Yes
//=============================================================================
//
// History
//
// Feb. 1998 JCH Creation            
// Aug. 1999 HKL Gestion de l'unification de demi-cercles
// Oct. 1999 HKL Ajout de RetrieveProjectedPart
// Mar. 2000 HKL Halo mode
// Jun. 2000 HLK Gestion de la projection en mode conique 
//
//=============================================================================

// For Windows NT
#include "HLRProject.h"

// Other includes
#include "CATHLRConstant.h"
#include "CATHLRBodyId.h"
#include "CATHLRResultBrowserBase.h"
#include "CATMathPoint.h"

class CATCrvParam;
class CATEdge;
class CATFace;
class CATGeoFactory;
class CATTolerance;

class CATHLRContainerEntity;
class CATHLRCurve;
class CATHLREdge;
class CATHLRFace;
class CATHLRGeometry2DFactory;
class CATHLRPlanarProjection;
class CATHLRResultEdge;
class CATHLRResultEntity;
class CATHLRResultPart;
class CATPCurve; 
class CATPlane;
class CATHLRObjectLinker;



typedef int (*ClientGOFunctionToUnify) (void * iClientContextData, CATHLREdge * iEdge1, CATHLREdge * iEdge2);


class ExportedByHLRProject CATHLRResultBrowser : public CATHLRResultBrowserBase
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Default constructor
 */
  CATHLRResultBrowser(CATHLRContainerEntity &iContainerEntity, const CATTolerance & iCtxTol, CATSoftwareConfiguration * iConfig = 0);


//=============================================================================
// METHODS
//=============================================================================
/** Selects the mode when the output is in the projection view.
 */
  virtual void SetProjectionSpaceMode();

/** Selects the mode when the output is in the original space ( default mode).
 */
  virtual void SetOriginalSpaceMode();

/** Sets the projection datas : a CATGeoFactory to create the objects, and a
 * projection plane on which the objects will be projected.
 */
  void SetProjectionDatas(CATGeoFactory * iFactory, CATPlane * iProjectionPlane);
  inline CATHLRPlanarProjection * GetProjecter() const;

//-----------------------------------------------------------------------------
// About the edge
//-----------------------------------------------------------------------------
/** Gets the number of visible vectors of the current edge.
 */
  virtual CATLONG32 GetCountVisibleVectors() const;

/** Gets the number of hidden vectors of the current edge.
 */
  virtual CATLONG32 GetCountHiddenVectors() const;

/** Gets the number of visible reflect vectors of the current edge.
 */
  virtual CATLONG32 GetCountVisibleSilhouetteVectors() const;

/** Gets the number of hidden reflect vectors of the current edge.
 */
  virtual CATLONG32 GetCountHiddenSilhouetteVectors() const;

/** Gets the array of visible vectors.
 */
  virtual const double * GetVisibleVectors() const;

/** Gets the array of hidden vectors.
 */
  virtual const double * GetHiddenVectors() const;

/** Gets the projection of the current part and its extremities.
 * If the projection is not possible, this throws an exception.
 * iProjectionMode 
 * 0: approximate 
 * 1: exact projection if available
 */
  virtual CATPCurve * ProjectPart(CATCrvParam & oStartParam, 
                                  CATCrvParam & oEndParam,
								                  int iProjectionMode = 0) = 0;

/** When the projected part has been simplified, ProjectPart returns 0
 *  In order to retrieve the real projection (shared with another part), 
 *  use the following method
 */
  virtual CATPCurve * RetrieveProjectedPart() = 0;

//=============================================================================
// OTHER METHODS
//=============================================================================
/** Changes the object that creates the 2-dimensional geometry. 
 */
  void SetGeometry2DBuilder(CATHLRGeometry2DFactory * iGeo2DFactory);

/** Smoothes the output geometry (for drafting views)
 */
  virtual void Lissage(double iSag=0.1) = 0;

/** Set the circle unification capability (1: ON 0: OFF).
 */
  void SetUnificationMode(int iMode);


/** External function used to:
 * disable visibility of some SubEdges (smooth edge application filter for example)
 * In case of polyhedral HLR Computer with PolyBodies, this function allows to
 * visualize as hidden the first edge which is occluded by another one that 
 * application would like to disable (smooth edge which is not an outline for example)
 * iSubEdgeOutlineType : 
 * 0 if not outline, 1 if outline but 2 if the outline is occluded by its own adjacent face
 */
  inline void SetClientContextData(void * iClientContextData);
  inline void SetClientGOFunctionToUnify(ClientGOFunctionToUnify iClientGOFunctionToUnifyHLRProjection);


/** If the projected part is a  circle or a line, looks for a circle or a
 * line that matches one of the projection extremities and merge the two curves
 */
  virtual CATPCurve * UnifyProjection(CATPCurve * iPCurve) = 0;

/** Computes the new segments limits when the halo mode is on
 */
  virtual void ComputeHaloRelimitations();
  virtual void ComputeHaloOnStart(CATHLRResultPart * iPart);
  virtual void ComputeHaloOnEnd  (CATHLRResultPart * iPart);
  int GetCountEntities();


protected:
    
/**
 * Destructor // private use only, please, use Release() method instead
 */
  virtual ~CATHLRResultBrowser();



  //=============================================================================
  // INTERNAL DATAS
  //=============================================================================
protected:

  // Object that makes the projections
  CATHLRPlanarProjection * _Projecter;

  // Used by UnifyProjection
  CATHLRObjectLinker     * _PartToJeleTable;

  char                     _UnificationMode;

  // External function used to:
  // disable visibility of some SubEdges (smooth edge application filter for example)
  // In case of polyhedral HLR Computer with PolyBodies, this function allows to
  // visualize as hidden the first edge which is occluded by another one that 
  // application would like to disable (smooth edge which is not an outline for example)
  void                   * _ClientContextData;
  ClientGOFunctionToUnify  _ClientGOFunctionToUnify;

};

inline int CATHLRResultBrowser::GetCountEntities()
{
  return _CountEntities;
}

inline void CATHLRResultBrowser::SetClientContextData(void * iClientContextData)
{
  _ClientContextData = iClientContextData;
}

inline void CATHLRResultBrowser::SetClientGOFunctionToUnify(ClientGOFunctionToUnify iClientGOFunctionToUnifyHLRProjection)
{
  _ClientGOFunctionToUnify = iClientGOFunctionToUnifyHLRProjection;
}

inline CATHLRPlanarProjection * CATHLRResultBrowser::GetProjecter() const {
  return _Projecter; }

#endif
