// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMKeepAttributes.h
// Header definition of CATPLMKeepAttributes enum
//
//===================================================================
//
// Usage notes: Use with operator|
//
//===================================================================
//
//  June 2009  Creation: ZUP
//===================================================================
/**
* @level Protected
* @usage U2
*/
#ifndef CATPLMKeepAttributes_H
#define CATPLMKeepAttributes_H

/**
 * Attributes which can be kept when copying.
 * It's used as a bitmask, it's possible to keep multiple attributes using | operator.
 * <dt> <code> ReferenceNoReset </code> <dd> Attributes which can be kept for references </dd> </dt>
 * <dt> <code> ReferenceNoReset::REF_KEEP_NOTHING </code> <dd> Reinitialise every attributes (default) </dd> </dt>
 * <dt> <code> ReferenceNoReset::REF_KEEP_OWNERSHIP </code> <dd> Don't reinitialise ownership </dd> </dt>
 * <dt> <code> ReferenceNoReset::REF_KEEP_LOCK </code> <dd> Don't reinitialise lock </dd> </dt>
 * <dt> <code> ReferenceNoReset::REF_KEEP_MATURITY </code> <dd> Don't reinitialise maturity </dd> </dt>
 * <dt> <code> ReferenceNoReset::REF_KEEP_VERSIONING </code> <dd> Don't reinitialise versionning </dd> </dt>
 * <dt> <code> ReferenceNoReset::REF_KEEP_ORGANIZATION </code> <dd> Don't reinitialise organization (available starting from R418) </dd> </dt>
 * <dt> <code> ReferenceNoReset::REF_KEEP_PROJECT </code> <dd> Don't reinitialise project (available starting from R418) </dd> </dt>
 * <dt> <code> InstanceNoReset </code> <dd> Attributes which can be kept for instances </dd> </dt>
 * <dt> <code> InstanceNoReset::REF_KEEP_NOTHING </code> <dd> Reinitialise every attributes (default) </dd> </dt>
 * <dt> <code> InstanceNoReset::REF_KEEP_OWNERSHIP </code> <dd> Don't reinitialise ownership </dd> </dt>
 * <dt> <code> InstanceNoReset::REF_KEEP_LOCK </code> <dd> Don't reinitialise lock </dd> </dt>
 * <dt> <code> InstanceNoReset::INST_KEEP_ORGANIZATION </code> <dd> Don't reinitialise organization (available starting from R418) </dd> </dt>
 * <dt> <code> InstanceNoReset::INST_KEEP_PROJECT </code> <dd> Don't reinitialise project (available starting from R418) </dd> </dt>
 **/

namespace CATPLMKeepAttributes {

enum ReferenceNoReset
{
  REF_KEEP_NOTHING    =    0,
  REF_KEEP_OWNERSHIP  = 1<<0,
  REF_KEEP_LOCK       = 1<<1,
  REF_KEEP_MATURITY   = 1<<2,
  REF_KEEP_VERSIONING = 1<<3,
  REF_KEEP_ORGANIZATION = 1<<4, // Available starting from R418
  REF_KEEP_PROJECT    = 1<<5  // Available starting from R418
};

enum InstanceNoReset
{
  INST_KEEP_NOTHING    =    0,
  INST_KEEP_OWNERSHIP  = 1<<0,
  INST_KEEP_LOCK       = 1<<1,
  INST_KEEP_ORGANIZATION = 1<<4,  // Available starting from R418
  INST_KEEP_PROJECT    = 1<<5 // Available starting from R418
};
  
inline ReferenceNoReset operator|(const ReferenceNoReset& a,const ReferenceNoReset& b)
{
  return ReferenceNoReset((int)a | (int)b);
}
  
inline InstanceNoReset operator|(const InstanceNoReset& a,const InstanceNoReset& b)
{
  return InstanceNoReset((int)a | (int)b);
}
}

#endif
