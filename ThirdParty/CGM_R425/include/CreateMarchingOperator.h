// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CreateMarchingOperator :
// Declaration of global functions used to create and destroy
// an instance of the Marching Operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// May. 97  Creation                          Tuan Phung
//=============================================================================
#ifndef CreateMarchingOperator_H 
#define CreateMarchingOperator_H 

#include "FrFAdvancedOpeSur.h"
#include "CATDataType.h"

class CATGeoFactory;
class CATFrFGeneratingShape;
class CATMarchingOperator;

ExportedByFrFAdvancedOpeSur CATMarchingOperator * CreateMarchingOperator(CATGeoFactory *iFactory, 
                                                                         const CATLONG32 iNbrOfShapes,
                                                                         const CATFrFGeneratingShape **iShapes);


ExportedByFrFAdvancedOpeSur void Remove( CATMarchingOperator *&ioMarchingOperator );

#endif


