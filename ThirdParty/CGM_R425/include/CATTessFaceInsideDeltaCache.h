// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessFaceInsideDeltaCache.h
//
//===================================================================
//
// Feb 2016  Creation: TPG
//
//===================================================================
#ifndef CATTessFaceInsideDeltaCache_H
#define CATTessFaceInsideDeltaCache_H

#include "ExportedByTessellateCommon.h"
#include "CATTessDataCache.h"
#include "TessCacheObjects.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATMathInline.h"
#include "CATDataType.h"
#include "CATMapOfIntToPtr.h"
#include "CATListOfDouble.h"

class CATCGMStream;
class CATEdge;

class ExportedByTessellateCommon CATTessFaceInsideDeltaCache : public CATTessDataCache
{

public:

  CATTessFaceInsideDeltaCache ();

  ~CATTessFaceInsideDeltaCache ();

public:

  // Inside delta.
  void SetDeltaOnEdge (CATEdge& iEdge, CATListOfDouble& iDeltaParam);
  const CATListOfDouble * GetDeltaOnEdge (CATEdge& iEdge) const;
  CATBoolean IsEmpty() const;
  int DeltaCount() const;

public:

  void Stream(CATCGMStream& iStream) const;
  void UnStream(CATCGMStream& iStream);

protected:

  CATMapOfIntToPtr *_DeltaOnEdge;

};


#endif
