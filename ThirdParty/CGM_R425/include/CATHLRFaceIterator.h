/* -*-C++-*-*/
#ifndef CATHLRFaceIterator_H
#define CATHLRFaceIterator_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRFaceIterator 
//
// DESCRIPTION :
/**
 * Iterator to sweep a list of faces
 */
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

#include "CATHLRFace.h"
#include "CATHLRChainFace.h"

class CATHLRFace;

class  CATHLRFaceIterator
{
public:
//=============================================================================
// SET AND GET METHODS
//=============================================================================
// Sets the first link of the chain
  inline void SetStartLink(CATHLRChainFace * iFirstLink);
  inline void SetStartFace(CATHLRFace      * iFirstFace);

// Gets the current Face ( NULL if the list is exhausted )
  inline CATHLRFace * GetCurrentFace() const;

// Go to the next Face
  inline void GoToNext();

// Go to the previous Face
  //inline void GoToPrevious();

// Resets the iterator: put it on the first CATHLRFace
  inline void Reset();

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
  union
  {
    CATHLRChainFace * _StartLink;
    CATHLRFace      * _StartFace;
  };
  union
  {
    CATHLRChainFace * _CurrentLink;
    CATHLRFace      * _CurrentFace;
  };
  int _Start;
  int _CountFaces;
};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================
inline void CATHLRFaceIterator::SetStartLink(CATHLRChainFace * StartLink)
{
  _StartLink   = StartLink;
  _CurrentLink = StartLink;  
  _Start       = 1;
  _CountFaces  = 0;
}

inline void CATHLRFaceIterator::SetStartFace(CATHLRFace * StartFace)
{
  _StartFace   = StartFace;
  _CurrentFace = StartFace;  
  _Start       = 1;
  _CountFaces  = 1;
}

inline CATHLRFace * CATHLRFaceIterator::GetCurrentFace() const
{
  if (_CountFaces)
    return ( _CurrentFace && (_Start || _CurrentFace!=_StartFace)) ? _CurrentFace : 0L;
  else
    return ( _CurrentLink && (_Start || _CurrentLink!=_StartLink)) ? _CurrentLink->GetFace() : 0L;
  /*
  if ( _CurrentLink)
    {
      return _CurrentLink->GetFace();
    }
  return 0L;
  */
}

inline void CATHLRFaceIterator::GoToNext()
{
  /*
  if (_CurrentLink)
    {
      _CurrentLink = _CurrentLink->GetNext();
    }
    */
  if (_CountFaces)
  {
    if ( _CurrentFace && (_Start || _CurrentFace!=_StartFace)) _CurrentFace = _CurrentFace->GetNext();
  }
  else
    if ( _CurrentLink && (_Start || _CurrentLink!=_StartLink)) _CurrentLink = _CurrentLink->GetNext();
  _Start = 0;
}
/*
inline void CATHLRFaceIterator::GoToPrevious()
{
  if (_CurrentLink)
    {
      _CurrentLink = _CurrentLink->GetPrevious();
    }
}
*/
inline void CATHLRFaceIterator::Reset()
{
  if (_CountFaces)
    _CurrentFace = _StartFace;
  else
    _CurrentLink = _StartLink;
  _Start       = 1;
}

#endif
