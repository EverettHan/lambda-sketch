#ifndef CATViewpoint_H
#define CATViewpoint_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//
// CATIA Version 5 Release 1 Framework Visualisation
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract : 	Point of view of the user 
//------------------------------------------------------------------------------
// Usage :	To visualize a model, the viewer needs models representations
//		and user s point of view. 
//              Viewpoint can be visualized in a viewer.
//              Representations can be added to a viewpoint.
//------------------------------------------------------------------------------
// Main methods :
//
//	Mains attributes
//	    GetZoom/SetZoom : Zoom value
//
//	Bounds
//	    GetMinimumZoomBound/GetMaximumZoomBound/SetZoomBounds
//
//	Modelization modification
//	    BeginModification/EndModification 	: Use them when modified viewpoint in several calls
//	    StartAnimation/StopAnimation 	: Use them in interactive viewpoint modification and
//		animation
//		
//------------------------------------------------------------------------------
// Class :	CATViewpoint
//		  CATEventSubscriber (SYSTEM Framework)
//------------------------------------------------------------------------------

#include "SGInfra.h"

#include "CATCallbackManager.h"
#include "CATVPPriorityEnum.h"

#include "list.h"
#include "CATBoolean.h"
#include "CATVisRepresentationRole.h"
#include "CATVisInvalidationToken.h"
#include "CATUnicodeString.h"

class CATRep;
class CATPooledDisplayList;
class CATViewport;
class CATMathPointf;
class CATMathPoint;
class CATMathPoint2Df;
class CATIndicator;
class CATDLPool;
class CATVisuTexture;
class CATViewer;
/** @nodoc */
class CATVizViewer;
class CATRepPath;
/** @nodoc */
class CATVisuTextureInfo;
class CATVizViewer;

/**
 *  A viewpoint represents the scene to be seen and the position of the 
 *  observer.
 *  This scene will be displayed in a window.
 */  
class ExportedBySGInfra CATViewpoint : public CATEventSubscriber
{
//------------------------------------------------------------------------------
 /** @nodoc */
   CATDeclareClass; 
   friend class SGInfraToVisuFConnectToolImpl;

  public :

//  Constructors
    /** Create a non-initialized viewpoint. At the first display, a reframe will automatically 
      * been done. */
    CATViewpoint ();
    /** Create a viewpoint from another one. */                   
    CATViewpoint (const CATViewpoint &iViewpoint);
    /** @nodoc */
    CATViewpoint ( const float iZoom);

//  Destructors 
 /** @nodoc */
    virtual ~CATViewpoint ();

 /** @nodoc */
    virtual CATCallbackManager * GetCallbackManager();

//  Operator
    /** Copy of zoom only. */
    CATViewpoint & operator = (const CATViewpoint &);
    
   /**
    * Retrieves whether viewpoint is a three dimensional one or not. 
    * @return
    *  <ul>
    *  <li><tt>TRUE</tt>: the viewpoint is a @href CAT3DViewpoint </li>
    *  <li><tt>FALSE</tt>: The viewpoint is not a 3D viewpoint. </li>
    * </ul>
    */
    virtual CATBoolean Is3D();

//  Zoom
  /**
    * Gets the zoom value.
    * <br>
    * <b>role</b>:
    * This method should be used only on a CAT2DViewpoint. <br>
    * In order to zoom in or out on a CAT3DViewpoint, you should use
    * something like:
    * <pre>
    *  CATMathVectorf t = 0.1 * theViewpoint.GetFocusDistance() * theViewpoint.GetSightDirection();
    *  CATMathPointf Target = theViewpoint.GetTarget();
    *  theViewpoint.SetOrigin( theViewpoint.GetOrigin() + t);
    *  theViewpoint.SetFocus( theViewpoint.GetOrigin().DistanceTo(Target));
    * @href  CAT3DViewpoint#GetTarget
    * @href  CAT3DViewpoint#SetTarget
    * @href  CAT3DViewpoint#GetOrigin
    * @href  CAT3DViewpoint#SetOrigin
    * @href  CAT3DViewpoint#GetFocusDistance
    * @href  CAT3DViewpoint#GetSightDirection
    * </pre>
    * This code zooms in by a small factor. In fact, it moves the Viewpoint origin
    * forward, so that you are 10% closer to the model. The reference distance is the
    * distance to the Target.
    * <br>
    * @see CAT3DViewpoint
   */
    virtual float GetZoom () const ;
    
