// COPYRIGHT DASSAULT SYSTEMES 2007

/* useless code
#ifndef CATVizExplodedPrimitivSet_H
#define CATVizExplodedPrimitivSet_H

#include "SGInfra.h"
#include "CATVizExtendedPrimitiveSet.h"

class ExportedBySGInfra CATVizExplodedPrimitiveSet : public CATVizExtendedPrimitiveSet
{
public:

  CATVizExplodedPrimitiveSet();
  CATVizExplodedPrimitiveSet (unsigned int nbPrimitives, CATVizPrimitive** primitives, CATVizVertexBuffer** vertexBuffers, CATGraphicAttributeSet* attributes, CATVizGeomType type);

  virtual CATBoolean WithVertexBuffer();
  virtual CATVizVertexBuffer* GetVertexBuffer(unsigned int i);
  void SetVertexBuffer(unsigned int i, CATVizVertexBuffer * iVertexBuffer);
  
  protected:
    virtual ~CATVizExplodedPrimitiveSet ();

private:
    
  // The size of _vertexBuffers is the same as _nbPrimitives defined in the base class
  CATVizVertexBuffer** _vertexBuffers;
  
  // Copy not allowed
  CATVizExplodedPrimitiveSet (const CATVizExplodedPrimitiveSet &);
  CATVizExplodedPrimitiveSet & operator=(const CATVizExplodedPrimitiveSet &);
};

#endif
*/
