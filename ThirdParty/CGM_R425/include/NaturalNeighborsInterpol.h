//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2010
//==============================================================================================================
// File: NaturalNeighborsInterpol.h
//==============================================================================================================
// Usage:
//                 /!\ Natural Neighbors Interpolation of scalar fields in 3-space /!\
//
//==============================================================================================================
// 3-oct-2013 - ALA - Création
//==============================================================================================================

#ifndef NaturalNeighborsInterpol_h
#define NaturalNeighborsInterpol_h

#include "ExportedByCATCldResMeshInria.h"

/**
 * Interface to NRDelaunay in order to create a volumic delaunay mesh.
 * 
 **/
class ExportedByCATCldResMeshInria NaturalNeighborsInterpol
{
public:
	//
	// initializes the points support of data to interpolate and a box in which interpolation will be evaluated 
	static NaturalNeighborsInterpol* CATCreateNaturalNeighborsInterpol( float* iPtrCloudToTriangulate,
            const int iNbPointsInCloud,  float *bboxMin,  float *bboxMax);
	//
	virtual ~NaturalNeighborsInterpol(){};
	//
	// set the value to interpolate : size of iValues must be at least iNbPointsInCloud 
	virtual void SetValues(const float * const iValues) = 0;
	//
	// retun 0 if OK
	// return 2 if out of box
	virtual int Eval(const float iXYZ[3], float &oResult) = 0;
	//
};

#endif
