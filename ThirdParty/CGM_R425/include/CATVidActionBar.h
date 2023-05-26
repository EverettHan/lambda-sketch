#ifndef CATVidActionBar_H
#define CATVidActionBar_H

#include <VisuDialogEx.h>
#include <CATVidFraPanel.h>
#include <CATBaseUnknown.h>
#include <CATSYPArray.h>
#include <CATSYPDataBlockFactory.h>
#include <CATVidFraMessageBox.h>

class CATVidMdlStandardTree;
class CATUnicodeString;
class CATBaseUnknown;
class CATSYPEventArgs;
class CATVidCtlButton;
class CATVidMdlIndex;
class CATSYPEvent;
class CATSYPEventFactory;
class CATVidFraPrePlaceChangedEventArgs;
class CATSYPEventHandlersSupport;
class CATSYPClassEventHandlersSupport;
class CATVidWidget;
class CATVidMdlStructureChangedEventArgs;
class CATVidLayFlow;
class CATVidLayStack;
class CATVidMdlEventItemDataModifiedArgs;
class CATSysPreferenceRepository;
class CATVidCtlActionBarV3FlyOut;
class CATVidDraggedEventArgs;
class CATVidDnDDataEventArgs;
class CATVidDnDEventArgs;
class CATSysWeakRef;
class CATSYPEventHandler;
class CATVidCtl;
class CATVidCtlActionBarV3Group;
class CATVidCtlActionBarV3Section;
class CATVidMouseAndKeyboardEventArgs;
class CATVidMdlContextMenu;
class CATVidMouseEventArgs;
class CATVidTabContextMenuEventArgs;
class CATVidActionBarContainer;
class CATVidActionBarContentFactory;
class CATVidActionBarSectionCache;
class CATVidFraDialogButtonClickedEventArgs;
class CATVizViewer;

/**
 * This component is aimed to display a StandardModelTree as an action bar.
 * The content of the model is restricted to the specification of the representation model of the AB.
 * The modifications of the structure of the AB will be tracked by listening the model modification events.
 * The action launching will be tracked by listening the #ActionLaunched event.
 */
class ExportedByVisuDialogEx CATVidActionBar : public CATBaseUnknown
{
  CATDeclareClass;

public:
  /** Default constructor */
  CATVidActionBar();
  /** Destructor */
  virtual ~CATVidActionBar();

  /**
   * Sets the model to display through the ActionBar view.
   *
   * @param i_pModel the model to display.
   */
  void SetModel(CATVidMdlStandardTree* i_pModel);
  /**
   * Get the model displayed by this ActionBar component.
   *
   * @return the model displayed by the ActionBar component
   */
  CATVidMdlStandardTree* GetModel() const;

  /**
   * Set the flag that controls the display of labels for buttons and fly-outs.
   *
   * @param i_displayButtonsLabelFlag value to set to the flag that controls
   * the display of labels for buttons and fly-outs. 1 means that labels will
   * be displayed, 0 means they will be hidden.
   */
  void SetDisplayButtonsLabelFlag(int i_displayButtonsLabelFlag);
  /**
   * Get the value of the flag that controls the display of labels for buttons
   * and fly-outs.
   *
   * @return 1 when the labels are displayed, 0 otherwise.
   */
  int GetDisplayButtonsLabelFlag() const;

