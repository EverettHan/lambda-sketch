
/* -*-C++-*-*/
#ifndef CATHLRClashEdge_H
#define CATHLRClashEdge_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2012
//
// CATAdvancedHLRExact
//
// DESCRIPTION :
//
//    General management of Clash information on HLREdge instances 
//    to compute specific jumps of visibility in ExactHLR motor.
//
//
//=============================================================================
//
// History
//
// July 2012  DPS    Creation            
//
//=============================================================================


#include "HLRTopology.h"

#include "CATCrvParam.h"
#include "CATErrorDef.h"       // HRESULT def


class CATHLRMemoryManager;
class CATHLRFace;
class CATHLREdge;
class CATHLRHedge;


class ExportedByHLRTopology CATHLRClashEdge
{
  //=============================================================================
  // CONSTRUCTORS AND DESTRUCTOR
  //=============================================================================

public :

  // Default constructor
  CATHLRClashEdge();

  // Destructor
  /*
  ~CATHLRClashEdge();
  */

  // Record a new Clash point on the edge  
  void AppendClashPointOnEdge(CATHLRMemoryManager * iMemoryManager, CATCrvParam &iClashParam, CATHLRFace * iClashFace); 

  // Retrieve one Clash point parameter on edge, 
  // the parameter will be identified thanks to an index between 0 and (_NbClashPoints-1).
  HRESULT GetClashPointOnEdge(int iClashIndex, CATCrvParam &oClashParam, CATHLRFace *&oHLRFace);


  // Methode Set et Get
  inline void SetHLRHedge(CATHLRHedge * iHedge);
  inline CATHLRHedge * GetHLRHedge();
  inline int GetNbClashPoints();


private :

  struct CATHLRClashPointOnEdge
  { 
    CATCrvParam            _clashCrvParam;
    CATHLRFace           * _clashHLRFace;
  };

  CATHLRHedge            * _HLRHedge;

  CATHLRClashPointOnEdge * _ClashPoints;
  int                      _NbClashPoints;

};

// Methodes inline 
// ---------------

inline void CATHLRClashEdge::SetHLRHedge(CATHLRHedge * iHedge) {
  _HLRHedge = iHedge; }

inline CATHLRHedge * CATHLRClashEdge::GetHLRHedge() {
  return _HLRHedge; }

inline int CATHLRClashEdge::GetNbClashPoints() {
  return _NbClashPoints; }

#endif

