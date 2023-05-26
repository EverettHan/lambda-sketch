//==============================================================================================================
// COPYRIGHT Dassault Systemes 2001 / TECHNODIGIT
//==============================================================================================================
// CATCldRshReshaper.h
// Header definition of CATCldRshReshaper
//==============================================================================================================
// Usage notes: Container classes.
//==============================================================================================================
// 14-Dec-2005 : JLH : Changement d'include "string.h -> stddef.h" pour la définition de NULL.
// 15-Dec-2003 : JLH : Ajout des méthodes GetStatistics et de sauvegarde des données initiales.
// 29-Mar-2002 : JLH : Ajout de l'Activity dans l'Init.
// 01-Oct-2001 : JLH : CATIA Integration.
// 28-Dec-2000 : PLA : Creation. (Pascal LEFEBVRE-ALBARET)
//==============================================================================================================

#ifndef CATCldRshReshaper_h
#define CATCldRshReshaper_h

#include "ExportedByCATCldResReshaper.h" // Pour la définition de ExportedByCATCldResReshaper.
#include "stddef.h"            // Pour la définition de NULL.
#include "CATBooleanDef.h"

class CATCldRshPolyedron ;
class CATCldRshArrayOfPoint ;

typedef void (*ProgressBarFunction) () ;

class ExportedByCATCldResReshaper CATCldRshReshaper
{
public:

  CATCldRshReshaper () ;
  ~CATCldRshReshaper () ;

  /**
   * Initialization of the internal tolerances.<br>
   * @param iEpsilonDouble
   * Relative accuracy (12 digits by default for the double).
   * @param iEpsilonFloat
   * Relative accuracy (5 digits by default for the float).
   * @param iAbsoluteAccuracy
   * Absolute accuracy.
   * @param iZeroDouble
   * Under this number we considere the number equal to ZERO.
   * @param iZeroFloat
   * Under this number we considere the number equal to ZERO.
   */
  static void SetTolerances (const double iEpsilonDouble    = 1.e-12, 
                             const float  iEpsilonFloat     = 1.e-5,
                             const float  iAbsoluteAccuracy = 1.e-5, 
                             const double iZeroDouble       = 1.e-100, 
                             const float  iZeroFloat        = 1.e-30) ;

  /**
   * Initialization of the internal data structure of the algorithm.<br>
   * @param iPolyedron
   * The polyedron to treat.
   */
  int Init (CATCldRshPolyedron* iPolyedron) ;

  /**
   * Initialization of the internal data structure of the algorithm.<br>
   * @param iNbVertices
   * The number of vertices.
   * @param iCoords
   * Coordinates of the vertices.<br>
   * The i'th vertex has as coordinates <tt>(iCoords[3*i+0],iCoords[3*i+1],iCoords[3*i+2])</tt>.
   * @param iActivity
   * Flags array to tell if a vertex is to be treated (0) or not (<>0).<br>
   * If NULL, all the vertices are to be treated.<br>
   * In fact, only triangles wiht their vertices to be treated will be treated.
   * @param iNbTriangles
   * The number of triangles.
   * @param iVertices
   * Triangles definition.<br>
   * The j'th triangle is defined by the three vertices <tt>(iVertices[3*j+0],iVertices[3*j+1],iVertices[3*j+2])</tt>.<br>
   * The coordinates of the vertices are given in the <tt>iCoords</tt> array.
   * @param iConnexes
   * Neighbourhood relationship between triangles.<br>
   * The j'th triangle has three neighbours <tt>(iConnexes[3*j+0],iConnexes[3*j+1],iConnexes[3*j+2])</tt>.<br>
   * <ul>
   * <li><tt>iConnexes[3*j+0]</tt> : Neighbour along the <tt>(iVertices[3*j+0],iVertices[3*j+1])</tt> edge.
   * <li><tt>iConnexes[3*j+1]</tt> : Neighbour along the <tt>(iVertices[3*j+1],iVertices[3*j+2])</tt> edge.
   * <li><tt>iConnexes[3*j+2]</tt> : Neighbour along the <tt>(iVertices[3*j+2],iVertices[3*j+0])</tt> edge.
   * </ul>
   * with the convention <tt>iConnexes[k] = -1</tt> if the edge is a boundary one (or free edge).
   * @return
   * Error status.<br>
   * <ul>
   * <li> 0 : No error.
   * <li> 1 : Problem during the polyedron creation.
   * <li>11 : Triangle with two confused vertices.
   * <li>12 : Triangle with itself as neighbour.
   * <li>13 : Triangle with two identical neighbours.
   * <li>14 : Two triangles coded as neighbours but without shared edge.
   * <li>15 : One-way connexity.
   * <li>16 : Two connex triangles with opposite orientation.
   * </ul>
   */
  int Init (const int      iNbVertices,
            const float*   iCoords,
            const boolean* iActivity,
            const int      iNbTriangles,
            const int*     iVertices,
            const int*     iConnexes) ;

  /**
   * Saves the initial coordinates.<br>
   * It is usefull when a treatment could be controled with regards on the certain position (as smoothing for example).
   * @return
   * A pointer to a structure storing the initial coordinates.
   */
  CATCldRshArrayOfPoint* StoreInitialCoordinates () ;

  /**
   * Resets the initial coordinates.<br>
   * It is usefull when a treatment could be controled with regards on the certain position (as smoothing for example).
   * @param iCoords
   * A pointer to a structure storing the initial coordinates.
   */
  void ResetInitialCoordinates (CATCldRshArrayOfPoint* iCoords) ;

  /**
   * Deletes the initial coordinates structure.<br>
   */
  static void DeleteInitialCoordinates (CATCldRshArrayOfPoint* &ioCoords) ;

  /**
   * Gets statistics in regards on the saved coordinates.
   * @param oNbVertices
   * Real number of vertices.
   * @param oDeviationMin
   * Minimal deviation.
   * @param oDeviationMoy
   * Mean deviation.
   * @param oDeviationMax
   * Maximal deviation.
   */
  boolean GetStatistics (int    &oNbVertices,
                         double &oDeviationMin,
                         double &oDeviationMoy,
                         double &oDeviationMax) ;

protected:

  boolean             _ToDelete ;
  CATCldRshPolyedron* _Polyedron ;

} ;

#endif