  /** @nodoc */
    virtual void SetZoom( const float &iZoom) = 0;

//  Zoom bounds
 /** @nodoc */
    virtual float GetMinimumZoomBound() const;
 /** @nodoc */
    virtual float GetMaximumZoomBound() const;
 /** @nodoc */
    virtual void SetZoomBounds( const float iMinimum=1.e-10, const float iMaximum=1.e+10);

    /**
     * Declares the begining of the transaction.
     * <br>
     * It is necessary the enclose with Begin and End
     * if the viewpoint is modified with severals methods
     */
    virtual void BeginModification ();

    /**
     * Declares the end of the transaction.
     * <br>
     * After the translation, an event 
     * VIEWPOINT_MODIFIED is sent (by callbacks)
     * @param iNotify The notification is sent (default) or not (when we want a reframe
     * at the first display of the viewer.
     */
    virtual void EndModification (const int iNotify=1);


    /**
     * Declares the begining of the manipulation of the viewpoint. 
     * <br>
     * It is necessary the do begin/end animation when several steps are
     * displayed consecutively.
     * At the start, an event VIEWPOINT_ANIMATION_STARTED is sent
     * @param  iFrom Not used
     */
    virtual void StartAnimation (void *iFrom);

    /**
     * Declares the end of the manipulation of the viewpoint. 
     * <br>
     * At the stop, an event VIEWPOINT_ANIMATION_STOPED is sent.
     * @param iFrom Not used
     */
    virtual void StopAnimation  (void *iFrom);

    /**
     * Animation query.
     */
    inline int IsAnimated();


   /** Gets the CATViewer associated to the viewpoint. */
    CATViewer *GetViewer() const;

   /**
    * @nodoc
    * Sets the CATViewer associated to the viewpoint.
    * @param  iViewer A pointer to the CATViewer to associate to the viewpoint
	*/
    void SetViewer (CATVizViewer *iViewer);

   /**
    * @nodoc
	* Gets the CATVizViewer associated to the viewpoint.
	*/
    CATVizViewer *GetVizViewer() const;

/** 
*  Changes the viewpoint configuration so that all representation are visible.
*  @param width            width in pixel
*  @param height           height in pixel
*  @param mmInSupportUnit  precision on wich you display, in mm per unit
*  @param ratioWH          ratio of a pixel on the display ( width/hright )
*/
    virtual void Reframe(const float width, const float height, const float mmInSupportUnit, const float ratioWH) = 0;
/** @nodoc */
    virtual void CreateViewportFrom(const float x, const float y, const float deltaX, const float deltaY, 
      const float supportWidth, const float supportHeight, const float mmInSupportUnit, const float ratioWH) = 0;

/** @nodoc */
    virtual void CreateViewport(const float supportWidth, const float supportHeight, const float mmInSupportUnit, const float ratioWH) = 0;

//  Clone does not copy the representations pointed neither viewport and display list.
//
    /** For internal use */
/** @nodoc */
    virtual CATViewpoint * Clone() const = 0;
/** @nodoc */
    virtual CATViewpoint * FullClone() = 0;
/** @nodoc */
    virtual CATViewpoint * Clone(CATViewpoint **) const = 0;
/** @nodoc */
    inline int IsMalloced();
/** @nodoc */
    inline void IsMalloced(int);
 
/** @nodoc */
    ::list<CATRep> & GetRepList();     
/** @nodoc recover the dialog rep list*/
    ::list<CATRep> & GetDialogRepList();     
/** @nodoc */
    ::list<CATRep> & GetFurtiveRepList();
/** @nodoc */
    ::list<CATRep> & GetOnTopRepList();
/** @nodoc */
    ::list<CATRep> & GetPrehighlightRepList();
/** @nodoc */
    ::list<CATRep> &GetHighlightRepList();
/** @nodoc */
    inline void SetRepList(::list<CATRep> *);     
    /** @nodoc */
    inline void SetFurtiveRepList(::list<CATRep> *);
    /** @nodoc */
    inline void SetOnTopRepList(::list<CATRep> *);
/** @nodoc */
    inline void SetPreHighlightRepList(::list<CATRep> *);
/** @nodoc */
    inline void  SetRatioWH (const float);
/** @nodoc */
    inline float GetRatioWH ( void);
/** @nodoc */
    virtual void Stretch(int x1, int y1, int x2, int y2);

/** @nodoc */
    int IsEmpty() const;

/** @nodoc */
    CATViewport	*GetViewport() const;
/** @nodoc */
    void SetViewport(CATViewport *);

/** @nodoc */
   CATPooledDisplayList *GetDisplayListToFill() const;
   /** @nodoc */
   void SetDisplayListToFill(CATPooledDisplayList *);
   
