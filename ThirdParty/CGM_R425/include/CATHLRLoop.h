/* -*-C++-*-*/
#ifndef CATHLRLoop_H
#define CATHLRLoop_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRLoop 
//
// DESCRIPTION :
/**
 * Loop on a face, for the HLR
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

class CATHLRChainCoedge;
class CATHLRCoedge;
class CATHLRCoedgeIterator;

class ExportedByHLRTopology CATHLRLoop
{
public:
//=============================================================================
// CONSTRUCTOR
//=============================================================================
/** Default constructor
 */
  CATHLRLoop();

//=============================================================================
// METHODS
//=============================================================================
/** Gets all the coedges of the edge. This method initialized an iterator.
 */
  void GetCoedges(CATHLRCoedgeIterator & oInitializedIterator);

//=============================================================================
// METHODS TO SET THE DATAS
//=============================================================================
// Sets the first chain
  //void SetFirstChain(CATHLRChainCoedge * iFirstChain);

/** Adds a coedge at the end of the loop. The CATHLRChainCoedge to chain them
 * must also be provided.
 */
  void AddCoedge(CATHLRCoedge      * iCoedge);
  //void AddCoedge(CATHLRCoedge      * iCoedge,
	//	 CATHLRChainCoedge * iLink);

  inline CATHLRLoop * GetNext() const;
  inline void SetNext(CATHLRLoop * iLoop);

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
  CATHLRLoop   * _Next;

// First chain of coedges
  //CATHLRChainCoedge * _FirstChain;
  CATHLRCoedge * _FirstChain;
  //CATHLRChainCoedge * _CurrentEnd;
};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================

//-----------------------------------------------------------------------------

inline CATHLRLoop * CATHLRLoop::GetNext() const
{
  return _Next;
}

//-----------------------------------------------------------------------------

inline void CATHLRLoop::SetNext(CATHLRLoop * iLoop)
{
  if (iLoop) iLoop->_Next = _Next;
  _Next = iLoop;
}

//-----------------------------------------------------------------------------

#endif
