/* -*-c++-*- */
#ifndef CATLISTV_CATIPLMComponent_H
#define CATLISTV_CATIPLMComponent_H
// COPYRIGHT DASSAULT SYSTEMES 2006
//===================================================================
//
//  jan 2006  Creation: ECN
//
//===================================================================
/**
* @CAA2Level L1
* @CAA2Usage U1
*/

#include "CATIPLMComponent.h"
#include "CATPLMIdentificationAccess.h"

// Clean previous functions requests
#include "CATLISTV_Clean.h"

/**
 * @collection CATLISTV_CATIPLMComponent
 * Collection class for pointers to @href CATIPLMComponent.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>AppendList</tt></li>
 * <li><tt>RemoveValue</tt</li>
 * <li><tt>RemovePosition</tt</li>
 * <li><tt>InsertAt</tt</li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */
// Require needed functions
#define CATLISTV_Append
#define CATLISTV_AppendList
#define CATLISTV_RemoveValue
#define CATLISTV_RemovePosition
#define CATLISTV_InsertAt
#define CATLISTV_Replace

// Get macros
#include "CATLISTV_Declare.h"

// Generate interface of collection-class
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATPLMIdentificationAccess

CATLISTV_DECLARE( CATIPLMComponent_var )

typedef CATLISTV( CATIPLMComponent_var ) CATIPLMComponents;

#endif

