#ifndef CAT3DRep_H
#define CAT3DRep_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @CAA2Level L1
* @CAA2Usage U1
*/

#include "CATRep.h"
#include "CAT3DBoundingSphere.h"
#include "SGInfra.h"

class CATMappingOperator;
class CATGraphicMaterial;
class CATOutlineBuilder;
class CATStreamer;
class CATGraphicPrimitive;

//++ SGCAAPlan
#include "CATVisMacroForInterfaces.h"
class IVisSG3DNode;
class CAT3DRepIVisSG3DNodeBOAImpl;
//-- SGCAAPlan

//++ E8C : Multi Materials
class CATMaterialApplication;
//++ E8C : Multi Materials


/**
* Class to create a 3D representation of an application object.
* <b>Role</b>: This class is the base class for all 3D representation classes.
* It manages specific 3D behavior, such as
* <ol>
*<li> 3D bounding element </li>
*<li> streaming </li>
*<li> outline builder </li>
*<li> materials </li>
* </ol>
*/
class ExportedBySGInfra CAT3DRep : public CATRep
{

  friend class CATMarshallable3DRep;
  friend class CATDmuStream3DRep;
  friend class SGCGRStreamerFor3DRep;
  friend class CAT3DVoxelVolumeRep;
  friend class CAT3DReferencePlaneRep;
  friend class CATVizUVRRep;
  friend class CAT3DBagRep;
  friend class CAT3DCuboidRep;
  friend class CAT3DPointRep;
  friend class CAT3DPointCloudRep;
  friend class CATVizBasePathElementRep;
  friend class CATVid3DBagRep;
  friend class VisPrimitiveGroupRep;
  friend class CAT3DLDHGeomRep;
  friend class CAT3DArcEllipseRep;
  friend class CAT3DLineRep;
  friend class CAT3DCloudOfPointsRep;
  friend class CAT3DCurvedPipeRep;
  friend class CAT3DMirrorRep;
  friend class CAT3DGeomRep;
  friend class CAT3DCylinderRep;
  friend class CAT3DUniformLatticeRep;
  friend class CATGroundRep;
  friend class CAT3DLightSourceRep;
  friend class CAT3DLodRep;
  friend class CAT3DSimpleSphereRep;
  friend class CATVizVoxelRep;
  friend class CATVisActor;
  friend class CAT3DCanonicalRep;
  friend class CATVizMonoWireRep;
  friend class CATVizVertexBufferRep;
  friend class CAT3DAxisRep;
  friend class CAT3DCurveRep;
  friend class CAT3DCustomRep;
  friend class CAT3DPlanRep;
  friend class CAT3DFinalRep;
  friend class CATParticleSystemRep;

  CATDeclareClass;
  CATVisDeclarePublicInterfaceAdhesion(CAT3DRep, IVisSG3DNode, CAT3DRepIVisSG3DNodeBOAImpl);

public:

  /** Constructs an empty 3D representation. */
  static CAT3DRep* CreateRep();

  virtual ~CAT3DRep();

  BEGIN_MIGRATE_REP_CTOR_PRIVATE
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 06072022 " __FILE__ " Use CreateRep to instantiate the class OR CAT3DFinalRep if you want to derive this class" )
#endif

  /** @deprecated R422 CAT3DRep::CreateRep */
  CAT3DRep();

  /** @nodoc : deprecated constructor */
  CAT3DRep(CATModelIdentificator &id,void *ctrl=NULL);
  END_MIGRATE_REP_CTOR

  /** Sets the bounding element of the representation.
  * @param iBoundingSphere
  * The (smallest) bounding element containing the representation.
  */
  virtual void SetBoundingElement(const CAT3DBoundingSphere & iBoundingSphere);

  /** Adds the given bounding element to the existing one.
  * @param iBoundingSphere
  * The current bounding element of the representation will be modified to
  * contain <tt>iBoundingSphere</tt>.
  */
  virtual void AddBoundingElement(const CAT3DBoundingSphere & iBoundingSphere);

