/* -*-C++-*-*/
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES	2010
//=============================================================================
// CATTessFaceIncrInfo
/**
  * This object provides information of face tessellation in the context 
  * of incremental tessellation
  */
//=============================================================================

#ifndef CATTessFaceIncrInfo_H
#define CATTessFaceIncrInfo_H


#include "TessAPI.h"
#include "CATBoolean.h"
#include "CATDataType.h"

class CATTessDegenFanIter;

//-----------------------------------------------------------------------------
class ExportedByTessAPI CATTessFaceIncrInfo
{
public:

  //=============================================================================
  //- Constructor and Destructor
  //=============================================================================

  CATTessFaceIncrInfo();

  virtual ~CATTessFaceIncrInfo();



  //=============================================================================
  //- Query methods for CATTessIncrModePropagation mode
  //=============================================================================

  // [Valid only in CATTessIncrModePropagation mode]
  // Returns TRUE if the tessellation for this face has been provided by the caller
  // using CATTessellate::AddFaceKnown().
  // Returns FALSE otherwise.

  virtual CATBoolean IsFaceKnown() const = 0;

  // [Valid only in CATTessIncrModePropagation mode]
  // [Valid only for known faces, i.e. if IsFaceKnown() returns TRUE ]
  // Returns TRUE if the resulting tessellation for this face is different than
  // what has been provided by the caller.
  // Returns FALSE otherwise.

  virtual CATBoolean IsModifiedByPropagation() const = 0;



  //=============================================================================
  //- Query methods for CATTessIncrModeNoPropagation / CATTessIncrModeNoPropagationDegenTriangles modes
  //=============================================================================

  // [Valid only in CATTessIncrModeNoPropagation / CATTessIncrModeNoPropagationDegenTriangles modes]
  // Returns TRUE if water-tightness has been achieved, 
  //      In CATTessIncrModeNoPropagation mode this means that the resulting tessellation 
  //        is same as what has been provided by the caller.
  //      In CATTessIncrModeNoPropagationDegenTriangles mode this means that either the 
  //        resulting tessellation is same as what has been provided by the caller or
  //        water-tightness has been achieved by creating degenerate triangles
  // Returns FALSE otherwise.

  virtual CATBoolean IsWaterTightnessAchieved() const = 0;



  //=============================================================================
  //- Query methods for CATTessIncrModeNoPropagationDegenTriangles modes
  //=============================================================================

  // [Valid only in CATTessIncrModeNoPropagationDegenTriangles mode]
  // Returns the number of degenerate triangles created for this face

  virtual CATLONG32 NumberOfDegenFansCreated() const = 0;
	
  // [Valid only in CATTessIncrModeNoPropagationDegenTriangles mode]
  // Returns the iterator for querying the degenerate triangles created for this face

  virtual CATTessDegenFanIter* GetDegenerateFansIterator() = 0;
};


#endif //CATTessFaceIncrInfo_H
