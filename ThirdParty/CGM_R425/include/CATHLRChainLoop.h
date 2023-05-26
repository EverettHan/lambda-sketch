/* -*-C++-*-*/
#ifndef CATHLRChainLoop_H
#define CATHLRChainLoop_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRChainLoop 
//
// DESCRIPTION :
/**
 *  Object that handles a chain of loops
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

class CATHLRLoop;

class ExportedByHLRTopology CATHLRChainLoop
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================

//=============================================================================
// METHODS TO GET THE DATAS
//=============================================================================
// Gets the next pointer on Loop ( NULL if none)
  inline CATHLRChainLoop * GetNext() const;

// Gets the previous one ( NULL if none)
  //inline CATHLRChainLoop * GetPrevious() const;

// Gets the Loop associated
  inline CATHLRLoop * GetLoop() const;

//=============================================================================
// SETTING THE DATAS
//=============================================================================
// Adds the CATHLRChainLoop after the previous given. If Previous is NULL, the
// objets will be chained to no other one.
  void SetDatas(CATHLRChainLoop * iPreviousChain, 
		CATHLRLoop      * iPointedLoop);

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Pointers on previous and next element chained
  //CATHLRChainLoop * _Previous, * _Next;
  CATHLRChainLoop * _Next;
  CATHLRLoop      * _Loop;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================
/*
inline CATHLRChainLoop * CATHLRChainLoop::GetPrevious() const
{
  return _Previous;
}
*/

inline CATHLRChainLoop * CATHLRChainLoop::GetNext() const
{
  return _Next;
}

inline CATHLRLoop * CATHLRChainLoop::GetLoop() const
{
  return _Loop;
}



#endif
