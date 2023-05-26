/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATLISTP_CATNavigInstance_H_
#define CATLISTP_CATNavigInstance_H_

// clean previous requests for extra functionalities :

/**
 * @level Private
 * @usage U1
 */

//   listes de CATNavigInstance
class CATNavigInstance;

#include  <CATLISTP_Clean.h>
// define symbols for extra functionalities :

#include "CATLISTP_PublicInterface.h"

// define macros CATLISTP_DECLARE :
#include  <CATLISTP_Declare.h>
// DECLARE All functions for class CATListPtrCATNavigInstance :
// (generate body of class)


#include  <CATOmnMain.h>
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATOmnMain


CATLISTP_DECLARE( CATNavigInstance )

typedef CATLISTP(CATNavigInstance) CATLISTP_CATNavigInstance;

#endif
