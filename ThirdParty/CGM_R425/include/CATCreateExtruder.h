#ifndef CATCreateExtruder_H
#define CATCreateExtruder_H

#include "Extrude.h"

class CATExtruderByCircle;
class CATExtruderByLine;

class CATGeoFactory;
class CATSoftwareConfiguration;
class CATMathAxis;
class CATMathPoint;


ExportedByExtrude CATExtruderByCircle * CATCreateExtruder(CATGeoFactory *iWhere,
                                        const CATMathAxis & iRef ,
                                        CATSoftwareConfiguration * iSoftwareConfiguration);



ExportedByExtrude CATExtruderByLine * CATCreateExtruder(CATGeoFactory *iWhere,
                                      const CATMathPoint & iRef,
                                      CATSoftwareConfiguration * iSoftwareConfiguration);

#endif



