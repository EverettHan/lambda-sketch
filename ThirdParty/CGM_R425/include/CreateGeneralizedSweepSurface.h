// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CreateGeneralizedSweepSurface :
// Declaration of global functions used to create and destroy
// an instance of the GeneralizedSweep Surface operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// March 98  Creation                           C.Pradal (CPL)
//=============================================================================
#ifndef CreateGeneralizedSweepSurface_H 
#define CreateGeneralizedSweepSurface_H 

#include "FrFAdvancedOpeSur.h"
#include "CATSkillValue.h"

class CATGeoFactory;
class CATFrFSweepShape;
class CATGeneralizedSweepSurface;

/*
ExportedByFrFAdvancedOpeSur
CATGeneralizedSweepSurface * CreateGeneralizedSweepSurface (CATGeoFactory    * ifactory,
                                                            CATFrFSweepShape * iShape, 
                                                            CATSkillValue      iMode = BASIC);
*/
ExportedByFrFAdvancedOpeSur
void Remove( CATGeneralizedSweepSurface *&ioGeneralizedSweep );



#endif


