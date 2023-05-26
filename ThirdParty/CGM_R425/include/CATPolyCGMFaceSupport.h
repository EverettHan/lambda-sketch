// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCGMFaceSupport.h
//
//===================================================================
// March 2009  Creation: NDO
//===================================================================
#ifndef CATPolyCGMFaceSupport_H
#define CATPolyCGMFaceSupport_H

#include "TessBodyAdapters.h"
#include "CATIPolySurfaceSupport.h"
#include "CATTopDefine.h"  // CATOrientation

#include "CATFace.h"


class ExportedByTessBodyAdapters CATPolyCGMFaceSupport : public CATIPolySurfaceSupport
{

public:

  /**
   * Construction of the support containing a CATFace and the orientation of the CATFace w.r.t. its context
   * (for instance a CATBody context.)
   */
#ifndef __ibmxl__
inline 
#endif 
  CATPolyCGMFaceSupport (CATFace& iFace, CATOrientation iContextOrientation);

  ~CATPolyCGMFaceSupport () {}

public:

  static const CATPolyCGMFaceSupport* Cast (const CATIPolyLayer*);
  static CATPolyCGMFaceSupport* Cast (CATIPolyLayer*);

  static const CLSID& ClassID ();
  const CLSID& GetClassID () const;

public:

  Type GetType () const;

  HRESULT GetID (unsigned int& oID) const;

public:

  const CATPolyCGMFaceSupport* CastAsCGMFace () const;

public:

  /*
   * Return a CATPolyMathSurface.  The object returned is not supposed to be deleted.
   * Its life cycle is managed by this class.
   */
  HRESULT GetMathSurface (const CATPolyMathSurface*& oSurface) const;
  HRESULT GetMathSurface (CATPolyMathSurface*& oSurface);

  // Instance returned must be deleted.
  HRESULT GetNewMathSurface (CATPolyMathSurface*& oSurface) const;

public:

  /**
   * Returns the orientation of the CATFace relative to its context.
   * For instance, this is the orientation of the CATFace w.r.t. a CATBody context.
   * It could be another context like just the CATFace context for local tessellation.
   */
  inline CATOrientation GetContextOrientation () const;

  /**
   * Returns the orientation of the CATFace relative to its geometry (CATSurface.)
   *
   * The orientation of the CATSurface w.r.t. the CATIPolySurface is the product of 
   * the context orientation and the geometry orientation.
   */
  inline CATOrientation GetGeometryOrientation () const;

  /**
   * Returns the orientation of the geometry of the support w.r.t. its context.
   * This is the product of GetContextOrientation () and GetGeometryOrientation ().
   * @return 
   *   <ul>
   *      <li> +1: Positive
   *      <li>  0: Undefined
   *      <li> -1: Negative
   *   </ul>
   */
  int GetOrientation () const;

public:

  inline CATFace& GetFace () const;

  // Method returning TRUE is the surface support is planar and FALSE otherwise.
  CATBoolean IsPlanar () const;

  // Make a copy of itself.  Instance is to be deleted.
  CATIPolySupport* Clone () const;

private:

  CATFace& _Face;

  CATOrientation _ContextOrientation;  // Orientation of the CATFace w.r.t its context (for instance a CATBody context.)

};

#ifndef __ibmxl__
inline 
#endif 
  CATPolyCGMFaceSupport::CATPolyCGMFaceSupport (CATFace& iFace, CATOrientation iContextOrientation) :
  _Face (iFace),
  _ContextOrientation (iContextOrientation)
{
}

inline CATFace& CATPolyCGMFaceSupport::GetFace () const
{
  return _Face;
}

inline CATOrientation CATPolyCGMFaceSupport::GetContextOrientation () const
{
  return _ContextOrientation;
}

inline CATOrientation CATPolyCGMFaceSupport::GetGeometryOrientation () const
{
  return _Face.GetGeometryOrientation ();
}

#endif // !CATPolyCGMFaceSupport_H
