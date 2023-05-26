/**
 *  Large Range compatibility certified by DNR (2014-05-21)
 */
//=============================================================================================== //
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2008                                                      //
//=============================================================================================== //

// ============================================================================================== //
//  File: CATM2DPolygonizeOper.h                                                                  //
// ---------------------------------------------------------------------------------------------- //
//  Delaunay mesher of a cloud of 2D points.                                                      //
// ---------------------------------------------------------------------------------------------- //
// 31-Jan-2022 - JLH - Portage Linux :
//                     Suppression des warnings et des erreurs de compilation en mode non-permissif.
// ..-May-2008 - UNZ - Création.Stagiaire de GDD - Direction Scientifique DSP
// ============================================================================================== //

#ifndef CATM2DDelaunayMesher_h
#define CATM2DDelaunayMesher_h

#include "ExportedByCATCloudBasicResources.h"
#include "stddef.h"

//=============================================================================================== //
//	Class CATM2DDelaunayMesher	       	                                						              //
//=============================================================================================== //

class ExportedByCATCloudBasicResources CATM2DDelaunayMesher 
{
public :

  // =====   Nested class : T_2DCloud   ==============================================================
  class T_Cloud {
  public:
    /**
     * GetNbPoints returns the number of points in the cloud.
     */
    virtual int GetNbPoints() const = 0 ;
    /**
     * GetCoords returns the 2D coordinates of the <tt>iNum</tt>'th point.
     */
    virtual void GetCoords (const int iNum, double oCoords[2]) const = 0 ;
    /**
     * isToBeTreated returns 1 if the 'iNum'th point has to be treated else returns 0.
     */
    virtual int isToBeTreated (const int iNum) const = 0 ;
    /**
     * Virtual destructor.
     */
    virtual ~T_Cloud(){} ;
  } ;

  /**
   * Constructor.
   * @param
   * The cloud of points to be meshed.
   */
  static CATM2DDelaunayMesher* CreateOperator (const T_Cloud * iCloud) ;

  /**
   * Constructor.
   * @param iNbOf2DPoints
   * Number of points.
   * @param iTableOf2DPoints
   * Array of 2D-coordinates.
   * @param iNbToBeTreated
   * Number of points to be treated.
   * @param iToBeTreated
   * Indexes array of the points to be treated.<br>
   * If NULL, all the points will be meshed.
   */
  static CATM2DDelaunayMesher* CreateOperator (const int	   iNbOf2DPoints,
								                               const double* iTableOf2DPoints,
                                               const int     iNbToBeTreated = 0,
                                               const int*    iToBeTreated = NULL) ;
  /**
   * Constructor.
   * @param iNbOf2DPoints
   * Number of points.
   * @param iTableOf2DPoints
   * Array of 2D-coordinates.
   * @param iNbToBeTreated
   * Number of points to be treated.
   * @param iToBeTreated
   * Indexes array of the points to be treated.<br>
   * If NULL, all the points will be meshed.
   */
  static CATM2DDelaunayMesher* CreateOperator (const int	  iNbOf2DPoints,
								                               const float* iTableOf2DPoints,
                                               const int    iNbToBeTreated = 0,
                                               const int*   iToBeTreated = NULL) ;

  /**
   * Computes a Delaunay tesselation on the cloud.<br>
   * Call the Delaunay algorithm in O(nln n) complexity.
   * @return
   * Computation status
   * <ul>
   * <li><tt> 0</tt> : no error occured.
   * <li><tt>>0</tt> : an error occured during the computation.
   * </ul>
   */
	virtual int Run() = 0 ;

  /**
   * Removes free edges in order to get the mesh envelope.<br>
   * This method sets the Crust Value: all the free edges longer than this value will be removed.
   *
   * @param crustValue
   * Minimum length of free edges to remove
   * <ul>
   * <li>Negative value: Does not compute the crust.<br>
   * <li>Stricly positive value: Computes crust with this value.<br>
   * </ul>
   */
  virtual void SetCrustValue (const double iCrustValue) = 0;

