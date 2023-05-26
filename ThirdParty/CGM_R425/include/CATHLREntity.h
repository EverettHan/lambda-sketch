/* -*-C++-*-*/
#ifndef CATHLREntity_H
#define CATHLREntity_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLREntity 
//
// DESCRIPTION :
/**
 * Entity of the model that will be used by the HLR. 
 * <BR> This object can be a V4 topological object or a CGM topological object.
 * <BR> This object includes a transformation ( on which will point all the
 * included objects), which can be NULL when no transformation is needed.
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Jan. 1998 HKL Creation            
// Jun. 1999 HKL Added the GetBox, IsSolid methods
// Sep. 1999 HKL Added the Save, GetIdentificationTAG methods
// Nov. 1999 HKL Added the Rep entity type
//
//=============================================================================

// For Windows NT
#include "HLRModele.h"

// For inheritance
#include "CATHLRObject.h"

// Other includes
#include "CATHLRBodyId.h"
#include "CATHLRTransformation.h"
#include "CATHLRConstant.h"

#include "CATTolerance.h" // XScale
#include "CATBoolean.h" 
#include "CATSysBoolean.h" 

#include "CATDataType.h"

class CATGeometry;
class CATHLRChainEdge; 
class CATHLRChainFace; 
class CATHLRContainer;
class CATHLRContainerEntity;
class CATHLREdge;
class CATHLREdgeIterator;
class CATHLRFace;
class CATHLRFaceIterator;
class CATHLRObjectLinker;
class CATHLRTemporaryFactory;
class CATMathBox;

class CATHLREntityPOL;
class CATHLREntityV4;
class CATHLREntityCGM;
class CATHLRPolyXBody;
class CATHLRPolyWireLyingOn;

class CATHLRContainerObject;
class CATHLRMemoryManager;
class CATHLRTemporaryContainer;
class CATSoftwareConfiguration;

class CATMapOfPtrToPtr;
class CATMapOfPtrToInt;


class ExportedByHLRModele CATHLREntity : public CATHLRObject
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Constructor from a jele, a container and a transformation that will
 * be copied.
 */
  CATHLREntity(int                          iJele,
	             CATHLRBodyId                 iIdentity,
               CATHLRContainerEntity      * iContainer,
               const CATHLRTransformation * iTransformation, 
               CATSoftwareConfiguration   * iSofwareConfig=0,
               const int                    iPrioGroup = 0);

/**
 * Constructor : from a pointer on a object supposed to be a body, a
 * container and a transformation that will be copied.
 * oldest configuration (CGMVersion=0) will be considered if iSoftwareConfig is set to null
 */
  CATHLREntity(void                       * iBody,
	             CATHLRBodyId                 iIdentity,
               CATHLRContainerEntity      * iContainer,
               const CATHLRTransformation * iTransformation, 
               CATSoftwareConfiguration   * iSofwareConfig=0,
               const int                    iPrioGroup = 0);

/**
 * Destructor
 */
  virtual ~CATHLREntity();

//=============================================================================
// METHODS TO READ THE ENTITY
//=============================================================================
/** Builds an iterator on the faces. The given object is initialized.
 */
  virtual void GetFaces(CATHLRFaceIterator & oFaceIterator) const;

/** Builds an iterator on the edges. The given object is initialized.
 */
  virtual  void GetEdges(CATHLREdgeIterator & oEdgeIterator) const;

/** Gets the number of 1D and 2D cells
 */
  inline CATLONG32 GetCountFaces();
  inline CATLONG32 GetCountEdges();


/** Retrieves the tolerance associated to the object.
 */  
  virtual const CATTolerance * RetrieveEntityTolerance() const;
  

/** Gets the identity of the body
 */
  inline CATHLRBodyId  GetIdentity() const;

/** Internal use only
 */
  inline CATHLRMemoryManager * GetMemoryManager();

/** Gets the priority group of the body
 */
  inline int GetGroupPriority() const;

/** Sets the priority group of the body
 */
  inline void SetGroupPriority(const int iGroupIdx);

/** Set / Read the activation status (Scene management)
 */
  inline void EnableEntity();
  inline void DisableEntity();
  inline int IsEnabled();

/** Gets the body's box
 */
  virtual void GetBox(CATMathBox & oBox) const;

/** Clears all the temporary objects in the entity
 */
  virtual void Clear();

/** Instanciate the internal data in case of light build
 */
  virtual void CompleteBuild();


/* Gets the container objects
 */  
  inline CATHLRContainerObject * GetContainerObject() const;

/* Gets a temporary factory
 */
  CATHLRTemporaryFactory * GetTemporaryFactory() const;

/* Gets the temporary container
 */
  inline CATHLRTemporaryContainer * GetTemporaryContainer() const;

  /* Gets the map of HLR Cells to CGM ID if body is polyhedral CATBody
 */
  inline CATMapOfPtrToPtr * GetMapOfPolyCellToCell() const;

/** Gets a pointer on the transformation used by the entity.
 */
  inline const CATHLRTransformation * GetTransformation() const;

/** Retrieves the linked object from their number (igra or tag). Returns null if
 * not found.
 */
  virtual CATHLREdge * GetEdge(int iTagEdge) const;
  virtual CATHLRFace * GetFace(int iTagFace) const;
  CATHLREdge * GetHLREdge(void * iClientDataEdge);
  CATHLRFace * GetHLRFace(void * iClientDataFace);

/** Gets the values of the transformation matrix (array[12]).
 */
  void GetTransformationValues(double * oArray) const;

/** Gets the igra of the object for the computation.
 */

  virtual CATINTPTR GetIgra() const;

