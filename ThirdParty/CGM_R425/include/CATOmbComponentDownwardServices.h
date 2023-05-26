/* -*-c++-*- */
/**
* @level Protected
* @usage U1
*/
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2011
//-----------------------------------------------------------------------------
//
// class CATOmbComponentDownwardServices :
// 
// Perform V5 Downgrade of the Authoring Data owned by a V6 component
//
//-----------------------------------------------------------------------------
// 30/03/2011 Creation                                                      VCS
//-----------------------------------------------------------------------------

#ifndef CATOmbComponentDownwardServices_H
#define CATOmbComponentDownwardServices_H

// System
#include "CATSysErrorDef.h" 

// ObjectModerBase
#include "CATOmbDWC.h"
#include "CATIOmyIncidentCollector.h"

// CATPLMIdentification
#include "CATComponentId.h"
#include "CATOmxVector.h"
#include "CATOmxSharable.h"
#include "CATOmxKeyString.h"
#include "CATIOmbDownwardData.h"
#include "CATIOmbCheckDownward.h"
#include "CATOmxKeyValueBlock.h"

class CATBaseUnknown;
class CATDocument;
class PLMIOmbVirtualObjectDescriptor_var;
class CATOmxKeyValueBlock;
class CATILinkableObject_var;

/**
* Services to perform V5 Downgrade of Authoring DS Data owned by a V6 component
* <br><b>Role:</b> Downgrades the <b>specification</b> data owned by a given V6 component
* <br> to their V5 matching data.
* <br>
* <br> This downgrade operation doesn't work on the input original data opened into the current session
* <br> but on their duplicated ones, to be usable on the targeted V5 level.
* <br> The container structure of the output data is not modified.
*/

namespace DowngradeTo
{
  /**
   * The document type the input Authoring Part data is to be downgraded into.
   * @param DwcPart
   *   Authoring data to be downgraded into a V5 CATPart.
   * @param DwcShape
   *   Authoring data to be downgraded into a V5 CATShape.
   */
  enum DocType { CATPart, CATShape, fea };
}



class ExportedByCATOmbDWC CATOmbComponentDownwardServices
{
public:

  /**
  * Downgrades V6 Authoring data to V5 document
  * <br><b>Role:</b> Downgrades the <b>authoring</b> Part data owned by a given V6 component
  * <br> to the V5 matching CATDocument.
  * @param ipBURepRef [in]
  *     the RepresentationReference the authoring data to be migrated belong to
  * @param DowngradeType [in]
  *     The late type the V5 CATDocument is to be created with.
  *     Not yet implemented: the output CATDocument is always a CATPart
  * @param opV5Document [out]
  *     The standalone V5 Document created from the input RepRef authoring data
  *     To be then fully editable in V5, the output CATDocument must include some additional Product Structure formating
  *     This operation is to be performed by the Downward Compatibility engine.
  * @param iopIncidentCollector [inout]
  *     A standard PLM Error collector getting all errors or warnings raised by the method
  *     The collector content is always to be read and displayed as warning may be raised even when method succeeds.
  * @return
  *	 if SUCCEEDED the caller can continue processing, otherwise it must redirect to its own failure management:
  * <br>  : E_INVALIDARG : input RepRef is NULL
  * <br>  : E_UNEXPECTED : an inconsistency occured : display output report
  * <br>  : CATOmb_E_NOT_CONSISTENT_MODE : The current load mode of the Authoring SD is not consistent.
  * <br>  : All other specific FAILED error codes
  */
  static HRESULT GetV5AuthoringDocumentFromRepresentation(CATBaseUnknown * ipBURepRef, DowngradeTo::DocType DowngradeType, CATDocument*& opV5Document, CATIOmyIncidentCollector_var& iopIncidentCollector);

  /**
  * Reports all eventual Catalog compliance errors for Authoring data to be downgraded from V6 To V5
  * <br><b>Role:</b> Reports all eventual V6 to V5 compliance Errors on catalogs pointed by Authoring data
  * <br> to be downgraded from V6 To V5.
  * @param ipBURepRef [in]
  *     the RepresentationReference the authoring data to be migrated belong to
  * @param iopIncidentCollector [inout]
  *     A standard PLM Error collector getting all errors or warnings raised by catalogs analysis
  * @return
  * <br>  : S_OK : report corectly generated: display output report
  * <br>  : E_INVALIDARG : input RepRef is NULL
  * <br>  : All specific FAILED error codes
  */
  static HRESULT GetV6ToV5CatalogsComplianceReport(CATBaseUnknown * ipBURepRef, CATOmxVector<CATBaseUnknown>& oFeatureErrorList);

