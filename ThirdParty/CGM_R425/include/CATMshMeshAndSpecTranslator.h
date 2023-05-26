#ifndef CATMshMeshAndSpecTranslator_h
#define CATMshMeshAndSpecTranslator_h

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022
//=============================================================================
//
// CATMshMeshAndSpecTranslator :
// Object that manage translation of a CATMesh and Specs into a mesh_t and 
// associated sizemaps
//
//=============================================================================
// January 2022  Creation                          Fabien Noblet (FNT1)
//=============================================================================

extern "C" {
#include <meshgems/meshgems.h>
}

#include "CATMshBase.h"
#include "CATIMshMesh.h"
#include "CATMshCallbacksMG.h"

class CATIMshSpec;
class CATMshCSMParameters;

class ExportedByCATMshCSMCommon CATMshMeshAndSpecTranslator : public CATMshBase
{

public:

  /* Contructeur */
  CATMshMeshAndSpecTranslator(context_t *iCtx);

  /* Destructeur */
  virtual ~CATMshMeshAndSpecTranslator();

  HRESULT SetMesh(CATIMshMesh *iMesh);

  HRESULT SetParameters(CATMshCSMParameters *_Param);

  HRESULT SetLocalSpecification(int iSpecCount, CATIMshSpec **iSpecs);

  HRESULT Translate();

  HRESULT TranslateUpdatable(mesh_t *Msht);

  mesh_t * GetMesh();

  int GetSizemaps(sizemap_t ***oSizemaps);
  
private:
   
  /* Constructeur recopie */
  CATMshMeshAndSpecTranslator(const CATMshMeshAndSpecTranslator & Source);

  /* Operateur d'affectation */
  CATMshMeshAndSpecTranslator& operator=(const CATMshMeshAndSpecTranslator & Source);

  HRESULT ImportCATMeshGeometry();
  HRESULT TranslateLocalSizeSpec(CATIMshSpec *);
  HRESULT TranslateMeshMatchingSpec(CATIMshSpec *);
  HRESULT TranslateLineDistributionSpec(CATIMshSpec *);
  HRESULT TranslateRequiredEntitySpec(CATIMshSpec *);
  HRESULT ReadAndTranslateSpecs();

  /* Input object */
  CATIMshMesh * _iMsh;
  CATMshCSMParameters *_Param;
  CATIMshSpec **_Specs;
  DataForSizemaps_t *_CBData;
  DataForMeshMatching_t *_MMatching;
  context_t *_Ctx;
  mesh_t *_Msht;
  sizemap_t **_oSizemaps;

  /* Vertex mapping */
  std::map<int, integer>::iterator _Iterator;
  std::map<int, integer> _VertexCAT2MG;
  CATMshVertexIndex *_VertexMG2CAT;

  /* Element mapping */
  CATMshElementIndex* _EdgeMapping;
  CATMshElementIndex* _TriangleMapping;
  CATMshElementIndex* _QuadMapping;

  int _SpecCount;
  int _LastSpecTranslated;
  int _SizemapCount;
  int _Has3d;
  int _HasvSize;
  int _HasGeom;
  int _HasPhy;
  int _HasMM;
  int _Updatable;

};

#endif
