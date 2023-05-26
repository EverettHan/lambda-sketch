#ifndef CATVisHLRClippingVolumeByPlanes_h
#define CATVisHLRClippingVolumeByPlanes_h

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
#include "CATVisHLRClippingVolume.h"
#include "CATVizPtrList.h"
#include "CAT3DBoundingSphere.h"

class CATMathPlane;
class CAT4x4Matrix;
class CATVisFilter;

class ExportedBySGInfra CATVisHLRClippingVolumeByPlanes : public CATVisHLRClippingVolume
{

CATDeclareClass;

public:
  // Constructions and destruction methods:
  // --------------------------------------

	CATVisHLRClippingVolumeByPlanes(CATVizPtrList<CATMathPlane> &iPlanes, CAT3DBoundingSphere &iSphere, const int *iFacesBehaviour = NULL);
	virtual ~CATVisHLRClippingVolumeByPlanes();

	virtual HRESULT Visibility(CAT3DRep *iRep, CAT4x4Matrix *iMatrix, int &oVisibility) const;
	virtual HRESULT ComputeEquivalentFilter(CATVisFilter *& oFilter, CAT3DBoundingSphere &oBE);

	inline void  GetDefinition(CATVizPtrList<CATMathPlane> &oClippingPlaneList, CAT3DBoundingSphere &oBE, const int *&oPlaneBehaviour) const;
	inline const CAT3DBoundingSphere& GetBoundingSphere(void) const;
  
private:
	
	CATVizPtrList<CATMathPlane>	_clippingPlaneList;
	CAT3DBoundingSphere					_be;
	int *_facesBehaviour;

	CATVisFilter *_filter;
};

inline void CATVisHLRClippingVolumeByPlanes::GetDefinition(CATVizPtrList<CATMathPlane> &oClippingPlaneList, CAT3DBoundingSphere &oBE, const int *&oPlaneBehaviour) const
{
	oClippingPlaneList	= _clippingPlaneList;
	oBE									= _be;
	oPlaneBehaviour			= _facesBehaviour;
}

inline const CAT3DBoundingSphere& CATVisHLRClippingVolumeByPlanes::GetBoundingSphere() const
{
	return _be;
}

#endif
