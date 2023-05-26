#ifndef VISSGPRIMITIVEDESCRIPTION_H
#define VISSGPRIMITIVEDESCRIPTION_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "VisSceneGraph.h"

#include "VisDataType.h"
#include "VisConnectivityType.h"

#include "CATSysErrorDef.h"

class VisVerticesDescription;
class VisIndicesDescription;

class ExportedByVisSceneGraph VisSGPrimitiveDescription
{
public:

  /**
   * Destructor.
   */
  virtual ~VisSGPrimitiveDescription();

  virtual HRESULT SetVerticesDescription(VisVerticesDescription* ipDescription) = 0;

  virtual HRESULT GetVerticesDescription(VisVerticesDescription*& opDescription) = 0;

  virtual HRESULT StoreIndicesDescription(  VisIndicesDescription* ipDescription, 
                                            VisConnectivityType iPrimitiveType) = 0;

  virtual HRESULT GetNumberOfIndicesDescription(VisSize& oNbIndicesDescription) = 0;

  virtual HRESULT RetrieveIndicesDescription( VisSize iIndex,
                                              VisIndicesDescription*& opDescription,
                                              VisConnectivityType& oPrimitiveType) = 0;

protected:

  /**
   * Builds an empty description.
   */
  VisSGPrimitiveDescription();

private:

  VisSGPrimitiveDescription(const VisSGPrimitiveDescription&);
  VisSGPrimitiveDescription & operator=(const VisSGPrimitiveDescription&);

};

#endif // VISSGPRIMITIVEDESCRIPTION_H
