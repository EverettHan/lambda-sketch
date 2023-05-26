//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010/10/25
//===================================================================
// CATIPLMCompassMaxiPlayer.cpp
// Header definition of class CATIPLMCompassMaxiPlayer
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2010/10/25 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIPLMCompassMaxiPlayer_H
#define CATIPLMCompassMaxiPlayer_H

#include "CATAfrItf.h"
#include "CATIPLMCompassPlayer.h"
#include "CATIAfrVIDCompass.h"

extern ExportedByCATAfrItf  IID IID_CATIPLMCompassMaxiPlayer ;

/**
 * Interface to be implented by compass filters to control the 'Maxi player' area of the PLM Compass
 **/

class ExportedByCATAfrItf CATIPLMCompassMaxiPlayer: public CATIPLMCompassPlayer
{
  CATDeclareInterface;

public:

  //
  //The following methods are reserved for MaxiPlayer
  //

  /**
  * The user has click on Go To Begin
  * Used for maxi player styles
  **/
  virtual void OnGoToBegin(void) = 0;

  /**
  * The user has click on Play Back
  * Used for maxi player styles
  **/
  virtual void OnPlayBack(void) = 0;

  //OnBack (one step backward) already done for mini player.
  //OnPause already done for mini player.
  //OnPlay already done for mini player.
  //OnNext (one step forward) already done for mini player.

  /**
  * The user has click on Go To End
  * Used for maxi player styles
  **/
  virtual void OnGoToEnd(void) = 0;

  /**
  * The user has click on change loop mode
  * Used for maxi player styles
  **/
  virtual void OnChangeLoopMode(CATPLMCompassMaxiPlayerLoopMode iLoopMode) = 0;

  /**
  * The user has changed jump to time
  * Used for maxi player styles
  **/
  virtual void OnJumpToTime(float iPosition) = 0;


  /**
  * The user has changed total duration of animation
  * Used for maxi player styles
  **/
  virtual void onChangeDuration(double iDuration) = 0;

  /**
* The user has changed total duration of animation
* Used for maxi player styles
**/
  virtual void onChangeDuration(float iDuration) = 0;

  /**
  * The user has changed FPS rate
  * Used for maxi player styles
  **/
  virtual void onChangeFps(int iFps) = 0;

  /**
  * The user has changed FPS rate
  * Used for maxi player styles
  **/
  virtual void onChangeFps(float iFps) = 0;

  /**
  * The user has changed Time Control mode to maximum
  * Used for maxi player styles
  **/
  virtual void OnSpeedModeMaximum() = 0;


  /**
  * Get the Speed/FPS/Duration min max and current value to always have the updated information
  */
  virtual void GetSpeedModeInfo(CATPLMCompassMaxiPlayerTimeControlType mode, float &oMin, float &oMax, float &currentValue, float &step) = 0;

  /**
  * Get the Speed/FPS/Duration min max and current value to always have the updated information
  */
  virtual void GetSpeedModeInfomation(CATPLMCompassMaxiPlayerTimeControlType mode, float &oMin, float &oMax, float &currentValue, float &step) = 0;

  /*
  * Get the current active Speed mode
  */
  virtual void GetCurrentSpeedMode(CATPLMCompassMaxiPlayerTimeControlType &oSpeedMode) = 0;

  /**
  * The user has clicked on Export option to export the animation to video
  */
  virtual void onExport() = 0;
/**
* Sets  the  animation player button style.
* @param iStyle [ in ]
*	 Default value is 0.
*    Style type.
* <br><b>Role:</b> It's the customization of your maxi animation player
*    The customization style can be a composition of several style.
*    Example : CATPLMCompassSliderParametersHidden|CATPLMCompassForwardButtonHidden.
*   <br><b>Legal values</b>:
*   <dl>
*     <dt>FirstButtonHidden</dt>
*     <dd>Go to first Button is hidden.</dd>
*     <dt>LastButtonHidden</dt>
*     <dd>Go to Last Button is hidden.</dd>
*     <dt>NextButtonHidden</dt>
*     <dd>Next Frame Button is hidden</dd>
*     <dt>BackButtonHidden</dt>
*     <dd>Go to Previous Frame Button is hidden</dd>
*     <dt>StopButtonHidden</dt>
*     <dd>the Stop button is hidden.</dd>
*     <dt>ExportButtonHidden</dt>
*     <dd>the Export button is hidden.</dd>
*	  <dt>SpeedOptionHidden</dt>
*     <dd>the Speed option is hidden.</dd>
*     <dt>DurationOptionHidden</dt>
*     <dd>the Duration option is hidden.</dd>
*     <dt>FpsOptionHidden</dt>
*     <dd>the FPS option is hidden.</dd>
*   </dl>
*/
virtual CATPLMCompassMaxiPlayerButtonStyle GetMaxiPlayerButtonStyle() = 0;



