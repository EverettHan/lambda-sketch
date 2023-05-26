#ifndef CATScriptDefs_h
#define CATScriptDefs_h

// COPYRIGHT DASSAULT SYSTEMES 2001

/**
 * CAT_NEW_SCRIPTING_BT is a deprecated build-time flag
 */
#define CAT_NEW_SCRIPTING_BT

#include "CATBoolean.h"
#include "AutomationItf.h"

/**
 * Determines if the CAT_NEW_SCRIPTING_RT has been exported.
 */
CATBoolean ExportedByCATAutoItf CATNewScriptingActivated();

/**
 * Determines if the CAT_SCRIPT_JAVA_ENABLED has been exported.
 */
CATBoolean ExportedByCATAutoItf CATJavaScriptingActivated();

/**
 * Determines if the runtime infrastructure is invoked from mkodt.
 */
CATBoolean ExportedByCATAutoItf CATScriptIsInMkodt();

/**
 * Determines if the CAT_SCRIPT_RMI_ENABLED has been exported.
 */
CATBoolean ExportedByCATAutoItf CATScriptRMIActivated();

/**
 * Determines if the CATMacroSecuritySystem has been exported.
 */
CATBoolean ExportedByCATAutoItf CATScriptSecurityActivated();

/**
 * Determines if the Automation infrastructure is activated or not.
 */
CATBoolean ExportedByCATAutoItf CATAutomationActivated();

// + qay VSTA Integration
/**
 * Determines if VSTA support is activated or not.
 */
CATBoolean ExportedByCATAutoItf CATVSTAActivated();
// end + qay
// ++IK8: since VSTA 2013, the IDE is optional
CATBoolean ExportedByCATAutoItf CATVSTAIDEAvailable();

// + jbx : file factorization 
/**
 * Determines if embeded macros are activated or not.
 */
CATBoolean ExportedByCATAutoItf CATEmbededMacrosActivated();

/**
 * Determines if macros on files are activated or not.
 */
CATBoolean ExportedByCATAutoItf CATMacroFilesActivated();

/**
 * Determines if macros in PLM representation are activated or not.
 */
CATBoolean ExportedByCATAutoItf CATPLMMacrosActivated();

/**
 * Determines if journaling in macros is activated or not.
 */
CATBoolean ExportedByCATAutoItf CATJournalingActivated();

// end + jbx

#endif // CATScriptDefs_h
