// COPYRIGHT Dassault Systemes 2006
// Code removed in R419 / 2017x, keeping just not implemented API such callers can continue compiling

#ifndef CATAdpSubscriptionDef_H
#define CATAdpSubscriptionDef_H
#include "CATIAV5Level.h"

#include "CATPLMIntegrationAccess.h"
#include "CATUnicodeString.h"
#include "CATErrorDef.h"
class CATIAdpPLMIdentificator;
class CATIAdpType;
enum RecipientType{ _NONE_=-1 , Person=1 , BuddyList=2 };
struct Recipient
{
public:
	CATUnicodeString _Recipient;
	enum RecipientType _Type;
};

class Subscription
{
public:
  inline void GetOperation (CATUnicodeString &iOperation) {}
  inline void GetDeliveryMethod (CATUnicodeString  &iDeliveryMethod) {}
  inline void SetOperation (CATUnicodeString &iOperation) {}
  inline void SetDeliveryMethod (CATUnicodeString  &iDeliveryMethod ) {}
  inline void SetRecipient (Recipient &iRecipient) {}
};

class SubscriptionForObject : public Subscription
{
public:
  inline HRESULT SetTarget (const CATIAdpPLMIdentificator *iTarget) {return E_FAIL;}
  inline void SetOperation (CATUnicodeString &iOperation) {}
  inline void SetRecipient (Recipient &iRecipient) {}
  inline void SetDeliveryMethod (CATUnicodeString  &iDeliveryMethod ) {}
};

class SubscriptionForType : public Subscription
{
public:
  inline HRESULT SetType (const CATIAdpType *iType){return E_FAIL;}
};

#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATPLMIntegrationAccess
#define CATLISTP_Append
#define CATLISTP_RemoveAll
#include "CATLISTP_Declare.h"
CATLISTP_DECLARE( Subscription );

#undef	CATCOLLEC_ExportedBy
#endif

