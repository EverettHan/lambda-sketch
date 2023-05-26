#ifndef IVISSG2DNODE_H
#define IVISSG2DNODE_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "IVisSGNode.h"
#include "VisSceneGraph.h"

extern ExportedByVisSceneGraph IID IID_IVisSG2DNode;

class CAT2DBoundingBox;

/** 
 * Basic class of any 2D Scene Graph Node.
 * <b>Role</b>: This is the basic class that any 2D Scene Graph Node has to C++ derive from.
 */
class ExportedByVisSceneGraph IVisSG2DNode : public IVisSGNode
{ 
public:    

  /** 
   * Returns the bounding element of the 2D node. 
   */
  virtual HRESULT GetBoundingElement(CAT2DBoundingBox& oBoundingBox) const = 0;

};

#endif // IVISSG2DNODE_H
