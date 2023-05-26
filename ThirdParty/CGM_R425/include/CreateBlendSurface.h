// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CreateBlendSurface :
// Declaration of global functions used to create and destroy
// an instance of the Analytic Blend Surface operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// May. 97  Creation                          Tuan Phung
//=============================================================================
#ifndef CreateBlendSurface_H 
#define CreateBlendSurface_H 

#include "FrFOpeSur.h"

class CATGeoFactory;
class CATBlendSurface;

ExportedByFrFOpeSur
void Remove( CATBlendSurface *&ioBlendSurface );

#endif


