/* -*-C++-*-*/
#ifndef CATHLRChainCoedge_H
#define CATHLRChainCoedge_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRChainCoedge 
//
// DESCRIPTION :
/**
 * Class of links between coedges, for the HLR
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


class CATHLRCoedge;

class ExportedByHLRTopology CATHLRChainCoedge
{
public:
//=============================================================================
// METHODS TO GET THE DATAS
//=============================================================================
// Gets the next pointer on Coedge ( NULL if none)
  inline CATHLRChainCoedge * GetNext() const;

// Gets the previous one ( NULL if none)
  //inline CATHLRChainCoedge * GetPrevious() const;

// Gets the Coedge associated
  inline CATHLRCoedge * GetCoedge() const;

//=============================================================================
// SETTING THE DATAS
//=============================================================================
// Adds the CATHLRChainCoedge after the previous given. If Previous is NULL, the
// objets will be chained to no other one.
  void SetDatas(CATHLRChainCoedge * iPreviousChain, 
		CATHLRCoedge      * iPointedCoedge);

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Pointers on previous and next element chained
  //CATHLRChainCoedge * _Previous, * _Next;
  CATHLRChainCoedge * _Next;
  CATHLRCoedge      * _Coedge;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================
/*
inline CATHLRChainCoedge * CATHLRChainCoedge::GetPrevious() const
{
  return _Previous;
}
*/
inline CATHLRChainCoedge * CATHLRChainCoedge::GetNext() const
{
  return _Next;
}

inline CATHLRCoedge * CATHLRChainCoedge::GetCoedge() const
{
  return _Coedge;
}




#endif
