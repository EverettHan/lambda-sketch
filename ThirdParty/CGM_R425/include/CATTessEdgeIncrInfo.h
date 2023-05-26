/* -*-C++-*-*/
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES	2010
//=============================================================================
// CATTessEdgeIncrInfo
/**
  * This object provides information of edge tessellation in the context 
  * of incremental tessellation
  */
//=============================================================================

#ifndef CATTessEdgeIncrInfo_H
#define CATTessEdgeIncrInfo_H


#include "TessAPI.h"
#include "CATBoolean.h"

//-----------------------------------------------------------------------------
class ExportedByTessAPI CATTessEdgeIncrInfo
{
public:

  //=============================================================================
  //- Constructor and Destructor
  //=============================================================================

  CATTessEdgeIncrInfo();

  virtual ~CATTessEdgeIncrInfo();



  //=============================================================================
  //- Query methods for CATTessIncrModePropagation / CATTessIncrModeNoPropagation / CATTessIncrModeNoPropagationDegenTriangles modes
  //=============================================================================

  // Returns TRUE if the tessellation for this edge has been provided by the caller
  // using CATTessellate::AddEdgeKnown() or CATTessellate::AddFaceKnown().
  // Returns FALSE otherwise.

  virtual CATBoolean IsEdgeKnown() const = 0;



  //=============================================================================
  //- Query methods for CATTessIncrModePropagation mode
  //=============================================================================

  // [Valid only in CATTessIncrModePropagation mode]
  // [Valid only for known edges, i.e. if IsEdgeKnown() returns TRUE ]
  // Returns TRUE if the resulting tessellation for this edge is different than
  // what has been provided by the caller.
  // Returns FALSE otherwise.

  virtual CATBoolean IsModifiedByPropagation() const = 0;



  //=============================================================================
  //- Query methods for CATTessIncrModeNoPropagation / CATTessIncrModeNoPropagationDegenTriangles modes
  //=============================================================================

  // [Valid only in CATTessIncrModeNoPropagation / CATTessIncrModeNoPropagationDegenTriangles modes]
  // [Valid only for known edges, i.e. if IsEdgeKnown() returns TRUE ]
  // Returns TRUE if water-tightness has been achieved, which also means that 
  // the resulting tessellation is same as what has been provided by the caller.
  // Returns FALSE otherwise.

  virtual CATBoolean IsWaterTightnessAchieved() const = 0;



};


#endif //CATTessEdgeIncrInfo_H
