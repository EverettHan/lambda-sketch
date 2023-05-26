#ifndef _CATPLMPersistentUnitBindingMode_H
#define _CATPLMPersistentUnitBindingMode_H

/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005

/**
 * @level Private
 * @usage U3
 */

 /**
 * Definition of the possible binding modes.
 * <tt> Possible values:</tt>
 * <dl>
 * @param <tt>CATPLMPersistentUnitBindedToCATDocument</tt>     <dd>Bound to document model. It means that the life cycle of persistent unit contents is linked to document (e.g. : PS1 old data model).
 * @param <tt>CATPLMPersistentUnitBindedToPLMOwner</tt>        <dd>Bound to component model.It means that the life cycle of persistent unit contents is linked to reference owner.
 * @param <tt>CATPLMPersistentUnitBindedToPLMComponent</tt>    <dd>Bound to component model.It means that the persistent unit is linked to component. No deletions support.
 * </dl>
 */
enum CATPLMPersistentUnitBindingMode
{
  CATPLMPersistentUnitBindedToCATDocument,
  CATPLMPersistentUnitBindedToPLMOwner,
  CATPLMPersistentUnitBindedToPLMComponent
};

#endif
