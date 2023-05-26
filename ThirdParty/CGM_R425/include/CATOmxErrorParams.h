#ifndef __CATOmxErrorParams_H
#define __CATOmxErrorParams_H

#include "CATOmxKernel.h"
#include "CATError.h"
#include "CATOmxArray.h"
#include "CATUnicodeString.h"
#include "CATOmxPortability.h"

/**
 * class allowing to hold the different parameters a CATError can hold:
 *   - classical message parameters
 *   - compound messages parameters:
 *      Request
 *      Diagnostic
 *      Advice
 * and to set them on a CATError
 */
struct CATOmxErrorParams
{
  /**various parameters*/
  CATOmxArray<CATUnicodeString> Params,RequestParams,DiagnosticParams,AdviceParams;

  /**Add a parameter to the appropriate parameter list*/
  inline CATOmxErrorParams& AddParam(const CATUnicodeString& iParam) {Params.Append(iParam);return *this;}
  inline CATOmxErrorParams& AddRequestParam(const CATUnicodeString& iParam) {RequestParams.Append(iParam);return *this;}
  inline CATOmxErrorParams& AddDiagnosticParam(const CATUnicodeString& iParam) {DiagnosticParams.Append(iParam);return *this;}
  inline CATOmxErrorParams& AddAdviceParam(const CATUnicodeString& iParam) {AdviceParams.Append(iParam);return *this;}

  /**assign parameters to a CATError*/
  ExportedByCATOmxKernel CATError& AssignToError(CATError& iError);

#if OMX_CODE_PHASE == 2
  /**Extract CATError NLS parameters*/
  ExportedByCATOmxKernel CATOmxErrorParams& ExtractFromError(const CATError& iError);
#endif
};

#endif
