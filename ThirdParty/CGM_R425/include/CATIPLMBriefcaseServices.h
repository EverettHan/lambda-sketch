/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2005
#ifndef CATIPLMBriefcaseServices_H
#define CATIPLMBriefcaseServices_H

/**
* @level Protected
* @usage U3
*/

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"

class CATIPLMBriefcaseHeader;
class CATUnicodeString;
class CATPLMREBusinessCard;
class CATPLMREBriefcaseReport;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMBriefcaseServices;
#else
extern "C" const IID IID_CATIPLMBriefcaseServices;
#endif

/**
* Briefcase services interface.
* <b>Role:</b>This interface exposes services for manipulation of briefcase headers and business cards.<br>
* It should be implemented by a session singleton.
*/
class ExportedByCATPLMIntegrationInterfaces CATIPLMBriefcaseServices: public CATBaseUnknown
{
  CATDeclareInterface;

public:


  /**
  * Creates a new briefcase header.
  * <br><b>Role</b>: Creates a new briefcase header object for use as an input of the CATIPLMReplicationEngine::ExportToBriefcase() method. 
  * 
  * @param ioBriefcaseHeader
  *    An add-refed pointer to the created briefcase header, if succesfull.
  * @return
  * <dt> <code>S_OK</code>     <dd> Success.
  * <dt> <code>E_FAIL</code>   <dd> Failure.
  */
  virtual HRESULT CreateBriefcaseHeader( CATIPLMBriefcaseHeader *&opBriefcaseHeader ) = 0;

  /**
  * Reads the header of an existing briefcase file.
  * <br><b>Role</b>: Loads the header section of a briefcase file and creates a CATIPLMBriefcaseHeader class for access to the header information. 
  * 
  * @param iBriefcaseFilePath
  *    Path of the briefcase file.
  * @param ioBriefcaseHeader
  *    An add-refed pointer to the created briefcase header, if succesfull.
  * @return
  * <dt> <code>S_OK</code>     <dd> Success.
  * <dt> <code>E_FAIL</code>   <dd> Failure.
  */
  virtual HRESULT ReadBriefcaseHeader( 
    const CATUnicodeString &iBriefcaseFilePath, 
    CATIPLMBriefcaseHeader *&opBriefcaseHeader ) = 0;

  /**
  * Packs an attachment inside an existing briefcase file.
  * <br><b>Role</b>: This service opens an existing briefcase and appends a new attachment file inside. 
  * Only briefcase files with an up-to-date format (briefcases generated with the same client code level) are supported.
  *
  * @param iBriefcaseFilePath
  *    Path of the briefcase file.
  * @param iFilename
  *    The filename of the attachement (can be obtained from the briefcase header)
  * @param iDescription
  *    The description of the file to be attached.
  * @param iFilePath
  *    The path of the file to be attached.
  * @return
  * <dt> <code>S_OK</code>           <dd> Success.
  * <dt> <code>E_INVALIDARG</code>   <dd> Invalid briefcase path, folder or filename.
  * <dt> <code>E_FAIL</code>         <dd> Failure / Non up-to-date format.
  */
  virtual HRESULT PackAttachment( 
	const CATUnicodeString &iBriefcaseFilePath, 
	const CATUnicodeString &iFilename, 
	const CATUnicodeString &iDescription, 
	const CATUnicodeString &iFilePath ) = 0;

  /**
  * Unpacks an attachment from a briefcase file.
  * <br><b>Role</b>: This service extracts to a folder an attachment file included in a briefcase file.
  *
  * @param iBriefcaseFilePath
  *    Path of the briefcase file.
  * @param iFilename
  *    The filename of the attachement (can be obtained from the briefcase header)
  * @param iFolder
  *    The folder where the attachment will be extracted.
  * @return
  * <dt> <code>S_OK</code>           <dd> Success.
  * <dt> <code>E_INVALIDARG</code>   <dd> Invalid briefcase path, folder or filename.
  * <dt> <code>E_FAIL</code>         <dd> Failure.
  */
  virtual HRESULT UnpackAttachment( 
    const CATUnicodeString &iBriefcaseFilePath, 
    const CATUnicodeString &iFilename, 
    const CATUnicodeString &iFolder ) = 0;

