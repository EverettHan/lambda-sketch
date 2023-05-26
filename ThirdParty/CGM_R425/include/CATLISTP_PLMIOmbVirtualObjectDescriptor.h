// COPYRIGHT DASSAULT SYSTEMES 2010

/**
 * @collection CATLISTP(PLMIOmbVirtualObjectDescriptor)
 * Collection class for pointers to <tt>PLMIOmbVirtualObjectDescriptor</tt>.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>Append</tt></li>
 * <li><tt>RemoveValue</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * <li><tt>Locate</tt></li>
 * </ul>
 *
 * @see PLMIOmbVirtualObjectDescriptor
 */

#ifndef CATLISTP_PLMIOmbVirtualObjectDescriptor_H_
#define CATLISTP_PLMIOmbVirtualObjectDescriptor_H_

class PLMIOmbVirtualObjectDescriptor;

#include "CATObjectModelerBase.h"
// --------------------------------------------------------------------------
//                       Clean previous functions requests
// --------------------------------------------------------------------------

#include  "CATLISTP_Clean.h"

// --------------------------------------------------------------------------
//                           Require needed functions
// --------------------------------------------------------------------------

#define CATLISTP_Append
#define CATLISTP_RemoveValue
#define CATLISTP_RemoveAll
#define CATLISTP_Locate

#include "CATLISTP_PublicInterface.h"

// --------------------------------------------------------------------------
//                                  Get macros
// --------------------------------------------------------------------------

#include "CATLISTP_Declare.h"
// DECLARE All functions for class CATListPtrPLMIOmbVirtualObjectDescriptor :
// (generate body of class)
// --------------------------------------------------------------------------
//                       Generate interface of collection-class
// --------------------------------------------------------------------------
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATObjectModelerBase


CATLISTP_DECLARE( PLMIOmbVirtualObjectDescriptor )

typedef CATLISTP(PLMIOmbVirtualObjectDescriptor) CATLISTP_PLMIOmbVirtualObjectDescriptor;

#endif