  // GDD le 21-07-2011 : Pour le Crust sur toutes les aretes
  virtual void SetCrustAll () = 0;

  /**
   * Retreives the computed description of the mesh after call of the <ttt>Run</ttt> method.<br>
   * Remarks:
   * <ul>
   * <li>Orientation is CCW for each triangle.
   * <li>If a positive crust value has been set (SetCrustValue), the result will be crusted.
   * </ul>
   * <br>
   * <b>If Format = 0:</b><br>
   *
   * @param oNbTriangles
   * Number of triangles of the computed mesh.
   *
   * @param oTriangles
   * Array of triangles describing the mesh.<br>
   * Each triangle is 3-number in the original array of points or cloud.<br>
   * The size of <tt>oTriangles</tt> array is 3*oNbTriangles.<br>
   * CAUTION: This array must be deleted by the caller.
   *
   * <br>
   * <b>If Format = 1:</b><br>
   * <b>CAUTION: This syntax has no meaning when the operator was created thanks to a T_2DCloud.</b><br>
   *
   * @param oNbTriangles
   * Number of VERTICES of the new mesh (equals to 3 times the number of triangles of the mesh).
   * 
   * @param oTriangles
   * Array of VERTICES that describes the tesselation.<br>
   * Each vertex is described as the index of its first coordinate (X-coordinate) in the original array of points.<br>
   * CAUTION: This array must be deleted by the caller.<br>
   */
	virtual int GetResult (int  & oNbTriangles,
                         int* & oTriangles,
                         const int iFormat = 0) = 0 ;

  /** oConnexes : Table des triangles connexes (numerotation commence a 0)
  *             Meme signification pour le Format
  */
	virtual int GetResult (int  &oNbTriangles, int * &oTriangles, int * &oConnexes, const int iFormat = 0) = 0 ;

/**
  * Give an array of index of triangles to invalidate. The index are based on the <tt>GetResult</tt> array
  * 
  * @param iNbTrianglesToInvalidate
  * Number of index in the array of TRIANGLES to Invalidate.
  * 
  * @param iIndexTriangleToInvalidate
  * Array of index of TRIANGLES to invalidate.
  * Rem : The array must sorted (indexes in the array must go from the min index to the max)
  */
	virtual  int SetInvalidTriangles (int &iNbTrianglesToInvalidate, int * &iIndexTriangleToInvalidate) = 0 ;

  /**
   * Sets values in order to regularize free edges.<br>
   *
   * @param iLngMinRegul
   * Minimum length for edges.
   *
   * @param iAngMinRegul
   * Minimum angle in degrees between edges.
   *
   * @param iRegularize
   * Compute the regularization or not
   * <ul>
   * <li>1: Computes the regularization.<br>
   * <li>0: Doesn't compute the regularization. <br>
   * </ul>
   */
  virtual void SetFreeEdgeRegulValues (const double iLngMinRegul,
                                       const double iAngMinRegul,
                                       const int    iRegularise) = 0  ;

  /**
   * Retrieves the computed desciption of the free edges.<br>
   * If a positive crust value has been set, the result will be the free edges of the crusted mesh.<br>
   *
   * @param oLstFreeEdges
   * Array of integers (indexes in the initial cloud of points) of the points describing to the free edges.<br>
   * In case of several free edges they are separeted by -1.<br>
   * Example of two free edges:<br>
   * The returned value is 13 the dimension of oLstFreeEdges, and the values could be :<br>
   * <pre>
   *           { 0, 1, 2, 3, 4, 0, -1, 10, 11, 12, 13, 10, -1}
   *            ^----------------^    ^------------------^
   *              First contour     |     Second contour  |
   * </pre>
   * CAUTION: This array must be deleted by the caller.
   */
  virtual int GetFreeEdges (int* & oLstFreeEdges) = 0 ;

  virtual ~CATM2DDelaunayMesher();
} ;
#endif
