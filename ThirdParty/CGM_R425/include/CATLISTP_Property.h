/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATLISTP_Property_H_
#define CATLISTP_Property_H_


//   listes de Property
struct Property;

// clean previous requests for extra functionalities :
#include  "CATLISTP_Clean.h"

#include "CATLISTP_PublicInterface.h"

// define macros CATLISTP_DECLARE :
#include  "CATLISTP_Declare.h"
// DECLARE All functions for class CATListPtrProperty :
// (generate body of class)


#include  "ON0PROP.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByON0PROP


CATLISTP_DECLARE( Property )

typedef CATLISTP(Property) CATLISTP_Property;

#endif
