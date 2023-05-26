// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshNormalComputer.h
//
//===================================================================
// Dec 2011  Creation JXO from NDO's code
//===================================================================
#ifndef CATPolyMeshNormalComputer_H
#define CATPolyMeshNormalComputer_H

#include "CATPolyMiscellaneous.h"

#include "CATBoolean.h"
#include "CATErrorDef.h"

class CATIPolyMesh;
class CATIPolyVertexPositionConstLayer;
class CATIPolySurfaceVertexNormalLayer;
class CATIPolySurfaceVertexFacetNeighborhood;


/**
 * Tools to compute Normals on editable (or not) meshes
 */
class ExportedByCATPolyMiscellaneous CATPolyMeshNormalComputer 
{

public:

  CATPolyMeshNormalComputer (){}

  ~CATPolyMeshNormalComputer (){}

public:

/**
 * Given a mesh and Position layer, fills the normal layer with the computed normals
 */
static HRESULT ComputeVertexNormals (const CATIPolyMesh& iMesh, const CATIPolyVertexPositionConstLayer& iPositionLayer, 
                                     CATIPolySurfaceVertexNormalLayer& iNormalLayer);

/**
 * Given a mesh, Position layer and Neighborhood information, fills the normal layer for the required surface vertex.
 */
static HRESULT ComputeVertexNormal (const CATIPolyMesh& iMesh, const int iSurfaceVertex,
                                    const CATIPolyVertexPositionConstLayer& iPositionLayer,
                                    const CATIPolySurfaceVertexFacetNeighborhood& iNeighborhood,
                                    CATIPolySurfaceVertexNormalLayer& iNormalLayer);

/**
 * Given an editable mesh, fills its normal layer with the computed normals
 */
static HRESULT ComputeVertexNormals (CATIPolyMesh& iMesh);

};

#endif
