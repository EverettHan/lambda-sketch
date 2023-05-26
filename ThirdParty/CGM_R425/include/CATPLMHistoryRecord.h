//===================================================================
// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMHistoryRecord
//
//===================================================================
//
// CATPLMHistoryRecord gives access to the object whose description is in HISTORY.metadata
// internal use for PLMAdapter team!!!
//
// WARNING1:
// when you have a CATPLMHistoryRecord, the first that you have to do is a call
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
// I have to provide a specific implemention for each operation
// CATPLMHistoryRecordCreate,CATPLMHistoryRecordUpdate....
// those records inherits from CATPLMHistoryRecord
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

#ifndef CATPLMHistoryRecord_H
#define CATPLMHistoryRecord_H

#include "CATPLMServicesItf.h"// ExportedByCATPLMServicesItf

#include "CATPLMHistoryRecordLight.h"   // Base class

#include "CATUnicodeString.h"   // System PublicInterfaces
#include "CATTime.h"            // System PublicInterfaces

#include "CATOmxAny.h"           // ObjectModelerSystem ProtectedInterfaces
#include "CATOmxKeyValueBlock.h" // ObjectModelerSystem ProtectedInterfaces

#include "CATPLMID.h"       // CATPLMIdentificationAccess ProtectedInterfaces CATPLMIdentifier.m CATPLMIdentificationAccess.dll

class CATOmxKeyString;

class ExportedByCATPLMServicesItf CATPLMHistoryRecord : public CATPLMHistoryRecordLight
{
public:
  /** 
  * ADD A DOCUMENTATION
  */
  enum OperationName{   
    Unknown=0, 
    Create, 
    Update , 
    Delete , 
    ChangeStatus , 
    Lock , 
    UnLock , 
    ChangeAuthorityControl , 
    TransferOwnership , 
    NewVersion,
    Clone,
    ModifyUnderCorrection,
    NewMinorVersion
  };

  static OperationName Convert(const CATUnicodeString& iStrOperationName);

  static const CATUnicodeString& Convert(OperationName ieOperationName);

  /** 
  * we create the C++ projection of the object HistoryEntry
  *
  * <br><b>Role</b>: we create the C++ projection of the object HistoryEntry
  *
  * @param iActionID [in]
  *   The parameter role...
  * @param iUniqueId [in]
  *   The parameter role...
  * @param iUser [in]
  *   The parameter role...
  * @param iRole [in]
  *   The parameter role...
  * @param iProject [in]
  *   The parameter role...
  * @param iModificationDate [in]
  *   The parameter role...
  * @param iHistoryComment [in]
  *   The parameter role...
  * @param iCompPLMID [in]
  *   The parameter role...
  * @param iOperation [in]
  *   The parameter role...
  *
  */
  CATPLMHistoryRecord(const CATPLMID & iActionID                  ,
                      const CATUnicodeString & iUniqueId          ,
                      const CATUnicodeString & iUser              ,
                      const CATUnicodeString & iRole              ,
                      const CATUnicodeString & iProject           ,
                      const CATTime & iModificationDate           ,
                      const CATUnicodeString & iHistoryComment    ,
                      const CATPLMID & iCompPLMID                 ,
                      const OperationName & iOperation            ,
                      const CATPLMID &iCompOwner                  , 
                      const CATPLMID &iCompInstanceOf             ,
                      const CATOmxAny &iOperationData             ,
                      const CATUnicodeString &iEventID = ""       ,
                      const CATUnicodeString &iUserFactID = ""    ,
                      const CATUnicodeString &iUserFactName = ""  ,
                      const CATPLMID &iDerivedFrom = CATPLMID_Null,
                      const CATUnicodeString &iUserData = "",
                      int iOrderValue = -1);

  virtual ~CATPLMHistoryRecord();

  // --------------------------
  // accessor on attributes
  // --------------------------

