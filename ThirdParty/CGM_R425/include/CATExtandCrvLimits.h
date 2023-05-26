#ifndef CATExtandCrvLimits_h
#define CATExtandCrvLimits_h

//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"

// Pour la demo, pour Jean Marc.

class CATCrvLimits;
class CATCurve;
class CATSoftwareConfiguration;

// Modified By : SUH : 2004:3:18
// iRatioMin/iRatioMax is the extrapolation ratio in min/max limit direction. These override iRatio if provided.
ExportedByRIBLight void CATExtandCrvLimits(CATSoftwareConfiguration *iConfig, 
                                       const CATCrvLimits & iLimits,
                                       const CATCrvLimits & iMaxLimits,
                                       const double         iRatio,
                                       CATCrvLimits       & oLimits,
                                       CATCurve*            iCurve=0,
                                       double*              iRatioMin = 0,
                                       double*              iRatioMax = 0);

#endif
