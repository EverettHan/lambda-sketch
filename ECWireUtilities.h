#ifndef ECWireUtilities_H
#define ECWireUtilities_H

#include "ListPOfCATBody.h"

class CATGeoFactory;
class CATTopData;
class CATSoftwareConfiguration;
class CATBody;

class ECWireUtilities
{
public:
	static CATBody* MakeWire(CATGeoFactory * ipFactory, CATTopData* ipTopData, CATLISTP(CATBody) & iCurveWires);
	static bool CheckSelfIntersection(CATSoftwareConfiguration * ipConfig, CATBody* iBody);
};


#endif //ECWireUtilities_H
