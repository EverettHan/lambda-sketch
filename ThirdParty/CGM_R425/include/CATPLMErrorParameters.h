/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005



#ifndef  CATPLMErrorParameters_H
#define CATPLMErrorParameters_H

/**
 * @level Private 
 * @usage U1
 */

class CATUnicodeString;
#include "CATListOfCATUnicodeString.h"
#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"




/**
 * broken class, do not use
 */
class PLMErrParamStruct  
{  
public :
  /**
  * Number of nls parameters in the diagnostic field.
  */
  int nDiagParam ;  
  /**
  * Number of nls parameters in the request field.
  */
  int nReqParam ;  
  /**
  * Number of nls parameters in the advice field.
  */
  int nAdvParam ;  
  /**
  * Number of not nls parameters.  
  */
  int nRuntimeParam ;  

  /**
  * Comparison operator 
  *   @param iParamStruct
  *      The struct ot compare to.
  */
  int operator == ( const PLMErrParamStruct &iParamStruct ) const 
  {
    return (this->nDiagParam==iParamStruct.nDiagParam && 
      this->nReqParam==iParamStruct.nReqParam && 
      this->nAdvParam==iParamStruct.nAdvParam &&
      this->nRuntimeParam==iParamStruct.nRuntimeParam );
  }
};  




/**
 * Class to declare client PLM error parameters.
 * obsolete, use CATOmxErrorParams
 */
class ExportedByCATPLMIntegrationInterfaces CATPLMErrorParameters 
{
public : 
  CATPLMErrorParameters();
  virtual ~CATPLMErrorParameters();

  /**
  * = operator : Member to member affectation.
  *   @param other
  *      The parameter to value to.
  */
  CATPLMErrorParameters & operator = ( const CATPLMErrorParameters& other ) ;

  /**
  * Declare a nls parameter for the nls diagnostic field.
  * <br><b>Role</b>:  Use this method to declare a parameter for the nls diagnostic field. 
  *                   Be carefull :  you must call this method for each parameter in the diagnostic,
  *                                  in respecting the parameters order (call this method first to declare the \P1 parameter, secondly to declare the \P2 parameter and so on.)
  *   @param iDiagNLSParam
  *      The param to add to other already declared parameters.
  */
  HRESULT AddDiagnosticNLSParam (const CATUnicodeString & iDiagNLSParam);
  
  /**
  * Declare a nls parameter for the nls advice field.
  * <br><b>Role</b>:  Use this method to declare a parameter for the nls advice field. 
  *                   Be carefull :  you must call this method for each parameter in the advice,
  *                                  in respecting the parameters order (call this method first to declare the \P1 parameter, secondly to declare the \P2 parameter and so on.)
  *   @param iAdvNLSParam
  *      The param to add to other already declared parameters.
  */
  HRESULT AddAdviceNLSParam (const CATUnicodeString & iAdvNLSParam);
  
  /**
  * Declare a nls parameter for the nls request field.
  * <br><b>Role</b>:  Use this method to declare a parameter for the nls request field. 
  *                   Be carefull :  you must call this method for each parameter in the request,
  *                                  in respecting the parameters order (call this method first to declare the \P1 parameter, secondly to declare the \P2 parameter and so on.)
  *   @param iReqNLSParam
  *      The param to add to other already declared parameters.
  */
  HRESULT AddRequestNLSParam (const CATUnicodeString & iReqNLSParam);

  CATListOfCATUnicodeString _DiagnosticNLSParams;
  CATListOfCATUnicodeString _AdviceNLSParams;
  CATListOfCATUnicodeString _RequestNLSParams;

  HRESULT GetParamStruct(PLMErrParamStruct & ioParamStruct) const;

};


#endif
