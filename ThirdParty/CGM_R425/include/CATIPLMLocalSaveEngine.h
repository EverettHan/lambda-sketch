/* -*-c++-*- */

/**
 * @level Protected
 * @usage U3
 */

#ifndef CATIPLMLocalSaveEngine_h
#define CATIPLMLocalSaveEngine_h

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMLocalSaveEngine;
#else
extern "C" const IID IID_CATIPLMLocalSaveEngine ;
#endif

#define AuthorizedModule     999

#define CATPLMIntegrationAccess  AuthorizedModule
#define CATPLMIntegrationAccessBase  AuthorizedModule
#define CATPLMItgTestLocalSave  AuthorizedModule
#define CATPLMItgOfflineTests  AuthorizedModule
#define CATMaintenanceIntegrationTest  AuthorizedModule
#define CATPLMIntegrationInterfaces  AuthorizedModule
#define CATPLMLocalSaveBase  AuthorizedModule
#define CATBackUpSessionUI           AuthorizedModule        // VPMNav
#define CATBusManager                AuthorizedModule        // VPMNav
#define CATPLMIntegration            AuthorizedModule
#define CATPLMSessionImages          AuthorizedModule        
#define SessionImage                 AuthorizedModule        // CATPLMSessionDebug
#define CATPLMSessionImageManagerTest AuthorizedModule       // odt
#define CATPLMIdentification_PLM  AuthorizedModule           // odt TOS
#define PerfStreamContainers      AuthorizedModule           // odt perfo
#define CATOmbLifeCycle           AuthorizedModule
#define CATLSWebServerManager  AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else
      #error Forbidden Access to CATIPLMLocalSaveEngine Interface
      @error
#endif

#undef CATPLMIntegrationInterfaces
#undef CATPLMLocalSaveBase
#undef CATBackUpSessionUI
#undef CATBusManager
#undef CATPLMIntegration
#undef CATPLMSessionImages
#undef SessionImage
#undef CATPLMSessionImageManagerTest
#undef CATPLMIdentification_PLM
#undef PerfStreamContainers
#undef CATMaintenanceIntegrationTest
#undef CATOmbLifeCycle
#undef CATPLMItgTestLocalSave
#undef CATPLMIntegrationAccess
#undef CATPLMIntegrationAccessBase
#undef CATPLMItgOfflineTests
#undef CATLSWebServerManager

/**
 * This interface is the external view of the LocalSave Engine
 * It describes how the LocalSaveEngine has to be used by its client.
 * The LocalSaveEngine performs a photo of the session on a local provider.
 *
 * The toolbox CATPLMEngineToolbox exposes static method giving acces to the LocalSave engine.
 */


#define S_CANCELED    ((HRESULT)0x00000033L)

class ExportedByCATPLMIntegrationInterfaces CATIPLMLocalSaveEngine: public CATBaseUnknown
{
  CATDeclareInterface;
 public :

  enum LocalSaveMode{ForAutoBackupIntent,
                     ForManualBackupIntent};


  /**
   * Processes a LocalSave transaction
   * @param iMode [in] with ForAutoBackupIntent, the localsave image will be overwrittent by the next LocalSave
   *                   with ForManualBackupIntent, the localsave image will be kept and could be restore.
   * @return
   *     S_OK The LocalSave process succeeded
   *     S_FALSE The LocalSave process has generated a non usable image
   *     S_CANCELED The LocalSave process has been canceled by an external event (by the listener for instance)
   *     E_FAIL The localsave process failed or did not complete successfully
   * @see CATPLMEngineToolbox, CATIPLMEngineListener
   */


  virtual HRESULT LocalSave(const LocalSaveMode iMode=ForAutoBackupIntent) = 0;

};
CATDeclareHandler(CATIPLMLocalSaveEngine, CATBaseUnknown);


#endif
