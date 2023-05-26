/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2007
#ifndef CATAdpVersioningDatum_H
#define CATAdpVersioningDatum_H

/**
 * @level Protected
 * @usage U1  
 */

#include "CATPLMIntegrationAccess.h"
#include "CATErrorDef.h"
#include "CATTime.h"
class CATIAdpPLMIdentificator;

/**
 * Class defining a set of data mandatory to perform a versioning operation.
 *
 * <br><b>Role</b>: provide a set of data used to perform a versioning operation.
 */
class ExportedByCATPLMIntegrationAccess CATAdpVersioningDatum
{
public:

/** 
 * Build a versioning datum.
 *
 * <br><b>Role</b>: Enables to build a versioning datum which can be used to version a component through
 * the @href CATAdpProtectedVersioningServices#NewVersion API.
 *
 * @param iLastVersion [in]
 *   The last version of the versioning family of components which must be enriched with a new version. 
 * <ul>
 * <li> The identifier must not be nul. Otherwise, the versioning operation will fail.</li> 
 * </ul>
 * @param iAncestor [in]
 *   The identifier of the component which will be used as a content initialization of the new version of the component.
 * <ul>
 * <li> If nul identifier is provided, the content will be initialized from the last version.</li> 
 * <li> The ancestor must part of the versioning family. Otherwise, the versioning operation will fail.</li> 
 * </ul>
 * @param iAction [in]
 *   The action which must be applied on the new version. If no action is available, use nul as argument.
 * @param iApplicabilityDate [in]
 *   The applicability date for the new version availability.
 *
 */
  CATAdpVersioningDatum( CATIAdpPLMIdentificator * iLastVersion, CATIAdpPLMIdentificator * iAncestor,
                         CATIAdpPLMIdentificator * iAction, const CATTime & iApplicabilityDate );

  virtual ~CATAdpVersioningDatum( void );

/** 
 * Gets the last version identifier.
 *
 * <br><b>Role</b>: Gets the @href CATIAdpPLMIdentificator enabling to identify the last version of the component.
 *
 * @param oLastVersion [out]
 *   The last version identifier.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the related identifier could be retrieved.</li>
 *   <li><code>E_FAIL</code> otherwise.</li>
 *   </ul>
 *
 */
  HRESULT GetLastVersion( CATIAdpPLMIdentificator *& oLastVersion ) const;

/** 
 * Gets the ancestor identifier.
 *
 * <br><b>Role</b>: Gets the @href CATIAdpPLMIdentificator enabling to identify the ancestor used for the versioning operation.
 *
 * @param oAncestor [out]
 *   The ancestor identifier.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the related identifier could be retrieved.</li>
 *   <li><code>E_FAIL</code> otherwise.</li>
 *   </ul>
 *
 */
  HRESULT GetAncestor( CATIAdpPLMIdentificator *& oAncestor ) const;

/** 
 * Gets the action identifier.
 *
 * <br><b>Role</b>: Gets the @href CATIAdpPLMIdentificator enabling to identify the action which will be to the new version of the component.
 *
 * @param oAction [out]
 *   The action identifier.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the related identifier could be retrieved.</li>
 *   <li><code>E_FAIL</code> otherwise.</li>
 *   </ul>
 *
 */
  HRESULT GetAction( CATIAdpPLMIdentificator *& oAction ) const;

/** 
 * Gets the applicability date defining the new version applicability deadline.
 *
 * <br><b>Role</b>: Gets the @href CATTime defining the new version applicability deadline.
 *
 * @param oApplicabilityDate [out]
 *   The applicability date of the new version of the component.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the date could be retrieved.</li>
 *   <li><code>E_FAIL</code> otherwise.</li>
 *   </ul>
 *
 */
  HRESULT GetApplicabilityDate( CATTime & oApplicabilityDate ) const;

private:
  CATIAdpPLMIdentificator * _LastVersion;
  CATIAdpPLMIdentificator * _Ancestor;
  CATIAdpPLMIdentificator * _Action;
  CATTime _ApplicabilityDate;
};



// CATLISTV(CATAdpVersioningDatum) definition

// Clean previous functions requests
#include "CATLISTV_Clean.h"

// Required functions
/** @nodoc INTERNAL */
#define CATLISTV_Append
#define CATLISTV_Size
#define CATLISTV_RemoveAll

// Get macros
// Generate interface of collection-class
#include "CATLISTV_Declare.h"
CATLISTV_DECLARE(CATAdpVersioningDatum)

// Typedef declaration for users easy identification.
typedef CATLISTV(CATAdpVersioningDatum) CATAdpVersioningData;

#endif
