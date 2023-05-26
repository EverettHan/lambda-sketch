// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// PLMPSIHelpParamValuation.h
// Header definition of PLMPSIHelpParamValuation
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

#ifndef PLMPSIHelpParamValuation_H
#define PLMPSIHelpParamValuation_H

#include "PLMPSISessionInterfaces.h"
#include "PLMPSIHelpParamInfos.h"
#include "CATBoolean.h"
class CATIValue;

/** @nodoc */
class ExportedByPLMPSISessionInterfaces PLMPSIHelpParamValuation
{

public:

    /** @nodoc */
    PLMPSIHelpParamValuation(const PLMPSIHelpParamInfos & iParamInfos, CATIValue * & iValue); 

    /** @nodoc */
    PLMPSIHelpParamValuation (const PLMPSIHelpParamValuation &);

    /** @nodoc */
    ~PLMPSIHelpParamValuation();

    /** @nodoc */
    PLMPSIHelpParamInfos GetParamInfos() const;

    /** @nodoc */
    CATIValue * GetParamValue() const;

    /** @nodoc */
    CATBoolean operator==(const PLMPSIHelpParamValuation& iInfos ) const;

    /** @nodoc */
    CATBoolean operator!=(const PLMPSIHelpParamValuation& iInfos ) const;

    /** @nodoc */
    PLMPSIHelpParamValuation &operator=(const PLMPSIHelpParamValuation& iInfos );

    /** @nodoc */
    PLMPSIHelpParamValuation(); 


private : 

    PLMPSIHelpParamInfos _paramInfo;
    CATIValue * _paramValue;

};

#endif
