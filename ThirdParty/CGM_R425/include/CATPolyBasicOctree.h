//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES 2006
//==============================================================================================================

// CATPolyBasicOctree : Octree structure that supports data on voxels

//==============================================================================================================
// Creation : DPS/CHU , march 2006
//==============================================================================================================

#ifndef CATPolyBasicOctree_H
#define CATPolyBasicOctree_H

#include "CATPolyDumpable.h"        // derivation
#include "CATPolyVoxDefine.h"       // VREP_DEBUG, VREP_COUNTER valuation
#include "PolyOctree.h"             // export definition
#include "CATErrorDef.h"            // HRESULT
#include "CATTolerance.h"           // agregated

class CATMathBox;
union CATPolyVoxel;
class CATPolyOctreeDivisionList;
class CATPolyOctoCube;
class CATPolyError;
class CATPolyVoxelPath;
class CATPolyCompleteVoxelPath;
class CATPolyBasicVoxelPath;
class CATPolyOctreeRoot;
class CATPolyIJKNeighborhood;

class ExportedByPolyOctree CATPolyBasicOctree  : public CATPolyDumpable
{

public :

  // Life cycle (call InitializeOctree to complete construction)
  CATPolyBasicOctree(const CATTolerance & iTol = CATGetDefaultTolerance());
  virtual ~CATPolyBasicOctree();

  // Initialize octree (calls SetGeometricMapping and CreateRoot())
  // iExpectQuickDivisions (debug only) = 1 if DivideUpToDepth is often expected to be called
  CATPolyError * InitializeOctree(CATMathBox &iBox, int iCubicVoxelsOnly, int iExpectQuickDivisions=0);

  // Initialize a "child" octree from a sub-voxel "V" of another "master" octree, sharing all smaller sub-voxels with the master.
  // Set iTrimMaster=0 to have both octrees share the same box, hence the same IJK on all shared sub-voxels (then the child
  // octree has additional octocubes between its root and V, and it behaves like a "focused" duplicated tree)
  // or iTrimMaster=1 to have the child octree actually trimmed to the sub-voxel box, with specific IJK that do
  // not match those of the master even on shared sub-voxels.
  // If iTrimMaster==0, divisions that would touch the additional octocubes (including the root) may be locked by
  // specifying iLockDivisionsOutsideRefVoxel=1 in input.
  // Warning:
  // 1) V may not be the root of the master octree : sharing the root would amount to a real octree duplication, 
  // there is no need to do this (so far), and a copy constructor would be better anyway.
  // 2) Divisions involving that sub-voxel (V, or one of its children) may either be processed on the master octree or on
  // the child, they affect both octrees in all cases.
  // 3) Undividing the immediate father of V is prohibited (in particular, focusing the master on a box that does not
  // interfere with V is prohibited). This is very important because there is no protection implemented against it.
  // 4) The master should be deleted after the child, not before. However, it is still possible to delete the child
  // after the master, providing no method (except the destructor) has been invoked on the child after the master is deleted
  // (its octocubes are already deleted).
  // 5) If there are voxel-clients, they are neither owned by the master nor by the child, but by the application itself.
  // If these voxel clients are to be deallocated by a cleaning function set by SetAllVoxelClientsCleaner method,
  // then voxel clients ownership is implicitly determined by the way this method works : the caller may choose
  // to assign a cleaning method to the master and none to the child, or assign a method to each and then ensure that
  // voxel clients attached to shared voxels are not deallocated twice (by sharing a VC. allocation manager in the context)
  // The cleaning method (if any) is not automatically transmitted to the child when the child is created.
  // If there is only a "single-voxel-deallocation" method, then it will be called only once on shared sub-voxels,
  // by the first deallocated octree, no special attention is required in this case.
  CATPolyError * InitializeOctreeFromMaster(const CATPolyCompleteVoxelPath &iPathFromMasterOctree, int iTrimMaster,
    int iLockDivisionsOutsideRefVoxel);
  inline CATPolyCompleteVoxelPath * GetFocusedVoxel() const; // reads the ref voxel if divisions are locked outside

    // Create a root voxel
  CATPolyError * CreateRoot();

  // Initialize geometric mapping (can be done on a complete, but "abstract" octree)
  CATPolyError * SetGeometricMapping(CATMathBox &iBox, int iCubicVoxelsOnly);

  // Get root voxel
  inline CATPolyOctreeRoot * GetOctreeRootVoxel() const;

  // Read actual depth (=depth of deepest voxel, -1 if no voxel at all, 0 if root is the only voxel)
  int GetDepth() const;

