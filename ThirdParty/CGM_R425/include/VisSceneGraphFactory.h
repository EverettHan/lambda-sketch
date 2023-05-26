#ifndef VISSCENEGRAPHFACTORY_H
#define VISSCENEGRAPHFACTORY_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "VisSceneGraph.h"

#include "IUnknown.h"
#include "VisDataType.h"
#include "CATSysErrorDef.h"

class IVisSGObject;

class VisSGPrimitiveDescription;

class VisSG3DMeshDescription;
class VisSG3DPolylineDescription;
class VisSG3DPointDescription;
class VisSG2DPolylineDescription;
class VisSG2DPointDescription;

class IVisSG3DNodeGroup;
class IVisSG3DPrimitiveGroup;
class IVisSG2DNodeGroup;
class IVisSG2DPrimitiveGroup;

class IVisSGCustomPrimitive;
class IVisSGGPGPUPrimitive;

class IVisSG3DFixedSizeNodeGroup;
class IVisSG3DBillboard;

class ExportedByVisSceneGraph VisSceneGraphFactory
{
  friend class l_VisSGFactory;

public:

  /**
   * Call this method to retrieve the Scene Graph Factory instance.
   * @param opSceneGraphFactory
   *   The Scene Graph Factory instance.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If query succeeds
   *   <dt><tt>E_INVALIDARG</tt>  <dd>If the provided pointer is null
   *   <dt><tt>E_FAIL</tt>        <dd>If query fails for any other reason.
   *   </dl>
   */
  static HRESULT GetSceneGraphFactory(VisSceneGraphFactory** opSceneGraphFactory);

  /**
   * Call this method to create an empty primitive description.
   * @param opDescription
   *   The address where the returned pointer to the description is located.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the creation query succeeds
   *   <dt><tt>E_INVALIDARG</tt>  <dd>If the provided pointer is null
   *   <dt><tt>E_OUTOFMEMORY</tt> <dd>If not enough storage is available to complete the creation.
   *   </dl>
   */
  virtual HRESULT CreatePrimitiveDescription(VisSGPrimitiveDescription** opDescription) = 0;

  /**
   * Call this method to create a new Scene Graph 3D Node Group object.
   * @param opNode
   *   The address where the returned pointer to the interface is located.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the creation query succeeds
   *   <dt><tt>E_INVALIDARG</tt>  <dd>If the provided pointer is null
   *   <dt>Other                  <dd>If the creation query fails for any other reason.
   *   </dl>
   */
  virtual HRESULT CreateSG3DNodeGroup(IVisSG3DNodeGroup** opNode) = 0;

  /**
   * Call this method to create a new Scene Graph Fixed Size 3D Node Group object.
   * @param opNode
   *   The address where the returned pointer to the interface is located.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the creation query succeeds
   *   <dt><tt>E_INVALIDARG</tt>  <dd>If the provided pointer is null
   *   <dt>Other                  <dd>If the creation query fails for any other reason.
   *   </dl>
   */
  virtual HRESULT CreateSG3DFixedSizeNodeGroup(IVisSG3DFixedSizeNodeGroup** opNode) = 0;

  /**
   * Call this method to create a new Scene Graph Billboard 3D Node object.
   * @param opNode
   *  The address where the returned pointer to the interface is located.
   * @return
   *  <dl>
   *  <dt><tt>S_OK</tt>            <dd>If the creation query succeeds
   *  <dt><tt>E_IVALIDARG</tt>    <dd>If the provided pointer is null
   *  <dt>Other                    <dd>If the creation query fails for any other reason.
   *  </dl>
   */
  virtual HRESULT CreateSG3DBillboard(IVisSG3DBillboard** opBillboard) = 0;

  /**
   * Call this method to create a new Scene Graph 3D Primitive Group object.
   * @param opNode
   *   The address where the returned pointer to the interface is located.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the creation query succeeds
   *   <dt><tt>E_INVALIDARG</tt>  <dd>If the provided pointer is null
   *   <dt>Other                  <dd>If the creation query fails for any other reason.
   *   </dl>
   */
  virtual HRESULT CreateSG3DPrimitiveGroup(IVisSG3DPrimitiveGroup** opNode) = 0;

  /**
   * Call this method to create a new Scene Graph Custom Primitive object.
   * @param ipDescription
   *   The description of the Primitive object.
   * @param opPrimitive
   *   The address where the returned pointer to the interface is located.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the creation query succeeds
   *   <dt><tt>E_INVALIDARG</tt>  <dd>If the provided pointer is null
   *   <dt>Other                  <dd>If the creation query fails for any other reason.
   *   </dl>
   */
  virtual HRESULT CreateSGCustomPrimitive(VisSGPrimitiveDescription* ipDescription, IVisSGCustomPrimitive** opPrimitive) = 0;

   /**
   * Call this method to create a new Scene Graph Primitive object using GPGPU.
   * @param ipDescription
   *   The description of the Primitive object.
   * @param opPrimitive
   *   The address where the returned pointer to the interface is located.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the creation query succeeds
   *   <dt><tt>E_INVALIDARG</tt>  <dd>If the provided pointer is null
   *   <dt>Other                  <dd>If the creation query fails for any other reason.
   *   </dl>
   */
  virtual HRESULT CreateSGGPGPUPrimitive(VisSGPrimitiveDescription* ipDescription, IVisSGGPGPUPrimitive** opPrimitive) = 0;


  /**
   * Call this method to create a new Scene Graph 2D Node Group object.
   * @param opNode
   *   The address where the returned pointer to the interface is located.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the creation query succeeds
   *   <dt><tt>E_INVALIDARG</tt>  <dd>If the provided pointer is null
   *   <dt>Other                  <dd>If the creation query fails for any other reason.
   *   </dl>
   */
  virtual HRESULT CreateSG2DNodeGroup(IVisSG2DNodeGroup** opNode) = 0;

  /**
   * Call this method to create a new Scene Graph 2D Primitive Group object.
   * @param opNode
   *   The address where the returned pointer to the interface is located.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the creation query succeeds
   *   <dt><tt>E_INVALIDARG</tt>  <dd>If the provided pointer is null
   *   <dt>Other                  <dd>If the creation query fails for any other reason.
   *   </dl>
   */
  virtual HRESULT CreateSG2DPrimitiveGroup(IVisSG2DPrimitiveGroup** opNode) = 0;

  /**
   * Call this method to create a new Scene Graph object.
   * @param iIID
   *   The interface identifier for which a pointer is requested.
   * @param ipDescription
   *   The description of the Scene Graph object.
   * @param opObject
   *   The address where the returned pointer to the interface is located.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the creation query succeeds
   *   <dt><tt>E_NOINTERFACE</tt> <dd>If the interface does not exist
   *   <dt><tt>E_INVALIDARG</tt>  <dd>If the provided pointer is null
   *   <dt>Other                  <dd>If the creation query fails for any other reason.
   *   </dl>
   */
  virtual HRESULT CreateSGObject(const IID& iIID, VisSGPrimitiveDescription* ipDescription, IVisSGObject** opObject) = 0;

private:

  /**
   * Constructor.
   */
  VisSceneGraphFactory();

  /**
   * Destructor.
   */
  virtual ~VisSceneGraphFactory();

  /**
   * Copy not allowed.
   */
  VisSceneGraphFactory(const VisSceneGraphFactory&);
  VisSceneGraphFactory& operator=(const VisSceneGraphFactory&);

  static VisSceneGraphFactory* _spFactory;
};

#endif // VISSCENEGRAPHFACTORY_H
