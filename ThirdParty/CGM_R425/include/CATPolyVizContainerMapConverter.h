// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVizContainerMapConverter.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// August 2008  Creation: NDO
//===================================================================
#ifndef CATPolyVizContainerMapConverter_H
#define CATPolyVizContainerMapConverter_H

#include "PolyVizLayers.h"
#include "CATErrorDef.h"

class CATPolyVizContainer;
class CATMapOfPtrToPtr;
class CATMapOfPtrToInt;


// Utilities to convert maps of pointers to GPs or Viz Keys. 
class ExportedByPolyVizLayers CATPolyVizContainerMapConverter
{

public:

  CATPolyVizContainerMapConverter () {}
  ~CATPolyVizContainerMapConverter () {}

public:

  // Convert a map of pointers to GPs into a map of pointers to Viz IDs as obtained from the Viz container.
  static HRESULT Convert (const CATPolyVizContainer& iVizContainer,
                          const CATMapOfPtrToPtr& iMapPtrToGP, CATMapOfPtrToInt& oMapPtrToVizID);

  // Convert a map of pointers to Viz IDs as obtained from the Viz container into a map of pointer to GPs.
  static HRESULT Convert (const CATPolyVizContainer& iVizContainer,
                          const CATMapOfPtrToInt& iMapPtrToVizID, CATMapOfPtrToPtr& oMapPtrToGP);

};

#endif
