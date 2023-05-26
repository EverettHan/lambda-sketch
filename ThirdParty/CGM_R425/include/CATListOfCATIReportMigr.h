/**
 * @level Protected
 * @usage U1
 */
// COPYRIGHT DASSAULT SYSTEMES 2000
//=============================================================================
//
// Class CATLISTV(CATReportInformation) :
//
//=============================================================================
// Creation : SCZ - Septembre 2000
// Modifications :
//
//=============================================================================

#ifndef CATListOfCATIReportMigr_H
#define CATListOfCATIReportMigr_H

// --------------------------------------------------------------------------
//                       Clean previous functions requests
// --------------------------------------------------------------------------

#include "CATLISTV_Clean.h"

// --------------------------------------------------------------------------
//                           Require needed functions
// --------------------------------------------------------------------------

#define  CATLISTV_Append
#define  CATLISTV_AppendList
#define  CATLISTV_InsertAt
#define  CATLISTV_Locate
#define  CATLISTV_RemoveValue
#define  CATLISTV_RemovePosition

// --------------------------------------------------------------------------
//                                  Get macros
// --------------------------------------------------------------------------

#include "CATLISTV_Declare.h"

// --------------------------------------------------------------------------
//                       Generate interface of collection-class
// --------------------------------------------------------------------------
#include "AC0CATNAV.h"
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy ExportedByAC0CATNAV

#include "CATIReportMigr.h"

CATLISTV_DECLARE(CATIReportMigr_var)

#endif
