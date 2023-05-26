#ifndef CATPLMLogModified_H
#define CATPLMLogModified_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2012
/**
 * @level Private
 * @usage U1
 */

#ifndef CATPLMLogModifiedCompatibility
#ifdef CATPLMDirtyService_H
 //meaningless values left for CATPLMDirtyService.cpp (useless debug code)
#define CATPLMLogModifiedCompatibility 1
#else
#define CATPLMLogModifiedCompatibility 0
#endif
#endif

/**
 * Definition of some specific Log Modification.
 */
enum CATPLMLogModified
{
  CATPLMLogModified_UserAttribute = 2, // modification of a PLM attribute

  CATPLMLogModified_Data = 12,     //meaningless, used in CATEPrdContextualLink::_InternalSetObject

  CATPLMLogModified_Relational = 16,
  CATPLMLogModified_Relational_UserSynch = 17,
  CATPLMLogModified_AuxiliaryExtensions = 18, //meaningless, used in CATEOsmExtendable::AddExtension

  CATPLMLogModified_StreamDescriptors = 21,
  CATPLMLogModified_Extensions = 22,
  CATPLMLogModified_Relational_BuildSpec = 23,
  CATPLMLogModified_Relational_Reidentified = 24

#if CATPLMLogModifiedCompatibility == 1
  ,
  CATPLMLogModified_Miscellaneous = 1, //meaningless
  CATPLMLogModified_Name = 3,
  CATPLMLogModified_Nomenclature = 4,
  CATPLMLogModified_Description = 5,
  CATPLMLogModified_Source = 6,
  CATPLMLogModified_Definition = 7,
  CATPLMLogModified_Responsible = 8,
  CATPLMLogModified_Version = 9,
  CATPLMLogModified_Move = 10,
  CATPLMLogModified_LifeCycle = 11,
  CATPLMLogModified_Link = 13,
  CATPLMLogModified_MasterStamp = 14,
  CATPLMLogModified_ReplaceReference = 15
#endif

};

#endif



