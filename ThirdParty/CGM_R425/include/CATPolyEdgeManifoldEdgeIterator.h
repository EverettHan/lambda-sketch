#pragma once

#include "CATPolyEdgeOrbitIterator.h"

// CATPolyEdgeManifoldEdgeIterator
#ifndef _AIX_SOURCE
using CATPolyEdgeManifoldEdgeIterator = CATPolyEdgeOrbitIterator;
#else
typedef CATPolyEdgeOrbitIterator CATPolyEdgeManifoldEdgeIterator;
#endif
