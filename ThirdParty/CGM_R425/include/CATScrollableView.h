// COPYRIGHT Dassault Systemes 2004
#ifndef CATScrollableView_H
#define CATScrollableView_H

#include <CATView.h>
#include <CATDrawView.h>
#include <CATSysWeakRef.h>

class CATScrollbarView;
class CATScrollableViewVPE;
class CATVidLayScrollable;
#define CATLeftScroll		0x0001
#define CATRightScroll		0x0002
#define CATScrollLookV2		0x0000

/**
 * A scrollable view.
 * Scrollbar are managed automatically from virtual size.
 **/
class ExportedByCATView CATScrollableView: public CATDrawView
{
	CATDeclareClass;
public:
	/**
	 * Constructor
	 **/
	CATScrollableView( CATCommand *iFather, const CATString &iName, int iStyle );
	/**
	 * Destructor
	 **/
	virtual ~CATScrollableView( void );
	/**
	 * Set virtual width
	 **/
  void SetVirtualWidth( float iWidth );
	/**
	 * Get virtual width
	 **/
	float GetVirtualWidth( void ) const;
	/**
	 * Set virtual width
	 **/
  void SetVirtualHeight( float iHeight );
	/**
	 * Get virtual height
	 **/
	float GetVirtualHeight( void ) const;
	/**
	 * Get visible height
	 **/
  int GetHeight(void);
	/**
	 * Set thorizontal scroll position
	 **/
  void SetScrollX( float iX, int iForce=0 );
	/**
	 * Get horizontal scroll position
	 **/
	float GetScrollX( void ) const;
	/**
	 * Set vertical scroll position
	 **/
  void SetScrollY( float iY, int iForce=0 );
	/**
	 * Get vertical scroll position
	 **/
	float GetScrollY( void ) const;
	/**
	 * Set horizontal scroll step
	 **/
	void SetScrollStepX( float iStepX );
	/**
	 * Set vertical scroll step
	 **/
	void SetScrollStepY( float iStepY );

	/**
   * Get the density
   * @return the density.
   */
   float GetDensity() const;


	/**
	 * Set zoom/scroll manipulation mode
	 **/
	//HRESULT SetDirectManipulationMode( int iActive );   // IOD : remonté dans CATDrawView
  virtual HRESULT OnDeviceAction( CATNotification* ipNotification, unsigned int& oReturn );

protected:
	void OnAfterResized( void );
	virtual void OnScroll(void);
	virtual void OnScrollStart(void);
	virtual void OnScrollStop(void);
	void Layout(void);
	void OnScrollCB( CATCommand *, CATNotification *, CATCommandClientData );
	void OnVisibility( void );

    CATVidLayScrollable* GetVidScrollable() const;
    // We have to keep _pVidLayScrollable raw pointer because of usage of it by clients, that should now use GetVidScrollable :
    //# make-ERROR: CATSplUI\CATSsmCustoExtensionMgr.m\src\CATSsmCustoExtensionMgrView.cpp
    //# make-ERROR: DELStrMfgPlanningServices\DELStrMfgSyncManager.m\src\DELShipMfgSynchronizationView.cpp
    //# make-ERROR: DNBFittingUI\DNBFITMultiListUI.m\src\DNBFITMultiListView.cpp
    //# make-ERROR: DELPPRAuthFoundationUI\DELPPRAuthFoundationHistogram.m\src\DELMPHistogram.cpp
    //# make-ERROR: KnowledgeSharedUI\CATKweGraphViewBase.m\src\CATKweGraphViewBase.cpp
    //# make-ERROR: SMAFeaBaseUI\SMAFeaBUIDialogs.m\src\SMAFeaListView.cpp
	CATVidLayScrollable* _pVidLayScrollable;
	CATScrollbarView *_horizontal;
	CATScrollbarView *_vertical;
	float _vwidth;
	float _vheight;
	float _scrollx;
	float _scrolly;
	float _vline;
	float _hline;
	float _inx, _iny, _inw, _inh;

private:
    CATSysWeakRef* _pVidLayScrollable_WR;
	//CATScrollableViewVPE *_vpe;   // IOD : remont� dans CATDrawView
};

#endif
