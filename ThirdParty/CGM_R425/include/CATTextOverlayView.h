
// COPYRIGHT Dassault Systemes 2004
#ifndef CATTextOverlayView_H
#define CATTextOverlayView_H

#include <CATView.h>
#include <CATDrawView.h>
//#include <CATMathPoint2Df.h>
//#include <CATMathPointf.h>
#include <CATGraphicAttributeSet.h>
#include <CAT4x4Matrix.h>
#include <CATListOfCATString.h>
#include <CATListOfCATUnicodeString.h>
#include <CATTextOverlayViewItem.h>
#include "CATIAfrCompassLabelView.h"

class CATMathPoint2Df;
class CATMathPointf;
class CATIAfrLabelLayout;
class CATICAfrComponentController;

#include <CATLISTP_Clean.h>
#define CATLISTP_Append
#define CATLISTP_RemoveAll
#define CATLISTP_QuickSort
#ifdef CATCOLLEC_ExportedBy
#undef CATCOLLEC_ExportedBy
#endif
#define CATCOLLEC_ExportedBy ExportedByCATView
#include <CATLISTP_Declare.h>
CATLISTP_DECLARE( CATTextOverlayViewItem )
typedef CATLISTP( CATTextOverlayViewItem ) CATListOfCATTextOverlayViewItem;

/**
 * CATTextOverlayView
 * Model should implement:
 * 1. CATIObjectSetViewModel		to list objects to display
 * 2. CATIInteractiveGeoViewModel	to get representation of objects to display
 * 3. CATIObjectViewModel			to get properties of objects to display
 **/
class ExportedByCATView CATTextOverlayView: public CATDrawView
{
	CATDeclareClass;
public:
	/**
	 * Constructor
	 **/
	CATTextOverlayView( CATCommand *iFather, const CATString &iName );
	/**
	 * Destructor
	 **/
	virtual ~CATTextOverlayView( void );
	/**
	 * Set properties to display (if model implements CATIView)
	 **/
	void SetProperties( const CATListOfCATString &iProperties );
	/**
	 * Get displayed properties
	 **/
	const CATListOfCATString &GetProperties( void ) const;
	/**
	 * Get tooltip
	 **/
	CATUnicodeString GetTooltip(void);
	/**
	 * Available looks
	 **/
	enum Look
	{
		Light,
		Strong
	};
	/**
	 * Set look
	 **/
	void SetLook( Look iLook );
	/**
	 * Get current look
	 **/
	Look GetLook(void) const;
	/**
	 * Available layouts
	 **/
	enum OverlayLayout
	{
		Automatic,
		Side,
		InPlace
	};
	/**
	 * Set layout mode
	 **/
	void SetLayout( OverlayLayout iLayout );
	/**
	 * Get current layout
	 **/
	OverlayLayout GetLayout(void) const;
	/**
	 * Set crop policy.
	 * -1 means automatic (from settings)
	 **/
	void SetCrop( int iCropPolicy );
	/**
	 * Set crop policy.
	 * -1 means automatic (from settings)
	 **/
  void SetDefaultCrop( const float& iDefaultSize );

    /**
	 * Set maximum number of displayed items. -1 means no limit.
	 **/
	void SetMaxDisplay( int iMaxDisplay );
	/**
	 * Get maximum number of displayed items. -1 means no limit.
	 **/
	int GetMaxDisplay( void ) const;

  HRESULT SetLayout( const OverlayLayoutLabel& iLayout );
  HRESULT RefresFromCompass( CATIAfrVIDCompass_var ispCompass );
  HRESULT SetLayoutModel( CATIAfrLabelLayout* ipiLayout );
  HRESULT SetCAfrLabelViewType( const CAfrLabelViewType& iType );
  HRESULT SetCAfrComponentController( CATICAfrComponentController* ipiCAfrComponentController );
  HRESULT UpdateView( const UpdateViewType& iType = Anchor );
  HRESULT SetApplicationViewer(CATCommand * pVizViewer);

protected:
	/*
	 * Paint
	 */
	virtual void Layout(void);
	void CleanupState(void);
	void UpdateState(void);
	void PaintForHighlight(void);
	void PaintForPick(void);
	void Paint(void);
	CATMathPoint2Df Point3DToPixel( const CATMathPointf &iPoint );
	void DrawLabel( CATTextOverlayViewItem *iItem, int iHighlight );
	void DrawArrow( float iX0, float iY0, float iX1, float iY1 );
	void ComputeLabelSize( CATTextOverlayViewItem *iItem );
	void OnClick( float iX, float iY );
	HRESULT GetOnClick( float iX, float iY, CATBaseUnknown_var &oSpLabel, CATString &oProperty );
	// SCA : Developpement Hyperlink.
	HRESULT GetOnClick( float iX, float iY, CATBaseUnknown_var &oSpLabel, CATString &oProperty, CATUnicodeString &oHyperLink );
	/**
	 * Analyse cursor position
	 **/
	HRESULT AnalysePosition( float iX, float iY, CATBaseUnknown_var &oObject );
	virtual CATPathElement *CreateObjectPath( CATBaseUnknown_var iObject );
	CATBaseUnknown_var GetObject( CATTextOverlayViewItem *iItem );
	class Colors
	{
	public:
		CATGraphicAttributeSet _back;
		CATGraphicAttributeSet _lineback;
		CATGraphicAttributeSet _high;
		CATGraphicAttributeSet _link;
		CATGraphicAttributeSet _text;
	};
	Colors _colors;
	int _crop;
	CATListOfCATString _properties;
	CATListOfCATTextOverlayViewItem _items;
	CAT4x4Matrix _lastVP;
	Look _look;
	OverlayLayout _layout;
	/**
	 * Tree Settings integration
	 **/
	void OnSettings( CATCallbackEvent, void *, CATNotification * evt, CATSubscriberData data, CATCallback);
	CATCallback _settingscb;
	/**
	 * Record/Replay integration
	 **/
	CATUnicodeString GetRecordId( CATBaseUnknown_var iRecordObject );
	CATBaseUnknown_var GetReplayObject( const CATUnicodeString &iReplayId );

	int _cropPolicy;
	int _maxDisplay;
  float _DefaultSize;
};

#endif
