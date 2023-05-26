
//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010/11/05
//===================================================================
// CATAdapterPLMCompassMaxiPlayer.cpp
// Header definition of class CATAdapterPLMCompassMaxiPlayer
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2010/11/05 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATAdapterPLMCompassMaxiPlayer_H
#define CATAdapterPLMCompassMaxiPlayer_H

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATIPLMCompassMaxiPlayer.h"
#include "CATUnicodeString.h"

//-----------------------------------------------------------------------

class ExportedByCATAfrItf CATAdapterPLMCompassMaxiPlayer: public CATBaseUnknown

{
CATDeclareClass;

public:

// Standard constructors and destructors
// -------------------------------------
CATAdapterPLMCompassMaxiPlayer ();
virtual ~CATAdapterPLMCompassMaxiPlayer ();

/**
	 * The user has click on Pause
	 **/
	virtual void OnPause(void);
	/**
	 * The user has click on Play
	 **/
	virtual void OnPlay(void);
	/**
	 * The user has click on Back
	 **/
	virtual void OnBack(void);
	/**
	 * The user has click on Next
	 **/
	virtual void OnNext(void);
	/**
	 * The user has moved the slider.
	 * iPosition is the new position.
	 * GetPosition will be called by the compass to get the modified position
	 * => implementation can constraint the position this way.
	 **/
	virtual void OnSlider( float iPosition );
	/**
	 * Method called by the compass to get current slider position
	 **/
	virtual float GetPosition(void);
	/**
	 * Method called by the compass to register on position change event
	 **/
	virtual CATCallback RegisterUpdateEvent( CATEventSubscriber *iSubscriber,
											CATSubscriberMethod iMethod,
											CATSubscriberData iData );
	/**
	 * Method called by views to unregister on play progress
	 **/
	virtual void UnRegisterUpdateEvent( CATEventSubscriber *iSubscriber,
											CATCallback iUpdateCallback );
    /**
    */
    virtual CATUnicodeString GetSliderParameters( );

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
    virtual CATPLMCompassStyle GetMiniPlayerStyle();


    /**
  * The user has click on Go To Begin
  * Used for maxi player styles
  **/
  virtual void OnGoToBegin(void);

  /**
  * The user has click on Play Back
  * Used for maxi player styles
  **/
  virtual void OnPlayBack(void);

  //OnBack (one step backward) already done for mini player.
  //OnPause already done for mini player.
  //OnPlay already done for mini player.
  //OnNext (one step forward) already done for mini player.

  /**
  * The user has click on Go To End
  * Used for maxi player styles
  **/
  virtual void OnGoToEnd(void);

  /**
  * The user has click on change loop mode
  * Used for maxi player styles
  **/
  virtual void OnChangeLoopMode(CATPLMCompassMaxiPlayerLoopMode iLoopMode);

  /**
  * The user has changed jump to time
  * Used for maxi player styles
  **/
  virtual void OnJumpToTime(float iPosition);

  /**
  * The user has changed total duration of animation
  * Used for maxi player styles
  **/
  virtual void onChangeDuration(double iDuration);

  /**
  * The user has changed total duration of animation
  * Used for maxi player styles
  **/
  virtual void onChangeDuration(float iDuration);

  /**
  * Get the Speed/FPS/Duration min max and current value to always have the updated information
  */
  virtual void GetSpeedModeInfo(CATPLMCompassMaxiPlayerTimeControlType mode, float &oMin, float &oMax, float &currentValue, float &step);
  
  /**
  * Get the Speed/FPS/Duration min max and current value to always have the updated information
  */
  virtual void GetSpeedModeInfomation(CATPLMCompassMaxiPlayerTimeControlType mode, float &oMin, float &oMax, float &currentValue, float &step);


  /*
  * Get the current active Speed mode
  */
  virtual void GetCurrentSpeedMode(CATPLMCompassMaxiPlayerTimeControlType &oSpeedMode);

  /*
  * The user has selected Export option to export the animation to video
  */
  virtual void onExport();

  /**
  * The user has changed FPS rate
  * Used for maxi player styles
  **/
  virtual void onChangeFps(int iFps);

  /**
* The user has changed FPS rate
* Used for maxi player styles
**/
  virtual void onChangeFps(float iFps);

  /**
  * The user has changed Time Control mode to maximum
  * Used for maxi player styles
  **/
  virtual void OnSpeedModeMaximum();

  /**
	  * Sets  the  maxi player button style.
	  * <br><b>Role:< / b> It's the customization of your maxi player.
	  * The style can  be a composition of several style.
  */
  virtual CATPLMCompassMaxiPlayerButtonStyle GetMaxiPlayerButtonStyle();

