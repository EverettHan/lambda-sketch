#ifndef IVISSG3DPRIMITIVEITERATOR_H
#define IVISSG3DPRIMITIVEITERATOR_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "IVisSG3DNode.h"
#include "VisSceneGraph.h"

extern ExportedByVisSceneGraph IID IID_IVisSG3DPrimitiveIterator;

class IVisSG3DPrimitive;

/** 
 * Basic class of any 3D Scene Graph Node.
 * <b>Role</b>: This is the basic class that any 3D Scene Graph Node has to C++ derive from.
 */
class ExportedByVisSceneGraph IVisSG3DPrimitiveIterator : public IVisSG3DNode
{ 
public:    

  /**
   * The .
   */
  typedef void * IVisSGPrimitiveKey;

  /**
   * Call this method to start an iteration on all primitives attached to this node.
   * @param ioContext
   *   The iteration context.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the iteration has succeessfully started
   *   <dt>Other                  <dd>If the iteration can't be executed.
   *   </dl>
   */
  virtual HRESULT StartIterationOnPrimitives(IVisSGIterationContext& ioContext) = 0;

  /**
   * Call this method to retrieve the next primitive key.
   * @param ioContext
   *   The iteration context.
   * @param oPrimitiveKey
   *   The primitive key.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the iteration has succeessfully retrieved the next primitive key
   *   <dt>Other                  <dd>If the iteration failed for any reason.
   *   </dl>
   */
  virtual HRESULT GetNextPrimitiveKey(IVisSGIterationContext& ioContext, IVisSGPrimitiveKey& oPrimitiveKey) = 0;

  /**
   * Call this method to end the previously started iteration on all primitives attached to this node.
   * @param ioContext
   *   The iteration context.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the iteration has succeessfully ended
   *   <dt>Other                  <dd>If the iteration has not successfully ended.
   *   </dl>
   */
  virtual HRESULT EndIterationOnPrimitives(IVisSGIterationContext& ioContext) = 0;

  /**
   * Call this method to retrieve the primitive attached to this node and identified by the specified key.
   * @param iPrimitiveKey
   *   The primitive key.
   * @param opPrimitive
   *   The address where the returned pointer to the primitive is located.
   *   An AddRef is performed on the returned pointer
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the primitive has been succeessfully retrieved
   *   <dt>Other                  <dd>If primitive has not been retrieved.
   *   </dl>
   */
  virtual HRESULT GetPrimitive(const IVisSGPrimitiveKey& iPrimitiveKey, IVisSG3DPrimitive* & opPrimitive) = 0;

  /**
   * Call this method to retrieve one attribute of the primitive attached to this node and identified by the specified key.
   * @param iPrimitiveKey
   *   The primitive key.
   * @param iAttributeID
   *   The attribute identifier.
   * @param iType
   *   The type in which the attribute value has to be retrieved.
   * @param oValue
   *   The retrieved attribute value.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the attribute has been succeessfully retrieved
   *   <dt><tt>E_INVALIDARG</tt>  <dd>If the attribute doesn't exist for the primitive or can't be converted into the desired form
   *   <dt>Other                  <dd>If the attribute can't be retrieved for any other reason.
   *   </dl>
   */
  virtual HRESULT GetPrimitiveAttribute(const IVisSGPrimitiveKey& iPrimitiveKey, const VisAttributeID iAttributeID, const VisDataType iType, void *oValue) = 0;
};

#endif // IVISSG3DPRIMITIVEITERATOR_H
