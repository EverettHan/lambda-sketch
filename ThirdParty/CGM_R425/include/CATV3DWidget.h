//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2012/05/15
//===================================================================
//  2012/05/15 Creation: Code generated by jov
//===================================================================
#ifndef CATV3DWidget_H
#define CATV3DWidget_H
#include <VisuImmersive3D.h>
#include <CATBaseUnknown.h>
#include <CATMathInline.h>
#include <CATSYPDeclareEnumFactory.h>

class l_CATV3DWidget;
class CATV3DWidget;
class CATSYPEventHandler;
class CATSYPEvent;
class CATSYPEventArgs;
class CATSYPEventFactory;

typedef l_CATV3DWidget* (* CreateV3DLetterFunc)(CATV3DWidget&);

/**
 * Base class for the V3D widgets.
 *
 * @par Role
 * This class is the parent class of all V3D controls and graphic primitives.
 * It gathers the visible and enable state information as well as some layouting
 * properties.
 *
 * Doc TODO : comment visualiser un widget, comment hierarchiser des widgets
 *
 * @ingroup V3DCore
 */
class ExportedByVisuImmersive3D CATV3DWidget: public CATBaseUnknown
{
  CATDeclareClass;
public:
  enum ManipulationState {DefaultManipulation=0, DisableManipulation, GhostManipulation, InvisibleManipulation};
  /** Destructor*/
  virtual ~CATV3DWidget ();
  /** @return the private letter */
  INLINE l_CATV3DWidget& GetV3DLetter() const{return *_pV3DLetter;};
  /**
   * Sets the name of the widget.
   * @param i_name Name of the widget
   */
  virtual void SetName(const CATString& i_name);
  /**
   * Gets the name of the widget.
   */
  virtual const CATString& GetName() const;
  /**
   * Sets the visibility flag of a widget. An unvisible widget will participate
   * to the layout depending on the LayoutWhenUnvisibleFlag property. 
   * A widget can have its visible flag to TRUE but not being visible on screen,
   * if one of its parent is not visible. To have the information about visibility
   * state of a widget, call GetVisibleState.
   * @param i_visibleFlag TRUE if the widget should be visible when all its parents hierarchy is visible, otherwise FALSE.
   * @see SetLayoutWhenUnvisibleFlag()
   * @see GetVisibleFlag().
   * @see GetVisibleState().
   */
  void SetVisibleFlag(CATBoolean i_visibleFlag);
  /**
   * @return the visibility flag of a widget.
   */
  int GetVisibleFlag() const;
  /**
   * @return the visible state of a widget, that is, TRUE if all its parents and 
   * himself are visible
   */
  CATBoolean GetVisibleState() const;

  void SetPickFlag(CATBoolean i_pickFlag);
  /**
   * Sets the pick flag of a widget, that is, TRUE if the picking is allowed, FALSE otherwise
   */
  int GetPickFlag() const;
  /**
   * @return the pick flag of a widget, that is, TRUE if the picking is allowed, FALSE otherwise
   */

  /**
   * Allows to layout the  widget when unvisible. If this flag is 
   * TRUE (default), the father container will take into account the dimensions
   * of the widget in its bounding sphere computation. Otherwise, it will considered as
   * not present in the layout.
   * @param i_layoutWhenUnvisibleFlag is a boolean. Default value is TRUE.
   */
  void SetLayoutWhenUnvisibleFlag(CATBoolean i_layoutWhenUnvisibleFlag);
  /**
   * @return a flag indicating if the widget must be layouted when invisible.
   */
  CATBoolean GetLayoutWhenUnvisibleFlag() const;
  /**
   * Sets the flag modifying the enable state of the widget.
   * A widget can have its enable flag to TRUE but not being enabled on screen,
   * if one of its parent is not enabled. To have the information about enability (?)
   * state of a widget, call GetEnableState.
   * @param i_enableFlag the enable flag to set on the widget.
   */
  void SetEnableFlag(CATBoolean i_enableFlag);
  /**
   * @return the enable flag of a widget.
   */
  CATBoolean GetEnableFlag() const;
  /**
   * @return the enable state of a widget that is, TRUE if all its parents and 
   * himself are enabled
   */
  CATBoolean GetEnableState() const;
  
