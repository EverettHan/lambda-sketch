#ifndef CATOmbImportExportManager_H
#define CATOmbImportExportManager_H

/**
* @level Protected
* @usage U1
*/

// System
#include "CATListOfCATUnicodeString.h"
#include "CATUnicodeString.h"
// ObjectModelerCollection
#include "CATOmxAutoPtr.h"
// CATVirtualVaultSystem
#include "CATVVSUrl.h"
#include "CATVVSUrlAndStreamManager.h"
// ObjectModelerBase
#include "CATListOfCATOmbUsageAndExtensionDescriptor.h"
#include "CATOmbImportExport.h"
#include "CATOmbImportExportParameters.h"
#include "CATOmbLifeCycleRootsBag.h"
#include "CATOmbLoadableDataUniqueKey.h"

#if !defined(_WINDOWS_SOURCE) || defined (__IfcCustMapUI) || defined (__CATPLMImportToFileUI) 
#include "CATComponentId.h"
#endif
#include "CATIAV5Level.h"
#include "IUnknown.h"
#include "CATSysMacros.h"
#include "CATCollec.h"

class  CATILockBytes2;
class CATComponentId;

/**
* Enable Consumer Applications
* to Export/Import Data inside the V5 Session
*/
class ExportedByCATOmbImportExport CATOmbImportExportManager
{
public:

  /**
  * ListAllAvailableFormatsToImport
  * @param oImportFormatAvailable
  * All the Format that the V5 can import.
  * @return
  * S_OK if we was able to ,or E_FAIL otherwise
  */
  static HRESULT ListAllAvailableFormatsToImport(CATListOfCATOmbUsageAndExtensionDescriptor& oImportFormatAvailable);
  /*
  * Allow to verify if an importer with a specific extension an usage is available.
  * @return
  * S_OK if the the Importer is available.
  * S_FALSE the the Importer is not available.
  * E_FAIL otherwise.
  */
  static HRESULT ImportFormatIsAvailable(const CATUnicodeString& iExtension, const CATUnicodeString& iUsage);


  /*
  * Retrieve the Importers which are able to import a stream identified by an Url.
  * If Importer's extension or usage is known it can be given in input (optional), otherwise
  * iExtension and iUsage should not be valuated.
  * @return the list of Importer able to Import a stream.
  */
  static HRESULT RetrieveListOfImportFormatsFromURL(const CATVVSUrl& iUrl, const CATUnicodeString& iExtension,
    const CATUnicodeString& iUsage, CATListOfCATOmbUsageAndExtensionDescriptor& oImportFormatAvailable);


  /**
  * Import a stream identified by a Url inside a V5 Session
  * @param iUrl
  * The identifier of the stream to import.
  * @param oRootObject
  * The Component from which we can retrieve the data created by the import
  * @return
  * S_OK if the url was succesfully imported inside the session, or E_FAIL otherwise
  */
  // deprecated move on CATOmbLifeCycleRootsBag
  static HRESULT ImportUrlInsideSession(const CATVVSUrl& iUrl, const CATUnicodeString& iExtension, const CATUnicodeString& iUsage,
    CATOmbImportExportParameters* iParameters, CATBaseUnknown*& oRootObject);


  /**
  * Import a stream identified by a Url inside a V5 Session
  * @param iUrl
  * The identifier of the stream to import.
  * @param oBag
  * The Bag containing all the created components
  * @return
  * S_OK if the url was succesfully imported inside the session, or E_FAIL otherwise
  */
  static HRESULT ImportUrlInsideSession(const CATVVSUrl& iUrl, const CATUnicodeString& iExtension, const CATUnicodeString& iUsage,
    CATOmbImportExportParameters* iParameters, CATOmbLifeCycleRootsBag& oBag);

  /**
  * List All the available formats for export operation for a Document
  * @param iComponent
  * The Component From which the exported data will be computed
  * @param oExportFormatAvailable
  * The list of supported format
  * @return
  * S_OK if the url was succesfully created, or E_FAIL otherwise
  */
  static HRESULT ListAllAvailableFormatsAtExportFromComponent(CATBaseUnknown& iComponent, CATListOfCATOmbUsageAndExtensionDescriptor& oExportFormatAvailable);

