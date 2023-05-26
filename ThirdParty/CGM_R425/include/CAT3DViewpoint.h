#ifndef CAT3DViewpoint_H
#define CAT3DViewpoint_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @CAA2Level L1
* @CAA2Usage U1
*/

/*
* HISTORY : 
*
* 23 April 2019 - PAV1 : Added camsera blades and blade angle
*  16 Juillet 2001 - CDT : ajout d'une liste memmbre triee pour gangner en perfo lors 
* du RemoveRep/RemoveReps/RemoveFurtiveRep/RemoveFurtiveReps.
* on fait ca au niveau de viewpoint (car perfos mauvaises lors de deshighlight d'une multi-sel)
* en attendant d'utiliser des listes triees dans les CATRep.
*/

#include "SGInfra.h"

#include "CATViewpoint.h"
#include "CATProjectionType.h"
#include "CATMathDirectionf.h"
#include "CATMathPointf.h"
#include "CATMathPoint.h"
#include "CATMathPoint2D.h"

#include "CAT4x4Matrix.h"
#include "CAT3DBoundingSphere.h"
#include "CAT3DBagRep.h"
#include "CATSorted3DBagRep.h"
#include "CATSortedSetOfObject.h"
#include "CAT3DViewport.h"

#include "CATIAV5Level.h"

#ifdef _IRIX_SOURCE
class CATSupport;
#endif

#include "CATIAV5Level.h"
#include "CATBoolean.h"

class CAT3DBagRepWithBox;
class CATSceneGraph;
/**
* Type on gravity for a 3D Viewpoint.
* @param NoViewpointGravity
* The whole model can rotate in any direction
* @param SingleViewpointGravity
* The gravity direction stays vertical and up. The observator keeps his
* head vertical.
* @param UpOrDownViewpointGravity
* The gravity direction stays vertical (up or down). The observator keeps his head vertical 
* but can have it up side down.
* @see CAT3DViewpoint
*/
enum CATViewpointGravityMode { 
  NoViewpointGravity, 
  SingleViewpointGravity, 
  UpOrDownViewpointGravity};

/** 
*  Class that represents the way the 3D scene is seen.
* 
*/
class ExportedBySGInfra CAT3DViewpoint : public CATViewpoint
{
  //------------------------------------------------------------------------------
  friend class CATDmuStream3DViewpoint;
  friend class CATUpdateWatcherRep;
  friend class vVolFrameData;
  friend class CSISceneBinder;

  CATDeclareClass;

public :

  /**
  * Creates a non-initialized viewpoint. 
  * <br>At the first display (when the viewer will appears)
  * a reframe will automatically been done on the viewpoint.
  */
  CAT3DViewpoint ();

  /**
  * Creates a new viewpoint by copying geometrical values.
  * <ul>
  * <li>Eye position and orientation (Origin, SightDirection, UpDirection)
  * <li>other characteristics (Angle, Focus, ProjectionType, ProjectionDirection)
  * <li>Dynamic behaviour (Gravity mode, Clipping planes mode)
  * </ul>
  */
  CAT3DViewpoint (const CAT3DViewpoint &);

  /**
  * Creates a new viewpoint from its main characteristics.
  * @param iEye Position of the Eye
  * @param iSight Sight Direction (Direction where the observator looks at)
  * @param iUp Up direction (Direction of the observator head's top)
  * @param iNearDistance Distance from the Eye to the near clipping plane
  * @param iFarDistance Distance from the Eye to the far clipping plane
  * @param iProjectionType The Projection type
  * <ul><li>CONIC
  *     <li>CYLINDRIC
  * </ul>
  * @param iFocusDistance The distance from the Eye to the target
  */
  CAT3DViewpoint (const CATMathPointf &iEye, const CATMathDirectionf &iSight, const CATMathDirectionf &iUp,
    const float iNearDistance=1.0, const float iFarDistance=10000, CATProjectionType iProjectionType=CONIC, const float iFocusDistance=0);

  /** @nodoc */
  virtual ~CAT3DViewpoint ();

  /**
  * Copies the geometric definition of a CAT3DViewpoint.
  */
  CAT3DViewpoint & operator = (const CAT3DViewpoint &);

  /**
  * Retrieves whether viewpoint is a three dimensional one or not. 
  * @return
  * The value is always <tt>TRUE</tt>.
  */
  virtual CATBoolean Is3D();

  /** 
  * Gets the type of projection on the window.
  */
  inline CATProjectionType GetProjectionType() const;

  /**
  * Sets the type of projection.
  */
  void SetProjectionType  (CATProjectionType iType);

