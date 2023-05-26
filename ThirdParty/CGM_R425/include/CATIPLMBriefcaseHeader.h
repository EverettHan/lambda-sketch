// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIPLMBriefcaseHeader.h
// Define the CATIPLMBriefcaseHeader interface
//
//===================================================================
#ifndef CATIPLMBriefcaseHeader_H
#define CATIPLMBriefcaseHeader_H

/**
* @level Protected
* @usage U3
*/

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"

class CATUnicodeString;
class CATTime;
class CATString;
class CATPLMREBusinessCard;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMBriefcaseHeader;
#else
extern "C" const IID IID_CATIPLMBriefcaseHeader ;
#endif

#include "CATCollec.h"


//------------------------------------------------------------------

/**
* Briefcase header interface.
* <br><b>Role</b>: Interface for accessing/editing the public information contained in the header section of a briefcase.<br>
* The briefcase header interface can be obtained through CATIPLMBriefcaseServices services.
*/

class ExportedByCATPLMIntegrationInterfaces CATIPLMBriefcaseHeader: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Returns the briefcase format version tag ("A.B.C" format for recent briefcases).
  * @param oVersion
  *   A string tag representing the format of the briefcase. Recent briefcases use an "A.B.C" format tag.
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK if the version tag was succesfully returned</dt>
      <dt>E_FAIL if the information not available in the header section or an unexpected error happened</dt>  
  * <br>
  */
  virtual HRESULT GetBriefcaseVersionTag( CATUnicodeString &oVersion ) = 0;

  /**
  * Sets the briefcase description.
  * @param iDescription
  *   The briefcase description.
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK if the description was succesfully set</dt>
      <dt>E_FAIL if the briefcase header is read-only or if an unexpected error happened</dt>  
  * <br>
  */
  virtual HRESULT SetDescription( const CATUnicodeString &iDescription  ) = 0;

  /**
  * Gets the briefcase description.
  * @param oDescription
  *   The briefcase description.
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK if the description was succesfully read</dt>
      <dt>E_FAIL if the information not available in the header section or an unexpected error happened</dt>  
  * <br>
  */  
  virtual HRESULT GetDescription( CATUnicodeString &oDescription  ) = 0;

  /**
  * Retrieves the name of the site where the briefcase was extracted.
  * @param oExtractSite
  *   The name of the site.
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK if the description was succesfully read</dt>
      <dt>E_FAIL if the information not available in the header section or an unexpected error happened</dt>  
  * <br>
  */  
  virtual HRESULT GetExtractSite( CATUnicodeString &oExtractSite ) = 0;
  
  /**
  * Retrieves the date of the briefcase extract.
  * @param oExtractDate
  *   The extract date.
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK if the description was succesfully read</dt>
      <dt>E_FAIL if the information not available in the header section or an unexpected error happened</dt>  
  * <br>
  */  
  virtual HRESULT GetExtractDate( CATTime &oExtractDate ) = 0;
  
  /**
  * Retrieves the number of entities included in the briefcase.
  * @param oNbEntities
  *   The number of PLM entities.
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK if the description was succesfully read</dt>
      <dt>E_FAIL if the information not available in the header section or an unexpected error happened</dt>  
  * <br>
  */  
  virtual HRESULT GetNumberOfEntities( int &oNbEntities ) = 0;

  /**
  * Sets the value of a custom attribute.
  * @param iKey
  *   The key of the custom attribute.
  * @param oValue
  *   The value of the custom attribute.
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK if the custom attribute was succesfully defined or updated</dt>
      <dt>E_FAIL if an unexpected error happened</dt>  
  * <br>
  */  
  virtual HRESULT SetCustomAttributeValue( const CATUnicodeString &iKey, const CATUnicodeString &iValue ) = 0;

  /**
  * Retrieves the value of a custom attribute.
  * @param iKey
  *   The key of the custom attribute.
  * @param oValue
  *   The retrieved value of the custom attribute.
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK if the value was succesfully read</dt>
      <dt>E_INVALIDARG if no custom attribute with the provided key was defined</dt>  
      <dt>E_FAIL if an unexpected error happened</dt>  
  * <br>
  */  
  virtual HRESULT GetCustomAttributeValue( const CATUnicodeString &iKey, CATUnicodeString &oValue ) = 0;

  /**
  * Lists all custom attribute keys.
  * @param oKeys
  *   A list where the custom attribute keys are appended.
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK if the keys were succesfully retrieved</dt>
      <dt>E_FAIL if an unexpected error happened.</dt>  
  * <br>
  */  
  virtual HRESULT ListCustomAttributeKeys( CATLISTV(CATUnicodeString) &oKeys ) = 0;

  /**
  * Adds an attachment file in the header.
  * @param iFilename
  *   The filename of the attachment. This filename should be unique in the header. 
  * @param iDescription
  *   A description of the attachment
  * @param iFilePath
  *   The path of the file to be included as an attachement. 
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK if the attachment was successfully added</dt>
  *   <dt>E_INVALIDARG if the filename was already used</dt>
  *   <dt>E_FAIL if an unexpected error happened.</dt>  
  * <br>
  */  
  virtual HRESULT AddAttachment( const CATUnicodeString &iFilename, const CATUnicodeString &iDescription, const CATUnicodeString &iFilePath ) = 0;

  /**
  * Lists all attachment files.
  * @param oFilenames
  *   A list where all attachment filenames will be appended. 
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK if the attachement filenames were succesfully returned</dt>
  *   <dt>E_FAIL if an unexpected error happened.</dt>  
  * <br>
  */  
  virtual HRESULT ListAttachments( CATLISTV(CATUnicodeString) &oFilenames ) = 0;

  /**
  * Retrieves the description of an attachment files.
  * @param iFilename
  *   The filename of the attachment. This filename should be unique in the header. 
  * @param oDescription
  *   The corresponding description
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK if the description was succesfully returned</dt>
  *   <dt>E_INVALIDARG if the filename does not exist in this header</dt>
  *   <dt>E_FAIL if an unexpected error happened.</dt>  
  * <br>
  */  
  virtual HRESULT GetAttachmentDescription( const CATUnicodeString &iFilename, CATUnicodeString &oDescription ) = 0;

  /**
  * Tests if the briefcase is a channel revision or not.
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK the briefcase is a channel revision</dt>
  *   <dt>S_FALSE the briefcase is not a channel revision</dt>
  *   <dt>E_FAIL if an unexpected error happened.</dt>  
  * <br>
  */  
  virtual HRESULT IsARevision() = 0;

  /**
  * Returns the channel identifier of a revision.
  * @param oChannelID
  *   The identifier of the channel the revision is associated with.
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK if the channel ID was succesfully returned</dt>
  *   <dt>E_FAIL if the briefcase is not a revision or an unexpected error happened.</dt>  
  * <br>
  */  
  virtual HRESULT GetChannelID( CATString &oChannelID ) = 0;

  /**
  * Returns the revision number.
  * @param oRevisionNumber
  *   The revision number of the revision. 
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK if the revision number was succesfully returned</dt>
  *   <dt>E_FAIL if the briefcase is not a revision or an unexpected error happened.</dt>  
  * <br>
  */  
  virtual HRESULT GetRevisionNumber( CATString &oRevisionNumber ) = 0;

  /**
  * Returns the source business-card.
  * @param opTargetBusinessCard
  *   The business-card of the source repository, if available.  
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK the source business card was succesfully retrieved/dt>
  *   <dt>S_FALSE no source business card available</dt>
  *   <dt>E_FAIL an unexpected error happened.</dt>  
  * <br>
  */  
  virtual HRESULT GetSourceBusinessCard( CATPLMREBusinessCard &oSourceBusinessCard ) = 0;

  /**
  * Returns the target business-card.
  * @param opTargetBusinessCard
  *   The business-card of the target repository, if available. 
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK the target business card was succesfully retrieved/dt>
  *   <dt>S_FALSE no target business card available</dt>
  *   <dt>E_FAIL an unexpected error happened.</dt>  
  * <br>
  */  
  virtual HRESULT GetTargetBusinessCard( CATPLMREBusinessCard &oTargetBusinessCard ) = 0;

  /**
  * Sets the downward compatibility parameters.
  * @param iCompatibilityLevels
  *   The list of compatibility release levels. 
  * @param iPivotFormat
  *   The format of pivot file. 
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK the downward compatibility parameters were successfully set/dt>
  *   <dt>E_FAIL an unexpected error happened.</dt>  
  * <br>
  */  
  virtual HRESULT SetDownwardCompatibilityParameters( const CATListOfCATUnicodeString & iCompatibilityLevels
                                                    , const CATUnicodeString          & iPivotFormat ) = 0 ;

  /**
  * Reads the downward compatibility parameters.
  * @param oCompatibilityLevels
  *   The list of compatibility release levels. 
  * @param oPivotFormat
  *   The format of pivot file. 
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK the downward compatibility parameters were successfully retrieved/dt>
  *   <dt>S_FALSE no downward compatibility parameters available</dt>
  *   <dt>E_FAIL an unexpected error happened.</dt>  
  * <br>
  */  
  virtual HRESULT GetDownwardCompatibilityParameters( CATListOfCATUnicodeString & oCompatibilityLevels
                                                    , CATUnicodeString          & oPivotFormat ) const = 0 ;

  /**
  * Returns the data dictionary level.
  * @param oDataDictionaryLevel
  *   The data dictionary level, if available. 
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK the data dictionary level was succesfully retrieved/dt>
  *   <dt>S_FALSE no data dictionary level available</dt>
  *   <dt>E_FAIL an unexpected error happened.</dt>  
  * <br>
  */  
  virtual HRESULT GetDataDictionaryLevel( CATUnicodeString & oDataDictionaryLevel ) const = 0 ;
  // FUN127642
  virtual HRESULT GetExportControlFlag(CATBoolean & obExportControl) const = 0;
  virtual HRESULT SetExportControlFlag(const CATBoolean   ibExportControl) = 0;

};
//------------------------------------------------------------------

CATDeclareHandler( CATIPLMBriefcaseHeader, CATBaseUnknown );

#endif
