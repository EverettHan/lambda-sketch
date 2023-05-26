/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999
//
//==============================================================================
// Inheritance
// -----------
// CATVisuPropertiesMigrationServices
//    CATBaseUnknown
//
//==============================================================================
// Abstract
// --------
// Implements several services to help migrate from CATIxxxGraphicProperties
// to CATIVisuProperties
//
//==============================================================================
// Usage
// -----
// 
//==============================================================================
// History
// -------
//     - Aug 9, 1999: Created.
//==============================================================================
#ifndef CATVisuPropertiesMigrationServices_H
#define CATVisuPropertiesMigrationServices_H

// interfaces
#include "CATIVisProperties.h"
#include "CATVisPropertiesValues.h"

// TIEs

// others
#include "CATModifyVisProperties.h"
#include "CATPointGraphicAttribut.h"
#include "CATShowMode.h"
#include "CATShowAttribut.h"

class CATIModelEvents;


#include "CATVisItf.h"

// returns availibility according to CATVisGeomType and CATVisPropertyType
/*
ExportedByCATVisController int     CATVPGetValidity (const CATVisGeomType,
                                                     const CATVisPropertyType);
ExportedByCATVisController HRESULT CATVPGetHRESULT  (const CATVisGeomType,
                                                     const CATVisPropertyType);
*/

// names of CATVisGeomType and CATVisPropertyType enum
ExportedByCATVisItf char * CATVPGetHRESULTName      (const HRESULT);
/*
ExportedByCATVisController char * CATVPGetGeomTypeName     (const CATVisGeomType);
*/
ExportedByCATVisItf char * CATVPGetPropertyTypeName (const CATVisPropertyType);

ExportedByCATVisItf CATShowAttribut ConvertFromShowMode (CATShowMode);
ExportedByCATVisItf CATShowMode ConvertFromShowAttribut (CATShowAttribut);


#endif // CATVisuPropertiesMigrationServices_H
