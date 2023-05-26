// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATIPLMFilterVolumeProximity.h
// Define the CATIPLMFilterVolumeProximity interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Sep 2008  Creation: Code generated by the CAA wizard  DST
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMFilterVolumeProximity_H
#define CATIPLMFilterVolumeProximity_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include  "CATLISTV_Declare.h" 

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMFilterVolumeProximity;
#else
extern "C" const IID IID_CATIPLMFilterVolumeProximity ;
#endif

class CATLISTV(CATPLMID);

//------------------------------------------------------------------

/**
* Interface representing CATIPLMFilterVolumeProximity.
*
*/
class ExportedByCATPLMServicesItf CATIPLMFilterVolumeProximity: public CATBaseUnknown
{
    CATDeclareInterface;

public:

    /**
    * Set the list of PLMID to consider for the Proximity .
    * @param iIds
    *     The list of PLMID for the Part
    */
    virtual HRESULT SetReferenceId( CATLISTV(CATPLMID) & iIds)=0;

    /**
    * Set the Clearance.
    * @param iClearance [in]
    *     The Clearance of the Proximity
    */
    virtual HRESULT SetClearance( double iClearance)=0;

    /**
    * Get the list of PLMID to consider for the Proximity .
    * @param iIds
    *     The list of PLMID for the Part
    */
    virtual HRESULT GetReferenceId( CATLISTV(CATPLMID) &opIds)=0;

    /**
    * Get the Clearance.
    * @param oClearance [in]
    *     The Clearance of the Proximity
    */
    virtual HRESULT GetClearance( double& oClearance)=0;

};

//------------------------------------------------------------------

#endif