  /**
  * Unpacks all attachments inluded in a briefcase file.
  * <br><b>Role</b>: This service extracts to a folder all attachment files included in a briefcase file. 
  *
  * @param iBriefcaseFilePath
  *    Path of the briefcase file.
  * @param iFolder
  *    The folder where the attachments will be extracted.
  * @return
  * <dt> <code>S_OK</code>           <dd> Success.
  * <dt> <code>E_INVALIDARG</code>   <dd> Invalid briefcase path or folder.
  * <dt> <code>E_FAIL</code>         <dd> Failure.
  */
  virtual HRESULT UnpackAllAttachments( 
    const CATUnicodeString &iBriefcaseFilePath, 
    const CATUnicodeString &iFolder ) = 0;

  /**
  * Writes a business-card to an XML file.
  * <br><b>Role</b>: This service serializes a business-card to an XML file. 
  *
  * @param iBusinessCard
  *    The business-card to be serialzed.
  * @param iXMLFilePath
  *    The path of the XML file.
  * @return
  * <dt> <code>S_OK</code>           <dd> Success.
  * <dt> <code>E_INVALIDARG</code>   <dd> Invalid file path.
  * <dt> <code>E_FAIL</code>         <dd> Failure.
  */
  virtual HRESULT WriteBusinessCardToXML( 
    const CATPLMREBusinessCard &iBusinessCard, 
    const CATUnicodeString &iXMLFilePath ) = 0;

  /**
  * Reads a business-card from an XML file.
  * <br><b>Role</b>: This service deserializes a business card from an XML file. 
  *
  * @param iXMLFilePath
  *    The path of the XML file.
  * @param oBusinessCard
  *    The deserialized business-card. 
  * @return
  * <dt> <code>S_OK</code>           <dd> Success.
  * <dt> <code>E_INVALIDARG</code>   <dd> Invalid file path.
  * <dt> <code>E_FAIL</code>         <dd> Failure.
  */
  virtual HRESULT ReadBusinessCardFromXML( 
    const CATUnicodeString &iXMLFilePath, 
    CATPLMREBusinessCard &oBusinessCard) = 0;

  /**	
  *	Write Briefcase operation report to an XML file.
  * <br><b>Role</b>: This service serializes a briefcase report to an XML file.
  *
  * @param iBriefcaseReport
  *	The report to write.
  * @param iXMLFilePath
  * The path of the XML file.
  * @return
  * <dt> <code>S_OK</code>         <dd> Success.
  * <dt> <code>E_INVALIDARG</code> <dd> Invalid file path
  * <dt> <code>E_FAIL</code>       <dd> Failure.
  */

#define PVSMS_INFRAREPORT
#ifdef PVSMS_REPORT_ACTIVATED
  virtual HRESULT WriteReportToXML(
	  const CATPLMREBriefcaseReport& iBriefcaseReport,
	  const CATUnicodeString& iXMLFilePath) = 0;

  /**
  * Read briefcase operation report from an XML file.
  * <br><b>Role</b>: this services initializes a report from an XML file.
  *
  * @param iXMLFilePath
  * the path of the XML file.
  * @param  oBriefcaseReport
  * the deserialized report.
  * @return
  * <dt> <code>S_OK</code>         <dd> Success.
  * <dt> <code>E_INVALIDARG</code> <dd> Invalid file path
  * <dt> <code>E_FAIL</code>       <dd> Failure.
  */
  virtual HRESULT ReadReportFromXML(
	  const CATUnicodeString& iXMLFilePath,
	  CATPLMREBriefcaseReport& oBriefcaseReport)=0;
#endif

};
CATDeclareHandler( CATIPLMBriefcaseServices, CATBaseUnknown );

#endif
