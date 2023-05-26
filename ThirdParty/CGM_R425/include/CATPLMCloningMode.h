// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMCloningMode.h
// Header definition of CATPLMCloningMode enum
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  May 2004  Creation: ZUP
//===================================================================
/**
* @level Protected
* @usage U2
*/
#ifndef CATPLMCloningMode_H
#define CATPLMCloningMode_H

/**
 * Description of the two modes for new version.
 * <dt> <code>Classical</code>                              <dd> The default use mode.
 * <ul>
 * <li> The operation will concern a cloning of component.</li>
 * <li> The current component in client session is not changed. No modification is performed in the authoring session.</li>
 * </ul>
 * <dt> <code>Classical_WithSessionModification</code>      <dd> The new component is going to be used in the current authoring session instead of the cloned component.
 * <ul>
 * <li> The operation will concern a cloning of component.</li>
 * <li> It results as a destruction of the instance of the cloned component in the session.</li>
 * <li> It results as a creation of an instance of the new component in the session and its aggregation under the owner of the old component.</li>
 * <li> These operations will be propagated to the server on next @href CATIPLMSaveEngine#Save call.</li> 
 * </ul>
 * <dt> <code>KeepFamily</code>                             <dd> Advanced use.
 * <ul>
 * <li> The operation will concern a cloning of component keeping its logical family.</li>
 * <li> It means that the new component will be seen as familiarly linked to the cloned component.</li>
 * <li> The current component in client session is not changed. No modification is performed in the authoring session.</li>
 * </ul>
 * <dt> <code>KeepFamily_WithSessionModification</code>     <dd> Advanced use.
 * <ul>
 * <li> The operation will concern a cloning of component keeping its logical family.</li>
 * <li> It means that the new component will be seen as familiarly linked to the cloned component.</li>
 * <li> It results as a destruction of the instance of the cloned component in the session.</li>
 * <li> It results as a creation of an instance of the new component in the session and its aggregation under the owner of the old component.</li>
 * <li> These operations will be propagated to the server on next @href CATIPLMSaveEngine#Save call.</li> 
 * <dt> <code>Classical_WithSessionModification</code>      <dd> The new component is going to be used in the current authoring session instead of the cloned component.
 * </ul>
 * <dt> <code>KeepFamily_TransferModifications</code>
 * <ul>
 * <li> The operation will keep the original component and the cloned component in session.</li>
 * <li> It results as a destruction of the instance of the cloned component in the session.</li>
 * <li> It results as a creation of an instance of the new component in the session and its aggregation under the owner of the old component.</li>
 * <li> These operations will be propagated to the server on next @href CATIPLMSaveEngine#Save call.</li>
  * </ul>
 */
namespace CATPLMCloningMode {
	enum CloningMode { Classical=0, Classical_WithSessionModification=1,
                     KeepFamily=2, KeepFamily_WithSessionModification=3,
                     Classical_TransferModifications,
                     KeepFamily_TransferModifications
                     };
}

#endif
