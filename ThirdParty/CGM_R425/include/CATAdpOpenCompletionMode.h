// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATAdpOpenCompletionMode.h
// Header definition of CompletionMode enum
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Feb 2010  Creation: ECN
//===================================================================
/**
* @level Protected
* @usage U2
*/
#ifndef CATAdpOpenCompletionMode_H
#define CATAdpOpenCompletionMode_H

/**
 * Defines a mode of data completion for open services.
 * <br><b>Role:</b>Description of the available modes defining the type of components which will be retrieved through an expand 
 * request, together with the depth of expand query. Please, refer to @href CATPLMCoreType for semantical explanation on the types.
 * <dt> <code><b>Navigation</b></code>     <dd> Only the components defining the structure will be retrieved, i.e. references
 * (aka. PLMCoreReference) and instances (aka. PLMCoreInstance). Expand is recursive on all the structure under the root component.
 * <dt> <code><b>Authoring</b></code>      <dd> All the components will be retrieved, i.e. references (PLMCoreReference), 
 * instances (PLMCoreInstance), representation references (PLMCoreRepReference), representation instances 
 * (PLMCoreRepInstance), ports (PLMPort) and connections (PLMConnection). Expand is recursive on all the structure under the root component.
 * <dt> <code><b>ShortNavigation</b></code>     <dd> Only the components defining the structure on the first level will be retrieved, 
 * i.e. instances (aka. PLMCoreInstance) of the first level with their references (aka. PLMCoreReference).
 * <dt> <code><b>ShortBrowse</b></code>     <dd> Only the representations on the first level will be retrieved, 
 * i.e. representation instances (aka. PLMCoreRepInstance) of the first level with their representation references (aka. PLMCoreRepReference).
 * <dt> <code><b>ShortAuthoring</b></code>      <dd> All the components of first navigation level will be retrieved, i.e. references (PLMCoreReference), 
 * instances (PLMCoreInstance), representation references (PLMCoreRepReference), representation instances 
 * (PLMCoreRepInstance), ports (PLMPort) and connections (PLMConnection).
 * <dt> <code><b>ShortRelational</b></code>      <dd> Only the connexions (aka. PLMConnection) and 
 * ports (aka. PLMPort) on the first level will be retrieved, 
 */

namespace CATAdpOpenCompletionMode {
	enum CompletionMode { Navigation=0, Authoring=1, ShortNavigation=2, ShortBrowse=3, ShortAuthoring=4, ShortRelational=5 };
}

#endif
