#ifndef CATOmbXConverterManager_H
#define CATOmbXConverterManager_H

/**
 * @level Protected
 * @usage U1
 */

#include "CATOmbXConverterForInfraOnly.h"

#include "CATUnicodeString.h"

#include "CATIOmyIncidentCollector.h"
#include "CATOmbConverterManager.h"
#include "CATToken.h"
#include "CATOmxVector.h"
#include "CATOmxOHMap.h"
#include "CATOmbStreamDescriptorProperties.h"
#include "CATOmxArray.h"
#include "CATOmxSR.h"
#include "CATOmxAny.h"

class CATDocument;
class CATVVSURLConnection;
class CATIDocId;
class CATComponentId;
class CATIOmbStreamDescriptor;
class CATOmxKeyValueBlock;
class CATOmbXConverterInfo;
class XConverterApplicativeInfos;
class XConverterInfo;

enum ConverterCapability { ConverterRead = 1, ConverterWrite, ConverterReadWrite };

/*
  Class to manage applicatives infos for a specific declarative

*/
class ExportedByCATOmbConverter CATOmbXConverterApplicativeInfos : public CATOmxSharable
{
public:
  /*
    Add another applicative info
  */
  virtual void AddOtherInformations(CATUnicodeString iKey, CATOmxAny iValue) = 0;
  /*
    Get all the other applicative infos (different from VendorID, ListExtensions and VendorPriority)
  */
  virtual CATOmxOHMap<CATUnicodeString, CATOmxAny> GetOtherInformations() = 0;

  /*
   return the Vendor ID
  */
  virtual CATUnicodeString GetVendorID() = 0;

  /*
   return the list of extensions (first one is default extension)
  */
  virtual CATOmxArray<CATUnicodeString> GetListExtension() = 0;

  /*
    return the Vendor Priority (1 is the maximal priority)
  */
  virtual int GetVendorPriority() = 0;

};

/*
class to manage XConverter information
*/
class ExportedByCATOmbConverter CATOmbXConverterInfo : public CATOmxSharable
{
public:
  /*
    return the list of applicative info associated to the converter
    you can use CATOmxIter<CATOmbXConverterApplicativeInfos> iter=oList.Iterator() to get an iterator on the list
  */
  virtual HRESULT GetFamilyMembers(CATOmxVector<CATOmbXConverterApplicativeInfos>& oList) = 0;

  /*
    Create an applicative info for the XConverter and return the created info to add another informations
  */
  virtual CATOmxSR<CATOmbXConverterApplicativeInfos> AddApplicativeInfos(CATUnicodeString iVendorId, CATOmxArray<CATUnicodeString> iListOfExtension, int iVendorIDPriority) = 0;

  /*
    return an applicative info based on VendorID
  */
  virtual CATOmxSR<CATOmbXConverterApplicativeInfos> GetApplicativeInfos(CATUnicodeString iVendorId) = 0;

  /*
    return the information of the SD (Format/Rôle/SDLateType)
  */
  virtual CATOmbStreamDescriptorProperties GetSDProp() = 0;

  /*
    return the direct access to SD informations
  */
  virtual CATOmbStreamDescriptorFormat GetFormat() = 0;
  virtual CATUnicodeString GetRole() = 0;
  virtual CATUnicodeString GetLateType() = 0;

  /*
    return the application format
  */
  virtual CATUnicodeString GetAppliFormat() = 0;

  virtual CATBoolean IsForUpdater() = 0;
  virtual CATBoolean IsForConverter() = 0;
};


/**
 * This class aims at
 * - computing the sream format to use to stream a document
 * - instantiante the converter to be used
 * - call the converter to unstream/stream the document
 */
class ExportedByCATOmbConverter CATOmbXConverterManager : public CATOmbConverterManager
{
public:
  CATOmbXConverterManager();
  ~CATOmbXConverterManager();

