//===================================================================
// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMExpandResultHandlerAdapter.h
// Define the CATPLMExpandResultHandlerAdapter adapter
//
//===================================================================
//
// Usage notes:
//   adapter
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

#ifndef CATPLMExpandResultHandlerAdapter_H
#define CATPLMExpandResultHandlerAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterQLBase

#include "CATIPLMExpandResultHandler.h"// CATPLMServices ProtectedInterfaces CATPLMServicesItf.m CATPLMServicesItf.dll

/**
 * gives an adapter to the interface CATIPLMExpandResultHandler
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMExpandResultHandlerAdapter : public CATIPLMExpandResultHandler
{
public:
    CATPLMExpandResultHandlerAdapter();
    virtual ~CATPLMExpandResultHandlerAdapter();

    /** 
    * @nodoc
    */
    virtual HRESULT StartResult(int iVersion);

    /** 
    * @nodoc
    */
    virtual HRESULT EndResult(int iElapseTime);

    /** 
    * @nodoc
    */
    virtual HRESULT StartBlock();

    /** 
    * @nodoc
    */
    virtual HRESULT EndBlock(int iElapseTime);

    /** 
    * @nodoc
    */
    virtual HRESULT StartPath(int iRank);

    /** 
    * @nodoc
    */
    virtual HRESULT EndPath();

    /** 
    * @nodoc
    */
    virtual HRESULT Record( CATIPLMRecordRead * iRecord, CATBoolean iAlreadyVisited);

    /** 
    * @nodoc
    */
    virtual HRESULT GlobalReport(CATIPLMError * iError);

private:
    CATPLMExpandResultHandlerAdapter (CATPLMExpandResultHandlerAdapter &);
    CATPLMExpandResultHandlerAdapter& operator=(CATPLMExpandResultHandlerAdapter&);
};

#endif
