#ifndef IVISSG2DPRIMITIVEITERATOR_H
#define IVISSG2DPRIMITIVEITERATOR_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "IVisSG2DNode.h"
#include "VisSceneGraph.h"

extern ExportedByVisSceneGraph IID IID_IVisSG2DPrimitiveIterator;

class IVisSG2DPrimitive;
class CATGraphicAttributeSet;

/** 
 * Basic class of any 2D Scene Graph Node.
 * <b>Role</b>: This is the basic class that any 2D Scene Graph Node has to C++ derive from.
 */
class ExportedByVisSceneGraph IVisSG2DPrimitiveIterator : public IVisSG2DNode
{ 
public:    

  /**
   * Browses the primitives
   */
  virtual HRESULT StartIteration(IVisSGIterationContext& ioContext) = 0;
  virtual HRESULT GetNext(IVisSGIterationContext& ioContext) = 0;
  virtual HRESULT EndIteration(IVisSGIterationContext& ioContext) = 0;

  /**
   * Returns a primitive.
   */
  virtual HRESULT GetPrimitive(const IVisSGIterationContext& iContext, IVisSG2DPrimitive** opPrimitive) = 0;

  /**
   * Retrieves attributes associated to the primitive.
   */
  virtual HRESULT GetAttribute(const IVisSGIterationContext& iContext, const VisAttributeID iAttributeID, const VisDataType iType, void *oValue) = 0;
};

#endif // IVISSG2DPRIMITIVEITERATOR_H
