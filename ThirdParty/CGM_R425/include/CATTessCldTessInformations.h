//==============================================================================================================
// Copyright Dassault Systemes Provence 2003
//==============================================================================================================
// CATTessCldTessInformations :
//==============================================================================================================
// 30-Apr-2003 : JLH : Creation.
// Oct. 2004 TPD integration de la nouvelle sortie "Polyedre" du maillage
// Jan. 2006 TPD On rend les w : "GetW" pour l'edge
// Jan. 2006 TPD On rend le CATVertex pour les points 
//==============================================================================================================

#ifndef CATTessCldTessInformations_H
#define CATTessCldTessInformations_H

#include "TessPolygon.h"

#include "CATCldAttribute.h"
#include "CATDataType.h"
#include "CATMathVector.h"

class CATEdge;
class CATFace;
class CATVertex;
class CATSurface;

//=============================================================================
/**
 * Attributes for the triangles created by a tessellation of a <tt>CATBody</tt>.
 * @see CATTessCloudOpe.h
 */

class ExportedByTessPolygon CATTessCldTessTriangleInfo : public CATCldAttribute
{
public:

  CATTessCldTessTriangleInfo();
  virtual ~CATTessCldTessTriangleInfo();

  inline void      SetFace(CATFace * iFace);
  inline CATFace * GetFace();

private:
  CATFace * _Face ;

} ;

class  ExportedByTessPolygon CATTessCldTessTriangleInfoUnknown : public CATTessCldTessTriangleInfo
{
public:

  CATTessCldTessTriangleInfoUnknown();
  CATTessCldTessTriangleInfoUnknown(CATTessCldTessTriangleInfo& iInfo);
  virtual ~CATTessCldTessTriangleInfoUnknown();

  inline void      SetVirtualFace(int iNum);
  inline int GetVirtualFace();

  inline void      SetSurface(CATSurface * iSurf);
  inline CATSurface *  GetSurface();

private:
  int _NumVirtualFace;
  CATSurface * _Surface;
} ;

// Temporary constructor
inline CATTessCldTessTriangleInfoUnknown::CATTessCldTessTriangleInfoUnknown(CATTessCldTessTriangleInfo& iInfo)
 : CATTessCldTessTriangleInfo(iInfo) 
{
}

// Temporary implementation until one is provided
inline CATTessCldTessTriangleInfoUnknown::~CATTessCldTessTriangleInfoUnknown()
{
  _Surface = NULL;
}

inline void CATTessCldTessTriangleInfoUnknown::SetSurface(CATSurface * iSurface)
{
  _Surface = iSurface;
}

//--------------------------------------------------------------------------------------------------------------
// Function : GetFace (CATTessCldTessTriangleInfo implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline CATSurface * CATTessCldTessTriangleInfoUnknown::GetSurface()
{
  return _Surface;
}
inline void CATTessCldTessTriangleInfoUnknown::SetVirtualFace(int iNum)
{
  _NumVirtualFace = iNum;
}

//--------------------------------------------------------------------------------------------------------------
// Function : GetFace (CATTessCldTessTriangleInfo implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline int CATTessCldTessTriangleInfoUnknown::GetVirtualFace()
{
  return _NumVirtualFace;
}

//=============================================================================
/**
 * Attributes for the vertices created by a tessellation of a <tt>CATBody</tt>.
 * @see CATAtoCldPolygonServices::Tessellate
 */

class ExportedByTessPolygon CATTessCldTessVertexInfo : public CATCldAttribute
{
public:
  CATTessCldTessVertexInfo();
  virtual ~CATTessCldTessVertexInfo();

  inline CATTessCldTessVertexInfo *& Next();

  // Grandeurs relatives a la Face
  inline virtual void      SetFace(CATFace * iFace);
  inline virtual CATFace * GetFace();

  inline virtual void SetUVParameters(double   iU, double   iV);
  inline virtual void GetUVParameters(double & oU, double & oV);

  inline virtual void SetNormal(const CATMathVector * iNor);
  inline virtual const CATMathVector * GetNormal();

  // Grandeurs relatives a l'Edge
  inline virtual void      SetEdge(CATEdge * iEdge);
  inline virtual CATEdge * GetEdge();

