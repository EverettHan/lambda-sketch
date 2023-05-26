
// COPYRIGHT Dassault Systemes 2004
#ifndef CATPLMCompassModel_H
#define CATPLMCompassModel_H

#include <CATPLMCompassModule.h>
#include <CATPLMCompassMode.h>
#include <CATIPLMCompassFilter.h>

#include <CATViewModel.h>
//#include <CATMathPointf.h>
#include <CATListOfCATString.h>
#include <CATListOfCATPathElement.h>
#include <CATLISTV_CATBaseUnknown.h>
#include <CATListOfInt.h>

class CATMathPointf;

#include <CATTextOverlayView.h>

/**
 * CATPLMCompassModel: the view model for text overlay.
 * This class delegates selection filtering and text and icon
 * computation to CATIPLMCompassFilter implementations.
 * It manages CSO notifications and view update.
 * It is an abstract class that has to be enriched with adapted
 * selection management: in CATIA, in ENOVIA Web Viewer...
 *
 * Implement GetSelectedItems
 * Call OnSelectionChanged when CSO has changed
 **/
class ExportedByCATPLMCompass CATPLMCompassModel: public CATViewModel
{
	CATDeclareClass;
public:
	/**
	 * Constructor
	 **/
	CATPLMCompassModel( const CATBaseUnknown_var &iFilter );
	/**
	 * Destructor
	 **/
	virtual ~CATPLMCompassModel( void );
	/**
	 * Set current mode
	 **/
	void SetMode( const CATPLMCompassMode &iMode );
	/**
	 * Get properties
	 **/
	void GetProperties( CATListOfCATString &oProperties );
	/**
	 * Get legend
	 **/
	CATLISTV(CATBaseUnknown_var) &GetLegend( void );
	/*
	 * CATIObjectSetViewModel
	 */
	HRESULT GetObjects( CATLISTV(CATBaseUnknown_var) &oObjects );
	CATPathElement *GetPath( const CATBaseUnknown_var &iObject );
	/*
	 * CATITextOverlayViewModel
	 */
	CATUnicodeString GetLabel( CATBaseUnknown_var iItem, const CATString &iPropertyID );
	CATUnicodeString GetIcon( CATBaseUnknown_var iItem, const CATString &iPropertyID );
	int GetStyle( CATBaseUnknown_var iItem, const CATString &iPropertyID );
	HRESULT GetAnchor( CATBaseUnknown_var iNode, CATMathPointf &oAnchor );
	/**
	 * Get filter
	 **/
	const CATBaseUnknown_var &GetFilter(void) const { return _filter; };

	/*
	 * Méthodes signalant le passage avant et après un undo
	 */
	void OnBeforeUndo();
	void OnAfterUndo();

	/*
	 * Méthodes signalant le passage avant et après un redo
	 */
	void OnBeforeRedo();
	void OnAfterRedo();

	/**
	 * Get command
	 **/
	int GetCommand( CATBaseUnknown_var ispItem, const CATString &iPropertyID );

	/**
	 * Launch command
	 **/
	HRESULT LaunchCommand( CATBaseUnknown_var ispItem, const CATString& iPropertyID, const CATPathElement& iPath, const float ilx, const float ily );

	// SCA : Developpement Hyperlink.
	/**
	 * Get command
	 **/
	int GetCommand( CATBaseUnknown_var ispItem, const CATString &iPropertyID, CATUnicodeString &oHyperLink );

	/**
	 * Launch command
	 **/
	HRESULT LaunchCommand( CATBaseUnknown_var ispItem, const CATString& iPropertyID, const CATPathElement& iPath, const float ilx, const float ily, const CATUnicodeString &iHyperLink );

protected:
	/**
	 * Abstract method: retreive current selection.
	 * AddRef path elements, caller will release them.
	 **/
	virtual HRESULT GetSelectedItems( CATLISTP(CATPathElement) &oElements ) = 0;
	/**
	 * Notify of selection change
	 **/
	void OnSelectionChanged(void);
private:
	void UpdateListOfVisibleObject(void);
	void ClearListOfSelectedObject(void);
	void OnVisibility( CATCallbackEvent, void *, CATNotification * evt, CATSubscriberData data, CATCallback);
	CATPLMCompassMode _Mode;
	CATBaseUnknown_var _filter;
	CATListOfCATString _properties;
	CATLISTV(CATBaseUnknown_var) _ListOfSelectedObjects;
	CATLISTV(CATBaseUnknown_var) _ListOfVisibleObjects;
	CATLISTV(CATBaseUnknown_var) _legend;
	CATListOfInt _callbacks;

	void UpdateView();

	static bool _isUndoing;
	static bool _isRedoing;
	static bool _needsUpdate;
};

#endif
