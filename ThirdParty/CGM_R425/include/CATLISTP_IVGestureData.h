//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2020
//===================================================================

#ifndef CATLISTP_IVGestureData_H
#define CATLISTP_IVGestureData_H

// Declare the class
class IVGestureData;

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

// Include macros
#include "CATLISTP_Declare.h"      

#include "IVInterfaces.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByIVInterfaces

// Declare the collection class
CATLISTP_DECLARE(IVGestureData);

#endif
