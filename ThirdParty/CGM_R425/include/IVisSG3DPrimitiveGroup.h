#ifndef IVISSG3DPRIMITIVEGROUP_H
#define IVISSG3DPRIMITIVEGROUP_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "IVisSG3DPrimitiveIterator.h"
#include "VisSceneGraph.h"

extern ExportedByVisSceneGraph IID IID_IVisSG3DPrimitiveGroup;

class IVisSG3DPrimitive;

/** 
 * Basic class of any 3D Scene Graph Node.
 * <b>Role</b>: This is the basic class that any 3D Scene Graph Node has to C++ derive from.
 */
class ExportedByVisSceneGraph IVisSG3DPrimitiveGroup : public IVisSG3DPrimitiveIterator
{ 
public:    


  /** 
   * Adds a primitive to this node.
   * @param ip3DPrimitive
   *  Primitive to be added.
   * @param iAttribute
   *  Graphical attributes associated to the primitive.
   */
  virtual HRESULT AddPrimitive(IVisSG3DPrimitive* ip3DPrimitive, IVisSGPrimitiveKey& oPrimitiveKey) = 0;

  /**
   * Sets attributes associated to a primitive.
   */
  virtual HRESULT SetPrimitiveAttribute(const IVisSGPrimitiveKey& iPrimitiveKey, const VisAttributeID iAttributeID, const VisDataType iType, void *iValue) = 0;

  /** 
   * Removes a primitive from this node.
   * @param ip3DPrimitive
   *  Primitive to be removed.
   */
  virtual HRESULT RemovePrimitive(IVisSG3DPrimitive* ip3DPrimitive) = 0;

  /** 
   * Sets the bounding element of the 3D node. 
   */
  virtual HRESULT SetBoundingElement(CAT3DBoundingSphere& iBoundingSphere) = 0;
};

#endif // IVISSG3DPRIMITIVEGROUP_H
