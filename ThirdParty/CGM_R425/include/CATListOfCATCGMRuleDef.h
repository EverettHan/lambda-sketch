/* -*-c++-*- */
/**
 * @COPYRIGHT DASSAULT SYSTEMES 2002
 */

//=============================================================================
//
// COPYRIGHT   : DASSAULT SYSTEMES 2002
// DESCRIPTION : Class for managing lists of pointers to CATCGMRuleDef structs
//
// Feb. 02	Creation                                                 HCN
//=============================================================================

#ifndef CATListOfCATCGMRuleDef_h
#define CATListOfCATCGMRuleDef_h

#include "ExportedByCATCGMCleaner.h"

#include "CATLISTPP_Clean.h"
#include "CATLISTPP_PublicInterface.h"
#include "CATLISTPP_Declare.h"

#include "CATCGMRuleDef.h"

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATCGMCleaner

CATLISTPP_DECLARE_TS(CATCGMRuleDef ,10)


#endif

