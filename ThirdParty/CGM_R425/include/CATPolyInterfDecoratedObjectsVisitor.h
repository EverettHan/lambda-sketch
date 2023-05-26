// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInterfDecoratedObjectsVisitor.h
//
//===================================================================
//
// Usage notes:
// Visitor interface descending the Interference operators cache.
//
//===================================================================
//
// Jan 2010 Creation: JS9
//===================================================================

#ifndef CATPolyInterfDecoratedObjectsVisitor_h
#define CATPolyInterfDecoratedObjectsVisitor_h

#include "CATPolyBoundingVolumeOperators.h"

// Interference
class CATPolyInterfDecoratedTree;
class CATPolyInterfDecoratedPolyBody;
class CATPolyInterferenceDecoratedSurface;
class CATPolyInterferenceDecoratedMesh;
class CATPolyInterferenceDecoratedCanonic;
class CATPolyInterfDecoratedTriangle;

/**
 * Visitor interface descending the Interference operators cache.
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyInterfDecoratedObjectsVisitor
{
public:

  virtual ~CATPolyInterfDecoratedObjectsVisitor() {}

  virtual void Visit(CATPolyInterfDecoratedTree & decoTree);

  virtual void Visit(CATPolyInterfDecoratedPolyBody & decoPB);

  virtual void Visit(CATPolyInterferenceDecoratedSurface & decoSurface);

  virtual void Visit(CATPolyInterferenceDecoratedMesh & decoMesh);

  virtual void Visit(CATPolyInterferenceDecoratedCanonic & decoCanonic);

  virtual void Visit(CATPolyInterfDecoratedTriangle & decoTriangle);

protected:

  virtual void VisitDefault() {}

  CATPolyInterfDecoratedObjectsVisitor() {}

};

#endif /* CATPolyInterfDecoratedObjectsVisitor */
