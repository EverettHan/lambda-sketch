//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2003
//==============================================================================================================
// CATCldBscServices.h : Services geometriques de base pour DSE, QSR et STL.
//==============================================================================================================
// 30-Jan-2020 - JLH - Recentrage au centre de la bounding box pour le calcul du barycentre, afin d'éviter les
//                     erreurs de griddage lors d'un grand nombre de points ou de coordonnées "large range".
//                     Diverses factorisations de code.
// 01-Sep-2010 - DNR - Suppression de CATCldBox.
// 26-Oct-2007 - YSN - R18SP3: Deplacer GetParameters vers CATCldTolerance et renomme GetSagAndStep()
// 24-Sep-2007 - YSN - R18SP2 Copier CATCldTopDistAnalysisOper::GetParameters vers ici.
// 20-May-2005 - JLH - Déplacement du source CATCloudEditorResources -> CATCloudBasicResources.
//                     Suppression des signatures GetPointOnCloud[Projection|Normal] remplacées par les services
//                     CATCldProjectionManager.
//                     Déplacement des autres signatures soit dans CATCldBasicServices soit en private dans le
//                     source CATCloudConstrainPolygonOper dont ils étaient au départ tirés.
//                     Ajout de InertialAxisSystem.
//                       EN GROS, ON EFFACE TOUT ET ON RECOMMENCE.
// 19-Dec-2003 - JLH - Changement de signature des services GetPointOnCloud[Projection|Normal] (suppression de
//                     la référence sur les CATCldBody*) (Ah les Copy&Paste).
// 17-Dec-2003 - JLH - Ajout des services GetPointOnCloud[Projection|Normal] pour PointOnCloud et 3DCurve.
// 05-Feb-2003 - RBD - Correction documentation dynamique
// 04-Feb-2003 - JLH - Relecture et documentation dynamique.
// 27-Jan-2003 - RBD - Creation.
//==============================================================================================================

#ifndef CATCldBscServices_H
#define CATCldBscServices_H

#include "ExportedByCATCloudBasicResources.h"

class ExportedByCATCloudBasicResources CATCldBscServices
{
public:

  /**
   * Compute the inertial axis of a cloud of points given by their coordinates.
   * The computation is done by evaluation of proper direction of the inertial
   * matrix of the points defined as :
   *
   *                / Sum (y²+z²) Sum (-xy)   Sum (-xz)   \
   * InertialMat = |  Sum (-xy)   Sum (x²+z²) Sum (-yz)   |
   *                \ Sum (-xz)   Sum (-yz)   Sum (x²+y²) /
   *
   * @param  iNbPoints
   *    Number of points in the array
   * @param  iCoords
   *    Array of dimension 3*iNbPoints
   * @param  oOrigine
   *    Coordinates of the origin wich is the barycenter.
   * @param  oEigenValues
   *    Proper values.
   * @param  oAxis
   *    Inertial Axis.
   * @return
   *    0 the Computation failed, else returns 1
   */
  static unsigned char InertialFrame (const int      iNbPoints,
                                      const float *  iCoords,
                                      double         oOrigine[3],
                                      double         oEigenValues[3],
                                      double         oAxis[3][3]) ;

  static unsigned char InertialFrame (const int      iNbPoints,
                                      const double * iCoords,
                                      double         oOrigine[3],
                                      double         oEigenValues[3],
                                      double         oAxis[3][3]) ;

  /**
   * Compute the inertial axis of a cloud of points given by their coordinates.
   * The computation is done by evaluation of proper direction of the median
   * matrix of the points defined as :
   *
   *              / Sum (x²)   Sum (xy)   Sum (xz)   \
   * MedialMat = |  Sum (xy)   Sum (y²)   Sum (yz)   |
   *              \ Sum (xz)   Sum (yz)   Sum (z²) /
   *
   * @param  iNbPoints
   *    Number of points in the array
   * @param  iCoords
   *    Array of dimension 3*iNbPoints
   * @param  oOrigine
   *    Coordinates of the origin wich is the barycenter.
   * @param  oEigenValues
   *    Proper values.
   * @param  oAxis
   *    Inertial Axis.
   * @return
   *    0 the Computation failed, else returns 1
   */
  static unsigned char MedialAxis (const int      iNbPoints,
                                   const float *  iCoords,
                                   double         oBarycenter[3],
                                   double         oEigenValues[3],
                                   double         oAxis[3][3]) ;

  static unsigned char MedialAxis (const int      iNbPoints,
                                   const double * iCoords,
                                   double         oBarycenter[3],
                                   double         oEigenValues[3],
                                   double         oAxis[3][3]) ;

