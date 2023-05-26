#ifndef VISVERTICESDESCRIPTION_H
#define VISVERTICESDESCRIPTION_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "VisCore.h"

#include "IUnknown.h"

#include "VisVertexComponent.h"
#include "VisDataType.h"

#include "CATSysErrorDef.h"

typedef enum _VisVerticesDescriptionCardinality
{
  ONE_PER_VERTEX,
  ONE_FOR_ALLVERTICES
} VisVerticesDescriptionCardinality;

class VisRawBuffer;

class ExportedByVisCore VisVerticesDescription : public IUnknown
{
public:

  /**
   * Destructor.
   */
  virtual ~VisVerticesDescription();

  virtual HRESULT SetComponent( VisVertexComponent iComponentType,
                                VisRawBuffer* ipRawBuffer,
                                VisSize iNbVertices,
                                VisSize iNbValuesPerVertex = 3,
                                VisDataType iDataFormat = VIS_FLOAT,
                                VisSize iOffset = 0,
                                VisVerticesDescriptionCardinality iCardinality = ONE_PER_VERTEX,
                                VisSize iStride = 0) = 0;

  virtual HRESULT GetNumberOfComponents(VisSize& oNbComponents) = 0;

  virtual HRESULT GetComponent( VisSize iComponentIndex, 
                                VisVertexComponent& oComponent, 
                                VisRawBuffer*& opRawBuffer,
                                VisSize& oNbVertices,
                                VisSize& oNbValuesPerVertex,
                                VisDataType& oDataFormat,
                                VisSize& oOffset,
                                VisVerticesDescriptionCardinality& oCardinality) = 0;

virtual HRESULT GetComponent( VisSize iComponentIndex, 
                                VisVertexComponent& oComponent, 
                                VisRawBuffer*& opRawBuffer,
                                VisSize& oNbVertices,
                                VisSize& oNbValuesPerVertex,
                                VisDataType& oDataFormat,
                                VisSize& oOffset,
                                VisVerticesDescriptionCardinality& oCardinality,
                                VisSize& oStride) = 0;

  virtual HRESULT GetComponentByName(VisVertexComponent iComponentIndex,                                 
                                     VisRawBuffer*& opRawBuffer,
                                     VisSize& oNbVertices,
                                     VisSize& oNbValuesPerVertex,
                                     VisDataType& oDataFormat,
                                     VisSize& oOffset,
                                     VisVerticesDescriptionCardinality& oCardinality) = 0;

  virtual HRESULT GetComponentByName( VisVertexComponent iComponentName,                                 
                                VisRawBuffer*& opRawBuffer,
                                VisSize& oNbVertices,
                                VisSize& oNbValuesPerVertex,
                                VisDataType& oDataFormat,
                                VisSize& oOffset,
                                VisVerticesDescriptionCardinality& oCardinality,
                                VisSize& oStride) = 0;

  virtual HRESULT GetComponentValue(VisSize iVertexIndex,
    VisSize iComponentIndex,
    VisDataType iType,
    void* oReturnValue) = 0;

  virtual HRESULT GetComponentCardinality(VisSize iComponentIndex,
    VisVerticesDescriptionCardinality& oCardinality) = 0;

  virtual HRESULT GetComponentNbVertices(VisSize iComponentIndex,
    VisSize& oNbVertices) = 0;

  virtual HRESULT GetComponentStride(VisSize iComponentIndex,
    VisSize& oStride) = 0;

  virtual HRESULT GetComponentIndex(VisVertexComponent iComponentName,
    VisSize& oComponentIndex) = 0;


protected:

  /**
   * Builds an empty vertices description.
   */
  VisVerticesDescription();

private:

  VisVerticesDescription(const VisVerticesDescription&);
  VisVerticesDescription & operator=(const VisVerticesDescription&);

};

#endif // VISVERTICESDESCRIPTION_H
