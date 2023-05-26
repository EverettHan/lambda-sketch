/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2022
//============================================================================
//
// CATLineShape for ACAD Data model
//
//=============================================================================
// 2022-07-22                                         Creation: TPG
//=============================================================================

#ifndef CATLineShape_H
#define CATLineShape_H

#include "SGInfra.h"
#include "CATSysErrorDef.h"
#include <stdint.h>

class CATLineShapePolylines;
class CATLineShapeTriangles;
class CATJSONObject;
class CATJSONParser;

class ExportedBySGInfra CATLineShape
{
public:
	// Standard constructors and destructors
	// -------------------------------------
	CATLineShape();
	virtual ~CATLineShape();

	// SafeCast
	inline virtual CATLineShapePolylines* SafeCastToCATLineShapePolylines() { return nullptr; }
	inline virtual CATLineShapeTriangles* SafeCastToCATLineShapeTriangles() { return nullptr; }

	// Streaming
	// -----------------------------------
	virtual HRESULT Stream(CATJSONObject& iJSONObject, float iVersion);
	virtual HRESULT UnStream(const CATJSONParser& iParser, const uint32_t iKey, float iVersion, CATLineShape* &oLineShape);
};

#endif