  /**
   * Get the @c ActionLaunched event.
   *
   * @par Emission
   * The @c ActionLaunched event is emitted whenever an action is launched
   * through buttons or combo by single click.
   *
   * @par EventProperties
   *   @li Name: @c "ActionLaunched"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATSYPEventActionLaunchedArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * ActionLaunched();
  /**
   * Get the @c ActionLocked event.
   *
   * @par Emission
   * The @c ActionLocked event is emitted whenever an action is launched
   * through buttons or combo by double click.
   *
   * @par EventProperties
   *   @li Name: @c "ActionLocked"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATSYPEventActionLaunchedArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * ActionLocked();
  /**
   * Get the @c ResetCustomization event.
   *
   * @par Emission
   * The @c ResetCustomization event is emitted whenever the user requested to
   * reset the customization of ActionBar.
   *
   * @par EventProperties
   *   @li Name: @c "ResetCustomization"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * ResetCustomization();
  /**
   * Get the @c CustomizationOn event.
   *
   * @par Emission
   * The @c CustomizationOn event is emitted whenever the Customization option
   * of the contextual menu is clicked to be set on.
   *
   * @par EventProperties
   *   @li Name: @c "CustomizationOn"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * CustomizationOn();
	/**
   * Get the @c CustomizationOff event.
   *
   * @par Emission
   * The @c CustomizationOff event is emitted whenever the Customization option
   * of the contextual menu is clicked to be set off.
   *
   * @par EventProperties
   *   @li Name: @c "CustomizationOff"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * CustomizationOff();
  /**
   * Returns the @c Dragged event.
   *
   * @par Emission
   * The @c Dragged event is emitted whenever a drag operation is started on a
   * command button or fly-out.
   *
   * @par EventProperties
   *   @li Name: @c "Dragged"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * Dragged();
  /**
   * Returns the @c CanImportData event.
   *
   * @par Emission
   * The @c CanImportData event is emitted whenever the current control that is
   * under the mouse cursor is queried to know whether it is interrested in
   * handling a drop operation.
   *
   * @par EventProperties
   *   @li Name: @c "CanImportData"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidMdlStructureChangedEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * CanImportData();
  /**
   * Returns the @c ImportDataFromActionBar event.
   *
   * @par Emission
   * The @c ImportDataFromActionBar event is emitted whenever a drop occurred
   * on the control that is under the mouse cursor and the drag operation comes
  * from the Action Bar itself.
   *
   * @par EventProperties
   *   @li Name: @c "ImportDataFromActionBar"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidMdlStructureChangedEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * ImportDataFromActionBar();
  /**
  * Returns the @c ImportDataFromActionPad event.
  *
   * @par Emission
  * The @c ImportDataFromActionPad event is emitted whenever a drop occurred
  * on the control that is under the mouse cursor and the drag operation comes
  * from the Action Pad.
  *
  * @par EventProperties
  *   @li Name: @c "ImportDataFromActionPad"
  *   @li Type of propagation: @c NoPropagation
  *   @li Type of argument: @ref CATVidDnDDataEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on the returned
  * pointer.
  */
  static CATSYPEvent * ImportDataFromActionPad();
  /**
   * Returns the @c ImportDataFromCustomizePanel event.
   *
   * @par Emission
   * The @c ImportDataFromCustomizePanel event is emitted whenever a drop occurred
   * on the control that is under the mouse cursor and the drag operation comes
   * from the CustomizePanel.
   *
   * @par EventProperties
   *   @li Name: @c "ImportDataFromCustomizePanel"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidMdlStructureChangedEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * ImportDataFromCustomizePanel();
  /**
   * Returns the @c RemoveCommand event.
   *
   * @par Emission
   * The @c RemoveCommand event is emitted whenever the contextual menu entry
   * Remove is clicked on a button.
   *
   * @par EventProperties
   *   @li Name: @c "RemoveCommand"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidMdlStructureChangedEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * RemoveCommand();
  /**
   * Returns the @c RemoveFlyOut event.
   *
   * @par Emission
   * The @c RemoveFlyOut event is emitted whenever the contextual menu entry
   * Remove is clicked on a flyout.
   *
   * @par EventProperties
   *   @li Name: @c "RemoveFlyOut"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidMdlStructureChangedEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * RemoveFlyOut();
  /**
   * Returns the @c AddSection event.
   *
   * @par Emission
   * The @c AddSection event is emitted whenever the contextual menu entry
   * New Section is clicked.
   *
   * @par EventProperties
   *   @li Name: @c "AddSection"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * AddSection();
  /**
   * Returns the @c AddGroup event.
   *
   * @par Emission
   * The @c AddGroup event is emitted whenever the contextual menu entry
   * New Group is clicked.
   *
   * @par EventProperties
   *   @li Name: @c "AddGroup"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidMdlStructureChangedEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * AddGroup();
  /**
   * Returns the @c DuplicateCommand event.
   *
   * @par Emission
   * The @c DuplicateCommand event is emitted whenever the contextual menu entry
   * Duplicate command is clicked on a button.
   *
   * @par EventProperties
   *   @li Name: @c "DuplicateCommand"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidMdlStructureChangedEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * DuplicateCommand();
  /**
   * Returns the @c DuplicateFlyOut event.
   *
   * @par Emission
   * The @c DuplicateFlyOut event is emitted whenever the contextual menu entry
   * Duplicate is clicked on a flyOut.
   *
   * @par EventProperties
   *   @li Name: @c "DuplicateFlyOut"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidMdlStructureChangedEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * DuplicateFlyOut();
  /**
   * Returns the @c ToggleExtraction event.
   *
   * @par Emission
   * The @c ToggleExtraction event is emitted whenever the contextual menu entry
   * Extract from current widget or insert in page is clicked.
   *
   * @par EventProperties
   *   @li Name: @c "ToggleExtraction"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * ToggleExtraction();
  /**
   * Returns the @c RenameSection event.
   *
   * @par Emission
   * The @c RenameSection event is emitted whenever the contextual menu entry
   * Rename Section is clicked.
   *
   * @par EventProperties
   *   @li Name: @c "RenameSection"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidMdlStructureChangedEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * RenameSection();
  /**
   * Returns the @c IsUserCreatedSection event.
   *
   * @par Emission
   * The @c IsUserCreatedSection event is emitted whenever the contextual menu
   * entry Delete Section is clicked to query the model whether the clicked
   * section is a new user created section or a default or custimzed section
   * from a default one.
   *
   * @par EventProperties
   *   @li Name: @c "IsUserCreatedSection"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidMdlStructureChangedEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * IsUserCreatedSection();
  /**
   * Returns the @c DeleteSection event.
   *
   * @par Emission
   * The @c DeleteSection event is emitted whenever the contextual menu entry
   * Delete Section is clicked.
   *
   * @par EventProperties
   *   @li Name: @c "DeleteSection"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidMdlStructureChangedEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * DeleteSection();
  /**
   * Returns the @c ActionBarVisibilityChanged event.
   *
   * @par Emission
   * The @c ActionBarVisibilityChanged event is emitted whenever the visibility state
   * has changed to display or hide the ActionBar.
   *
   * @par EventProperties
   *   @li Name: @c "ActionBarVisibilityChanged"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * ActionBarVisibilityChanged();

  /**
   * Returns the @c OpenCustomize event.
   *
   * @par Emission
   * The @c OpenCustomize event is emitted whenever the contextual menu entry
   * Open Customize is clicked.
   *
   * @par EventProperties
   *   @li Name: @c "OpenCustomize"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * OpenCustomize();

  /**
   * Returns the @c ResetSection event.
   *
   * @par Emission
   * The @c ResetSection event is emitted whenever the contextual menu entry
   * Reset section is clicked.
   *
   * @par EventProperties
   *   @li Name: @c "ResetSection"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidMdlStructureChangedEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * ResetSection();

  /**
   * Returns the @c RemoveGroup event.
   *
   * @par Emission
   * The @c RemoveGroup event is emitted whenever the contextual menu entry
   * Remove group is clicked.
   *
   * @par EventProperties
   *   @li Name: @c "RemoveGroup"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidMdlStructureChangedEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * RemoveGroup();

  /**
   * Returns the @c RemoveSecondaryArea event.
   *
   * @par Emission
   * The @c RemoveSecondaryArea event is emitted whenever the contextual menu entry
   * Remove secondaries is clicked.
   *
   * @par EventProperties
   *   @li Name: @c "RemoveSecondaryArea"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidMdlStructureChangedEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * RemoveSecondaryArea();

  /**
   * Returns the @c IsCustomizedSection event.
   *
   * @par Emission
   * The @c IsCustomizedSection event is emitted whenever the contextual menu
   * is built in order to check if the related section is a customized one or not.
   *
   * @par EventProperties
   *   @li Name: @c "IsCustomizedSection"
   *   @li Type of propagation: @c NoPropagation
   *   @li Type of argument: @ref CATVidMdlStructureChangedEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the returned
   * pointer.
   */
  static CATSYPEvent * IsCustomizedSection();

