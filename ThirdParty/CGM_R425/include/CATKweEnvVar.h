
//===================================================================
//
// CATKweEnvVar.h
// Header definition of CATKweEnvVar
//
//===================================================================
//
// Usage notes:
//
//  Declaration   : CATKWE_DECLARE_VAR(EnvVarName);
//  Init (in cpp) : CATKWE_INIT_VAR(CATKweEnvVar, EnvVarName, DefaultValue);
//  Call          : CATKweEnvVar::EnvVarName()
//
//===================================================================
//
//  01.12.20 Creation KJD
//===================================================================
#ifndef CATKweEnvVar_H
#define CATKweEnvVar_H

#include "CATLifSpecs.h"
#include "CATKweEnvVarMacros.h"

//-- System -----------------------------------------------------------
#include "CATGetEnvValue.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

//----------------------------------------------------------------------
// CATKweEnvVar
//----------------------------------------------------------------------
class ExportedByCATLifSpecs CATKweEnvVar : public CATBaseUnknown
{
  CATDeclareClass;

  ////////////////// ENV VARIABLE DECLARATION //////////////////

  CATKWE_DECLARE_VAR(Kwe_PythonEditorCmd); //kjd 01.12.2020 PythonActionCmd
  CATKWE_DECLARE_VAR(Kwe_UdfCatalogPreview);     //kjd 24.03.2021 CATEUdfCatalogPreview::GetObjectPreview
  CATKWE_DECLARE_VAR(Kwe_KACBatch);     //ary3 03.03.2022 KACBatch
  CATKWE_DECLARE_VAR(Kwe_TraceToCompare); //kjd 22.04.22 Trace Light
  CATKWE_DECLARE_VAR(Kwe_KAC_PythonOperation); //kjd 28.06.22 PythonOperation
  // <--- HERE ADD NEW ENV VARIABLE DECLARATION



//////////////////////////////////////////////////////////////

public:
  // Constructor and destructor
  CATKweEnvVar() {};
  virtual ~CATKweEnvVar() {};

private:
  // Copy constructor and equal operator
  CATKweEnvVar(CATKweEnvVar&);
  CATKweEnvVar& operator=(CATKweEnvVar&);
};
//-----------------------------------------------------------------------

#endif
