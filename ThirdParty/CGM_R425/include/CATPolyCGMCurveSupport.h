// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCGMCurveSupport.h
//
//===================================================================
// September 2009  Creation: NDO
//===================================================================
#ifndef CATPolyCGMCurveSupport_H
#define CATPolyCGMCurveSupport_H

#include "TessBodyAdapters.h"
#include "CATIPolyCurveSupport.h"

class CATCurve;


class ExportedByTessBodyAdapters CATPolyCGMCurveSupport : public CATIPolyCurveSupport
{

public:

  inline CATPolyCGMCurveSupport (CATCurve& iCurve);

  ~CATPolyCGMCurveSupport () {}

public:

  static const CATPolyCGMCurveSupport* Cast (const CATIPolyLayer*);
  static CATPolyCGMCurveSupport* Cast (CATIPolyLayer*);

  static const CLSID& ClassID ();
  const CLSID& GetClassID () const;

public:

  Type GetType () const;

  HRESULT GetID (unsigned int& oID) const;

public:

  const CATPolyCGMCurveSupport* CastAsCGMCurve () const;

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

public:

  inline CATCurve& GetEdge () const;

  // Make a copy of itself.  Instance is to be deleted.
  CATIPolySupport* Clone () const;

private:

  CATCurve& _Curve;

};

inline CATPolyCGMCurveSupport::CATPolyCGMCurveSupport (CATCurve& iCurve) :
  _Curve (iCurve)
{
}

inline CATCurve& CATPolyCGMCurveSupport::GetEdge () const
{
  return _Curve;
}

#endif // !CATPolyCGMCurveSupport_H