  /**
   * Returns the min and max coordinates from an input array of floats
   * @param  iTableOfPointsf
   *    Array of dimension iTypeOfIndices*iNbPointsf
   * @param  iNbPointsf
   *    Number of points in the previous array
   * @param  iTableOfIndices
   *    Array of points indices to be considered. If NULL, all points will be considered
   * @param  iNbIndices
   *    Number of points to be considered. If 0 all points will be considered
   * @param  iTypeOfIndices
   *    <dl>
   *      <dt> 1 => The indices refer to a 1D array of points
   *      <dt> 2 => The indices refer to a 2D array of points
   *      <dt> 3 => The indices refer to a 3D array of points
   *    </dl>
   * @param  oMinCoord
   *    Array of iTypeOfIndices floats allocated by the calling function
   * @param  oMaxCoord
   *    Array of iTypeOfIndices floats allocated by the calling function
   * @return
   *    0 if an error occured, else returns 1
   */
  static unsigned char GetMinMaxCoords (const int      iNbPoints,
                                        const float *  iCoords,
                                        double         oMin[3],
                                        double         oMax[3]) ;

  static unsigned char GetMinMaxCoords (const int      iNbPoints,
                                        const double * iCoords,
                                        double         oMin[3],
                                        double         oMax[3]) ;

  /**
   * Compute the barycenter of a set of points given by their coordinates.
   */
  static unsigned char Barycenter (const int      iNbPoints,
                                   const float *  iCoords,
                                   double         oBarycenter[3]) ;

  static unsigned char Barycenter (const int      iNbPoints,
                                   const double * iCoords,
                                   double         oBarycenter[3]) ;

  /**
   * Returns the indices of ONE of the closest points of a given 3D point.
   * If the points are sorted, this algorithm avoid the O(n)
   * by using the sorted indices on the input datas
   * @param  iTableOfPointsf
   *    Array of dimension 3*iNbPointsf
   * @param  iNbPointsf
   *    Number of points in the previous array
   * @param  iCurrentIndex
   *    The index of the point must be >= 0 and < iNbIndices
   * @param  iTableOfIndices
   *    Array of points indices to be considered. If NULL, all points will be considered
   * @param  iNbIndices
   *    Number of points to be considered. If 0 all points will be considered
   * @param iCriterion
   *    <dl>
   *      <dt> the criterion if iTableOfPointsf is a sorted array
   *        <dt> -1 => iTableOfPointsf is not a sorted array
   *        <dt>  0 => iTableOfPointsf is a sorted array on the first column
   *        <dt>  1 => iTableOfPointsf is a sorted array on the second column
   *        <dt>  2 => iTableOfPointsf is a sorted array on the third column
   *        <dt> iCriterion must be >= -1 and < 3
   *    </dl>
   * @param  oIndexNeigh
   *    The index of the one closest point
   *    <dl>
   *        <dt> -1 => the search failed
   *        <dt> else oIndexNeigh is >= 0 and < iNbIndices
   *    </dl>
   * @param  oSqDistance
   *    The squared distance between the 2 points
   * @return
   *    0 the search failed, else returns 1
   */
  static unsigned char FindClosestPoint (const float *  iCoords,
                                         const int      iNbPoints,
                                         const int      iOrigin,
                                         const int *    iIndices,
                                         const int      iNbIndices,
                                         const int      iCriterion,
                                         int           &oClosest,
                                         float         &oSquareDistance) ;

  /**
   * Compute the transformation of the iNbPoints points described by their
   * coordinates iCoords into a new axis system (iOrigin,iAxis).
   * @param  iCoords
   *    Array of dimension 3*iNbPoints
   * @param  iNbPoints
   *    Number of points in the array
   * @param  iTableOfIndices
   *    Indices for the points, can be NULL.
   * @param  iNbIndices
   *    Number of indices in iTableOfIndices.
   * @param  iOrigin
   *    Coordinates of the new origin.
   * @param  iAxis
   *    New axis directions.
   * @param  oCoords
   *    New transformed coordinates.
   * @return
   *    0 the Computation failed, else returns 1
   */
  static unsigned char ChangeReferenceAxis (const float * iCoords,
                                            const int     iNbPoints,
                                            const int *   iIndices,
                                            const int     iNbIndices,
                                            const double  iOrigin[3],
                                            const double  iAxis[3][3],
                                            float *       oCoords) ;