  /**
  * The user has clicked on simulation options icon.
  * This panel is centralized users must integrate their needs in
  * this panel.
  * A new tab may be designed for that.
  * Used for maxi player styles
  **/
  virtual void OnSimulationOptions(void) = 0;

  /**
  * The user has clicked on play list icon.
  * Used for maxi player styles
  **/
  virtual void OnPlayList(void) = 0;

  /**
  *@Deprecated
  * The user has clicked to increase speed
  * Used for maxi player styles
  **/
  virtual void OnIncreaseSpeed(int iMultiplySpeed)= 0;

  /**
  *@Deprecated
  * The user has clicked to decrease speed
  * Used for maxi player styles
  **/
  virtual void OnDecreaseSpeed(int iMultiplySpeed)= 0;


    /**
  * The user has clicked to increase speed
  * Used for maxi player styles
  **/
  virtual void OnIncreaseSpeed(float iMultiplySpeed)=0;

  /**
  * The user has clicked to decrease speed
  * Used for maxi player styles
  **/
  virtual void OnDecreaseSpeed(float iMultiplySpeed)=0;

  /**
  * The user has entered a value on the editor.
  * If the value is in a wrong format, dispatch a callback to the compas with the good value. 
  * The compass will call teh GetEditorValue to retrieve the correct value.
  * Used for maxi player styles
  **/
  virtual void OnEditorChanged(const CATUnicodeString & i_newValue) = 0;


  /**
  * Method called by the compass to get current editor value
  **/
  virtual CATUnicodeString GetEditorValue() = 0;

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
  virtual CATPLMCompassMaxiPlayerSpeedMode     GetMaxiPlayerSpeedMode() = 0;

  /**
  * @Deprecated use GetSpeedStepAndBoundaries
  */
  virtual void GetMaxiPlayerSpeedStepAndBoundaries(int oStep, int oBoundary) = 0;

    /**
  * Sets  the  maxi player speed step ans boundaires.  
  * <br><b>Role:</b> It's the speed style of your maxi player.
  *    When GetMaxiPlayerSpeedMode has an undef mode.
  *    Step 10 and boundary 30 will make a choice for:
  *    1/30, 1/20, 1/10, 1, 10, 20, 30.
  * @param oStep [ out ]
  * @param oBoundary [ out ]
  */
  virtual void GetSpeedStepAndBoundaries(int &oStep, int & oBoundary) = 0;

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
  virtual CATPLMCompassMaxiPlayerStyle GetMaxiPlayerStyle() = 0;

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
  virtual void GetMaxiPlayerMinMaxUnit(int & oMin,  int & oMax, CATUnicodeString & oUnit) = 0;


  
/**
*
* <br><b>Role</b>: Set the player visibility .
* @param oVisibility The visibility of the player.
* TRUE, the player is visible when user click on Play (default), FALSE, otherwise
* 
* @return S_OK it the visibility is correctly set, E_FAIL (or <> S_OK), the result will not 
* taken account and the player will be displayed
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
*/
virtual HRESULT GetPlayerVisibility(CATBoolean & oVisibility) = 0;

/**
*
* <br><b>Role</b>: Set the default loop mode .
* @param oLoopMode The initial loop mode of the player.
*/
virtual void GetDefaultLoopMode(CATPLMCompassMaxiPlayerLoopMode & oLoopMode) = 0;

/**
*
* <br><b>Role</b>: Returns TRUE if this player supports the synchronization mechanism, FALSE otherwise
* @return 
* <dl>
* <dt><code>TRUE</code> : this player supports the synchronization <dd>
* <dt><code>FALSE </code> : this player does not support synchronization <dd>
* </dl>
*/
virtual CATBoolean IsSupportSynchronization() = 0;


/**
*
* <br><b>Role</b>: Set the title of the simulation that will be displayed in the Synchronisation Panel.
If not title, the title will be compound of "SIM_" with an index.
* @param o_title i_title the title of the current simulation
* 
* @return 
* <dl>
* <dt><code>S_OK</code> <dd>
* <dt><code>E_FAIL</code> <dd>
* </dl>
*/
virtual HRESULT GetCurrentSimulationTitle(CATUnicodeString & o_title) = 0;



/**
*
* <br><b>Role</b>: Get the state of the simulation before the window be deactivated. This value
will be restored when the window will be activated again. 
<b>Note</b> This method will be called only if the simulation was running when the window is deactivated
* @param &oSave the output value of the simulation state to save, TRUE the simulation will run when the window is reactivated, FALSE the simulation will not run
* 
* @return
* <dl>
* <dt><code>S_OK</code> The saved value will be taken account for the restoring  <dd>
* <dt><code>E_FAIL</code> the saved value is ignored <dd>
* </dl>
*/
virtual HRESULT GetSaveSimulationMode( CATBoolean &oSave ) = 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler( CATIPLMCompassMaxiPlayer, CATIPLMCompassPlayer );

#endif