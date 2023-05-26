// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// PLMPSIHelpParamInfos.h
// Header definition of PLMPSIHelpParamInfos
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2005  Creation: Code generated by the CAA wizard  pvn
//===================================================================

/**
* @level Protected
* @usage U1
*/

#ifndef PLMPSIHelpParamInfos_H
#define PLMPSIHelpParamInfos_H

#include "PLMPSISessionInterfaces.h"
#include "CATUnicodeString.h"
#include "CATBoolean.h"
#include "IUnknown.h"

/** @nodoc */
class ExportedByPLMPSISessionInterfaces PLMPSIHelpParamInfos
{

public:

    /** @nodoc */
    enum CATPLMParamType {
        StringType = 0,
        RealType = 1,
        IntegerType = 2,
        DateType = 3,
        BooleanType = 4
    };

    /** @nodoc */
    PLMPSIHelpParamInfos (const CATPLMParamType &iType,
        const CATUnicodeString& iName, 
        const CATUnicodeString& iAlias,
        const CATBoolean iIsMandatory = FALSE);

    /** @nodoc */
    ~PLMPSIHelpParamInfos ();

    /** @nodoc */
    PLMPSIHelpParamInfos (const PLMPSIHelpParamInfos &);

    /** @nodoc */
    CATPLMParamType GetType();

    /** @nodoc */
    HRESULT IsMandatory () const;

    /** @nodoc */
    CATUnicodeString GetName() const;

    /** @nodoc */
    CATUnicodeString GetAliasName() const;

    /** @nodoc */
    CATBoolean operator==( const PLMPSIHelpParamInfos& iInfos ) const;

    /** @nodoc */
    CATBoolean operator!=( const PLMPSIHelpParamInfos& iInfos ) const;

    /** @nodoc */
    PLMPSIHelpParamInfos &operator=( const PLMPSIHelpParamInfos& iInfos ) ;

    /** @nodoc */
    PLMPSIHelpParamInfos();

private :

    CATPLMParamType _paramType;
    CATUnicodeString _paramName;
    CATUnicodeString _paramAlias;
    CATBoolean _isMandatory;
};

#endif