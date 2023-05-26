// COPYRIGHT Dassault Systemes 2006
// Code removed in R419 / 2017x, keeping just not implemented API such callers can continue compiling

#ifndef CATAdpProtectedPubSubServices_H
#define CATAdpProtectedPubSubServices_H
#include "CATIAV5Level.h"

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATSysMacros.h"

class CATIAdpPLMIdentificator;
class CATAdpPubSubIndex;
class CATListPtrCATAdpPubSubNotification;

#include "CATAdpSubscriptionDef.h"
class ExportedByCATPLMIntegrationAccess CATAdpProtectedPubSubServicesErrorHandler
{
};

class CATAdpProtectedPubSubServices
{
public:
  inline static HRESULT ListDeliveryMethod( CATListOfCATUnicodeString& Operations , CATListOfCATUnicodeString& OperationsUS  ){return E_FAIL;}
	inline static HRESULT QuerySubscriptions ( const CATIAdpPLMIdentificator *iInput , int iResultFilter, const CATUnicodeString &iRecipient, CATLISTP(Subscription) &oSubList, const char *iRepositoryName = NULL){return E_FAIL;}
	inline static HRESULT Begin( const CATString& iProviderName , CATAdpProtectedPubSubServicesErrorHandler * iErrorHandler){return E_FAIL;}
	inline static HRESULT RegisterSubscriptionForObject( const SubscriptionForObject& iSub  ){return E_FAIL;}
  inline static HRESULT RemoveSubscription( const CATLISTP(Subscription) &iSub  ){return E_FAIL;}
	inline static HRESULT RegisterSubscriptionForType( const SubscriptionForType& iSub ){return E_FAIL;}
  inline static HRESULT ListPublishedOperations( const  CATIAdpType *iType , CATListOfCATUnicodeString& Operations , CATListOfCATUnicodeString& OperationsNLS){return E_FAIL;}
  inline static HRESULT GetNotifications ( const CATString& iRepositoryName,  const CATAdpPubSubIndex &iIndex , int iNbRequest, CATListPtrCATAdpPubSubNotification &oNotifs, CATAdpPubSubIndex &oNewIndex) {return E_FAIL;} 
  inline static HRESULT End( ){return E_FAIL;}
};
#endif
