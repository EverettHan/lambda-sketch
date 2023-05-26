//=============================================================================
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// CATPolyBodyMatrixApplier.cpp
//
//=============================================================================
// 2008-02-13   BPG: New.
//=============================================================================
#ifndef CATPolyBodyMatrixApplier_H
#define CATPolyBodyMatrixApplier_H

class CATPolyBody;

class CATMathTransformation;

#include "CATErrorDef.h"

#include "PolyImportExport.h"
class ExportedByPolyImportExport CATPolyBodyMatrixApplier
{
public:
  HRESULT Apply (CATPolyBody &ioPolyBody, const CATMathTransformation &iTransformation) const;
};

#endif // CATPolyBodyMatrixApplier_H
