// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyGeometryLayer.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// Mars 2008  Creation: ZFI
//===================================================================

#ifndef CATPolyBodyGeometryLayer_H
#define CATPolyBodyGeometryLayer_H

#include "PolyBodyBuilders.h"
#include "CATErrorDef.h"     // HRESULT definition
#include "CATMapOfPtrToPtr.h"

class CATPolyGeometricForm;
class CATPolyCell;

class ExportedByPolyBodyBuilders CATPolyBodyGeometryLayer
{
public : 
  CATPolyBodyGeometryLayer();
  virtual ~CATPolyBodyGeometryLayer();

  HRESULT GetGeometricForm(const CATPolyCell* iCell, CATPolyGeometricForm& oForm) const;
  HRESULT SetGeometricForm(const CATPolyCell* iCell, const CATPolyGeometricForm& iForm);

private:
  CATMapOfPtrToPtr _CellToForm;
};


#endif
