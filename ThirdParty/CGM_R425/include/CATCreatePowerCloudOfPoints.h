#ifndef CATCreatePowerCloudOfPoints_h
#define CATCreatePowerCloudOfPoints_h

class CATPowerCldPolygon;
class CATCloudOfPoints;

#include "GeoPlate.h"

// ***********************************
// Basics methods to build a Location
// ***********************************

ExportedByGeoPlate CATPowerCldPolygon * CreatePowerCloudOfPoints( 
                                        const int inbPoints, // number Of points 
                                        const double * ixyz, // tables of points [x1,y1,z1, ...,xn,yn,zn]; n=inbPoints
                                        // const double iRatio, // ratio of satisfied points, 0.<iRati0<=1.; ex :1<=>100%, 0.99<=>99%
                                        const double iTol    // G0 deviation
                                       );

ExportedByGeoPlate CATPowerCldPolygon * CreatePowerCloudOfPoints( 
                                        const CATCloudOfPoints * iCloudOfPts, // les  Pts
                                        const double iTol    // G0 deviation
                                       );
#endif