  /** @nodoc */
  inline void LockProjectionType(const int lock);
  /** @nodoc */
  inline int IsProjectionTypeLocked() const;

#ifdef _IRIX_SOURCE
  /** @nodoc */
  void SetMPK(CAT4x4Matrix &m);
  /** @nodoc */    
  inline void SetUpdateMPK(int i);
  /** @nodoc */    
  inline int GetUpdateMPK(void);
#endif

  /** @nodoc
  * In favor of void Set( const CATMathPoint &iEye, const CATMathDirectionf &iSight, const CATMathDirectionf &iUp);
  * Sets viewpoint location (main characteristics).
  * @param iEye Position of the Eye
  * @param iSight Sight Direction (Direction where the observator looks at)
  * @param iUp Up direction (Direction of the observator head's top)
  */
  virtual void Set( const CATMathPointf &iEye, const CATMathDirectionf &iSight, const CATMathDirectionf &iUp);

  /**
  * Sets viewpoint location (main characteristics).
  * @param iEye Position of the Eye
  * @param iSight Sight Direction (Direction where the observator looks at)
  * @param iUp Up direction (Direction of the observator head's top)
  */
  virtual void Set( const CATMathPoint &iEye, const CATMathDirectionf &iSight, const CATMathDirectionf &iUp);

  /** @nodoc
  * In favor of CATMathPoint & GetEyePosition()
  * Gets viewpoint eye position.
  * @return The Position of the Eye
  */
  inline virtual const CATMathPointf & GetOrigin () const;

  /**
  * Gets viewpoint eye position.
  * @return The Position of the Eye
  */
  inline virtual const CATMathPoint & GetEyePosition() const;

  /** @nodoc
  * In favor of SetEyePosition (const CATMathPoint &iEye)
  * Sets viewpoint eye position.
  * @param iEye Position of the Eye
  */
  virtual void SetOrigin (const CATMathPointf &iEye);

  /**
  * Sets viewpoint eye position.
  * @param iEye Position of the Eye
  */
  virtual void SetEyePosition (const CATMathPoint &iEye);

  /**
  * Gets viewpoint sight.
  * @return Sight Direction (Direction where the observator looks at)
  */
  inline virtual const CATMathDirectionf & GetSightDirection () const;

  /**
  * Sets viewpoint sight.
  * @param iSight Sight Direction (Direction where the observator looks at)
  */
  virtual void SetSightDirection (const CATMathDirectionf &iSight);

  /**
  * Gets viewpoint up.
  * @return Up direction (Direction of the observator head's top)
  */
  inline virtual const CATMathDirectionf & GetUpDirection ()const ;

  /**
  * Sets viewpoint up.
  * @param iUp Up direction (Direction of the observator head's top)
  */
  virtual void SetUpDirection (const CATMathDirectionf &iUp);

  /**
  * Gets the focus distance.
  * @return The distance from the Eye to the target.
  */
  inline virtual float GetFocusDistance() const ;

  /**
  * Sets the focus distance. 
  * @param iFocusDistance The distance from the Eye to the target
  */
  virtual void SetFocus (const float &);

  /** @nodoc */
  inline virtual float GetAngle() const ;

  /** @nodoc */
  virtual void SetAngle (const float &iAngle);

  /** @nodoc */
  inline virtual float GetAperture() const ;

  /** @nodoc */
  virtual void SetAperture (const float &iAperture);

  /** @nodoc */
  virtual const CATMathPoint2D GetSensorSize(const float iAspect) const;

  /** @nodoc */
  /* Only the height of the physical sensor size can be explicitly set. The width is calculated according to the viewport
  *  resolution aspect during the call to GetSensorSize
  */
  virtual void SetSensorSize(const float iSensorHeight);

  /** @nodoc */
  inline virtual int GetBlades() const;

  /** Sets the number of the camera blades
   *  @param iBlades The bumber of blades
   */
  virtual void SetBlades(const int iBlades);

  /** @nodoc */
  inline virtual float GetBladeRotation() const;

  /** Sets the rotation angle of the camera blades
   *  @param iBladeRotation The rotation angle of the camera blades in degrees
   */
  virtual void SetBladeRotation(const float iBladeRotation);

  /** @nodoc */
  inline void SetShutterSpeed(const float iSpeed);

  /** @nodoc */
  inline float GetShutterSpeed() const;

  /** @nodoc */
  inline float GetZoom () const ;

  /** @nodoc */
  virtual void SetZoom( const float &iZoom);

  /** @nodoc */
  //int IsEmpty() const;

  /** @nodoc
  * In favor of CATMathPoint GetTargetPosition
  * Gets the target location. 
  * <br><b>Role</b>:The target is the point situated a a Focus distance from
  * the eye of the viewpoint in the sight direction. This point can be also called focal point.
  * @return Target point 
  */
  inline virtual CATMathPointf GetTarget() const;

