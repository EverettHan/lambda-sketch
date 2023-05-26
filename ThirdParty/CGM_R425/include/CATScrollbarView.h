#ifndef CATScrollbarView_H
#define CATScrollbarView_H

#include <CATView.h>
#include <CATDrawView.h>
#include <CATGraphicAttributeSet.h>

#define CAT3DNSBLookV2			0x0000

/**
 * CATScrollbarView
 **/
class ExportedByCATView CATScrollbarView: public CATDrawView
{
	CATDeclareClass;
public:
	/**
	 * Constructor
	 **/
	CATScrollbarView( CATCommand *iParent,
		const CATString &iName,
		int iStyle );
	/**
	 * Destructor
	 **/
	virtual ~CATScrollbarView( void );
	/**
	 * Set range
	 **/
	HRESULT SetRange( float iRange, float iPage, float iLine );
	/**
	 * Get range
	 **/
	HRESULT GetRange( float &oRange, float &oPage, float &oLine ) const;
	/**
	 * Set position
	 **/
	HRESULT SetPosition( float iPosition, int iForce=0 );
	/**
	 * Get position
	 **/
	float GetPosition( void );
	/**
	 * Position changed notification
	 **/
	CATNotification *GetPositionChangedNotification(void);
	CATNotification *GetStartScrollNotification(void);
	CATNotification *GetStopScrollNotification(void);

  virtual HRESULT OnDeviceAction( CATNotification* ipNotification, unsigned int& oReturn );

private:
	/*
	 * Callbacks
	 */
	void OnClick( float iX, float iY );
	void OnDoubleClick( float iX, float iY );
	void OnRepeatClick( float iX, float iY );
	void OnDrag( float iX, float iY, float iDX, float iDY, int iStart );

	/*
	 * Internal services
	 */
	enum Position
	{
		Unknown= 0,
		PreviousLine= 1,
		PreviousPage= 2,
		Scroller= 3,
		NextPage= 4,
		NextLine= 5
	};
	Position AnalysePosition( float iX, float iY );
	void Paint( void );
	void PaintForPick( void );

	void ComputePixelSizes( float &oPos, float &oPage, float &oArrow );
	float _minsize;
	Position _lastclickpos;
public:
	float _lastposition, _position, _range, _page, _line, _allowdrag;
	CATGraphicAttributeSet _arrowColor, _buttonColor, _buttonLightColor, _buttonDarkColor, _scrollColor;
};

#endif