  /**
   * Activate the button corresponding to the given index.
   *
   * @note This member function is used when a command header is started by
   * code to update the visual of the associated button.
   *
   * @param i_index the index corresponding to the button to activate.
   */
  void ActivateButton(const CATVidMdlIndex & i_index);
  /**
   * Deactivate the button corresponding to the given index.
   *
   * @note This member function is used when a command header is stopped by
   * code to update the visual of the associated button.
   *
   * @param i_index the index corresponding to the button to deactivate.
   */
  void DeactivateButton(const CATVidMdlIndex & i_index);

  /**
   * Activate or deactivate the customization mode.
   *
   * @param i_custoActivation the value to apply to the customization state.
   * true to activate the customization mode, false otherwise.
   */
  void SetCustomization(bool i_custoActivation);

  /**
   * Set the value of the flag that indicates whether the ActionBar is
   * extracted or not from the current widget.
   *
   * @param i_extractedFlag value to set to the extracted flag. 1 means the
   * ActionBar is extracted from the current widget, 0 means it is inserted
   * in the current widget.
   */
  void SetExtractedFlag(int i_extractedFlag);
  /**
   * Get the value of the flag that indicates whether the ActionBar is
   * extracted or not from the current widget.
   *
   * @return the value of the flag that indicates whether the ActionBar is
   * extracted or not from the current widget.
   */
  int GetExtractedFlag();

