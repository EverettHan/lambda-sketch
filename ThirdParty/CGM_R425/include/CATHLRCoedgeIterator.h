/* -*-C++-*-*/
#ifndef CATHLRCoedgeIterator_H
#define CATHLRCoedgeIterator_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRCoedgeIterator 
//
// DESCRIPTION :
/**
 * Iterator on coedges of a model
 */
//
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

// For Windows NT
#include "HLRTopology.h"

#include "CATHLRCoedge.h"
#include "CATHLRChainCoedge.h"

class CATHLRCoedge;

class CATHLRCoedgeIterator
{
public:
//=============================================================================
// SET AND GET METHODS
//=============================================================================
// Sets the first link of the chain
  inline void SetStartLink(CATHLRChainCoedge * iFirstLink);
  inline void SetStartCoedge(CATHLRCoedge      * iFirstCoedge);

// Gets the current Coedge ( NULL if the list is exhausted )
  inline CATHLRCoedge * GetCurrentCoedge() const;

// Go to the next Coedge
  inline void GoToNext();

// Go to the previous Coedge
  //inline void GoToPrevious();

// Resets the iterator: put it on the first CATHLRCoedge
  inline void Reset();

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
  union
  {
    CATHLRChainCoedge * _StartLink;
    CATHLRCoedge      * _StartCoedge;
  };
  union
  {
    CATHLRChainCoedge * _CurrentLink;
    CATHLRCoedge      * _CurrentCoedge;
  };
  int _Start;
  int _CountCoedges;
};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================
inline void CATHLRCoedgeIterator::SetStartLink(CATHLRChainCoedge * StartLink)
{
  _StartLink   = StartLink;
  _CurrentLink = StartLink;  
  _Start       = 1;
  _CountCoedges= 0;
}

inline void CATHLRCoedgeIterator::SetStartCoedge(CATHLRCoedge * StartCoedge)
{
  _StartCoedge   = StartCoedge;
  _CurrentCoedge = StartCoedge;  
  _Start         = 1;
  _CountCoedges  = 1;
}

inline CATHLRCoedge * CATHLRCoedgeIterator::GetCurrentCoedge() const
{
  if (_CountCoedges)
    return ( _CurrentCoedge && (_Start || _CurrentCoedge!=_StartCoedge)) ? _CurrentCoedge : 0L;
  else
    return ( _CurrentLink && (_Start || _CurrentLink!=_StartLink)) ? _CurrentLink->GetCoedge() : 0L;
  /*
  if ( _CurrentLink)
    {
      return _CurrentLink->GetCoedge();
    }
  return 0L;
  */
}

inline void CATHLRCoedgeIterator::GoToNext()
{
  /*
  if (_CurrentLink)
    {
      _CurrentLink = _CurrentLink->GetNext();
    }
    */
  if (_CountCoedges)
  {
    if ( _CurrentCoedge && (_Start || _CurrentCoedge!=_StartCoedge)) _CurrentCoedge = _CurrentCoedge->GetNext();
  }
  else
    if ( _CurrentLink && (_Start || _CurrentLink!=_StartLink)) _CurrentLink = _CurrentLink->GetNext();
  _Start = 0;
}

/*
inline void CATHLRCoedgeIterator::GoToPrevious()
{
  if (_CurrentLink)
    {
      _CurrentLink = _CurrentLink->GetPrevious();
    }
}
*/
inline void CATHLRCoedgeIterator::Reset()
{
  if (_CountCoedges)
    _CurrentCoedge = _StartCoedge;
  else
    _CurrentLink = _StartLink;
  _Start       = 1;
}


#endif
