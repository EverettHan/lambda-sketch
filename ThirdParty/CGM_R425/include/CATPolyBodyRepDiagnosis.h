// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyRepDiagnosis
//
//===================================================================
//
// December 2010  Creation: NDO
//===================================================================
#ifndef CATPolyBodyRepDiagnosis_H
#define CATPolyBodyRepDiagnosis_H

#include "PolyVizAdapters.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "CATMapOfPtrToInt.h"
#include "CATMathInline.h"

class CATPolyBodyVizDiagnosis;
class CATPolyBodyGPDiagnosis;

/**
Class used for logging errors occurring during construction of a CATPolyBody from visualization reps.
*/
class ExportedByPolyVizAdapters CATPolyBodyRepDiagnosis
{

public:

  /**
   * Definition of the errors that are logged when a problem with the visualization data is encountered
   * during construction of the CATPolyBody.
   */
  enum Error 
  {
    /** */                                   eNoError                                 = 0x0000,

    /** */                                   eMemoryError                             = 0x0001,

    /** */                                   eBadVertex                               = 0x0100,

    /** */                                   eBadEdge                                 = 0x0200,
    /** */                                   eBadEdge_NonMatchingSurfaceVertexLine    = 0x0201,
    /** */                                   eBadEdge_NonMatchingGeometry             = 0x0202,
    /** */                                   eBadEdge_NoVertexPosition                = 0x0204,
    /** */                                   eBadEdge_InvalidNbVertices               = 0x0208,

    /** */                                   eBadFace                                 = 0x0400,
    /** */                                   eBadFace_NonManifoldSurface              = 0x0401,
    /** */                                   eBadFace_NonMatchingSurfaceVertexLine    = 0x0402,
    /** */                                   eBadFace_NoVertexBuffer                  = 0x0404
  };

public:

  virtual ~CATPolyBodyRepDiagnosis ();

public:

  virtual CATPolyBodyVizDiagnosis* CastAsVizPrimitiveDiagnosis () = 0;
  virtual const CATPolyBodyVizDiagnosis* CastAsVizPrimitiveDiagnosis () const = 0;

  virtual CATPolyBodyGPDiagnosis* CastAsGraphicPrimitiveDiagnosis () = 0;
  virtual const CATPolyBodyGPDiagnosis* CastAsGraphicPrimitiveDiagnosis () const = 0;

public:

  /**
   * Returns the number of cell errors that have been logged.
   */
  INLINE int GetNbCellErrors () const;

protected:

  // Map used for logging the primitive errors encountered during construction of the CATPolyBody.
  CATMapOfPtrToInt _PrimitiveToError;

};

INLINE int CATPolyBodyRepDiagnosis::GetNbCellErrors () const
{
  return _PrimitiveToError.Size ();
}

#endif // !CATPolyBodyVizDiagnosis_H
