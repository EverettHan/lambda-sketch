//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2020
//===================================================================

#ifndef CATLISTP_IVGestureRecognizer_H
#define CATLISTP_IVGestureRecognizer_H

// Declare the class
class IVGestureRecognizer;

// Clean previous method requests
#include "CATLISTP_Clean.h"


// Request the methods to create
#define CATLISTP_Append
#define	CATLISTP_AppendList
#define	CATLISTP_InsertAt

#define	CATLISTP_RemovePosition
#define CATLISTP_RemoveValue
#define	CATLISTP_RemoveAll
#define	CATLISTP_RemoveList

#define	CATLISTP_Locate

#include "IVInterfaces.h"    
// Include macros
#include "CATLISTP_Declare.h"      

#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByIVInterfaces

// Declare the collection class
CATLISTP_DECLARE(IVGestureRecognizer);


#endif
