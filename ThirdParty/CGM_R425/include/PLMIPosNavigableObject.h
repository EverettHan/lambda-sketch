// (C) Copyright Dassault Systemes - 2005
// -----------------------------------------------------------------------
// Interface declaration: PLMIPosNavigableObject
// -----------------------------------------------------------------------
// Creation: 2005-12-12
// -----------------------------------------------------------------------
/**
 * @level Protected
 * @usage U5
 */

#ifndef _PLMIPosNavigableObject_H_
#define _PLMIPosNavigableObject_H_

#include "CATBaseUnknown.h"
#include "ExportedByGUIDPLMPosBaseInterfaces.h"
#include "CATCollec.h"
#include "CATListOfPLMPosAny.h"



class CATUnicodeString;
//
class PLMPosAny;
//class CATListOfPLMPosAny;
//
class PLMPosAttributeInfo;
//
class PLMIPosNavigableObject_var;
typedef class CATLISTV(PLMIPosNavigableObject_var) CATListOfPLMIPosNavigableObject;



#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByGUIDPLMPosBaseInterfaces IID IID_PLMIPosNavigableObject;
#else
extern "C" const IID IID_PLMIPosNavigableObject;
#endif



/**
 * PLM security navigable object base interface.
 * <b>Role</b>: This interface provides services to access the contents of
 * navigable objects (plain attribute values and references); it is used by
 * the rule valuation engine of component Security Engine to determine if
 * these objects comply with security rules
 * (e.g. <tt>V_status = "in work"</tt>).
 * <p>All PLM objects that require security function control must implement
 * this interface.
 * 
 * @see PLMIPosSecurityEngine
 */
class ExportedByGUIDPLMPosBaseInterfaces PLMIPosNavigableObject : public CATBaseUnknown
{
    CATDeclareInterface;
public:
    /**
     * Gets the entity name.
     * <br><b>Role</b>: This method retrieves the name of the PLM entity of
     * the object.
     * 
     * @param oEntityName
     * PLM entity name.
     * @return
     * Method execution status.
     * Possible values are:
     * S_OK   if the method is successfully executed;
     * E_FAIL when an error occurs while retrieving the entity name.
     */
    virtual HRESULT GetEntityName(CATUnicodeString& oEntityName) = 0;
    /**
     * Gets the entity hierarchy names.
     * <br><b>Role</b>: This method retrieves the hierarchical list of the PLM entity of
     * the object.
     * If not implemented, the PLMDictionary is used by the security kernel instead.
     * 
     * @param oEntityNames
     * PLM entity names.
     * @return
     * Method execution status.
     * Possible values are:
     * S_OK   if the method is successfully executed;
     * E_FAIL when an error occurs while retrieving the entity names.
     */
    virtual HRESULT GetEntityNames (CATListOfCATUnicodeString& oListEntityNames) = 0;
    /**
     * Checks the attribute existence.
     * <br><b>Role</b>: check whether an PLM entity's attribute exists.
     * @param iAttributeName
     * Name of the attribute whose existence has to be checked.
     * @param oAttributeInfo
     * Attribute's information.
     * @return
     * S_OK    if the attribute exists.
     * S_FALSE if the attribute does not exist.
     * E_FAIL  when an error occurs while computing the attribute information or checking its existence.
     */
    virtual HRESULT CheckAttribute(const CATUnicodeString& iAttributeName, PLMPosAttributeInfo &oAttributeInfo) = 0;
    /**
     * Gets an attribute value.
     * <br><b>Role</b>: This method retrieves the value of the specified
     * object's attribute (mono-valuated and simple type).
     * 
     * @param iAttributeName
     * Attribute name.
     * @param oAttributeValue
     * Attribute value.
     * @return
     * Method execution status.
     * Possible values are:
     * S_OK    if the attribute value is set and successfully retrieved;
     * S_FALSE if the attribute value is not set;
     * E_FAIL  when an error occurs while retrieving the attribute value.
     */
    virtual HRESULT GetAttributeValue(const CATUnicodeString& iAttributeName, PLMPosAny& oAttributeValue) = 0;
    /**
     * Gets an attribute value (for a reference to one object).
     * <br><b>Role</b>: This method retrieves the value of the specified
     * object's mono-valuated attribute, when the attribute type is a reference to object.
     * 
     * @param iAttributeName
     * Attribute name (a reference to another object).
     * @param oRefAttributeValue
     * Object referenced by the attribute.
     * @return
     * Method execution status.
     * Possible values are:
     * S_OK    if the attribute value is set and successfully retrieved;
     * S_FALSE if the attribute value is not set;
     * E_FAIL  when an error occurs while retrieving the attribute value.
     */
    virtual HRESULT GetRefAttributeValue(const CATUnicodeString& iAttributeName, PLMIPosNavigableObject_var& oRefAttributeValue) = 0;
    /**
     * Count values of the object's aggregate attribute.
     * @param iAggrAttributeName
     * Attribute name (an aggregate of simple type values).
     * @param oNumber
     * The elements number of the object's aggregate.
     */
    virtual HRESULT CountAggrValues(const CATUnicodeString& iAggrAttributeName, int &oNumber) = 0;
    /**
     * Gets all aggregate values.
     * <br><b>Role</b>: This method retrieves the value of the specified
     * object's attribute (mono-valuated and simple type).
     * 
     * @param iAggrAttributeName
     * Attribute name.
     * @param oAttributeValues
     * Aggregate attribute values.
     * @return
     * Method execution status.
     * Possible values are:
     * S_OK    if the attribute values are successfully retrieved;
     * E_FAIL  when an error occurs while retrieving the attribute values.
     */
    virtual HRESULT GetAggrAttributeValues(const CATUnicodeString& iAggrAttributeName, CATListOfPLMPosAny& oAttributeValues) = 0;
    /**
     * Gets an attribute value (for a reference to one object).
     * <br><b>Role</b>: This method retrieves the value of the specified
     * object's mono-valuated attribute, when the attribute type is a reference to object.
     * 
     * @param iAggrAttributeName
     * Attribute name (aggregate of references to another object).
     * @param oRefAttributeValues
     * List of objects referenced by the aggregate attribute.
     * @return
     * Method execution status.
     * Possible values are:
     * S_OK    if the attribute values are successfully retrieved;
     * E_FAIL  when an error occurs while retrieving the attribute values.
     */
    virtual HRESULT GetAggrRefAttributeValues(const CATUnicodeString& iAggrAttributeName, CATListOfPLMIPosNavigableObject& oRefAttributeValue) = 0;
};

CATDeclareHandler(PLMIPosNavigableObject,CATBaseUnknown);

#endif
