/* -*-C++-*-*/
#ifndef CATHLREdgeIterator_H
#define CATHLREdgeIterator_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLREdgeIterator 
//
// DESCRIPTION :
/**
 * Iterator to sweep a list of edges
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Feb. 98   Jose CHILLAN (jch)    Creation            
//
//=============================================================================


// For Windows NT
#include "HLRTopology.h"

#include "CATHLRChainEdge.h"

class CATHLREdge;

class CATHLREdgeIterator
{
public:
//=============================================================================
// SET AND GET METHODS
//=============================================================================
// Sets the first link of the chain
  inline void SetStartLink(CATHLRChainEdge * iFirstLink);
  inline void SetStartEdge(CATHLREdge      * iFirstEdge);

// Gets the current Edge ( NULL if the list is exhausted )
  inline CATHLREdge * GetCurrentEdge() const;

// Go to the next Edge
  inline void GoToNext();

// Go to the previous Edge
  //inline void GoToPrevious();

// Resets the iterator: put it on the first CATHLREdge
  inline void Reset();

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
  union
  {
    CATHLRChainEdge * _StartLink;
    CATHLREdge      * _StartEdge;
  };
  union
  {
    CATHLRChainEdge * _CurrentLink;
    CATHLREdge      * _CurrentEdge;
  };
  int _Start;
  int _CountEdges;
};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================
inline void CATHLREdgeIterator::SetStartLink(CATHLRChainEdge * StartLink)
{
  _StartLink   = StartLink;
  _CurrentLink = StartLink;  
  _Start       = 1;
  _CountEdges  = 0;
}

inline void CATHLREdgeIterator::SetStartEdge(CATHLREdge * StartEdge)
{
  _StartEdge   = StartEdge;
  _CurrentEdge = StartEdge;  
  _Start       = 1;
  _CountEdges  = 1;
}

inline CATHLREdge * CATHLREdgeIterator::GetCurrentEdge() const
{
  if (_CountEdges)
    return ( _CurrentEdge && (_Start || _CurrentEdge!=_StartEdge)) ? _CurrentEdge : 0L;
  else
    return ( _CurrentLink && (_Start || _CurrentLink!=_StartLink)) ? _CurrentLink->GetEdge() : 0L;
  /*
  if ( _CurrentLink)
    {
      return _CurrentLink->GetEdge();
    }
  return 0L;
  */
}

inline void CATHLREdgeIterator::GoToNext()
{
  /*
  if (_CurrentLink)
    {
      _CurrentLink = _CurrentLink->GetNext();
    }
    */
  if (_CountEdges)
  {
    if ( _CurrentEdge && (_Start || _CurrentEdge!=_StartEdge)) _CurrentEdge = _CurrentEdge->GetNext();
  }
  else
    if ( _CurrentLink && (_Start || _CurrentLink!=_StartLink)) _CurrentLink = _CurrentLink->GetNext();
  _Start = 0;
}
/*
inline void CATHLREdgeIterator::GoToPrevious()
{
  if (_CurrentLink)
    {
      _CurrentLink = _CurrentLink->GetPrevious();
    }
}
*/
inline void CATHLREdgeIterator::Reset()
{
  if (_CountEdges)
    _CurrentEdge = _StartEdge;
  else
    _CurrentLink = _StartLink;
  _Start       = 1;
}

#endif
