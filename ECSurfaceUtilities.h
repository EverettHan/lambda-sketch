#ifndef ECSurfaceUtilities_H
#define ECSurfaceUtilities_H

#include <CATBoolean.h>

class CATSurface;

class  ECSurfaceUtilities
{
public:
    static CATBoolean  IsSurfaceFinite( CATSurface * iSurface ) ;
};

#endif //ECSurfaceUtilities_H