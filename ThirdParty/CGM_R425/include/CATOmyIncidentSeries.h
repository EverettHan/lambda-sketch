/* -*-c++-*- */
/**
* @level Protected
* @usage U3
*/
// COPYRIGHT Dassault Systemes 2020
//===================================================================
//
// Defines all specific error series that could be mapped
// from an error group
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//  April 2020                                                    vcs
//===================================================================
#ifndef CATOmyIncidentSeries_H
#define CATOmyIncidentSeries_H

#include "CATErrorDef.h"
//------------------------------------------------------------------

// To limit error ranges expansion and overload risk, this class uses non  yet attributed range of CATOmbPersistErrorDef.h
// see CATOmbPersistErrorDef.h content before any modification

//CATOmb_ERR_BASE + 0x70 = 0x0A00 + 0x70 = 0x0A70
#define CATOmy_E_V5V6_Catalog_Compliance           MAKE_HRESULT(SEVERITY_ERROR,FACILITY_ITF,0x0A070)
#define CATOmy_E_Waited_Task_On_Reentrant_Pattern  MAKE_HRESULT(SEVERITY_ERROR,FACILITY_ITF,0x0A071)

#endif
