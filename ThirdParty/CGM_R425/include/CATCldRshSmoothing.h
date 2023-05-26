//==============================================================================================================
// COPYRIGHT Dassault Systemes 2002 / TECHNODIGIT
//==============================================================================================================
// CATCldRshSmoothing.h
// Polygon Smoothing operator.
//==============================================================================================================
// Usage notes: Container classes.
//==============================================================================================================
// 24-Dec-2002 : JLH : Big nettoyage iostream, cout et autres printf.
//                     On ajoute le nombre d'iterations.
// 29-Mar-2002 : JLH : Ajout de l'Activity dans GetResult.
// 18-Feb-2002 : JLH : Creation.
//==============================================================================================================

#ifndef CATCldRshSmoothing_h
#define CATCldRshSmoothing_h

#include "CATCldRshReshaper.h"

class CATCldRshPolyedron ;

typedef void (*ProgressBarFunction) () ;

/**
 * Recomputes the vertices of a polyedron to smooth the surface.<br>
 * The use of this algorithm is done in three steps :<br>
 * <ul>
 * <li>Initialization done by a call to the <tt>Init</tt> method (@see CATCldRshReshaper#Init).
 * <li>Process iteration done by a call to the <tt>Run</tt> method (@see CATCldRshReorganization#Run).
 * <li>Retreiving the temporary or final result by a call to the <tt>GetResult</tt> method (@see CATCldRshReorganization#GetResult).
 * </ul>
 */

class ExportedByCATCldResReshaper CATCldRshSmoothing : public CATCldRshReshaper
{
public:

  CATCldRshSmoothing () ;
  ~CATCldRshSmoothing () ;

  /**
   * Does an incremental computation at each call.<br>
   * 
   * The parameters SmoothCoef and NbIterations allow to adjust the strengh and area of smoothing.<br>
   * Example :
   * <ul>
   * <li> > SmoothCoef=0.5 and NbIterations=1 will give you the strongest local smoothing.
   * <li> > SmoothCoef=0.1 and NbIterations=5 will give you the same intensity, but a more global smoothing.
   * </ul>
   * 
   * @param iSmoothingCoef
   * Smoothing coefficient.<br>
   * When a vertex is a recomputed point, the new coordinates are recomputed according to the formula:<br>
   * <tt>NewCoord = iSmoothCoef * RecomputedCoord + (1-Coef) * OldCoord.</tt>
   * 
   * @param iNbIterations
   * The number of iterations of the smoothing operation.
   * 
   * @param iSmoothingType
   * Filter smoothing type :
   * <ul>
   * <li>1 : order 1 filter. Very smooth filter.<br>
   * The small radii are becoming greater even if the reorganization limits this problem.<br>
   * In this case, the parameter maxi deviation has no effect.
   * <li>2 : order 2 filter.<br>
   * More complex filter that allows to limit as much as possible encreasing the radii and allows the deviation control.
   * </ul>
   * 
   * @param iMaxDeviation
   * Maximum deviation.<br>
   * The distance beetween the vertices before smoothing and after smoothing must not exceed this value
   * after all the smoothing iterations.<br>
   * If equals zero, no check is done.
   * 
   * @param iNbNeighbours
   * If this parameter is not -1, a reorganization is asked beetween all the smoothing iterations.<br>
   * Number of neighbours that the function will treat globaly.<br>
   * <ul>
   * <li>0 means only the direct neighbour of each triangle.
   * <li>1 means the direct neighbour and the neighbour of the neighbour.
   * <li>...
   * </ul>
   * A good value is 1 or 2 for this parameter.<br>
   * Sometimes (rarely) it can be necessary to set this parameter until 10... but remind that the reponse time
   * is about proportional to this parameter multiplied by the iterations number.
   * 
   * @param iSinusMin
   * Sinus of the thinest triangle authorised to be created.<br>
   * A good value is 0.0001.
   * 
   * @param iNbIterations
   * Number of iterations [1,10].
   * 
   * @param iProgressBar
   * Progress bar.<br>
   * The maximum number of progress bar incrementations is <tt>3*iNbIterations</tt>.
   */
  void Run (const double         iSmoothingCoef,
            const int            iSmoothingType,
            const double         iMaxDeviation,
            const int            iNbNeighbours = -1,
            const double         iSinusMin     = 1.e-4,
            const unsigned int   iNbIterations = 1,
            ProgressBarFunction  iProgressBar  = NULL) ;

  /**
   * Retreives the computed description of the polyedron after each call of the <tt>Run</tt> method.<br>
   * 
   * @param oNbVertices
   * Number of vertices of the new polyedron (should be the same than the initial one).
   * 
   * @param oVertices
   * Array of the vertices description of the triangles.
   * 
   * @param oActivity
   * Array of the activity of the vertices.
   * 
   * @param oNbTriangles
   * Number of triangles of the new polyedron (should be the same than the initial one).
   * 
   * @param oVertices
   * Array of the vertices description of the triangles.
   * 
   * @param oConnexes
   * Array of the neighbouring relationship between triangles.
   * 
   * @return
   * TRUE, if there is a result. FALSE, otherwise.
   */
  boolean GetResult (int      &oNbVertices,
                     double*  &oCoords,
                     boolean* &oActivity,
                     int      &oNbTriangles,
                     int*     &oVertices,
                     int*     &oConnexes) ;
} ;

#endif