  /**
   * Set the value of the flag that indicates whether the current window (i.e.
   * the window associated to the ActionBar) is maximized or not.
   *
   * @param i_maximizedWindowFlag value to set to the maximized flag. 1 means
   * the window is maximized, 0 means it is not maximized.
   */
  void SetMaximizedWindowFlag(int i_maximizedWindowFlag);
  /**
   * Get the value of the flag that indicates whether the current window (i.e.
   * the window associated to the ActionBar) is maximized or not.
   *
   * @return the value of the flag that indicates whether the window containing
   * the ActionBar is maximized or not.
   */
  int GetMaximizedWindowFlag();

  /**
   * Set the value of the flag that indicates whether the current window (i.e.
   * the window associated to the ActionBar) is extracted or not from the main
   * application window.
   *
   * @param i_extractedWindowFlag value to set to the extracted window flag.
   * 1 means the window is extracted from the main application window, 0
   * means it is not extracted from the main application window.
   */
  void SetExtractedWindowFlag(int i_extractedWindowFlag);
  /**
   * Get the value of the flag that indicates whether the current window (i.e.
   * the window associated to the ActionBar) is extracted or not from the main
   * application window.
   *
   * @return the value of the flag that indicates whether the current window
   * (i.e. the window associated to the ActionBar) is extracted or not from the
   * main application window.
   */
  int GetExtractedWindowFlag();

  /**
   * Associate to the ActionBar view a parent to host it.
   * 
   * The parent determines whether the ActionBar view is displayed as floating
   * panels or as a tab component outside of the current widget.
   *
   * @param i_pViewParent the parent container in which the ActionBar should be
   * displayed.
   */
  void SetViewParent(CATBaseUnknown * i_pViewParent);
  /**
   * Get the parent container that hosts the ActionBar view.
   *
   * @return the parent container that hosts the ActionBar view.
   */
  CATBaseUnknown * GetViewParent();

  /** SYP event support*/
  int AddHandler(CATSYPEvent * i_pEvent, CATSYPEventHandler * i_pHandler, int i_handleConsumedEvents = 0);
  /** SYP event support*/
  int RemoveHandler(CATSYPEvent * i_pEvent, CATSYPEventHandler * i_pHandler);
  /** SYP event support*/
  static int AddClassHandler(CATMetaClass *i_pClass, CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler, int i_handleConsumedEvents);
  /** SYP event support*/
  static int RemoveClassHandler(CATMetaClass *i_pClass, CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler);
  /** SYP event support*/
  int Dispatch(CATSYPEventArgs * i_pArgs);

  /**
   * Set the value of the flag that indicates whether a section is being
   * currently created from the Customize panel or not.
   *
   * @param i_value TRUE when a section is being currently added from the
   * Customize Panel, FALSE otherwise.
   */
  void SetCustomizationFromCustomizePanel(CATBoolean i_value);

  /**
   * Set a flag to indicate that the ActionBar should be displayed or not.
   *
   * @see _visibleCounter for more information about this mechanism.
   *
   * @param i_value TRUE when the should be displayed, FALSE otherwise.
   */
  void SetABVisibleFlag(CATBoolean i_value);

  /**
   * Get the value of the flag indicating whether the ActionBar is displayed or
   * not.
   *
   * @see _visibleCounter for more information about this mechanism.
   *
   * @return TRUE when ActionBar is displayed, FALSE otherwise.
   */
  CATBoolean GetABVisibleFlag() const;

  /**
   * Get the viewer in which the ActionBar is currently displayed.
   *
   * @return the viewer in which the ActionBar is currently displayed.
   */
  CATVizViewer * GetViewer();

  /** Show an Action Bar section based on an id and save its new state.
    * <p>
    * The new Action Bar section's visibility will be stored in a CATSettings
    * file called AfrActionBarSectionVisibility.
    * </p>
    *
    * @param i_sectionId A CATString identifying the section.
    *                    This id contains the name of the access container.
    *                    For exemple, the Geolocation section in CATIA Product Structure Design 
    *                    is identified by: PRDWorkshop_PrsConfiguration_GeolocationAddinSection
    */
  void ShowSection(const char * i_sectionId);

  /** Hide an Action Bar section based on an id and save its new state.
    * <p>
    * The new Action Bar section's visibility will be stored in a CATSettings
    * file called AfrActionBarSectionVisibility.
    * </p>
    *
    * @param i_sectionId A CATString identifying the section.
    *                    This id contains the name of the access container.
    *                    For exemple, the Geolocation section in CATIA Product Structure Design
    *                    is identified by: PRDWorkshop_PrsConfiguration_GeolocationAddinSection
    */
  void HideSection(const char * i_sectionId);

