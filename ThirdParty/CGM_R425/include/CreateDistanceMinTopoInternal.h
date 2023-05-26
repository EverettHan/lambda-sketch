#ifndef CreateDistanceMinTopoInternal_h
#define CreateDistanceMinTopoInternal_h

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "AnalysisToolsLight.h"
#include "CATSkillValue.h"
#include "CreateDistanceMinTopo.h"

//
class CATGeoFactory;
class CATBody;
class CATDomain;
class CATCell;
class CATDistanceMinBodyBody;
class CATTopData;


/**
 * @nodoc
 * for internal use
 */
ExportedByAnalysisToolsLight CATDistanceMinBodyBody * CATCreateDistanceMinTopoInternal(
                                                 CATGeoFactory *iFactory,
                                                 CATTopData    *iData,
                                                 CATBody       *iBody1,
                                                 CATBody       *iBody2,
                                                 CATSkillValue  iMode);

#endif