  inline virtual void      SetNuPtDisc(CATLONG32 iNuPtDisc);
  inline virtual CATLONG32 GetNuPtDisc();

  inline virtual void      SetWParameter(double iW);
  inline virtual double    GetWParameter();
  inline virtual void      SetQualPts(short iQualPts);
  inline virtual short     GetQualPts();

  // Grandeurs relatives au Vertex
  inline virtual void        SetVertex(CATVertex * iVertex);
  inline virtual CATVertex * GetVertex();

private:
  CATTessCldTessVertexInfo * _Next;

} ;

class ExportedByTessPolygon CATTessCldTessVertexInfoFace : public CATTessCldTessVertexInfo
{
public:
  CATTessCldTessVertexInfoFace();
  virtual ~CATTessCldTessVertexInfoFace();

  // Grandeurs relatives a la Face
  inline void      SetFace(CATFace * iFace);
  inline CATFace * GetFace();

  inline void SetUVParameters(double   iU, double   iV);
  inline void GetUVParameters(double & oU, double & oV);

private:
  double    _U ;
  double    _V ;
  CATFace * _Face;

} ;

class ExportedByTessPolygon CATTessCldTessVertexInfoFaceAll : public CATTessCldTessVertexInfoFace
{
public:
  CATTessCldTessVertexInfoFaceAll();
  virtual ~CATTessCldTessVertexInfoFaceAll();

  inline void SetNormal(const CATMathVector * iNor);
  inline const CATMathVector * GetNormal();

private:
  CATMathVector _Nor;

} ;

class ExportedByTessPolygon CATTessCldTessVertexInfoFaceGeomAll : public CATTessCldTessVertexInfoFaceAll
{
public:
  CATTessCldTessVertexInfoFaceGeomAll();
  virtual ~CATTessCldTessVertexInfoFaceGeomAll();

  inline void SetWidthUV(double iWidthU, double iWidthV);
  inline double GetWidthU();
  inline double GetWidthV();

private:
  double _WidthU;
  double _WidthV;

} ;

class ExportedByTessPolygon CATTessCldTessVertexInfoEdge : public CATTessCldTessVertexInfo
{
public:
  CATTessCldTessVertexInfoEdge();
  virtual ~CATTessCldTessVertexInfoEdge();

  inline void      SetEdge(CATEdge * iEdge);
  inline CATEdge * GetEdge();

  inline void      SetNuPtDisc(CATLONG32 iNuPtDisc);
  inline CATLONG32 GetNuPtDisc();

private:
  CATEdge   * _Edge;
  CATLONG32   _NuPtDisc;
};

class ExportedByTessPolygon CATTessCldTessVertexInfoEdgeAll : public CATTessCldTessVertexInfoEdge
{
public:
  CATTessCldTessVertexInfoEdgeAll();
  virtual ~CATTessCldTessVertexInfoEdgeAll();

  inline void      SetWParameter(double iW);
  inline double    GetWParameter();
  inline void      SetQualPts(short iQualPts);
  inline short     GetQualPts();

private:
  double      _W;
  short       _QualPts;
};

class ExportedByTessPolygon CATTessCldTessVertexInfoVertex : public CATTessCldTessVertexInfo
{
public:
  CATTessCldTessVertexInfoVertex();
  virtual ~CATTessCldTessVertexInfoVertex();

  inline void        SetVertex(CATVertex * iVertex);
  inline CATVertex * GetVertex();

private:
  CATVertex * _Vertex;
};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================

//--------------------------------------------------------------------------------------------------------------
// Function : SetFace (CATTessCldTessTriangleInfo implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline void CATTessCldTessTriangleInfo::SetFace(CATFace * iFace)
{
  _Face = iFace;
}

//--------------------------------------------------------------------------------------------------------------
// Function : GetFace (CATTessCldTessTriangleInfo implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline CATFace * CATTessCldTessTriangleInfo::GetFace()
{
  return _Face;
}

//=============================================================================
//--------------------------------------------------------------------------------------------------------------
// Function : SetFace (CATTessCldTessVertexInfo implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline void CATTessCldTessVertexInfo::SetFace(CATFace * iFace)
{
}

