
// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessCellBVHAttribute
//
//===================================================================
// 2011-03-15   DPS
//      * New
// 2018-02-08 JXO: Monocell for IR 574664
//===================================================================

#ifndef CATTessCellBVHAttribute_H
#define CATTessCellBVHAttribute_H

#include "BVHTools.h"     // ExportedBy

#include "CATTessBVHAttribute.h"
#include "CATPolyPool.h"
#include "CATSysBoolean.h"
#include <stddef.h>

class CATTessBodyBVHAttribute;
class CATCell;
class CATIPolySurface;
class CATIPolyCurve;
class CATIPolyObject;
class CATVertex;

/**
 * This defines a CATCGMTessBody attribute to a CATBVHNode.
 * It implements @CATTessBVHAttribute.
 */

/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByBVHTools CATTessCellBVHAttribute : public CATTessBVHAttribute
{
  CATPolyDeclarePooledNew;

public:

  CATTessCellBVHAttribute(CATCell & iCGMCell, CATTessBodyBVHAttribute & iRootTessBVHAttrib, unsigned int iCellID12n);

  virtual ~CATTessCellBVHAttribute();


public:

  virtual CATBoolean HasFace() const;
  virtual CATBoolean HasEdge() const;
  virtual CATBoolean HasPoints() const;


  virtual CATFace * GetFace() const;
  virtual CATEdge * GetEdge() const;
  virtual CATVertex * GetVertex() const;
  virtual int GetNbVertices() const;


  virtual CATBoolean HasPolySurface() const;
  virtual CATBoolean HasPolyCurve() const;
  virtual CATBoolean HasPolyVertices() const;

  virtual CATIPolySurface* GetPolySurface (CATBoolean iNeedCellLayers = TRUE) const;
  virtual CATIPolyCurve* GetPolyCurve () const;
  virtual CATCellId * GetId() const;
  virtual CATCellId * GetId(int v) const;
  virtual CATIPolyPoint* GetPolyPoint (int v) const;

  virtual CATULONG32 GetCGMTag() const;
  virtual double GetSag() const;


  virtual CATTessBodyBVHAttribute * GetRootTessBVHAttribute() const;

  // JXO for IR 574664
  CATCell * GetMonoCell() override {return &_CGMCell;}

protected :

  // constructors without implementation
  CATTessCellBVHAttribute();
  CATTessCellBVHAttribute(const CATTessCellBVHAttribute &iAttToCopy);

private:

  CATCell                 & _CGMCell;
  CATTessBodyBVHAttribute & _RootTessBVHAttribute;

  CATIPolyObject          * _PolyGeom;

};

// inline
// ======




#endif

