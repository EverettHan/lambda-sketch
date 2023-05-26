#pragma once

#include "CATPolyVertexOrbit.h"

// CATPolyPseudoManifoldVertex
#ifndef _AIX_SOURCE
using CATPolyPseudoManifoldVertex = CATPolyVertexOrbitRef;
#else
typedef CATPolyVertexOrbitRef CATPolyPseudoManifoldVertex;
#endif
