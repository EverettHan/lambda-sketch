#ifndef CATHLRArrangeTangents_H
#define CATHLRArrangeTangents_H
//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1997
//
//=============================================================================
//
// CATHLRArrangeTangents : function that ensure the tangents on a curve
//  has the good norm
//
//=============================================================================
//
// History
//
// Jan. 98   Jose CHILLAN (jch)    Creation            
//
//=============================================================================

#include "CATDataType.h"
#include "HLRGeometry.h"

#include "CATCGMScaleCategoryDef.h" // for enum CATCGMScaleCategory

class CATMathPoint;
class CATMathVector;

// Function that ensure the tangents on a curve has the good norm
ExportedByHLRGeometry void CATHLRArrangeTangents(CATMathPoint      * iArrayPoints,
                                                 CATMathVector     * iArrayTangents,
                                                 CATLONG32           iCountPoints,
                                                 CATCGMScaleCategory iScaleCategory=ScaleN);
#endif
