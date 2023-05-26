/* -*-c++-*- */
#ifndef CATPLMSessionMaterialDirtyBypass_H
#define CATPLMSessionMaterialDirtyBypass_H
//
// CATIA Version 6 Release 215
// Copyright   : Dassault Systemes 2013
//-----------------------------------------------------------------------------
// Description :
// C++ class header file for the class named "CATPLMSessionMaterialDirtyBypass"
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Inheritance : CATPLMSessionMaterialDirtyBypass
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//
#include "CATPLMModelBuilder.h"
#include "CATBaseUnknown.h"
#include "CATPLMID.h"
#include "CATLISTV_CATPLMID.h"
#include "CATPLMLoadingSpec.h"

/**
* @level Protected
* @usage U1
*/

#define MATERIAL_MaterialType "CATMatReference"

#ifdef CATIAR425

class ExportedByCATPLMModelBuilder   OMX_DEPRECATED("This class is deprecated. Your application should work without use of this service.")
  CATPLMSessionMaterialDirtyBypass
{
public:
  OMX_DEPRECATED("This method is deprecated. Your application should work without use of this service.")
    static HRESULT PreLoadMaterials(const char* iMaterialTypeToLoad = MATERIAL_MaterialType, const char* iWithProfile = LS_Explore);
};

#else

class ExportedByCATPLMModelBuilder
  CATPLMSessionMaterialDirtyBypass
{
public:
  static HRESULT PreLoadMaterials(const char* iMaterialTypeToLoad = MATERIAL_MaterialType, const char* iWithProfile = LS_Explore);

private:
  static HRESULT Is3DXML43();
  static HRESULT SearchMaterialRefs(const char* iMaterialTypeToSearch, CATLISTV(CATPLMID)& oMaterialRefs);
  static HRESULT LoadMaterialRefs(CATLISTV(CATPLMID)& iMaterialRefs, const char* iWithProfile);
};

#endif


#endif
