#ifndef CATPLMSessionCoarseMemoryStateKind_H
#define CATPLMSessionCoarseMemoryStateKind_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005

/**
 * @level Private
 * @usage U3
 */

 /**
 * Definition of the possible coarse memory states.
 * <tt> Possible values:</tt>
 * <dl>
 * @param <tt>CATPLMSessionCoarseMemoryStateKind_Undefined</tt>         <dd>Memory state is not defined.
 * @param <tt>CATPLMSessionCoarseMemoryStateKind_ToCreate</tt>          <dd>Newly created.
 * @param <tt>CATPLMSessionCoarseMemoryStateKind_ToOverride</tt>        <dd>Override committed component.
 * @param <tt>CATPLMSessionCoarseMemoryStateKind_ToDelete</tt>          <dd>To be Deleted.
 * @param <tt>CATPLMSessionCoarseMemoryStateKind_Unloaded</tt>          <dd>Unloaded.
 * </dl>
 */
#if ! defined ( CATPLMSessionCoarseMemoryStateKind_definition )
#define CATPLMSessionCoarseMemoryStateKind_definition
typedef unsigned int CATPLMSessionCoarseMemoryStateKind;
#endif

#define CATPLMSessionCoarseMemoryStateKind_Undefined                  0x00000000

#define CATPLMSessionCoarseMemoryStateKind_ToCreate                   0x00000001
#define CATPLMSessionCoarseMemoryStateKind_ToOverride                 0x00000002
#define CATPLMSessionCoarseMemoryStateKind_ToDelete                   0x00000004
#define CATPLMSessionCoarseMemoryStateKind_Unloaded                   0x00000008

#endif
