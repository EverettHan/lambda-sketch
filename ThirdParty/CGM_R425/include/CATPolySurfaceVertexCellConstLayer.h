// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolySurfaceVertexCellConstLayer.h
//
//===================================================================
// October 2009  Creation: NDO
//===================================================================
#pragma once

#include "PolyMeshImpl.h"
#include "CATIPolySurfaceVertexCellConstLayer.h"
#include "CATMapOfIntToInt.h"

class CATPolyFace;
class CATPolyBodyDiagnosis;
class CATPolyBodyCheckerObserver;


/**
This is a read-only surface vertex cell layer.  It cannot be modified after its construction.
*/
class ExportedByPolyMeshImpl CATPolySurfaceVertexCellConstLayer : public CATIPolySurfaceVertexCellConstLayer
{

public:

  /**
   * Constructs a new CATPolySurfaceVertexCellConstLayer for a face.
   * @param iPolyFace
   *   The input CATPolyFace.
   * @param iDiagnosis
   *   An optional object to log the errors encountered during the construction of the surface vertex cell layer.
   * @param obs
   *   An optional object to finer log errors.
   */
  static CATPolySurfaceVertexCellConstLayer* New (const CATPolyFace& iPolyFace, CATPolyBodyDiagnosis* ioDiagnosis = 0, CATPolyBodyCheckerObserver * obs = 0);

public:

  HRESULT Get (int iVertex, CATPolyCell *&oCell, int &oCellVertex) const;

public:

  /**
   * Returns the size of the object in bytes.
   */
  unsigned int SizeOf () const;

  /**
   * Compares the pairs (iCell1, iCellVertex1) and (iCell2, iCellVertex2).
   * Updates the diagnosis if available and if there is a difference between the two pairs.
   * @return
   * <ul>
   *   <li> S_OK if the two pairs are the same.
   *   <li> S_FALSE if the two pairs are different.
   * </ul>
   */
  static HRESULT CompareCells (const CATPolyCell* iCell1, const int iCellVertex1, 
                               const CATPolyCell* iCell2, const int iCellVertex2,
                               CATPolyBodyDiagnosis* ioDiagnosis = 0,   // Optional.
                               CATPolyBodyCheckerObserver * obs = 0);   // Optional.

private:

  struct Cell
  {
    CATPolyCell* _PolyCell;
    int _CellVertex;
  };

  Cell* _Cells;                    // Fixed-size array of cells (minimum incident cell at a surface-vertex).
  CATMapOfIntToInt _MapSVToIndex;  // Map a surface-vertex to an index in the above array.

private:

  friend class CATPolySurfaceVertexCellLayer;

  /**
   * Counts the number of surface-vertex cells for a CATPolyFace.
   */
  static int CountVertexCells (const CATPolyFace& iPolyFace);

  /**
   * Initializes the cell associated to a surface-vertex.
   * The number of distinct surface-vertices supported by this method is the size set in the constructor.
   * The number iCountCells ranges from 0 to iNbSVCells - 1.  For each new vertex, during initialization
   * of the layer, iCountCells should be incremented by one:
   *   o The initial value is 0.  
   *   o The final value is iNbSVCells - 1.
   * Be careful, this method does not do any bound checking.
   */
  static HRESULT InitCell (Cell cells[], CATMapOfIntToInt& mapSVToIndex,
    int sv, int iCountCells, CATPolyCell* iCell, int iCellVertex,
    CATPolyBodyDiagnosis* ioDiagnosis, CATPolyBodyCheckerObserver* obs = 0);

  static HRESULT Initialize (Cell cells[], CATMapOfIntToInt& mapSVToIndex,
    const CATPolyFace& iPolyFace, CATPolyBodyDiagnosis* ioDiagnosis = 0, CATPolyBodyCheckerObserver* obs = 0);

private:

  /**
   * Constructs a surface vertex layer for a given number of cells.
   */
  CATPolySurfaceVertexCellConstLayer (const int iNbSVCells);

  virtual ~CATPolySurfaceVertexCellConstLayer ();

};
