//====================================================================
// Copyright Dassault Systemes Provence 2015 , All Rights Reserved 
//====================================================================
// class CATShapeDescriptorART2D
// Computes the Angular Radial Transform of a binary shape image
//
//=============================================================================
// HISTORIQUE :
//
// 07 2015 JX2 creation 
//
//=============================================================================
#ifndef CATShapeDescriptorART2D_h
#define CATShapeDescriptorART2D_h

#include "MathShape.h"


class ExportedByMathShape CATShapeDescriptorART2D
{
public :
	// Constructor and destructor
	CATShapeDescriptorART2D();
	~CATShapeDescriptorART2D();
	
	// Set input image
	// Image as a buffer (one unsigned int per pixel (4 bytes))
	// Positive value for foreground, null value for background (or the contrary)
	// Not copied internally, don't release until Run is complete
	void SetImage(unsigned int* iImageBuffer, unsigned short iImageWidth, unsigned short iImageHeight);

	// Set parameters
	// iRadialOrder : number of radial coefficients (default is 3)
	// iAngularOrder : number of angular coefficients (default is 12)
	// The descriptor dimension is then iRadialOrder*iAngularOrder
	// iOrderExponent : the coefficients are divided by sqrt(n^2+m^2) to the power of iOrderExponent
	// where n, m are radial, angular indices (default is 0.0f)
	void SetParameters(unsigned short iRadialOrder, unsigned short iAngularOrder, float iOrderExponent);

	// Run
	// Returns 0 upon success
	int Run();
	
	// Get result descriptor
	// oDescriptor is allocated internally but destruction is in charge of the caller
	// oDescriptorSize is RadialOrder*AngularOrder
	// Returns 0 upon success
	int GetDescriptor(float *&oDescriptor, unsigned short &oDescriptorSize);

private:
	// Copy constructor and equal operator
	CATShapeDescriptorART2D (CATShapeDescriptorART2D &);
	CATShapeDescriptorART2D& operator=(CATShapeDescriptorART2D&);

	unsigned int *_pImageBuffer;
	unsigned short _ImageWidth;
	unsigned short _ImageHeight;

	float *_pDescriptor;
	unsigned short _RadialOrder;
	unsigned short _AngularOrder;
	float _OrderExp;
};

#endif