   /** @nodoc */
   const ::list<CATPooledDisplayList>&	GetFilledDisplayList();
   /** @nodoc */
   void AddFilledDisplayList(CATPooledDisplayList *);
   /** @nodoc */
   void ResetFilledDisplayListList();
   /** @nodoc */
   //void SetFilledDisplayListList(list<CATPooledDisplayList>*);
   /** @nodoc */
   void ResetFilledDisplayList();
   /** @nodoc */
   void DoNotResetFilledDisplayList();
   /** @nodoc */
   int IsResetFilledDisplayListAllowed();


   /** @nodoc */
   virtual CATPooledDisplayList* GetPooledDisplayList();
   /** @nodoc */
   CATPooledDisplayList* GetPooledDisplayList3D(unsigned int drawtype=0);
   /** @nodoc */
   CATPooledDisplayList* GetPooledDisplayList2D(unsigned int drawtype=0);

   /** @nodoc */
   void SetDisplayListPool(CATDLPool*);
   
   /** @nodoc */
   virtual CATDLPool* GetDisplayListPool();

/** Computes the line going from the eye to a pixel position ( for insatnce the mouse position ) in model corrdinate system.
@param x       horizontal position in pixel
@param y       vertical position in pixel
@param neard   intersection of the line going from the eye through the x-y position and the near plane
@param fard    intersection of the line going from the eye through the x-y position and the far plane
@param width   width in pixel of the visible space
@param height  height in pixel of the visible space
@href  CATViewer#GetGraphicSize
@param mmInSupportUnit precision on wich you display, in mm per unit
@href  CATSupport#GetMMInSupportUnit
@param ratioWH  ratio of a pixel on the display ( width/hright )
@href  CATSupport#GetRatioWH
*/
    virtual void ComputeModelFromPixel (const float x, const float y, CATMathPointf &neard, CATMathPointf &fard, 
      const float width, const float height, const float mmInSupportUnit, const float ratioWH) = 0;

/** Computes the line going from the eye to a pixel position ( for insatnce the mouse position ) in model corrdinate system.
@param x       horizontal position in pixel
@param y       vertical position in pixel
@param neard   intersection of the line going from the eye through the x-y position and the near plane
@param fard    intersection of the line going from the eye through the x-y position and the far plane
@param width   width in pixel of the visible space
@param height  height in pixel of the visible space
@href  CATViewer#GetGraphicSize
@param mmInSupportUnit precision on wich you display, in mm per unit
@href  CATSupport#GetMMInSupportUnit
@param ratioWH  ratio of a pixel on the display ( width/hright )
@href  CATSupport#GetRatioWH
*/
    virtual void ComputeModelFromPixel (const float x, const float y, CATMathPoint &neard, CATMathPoint &fard, 
      const float width, const float height, const float mmInSupportUnit, const float ratioWH);

/** Computes the pixel position at wich a given point is displayed .
@param pt_model A CATMathPoint 
@param pt_pixel
@param width   width in pixel of the visible space
@param height  height in pixel of the visible space
@param mmInSupportUnit precision on wich you display, in mm per unit
@param ratioWH  ratio of a pixel on the display ( width/hright )
*/
    virtual void ComputePixelFromModel (const CATMathPointf &pt_model, CATMathPoint2Df &pt_pixel, 
      const float width, const float height, const float mmInSupportUnit, const float ratioWH) = 0;

/** @nodoc */
    int IsInitDone() const;
/** @nodoc */
    virtual float GetScaleFactor(const float width, const float height, const float mmInSupportUnit, const float ratioWH) = 0;

/** @nodoc */
    virtual int SizeOf() = 0;
    
/** @nodoc */
    virtual void Modify();

/** Specifies whether we display the show space or the noshow space. */
  void SetShowSpace(int iShowState);
/** Returns 1 if we display the Show Space. */
   int IsShowSpace();

