#ifndef IVISSG2DPRIMITIVEGROUP_H
#define IVISSG2DPRIMITIVEGROUP_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "IVisSG2DPrimitiveIterator.h"
#include "VisSceneGraph.h"

extern ExportedByVisSceneGraph IID IID_IVisSG2DPrimitiveGroup;

class IVisSG2DPrimitive;
class CATGraphicAttributeSet;

/** 
 * Basic class of any 2D Scene Graph Node.
 * <b>Role</b>: This is the basic class that any 2D Scene Graph Node has to C++ derive from.
 */
class ExportedByVisSceneGraph IVisSG2DPrimitiveGroup : public IVisSG2DPrimitiveIterator
{ 
public:    


  /** 
   * Adds a primitive to this node.
   * @param ip2DPrimitive
   *  Primitive to be added.
   * @param iAttribute
   *  Graphical attributes associated to the primitive.
   */
  virtual HRESULT AddPrimitive(IVisSG2DPrimitive* ip2DPrimitive, const CATGraphicAttributeSet& iAttribute) = 0;

  /** 
   * Removes a primitive from this node.
   * @param ip2DPrimitive
   *  Primitive to be removed.
   */
  virtual HRESULT RemovePrimitive(IVisSG2DPrimitive* ip2DPrimitive) = 0;

  /** 
   * Sets the bounding element of the 2D node. 
   */
  virtual HRESULT SetBoundingElement(CAT2DBoundingBox& iBoundingBox) = 0;
};

#endif // IVISSG2DPRIMITIVEGROUP_H
