/* -*-C++-*-*/
#ifndef CATHLRCoedge_H
#define CATHLRCoedge_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRCoedge 
//
// DESCRIPTION :
/**
 * Coedge on a face for the HLR
 */
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
// Jan. 98   Jose CHILLAN (jch)    Creation            
//
//=============================================================================

#include "CATDataType.h"
// For Windows NT
#include "HLRTopology.h"

class CATHLREdge;
class CATHLRPCurve;
class CATHLRCoSubEdge;
class CATHLRVertex;
class CATCrvParam;

class ExportedByHLRTopology CATHLRCoedge
{
public:

//=============================================================================
// CONSTRUCTOR
//=============================================================================
/** Constructor with a PCurve and a sense
 */
  CATHLRCoedge(CATHLRPCurve * iPCurve,
	             CATHLREdge   * iEdge,
	             CATLONG32      iSense);
 
//=============================================================================
// METHODS
//=============================================================================
/** Gets the PCurve on which the coedge lies
 */
  inline CATHLRPCurve * GetPCurve() const;

/** Gets the edge associated to the coedge
 */
  inline CATHLREdge * GetAssociatedEdge() const;

/** Gets the sense of the coedge in comparison to the edge
 */
  inline CATLONG32 GetSense() const;

  virtual CATHLRCoSubEdge * SafeCastToHLRCoSubEdge();

  virtual CATHLRVertex * GetStartVertexInLoop(CATCrvParam * iStartParamInLoop);
  virtual CATHLRVertex * GetEndVertexInLoop(CATCrvParam * iEndParamInLoop);


//=============================================================================
// METHODS TO SET THE DATAS
//=============================================================================
// Sets the PCurve
  inline void SetPCurve(CATHLRPCurve * iPCurve);

// Sets the edge with the sense
  inline void SetEdge(CATHLREdge * iEdge, CATLONG32 iSense);

  inline CATHLRCoedge * GetNext() const;
  inline void SetNext(CATHLRCoedge * iCoedge);

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// next Edge of the Entity
  CATHLRCoedge * _Next;

// PCurve that determine the coedge
  CATHLRPCurve * _PCurve;

// Edge which is associated to the coedge
  CATHLREdge   * _AssociatedEdge;

// Sense of the coedge ( 1 or -1)
  signed char    _Sense;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================

//-----------------------------------------------------------------------------

inline CATHLRCoedge * CATHLRCoedge::GetNext() const
{
  return _Next;
}

//-----------------------------------------------------------------------------

inline void CATHLRCoedge::SetNext(CATHLRCoedge * iCoedge)
{
  if (iCoedge) iCoedge->_Next = _Next;
  _Next = iCoedge;
}

//------------------------------------------------------------
// About the pcurve
//------------------------------------------------------------
inline CATHLRPCurve * CATHLRCoedge::GetPCurve() const
{
  return _PCurve;
}

inline void CATHLRCoedge::SetPCurve(CATHLRPCurve * PCurve)
{
  _PCurve = PCurve;
}

//------------------------------------------------------------
// About the edges
//------------------------------------------------------------
inline CATHLREdge * CATHLRCoedge::GetAssociatedEdge() const
{
  return _AssociatedEdge;
}

//------------------------------------------------------------

inline void CATHLRCoedge::SetEdge(CATHLREdge * Edge, CATLONG32 Sense)
{
  _AssociatedEdge = Edge;
  _Sense          = (signed char) Sense;
}

//------------------------------------------------------------

inline CATLONG32 CATHLRCoedge::GetSense() const
{
  return (CATLONG32) _Sense;
}

//-----------------------------------------------------------------------------

#endif
