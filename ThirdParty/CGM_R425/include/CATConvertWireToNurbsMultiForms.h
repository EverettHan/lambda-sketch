// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATConvertWireToNurbsMultiForms :
// Creation of NurbsMultiForms with a wire
// It is possible to specify reference multiforms used as references for 
// segmentation and parametrisation.
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// 22/11/99 Creation                                      DHN
// 28/11/00 NLD signature avec CATTopData
// 19 07 05 NLD Inactivation de la signature sans CATTopData
// 09 12 09 NLD Suppression definitive de la signature sans CATTopData
//=============================================================================
// Remarque: utilise par RGR dans le sweep variationnel
//=============================================================================

#ifndef CATConvertWireToNurbsMultiForms_H
#define CATConvertWireToNurbsMultiForms_H
//
#include "CATDataType.h"
#include "AdvTopoUtil.h"
#include "CATConvertWireToNurbsMultiForms.h"
//
class CATFrFNurbsMultiForm;
class CATBody;
class CATTopData;

ExportedByAdvTopoUtil
CATFrFNurbsMultiForm **CATConvertWireToNurbsMultiForms(CATTopData* iTopData,
                                                       const CATBody * iWire,
                                                       CATFrFNurbsMultiForm **iRefMults,
                                                       CATLONG32 iNbRefMults);
#endif // CATConvertWireToNurbsMultiForms






