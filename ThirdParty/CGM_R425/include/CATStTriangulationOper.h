//=============================================================================
//
// <ClassName>: CATStTriangulationOper
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
// 19-Jan-2004 - JLH - Eradication des 'long's.
// March    02  : MkCheckSource.											R. BERAUD
// February 01  : Improve algorithm :compute with a given polygon		    R. BERAUD
// Jan. 2000    : mkCheckSource												STA
// January 2000 : Improvment. The projecting plane is given if necessary.   R. BERAUD	 
// July 98		: Creation													F. LETZELTER                                  
//=============================================================================

#ifndef CATStTriangulationOper_H
#define CATStTriangulationOper_H
/**
 * DSECAAFutureExposure_Level L1
 * DSECAAFutureExposure_Usage U3
 */ 

#include "ExportedByCATCloudBasicResources.h"
#include "CATListOfInt.h"
#include "CATCORBABoolean.h"
//#include "CATMathVectorf.h"
//#include "CATMathPlane.h"


/**
 *@nodoc
 */
#define FIRST_SUPER_VERTEX		-1
/**
 *@nodoc
 */
#define SECOND_SUPER_VERTEX		-3
/**
 *@nodoc
 */
#define THIRD_SUPER_VERTEX		-5

/**
 *@nodoc
 */
#define NB_SUPER_VERTICES		6

class CATTrace;

/**
 *@nodoc
 */
typedef void (*fctOnStep)();


class ExportedByCATCloudBasicResources CATStTriangulationOper
{

public:
	// Constructor
	// iPtrCloudToTriangulate	: Input Cloud on which to perform the algorithm
	//							  This parameter is not modified by the object
	// iNbPointsInCloud			: Number of points in the cloud. This value is iPtrCloudToTriangulate
	//							  length/3
	// iTableOfIndices			: Active points to considerate in the previous table. If NULL all points are.
	// iNbIndices				: Number of active points. If 0 all points are active
	CATStTriangulationOper( const float *iPtrCloudToTriangulate, 
                          int iNbPointsInCloud, \
						              const float iRefVector[3], \
						              const int *iTableOfIndices = NULL, 
                          int iNbIndices = 0, \
						              const boolean iUsersPlane = FALSE, 
                          //CATMathPlane *iProjectPlane = NULL, 
                          float *iProjectPlane = NULL, 
                          fctOnStep fonctionStep=NULL);

	// Constructor
	// iPtrCloudToTriangulate	: Input Cloud on which to perform the algorithm
	//							  This parameter is not modified by the object
	// iNbPointsInCloud			: Number of points in the cloud. This value is iPtrCloudToTriangulate
	//							  length/3
	// iNbPointsInPolygon		: Number of points in the the polygon already computed. 
	//							  This value must be less or equal than iNbPointsInCloud.
	//							  The first iNbPointsInPolygon from iPtrCloudToTriangulate are already computed
	//							  (The polygon is dexcribed with iNoVertices and iNbVertices)
	//                            The remaining points ( NbPointsInPolygon+1, NbPointsInPolygon+2, ... iNbPointsInCloud) 
	//                            are added to the initial polygon if and only if there is a triangle which contains the point.
	// iNbTriangles				: Number of triangles (table width / 3)
	// iNoVertices				: The initial polygon. i.e. the table of indexes of triangles already computed
	// iNoConnexes				: The connexity table 
	// iTableOfIndices			: Active points to considerate in the previous table. If NULL all points are.
	// iNbIndices				: Number of active points. If 0 all points are active

    CATStTriangulationOper( const float *iPtrCloudToTriangulate, 
						                int iNbPointsInCloud, 
							              int iNbPointsInPolygon, 
					                  int iNbTriangles, 
							              const int *iNoVertices, 
							              const int *iNoConnexes, 
                            const float iRefVector[3], 
							              const int *iTableOfIndices = NULL,
							              int iNbIndices = 0, 
							              const boolean iUsersPlane = FALSE, 
							              //CATMathPlane *iProjectPlane = NULL,
							              float *iProjectPlane = NULL,
                            fctOnStep fonctionStep = NULL) ;
	// Destructor
	~CATStTriangulationOper();

	// Run the algorithm on the Cloud passed in the constructor
	void Run();

	// Return a table containing the index of the points in the cloud forming 
	// a triangle
	// oVertices				: Table of indexes. This table is allocated in this 
	//							  function, but must be deleted using delete[] in
	//							  the calling function
	// oNbVertices				: Number of triangles (table width / 3)
	// Ex :			Cloud				Table
	//				0.234				2	|
	//				0.428				5	| |	1 triangle formed by (0.864, 0.561, 0.428)
	//				0.864				1	|
	//
	//				0.450				3	|
	//				0.580				4	| |	1 triangle formed by (0.450, 0.580, 0.234)
	//				0.561				0	|
	void GetResult(int **oVertices, int &oNbVertices);

