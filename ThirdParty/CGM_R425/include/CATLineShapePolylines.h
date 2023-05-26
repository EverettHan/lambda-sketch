/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2022
//============================================================================
//
// CATLineShapePolylines for ACAD Data model
//
//=============================================================================
// 2022-07-22                                         Creation: TPG
//=============================================================================

#ifndef CATLineShapePolylines_H
#define CATLineShapePolylines_H

#include "SGInfra.h"
#include "CATLineShape.h"
#include <stdint.h>

class CATJSONObject;
class CATJSONParser;

class ExportedBySGInfra CATLineShapePolylines : public CATLineShape
{
public:
	// Standard constructors and destructors
	// note that vertices is 3D (x,y,z for each vertex)
	// -------------------------------------
	CATLineShapePolylines();
	CATLineShapePolylines(const unsigned int iNbPolylines, const unsigned int *iNbVerticesPerPolyline, const float *iVertices);
	virtual ~CATLineShapePolylines();

	// Copy constructor and equal operator
	// -----------------------------------
	CATLineShapePolylines(const CATLineShapePolylines&);
	CATLineShapePolylines& operator=(const CATLineShapePolylines&);

	// SafeCast
	virtual CATLineShapePolylines* SafeCastToCATLineShapePolylines();

	// IsEqual
	// -----------------------------------
	bool IsEqual(const CATLineShapePolylines&) const;

	// Set Polylines and Vertices
	// note that vertices is 3D (x,y,z for each vertex)
	HRESULT SetPolylinesAndVertices(const unsigned int iNbPolylines, const unsigned int *iNbVerticesPerPolyline, const float *iVertices);
	
	// GetReadOnly: note that oVertices is 3D (x,y,z for each vertex)
	inline void GetReadOnly(unsigned int &oNbPolylines, unsigned int const * &oNbVerticesPerPolyline, float const * &oVertices) const;

	// Streaming
	// -----------------------------------
	virtual HRESULT Stream(CATJSONObject& iJSONObject, float iVersion);
	virtual HRESULT UnStream(const CATJSONParser& iParser, const uint32_t iKey, float iVersion);

private:
	unsigned int  _nbPolylines;
	unsigned int* _nbVerticesPerPolyline;
	float* _vertices;
};

//------------------------------------------------------------------------------
// GetReadOnly
inline void CATLineShapePolylines::GetReadOnly(unsigned int &oNbPolylines, unsigned int const * &oNbVerticesPerPolyline, float const * &oVertices) const
{
	oNbPolylines           = _nbPolylines;
	oNbVerticesPerPolyline = _nbVerticesPerPolyline;
	oVertices              = _vertices;
}

#endif


