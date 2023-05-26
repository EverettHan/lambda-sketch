// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATIPLMQueryFilterAdditionalParams.h
// Define the CATIPLMQueryFilterAdditionalParams interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Apr 2007  Creation: Code generated by the CAA wizard  NLZ
//===================================================================

/**
* @level Private
* @usage U3
*/

#ifndef CATIPLMQueryFilterAdditionalParams_H
#define CATIPLMQueryFilterAdditionalParams_H

#include "CATPLMServicesLimitedAccess.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesLimitedAccess IID IID_CATIPLMQueryFilterAdditionalParams;
#else
extern "C" const IID IID_CATIPLMQueryFilterAdditionalParams ;
#endif

class CATUnicodeString;

//------------------------------------------------------------------

/**
* @nodoc
*/
class ExportedByCATPLMServicesLimitedAccess CATIPLMQueryFilterAdditionalParams: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /**
  * Setting an option for the query filter
  * 
  * note:
  * Suppose you perform a NAVIGATE (or and EXPAND with filter on relation)
  * Suppose you use following parameter: CATIPLMQueryFilterAdditionalParams::SetParameter("SR_Optimisation", "SRUsedDuringNavigation") <=> Only SR crossed while navigating are returned by server
  * Then use of CATIPLMQueryFilter::AddFilterSelectCriteria(<your type with SR>, PLMQY_RELATIONS, PLMQY_ALL) is meaningless and so is useless and has no effect
  *
  * @param iKey
  *   Name of the option.
  * @param iKey
  *   Value of the option.
  * @return
  *   S_OK 
  *   E_INVALIDARG unknown option.
  */
  virtual HRESULT SetParameter( const CATUnicodeString iKey, const CATUnicodeString iValue ) = 0 ;
/**
* @nodoc
*/
  virtual HRESULT GetParameter( const CATUnicodeString iKey, CATUnicodeString &oValue) = 0 ;
/**
* @nodoc
*/
  virtual HRESULT ClearParameters() = 0 ;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------

#endif