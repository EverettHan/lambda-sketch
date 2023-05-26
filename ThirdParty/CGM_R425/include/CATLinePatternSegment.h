/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2022
//============================================================================
//
// CATLinePatternSegment for ACAD Data model
//
//=============================================================================
// 2022-07-22                                         Creation: TPG
//=============================================================================

#ifndef CATLinePatternSegment_H
#define CATLinePatternSegment_H

#include "SGInfra.h"
#include "CAT3x3Matrix.h"
#include <stdint.h>

class CATLineShape;
class CATJSONObject;
class CATJSONParser;

class ExportedBySGInfra CATLinePatternSegment
{
public:
	// Standard constructors and destructors
	// -------------------------------------
	CATLinePatternSegment();
	virtual ~CATLinePatternSegment();

	// Copy constructor and equal operator
	// -----------------------------------
	CATLinePatternSegment(const CATLinePatternSegment&);
	CATLinePatternSegment& operator=(const CATLinePatternSegment&);

	// IsEqual
	// -----------------------------------
	bool IsEqual(const CATLinePatternSegment&) const;

	/** Sets the LineShape.
	* @param iLineShape
	* The input LineShape lifecycle is managed by caller.
	*/
	void SetLineShape(CATLineShape &iLineShape);

	/** Retrieves the LineShape.<br>
	* @param oLineShape
	* The output LineShape lifecycle is managed by caller.
	*/
	void GetLineShape(CATLineShape* &oLineShape);

	/** Sets the Matrix.
	* @param iMatrix
	* The Matrix.
	*/
	inline void SetMatrix(const CAT3x3Matrix &iMatrix) {_matrix = iMatrix;}

	/** Retrieves the Matrix.<br>
	*/
	inline const CAT3x3Matrix& GetMatrix() const {return _matrix;}

	/** Sets the UpRight.
	* @param iUpRight
	*/
	inline void SetUpRight(const bool iUpRight = TRUE) {_upright = iUpRight;}

	/** Retrieves the UpRight.<br>
	*/
	inline bool IsUpRight() const {return _upright;}

	/** Sets the Length.
	* @param iLength
	*/
	inline void SetLength(const float iLength) {_length = iLength;}

	/** Retrieves the Length.<br>
	*/
	inline float GetLength() const {return _length;}

	// Streaming
	// -----------------------------------
	virtual HRESULT Stream(CATJSONObject& iJSONObject, float iVersion);
	virtual HRESULT UnStream(const CATJSONParser& iParser, const uint32_t iKey, float iVersion);

private:
	float _length;
	CATLineShape* _shape;
	CAT3x3Matrix _matrix;
	bool _upright;
};

#endif


