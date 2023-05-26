// COPYRIGHT Dassault Systemes 2015
//===============================================

#ifndef CATEOmbXImportExportDefinition_h
#define CATEOmbXImportExportDefinition_h
// ==============================================
// Adapter for CATIOmbXImportExportDefinition
// ==============================================

#include "CATIOmbXImportExportDefinition.h"
class CATIOmbPLMDataSourceBuilderForImportPreview;
class CATOmbImportExportParameters;

class ExportedByCATOmbImportExport CATEOmbXImportExportDefinition : public CATIOmbXImportExportDefinition
{
public:
  virtual HRESULT GetDataSourceBuilderForImportPreview(CATOmbImportExportParameters& iParams, CATIOmbPLMDataSourceBuilderForImportPreview*& oDataSourceBuilder);
  virtual CATBoolean ReturnAvailabilityForExportComponent(const CATBaseUnknown* iComponent);
  virtual CATBoolean ReturnAvailabilityForImportUrl();
  virtual CATBoolean ReturnAvailabilityForOutlineComponent(const CATBaseUnknown* iComponent);
};


#endif
