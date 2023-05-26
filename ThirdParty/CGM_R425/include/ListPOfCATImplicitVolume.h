#ifndef ListPOfCATImplicitVolume_h
#define ListPOfCATImplicitVolume_h

// COPYRIGHT DASSAULT SYSTEMES  2022

/**
 * CATImplicitVolume are in fact CATVolume but ListPOfCATVolume already exist in BSF
 * but alas not in the same FWs as ListPOfCATFace... so defining something here
 * for specific usage with GMScalarFieldsObjects with a different name to avoid
 * clashes.
 */ 

class CATVolume;
/** 
 * @collection CATLISTP(CATVolume)
 * Collection class for pointers to (topological) volume.
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
CATLISTPP_DECLARE_TS(CATVolume, 10)
/** @nodoc */
typedef CATLISTP(CATVolume) ListPOfCATImplicitVolume;

class CATCGMOutput;

/**
 * @nodoc
 * Writes the tags of the faces of the list.
 * @param iWhereToWrite
 * The output.
 * @param  iToWrite
 * The list to dump.
 */
ExportedByCATGMModelInterfaces CATCGMOutput& operator<<(CATCGMOutput& iWhereToWrite, const ListPOfCATImplicitVolume& iToWrite);

#endif
