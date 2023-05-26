// COPYRIGHT Dassault Systemes 2004
#ifndef CATPLMCompass_H
#define CATPLMCompass_H

#include <CATLib.h>
#include <CATBaseUnknown.h>
#include <CATBaseUnknown_var.h>
#include <CATDrawView.h>
#include <CATDynHashDico.h>
#include <CATDynHashTable.h>
#include <CATListOfCATString.h>
#include <CATPLMCompassMode.h>
#include <CATRepPath_WR.h>
#include <CATListPV.h>
#include <CATPLMCompassWestToolbar.h>
#include "CATPLMCompassStyle.h"
#include "CATIAfrPLMCompass.h"


class CATCSO;
class CAT2DViewpoint;
class CATVizViewer;
class CATPLMCompassModel;
class CATPixelImage;
class CATPLMCompassWidget;
class CATPLMCompassWidgetButton;
class CATPLMCompassWidgetCombo;
class CATPLMCompassWidgetGhost;
class CATPLMCompassWidgetMode;
class CATPLMCompassWidgetLegend;
class CATPLMCompassWidgetTool;
class CATPLMCompassWidgetSlider;
class CATPLMCompassWidgetLegend;
class CATTextOverlayView;

CATLISTP_DECLARE( CATPLMCompassWidgetLegend );
typedef CATLISTP( CATPLMCompassWidgetLegend ) CATListOfWidgetLegend;

#define CATPLMCompassStyleAnim 0x00000001

enum CATPLMCompassAnimState
{
    ForcePlayAnimation  =  1,
    ForcePauseAnimation =  2
};

/**
 * CATPLMCompass.
 * The compass interactive object, agregates the text overlay view that displays information
 * from compass selected 'mode'.
 **/
class ExportedByCATPLMCompass CATPLMCompass: public CATDrawView
{
	friend class CATPLMCompassWidget;
	friend class CATPLMCompassController;
	CATDeclareClass;
public:	
  /**
	 * Constructor
	 **/
	CATPLMCompass(const CATString &iName);
	/**
	 * Constructor
	 **/
	CATPLMCompass( CATVizViewer *iViewer, const CATString &iName, int iStyle= 0 );
	/**
	 * Destructor
	 **/
	virtual ~CATPLMCompass( void );
	/**
	 * Change current mode
	 **/
	void SetMode( const CATPLMCompassMode &iMode );
	/**
	 * Change current LiveShape mode
	 **/
	void SetModeDesign( const CATPLMCompassMode &iMode );
	/**
	 * Get current mode
	 **/
	const CATPLMCompassMode &GetMode(void) const;
	/**
	 * Change in PlayOnly Mode
	 **/
	void SetPlayerOnlyDesign();
	/**
	 * Get PlayerOnly mode
	 **/
	const CATBoolean GetPlayerOnlyDesign();
	/**
	 * Set text overlay model in docked mode
	 **/
	void SetModel( CATPLMCompassModel *iModel );
	/**
	 * Get text overlay
	 **/
	CATTextOverlayView *GetTextOverlay(void);
	/**
	 * Notification of mode change
	 **/
	CATNotification *GetModeChangeNotification(void);
	/**
	 * Set player position and play mode
	 * iPosition is between 0.0 and 1.0
	 * iPlay is 0 for pause, 1 for play
	 **/
	void SetPlayer( float iPosition, int iPlay );
	/**
	 * Get player position and play mode
	 **/
	void GetPlayer( float &oPosition, int &oPlay ) const;
	/**
	 * Set legend visibility (legend will show only if enabled)
	 **/
	void SetLegendVisibility( int iVisibility );
	/**
	 * Get legend visibility
	 **/
	int GetLegendVisibility( void ) const { return _legendVisible; };
	/**
	 * Set Enable/Disable legend state
	 **/
	void SetLegend( int iLengendActive );
	/**
	 * Get Enable/Disable legend state
	 **/
	int GetLegend( void ) const { return _legendEnable; };
	/**
	 * GetToolbar
	 */
	CATPLMCompassWestToolbar *GetToolbar() {return _westToolbar;}
	/**
	 * Set toolbar visibility (toolbar will show only if enabled)
	 **/
	void SetToolbarVisibility( int iVisibility );
	/**
	 * Get toolbar visibility
	 **/
	int GetToolbarVisibility( void ) const { return _toolbarVisible; };
	/**
	 * Make toolbar visible
	 **/
	void MakeToolbarVisible();

