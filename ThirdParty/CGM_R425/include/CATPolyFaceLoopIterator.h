#pragma once

#include "CATPolyFaceOrbitIterator.h"

// CATPolyFaceLoopIterator
#ifndef _AIX_SOURCE
using CATPolyFaceLoopIterator = CATPolyFaceOrbitIterator;
#else
typedef CATPolyFaceOrbitIterator CATPolyFaceLoopIterator;
#endif