  // Mise a jour de la profondeur de l'Octree suite a une division
  void AppendDivisionDepth(int iDivisionDepth);
  
  // Get  chronological list of divisions, if any (debug only).  Clean this list
  inline CATPolyOctreeDivisionList * GetChronoDivisionList() const;
  void CleanDivisionList();

  inline const CATTolerance & GetTolerance() const;

  // Eliminate all voxels divisions outside a given box
  // The reference box is not changed, but the octree has less voxels (this method calls RemoveOctoCube())
  // It is assumed that iBox is contained in the current box.
  // Voxel clients under removed OctoCubes are delete during this focus operation
  // The Octree Depth is updated before return
  HRESULT FocusOnBox(CATMathBox & iBox);
  HRESULT FocusOnBox(unsigned int iTrimIJKBox[6]);

  // Note: concernant toutes les methodes amenees a faire des divisions : il y a 2 methodes en bout de ligne
  // qui sont appelees pour tous les cas : CATPolyBasicOctree::DivideNonRootLeafVoxel et CATPolyOctreeRoot:DivideRoot

  // Divisions minimales permettant l'existence du voxel de profondeur idepth et coin gauche iIJK[3]
  // *oProhibitedDivision=1 en sortie si une division requise (iDivideIfNeeded=1) est interdite (par un octree focus-duplique)
  HRESULT DivideUpToIJKDepth(unsigned int iIJK[3], unsigned int iDepth, CATPolyCompleteVoxelPath * oPath=0, int * oProhibitedDivision=0);

  // Decalage quelconque, a iso-profondeur, avec possibilite debrayable de subdiviser au besoin
  // iDelta[3] est en unites de la taille du voxel adresse par ioPath (ex:{-1,-1,-1)=on franchit le sommet en bas a gauche)
  // *oProhibitedDivision=1 en sortie si une division requise (iDivideIfNeeded=1) est interdite (par un octree focus-duplique)
  HRESULT IsoDepthOffset(CATPolyCompleteVoxelPath & ioPath, int iDelta[3], int iDivideIfNeeded=0, int * oProhibitedDivision=0);

  // Divide recursively voxels closed to a given position, 
  // to make the octree locally mono-resolution according to the input Depth
  HRESULT DivideUpToDepthAroundIJK(int iLocalDepthTarget, unsigned int iIJK[3]);

  // Make all missing divisions to have a given box covered with d-depth voxels
  CATPolyError * DivideInBoxUpToDepth(int * iIJKBox, int iExpectedDepth);

  // Divide recursively voxels above a given position, 
  // to make the octree locally mono-resolution according to the input Depth
  HRESULT DivideUpToDepthAboveIJK(int iLocalDepthTarget, unsigned int iIJK[3], 
    CATPolyVoxelPath &oUpperVoxelPath);

  // Division d'un Voxel feuille, a condition implicite qu'il soit vierge de tout VoxelClient
  // Renvoie le PolyOctoCube issu de la division
  // Met a jour la profondeur de l'Octree
  // Si une classe derivee a inhibe la division, l'info est rendue en option par int *oDivisionSkipped=1
  CATPolyOctoCube * DivideLeafVoxel(CATPolyVoxelPath &iVoxelPath, int * oDivisionSkipped = 0);

  // Divide a voxel several times (equivalent to DivideLeafVoxel() if iAddedDepth==1)
  CATPolyError * DivideVoxelUpToDepth(CATPolyVoxelPath * iVoxel, int iAddedDepth);

  // Determination du caractere "Leaf" d'un VoxelCube donné
  int IsVoxelALeaf(const CATPolyBasicVoxelPath &iVoxelPath) const;
  int IsVoxelALeaf(const CATPolyCompleteVoxelPath &iVoxelPath) const;

  // Determination du caractere "Leaf" du VoxelCube Root
  int IsUnsafeRootVoxelALeaf(const CATPolyCompleteVoxelPath &iVoxelPath) const;

  // Determination du caractere "Leaf" d'un VoxelCube non Root
  int IsUnsafeNonRootVoxelALeaf(const CATPolyCompleteVoxelPath &iVoxelPath) const;

  // Determination du caractere "Leaf" d'un fils d'un OctoCube donné
  virtual int IsOctoChildALeaf(const CATPolyOctoCube * iOctoCube, int iChildIndex0to7) const;

  // Renvoie 1 si l'octree partage des données avec un octree maitre, 0 sinon
  int HasMasterOctree() const;

