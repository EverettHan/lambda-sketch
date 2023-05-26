#ifndef CATPLMTypePatterns_H
#define CATPLMTypePatterns_H

#include "CATPLMTypeToolsDefinitions.h"

/***
 * A set of 'masks' to be used with CATPLMTypeProtectedDescriptor::IsMatchingCoreBehavior (or similar API with same 'semantics')
 * Notice the TYPTRP prefix is meaningless but used for coherency with CATPLMTypeToolsDefinitions
 */


 /** (IRPC) reference and rep reference */
static const int TYPTRP_References = TYPTRP_Reference | TYPTRP_RepReference;

/** (IRPC) instance and rep instance */
static const int TYPTRP_Instances = TYPTRP_Instance | TYPTRP_RepInstance;

/** (IRPC) instance, rep instance and (ER) relations*/
static const int TYPTRP_Relations = TYPTRP_Instances | TYPTRP_Relation;

/**
 * (IRPC) objects for which M1 compositional relationship is hidden
 * they appear in session with a from/V_Owner
 */
static const int TYPTRP_PortOrConnection = TYPTRP_Connection | TYPTRP_Port;

/**
* catch objects which have 'to' structural relation: instance, rep instance & relation
* Notice 'to' relation can be V_IsInstanceOf, to, torel...
*/
static const int TYPTRP_HasTo = TYPTRP_Relations;

/**
 * catch objects which have 'from' structural relation: instance, rep instance, relation, port & connection
 * Notice 'from' relation can be V_Owner, from, fromrel...
 */
static const int TYPTRP_HasFrom = TYPTRP_PortOrConnection | TYPTRP_Relations;

/**
 * The intent of this pattern is to catch (session) objects that 'really' handle streams: (IRPC) reps & (ER) entities.
 * Actually ports/connections might have a stream (CATLnk) but it is 'implementation detail' and as a consequence they are intentionally not caught by this mask
 */
static const int TYPTRP_HasStreams = TYPTRP_RepReference | TYPTRP_Entity;

/**
 * Not there on purpose (unprecise or meaningless as a relation can 'aggregate' relations)
 * Use alternatively:
 *  S_OK == IsMatchingCoreBehavior(~TYPTRP_HasFrom)
 *  S_OK != IsMatchingCoreBehavior(TYPTRP_HasFrom)
 */
#if 0
static const int TYPTRP_Aggregates = TYPTRP_Reference | TYPTRP_RepReference | TYPTRP_Entity;
#endif

/**
  * Not there on purpose (unprecise or meaningless): Use TYPTRP_HasFrom
  */
#if 0
static const int TYPTRP_HasSRs = TYPTRP_RepReference | TYPTRP_Port | TYPTRP_Connection | TYPTRP_Instance;
#endif

#endif