  /** Get the section's visibility stored in the AfrActionBarSectionVisibility.CATSettings file.
    *
    * @param i_sectionId A CATString identifying the section.
    *                    This id contains the name of the access container.
    *                    For exemple, the Geolocation section in CATIA Product Structure Design
    *                    is identified by: PRDWorkshop_PrsConfiguration_GeolocationAddinSection
    * @param io_visibility The visibility value stored.
    * @return S_OK if a value has been retrieved, 
    *         E_NOT_SET if the file was found but not the key, 
    *         E_UNEXPECTED in the case where CATSysPreferenceRepository::GetPreferenceRepository returns nullptr or if i_sectionId is nullptr.
    */
  HRESULT GetSectionVisibilityFromPreferences(const char * i_sectionId, int & io_visibility) const;

  /**
   * Set the value of the flag SynchroFullScreenMode to the given value.
   *
   * @param i_value the value to set to the flag
   */
  void SetSynchroFullScreenMode(CATBoolean i_value);
  /**
   * Get the value of the flag SynchroFullScreenMode.
   *
   * @return the value of the flag SynchroFullScreenMode.
   */
  CATBoolean GetSynchroFullScreenMode() const;

private:
  /**Copy constructor. not implemented*/
  CATVidActionBar(const CATVidActionBar& iToCopy);
  /**Equal operator. not implemented*/
  CATVidActionBar& operator=(const CATVidActionBar& i_original);
  
  
  /** called whenever a button is clicked. */
  void OnActionButtonClick(CATBaseUnknown* i_pSender, CATSYPEventArgs* i_pArgs);
  /** called whenever a button is doubleclicked. */
  void OnActionButtonDoubleClick(CATBaseUnknown* i_pSender, CATSYPEventArgs* i_pArgs);
  /** called whenever a combo item is clicked. */
  void OnActionComboClick(CATBaseUnknown* i_pSender, CATSYPEventArgs* i_pArgs);
  /** called whenever a combo item is double clicked. */
  void OnActionComboDoubleClick(CATBaseUnknown* i_pSender, CATSYPEventArgs* i_pArgs);
  /**
   * @returns the section model index from a window pointer.
   */
  CATVidMdlIndex GetSectionMdlIndexFromPanel(CATVidFraWindow* i_pPanel) const;
  CATVidMdlIndex GetSectionMdlIndexFromPanel(const CATString & i_sectionId)const;
  CATVidCtlActionBarV3Section * GetSectionFromMdlIndex(const CATVidMdlIndex & i_mdlIndex) const;
  CATVidCtlActionBarV3Section * GetSectionFromWidget(CATVidWidget * i_pCtl) const;
  /**
   * @returns the toolbar model index from a name.
   */
  CATVidMdlIndex GetToolbarMdlIndexFromWidget(const CATVidMdlIndex& i_sectionMdlIndex, const CATUnicodeString& i_commandName) const;

  /**
   * @returns the L2 (button or combo) model index from a name.
   */
  CATVidMdlIndex GetL2MdlIndexFromWidget(const CATVidMdlIndex& i_toolbarMdlIndex, const CATUnicodeString& i_L2Name) const;
  CATVidWidget* GetWidgetFromL2MdlIndex(const CATVidMdlIndex& i_mdlIndex) const;

  CATVidMdlIndex GetMdlIndexFromL2Widget(CATVidWidget* i_pL2Widget) const;

