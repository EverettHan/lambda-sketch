// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCGMVertexSupport.h
//
//===================================================================
// August 2009  Creation: NDO
//===================================================================
#ifndef CATPolyCGMVertexSupport_H
#define CATPolyCGMVertexSupport_H

#include "TessBodyAdapters.h"
#include "CATIPolyPointSupport.h"

class CATVertex;


class ExportedByTessBodyAdapters CATPolyCGMVertexSupport : public CATIPolyPointSupport
{

public:

#ifndef __ibmxl__
inline 
#endif 
  CATPolyCGMVertexSupport (CATVertex& iVertex);

  ~CATPolyCGMVertexSupport () {}

public:

  static const CATPolyCGMVertexSupport* Cast (const CATIPolyLayer*);
  static CATPolyCGMVertexSupport* Cast (CATIPolyLayer*);

  static const CLSID& ClassID ();
  const CLSID& GetClassID () const;

public:

  Type GetType () const;

  HRESULT GetID (unsigned int& oID) const;

public:

  const CATPolyCGMVertexSupport* CastAsCGMVertex () const;

public:

  inline CATVertex& GetVertex () const;

  // Make a copy of itself.  Instance is to be deleted.
  CATIPolySupport* Clone () const;

private:

  CATVertex& _Vertex;

};

#ifndef __ibmxl__
inline 
#endif 
CATPolyCGMVertexSupport::CATPolyCGMVertexSupport (CATVertex& iVertex) :
  _Vertex (iVertex)
{
}

inline CATVertex& CATPolyCGMVertexSupport::GetVertex () const
{
  return _Vertex;
}

#endif // !CATPolyCGMVertexSupport_H
