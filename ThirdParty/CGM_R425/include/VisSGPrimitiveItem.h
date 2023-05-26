#ifndef IVISSGPRIMITIVEITEM_H
#define IVISSGPRIMITIVEITEM_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "IVisSGObject.h"
#include "VisSceneGraph.h"

#include "VisDataType.h"
#include "VisVertexComponent.h"
#include "VisConnectivityType.h"

/** 
 * interface for primitive item concept.
 * <b>Role</b>: Provides services to retrieve the content of a primitive item.
 */

class ExportedByVisSceneGraph VisSGPrimitiveItem
{
  friend class VisGPGPUPrimitiveIVisSGGPGPUPrimitiveBOAImpl;
  friend class VisPrimitiveIVisSGPrimitiveBOAImpl;
  friend class CATViz3DMarkerIVisSG3DPointBOAImpl;
  friend class CATVizUV3DMarkerIVisSG3DPointBOAImpl;
  friend class CAT3DMarkerGPIVisSG3DPointBOAImpl;
  friend class CAT3DEdgeGPIVisSG3DPolylineBOAImpl;
  friend class CAT3DIndexedLineGPIVisSG3DPolylineBOAImpl;
  friend class CAT3DLineGPIVisSG3DPolylineBOAImpl;
  friend class CATViz3DEdgeIVisSG3DPolylineBOAImpl;
  friend class CATVizUV3DEdgeIVisSG3DPolylineBOAImpl;
  friend class CATViz3DLineIVisSG3DPolylineBOAImpl;
  friend class CATVizUV3DLineIVisSG3DPolylineBOAImpl;
	friend class CAT3DBoundingGPIVisSG3DMeshBOAImpl;
  friend class CAT3DFaceGPIVisSG3DFaceBOAImpl;
  friend class CATViz3DFaceIVisSG3DFaceBOAImpl;
  friend class CATVizUV3DFaceIVisSG3DFaceBOAImpl;
	friend class CATCustomGraphicPrimitiveIVisSGCustomPrimitiveBOAImpl;
  friend class CATCustomGraphicPrimitiveIVisSGCustomPrimitiveBOAImpl;
  friend class CAT3DAnnotationTextGPIVisSG3DPrimitiveBOAImpl;
  friend class CAT3DArcEllipseGPIVisSG3DPrimitiveBOAImpl;
  friend class CAT3DArrowGPIVisSG3DPrimitiveBOAImpl;
  friend class CAT3DFixedArrowGPIVisSG3DPrimitiveBOAImpl;
  friend class CATViz3DFixedPlanIVisSG3DPrimitiveBOAImpl;
  friend class CATVizIndexed3DMarkerIVisSG3DPointBOAImpl;
  friend class CAT3DLightSourceGPIVisSG3DPrimitiveBOAImpl;

public:

  /**
   * Destructor.
   */
  virtual ~VisSGPrimitiveItem();

  /**
   * Call this method to retrieve the connectivity type of the primitive item.
   * @return
   *   <dl>
   *   <dt><tt>VIS_POINTS</tt>          <dd> the primitive item is a set of points
   *   <dt><tt>VIS_LINES</tt>           <dd> the primitive item is a set of independant lines
   *   <dt><tt>VIS_LINE_STRIP</tt>      <dd> the primitive item is a line strip
   *   <dt><tt>VIS_LINE_LOOP</tt>       <dd> the primitive item is a line loop
   *   <dt><tt>VIS_TRIANGLES</tt>       <dd> the primitive item is a set of independant triangles
   *   <dt><tt>VIS_TRIANGLE_STRIP</tt>  <dd> the primitive item is a triangle strip
   *   <dt><tt>VIS_TRIANGLE_FAN</tt>    <dd> the primitive item is a triangle fan
   *   </dl>
   */
  virtual VisConnectivityType GetConnectivityType() = 0;

  /**
   * Call this method to retrieve the number of vertices of the primitive item.
   * @return the number of vertices of the primitive item
   */
  virtual VisSize GetNumberOfVertices() = 0;

  /**
   * Call this method to retrieve components of a vertex of the primtive item.
   * @param iIndex
   *   The index of the vertex in the primitive item ranging from 0 to @href GetNumberOfVertices() - 1.
   * @param iComponantType
   *   The component to be retrieved
   * @param iType
   *   The type in which the return value has to be formated
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the creation query succeeds
   *   <dt><tt>E_INVALIDARG</tt>  <dd>If one of the provided argument is invalid
   *   <dt><tt>E_INVALIDTYPE</tt>  <dd>If the input type does not match the requested vertex component
   *   <dt><tt>E_COMPONENT_UNDEFINED</tt>  <dd>If the vertex definition does not include such a component
   *   </dl>
   */
  virtual HRESULT FASTCALL GetVertexComponent(VisSize iVertexIndex, VisVertexComponent iComponent, VisDataType iType, void *oReturnValue) = 0;

protected:

  /**
   * Builds an empty primitive item.
   */
  VisSGPrimitiveItem();

  virtual HRESULT GetVisDataTypeComponent(VisVertexComponent iComponent, VisDataType& oType);

private:

  VisSGPrimitiveItem(const VisSGPrimitiveItem&);
  VisSGPrimitiveItem & operator=(const VisSGPrimitiveItem&);

};

#endif
