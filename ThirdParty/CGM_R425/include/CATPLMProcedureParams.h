//===================================================================
// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMProcedureParams.h
// Define the CATPLMProcedureParams class
//
//===================================================================
//
// Usage notes:
//   New adapter: parameters of procedures
//
//===================================================================
//
// July 2009
// Creation: EPB
//
//===================================================================

/**
* @level Protected
* @usage U1
*/

#ifndef CATPLMProcedureParams_H
#define CATPLMProcedureParams_H

#include "CATPLMServicesProc.h"

#include "CATSysErrorDef.h"             // SpecialAPI PublicInterfaces

#include "CATListOfInt.h"               // System PublicInterfaces
#include "CATListOfDouble.h"            // System PublicInterfaces
#include "CATListOfCATString.h"         // System PublicInterfaces
#include "CATBaseUnknown.h"             // System PublicInterfaces
#include "CATListOfCATBoolean.h"        // System PublicInterfaces
#include "CATString.h"                  // System PublicInterfaces
#include "CATListOfCATBinary.h"

#include "CATListOfCATTime.h"           //CATPLMServices ProtectedInterfaces

#include "CATLISTV_CATPLMID.h"          // CATPLMIdentificationAccess ProtectedInterfaces

#include "CATOmxKeyValueBlock.h"        // ObjectModelerCollection ProtectedInterfaces CATOmxKernel.m CATOmx

class CATString;

class ExportedByCATPLMServicesProc CATPLMProcedureParams : public CATBaseUnknown
{
  friend class CATPLMxProcedureCall;
  friend class CATAsyncProcedureCallRequest_old;
  friend class CATAsyncProcedureCallRequest;
  friend class CATPLMAsyncImpl;
  friend class CATAsyncServicesClass;
  friend class CATProcedureCallTransactionMsg;
  friend class CATProcedureCallAsyncResultMsg;
  friend class CATSyncPlatformAdapter;
  friend class CATSyncPlatformAdapter_old;
  friend class CATPLMAsyncAdapter;

public:
  CATPLMProcedureParams();
  virtual ~CATPLMProcedureParams();

  //PLMId
  HRESULT SetListPlmid(const CATString & iParamName , const CATLISTV(CATPLMID) & iListPlmid);
  HRESULT GetListPlmid(const CATString & iParamName , CATLISTV(CATPLMID) & oListPlmid) const;

  HRESULT SetPlmid(const CATString & iParamName , const CATPLMID & iPlmid);
  HRESULT GetPlmid(const CATString & iParamName , CATPLMID & oPlmid) const;

  //integer
  HRESULT SetListInt(const CATString & iParamName , const CATListOfInt & iListInt);
  HRESULT GetListInt(const CATString & iParamName , CATListOfInt & oListInt) const;

  HRESULT SetInt(const CATString & iParamName , const int & iInt);
  HRESULT GetInt(const CATString & iParamName , int & oInt) const;

  //double
  HRESULT SetListDouble(const CATString & iParamName , const CATListOfDouble & iListDouble);
  HRESULT GetListDouble(const CATString & iParamName , CATListOfDouble & oListDouble) const;

  HRESULT SetDouble(const CATString & iParamName , const double & iDouble);
  HRESULT GetDouble(const CATString & iParamName , double & oDouble) const;

  //boolean
  HRESULT SetListBoolean(const CATString & iParamName , const CATListOfCATBoolean & iListBoolean);
  HRESULT GetListBoolean(const CATString & iParamName , CATListOfCATBoolean & oListBoolean) const;

  HRESULT SetBoolean(const CATString & iParamName , const CATBoolean & iBoolean);
  HRESULT GetBoolean(const CATString & iParamName , CATBoolean & oBoolean) const;

  //date
  HRESULT SetListDate(const CATString & iParamName , const CATListOfCATTime & iListTime);
  HRESULT GetListDate(const CATString & iParamName , CATListOfCATTime & oListTime) const;

  HRESULT SetDate(const CATString & iParamName , const CATTime & iTime);
  HRESULT GetDate(const CATString & iParamName , CATTime & oTime) const;

  //string
  HRESULT SetListString(const CATString & iParamName , const CATListOfCATUnicodeString & iListString);
  HRESULT GetListString(const CATString & iParamName , CATListOfCATUnicodeString & oListString) const;

  HRESULT SetString(const CATString & iParamName , const CATUnicodeString & iString);
  HRESULT GetString(const CATString & iParamName , CATUnicodeString & oString) const;

  //binary
  HRESULT SetListBinary(const CATString & iParamName , const CATListOfCATBinary & iListBin);
  HRESULT GetListBinary(const CATString & iParamName , CATListOfCATBinary & oListBin) const;

  HRESULT SetBinary(const CATString & iParamName , const CATBinary & iBin);
  HRESULT GetBinary(const CATString & iParamName , CATBinary & oListBin) const;

  CATOmxKeyValueBlock GetValueBlock() const;
  //virtual void SetValueBlock(CATOmxKeyValueBlock iValueObject);

  CATPLMProcedureParams & operator=(const CATPLMProcedureParams &rhs);

private:
  CATPLMProcedureParams(const CATPLMProcedureParams& iParams);
  CATPLMProcedureParams(CATOmxKeyValueBlock& iValueBlock);

  // Check that the name of the parameter given to the current class calling SetListPlmid, SetPlmid.... 
  // is found in the metadata of the procedure iProcName 
  // S_OK parameter found on the metadata
  // E_FAIL parameter not found
  HRESULT _Check(const CATString & iProcName);

  CATOmxKeyValueBlock _ValueBlock;
  //CATListOfCATString _ListOfParamName;
};


#endif