  /**
  * The user has clicked on simulation options icon.
  * This panel is centralized users must integrate their needs in
  * this panel.
  * A new tab may be designed for that.
  * Used for maxi player styles
  **/
  virtual void OnSimulationOptions(void);

  /**
  * The user has clicked on play list icon.
  * Used for maxi player styles
  **/
  virtual void OnPlayList(void);

  /**
  *@Deprecated
  * The user has clicked to increase speed
  * Used for maxi player styles
  **/
  virtual void OnIncreaseSpeed(int iMultiplySpeed);

  /**
  *@Deprecated
  * The user has clicked to decrease speed
  * Used for maxi player styles
  **/
  virtual void OnDecreaseSpeed(int iMultiplySpeed);

  /**
  * The user has clicked to increase speed
  * Used for maxi player styles
  **/
  virtual void OnIncreaseSpeed(float iMultiplySpeed);

  /**
  * The user has clicked to decrease speed
  * Used for maxi player styles
  **/
  virtual void OnDecreaseSpeed(float iMultiplySpeed);
  /**
  * The user has entered a value on the editor.
  * If the value is in a wrong format, dispatch a callback to the compas with the good value. 
  * The compass will call teh GetEditorValue to retrieve the correct value.
  * Used for maxi player styles
  **/
  virtual void OnEditorChanged(const CATUnicodeString & i_newValue);


	/**
	 * Method called by the compass to get current editor value
	 **/
  virtual CATUnicodeString GetEditorValue();

  /**
  * Sets  the  maxi player speed mode.  
  * <br><b>Role:</b> It's the speed stype of your maxi player.
  *    Defined in CATPLMCompass.h
  *    The style cannot  be a composition of several style.
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>CATPLMCompassMaxiPlayerSpeedUndef</dt>
  *     <dt>CATPLMCompassMaxiPlayerSpeedUserDefined</dt>
  *     <dd>When the speed type is user defined,</dd>
  *     <dd>Speed is defined by GetMaxiPlayerSpeedStepAndBoundaries.</dd>
  *     <dt>CATPLMCompassMaxiPlayerSpeedA</dt>
  *     <dd>the maxi player has style speedA.</dd> 
  *   </dl>
  */
  virtual CATPLMCompassMaxiPlayerSpeedMode     GetMaxiPlayerSpeedMode();

  /**
  * Sets  the  maxi player speed step ans boundaires.  
  * <br><b>Role:</b> It's the speed style of your maxi player.
  *    When GetMaxiPlayerSpeedMode has an undef mode.
  *    Step 10 and boundary 30 will make a choice for:
  *    1/30, 1/20, 1/10, 1, 10, 20, 30.
  * @param oStep [ out ]
  * @param oBoundary [ out ]
  */
  virtual void GetMaxiPlayerSpeedStepAndBoundaries(int oStep, int oBoundary);

   virtual void GetSpeedStepAndBoundaries(int &oStep, int & oBoundary);
  /**
  * Sets  the  maxi player style.  
  * @param iStyle [ in ]
  *	 Default value is 0.
  *    Style type.
  * <br><b>Role:</b> It's the style of your maxi player.
  *    Defined in CATPLMCompass.h
  *    The style cannot  be a composition of several style.
  *   <br><b>Legal values</b>:
  *   <dl>
  *   </dl>
  */
  virtual CATPLMCompassMaxiPlayerStyle GetMaxiPlayerStyle();

  /**
  * Gets  the  min, max and unit for the maxi player.  
  * @param oMin [ out ]
  *    Minimum of the slider.
  * @param oMax [ out ]
  *    Maximum of the slider.
  * @param oUnit [ out ]
  *    Default value "s" (seconds)
  *    unit of the slider.
  * <br><b>Role:</b> Gets  the  min, max and unit for the maxi player
  *   <br><b>Legal values</b>:
  *   <dl>
  *   </dl>
  */
  virtual void GetMaxiPlayerMinMaxUnit(int & oMin,  int & oMax, CATUnicodeString & oUnit);

  virtual HRESULT GetPlayerVisibility(CATBoolean & oVisibility);

  virtual void GetDefaultLoopMode(CATPLMCompassMaxiPlayerLoopMode & oLoopMode);
  virtual CATBoolean IsSupportSynchronization();
  virtual HRESULT GetCurrentSimulationTitle(CATUnicodeString & o_title) ;
  virtual HRESULT GetSaveSimulationMode( CATBoolean &oSave );
private:
// Copy constructor and equal operator
// -----------------------------------
CATAdapterPLMCompassMaxiPlayer (CATAdapterPLMCompassMaxiPlayer &);
CATAdapterPLMCompassMaxiPlayer& operator=(CATAdapterPLMCompassMaxiPlayer&);
};

//-----------------------------------------------------------------------

#endif