   //management of the printing state
   /** @nodoc */
   void SetPrintingState(int iPrintingState);
   /** @nodoc */
   int GetPrintingState();
   /** @nodoc */
   void SetStretched(int iStreached);
   /** @nodoc */
   int IsStretched ( void);

   // Management of an indicator attached to the viewpoint
   // If an indicator is attached to a Viewpoint, it is this indicator that is going to be taken in account
   // when a setmainviewpoint will be done on this wiewpoint.
   // If no indicator is attached, the viewer contains a 2DIndicator and a 3Dindicator, it is this ones which
   // are goind to be used.
   /** @nodoc */
   CATIndicator* GetIndicator();

	/** @nodoc */
	virtual void AttachIndicator(CATIndicator* indicator);

	/** @nodoc */
	int  IsDefaultIndicatorAttached();

	/** @nodoc */
	void AttachDefaultIndicator();

	/** @nodoc */
	void ResetIndicator();

	// management of priority on viewpoint
	/** @nodoc */
	int GetPriority();

	/** @nodoc */
	void SetPriority(CATVPPriority priority);

	/** @nodoc */
  void UnreferenceViewpointFromManager();
//-----------------------------------------------------------------------------

 // la position et la dimension de glViewport
/** @nodoc */
    inline void	GetGLViewport(int & x, int & y, int & dx, int & dy);
/** @nodoc */
    inline void SetGLViewport(const int x, const int y, const int dx, const int dy);
/** @nodoc */
    inline void GetAccurateGLViewport(float& x, float& y, float& dx, float& dy);
/** @nodoc */
    inline void SetAccurateGLViewport(const float x, const float y, const float dx, const float dy);
//------------------------------------------------------------------------------

	/** @nodoc */
	void RefreshBoundingElement();

     /** @nodoc */
    inline void SetPLMViewMode(int iPLMViewMode);

    /** @nodoc */
    inline int GetPLMViewMode();

    /** @nodoc */
    inline unsigned char IsMainDialogViewpoint();

    /** @nodoc */
    inline void SetMainDialogViewpoint();

    /** @nodoc */
    inline unsigned char IsV3DViewpoint();

    /** @nodoc */
    inline void SetV3DViewpoint();

    /** @nododc */
    HRESULT AddVIDRep(CATRep& i_rep, CATVisRepresentationRole i_repType);
    /** @nododc */
    HRESULT RemoveVIDRep(CATRep& i_rep, CATVisRepresentationRole i_repType, int i_updateFlag = 1);
    /** @nododc */
    CATBoolean ContainsVIDReps();

    /** @nodoc */
    void EmptyVisuTextures(int iType=-1);
    /** @nodoc */
    CATVisuTexture* GetVisuTexture(int iID);
    /** @nodoc */
    CATVisuTexture* GetVisuTexture(const CATVisuTextureInfo& iTextureInfo);
    /** @nodoc */
    int AddVisuTexture(CATVisuTexture* iVisuTexture, int iRemoveSameVisuInfo = 0);
    /** @nodoc */
    void SetSpriteUpToDateFlag(int i_spriteUpToDateFlag);
    /** @nodoc */
    int GetSpriteUpToDateFlag();
   
