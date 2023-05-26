// COPYRIGHT Dassault Systemes Provence 2007
//==============================================================================
//
// CATCldToleranceBase.h
// Header definition of CATCldToleranceBase
//
//==============================================================================
//
// Usage notes: 
//
//==============================================================================
// 14-Nov-2007 YSN: R18SP3: Creation
//==============================================================================
#ifndef CATCldToleranceBase_H
#define CATCldToleranceBase_H

#include "ExportedByCATCloudBasicResources.h"
#include "float.h"


//------------------------------------------------------------------------------
class ExportedByCATCloudBasicResources CATCldToleranceBase
{
public:

    inline static const double Infinite();
    // par rapport au vector normalisee d'une direction
    // Cette value est donc invariable quel que soit le scale.
    inline static const double TolDirection(); 

    // Resolution
    inline static const double ResolutionG0Default() ;

    // Action
    static void SwellBoundingBox(double ioMin[3], double ioMax[3]);
	inline static const float InfiniteF();
};

//------------------------------------------------------------------------------
inline const double
CATCldToleranceBase::Infinite() 
{
    return DBL_MAX;
}

inline const float
CATCldToleranceBase::InfiniteF() 
{
    return FLT_MAX;
}

inline const double
CATCldToleranceBase::TolDirection() 
{
    return 1.0E-09;
}

//------------------------------------------------------------------------------
inline const double
CATCldToleranceBase::ResolutionG0Default() 
{
    return 0.001;
}

#endif
