// COPYRIGHT Dassault Systemes 2004
#ifndef CATViewBase_H
#define CATViewBase_H

#include <CATView.h>
#include <CATCommand.h>
#include <CATIViewController.h>
#include <CATIViewModel.h>

class CATKeybdEvent;
class CATViewBase;
class CATPathElement;

#include <CATLISTP_Clean.h>
#define CATLISTP_Append
#define CATLISTP_RemoveValue
#define CATLISTP_RemoveAll
#include <CATLISTP_Declare.h>
CATLISTP_DECLARE( CATViewBase );
typedef CATLISTP( CATViewBase ) CATListOfCATViewBase;

/**
 * Base class for CATDrawView and CATContainerView
 **/
class ExportedByCATView CATViewBase: public CATCommand
{
	friend class CATViewRecorder;
	friend class CATViewCellEditControllerTst;
	friend class CATCellEditController;
	friend class CATViewControllerTst;

	CATDeclareClass;
public:
	/**
	 * Constructor
	 **/
	CATViewBase( CATCommand *iParent, const CATString &iName, int iStyle );
	/**
	 * Destructor
	 **/
	virtual ~CATViewBase( void );
	/**
	 * Set position relative to parent overlay
	 **/
	virtual void SetPosition( int iX, int iY, int iW, int iH );
	/**
	 * Get position
	 **/
	void GetPosition( int &oX, int &oY, int &oW, int &oH ) const;
	/**
	 * Get width in pixels
	 **/
	int GetWidth( void ) const;
	/**
	 * Get height in pixels
	 **/
	virtual int GetHeight( void );
	/**
	 * Get child count
	 **/
	int GetChildCount( void ) const;
	/**
	 * Get child from index (between 0 and GetChildCount()-1)
	 **/
	CATViewBase *GetChild( int iIndex ) const;
	/**
	 * Set controller
	 **/
	void SetController( CATIViewController_var iController );
	/**
	 * Get controller
	 **/
	CATIViewController_var GetController(void) const;
	/**
	 * Get visibility
	 **/
	int GetVisibility(void) const;
	/**
	 * Set visibility
	 **/
	virtual void SetVisibility( int iVisibility );
	/**
	 * Visibilty changed
	 **/
	CATNotification *GetVisibilityNotification(void);
	/**
	 * Change style
	 **/
	virtual void SetStyle( int iStyle );
	/**
	 * Get style
	 **/
	int GetStyle(void) const;
	/**
	 * Is a style set ?
	 **/
	int HasStyle( int iStyle ) const;
	/**
	 * Refresh state and redraw view
	 **/
	virtual int Invalidate(void);
	/**
	 * Update sate if needed
	 **/
	void Update(void);
	/**
	 * Highlight/prehighlight changed
	 **/
	virtual void UpdateHightlight( CATBaseUnknown *iNode ) {};
	/**
	 * Create path element to node under the mouse
	 **/
	virtual CATPathElement *CreateObjectPath(void);
	/**
	 * Focus on a model element
	 **/
	HRESULT SetFocus( CATPathElement *iFocus );
	/**
	 * Get focus model element
	 **/
	CATPathElement *GetFocus( void ) const;
	/**
	 * Set model
	 **/
	HRESULT SetModel( CATIViewModel_var iModel );
	/**
	 * Get model
	 **/
	CATIViewModel_var GetModel(void) const;
	/**
	 * Overloadable notification callback functions
	 **/
	virtual void OnResized( void );
	virtual void OnClick( float iX, float iY );
	virtual void OnDoubleClick( float iX, float iY );
	virtual void OnRightClick( float iX, float iY );
	virtual void OnDrag( float iOriginX, float iOriginY, float iDX, float iDY, int iStart );
	virtual void OnMoveOver( float iX, float iY );
	virtual void OnLeave( void );
	virtual void OnFocusChange( void );
	virtual void OnModelChange( void );
	virtual void OnKey( const CATKeybdEvent &iEvent );
	virtual void OnVisibility( void );
  virtual HRESULT OnKeyboardAction( const CATKeybdEvent &iEvent, unsigned int& oReturn );
  virtual HRESULT OnDeviceAction( CATNotification* ipNotification, unsigned int& oReturn );
	virtual void OnEndContext( void );

	/**
	 * Send during 'long click', every 'RepeatTimer'
	 * Default implementation calls OnClick
	 * Override to remove repeat behavior
	 **/
	virtual void OnRepeatClick( float iX, float iY );
	void SetRepeatTimer( int iLength );
	int GetRepeatTimer( void ) const;
	/**
	 * Override CATCommand::IsReplay to disable custom record/replay with CATViewStandardRecord variable
	 **/
    int IsReplay(void);
	/**
	 * Override CATCommand::IsCapture to disable custom record/replay with CATViewStandardRecord variable
	 **/
    int IsCapture(void);
protected:
	/**
	 * Override this method with object state update code
	 **/
	virtual void UpdateState(void);
	/**
	 * Override this method with object state cleanup code
	 **/
	virtual void CleanupState(void);
	/**
	 * Get object under the cursor
	 **/
	virtual HRESULT AnalysePosition( float iX, float iY, CATBaseUnknown_var &oObject );
	/**
	 * Create path element to a node
	 **/
	virtual CATPathElement *CreateObjectPath( CATBaseUnknown_var iObject );
	/**
	 * Get current cursor position
	 **/
	virtual HRESULT GetMousePosition( float &oX, float &oY );
	/**
	 * Trigger highlight refresh (immediat draw, with highlight only, no full scene draw)
	 **/
	virtual void DrawHighlight(void) {};
	/**
	 * Is object in list of objects to draw in highlight draw ?
	 **/
	virtual int IsDrawHighlight( CATBaseUnknown_var iObject ) { return 0; };
	/**
	 * Get a stable pointer on an object.
	 * Do not used the returned value to access the object, it may not exist anymore
	 * (no AddRef is done on it)
	 **/
	CATBaseUnknown *GetStablePointer( CATBaseUnknown *iObject );
	/**
	 * Record integration
	 **/
	HRESULT Record( const char *iEvent, CATBaseUnknown_var iObject );
	virtual HRESULT Replay( const char *iEvent, CATBaseUnknown_var iObject );
	virtual CATUnicodeString GetRecordId( CATBaseUnknown_var iRecordObject );
	virtual CATBaseUnknown_var GetReplayObject( const CATUnicodeString &iReplayId );
	CATBaseUnknown_var _lastObject;
private:
	/*
	 * Callbacks
	 */
	CATCallback _modelModified;
	void OnModelModified( CATCallbackEvent, void *, CATNotification * evt, CATSubscriberData data, CATCallback);

	CATIViewModel_var _model;
	CATPathElement *_focus;
	int _dirty;
	int _visibility;
	int _style;
	int _x, _y, _width;
protected:
	int _height;
private:
	int _repeatTimer;
	CATListOfCATViewBase _children;
	CATIViewController_var _controller;
	/*
	 * Record support methods
	 */
	CATNotification *GetRecordNotification(void);
	int RestoreState( CATNotification *iNotification, CATMarshal &oDataToRestore);
	void ReplayEvent( const CATString &iEvent, const CATUnicodeString &iObject );
};

#endif