//--------------------------------------------------------------------------------------------------------------
// Function : GetFace (CATTessCldTessVertexInfo implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline CATFace * CATTessCldTessVertexInfo::GetFace()
{
  return NULL;
}

//--------------------------------------------------------------------------------------------------------------
// Function : SetUVParameters (CATTessCldTessVertexInfo implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------

inline void CATTessCldTessVertexInfo::SetUVParameters(double  iU, double  iV)
{
}

//--------------------------------------------------------------------------------------------------------------
// Function : GetUVParameters (CATTessCldTessVertexInfo implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline void CATTessCldTessVertexInfo::GetUVParameters(double & oU, double & oV)
{
  oU = 0.;
  oV = 0.;
}

//--------------------------------------------------------------------------------------------------------------
// Function : Next (CATTessCldTessVertexInfo implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline CATTessCldTessVertexInfo *& CATTessCldTessVertexInfo::Next()
{
  return _Next;
}

//--------------------------------------------------------------------------------------------------------------
// Function : SetNormal (CATTessCldTessTriangleInfo implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline void CATTessCldTessVertexInfo::SetNormal(const CATMathVector * iNor)
{
}

//--------------------------------------------------------------------------------------------------------------
// Function : GetNormal (CATTessCldTessTriangleInfo implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline const CATMathVector * CATTessCldTessVertexInfo::GetNormal()
{
  return NULL;
}

//--------------------------------------------------------------------------------------------------------------
// Function : SetEdge (CATTessCldTessVertexInfo implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline void CATTessCldTessVertexInfo::SetEdge(CATEdge * iEdge)
{
}

//--------------------------------------------------------------------------------------------------------------
// Function : GetEdge (CATTessCldTessVertexInfo implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline CATEdge * CATTessCldTessVertexInfo::GetEdge()
{
  return NULL;
}

//--------------------------------------------------------------------------------------------------------------
// Function : SetNuPtDisc (CATTessCldTessVertexInfo implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline void CATTessCldTessVertexInfo::SetNuPtDisc(CATLONG32 iNuPtDisc)
{
}

//--------------------------------------------------------------------------------------------------------------
// Function : GetNuPtDisc (CATTessCldTessVertexInfo implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline CATLONG32 CATTessCldTessVertexInfo::GetNuPtDisc()
{
  return 0;
}

//--------------------------------------------------------------------------------------------------------------
// Function : SetWParameter (CATTessCldTessVertexInfo implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline void CATTessCldTessVertexInfo::SetWParameter(double iW)
{
}

//--------------------------------------------------------------------------------------------------------------
// Function : GetWParameter (CATTessCldTessVertexInfo implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline double CATTessCldTessVertexInfo::GetWParameter()
{
  return 0.;
}

//--------------------------------------------------------------------------------------------------------------
// Function : SetQualPts (CATTessCldTessVertexInfo implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline void CATTessCldTessVertexInfo::SetQualPts(short iQualPts)
{
}

//--------------------------------------------------------------------------------------------------------------
// Function : GetQualPts (CATTessCldTessVertexInfo implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline short CATTessCldTessVertexInfo::GetQualPts()
{
  return 0;
}

//--------------------------------------------------------------------------------------------------------------
// Function : SetVertex (CATTessCldTessVertexInfo implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline void CATTessCldTessVertexInfo::SetVertex(CATVertex * iVertex)
{
}

//--------------------------------------------------------------------------------------------------------------
// Function : GetVertex (CATTessCldTessVertexInfo implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline CATVertex * CATTessCldTessVertexInfo::GetVertex()
{
  return NULL;
}

//=============================================================================
//--------------------------------------------------------------------------------------------------------------
// Function : SetFace (CATTessCldTessVertexInfoFace implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline void CATTessCldTessVertexInfoFace::SetFace(CATFace * iFace)
{
  _Face = iFace;
}

//--------------------------------------------------------------------------------------------------------------
// Function : GetFace (CATTessCldTessVertexInfo implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline CATFace * CATTessCldTessVertexInfoFace::GetFace()
{
  return _Face;
}

//--------------------------------------------------------------------------------------------------------------
// Function : SetUVParameters (CATTessCldTessVertexInfoFace implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------

