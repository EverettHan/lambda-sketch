// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIPsiPLMPropertiesForApplication.h
// Define the CATIPsiPLMPropertiesForApplication interface
//
//===================================================================
//
//  Dec 2006  Creation: JIT
//===================================================================
#ifndef CATIPsiPLMPropertiesForApplication_H
#define CATIPsiPLMPropertiesForApplication_H

/**
* @level Protected
* @usage U3
*/
#include "PLMPSISessionInterfaces.h"
#include "CATBaseUnknown.h"
//declaration
class CATIValue;

extern ExportedByPLMPSISessionInterfaces IID IID_CATIPsiPLMPropertiesForApplication;
//------------------------------------------------------------------

/**
 * Interface managing applicative attributes of a PLM entity.
 * <br><b>Role</b>: This interface enables to read or valuate applicative attributes information on a PLM entity.
 * <br> This interface is dedicated to DS applications.
 */

class ExportedByPLMPSISessionInterfaces CATIPsiPLMPropertiesForApplication: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
     * Deprecated.
     */
    virtual HRESULT SetNatureValue(CATIValue* ipiValue) = 0;

    /**
     * Deprecated.
     */
    virtual HRESULT SetDisciplineValue(CATIValue* ipiValue) = 0;

    /**
     * Deprecated.
     */
    virtual HRESULT SetUsageValue(CATIValue* ipiValue) = 0;

    /**
		 * Deprecated
     */
    virtual HRESULT SetApplicativeParameters(CATIValue* ipiDisciplineValue, CATIValue* ipiUsageValue, CATIValue* ipiNatureValue) = 0;
};

CATDeclareHandler(CATIPsiPLMPropertiesForApplication,CATBaseUnknown);

#endif

//------------------------------------------------------------------