  /**
   * Set refinement panel visibility
   **/
  virtual void SetRefinementPanelVisibility(  const int & iVisibility );
  /**
   * Get refinement panel visibility
   **/
  virtual int GetRefinementPanelVisibility( void ) const;

	/**
	 * UpdateModeWest (if the toolbar is empty, don't show the "ModeWestDesign")
	 **/
	void UpdateModeWest();
	/**
	 * Set player visibility
	 **/
	void SetPlayerVisibility( int iVisibility );
	/**
	 * Get player visibility
	 **/
	int GetPlayerVisibility(void) const { return _playerVisible; };
	/**
	 * Get tooltip
	 **/
	CATUnicodeString GetTooltip( void );

  virtual CATBoolean IsSynchronizedModeActivated() const {return FALSE;};

	// DBE Aug 2007 +
	CATString GetTooltipIconName( void );
	CATUnicodeString GetTooltipLink( CATCommand* widget );
	CATCommand* GetCurrentWidget(CATNotification*& oToolTipLinkNotification);
	// DBE Aug 2007 -

	/**
	 * Attach to an object
	 **/
	void Attach( CATBaseUnknown *iObject );
	/**
	 * Detach from an object
	 **/
	void Detach( CATBaseUnknown *iObject );
	/**
	 * Get compass attached to an object
	 **/
	static CATPLMCompass *GetCompass( CATBaseUnknown *iObject );
	/**
	 * Attach the compass to a 3D point.
	 * iPath is the rep path that will be used to compute transformation to apply to iPoint
	 * iPoint is the 3D point coordinate in the axis system defined by the transformation matrix
	 * computed by CATRepPath. Most commonly the bounding sphere center of the rep of the object
	 * to which the compass is attached to.
	 * Sample:
	 *
		CATPLMCompass *compass= CATPLMCompass::GetCompass( CAT3DNFrmWindow::GetCurrentWindow() );
		if( compass && iPathElement )
		{
			CATRepPath rp;
			for( int i= 0; i<iPathElement->GetSize(); i++ )
			{
				CATI3DGeoVisu_var visu( (*iPathElement)[i] );
				if( !!visu )
				{
					CATRep *rep= visu->GetRep();
					if( rep )
					{
						rp.AddRep( *rep );
					}
				}
			}
			compass->SetAnchor( rp, CATMathPointf() );
			compass->SetPosition( CATPLMCompass::Anchored );
		}
	 *
	 **/
	HRESULT SetAnchor( const CATRepPath &iPath, const CATMathPointf &iPoint );
	/**
	 * Detach the compass from 3D point, and put it back to its normal position
	 **/
	HRESULT UnsetAnchor( void );
	/**
	 * enum for position modes
	 **/
	enum Position
	{
		Anchored= 1,
		Docked= 2
	};
	/**
	 * Select anchored of docked mode (SetAnchor must be called first before using the Anchor mode)
	 **/
	void SetPosition( Position iPosition );
	/**
	 * Set text overlay model in anchored mode
	 **/
	void SetModelAnchored( CATPLMCompassModel *iModel );
	/**
	 * Set automatic size from viewer size mode (for 3D Live Embeded)
	 **/
	static void SetCompassScalable( int iMode );

	CATPLMCompassWidgetMode *GetModeWestDesign() {return _modeWestDesign;}

	/**
	 * Get/Set to know if the compass is painted grey
	 **/
	// Every compasses will be greyed
	void SetCompassGrey(bool isGreyed = true) {_isGreyed = isGreyed;}
	// Only this compass will be greyed
	void SetThisCompassGrey(bool isGreyed = true) {_thisCompassIsGrey = isGreyed;}
	// Return true if this compass is greyed (or if every compass is greyed)
	bool IsCompassGrey() {return (_isGreyed || _thisCompassIsGrey) ;}

	/**
	 * Get/Set the  slider  parameters  (float  number  and  its  unit)  on  the  upper  side
	 * of  the  miniplayer  just  above  the  slider.
	 **/
	void SetSliderParameters(CATUnicodeString iString);
	CATUnicodeString GetSliderParameters();

