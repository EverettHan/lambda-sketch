#ifndef CATPolyPPSteeringOperator_HH
#define CATPolyPPSteeringOperator_HH

#include "DSYExport.h"
#include "CATPolyRefCounted.h"
#include "CATCGMSharedPtr.h"
class CATPolyPPPosition;
class CATPolyPPRRTNode;

/**
 * default inmplementation do nothing ,  equivalent to the old enum NoSteering
 */
class DSYExport CATPolyPPSteeringOperator : public CATPolyRefCounted
{
public:
  typedef CATCGMSharedPtr<CATPolyPPSteeringOperator> SPtr;

	CATPolyPPSteeringOperator();
	virtual ~CATPolyPPSteeringOperator();

  /**
	@brief this operator allow you to control the ioSampleToSteer which for the moment is just randomly sample
	For example we can try to reduce the distance (translation/rotation or just one ) 

	default implementation do nothing 

	@param iNearestInTree  nearest config in the tree
	@param ioSampleToSteer random Sample point that must be adapted (for example do small rotation and keep translation intact )

	@return true if all is OK, false in case of problems.
   */
  virtual bool Steer(const CATPolyPPRRTNode & iNearestInTree, CATPolyPPPosition & ioSampleToSteer) ;


};

#endif