  /** 
  * Gets the target location. 
  * <br><b>Role</b>:The target is the point situated a a Focus distance from
  * the eye of the viewpoint in the sight direction. This point can be also called focal point.
  * @return Target point 
  */
  inline virtual CATMathPoint GetTargetPosition() const;

  /**
  * @nodoc
  * In favor of SetTargetPosition (const CATMathPoint &iTargetPosition)
  * Sets the Target.
  * <br><b>Role</b>:It changes the focus (CONIC proj type) or the origin (CYLINDRIC).
  * Sight direction stays invariant.
  */
  virtual void SetTarget( const CATMathPointf &iTargetPosition);

  /** 
  * Sets the Target.
  * <br><b>Role</b>:It changes the focus (CONIC proj type) or the origin (CYLINDRIC).
  * Sight direction stays invariant.
  */
  virtual void SetTargetPosition( const CATMathPoint &iTargetPosition);

  //------------------------------------------------------------------------------
  // Next methods to document :

  /** @nodoc */
  void SetStereoViewpoint (CAT3DViewpoint *, CAT3DViewpoint *);
  /** @nodoc */
  void GetStereoViewpoint (CAT3DViewpoint **, CAT3DViewpoint **);

  /** @nodoc */
  virtual CATViewpoint *Clone() const;
  /** @nodoc */
  virtual CATViewpoint *FullClone();
  /** @nodoc */
  virtual CATViewpoint *CloneForSlaveViewpoint();
  /** @nodoc */
  virtual CATViewpoint *Clone(CATViewpoint **) const;
  /** @nodoc */
  inline virtual const CAT3DBagRep* GetBag() const;
  /** @nodoc */
  inline virtual const CAT3DBagRep* GetBagFurtive() const;
  /** @nodoc */
  inline virtual const CAT3DBagRep* GetBagOnTop() const;
  /** @nodoc */
  inline virtual const CAT3DBagRep* GetBagPrehighlight() const;

  /** @nodoc */
  inline virtual const CAT3DBagRep* GetBagDialog() const;  

  /** @nodoc DEPRECATED (use GetSceneGraph instead) */
  inline virtual const CATSceneGraph* GetBagSG() const { return _Scene; }

  /** @nodoc Should replace GetBag at some point */
  CATSceneGraph * GetSceneGraph() const;

  //  Perspective  
  /** @nodoc */
  void SetProjectionDirection (const CATMathDirectionf &direction);
  /** @nodoc */
  inline virtual const CATMathDirectionf & GetProjectionDirection () const;
  /** @nodoc */
  void ResetProjectionDirection ();
  /** @nodoc */
  int IsProjectionDirection() const ;
  /** @nodoc  Set the sight whatever the the ProjectionDirection*/
  void SetSightDirectionAs(const CATMathDirectionf &Sight);
  /** @nodoc  Set the ProjectionDirection whatever the sight*/
  void SetProjectionDirectionAs (const CATMathDirectionf &direction);


  /** @nodoc */
  void GetFrustum (const float width, const float height, const float mmInSupportUnit, const float ratioWH, float *left, float *right, float *bottom, float *top, float *neard, float *fard);
  /** @nodoc */
  void GetAbsoluteFrustum (CATMathPointf Vertices[8], const float width, const float height, const float, const float ratioWH);

  /** @nodoc To remove in R14 and valuate default value 0 for mode*/
  void SetFrustum (const float left, const float right, const float bottom, const float top,  const float neard, const float fard);
  /** @nodoc */
  void SetFrustum (const float left, const float right, const float bottom, const float top,  const float neard, const float fard,int mode);//=0);

  //  Point of view location (secondary methods)
  /** @nodoc */
  virtual double GetCape (const CATMathDirectionf &Vertical, const CATMathDirectionf &nord) const;
  /** @nodoc */
  virtual double GetTwist (const CATMathDirectionf &Vertical) const;
  /** @nodoc */
  virtual void SetVertical( const CATMathDirectionf &Vertical);
  /** @nodoc */
  inline virtual const CATMathDirectionf & GetRightDirection () const;

  /** @nodoc */
  inline const CAT4x4Matrix &GetMatrix() const ;
  /** @nodoc */
  inline const CAT4x4Matrix &GetInverseMatrix();
  /** @nodoc */
  CAT3DViewpoint & operator *= ( const CAT4x4Matrix & );

  /**
  * Gets the gravity mode .
  */
  inline virtual CATViewpointGravityMode GetGravityMode () const;

  /**
  * Sets the gravity mode .
  * @param iGravityMode
  */
  virtual void SetGravityMode( const CATViewpointGravityMode iGravity);

  /**
  * Sets the gravity direction.
  * @return Direction in model coordinates, positive towards the up.
  */
  virtual const CATMathDirectionf & GetGravityDirection() const;