   /**
    * @nodoc
    * @see CATIVisRootNode#AddRep
    */
    virtual HRESULT AddRep (CATRep& i_rep, CATVisRepresentationRole i_repType);
   /**
    * @nodoc
    * @see CATIVisRootNode#RemoveRep
    */
    virtual HRESULT RemoveRep (CATRep& i_rep, CATVisRepresentationRole i_repType, int i_updateFlag=1);
   /**
    * @nodoc
    * @see CATIVisView#Invalidate
    */
    virtual HRESULT Invalidate(CATVisInvalidationToken i_invalidationToken, CATVisRepresentationRole i_repType=AllRoles);
   /**
    * @nodoc
    * @see CATIVisRootNode#ComputeBoundingElement
    */
    virtual HRESULT ComputeBoundingElement (CATVisRepresentationRole i_repType);
   /**
    * @nodoc
    * @see CATIVisRootNode#ComputeBoundingElement
    */
    virtual HRESULT RemoveAll (CATVisRepresentationRole i_repType);
   /**
    * @nodoc
    */
    void DrawElement   (CATRepPath &iPath);
   /**
    * @nodoc
    */
    void UndrawElement (CATRepPath &iPath);
   /**
    * @nodoc
    */
    void EndDrawElement(unsigned int saveRenderBuffer);
   /**
    * @nodoc
    */
    void DrawElements  (::list<CATRepPath> &iPaths);
   /**
    * @nodoc
    */
    void UndrawElements(::list<CATRepPath> &iPaths);
   /**
    * @nodoc
    */
    void BeginDrawElement();

     /**
    * @nodoc
    */
    void CopyForSynchro (const CATViewpoint &);

  public :
    
    enum VisAAMode
    {
      VIS_USE_SETTINGS,
      VIS_FORCE_ON,
      VIS_FORCE_OFF
    };

  public :
    /**
     * @nodoc
     */
    void SetAAMode(VisAAMode iMode);

    /**
     * @nodoc
     */
    VisAAMode GetAAMode() const;
 
    /** @nodoc */
    void SetAlgo(const char* iResources, const char* iPass, const char* iCameras);

    /** @nodoc */
    const char* GetAlgo(int iType) const;

  protected :

/** @nodoc */
    float _zoom, _ratioWH;     		// Zoom
/** @nodoc */
    float _MinimumZoom; 		// Zoom minimun
/** @nodoc */
    float _MaximumZoom; 		// Zoom maximun
/** @nodoc */
    int	_OnModification, _Modified;
/** @nodoc */
    int _Animated;

/** @nodoc */
    ::list<CATRep> *dialogRep_;
/** @nodoc */
    ::list<CATRep> *rep_;
/** @nodoc */
    ::list<CATRep> *furtiveRep_;
/** @nodoc */
    ::list<CATRep> *onTopRep_;
/** @nodoc */
    ::list<CATRep> *prehighlightRep_;
/** @nodoc */
    ::list<CATRep> *highlightRep_;

   /** @nodoc 
    * MPCulling */
   CATDLPool*    _displayListPool;
   
   /** @nodoc 
    * MPCulling */
   CATPooledDisplayList *_displayListToFill;
   /** @nodoc 
    * MPCulling */
   ::list<CATPooledDisplayList>* _filledDisplayListList;

//   list<CATPooledDisplayList>* _filledDisplayListList;

/** @nodoc */
    CATViewport	*viewport_;
/** @nodoc */
    CATVizViewer	*viewer_;

    // show/noshow state
/** @nodoc */
    int _IsShowSpace;

    /** @nodoc */
    VisAAMode _aaMode;


//------------------------------------------------------------------------------
  private :

/** @nodoc */
    int	initDone_;
/** @nodoc */
    CATCallbackManager *_CallbackManager;
/** @nodoc */
    int _IsMalloced;
/** @nodoc */
    int _RestoreEdge;
/** @nodoc */
    int _isPrintable;
/** @nodoc */
  int _isStretched;

/** @nodoc */
  CATIndicator* _indicator;
/** @nodoc */
  int _isDefaultIndicator;

/** @nodoc */
    int _priority;

/** @nodoc */
    int _px, _py, _dx, _dy; // la position et la dimension de glViewport
/** @nodoc */
    float _pxf, _pyf, _dxf, _dyf; // la position et la dimension precises de glViewport
    
/** @nodoc */
    int _plmViewMode;
/** @nodoc */
    unsigned char _mainDialogViewpointFlag;
/** @nodoc */
    unsigned char _v3dViewpointFlag;
    /** @nodoc */
    unsigned int   _VIDRepsCpt;

    /** @nodoc */
    ::list<CATVisuTexture> _visuTextures;
    /** @nodoc */
    unsigned int   _spriteUpToDateFlag;