  /** Returns the bounding element of the representation. */
  inline const CAT3DBoundingSphere & GetBoundingElement () const {return (_bound_elt);};

  /** Returns the bounding element of the representation. */
  const CAT3DBoundingSphere & GetBoundingElement ();

#if defined (_IRIX_SOURCE) || defined (_WINDOWS_SOURCE)
  /**
  * Returns the bounding element pointer ...
  */
  inline CATBoundingElement * GetBoundingCube (void);
#endif

  /** Computes the bounding element of the representation.
  * The bounding element should be the smallest possible sphere containing the representation.
  * @param iShowSpace
  * <br><b>Legal Values</b>:
  * <ol>
  *<li> 0 :  </li>
  *<li> 1 :  </li>
  * </ol>
  */
  virtual void ComputeBoundingElement(int iShowSpace=1);

  /** Resets the bounding element of representation.
  *  The visualization manager will ignore the representation.
  */
  void ResetBoundingElement();

  /** Invalidates the bounding element of the representation.
  * The visualization manager will recompute the bounding element of the representation. */
  virtual void SetInvalid();

  // Compute the BE for the noshow space
  /** @nodoc */ 
  virtual const CAT3DBoundingSphere &GetNoshowBoundingElement (int & ioIsOneRepNoshow) ;
  // Compute the BE for the Show space
  /** @nodoc */ 
  virtual const CAT3DBoundingSphere &GetShowBoundingElement () ;
  /** @nodoc */
  virtual int IsInvalid();

  /** 
  * @nodoc 
  * Saves the representation data in a stream.
  * @param oStream
  * Stream in which to save the representation data.
  * @param iSaveType
  *
  */
  virtual void Stream(CATStreamer & oStream, int iSaveType = 0);

  /** 
  * @nodoc 
  * Restores the representation data from a stream.
  * @param iStream
  * Stream from which the representation data is restored.
  */
  virtual void UnStream(CATStreamer & iStream);

  /** 
  * @nodoc
  * Returns the outline builder of the representation.
  * The representation retains ownership of the outline builder. Do not delete it.
  */
  virtual CATOutlineBuilder * GetOutlineBuilder();

  /** Sets the heritance mode for the applied material.
  * @param iInheritance
  * <ol>
  *<li> MATERIAL_NOT_INHERIT : children reps will not have this rep's material </li>
  *<li> MATERIAL_INHERIT :  children reps will have automaticly this rep's material</li>
  *<li> MATERIAL_FORCE_INHERIT : same as INHERIT, but even when a father has the INHERIT flag</li>
  * </ol>
  */
  virtual void SetMaterialInheritance(int iInheritance);

  /**
  * @return
  * Returns the inheritance mode for the material applied to the rep.
  */
  virtual int GetMaterialInheritance();

  /** Sets the validity of texture coordinates.
  * @param iState
  * <ol>
  *<li> 0 : TC invalid, they will be computed at next Draw </li>
  *<li> 1 : TC valid </li>
  * </ol>
  */
  virtual void SetIsValidTC(int iState);

  /** Return the validity of texture coordinates.
  */
  virtual int GetIsValidTC();

  /** Deletes the existing list of MaterialApplication and creates a new one with this unique material.
  * @param iMaterial
  * Material that will compose the new list of MaterialApplication.
  */
  virtual void SetGraphicMaterial(CATGraphicMaterial * iMaterial);

  /** Returns the material applied to the 3DRep, after resolution of the list of MaterialApplication, according to new materials inheritance rules.
  * @return
  * Returns the applied material.
  */
  CATGraphicMaterial * GetGraphicMaterial() const;

  /** @nodoc */
  virtual void UpdateTextureCoordinates(CATMappingOperator* iOperator = NULL);

  /** @nodoc */
  virtual int IsUVMeshToCompute() const;

  /** @nodoc */
  virtual void SetLayerNumber(int iLayer);

  /** @nodoc */
  virtual int GetLayerNumber();

  /** @nodoc */
  virtual void SetCGMId(unsigned int iId);