	/**
	 * Get/Set the mini player styles
	 **/
	void SetMiniPlayerStyle(CATPLMCompassStyle iStyle);
	CATPLMCompassStyle GetMiniPlayerStyle();

	/**
	 * Set state of the animation
	 **/
	void SetPlayerState(CATPLMCompassAnimState iStyle, CATBoolean iNotify);



/**
*****************************************************************************************
** missing methods implemented by CATIAfrPLMCompass
*****************************************************************************************
*/

   HRESULT CreateVIDCompass(CATVizViewer * iViewer, const CATString &iName, CATCSO *iCSO = NULL, const CATBaseUnknown_var & iFilter = NULL_var, int iStyle=0);
  /**
  * Set plm compass visibility 
  **/
   void SetCompassVisibility( const int & iVisibility )  ;
  /**
  * Get plm compass visibility
  **/
   int GetCompassVisibility( void ) const ;

     /**
  * Adds a callback when PLM Compass mode change published by a given command.
  *
  * N.B : So as to avoid problems using the interface as data member in the scope 
  * of the method, you have to give as iUsefulData (the second parameter) this pointer casted.
  * ex : ... ->AddModeChangeNotificationCB( (CATCommandMethod)&MyClass::MyMethodCalledOnCB.., 
  (CATCommandClientData*)this)  ;
  *
  * Then in the method MyMethodCalledOnCB, you need to do for retrieving the pointer _piCompass
  * on CATIAfrPLMCompass  to do : 
  *
  * ex : 
  * MyClass * pMyClassptr = (MyClass *) iUsefulData
  * if (pMyClassptr)
  * { 
  *   CATIAfrPLMCompass * piCompass = pMyClassptr -> _piCompass; // or for CATFrmWindow type use GetCompassPtrItf() to retrieve the compass
  *   if (piCompass)
  *   {
  *    // Finally , I can now do my treatment by using the class pointer.
  *
  * @param iMethodToExecute
  *   The method to execute 
  * @param iUsefulData
  *   Data to pass to <tt>iMethodToExecute</tt> and that can be useful
  *   to this method
  * @return
  *   The added callback
  */
   CATCallback AddModeChangeNotificationCB(CATCommandMethod iMethodToExecute, CATCommandClientData iUsefulData) ;

        /**
  * Remove the previously Callback 
  *
  * 
  * @param callback
  *   The callback
  */
   void RemoveModeChangeNotificationCB(CATCallback callback) ;
   virtual void SetQuadrantExclusiveFlag(const CATBoolean & iFlag = TRUE);

     /**
  * Set state of the animation
  **/
   void SetPlayerState(CATAfrPLMCompassAnimState iStyle, CATBoolean iNotify)  ;

     /**
  * Select anchored of docked mode (SetAnchor must be called first before using the Anchor mode)
  **/
   void SetPosition( const CATIAfrPLMCompass::Position &iPosition )  ;
  /**
  * Sets the model
  **/
   HRESULT SetModel( CATIAfrPLMCompassModel* ipiModel )  ;

       /**
  * Sets the model
  **/
   HRESULT SetCompassModel( CATAfrCompassModel * ipModel ) ;

  /**
  * Sets the model anchored
  **/
   HRESULT SetCompassModelAnchored( CATAfrCompassModel * ipModel );
    /**
  * Sets the label view
  **/
   HRESULT SetLabelView( CATIAfrCompassLabelView* ipiModel )  ;
   HRESULT GetLabelView( CATIAfrCompassLabelView** ipiModel );

   	/**
	 * Set visibility
	 **/
	//virtual void SetVisibility( int iVisibility );
   /** 
   * SetModeBis
   */
   virtual void SetModeBis(const CATPLMCompassMode &iMode) {SetMode(iMode);};


/**
*****************************************************************************************
** --------------------------------------------------------------------------------------
*****************************************************************************************
*/


protected:
	/**
	 * Text overlay creation. Default implementation instanciate
	 * the CATTextOverlayView that implements the label layout from 3D.
	 * Override the method to instanciate a custom text overlay
	 * with custom label layout.
	 **/
	virtual CATTextOverlayView *CreateTextOverlay( CATCommand *iFather, const CATString &iName );

