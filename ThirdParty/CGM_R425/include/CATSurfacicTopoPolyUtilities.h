#ifndef CATSurfacicTopoPolyUtilities_H
#define CATSurfacicTopoPolyUtilities_H

#include "CATSurfacicTopoOperators.h"
#include "CATMathPoint2D.h"


class  ExportedByCATSurfacicTopoOperators CATSurfacicTopoPolyUtilities
{
	public :
	/** @nodoc */
    static int ArePointsTurningCCW(const CATMathPoint2D iPoints[], unsigned int nbPoints);

};

#endif

