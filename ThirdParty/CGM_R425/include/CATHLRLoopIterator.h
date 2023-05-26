/* -*-C++-*-*/
#ifndef CATHLRLoopIterator_H
#define CATHLRLoopIterator_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRLoopIterator 
//
// DESCRIPTION :
/**
 * Iterator to sweep a list of loops
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

// For Windows NT
#include "HLRTopology.h"

#include "CATHLRLoop.h"
#include "CATHLRChainLoop.h"

class CATHLRLoop;

class CATHLRLoopIterator
{
public:
//=============================================================================
// SET AND GET METHODS
//=============================================================================
// Sets the first link of the chain
  inline void SetStartLink(CATHLRChainLoop * iFirstLink);
  inline void SetStartLoop(CATHLRLoop      * iFirstLoop);

// Gets the current Loop ( NULL if the list is exhausted )
  inline CATHLRLoop * GetCurrentLoop() const;

// Go to the next Loop
  inline void GoToNext();

// Go to the previous Loop
  inline void GoToPrevious();

// Resets the iterator: put it on the first CATHLRLoop
  inline void Reset();

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
  union
  {
    CATHLRChainLoop * _StartLink;
    CATHLRLoop      * _StartLoop;
  };
  union
  {
    CATHLRChainLoop * _CurrentLink;
    CATHLRLoop      * _CurrentLoop;
  };
  int _Start;
  int _CountLoops;
};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================
inline void CATHLRLoopIterator::SetStartLink(CATHLRChainLoop * StartLink)
{
  _StartLink   = StartLink;
  _CurrentLink = StartLink;  
  _Start       = 1;
  _CountLoops= 0;
}

inline void CATHLRLoopIterator::SetStartLoop(CATHLRLoop * StartLoop)
{
  _StartLoop   = StartLoop;
  _CurrentLoop = StartLoop;  
  _Start         = 1;
  _CountLoops  = 1;
}

inline CATHLRLoop * CATHLRLoopIterator::GetCurrentLoop() const
{
  if (_CountLoops)
    return ( _CurrentLoop && (_Start || _CurrentLoop!=_StartLoop)) ? _CurrentLoop : 0L;
  else
    return ( _CurrentLink && (_Start || _CurrentLink!=_StartLink)) ? _CurrentLink->GetLoop() : 0L;
  /*
  if ( _CurrentLink)
    {
      return _CurrentLink->GetLoop();
    }
  return 0L;
  */
}

inline void CATHLRLoopIterator::GoToNext()
{
  /*
  if (_CurrentLink)
    {
      _CurrentLink = _CurrentLink->GetNext();
    }
    */
  if (_CountLoops)
  {
    if ( _CurrentLoop && (_Start || _CurrentLoop!=_StartLoop)) _CurrentLoop = _CurrentLoop->GetNext();
  }
  else
    if ( _CurrentLink && (_Start || _CurrentLink!=_StartLink)) _CurrentLink = _CurrentLink->GetNext();
  _Start = 0;
}

/*
inline void CATHLRLoopIterator::GoToPrevious()
{
  if (_CurrentLink)
    {
      _CurrentLink = _CurrentLink->GetPrevious();
    }
}
*/
inline void CATHLRLoopIterator::Reset()
{
  if (_CountLoops)
    _CurrentLoop = _StartLoop;
  else
    _CurrentLink = _StartLink;
  _Start       = 1;
}

#endif