  /**
  * This method allows streaming a V5 document to a non V5 legacy stream.
  *
  * <br><b>Role</b>:
  * This method retrieves the converter to stream a document and call it on its stream method.
  * @param iDoc [in]
  *   The document to be streamed.
  * @param iUrlConnection [in]
  *   The URLConnection that give access to the ILB where the document will be streamed.
  * @param iSDFormat [in]
  *   Format of the Stream Descriptor such as Authoring...
  * @param iSDRole [in]
  *   Role of the Stream Descriptor
  * @param iLateType [in]
  *   LateType of the CATDocument to be streamed.
  * @param iStreamFormat [in]
  *   The stream format in which the document will be streamed.
  * @param oError [out]
  *   In case of error, an end-user error that can be displayed in an error panel.
  * @param iParamList [in]
  *	A list of parameters useful for streams conversion
  * @param ioIncidentCollector [inout]
  *   Incident Collector logging errors raised during stream conversion
  *
  * @return
  *   <code>S_OK</code> document has been streamed correctly.
  *
  *   IMPORTANT: in following error cases, always check ioIncidentCollector content after execution and empty it after eventual error message display,
  *   using  @href CATIOmyIncidentCollector::EmptyCollector() in order to avoid later ghost messages:
  *
  *   <code>CATOmb_S_NOCONVERSION</code> an error occurs but converter manage to generate a default archive. ioIncidentCollector contains more information.
  *   <code>E_FAIL</code> an error occurs. ioIncidentCollector contains more information.
  */
  virtual HRESULT StreamDocumentToExternalFormat(CATDocument& iDoc, CATVVSURLConnection& iUrlConnection, const CATUnicodeString& iSDFormat, const CATUnicodeString& iSDRole, const CATUnicodeString& iLateType, const CATUnicodeString& iStreamFormat, CATOmxKeyValueBlock& iParamList, CATIOmyIncidentCollector_var& ioIncidentCollector);

  /**
  * This method allows unstreaming a non legacy V5 stream as a V5 CATDocument.
  *
  * <br><b>Role</b>:
  * This method allows unstreaming a non legacy V5 stream as a V5 CATDocument.
  * CATDocument generated should have the same behavior than a document generated by CATInit::Init and CATIPersistent::Load
  * in CATIA3D, on cluster document, URLConnection is on the vault while in 3dlive, URLConnection points to the SelectiveLoading Cache.
  *
  * @param iDocId [in]
  *   The Identifier of the Document to be unstreamed.
  * @param iComId [in]
  *   The identifier of the PLM Component this document and its Stream Descriptor are attached to.
  * @param iUrlConnection [in]
  *   The URLConnection giving access to the ILB of the document to be unstreamed.
  * @param ioStreamDescriptor [in]
  *   The Stream Descriptor associated to the document to be unstreamed.
  * @param iStreamFormat [in]
  *   The stream format in which the document will be unstreamed.
  * @param iParamList [in]
  *	  A list of parameters useful for streams conversion.
  * @param opDoc [out]
  *   The document unstreamed and loaded in session.
  * @param ioIncidentCollector [inout]
  *   Incident Collector logging errors raised during stream conversion.
  *
  * @return
  *   <code>S_OK</code> document has been streamed correctly.
  *
  *   IMPORTANT: in following error cases, always check ioIncidentCollector content after execution and empty it after eventual error message display,
  *   using  @href CATIOmyIncidentCollector::EmptyCollector() in order to avoid later ghost messages:
  *
  *   <code>CATOmb_S_NOCONVERSION</code> an error occurs but converter manages to create a default document. ioIncidentCollector contains more information.
  *   <code>E_FAIL</code> an error occurs. ioIncidentCollector contains more information.
  */
  virtual HRESULT UnstreamDocumentFromExternalFormat(CATIDocId& iDocId, const CATComponentId& iComId, CATVVSURLConnection& iUrlConnection, CATIOmbStreamDescriptor& ioStreamDescriptor, const CATUnicodeString& iStreamFormat, CATOmxKeyValueBlock& iParamList, CATDocument*& opDoc, CATIOmyIncidentCollector_var& ioIncidentCollector);

