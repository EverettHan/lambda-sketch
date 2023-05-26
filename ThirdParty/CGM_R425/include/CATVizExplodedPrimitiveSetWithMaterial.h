// COPYRIGHT DASSAULT SYSTEMES 2007

/* useless code
#ifndef CATVizExplodedPrimitiveSetWithMaterial_H
#define CATVizExplodedPrimitiveSetWithMaterial_H

#include "SGInfra.h"
#include "CATVizExplodedPrimitiveSet.h"
#include "CATVisAppliedMaterial.h"

class CATVizPrimitive;
class CATVizVertexBuffer;
class CATGraphicAttributeSet;
class CATMappingOperator;

class ExportedBySGInfra CATVizExplodedPrimitiveSetWithMaterial : public CATVizExplodedPrimitiveSet
{

public:

  CATVizExplodedPrimitiveSetWithMaterial();
  CATVizExplodedPrimitiveSetWithMaterial(unsigned int nbPrimitives, CATVizPrimitive** primitives, CATVizVertexBuffer** vertexBuffers, CATGraphicAttributeSet* attributes, CATGraphicMaterial** materials, CATVizGeomType type);
  virtual ~CATVizExplodedPrimitiveSetWithMaterial ();

  virtual CATGraphicMaterial* GetGraphicMaterial(unsigned int i);
  void SetGraphicMaterial(unsigned int i, CATGraphicMaterial* ipMat);
  virtual CATMappingOperator* GetMappingOperator(unsigned int i);

  virtual CATBoolean WithGraphicMaterial();

private:

  // The size of _materials is the same as _nbPrimitives defined in the base class
  list<CATVisAppliedMaterial> _materials;

  // Copy not allowed
  CATVizExplodedPrimitiveSetWithMaterial (const CATVizExplodedPrimitiveSetWithMaterial &);
  CATVizExplodedPrimitiveSetWithMaterial & operator=(const CATVizExplodedPrimitiveSetWithMaterial &);
};


#endif
*/
