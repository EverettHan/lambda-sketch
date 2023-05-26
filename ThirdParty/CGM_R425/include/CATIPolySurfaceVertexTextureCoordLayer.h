//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// Layer of per-surface-vertex texture coordinates interface
//
//=============================================================================
// 2008-10-16   ZFI: add tangents, binormals, scale
// 2008-04-17   BPG: New.
//=============================================================================
#pragma once

#include "PolyhedralAttributes.h"
#include "CATIPolySurfaceVertexTextureCoordConstLayer.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"


class ExportedByPolyhedralAttributes CATIPolySurfaceVertexTextureCoordLayer : public CATIPolySurfaceVertexTextureCoordConstLayer
{

public:

  virtual HRESULT SetCoords(int iVertex, double x, double y) = 0;

  virtual HRESULT SetCoords(int iVertex, double x, double y, double z) = 0;

  virtual HRESULT SetTangent(int iVertex, double tx, double ty, double tz) = 0;

  virtual HRESULT SetBinormal(int iVertex, double bnx, double bny, double bnz) = 0;

  virtual HRESULT SetScale(double scale) = 0;

  virtual HRESULT Empty() = 0;

  virtual HRESULT Set (int v, const double* a) = 0;
  virtual HRESULT Get (int v, double* a) const = 0;

public:

  /**
   * Casts as a non-const layer.
   */
  CATIPolySurfaceVertexTextureCoordLayer* NonConstCast ();

public:

  // DEPRECATED.

  /**
   * @nodoc
   */
  virtual HRESULT Set (int iVertex, double x, double y) {return SetCoords (iVertex,x,y);}

  /**
   * @nodoc
   */
  virtual HRESULT Get (int iVertex, double &x, double &y) {return GetCoords (iVertex,x,y);}

protected:

  virtual ~CATIPolySurfaceVertexTextureCoordLayer () {}

};
