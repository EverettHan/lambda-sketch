//===================================================================
// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMHistoryRecordLight
//
//===================================================================
//
// CATPLMHistoryRecordLight gives access to the object whose description is in HISTORY.metadata
// internal use for PLMAdapter team!!!
//
// WARNING1:
// when you have a CATPLMHistoryRecordLight, the first that you have to do is a call
// on the method IsValid!!!
//
// WARNING2:
// in the metadata HISTORY.metadata, all attributes are mandatory
// Remark: we can do a query on a subset of attributes that we found on the HISTORY
// in such a case, all attributes are not set and it is not a mistake!!!
// today, only one attribute is mandatory whatever the query sent to the server:
// oCompPLMID(id of the component on which operation occurred )
//
// TO BE FINISHED
// I have to provide a specific implemenation for each operation
// CATPLMHistoryRecordLightCreate,CATPLMHistoryRecordLightUpdate....
// those records inherits from CATPLMHistoryRecordLight
//
//===================================================================
//
// Jan 2009 Creation EPB
// 
//===================================================================

/**
* @level Protected
* @usage U1
*/

#ifndef CATPLMHistoryRecordLight_H
#define CATPLMHistoryRecordLight_H

#include "CATPLMServicesItf.h"// ExportedByCATPLMServicesItf

#include "CATUnicodeString.h"   // System PublicInterfaces

#include "CATPLMID.h"       // CATPLMIdentificationAccess ProtectedInterfaces CATPLMIdentifier.m CATPLMIdentificationAccess.dll

class CATPLMHistoryRecord;

class ExportedByCATPLMServicesItf CATPLMHistoryRecordLight 
{
public:
    /** 
    * we create the C++ projection of the object HistoryEntry
    *
    * <br><b>Role</b>: we create the C++ projection of the object HistoryEntry
    *
    * @param iActionID [in]
    *   The parameter role...
    * @param iCompPLMID [in]
    *   The parameter role...
    *
    */
    CATPLMHistoryRecordLight( const CATPLMID & iActionID, const CATPLMID & iCompPLMID );

    virtual ~CATPLMHistoryRecordLight();

    // --------------------------
    // accessor on attributes
    // --------------------------

    /** 
    * this method retrieves the ActionID on the HistoryEntry object.
    *
    * <br><b>Role</b>: this method retrieves the ActionID on the HistoryEntry object.
    *
    * @param oActionID [out]
    *   value of the ActionID
    *
    * @return
    *   <code>S_OK</code> if everything ran ok, we always return S_OK
    * reason:
    * in the metadata HISTORY.metadata, all attributes are mandatory
    * Remark: we can do a query on a subset of attributes that we found on the HISTORY
    * in such a case, all attributes are not set and it is not a mistake!!!
    * today, only one attribute is mandatory whatever the query sent to the server:
    * oCompPLMID(id of the component on which operation occurred )
    *
    */
    HRESULT GetActionID(CATPLMID & oActionID);

    /** 
    * this method retrieves the CompPLMID on the HistoryEntry object.
    * oCompPLMID is the id of the component on which operation occurred 
    *
    * <br><b>Role</b>: this method retrieves the CompPLMID on the HistoryEntry object.
    *
    * @param oCompPLMID [out]
    *   value of the CompPLMID
    *
    * @return
    *   <code>S_OK</code> if everything ran ok and if oCompPLMID is correctly filled
    *   <code>S_FALSE</code>if oCompPLMID is badly filled, it is strange you should have called the method IsValid() before
    *   <code>E_fAIL</code>if a problem occurs when we have tried to get the CompPLMID, it is strange you should have called the method IsValid() before
    *
    */
    HRESULT GetCompPLMID(CATPLMID & oCompPLMID);

    /** 
    * test if the record is correctly filled.
    *
    * <br><b>Role</b>: test if the method is correctly written.
    *
    * in the metadata HISTORY.metadata, all attributes are mandatory
    * Remark: we can do a query on a subset of attributes that we found on the HISTORY
    * in such a case, all attributes are not set and it is not a mistake!!!
    * today, only one attribute is mandatory whatever the query sent to the server:
    * CompPLMID(id of the component on which operation occurred )
    *
    * @return
    *   <code>S_OK</code> CompPLMID and ActionId are correctly filled
    *   <code>S_FALSE</code> CompPLMID is correctly filled but ActionId is not set
    *   <code>E_FAIL</code> CompPLMID is badly filled. The record has no meaning.
    */
    virtual HRESULT IsValid();

    /**
    *  Returns a pointer to a more complete record.
    *  @param oAccess
    *     The output pointer if valid.
    *  @return
    *    S_OK   : The pointer is OK
    *    E_FAIL : The record light does not contian more info or oAccess is not empty
    */
    virtual HRESULT GetMoreInfo ( CATPLMHistoryRecord *& oAccess );

protected:
    int _Type;

private:
    CATPLMID _ActionID;
    CATPLMID _CompPLMID;

};

#endif
