/* -*-c++-*- */


/**
 * @level Private
 * @usage U1
 */

#ifndef CATPlmUtils_H
#define CATPlmUtils_H

// COPYRIGHT Dassault Systemes 2004

#include "CATSysMacros.h"
#include "CATPLMIntegrationBase.h"
#include "CATAssert.h"
#include "CATBaseUnknown.h"
#include "CATOmyAsserts.h"
#include "CATPLMTypeH.h"

#ifdef _WINDOWS_SOURCE
#ifndef snprintf
#define  snprintf _snprintf
#endif
#endif

class CATPLMTypeId;

/**
 * Ensemble de macros et fonctions de test et d'assertion utiles dans ce framework.
 */
class ExportedByCATPLMIntegrationBase CATPLMUtils
{
public:
  static void AssertionFailed  (const char * iTitle, const char * iFileName, const int iLn, const char * iMsg ="");
  static void AssertionFailedFACTO(const char *iFileName, const int iLn, const char * iMsg, const char *iFactoryClassName, const CATPLMTypeH & iPLMType);
};
#define LOG_FACTO_ABEND(iMsg, iFactoClassName, iType) CATPLMUtils::AssertionFailedFACTO(__FILE__, __LINE__, iMsg, iFactoClassName, iType)
#define LOG_ERROR( iMsg ) ON_ERROR( iMsg )
#endif
