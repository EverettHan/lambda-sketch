#ifndef CATCreateDeform_h
#define CATCreateDeform_h

class CATGeoFactory; 
class CATBuildPlateDeform; 
class CATSoftwareConfiguration;
#include "GeoPlate.h"

// ***********************************
// method to build a CATBuildPlateDeform
// ***********************************
 

ExportedByGeoPlate CATBuildPlateDeform * CreateDeform(CATGeoFactory * iFactory,CATSoftwareConfiguration * iConfig); 

ExportedByGeoPlate void RemoveDeform(CATBuildPlateDeform *& iDeform);

#endif