        /**
         * Compas geometry
         **/
	inline void GetGeometry( float &oX, float &oY, float &oR) { oX = _x; oY = _y; oR = _r1; };

private:
	/**
	 * Available screen size
	 **/
	enum WidgetSize
	{
		UndefinedSize,
		MediumSize,
		LargeSize
	};
	WidgetSize _widgetSize;
	void SetWidgetSize( WidgetSize iSize );
	/**
	 * Set current text overlay model
	 **/
	void _SetModel( CATPLMCompassModel *iModel );
	CATBaseUnknown_var _player;
	class Attachement
	{
	public:
		Attachement( CATBaseUnknown *iObject, CATPLMCompass *iCompass ) : _object(iObject), _compass(iCompass)
		{
		};
		CATBaseUnknown *_object;
		CATPLMCompass *_compass;
	};
	static CATListPV _attachments;
	static CATListPV _ListOfDefinedPLMCompass;
	static Attachement * LocateFromObject(CATBaseUnknown * iObject);
	/*
	 * Callbacks
	 */
	void OnDrag( float iOriginX, float iOriginY, float iDX, float iDY, int iStart );
	void OnGhost( CATCommand *iSource, CATNotification *iNotification, CATCommandClientData iData );
	void OnMoveOver( float iX, float iY );
	void OnRepeatClick( float iX, float iY );
	void OnMode( CATCommand *iSource, CATNotification *iNotification, CATCommandClientData iData );
	void OnModeEdit( CATCommand *iSource, CATNotification *iNotification, CATCommandClientData iData );
	void OnPlayerButton( CATCommand *iSource, CATNotification *iNotification, CATCommandClientData iData );
	void OnLegendCombo( CATCommand *iSource, CATNotification *iNotification, CATCommandClientData iData );
	void OnLegendArrow( CATCommand *iSource, CATNotification *iNotification, CATCommandClientData iData );
	void OnPlayer( CATCallbackEvent, void *, CATNotification * evt, CATSubscriberData data, CATCallback);
	void OnToolTipLink( CATCommand *iSource, CATNotification *iNotification, CATCommandClientData iData );
	CATCallback _playercb;
	/*
	 * Layout widgets
	 */
	void Layout(void);
	void LayoutLegend(void);
	void LayoutToolbar(void);
	float _w, _h;
	/*
	 * CATDrawView
	 */
	void UpdateState(void);
	HRESULT AnalysePosition( float iX, float iY, CATBaseUnknown_var &oObject );
	void Paint(void);
	void PaintForHighlight(void);
	void PaintForPick(void);
	void PaintBackground( float iWestTabWidth, float iWestTabHeight,
						float iSouthTabWidth, float iSouthTabHeight,
						float iNorthTabWidth=0.0f, float iNorthTabHeight=0.0f,
						float iEastTabWidth=0.0f, float iEastTabHeight=0.0f);
	void PaintWidget( CATPLMCompassWidget *iWidget, int iHighlight );
	void OnResized( void );
	void Sound( const CATString &iName );
	/**
	 * Load images (background and icons)
	 **/
	void ColorizeBackground(void);
	/**
	 * Unload images
	 **/
	void CleanupIcons(void);
	/**
	 * Geometry
	 **/
	float _x, _y, _r1, _r2, _r3, _d, _m;
	/**
	 * Available 'modes' (North,West,South,East,Play) + design
	 **/
	CATPLMCompassWidgetMode *_modeSimulation, *_modeNorth, *_modeSouth, *_modeEast, *_modeWest, *_modeWestDesign;
	/**
	 * Current position mode
	 **/
	int _position;
	/**
	 * Text overlay view model
	 **/
	CATPLMCompassModel *_TextModel;
	/**
	 * Text overlay view model in docked mode
	 **/
	CATPLMCompassModel *_TextModelDocked;
	/**
	 * Text overlay view model in anchored mode
	 **/
	CATPLMCompassModel *_TextModelAnchored;
	/**
	 * Text overlay view
	 **/
	CATTextOverlayView *_TextView;
	/**
	 * Current mode
	 **/
	CATPLMCompassMode _Mode;
	/**
	 * Current LiveShape mode
	 **/
	CATPLMCompassMode _ModeDesign;
	/**
	 * Default mode = nothing
	 **/
	CATPLMCompassMode _DefaultMode;
	/**
	 * Background image
	 **/
	CATPixelImage *_skin, *_back, *_backRing, *_backCenter, *_backWest, *_backSouth, *_backWest2, *_backNorth, *_backNorth2, *_backEast, *_backEast2;
	float _br, _bg, _bb;
	float _westTabWidth, _westTabHeight, _southTabWidth, _southTabHeight, _northTabWidth, _northTabHeight, _eastTabWidth, _eastTabHeight;
	/**
	 * Legend
	 **/
	CATPLMCompassWidgetButton *_legendArrowLeft, *_legendArrowRight;
	CATPLMCompassWidgetCombo *_legendCombo;
	CATListOfWidgetLegend _legend;
	float _legendh, _legendw;
	int _legendVisible;
	int _legendEnable;
	/**
	 * West Bar
	 **/
	int _toolbarVisible;
	CATPLMCompassWestToolbar *_westToolbar;
	// West toolbar open/close animation: first steps are smaller than last steps
	// Big open step (WestBar.Animation.BigStep resource):
	void IncrementProgressivePaintFast();
	// Small open step (WestBar.Animation.SmallStep resource):
	void IncrementProgressivePaintSlow();
	// Big close step (WestBar.Animation.BigStep resource):
	void DecrementProgressivePaintFast();
	// Small close step (WestBar.Animation.SmallStep resource):
	void DecrementProgressivePaintSlow();
	// Set to close position:
	void ResetProgressivePaint();
	// Set to open position:
	void SetMaxProgressivePaint();
	int  GetProgressivePaint();
	int  GetWestBarAnimationSmallStep(); //WestBar.Animation.SmallStep resource
	int  GetWestBarAnimationBigStep();   //WestBar.Animation.BigStep resource
	int _progressivePaint;
	// Timer management:
	static void DelayToolbarApparition(CATPLMCompass *compass);
	static void DelayToolbarApparitionTimeOut( void *iParam );
	static void DelayToolbarDisparition(CATPLMCompass *compass);
	static void DelayToolbarDisparitionTimeOut( void *iParam );
	// Animation speed: delay between 2 steps (WestBar.Animation.Speed resource)
	int GetWestBarAnimationSpeed();
	int _westBarAnimationSpeed, _westBarAnimationBigStep, _westBarAnimationSmallStep;

