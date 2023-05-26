/* -*-C++-*-*/
#ifndef CATHLRResultBrowserV4_H
#define CATHLRResultBrowserV4_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1999
//
// CATHLRResultBrowserV4 
//
// DESCRIPTION :
/**
 *
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : yes
//=============================================================================
//
// History
//
// Feb. 1999 JCH Creation            
// Aug. 1999 HKL Correction dans TranformResult pour ne pas ecraser le resultat
//               du paquet des visibles par celui des cahcees (ou vice versa)
// Oct. 1999 HKL Ajout de RetrieveProjectedPart
//
//=============================================================================

//=============================================================================
// For Windows NT
//-----------------------------------------------------------------------------
#include "HLRModeleV4.h"

//=============================================================================
// For inheritance and other includes
//-----------------------------------------------------------------------------
#include "CATHLRBodyId.h"
#include "CATHLRResultBrowser.h"

#include "CATMathPoint.h"

//=============================================================================
// Forward declarations
//-----------------------------------------------------------------------------
class CATEdge;
class CATFace;
class CATGeoFactory;
class CATHLRContainerEntity;
class CATHLRCurve;
class CATHLREdge;
class CATHLRFace;
class CATHLRMemoryManager;
class CATHLRPlanarProjection;
class CATHLRResultEdgeV4;
class CATHLRResultEntityV4;
class CATHLRResultPartV4;
class CATMathTransformation;
class CATPCurve; 
class CATPlane;
class CATTolerance;

//=============================================================================
// CLASS DEFINITION
//=============================================================================

class ExportedByHLRModeleV4 CATHLRResultBrowserV4 : public CATHLRResultBrowser
{
public:
//============================================================
// CONSTRUCTORS AND DESTRUCTOR
//------------------------------------------------------------
/**
 * Default constructor.
 */
  CATHLRResultBrowserV4(CATHLRContainerEntity & iContainerEntity, const CATTolerance & iClientTol);

/**
 * Destructor.
 */
  virtual ~CATHLRResultBrowserV4();

//============================================================
// METHODS
//------------------------------------------------------------ 
/** Returns 0 for this class
 */
  virtual int IsExact();

/** Sets/unsets the output of the hidden lines.
 * <BR> Default mode computes the hidden lines.
 */
  inline void SetOutputHiddenLines();
  inline void UnsetOutputHiddenLines();

/** Selects only the results of a body, defined by its identifier CATHLRId.
 */
  virtual void SelectObject(CATHLRBodyId iObjectId);

/** Selects all the results.
 */
  virtual void SelectAll();

/** Sets the reverse transformation matrix.
 */
  void SetReverseTransformation(const CATMathPoint&iObserver,
                                const CATMathPoint&iTarget,
                                CATHLRConstant::TypeProjection iType,
                                const CATMathTransformation & iTransfo);

/** Go to the next edge of the selected ones. It returns 0 if there is no more edge,
 * 1 else.
 */
  virtual CATLONG32 GoToNextEdge();

/** Go to the edge designated.
 */
  virtual void GoToEdge(CATLONG32 iIdxEdge);

//-----------------------------------------------------------------------------
// About the edge
//-----------------------------------------------------------------------------
/** Gets the count of parts in the current edge.
 */
  virtual CATLONG32 GetCountParts() const;

/** Returns 1 if the edge is smooth.
 */
  virtual CATLONG32 IsSmooth() const;

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

/** Gets the curve associated to the edge.
 */
  virtual CATHLRCurve * GetCurve() const;

/** Gets the CATEdge associated to the edge. This returns NULL if there is no
 * (in case of created reflect line, for example).
 */
  virtual CATEdge * GetEdge() const;

/** Gets the CATHLREdge associated to the edge.
 */
  virtual CATHLREdge * GetHLREdge() const;

/** Gets the number of faces linked to the edge. If the edge is imbedded in a 
 * face, there should be only one ( this is the case for a created reflect line). 
 */
  virtual CATLONG32 GetCountFaces() const;

/** Gets a face linked to the edge from its number (this should start at 0 and
 * be strictly lower than GetCountFaces() ).
 */
  virtual CATHLRFace * GetFace(CATLONG32 iIdxFace) const;

//-----------------------------------------------------------------------------
// About the current part
//-----------------------------------------------------------------------------
/** Gets the visibility of the current part.
 */
  virtual CATHLRConstant::TypeVisibility GetVisibility() const;

/** Gets the start/end parameters of the current part on the curve
 */
  virtual void GetStartParam(CATCrvParam & oStart) const;
  virtual void GetEndParam(CATCrvParam & oEnd) const;

/** Returns 1 if the part is a reflect.
 */
  virtual CATLONG32 IsReflect() const;

/** Go to the next part. Returns 0 if there is no more part on the edge, 1 else.
 */
  virtual CATLONG32 GoToNextPart();

/** Gets the projection of the current part and its extremities.
 * If the projection is not possible, this throws an exception.
 * iProjectionMode 
 * 0: approximate 
 * 1: exact projection if available
 */
  virtual CATPCurve * ProjectPart(CATCrvParam & oStartParam, 
                                  CATCrvParam & oEndParam,
								  int iProjectionMode = 0);

/** When the projected part has been simplified, ProjectPart returns 0
 *  In order to retrieve the real projection (shared with another part), 
 *  use the following method
 */
  virtual CATPCurve * RetrieveProjectedPart();

//============================================================
// INTERNAL DATA
//------------------------------------------------------------
protected:
// List of entities in the result
  CATHLRResultEntityV4 ** _ArrayEntity;

// Current selected edge
  CATHLRResultEdgeV4  * _CurrentResultEdgeV4;

// Current Part used.
  CATHLRResultPartV4 * _CurrentPartV4;

// First edge of the results selected
  CATHLRResultEdgeV4 * _FirstResultEdgeV4;
  CATHLRResultEdgeV4 * _LastResultEdgeV4;

// Replace matrix to put the result in the original space.
  CATMathTransformation * _ReplaceMatrix;

// Flag to see if the output contains the hidden lines
  int                     _OutputHiddenLines;

// Buffer for the vectors
  double               *  _VisibleBuffer;
  double               *  _HiddenBuffer;
  int                     _SizeVisibleBuffer;
  int                     _SizeHiddenBuffer;

// Select the CurrentEdge
  virtual void SelectCurrentEdge();
  virtual void SelectEntity(CATLONG32 iIdxEntity);
  virtual void ReallocateEntity();
  void TransformResult(const double * iArray, const double * ioOutputBuffer, int iNbVectors) const;
};

//============================================================
// INLINE FUNCTIONS
//------------------------------------------------------------

inline void CATHLRResultBrowserV4::SetOutputHiddenLines()
{
  _OutputHiddenLines=1;
}

inline void CATHLRResultBrowserV4::UnsetOutputHiddenLines()
{
  _OutputHiddenLines=0;
}


#endif
