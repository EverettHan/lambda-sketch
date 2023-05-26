// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCurveRefinerData.cpp
//
//===================================================================
//
// December 2009  Creation: NDO
//===================================================================
#ifndef CATPolyCurveRefinerData_H
#define CATPolyCurveRefinerData_H

#include "PolyVizRefiners.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"

class CATMathPoint;
class CATMathVector;


class ExportedByPolyVizRefiners CATPolyCurveRefinerData 
{

public:

  CATPolyCurveRefinerData ();
  ~CATPolyCurveRefinerData ();

public:

  inline unsigned int GetSizeOfVertices () const;

  HRESULT ResizeVertices (const int iNbVertices);
  HRESULT ResizeVertices (const int iNbVertices, CATBoolean iWithTangents, CATBoolean iWithWs);

public:

  // Reset the number of vertices stored in the curve to 0.
  inline void Reset ();

  HRESULT AddVertex (const CATMathPoint& P, unsigned int& v);

  HRESULT SetVertexTangent (const unsigned int v, const CATMathVector& N);
  HRESULT SetVertexW (const unsigned int vertex, const float w);

public:

  inline unsigned int GetNbVertices () const;

  inline const float* GetVertexCoordinates () const;
  inline const float* GetVertexTangents () const;
  inline const float* GetVertexWs () const;

public:

  // For direct vertex feed.  Make sure the array is sufficiently large.
  inline float* GetVertexCoordinates ();
  inline void SetNbVertices (const unsigned int iNbVertices);

private:

  float* _VertexCoords;
  float* _VertexTangents;
  float* _VertexWs;

  unsigned int _NbVertices;
  unsigned int _SizeVertices; 

};


inline unsigned int CATPolyCurveRefinerData::GetSizeOfVertices () const
{
  return _SizeVertices;
}

inline unsigned int CATPolyCurveRefinerData::GetNbVertices () const
{
  return _NbVertices;
}

inline const float* CATPolyCurveRefinerData::GetVertexCoordinates () const
{
  return _VertexCoords;
}

inline const float* CATPolyCurveRefinerData::GetVertexTangents () const
{
  return _VertexTangents;
}

inline const float* CATPolyCurveRefinerData::GetVertexWs () const
{
  return _VertexWs;
}

inline void CATPolyCurveRefinerData::Reset ()
{
  _NbVertices = 0;
}

inline float* CATPolyCurveRefinerData::GetVertexCoordinates ()
{
  return _VertexCoords;
}

inline void CATPolyCurveRefinerData::SetNbVertices (const unsigned int iNbVertices)
{
  _NbVertices = iNbVertices;
}

#endif