  /**
  * Sets the gravity direction.
  * @param iDirection Direction in model coordinates, positive towards the up.
  */
  virtual void SetGravityDirection( const CATMathDirectionf &iDirection);

  /** @nodoc */
  //Lock the gravity mode and the gravity direction
  //@param iGravityLock: TRUE = Lock; FALSE = Unlock
  void LockGravity( const CATBoolean iGravityLock);

  /** @nodoc */
  //Lock the gravity mode and the gravity direction
  //@return the gravity lock info.
  CATBoolean IsGravityLocked() const;

  /** @nodoc */
  //Set the head tilt angle
  //@param iRollAngle (in degree): positive value = tilt head rightward; negaitive value = tilt head leftward
  void SetRollAngle( const float iRollAngle = 0.f);

  /** @nodoc */
  //@return the head tilt angle.
  float GetRollAngle() const;

  /** @nodoc */
  virtual void Rotate( const CATMathVectorf &iRotationStep, const CATMathPointf &iCenter);
  /** @nodoc */
  virtual void ApplyGravity();

  //  Clipping planes
  /** @nodoc */
  inline void GetModelNearAndFarPlanes (float &, float &) const ;
  /** @nodoc */
  inline void SetModelNearAndFarPlanes  (const float &, const float &);
  /** @nodoc */
  inline float GetBoundedNear() const;
  /** @nodoc */
  inline void SetBoundedNear (const float);

  /** @nodoc */
  inline void UseMinimumNearAndFarPlanes  (const int &);
  /** @nodoc */
  inline void GetMinimumNearAndFarPlanes  (float &, float &);
  /** @nodoc */
  inline void SetMinimumNearAndFarPlanes  (const float &, const float &);

  /** @nodoc */
  int GetClippingMode() const;
  /** @nodoc */
  void SetClippingMode(const int); 

  /** @nodoc */
  void GetClippingValue(float *nearValue, float *farValue) const;
  /** @nodoc */
  void SetClippingValue(const float nearValue, const float farValue);

  /** @nodoc */
  float GetNearPlane() const;
  /** @nodoc */
  float GetFarPlane() const;


  /**
  * Adds a representation in the scene the observator may seen.
  * @param iRep Representation 3D
  */
  void AddRep ( CAT3DRep *iRep );

  /** 
  * Allow to add or remove rep in the dialog bag.
  * @param i_onOffFlag : switch the mode indialog mode
  **/
  void SetAddToDialogFlag(unsigned int i_onOffFlag);

  /** @nodoc */
  void AddRepForHighlight ( CAT3DRep *iRep );

  //Add a rep in the right bag of highlight reps for multicolor highlight feature
  /** @nodoc */
  void AddRepForMultiColorHighlight( CAT3DRep *rep);

  /** @nodoc */
  void AddHighlightBag ();

  /** @nodoc */
  void EndAddRepsForHighlight ();
  /**
  * Removes the representation from the furtive list.
  * @param iRep Representation 3D
  */
  void RemoveRep ( CAT3DRep *iRep );
  /** @nodoc */
  void RemoveReps ( CAT3DRep *iRep );
  /** @nodoc */
  void RemoveRepFromHighlight ( CAT3DRep *iRep );

  //Remove a rep from the right bag of highlight reps for multicolor highlight feature
  /** @nodoc */
  void RemoveRepFromMultiColorHighlight ( CAT3DRep * rep );

  /** @nodoc */
  void RemoveHighlightBag ();
  /** @nodoc */
  void EndRemoveReps ();
  /** @nodoc */
  void EndRemoveRepsFromHighlight ();

  /**
  * Adds a furtive representation in the scene the observator may seen.
  * <p> Pixels of Furtive representations may not be in the expected color but can
  * be displayed and hidden without re-drawind the whole scene. Must be used for 
  * temporary displays
  * @param iRep Representation 3D
  */
  void AddFurtiveRep ( CAT3DRep *iRep );

  /**
  * Removes the representation from the furtive list.
  * @param iRep Representation 3D
  */
  void RemoveFurtiveRep ( CAT3DRep *iRep );
  /** @nodoc */
  void RemoveFurtiveReps ( CAT3DRep *iRep );

  /**
  * @nodoc 
  * Adds a representation in the scene the observator may seen.
  * <p> Pixels of representations can
  * be displayed and hidden without re-drawind the whole scene. Must be used for 
  * temporary displays
  * @param iRep Representation 3D
  */
  void AddOnTopRep ( CAT3DRep *iRep );

  /**
  * @nodoc 
  * Removes the representation from the onTop list.
  * @param iRep Representation 3D
  */
  void RemoveOnTopRep ( CAT3DRep *iRep );
  /** @nodoc */
  void RemoveOnTopReps ( CAT3DRep *iRep );


  /** @nodoc */
  void EndRemoveFurtiveReps ();

