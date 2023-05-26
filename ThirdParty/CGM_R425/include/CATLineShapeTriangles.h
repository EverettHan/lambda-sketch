/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2022
//============================================================================
//
// CATLineShapeTriangles for ACAD Data model
//
//=============================================================================
// 2022-07-22                                         Creation: TPG
//=============================================================================

#ifndef CATLineShapeTriangles_H
#define CATLineShapeTriangles_H

#include "SGInfra.h"
#include "CATLineShape.h"
#include <stdint.h>

class CATJSONObject;
class CATJSONParser;

class ExportedBySGInfra CATLineShapeTriangles : public CATLineShape
{
public:
	// Standard constructors and destructors
	CATLineShapeTriangles();
	CATLineShapeTriangles(const unsigned int* iTriangles, const unsigned int iNbtriangles, const float* iVertices, const unsigned int iNbvertices);
	virtual ~CATLineShapeTriangles();

	// Copy constructor and equal operator
	// -----------------------------------
	CATLineShapeTriangles(const CATLineShapeTriangles&);
	CATLineShapeTriangles& operator=(const CATLineShapeTriangles&);

	// SafeCast
	virtual CATLineShapeTriangles* SafeCastToCATLineShapeTriangles();

	// IsEqual
	// -----------------------------------
	bool IsEqual(const CATLineShapeTriangles&) const;

	// Set Triangles and Vertices
	// note that vertices is 3D (x,y,z for each vertex)
	HRESULT SetTrianglesAndVertices(const unsigned int* iTriangles, const unsigned int iNbtriangles, const float* iVertices, const unsigned int iNbvertices);

	// GetReadOnly
	// note that vertices is 3D (x,y,z for each vertex)
	inline void GetReadOnly(unsigned int const* &oTriangles, unsigned int &oNbtriangles, float const * &oVertices, unsigned int &oNbvertices) const;

	// Streaming
	// -----------------------------------
	virtual HRESULT Stream(CATJSONObject& iJSONObject, float iVersion);
	virtual HRESULT UnStream(const CATJSONParser& iParser, const uint32_t iKey, float iVersion);

private:
	unsigned int  _nbTriangles;
	unsigned int* _triangles;
	unsigned int  _nbVertices;
	float* _vertices;
};

//------------------------------------------------------------------------------
inline void CATLineShapeTriangles::GetReadOnly(unsigned int const* &oTriangles, unsigned int &oNbtriangles, float const * &oVertices, unsigned int &oNbvertices) const
{
	oTriangles = _triangles;
	oNbtriangles = _nbTriangles;
	oVertices = _vertices;
	oNbvertices = _nbVertices;
}

#endif


