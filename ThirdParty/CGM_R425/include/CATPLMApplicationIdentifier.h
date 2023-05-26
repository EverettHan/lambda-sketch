/*
 * CATPLMApplicationIdentifier.h
 *
 *  Created on: Jan 8, 2015
 *      Author: pjq
 */

#ifndef CATPLMAPPLICATIONIDENTIFIER_H_
#define CATPLMAPPLICATIONIDENTIFIER_H_

// Prepare a migration from CATIPLMCompStatementService::ApplicationIdentifier to CATPLMApplicationIdentifier
#include "CATIPLMCompStatementService.h"
#define CATPLMApplicationIdentifier CATIPLMCompStatementService::ApplicationIdentifier
#define PLMAppId_Navigate       CATIPLMCompStatementService::AppId_Navigate
#define PLMAppId_UWPNav         CATIPLMCompStatementService::AppId_UWPNav
#define PLMAppId_Open           CATIPLMCompStatementService::AppId_Open
#define PLMAppId_CompletionOpen CATIPLMCompStatementService::AppId_CompletionOpen
#define PLMAppId_ExchangeStatus CATIPLMCompStatementService::AppId_ExchangeStatus
#define PLMAppId_Validate       CATIPLMCompStatementService::AppId_Validate

#endif /* CATPLMAPPLICATIONIDENTIFIER_H_ */