  /** @nodoc */
  void AddPrehighlightRep ( CAT3DRep *iRep );
  /** @nodoc */  
  void RemovePrehighlightRep ( CAT3DRep *iRep );
  /** @nodoc */
  void RemovePrehighlightReps ( CAT3DRep *iRep );


  /** @nodoc */
  void EmptyHighlightBag();
  /** @nodoc */
  void EmptyMultiColorHighlightBag();

  /** @nodoc */
  //Get the list of reps for multicolor highlight
  ::list<CATRep>& GetMultiColorHighlightRepList();

  /**
  * Reframes the model in the window.
  * @param iWidth Wight of the window (in pixel)
  * @param iHeight Height of the window (in pixel)
  * @param mmInSupportUnit Inverse of the size(height) of a pixel in millimeter
  * @param ratioWH Ratio Height of a pixel / Width of a pixel
  */
  virtual void Reframe( const float iWidth, const float iHeight, const float mmInSupportUnit, const float ratioWH);
  /**
  * Reframes the model in the window.
  * @param iWidth Wight of the window (in pixel)
  * @param iHeight Height of the window (in pixel)
  * @param mmInSupportUnit Inverse of the size(height) of a pixel in millimeter
  * @param ratioWH Ratio Height of a pixel / Width of a pixel
  * @param iBs3D CAT3DBoundingSphere we want to fit on the specified position
  */
  virtual void Reframe( const float iWidth, const float iHeight, const float mmInSupportUnit, 
    const float ratioWH, const CAT3DBoundingSphere &iBs3D);

  virtual void CreateViewportFrom( const float x, const float y, const float deltaX, const float deltaY, const float supportWidth, const float supportHeight,     const float mmInSupportUnit, const float ratioWH);

  /** @nodoc */
  virtual void CreateViewport( const float supportWidth, const float supportHeight, const float mmInSupportUnit, const float ratioWH);

  /**
  * Computes the line of indication from a pixel position on the window.
  * @param iX Position in X of the point (pixel coordinates : x=0 left window)
  * @param iY Position in Y of the point (pixel coordinates : y=0 top of window)
  * @param oNearPoint Returns the nearest point (seen) of the line
  * @param oFarPoint Returns the farest point (seen) of the line
  * @param iWidth Wight of the window (in pixel)
  * @param iHeight Height of the window (in pixel)
  * @param mmInSupportUnit Inverse of the size(height) of a pixel in millimeter
  * @param ratioWH Ratio Height of a pixel / Width of a pixel
  */
  virtual void ComputeModelFromPixel( const float iX, const float iY, CATMathPointf &oNearPoint, CATMathPointf &oFarPoint, 
    const float iWidth, const float iHeight, const float mmInSupportUnit, const float ratioWH);

  /**
  * Computes the line of indication from a pixel position on the window.
  * @param iX Position in X of the point (pixel coordinates : x=0 left window)
  * @param iY Position in Y of the point (pixel coordinates : y=0 top of window)
  * @param oNearPoint Returns the nearest point (seen) of the line
  * @param oFarPoint Returns the farest point (seen) of the line
  * @param iWidth Wight of the window (in pixel)
  * @param iHeight Height of the window (in pixel)
  * @param mmInSupportUnit Inverse of the size(height) of a pixel in millimeter
  * @param ratioWH Ratio Height of a pixel / Width of a pixel
  */
  virtual void ComputeModelFromPixel (const float iX, const float iY, CATMathPoint &oNearPoint, CATMathPoint &oFarPoint, 
    const float iWidth, const float iHeight, const float mmInSupportUnit, const float ratioWH);

  /** @nodoc */
  virtual void ComputePixelFromModel( const CATMathPointf &ptModel, CATMathPoint2Df &ptPixel, const float width, const float height, const float mmInSupportUnit, const float ratioWH);

  /** @nodoc */
  virtual void ComputePixelFromModel( const CATMathPoint &ptModel, CATMathPoint2D &ptPixel, const float width, const float height, const float mmInSupportUnit, const float ratioWH);


  /** @nodoc */
  virtual float GetScaleFactor( const float width, const float height, const float mmInSupportUnit, const float ratioWH);

  /**
  * Gets the bounding sphere of all non-furtive representation of the scene.
  * @return CAT3DBoundingSphere
  */ 
  CAT3DBoundingSphere GetBoundingSphere();

  /** @nodoc */
  inline int IsMain3DViewpoint ();
  /** @nodoc */
  inline void SetMain3DViewpoint(const int IsMain);

  /** @nodoc */
  virtual int SizeOf();

  /** @nodoc */
  void ComputePerspectiveTranslation();

  /** @nodoc */
  void ComputeProjectionMatrix   (const float width, const float height,
    const float ratioWH, CAT4x4Matrix &projection_matrix);

