/** 
 * @fullReview  TPG 02:03:20
 * @quickReview TPG 01:07:24
 * @quickReview TPG 02:03:20
 */
/* -*-C++-*-*/
#ifndef CATHLREdge_H
#define CATHLREdge_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLREdge 
//
// DESCRIPTION :
// Edge for the HLR. An edge is necessary linked to 2 vertices.
//
// Main Methods :
//  
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Jan. 1998 JCH Creation            
// Jun. 1999 HKL Added EvaluateOnFace method
// Nov. 1999 HKL Store the curvature step
// Jul. 2001 TPG IsHelix
// Mar. 2002 TPG CATHLREdgeExact
// Jul. 2012 DPS No Helix anymore here but Clash management
//
//=============================================================================

// For Windows NT
#include "HLRTopology.h"

// For inheritance
#include "CATHLRTopology.h"

// Other includes
#include "CATHLRConstant.h"
#include "CATCrvParam.h"

#include "CATHLRBodyId.h"

#include "CATCGMOutput.h"

class CATEdge;
class CATHLRCoedge;
class CATHLRChainFace; 
class CATHLRContainer;
class CATHLRCurve;
class CATHLRFace;
class CATHLRVertex;
class CATHLRTransformation;
class CATMathVector;
class CATHLRHedge;
class CATSurParam;
class CATHLRMemoryManager;
class CATHLRClashEdge;

class ExportedByHLRTopology CATHLREdge : public CATHLRTopology
{
public:
//=============================================================================
// ENUMERATIONS
//=============================================================================
/** Different curvatures computed.
 */
  enum CurvatureStatus { Successful, Failed};

  enum CATHLREdgeIdType { EdgeUnknownId, EdgeV5TAG, EdgeV4JELE, EdgeGPPTR, PolyEdgeID, EdgeTemp };


//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/** Constructor from a CATEdge
 */ 
  CATHLREdge(void            * iEdge, 
	           CATHLRBodyId      iIdentity,
             CATHLRContainer * iContainer,
             CATHLRVertex    * iStartVertex,
             CATHLRVertex    * iEndVertex,
             CATHLRCurve     * iSupportCurve,
             const CATHLRTransformation * iTransformation);

/** Constructor with no model geometry, but all the datas. The last datas is
 * put to declare if the edge is a reflect line.
 */
  CATHLREdge(int                 iIdentifier,
	           CATHLRBodyId        iIdentity,
             CATHLRContainer   * iContainer,
             CATHLRVertex      * iStartVertex,
             CATHLRVertex      * iEndVertex,
             CATHLRCurve       * iSupportCurve,
             const CATHLRTransformation * iTransformation=0);

//=============================================================================
// METHODS
//=============================================================================
/** Gets the identity of the owning body.
 */
  inline CATHLRBodyId GetIdentity() const;

/** Gets the extremities of the vertex
 */
  inline CATHLRVertex * GetStartVertex() const;
  inline CATHLRVertex * GetEndVertex() const;

/** Gets the curve on which the edge lies
 */
  inline CATHLRCurve * GetCurve() const;

/** Return the original orientation of the curve in the edge, multiplied by the
 *  orientation of the edge in its unique domain. Return 0 if the edge is
 *  shared by several domains.
 */
  virtual int GetCurveUniqueOrientation() const;
  virtual void UpdateCurveUniqueOrientation(int iOrientation);

/** Gets the start and end param of the edge
 */
  virtual void GetStartParam(CATCrvParam & oParam) const = 0;
  virtual void GetEndParam  (CATCrvParam & oParam) const = 0;

/** Checks if the edge is vivid.
 */
  virtual CATLONG32 IsVivid() const;
  virtual CATLONG32 IsSmooth() const;

/** Gets a pointer on a CATEdge. This returns NULL if it is a reflect line.
 */
  virtual CATEdge * GetEdge() const = 0;


/** Get attribute/identifier (CATINPTR) lying on CATHLREdge, 
  * CATHLREdgeIdType depends on context (JELE, TAG, EdgeGP* ...)
  * Null value means no attribute/identifier
  */
  virtual CATINTPTR GetClientId(CATHLREdgeIdType &oType);

/** Gets the count of faces linked to the edge.
 */
  inline CATLONG32 GetCountFaces() const;

/** Gets a face associated to the edge from its index ( starting at 0).
 * If the Edge is a reflect line, the only face is the one on which it lies.
 */
  virtual CATHLRFace * GetFace(int iIdxFace) const;

/** Specific method for the drafting.
 * <BR> Evaluates the difference of curvature between the two faces that share
 * the edge.
 * The result is between 0. and 1..
 * 0 means there is no jump of curvature, 1. there is a big step.
 */
  virtual double GetCurvatureStep(double iReferenceCurvature);

/** Retrieves the edge's dimension (ie. 1)
  */
  inline int GetDimension();


//=============================================================================
// METHODS TO SET THE DATAS
//=============================================================================
// Sets the vertices
  inline void SetStartVertex(CATHLRVertex * iStartVertex);
  inline void SetEndVertex  (CATHLRVertex * iEndVertex);

/** Adds a face on which the edge lies, giving the chain that is used.
 */
  void AddFace(CATHLRFace * iFace, 
	       CATHLRMemoryManager * iMemoryManager);

// Sets the curve
  inline void SetCurve(CATHLRCurve *iCurve);

/** Sets the vivicity.
 */
  virtual void SetVivicity(CATHLRConstant::Vivicity iVivicity);

/** Update Clash information on edge
 */
  virtual void AppendClashPoint(CATHLRMemoryManager * iMemoryManager, CATCrvParam &iClashParam, CATHLRFace * iClashingFace);

/** Evaluates the inverse of the curvature of the face in the direction
 * that is orthogonal to the tangent at the given parameter..
 */
  virtual CATHLREdge::CurvatureStatus EvaluateInternalCurvature(const CATCrvParam & iParam,
                                                        CATHLRFace        * iFace,
                                                        double            & iCurvature,
                                                        CATMathVector     * oDirection = 0L) const;
/** Evaluates the face's surface parameter at edge's curve parameter
 */
  virtual void EvaluateOnFace(double iParam, CATHLRFace * iFace, CATSurParam & oParam) const = 0;

//------------------------------------------------------------
// For the HLR's management
//------------------------------------------------------------
  //inline void SetHLRHedge(CATHLRHedge * iHeadEdge);
  //inline CATHLRHedge * GetHLRHedge();
  virtual void SetHLRHedge(CATHLRHedge * iHeadEdge);
  virtual CATHLRHedge * GetHLRHedge();
  virtual CATHLRClashEdge * GetHLRClashEdge();


/** For the debug of the models.
 */
// HKL  inline void SetComputationId(CATLONG32 iNumber);
// HKL  CATLONG32 GetComputationId() const;

