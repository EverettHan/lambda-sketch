// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMImportTransactionAdapter.h
// Define the CATPLMImportTransactionAdapter interface
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMImportTransaction
//
//===================================================================
//
// Feb 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMImportTransactionAdapter_H
#define CATPLMImportTransactionAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedBy

#include "CATIPLMImportTransaction.h"// CATPLMServices ProtectedInterfaces CATPLMServicesItf.m CATPLMServicesItf.dll

/**
 * gives an adapter to the interface CATIPLMImportTransaction
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMImportTransactionAdapter : public CATIPLMImportTransaction
{
public:
    CATPLMImportTransactionAdapter();
    virtual ~CATPLMImportTransactionAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT GetTransactionCEStamp(CATLISTV(CATPLMID) &iImportedComponents, CATPLMCEStamp &oCEStamp);

    /** 
    * @nodoc
    */
    virtual HRESULT GetURLs (  CATLISTV(CATPLMSDId) &ioSDIdList);

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
    CATPLMImportTransactionAdapter (CATPLMImportTransactionAdapter &);
    CATPLMImportTransactionAdapter& operator=(CATPLMImportTransactionAdapter&);
};

#endif
