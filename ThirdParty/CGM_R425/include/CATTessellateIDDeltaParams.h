// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessellateIDDeltaParams
//
//===================================================================
//
// June 2013  Creation: TPG
//===================================================================
#ifndef CATTessellateIDDeltaParams_H
#define CATTessellateIDDeltaParams_H

#include "ExportedByTessellateCommon.h"
#include "CATCGMTessellateID.h"
#include "CATListOfDouble.h"
#include "CATBoolean.h"

class ExportedByTessellateCommon CATTessellateIDDeltaParams: public CATCGMTessellateID
{
public:
  CATTessellateIDDeltaParams(const void* iCachePtr, int iOrientation, CATListOfDouble * iListOfDeltaParams);
  CATTessellateIDDeltaParams(const CATTessellateIDDeltaParams& iRHS);

  ~CATTessellateIDDeltaParams();

public:
  CATCGMTessellateID& operator = (const CATCGMTessellateID& iRHS);
  CATTessellateIDDeltaParams& operator = (const CATTessellateIDDeltaParams& iRHS);
  int operator == (const CATCGMTessellateID& iRHS) const;
  int operator != (const CATCGMTessellateID& iRHS) const;
  int operator < (const CATCGMTessellateID& iRHS) const;
  CATBoolean AreSettingsEqual(const CATCGMTessellateID& iRHS) const;

  inline CATBoolean HasDelta() const;
  inline int GetOrientation() const;
  inline const void* GetCachePtr() const;

protected:
  const void* _CachePtr;
  int _Orientation; // only for contextual comparison, 0 by default
  CATListOfDouble * _ListOfDeltaParams;
};

inline CATBoolean CATTessellateIDDeltaParams::HasDelta() const
{
  if (_ListOfDeltaParams && _ListOfDeltaParams->Size()>0)
	return TRUE;
  return FALSE;
}

inline int CATTessellateIDDeltaParams::GetOrientation() const
{
  return _Orientation;
}

inline const void* CATTessellateIDDeltaParams::GetCachePtr() const
{
  return _CachePtr;
}

#endif // CATTessellateIDDeltaParams_H

