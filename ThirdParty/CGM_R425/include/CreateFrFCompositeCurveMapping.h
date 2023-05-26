// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CreateFrFCompositeCurveMapping :
// Declaration of global functions used to create and destroy
// an instance of the CompositeCurveMapping operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// Jan. 98  Creation                          Tuan Phung (tpg)
// Oct. 01  Ajout PreciseCompositeCurveMapping Jean Saloux
// 18/06/04 NLD CreateDeprecatedUnpreciseCompositeCurveMapping()
//              remplace CreateCompositeCurveMapping()
// 23/06/04 NLD Ajout ProtectedRemove() pour appel depuis la CCV
//=============================================================================
#ifndef CreateFrFCompositeCurveMapping_H 
#define CreateFrFCompositeCurveMapping_H 
//
#include "FrFAdvancedObjects.h"
//
class CATFrFCompositeCurveMapping;
class CATFrFCompositeCurve;

//
ExportedByFrFAdvancedObjects
CATFrFCompositeCurveMapping * CreatePreciseCompositeCurveMapping(const CATFrFCompositeCurve *iCompositeCurve);
//
ExportedByFrFAdvancedObjects
CATFrFCompositeCurveMapping * CreateDeprecatedUnpreciseCompositeCurveMapping(const CATFrFCompositeCurve *iCompositeCurve);
//
ExportedByFrFAdvancedObjects
void PrivRemove(CATFrFCompositeCurveMapping *&ioCompositeCurveMapping);

ExportedByFrFAdvancedObjects
void ProtectedRemove(CATFrFCompositeCurveMapping*& iCompositeCurveMapping);

#endif


