#ifndef ListPOfCATTessCldTessTriangleInfo_h
#define ListPOfCATTessCldTessTriangleInfo_h


// Name of the class to be listed
class CATTessCldTessTriangleInfo;

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
CATLISTP_DECLARE( CATTessCldTessTriangleInfo );

// define the Type of the class
typedef CATLISTP(CATTessCldTessTriangleInfo) ListPOfCATTessCldTessTriangleInfo ;
     
#endif
