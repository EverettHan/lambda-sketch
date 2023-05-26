//=============================================================================
// COPYRIGHT Dassault Systemes 2006
//=============================================================================
//
// ListPOfCATTopFilletAssistantGroups.h
//
//=============================================================================
// 2006-11_27   PFV
//      * New
//=============================================================================
#ifndef ListPOfCATTopFilletAssistantGroups_H
#define ListPOfCATTopFilletAssistantGroups_H

#include "AutoBase.h"

#include "CATLISTPP_Clean.h"
#define CATLISTPP_RemoveAll
#include "CATLISTPP_MinimumPublicInterface.h"
#include "CATLISTPP_Declare.h"

class CATTopFilletAssistantGroup;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByAutoBase

CATLISTPP_DECLARE_TS(CATTopFilletAssistantGroup, 4);
typedef CATLISTP(CATTopFilletAssistantGroup) ListPOfCATTopFilletAssistantGroups;

#endif // !ListPOfCATTopFilletAssistantGroups_H