    /** @nodoc */
    CATUnicodeString _algo[3];

    int _resetFilledDisplayList;

    
//------------------------------------------------------------------------------
  public :

    /**
     * Event sent when the viewpoint change.
     */
    CATDeclareCBEvent (VIEWPOINT_MODIFIED);    

    /** @nodoc */
    CATDeclareCBEvent (VIEWPOINT_ANIMATION_STARTED);

    /** @nodoc */
    CATDeclareCBEvent (VIEWPOINT_ANIMATION_STOPED);

    /** @nodoc */
    CATDeclareCBEvent (VIEWPOINT_DESTROYED); //Event sent when the viewpoint is destroyed.

    /** @nodoc */
    CATDeclareCBEvent (VIEWPORT_MV_MODIFIED);

    /** @nodoc */
    CATDeclareCBEvent (VIEWPOINT_ALGO_MODIFIED);

    /** @nodoc */
    CATDeclareCBEvent (VIEWPOINT_ACTION_ENDED);
};

/** @nodoc */
inline int CATViewpoint::IsAnimated()
{
 return (_Animated);
}

/** @nodoc */
inline int CATViewpoint::IsMalloced()
{
 return (_IsMalloced);
}

/** @nodoc */
inline void CATViewpoint::IsMalloced(int n)
{
 _IsMalloced = n;
}

/** @nodoc */
inline void CATViewpoint::SetRepList(::list<CATRep> *rep)
{
 rep_ = rep;
}

/** @nodoc */
inline void CATViewpoint::SetFurtiveRepList(::list<CATRep> *rep)
{
 furtiveRep_ = rep;
}

/** @nodoc */
inline void CATViewpoint::SetOnTopRepList(::list<CATRep> *rep)
{
  onTopRep_ = rep;
}

/** @nodoc */
inline void CATViewpoint::SetPreHighlightRepList(::list<CATRep> *rep)
{
  prehighlightRep_ = rep;
}

/** @nodoc */
inline void CATViewpoint::SetRatioWH (const float ratioWH) 
{
 _ratioWH = ratioWH;
}

/** @nodoc */
inline float CATViewpoint::GetRatioWH ( void) 
{
  return  _ratioWH;
}

/** @nodoc */
inline void	CATViewpoint::GetGLViewport(int & x, int & y, int & dx, int & dy)
{
   x = _px; y = _py; dx = _dx; dy = _dy;
}

/** @nodoc */
inline void CATViewpoint::SetGLViewport(const int x, const int y, const int dx, const int dy)
{
   _px = x; _py = y; _dx = dx; _dy = dy;
   _pxf = (float)x; _pyf = (float)y; _dxf = (float)dx; _dyf = (float)dy;
   if (_CallbackManager)_CallbackManager->DispatchCallbacks(VIEWPORT_MV_MODIFIED(),NULL,this);
}

/** @nodoc */
inline void	CATViewpoint::GetAccurateGLViewport(float& oX, float& oY, float& oDx, float& oDy)
{
  oX = _pxf; oY = _pyf; oDx = _dxf; oDy = _dyf;
}

/** @nodoc */
inline void CATViewpoint::SetAccurateGLViewport(const float iX, const float iY, const float iDx, const float iDy)
{
  _pxf = iX; _pyf = iY; _dxf = iDx; _dyf = iDy;
}

/** @nodoc */
inline void CATViewpoint::SetPLMViewMode(int iPLMViewMode)
{
    _plmViewMode = iPLMViewMode;
}

/** @nodoc */
inline int CATViewpoint::GetPLMViewMode()
{
    return _plmViewMode;
}

/** @nodoc */
inline unsigned char CATViewpoint::IsMainDialogViewpoint()
{
  return _mainDialogViewpointFlag;
}

/** @nodoc */
inline void CATViewpoint::SetMainDialogViewpoint()
{
    _mainDialogViewpointFlag = 1;
}

/** @nodoc */
inline unsigned char CATViewpoint::IsV3DViewpoint()
{
  return _v3dViewpointFlag;
}

/** @nodoc */
inline void CATViewpoint::SetV3DViewpoint()
{
  _v3dViewpointFlag = 1;
}

#endif
