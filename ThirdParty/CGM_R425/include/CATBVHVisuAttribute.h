// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATBVHVisuAttribute
//
//===================================================================
// 2009-09-04   JXO
//      * New
// 2010-03-23   JXO
//      * CATPolyData proxy
// 2013-04-23   JXO
//      * CATBVHVisuAttributeFullImpl cast method
//===================================================================
#ifndef CATBVHVisuAttribute_H
#define CATBVHVisuAttribute_H

#include "PolyVisuBVH.h"

#include "CATPolyBVHAttribute.h"
#include "CATPolyPool.h"
#include <string.h>

// Poly
class CATPolyBody;
class CATPolyFace;
class CATPolyEdge;
class CATIPolySurface;
class CATIPolyCurve;
class CATMathTransformation;
class CATPolyBodyVisuContext;
class CATBVHVisuAttributeFullImpl;
class CATBVHVisuAttributeGP;
class CATBVHVisuAttributeVP;
class CATBVHVisuAttributeRep;
class CATBVHTreeRepBuilderObserver;

// Visu
class CATRep;
class CAT4x4Matrix;
class CATGraphicPrimitive;
class CATVizPrimitive;
class CATRepPath;


/**
 * Implementation of visu model attributes of CATBVHNode's.
 */
class ExportedByPolyVisuBVH CATBVHVisuAttribute : public CATPolyBVHAttribute
{
  CATPolyDeclarePooledNew;

public:
  virtual ~CATBVHVisuAttribute();

public:

  virtual CATPolyBVHAttribute* CastAsPolyAttribute ();
  virtual const CATPolyBVHAttribute* CastAsPolyAttribute () const;
  virtual CATBVHVisuAttribute* CastAsVisuAttribute ();
  virtual const CATBVHVisuAttribute* CastAsVisuAttribute () const;

public:

  virtual CATPolyBody* GetPolyBody (CATBoolean iWithFaceEdges = TRUE) const;
  virtual CATPolyFace* GetPolyFace (CATBoolean iWithFaceEdges = TRUE) const;
  virtual CATPolyEdge* GetPolyEdge () const;
  virtual int GetNbVertices() const;
  virtual CATPolyVertex * GetPolyVertex(int v) const;

  virtual CATIPolySurface* GetPolySurface (CATBoolean iWithFaceEdges = TRUE) const;
  virtual CATIPolyCurve* GetPolyCurve () const;

  virtual const CATMathTransformation* GetPosition () const;

  virtual CATBoolean HasPolyBody() const;
  virtual CATBoolean HasPolySurface() const;
  virtual CATBoolean HasPolyCurve() const;
  virtual CATBoolean HasPolyVertices() const;
  virtual CATPolyBVHAttribute * GetParentPolyBodyAttribute() const;

  /**
   * If the attribute is relative to a polybody, return its Sag.
   * Otherwise return a negative value.
   * This implementation does not require the actual polybody creation.
   */
  virtual double GetSag() const;

  /**
   * If the attribute is relative to a polybody, return its dimension.
   * The dimension can be 0 for points, 1 for lines, 2 for surfaces or 3 for volumes.
   * This implementation does not require the actual polybody creation.
   */
  virtual int GetBodyDimension() const;

  virtual void FlushComputedData();


  // Visu :
  virtual const CATRep * GetRep() const;
  virtual const CATGraphicPrimitive * GetGraphicPrimitive() const;
  virtual const CATVizPrimitive * GetVizPrimitive() const;
  virtual CAT4x4Matrix * GetMatrix() const;
  
  /** @nodoc */
  virtual int GetPathId();
  /** @nodoc */
  // Don't delete this reppath
  virtual CATRepPath * GetRepPath();
  /** @nodoc */
  /** Will be deleted by destructor */
  virtual int SetRepPath(CATRepPath * pRepPath);
  /** @nodoc */
  virtual CATBVHVisuAttribute * GetParentRepAttribute();
  /** @nodoc */
  virtual void SetParentRepAttribute(CATBVHVisuAttribute * pRepAtt);
  /** @nodoc */
  virtual CATPolyBodyVisuContext * GetVisuContext();

  virtual CATBVHVisuAttributeFullImpl * CastAsVisuAttributeFullImpl(){return 0;}
  virtual const CATBVHVisuAttributeFullImpl * CastAsVisuAttributeFullImpl() const {return 0;}
  virtual CATBVHVisuAttributeVP * CastAsVisuAttributeVP() {return 0;}
  virtual const CATBVHVisuAttributeVP * CastAsVisuAttributeVP() const {return 0;}
  virtual CATBVHVisuAttributeGP * CastAsVisuAttributeGP() {return 0;}
  virtual const CATBVHVisuAttributeGP * CastAsVisuAttributeGP() const {return 0;}
  virtual CATBVHVisuAttributeRep * CastAsVisuAttributeRep() {return 0;}
  virtual const CATBVHVisuAttributeRep * CastAsVisuAttributeRep() const {return 0;}

  virtual void SetObserver(CATBVHTreeRepBuilderObserver * o){}
};

#endif
