#ifndef IVISSG3DNODE_H
#define IVISSG3DNODE_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "IVisSGNode.h"
#include "VisSceneGraph.h"

extern ExportedByVisSceneGraph IID IID_IVisSG3DNode;

class CAT3DBoundingSphere;

/** 
 * Basic class of any 3D Scene Graph Node.
 * <b>Role</b>: This is the basic class that any 3D Scene Graph Node has to C++ derive from.
 */
class ExportedByVisSceneGraph IVisSG3DNode : public IVisSGNode
{ 
public:    

  /** 
   * Returns the bounding element of the 3D node. 
   */
  virtual HRESULT GetBoundingElement(CAT3DBoundingSphere& oBoundingSphere) const = 0;

};

#endif // IVISSG3DNODE_H