  /** @nodoc */
  virtual void Stretch(int x1, int y1, int x2, int y2);

  /** @nodoc */
  virtual void Modify();

  /** @nodoc */
  void SetNearFar(const float supportWidth, const float supportHeight, const float mmInSupportUnit);

#ifdef _IRIX_SOURCE
  /** @nodoc */
  inline void SetMPKViewpoint(CAT3DViewpoint *v);
  /** @nodoc */
  inline CAT3DViewpoint *GetMPKViewpoint(void);
  /** @nodoc */  
  inline void SetRightViewpoint(CAT3DViewpoint *v);
  /** @nodoc */  
  inline CAT3DViewpoint *GetRightViewpoint(void);  
  /** @nodoc */  
  inline void SetLeftViewpoint(CAT3DViewpoint *v);
  /** @nodoc */  
  inline CAT3DViewpoint *GetLeftViewpoint(void);    
#endif

  //------------------------------------------------------------------------------

  /** @nodoc */
  virtual void AttachIndicator(CATIndicator* indicator);

  /** @nodoc */    
  void SetShadowBag(CAT3DBagRepWithBox*);
  /** @nodoc */    
  CAT3DBagRepWithBox* GetShadowBag();

  /** @nodoc */
  void SetIndirectAxisMode();
  /** @nodoc */
  inline unsigned int IsIndirectAxisMode();

  /**
  * @nodoc
  * @see CATIVisRootNode#AddRep
  */
  virtual HRESULT AddRep (CATRep& i_rep, CATVisRepresentationRole i_repType);
  /**
  * @nodoc
  * @see CATIVisRootNode#RemoveRep
  */
  virtual HRESULT RemoveRep (CATRep& i_rep, CATVisRepresentationRole i_repType, int i_updateFlag=TRUE);
  /**
  * @nodoc
  * @see CATIVisRootNode#ComputeBoundingElement
  */
  virtual HRESULT ComputeBoundingElement (CATVisRepresentationRole i_repType=AllRoles);
  /**
  * @nodoc
  * @see CATIVisRootNode#RemoveAll
  */
  HRESULT RemoveAll (CATVisRepresentationRole i_repType);
  /**
  * @nodoc
  * @see CATIVisRootNode#Is3D
  */
  int Is3D()const;

   /**
  * @nodoc
  * Copies the geometric definition of a CAT3DViewpoint.
  */
  void CopyForSynchro (const CAT3DViewpoint &);

  /** @nodoc */
  inline CATMathVector const& GetWorldScale() const;

  /** @nodoc */
  void SetWorldScale(CATMathVector const&);

  //Varjo
  /** @nodoc */
  void SetInnerStereoViewpoint(CAT3DViewpoint *, CAT3DViewpoint *);
  /** @nodoc */
  void GetInnerStereoViewpoint(CAT3DViewpoint **, CAT3DViewpoint **);

protected :
  /** */
  CATMathPointf _EyePosition;		// viewpoint position
  /** @nodoc */
  CATMathPoint _EyePositiond;		// viewpoint position
  /** @nodoc */
  CATMathPoint _working_point[7];	 
  /** @nodoc */
  CATMathDirectionf _working_direction[6];

  CATMathDirectionf _Sight;	// VPN or View Plane Normal (VPN)
  CATMathDirectionf _Up;		// Up direction (will be projected Verticaly on screen)  
  CATMathDirectionf _Right;	// right direction  
  // Main viewpoint
  /** @nodoc */
  int _IsMain;  /** @win64 fbq : 64-bit structure padding **/

  /** @nodoc */
  CAT4x4Matrix _matrix, _invert;	// projection matrix

  CATMathVector _worldScale;

  /** @nodoc */
  float _near_min;
  /** @nodoc */
  float _far_max;	//clipping plane length (>0 devant)
  /** @nodoc */
  float _near_bounded;

  /** @nodoc */
  float _angleD;		// angle of vision
  /** @nodoc */
  float _angle;
  /** @nodoc */
  float _aperture;
  /** @nodoc */
  float _focus;		//  distance of sight in _Sight direction (>=0)
  /** @nodoc */
  float _sensorHeight; //mm

  // Exposure time of the camera. Used for motion blur and does not affect overall brightness of the rendering output 
  /** @nodoc */
  float _shutterSpeed;

  /** @nodoc */
  int _blades;
  /** @nodoc */
  float _bladeRotationAngle; // in degrees

  // Clipping Planes
  /** @nodoc */
  int _ClippingMode;
  /** @nodoc */
  float _NearPlaneValue;
  /** @nodoc */
  float _FarPlaneValue;	

  // Projection
  /** @nodoc */
  CATProjectionType _projection; // CONIC or CYLINDRIC
  /** @nodoc */
  int _projection_type_lock;

  /** @nodoc */
  void Orthogonalize();

