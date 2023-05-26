#ifndef CATVisHLRClippingVolume_h
#define CATVisHLRClippingVolume_h

//******************************************************************************
// CATIA Version 5 Release 3 Framework VISUALIZATION
// Copyright Dassault Systemes 1996
//******************************************************************************
//  Abstract:
//  ---------
//   class representing a face, with every informations needed for
//   the polyhedric HLR display
//
//******************************************************************************
//  Usage:
//  ------
//
//******************************************************************************
//  Inheritance:
//  ------------
//******************************************************************************
//  Main Methods:
//  -------------
//******************************************************************************

#include "SGInfra.h"
#include "CATBaseUnknown.h"
#include "CAT3DBoundingSphere.h"

#include "CATMathBox.h"

#include "CATErrorDef.h"

class CAT3DRep;
class CAT4x4Matrix;
class CATVisFilter;

class ExportedBySGInfra CATVisHLRClippingVolume : public CATBaseUnknown
{
	CATDeclareClass;

public:

  // 0 : non vue
  // 1 : completement vue
  // 2 : intersection potentielle (il s'agit d'une approximation)
  virtual HRESULT Visibility(CAT3DRep *iRep, CAT4x4Matrix *iMatrix, int &oVisibility) const = 0;
	
	//oFilter has to be released
	virtual HRESULT ComputeEquivalentFilter(CATVisFilter *& oFilter, CAT3DBoundingSphere &oBE) = 0;

protected:
  HRESULT ComputeBoundingBox(CAT3DRep *iRep,CAT4x4Matrix *iMatrix,CATMathBox &oBox) const;
};

#endif
