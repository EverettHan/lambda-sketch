#ifndef _CATVidViewContainer_H
#define _CATVidViewContainer_H

#include <CATVidCtl.h>
#include <CATView.h>

//Temporary:
#include <CATBaseUnknown_WR.h>

class CATDrawView;
class CATVidViewInternalContainer;
class CATCommand;
class CATString;
class CATMathPoint2Df;
class CATMathVectorf;
class CATRep;

/**
 * A CATVidWidget that contains a CATDrawView object
 * Use this class to use CATView objects in VisuImmersiveDialog context.
 * Instanciate this object and use it as the father of you CATView object.
 * Only CATTreeView or CATListView objects are supported.
 * OBSOLETE class use CATVidViewAdaptor
 * DON'T USE !! use CATVidViewAdaptor
 **/
class ExportedByCATView CATVidViewContainer : public CATVidCtl
{
  CATDeclareClass;

public:
  /**
  * Constructor
  **/
  CATVidViewContainer( CATCommand *iParent, const CATString &iIdentifier );
  /**
  * Destructor
  **/
  virtual ~CATVidViewContainer( void );
  /**
  * Get child CATView object
  **/
  CATDrawView *GetView(void);
  /**
  * Set child CATView object. iView should be a child of this.
  **/
  HRESULT SetView( CATDrawView *iView );

  /*
  * CATIViewContainer methods
  */
  int GetContainerVisibility(void);
  void AddRep(CATRep *ipRep);
  void SetEffectiveDimensions (const CATMathPoint2Df& i_requestedEffectiveDimension);
  void GetTranslation (CATMathVectorf & oTranslation);

  virtual void Update(void);
  virtual void TunnelInformation(const CATVidInformation& i_information);


private:
  CATVidViewContainer (CATVidViewContainer &);
  CATVidViewContainer& operator=(CATVidViewContainer &original);

  void WindowResized (CATCallbackEvent iEvt, void *pSender, CATNotification *ipNotification,  
                      CATSubscriberData iData, CATCallback id);

  void CheckPosition(void);
  void UpdateVisibility();
	CATBaseUnknown_WR _viewWR;
	float _viewerWidth, _viewerHeight;
};

#endif
