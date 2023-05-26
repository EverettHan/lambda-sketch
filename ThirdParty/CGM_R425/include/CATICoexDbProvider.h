/** WARNING: YWE 15:05:15 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
//  COPYRIGHT  DASSAULT  SYSTEMES  2011  
#ifndef CATICoexDbProvider_H_
#define CATICoexDbProvider_H_

/** @level Private 
* @usage U3
*/
#include "ExportedByCATDbProvider.h"
#include "CATBaseUnknown.h"
#include "IUnknown.h"
//#include "CATBoolean.h"
#include "CATListOfCATUnicodeString.h"
class CATUnicodeString;
class CATICoexDbProvider_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATDbProvider IID IID_CATICoexDbProvider;
#else
extern "C" const IID IID_CATICoexDbProvider ;
#endif


//---------------------------------------------------------------------------  
class ExportedByCATDbProvider CATICoexDbProvider : public CATBaseUnknown
{  
  CATDeclareInterface;

 public: 

  /**
  *  Gets the internal  name  of  the coexistence database provider.
  *  @param  oProviderName [out]
  *  The  internal  name  of  the coexistence database provider. 
  * @return
  * <br> S_OK successful
  * <br> E_FAIL failed  
  */
	 virtual  HRESULT  GetCoexDbProviderName  ( CATUnicodeString &oProviderName  )  =  0  ; 


 /**
  *  Sets the internal  name  of  the coexistence database provider.
  *  @param  iProviderName [in]
  *  The  internal  name  of  the coexistence database provider. 
  * @return
  * <br> S_OK successful
  * <br> E_FAIL failed
  */
	 virtual  HRESULT  SetCoexDbProviderName(const CATUnicodeString &iProviderName) =  0  ; 


 /**
  *  Gets the coexistence database provider parameters.
  *  @param  oLstParam [out]
  *  The  list  of  parameters 
  *  @param  oLstValue [out]
  *  The  list  of  value  attached  to  each  parameter  
  * @return
  * <br> S_OK successful
  * <br> E_FAIL failed
  */
	 virtual  HRESULT  GetCoexDbProviderParameters(  CATListOfCATUnicodeString  &  oLstParam  ,  CATListOfCATUnicodeString  &  oLstValue  )  =  0  ;

 /**
  *  Sets the coexistence database provider parameters.
  *  @param  iLstParam [in]
  *  The  list  of  parameters 
  *  @param  iLstValue [in]
  *  The  list  of  value  attached  to  each  parameter  
  * @return
  * <br> S_OK successful
  * <br> E_FAIL failed
  */
	 virtual  HRESULT  SetCoexDbProviderParameters(  const CATListOfCATUnicodeString  &  iLstParam  , const CATListOfCATUnicodeString  &  iLstValue  )  =  0  ;
 


 /**
  * Check the validity of the coexistence database provider.
  *  @param  oIsValid [out]
  *  The validity status.
  * @return
  * <br> S_OK successful
  * <br> E_FAIL failed
  */
	 virtual  HRESULT  IsaValidCoexDbProvider(CATBoolean &oIsValid)=  0;

 /**
  * Check the equality to another coexistence database provider.
  *  @param  iCoexDbProvider [in]
  *  The coexistence database provider to be checked.
  *  @param  oIsEqual [out]
  *  The equality status.
  * @return
  * <br> S_OK successful
  * <br> E_FAIL failed
  */
	 virtual  HRESULT  IsEqualToCoexDbProvider(const CATICoexDbProvider_var & iCoexDbProvider,CATBoolean &oIsEqual)=  0; 

};  
CATDeclareHandler(CATICoexDbProvider, CATBaseUnknown);  

#endif  
