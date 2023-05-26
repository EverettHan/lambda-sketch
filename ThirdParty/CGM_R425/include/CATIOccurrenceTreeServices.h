// COPYRIGHT Dassault Systemes 2015
#ifndef CATIOccurrenceTreeServices_H
#define CATIOccurrenceTreeServices_H

/**
* @level Private
* @usage U3
*/

#include "CATBaseUnknown.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATLISTV_CATPLMID.h"
#include "CATOmxSharable.h"
#include "ExportedByCATPLMTos.h"
#include "CATOmxSR.h"
class CATIPLMSpace;
class CATIPLMNavOccurrence;
class CATPLMOccurrenceWrapper;
class CATIPLMNavOccurrence_var;
class CATListValCATBaseUnknown_var;

/**
 * internal protocol meant to be called by integration in order to create occurrence tree
 */
class CATIOccurrenceTreeServices
{
public:
  ExportedByCATPLMTos static CATIOccurrenceTreeServices& Get();
  /**
   * documentation is for pussies
   */
  virtual HRESULT GetRootOccurrence(const CATBaseUnknown_var& iRootReference, CATIPLMNavOccurrence_var& oRootOcc, CATBoolean iForLightNav) = 0;
  virtual HRESULT BeginBuildOccurrences(const CATIPLMNavOccurrence_var& iRootOccurrence, int iDelta) = 0;
  virtual HRESULT EndBuildOccurrences(const CATIPLMNavOccurrence_var& iRootOccurrence, CATBoolean iForceEventDispatch) = 0;
  virtual HRESULT BeginExplicitFilter(const CATIPLMNavOccurrence_var& iRootOccurrence, const CATIPLMNavOccurrence_var& iFilteredRootOccurrence, CATBoolean iKeepTrailingPath) = 0;
  virtual HRESULT AppendInExplicitFilter(const CATIPLMNavOccurrence_var& iRootOccurrence, const CATPLMOccurrenceWrapper& iOccurrence) = 0;
  virtual HRESULT EndExplicitFilter(const CATIPLMNavOccurrence_var& iRootOccurrence) = 0;
  virtual HRESULT RetrieveOccurrence(const CATIPLMNavOccurrence_var& iRootOccurrence, const CATListValCATBaseUnknown_var& iPOFI, CATIPLMNavOccurrence_var& oOccurrence) = 0;
  virtual HRESULT GetOccurrence(CATBaseUnknown* iRootOccurrence, const CATListValCATBaseUnknown_var& iPOFI, CATPLMOccurrenceWrapper& oOccurrence) = 0;
  virtual void ReleaseContext(CATIPLMNavOccurrence* iRootOccurrence) = 0;
  virtual HRESULT BuildOccurrences(CATBaseUnknown * iRootComponent, CATListValCATPLMID& iOccurrencePaths, CATIPLMSpace * iDataSpace, const CATIPLMNavOccurrence * iExistingRootOcc, CATIPLMNavOccurrence ** oNewRootOcc) = 0;


  struct ExplicitOccurrencesSnapshot : public CATOmxSharable
  {
    virtual void RestoreAfterReload() = 0;
  };

  virtual CATOmxSR<ExplicitOccurrencesSnapshot> CaptureExplicitOccurrencesBeforeReload(const CATOmxList<CATBaseUnknown>& instances) const = 0;

  virtual void DestroyTree(CATBaseUnknown* iRootOccurrence) const = 0;

};

#endif