	// Return the table of adjacence regarding to the previous table (oVertices)
	// iTableOfVertices			: Array of indices referencing the points in the table of points.
	//							  3 following indices form a triangle
	// iNbVertices				: Length of the previous array
	// oTableOfAdjacence		: Array of indexes. This table is allocated here but must be deleted
	//							  by the calling function
	// oNbAdj					: Length of the previous array
	//void GetAdjacence(int **oTableOfAdjacence, int &oNbAdj);

	// Return the super-triangle vertices
	void GetSuperTriangle(float *oVertices);

	// Return the table of points projected in the median plane of the cloud
	void GetProjectedPoints(float **oVertices);


	// Return the cloud bounds
	//void GetCloudBounds(float &oMin, float &oMax);

	// Find the center of the circle (sphere) that contains the triangle ABC and its radius
	// iA						: First point of the triangle (3 coordinates)
	// iB						: Second point of the triangle (3 coordinates)
	// iC						: Third point of the triangle (3 coordinates)
	// oCenter					: Center of the circle (sphere) (3 coordinates)
	//							  must be allocated by the calling function
	// oSquareRadius			: Square radius of the sphere
	void FindCircleCenter(float *iA, float *iB, float *iC,\
						  float *oCenter, float &oSquareRadius);

	// Methode permettant de rendre convexe le maillage 2D
	// Retourne TRUE si le calcul a reussi, FALSE sinon.
	// A utiliser avant GetResult.
	//boolean SetResultConvex() ;


private:

	// data members

	// For Debug
	CATTrace					*_ptrTrace;
	int							_nbTraceMax ;

	// Reference vector
	//CATMathVectorf				_refVector;
	float				    _refVector[3];
	float						_barycenter[3] ;

	// Cloud of points
	const float					*_tableOfPoints;
	// Number of points in the input cloud
	const int					_nbPoints;
	// Number of points from the input cloud already in the polygon
	// _nbPtsInPolygon must be <= _nbPoints
	int						_nbPtsInPolygon;
	// The first Polygon
	int					    _nbTriangles ;
	const int							*_noVertices ; 
	const int							*_noConnexes ;
	boolean						_initPolygon;
	// Table Of Activity
	int							*_tableOfActiveIndices;
	// Number of active points
	int						_nbActivePoints;

	// Pointer on the table of points projected in the median plane
	float						*_tableOfProjPoints;

	// Table of indices while indirect sort
	int						*_tableOfSortedIndices;

	// Is there a projecting plane for computing the Delaunay triangulation ?
	boolean						_usersPlane;

	// The plane where the points 3D have to be projected if _usersPlane is TRUE
	//CATMathPlane				*_projectPlane;
	float   				*_projectPlane;

  // LIFO (cf explanation higher)
	CATListOfInt*				_ptrLIFO;
//	CATRCOLL(int)				_LIFO;
	// Bounds of the Cloud
	float						_minBound[2];
	float						_maxBound[2];

	// Pointer on the list of triangles
	// This list contains each triangle represented by the indexes of its three vertices
	// Moreover, following these three vertices, there are three another pieces of information
	// that give the indexes of the adjacent triangles
	// To resume, a triangle owns :
	// 3 indexes, each one representing the position of a vertex in the table of points
	// 3 indexes, each one representing the position of an adjacent triangle in the current list
	// If no adjacent triasgle exists, a null value is inserted
	int							**_ptrTableOfVertices;
	// Max number of blocs in the table
	int							_nbMaxBlocs;
	// Current number of blocs in the table
	int						_nbBlocs;
	// Max number of elements per bloc
	int							_nbMaxPerBloc;
	// Total number of elements referenced in the blocs
	int						_nbTotalElements;
	// Number of elements referenced in the blocs
	int						_nbElements;
	// Number of elements referenced in the last bloc
	int						_nbElemInLastBloc;

	// Array containing the indices referencing a triangle that contains at least a super-vertex
	int							*_tableOfSuperIndices;
	// Length
	int						_nbSuperIndices;

	// Table containing the vertices of the Super-triangle
	float						_tableOfSuperVertices[NB_SUPER_VERTICES];

	int							_siamRef ;


	// functions

	// Project input points in the plane defined by a normal vector and one of its points
	// iPointsToProject			: Points to be projected in the plane (table of 3 coordinates) 
	// iNbPointsToProject		: Number of points to be projected
	// iVector					: Normal vector of the plane (3 coordinates)
	// iPointInPlane			: Point in the plane (3 coordinates)
	// oProjectedPoints			: Output table containing the input points projected in the plane
	//							  This table is allocated here but must be deallocated by the calling function
	//							  The number of points in this table is the same as in the input one
	void ProjectPointsInPlane(const float *iPointsToProject, int iNbPointsToProject, \
							 float *iFirstVector, float *iSecondVector, float *iPointInPlane, \
							 float **oProjectedPoints);
	
