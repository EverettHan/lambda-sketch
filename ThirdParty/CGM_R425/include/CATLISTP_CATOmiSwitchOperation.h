/*
* @fullReview BES LED 05:04:11 Creation
*/
/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2005
//===================================================================


#ifndef CATLISTP_CATOmiSwitchOperations_H
#define CATLISTP_CATOmiSwitchOperations_H

/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004

/**
 * @level Protected 
 * @usage U1
 */

/**
 * @collection CATLISTP_CATOmiSwitchOperations
 * Collection class for pointers to @href CATOmiSwitchOperations
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>RemoveValue</tt</li>
 * <li><tt>RemoveAll</tt</li>
 * <li><tt>RemoveList</tt</li>
 * <li><tt>Locate</tt</li>
 * </ul> 
 * Refer to the articles dealing with collections in the encyclopedia.
 */

#include "CATOmiSwitchEngineItf.h"


#include "CATLISTP_Clean.h"
	
#define CATLISTP_Append
#define CATLISTP_AppendList
#define CATLISTP_RemoveAll
#define CATLISTP_RemoveValue
#define CATLISTP_RemoveList
#define CATLISTP_Locate

#include "CATLISTP_Declare.h"

class CATOmiSwitchOperation;

#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATOmiSwitchEngineItf

CATLISTP_DECLARE(CATOmiSwitchOperation)
typedef CATLISTP(CATOmiSwitchOperation) CATLISTP_CATOmiSwitchOperation;

#endif
