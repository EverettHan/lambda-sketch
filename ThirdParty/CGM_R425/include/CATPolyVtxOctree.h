//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES 2006
//==============================================================================================================

// CATPolyVtxOctree : Octree structure that supports data on voxel vertices (except on rightmost vertices:
//                    vertices whose X, or Y, or Z coordinate is equal to XMax, YMax or ZMax)

//==============================================================================================================
// Creation : DPS/CHU , march 2006
//==============================================================================================================

#ifndef CATPolyVtxOctree_H
#define CATPolyVtxOctree_H

#include "PolyOctree.h"            // export definition
#include "CATPolyBasicOctree.h"    // derivation
#include "CATErrorDef.h"           // HRESULT
#include "CATTolerance.h"          // used by default argument


class CATMathBox;
class CATPolyVtxOctreeDivisionList;
class CATPolyOctoCube;
union CATPolyVoxel;
class CATPolyError;
class CATPolyVoxelPath;
class CATPolyVtxPath;
class CATPolyCompleteVtxPath;

class ExportedByPolyOctree CATPolyVtxOctree : public CATPolyBasicOctree
{

public :

  // Life cycle (call InitializeOctree to complete construction)
  CATPolyVtxOctree(const CATTolerance & iTol = CATGetDefaultTolerance());
  CATPolyVtxOctree(const CATPolyVtxOctree & iMasterVtxOctree);
  virtual ~CATPolyVtxOctree();

  // Construction from a sub-voxel of another octree, sharing all data under this sub-voxel with the master octree:

  // TrimDuplicateVtxOctree creates a root equivalent to a sub-voxel, therefore changes the atomic voxel size,
  // and has unmatching IJK on its voxels.
  
  // FocusDuplicateVtxOctree creates a root equivalent to the master's root, therefore has unshared octocubes
  // down to the given voxel depth, and shares all data from this depth downward, but its IJK match those of
  // the master, and the atomic voxel size is identical.
  // Divisions that would touch the unshared octocubes (including the root) may be locked by specifying iLockDivisionsOutsideRefVoxel=1 in input.

  static CATPolyVtxOctree * TrimDuplicateVtxOctree(const CATPolyVtxOctree & iMasterVtxOctree, 
    const CATPolyCompleteVoxelPath &iMasterPath);

  static CATPolyVtxOctree * FocusDuplicateVtxOctree(const CATPolyVtxOctree & iMasterVtxOctree, 
    const CATPolyCompleteVoxelPath &iMasterPath, int iLockDivisionsOutsideRefVoxel = 0);

  // Expensive methode (the search starts on Octree Root !)
  // Recherche d'un VtxPath a partir d'une position donnee
  HRESULT SearchIJKVtxPath(unsigned int iIJK[3], CATPolyVtxPath &oVtxPath);

  // Expensive methode (the search starts on Octree Root !)
  // Recherche d'un VtxPath a partir d'une position donnee
  HRESULT SearchIJKVtxPath(unsigned int iIJK[3], CATPolyCompleteVtxPath &oVtxPath);

  // Determination de la distance separant 2 vertex de l'Octree
  double GetDistanceBetweenVertices(CATPolyVtxPath &iFirstCorner, CATPolyVtxPath &iSecondCorner);

  // Determination de la distance separant 2 vertex de l'Octree
  double GetDistanceBetweenVertices(CATPolyCompleteVtxPath &iFirstCorner, CATPolyCompleteVtxPath &iSecondCorner);

  // Divide recursively voxels closed to a given position, 
  // to make the octree locally mono-resolution according to the input Depth
  // then to extract the PrimeCornerPath (returns E_FAIL if it doesn't exist)
  HRESULT ExtractCornerPathFromDivisonAroundIJK(int iLocalDepthTarget, unsigned int iIJK[3], CATPolyVtxPath &oPrimeCornerPath);

  // Eliminate all voxels divisions outside areas where CornerClients are attached to Voxel corners
  // The reference box is not changed, but the octree has less voxels (this method calls Undivide())
  // Voxel clients, and orphan corners (not bounding any voxel) are either listed in output (if the
  // corresponding list pointer is not null), or submitted to a given function if the corresponding
  // pointer is provided). It is advised to delete the pending corners and clients (voxel or corner clients)
  // in this function
  HRESULT SimplifyOutOfCornerClientAreas();


  // Determination du caractere "Leaf" d'un fils d'un OctoCube donné
  // ATTENTION : ce caractere ne renseigne pas sur le type de l'objet,
  // puisqu'une feuille peut etre de type OctoCube pour des raisons d'architecture 
  // de code dans les cas "Adaptatif avec info sur les Corners" !
  virtual int IsOctoChildALeaf(const CATPolyOctoCube * iOctoCube, int iChildIndex0to7) const;

  
  // static method giving the octo-cube geometrically equivalent to a given voxel
  static CATPolyOctoCube * GetNonFakeOnlyEquivOctoCube(const CATPolyVoxelPath &iVoxelOfVtxOctree);


