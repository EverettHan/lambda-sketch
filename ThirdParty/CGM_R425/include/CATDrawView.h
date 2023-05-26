// COPYRIGHT Dassault Systemes 2004
#ifndef CATDrawView_H
#define CATDrawView_H

#include <CATDynHashTable.h>
#include <CATIVidViewAdaptor.h>
#include <CATIViewContainer.h>
#include <CATRep_WR.h>
#include <CATView.h>
#include <CATViewBase.h>
#include <CATUnicodeString.h>
#include <CATString.h>
#include <CAT2DViewpoint.h>
#include <CAT2DViewport.h>
#include <CATBaseUnknown_WR.h>

class CATDrawViewGP;
class CATDrawViewGPH;
class CATVizViewer;
class CAT2DCustomRep;
class CAT2DManipulator;
class CATRender;
class CATCharacterFont;
class CATDlgContextualMenu;
class CATPixelImage;
class CATGraphicAttributeSet;
class CATDeviceEvent;
class CATViewController;
class CATDlgContextualMenu;
class CATViewTooltip;
class CATCommand;
class CATNotification;
class CATScrollableViewVPE;
class CATViewVisuEventListener;

/**
* CATDrawView - Abstract class for Viewer overlay using dynamic GP for drawing.
* Implement the method 'Paint' with custom drawing.
**/
class ExportedByCATView CATDrawView : public CATViewBase
{
	friend class CATVidViewContainer;
	friend class l_CATVidViewInternalContainer;
	friend class CATDrawViewGP;
	friend class CATDrawViewGPH;
	friend class CATScrollableViewVPE; // for GetViewpoint
	CATDeclareClass;

public:
	/**
	* Constructor
	**/
	CATDrawView(CATCommand *iFather, const CATString &iName, int iStyle);
	/**
	* Destructor
	**/
	virtual ~CATDrawView(void);
	/**
	* Change parent. Implementation calls CATCommand::SetParent.
	**/
	void Reparent(CATCommand *iFather);
	/**
	* Get contextual menu
	**/
	CATDlgContextualMenu *GetMenu(void);
	/*
	* Drawing functions
	*/
	void DrawText(float iX, float iY, const CATUnicodeString &iText, float iSize = 0);
	void DrawRect(float iX, float iY, float iW, float iH);
	void FillRect(float iX, float iY, float iW, float iH);
	void DrawButton(float iX, float iY, float iW, float iH,
		const CATGraphicAttributeSet &iLight,
		const CATGraphicAttributeSet &iFace,
		const CATGraphicAttributeSet &iDark);
	void DrawLabel(const CATUnicodeString &iString,
		const CATUnicodeString &iIcon,
		int iPreHighlight, int iHighlight, int iActive,
		float iX, float iY, float iW, float iH);
	void DrawLines(float *iPts, int iNbPoints);
	void FillPolygon(float *iPts, int iNbPoints);
	void DrawImage(float iX, float iY, CATPixelImage *iImage, const float& iOfset = 0.5f);
	void DrawArrow(float iX, float iY, float iSize, int iOrientation);
	/**
	* Create a color from background and foreground
	* iForeground is between 0.0 and 1.0.
	* 0.0 gives the background color, 1.0 the foreground color
	**/
	virtual void GetColor(float iForeground, float iTransparency, CATGraphicAttributeSet &oGAS);
	/**
	* Modify an image by applying a color filter
	**/
	void ColorizeImage(CATPixelImage *ioImage, const CATGraphicAttributeSet &iGAS);
	/**
	* Modify an image by inverting its colors
	**/
	void InvertImage(CATPixelImage *ioImage);
	/**
	* Is the background color a dark one ?
	**/
	int IsDarkBackground(void);
	/**
	* Crop a string so that it becomes smaller than iWidth (in pixels)
	* iIndex is the font index used
	**/
	CATUnicodeString CropString(const CATUnicodeString &iString, int iIndex, float iWidth);
	/**
	* Crop a string so that it becomes smaller than iWidth (in chars)
	**/
	CATUnicodeString CropString(const CATUnicodeString &iString, int iWidth);
	void SetGAS(const CATGraphicAttributeSet &iGAS);
	CATGraphicAttributeSet &GetGAS(void);
	void SetClipping(float iX0, float iY0, float iX1, float iY1);
	void UnsetClipping(void);
	/**
	* Get font
	**/
	CATCharacterFont *GetFont(void);
	/**
	* Get font index, if iSize==0, returns current font index
	**/
	int GetTextFontIndex(float iSize = 0);
	/**
	* Highlight/prehighlight changed
	**/
	void UpdateHightlight(CATBaseUnknown *iNode);
	/**
	* Get device event, containing keyboard modifiers (Ctrl, Shift)
	**/
	CATDeviceEvent *GetDeviceEvent(void);
	/**
	* Get default text size for the system
	**/
	float GetDefaultTextSize(void);
	/**
	* Set text size (used as reference for tree scaling, including icons, nodes...)
	**/
	void SetTextSize(float iHeight);
	/**
	* Get current text size
	**/
	float GetTextSize(void);
	/**
	* Get a string width in pixels
	**/
	float GetTextWidth(const CATUnicodeString &iString, float iSize = 0);
	virtual int Invalidate(void);
	CATVizViewer *GetViewer(void);
	float GetViewerDensity();
	/**
	* Get tooltip
	**/
	virtual CATUnicodeString GetTooltip(void);
	// DBE August 2007 +
	virtual CATString GetTooltipIconName(void);
	virtual CATUnicodeString GetTooltipLink(CATCommand* widget);
	virtual CATCommand* GetCurrentWidget(CATNotification*& oToolTipLinkNotification);
	// DBE August 2007 -

