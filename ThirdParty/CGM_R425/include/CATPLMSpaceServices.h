// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATPLMSpaceServices.h
// Define the CATPLMSpaceServices interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Nov 2005  Creation: Code generated by the CAA wizard  PBV
//===================================================================
/**
* @level Protected
* @usage U1
*/
#ifndef CATPLMSpaceServices_H
#define CATPLMSpaceServices_H

#include "CATPLMIdentificationAccess.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATIPLMSpace.h"
#include "CATOmxOMap.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATPLMID_Any.h"

class CATPLMID;
class CATUnicodeString;

template<> CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMID>::manager();

class ExportedByCATPLMIdentificationAccess CATPLMSpaceServices
{
public:

  static const CATUnicodeString Cat3DSpace;

  /**
  * Same as GetResolutionSpace with default arguments
  **/
  static CATOmxSR<CATIPLMSpace> GetAuthoringSpace();

  /**
  * Retrieve a resolution space according to space type and name.
  *
  * @param oSpace [out, CATBaseUnknown#Release]
  *   The space.
  * @param iSpaceType [int]
  *   The space type.
  * @param iSpaceInstanceName [int]
  *   The space name.
  * @return
  *    S_OK    : successful
  *    S_FALSE : space not found
  *    E_FAIL  : failure
  */
  static HRESULT GetResolutionSpace(CATIPLMSpace *& oSpace, CATIPLMSpace::CatType iSpaceType = CATIPLMSpace::CatAuthoring, const CATUnicodeString& iSpaceInstanceName = Cat3DSpace);

  /**
  * Get identifier for the object whose opening is requested by 3DExperience
  *
  * @param oObject [out]
  *   The object identifier.
  * @return
  *    S_FALSE : no 3DExperience request to proceed
  *    S_OK    : success, oObject out parameter is set, the request is considered proceeded
  *                (ie. futher calls to GetObjectWhoseOpeningIsRequestedBy3DExperience will answer relatively to another 3DExperience request,
  *                 or S_FALSE if none)
  *    E_FAIL  : unable to proceed 3DExperience request
  */
  static HRESULT GetObjectWhoseOpeningIsRequestedBy3DExperience(CATPLMID & oObject);

  /**Deprecated starting from R417, use CATAdpQueryPLMIDByPhysicalId*/
  static HRESULT GetPLMIDs(CATOmxOMap <CATUnicodeString, CATPLMID> & oPLMIDs);

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------

private:

  friend class CATOxiRestrictedTOS;
  friend class CATAdpProtectedIterationOpenerImpl;

  static HRESULT GetRestrictedSpace(CATIPLMSpace *& opSpace);

private:

  friend class CATOxiSpaceLifeCycleAnalysis;
  friend class CATSetupDataBRFamily_fillBRidsImpl;

  /**
  * DeleteEmptySpace
  * <br><b>Role</b>: Delete the given empty space
  * @param ipSpace
  *   The space
  * @return
  *   S_OK : succeeded
  *   E_INVALIDARG : the space is not empty
  *   E_FAIL : error occurred
  */
  static HRESULT DeleteEmptySpace(CATIPLMSpace * ipSpace);

};

//------------------------------------------------------------------

#endif