  void GetFocusIJKBox(unsigned int oIJKBox[6]);

  // Recuperation du Voxel feuille de la sous-branche definie par un Voxel courant et un indice de Corner
  // (partage entre iVoxelPath et oLeafVoxelPath)
  // renvoie 0 si non trouve
  // oLeafVoxelPath est un clone de iVoxelPath si ce dernier est feuille
  int GetLeafVoxelFromVoxelCorner(const CATPolyVoxelPath &iVoxelPath, unsigned int iCornerIndex, CATPolyVoxelPath &oLeafVoxelPath) const;

  // Check if {i,j,k} corresponds to an existing corner
  int IsARealVoxelCorner(unsigned int iI, unsigned int iJ, unsigned int iK);
  
  // Requete d'une clef donnant acces a une zone de travail de longueur donnee dans les OctoCubes
  // L'ATTRIBUTION D'UNE CLEF IMPLIQUE QUE LES CHAMPS DE BITS DISPONIBLES DANS LES OCTOCUBES
  // SONT INITIALEMENT AFFECTES A LA VALEUR ZERO AVANT USAGE PAR LE CLIENT.
  // -> A REMETTRE A ZERO IMPERATIVEMENT APRES USAGE PAR LE CLIENT DANS TOUS LES OCTOCUBES VISITES !
  // -> PUIS LIBERER LA ZONE DE TRAVAIL : UnlockOctoCubeWorkArea(int iClientBitLength, int iClientWorkAreaKey)
  HRESULT QueryLockOctoCubeWorkArea(int iClientBitLength, int &oClientWorkAreaKey);

  // Liberation de la zone de travail accessible par une clef donnee dans les OctoCubes
  // ATTENTION : LA REMISE A ZERO DES CHAMPS DE BITS DANS LES OCTOCUBES VISITES DOIT
  // ETRE OBLIGATOIREMENT REALISEE PAR LE CLIENT AVANT L'APPEL DU UNLOCK
  void UnlockOctoCubeWorkArea(int iClientBitLength, int iClientWorkAreaKey);

  // Voxel investigation 

  // Smallest voxel size (grid step) set iDim = 0 for X, 1 for Y, 2 for Z
  // set iDim012=-1 to get the minimum value among X, Y and Z
  double GetSmallestVoxelSize(int iDim) const;

  // Get the VoxelSize according both the required depth and the input direction iDim = 0 for X, 1 for Y, 2 for Z
  double GetVoxelSize(unsigned int iDim, int iVoxelDepth);

  // Get cubic voxels information
  inline int AreVoxelsCubic();

  // static method giving the octo-cube geometrically equivalent to a given voxel
  static CATPolyOctoCube * GetEquivOctoCube(const CATPolyVoxelPath & iVoxel);

  // Corner investigation
  void GetCornerPosition(unsigned int iI, unsigned int iJ, unsigned int iK, 
    double & oX, double &oY, double &oZ) const;
  
  // Search a voxel containing or bounded by a given iIJK position, and containing the immediate neighborhood
  // of iIJK in a given direction (0<=iWantedCornerPositionVsVoxel<=7)
  // Among existing solutions (if any). the voxel returned is the smallest one whose depth is inferior
  // or equal to iMaxTargetDepth. 
  // Hence setting iMaxTargetDepth=_MaxOctreeDepth_ enables to get the leaf solution voxel.
  // Note that the root is always a aolution if iIJK lies in the reference box.
  // E_FAIL is returned if there exists no solution (iIJK outside reference box or given direction points outward reference box).
  // In all other situations, S_OK is returned and oVoxelPath gives the solution.
  // oIsSolutionALeaf=1 is oVoxelPath is a leaf
  // oUnmatchedPosition = 0 if iIJK is actually the corner of oVoxelPath defined by iWantedCornerPositionVsVoxel
  // oUnmatchedPosition = 1 if iIJK lies anywhere else on oVoxelPath (interior, or boundary except at iWantedCornerPositionVsVoxel)
  // Note that the solution's depth can be read directly in the path

  // NOTE PROVISOIRE: METHODE EQUIVALENTE AU VIEUX GetLeafVoxelFromCorner() 
  //                  A CONDITION DE METTRE iMaxTargetDepth=_MaxOctreeDepth_ (ou 15) 
  //                  ET DE REJETER LA SOLUTION SI oUnmatchedPosition=1 EN SORTIE
  HRESULT GetVoxelInGivenDirectionFromIJK(unsigned int * iIJK, int iWantedCornerPositionVsVoxel, 
    CATPolyOctoCube*(*iGetVisitableOctoCube)(const CATPolyVoxelPath &),
    int iMaxTargetDepth, CATPolyVoxelPath &oVoxelPath, int & oUnmatchedPosition) const;

