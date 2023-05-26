// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// PLMIPSIUEHelpParamValues.h
// Define the PLMIPSIUEHelpParamValues interface
//
//===================================================================
//
// Usage notes:
//   PLMIPSIUEHelpParamValues : Interface to retrieve parameters for attributes prevaluation
//
//===================================================================

/**
* @level Protected
* @usage U4 PLMPSIUEHelpParamValuesAdapter
*/

#ifndef PLMIPSIUEHelpParamValues_H
#define PLMIPSIUEHelpParamValues_H

#include "PLMPSISessionInterfaces.h"
#include "CATBaseUnknown.h"

class CATListValPLMPSIHelpParamInfos;

extern ExportedByPLMPSISessionInterfaces IID IID_PLMIPSIUEHelpParamValues;
/** @nodoc */
class ExportedByPLMPSISessionInterfaces PLMIPSIUEHelpParamValues: public CATBaseUnknown
{
    CATDeclareInterface;

public:

    /** @nodoc */
    virtual HRESULT GetListHelpParamInfos (CATListValPLMPSIHelpParamInfos & oListParam) = 0; 

};

#endif
