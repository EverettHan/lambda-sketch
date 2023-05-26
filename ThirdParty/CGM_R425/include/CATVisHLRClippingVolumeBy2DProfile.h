#ifndef CATVisHLRClippingVolumeBy2DProfile_h
#define CATVisHLRClippingVolumeBy2DProfile_h

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
#include "CAT3DBoundingSphere.h"
#include "CAT4x4Matrix.h"
#include "CAT3DViewpoint.h"

#include "CATMathVectorf.h"
#include "CATMathDirectionf.h"

class CAT3DRep;
class CATMathPoint2D;
class CATVisFilter;

class ExportedBySGInfra CATVisHLRClippingVolumeBy2DProfile : public CATVisHLRClippingVolume
{
	CATDeclareClass;

public:
  // Constructions and destruction methods:
  // --------------------------------------

  CATVisHLRClippingVolumeBy2DProfile(unsigned int iPolygonSize, const float *iPolygonVertex, CAT4x4Matrix &iMatrix, CAT3DBoundingSphere &iSphere, const CAT3DViewpoint &iViewpoint);
  virtual ~CATVisHLRClippingVolumeBy2DProfile();

  virtual HRESULT Visibility(CAT3DRep *iRep, CAT4x4Matrix *iMatrix, int &oVisibility) const;
	virtual HRESULT ComputeEquivalentFilter(CATVisFilter *& oFilter, CAT3DBoundingSphere &oBE);

  inline CATMathDirectionf GetSightDirection() const;
  virtual HRESULT ComputeVertex(float *&oVertex, int &oNbVertex);

private:

	int InsidePolygon(const CATMathPoint2D *iPolygonDescription, unsigned int iPolygonSize, CATMathPoint2D iPoint) const;
	  
	
	CAT3DBoundingSphere	_be;
	CAT4x4Matrix			 *_matrix;
	unsigned int				_polygonSize;
	float							 *_polygonVertex;
	CAT3DViewpoint			_viewpoint;
	
	CATVisFilter *_filter;
};

inline CATMathDirectionf CATVisHLRClippingVolumeBy2DProfile::GetSightDirection() const
{
	return _viewpoint.GetSightDirection();
}
#endif