  // Gravity
  /** @nodoc */
  CATMathDirectionf _GravityDirection;
  /** @nodoc */
  CATViewpointGravityMode _GravityMode;
  /** @nodoc */
  CATBoolean _GravityLocked;

  // Roll angle
  /** @nodoc */
  float _RollAngle;

  // Perspective
  /** @nodoc */
  CATMathVectorf _PerspectiveTranslation;
  /** @nodoc */
  CATMathDirectionf _ProjectionDirection;
  /** @nodoc */
  int _assym_proj;

  CATSceneGraph * _Scene; // new SG API.

  // Bag
  /** @nodoc */
  CAT3DBagRep* _Bag;
  /** @nodoc */
  CAT3DBagRep* _dialogBag;
  /** @nodoc */
  unsigned int _addToDialogFlag;

  /** @nodoc */
  CAT3DBagRep* _BagFurtive;

  /** @nodoc */
  CAT3DBagRep* _BagOnTop;

  /** @nodoc */
  CAT3DBagRep* _BagPrehighLight;

  /** @nodoc */
  CATSorted3DBagRep* _EnglobingHighlightBag;

  // Multicolor Highlight feature
  /** @nodoc */
  CATSorted3DBagRep*	_EnglobingMultiColorHighlightBag;
  /** @nodoc */
  ::list<CATRep>*		_multiColorHighlightRepList;

  //CAT3DBagRep _EnglobingHighlightBag;

  /** @nodoc */
  CAT3DViewpoint *_leftVP;
  /** @nodoc */

  CAT3DViewpoint *_rightVP;
  /** @nodoc */
  float _frustum[6];

  /************* Varjo new viewpoints *******/
  /** @nodoc */
  CAT3DViewpoint *_inLeftVP;
  /** @nodoc */
  CAT3DViewpoint *_inRightVP;
  /******************************************/
  
private:

  /** @nodoc */
  void ComputePerspectiveTranslation(bool iUseIndirectAxis);
    
  // Internal use only for rotate ; should deseapear
  /** @nodoc */
  virtual double GetTrim (const CATMathDirectionf &Vertical) const;

  /** @nodoc */
  static void _CopyRep(CAT3DViewpoint * iSrc, CAT3DViewpoint * iDst);

  /** @nodoc */
  CAT3DViewport GetViewportFromFrustum();

  /** @nodoc */
  /** on va utiliser une liste triee lors du Remove sur le viewpoint */
  CATSortedSetOfObject *_Children;

#ifdef _IRIX_SOURCE

private :
  CAT3DViewpoint     *_mpkViewpoint;
#endif
  int		     _useFrustum;

  int _useMinimumNearAndFarPlanes;
  float _minimumNearPlane;
  float _minimumFarPlane;

  /** @nodoc */
  unsigned int _indirectAxisMode;

  //=========================================================================================  
public :

  /** @nodoc */
  CATDeclareCBEvent (VIEWPOINT3D_DESTROYED); //Event sent when the viewpoint is destroyed.

public:
  /** @nodoc */
  void InitializeSlaveStereoViewpoint(CAT3DViewpoint* iVp);
  /** @nodoc */
  inline bool IsWorldUniformlyScaled() const;

};

//------------------------------------------------------------------------------

inline void CAT3DViewpoint::SetBoundedNear (const float near_bounded)
{
  _near_bounded = near_bounded;
}

inline float CAT3DViewpoint::GetBoundedNear () const
{
  return (_near_bounded);
}

inline CATProjectionType CAT3DViewpoint::GetProjectionType () const
{
  return (_projection);
}

inline void CAT3DViewpoint::LockProjectionType(const int lock)
{
  _projection_type_lock = lock;
}

inline int CAT3DViewpoint::IsProjectionTypeLocked() const
{
  return (_projection_type_lock);
}

inline void CAT3DViewpoint::GetModelNearAndFarPlanes (float &neard, float &fard) const
{
  neard = _near_min;
  fard  = _far_max;
}

inline void CAT3DViewpoint::SetModelNearAndFarPlanes (const float &neard, const float &fard)
{
  _near_min = neard;
  _far_max  = fard;
}

inline const CAT4x4Matrix & CAT3DViewpoint::GetMatrix () const
{
  return (_matrix);
}

inline const CAT4x4Matrix & CAT3DViewpoint::GetInverseMatrix ()
{
  return (_invert);
}

inline float CAT3DViewpoint::GetFocusDistance () const
{
  return (_focus);
}

inline float CAT3DViewpoint::GetZoom () const
{
  float tmp = _focus * _angle;
  if (tmp == 0.0f)
  {
    return  (1.f);
  }
  else
  {
    return  (1.f / tmp);
  }
}

inline const CATMathPointf & CAT3DViewpoint::GetOrigin () const
{
  return (_EyePosition);
}

