//=============================================================================
// <ClassName>: CATStTrianglesRemovalOper
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
// November 98   Creation                                   F. LETZELTER
// February 2000 Update                    R. BERAUD
//               Modification of the algorithm to keep the constrained triangles
// 19-Jan-2004 - JLH - Eradication des 'long's.
//=============================================================================

#ifndef CATStTrianglesRemovalOper_H
#define CATStTrianglesRemovalOper_H

#include "ExportedByCATCloudBasicResources.h"
class CATCldCloud ;

class ExportedByCATCloudBasicResources CATStTrianglesRemovalOper
{

public:

  class T_Cloud {
  public:
    /**
     * GetCoords returns the 3D coordinates of the <tt>iIndex</tt>'th point.
     */
    virtual void GetCoords (const int iIndex, float oCoords[3]) const = 0 ;
  } ;

  // Constructor
  // iTableOfPointsf      : Pointer on the table of points where are stored the 3 coordinates of 
  //                the vertices (const)
  // iTableOfVertices      : Pointer on the table of indices that refer to the point in the previous
  //                table. 3 following indices compose a triangle (const)
  // iNbVertices        : Length of this table
  // iTableOfAdjacence    : Pointer on the table of indices that indicates which triangle is adjacent to
  //                another
  // iNbAdjacence        : Length of this table
  // iMaxSideLength      : Max length for a triangle. If one of its sides is larger than this value
  //                the triangle will be removed in the table given by the GetResult function
  //
  // !!! It is supposed that the table of vertices contains correct indices, that don't overpass the length
  // of the points table !!!
  // Moreover, it is supposed that the length of the table of vertices is a 3-multiple because to create
  // a triangle, we need 3 vertices !!!
  // NO CHECK IS HERE !!! BE CAREFUL !!
  CATStTrianglesRemovalOper (const T_Cloud *iPtrCloud,
                             const int *iIndexesOfVertices, const int iNbVertices, \
                             /*const int *iTableOfAdjacence, int iNbAdjacence, \*/
                             const float iMaxSideLength, const int *iTriConstrained) ;

  CATStTrianglesRemovalOper (const float *iTableOfPointsf, \
                             const int *iTableOfVertices, int iNbVertices, \
                             /*const int *iTableOfAdjacence, int iNbAdjacence, \*/
                             float iMaxSideLength) ;

  // Destructor
  ~CATStTrianglesRemovalOper() ;

  // Set the max side length of the resulting triangles
  void SetMaxSideLength (float iMaxSideLength) ;

  // Run the algorithm. Can be run on the same operator with different lengths
  void Run() ;

  // Return a pointer on the table of triangles that were not removed
  // oTableOfVertices      : Pointer on the table of Vertices that weren't deleted.
  //                !!!! This table is allocated in the operator but must be deleted
  //                by the calling function !!!!
  // oNbVertices        : Length of the table (number of elements in the table and not of triangles)
  // oTableOfAdjacence    : Pointer on the table of adjacent triangles that weren't deleted.
  //                !!!! This table is allocated in the operator but must be deleted
  //                by the calling function !!!!
  // oNbAdjacence        : Length of the table (number of elements in the table and not of triangles)
  void GetResult (int **oTableOfVertices, int &oNbVertices/*, \
           int **oTableOfAdjacence, int &oNbAdjacence*/) ;

private:

  const T_Cloud *_ptrCloud ; // Pointer on the table of points

  const int   *_indexesOfVertices ; // Pointer on the table of vertices
  const float *_tableOfPointsf ;    // Pointer on the table of points

  const int *_tableOfVertices ; // Pointer on the table of vertices
  int        _nbVertices ;      // Length of the table

  float _maxSideLength ; // Max length of a triangle side (square of)

  const int *_tableOfTriConstrained ; // Table of flags on the (_nbVertices)/3 triangles :
                                      // The ith triangle must be kept if _tableOfTriConstrained[i] == 1,
                                      // The ith triangle must be removed if _tableOfTriConstrained[i] == -1,
                                      // The ith triangle must tested with _maxSideLength if _tableOfTriConstrained[i] == 0.
  int *_indexesOfKeptVertices ; // Pointer on the resulting table of vertices
  int *_tableOfKeptVertices ;   // Pointer on the resulting table of vertices
  int  _nbKeptVertices ;        // Length of this table
} ;

#endif