  /**
   * Returns the characteristic distance between two points in the input array
   * @param  iTableOfPointsf
   *    Array of dimension iTypeOfIndices*iNbPointsf
   * @param  iNbPointsf
   *    Number of points in the previous array
   * @param  iTableOfIndices
   *    Array of points indices to be considered. If NULL, all points will be considered
   * @param  iNbIndices
   *    Number of points to be considered. If 0 all points will be considered
   * @param  iTypeOfIndices
   *    <dl>
   *      <dt> 1 => The indices refer to a 1D array of points
   *      <dt> 2 => The indices refer to a 2D array of points
   *      <dt> 3 => The indices refer to a 3D array of points
   *    </dl>
   * @param  oDist
   *    Result of the function
   * @return
   *    0 if an error occured, else returns 1
   */
  static unsigned char GetCharactDist (const float *  iCoords,
                                       const int      iNbPoints,
                                       const int *    iIndices,
                                       const int      iNbIndices,
                                       short          iDim,
                                       float         &oDistance) ;

  /**
   * Returns the min and max coordinates from an input array of floats
   * @param  iTableOfPointsf
   *    Array of dimension iTypeOfIndices*iNbPointsf
   * @param  iNbPointsf
   *    Number of points in the previous array
   * @param  iTableOfIndices
   *    Array of points indices to be considered. If NULL, all points will be considered
   * @param  iNbIndices
   *    Number of points to be considered. If 0 all points will be considered
   * @param  iTypeOfIndices
   *    <dl>
   *      <dt> 1 => The indices refer to a 1D array of points
   *      <dt> 2 => The indices refer to a 2D array of points
   *      <dt> 3 => The indices refer to a 3D array of points
   *    </dl>
   * @param  oMinCoord
   *    Array of iTypeOfIndices floats allocated by the calling function
   * @param  oMaxCoord
   *    Array of iTypeOfIndices floats allocated by the calling function
   * @return
   *    0 if an error occured, else returns 1
   */
  static unsigned char GetMinMaxCoords (const float * iCoords,
                                        const int     iNbPoints,
                                        const int *   iIndices,
                                        const int     iNbIndices,
                                        short         iDim,
                                        float *       oMin,
                                        float *       oMax) ;

  /**
   * Returns the min box containing the cloud
   * @param  iTableOfPointsf
   *    Array of dimension iTypeOfIndices*iNbPointsf
   * @param  iNbPointsf
   *    Number of points in the previous array
   * @param  iTableOfIndices
   *    Array of points indices to be considered. If NULL, all points will be considered
   * @param  iNbIndices
   *    Number of points to be considered. If 0 all points will be considered
   * @param  iTypeOfIndices
   *    <dl>
   *      <dt> 1 => The indices refer to a 1D array of points
   *      <dt> 2 => The indices refer to a 2D array of points
   *      <dt> 3 => The indices refer to a 3D array of points
   *    </dl>
   * @param  oBoxDimension[3]
   *    The box dimension
   * @param  oBoxAxis[9]
   *    The three axes of the land mark coordinate system
   * @param  oBoxCenter[3]
   *    The origin of the land mark coordinate system
   * @param  oBoxOrigin[3]
   *    The origin of the cloud box
   * @return
   *    0 if an error occured, else returns 1
   */
  static unsigned char GetMinBox (const float * iCoords,
                                  const int     iNbPoints,
                                  const int *   iIndices,
                                  const int     iNbIndices,
                                  short         iDim,
                                  float         oBoxDimension[3],
                                  float         oBoxAxis[9],
                                  float         oBoxCenter[3],
                                  float         oBoxOrigin[3]) ;

private:
  CATCldBscServices() ;
  ~CATCldBscServices() ;

  static unsigned int _FillInertiaMatrix (const int      iNbPoints,
                                          const float *  iCoords,
                                          const double   iBarycenter[3],
                                          double         oMatrix[6]) ;

  static unsigned int _FillInertiaMatrix (const int      iNbPoints,
                                          const double * iCoords,
                                          const double   iBarycenter[3],
                                          double         oMatrix[6]) ;

  static unsigned int _FillQuadricMatrix (const int      iNbPoints,
                                          const float *  iCoords,
                                          const double   iBarycenter[3],
                                          double         oMatrix[6]) ;

  static unsigned int _FillQuadricMatrix (const int      iNbPoints,
                                          const double * iCoords,
                                          const double   iBarycenter[3],
                                          double         oMatrix[6]) ;

  static unsigned int _Diagonalize (double ioMatrix[3],
                                    double oEigenValues[3],
                                    double oEigenVectors[3][3]) ;
} ;

#endif
