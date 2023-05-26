// COPYRIGHT DASSAULT SYSTEMES 2023, ALL RIGHTS RESERVED.
//===================================================================
//
// CATMapOfBodyFaceToMesh.h
//
//===================================================================
//
// February 2023  Creation: JXO
//  
//===================================================================
#ifndef CATMapOfBodyFaceToMesh_h
#define CATMapOfBodyFaceToMesh_h

#include "CATPolyBoundingVolumeOperators.h"
#include "CATMapOfPtrPtrToPtr.h"
#include "CATBoolean.h"

class CATPolyBody;
class CATPolyFace;
class CATIPolyMesh;

/*
 * Full information of selections of triangles onto PolyBodies.
 * Meshes are CATPolySubMesh.
 */
class ExportedByCATPolyBoundingVolumeOperators CATMapOfBodyFaceToMesh : public CATMapOfPtrPtrToPtr
{

public:

  /* Default constructor */
  CATMapOfBodyFaceToMesh();
  /* Default destructor */
  ~CATMapOfBodyFaceToMesh();

public:
  // Iterator to cycle through all the elements in the map.
  class ExportedByCATPolyBoundingVolumeOperators Iterator : public CATMapOfPtrPtrToPtr::Iterator
  {
  public:
    Iterator(const CATMapOfBodyFaceToMesh& map) : CATMapOfPtrPtrToPtr::Iterator(map) {}
    ~Iterator() {}

    const CATPolyBody* GetBody() const;
    const CATPolyFace* GetFace() const;
    const CATIPolyMesh* GetMesh() const;
  };


  /*
   * Inserts a new mesh in the map.
   * If a mesh is already attached to this pair body / face, it fails.
   * An AddRef is done on the mesh, you can release it.
   */
  HRESULT Insert(const CATPolyBody* pBody, const CATPolyFace* pFace, const CATIPolyMesh* pMesh);

  /*
   * Locates a mesh in the map.
   * An AddRef is done on the mesh, you have to release it after use
   */
  CATBoolean Locate(const CATPolyBody* pBody, const CATPolyFace* pFace, CATIPolyMesh* &oMesh);


  friend class Iterator;
};
#endif
