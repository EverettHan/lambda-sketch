#ifndef IVisSG3DBillboard_h
#define IVisSG3DBillboard_h

// COPYRIGHT DASSAULT SYSTEMES 2011

#include "IVisSG3DNodeGroup.h"
#include "VisSceneGraph.h"

extern ExportedByVisSceneGraph IID IID_IVisSG3DBillboard;

/**
 * Scene graph node class to create billboards
 * <b>Role</b>: Scene graph node class to create billboards
 * A billboard is a node that causes its children to always "face" the viewpoint. This is
 * performed by a set of dynamic (viewpoint's dependent) rotations.
 * There are two types of billboards:
 *  - Spherical billboard nodes will cause the local z axis of its children to be aligned
 *    with the viewpoint's sight vector and the local y axis of its children to be alinged
 *    with the viewpoint's up vector.
 *  - Cylindrical billboard nodes will cause the local z axis of its children to be in
 *    the same plane of the viewpoint's sight vector by only rotating around
 *    the local y axis of its children.
 */
class ExportedByVisSceneGraph IVisSG3DBillboard : public IVisSG3DNodeGroup
{
public:
  typedef enum _VisSGBillboardType
  {
    VisSGCylindricalBillboard,
    VisSGSphericalBillboard
  } VisSGBillboardType;

  /**
   * Get the billboard type (spherical or cylindrical) of the node.
   * @param oType
   *   Type of the billboard
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>The parameter has been successfully set on node
   *   <dt>Other                  <dd>The parameter has not been set on node
   *   </dl>
   */
  virtual HRESULT GetBillboardType(VisSGBillboardType& oType) = 0;

  /**
   * Set the billboard type (spherical or cylindrical) of the node.
   * @param iType
   *   Type of the billboard (must be one of VisSGCylindricalBillboard or VisSGSphericalBillboard)
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>The parameter has been successfully set on node
   *   <dt>Other                  <dd>The parameter has not been set on node
   *   </dl>
   */
  virtual HRESULT SetBillboardType(VisSGBillboardType iType) = 0;
};

#endif  // IVisSG3DBillboard_h
