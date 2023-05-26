#ifndef IVISSGPRIMITIVE_H
#define IVISSGPRIMITIVE_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "IVisSGObject.h"
#include "VisSceneGraph.h"

#include "VisConnectivityType.h"

class VisSGVisitor;
class VisSGPrimitiveItem;

extern ExportedByVisSceneGraph IID IID_IVisSGPrimitive;

/** 
 * Basic class of any Scene Graph Primitive.
 * <b>Role</b>: This is the basic class that any Scene Graph Primitive has to C++ derive from.
 * <br> 
 * <br><b>How to use iteration methods on items of a primitive?</b>
 * <br>
 * <br>Example : simple iteration on items of a 3D primitive
 * <br>
 * <br>HRESULT hr = E_FAIL;
 * <br>
 * <br>IVisSGObject::IVisSGIterationContext primitiveContext;
 * <br>VisPrimitiveType primItemTypes = VIS_POINTS | VIS_LINES | VIS_TRIANGLES;
 * <br>hr = pPrimitive->StartIteration(primitiveContext, primItemTypes);
 * <br>
 * <br>// iteration on primitive items of the primitive
 * <br>VisSGPrimitiveItem *primItem = NULL;
 * <br>while(SUCCEEDED(pPrimitive->GetNext(primitiveContext, primItem)) && primItem)
 * <br>{
 * <br>  // Perform any operation on primItem
 * <br>  // ...
 * <br>
 * <br>  delete primItem;
 * <br>  primItem = NULL;
 * <br>}
 * <br>
 * <br>hr = pPrimitive->EndIteration(primitiveContext);
*/


class ExportedByVisSceneGraph IVisSGPrimitive : public IVisSGObject
{  
public:
   
  /**
   * Returns the primitive identifier.
   */
  virtual HRESULT GetId(unsigned int& oID) = 0;

  /**
   * Call this method to start an iteration on all items of the primitive.
   * @param ioContext
   *   The iteration context.
   * @param handledPrimitiveItemTypes
   *   The allowed item types: the caller specifies in which types the items have to be
   * retrieved.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the iteration has successfully started
   *   <dt>Other                  <dd>If the iteration can't be executed.
   *   </dl>
   */
  virtual HRESULT StartIteration   (IVisSGIterationContext& ioContext, VisConnectivityType handledConnectivityTypes) = 0;

  /**
   * Call this method to retrieve the next item of the primitive.
   * @param ioContext
   *   The iteration context.
   * @param oItem
   *   The output primitive item: its type can be retrieved by the GetType() method 
   * associated to it.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the iteration has successfully retrieved the next item
   *   <dt>Other                  <dd>If the iteration failed for any reason.
   *   </dl>
   */
  virtual HRESULT GetNext          (IVisSGIterationContext& ioContext, VisSGPrimitiveItem * & oItem) = 0;

  /**
   * Call this method to end the previously started iteration on all items of the primitive.
   * @param ioContext
   *   The iteration context.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the iteration has successfully ended
   *   <dt>Other                  <dd>If the iteration has not successfully ended.
   *   </dl>
   */
  virtual HRESULT EndIteration     (IVisSGIterationContext& ioContext) = 0;

  /**
   * This method is called by VisSGVisitor to enable IVisSGPrimitive to declare itself.
   * By default this method calls StartDeclare / DeclareAttribute / DeclareGeometry / EndDeclare.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the declaration has successfully ended
   *   <dt>Other                  <dd>If the declaration has not successfully ended.
   *   </dl>
   */
   virtual HRESULT Accept(VisSGVisitor& iVisitor) = 0;

  /**
   * This method is called by IVisSGPrimitive in Accept method to enable IVisSGPrimitive to declare itself.
   * @param iVisitor
   *   The visitor that visits the IVisSGPrimitive.
   * @param oContinue
   *   Bypass the attribute declaration and the geometry declaration.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the declaration has successfully ended
   *   <dt>Other                  <dd>If the declaration has not successfully ended.
   *   </dl>
   */
  virtual HRESULT StartDeclare(VisSGVisitor& iVisitor, unsigned char& oContinue) = 0;

  /**
   * This method is called by IVisSGPrimitive in Accept method to enable IVisSGPrimitive to declare its attributes.
   * @param iVisitor
   *   The visitor that visits the IVisSGPrimitive.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the declaration has successfully ended
   *   <dt>Other                  <dd>If the declaration has not successfully ended.
   *   </dl>
   */
  virtual HRESULT DeclareAttribute(VisSGVisitor& iVisitor) = 0;

  /**
   * This method is called by IVisSGPrimitive in Accept method to enable IVisSGPrimitive to declare its geometry.
   * @param iVisitor
   *   The visitor that visits the IVisSGPrimitive.
   * @param oContinue
   *   Bypass the primitive geometry declaration.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the declaration has successfully ended
   *   <dt>Other                  <dd>If the declaration has not successfully ended.
   *   </dl>
   */
  virtual HRESULT DeclareGeometry(VisSGVisitor& iVisitor, unsigned char& oContinue) = 0;

  /**
   * This method is called by IVisSGPrimitive in Accept method to enable IVisSGPrimitive to declare itself.
   * @param iVisitor
   *   The visitor that visits the IVisSGPrimitive.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the declaration has successfully ended
   *   <dt>Other                  <dd>If the declaration has not successfully ended.
   *   </dl>
   */
  virtual HRESULT EndDeclare(VisSGVisitor& iVisitor) = 0;
};

#endif // IVISSGPRIMITIVE_H
