/** WARNING: YWE 15:05:15 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
//  COPYRIGHT  DASSAULT  SYSTEMES  2011  
#ifndef CATICoexDbProviderUser_H_
#define CATICoexDbProviderUser_H_

#include "ExportedByCATDbProvider.h"
#include "CATBaseUnknown.h"
#include "IUnknown.h"
#include "CATListOfCATUnicodeString.h"

/** @level Private 
* @usage U3
*/
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATDbProvider IID IID_CATICoexDbProviderUser;
#else
extern "C" const IID IID_CATICoexDbProviderUser ;
#endif
//---------------------------------------------------------------------------  
class ExportedByCATDbProvider CATICoexDbProviderUser : public CATBaseUnknown
{  
  CATDeclareInterface;
 
 public: 
 /**
  *  Gets the coexistence provider user parameters.
  *  @param  oLstParam [out]
  *  The  list  of  parameters 
  *  @param  oLstValue [out]
  *  The  list  of  value  attached  to  each  parameter  
  * @return
  * <br> S_OK successful
  * <br> E_FAIL failed
  */
	 virtual  HRESULT  GetCoexDbProviderUserParameters(  CATListOfCATUnicodeString  &  oLstParam  ,  CATListOfCATUnicodeString  &  oLstValue  )  =  0  ;

 /**
  *  Sets the coexistence provider user parameters.
  *  @param  iLstParam [in]
  *  The  list  of  parameters 
  *  @param  iLstValue [in]
  *  The  list  of  value  attached  to  each  parameter  
  * @return
  * <br> S_OK successful
  * <br> E_FAIL failed
  */
	 virtual  HRESULT  SetCoexDbProviderUserParameters(  const CATListOfCATUnicodeString  &  iLstParam  , const CATListOfCATUnicodeString  &  iLstValue  )  =  0  ;

 /**
  * Check the validity of the coexistence provider user.
  *  @param  oIsValid [out]
  *  The validity status.
  * @return
  * <br> S_OK successful
  * <br> E_FAIL failed
  */
     virtual  HRESULT  IsaValidCoexDbProviderUser(CATBoolean &oIsValid)=  0;
     
};  
CATDeclareHandler(CATICoexDbProviderUser, CATBaseUnknown);  

#endif  
  
