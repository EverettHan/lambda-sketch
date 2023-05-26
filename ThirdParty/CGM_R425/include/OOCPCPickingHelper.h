#ifndef OOCPCPickingHelper_h_
#define OOCPCPickingHelper_h_

#ifndef _WINDOWS_SOURCE
#include "CATSysErrorDef.h"
#endif

class CATPickPath;
class CAT3DPointCloudRep;
class CATMathPoint;
class CATMathVector;

/**
* @brief Interface that can be implemented to provide an accurate Point position in PointCloud picking scenarios.
* The implementation can be stored in the CAT3DPointCloudRep.
*/
class OOCPCPickingHelper
{
public:
    virtual HRESULT ComputeIntersectionPoint(const CAT3DPointCloudRep& iPointCloudRep, CATMathPoint& oIntersectionPoint) const = 0;
};

#endif // !OOCPCPickingHelper_h_
