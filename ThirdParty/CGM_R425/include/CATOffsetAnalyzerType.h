// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATOffsetAnalyzerType.cpp
// Header definition of CATOffsetAnalyzerType
//
//===================================================================

//===================================================================
//
//  MNJ - October 2011
//===================================================================
#ifndef CATOffsetAnalyzerType_H
#define CATOffsetAnalyzerType_H

//==============================================================================
// OffsetType
//==============================================================================
enum CATOffsetAnalyzerType{
  DEFAULT=0, // rien
  SKIN, // Offset
  PERPENDICULAR, // ThickSurface avec parois laterales perpendiculaires (SheetMetal)
  PERPENDICULAR_G1SMOOTHED, // ThickSurface avec parois laterales lissees
  VOLUMIC_OTHER}; // Shell ou ThickSurface/Shell en mode geo (Import)

//==============================================================================
// CATComputationMode
//==============================================================================
enum CATComputationMode{
  NONE=0,
  LOGICAL,
  GEOMETRICAL};

#endif

