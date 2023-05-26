/* -*-C++-*-*/
#ifndef CATHLRChainFace_H
#define CATHLRChainFace_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRChainFace 
//
// DESCRIPTION :
/**
 *  Object that handles a chain of faces
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

class CATHLRFace;

class ExportedByHLRTopology CATHLRChainFace
{
public:
//=============================================================================
// METHODS TO GET THE DATAS
//=============================================================================
/** Gets the next pointer on Face ( NULL if none)
 */
  inline CATHLRChainFace * GetNext() const;

/** Gets the previous one ( NULL if none)
 */
//  inline CATHLRChainFace * GetPrevious() const;

/** Gets the Face associated
 */
  inline CATHLRFace * GetFace() const;

//=============================================================================
// SETTING THE DATAS
//=============================================================================
/** Adds the CATHLRChainFace after the previous given.
 *  <BR> If Previous is NULL, the objects will be chained to no other one.
 */
  void SetDatas(CATHLRChainFace * iPreviousChain, 
		CATHLRFace      * iPointedFace);

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Pointers on previous and next element chained
  //CATHLRChainFace * _Previous, * _Next;
  CATHLRChainFace * _Next;
  CATHLRFace      * _Face;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================
//inline CATHLRChainFace * CATHLRChainFace::GetPrevious() const
//{
//  return _Previous;
//}

inline CATHLRChainFace * CATHLRChainFace::GetNext() const
{
  return _Next;
}

inline CATHLRFace * CATHLRChainFace::GetFace() const
{
  return _Face;
}

#include "CATHLRMemoryManager.h"
class CATHLRMemoryManager;

class ExportedByHLRTopology CATHLRArrayFace
{
public:

  CATHLRArrayFace(CATHLRChainFace * iFirstChainFace, CATHLRMemoryManager * iManager);
  ~CATHLRArrayFace();

//=============================================================================
// METHODS TO GET THE DATAS
//=============================================================================
/** Gets the Faces
 */
  inline CATHLRFace ** GetFaces() const;

/** Gets the Size
 */
  inline unsigned int GetSize() const;

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Pointers on previous and next element chained
  unsigned int   _Size;
  CATHLRFace ** _Faces;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================

inline CATHLRFace ** CATHLRArrayFace::GetFaces() const
{
  return _Faces;
}

inline unsigned int CATHLRArrayFace::GetSize() const
{
  return _Size;
}


#endif
