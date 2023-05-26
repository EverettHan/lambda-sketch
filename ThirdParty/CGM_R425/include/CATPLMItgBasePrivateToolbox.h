/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005
#ifndef CATPLMItgBasePrivateToolbox_H
#define CATPLMItgBasePrivateToolbox_H

#include "CATPLMIntegrationBase.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATPLMSessionDataSourceStatus.h"
#include "CATComponentIdStatus.h"
#include "CATOmxSR.h"
#include "CATOmxOHMap.h"
#include "CATListOfCATString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATPLMTypeH.h"
#include "CATOmxKeyValueBlock.h"

class CATPLMID;
class CATPLMID_RepositoryLocation;
class CATPLMTypeId;
class CATPLMType;
class CATString;
class CATComponentId;
class CATBaseUnknown;
class CATIPLMIntegRecordRead;
class CATPLMCEStamp;
class CATPLMRepositoryName;
class CATPLMID_Any;
class CATProxySpace;
class CATUnicodeString;
class CATIPLMRecordRead;
class CATIPLMAttributeSet;

/**
 * Helpers for integration processes.
 */

namespace DataSourceStatus
{
  struct ExportedByCATPLMIntegrationBase Transient
  {
    static const char None[];
    static const char Created[];
    static const char Modified[];
    static const char Deleted[];
    static const char Loaded[];
    static const char Undefined[];
  };
};

class ExportedByCATPLMIntegrationBase CATPLMItgBasePrivateToolbox
{
public:

  static HRESULT GetExtensionTypeId(  const CATString & iType,
                                      CATPLMTypeId & oTypeId );

  //static HRESULT GetExtensionTypeId(  const CATString & iModeler,
  //                                    const CATString & iType, 
  //                                    CATPLMTypeId & oTypeId );

  /**
 * Write the CEStamp of a PLM component in the record write. To use only in save context.
 * <br><b>Role : </b> This method indicates in the server input message the CEStamp handled by the PLM component in session. 
 * The comparison of this CEStamp and of the CEStamp of the PLM Component in DB allows to avoid concurrency engineering problems.
 * <br> This methods does anything in 2 cases:
 * <br> For a created PLM component :  The server will affect later a CEStamp to him.
 * <br> if the provider doesn't manage CEStamp. 
 * PROBLEME : For the moment, the adapter layer doesn't indicate to the engines if a provider manages CEStamps of not.
 * ---> Pb to judge if it is normal or an error 
 *      - if the TOS is not able to give CEStamp, 
 *   or - if the API used to write CEStamp in the server input message fails.
 * @param iComp
 *   The PLM component to describe in the server input msg.
 * @param  ipRecWrite 
 *   Is a CATIPLMCompRecordWrite or CATIPLMCompNewVersionRecordWrite pointer.  --> expected to adher also to CATIPLMSystemAttrWrite
 */
  static HRESULT WriteSessionCEStampInMsg(const CATComponentId &iComp, CATBaseUnknown * ipRecWrite);

 
 
/**
 * @nodoc
 */
  static HRESULT GetWorkspaceIdentifier( const CATProxySpace & iWorkspace, CATUnicodeString & oWorkspaceId );

/**
 * @nodoc
 */
  static HRESULT GetProxySpace( CATIPLMRecordRead * iRecord, CATProxySpace & oSpace );

/**
 * @nodoc
 * Checks in the workspace if the given CATComponentId is already opened in the session.
 * @param <tt>const CATComponentId & iCompId</tt>
 * [in] The reference component.
 * @return
 * <tt>HRESULT</tt>
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> The component is represented in the workspace (created, loaded, modified or deleted).
 * <dt> <tt>S_FALSE</tt>  <dd> The component is not represented in the workspace (waiting or unreferenced).
 * <dt> <tt>E_FAIL</tt>   <dd> Failure.
 * </dl>
 */
  static HRESULT IsLoadedInWorkspace( const CATComponentId & iCID );

/**
 * @nodoc
 * Checks in the workspace if the given component is seen as deleted in the provided workspace.
 * @param <tt>const CATPLMID & iPID</tt>
 * [in] The reference component.
 * @param <tt>const CATProxySpace & iSpace</tt>
 * [in] The reference workspace.
 * @return
 * <tt>HRESULT</tt>
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> The CEStamp is available
 * <dt> <tt>S_FALSE</tt>  <dd> The CEStamp is not available
 * <dt> <tt>E_FAIL</tt>   <dd> Failure.
 * </dl>
 */
  static HRESULT IsCEStampAvailableInWorkspace( const CATPLMID & iPID, const CATProxySpace & iSpace );

  static HRESULT GetCEStampFromMessage( CATIPLMRecordRead * iRecordRead, CATPLMCEStamp & oCEStamp );
  static HRESULT UpdateSessionCEStamp( const CATComponentId & iComponent, const CATPLMCEStamp & iStamp );

/**
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the component is currently available as activated or garbaged in the dataspace.</li>
 *   <li><code>S_FALSE</code> if it is not available (or workspace does not exist).</li>
 *   <li><code>E_FAIL</code> if a fatal error occured.</li>
 *   </ul>
 *
 */
  static HRESULT BindInDataspace( const CATPLMID & iComponent, const CATProxySpace & iDataspace,
                                  CATBoolean iReserveCell, CATComponentId & oRepCell );

  static HRESULT ConvertLogStatusToTransientStatus( const CATComponentIdStatus & iStatus, CATUnicodeString & oStatus );
  static HRESULT ConvertTransientStatusToDataSourceStatus( const CATUnicodeString & iStatus, CATPLMSessionDataSourceStatus & oStatus );
  
  /**
   * GetAttributeSet
   * @param oAttributeSet [out, CATBaseUnknown#Release]
   */
  static HRESULT GetAttributeSet( CATIPLMAttributeSet *& oAttributeSet );


  static HRESULT IsAMonoinstanciatedRep(const CATComponentId &iCompId);

  static HRESULT InsertStringAttributes( CATIPLMAttributeSet * iAttrSet,
      const CATListOfCATString & iAttributes, const CATListOfCATUnicodeString & iValues );
  static HRESULT InsertStringAttribute( CATIPLMAttributeSet * iAttrSet,
      const CATString & iAttributes, const CATUnicodeString & iValues );

  static HRESULT ConvertAttributes(CATOmxOHMap<CATPLMTypeH,CATOmxKeyValueBlock>::IteratorType &iKVB, CATIPLMAttributeSet* ioAttributeSet);
};
#endif
