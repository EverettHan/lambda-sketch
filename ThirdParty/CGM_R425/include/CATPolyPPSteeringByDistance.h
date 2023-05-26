#ifndef CATPolyPPSteeringByDistance_HH
#define CATPolyPPSteeringByDistance_HH

#include "DSYExport.h"
#include "CATPolyPPSteeringOperator.h"

/**
 *  implementation that shorten the edge to some maxdistance
 *  will use the Distance method of the config space associate to the iNearestInTree CATPolyPPPosition
 * 
 *  equivalent to the old enum SimpleSteer
 */
class DSYExport CATPolyPPSteeringByDistance : public CATPolyPPSteeringOperator
{
public:
	CATPolyPPSteeringByDistance(double iSteeringDistance);
	~CATPolyPPSteeringByDistance();
	

  virtual bool Steer(const CATPolyPPRRTNode & iNearestInTree, CATPolyPPPosition & ioSampleToSteer) ;
protected:
	double _SteeringDistance = 0;;

};

#endif
