// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolySegmentLayer.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// Mars 2008  Creation: ZFI
//===================================================================

#ifndef CATPolySegmentLayer_H
#define CATPolySegmentLayer_H

#include "CATPolySegmentCommon.h"
#include "CATErrorDef.h"     // HRESULT definition
#include "CATPolyBuckets_T.h"

#include "CATPolyGeometricForm.h"

class CATPolyGeometricForm;

class ExportedByCATPolySegmentCommon CATPolySegmentLayer
{
public : 
  CATPolySegmentLayer();
  virtual ~CATPolySegmentLayer();

  HRESULT GetGeometricForm(int iIdxPatch, CATPolyGeometricForm& oForm) const;
  int GetNbForms()const;

  HRESULT SetGeometricForm(int iIdxPatch, const CATPolyGeometricForm& iForm);

private:
  class Specialize_CATPolyBuckets_T(FormBuckets, CATPolyGeometricForm);
  FormBuckets _Forms;
};


#endif
