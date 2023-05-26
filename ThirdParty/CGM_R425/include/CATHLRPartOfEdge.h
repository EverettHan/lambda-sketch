#ifndef CATHLRPARTOFEDGE_H
#define CATHLRPARTOFEDGE_H
//
//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1997
//
// CATHLRPartOfEdge : Part of of an edge with a certain type of visibility
//
// DESCRIPTION : this class delimits the differents types of visibility
//               of an edge for a certain projection in the HLR
// 
//=============================================================================
//
// History
//
// Mai. 97      Creation              Herve BAREAU (hbu)
//
//=============================================================================

#include "HLRModele.h"

#include "CATCrvParam.h"
#include "CATHLRConstant.h"

class CATSurface;
class CATMathBox;
class CATHLRCurve;

class CATHLREdge;

class ExportedByHLRModele CATHLRPartOfEdge
{
public:
// The different types of visibility
// Null: edge reduced to a point on the projection plane
// Occluded: edge or part of edge hidden by another edge
// Smooth: the angle of the two surfaces of the edge is null 
// with a given tolerance 
  enum CATHLRTypeVisibility {Visible, Hidden, Null, Occluded, Smooth};

//------------------------------------------------------------
// Methods
//------------------------------------------------------------
// Returns 1 if the part of edge is a reflect line
  inline CATLONG32 IsReflect() const;

// Returns 1 if the part of edge is smooth
  CATLONG32 IsSmooth() const;

// Returns 1 is the edge generated belongs to a fillet surface
  CATLONG32 IsFromFillet() const;

// Get the visibility of the part of edge
  inline CATHLRPartOfEdge::CATHLRTypeVisibility GetVisibility() const;

// Get the curve on which the part of edge lies
  CATHLRCurve * GetCurve() const;

// Getting the extremities of the part
  inline const CATCrvParam & GetStart() const;
  inline const CATCrvParam & GetEnd() const;

// Gets the number of faces associated to the part of edge
  CATLONG32 GetCountFaces() const;

// Gets the jele of one face associated to the part of edge 
// Note that : 0 <= IdxFace < GetCountFaces() 
  int GetJeleFace(CATLONG32 iIdxFace) const;

/** Gets the next Part of edge
 */
  inline CATHLRPartOfEdge * GetNext();

//=============================================================================
// INTERNAL DATAS
//=============================================================================
// Silhouette or not
  int Reflect;
  
// Next part in the list
  CATHLRPartOfEdge* Next;
  
// Correspondant edge of the part
  CATHLREdge* Edge;

// Limits of the part
   CATCrvParam wStart;
   CATCrvParam wEnd;
  
// Type of visibility of the part
  CATHLRTypeVisibility TypeOfVisibility;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================
inline CATLONG32 CATHLRPartOfEdge::IsReflect() const
{
  return Reflect;
}

inline CATHLRPartOfEdge::CATHLRTypeVisibility CATHLRPartOfEdge::GetVisibility() const
{
  return TypeOfVisibility;
}

inline const CATCrvParam & CATHLRPartOfEdge::GetStart() const
{
  return wStart;
}

inline const CATCrvParam & CATHLRPartOfEdge::GetEnd() const
{
  return wEnd;
}

inline CATHLRPartOfEdge * CATHLRPartOfEdge::GetNext()
{
  return Next;
}


#endif