  // Undivide a voxel if it is divided, delete its sub-tree and all pending voxel clients
  // This method does nothing if iVoxel is not divided
  // The octree depth is updated in option
  HRESULT UndivideVoxel(CATPolyVoxelPath & iVoxel, int iUpdateOctreeDepth = 1);

  // Update the octree depth. Useless unless depth updating has been explicily disabled before 
  // (e.g by Undivide). The new depth value is returned
  int UpdateDepth();
  void ForceSetDepth(int iDepth);

  void GetInitialBox(CATMathBox & iBox) const; // input box
  void GetBox(CATMathBox & iBox) const;  // internal working box

  // Dump customizing
  inline void SetDumpVoxelClientMethod(HRESULT (*iDumpVoxelClient)(CATCGMOutput&,int,const CATPolyVoxel&,const CATPolyBasicOctree*,void*));
  inline void SetDumpVoxelClientContext(void * iDumpVoxelClientContext);

  // Stream as text file (requires CATDevelopmentStage=TRUE)
  virtual HRESULT WriteToFile(char * iFilePathName, int iVerbose, int iDumpVoxelClients);

  // Check if there is at least one bit reserved for octocube's work areas (0=no, 1=yes)
  inline int AreThereWorkAreasOnOctoCubes() const;

  // Initialize work area manager (reserved for unstream)
  inline void SetWorkAreaManager(int iWorkAreaManager);

  // Voxel clients existence flag (internal use)
  inline void SetThereIsAtLeastOneVoxelClient(int iValue);

  // Investigate, or clean a mirror voxel on a master octree
  void GetMirrorVoxelData(const CATPolyBasicOctree *& oMasterOctree, const CATPolyCompleteVoxelPath *& oMasterPath, unsigned int oIJK[3]);
  void CleanMirrorVoxelData();

  // Get a tag for an octocube (reserved for debug)
  inline unsigned int GetNewOctoCubeTag();

  // Dump
  static char _TreeName[10];
  virtual char * GetShortName() const;

  virtual HRESULT Dump( CATCGMOutput & s, int iVerbose, int iDumpVoxelClients, int iSkipName=0) const;
  HRESULT Dump( CATCGMOutput & s) const; // inherited from CATPolyDumpable
  HRESULT DumpVoxelClient(CATCGMOutput & s, int iVerbose, const CATPolyVoxel & iClientData) const;
#ifdef VREP_COUNTER
  void DumpCounter(CATCGMOutput & s);
#endif

  // Structure used to update a master octree (if any) when a first division is made on the shared voxel
  // by the child octree (useless if this shared voxel is not a leaf when the child octree is created)
  struct MirrorVoxel {
    const CATPolyCompleteVoxelPath * _PathInMasterOctree; // owned
    unsigned int                     _IJKInCurrentOctree[3];
    MirrorVoxel(const CATPolyCompleteVoxelPath * iMasterPath, unsigned int iIJK[3]);
    ~MirrorVoxel();
  };

protected:


  // Division d'un voxel non racine (il doit exister un octocube pere)
  // Renvoie le PolyOctoCube issu de la division
  // C'est a l'appelant de mettre a jour la profondeur de l'Octree
  // Attention, cette methode est virtuelle, rien n'empeche une classe derivee de ne pas effectuer la division,
  // si c'est le cas, l'information peut etre recuperee en option par *oDivisionSkipped
  // *oProhibitedDivision=1 en sortie si la division requise est explictement interdite (par un octree focus-duplique)
  virtual CATPolyOctoCube * DivideNonRootLeafVoxel(CATPolyVoxelPath & iVoxelPath, int * oDivisionSkipped = 0,
    int * oDivisionProhibited = 0);

  // Utility for DivideVoxelUpToDepthAroundIJK() and IsASubtreeCorner() 
  // oQualifiedSubVoxelIndexes must be sized for 8 sub-voxels.
  // It is assumed that iCornerIJK may not lie outside of iVoxelPath 
  // If iStopIfLeaf is required, this method does not return any qualified SubVoxel in case of Leaf Voxel
  // If the input corner is already a corner of iVoxelPath, oCornerIndexInCurrentVoxel gives this corner index 
  // in output (between 0 and 7), and oNbBQualifiedSubVoxels is left null in this case.
  // If the input is not a corner of iVoxelPath, oCornerIndexInCurrentVoxel = -1 in output
  void WhichSubVoxelTreesMayContainCorner(unsigned int iCornerIJK[3], CATPolyVoxelPath &iVoxelPath, int iStopIfLeaf,
    int &oNbBQualifiedSubVoxels, int oQualifiedSubVoxelIndexes[8], int &oCornerIndexInCurrentVoxel);