	// Find the bounds of the cloud and update the data members _minBound and _maxBound
	void GetBounds();
	
	// Create the super-triangle containing all the points
	void CreateSuperTriangle(const float *iBarycenter);

	// Create the triangulation after the super-triangle creation
	void CreateTesselation();

	// Sort the input / output triangles which indexes are passed in arguments according to
	// the following rules :
	// The first triangle (ioFirstTri) must be adjacent to the line described by iFirstV iSecondV
	// The second triangle (ioSecondTri) must be adjacent to iThirdV iFirstV
	// The third triangle (ioThirdV) must be adjacent to iSecondV iThirdV
	// iFirstV					: Index of the first vertex in the table of points
	// iSecondV					: Index of the second vertex in the table of points
	// iThirdV					: Index of the third vertex in the table of points
	// ioFirstTri				: Index of the first triangle to be sorted in the list of vertices (io)
	// ioSecondTri				: Index of the second triangle to be sorted in the list of vertices (io)
	// ioThirdTri				: Index of the third triangle to be sorted in the list of vertices (io)
	void SortAdjacentTriangles(int iFirstV, int iSecondV, int iThirdV, \
							   int &ioFirstTri, int &ioSecondTri, int &ioThirdTri);

	// Check if the input point is contained in the input triangle
	// D						: Input point
	// A						: First triangle vertex
	// B						: Second triangle vertex
	// C						: Last triangle vertex
	// oDefaut					: Evaluation of the distance  of the point D out (i. e. <0) of the triangle ABC
//	boolean IsPointInTriangle(float *D, float *A, float *B, float *C);

	// For each triangle in the LIFO, check if the input point is included in its circle
	// iPoint					: Point to Check (3 coordinates)
	void CheckPointInLIFO(float *iPoint);

	// Find the triangles that are adjacent to the input one
	// iTriangleIndex			: Index in the list of vertices of the first vertex of the triangle
	// oFirst					: Index of the first adjacent triangle
	// oSecond					: Index of the second adjacent triangle
	// oThird					: Index of the third adjacent triangle (0 if less than 3 to be found)
	// iNbToFind				: Number of adjacent triangles to be found. 3 by default
	// iTriangleToAvoid			: If found, this triangle must not be considered as adjacent
	void GetAdjacentTriangles(int iBloc, int iTriangleIndex, int &oFirst, \
							  int &oSecond, int &oThird, \
							  int iNbToFind = 3, int iTriangleToAvoid = 0);

	// Find the position of the triangle which contains both input vertices, in the list of
	// adjacent triangles of the triangle passed in argument
	// iFirstVertex				: First vertex that the output triangle nust contain
	// iSecondVertex			: Second vertex that the output triangle nust contain
	// iTriangleIndex			: Index of the triangle in the list of vertices where to find in list of
	// oTrianglePosition		: Position of the found triangle in the list of vertices
	// oPositionInList			: Position of the found triangle in the list of adjacent triangles of the
	//							  input triangle
	void FindAdjInList(int iFirstVertex, int iSecondVertex, int iBloc, int iTriangleIndex, \
					   int &oTrianglePosition, int &oPositionInList);


	// Return TRUE if the input point is included in the input circle defined by its center and 
	// its radius
	// iPoint					: Point to examine (3 coordinates)
	// iCenter					: Center of the circle (sphere) (3 coordinates)
	// iSquareRadius			: Square radius of the circle (sphere). The square is requiered
	//							  for perfos reasons.
	boolean IsPointInCircle(float *iPoint, float *iCenter, float iSquareRadius);

	// Return TRUE if the input point #4 is included in the circle defined by 
	// the first 3 points
	// iPoint1					: Point on the circle (2 coordinates)
	// iPoint2					: Point on the circle (2 coordinates)
	// iPoint3					: Point on the circle (2 coordinates)
	// iPoint4					: Point to examine (2 coordinates)

//	boolean IsPointInCircle(float *iPoint1, float *iPoint2, float *iPoint3, float *iPoint4);


//	float AireTriangle(float *A, float *B, float *C) ;

	
	// Determinate the center of the largest dimension of the bounding box
	// omaxValue				: Value of the center
	// omaxCoord				: Coordinate along which the center is
	void GetMaxDimensionCenter(float &omaxValue, short &omaxCoord);

	//boolean GetTriangleOnBoundary(int iIdxVertex1, int iIdxVertex2, int& oBloc, int& oIndex) ;
	//boolean WalkFromSP(int iTri13, int firstVertex, int secondVertex, int thirdVertex) ;


    fctOnStep _TheIncrementFunction;

    void IncrementStep();

	void InitDatas(const int *iTableOfIndices, int iNbIndices) ;
	void IncrementTableOfTriangles() ;


};


#endif
