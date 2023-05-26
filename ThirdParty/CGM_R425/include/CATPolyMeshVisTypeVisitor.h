// COPYRIGHT DASSAULT SYSTEMES 2015, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshVisTypeVisitor.h
//
//===================================================================
// August 2015  Creation: JXO
//===================================================================
#ifndef CATPolyMeshVisTypeVisitor_H
#define CATPolyMeshVisTypeVisitor_H

#include "PolyVizAdapters.h"
#include "CATErrorDef.h"

class CATIPolySurface;


/**
 * Returns the PolyhedralVisualization type of the CATIPolyMesh.  
 */
class ExportedByPolyVizAdapters CATPolyMeshVisTypeVisitor
{

public:

  CATPolyMeshVisTypeVisitor () {}
  ~CATPolyMeshVisTypeVisitor () {}

  enum MeshType
  {
    /** Unknown mesh */               eUnknownMesh            = -1,
    /** CATPolyMeshVizAdapter */      ePolyMeshVizAdapter     = 1,
    /** CATPolyMeshGPFace */          ePolyMeshGPFace         = 2,
    /** CATPolyMeshGPBounding */      ePolyMeshGPBounding     = 3,
    /** CATPolyMeshVizFace */         ePolyMeshVizFace        = 4,
    /** CATPolyMeshEVizUVFace */      ePolyMeshEVizUVFace     = 5,
    /** CATPolyMeshEVizUVSubFace */   ePolyMeshEVizUVSubFace  = 6,
    /** CATPolyMeshEVizUVFullFace */  ePolyMeshEVizUVFullFace = 7,
    /** CATPolyPlanGPFace */          ePolyPlanGPFace         = 8
  };

public: 

  /**
   * Returns the PolyhedralVisualization type of the CATIPolySurface.
   * @param oType
   *   The type of the CATIPolySurface.
   *   <ul>
   *     <li> ePolyMeshVizAdapter    
   *     <li> ePolyMeshGPFace        
   *     <li> ePolyMeshGPBounding    
   *     <li> ePolyMeshVizFace       
   *     <li> ePolyMeshEVizUVFace    
   *     <li> ePolyMeshEVizUVSubFace 
   *     <li> ePolyMeshEVizUVFullFace
   *     <li> ePolyPlanGPFace
   *   </ul>
   */
  HRESULT GetType (const CATIPolySurface& iSurface, unsigned int& oType);

};

#endif
