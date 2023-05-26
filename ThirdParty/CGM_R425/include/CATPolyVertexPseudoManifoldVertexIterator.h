#pragma once

#include "CATPolyVertexOrbitIterator.h"

// CATPolyVertexPseudoManifoldVertexIterator
#ifndef _AIX_SOURCE
using CATPolyVertexPseudoManifoldVertexIterator = CATPolyVertexOrbitIterator;
#else
typedef CATPolyVertexOrbitIterator CATPolyVertexPseudoManifoldVertexIterator;
#endif
