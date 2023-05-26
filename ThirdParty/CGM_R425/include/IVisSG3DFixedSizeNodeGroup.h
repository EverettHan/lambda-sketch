#ifndef IVisSG3DFixedSizeNodeGroup_H
#define IVisSG3DFixedSizeNodeGroup_H

// COPYRIGHT DASSAULT SYSTEMES 2011

#include "IVisSG3DNodeGroup.h"
#include "VisSceneGraph.h"

extern ExportedByVisSceneGraph IID IID_IVisSG3DFixedSizeNodeGroup;

/**
 * Basic class of any 3D Scene Fixed Size Graph Group Node.
 * <b>Role</b>: This is the basic class that any 3D Scene Fixed Size Graph Group Node has to C++ derive from.
 * The geometry agregated by this node will display itself so that it's screen space size will be kept fixed to size defined by the model.
 * This is performed through the computation of a dynamic (viewpoint's dependant) homothety whose invariant point can be
 * specified though SetCustomInvariantPoint() method.
 * If no custom invariant has been explicitly set, the node BE's center will be used as invariant point.
 */
class ExportedByVisSceneGraph IVisSG3DFixedSizeNodeGroup : public IVisSG3DNodeGroup
{
public:

  /**
   * Set the scale factor to be applied when model is displayed in fixed screen size.
   * @param iRatio
   *   Scale factor to make model bigger or smaller on screen. (Can't be 0.f)
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>The parameter has been successfully set on node
   *   <dt><tt>E_INVALIDARG</tt>  <dd>iRatio is 0.f. It will not be set on the node.
   *   <dt>Other                  <dd>The parameter has not been set on node 
   *   </dl>
   */
  virtual HRESULT SetScaleFactor(float iRatio) = 0;

  /**
   * Get the scale factor to be applied when model is displayed in fixed screen size.
   * @param oRatio
   *   Scale factor to make model bigger or smaller on screen. (1.f by default)
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>The parameter has been successfully get from node
   *   <dt>Other                  <dd>Any other case
   *   </dl>
   */
  virtual HRESULT GetScaleFactor(float& oRatio) = 0;

  /**
   * @nodoc
   * @deprecated R425: The name was misleading. Use @SetScaleFactor with same argument. Call is redirected to @SetScaleFactor. 
   */
  virtual HRESULT SetUnitFixedSize(float iFixedSize) = 0;

  /**
   * @nodoc
   * @deprecated R425: Range is no more supported. Stop using this function.
   * @return
   *   <dl>
   *   <dt><tt>E_NOTIMPL</tt>  <dd>Always returns this error.
   *   </dl>
   */
  virtual HRESULT SetUnitFixedSizeRange(float iMinSize, float iMaxSize) = 0;

  /**
   * @nodoc
   * @deprecated R425: Range is no more supported. Stop using this function.
   * @return
   *   <dl>
   *   <dt><tt>E_NOTIMPL</tt>  <dd>Always returns this error.
   *   </dl>
   */
  virtual HRESULT GetUnitFixedSizeRange(float& oMinSize, float& oMaxSize) = 0;

  /**
   * Set the coordinate point (in local space) which is invariant whatever the zoom is.
   * @param iInvariantPoint
   * Coordinates of the point (in local space) which has to be invariant.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>The custom invariant point has been successfully set on node
   *   <dt>Other                  <dd>The custom invariant point has not been set on node
   *   </dl>
   */
  virtual HRESULT SetCustomInvariantPoint(const float iInvariantPoint[3]) = 0;

  /**
   * Resets the effect of @SetCustomInvariantPoint so that bounding sphere center will be used as invarient point.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>The custom invariant point is reset to bounding sphere center
   *   <dt><tt>S_FALSE</tt>       <dd>The custom invariant point was never set so this call doesn't have any effect
   *   <dt>Other                  <dd>Any other error which prevented the function to execute correctly
   *   </dl>
   */
  virtual HRESULT ResetCustomInvariantPoint() = 0;

  /**
   * Get the coordinate point (in local space) which is invariant whatever the zoom is.
   * @param oInvariantPoint
   * Coordinates of the point (in local space) which is invariant.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>The custom invariant point has been successfully fetched from node
   *   <dt><tt>S_FALSE</tt>       <dd>The custom invariant point was never set or @ResetCustomInvariantPoint is called. The node's BE center is the invariant point.
   *   <dt>Other                  <dd>Any other error which prevented the function to execute correctly
   *   </dl>
   */
  virtual HRESULT GetCustomInvariantPoint(float oInvariantPoint[3]) = 0;

};

#endif // IVisSG3DFixedSizeNodeGroup_H
