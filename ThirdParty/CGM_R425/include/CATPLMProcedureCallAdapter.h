//===================================================================
// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMProcedureCallAdapter.h
// Define the CATPLMProcedureCallAdapter adapter
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMProcedureCall
//
//===================================================================
//
// Feb 2009
// Creation: EPB
//
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMProcedureCallAdapter_H
#define CATPLMProcedureCallAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedBy

#include "CATIPLMProcedureCall.h"// CATPLMServices ProtectedInterfaces CATPLMServicesItf.m CATPLMServicesItf.dll

class CATPLMProcedureParams;
class CATIPLMError;
class CATIPLMRecordReadSet;

/**
 * gives an adapter to the interface CATIPLMProcedureCall
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMProcedureCallAdapter : public CATIPLMProcedureCall
{
public:
    CATPLMProcedureCallAdapter();
    virtual ~CATPLMProcedureCallAdapter();

    //virtual HRESULT LaunchProcedure(    const CATString & iProcedureName,
    //                                    const CATLISTV(CATPLMID) & iInputIDs,
    //                                    CATIPLMRecordReadSet *& oRecordSet);

    virtual HRESULT LaunchProcedure(const CATString & iProcName,
                                    CATPLMProcedureParams & iObject,
                                    CATPLMProcedureParams & oObject,
                                    CATIPLMError* & opError);

    //virtual HRESULT ParseProcParams(  const CATString & iProcName                               ,
    //                                  ParamModes   iParamMode                                   ,
    //                                  CATListOfCATString & oListOfParamName /*Parameter Name*/  ,
    //                                  CATListOfCATBoolean & oListOfIsMulti  /*MultiValuated*/   ,
    //                                  CATListOfInt & oListLowerBound        /*Lower*/           ,
    //                                  CATListOfInt & oListUpperBound        /*Upper*/           ,
    //                                  CATListOfCATString & oListOfDataType  /*DataType*/
    //                                  );

    virtual HRESULT Convert(  const CATString & iProcedureName,
                              CATPLMProcedureParams & iObject     ,
                              CATIPLMRecordReadSet *& oRecordSet);

private:
    CATPLMProcedureCallAdapter (CATPLMProcedureCallAdapter &);
    CATPLMProcedureCallAdapter& operator=(CATPLMProcedureCallAdapter&);
};

#endif
