#ifndef ECCurveUtilities_H
#define ECCurveUtilities_H

class CATTopData;
class CATBody;
class CATCrvLimits;
class CATCurve;

class ECCurveUtilities
{
public:
	static CATBody* MakeWireBody(CATTopData* iTopData, CATCurve* ipCurve, const CATCrvLimits& ipLimit, bool iOrientationPositive = true);
};


#endif //ECCurveUtilities_H