  inline CATHLREdge * GetNext() const;
  inline void SetNext(CATHLREdge * iEdge);

  inline CATHLREdge * GetNextBoundedEdge(const CATHLRVertex * iVertex) const;
  inline void SetNextBoundedEdge(const CATHLRVertex * iVertex, CATHLREdge * iEdge);

//=============================================================================
// INTERNAL METHODS
//=============================================================================
public:
/** Gets the coedge associated to a given face.
 */
  CATHLRCoedge * GetCoedge(CATHLRFace * iFace) const;

/** Compute the vivicity.
 */
  virtual void ComputeVivicity();

  virtual void Dump(CATCGMOutput& os);

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// next Edge of the Start Vertex
  CATHLREdge   * _NextStartBoundedEdge;
// next Edge of the End Vertex
  CATHLREdge   * _NextEndBoundedEdge;
// next Edge of the Entity
  CATHLREdge   * _Next;

// Identity of the body the edge belongs
  CATHLRBodyId   _Identity;

// Vertice extremity of the edge
  CATHLRVertex * _StartVertex;
  CATHLRVertex * _EndVertex;

// Curve
  CATHLRCurve  * _SupportCurve;

// Extremities of the edge
//  CATCrvParam    _StartParam;
//  CATCrvParam    _EndParam;

// Pointer on the HLREdge
//  cHedge       * _HLREdge;

// Pointer on a chain of faces
//abt  CATHLRChainFace * _FirstChainFace;

// VERY often there is 1 or 2 faces -> in this case we use _OneFace or an allocated _ArrayFaces if not 
// we use a chain of CATHLRChainFace
// Pointer on the current end
  union {
    CATHLRFace      *  _FirstFace; 
    //CATHLRFace      ** _ArrayFaces; 
    CATHLRChainFace *  _CurrentEnd;
  };
  CATHLRFace      *  _SecondFace; 
  
  short               _CountFaces;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================

//-----------------------------------------------------------------------------

inline CATHLRBodyId CATHLREdge::GetIdentity() const
{
  return _Identity;
}

//-----------------------------------------------------------------------------

inline CATLONG32 CATHLREdge::GetCountFaces() const
{
  return (CATLONG32) _CountFaces;
}

//-----------------------------------------------------------------------------

inline CATHLREdge * CATHLREdge::GetNext() const
{
  return _Next;
}

//-----------------------------------------------------------------------------

inline void CATHLREdge::SetNext(CATHLREdge * iEdge)
{
  if (iEdge) iEdge->_Next = _Next;
  _Next = iEdge;
}



//------------------------------------------------------------
// About the vertice
//------------------------------------------------------------
inline CATHLRVertex * CATHLREdge::GetStartVertex() const
{
  return _StartVertex;
}

//-----------------------------------------------------------------------------

inline CATHLRVertex * CATHLREdge::GetEndVertex() const
{
  return _EndVertex;
}

//-----------------------------------------------------------------------------

inline void CATHLREdge::SetStartVertex(CATHLRVertex * Vertex)
{
  _StartVertex = Vertex;
}

//-----------------------------------------------------------------------------

inline void CATHLREdge::SetEndVertex(CATHLRVertex * Vertex)
{
  _EndVertex = Vertex;
}

//------------------------------------------------------------
// About the curve
//------------------------------------------------------------
inline CATHLRCurve * CATHLREdge::GetCurve() const
{
  return _SupportCurve;
}

//-----------------------------------------------------------------------------

inline void CATHLREdge::SetCurve(CATHLRCurve * Curve)
{
  _SupportCurve = Curve;
}

//-----------------------------------------------------------------------------

inline int CATHLREdge::GetDimension()
{
  return 1;
}

//-----------------------------------------------------------------------------

inline CATHLREdge * CATHLREdge::GetNextBoundedEdge(const CATHLRVertex * iVertex) const
{
  if (iVertex==_StartVertex)
    return _NextStartBoundedEdge;
  else if (iVertex==_EndVertex)
    return _NextEndBoundedEdge;
  else 
    return 0L;
}

//-----------------------------------------------------------------------------

inline void CATHLREdge::SetNextBoundedEdge(const CATHLRVertex * iVertex, CATHLREdge * iEdge)
{
  if (iVertex==_StartVertex)
    _NextStartBoundedEdge = iEdge;
  else if (iVertex==_EndVertex)
    _NextEndBoundedEdge   = iEdge;
}

//-----------------------------------------------------------------------------

#endif
