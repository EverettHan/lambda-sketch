// (C) Copyright Dassault Systemes - 2005
// -----------------------------------------------------------------------
// Class declaration PLMPosAttributeInfo
// -----------------------------------------------------------------------
// Creation: 2005-12-12
// -----------------------------------------------------------------------
/**
 * @level Protected
 * @usage U3
 */

#ifndef _PLMPosAttributeInfo_H_
#define _PLMPosAttributeInfo_H_

#include "CATBaseUnknown.h"
#include "ExportedByGUIDPLMPosBaseInterfaces.h"



/**
 * Class that gives information about one attribute.
 */
class ExportedByGUIDPLMPosBaseInterfaces PLMPosAttributeInfo
{
public:
    /** @nodoc */
    PLMPosAttributeInfo();
    /** @nodoc */
    PLMPosAttributeInfo(int iIsDate, int iIsAggregate, int iIsObject);
    /** @nodoc */
    void SetInfo(int iIsDate, int iIsAggregate, int iIsObject);
    /** @nodoc */
    HRESULT SetObjectType(const char *iObjectType);
    /** @nodoc */
    ~PLMPosAttributeInfo();
    /** @nodoc */
    PLMPosAttributeInfo(const PLMPosAttributeInfo &iCopy);
    /** @nodoc */
    PLMPosAttributeInfo& operator= (const PLMPosAttributeInfo &iCopy);
    /** @nodoc */
    HRESULT IsDate() const;
    /** @nodoc */
    HRESULT IsAggregate() const;
    /** @nodoc */
    HRESULT IsObject() const;
    /** @nodoc */
    HRESULT GetObjectType(CATUnicodeString &osObjectType) const;
private:
    /** @nodoc */
    int _bAggregate;
    /** @nodoc */
    int _bDate;
    /** @nodoc */
    int _bObject;
    /** @nodoc */
    char * _ccObjectType;
};

#endif
