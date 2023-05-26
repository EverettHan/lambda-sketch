// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVizContainerFiller.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// August 2008  Creation: NDO
//===================================================================
#ifndef CATPolyVizContainerFiller_H
#define CATPolyVizContainerFiller_H

#include "PolyVizLayers.h"
#include "CATErrorDef.h"

class CATPolyVizContainer;
class CAT3DRep;


// Fills a CATPolyVizContainer with the GP's contained in a rep.
class ExportedByPolyVizLayers CATPolyVizContainerFiller
{

public:

  CATPolyVizContainerFiller () {}
  ~CATPolyVizContainerFiller () {}

public:

  HRESULT Fill (const CAT3DRep& iRep, CATPolyVizContainer& iVizContainer) const;

};

#endif
