
// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessBodyBVHAttribute
//
//===================================================================
// 2011-03-15   DPS
//      * New
// 2018-02-08 JXO: Monocell for IR 574664
//===================================================================

#ifndef CATTessBodyBVHAttribute_H
#define CATTessBodyBVHAttribute_H

#include "BVHTools.h"     // ExportedBy

#include "CATTessBVHAttribute.h"
#include "CATTessBodyBVHTreeBuilder.h"
#include "CATPolyPool.h"
#include "CATDataType.h"
#include "CATSysBoolean.h"

#include <stddef.h>

class CATCGMTessBody;
class CATCell;
class CATFace;
class CATEdge;
class CATVertex;
class CATIPolyObject;
class CATIPolySurface;
class CATIPolyCurve;
class CATCellId;

/**
 * This defines a CATCGMTessBody attribute to a CATBVHNode.
 * It implements @CATTessBVHAttribute.
 */

/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByBVHTools CATTessBodyBVHAttribute : public CATTessBVHAttribute
{
  CATPolyDeclarePooledNew;

public:

  // Constructor with the type of cells on which the node generation is required
  CATTessBodyBVHAttribute(CATCGMTessBody & iTessBody, CATTessBodyBVHTreeBuilder::EntityType iEntityType);

  // Constructor in case of specific area with the single cell if any
  CATTessBodyBVHAttribute(CATCGMTessBody & iTessBody, CATCell * iMonoSpecCell);

  virtual ~CATTessBodyBVHAttribute();


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
  virtual CATCellId * GetId()const;
  virtual CATCellId * GetId(int v) const;
  virtual CATIPolyPoint* GetPolyPoint (int v) const;

  virtual double GetSag() const;
  
  virtual CATBoolean HasBody() const; 
  virtual int GetBodyDimension() const;

  virtual CATCGMTessBody * GetTessBody() const;
  virtual CATBoolean HasTessBody() const;

  virtual CATULONG32 GetCGMTag() const;

  virtual CATTessBodyBVHAttribute * GetRootTessBVHAttribute() const;


  inline CATBoolean HasVertexDomain() const;
  inline CATBoolean HasWire() const;
  inline CATBoolean HasShell() const;
  inline CATBoolean HasVolume() const;

  // JXO for IR 574664
  CATCell * GetMonoCell() override {return _MonoCell;}
  void SetMonoCell(CATCell * iCell) override {_MonoCell = iCell;}

protected :

  // constructors without implementation
  CATTessBodyBVHAttribute();
  CATTessBodyBVHAttribute(const CATTessBodyBVHAttribute &iAttToCopy);

private:

  enum BODY_DOM_DIM
  {
    NO_DOMAIN = 0,
    HAS_VERTEX_DOMAIN = 1,   // first bit
    HAS_WIRE = 2,            // second bit
    HAS_SHELL = 4,           // third bit
    HAS_VOLUME = 8           // forth bit
  };

  CATCGMTessBody              & _TessBody;
  CATCell                     * _MonoCell;
  CATIPolyObject              * _MonoPolyGeom;

  unsigned char                 _DimCompilation;


};

// inline
// ======

inline CATBoolean CATTessBodyBVHAttribute::HasVertexDomain() const {
  return (_DimCompilation & HAS_VERTEX_DOMAIN); }

inline CATBoolean CATTessBodyBVHAttribute::HasWire() const {
  return (_DimCompilation & HAS_WIRE); }

inline CATBoolean CATTessBodyBVHAttribute::HasShell() const {
  return (_DimCompilation & HAS_SHELL); }

inline CATBoolean CATTessBodyBVHAttribute::HasVolume() const {
  return (_DimCompilation & HAS_VOLUME); }


#endif