  void OnMdlPreRowsRemoved(CATBaseUnknown* i_pSender, CATVidMdlStructureChangedEventArgs* i_pArgs);
  void OnMdlRowsInserted(CATBaseUnknown* i_pSender, CATVidMdlStructureChangedEventArgs* i_pArgs);
  void OnItemDataModified(CATBaseUnknown* i_pSender, CATVidMdlEventItemDataModifiedArgs* i_pArgs);
  void OnExtractActionBar(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
  void OnDisplayButtonsLabelFlag(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
  void OnPinSection(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
  void OnToggleCustomization(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
  void OnDragItem(CATBaseUnknown * i_pSender, CATVidDraggedEventArgs * i_pArgs);
  void OnCanImportDataEvent(CATBaseUnknown * i_pSender, CATVidDnDDataEventArgs * i_pArgs);
  void OnImportDataEvent(CATBaseUnknown * i_pSender, CATVidDnDDataEventArgs * i_pArgs);
  void OnMouseLeaveEvent(CATBaseUnknown * i_pSender, CATVidDnDEventArgs * i_pArgs);

  /**
   * Utility function to dispatch an event (mainly used by customization).
   *
   * @param i_pEvent event to dispatch (can't be NULL).
   */
  void DispatchCustomizationEvent(CATSYPEvent * i_pEvent);

  /**
   * Callback called when the contextual menu option "Reset Action Bar" is
   * clicked.
   *
   * This callback displays a panel allowing the user to choose what is the
   * part to reset among
   *    - resetting the position of sections
   *    - resetting the customized content of the sections
   *    - resetting both position and customized content of the sections.
   *
   * @param i_pSender the control that sends the event
   * @param i_pArgs argument associated to the event
   */
  void OnResetActionBar(CATBaseUnknown* i_pSender, CATSYPEventArgs* i_pArgs);

  /**
   * Callback called when the contextual menu option "Reset section positions" is
   * clicked.
   *
   * It displays a panel asking the user for a confirmation.
   * If the user validates the action in the message box, the OnResetSectionPositionsOk callback 
   * is called.
   * 
   *
   * @param i_pSender the control that sends the event
   * @param i_pArgs argument associated to the event
   */
  void OnResetSectionPositions(CATBaseUnknown* i_pSender, CATSYPEventArgs* i_pArgs);

  /**
   * Callback called when the user clicks "ok" in the message box shown by 
   * the OnResetPositions callback.
   *
   * It sends an event to communicate with the Action Bar controller
   * in order to make the required model modification.
   *
   * This callback reset the position of every Action Bar's section.
   *
   * @param i_pSender the control that sends the event
   * @param i_pArgs argument associated to the event
   */
  void OnResetSectionPositionsOk(CATBaseUnknown* i_pSender, CATVidFraDialogButtonClickedEventArgs* i_pArgs);

  /**
   * Callback called when the contextual menu option "Reset all customization" is
   * clicked.
   *
   * This callback displays a panel asking the user for a confirmation.
   * If the user validates the action in the message box, the OnResetAllCustomizationOk callback 
   * is called.
   *
   * @param i_pSender the control that sends the event
   * @param i_pArgs argument associated to the event
   */
  void OnResetAllCustomization(CATBaseUnknown* i_pSender, CATSYPEventArgs* i_pArgs);

  /**
   * Callback called when the user clicks "ok" in the message box shown by 
   * the OnResetAllCustomization callback.
   *
   * It sends an event to communicate with the Action Bar controller
   * in order to make the required model modification.
   *
   * This callback will reset:
   * - both position and customized content of the sections.
   * - the visibility of Commands labels
   * 
   * @param i_pSender the control that sends the event
   * @param i_pArgs argument associated to the event
   */
  void OnResetAllCustomizationOk(CATBaseUnknown* i_pSender, CATVidFraDialogButtonClickedEventArgs* i_pArgs);

  /**
   * Callback called when the contextual menu option "Add commands..." is
   * clicked.
   *
   * This callback displays the Tools>Customize panel with the "Commands" tab
   * as the active tab.
   *
   * @param i_pSender the control that sends the event
   * @param i_pArgs argument associated to the event
   */
  void OnAddCommands(CATBaseUnknown* i_pSender, CATSYPEventArgs* i_pArgs);

  /**
   * Callback called when the contextual menu option "Reset section" is
   * clicked.
   *
   * This callback displays a panel asking the user for a confirmation.
   * If the user validates the action in the message box, the OnResetSectionOk callback 
   * is called.
   *
   * @param i_pSender the control that sends the event
   * @param i_pArgs argument associated to the event
   */
  void OnResetSection(CATBaseUnknown* i_pSender, CATSYPEventArgs* i_pArgs);

  /**
   * Callback called when the user clicks "ok" in the message box shown by 
   * the OnResetSection callback.
   *
   * It send an event to communicate with the Action Bar controller
   * in order to make the required model modification.
   *
   * @param i_pSender the control that sends the event
   * @param i_pArgs argument associated to the event
   */
  void OnResetSectionOk(CATBaseUnknown* i_pSender, CATVidFraDialogButtonClickedEventArgs* i_pArgs);

  /**
   * Callback called when the contextual menu option "Remove group" is
   * clicked.
   *
   * This callback displays a panel asking the user for a confirmation.
   * If the user validates the action in the message box, the OnRemoveGroupOk callback 
   * is called.
   * This callback will reset the customization for the given section.
   *
   * @param i_pSender the control that sends the event
   * @param i_pArgs argument associated to the event
   */
  void OnRemoveGroup(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);

  /**
   * Callback called when the user clicks "ok" in the message box shown by 
   * the OnRemoveGroup callback.
   *
   * This callback send an event to communicate with the Action Bar controller
   * in order to make the required model modification.
   *
   * @param i_pSender the control that sends the event
   * @param i_pArgs argument associated to the event
   */
  void OnRemoveGroupOk(CATBaseUnknown* i_pSender, CATVidFraDialogButtonClickedEventArgs* i_pArgs);


  /**
  * Callback called when the contextual menu option "Remove secondary" is
  * clicked.
  *
  * This callback displays a panel asking the user for a confirmation.
  * If the user validates the action in the message box, the OnRemoveSecondaryAreaOk callback
  * is called.
  * This callback removed secondary CATCmdAccess from the given group.
  *
  * @param i_pSender the control that sends the event
  * @param i_pArgs argument associated to the event
  */
  void OnRemoveSecondaryArea(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);

  /**
  * Callback called when the user clicks "ok" in the message box shown by
  * the OnRemoveSecondaryArea callback.
  *
  * This callback send an event to communicate with the Action Bar controller
  * in order to make the required model modification.
  *
  * @param i_pSender the control that sends the event
  * @param i_pArgs argument associated to the event
  */
  void OnRemoveSecondaryAreaOk(CATBaseUnknown* i_pSender, CATVidFraDialogButtonClickedEventArgs* i_pArgs);

  /**
   * Callback called when the user clicked on OK or cancel button of the "Reset
   * Action Bar" panel.
   *
   * Execute the selected reset action from the panel when the user clicked the
   * "ok" button.
   * Do nothing when the user clicked the cancel button.
   *
   * @param i_pSender the control that sends the event
   * @param i_pArgs argument associated to the event
   */
  void OnResetActionBarOkCancel(CATBaseUnknown * i_pSender, CATVidFraDialogButtonClickedEventArgs  * i_pArgs);
  /**
   * Reset the customization of the ActionBar made by the user.
   *
   * This member function only resets the customization of commands. It doesn't
   * reset the position of sections.
   */
  void ResetActionBarCustomization();
  /**
   * Reset the position of sections.
   *
   * This member function only resets the position of sections to their initial
   * position. It doesn't reset the user customization.
   */
  void ResetSectionsToDefaultPosition();
  void OnAddGroup(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
  void OnAddSecondaryArea(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
  void OnAddSection(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
  void OnRenameSection(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
  void OnRenameSectionOk(CATBaseUnknown * i_pSender, CATVidFraDialogButtonClickedEventArgs  * i_pArgs);
  void OnRenameSectionCancel(CATBaseUnknown * i_pSender, CATVidFraDialogButtonClickedEventArgs  * i_pArgs);
  void OnRenameSectionClose(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
  void OnDuplicateButton(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
  void OnDuplicateFlyOut(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
  void OnRemoveButton(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
  void OnRemoveFlyOut(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
  void OnDeleteSection(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
  void OnDeleteSectionOkCancel(CATBaseUnknown * i_pSender, CATVidFraDialogButtonClickedEventArgs * i_pArgs);

  /** A callback called when hiding a section is requested.
    * <p>
    * The default use case of this callback is to be called when an
    * end-user hide a section from the contextual menu.
    * </p>
    *
    * @param i_pSender A CATVidActionBarV3Action (CAT_DYNAMIC_CAST used internaly)
    *                  The GetOwnerSectionId will be called on it in order to retrieve
    *                  the section id.
    * @param i_pArgs   Nothing is expected here.
    */
  void OnRequestHideSection(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);

  /** A callback called when showing a section is requested.
    * <p>
    * The default use case of this callback is to be called when an
    * end-user show a section from the contextual menu.
    * </p>
    *
    * @param i_pSender A CATVidActionBarV3Action (CAT_DYNAMIC_CAST used internaly)
    *                  The GetOwnerSectionId will be called on it in order to retrieve
    *                  the section id.
    * @param i_pArgs   Nothing is expected here.
    */
  void OnRequestShowSection(CATBaseUnknown * i_pSender, CATSYPEventArgs * i_pArgs);
  
  /** SYP event support*/
  static CATSYPEventFactory *GetEventFactory();

  CATVidWidget* GetWidgetFromMdlIndex(const CATVidMdlIndex& mdlIndex, CATVidWidget*& o_pAssociatedSeparator);

  void UpdateActionBarVisibility(int i_VisibleFlag);

  void SetupCustomization(CATVidCtlActionBarV3Section * i_pSection, CATBoolean i_OnlyDragBehavior);
  void SetCustomizationMode();
  void UnsetCustomizationMode();

  bool IsPlayerSection(CATVidFraWindow * i_pWindow);
  
  /**
   * Callback to handle the display of a contextual menu when the user clicks
   * on the content of a section.
   *
   * @param i_pSender control that needs to display a contextual menu
   * @param i_pArgs argument associated to the display of the contextual menu
   */
  void OnContextMenuRequiredEvent(CATBaseUnknown * i_pSender, CATVidMouseAndKeyboardEventArgs * i_pArgs);

  /**
   * Initialize the ActionBar component when all needed data are set.
   *
   * This member function is also responsible to change the view of the
   * ActionBar between inserted in the current widget or extracted from the
   * current widget.
   *
   * @param i_pNewViewer pointer on a new viewer in which the ActionBar should
   * be displayed (NULL if no change in current viewer occurred)
   * @param i_parentHasChanged boolean to indicate if the previous parent stored
   * in _pABViewHostCtlWR has been remplaced by another one. In that case, force
   * the display of the view in this new one (useful for Dialog based apps when
   * the user decides to display the ActionBar outside of the widget).
   */
  void Init(CATVizViewer * i_pNewViewer, bool i_parentHasChanged = false);

  /**
   * Create and setup handlers to listen to model modifications and model items
   * modifications.
   */
  void AddModelHandlers();
  /**
   * Remove and destroy handlers that listen to model modifications and model
   * items modifications.
   */
  void RemoveModelHandlers();

private:

  void DeletePlayerSection();

  // Model to display through ActionBar view
  CATVidMdlStandardTree* _pModel;
  // Handler to listen to model items modification
  CATSYPEventHandler * _pItemDataModifiedHandler;
  // Handlers to listen to model modification
  CATSYPEventHandler * _pPreRowsRemovedHandler;
  CATSYPEventHandler * _pRowsInsertedHandler;

  CATSYPArray<CATVidFraWindow*> _pPanelsList;
  CATSYPEventHandlersSupport * _pEventHandlersSupport;
  static CATSYPClassEventHandlersSupport * _pClassEventHandlersSupport;

  int _displayButtonsLabelFlag;
  bool _customizationFlag;
  int _extractedFlag;
  int _maximizedWindowFlag;
  int _extractedWindowFlag;

  CATSysPreferenceRepository* _pABPreferences;

  CATSYPDataBlockFactory _tooltipDataFactory;

  // Parent control to host the ActionBar
  // When this data member is set, that means the ActionBar is extracted from
  // the current widget.
  // When this data member is set to NULL, that means the ActionBar is
  // displayed inserted in the current widget.
  CATSysWeakRef * _pABViewHostCtlWR;
  
  class SectionHandlerData
  {
  public:
    SectionHandlerData(CATVidCtl * i_pSectionCtl, CATVidActionBar * i_pActionBar);
    ~SectionHandlerData();

  private:
    SectionHandlerData(const SectionHandlerData &);
    SectionHandlerData & operator=(const SectionHandlerData &);
    CATSysWeakRef * _pSectionCtlWR;
    CATSYPEventHandler * _pCanImportDataHandler;
    CATSYPEventHandler * _pImportDataHandler;
    CATSYPEventHandler * _pEndPreDropHandler;
  };
  CATSYPDynArray<SectionHandlerData *> _sectionCustoHandlerDataList;

  class ButtonHandlerData
  {
  public:
    ButtonHandlerData(CATVidCtl * i_pButton, CATVidActionBar * i_pActionBar);
    ~ButtonHandlerData();

  private:
    ButtonHandlerData(const ButtonHandlerData &);
    ButtonHandlerData & operator=(const ButtonHandlerData &);

    CATSysWeakRef * _pButtonCtlWR;
    CATSYPEventHandler * _pDraggedHandler;
  };
  CATSYPDynArray<ButtonHandlerData *> _buttonCustoHandlerDataList;

  CATVidActionBarContentFactory * _pABContentFactory;
  CATVidActionBarContainer * _pABContainer;
  CATVidActionBarSectionCache * _pABSectionCache;

  // Counter to save how many times the ActionBar has been hidden or displayed.
  //
  // At start, this variable is set to 0. It means the ActionBar is displayed
  // and nobody has asked to hide or show it.
  //
  // When someone asks to hide the ActionBar, this counter is incremented. When
  // it is equal to 1, then the ActionBar is hidden. If its value is greater
  // than one, nothing is done.
  // When someone asks to show the ActionBar, this counter is decremented. When
  // it is equal to 0, then the ActionBar is displayed. If its value would
  // become lower than 0, nothing the counter is not decremented (that means
  // some people asks the ActionBar to be displayed without hidding it first).
  unsigned int _visibleCounter;
  // Flag set to TRUE when the full screen synchro mode is set
  CATBoolean _synchroFullScreenModeFlag;

  friend class CATVidActionBarEventPathBuilder;
  friend class CATVidActionBar_ClassHandlersSupportLifecycle;
  friend class CATVidTstActionBarTestActionBarUpdateFromModel;
  friend class CATVidActionBarContentFactory;
  friend class CATVidABV3ActionBarTester;
  friend class AfrActionBarV3Controller; // for access to ResetSectionsToDefaultPosition

};

#endif