	/**     IOD report CATScrollableView
	* Set zoom/scroll manipulation mode
	**/
	HRESULT SetDirectManipulationMode(int iActive);

	enum HighlightManagement
	{
		OptimizeSpeed,
		OptimizeQuality
	};
	/**
	* Set highlight management policy, default is OptimizeSpeed.
	* In OptimizeQuality mode, a full redraw is done instead of an incremental draw.
	* => Use optimize quality when no 3D is rendered in the viewer
	**/
	void SetHighlightManagement(HighlightManagement iHighlightManagement);
	/**
	* Get current highlight management policy
	**/
	HighlightManagement GetHighlightManagement(void) const;
	class DrawColors
	{
	public:
		CATGraphicAttributeSet _back;
		CATGraphicAttributeSet _text;
		CATGraphicAttributeSet _high;
		CATGraphicAttributeSet _active;
	};
	DrawColors _drawcolors;

	unsigned int KeyboardAction(CATKeybdEvent * iEvent);
	unsigned int DeviceAction(CATNotification * iNotification);

	virtual void SetViewer(CATVizViewer *iViewer);

	int GetGoodYOrientationFlag() const;
protected:
	/*
	* Overloadable paint functions
	*/
	virtual void PaintForHighlight(void);
	virtual void Paint(void);
	virtual void PaintForPick(void);
	/*
	* Overloadable notification callback functions
	*/
	virtual void OnResized(void);
	virtual void OnAfterResized(void);
	/**
	* Trigger highlight refresh (immediat draw, with highlight only, no full scene draw)
	**/
	void DrawHighlight(void);
	void DrawFurtive(void);
	/**
	* Is object in list of objects to draw in highlight draw ?
	**/
	int IsDrawHighlight(CATBaseUnknown_var iObject);

	HRESULT GetMousePosition(float &oX, float &oY);

	// IOD accès pour CATScrollableViewVPE
	void SetViewpointEditor(CATScrollableViewVPE *vpe) { _vpe = vpe; }

	// Tells about VID integration
	CATIVidViewAdaptor_var GetVidViewAdaptor(void);
	CATIViewContainer_var GetViewContainer(void);

	// SCA : private -> protected.
	//       Must be used in CATWintopValueUI/CATKweSharedUI.m/src/CATKweTreeListView.cpp
	CATRender *_currentRender;

	CATBoolean _viewerBackgroundChanged;

private:
	/*
	* Callbacks
	*/
	void OnViewerDestroyed(CATCallbackEvent, void *, CATNotification * evt, CATSubscriberData data, CATCallback);
	void OnViewerBackgroundChanged(CATCallbackEvent, void *, CATNotification * evt, CATSubscriberData data, CATCallback);
	void OnWindowResized(CATCallbackEvent, void *, CATNotification * evt, CATSubscriberData data, CATCallback);
	void OnClick(CATCommand *, CATNotification *, CATCommandClientData);
	void OnDoubleClick(CATCommand *, CATNotification *, CATCommandClientData);
	void OnRightClick(CATCommand *, CATNotification *, CATCommandClientData);
	void OnDrag(CATCommand *, CATNotification *, CATCommandClientData);
	void OnMoveOver(CATCommand *, CATNotification *, CATCommandClientData);
	void OnLeave(CATCommand *, CATNotification *, CATCommandClientData);
	void OnUpdateHighlight(CATCommand *, CATNotification *, CATCommandClientData);
	void OnDrop(CATCommand *, CATNotification *, CATCommandClientData);
	void OnEndContextCB(CATCommand *, CATNotification *, CATCommandClientData);
	static void Timer(void *iData);
	void OnTimer(void);
	void CreateTooltip(void);
	void AddVisuListener();
	float TransformY(float i_y);
	int GetVIDAdaptorFlag() const;

	class Clipping
	{
	public:
		float _x0, _y0, _x1, _y1;
		Clipping *_previous;
	};
	Clipping _clippingRoot;
	Clipping *_clippingStack;
	void UpdateViewport(void);
	CAT2DViewport _viewport;
	CATNotification *GetUpdateHighlightNotification(void);

	CATBaseUnknown_WR _wrViewpoint;
	CAT2DViewpoint _viewpoint; // Temporary
	CAT2DViewpoint *GetViewpoint(void);
	CAT2DViewpoint *GetViewpointWR();

	CATScrollableViewVPE *_vpe;     // IOD spécifique CATScrollableView

	CATCallback _CBViewerDestroyed;
	CATCallback _CBViewerBackgroundChanged;
	CATCallback _CBWindowResized;
	CATDynHashTable _tohighlightdraw;
	int _highlightdraw;
	CATBaseUnknown_WR _wrViewer;
	CATDrawViewGP *_gp;
	CATDrawViewGPH *_hgp;
	CAT2DManipulator *_manip;
	CATDlgContextualMenu *_menu;
	float _ratio;
	float _vh;
	float _dragX, _dragY;
	int _fontindex;
	int _firstRepeat;
	CATViewTooltip *_tooltip;
	HighlightManagement _highlightManagement;
	CATRepWeakRef *_rep, *_hrep;
	CATBoolean         _bIn;
	CATViewVisuEventListener* _pVisuEventListener;
	int _vidAdaptorFlag;
};

#endif
