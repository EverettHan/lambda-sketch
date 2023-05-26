#ifndef IVISSG3DNODEGROUP_H
#define IVISSG3DNODEGROUP_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "IVisSG3DNode.h"
#include "VisSceneGraph.h"

extern ExportedByVisSceneGraph IID IID_IVisSG3DNodeGroup;

/** 
 * Basic class of any 3D Scene Graph Node.
 * <b>Role</b>: This is the basic class that any 3D Scene Graph Node has to C++ derive from.
 */
class ExportedByVisSceneGraph IVisSG3DNodeGroup : public IVisSG3DNode
{ 
public:    

  /** 
   * Adds a child node to the group.
   * @param ipChild
   * Child node to be added.
   */
  virtual HRESULT AddChild(IVisSG3DNode* ipChild) = 0;

  /** 
   * Removes a child node from the group.
   * @param ipChild
   * Child node to be removed.
   */
  virtual HRESULT RemoveChild(IVisSG3DNode* ipChild) = 0;

};

#endif // IVISSG3DNODEGROUP_H
