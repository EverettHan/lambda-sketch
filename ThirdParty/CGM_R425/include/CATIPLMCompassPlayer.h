#ifndef _CATIPLMCompassPlayer_H
#define _CATIPLMCompassPlayer_H

#include <CATBaseUnknown.h>
#include <CATEventSubscriber.h>
#include <CATPLMCompassStyle.h>
#include "UIModelInterfaces.h"

extern ExportedByUIModelInterfaces IID IID_CATIPLMCompassPlayer;

/**
 * Interface to be implented by compass filters to control the 'player' area of the PLM Compass
 **/
class ExportedByUIModelInterfaces CATIPLMCompassPlayer : public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	 * The user has click on Pause
	 **/
	virtual void OnPause(void) = 0;
	/**
	 * The user has click on Play
	 **/
	virtual void OnPlay(void) = 0;
	/**
	 * The user has click on Back
	 **/
	virtual void OnBack(void) = 0;
	/**
	 * The user has click on Next
	 **/
	virtual void OnNext(void) = 0;
	/**
	 * The user has moved the slider.
	 * iPosition is the new position.
	 * GetPosition will be called by the compass to get the modified position
	 * => implementation can constraint the position this way.
	 **/
	virtual void OnSlider( float iPosition ) = 0;
	/**
	 * Method called by the compass to get current slider position
	 **/
	virtual float GetPosition(void) = 0;
	/**
	 * Method called by the compass to register on position change event
	 **/
	virtual CATCallback RegisterUpdateEvent( CATEventSubscriber *iSubscriber,
											CATSubscriberMethod iMethod,
											CATSubscriberData iData )= 0;
	/**
	 * Method called by views to unregister on play progress
	 **/
	virtual void UnRegisterUpdateEvent( CATEventSubscriber *iSubscriber,
											CATCallback iUpdateCallback )= 0;
    /**
    */
    virtual CATUnicodeString GetSliderParameters( ) = 0;

    /**
    * Sets  the  mini player style.  
    * @param iStyle [ in ]
    *	 Default value is 0.
    *    Style type.
    * <br><b>Role:</b> It's the style of your mini player.
    *    The style can be a composition of several style.
    *    Example : CATPLMCompassSliderParametersHidden|CATPLMCompassForwardButtonHidden.
    *   <br><b>Legal values</b>:
    *   <dl>
    *     <dt>CATPLMCompassMiniPlayerHidden</dt>
    *     <dd>the mini player is hidden.</dd>
    *     <dt>CATPLMCompassSliderHidden</dt>
    *     <dd>the slider is hidden.</dd>
    *     <dt>CATPLMCompassSliderNoPick</dt>
    *     <dd>the slider is not selectable.</dd>
    *     <dt>CATPLMCompassSliderParametersHidden</dt>
    *     <dd>the slider parameters are hidden.</dd>
    *     <dt>CATPLMCompassBackwardButtonHidden</dt>
    *     <dd>the backward button is hidden.</dd>
    *     <dt>CATPLMCompassForwardButtonHidden</dt>
    *     <dd>the forward button is hidden.</dd>
    *   </dl>
    */
    virtual CATPLMCompassStyle GetMiniPlayerStyle() = 0;
};

CATDeclareHandler( CATIPLMCompassPlayer, CATBaseUnknown );

#endif
