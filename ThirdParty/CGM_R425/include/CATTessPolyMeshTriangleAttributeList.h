//=============================================================================
// COPYRIGHT Dassault Systemes 2006
//=============================================================================
//
// List of tessellation's triangle attributes.
//
//=============================================================================
// 2006-11-02  BPG: New.
//=============================================================================
#ifndef CATTessPolyMeshTriangleAttributeList_H
#define CATTessPolyMeshTriangleAttributeList_H

//
class CATTessPolyMeshTriangleAttribute;

// Clean previous function requests
#include "CATLISTP_Clean.h"

// Defines all the required methods
//#include "CATLISTP_PublicInterface.h"
//#define CATLISTP_RemoveAll
#include  "CATLISTP_PublicInterface.h"

// Get the macros
#include "CATLISTP_Declare.h"

#include "TessPolygon.h"
#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByTessPolygon

// Generate interface of collection class 
CATLISTP_DECLARE(CATTessPolyMeshTriangleAttribute);

// Define the type of the class
typedef CATLISTP(CATTessPolyMeshTriangleAttribute) CATTessPolyMeshTriangleAttributeList;
     
#endif // !CATTessPolyMeshTriangleAttributeList_H
