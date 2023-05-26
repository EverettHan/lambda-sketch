/** WARNING: YWE 14:12:17 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATListPtrCATCheckRule_H_
#define CATListPtrCATCheckRule_H_
/** @level Protected 
* @usage U1
*/

class CATCheckRule;

#include  "CATLISTP_Clean.h"

#include "CATLISTP_PublicInterface.h"

#include  "CATLISTP_Declare.h"

#define	CATLISTP_AppendList



#include "ExportedByCATClnBase.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATClnBase


CATLISTP_DECLARE( CATCheckRule )

typedef CATLISTP(CATCheckRule) CATLISTP_CATCheckRule;

#endif
