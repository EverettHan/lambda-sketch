// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CreateFillSurface :
// Declaration of global functions used to create and destroy
// an instance of the Fill Surface operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// May. 97  Creation                          Tuan Phung
//=============================================================================
#ifndef CreateFillSurface_H 
#define CreateFillSurface_H 

#include "FrFOpeSur.h"
#include "CATSkillValue.h"
#include "CATDataType.h"

class CATGeoFactory;
class CATCurve;
class CATCrvLimits;
class CATFillSurface;
class CATFrFNurbsMultiForm;

ExportedByFrFOpeSur
CATFillSurface * CreateFillSurface (        CATGeoFactory         * ifactory,
                                    const   CATLONG32               inumberofcurves, 
                                    const   CATCurve             ** itabofcurve, 
                                            CATCrvLimits          * itabofcrvlimits,
                                            CATSkillValue           iMode = BASIC);
ExportedByFrFOpeSur
CATFillSurface * CreateFillSurface (        CATGeoFactory         * ifactory,
                                    const   CATLONG32               inumberofcurves, 
                                    const   CATCurve             ** itabofcurve, 
                                            CATCrvLimits          * itabofcrvlimits,
                                            CATLONG32               iNbOfMultiForms,
                                    const   CATFrFNurbsMultiForm ** iMultiForm,
                                            CATLONG32             * iTransitioncontMultiForm,
                                            CATSkillValue           iMode = BASIC);


#endif


