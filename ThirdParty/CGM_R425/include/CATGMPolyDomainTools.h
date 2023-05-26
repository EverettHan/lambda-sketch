#ifndef CATGMPolyDomainTools_H
#define CATGMPolyDomainTools_H

// COPYRIGHT DASSAULT SYSTEMES  2014
//=============================================================================
//
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
// December 2014 Creation                                              DPS
//=============================================================================

#include "CATIAV5Level.h"

#include "GMPolyTopTools.h"   // ExportedBy
#include "CATTopDefine.h"        
#include "CATErrorDef.h"        
#include "ListPOfCATCell.h"        
#include "ListVOfLong.h"        

#include "CATBoolean.h"        
#include "CATSysBoolean.h"        


class CATDomain;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyTopTools CATGMPolyDomainTools
{

public:

  // Retrieve the boundary of the input domain
  // Returns an empty list if the domain is closed
  // else returns all the cells which are 1 manifold in the domain.
  // oBoundedCells & oSidesInDomain are 2 optional lists (independant from each other, their respective size is equal to oBoundingCells.Size())
  //    oBoundedCells[nucell]  allows the caller to know the unique cell bounded by oBoundingCells[nucell] in the domain
  //    oSidesInDomain[nucell] allows the caller to know if the input Shell (resp. wire) is seen on the left (+1) or on the right (-1) 
  //                           of the bounding edge (resp. vertex),  according to the orientation of the input domain
  //                           in case of VtxInFace or VtxInVolume, the bounded cell will be NULL and the side full (0)
  static HRESULT GetBoundingCells(CATDomain &iDomain, CATLISTP(CATCell)& oBoundingCells, CATLISTP(CATCell) * oBoundedCells=NULL, CATListOfInt * oSidesInDomain=NULL);

  // Retrieve the manifold subsets of connected cells from an input list of cells
  // The number of manifold subsets is done by oNbCellsByManifoldSet.Size() and 
  // the size of each subset is done by oNbCellsByManifoldSet[num]
  // The output list oGroupedCells will contain all the contiguous elements in the successives subsets
  // By default, the order of the contiguous elements in a same subset will respect the initial order as much as possible,
  // but the option iReorder1DCells allows the caller to trigger to reorder the chain of next adjacent 1-dimension elements.
  // The optional oOriCellsInDomain allows the caller to know the relative orientations between cells sharing a subset
  // and this list will be bijective with oGroupedCells
  // In case of subsets of edges, if the 2 options are demanded, oOriCellsInSubsets will be conform to the order of the output pseudo-wires
  static HRESULT GroupCellsIntoManifoldSets(const CATLISTP(CATCell) & iCellList, CATListOfLong & oNbCellsByManifoldSet, CATLISTP(CATCell) & oGroupedCells,
    CATBoolean iReorder1DCells=FALSE,  CATListOfLong * oOriCellsInSubsets = NULL);

  // Retrieve the connexe sets of connected cells from an input list of cells
  // The number of connexe subsets is done by oNbCellsByConnexeSet.Size() and 
  // the size of each subset is done by oNbCellsByConnexeSet[num]
  // The output list oGroupedCells will be ordered in order to have contiguous elements in the same subset
  static HRESULT GroupCellsIntoConnexeSets(const CATLISTP(CATCell) & iCellList, CATListOfLong & oNbCellsByConnexeSet, CATLISTP(CATCell) & oGroupedCells);


private:

  // By default, the order of cells in each subset matchs as more as possible with the order of cells in iCellList
  // iManifoldMode drives the behavior of the subset construction and of its order
  // 0 means that a NonManifold connected subset won't be split into separated Manifold subsets
  // 1 means each output connected subset will be Manifold
  // 2 means each output connected subset will be Manifold with an order respecting the chain previous<->next for 1-dimension elements
  static HRESULT GroupConnectedCellsIntoSubsets(const CATLISTP(CATCell) & iCellList, int iManifoldMode, CATListOfLong & oNbCellsBySubset, CATLISTP(CATCell) & oGroupedCells, 
    CATListOfLong * oOriCellsInSubsets = NULL);

};

#endif


