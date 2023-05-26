#ifndef CATMshSpecTranslator_h
#define CATMshSpecTranslator_h

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022
//=============================================================================
//
// CATMshSpecTranslator :
// Object that manage translation of the specification into MG structures
//
//=============================================================================
// February 2022  Creation                          Fabien Noblet (FNT1)
//=============================================================================

extern "C" {
#include <meshgems/meshgems.h>
}

#include "CATMshBase.h"
#include "CATMshCallbacksMG.h"

class CATIMshSpec;
class CATMshCSMParameters;

class CATMshSpecTranslator : public CATMshBase
{

public:

  /* Contructeur */
  CATMshSpecTranslator(cad_t *c);

  /* Destructeur */
  virtual ~CATMshSpecTranslator();

  HRESULT SetParameters(CATMshCSMParameters *_Param);

  HRESULT SetLocalSpecification(int iSpecCount, CATIMshSpec **iSpecs);

  HRESULT SetTopoIDMuliMap(std::multimap<int, int> iTopoID2ID);

  HRESULT Translate();

  HRESULT TranslateUpdatable(mesh_t *Msht);

  dcad_t * GetDcad();

  int GetSizemaps(sizemap_t ***oSizemaps);

  element_generation_map_t * GetElementGenerationMap();

private:

  /* Constructeur recopie */
  CATMshSpecTranslator(const CATMshSpecTranslator & Source);

  /* Operateur d'affectation */
  CATMshSpecTranslator& operator=(const CATMshSpecTranslator & Source);


  HRESULT BrowseCAD();
  HRESULT FillLocalSizeOnID(int TopoID, double MeshSize, double GeomApp, double Sag, double Min, double Max, double Met[6], bool HasMetric);
  HRESULT FillLocalTypeOnID(int TopoID, std::string Type);
  HRESULT FillBoundaryLayerOnID(int TopoID, int NbLayer, int axi, double SizeAlong, double SizeOrtho, double Propagation);
  HRESULT TranslateLocalSizeSpec(CATIMshSpec *);
  HRESULT TranslateMeshMatchingSpec(CATIMshSpec *);
  HRESULT TranslateLineDistributionSpec(CATIMshSpec *);
  HRESULT TranslateRequiredEntitySpec(CATIMshSpec *);
  HRESULT TranslatePatchIndependentSpec(CATIMshSpec *Spec);
  HRESULT TranslateLocalTypeSpec(CATIMshSpec *Spec);
  HRESULT TranslateBoundaryLayerSpec(CATIMshSpec *Spec);
  HRESULT TranslateEntitiesPropertySpec(CATIMshSpec *Spec);
  HRESULT UpdateCAD();

  std::map<int, cad_edge_t*> _GeomIDMap;
  std::map<int, cad_wire_t*> _GeomIDWireMap;
  std::map<int, int> _ReqEdges;
  std::map<int, int> _Slivers;
  std::map<int, int> _Hyperpatch;
  std::map<int, int> _HollowEdge;
  std::map<int, int> _TopoIDDim;

  std::multimap<int, int> _TopoID2ID;

  CATIMshSpec **_Specs;
  DataForSizemaps_t *_CBData;
  DataForMeshMatching_t *_MMatching;
  CATMshCSMParameters *_Param;

  cad_t *_Cad;
  context_t *_Ctx;
  dcad_t *_Dcad;
  sizemap_t **_oSizemaps;
  element_generation_map_t *_EltMap;

  int _SpecCount;
  int _LastSpecTranslated;
  int _HasMMap;
  int _SizemapCount;
  int _Has3d;
  int _HasGeom;
  int _HasPhy;
  int _HasAnisoCadFace;
  int _HasMeshType;
  int _HasPI;
  int _HasReq;
  int _HasMM;
  int _HasAxi;
  int _HasBL;
  int _HasLineDistrib;
  int _HasvSize;
  int _HasSliver;
  int _Updatable;

};

#endif
