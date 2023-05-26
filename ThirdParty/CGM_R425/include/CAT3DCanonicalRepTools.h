#ifndef CAT3DCanonicalRepTools_h_
#define CAT3DCanonicalRepTools_h_

// SGInfra (PublicInterfaces)
#include "SGInfra.h"

// SpecialAPI (PublicInterfaces)
#include "CATSysErrorDef.h"

class CAT3DCanonicalRep;

//
// WARNING: LIMITED USE ONLY!
//          YOU NEED TO ASK SCENEGRAPH TEAM (E8C, HQ4) BEFORE USING THIS CLASS!
//

namespace CAT3DCanonical
{
    ExportedBySGInfra double ComputeMeshSAG(CAT3DCanonicalRep& iCanonicalRep);

    /**
    * Makes a copy of an array of VERTEX indices, and multiplies every value by 3 to return an array of COORD indices.
    * NOTE: iArraySize is the size of the array (number of indices in the array). In the case of an array of isolated triangles, iArraySize is 3 times the number of triangles.
    * NOTE: iArrayOfVertexIndices remains unchanged.
    * IMPORTANT: The caller is responsible for the lifecycle of oArrayOfCoordIndices, and the caller must call delete[] when finished with it.
    */
    ExportedBySGInfra HRESULT ConvertToCoordIndices(int         iArraySize,
                                                    int const*  iArrayOfVertexIndices,
                                                    int const*& oArrayOfCoordIndices);

    /**
    * Makes a copy of an array of VERTEX indices, and multiplies every value by 3 to return an array of COORD indices.
    * NOTE: iSizePerArray and iArrayOfVertexIndices remain unchanged.
    * IMPORTANT: The caller is responsible for the lifecycle of oArrayOfCoordIndices, and the caller must call delete[] when finished with it.
    */
    ExportedBySGInfra HRESULT ConvertToCoordIndices(int         iNbArrays,
                                                    int const*  iSizePerArray,
                                                    int const*  iArrayOfVertexIndices,
                                                    int const*& oArrayOfCoordIndices);
}

#endif // !CAT3DCanonicalRepTools_h_