  /**
  * Export PLM Component Data to a File stream
  * @param iComponent
  * The PLM Component from which data are to be exported
  * @param iExtension
  * The extension of the target file, defining the internal data format of the stream to be generated
  * @param iUsage
  * The target usage that eventually discriminates among distinct exporters for the same PLM input data and extension
  * @param iUrl
  * The url locating the stream to be generated by exporter at Save
  * @param iParameters
  * The eventual stream generation parameters to be passed to exporter
  * @param iRole
  * The eventual Role associated to the component stream descriptor which stream is to be (re)generated by the exporter
  * @return
  * S_OK if the exporter has been found and the url pointed is correctly filled by the exporter, E_FAIL otherwise.
  *  CATOmb_S_KeepPreviousStream : nothing should be done and previous stream should not be updated. This return code cannot be used at stream creation.
  *
  * NB:
  * The exporter is found using information given as input and compared to the information
  * stored in the .capa or (new) .xdefinition declarative file (cf CATIOmbExporter.h general description):
  *
  *   �	The PLM basetype Type :  must be same as define itn the .capa/.xdefinition file
  *   �	The specific sub-type for a representation reference (drawing, part, analysis), retrieved using Authoring Stream Descriptor:  must be the same as defined optionaly in the .capa/.xdefinition file
  *    	if no authoring Stream descriptor are associated to the component, the sub type must not be valuated in the capa file
  *   �	iUsage & iExtension:  must be exactly the same as defined in the capa file
  *   the (PLM type, sub-type, Usage, Extension, Role) data set identifies a given exporter in a unique way
  */
  static HRESULT ExportFromComponentToFormatAndToUrl(CATBaseUnknown& iComponent, const CATUnicodeString& iExtension, const CATUnicodeString& iUsage,
    const CATVVSUrl& iUrl, CATOmbImportExportParameters* iParameters, CATUnicodeString iRole = "");

  /**
  * List All the available formats for Export
  * @param oExportFormatAvailable
  *   The list of supported format
  * @return
  *   S_OK if the list has been computed successfully
  */
  static HRESULT ListAllAvailableFormatsAtExport(CATListOfCATOmbUsageAndExtensionDescriptor& oExportFormatAvailable);

  /**
  * Not implemented on R2013x
  * Retrieves Outliner corresponding to the input definition
  * The attributs used to define the Outliner are:
  * @param iUsage
  *   The usage of the Outliner, for instance 'BoundingBox' if it's supposed to compute bounding box of a geometry
  * @param iCompId
  *   The component id, it will allow to get the super type (firstDSType) of the component, then find corresponding outliner thanks to xdefintion file declaration
  * @param oOutliner
  *   the outliner if found (AddRef'ed).
  * @return
  *     S_OK if outliner found, E_FAIL if something went wrong
  */
  /**
  * idem GetOutliner above, except it will get the superType from the CATComponentId iCompId
  */
  static HRESULT GetOutliner(const CATUnicodeString& iUsage, const CATComponentId& iCompId, CATBaseUnknown*& oOutliner);

  /**
  * return an iterator on all usages that have been registered for outlining (e.g 'BoundingBox')
  */
  static CATOmxIter<CATUnicodeString> GetOutlinerUsagesIterator();

  /**
  * Not implemented on R2013x
  * Retrieves Selector corresponding to the input definition
  * The attributs used to define the Selector are:
  * @param iType
  *   Type of the component on which the selector will be applied.
  * @param iLatetype
  *   The latetype of the stream on which the selector will be applied.
  * @param iInterface
  *   The interface that should be implemented by the selector
  * @param oSelector
  *   the selector if found (smart pointer)
  * @return
  *     S_OK if selector found, E_FAIL if something went wrong
  */
  static HRESULT GetSelector(const CATUnicodeString iType, const CATUnicodeString& iLatetype, const CATUnicodeString& iInterface, CATOmxSR<CATBaseUnknown>& oSelector);
  //obsolete
  static HRESULT GetSelector(const CATUnicodeString& iLatetype, const CATUnicodeString& iInterface, CATOmxSR<CATBaseUnknown>& oSelector);

  /**
  * Not implemented on R2013x
  * Retrieves Updater corresponding to the input definition
  * The attributs used to define the Updater are:
  * @param iInputExtension
  *   the persistency type of the input stream.
  * @param iOutputExtension
  *   the persistency type of the output extension
  * @param iFormat
  *   the format of output stream
  * @param iRole
  *   the role of output stream
  * @param oStreamMode
  *   the stream method supported by updater (File or ILB)
  * @param oUpdater
  *   the updater if found (smart pointer)
  * @return
  *     S_OK if outliner found, E_FAIL if something went wrong
  */
  static HRESULT GetUpdater(const CATUnicodeString& iInputExtension, const CATUnicodeString& iOutputExtension, const CATUnicodeString& iFormat, const CATUnicodeString& iRole, CATOmxSR<CATBaseUnknown>& oUpdater,const CATUnicodeString& iVendorId=CATUnicodeString());

private:

  CATOmbImportExportManager(const CATUnicodeString& iSessionName);
  CATOmbImportExportManager();
  ~CATOmbImportExportManager();

  static HRESULT GetFilePathFromUrl(CATVVSUrl& iUrl, CATUnicodeString& oFilePath);

  static CATBoolean StreamSynchroRequestedByOMB(CATOmbImportExportParameters* iParameters, CATOmxAutoPtr<CATOmbLoadableDataUniqueKey>& opKey);


  static HRESULT ImportUrlInsideSession(const CATVVSUrl& iUrl, const CATUnicodeString& iExtension, const CATUnicodeString& iUsage,
    CATOmbImportExportParameters* iParameters, CATBaseUnknown*& oRootObject, CATOmbLifeCycleRootsBag& oBag, CATBoolean iBagMode);

};

#endif