  // Recursive utility for DivideUpToDepthAroundIJK()
  // It is assumed that iCornerIJK may not lie outside of iVoxelPath 
  // Optional argument oIJKData makes method return all adjacent VoxelPath in a structure data
  HRESULT DivideVoxelUpToDepthAroundIJK(CATPolyVoxelPath & iVoxelPath, unsigned int iDepthTarget,
    unsigned int iCornerIJK[3], CATPolyIJKNeighborhood *oIJKData=0);

  // Methode recursive de destruction d'un OctoCube et de tous ses enfants, quelle que soit leur nature
  // La recursion est arretee si on rencontre iSharedOctocube (partage avec l'octree maitre s'il existe)
  // ATTENTION : la depth de l'Octree n'est pas remise a jour par cette methode.
  // L'appelant doit lancer la methode UpdateDepth apres cession de RemoveOctoCube 
  // si cette donnee a toujours un sens pour la suite
  HRESULT RemoveOctoCube(CATPolyOctoCube * &ioOctoCubeToRemove, int iIgnoreVoxelClients = 0, CATPolyOctoCube *iSharedOctocube = NULL) const;
 
  // Methode de destruction d'un VoxelClient s'appuyant sur le pointeur sur fonction dedie
  HRESULT RemoveVoxelClient(CATPolyVoxel *& ioVoxelClient, CATPolyOctoCube * iFather, int iChildIndex0to7) const;

  // Divide a voxel several times (equivalent to DivideLeafVoxel() if iAddedDepth==1)
  // Recursive utility called by DivideVoxelUpToDepth(), handing division-lists in standard (verbose) mode
  // Since virtual method DivideNonRootLeafVoxel is internally used, some divisions may have been
  // skipped, this information can be retrieved in option (* oSomeDivisionsWereSkipped=1 in output)
  CATPolyError * RecursiveDivideVoxelUpToDepth(CATPolyVoxelPath * iVoxel, int iAddedDepth,
    int * oSomeDivisionsWereSkipped = 0);

  // Methode recursive de destruction de Voxel en dehors d'une boite donnee.
  // ATTENTION : la depth de l'Octree n'est pas remise a jour par cette methode.
  // L'appelant doit lancer la methode UpdateDepth apres cession de RemoveOctoCube 
  // si cette donnee a toujours un sens pour la suite
  HRESULT RemoveVoxelOutOfBox(CATPolyVoxelPath &iVoxelPath, double iTrimBox[6], double iCurBox[6]);
  HRESULT RemoveVoxelOutOfBox(CATPolyVoxelPath &iVoxelPath, unsigned int iTrimIJKBox[6], unsigned int iCurIJKBox[6]);
 
  // Methode virtuelle de destruction d'un VoxelClient attache a un Voxel en dehors d'un boite donnee.
  // Le traitementdu cas "a cheval" necessite des implementations specifiques selon letype d'Octree
  // sous-methode de RemoveVoxelOutOfBox()
  virtual HRESULT RemoveVoxelClientOutOfBox(CATPolyVoxelPath &iVoxelPath, double iTrimBox[6], double iCurBox[6]);
  virtual HRESULT RemoveVoxelClientOutOfBox(CATPolyVoxelPath &iVoxelPath, unsigned int iTrimIJKBox[6], unsigned int iCurIJKBox[6]);


  // -----------------------------------------------------------
  // Protected Data

  const CATPolyBasicOctree * _MasterOctree; // Octree dont l'objet courant est une vue partielle (sous-branche)
  MirrorVoxel              * _MirrorVoxelToDivide; // non nul si cet octree maitre doit etre mis a jour lors d'une 1e division de 'this'
  CATPolyCompleteVoxelPath * _PathFromMasterToRoot;
  CATBoolean                 _LockDivisionsOutsideRefVoxel; // non nul si les seules divisions autorisees sont internes a ce voxel focus-duplique

  double _InitialBox[3][2]; // box of whole element [XYZ][MinMax]
 
