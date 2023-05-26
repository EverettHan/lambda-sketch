#ifndef CATCRVPARAMUTILITIES_H
#define CATCRVPARAMUTILITIES_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2007
//
// CATCrvParam utilities
//
//=============================================================================
//
// History
//
// 04/04/07 NLD Creation. IsEqualForCrvParam
// 14/11/07 PTO Chgt ExportedBy pour eviter cycle entre CATGeometricObjects.dll
//              et CATCGMGeoMath.dll (utilisation CATGetTolerance)
// 15/06/09 NLD Argument optionnel iTolObject a IsEqualForCrvParam()
// 20/11/19 Q48 Migration to use const
// 31/03/23 NLD IsEqualForCrvParam: New API with Software configuration
// 05/04/23 NLD IsEqualForCrvParam: TolObject and Software configuration become mandatory
//=============================================================================

#include "CATIAV5Level.h" // for definition of V5 / V6 release level

// ExportedBy (different modules V5/V6)
#ifdef CATIAR425
#include "YP00IMPL.h"
#else
#include "ExportedByCATCGMGeoMath.h"
#endif

#include "CATDataType.h"

#include "CATCrvParam.h"
class CATCurve;
class CATTolerance;
class CATSoftwareConfiguration;

// using IsEqualForCrvParam avoids using == or != tests non XScale compliants in CATCrvParam
//
// using iTolObject         optional argument, if already known by caller,  may speed up computation by avoiding
//                          searching it under iCurve geometric container
//       iCurve             is not mandatory and may be null if iTolObject specified 
//       iConfig            should be given
#ifdef CATIAR425
extern "C" const CATLONG32 ExportedByYP00IMPL IsEqualForCrvParam(const CATCrvParam              & iParam1    ,
                                                                 const CATCrvParam              & iParam2    ,
                                                                 const CATCurve                 * iCurve     ,
                                                                 const CATTolerance             * iTolObject ,
                                                                       CATSoftwareConfiguration * iConfig    );
#else
extern "C" const CATLONG32 ExportedByCATCGMGeoMath IsEqualForCrvParam(const CATCrvParam              & iParam1    ,
                                                                      const CATCrvParam              & iParam2    ,
                                                                      const CATCurve                 * iCurve     ,
                                                                      const CATTolerance             * iTolObject ,
                                                                            CATSoftwareConfiguration * iConfig    );
#endif

#endif
