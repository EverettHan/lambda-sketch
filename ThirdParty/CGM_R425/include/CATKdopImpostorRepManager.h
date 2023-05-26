#ifndef CATKdopImpostorRepManager_h_
#define CATKdopImpostorRepManager_h_

#include "CATMathPointf.h"
#include "SGComposites.h"
#include "CATSysErrorDef.h"
#include "IVisTexturePtr.h"
#include <cstdint>

class CATRepWeakRef;
class CATRep;


/**
CATKdopImpostorRepManager manages the rep that actually displays the blue boxes for CATKdopImpostorManager.

It consists of a VisPrimitiveGroupRep that contains the geometry of a cube and supports GPU instancing.

On the GPU side, it contains 3 pieces of data:
- the number of instances
- the position of each instance (6 float per instance: center.xyz and size.xyz)
- the visibility of each instance (1 bit per instance: 1 if visible, 0 otherwise)

The visibility can be updated without changing the positions by submitting a visibility buffer of the correct size.

*/
class ExportedBySGComposites CATKdopImpostorRepManager
{
public:
    CATKdopImpostorRepManager();
    CATKdopImpostorRepManager( const CATKdopImpostorRepManager & ) = delete;
    void operator=( const CATKdopImpostorRepManager & ) = delete;

    ~CATKdopImpostorRepManager();

    HRESULT CreateRep( float red, float green, float blue, float alpha );
    HRESULT CreateCuboid(const CATMathPointf& cornerA, const CATMathPointf& cornerB, float red, float green, float blue, float alpha, CATRep*& oNewSurf);

    HRESULT UpdateGeometry( uint64_t iNumInstances, const float* iGeometryBuffer, const uint32_t* iVisibilityBuffer );

    HRESULT UpdateVisibilityOnly( const uint32_t* iVisibilityBuffer );

    CATRep* GetRep();
    CATRep* GetBag();

private:
    CATRepWeakRef* _repWeakRef;
    CATRepWeakRef* _bagWeakRef;
    IVisTexturePtr _geomTexture;
};


#endif //CATKdopImpostorRepManager_h_