inline void CATTessCldTessVertexInfoFace::SetUVParameters(double  iU, double  iV)
{
  _U = iU;
  _V = iV;
}

//--------------------------------------------------------------------------------------------------------------
// Function : GetUVParameters (CATTessCldTessVertexInfoFace implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline void CATTessCldTessVertexInfoFace::GetUVParameters(double & oU, double & oV)
{
  oU = _U;
  oV = _V;
}

//--------------------------------------------------------------------------------------------------------------
// Function : SetNormal (CATTessCldTessVertexInfoFaceAll implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline void CATTessCldTessVertexInfoFaceAll::SetNormal(const CATMathVector * iNor)
{
  if ( iNor ) {
    _Nor = * iNor;
  } else {
    _Nor.SetCoord( 0.0, 0.0, 0.0 );
  }
}

//--------------------------------------------------------------------------------------------------------------
// Function : GetNormal (CATTessCldTessVertexInfoFaceAll implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline const CATMathVector * CATTessCldTessVertexInfoFaceAll::GetNormal()
{
  return & _Nor;
}
//=============================================================================
//--------------------------------------------------------------------------------------------------------------
// Function : SetFace (CATTessCldTessVertexInfoEdgeAll implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline void CATTessCldTessVertexInfoEdge::SetEdge(CATEdge * iEdge)
{
  _Edge = iEdge;
}

//--------------------------------------------------------------------------------------------------------------
// Function : GetFace (CATTessCldTessVertexInfoEdge implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline CATEdge * CATTessCldTessVertexInfoEdge::GetEdge()
{
  return _Edge;
}

//--------------------------------------------------------------------------------------------------------------
// Function : SetNuPtDisc (CATTessCldTessVertexInfoEdge implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline void CATTessCldTessVertexInfoEdge::SetNuPtDisc(CATLONG32 iNuPtDisc)
{
  _NuPtDisc = iNuPtDisc;
}

//--------------------------------------------------------------------------------------------------------------
// Function : GetFace (CATTessCldTessVertexInfoEdge implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline CATLONG32 CATTessCldTessVertexInfoEdge::GetNuPtDisc()
{
  return _NuPtDisc;
}
//--------------------------------------------------------------------------------------------------------------
// Function : SetWParameter (CATTessCldTessVertexInfoEdgeAll implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline void CATTessCldTessVertexInfoEdgeAll::SetWParameter(double iW)
{
  _W = iW;
}

//--------------------------------------------------------------------------------------------------------------
// Function : GetFace (CATTessCldTessVertexInfoEdgeAll implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline double CATTessCldTessVertexInfoEdgeAll::GetWParameter()
{
  return _W;
}

//--------------------------------------------------------------------------------------------------------------
// Function : SetQualPts (CATTessCldTessVertexInfoEdge implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline void CATTessCldTessVertexInfoEdgeAll::SetQualPts(short iQualPts)
{
  _QualPts = iQualPts;
}

//--------------------------------------------------------------------------------------------------------------
// Function : GetQualPts (CATTessCldTessVertexInfoEdge implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline short CATTessCldTessVertexInfoEdgeAll::GetQualPts()
{
  return _QualPts;
}

//=============================================================================
//--------------------------------------------------------------------------------------------------------------
// Function : SetVertex (CATTessCldTessVertexInfoVertex implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline void CATTessCldTessVertexInfoVertex::SetVertex(CATVertex * iVertex)
{
  _Vertex = iVertex;
}

//--------------------------------------------------------------------------------------------------------------
// Function : GetVertex (CATTessCldTessVertexInfo implementation)
// Purpose  :
//--------------------------------------------------------------------------------------------------------------
inline CATVertex * CATTessCldTessVertexInfoVertex::GetVertex()
{
  return _Vertex;
}

inline void CATTessCldTessVertexInfoFaceGeomAll::SetWidthUV(double iWidthU, double iWidthV)
 {
 _WidthU = iWidthU;
 _WidthV = iWidthV;
 }

inline double CATTessCldTessVertexInfoFaceGeomAll::GetWidthU()
 {
 return _WidthU;
 }
inline double CATTessCldTessVertexInfoFaceGeomAll::GetWidthV()
 {
 return _WidthV;
 }

#endif
