//===================================================================================
// Copyright Dassault Systemes Provence 2016, All Rights Reserved
//===================================================================================
//
// CATPolyMCurveNetworkUtilities.h
//
//===================================================================================
//
// Usage notes: Data structure for PolyMCurve network
//
//===================================================================================
// 13.07.2016 : RAQ : Création
//===================================================================================
#ifndef CATPolyMCurveNetworkUtilities_H
#define CATPolyMCurveNetworkUtilities_H

//Divers
#include "CATLib.h"

//STL
#ifdef _AIX_SOURCE
  #undef throw
#endif  //_AIX_SOURCE
#include <vector>
#include <set>

class CATPolyMCNOEdge;


namespace CATPolyMCurveNetworkUtilities
{
  struct RemovedMCNOEdge
  {
    RemovedMCNOEdge(CATPolyMCNOEdge* ipRemovedMCNOEdge = 0):
      m_pRemovedMCNOEdge(ipRemovedMCNOEdge)
    {
    }

    ~RemovedMCNOEdge()
    {
      m_pRemovedMCNOEdge=0;
    }

    //---- Data :
    CATPolyMCNOEdge* m_pRemovedMCNOEdge;  //Warning : this member points to an already released element, you can't dereference it.
    std::vector<CATPolyMCNOEdge*> m_newEdges;
  };

  struct RemovedMCNOEdgeComparator
  {
    inline bool operator()(const RemovedMCNOEdge& iObject1, const RemovedMCNOEdge& iObject2) const
    {
      return (iObject1.m_pRemovedMCNOEdge<iObject2.m_pRemovedMCNOEdge);
    }
  };

  typedef std::set<RemovedMCNOEdge, RemovedMCNOEdgeComparator> SetOfRemovedMCNOEdge_t;
}


#endif  //CATPolyMCurveNetworkUtilities_H


