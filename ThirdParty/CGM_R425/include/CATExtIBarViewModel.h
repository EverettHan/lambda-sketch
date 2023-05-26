// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATExtIBarViewModel.h
// Adapter for CATExtIBarViewModel interface
//
//===================================================================
//
#ifndef CATExtIBarViewModel_H
#define CATExtIBarViewModel_H

#include "CATBaseUnknown.h"
#include "CATAfrItf.h"
#include "CATIBarViewModel.h"
#include "CATString.h"
#include "CATUnicodeString.h"

class CATPixelImage;
class l_CATIAfrBalloonModel;
class CATMathPointf;
class CATMathPoint2Df;
//------------------------------------------------------------------

/**
* Class representing the Model of an immersive toolbar.
* <br>
* Use this adapter to implement CATIBarViewModel interface.
* <br>
* See @href CATBarView for all explanations on the component.
* <br>
* Call Update method to update views when model changes.
*/
class ExportedByCATAfrItf CATExtIBarViewModel: public CATBaseUnknown
{
  CATDeclareClass;
public:

  CATExtIBarViewModel();
  virtual ~CATExtIBarViewModel();

  /** 
  * Get components of a Bar element.
  *
  * <br><b>Role</b>: Gives the Model structure.
  * @param iBarComponent [in]
  *   iBarComponent sould be NULL_var to ask first level components, if not NULL_var it should be a compound component (CATBarViewToolbar style).
  * @param oBarComponentList [out]
  *   List of Model components of iBarComponent, or first level Model components if iBarComponent=NULL_var
  */
  virtual void GetBarViewComponents (CATBaseUnknown_var iBarComponent, CATListOfCATBaseUnknown_var &oBarComponentList);

  /**
   * Ask for a information about a Bar element.
   **/
  virtual void GetStyle (CATBaseUnknown_var iBarComponent, int &oStyle);
  virtual void GetIcon (CATBaseUnknown_var iBarComponent, int iconState, CATUnicodeString &oIconName);
  virtual void GetShortHelp (CATBaseUnknown_var iBarComponent, CATUnicodeString &oHelp);
  virtual void GetHelp      (CATBaseUnknown_var iBarComponent, CATUnicodeString &oHelp);
  virtual void GetLongHelp  (CATBaseUnknown_var iBarComponent, CATUnicodeString &oHelp);
	virtual void GetRecordName(CATBaseUnknown_var iBarComponent, CATUnicodeString &oName);
	virtual void GetTitle			(CATBaseUnknown_var iBarComponent, CATUnicodeString &oTitle);
  /** Dev for CATPixelImage support **/
  virtual CATPixelImage * GetPixelImage(CATBaseUnknown_var iBarComponent, int iconState);

	virtual void GetTooltipResourcesInfo(CATBaseUnknown_var iBarComponent, CATUnicodeString &oResourcesFile, CATUnicodeString &oResourcesID);

  /**
   * Positionning management. Use only one of the 3 methods to return the position of your bar.
  **/
  /**
  * Bar 3D anchor point. Initial 3D position for the linked object. A dotted line will link the bar and this point.
  **/
  virtual void GetBarAnchorPoint (CATMathPointf & oPoint3D);
  /**
  * Bar 2D connection point. Initial position for the bar up left corner.
  **/
  virtual void GetBarConnectionPoint (CATMathPoint2Df & oPoint2D);

  /**
   * Set the initial position of your bar. Has no effect once the bar is displayed
  **/
  virtual void SetBarAnchorPoint (const CATMathPointf & iPoint3D);
  virtual void SetBarConnectionPoint (const CATMathPoint2Df & iPoint2D);

  // Obsolete, has no effect, do not use.
  virtual void SetBarRightCornerPosition (const int iRightPx, const int iTopPx);



  /**
  * Method called by views to register to model update event.
  **/
  virtual CATCallback RegisterUpdateEvent( CATEventSubscriber *iSubscriber, CATSubscriberMethod iMethod, CATSubscriberData iData );
  /**
  * Method called by views to unregister to model update event
  **/
  virtual void UnRegisterUpdateEvent( CATEventSubscriber *iSubscriber, CATCallback iUpdateCallback );

  /**
  * Ask for update of views from model change
  **/
  HRESULT Update(void);


private:

  l_CATIAfrBalloonModel *_letter;
  friend class CATBarView_UT;
};

#endif
