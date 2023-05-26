#ifndef IVISSG2DNODEGROUP_H
#define IVISSG2DNODEGROUP_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "IVisSG2DNode.h"
#include "VisSceneGraph.h"

extern ExportedByVisSceneGraph IID IID_IVisSG2DNodeGroup;

/** 
 * Basic class of any 2D Scene Graph Node.
 * <b>Role</b>: This is the basic class that any 2D Scene Graph Node has to C++ derive from.
 */
class ExportedByVisSceneGraph IVisSG2DNodeGroup : public IVisSG2DNode
{ 
public:    

  /** 
   * Adds a child node to the group.
   * @param ipChild
   * Child node to be added.
   */
  virtual HRESULT AddChild(IVisSG2DNode* ipChild) = 0;

  /** 
   * Removes a child node from the group.
   * @param ipChild
   * Child node to be removed.
   */
  virtual HRESULT RemoveChild(IVisSG2DNode* ipChild) = 0;
};

#endif // IVISSG2DNODEGROUP_H
