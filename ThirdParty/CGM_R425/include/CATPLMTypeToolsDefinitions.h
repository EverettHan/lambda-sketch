/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMTypeToolsDefinitions_H
#define CATPLMTypeToolsDefinitions_H


namespace CATPLMTypeDescriptorDefs
{
  enum DSModelerQualifier { mqUndefined = 0, mqFirst = 1, mqTop = 2 };
}

namespace CATPLMTypeBehaviorDefs
{
  enum PLMTypeRankingOperation { SaveOperation = 0, OpenOperation = 1 };
  enum PLMTypeFacet { Composed = 0, Compositional = 1 };
}

// PRIVATE USE ONLY.
static const int TYPTRP_None = 0x00;  // 00000000
static const int TYPTRP_Reference = 0x01;  // 00000001
static const int TYPTRP_RepReference = 0x02;  // 00000010
static const int TYPTRP_Entity = 0x04;  // 00000100
static const int TYPTRP_Relation = 0x08;  // 00001000
static const int TYPTRP_Instance = 0x10;  // 00010000
static const int TYPTRP_RepInstance = 0x20;  // 00100000
static const int TYPTRP_Connection = 0x40;  // 01000000
static const int TYPTRP_Port = 0x80;  // 10000000
static const int TYPTRP_Component = 0xff;  // 11111111
static const int TYPTRP_IRPCComponent = 0xf3;  // 11110011
static const int TYPTRP_ERComponent = 0xC;   // 00001100

#endif
