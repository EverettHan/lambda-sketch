//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2010
//==============================================================================================================
// File: CAT3DDelaunayMesh.h
//==============================================================================================================
// Usage:
//==============================================================================================================
// 19-Aug-2020 - PMG - Ajout de FindTetra.
// 15-Sep-2010 - FV2 - Check sources + Memory check + respect conventions CAA
// 09-Sep-2010 - FV2 - Documentation + relecture code
// 27-May-2010 - FV2 - Creation
//==============================================================================================================

#ifndef CAT3DDelaunayMesh_h
#define CAT3DDelaunayMesh_h

#include "ExportedByCATCldResMeshInria.h"

/**
 * Interface to NRDelaunay in order to create a volumic delaunay mesh.
 * 
 **/
class ExportedByCATCldResMeshInria CAT3DDelaunayMesh {
public:
  struct CircumSphere
  {
    float _CenterCoords[3];
    float _Radius;
  };
  /**
   * Creation of the delaunay mesh with the list of points (iP) and association of a index to
   * every point in the delaunay mesh.
   *
   * @param iP Array of input points.
   * @param iI Array of indices in the same order than <tt>iP</tt>
   * @param iN Size of <tt>iP</tt> and <tt>iI</tt> arrays.
   **/
	static CAT3DDelaunayMesh* CATCreate3DDelaunayMesh(float **iP, int *iI, int iN);

  ////////////////
  static CAT3DDelaunayMesh* CATCreate3DDelaunayMesh(float iBBMin[3], float iBBMax[3]);

  
  /**
   * Insertion of a point into the delaunay mesh and association of the index to
   * the point in the delaunay mesh.
   *
   * @param iX x coordinate of the point
   * @param iY y coordinate of the point
   * @param iZ z coordinate of the point
   * @param iI index of the point
   *
   * @return <tt>0</tt> if the insertions finished normally and <tt>-1</tt> otherwise.
   **/
  virtual int insertPoint(const float iX, const float iY, const float iZ, const int iI) = 0;

  /**
   * Method to retrieve the list of tetraedron created by the delaunay mesher.
   * Note : Indices that are <tt><= 0</tt> in the array are indices of bounding box points.
   *
   * @param oTetra array of vertices indices of all the tetraedron in the mesh.
   * @param oNbTetra number of tetraedron
   **/
  virtual void GetListOfTetra(int**& oTetra, int& oNbTetra) = 0;


  virtual void GetListOfCircumCenters(CircumSphere *&TetraCircumSphere, int& nTetra) = 0;


  /**
   * Method to retrieve the list of triangles created by the delaunay mesher.
   * Note : Indices that are <tt><= 0</tt> in the array are indices of bounding box points.
   *
   * @param oTri list of vertices indices of all the triangles in the mesh.
   * @param oNbTri number of triangles
   **/
  virtual void GetListOfTriangles(int**& oTri, int& oNbTri) = 0;

  /**
   * Retrieve the sum of the diedral angles corresponding to the edge composed by <tt>iV1</tt> and <tt>iV2</tt> 
   * in every tetraedron sharing this edge.
   *
   * @param iE1 index of the first point of the edge
   * @param iE2 index of the second point of the edge
   *
   * @return The sum of the diedral angles
   **/
  virtual double SumOfDiedralAngles(const int iV1, const int iV2) = 0;

  virtual void GetListOfVorVertices (float* ***& pts, int& nSites, int* &nbOfFaces, int** &nVertex) = 0;
  virtual void GetListOfDelauVertices (float * *** & pts, int & ntetra)= 0 ;

  virtual bool FindTetra(float iP[3], int idx[4], int& oVertex) = 0;

  /**
   * Destructor
   **/
  virtual ~CAT3DDelaunayMesh();

protected:
  CAT3DDelaunayMesh(){}
};

#endif
