//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010/06/17
//===================================================================
// CATPLMImportInputOutputSingleton.h
// Header definition of class CATPLMImportInputOutputSingleton
//===================================================================
//
// Usage notes:
// class implemented as part of Project:
// Ability to import a 3DXML for review in V6 session using a specific provider called Psp.
// (Psp like Provider Session)
//
// class specification:
// Ability to create the singleton CATPLMImportInputOutput that implements interface CATIPLMImportInputOutput
//
//===================================================================
//  2010/06/17 Creation: EPB
//===================================================================

/**
 * @level Protected
 * @usage U1
 */

#ifndef CATPLMImportInputOutputSingleton_H
#define CATPLMImportInputOutputSingleton_H

#include "CATPLMIntegrationInterfaces.h" // ExportedByCATPLMIntegration

#include "CATBaseUnknown_WR.h"           // System PublicInterfaces JS0CORBA.m JS0GROUP.dll

#include "CATSysBoolean.h"               // System PublicInterfaces
#include "CATIAV5Level.h"

class CATIPLMImportInputOutput_var;

class ExportedByCATPLMIntegrationInterfaces CATPLMImportInputOutputSingleton
{
  friend class CATPLMTETransaction;
  friend class CATPLMSessionPopulate;
  friend class CAT3DXMLRevImportUI; // Replaced by PLMEImport3DXMLReviewCustomization
  friend class PLMEImport3DXMLReviewCustomization;
  friend class CATPLMPspDXPImporter;
  friend class CATPLMComponentServicesBuilder;
  friend class TstCATPLMPspImportCoverage;
  friend class CAT3DXMLMap;
  friend class CAT3DXMLRevImportUI; // Replaced by PLMEImport3DXMLReviewCustomization
  friend class ImportPLMBriefcaseBatchImpl;

private:

  CATPLMImportInputOutputSingleton();
  ~CATPLMImportInputOutputSingleton();


  /**
  *
  * <br><b>Role</b>:
  * @param ospiImport
  *        create an instance of CATIPLMImportInputOutput
  * @return
  * <dl>
  * <dt><code>E_INVALIDARG</code>if ospiImport != NULL_var<dd>
  * <dt><code>S_OK</code>ospiImport already exists<dd>
  * <dt><code>E_FAIL</code>if an instance of ospiImport already exists, for sure you have a leak<dd>
  * </dl>
  */
  HRESULT CreateInstance(CATIPLMImportInputOutput_var & ospiImport);


  /**
  *
  * <br><b>Role</b>:
  * @param ospiImport
  *        retrieve the singleton.
  * @return
  * <dl>
  * <dt><code>E_INVALIDARG</code>if ospiImport != NULL_var<dd>
  * <dt><code>S_OK</code>ospiImport!=NULL_var, you are in a import of 3DXML transaction<dd>
  * <dt><code>S_FALSE</code>ospiImport==NULL_var,no instance of the singleton has been found, you are not in a import of 3DXML transaction<dd>
  * </dl>
  */
  HRESULT GetInstance(CATIPLMImportInputOutput_var & ospiImport);

  /**
  *
  * <br><b>Role</b>:
  * @return
  *    TRUE  : import using session loaded.
  *    FALSE : import using session not loaded.
  */
  CATBoolean IsImportUsingSessionActivated();

  static CATBaseUnknown_WR _pWR;
};

#endif
