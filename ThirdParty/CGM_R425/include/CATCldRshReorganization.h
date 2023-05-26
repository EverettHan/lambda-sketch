//==============================================================================================================
// COPYRIGHT Dassault Systemes 2001 / TECHNODIGIT
//==============================================================================================================
// CATCldRshReorganization.h
// Polygon Reorganization operator.
//==============================================================================================================
// Usage notes: Container classes.
//==============================================================================================================
// 24-Dec-2002 : JLH : Big nettoyage iostream, cout et autres printf.
//                     On ajoute le nombre d'iterations.
// 01-Oct-2001 : JLH : CATIA Integration.
// 28-Dec-2000 : PLA : Creation. (Pascal LEFEBVRE-ALBARET)
//==============================================================================================================

#ifndef CATCldRshReorganization_h
#define CATCldRshReorganization_h

#include "CATCldRshReshaper.h"

class CATCldRshPolyedron ;

typedef void (*ProgressBarFunction) () ;

/**
 * Reorganizes a mesh.<br>
 * The organization of the triangles fits as much as possible with the "flow" of the shape (eg edges or small radii).<br>
 *
 * The use of this algorithm is done in three steps :<br>
 * <ul>
 * <li>Initialization done by a call to the <tt>Init</tt> method (@see CATCldRshReshaper#Init).
 * <li>Process iteration done by a call to the <tt>Run</tt> method (@see CATCldRshReorganization#Run).
 * <li>Retreiving the temporary or final result by a call to the <tt>GetResult</tt> method (@see CATCldRshReorganization#GetResult).
 * </ul>
 */

class ExportedByCATCldResReshaper CATCldRshReorganization : public CATCldRshReshaper
{
public:

  CATCldRshReorganization () ;
  ~CATCldRshReorganization () ;

  /**
   * Does an incremental computation at each call.<br>
   * 
   * @param iNbNeighbours
   * Number of neighbours that the function will treat globaly.<br>
   * <ul>
   * <li>0 means only the direct neighbour of each triangle.
   * <li>1 means the direct neighbour and the neighbour of the neighbour.
   * <li>...
   * </ul>
   * A good value is 1 or 2 for this parameter.<br>
   * Sometimes (rarely) it can be necessary to set this parameter until 10... but remind that the reponse
   * time is about proportional to this parameter.
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
   * The maximum number of progress bar incrementations is <tt>iNbTriangles*iOptLevel</tt>.
   */
  void Run (const unsigned int   iNbNeighbours = 2,
            const double         iSinusMin     = 1.e-4,
            const unsigned int   iNbIterations = 1,
            ProgressBarFunction  iProgressBar  = NULL) ;

  /**
   * Retreives the new computed organization of the polyedron after each call of the <tt>Run</tt> method.<br>
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
  boolean GetResult (int  &oNbTriangles,
                     int* &oVertices,
                     int* &oConnexes) ;
} ;

#endif
