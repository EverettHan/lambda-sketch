//==============================================================================================================
// Copyrigth Dassault Systemes Provence 2002
//==============================================================================================================
// CATCldRshStreamer.h
//==============================================================================================================
// Usage notes:
// Reads and writes polyedron in .POLY or .STL ascii files.
// Offers a destructor of the created polyedron.
//==============================================================================================================
// 23-Dec-2002 : JLH : Creation.
//==============================================================================================================

#ifndef CATCldRshStreamer_h
#define CATCldRshStreamer_h

#include "ExportedByCATCldResReshaper.h" // Pour la definition de ExportedByCATCldResReshaper.

class CATCldRshPolyedron ;

class ExportedByCATCldResReshaper CATCldRshStreamer
{
public:

  /**
   * Creates a new CATCldRshPolyhedron from data read in an ascii POLY file and checks its integrity.
   * @param oStatus
   * Error status.
   * <ul>
   * <li>-1 : Reading error.
   * <li> 0 : No error.
   * <li> 1 : Triangle with two confused vertices.
   * <li> 2 : Triangle with itself as neighbour.
   * <li> 3 : Triangle with two identical neighbours.
   * <li> 4 : Two triangles coded as neighbours but without shared edge.
   * <li> 5 : One-way connexity.
   * <li> 6 : Two connex triangles with opposite orientation.
   * </ul>
   * @param oNoTriangle
   * Number of the corrupted triangle.
   * @return
   * TRUE, if the polygon has a good integrity, FALSE otherwise.
   */
  static void ReadPoly (char*                iFileName,
                        CATCldRshPolyedron* &oPolyedron,
                        int                 &oStatus,
                        int                 &oNoTriangle) ;

  /**
   * Saves the polyedron in an ascii STL file.
   */
  static void SaveStl (CATCldRshPolyedron* iPolyedron,
                       char*               iFileName) ;

  /**
   * Saves the polyedron in an ascii POLY file.
   */
  static void SavePoly (CATCldRshPolyedron* iPolyedron,
                        char*               iFileName) ;

  /**
   * Deletes the polyedron.
   */
  static void Delete (CATCldRshPolyedron* &ioPolyedron) ;

private:

  CATCldRshStreamer () ;
  ~CATCldRshStreamer () ;
} ;

#endif