inline const CATMathPoint & CAT3DViewpoint::GetEyePosition () const
{
  return (_EyePositiond);
}

inline const CATMathDirectionf & CAT3DViewpoint::GetUpDirection () const
{
  return (_Up);
}

inline const CATMathDirectionf & CAT3DViewpoint::GetSightDirection () const
{
  return (_Sight);
}

inline const CATMathDirectionf & CAT3DViewpoint::GetRightDirection () const
{
  return (_Right);
}

inline const CATMathDirectionf & CAT3DViewpoint::GetProjectionDirection() const
{
  return (_ProjectionDirection);
}

inline CATMathPointf CAT3DViewpoint::GetTarget() const
{
  return (_EyePosition + _Sight * _focus);
}

inline CATMathPoint CAT3DViewpoint::GetTargetPosition() const
{
  CATMathVector sight(_Sight.x, _Sight.y, _Sight.z);
  return (_EyePositiond + sight * _focus);
}

inline float CAT3DViewpoint::GetAngle () const
{
  return (_angleD);
}

inline float CAT3DViewpoint::GetAperture () const
{
  return (_aperture);
}

inline void CAT3DViewpoint::SetShutterSpeed(const float iSpeed)
{
  _shutterSpeed = iSpeed;
}
inline float CAT3DViewpoint::GetShutterSpeed() const
{
  return _shutterSpeed;
}

inline int CAT3DViewpoint::GetBlades () const
{
  return _blades;
}

inline float CAT3DViewpoint::GetBladeRotation () const
{
  return _bladeRotationAngle;
}

inline CATViewpointGravityMode CAT3DViewpoint::GetGravityMode () const
{
  return _GravityMode;
}

inline int CAT3DViewpoint::IsMain3DViewpoint ()
{
  return (_IsMain);
}

inline void CAT3DViewpoint::SetMain3DViewpoint(const int IsMain)
{
  _IsMain = IsMain;
}


inline const CAT3DBagRep* CAT3DViewpoint::GetBag() const
{
  return _Bag;
}

inline const CAT3DBagRep* CAT3DViewpoint::GetBagFurtive() const
{
  return _BagFurtive;
}

inline const CAT3DBagRep* CAT3DViewpoint::GetBagOnTop() const
{
  return _BagOnTop;
}

inline const CAT3DBagRep* CAT3DViewpoint::GetBagPrehighlight() const
{
  return _BagPrehighLight;
}

inline const CAT3DBagRep* CAT3DViewpoint::GetBagDialog() const
{
  return _dialogBag;
}

#ifdef _IRIX_SOURCE
inline CAT3DViewpoint *CAT3DViewpoint::GetMPKViewpoint(void)
{
  return _mpkViewpoint;
}

inline void CAT3DViewpoint::SetMPKViewpoint(CAT3DViewpoint *v)
{
  _mpkViewpoint = v;
}
inline CAT3DViewpoint *CAT3DViewpoint::GetRightViewpoint(void)
{
  return _rightVP;
}

inline void CAT3DViewpoint::SetRightViewpoint(CAT3DViewpoint *v)
{
  _rightVP = v;
}
inline CAT3DViewpoint *CAT3DViewpoint::GetLeftViewpoint(void)
{
  return _leftVP;
}

inline void CAT3DViewpoint::SetLeftViewpoint(CAT3DViewpoint *v)
{
  _leftVP = v;
}

#endif

inline unsigned int CAT3DViewpoint::IsIndirectAxisMode()
{
  return _indirectAxisMode;
}

inline void CAT3DViewpoint::UseMinimumNearAndFarPlanes  (const int & iUseMinimumNearAndFarPlanesMode)
{
  _useMinimumNearAndFarPlanes = iUseMinimumNearAndFarPlanesMode;
}

inline void CAT3DViewpoint::GetMinimumNearAndFarPlanes  (float & oMinimumNearPlane, float & oMinimumFarPlane)
{
  oMinimumNearPlane = _minimumNearPlane;
  oMinimumFarPlane = _minimumFarPlane;
}

inline void CAT3DViewpoint::SetMinimumNearAndFarPlanes  (const float & iMinimumNearPlane, const float & iMinimumFarPlane)
{
  _minimumNearPlane = iMinimumNearPlane;
  _minimumFarPlane = iMinimumFarPlane;
}

inline CATMathVector const& CAT3DViewpoint::GetWorldScale() const
{
  return _worldScale;
}

inline bool CAT3DViewpoint::IsWorldUniformlyScaled() const
{
  // ideally should do a tolerance check, but when uniform scale is set
  // bits should match.
  return (_worldScale.GetX() == _worldScale.GetY() && _worldScale.GetX() == _worldScale.GetZ()) != 0;
}

#endif
