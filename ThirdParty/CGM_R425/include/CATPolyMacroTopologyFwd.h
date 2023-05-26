#pragma once

class CATPolyBody;
class CATPolyCell;
class CATPolyVertex;
class CATPolyEdge;
class CATPolyFace;
class CATPolyVolume;

class CATPolyCellOrbit;
class CATPolyVertexOrbit;
class CATPolyEdgeOrbit;
class CATPolyFaceOrbit;
class CATPolyVolumeOrbit;
class CATPolyVertexOrbitRef;
class CATPolyEdgeOrbitRef;
class CATPolyFaceOrbitRef;
class CATPolyVolumeOrbitRef;

#ifndef _AIX_SOURCE
using CATPolyPseudoManifoldVertex = CATPolyVertexOrbitRef;
using CATPolyManifoldEdge = CATPolyEdgeOrbitRef;
using CATPolyFaceLoop = CATPolyFaceOrbitRef;
using CATPolyVolumeShell = CATPolyVolumeOrbitRef;
#else
typedef CATPolyVertexOrbitRef CATPolyPseudoManifoldVertex;
typedef CATPolyEdgeOrbitRef CATPolyManifoldEdge;
typedef CATPolyFaceOrbitRef CATPolyFaceLoop;
typedef CATPolyVolumeOrbitRef CATPolyVolumeShell;
#endif
