// COPYRIGHT DASSAULT SYSTEMES 1999
//============================================================================
//
// CreateFrFTopoRefElement :
// Declaration of global functions used to create and destroy
// an instance of a Geometric Refernece Element
//
//============================================================================
// January 99  Creation                              CPL
// 21/11/00 NLD CATTopData
//============================================================================
#ifndef CreateFrFTopoRefElement_H
#define CreateFrFTopoRefElement_H

#include "AdvTopoUtil.h"
#include "CATFrFRefElement.h"

class CATGeoFactory;
class CATGeometry;
class CATTopData;

ExportedByAdvTopoUtil CATFrFRefElement*
                     CreateTopoRefElement( CATGeoFactory* iFactory,
                                           CATTopData*    iTopData,
                                           const CATGeometry* iShell);

#endif // CreateFrFTopoRefElement_H
