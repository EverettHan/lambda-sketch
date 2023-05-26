// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCGMEdgeSupport.h
//
//===================================================================
// March 2009  Creation: NDO
//===================================================================
#ifndef CATPolyCGMEdgeSupport_H
#define CATPolyCGMEdgeSupport_H

#include "TessBodyAdapters.h"
#include "CATIPolyCurveSupport.h"

class CATEdge;


class ExportedByTessBodyAdapters CATPolyCGMEdgeSupport : public CATIPolyCurveSupport
{

public:

#ifndef __ibmxl__
inline 
#endif 
  CATPolyCGMEdgeSupport (CATEdge& iEdge);

  ~CATPolyCGMEdgeSupport () {}

public:

  static const CATPolyCGMEdgeSupport* Cast (const CATIPolyLayer*);
  static CATPolyCGMEdgeSupport* Cast (CATIPolyLayer*);

  static const CLSID& ClassID ();
  const CLSID& GetClassID () const;

public:

  Type GetType () const;

  HRESULT GetID (unsigned int& oID) const;

public:

  const CATPolyCGMEdgeSupport* CastAsCGMEdge () const;

public:

  /*
   * Return a CATPolyMathCurve.  The object returned is not supposed to be deleted.
   * Its life cycle is managed by this class.
   */
  HRESULT GetMathCurve (const CATPolyMathCurve*& oCurve) const;
  HRESULT GetMathCurve (CATPolyMathCurve*& oCurve);

  /*
   * Return a CATPolyMathSurface.  The object returned is not supposed to be deleted.
   * Its life cycle is managed by this class.
   */
  HRESULT GetMathSurface (const CATPolyMathSurface*& oSurface) const;
  HRESULT GetMathSurface (CATPolyMathSurface*& oSurface);

  // Instance returned must be deleted.
  HRESULT GetNewMathCurve (CATPolyMathCurve*& oCurve) const;

public:

  inline CATEdge& GetEdge () const;

  // Make a copy of itself.  Instance is to be deleted.
  CATIPolySupport* Clone () const;

private:

  CATEdge& _Edge;

};

#ifndef __ibmxl__
inline 
#endif 
CATPolyCGMEdgeSupport::CATPolyCGMEdgeSupport (CATEdge& iEdge) :
  _Edge (iEdge)
{
}

inline CATEdge& CATPolyCGMEdgeSupport::GetEdge () const
{
  return _Edge;
}

#endif // !CATPolyCGMEdgeSupport_H
