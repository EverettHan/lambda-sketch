#ifndef CATScriptSelectionConstants_h
#define CATScriptSelectionConstants_h
// COPYRIGHT DASSAULT SYSTEMES 2001

#include "CATScriptReplayInteractions.h"

// sub-elements interfering in the boundary automation API:
//   . sDetermineSelectionObject
//   . sDetermineBRepFeature
//   . sDetermineConnector
  typedef unsigned long CATScBoundaryType;
  ExportedByCATScriptReplayInteractions extern const CATScBoundaryType ScBoundary;                  // 1 
  ExportedByCATScriptReplayInteractions extern const CATScBoundaryType ScFace;                      // 2
  ExportedByCATScriptReplayInteractions extern const CATScBoundaryType ScPlanarFace;                // 4
  ExportedByCATScriptReplayInteractions extern const CATScBoundaryType ScCylindricalFace;           // 8
  ExportedByCATScriptReplayInteractions extern const CATScBoundaryType ScEdge;                      // 16
  ExportedByCATScriptReplayInteractions extern const CATScBoundaryType ScTriDimFeatEdge;            // 32
  ExportedByCATScriptReplayInteractions extern const CATScBoundaryType ScRectilinearTriDimFeatEdge; // 64
  ExportedByCATScriptReplayInteractions extern const CATScBoundaryType ScBiDimFeatEdge;             // 128
  ExportedByCATScriptReplayInteractions extern const CATScBoundaryType ScRectilinearBiDimFeatEdge;  // 256
  ExportedByCATScriptReplayInteractions extern const CATScBoundaryType ScMonoDimFeatEdge;           // 512
  ExportedByCATScriptReplayInteractions extern const CATScBoundaryType ScRectilinearMonoDimFeatEdge;// 1024
  ExportedByCATScriptReplayInteractions extern const CATScBoundaryType ScVertex;                    // 2048
  ExportedByCATScriptReplayInteractions extern const CATScBoundaryType ScTriDimFeatVertexOrBiDimFeatVertex;               // 4096
  ExportedByCATScriptReplayInteractions extern const CATScBoundaryType ScNotWireBoundaryMonoDimFeatVertex;                // 8192
  ExportedByCATScriptReplayInteractions extern const CATScBoundaryType ScZeroDimFeatVertexOrWireBoundaryMonoDimFeatVertex;// 16384

#endif
