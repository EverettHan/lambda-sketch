#ifndef CATCreateContactLocation_h
#define CATCreateContactLocation_h

class CATCContactLocation;
class CATPContactLocation;
class CATIPowerCldPolygon;
class CATICldLocation;
#include "CATBoolean.h"

#include "GeoPlate.h"

// ***********************************
// Basics methods to build a Location
// ***********************************

ExportedByGeoPlate CATCContactLocation * CreateCContactLocation();

ExportedByGeoPlate CATPContactLocation * CreatePContactLocation();


ExportedByGeoPlate CATICldLocation * CreateCldLocation( CATIPowerCldPolygon * iCld, 
                                                                 CATBoolean iIsToDeformed );

#endif