/** Updates the table of references for faces and edges.
 */
  virtual void UpdateReferences();

/** Gets the tolerance associated to the object.
 */
  virtual double GetTolerance() const;

/** Gets the entity version
 */
  enum Version {V4, V5, Rep, PolyBody, PolyXBody, UnknownVersion};
  virtual CATHLREntity::Version GetVersion() const;

/** Tells if the body is a solid or a skin.
 */
  virtual CATLONG32 IsSolid() const;

/** Gets the V5 tag for V5 bodies and the igra for V4 bodies
 */
  virtual CATINTPTR GetIdentificationTAG() const;

/** Save the body with the specified name (only for V5 bodies)
 */
  virtual void Save(const char * iFileName) const;

  virtual int PreProcess(CATHLRConstant::TypeProjection iTypeOfView, double * ClippingWindow = 0);
  
  virtual CATHLREntityPOL * CastToEntityPOL();

  virtual CATHLREntityV4 * CastToEntityV4();

  virtual CATHLREntityCGM * CastToEntityCGM();

  virtual CATHLRPolyXBody * CastToPolyXBody();


  //=============================================================================
  // SILHOUETTE COMPUTATION METHODS
  //=============================================================================
  
  virtual HRESULT ComputeFacesSilhouetteSubdivision(double iObserverViewRef[3], CATHLRConstant::TypeProjection iViewType, double iResDot, CATBoolean iPolyBodySilhouetteRequired,
                                                    CATMapOfPtrToPtr * &oHLRFaceToChainOfSubFaces, CATMapOfPtrToInt * &oHLRFaceToViewOrientation);

  CATHLRPolyWireLyingOn * GetSilhouetteWireLyingOn();
  virtual CATHLRPolyWireLyingOn * GetMissingBorderWireLyingOn();


protected:

//=============================================================================
// PROTECTED METHODS
//=============================================================================

  /** Creation du container et du Manager d'allocation (surcharge du new des CATHLRObject)
  */
  void BuildContainer(int * iEstimatedSize=0);

  /** Adds a face in the entity
  */
  void AddFace(CATHLRFace * iNewFace);

  /** Adds a edge in the entity
  */
  void AddEdge(CATHLREdge  * iNewEdge);

  /** For the addition of a face or edge in the entity
  */
  CATHLRChainEdge * CreateChainEdge();
  CATHLRChainFace * CreateChainFace(); 

  /** For debug...
  */
  virtual void DumpStream(ostream & oOutput, int iDepth = 0);


//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:

  // Container for all the objects in the entity
  CATHLRContainerObject       * _ContainerObjects;

  // Pointer on the memory manager of the container
  CATHLRMemoryManager         * _MemoryManager;


  // Transformation associated to the instance and all the included objects.
  CATHLRTransformation * _Transformation;

  // Identity of the entity
  CATHLRBodyId           _Identity;

  // Pointer on a chain of faces and edges
  /*CATHLRChainFace*/CATHLRFace * _FirstChainFace;
  /*CATHLRChainEdge*/CATHLREdge * _FirstChainEdge;

  // Pointer on the current end
  CATHLRChainFace * _CurrentEndFace;
  CATHLRChainEdge * _CurrentEndEdge;

  // Hash table for the edges an faces
  CATHLRObjectLinker * _LinkTable;

  // Container for the temporary objects
  CATHLRTemporaryContainer * _TemporaryContainer;

  // Map of HLR Cells to CGM ID if body is polyhedral CATBody
  CATMapOfPtrToPtr *_MapOfPolyCellToCell;

  // Number of faces
  CATLONG32              _CountFaces;
  CATLONG32              _CountEdges;

  private :

    struct HLREntSceneManagement
    {
      // Priority group of the body
      // The lower the value, the higher the priority
      // An entity whose priority is under that of another entity cannot hide parts of it
      signed int      _groupPriority : 15;
      unsigned int    _isEnabled     :  1;
    };
    HLREntSceneManagement _SceneData;
};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================

inline CATHLRMemoryManager * CATHLREntity::GetMemoryManager() {
  return _MemoryManager; }

inline CATHLRBodyId CATHLREntity::GetIdentity() const {
  return _Identity; }

//------------------------------------------------------------
inline int CATHLREntity::GetGroupPriority() const {
  return (int) _SceneData._groupPriority; }

inline void CATHLREntity::SetGroupPriority(const int iGroupIdx) {
  _SceneData._groupPriority = iGroupIdx; }

//------------------------------------------------------------
inline void CATHLREntity::EnableEntity() {
  _SceneData._isEnabled = 1; }

inline void CATHLREntity::DisableEntity() {
  _SceneData._isEnabled = 0; }

inline int CATHLREntity::IsEnabled() {
  return _SceneData._isEnabled ; }

//------------------------------------------------------------

inline const CATHLRTransformation * CATHLREntity::GetTransformation() const {
  return _Transformation; }

//------------------------------------------------------------

inline CATLONG32 CATHLREntity::GetCountFaces() {
  return _CountFaces; }

//------------------------------------------------------------

inline CATLONG32 CATHLREntity::GetCountEdges() {
  return _CountEdges; }

//------------------------------------------------------------
inline CATHLRContainerObject * CATHLREntity::GetContainerObject() const {
  return _ContainerObjects; }

/* Gets the temporary container
 */
inline CATHLRTemporaryContainer * CATHLREntity::GetTemporaryContainer() const {
  return _TemporaryContainer; }

inline CATMapOfPtrToPtr * CATHLREntity::GetMapOfPolyCellToCell() const {
  return _MapOfPolyCellToCell; }

#endif
