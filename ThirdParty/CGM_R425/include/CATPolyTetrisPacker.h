// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyTetrisPacker.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// Nov 2008  Creation: ZFI
//===================================================================

#ifndef CATPolyTetrisPacker_H
#define CATPolyTetrisPacker_H

#include "CATPolyVisuTetrisAtlas.h"
#include "CATPolySurfaceVertexTexturePacking.h"

#include "CATErrorDef.h"
#include "CATListPV.h"

class ExportedByPolyVisuTetrisAtlas CATPolyTetrisPacker: public CATPolySurfaceVertexTexturePacking
{
public:  
  //constructor and destructor
  CATPolyTetrisPacker(double iSpacing);
  virtual ~CATPolyTetrisPacker();

public:
  virtual HRESULT Pack(CATListPV & iListOfCharts, double iSquareRatio) const;

  //get/set
public:
  inline HRESULT SetNbDirections(const int iNbDirections);
  inline int GetNbDirections()const;

private:
  static int SortByHeight (const void * chart1, const void* chart2);
  static double TotalChartsArea (const CATListPV & iListOfCharts);

private:
  int _NbDirections;
};

inline HRESULT CATPolyTetrisPacker::SetNbDirections(const int iNbDirections)
{
  _NbDirections = iNbDirections;
  return S_OK;
}
inline int CATPolyTetrisPacker::GetNbDirections()const
{
  return _NbDirections;
}

#endif
