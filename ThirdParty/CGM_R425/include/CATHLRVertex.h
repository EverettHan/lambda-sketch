/* -*-C++-*-*/
#ifndef CATHLRVertex_H
#define CATHLRVertex_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRVertex 
//
// DESCRIPTION :
/**
 * Vertex in a model for the HLR
 */
//
// Main Methods :
//  
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Jan. 1998 JCH Creation            
// Jul. 1999 HKL Added the edge array (CATListPV)
// Aug. 1999 HKL Added the AddEdge method
// Jan. 2000 HKL Change the way the edge arry is stored (CATHLREdge**)
//
//=============================================================================

// For Windows NT
#include "HLRTopology.h"

// For inheritance
#include "CATHLRTopology.h"

#include "CATMathPoint.h" 
#include "CATListPV.h" 

class CATHLRContainer;
class CATHLRTransformation;
class CATHLREdge;
class CATHLRNode;

class ExportedByHLRTopology CATHLRVertex : public CATHLRTopology
{
public:

//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/** Constructor from a CATVertex
 */
  CATHLRVertex(void            * iVertex, 
               CATHLRContainer * iContainer,
               const CATHLRTransformation * iTransformation);

/** Constructor from a point and a container.
 */
  CATHLRVertex(int                  iIdentifier,	       
	             CATHLRContainer    * iContainer);
	       
//=============================================================================
// METHODS
//=============================================================================
/** Gets the position of the vertex in the space
 */
  virtual void GetPosition(CATMathPoint & oPoint) const = 0;

/** Retrieves the vertex's dimension (ie. 0)
  */
  inline int GetDimension();

/** Gets an identifier for the edge.
 */
  inline CATINTPTR GetIdentificationTAG() const;

/** Adds a backward link from the vertex to a bounded edge
 */
  void AddEdge(CATHLREdge * iEdge);

/** Retrieves the bounded edges number
 */
  CATLONG32 GetBoundedEdgesNumber() const;

/** Retrieves the i-th bounded edge starting from 0
 */
  CATHLREdge * GetBoundedEdge(int iIndex) const;

//------------------------------------------------------------
// For the HLR's management
//------------------------------------------------------------
  virtual void SetHLRNode(CATHLRNode * iNode);
  virtual CATHLRNode * GetHLRNode();


//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:

  // Position of the vertex
  // CATMathPoint   _Position;
  CATHLRNode        * _HLRNode;

  // Bounded edges
  CATHLREdge * _LastBoundedEdge;
};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================



//-----------------------------------------------------------------------------

inline int CATHLRVertex::GetDimension()
{
  return 0;
}

//-----------------------------------------------------------------------------

inline CATINTPTR CATHLRVertex::GetIdentificationTAG() const
{
  return 0;
}

//-----------------------------------------------------------------------------

#endif

