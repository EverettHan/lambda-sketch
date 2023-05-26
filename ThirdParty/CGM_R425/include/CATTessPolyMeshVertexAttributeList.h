//=============================================================================
// COPYRIGHT Dassault Systemes 2006
//=============================================================================
//
// List of tessellation's vertex attributes.
//
//=============================================================================
//  2006-11-02  BPG: New.
//=============================================================================
#ifndef CATTessPolyMeshVertexAttributeList_H
#define CATTessPolyMeshVertexAttributeList_H

//
class CATTessPolyMeshVertexAttribute;

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
CATLISTP_DECLARE(CATTessPolyMeshVertexAttribute);

// Define the type of the class
typedef CATLISTP(CATTessPolyMeshVertexAttribute) CATTessPolyMeshVertexAttributeList;
     
#endif // !CATTessPolyMeshVertexAttributeList_H
