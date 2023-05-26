#ifndef _CATVidViewAdaptor_H
#define _CATVidViewAdaptor_H

#include <CATVidCtl.h>
#include <CATView.h>
#include <CATISYPIntrospectableProvider.h>

class CATVidViewInternalContainer;
class CATCommand;
class CATString;

/**
 * Embed CATView objects in VisuImmersiveDialog dialog.
 * <br><b>Role</b>: Adaptor for inserting a @href CATDrawView instance in a @href CATVidContainer.
 * <br>
 * An instance of CATVidViewAdaptor may be placed anywhere in any Vid container.
 * <br>
 * An instance of CATVidViewAdaptor can contain only one CATDrawView instance. Instanciate CATVidViewAdaptor for each @href CATDrawView you want to see in a Vid container.
 * <br>
 * The first argument of the CATDrawView constructor MUST be the CATVidViewAdaptor instance.
 * <br>
 * <br>
 * Examples :
 * <ul>
 * <li> Good use
 * <br>
 * CATVidViewAdaptor *pViewAdaptor= new CATVidViewAdaptor(myCATVizViewer, "ViewAdaptor" );
 * <br>
 * CATTreeView *pTreeView = new CATTreeView( pViewAdaptor, "TreeSample" );
 * <li> wrong use
 * <br>
 * CATVidViewAdaptor *pViewAdaptor= new CATVidViewAdaptor(myCATVizViewer, "ViewAdaptor" );
 * <br>
 * CATTreeView *pTreeView = new CATTreeView( myCATVizViewer, "TreeSample" ); // BAD, myCATVizViewer is the wrong father
 * </ul>
 * Only CATTreeView or CATListView objects are supported as childs of CATVidViewAdaptor.
 * Using any other CATView may result in any kind of bad behavior.
 **/

class CATVidLayScrollable;

class ExportedByCATView CATVidViewAdaptor : public CATVidCtl
{
  CATDeclareClass;

public:

  CATVidViewAdaptor (CATCommand *iParent, const CATString &iIdentifier);
  virtual ~CATVidViewAdaptor (void);

  /* Access VID scrollable manager
   * Allows for example to change scroll percentage
   */
  CATVidLayScrollable *GetVidScrollable();

  /*
   * Get letter object. Do not use, INTERNAL usage only.
   */
  CATVidViewInternalContainer *GetInternalVidViewAdaptor (void);

	void TunnelNotification( CATCommand *, CATNotification *, CATCommandClientData iData );

  /**
  * Display a notification
  *
  * @par
  * A call to @ref ConfigureNotification is required first.
  *
  * @param iText The text to be displayed in the notification.
  *
  * @param iIconName The name of the icon to be displayed in the notification.
  *
  * @param iIconDimension The dimension of the icon to be displayed in the notification.
  *
  * @param iLevel The level criticality to be used. 
  * Two level are actually considered : "Information" and default one.
  *
  * @param iPosition The position of the tooltip
  *
  * @see CATVid#ConfigureNotification
  */
  void DisplayNotification(const CATUnicodeString& iText,
    const CATUnicodeString& iIconName,
    const CATMathPoint2Df& iIconDimension,
    const CATUnicodeString& iLevel = CATUnicodeString(""),
    const CATMathPoint2Df& iPosition = CATMathPoint2Df(0.f,0.f));

  void DisplayTooltip( CATBaseUnknown_var ispBase );

private:

  CATVidViewAdaptor ();
  CATVidViewAdaptor (CATVidViewAdaptor &);
  CATVidViewAdaptor& operator=(CATVidViewAdaptor &original);

  void _EventHandler(CATBaseUnknown *ipSender, CATSYPEventArgs *ipArgs);

  CATVidViewInternalContainer * _pInternalContainer;
  CATVidLayScrollable *_pScrollable;
};

#endif