	/*
	 * Player
	 */
	CATPLMCompassWidgetButton *_playerBack, *_playerPlay, *_playerPause, *_playerNext, *_playerFirst, *_playerLast;
	CATPLMCompassWidgetSlider *_playerSlider;
	CATPLMCompassWidgetLegend *_playerLegend;
	CATUnicodeString _playerSliderParameters;
	CATPLMCompassStyle _playerStyle;
	CATPLMCompassWidgetGhost *_ghost;
	int _playerVisible, _playerActive;
	float _playerh, _playerw, _playerDragStartPos;
	/*
	 * Delay repaint used to remove legend arrow
	 */
	void DelayRepaint(void);
	static void DelayRepaintTimeOut( void *iParam );
	/*
	 * Widgets
	 */
	CATDynHashDico _widgets;
	/*
	 * Anchor management
	 */
	CATRepPath_WR _anchorPath;
	CATMathPointf _anchorPoint;
	/*
	 * Record stuff
	 */
	CATUnicodeString GetRecordId( CATBaseUnknown_var iRecordObject );
	CATBaseUnknown_var GetReplayObject( const CATUnicodeString &iReplayId );
	static int _scalable;
	/*
	 * Every compass will be painted grey
	 */
	static bool _isGreyed;
	/*
	 * This compass will be painted grey
	 */
	bool _thisCompassIsGrey;
	/*
	 * This compass is designed for play use
	 */
	bool _thisCompassPlayerOnlyDesign;
	/*
	 * New code only if not replaying ODT
	 */
	static bool _ODTfree;

	// SCA : Beta Version sur CATLiveShapeWorkbench.
	CATPLMCompassWidgetButton *_playerBeta;
	CATVizViewer *_parentBeta;

	// Get a resource and convert it to an int
	void GetIntResource (const CATString iResourceKey, int iDefaultValue, int & ioValue);

  CATIAfrVIDCompass_var _spiVidCompass;
};

#endif
