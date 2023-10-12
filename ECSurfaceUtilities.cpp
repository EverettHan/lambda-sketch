#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <CATGeoFactory.h>
#include <CATSoftwareConfiguration.h>
#include <CATBody.h>
#include <CATErrorMacros.h>
#include <CATSurLimits.h>
#include <CATLine.h>
#include <CATCGMJournalList.h>
#include <CATGeometry.h>
#include <CATCGMCellTracker.h>
#include <CATCGMContainerMngt.h>
#include <CATIPGMTopCompatible.h>
#include <CATMathPlane.h>
#include <CATPlane.h>
#include <CATCrvLimits.h>

#include <ECSurfaceUtilities.h>

CATBoolean     ECSurfaceUtilities::IsSurfaceFinite( CATSurface * iSurface )
{
   int ii ;
   if ( NULL == iSurface ) return FALSE ;
   CATGeoFactory * p_factory = NULL ;
   double max_size,
          range[2][2],
          tolerance ;
    CATSurLimits  surf_limits ;
    CATBoolean isFiniteFlag =  TRUE ;
	p_factory = iSurface->GetContainer() ;
    if ( NULL == p_factory ) return FALSE ;
    max_size = p_factory->GetModelSize() ;
    tolerance = p_factory->GetResolution() ;
    iSurface->GetLimits(surf_limits) ;
	surf_limits.GetExtremities(range[0][0],
                               range[1][0],
							   range[0][1],
							   range[1][1]) ;
	for (ii = 0 ; ii < 2 ; ii++ ) {
		if (  range[ii][0] - tolerance   <= -max_size ||
			  range[ii][1] + tolerance >= max_size  ) {
             isFiniteFlag = FALSE  ;
             break ;
		}
	}
    return isFiniteFlag ;
}