  /** 
  * this method retrieves the UniqueId on the HistoryEntry object.
  *
  * <br><b>Role</b>: this method retrieves the ActionID on the UniqueId object.
  *
  * CATPLMCEStamp is here to solve problem of concurrent engineering
  * eg: you have loaded a data in session, you have modified it in session
  *     at the same time, another user has saved the same data in the database
  *     With the CATPLMCEStamp, we are able to solve those kinds of scenarios
  *
  * @param oUniqueId [out]
  *   value of the UniqueId
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
  HRESULT GetUniqueId(CATUnicodeString & oUniqueId);

  /** 
  * this method retrieves the User on the HistoryEntry object.
  *
  * <br><b>Role</b>: this method retrieves the User on the HistoryEntry object.
  *
  * @param oUser [out]
  *   value of the User
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
  HRESULT GetUser(CATUnicodeString & oUser);

  /** 
  * this method retrieves the Role on the HistoryEntry object.
  *
  * <br><b>Role</b>: this method retrieves the Role on the HistoryEntry object.
  *
  * @param oRole [out]
  *   value of the Role
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
  HRESULT GetRole(CATUnicodeString & oRole);

  /** 
  * this method retrieves the Project on the HistoryEntry object.
  *
  * <br><b>Role</b>: this method retrieves the Project on the HistoryEntry object.
  *
  * @param oProject [out]
  *   value of the Project
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
  HRESULT GetProject(CATUnicodeString & oProject);

  /** 
  * this method retrieves the ModificationDate on the HistoryEntry object.
  *
  * <br><b>Role</b>: this method retrieves the ModificationDate on the HistoryEntry object.
  *
  * @param oModificationDate [out]
  *   value of the ModificationDate
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
  HRESULT GetModificationDate(CATTime & oModificationDate);

  /** 
  * this method retrieves the HistoryComment on the HistoryEntry object.
  *
  * <br><b>Role</b>: this method retrieves the HistoryComment on the HistoryEntry object.
  *
  * @param oHistoryComment [out]
  *   value of the HistoryComment
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
  HRESULT GetHistoryComment(CATUnicodeString & oHistoryComment);

  /** 
  * this method retrieves the CompPLMID on the HistoryEntry object.
  *
  * <br><b>Role</b>: Explain what this method does.
  *
  * @param oOperation [out]
  *   value of the Operation
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
  HRESULT GetOperation(OperationName & oOperation);

  /** 
  * this method retrieves the CompCUS on the HistoryEntry object.
  *
  * <br><b>Role</b>: this method retrieves the CompCUS on the HistoryEntry object.
  *
  * @param oCompCUS [out]
  *   value of the CompCUS (CUpdatestamp)
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
  HRESULT GetCompCUS(int & oCompCUS);

  /** 
  * this method retrieves the owner of the HistoryEntry object.
  *
  * @param oCompOwner [out]
  *   PLMID of the owner associated to the CompPLMID
  *
  * @return
  *   <code>S_OK</code> if a owner was found
  *   <code>E_FAIL</code> if a valid owner was not found. Can happen if CompPLMID is a reference for example
  */
  HRESULT GetCompOwner (CATPLMID &oCompOwner);

  /** 
  * this method retrieves the reference pointed by the HistoryEntry object.
  *
  * @param oCompInstanceOf [out]
  *   PLMID of the reference associated to the CompPLMID
  *
  * @return
  *   <code>S_OK</code> if a reference was found
  *   <code>E_FAIL</code> if a valid reference was not found. Can happen if CompPLMID is not an instance for example
  */
  HRESULT GetCompInstanceOf (CATPLMID &oCompInstanceOf);

  /** 
  * this method retrieves the operation data of the HistoryEntry object.
  *
  * @param oOperationData [out]
  *   Operation data. It is a list of CATOmxAny.
  *
  * @return
  *   <code>S_OK</code> their is operation data
  *   <code>E_FAIL</code> otherwise
  */
  HRESULT GetOperationData (CATOmxAny &oOperationData);

  HRESULT GetOperationData (const CATOmxKeyString& iAttrName,CATOmxAny &oOperationData);

  // TO BE DEFINED
  //virtual HRESULT GetOperationData(CATUnicodeString & oOperationData);

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

  HRESULT GetEventID(CATUnicodeString &oValue);
  HRESULT GetDerivedFrom(CATPLMID &oValue);
  HRESULT GetUserFactID(CATUnicodeString &oValue);
  HRESULT GetUserFactName(CATUnicodeString &oValue);
  HRESULT GetUserData(CATUnicodeString &oValue);

  // 0 if order is not valuated, order starts at 1 if it is valuated
  int GetOrderValue();

private:
  CATUnicodeString _UniqueId;
  CATUnicodeString _User;
  CATUnicodeString _Role;
  CATUnicodeString _Project;
  CATTime _ModificationDate;
  CATUnicodeString _HistoryComment;
  OperationName _Operation;
  CATOmxAny _OperationData;
  CATOmxKeyValueBlock _OperationDataKvb;
  CATBoolean _isComputedODKvb;

  CATPLMID _CompOwner, _CompInstanceOf;

  CATUnicodeString _EventID;
  CATUnicodeString _UserFactID;
  CATUnicodeString _UserFactName;
  CATUnicodeString _UserData;
  CATPLMID         _DerivedFrom;

  int _OrderValue;//not valuated _OrderValue==-1, _OrderValue starts at 1 if it is valuated
};

#endif
