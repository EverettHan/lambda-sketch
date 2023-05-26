#ifndef _CATPLMCoreTypeFilter_H
#define _CATPLMCoreTypeFilter_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2009

/**
 * @level Private
 * @usage U3
 */

 /**
 * Filtering on CoreType.
 *
 * <tt> Possible values:</tt>
 * <dl>
 * @param <tt>CATPLMCoreTypeFilter_NONE</tt>                 <dd>no core types.
 * @param <tt>CATPLMCoreTypeFilter_ALL</tt>                  <dd>All core types.
 * @param <tt>CATPLMCoreTypeFilter_PLMCoreReference</tt>     <dd>filtering references.
 * @param <tt>CATPLMCoreTypeFilter_PLMCoreInstance</tt>      <dd>filtering instances.
 * @param <tt>CATPLMCoreTypeFilter_PLMCoreRepReference</tt>  <dd>filtering representation references.
 * @param <tt>CATPLMCoreTypeFilter_PLMCoreRepInstance</tt>   <dd>filtering representation instances.
 * @param <tt>CATPLMCoreTypeFilter_PLMConnection</tt>        <dd>filtering representation instances.
 * @param <tt>CATPLMCoreTypeFilter_PLMPort</tt>              <dd>filtering representation instances.
 * </dl>
 */
typedef unsigned int CATPLMCoreTypeFilter;

#define CATPLMCoreTypeFilter_Cardinality          6
#define CATPLMCoreTypeFilter_NONE                 0x00000000
#define CATPLMCoreTypeFilter_ALL                  0xFFFFFFFF
#define CATPLMCoreTypeFilter_PLMCoreReference     0x00000001
#define CATPLMCoreTypeFilter_PLMCoreInstance      0x00000002
#define CATPLMCoreTypeFilter_PLMCoreRepReference  0x00000004
#define CATPLMCoreTypeFilter_PLMCoreRepInstance   0x00000008
#define CATPLMCoreTypeFilter_PLMConnection        0x00000010
#define CATPLMCoreTypeFilter_PLMPort              0x00000020

#endif
