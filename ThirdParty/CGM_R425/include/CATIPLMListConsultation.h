// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATIPLMListConsultation.h
// Define the CATIPLMListConsultation interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Sep 2004  Creation: Code generated by the CAA wizard  son
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMListConsultation_H
#define CATIPLMListConsultation_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"

class CATComponentId;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMListConsultation;
#else
extern "C" const IID IID_CATIPLMListConsultation ;
#endif

//------------------------------------------------------------------

/**
 * This makes possible to give a light access to a list, by allowing consultation only if wanted. It also avoid the list copy. 
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMListConsultation: public CATBaseUnknown
{
  CATDeclareInterface;

  public:


  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------



/**
* This methods allows to consult list elements
* @param  oComp : The next element of the list being consulted
* returns S_FALSE if there is no next element (the list is empty or we are at the end of the list)
* returns E_FAIL if the list is not accessible or has changed 
*/
virtual HRESULT Next(CATComponentId &  oComp)  =0 ;


/**
* This methods allows to position the iterator to the beginning of the list to consult
* returns E_FAIL if the list is not accessible or has changed 
*/
virtual HRESULT Rewind() =0;


/**
* This methods allows to consult list elements
* @param  oNelts : The number of elements 
* returns E_FAIL if the list is not accessible or has changed 
*/
virtual HRESULT Cardinal(int &  oNelts)  =0 ;




};

//------------------------------------------------------------------

#endif
