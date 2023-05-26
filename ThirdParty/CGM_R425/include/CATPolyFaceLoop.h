#pragma once

#include "CATPolyFaceOrbit.h"

// CATPolyFaceLoop
#ifndef _AIX_SOURCE
using CATPolyFaceLoop = CATPolyFaceOrbitRef;
#else
typedef CATPolyFaceOrbitRef CATPolyFaceLoop;
#endif
