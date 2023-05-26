//=============================================================================
//
// <ClassName>: CATStTrianglesNormalsOper
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
// November 98   Creation                                   F. LETZELTER
// 19-Jan-2004 - JLH - Eradication des 'long's.
//=============================================================================

#ifndef CATStTrianglesNormalsOper_H
#define CATStTrianglesNormalsOper_H
/**
 * DSECAAFutureExposure_Level L1
 * DSECAAFutureExposure_Usage U3
 */ 

#include "ExportedByCATCloudBasicResources.h"

class ExportedByCATCloudBasicResources CATStTrianglesNormalsOper
{

public:

	// Type of normals
	enum NormalType {FLAT, SMOOTHED};

	// Constructor
	// iTableOfPointsf			: Pointer on the table of points where are stored the 3 coordinates of 
	//							  the vertices (const)
	// iNbPointsf				: Number of points in the table
	// iTableOfVertices			: Pointer on the table of indices that refer to the point in the previous
	//							  table. 3 following indices compose a triangle (const)
	// iNbVertices				: Length of this table
	// !!! It is supposed that the table of vertices contains correct indices, that don't overpass the length
	// of the points table !!!
	// Moreover, it is supposed that the length of the table of vertices is a 3-multiple because to create
	// a triangle, we need 3 vertices !!!
	// NO CHECK IS HERE !!! BE CAREFUL !!
	CATStTrianglesNormalsOper(const float *iTableOfPointsf, int iNbPointsf, \
							  const int *iTableOfVertices, int iNbVertices, \
							  NormalType iNormalType = FLAT);

	// Destructor
	~CATStTrianglesNormalsOper();

	// Set the type of normals expected
	void SetNormalsType(NormalType iNormalType);

	// Run the algorithm. Can be run on the same operator with different lengths
	void Run();

	// Return a pointer on the table of normals
	// oTableOfNormals			: Pointer on the table of normals (3 coordinates)
	//							  This table is allocated here, but MUST BE DELETED BY THE CALLING FUNCTION
	// oNbNormals				: Number of normals (!! 1 normal = 3 coordinates)
	void GetResult(float **oTableOfNormals, int &oNbNormals);

private:

	// data members

	// Table of points
	const float				*_tableOfPointsf;
	// Number of points
	int					_nbPointsf;

	// Table of vertices
	const int				*_tableOfVertices;
	// Number of vertices
	int					_nbVertices;

	// Type of the normals (SMOOTHED, FLAT)
	NormalType				_type;

	// Resulting table of normals
	float					*_tableOfNormals;
	// Number of normals
	int					_nbNormals;

	// Functions
	void GetFlatNormals();
	void GetSmoothedNormals();
};


#endif
