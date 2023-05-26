#ifndef IVISSGNODE_H
#define IVISSGNODE_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "IVisSGObject.h"
#include "VisSceneGraph.h"

#include "VisDataType.h"
#include "VisAttributeID.h"

class VisSGVisitor;

extern ExportedByVisSceneGraph IID IID_IVisSGNode;

/** 
 * Basic class of any Scene Graph Node.
 * <b>Role</b>: This is the basic class that any Scene Graph Node has to C++ derive from.
 * Nodes are organized into trees and possess attributes. This class defines these two behaviors.
 * <br> 
 * <br><b>How to use iteration methods?</b>
 * <br> 
 * <br>An iteration is executed in three steps: it is first initialized, then objects are retrieved
 * and, finally, it is ended.
 * <br> 
 * <br>Example : simple iteration on children attached to a node
 * <br> 
 * <br>IVisSGObject::IVisSGIterationContext IterationContext;
 * <br>if (SUCCEEDED(ipNode->StartIterationOnChildren(IterationContext)))
 * <br>{
 * <br> IVisSGNode* pChildNode = NULL;
 * <br> while (SUCCEEDED(ipNode->GetNextChild(IterationContext, pChildNode)) && pChildNode)
 * <br> {
 * <br>   // Perform any operation using pChildNode
 * <br>
 * <br>   pChildNode->Release();
 * <br>   pChildNode = NULL;
 * <br> }
 * <br>
 * <br> ipNode->EndIterationOnChildren(IterationContext);
 * <br>}
 * <br> 
 * <br><b>How to use methods to set or retrieve attributes?</b>
 * <br> 
 * <br>All attributes are defined by a key (for example, VIS_RGBA_COLOR represents the R,G,B,A color
 * of a node) and stored on the node object. The caller specifies in which form an attribute has to be
 * retrieved.
 * <br> 
 * <br>Example : retrieval of the node RGBA color
 * <br> 
 * <br>Let's first assume that the node RGBA color is an opaque white, stored as int values : 
 * R=255, G=255, B=255, A=0. This example shows how the color attribute can be retrieved as int values
 * or float values.
 * <br> 
 * <br>int iRGBAColor[4]={0, 0, 0, 0};
 * <br>if (SUCCEEDED(ipNode->GetAttribute(VIS_RGBA_COLOR, VIS_INT_4, &iRGBAColor)))
 * <br>{
 * <br> // iRGBAColor contains the values {255, 255, 255, 0}
 * <br>}
 * <br>float fRGBAColor[4]={0.0f, 0.0f, 0.0f, 0.0f};
 * <br>if (SUCCEEDED(ipNode->GetAttribute(VIS_RGBA_COLOR, VIS_FLOAT_4, &fRGBAColor)))
 * <br>{
 * <br> // fRGBAColor contains the values {1.0f, 1.0f, 1.0f, 0}
 * <br>}
*/
class ExportedByVisSceneGraph IVisSGNode : public IVisSGObject
{  
public:

  /**
   * Call this method to start an iteration on all children nodes attached to this node.
   * @param ioContext
   *   The iteration context.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the iteration has successfully started
   *   <dt>Other                  <dd>If the iteration can't be executed.
   *   </dl>
   */
  virtual HRESULT StartIterationOnChildren(IVisSGIterationContext& ioContext) = 0;

  /**
   * Call this method to retrieve the next child node attached to this node.
   * @param ioContext
   *   The iteration context.
   * @param opChildNode
   *   The address where the returned pointer to the child node is located.
   *   An AddRef is performed on the returned pointer
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the iteration has successfully retrieved the next child node
   *   <dt>Other                  <dd>If the iteration failed for any reason.
   *   </dl>
   */
  virtual HRESULT GetNextChild(IVisSGIterationContext& ioContext, IVisSGNode* & opChildNode) = 0;

  /**
   * Call this method to end the previously started iteration on all children nodes attached to this node.
   * @param ioContext
   *   The iteration context.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the iteration has successfully ended
   *   <dt>Other                  <dd>If the iteration has not successfully ended.
   *   </dl>
   */
  virtual HRESULT EndIterationOnChildren(IVisSGIterationContext& ioContext) = 0;

  /**
   * Call this method to start an iteration on all parent nodes attached to this node.
   * @param ioContext
   *   The iteration context.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the iteration has successfully started
   *   <dt>Other                  <dd>If the iteration can't be executed.
   *   </dl>
   */
  virtual HRESULT StartIterationOnParents(IVisSGIterationContext& ioContext) = 0;

  /**
   * Call this method to retrieve the next parent node attached to this node.
   * @param ioContext
   *   The iteration context.
   * @param opChildNode
   *   The address where the returned pointer to the parent node is located.
   *   An AddRef is performed on the returned pointer
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the iteration has successfully retrieved the next parent node
   *   <dt>Other                  <dd>If the iteration failed for any reason.
   *   </dl>
   */
  virtual HRESULT GetNextParent(IVisSGIterationContext& ioContext, IVisSGNode* & opParentNode) = 0;

  /**
   * Call this method to end the previously started iteration on all parent nodes attached to this node.
   * @param ioContext
   *   The iteration context.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the iteration has successfully ended
   *   <dt>Other                  <dd>If the iteration has not successfully ended.
   *   </dl>
   */
  virtual HRESULT EndIterationOnParents(IVisSGIterationContext& ioContext) = 0;

  /**
   * Call this method to retrieve one of the node attributes.
   * @param iAttributeID
   *   The attribute identifier.
   * @param iType
   *   The type in which the attribute value has to be retrieved.
   * @param oValue
   *   The retrieved attribute value.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the attribute has been successfully retrieved
   *   <dt><tt>E_INVALIDARG</tt>  <dd>If the attribute doesn't exist for the node or can't be converted into the desired form
   *   <dt>Other                  <dd>If the attribute can't be retrieved for any other reason.
   *   </dl>
   */
  virtual HRESULT GetNodeAttribute(const VisAttributeID iAttributeID, const VisDataType iType, void *oValue) = 0;

  /**
   * Call this method to set one of the node attributes.
   * @param iAttributeID
   *   The attribute identifier.
   * @param iType
   *   The type in which the attribute value is specified.
   * @param iValue
   *   The attribute value to set.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the attribute has been successfully set
   *   <dt><tt>E_INVALIDARG</tt>  <dd>If the attribute doesn't exist for the node or can't be converted from the specified form
   *   <dt>Other                  <dd>If the attribute can't be set for any other reason.
   *   </dl>
   */
  virtual HRESULT SetNodeAttribute(const VisAttributeID iAttributeID, const VisDataType iType, void *iValue) = 0;

  /**
   * This method is called by VisSGVisitor to enable IVisSGNode to declare itself.
   * By default this method calls StartDeclare / DeclareAttribute / DeclareGeometry / EndDeclare.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the declaration has successfully ended
   *   <dt>Other                  <dd>If the declaration has not successfully ended.
   *   </dl>
   */
   virtual HRESULT Accept(VisSGVisitor& iVisitor) = 0;
};

#endif 