  /** @nodoc */
  virtual unsigned int GetCGMId();

  /** @nodoc */
  virtual CATGraphicPrimitive* GetGeomElement(int iIndice);

  /** @nodoc */
  // RepViewMode set on this 3DRep will be applied on it and all its children ONLY IF:
  // #1. VIEW_REP_OVERLOAD is enabled for the Viewer 
  //  Currently it is disabled if ViewerViewMode contains any of the modes below:
  //      - VIEW_COLORED_EDGES_FROM_FACES
  //      - VIEW_LINEONLINE
  //      - VIEW_HLR
  //      - VIEW_TRANSPARENT
  //      - VIEW_POLYGON
  //      - VIEW_ISOPARS
  //      - VIEW_TOON
  // #2. RepViewMode is not set to REP_VIEW_DISABLED (0x0)
  //      In such a case, ViewerViewMode will be effective for the rep.
  // #3. No parent of this node is applied with the CATVisRepViewModeFilter
  // #4. No parent of this node is applied with the RepViewMode through this API
  //      In such a case, RepViewmode set on any child rep will be discarded. RepViewMode of the parent will be effective for the rep.
  // #5. The only RepViewMode combinations accepted by this API are : (defined in CATRep.h)
  // - REP_VIEW_DISABLED 
  // - REP_VIEW_NOTHING
  // - REP_VIEW_MESH
  // - REP_VIEW_EDGE
  // - REP_VIEW_MESH | REP_VIEW_EDGE
  // - REP_VIEW_POLYGON
  // - REP_VIEW_EDGE | REP_VIEW_OUTLINE
  // - REP_VIEW_MESH | REP_VIEW_EDGE | REP_VIEW_OUTLINE
  // - REP_VIEW_HRD  
  // - REP_VIEW_HRD | REP_VIEW_HIDDEN_EDGE
  // #6. The following RepViewModes containing REP_VIEW_OUTLINE (explicit or implicit) won't be taken into account if the ViewerViewMode does not contain VIEW_OUTLINE:
  // - REP_VIEW_EDGE | REP_VIEW_OUTLINE
  // - REP_VIEW_MESH | REP_VIEW_EDGE | REP_VIEW_OUTLINE
  // - REP_VIEW_HRD
  // - REP_VIEW_HIDDEN_EDGE | REP_VIEW_HRD
  //      In such a case, ViewerViewMode will be effective for the rep.  
  virtual void SetViewMode (const int iViewMode, const int iActive,const int iWindowViewModeSensitive=0);

  /** @nodoc */
  virtual int ViewMode (const int oViewMode=0xFFFF,int * oWindowViewModeSensitive=NULL) const;

  /** @nodoc */
  // The only pick mode accepted by this method are : (defined in CATRep.h)
  // - REP_PICK_NOTHING
  // - REP_PICK_MESH
  // - REP_PICK_EDGE
  // - REP_PICK_MESH | REP_PICK_EDGE
  // If the CATViewer is set to one of this view mode, the rep view mode
  // won't be taken into account :
  // - VIEW_OUTLINE
  // - VIEW_HLR
  // - VIEW_POLYGON
  // - VIEW_ISOPARS
  // - VIEW_TOON
  virtual void SetRepPickMode (const int iPickMode, const int iActive);

  /** @nodoc */
  virtual int GetRepPickMode (const int oPickMode=0xFFFF) const;

  /** @nodoc */
  // 0 contexte inconnu
  // 1 lorsque le _CGMId correspond à un #ele  (contexte Feature)
  // 2 lorsque le _CGMId correspond à un CGMId (contexte CGM)
  virtual void SetNamingContext (int iNamingContext);

  /** @nodoc */
  virtual int GetNamingContext ();

  /** @nodoc */
  virtual int IsA3DRep();

  /** @nodoc */
  virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

  /** 
  * Returns the list of CATMaterialApplication.
  * @return
  * Returns the list of CATMaterialApplication.
  */
  const ::list<CATMaterialApplication>& GetListOfMaterialApplication() const;

