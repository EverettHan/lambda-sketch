//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// Packing operation on a set of surface textures: allows to set the
// textures (one texture per surface) of a full poly body in a [0;1]²
// square, without overlapping.
//
//=============================================================================
// 2008-09-19   XXC: New.
//=============================================================================

#ifndef CATPolySurfaceVertexTexturePacking_H
#define CATPolySurfaceVertexTexturePacking_H

#include "CATListPV.h"
#include "PolyhedralTexture.h"
#include "CATPolyRefCounted.h"
#include "IUnknown.h"

class ExportedByPolyhedralTexture CATPolySurfaceVertexTexturePacking: public CATPolyRefCounted
{
 public:
  CATPolySurfaceVertexTexturePacking();
  CATPolySurfaceVertexTexturePacking(const double iSpacing);
  virtual ~CATPolySurfaceVertexTexturePacking();
  
  inline void SetRasterBounds(unsigned int iRasterSize, unsigned int iRasterMin);
  
 public:
  /**@return Get the minimum space between to surface texture, in percentage of the atlas size.
   */
  inline double GetSpace() const;

  virtual HRESULT Pack(CATListPV & iListOfCharts) const;

 protected:
  virtual void ApplyScale (const CATListPV & iListOfCharts, double scaling) const;

 private:
  /** Considering a list of charts, pack all together the textures of
   *  the surfaces contained in the charts.
   *  Pure virtual method, the packing algorithm must be implemented
   *  in inherited classes, according to the purpose, needs, etc.
   */
  virtual HRESULT Pack(CATListPV & iListOfCharts, double iSquareRatio) const = 0;

 private:
  CATPolySurfaceVertexTexturePacking(const CATPolySurfaceVertexTexturePacking & iPacker);
  CATPolySurfaceVertexTexturePacking & operator = (const CATPolySurfaceVertexTexturePacking & iPacker) const;

 protected:
  // Minimum space between each chart.
  double _Spacing;
};


// Inline methods implementation
//¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

inline double CATPolySurfaceVertexTexturePacking::GetSpace() const
{
  return _Spacing;
}
#endif // !CATPolySurfaceVertexTexturePacking_H
