// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMTransactionAdapter.h
// Define the CATPLMTransactionAdapter interface
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMTransaction
//
//===================================================================
//
// Feb 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMTransactionAdapter_H
#define CATPLMTransactionAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterQLBase

#include "CATIPLMTransaction.h"// CATPLMServices ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterClass.dll

class CATIPLMRecordReadSet;
class CATPLMID;
class CATTime;
class CATUnicodeString;

class ExportedByCATPLMImplAdapterClass CATPLMTransactionAdapter : public CATIPLMTransaction
{
public:
    CATPLMTransactionAdapter();
    virtual ~CATPLMTransactionAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT Save(CATIPLMRecordReadSet ** oRecordReportSet);

    /** 
    * @nodoc
    */
    virtual HRESULT Commit(CATIPLMRecordReadSet ** oRecordReportSet = NULL);

    /** 
    * @nodoc
    */
    virtual HRESULT Rollback();

    /** 
    * @nodoc
    */
    virtual HRESULT Flush();

    /** 
    * @nodoc
    */
    virtual HRESULT SetAction(const CATPLMID & iId);

    /** 
    * @nodoc
    */
    virtual HRESULT SetApplicabilityDate(const CATTime * iValue);

    /** 
    * @nodoc
    */
    virtual HRESULT SetTransactionComment (const CATUnicodeString &iTransactionComment);

    /**
    * @nodoc
    */
    virtual HRESULT SetCustomizedParameters(const CATPLMStrToKvb& iMapStrToKvb);

    /**
    * @nodoc
    */
    virtual HRESULT GetCustomizedParameters(CATPLMStrToKvb& oMapStrToKvb) const;

private:
    CATPLMTransactionAdapter (CATPLMTransactionAdapter &);
    CATPLMTransactionAdapter& operator=(CATPLMTransactionAdapter&);
};

#endif
