/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMSpecializationSaveFactory_H
#define CATIPLMSpecializationSaveFactory_H

#include "CATIPLMSaveFactory.h"
class CATPLMTypeId;
class CATIPLMSaveFactoryServices;

/** dead protocol */
class CATIPLMSpecializationSaveFactory : public CATBaseUnknown
{
  CATDeclareInterface;
};

const IID IID_CATIPLMSpecializationSaveFactory = { 0xf3024060, 0x665a, 0x4dff, { 0x84, 0xb4, 0xe7, 0xa9, 0x44, 0x32, 0xb3, 0xdb} };
CATImplementInterface(CATIPLMSpecializationSaveFactory, CATBaseUnknown);

#endif

