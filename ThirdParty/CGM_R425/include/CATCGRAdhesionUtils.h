// COPYRIGHT Dassault Systemes 2003

#ifndef CATCGRAdhesionUtils_H
#define CATCGRAdhesionUtils_H

#include "SGInfra.h"
#include "CATBaseUnknown.h"
#include "CATSysSettingRepository.h"
#include "TIE_CATICreateInstance.h"

/****************************************************
 * CGR Container Streaming Adhesion Declaratives    *
 ****************************************************/

/*
 * This macro declares a class to be used as a fake LateType
 * for CGR adhesion. This class implements CATICreateInstance.
 */
#define CATVizDeclareCGRAdhesion(LateType)                                       \
class LateType: public CATBaseUnknown                                            \
{                                                                                \
   CATDeclareClass;                                                              \
};                                                                               \
class LateType##CodeExt: public CATBaseUnknown                                   \
{                                                                                \
   CATDeclareClass;                                                              \
                                                                                 \
public:                                                                          \
                                                                                 \
   HRESULT __stdcall CreateInstance(void **oPPV);				                     \
};                                                                               \
                                                                                 \
extern ExportedBySGInfra int     CATGetCGR_##LateType();                          \
extern ExportedBySGInfra HRESULT CATSetCGR_##LateType(const int iOnOff);


/*
 * This macro implements the class to be used as a fake
 * LateType for CGR adhesion.
 */
#define CATVizImplementCGRAdhesion(LateType)                                     \
CATImplementClass( LateType,                                                     \
                   Implementation,                                               \
                   CATBaseUnknown,                                               \
                   CATNull );                                                    \
CATImplementClass( LateType##CodeExt,                                            \
                   CodeExtension,                                                \
                   CATBaseUnknown,                                               \
                   LateType );                                                   \
                                                                                 \
TIE_CATICreateInstance(LateType##CodeExt);		                                 \
                                                                                 \
HRESULT LateType##CodeExt::CreateInstance(void **oPPV)                           \
{                                                                                \
  if (oPPV == NULL)  return E_FAIL;                                              \
  *oPPV = new LateType();                                                        \
  return S_OK;                                                                   \
}                                                                                \
                                                                                 \
int CATGetCGR_##LateType()                                                       \
{                                                                                \
   if (!CGRRepository)                                                           \
      CGRRepository = CATSysSettingRepository::GetRepository("CGRFormat");       \
                                                                                 \
   int value = 0;                                                                \
   CATLONG32 rc = CGRRepository->ReadAttr ( #LateType, &value);                  \
   if(rc == -1) return -1;                                                       \
   return value;                                                                 \
}                                                                                \
                                                                                 \
HRESULT CATSetCGR_##LateType(const int iOnOff)                                   \
{                                                                                \
   if (!CGRRepository)                                                           \
      CGRRepository = CATSysSettingRepository::GetRepository("CGRFormat");       \
                                                                                 \
CATLONG32 rc = CGRRepository->WriteAttr(#LateType, (int *)&iOnOff);              \
   if(rc == -1) return E_FAIL;                                                   \
   return S_OK;                                                                  \
}

#endif
