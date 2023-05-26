// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBaseSpatialPartitionOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  aug 2004 Creation: dhp
//===================================================================
#ifndef CATPolyBaseSpatialPartitionOper_h
#define CATPolyBaseSpatialPartitionOper_h

#include "CATPolyAnalyzeOperators.h"
#include "CATListOfInt.h"
#include "CATListPV.h"
#include "CATMathBox.h"

class CATCGMOutput;
class CATMathPoint;

class ExportedByCATPolyAnalyzeOperators CATPolyBaseSpatialPartitionOper 
{
  
public :

  CATPolyBaseSpatialPartitionOper (const int sizeX,
    const int sizeY,
    const int sizeZ);

  virtual ~CATPolyBaseSpatialPartitionOper (void);

  /* HRESULT Run (const int sizeX,
    const int sizeY,
    const int sizeZ); */

  void SetBox (const CATMathBox & box);

  void Print (CATCGMOutput & stream) const;

protected :

  virtual CATBoolean CleanupCell (void * cell);

  virtual void PrintCell (CATCGMOutput & stream,
    void * cell) const;

  void GetSize (int & sizeX,
    int & sizeY,
    int & sizeZ) const;

  CATBoolean CellIndicesOk (const int x,
    const int y,
    const int z) const;

  void * FindCell (const int x,
    const int y,
    const int z) const;

  void SetCell (const int x,
    const int y,
    const int z,
    void * cell);

  void GetCells (CATListOfInt & cellsX,
    CATListOfInt & cellsY,
    CATListOfInt & cellsZ) const;

  CATBoolean GetCellBox (const int x,
    const int y,
    const int z,
    CATMathBox & box) const;

  void GetCells (const CATMathPoint & point,
    const double distance,
    CATListPV & cells) const;

  void GetBarCellsFromPoints (const CATMathPoint & point0,
    const CATMathPoint & point1,
    CATListOfInt & cellsX,
    CATListOfInt & cellsY,
    CATListOfInt & cellsZ) const;

  CATBoolean GetCellFromPoint (const CATMathPoint & point,
    int & cellX,
    int & cellY,
    int & cellZ) const;

  CATBoolean IsContaining (const CATMathBox & box) const;

  void CleanupCells (void);

  CATBoolean BoxSet (void) const;


protected:
  int _sizeX;
  int _sizeY;
  int _sizeZ;

private :

  void SetupPartition (void);

  CATMathBox _box;

  double _boxLowX;
  double _boxLowY;
  double _boxLowZ;

  double _boxHighX;
  double _boxHighY;
  double _boxHighZ;

  double _boxSizeX;
  double _boxSizeY;
  double _boxSizeZ;

  double _cellSizeX;
  double _cellSizeY;
  double _cellSizeZ;

  void ** _cells;

};

#endif
