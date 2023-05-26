#pragma once

#include "CATPolyVolumeOrbit.h"

// CATPolyVolumeShell
#ifndef _AIX_SOURCE
using CATPolyVolumeShell = CATPolyVolumeOrbitRef;
#else
typedef CATPolyVolumeOrbitRef CATPolyVolumeShell;
#endif