  // Recuperation d'un CornerClient sur un Corner donné.
  // Renvoie E_FAIL si l'operation echoue (Corner non initialise, Ecriture du corner Hors spec : Imax ou Jmax ou Kmax), 
  HRESULT GetCornerClient(CATPolyVtxPath &iCornerPath, CATPolyVoxel *& oCornerClient);

  // Enregistrement d'un CornerClient sur un Corner donné.
  // En cas de conflit avec un CornerClient existant, le pointeur sera ecrase sans appeler
  // aucun destructeur (c'est a l'appelant de gerer)
  // Renvoie E_FAIL si l'operation echoue (Corner non initialise, Ecriture du corner Hors spec : Imax ou Jmax ou Kmax), 
  HRESULT SetCornerClient(CATPolyVtxPath &iCornerPath, const CATPolyVoxel & iCornerClient);

  // Dump
  virtual HRESULT Dump( CATCGMOutput & s, int iVerbose, int iDumpVoxelClients, int iSkipName=0) const;

  // Set work-area key used to check out fake octocubes (used by unstream only)
  inline void SetFakeOctoCubeKey(int iFakeOctoCubeKey);
    
  // debug data
  static char _VtxTreeName[10];
  virtual char * GetShortName() const;


private:

  // Methode virtuelle de destruction d'un VoxelClient attache a un Voxel en dehors d'un boite donnee.
  // Le traitementdu cas "a cheval" necessite des implementations specifiques selon letype d'Octree
  // sous-methode de CATPolyBasicOctree::RemoveVoxelOutOfBox()
  virtual HRESULT RemoveVoxelClientOutOfBox(CATPolyVoxelPath &iVoxelPath, double iTrimBox[6], double iCurBox[6]);
  virtual HRESULT RemoveVoxelClientOutOfBox(CATPolyVoxelPath &iVoxelPath, unsigned int iTrimBox[6], unsigned int iCurBox[6]);

  // Utilitaire de la methode SimplifyOutOfCornerClientAreas()
  // Methode recursive de simplification de Voxel en dehors de toute zone CornerClient.
  // ioHasCornerClientOnFace est le tableau d'information sur l'absence de CornerClient sur une face donnee,
  // parallele aux 6 faces  FACE_Z0, FACE_Z1, FACE_Y0, FACE_Y1, FACE_X0, FACE_X1
  // La valeur 2 pour Unknown est mise a jour (0 ou 1) lors de l'appel
  void SimplifyVoxelOutOfCornerClient(CATPolyVoxelPath &iVoxelPath, int ioHasCornerClientOnFace[6]);

  // Division d'un voxel non racine (il doit exister un octocube pere)
  // Renvoie le PolyOctoCube issu de la division
  // C'est a l'appelant de mettre a jour la profondeur de l'Octree
  virtual CATPolyOctoCube * DivideNonRootLeafVoxel(CATPolyVoxelPath & iVoxelPath, int * oDivisionSkipped = 0);

  // Division d'un voxel non racine, cette operation devant laisser ce voxel "feuille"
  // vu par le VtxOctree (la profondeur est volontairement non mise a jour)
  // Le transfert du VoxelClient (s'il existe) est assure par cette methode
  CATPolyOctoCube * DivideFakeVoxel(CATPolyVoxelPath & iVoxelPath);

  // Recursive utility for CreateCornerClientPath()
  // It is assumed that iCornerIJK may not lie outside of iVoxelPath 
  HRESULT CreateIJKFakeUpperSubVoxel(CATPolyVoxelPath &iVoxelPath, unsigned int iCornerIJK[3], CATPolyVoxelPath &oSubVoxelDirectPath);

  int IsOctoCubeAFake(const CATPolyOctoCube * iOctoCube) const;
  void SetOctoCubeFakeInfo(CATPolyOctoCube * iOctoCube, int iIsOctoCubeAFake);

  // Recuperation d'un CornerClient, via le VoxelClient d'un Voxel dont on sait qu'il n'est pas divisible
  HRESULT GetEquivalentCornerClient(CATPolyVoxelPath & iNotDivisibleVoxelPath, CATPolyVoxel *& oCorner);

  // -----------------------------------------------------------
  // Data 

  // Clef permettant de reserver un bit de la zone de travail de la classe OctoCube, de facon a pouvoir creer
  // des instances de cette classe tout en les considerant comme des (feuilles ou des sous-feuilles) de l'arbre, 
  // dans le but de pouvoir associer des informations (DistanceFiel, GradientField, etc...) sur des Vertices 
  // qui seraient non accessibles par ailleurs.
  // En effet, les informations stockées au niveau d'un Voxel ne concerne que son Corner Imin, Jmin, Kmin, 
  // ce qui ne pose pas de problème en mono-résolution, mais nécessite des "branches artificielles" en adaptatif.
  int             _FakeOctoCubeKey;

};

// methodes inline
// ---------------
inline void CATPolyVtxOctree::SetFakeOctoCubeKey(int iFakeOctoCubeKey) {
  _FakeOctoCubeKey = iFakeOctoCubeKey; }


#endif
