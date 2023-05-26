/**
 * Useful functions to work with the Scene Graph.
 */

#ifndef CATSGHelper_H
#define CATSGHelper_H

#include "CATRep.h"
#include "CAT3DBagRep.h"
#include "CATSupport.h"
#include "CAT3DViewpoint.h"
#include "CAT4x4Matrix.h"
#include <vector>

class ExportedBySGInfra CATSGHelper
{
public:

    static CAT3DViewpoint* GetMain3DViewpoint( CATSupport* iSupport );

    static CAT3DBagRep* GetRootRep( CAT3DViewpoint* iViewpoint );

    static CAT4x4Matrix GetMatrix( const CATRep& iRep );

    static std::vector<CAT4x4Matrix> GetMatricesUpward( const CATRep* iFromRep, const CATRep* iToRep );

    /**
    * FastBoxOutsideFrustum tests whether the box defined by its two corners lies fully outside the frustum.
    * It does only a simple rejection test in order to be fast, at the cost of false negatives.
    * @param iFrustum: the frustum planes equations. Must have normals pointing toward the inside of the frustum.
    * @param iMin, iMax: the box corners
    * @return true if the box is outside for sure, false if the box is probably inside, intersecting, or outside.
    */
    template<typename T, typename U = T>
    static bool FastBoxOutsideFrustum( const T( &iFrustum )[6][4], const U( &iMin )[3], const U( &iMax )[3] );

    template<typename T>
    static void NormalizePlaneEquation( T( &ioEquation )[4] );

    template<typename T>
    static void swap( T& a, T& b );
};

#endif
