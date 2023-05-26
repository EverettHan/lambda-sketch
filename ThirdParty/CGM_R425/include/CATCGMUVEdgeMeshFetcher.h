// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVEdgeMeshFetcher.h
//
//===================================================================
//
// Usage notes: 
//              
//===================================================================
//
// Dec 2011  Creation: MPX
//===================================================================

#ifndef CATCGMUVEdgeMeshFetcher_H
#define CATCGMUVEdgeMeshFetcher_H

#include "ExportedByTessellateCommon.h"

class CATEdge;
class CATCGMUVEdgeMeshBasicItf;

class ExportedByTessellateCommon CATCGMUVEdgeMeshFetcher
{
public:

  // Returns mesh for the given edge, if found, otherwise NULL
  // Remember to delete returned object after use.
  virtual CATCGMUVEdgeMeshBasicItf* GetMesh(CATEdge& iEdge) const = 0;

public:
  virtual ~CATCGMUVEdgeMeshFetcher();
};

#endif
