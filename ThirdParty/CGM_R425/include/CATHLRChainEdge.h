/* -*-C++-*-*/
#ifndef CATHLRChainEdge_H
#define CATHLRChainEdge_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRChainEdge 
//
// DESCRIPTION :
/**
 *  Object that handles a chain of edges
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

class CATHLREdge;

class ExportedByHLRTopology CATHLRChainEdge
{
public:
//=============================================================================
// METHODS TO GET THE DATAS
//=============================================================================
/** Gets the next pointer on Edge ( NULL if none)
 */
  inline CATHLRChainEdge * GetNext() const;

/** Gets the previous one ( NULL if none)
 */
  //inline CATHLRChainEdge * GetPrevious() const;

/** Gets the Edge associated
 */
  inline CATHLREdge * GetEdge() const;

//=============================================================================
// SETTING THE DATAS
//=============================================================================
/** Adds the CATHLRChainEdge after the previous given.
 *  <BR> If Previous is NULL, the objects will be chained to no other one.
 */
  void SetDatas(CATHLRChainEdge * iPreviousChain, 
		CATHLREdge      * iPointedEdge);

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Pointers on previous and next element chained
  //CATHLRChainEdge * _Previous, * _Next;
  CATHLRChainEdge * _Next;
  CATHLREdge      * _Edge;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================
/*
inline CATHLRChainEdge * CATHLRChainEdge::GetPrevious() const
{
  return _Previous;
}
*/
inline CATHLRChainEdge * CATHLRChainEdge::GetNext() const
{
  return _Next;
}

inline CATHLREdge * CATHLRChainEdge::GetEdge() const
{
  return _Edge;
}




#endif
