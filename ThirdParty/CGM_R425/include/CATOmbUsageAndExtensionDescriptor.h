#ifndef CATOmbUsageAndExtensionDescriptor_H
#define CATOmbUsageAndExtensionDescriptor_H

/**
 * @level Protected
 * @usage U1
 */

#include "CATOmbImportExport.h"

#include "CATUnicodeString.h"
class CATOmbUnicodeStringHashtable;
class CATIOmbPLMDataSourceBuilderForImportPreview;
#define OMB_STRUCTURE_VIEWER_SML1
/**
 * 
 */
class ExportedByCATOmbImportExport CATOmbUsageAndExtensionDescriptor
{

  public:
  
  /**
   * Constructor
   */
  CATOmbUsageAndExtensionDescriptor(const CATUnicodeString& iExtension);

  /**
   * Constructor
   */
  CATOmbUsageAndExtensionDescriptor(const CATUnicodeString& iExtension,const CATUnicodeString& iUsage, CATBoolean IsVisible = TRUE);

  CATOmbUsageAndExtensionDescriptor(const CATUnicodeString& iExtension,const CATUnicodeString& iUsage, const CATUnicodeString& iPreviewLateType, const CATUnicodeString& iRole, CATBoolean IsVisible = TRUE);



  /**
   * Destructor
   */
  ~CATOmbUsageAndExtensionDescriptor();


  /**
   * Returns the Extension
   * @return
   * The Extension
   */
  CATUnicodeString GetExtension() const ;

  /**
   * Returns the Usage
   * @return
   * The Usage
   */
  CATUnicodeString GetUsage() const ;

  /**
   * Returns the Role
   * @return
   * The Role
   */
  CATUnicodeString GetRole() const;

  /**
  * Returns the Visibility
  * @return
  * The Visibility
  */
  CATBoolean GetVisibility() const ;

  /**
  * @return TRUE if the importer has preview
  */
  CATBoolean HasPreviewForImport() const;

  /**
  * Provide DataSourceBuilder used to compute all information needed for Preview
  */
  virtual HRESULT GetDataSourceBuilderForImportPreview(CATIOmbPLMDataSourceBuilderForImportPreview*& oDataSourceBuilder);


  private :

	CATUnicodeString  _Extension;
	CATUnicodeString  _Usage ;
  CATBoolean _IsVisible;
  CATBoolean _HasPreview;
  CATUnicodeString _previewLateType;
  CATUnicodeString _Role;

};

#endif

