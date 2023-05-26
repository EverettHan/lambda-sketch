// COPYRIGHT Dassault Systemes 2008

#ifndef CATBarView_H
#define CATBarView_H

#include "CATAfrItf.h"
#include "CATIBarViewModel.h"
#include "CATIBarViewController.h"
#include "CATBoolean.h"
#include "CATBaseUnknown.h"

class CATCommand;
class CATVizViewer;
class l_CATIAfrBalloon;
class CATViewpoint;


/**
* Class for contextual options container immersive representation.
* <br><b>Role</b>: Provide an immersive container representation for contextual options.
* <p>
* French users only: vous trouverez une petite documentation en français dans http://codewiki/codewiki/index.php/Phylactère_en_V6
* <p>
* This class is the View of the container. It is displayed as a bubble containing icons of the options.
* The options are the Model of the container.
* <br>
* The container is displayed in a graphical Viewer and is linked to a graphical point.
* This link appears as a dotted line drawn between the container and this graphical point.
* <br>
* Model objects icons are displayed in a horizontal bubble. Each of the first level objects may have several components,
* these components are displayed in a vertical bubble when the user points the compound object icon. Only 2 levels are supported.
* <br>
* <br>
* CATBarView should not be used to control commands. It is designed only to display options the user can switch depending on his immediate context.
* <br>
* If you try to control commands from a CATBarView no standard command controller is provided:
* <ul>
* <li>There is no means to link an option to a command as provided by CATCommandHeader class.
* <li>You may start a command by yourself but the button will not stay pressed when the command is running.
* <li>you will not be able to gray out options.
* </ul>
* <br>
* <br>
* Derive @href CATExtIBarViewModel adapter to create the Model of the bar.
* <br>
* Derive @href CATExtIBarViewController adapter to create the Controller of the bar.
*
* @example
* See CATView.tst sample:
* <ul>
* <li>CATBarView use case in is CATBarViewTests.m.
* <li>Sample application is in CATBarViewStart.m, start it using "mkrun -c CATBarViewStart"
* </ul>
*/
class ExportedByCATAfrItf CATBarView : public CATBaseUnknown
{
  friend class CATBarView_UT;

  CATDeclareClass;
  public:
	/** 
	* CATBarView constructor.
	* <br><b>Role</b>: Constructs a CATBarView instance.
	*
	* @param pViewer [in]
	*   The viewer where the bar will be drawn.
	* @param iName [in]
	*   The name of the bar.
	*/
	CATBarView (const CATString &iName);

    virtual ~CATBarView (void);

    /** 
    * Get the name of the bar.
    *
    * @return
    *   The name of the bar set at its construction.
    */
    const CATString &GetName (void) const;

    /** 
    * Set parent container.
    * <br><b>Role</b>: Sets the parent container of the bar.
    * <br> Only CATVizViewer instances are accepted.
    *
    * @param ipParentContainer [in]
    *   The parent container of the bar View.
    *
    * @return
    *   <code>S_OK</code> if the parent was accepted, otherwise <code>E_FAIL</code>.
    */
    HRESULT SetParentContainer (CATBaseUnknown *ipParentContainer);

    /** 
    * Set visibility status of the bar.
    * <br><b>Role</b>: Shows or hides the bar.
    *
    * @param iVisibility [in]
    *   TRUE to show the bar, FALSE to hide it.
    */
    void SetVisibility (CATBoolean iVisibility);

    /** 
    * Get visibility status of the bar.
    * <br><b>Role</b>: Tells whether the bar is visible or not.
    *
    * @return
    *   TRUE if the bar is visible, FALSE else.
    */
    CATBoolean GetVisibility (void) const;

    /** 
    * Set discretion status of the bar.
    * <br><b>Role</b>: The discretion attribute makes the bar become transparent when the mouse cursor
    * goes away from it. The default is TRUE.
    * <br>Use this method only once just after constructing the bar.
    *
    * @param iDiscretion [in]
    *   TRUE to make the bar discrete, FALSE to make the bar never discrete.
    */
    void SetDiscretion (CATBoolean iDiscretion);

    /** 
    * Set activity status of the bar.
    * <br><b>Role</b>: The activity attribute makes the bar become the active immersive window or not.
    * The default is FALSE, i.e. the bar is not the active window.
    * <br>When the bar is inactive, there is a delay when the mouse cursor enters the window to make it active.
    * <br>Please notice making another window active will make the bar window inactive.
    * <br>Use this method only once just after constructing the bar.
    *
    * @param iActive [in]
    *   TRUE to make the bar active, FALSE to make the bar inactive.
    */
    void SetActive (CATBoolean iActive);

