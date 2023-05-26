#ifndef IVISPRIMITIVEITEM_H
#define IVISPRIMITIVEITEM_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "SGInfra.h"
#include "VisSGPrimitiveItem.h"
#include "VisDataType.h"
#include "VisVertexComponent.h"
#include "VisConnectivityType.h"
#include "CATVizAllocator.h"

class VisIndicesDescription;
class VisVerticesDescription;
class l_VisVerticesDescription;
class VisRawBuffer;


class ExportedBySGInfra VisPrimitiveItem : public VisSGPrimitiveItem
{
public:
  
  /**
   * Constructor.
   */
  VisPrimitiveItem(VisIndicesDescription *iIndicesDescription, VisVerticesDescription *iVerticesDescription, VisConnectivityType iConnectivity);

  /**
   * Destructor.
   */
  virtual ~VisPrimitiveItem();

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
  virtual VisConnectivityType GetConnectivityType();

  /**
   * Call this method to retrieve the number of vertices of the primitive item.
   * @return the number of vertices of the primitive item
   */
  virtual VisSize GetNumberOfVertices();

  /**
   * Call this method to retrieve components of a vertex of the primtive item.
   * @param iVertexIndex
   *   The index of the vertex in the primitive item ranging from 0 to @href GetNumberOfVertices() - 1.
   * @param iComponentName
   *   The component enum type to be retrieved
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
  virtual HRESULT FASTCALL GetVertexComponent(VisSize iVertexIndex, VisVertexComponent iComponentName, VisDataType iType, void *oReturnValue);

  CATVizDeclareVolatileObject(VisPrimitiveItem);

protected:

  virtual HRESULT GetVisDataTypeComponent(VisVertexComponent iComponent, VisDataType& oType);

private:
 
  VisSize                           _nbIndices;
  VisSize                           _indicesOffset;
  VisDataType                       _indicesDataType;
  VisConnectivityType               _connectivity;
  unsigned int                      _arrayLengthOfRestartIndices;
  unsigned int                     *_arrayOfRestartIndices;
  VisRawBuffer                     *_pIndicesBuffer;
  l_VisVerticesDescription         *_pVerticesDescription;

};

#endif
