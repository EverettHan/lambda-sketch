// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonIO2D.h
//
//===================================================================
// October 2006  Creation: ndo
//===================================================================
#ifndef CATPolyPolygonIO2D_h
#define CATPolyPolygonIO2D_h

#include "PolygonalModel.h"
#include "CATErrorDef.h"  // HRESULT
#include "CATUnicodeString.h"

class CATPolyPolygon2D;
class CATPolyVertex2D;



/**
* A streaming utility to write and read polygons from text files.
*/
class ExportedByPolygonalModel CATPolyPolygonIO2D
{

public :

  CATPolyPolygonIO2D ();

public:

  /**
   * Reads a polygon from a file.  
   * @param iFileName
   *   The name of the polygon file.
   * @param oPolygon
   *   An empty polygon that is populated during the read.
   * @return
   * <ul>
   *   <li> <code> S_OK </code> on success.
   *   <li> <code> E_FAIL </code> or an other error code otherwise.
   * </ul>
   */
  HRESULT Read (const CATUnicodeString& iFileName, CATPolyPolygon2D& oPolygon);


  /**
   * User entry point to insert user data has comment  in the output file
  */
  class ExportedByPolygonalModel UserStreamer
  {
    public:
    virtual CATUnicodeString Stream(CATPolyVertex2D & v2d) ;    
  };

  /**
   * 
   * Streamer called to add comment in the output 
  */
  void SetUserStreamer(UserStreamer * iUserStream);
  /**
   * Writes a polygon to a file.  
   * @param iFileName
   *   The name of the polygon file.
   * @param iPolygon
   *   A polygon to write in the file.
   * @return  
   * <ul>
   *   <li> <code> S_OK </code> on success.
   *   <li> <code> E_FAIL </code> or an other error code otherwise.
   * </ul>
   */
  HRESULT Write (const CATUnicodeString& iFileName, const CATPolyPolygon2D& iPolygon);

public:

  /**
   * @deprecated
   */
  HRESULT Read (const CATUnicodeString& iFileName, CATPolyPolygon2D* oPolygon);

  /**
   * @deprecated
   */
  HRESULT Write (const CATUnicodeString& iFileName, CATPolyPolygon2D* iPolygon);

protected:
  UserStreamer * _UserStreamer;
};

#endif

