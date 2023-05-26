/* -*-c++-*- */
#ifndef CATPLMUTXDumper_H
#define CATPLMUTXDumper_H
//
// CATIA Version 6 Release 208
// Copyright   : Dassault Systemes 2009
//-----------------------------------------------------------------------------
// Description :
// C++ class header file for the class named "CATPLMUTXDumper"
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Inheritance : CATPLMUTXDumper
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//
#include "CATBaseUnknown.h"
#include "CATPLMIntegrationInterfaces.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATOmxOrderedSet.h"
#include "CATOmxCollecManagers.h"
class CATUnicodeString;
class CATPLMID;

class ExportedByCATPLMIntegrationInterfaces CATPLMUTXDumper : public CATBaseUnknown
{
public:

  /**
   * Get an instance of the dumper.
   * @return
   *    the dumper.
   */
  static CATPLMUTXDumper& Get();

  virtual HRESULT SetDumpName(const CATUnicodeString& iDumpName) = 0;
  virtual HRESULT SetLevelManagement(CATBoolean iWithLevelMngt) = 0;
  virtual HRESULT SetAssertInOdt(CATBoolean iActivate = TRUE) = 0;
  virtual HRESULT AddPlmidReplacement(const CATPLMID& iPlmid, const CATUnicodeString& iReplacement) = 0;
  virtual HRESULT AddExcludedAttribute(const CATString& iAttributeId) = 0; // excluded attributes values are replaced by 'excluded' in the dump
  virtual HRESULT CleanOverloads() = 0; // removes all PlmidReplacements and ExcludedAttributes
  virtual int     Activate(int iNewActiveState) = 0; // returns old active state

  virtual HRESULT BeginDump(int iLevel = 1) = 0;
  virtual HRESULT Dump(CATBaseUnknown* iObject, int iLevel = 1) = 0;
  virtual HRESULT Dump(const CATOmxOrderedSet<CATBaseUnknown, cbu_manager>& iObjects, int iLevel = 1) = 0;
  virtual HRESULT Dump(CATListValCATBaseUnknown_var& iObjects, int iLevel = 1) = 0;
  virtual HRESULT EndDump() = 0;
};
#endif
