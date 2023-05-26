// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATDecodeRepPathFromIDs.h
// Header definition of CATDecodeRepPathFromIDs
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Apr 2003  Creation: Code generated by the CAA wizard  jut
//===================================================================
#ifndef CATCreatePathElementFromIDs_H
#define CATCreatePathElementFromIDs_H

#include "SceneGraphManager.h"
#include "CATErrorDef.h"

class CATPathElement;
class CATRep;

// Decodes a rep path from an input list of ids
// The input list might have holes.
extern ExportedBySceneGraphManager HRESULT CATCreatePathElementFromIDs(CATPathElement & ioPathElement, CATRep & iRep, unsigned long * repIDs, unsigned int nbRepIDs, unsigned long * gpIDs, unsigned int nbGPIds);

#endif