  /**
  * For publication CATDWC As Spec purpose.
  * @param iVODesc [in]
  *     The virtual object descriptor with the target to find in V5 document.
  * @param iV5Doc [in]
  *     The V5 document.
  * @param iIdentificationSpec [in]
  *     The identification specifications to use in order to find the object in the V5 document.
  * @param oCorrespondingV5Object [out]
  *     The result.
  * @return
  * <br>  : S_OK : if everything ran OK.
  * <br>  : Otherwise, associated error code.
  */
  static HRESULT GetCorrespondingV5Object(PLMIOmbVirtualObjectDescriptor_var & iVODesc, CATDocument & iV5Doc,
    CATOmxKeyValueBlock & iIdentificationSpec, CATILinkableObject_var & oCorrespondingV5Object);


  /**
  * Creates a new CATDocument for a CATBack as result export
  * @param iType [in]
  *     the document latetype
  * @param oNewDoc [out]
  *     a pointer to the CATDocument created
  * @return
  * <br>  : S_OK : if everything ran OK.
  * <br>  : Otherwise, associated error code.
  */
  static HRESULT NewCATBackDocumentAsResult(const CATUnicodeString& iType, CATDocument*& oNewDoc);

  /**
  * To check if the document is marked as V6ToV5 dowgraded
  * @param iDoc [in]
  *   the document to check
  * @param oVal [out]
  *   The value associated to the flag if set ("NoCheck" or CatalogCheck")
  * @param oV5Version [out]
  *   The version on which the document will be/is catbacked (cf VersionManagement), if downgraded, else empty
  * @param oCATBackMode [out]
  *   the CATBack Mode, can take values "asSpec" or "asResult" or empty if not downgraded
  * @return
  *   S_OK : all is OK
  *   S_FALSE : failed to get value
  *   E_XXX : an error occurred
  */
  static HRESULT IsDocumentMarkedAsV6ToV5Downgraded(CATDocument& iDoc, CATBoolean& isDowngraded, CATUnicodeString& oVal, CATUnicodeString& oV5Version, CATUnicodeString& oCATBackMode);

  /**
  * To check if the document is marked as V6ToV6 dowgraded
  * @param iDoc [in]
  *   the document to check
  * @param oDowngradeLevel [out]
  *   The downgrad level if downgraded
  * @param oOriginLevel[out]
  *   The origin level if downagraded
  * @return
  *   S_OK : all is OK
  *   S_FALSE : failed to get value
  *   E_XXX : an error occurred
  */
  static CATBoolean IsDocumentMarkedAsV6ToV6Downgraded(const CATDocument& iDoc, CATUnicodeString& oDowngradeLevel, CATUnicodeString& oOriginLevel);

  // Unmarshall iString with format : CATIAV(N)R(P)
  // where (N) represents the version, and (P) the release
  static HRESULT GetVersionReleaseFromString(const CATUnicodeString& iString, int& oVersion, int& oRelease);
  //inverse method
  static CATUnicodeString VersionReleaseToString(int version, int release);

private:

  static HRESULT ProcessV6ToV5Downward(CATBaseUnknown * ipBURepRef, DowngradeTo::DocType DowngradeType, CATDocument* & opV5Document, CATIOmyIncidentCollector_var& iopIncidentCollector);

};

class ExportedByCATOmbDWC CATEOmbDownwardData : public CATIOmbDownwardData
{

public:
  /**
  * Process a document at end of CATBack operation
  */
  virtual HRESULT ProcessDocument(CATDocument& iDocument) { return E_NOTIMPL; };
};

class ExportedByCATOmbDWC CATEOmbCheckDownward : public CATIOmbCheckDownward
{

public:
  /**
  * Check if content of a container is compliant with DonwwardAsSpec operation
  */
  virtual CATBoolean ContentCompliantForDownwardAsSpec(CATOmxKeyValueBlock& iParamList) { return TRUE; };
};

#endif
