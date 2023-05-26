/* -*-C++-*-*/
#ifndef CATHLRResultCreationV4_H
#define CATHLRResultCreationV4_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1999
//
// CATHLRResultCreationV4 
//
// DESCRIPTION :
/**
 * Class inherited from CATHLRResultBrowserV4, used to set the datas.
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Feb. 99 JCH Creation            
// Aug. 99 HKL Unification decercles
//
//=============================================================================

//=============================================================================
// For Windows NT
//-----------------------------------------------------------------------------
#include "HLRModeleV4.h"

//=============================================================================
// For inheritance and other includes
//-----------------------------------------------------------------------------
#include "CATHLRResultBrowserV4.h"

//=============================================================================
// Forward declarations
//-----------------------------------------------------------------------------
class CATHLRContainerEntity;
class CATHLRMemoryManager;
class CATHLRResultEdgeV4; 
class CATHLRResultEntityV4;
class CATHLREdge;
class CATHLRFace;
class CATMathTransformation;
class CATTolerance;

//=============================================================================
// CLASS DEFINITION
//=============================================================================

class ExportedByHLRModeleV4 CATHLRResultCreationV4 : public CATHLRResultBrowserV4
{
public:
//============================================================
// CONSTRUCTORS AND DESTRUCTOR
//------------------------------------------------------------
/**
 * Default constructor.
 */
  CATHLRResultCreationV4(CATHLRContainerEntity & iContainerEntity, const CATTolerance & iClientTol);

/**
 * Destructor.
 */
  ~CATHLRResultCreationV4();

//============================================================
// METHODS
//------------------------------------------------------------ 
/** Creating a new CATHLRResultEntity.
 */
//  void SelectEntity(CATHLRBodyId iIdentity);

/** Adds an edge/face in the result (this creates an entity if necessary).
 * <BR> The pointer might be null/
 */
  void AddEdge(CATHLRBodyId iNewId, CATHLREdge * iLinkedEdge);
  void AddFace(CATHLRBodyId iNewId, CATHLRFace * iLinkedFace);

/** Sets the visible/hidden vectors of the current edge
 */
  void SetVisibleVectors(int iCountVectors, const double * iArrayVectors, int * iIsReflect);
  void SetHiddenVectors (int iCountVectors, const double * iArrayVectors, int * iIsReflect);

/** Smoothes the output geometry (for drafting views)
 */
  virtual void Lissage(double iSag=0.1);

/** If the projected part is a  circle or a line, looks for a circle or a
 * line that matches one of the projection extremities and merge the two curves
 */
  virtual CATPCurve * UnifyProjection(CATPCurve * iPCurve);

//============================================================
// INTERNAL DATA
//------------------------------------------------------------
protected:
// Current BodyId of the last created entity
  CATHLRBodyId           _CurrentId;

// Current entity in which the edges are added.
  CATHLRResultEntityV4 * _UsedEntity;

// Current Result edge on which the parts are added
  CATHLRResultEdgeV4   * _UsedResultEdge;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================



#endif
