#ifndef CATTessIncrMode_h
#define CATTessIncrMode_h

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * Specifies the incremental tessellation mode.
 * @param CATTessIncrModePropagation
 * Propagate the extra edge points to old adjacent tessellated faces
 * @param CATTessIncrModeNoPropagation
 * Don't propagate the extra edge points, water-tightness may not be achieved
 * @param CATTessIncrModeNoPropagationDegenTriangles
 * Don't propagate the extra edge points, but create degenerate triangles to achieve water-tightness
 * @param CATTessIncrModeOff
 * Incremental tessellation not activated
 */
enum CATTessIncrMode
{
  CATTessIncrModePropagation,
  CATTessIncrModeNoPropagation,
  CATTessIncrModeNoPropagationDegenTriangles,
  CATTessIncrModeOff
};


#endif //CATTessIncrMode_h
