/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMSessionDuplicateEngineToolbox_H
#define CATPLMSessionDuplicateEngineToolbox_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATErrorDef.h"

class CATIPLMEngineListener;
class CATIAdpErrorMonitorAbstract;
class CATIPLMSessionDuplicateEngine_var;

// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                  999
#define CATPLMIntegrationInterfaces       AuthorizedModule
#define CATPLMIdentification_PLM          AuthorizedModule
#define CATOmbDebugLink                   AuthorizedModule
#define CATComponentsFamily               AuthorizedModule
#define CATPLMClientCoreModel             AuthorizedModule
#define CATPCCOOD                         AuthorizedModule
#define PLMUICommands                     AuthorizedModule
#define SWXToolbox                        AuthorizedModule
#define CATPLMTemplates                   AuthorizedModule
#define SWXAsProductStructure             AuthorizedModule
#define CATMRCModel                       AuthorizedModule // JBB, 20171115
#define CATFmtToolsServices               AuthorizedModule // JBB, 20171124
#define CATKinMechUI                      AuthorizedModule // JBB, 20180313 - FUN073672, CRX
#define CATPrdPccModelRep                 AuthorizedModule // RSR7 - FUN083237
#define DELPLMProSysServices              AuthorizedModule // JBB, 20190339, NNU
#define CATSddModelServices               AuthorizedModule // JBB, 20191029, SDD Fasteners, EWN
#define DELPLMFunctionModelImpl           AuthorizedModule 
#define MOTMechFactory                    AuthorizedModule // JBB, 20210311, IR-790794-3DEXPERIENCER2021x, WEZ - removal of CATMechanism, replaced by subcomponent of FEMRep
#define MOTSimulationModel                AuthorizedModule // JBB, 20221209, IR-905502-3DEXPERIENCER2022x, duplication des SIMObjSimulationObjectGeneric 
#define CATSchematicModelServices         AuthorizedModule // JBB, 20221216, IR-907175-3DEXPERIENCER2021x, duplication of Piping, HVAC, Electrical logical references when compatible with restrictions.
#define CATPLMSpecsModelerTestLib         AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATPLMSessionDuplicateEngineToolbox from non-infrastructure module
#endif
#undef CATPLMIntegrationInterfaces
#undef CATPLMIdentification_PLM
#undef CATOmbDebugLink
#undef CATComponentsFamily
#undef CATPLMClientCoreModel
#undef CATPCCOOD
#undef PLMUICommands
#undef SWXToolbox
#undef CATPLMTemplates
#undef SWXAsProductStructure
#undef CATMRCModel
#undef CATFmtToolsServices
#undef CATKinMechUI
#undef CATPrdPccModelRep
#undef DELPLMProSysServices
#undef CATSddModelServices
#undef DELPLMFunctionModelImpl
#undef MOTMechFactory
#undef MOTSimulationModel
#undef CATSchematicModelServices
#undef CATPLMSpecsModelerTestLib
// ----------------------------------------------------------------------------------------------------------------------

/**
 * Class to access private integration engines
 *<br><b>Role</b>: Thanks to its static method, you can access to the session duplicate engine.
 */
class ExportedByCATPLMIntegrationInterfaces CATPLMSessionDuplicateEngineToolbox
{
public:

  /**
  * Gets duplicate engine.
  * @param oSessionDuplicateEngine
  *   The duplicate engine.
  * @param ioErrorMonitor [inout]
  *   The ErrorMonitor that collects all eventual errors happening during duplicate process
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  static HRESULT GetSessionDuplicateEngine(CATIPLMSessionDuplicateEngine_var & oSessionDuplicateEngine, CATIAdpErrorMonitorAbstract * ioErrorMonitor = 0);
};
#endif
