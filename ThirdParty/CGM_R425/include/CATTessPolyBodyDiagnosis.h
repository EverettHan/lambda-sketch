// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessPolyBodyDiagnosis
//
//===================================================================
//
// September 2010  Creation: NDO
//===================================================================
#ifndef CATTessPolyBodyDiagnosis_H
#define CATTessPolyBodyDiagnosis_H

#include "TessBodyAdapters.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "CATMapOfPtrToInt.h"
#include "CATMathInline.h"

class CATCell;


/**
Class used for logging errors occurring during construction of a CATPolyBody from
a CATCGMTessBody.
*/
class ExportedByTessBodyAdapters CATTessPolyBodyDiagnosis
{

public:

  /**
   * Definition of the errors that are logged when a problem with the tessellation data is encountered
   * during construction of the CATPolyBody.
   */
  enum Error 
  {
    /** */                                   eNoError                                 = 0x0000,

    /** */                                   eMemoryError                             = 0x0001,

    /** */                                   eBadVertex                               = 0x0100,

    /** */                                   eBadEdge                                 = 0x0200,
    /** */                                   eBadEdge_NonMatchingSurfaceVertexLine    = 0x0201,
    /** */                                   eBadEdge_NonMatchingGeometry             = 0x0202,
    /** */                                   eBadEdge_NoVertexPosition                = 0x0204,
    /** */                                   eBadEdge_InvalidNbVertices               = 0x0208,

    /** */                                   eBadFace                                 = 0x0400,
    /** */                                   eBadFace_NonManifoldSurface              = 0x0401,
    /** */                                   eBadFace_NonMatchingSurfaceVertexLine    = 0x0402
  };

public:

  /**
   * Constructor.
   */
  CATTessPolyBodyDiagnosis ();

  ~CATTessPolyBodyDiagnosis ();

public:

  /**
   * Logs an error for a cell.
   * The methods may be called several times for the same cell if different errors are encountered.
   */
  HRESULT LogError (CATCell* iCell, Error iError);

public:

  /**
   * Returns the number of cell errors that have been logged.
   */
  INLINE int GetNbCellErrors () const;

  /**
   * Returns the error code associated to the CATCell.
   */
  int GetError (CATCell* iCell) const;

public:

  /**
   * Iterator.  
   * Cycles through all the errors that are logged.
   */
  class ExportedByTessBodyAdapters Iterator
  {
  public:
    Iterator (const CATTessPolyBodyDiagnosis& iDiagnosis) : _It (iDiagnosis._CellToError) {}
    ~Iterator () {}

    /**
     * Given an iterator, returns a CATCell.
     */
    CATCell* GetCell () const;

    /**
     * Given an iterator, returns an error.
     */
    int GetError () const;

    /**
     */
    Iterator& Begin () {_It.Begin (); return *this;}

    /**
     */
    CATBoolean End () const {return _It.End ();}

    /**
     */
    Iterator& operator++ () {++_It; return *this;}

  private:
    CATMapOfPtrToInt::Iterator _It;
  };

  friend class Iterator;

private:

  // Map used for logging the tessellation errors encountered with the CATCell's of the CATPGMTessBody.
  CATMapOfPtrToInt _CellToError;

};


INLINE int CATTessPolyBodyDiagnosis::GetNbCellErrors () const
{
  return _CellToError.Size ();
}

#endif // !CATTessPolyBodyDiagnosis_H
