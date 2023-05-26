/* -*-c++-*- */
#ifndef CATDynHiddenCreate_H
#define CATDynHiddenCreate_H
//=============================================================================
// 16 Feb 2021 DLR6 : new creates for CATDynBoolean
//=============================================================================
#include "CATIACGMLevel.h"
//=============================================================================
#include "BONEWOPE.h"

#include "CATDynBoolean.h"
#include "CATDynBooleanCGMType.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATListPtrDynBoolSharedFaceData;

//=============================================================================
extern "C"
{
ExportedByBONEWOPE CATDynBoolean    * CATCreateDynBoolean_NoVolumicSimplif(
                          CATGeoFactory                   * ipContainer,
                          CATTopData                      * ipData,
                          CATDynBooleanCGMType              iOperation,
                          CATBody                         * ipBody_1,
                          CATBody                         * ipBody_2,
                          CATListPtrDynBoolSharedFaceData * ipListSharedFaceOperations = NULL);
};


#endif // CATDynHiddenCreate_H