  /**
   * @deprecated, use SetGhostFlag instead
   * Sets the ghost state of the V3DCtl
   * @param iGhostState
   * The ghost state of the V3DCtl to set.
   *   <br>
   *   <b>Legal values</b> : It can be set to either :
   *   <dl>
   *   <dt><tt>FALSE</tt><dd> to put the V3DCtl in default state,
   *   <dt><tt>TRUE</tt><dd> to put the V3DCtl in ghost state
   *   </dl>
   */
  void SetGhostState(const CATBoolean& iGhostState);
  /**  
   * Sets the ghost flag of the V3DWidget.
   * This flag is used by the CATV3DCtlRobot when it is drag and droped
   * on a 3D face to highlight the normal of the face.
   * It prevails over the enable flag
   * @param iGhostFlag the ghost flag of the V3DWidget.
   */
  void SetGhostFlag(const CATBoolean& iGhostFlag);
  /**
   * @return the ghost flag of the V3DWidget
   */
  int GetGhostFlag() const;
  /**
   * @return the ghost state of the V3DWidget
   *   <br>
   * The ghost state of the V3DWidget can be:
   *   <dl>
   *   <dt><tt>FALSE</tt><dd> V3DWidget is no ghost,
   *   <dt><tt>TRUE</tt><dd> V3DWidget is ghosted.
   *   </dl>
   */
  CATBoolean GetGhostState() const;

  /**
   * Sets the visibleFlag With Policy state of the V3DWidget.
   * React as the widget visible flag but can be used to add some 
   * specific policy and animations.
   * @param iFlag
   * The visibleFlag With Policy state of the V3DWidget to set.
   *   <br>
   *   <b>Legal values</b> : It can be set to either :
   *   <dl>
   *   <dt><tt>FALSE</tt><dd> to put the V3DWidget not visible,
   *   <dt><tt>TRUE</tt><dd> to put the V3DWidget visible
   *   </dl>
   */
  void SetVisibleFlagWithAnimation(const CATBoolean& iFlag);
  /**
   * @return the visibleFlag With Policy state of the V3DWidget
   *   <br>
   * The state of the V3DWidget can be:
   *   <dl>
   *   <dt><tt>FALSE</tt><dd> V3DWidget is not visible,
   *   <dt><tt>TRUE</tt><dd> V3DWidget is visible.
   *   </dl>
   */
  int GetVisibleFlagWithAnimation() const;

  /**
   * The property ManipulationState is used for adapting the style to the allowed manipulations.
   * It d�pends on the values of "VisibleFlagWithAnimation", "EnableFlag" and "GhostFlag" :
   *   - CATVidCtlButton::InvisibleManipulation if VisibleFlagWithAnimation:0
   *   - CATVidCtlButton::GhostManipulation     else if GhostFlag:1
   *   - CATVidCtlButton::DisableManipulation   else if EnableFlag:0
   *   - CATV3DWidget::DefaultManipulation      otherwise
   */
  CATV3DWidget::ManipulationState GetManipulationState() const;

  /** 
   * Sets the picking priority of this v3dwidget. The value must be an int between
   * 0 and 15, 0 being the lowest priority and 15 the highest priority.
   *
   * the priority of a widget is calculated by adding all the priority values of
   * its widget hierarchy.
   */
  void SetPriority(const unsigned int& i_Priority);
  /**
   * @return the picking priority value.
   */
  const unsigned int GetPriority() const;

  void SetAutoHideFlag(const CATBoolean& iFlag);
  CATBoolean GetAutoHideFlag() const;

  /**
   * @copydoc CATVidWidget#AddHandler
   */
  int AddHandler(CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler, int i_handleConsumedEvents = 0);
  /**
   * @copydoc CATVidWidget#RemoveHandler
   */
  int RemoveHandler(CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler);
  /**
   * @copydoc CATVidWidget#AddClassHandler
   */
  static int AddClassHandler(CATMetaClass *i_pClass, CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler, int i_handleConsumedEvents = 0);
  /**
   * @copydoc CATVidWidget#RemoveClassHandler
   */
  static int RemoveClassHandler(CATMetaClass *i_pClass, CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler);
  /** 
   * @copydoc CATVidWidget#Dispatch
   */
  int Dispatch(CATSYPEventArgs *i_pArgs);
  /**
   * @copydoc CATVidWidget#GetEventFactory
   */
  static CATSYPEventFactory *GetEventFactory();
  /**
   * @return the density factor of the display of the widget.
   */
  float GetDensity() const;
protected:
  /** Constructor*/
  CATV3DWidget (CreateV3DLetterFunc i_pCreateLetterFunc);
private:
  /** Constructor*/
  CATV3DWidget ();
  CATV3DWidget (CATV3DWidget &);
  CATV3DWidget& operator=(CATV3DWidget&);

  l_CATV3DWidget* _pV3DLetter;
};

CATSYP_DECLARE_ENUMFACTORY(ExportedByVisuImmersive3D, CATV3DWidget__ManipulationState);

#endif