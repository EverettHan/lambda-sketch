#ifndef CATIPGMCloudCGMUtilItfBldr_h
#define CATIPGMCloudCGMUtilItfBldr_h

#include "CATGMOperatorsInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"
#include <vector> 

class CATIPGMConvertTessellatedMesh;
#ifndef _AIX_SOURCE
class CATIPGMManualPipesReconstruction;
#endif
class CATGeoFactory;
class CATTopData;
class CATIPolyMesh;

extern ExportedByCATGMOperatorsInterfaces IID IID_CATIPGMCloudCGMUtilItfBldr;

/**
 * Factory of implementations of CGM interfaces for the framework CATCloudCGMUtilities.
 */
class ExportedByCATGMOperatorsInterfaces CATIPGMCloudCGMUtilItfBldr: public CATBaseUnknown
{
  CATDeclareInterface;
public:
  virtual CATIPGMConvertTessellatedMesh *CATPGMCreateConvertTessellatedMesh(
    CATGeoFactory *iFactory,
    CATTopData *iTopData,
    CATIPolyMesh *iPolyMesh) = 0;

#ifndef _AIX_SOURCE
  virtual CATIPGMManualPipesReconstruction* CATPGMCreateManualPipesReconstruction(
    CATGeoFactory* iFactory, 
    CATTopData* iTopData, 
    std::vector<double>& iVerticesCoords) = 0;
#endif
};

/**
 * Returns the factory of implementations of interfaces for the framework CATCloudCGMUtilities.
 * @return
 *   The factory. Pay attention: no <tt>AddRef</tt> is run.
 */
CATIPGMCloudCGMUtilItfBldr *CATCGMGetCloudCGMUtilItfBldr();

#endif /* CATIPGMCloudCGMUtilItfBldr_h */
