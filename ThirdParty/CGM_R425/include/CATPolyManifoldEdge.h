#pragma once

#include "CATPolyEdgeOrbit.h"

// CATPolyManifoldEdge
#ifndef _AIX_SOURCE
using CATPolyManifoldEdge = CATPolyEdgeOrbitRef;
#else
typedef CATPolyEdgeOrbitRef CATPolyManifoldEdge;
#endif