  /**
   * This method allows unstreaming a non legacy V5 stream as a V5 CATDocument.
   *
   * <br><b>Role</b>:
   * This method allows unstreaming a non legacy V5 stream as a V5 CATDocument.
   * CATDocument generated should have the same behavior than a document generated by CATInit::Init and CATIPersistent::Load
   * in CATIA3D, on cluster document, URLConnection is on the vault while in 3dlive, URLConnection points to the SelectiveLoading Cache.
   *
   * @param iDocId [in]
   *   The Identifier of the Document to be unstreamed.
   * @param iComId [in]
   *   The identifier of the PLM Component this document and its Stream Descriptor are attached to.
   * @param iUrlConnection [in]
   *   The URLConnection giving access to the ILB of the document to be unstreamed.
   * @param iLateType [in]
   *   LateType of the CATDocument to be unstreamed.
   * @param iFormat [in]
   *   Format of the Stream Descriptor for the document to be unstreamed.
   * @param iRole [in]
   *   Role of the  Stream Descriptor for the document to be unstreamed.
   * @param iStreamFormat [in]
   *   The stream format in which the document will be unstreamed.
   * @param iParamList [in]
   *	  A list of parameters useful for streams conversion.
   * @param opDoc [out]
   *   The document unstreamed and loaded in session.
   * @param ioIncidentCollector [inout]
   *   Incident Collector logging errors raised during stream conversion.
   *
   * @return
   *   <code>S_OK</code> document has been streamed correctly.
   *
   *   IMPORTANT: in following error cases, always check ioIncidentCollector content after execution and empty it after eventual error message display,
   *   using  @href CATIOmyIncidentCollector::EmptyCollector() in order to avoid later ghost messages:
   *
   *   <code>CATOmb_S_NOCONVERSION</code> an error occurs but converter manages to create a default document. ioIncidentCollector contains more information.
   *   <code>E_FAIL</code> an error occurs. ioIncidentCollector contains more information.
   */
  virtual HRESULT UnstreamDocumentFromExternalFormat(CATIDocId& iDocId, const CATComponentId& iComId, CATVVSURLConnection& iUrlConnection, const CATUnicodeString& iFormat, const CATUnicodeString& iRole, const CATUnicodeString& iStreamFormat, CATOmxKeyValueBlock& iParamList, CATDocument*& opDoc, CATIOmyIncidentCollector_var& ioIncidentCollector);

  /**
  * this method returns the list of CATOmbXConverterInfo associated to iSDProperties
  * @param CATBoolean iCheckCode [in]
  *   Check that the Converter implement CATIOmbConverter2
  * @param CATOmbStreamDescriptorProperties iSDProperties [in]
  *   describe a SD : Format/Role/LateType
  * @param CATOmxVector<CATOmbXConverterInfo>& oList [out]
  *   List of CATOmbXConverterInfo
  * @return
  *   <code>S_OK</code> oList not empty.
  *   <code>E_FAIL</code> oList is empty.
  * XConverterInfo contient les infos {CATOmbStreamDescriptorProperties(Session),Format,ExtensionParDefault,Capability,statut du converter}
  */
  HRESULT ListAvailableFormats(CATBoolean iCheckCode, CATOmbStreamDescriptorProperties iSDProperties, CATOmxVector<CATOmbXConverterInfo>& oList);

  /**
  * this method returns the list of CATOmbXConverterInfo associated to an application format
  * @param CATBoolean iCheckCode [in]
  *   Check that the Converter implement CATIOmbConverter2
  * @param CATUnicodeString iApplicationFormat [in]
  *   the application format we want to search for
  * @param CATOmxVector<CATOmbXConverterInfo>& oList [out]
  *   List of CATOmbXConverterInfo associated to previous application format
  * @return
  *   <code>S_OK</code> oList not empty.
  *   <code>E_FAIL</code> oList is empty.
  * XConverterInfo contains {CATOmbStreamDescriptorProperties(Session),Format,ExtensionParDefault, Capability, Converter status} information
  */
  HRESULT ListAvailableStreamDescriptors(CATBoolean iCheckCode, const CATUnicodeString& iApplicationFormat, CATOmxVector<CATOmbXConverterInfo>& oList);

private:
  friend class CATOmbXDefinitionParser;
  static HRESULT ManageCell(const CATUnicodeString& iCell, CATOmxSR<XConverterInfo>& ioInfos);
  static HRESULT ReadCurrentLine(const CATUnicodeString& iResourceFile, const CATUnicodeString& iString);

  static void FinishInit();
  static CATUnicodeString SetRuntimeConvKey(XConverterInfo& iInfos);
  static CATUnicodeString GetRuntimeConvKey(XConverterInfo& iInfos);

  // Copy Constructor and copy operator are forbidden. 
  CATOmbXConverterManager(CATOmbXConverterManager&);
  CATOmbXConverterManager& operator=(CATOmbXConverterManager&);
};

#endif
