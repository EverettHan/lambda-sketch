// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIOmbXImportExportDefinition.h
// Define the CATIOmbXImportExportDefinition interface
//
// /!\ WARNING /!\
//
// Any C++ class that implements CATIOmbXImportExportDefinition must inherit from
// the adapter CATEOmbXImportExportDefinition (with a E)
//
// /!\ WARNING /!\
//
//===================================================================
//
// Usage notes:
//   
//
//===================================================================
#ifndef CATIOmbXImportExportDefinition_H
#define CATIOmbXImportExportDefinition_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATOmbImportExport.h"
#include "CATBaseUnknown.h"
#include "CATBooleanDef.h"
#include "CATOmxSharable.h"
class CATOmbImportExportParameters;
class CATPLMStructureViewer;
class CATVVSUrl;

#include "CATIAV5Level.h"
#include "IUnknown.h"
#include "CATSysMacros.h"
#include "CATCollec.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATOmbImportExport IID IID_CATIOmbXImportExportDefinition;
#else
extern "C" const IID IID_CATIOmbXImportExportDefinition ;
#endif


class ExportedByCATOmbImportExport CATIOmbPLMDataSourceBuilderForImportPreview : public CATOmxSharable///replaces CATPLMDataSourceBuilder
{
public:
  virtual HRESULT GenerateDataSources(const CATVVSUrl &iUrl,CATOmbImportExportParameters& iHelper)=0;
};



//------------------------------------------------------------------

class ExportedByCATOmbImportExport CATIOmbXImportExportDefinition: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /**
  * Returns the DataSource builder for a specific context
  * @return
  * oDataSourceBuilder
  */
  virtual HRESULT GetDataSourceBuilderForImportPreview(CATOmbImportExportParameters& iParams, CATIOmbPLMDataSourceBuilderForImportPreview*& oDataSourceBuilder )= 0;

    
  /** 
  * If Exporter is seen with CustomVisibility, this method returns the availability of the exporter for a specific component .
  * Else it won't be called
  * @param iComponent [in]
  *   A pointer to the component to export
  *
  * @return
  *   <code>TRUE</code> The exporter is available
  *   <code>FALSE</code> The exporter is not available
  */    
  virtual CATBoolean ReturnAvailabilityForExportComponent(const CATBaseUnknown* iComponent) = 0;

  /** 
  * If Importer is seen with CustomVisibility, This method returns its availability.
  * Else it won't be called
  *
  * @return
  *   <code>TRUE</code> The importer is available
  *   <code>FALSE</code> The importer is not available
  */    
  virtual CATBoolean ReturnAvailabilityForImportUrl() = 0;

  /** 
  * If Outliner is seen with CustomVisibility, this method returns the availability of the outliner for a specific component .
  * Else it won't be called
  * @param iComponent [in]
  *   A pointer to the component to outline
  *
  * @return
  *   <code>TRUE</code> The outliner is available
  *   <code>FALSE</code> The outliner is not available
  */
  virtual CATBoolean ReturnAvailabilityForOutlineComponent(const CATBaseUnknown* iComponent) = 0;
};
CATDeclareHandler( CATIOmbXImportExportDefinition, CATBaseUnknown );
//------------------------------------------------------------------



#endif
