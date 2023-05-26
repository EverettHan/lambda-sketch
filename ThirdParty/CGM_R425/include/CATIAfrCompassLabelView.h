
#ifndef CATIAfrCompassLabelView_H
#define CATIAfrCompassLabelView_H

// COPYRIGHT DASSAULT SYSTEMES 2011/01/11

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATString.h"
#include "CATCommand.h"

class CATIAfrVIDCompass_var;
class CATIAfrLabelLayout;
class CATICAfrComponentController;

enum OverlayLayoutLabel
{
  Automatic = 0,
  Side      = 1,
  InPlace
};
enum CAfrLabelViewType
{
  UndefLabel = 0,
  F5Label    = 1
};
enum UpdateViewType
{
  Full      = 0,
  Anchor    = 1
};
extern ExportedByCATAfrItf  IID IID_CATIAfrCompassLabelView ;

//-----------------------------------------------------------------------------
/**
* Interface managing Label View.
*
*/
class ExportedByCATAfrItf CATIAfrCompassLabelView: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
    * Set model to display
    **/
    virtual HRESULT SetModel( CATBaseUnknown_var ispModel ) = 0;

    /**
    * Set properties to display (if model implements CATIView)
    **/
    virtual void SetProperties( const CATListOfCATString& iProperties ) = 0;

    /**
    * Get displayed properties
    **/
    virtual const CATListOfCATString& GetProperties( void ) const = 0;

    /**
    * Set maximum number of displayed items. -1 means no limit.
    **/
    virtual void SetMaxDisplay( int iMaxDisplay ) = 0;

    /**
    * Get maximum number of displayed items. -1 means no limit.
    **/
    virtual int GetMaxDisplay( void ) const = 0;

    /**
    * Set layout mode
    **/
    virtual HRESULT SetLayout( const OverlayLayoutLabel& iLayout ) = 0;

    /**
    * Set visibility
    **/
    virtual void SetVisibility( int iVisibility ) = 0;

    /**
    * Refresh for update label
    **/
    virtual HRESULT RefresFromCompass( CATIAfrVIDCompass_var ispCompass ) = 0;

    /**
    * Set layout model
    **/
    virtual HRESULT SetLayoutModel( CATIAfrLabelLayout* ipiLayout ) = 0;

    /**
    * Set CAfrLabelViewType type
    **/
    virtual HRESULT SetCAfrLabelViewType( const CAfrLabelViewType& iType ) = 0;

    /**
    * Set Controller for item
    **/
    virtual HRESULT SetCAfrComponentController( CATICAfrComponentController* ipiCAfrComponentController ) = 0;

    /**
    * Update the View
    **/
    virtual HRESULT UpdateView( const UpdateViewType& iType = Anchor ) = 0;

	/**
	* To Set Viewer 
	**/
	virtual HRESULT SetApplicationViewer(CATCommand * pVizViewer) = 0;
};
#endif
