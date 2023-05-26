// COPYRIGHT Dassault Systemes 2004
#ifndef CATSplitterView_H
#define CATSplitterView_H

#include <CATDrawView.h>
#include <CATUnicodeString.h>
#include <CATView.h>

#define CATSplitterViewHorizontal	0x00010000
#define CATSplitterViewVertical		0x00020000

/**
 * CATSplitterView. A splitter that layouts its children (should have 2 children)
 **/
class ExportedByCATView CATSplitterView: public CATDrawView
{
	CATDeclareClass;
public:
	/**
	 * Constructor
	 **/
	CATSplitterView( CATCommand *iFather, const CATString &iName, int iStyle= CATSplitterViewHorizontal );
	/**
	 * Destructor
	 **/
	virtual ~CATSplitterView( void );
	/**
	 * Recompute layout
	 **/
	void Layout(void);
	/**
	 * Set splitter position (in pixels)
	 **/
	void SetSplitterPosition( int iPosition );
	/**
	 * Get area size
	 **/
	int GetSplitterPosition( void ) const;
	/**
	 * Get tooltip
	 **/
	CATUnicodeString GetTooltip( void );
protected:
	void UpdateState(void);
	void OnVisibility( CATCommand *iCommand, CATNotification *iNotif, CATCommandClientData iData );
	void OnClick( float iOriginX, float iOriginY );
	void OnDrag( float iOriginX, float iOriginY, float iDX, float iDY, int iStart );
	void Paint(void);
	void PaintForHighlight(void);
	void PaintForPick(void);
	void OnResized(void);
	HRESULT AnalysePosition( float iX, float iY, CATBaseUnknown_var &oObject );
	float _position;
};

#endif
