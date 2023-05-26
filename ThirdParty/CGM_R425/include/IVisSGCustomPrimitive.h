#ifndef IVISSGCUSTOMPRIMITIVE_H
#define IVISSGCUSTOMPRIMITIVE_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "IVisSGTessellatedPrimitive.h"
#include "VisSceneGraph.h"

#include "VisDataType.h"

class VisVerticesDescription;
class VisIndicesDescription;

extern ExportedByVisSceneGraph IID IID_IVisSGCustomPrimitive;

/** 
 * Basic class of any Scene Graph Primitive.
 */
class ExportedByVisSceneGraph IVisSGCustomPrimitive : public IVisSGTessellatedPrimitive
{  
public:

  virtual HRESULT GetVerticesDescription(VisVerticesDescription*& opDescription) = 0;

  virtual HRESULT GetNumberOfIndicesDescription(VisSize& oNbIndicesDescription) = 0;

  virtual HRESULT RetrieveIndicesDescription( VisSize iIndex,
                                              VisIndicesDescription*& opDescription,
                                              VisConnectivityType& oPrimitiveType) = 0;
};

#endif // IVISSGCUSTOMPRIMITIVE_H
