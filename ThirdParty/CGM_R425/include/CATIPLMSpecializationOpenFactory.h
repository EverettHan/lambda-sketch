/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMSpecializationOpenFactory_H
#define CATIPLMSpecializationOpenFactory_H

#include "CATIPLMOpenFactory.h"

/** dead protocol */
class CATIPLMSpecializationOpenFactory : public CATBaseUnknown
{
  CATDeclareInterface;
};
const IID IID_CATIPLMSpecializationOpenFactory = { 0xdb402889, 0x832f, 0x4eb9, { 0xb7, 0xb6, 0x44, 0x38, 0x4c, 0x8b, 0x58, 0x7d} };
CATImplementInterface(CATIPLMSpecializationOpenFactory, CATBaseUnknown);

#endif
