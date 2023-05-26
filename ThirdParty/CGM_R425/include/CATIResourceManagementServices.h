//===================================================================
// COPYRIGHT Dassault Systemes 2018/04/17
//===================================================================
// CATIResourceManagementServices.cpp
// Header definition of class CATIResourceManagementServices
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2018/04/17 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIResourceManagementServices_H
#define CATIResourceManagementServices_H

#include "CATLifSpecs.h"
#include "CATBaseUnknown.h"

class CATUnicodeString;
class CATCkeEvalContext;
class CATIKweAppResourcesTable_var;

extern ExportedByCATLifSpecs  IID IID_CATIResourceManagementServices;
class ExportedByCATLifSpecs CATIResourceManagementServices : public CATBaseUnknown
{
    CATDeclareInterface;

public:

    //
    // TODO: Add your methods for this interface here.
    //
    virtual CATBaseUnknown_var GetResource(const CATUnicodeString &ARMPath,
        const CATUnicodeString &CallingFunction,
        CATUnicodeString &errorMsg,
        const CATCkeEvalContext *iEvalContext) = 0;

    virtual HRESULT GetTableKAC(CATUnicodeString & ioARMPath, CATIKweAppResourcesTable_var & oARMTable, CATUnicodeString & oErrorMessage) = 0;

    virtual HRESULT StackFilter(const CATBaseUnknown_var & hFilter) = 0;
    virtual HRESULT UnstackFilter(const int n, CATUnicodeString & oErrorMessage) = 0;

    // @SOB Dev Config Filter II
    // _FilterPLMWspPVS
    virtual HRESULT SetPvsFilter(const CATBaseUnknown_var& ihFilter) = 0;
    virtual HRESULT GetPvsFilter(CATBaseUnknown_var& ohFilter) = 0;
    virtual HRESULT UnsetPvsFilter() = 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler(CATIResourceManagementServices, CATBaseUnknown);

#endif