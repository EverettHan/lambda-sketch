#ifndef ListPOfCATGeoImplicitSurface_h
#define ListPOfCATGeoImplicitSurface_h

// COPYRIGHT DASSAULT SYSTEMES  2022

class CATGeoImplicitSurface;

/** 
 * @collection CATLISTP(CATGeoImplicitSurface)
 * Collection class for pointers to implicit surface.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia. 
 */
#include "CATLISTPP_Clean.h"
#include "CATLISTPP_PublicInterface.h"
#include "CATLISTPP_Declare.h"
//
// generate interface of collection class
// (functions declarations)
#include "CATGMModelInterfaces.h"
#include "GMScalarFieldsObjects.h"
#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByGMScalarFieldsObjects
/** @nodoc */
CATLISTPP_DECLARE_TS(CATGeoImplicitSurface, 10)
/** @nodoc */
typedef CATLISTP(CATGeoImplicitSurface) ListPOfCATGeoImplicitSurface;

class CATCGMOutput;

/**
 * @nodoc
 * Writes the tags of the faces of the list.
 * @param iWhereToWrite
 * The output.
 * @param  iToWrite
 * The list to dump.
 */
ExportedByCATGMModelInterfaces CATCGMOutput& operator<<(CATCGMOutput& iWhereToWrite, const ListPOfCATGeoImplicitSurface& iToWrite);

#endif
