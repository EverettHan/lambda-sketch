//===================================================================
// COPYRIGHT DS SolidWorks Corporation 2012/03/08
//===================================================================
// CATFreeTypeDistanceTransform.cpp
//
// Calculates the euclidean distance transform (EDT) 
// of a 2D grayscale alpha mask
//
//===================================================================
//
// This is a custom implementation of the 8-point SED from the paper
// "Euclidean Distance Mapping", Danielsson, 1980
// with the linear correction for antialiased edges from
// "Anti-aliased Euclidean distance transform", Gustavson & Strand, 2010
// Ref: http://contourtextures.wikidot.com/
//
//===================================================================

#ifndef CATFreeTypeDistanceTransform_H
#define CATFreeTypeDistanceTransform_H

#include "SGInfra.h"
#include "CATMath.h"

class ExportedBySGInfra CATFreeTypeDistanceTransform 
{
public:
	CATFreeTypeDistanceTransform();
	~CATFreeTypeDistanceTransform();

	//! Set a scaling factor for the distance values
	void SetScale(float iScale);

	//! Calculate the EDT of the input alpha mask iMask. Output buffer may be equal to input
	void Apply(unsigned char* iMask, size_t iWidth, size_t iHeight, unsigned char* oDistField);

private:
	struct vec
	{
		float x,y;

		vec() : x(0), y(0) {}
		vec(float ix, float iy) : x(ix), y(iy) {}
	};
	inline float Length(vec const& in) { return sqrt(in.x*in.x + in.y*in.y); }

	void Update(size_t row, size_t col, int xvec, int yvec);

	void Transform(float* oField);

	void AllocBuffers();

	void FreeBuffers();

private:
	size_t _width;
	size_t _height;
	size_t _size;
	unsigned char*	_mask;
	vec*	_points;
	float*  _dist;
	float*	_fg;
	float* _bg;
	float _scale;
};

#endif // CATFreeTypeDistanceTransform_H 
