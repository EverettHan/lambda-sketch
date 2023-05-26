// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVizContainer.h
// Header definition of CATPolyVizContainer
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// March 2008  Creation: NDO
//===================================================================
#ifndef CATPolyVizContainer_H
#define CATPolyVizContainer_H

#include "PolyVizLayers.h"
#include "CATPolyRefCounted.h"
#include "CATListPV.h"
#include "CATErrorDef.h"

class CAT3DRep;
class CATGraphicPrimitive;
class CATHashTable;
class CATCGMOutput;


class ExportedByPolyVizLayers CATPolyVizContainer : public CATPolyRefCounted
{

public:

  CATPolyVizContainer (const int iEstimatedSize = 0);

  ~CATPolyVizContainer ();

public:

  // Add a support and return a unique key.
  HRESULT Add (const CAT3DRep* iRep, const CATGraphicPrimitive* iGP, unsigned int& oKey);

  // Remove a support.
  HRESULT Remove (const CATGraphicPrimitive* iGP);

  // Return the key of the support or 0 if no support is found.
  unsigned int Locate (const CATGraphicPrimitive* iGP) const;

  // Given a key, return the support.
  HRESULT Get (const unsigned int iKey, const CAT3DRep*& oRep, const CATGraphicPrimitive*& oGP) const;

  // Given a key, replace the rep and the GP associated to the key.
  HRESULT Update (const unsigned int iKey, const CAT3DRep* iRep, const CATGraphicPrimitive* iGP);

  const CATGraphicPrimitive* GetGraphicPrimitive (const unsigned int iKey) const;

public:

  inline unsigned int GetMinimumKey () const;
  inline unsigned int GetMaximumKey () const;

  int GetNbSupports () const;

public:

  // For debugging purpose.
  void Print (CATCGMOutput& stream) const;

private:

  CATListPV _SupportAndKeyList;
  CATHashTable* _HashTable;

};

inline unsigned int CATPolyVizContainer::GetMinimumKey () const
{
  return 1;
}

inline unsigned int CATPolyVizContainer::GetMaximumKey () const
{
  return _SupportAndKeyList.Size ();
}

#endif