  // If cubic voxels are required, the above box is cubed (the largest dimension prevails)
  // if not, the initial box is simply copied into this one
  // _InitialBox and _Box have the same (Xmin,Ymin,Zmin) origin point
  int    _CubicVoxels;
  double _Box[3][2];       

  double _AtomicVoxelSize[3]; // = atomic voxel size = size when depth=15 (redundant with box size, but quicker)
  double _MinAtomicVoxelSize;

  CATPolyOctreeRoot * _RootVoxel;

  // Depth must be updated each time a voxel is divided or undivided (0 = root only, ..)
  mutable int         _UpdatedDepth;
  int                 _Depth;

  // Applicable tolerance system
  const CATTolerance & _Tol;             

private:

  // Recursive utility for IsARealVoxelCorner()
  // It is assumed that iCornerIJK may not lie outside of iRefVoxel 
  HRESULT IsASubtreeCorner(unsigned int iCornerIJK[3], CATPolyVoxelPath * iRefVoxel,
    int & oIsACorner);

  // Recursive utility of DivideInBoxUpToDepth, with iBoxToDivide contained in iVoxelBox.
  CATPolyError * RecursiveDivideVoxelInBox(CATPolyVoxelPath * iVoxel, 
    int iIsVoxelTheRoot, int * iVoxelBox, int * iBoxToDivide, int iExpectedDepth, int & ioNbDivisions);

  // -----------------------------------------------------------
  // Private Data (note that _Tag and GetTag() are defined in father class CATPolyDumpable)

  static unsigned int  _LastCreatedOctreeNumber;
  unsigned int         _LastCreatedOctoCubeTag;

  // In debug mode, a chronological list of voxel divisions is kept
  // in standard mode, this list is not stored (null pointer), it can be regenerated on demand, but chronological order is lost
  CATPolyOctreeDivisionList * _ChronoDivisionList;
    
  // Dump method invoked on voxel clients (debug only, iOwningVoxel, iOctree and context mat be ommitted if dump does not require them)
  HRESULT (*_DumpVoxelClient)(CATCGMOutput & s, int iVerbose, const CATPolyVoxel & iClient, const CATPolyBasicOctree * iOctree, void * iDumpVoxelClientContext);
  void * _DumpVoxelClientContext;

  // Optional dump method dedicated to elements attached to leaves, and associated context
  void (* _DumpLeaf)(CATCGMOutput & s, void * iData, int iVoxelNum, void * iLeafContext);
  void  * _DumpLeafContext;

  int _ThereIsAtLeastOneVoxelClient;

  int _OctoCubeWorkAreaManager; // 32 bits to manage the OctoCube WorkArea
};

inline void CATPolyBasicOctree::SetDumpVoxelClientMethod(HRESULT (*iDumpVoxelClient)(CATCGMOutput&,int,const CATPolyVoxel&,const CATPolyBasicOctree*,void*)) {
  _DumpVoxelClient = iDumpVoxelClient; }

inline void CATPolyBasicOctree::SetDumpVoxelClientContext(void * iDumpVoxelClientContext) {
  _DumpVoxelClientContext = iDumpVoxelClientContext; }  

inline CATPolyOctreeRoot * CATPolyBasicOctree::GetOctreeRootVoxel() const {
  return _RootVoxel; }

inline CATPolyOctreeDivisionList * CATPolyBasicOctree::GetChronoDivisionList() const {
  return _ChronoDivisionList; }

inline int CATPolyBasicOctree::AreThereWorkAreasOnOctoCubes() const {
  return ((_OctoCubeWorkAreaManager) ? (1) : (0)); }

inline void CATPolyBasicOctree::SetWorkAreaManager(int iWorkAreaManager) {
  _OctoCubeWorkAreaManager = iWorkAreaManager; }

inline unsigned int CATPolyBasicOctree::GetNewOctoCubeTag() {
  return (++_LastCreatedOctoCubeTag); }

inline void CATPolyBasicOctree::SetThereIsAtLeastOneVoxelClient(int iValue) {
  _ThereIsAtLeastOneVoxelClient = iValue; }

inline int CATPolyBasicOctree::AreVoxelsCubic() {
  return _CubicVoxels; }

inline const CATTolerance & CATPolyBasicOctree::GetTolerance() const {
    return _Tol;
}

inline int CATPolyBasicOctree::HasMasterOctree() const {
  return _MasterOctree ? 1 : 0;
}

inline CATPolyCompleteVoxelPath * CATPolyBasicOctree::GetFocusedVoxel() const {
  return _PathFromMasterToRoot;
}

#endif