  /** 
  * Adds a new CATMaterialApplication to the list.
  * @param iMatApp
  * CATMaterialApplication to be added to the list.
  * Makes a AddReference() on the material contained in the CATMaterialApplication.
  */
  void AddMaterialApplication( const CATMaterialApplication &iMatApp );

  /** 
  * Removes a CATMaterialApplication from the list.
  * @param iMatApp
  * CATMaterialApplication to be removed from the list.
  * Makes a SubReference() on the material contained in the CATMaterialApplication.
  */
  void RemoveMaterialApplication( const CATMaterialApplication &iMatApp );

  /** 
  * Removes a CATMaterialApplication from the list.
  * @param ipMatApp
  * CATMaterialApplication pointer, known to belong to the list, and to be removed from it.
  * Makes a SubReference() on the material contained in the CATMaterialApplication.
  */
  void RemoveMaterialApplication( const CATMaterialApplication* ipMatApp );

  /** 
  * Returns the effective CATMaterialApplication applied to the 3DRep, after resolution of the list of CATMaterialApplication, according to new materials inheritance rules.
  * @return
  * Returns the applied CATMaterialApplication.
  */
  CATMaterialApplication * GetMaterialApplication() const;

  /** 
  * Removes all CATMaterialApplication from the list. */
  void RemoveAllMaterialApplication();

  /** 
  * Sets the layer of the effective CATMaterialApplication applied to the 3DRep.
  * @param iLayer
  * input layer to be set.
  */
  virtual void SetTopMaterialLayer(const CATULONG32 iLayer);

  /** 
  * Gets the layer of the effective CATMaterialApplication applied to the 3DRep.
  * @return
  * Returns the layer.
  */
  virtual const CATULONG32 GetTopMaterialLayer() const;

  /** 
  * Sets a UV translation to the CATMaterialApplication applied to the 3DRep, in both U and V directions */
  void SetUVTranslation( float translate_u, float translate_v );
  /** 
  * Gets the UV translation from the CATMaterialApplication applied to the 3DRep, in both U and V directions */
  void GetUVTranslation( float& translate_u, float& translate_v ) const;

  /** 
  * Sets a UV rotation angle to the CATMaterialApplication applied to the 3DRep, which has to be in radian */
  void SetUVRotation( float angle );
  /** 
  * Gets the UV rotation angle from the CATMaterialApplication applied to the 3DRep, which is in radian */
  void GetUVRotation( float& angle ) const;

  /** 
  * Sets an uniform UV scale to the CATMaterialApplication applied to the 3DRep, which has to be positive */
  void SetUVScale( float scale );
  /** 
  * Gets the uniform UV scale from the CATMaterialApplication applied to the 3DRep, which is positive */
  void GetUVScale( float& scale ) const;

protected:
  /** Tests whether the representation will draw its graphic primitives.
  * See CATRep::OkToDraw(CATRender & iRender, int * ioInside)
  */
  int OkToDraw(CATRender & ioRender, int * ioInside);

  CAT3DBoundingSphere   _bound_elt;       // bounding element

  /** 
  * list of CATMaterialApplication
  * It is semi-resolved : at any time, the effective CATMaterialApplication applied to the 3DRep,
  * according to new materials inheritance rules, is at the queue of the list.
  */
  ::list<CATMaterialApplication> 	_MatAppList;

private:

  unsigned int _CGMId;

  unsigned int         _isValidTC           : 1; // validity of texture coordinates
  unsigned int         _LayerNumber         :16;
  unsigned int         _view_mode           : 5;
  unsigned int         _pick_mode           : 5;
  unsigned int         _view_mode_sensitivity : 1;
  unsigned int         _naming_context      : 2;

};

#if defined (_IRIX_SOURCE) || defined (_WINDOWS_SOURCE)
inline CATBoundingElement *CAT3DRep::GetBoundingCube (void)
{
  return (CATBoundingElement *) &_bound_elt;
}
#endif

#endif // CAT3DRep_H