    /** 
    * Set the viewpoint of the bar.
    * <br><b>Role</b>: The default viewpoint is the main viewpoint of the viewer
    * but you may use this method to specify another viewpoint.
    * <br>Use this method only once just after constructing the bar.
    *
    * @param iActive [in]
    *   TRUE to make the bar active, FALSE to make the bar inactive.
    */
    void SetViewpoint (CATViewpoint *ipViewpoint);
 
    /** 
    * Set the pointer to the model of the bar.
    *
    * <br><b>Role</b>: Sets the Model of the bar. The Model must be set before the Build method of the bar is called.
    * <br>Use @href CATExtIBarViewModel adapter to create the Model of the bar.
    * <br>Setting the model will build the view. No bar will be displayed if no model is set.
    *
    * @param iModel [in]
    *   The model pointer.
    *
    * @return
    *   <code>S_OK</code> if everything ran ok, otherwise <code>E_FAIL</code>.
    */
    HRESULT SetModel (CATIBarViewModel_var iModel);

    /** 
    * Get a pointer to the Model of the bar.
    *
    * @return
    *   Pointer to the Model.
    */
    CATIBarViewModel_var GetModel (void) const;

    /** 
    * Set the pointer to the Controller of the bar.
    *
    * <br><b>Role</b>: Sets the Controller of the bar. The Controller must be set before the Build method of the bar is called.
    * Use @href CATExtIBarViewController adapter to create the Controller of the bar.
    *
    * @param iModel [in]
    *   The model pointer.
    *
    * @return
    *   <code>S_OK</code> if everything ran ok, otherwise <code>E_FAIL</code>.
    */
    void SetController (CATIBarViewController_var iController);

    /** 
    * Get a pointer to the Controller of the bar.
    *
    * @return
    *   Pointer to the Controller.
    */
    CATIBarViewController_var GetController (void) const;

    /** 
    * Set dockable status of the bar.
    * <br><b>Role</b>: The attribute "dockable" allows the bar to attach to the four areas of the window 
    * (Top, Bottom, Left or Right).
    * <br><b>Note</b>:For the moment, this attribute is active only when the Multitouch setting is enabled.
    * The default is FALSE if Multitouch Setting is disabled, i.e. the bar is not dockable and TRUE if not.
    * <br>Use this method only once just after constructing the bar and set your model. 
    *
    * @param iDockable [in]
    *   TRUE to make the bar dockable, FALSE to make the bar non dockable.
    */
    void SetDockable (const CATBoolean & iDockable);

    /** 
    * Get dockable status of the bar.
    * <br><b>Role</b>: Tells whether the bar is dockable or not.
    *
    * @return
    *   TRUE if the bar is dockable, FALSE else.
    */
    CATBoolean IsDockable (void) const;


    /** 
    * Lock all bubbles.
    * <br><b>Role</b>: Allow to lock all bubbles when their view is not desired.
    * For example, during the simulation
    *
    * @param iLocked [in]
    *   TRUE to lock all bubbles, FALSE to unlock.
    */
    static void SetLocked(const CATBoolean & iLocked);

    /** 
    * Gets locked property of all bubbles
    * <br><b>Role</b>: Tells whether all bubbles are locked or not. 
    *
    * @return
    *   TRUE if all bubbles are locked, FALSE else.
    */
    static  CATBoolean IsLocked (void);

    /** 
    * Hide or show all bubbles when experience player is launched.
    * <br><b>Role</b>: Allow to show/hide all bubbles when experience player is launched.
    *
    * @param iVisible [in]
    *   TRUE to show all bubbles, FALSE to hide.
    */
    void SetVisibilityWhenPlayerLaunched(const CATBoolean & iVisible);

    /** 
    * Gets visibility property of all bubbles when experience player is launched.
    * <br><b>Role</b>: Tells whether all bubbles are shown or not when experience player is launched. 
    *
    * @return
    *   TRUE if all bubbles are shown, FALSE else.
    */
    CATBoolean IsVisibleWhenPlayerLaunched(void) const;

  private:
    // Copy constructor (not implemented)
    CATBarView (const CATBarView&);
    // Default constructor (not implemented)
    CATBarView ();
    CATBaseUnknown * GetLetter();
    CATCommand *   _letter;
    CATString      _name;
    CATBoolean     _discretion;
    CATBoolean     _active;
    CATViewpoint * _pViewpoint;

    static CATBoolean _locked;
};

#endif
