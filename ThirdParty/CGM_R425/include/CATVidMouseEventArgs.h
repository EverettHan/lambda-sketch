#ifndef CATVidMouseEventArgs_H
#define CATVidMouseEventArgs_H

#include <VisuDialog.h>

#include <CATVidInputEventArgs.h>
#include <CATBaseUnknown_WR.h>
#include <CATMathPoint2Df.h>
#include <CATUnicodeString.h>

class CATVizViewer;
class CATVidWidget;
struct CATVidMouseEventData;

/** @ingroup VIDGP
 * Dispatching arguments for mouse events of @ref CATVidGP.
 *
 * @see CATVidGP::Entry CATVidGP::Leave CATVidGP::Press CATVidGP::Drag
 * CATVidGP::ReleaseEvt CATVidGP::DoubleClick CATVidGP::MoveOver
 * CATVidGP::RightClick 
 */
class ExportedByVisuDialog CATVidMouseEventArgs : public CATVidInputEventArgs
{
  CATDeclareClass;
public:
  /** 
   * A bitfield representing the pressed keyboard modifiers.
   *
   * Its value must be on or-combination of masks @ref #SHIFT_MASK,
   * @ref #CTRL_MASK and @ref #ALT_MASK.
   *
   * @see #Modifiers2String
   */
  typedef int Modifiers;
  /** the `Shift' key bitfield mask constant. To be used with @ref
      #Modifiers type. */
  static const int SHIFT_MASK;
  /** the `Control' key bitfield mask constant. To be used with @ref
      #Modifiers type. */
  static const int CTRL_MASK;
  /** the `Alt' key bitfield mask constant. To be used with @ref
      #Modifiers type. */
  static const int ALT_MASK;
  /** the combination of all possible masks. Useful to test for
      bitfield validity. To be used with @ref #Modifiers type. */
  static const int ALL_MASKS;
  /**
   * Build a string representation of a modifier bitfield.
   *
   * The returned string is built as a list of tokens separated by a
   * @c '|' character. If the bitfield contains invalid bits, then the
   * token @c "<Invalid>" is appended to the list.
   *
   * This string representation is meant to be used for debugging
   * purpose only. No production code should rely on this
   * representation as it may change without warning.
   *
   * @return the string representation.
   */
  static CATUnicodeString Modifiers2String(Modifiers i_modifiers);
  /**
   * Defines the mouse button identifier
   */
  enum MouseButton{
    /** Default */
    Unknown = 0,
    /** Left mouse button. */
    LeftButton,
    /** Middle mouse button. */
    MiddleButton,
    /** Right mouse button. */
    RightButton
  };

public:
  /** 
   * Initialize this class.
   *
   * @param i_pEvent the event dispatched. Can't be @c NULL.
   * 
   * @param i_timestamp the timestamp in milli-seconds of the
   * interaction represented by the dispatch of the event.
   *
   * @param i_pViewer the viewer in which the event occured. Can't be
   * @c NULL.
   *
   * @param i_mousePositionInViewer the position of the mouse in the
   * viewer.
   */
  CATVidMouseEventArgs(CATSYPEvent *i_pEvent,
                       CATULONG32 i_timestamp,
                       CATVizViewer *i_pViewer,
                       const CATMathPoint2Df &i_mousePositionInViewer,
                       Modifiers i_modifiers,
                       unsigned int i_touchFlag,
                       unsigned int i_stylusFlag,
                       unsigned int i_winTabFlag = 0,
                       MouseButton i_buttonPressed = Unknown);
  /**@deprecated**/
  CATVidMouseEventArgs(CATSYPEvent *i_pEvent,
                       CATULONG32 i_timestamp,
                       CATVizViewer *i_pViewer,
                       const CATMathPoint2Df &i_mousePositionInViewer,
                       Modifiers i_modifiers,
                       unsigned int i_touchFlag,
                       MouseButton i_buttonPressed = Unknown);

  /**
   * Initialize this class from @ref CATVidMouseEventData.
   *
   * @param i_pEvent the event dispatched. Can't be @c NULL.
   *
   * @param i_mouseData the mouse data. Its @ref CATVidMouseEventData#wrViewer 
   * can't be @c NULL.
   */
  CATVidMouseEventArgs(CATSYPEvent *i_pEvent, 
                       const CATVidMouseEventData &i_mouseData);

  /** Destroy this class */
  virtual ~CATVidMouseEventArgs();

  /**
   * Get the mouse position.
   *
   * The returned position is relative to @a i_pWidget. If not @c
   * NULL, @a i_pWidget must be in the same viewer as the one in which
   * the event occured. If it is not the case a @ref FAILURE will
   * occur and this function will return <code>0.f,0.f</code> as coordinates.
   *
   * This function can't be called if the viewer in which the event
   * occured has been destroyed. In that case a @ref FAILURE will be
   * raised (except when called with @c NULL, in that case it never
   * fails).
   *
   * This class stores the position relative to the viewer and then
   * interprets it when being called on this function. As a
   * consequence the relative position of the mouse to a given widget
   * may change during the dispatch of the event if one of the widget
   * in its parenthood is moved (for example by an other event
   * handler). The initial value may also be inaccurate if some code
   * has moved the widget between the generation of the event in
   * Visualization code and the dispatch of the VID event.<br/>
   * Since the stored position is relative to the viewer, moving the
   * CATViewer itself won't change the returned value.
   *
   * @param i_pWidget the widget. @c NULL if the caller wants to
   * obtain the mouse position in the viewer.
   *
   * @return the mouse position relative to @a i_pWidget, in dp (pixels divided
   * by density), or relative to the viewer, in px (pixels), if @a i_pWidget is
   * @c NULL. It will return <code>0.f,0.f</code> if i_pWidget is not in the
   * correct viewer (in this case a @ref FAILURE) will also be triggered, or if
   * the viewer has been destroyed and @a i_pWidget is not @c NULL. If the
   * viewer has been destroyed an @a i_pWidget is @c NULL then the
   * position in the destroyed viewer will still be returned.
   *
   * @see #GetViewer
   */
  CATMathPoint2Df GetMousePosition(CATVidWidget *i_pWidget) const;
  
  /**
   * Get the mouse position relative to the viewer associated to the given widget.
   *
   * @param i_pWidget the widget. @c NULL if the caller wants to
   * obtain the mouse position in the viewer.
   *
   * @return the mouse position relative to the viewer associated to the given widget.
   */
  CATMathPoint2Df GetMousePositionRelativeToAssociatedViewer(CATVidWidget *i_pWidget) const;
	
	/**
   * Get the viewer in which the event occured.
   *
   * @return the viewer. @c NULL if the viewer has been destroyed or
   * if an internal error occured. No @c AddRef has been done on the
   * returned value.
   */
  CATVizViewer *GetViewer() const;

  /**
   * Get the pressed keyboard modifiers.
   *
   * @return the modifiers.
   */
  Modifiers GetModifiers() const;

  /**
   * Get the flag that indicates if this event simulates a touch.
   *
   * @return the touch flag.
   */
  unsigned int GetTouchFlag() const;

  /**
   * Get the flag that indicates if this event simulates a stylus.
   *
   * @return the stylus flag.
   */
  unsigned int GetStylusFlag() const;
  
  /**
   * Get the flag that indicates if this event simulates a stylus.
   *
   * @return the stylus flag.
   */
  unsigned int GetWinTabFlag() const;

  /**
   * Get the mouse button identifier.
   *
   * @return 0 for left button, 2 for middle button, 4 for right button         
   */
  MouseButton GetButtonPressed() const;

  /**
   * Permit to know if the event (the release) is a true release and not a simple change of manipulator
   */
  void SetTrueRelease(int i_trueRelease);
  int IsTrueRelease() const;

private:
  CATVidMouseEventArgs(const CATVidMouseEventArgs &);
  CATVidMouseEventArgs &operator=(const CATVidMouseEventArgs &);

private:
  /** a weakreference on the @ref CATVizViewer used to defined the
      mouse position */
  const CATBaseUnknown_WR _wrViewer;
  /** the mouse position relative to the viewer @ref #_wrViewer */
  const CATMathPoint2Df _mousePositionInViewer;
  /** the bitfield representing modifiers */
  const Modifiers _modifiers;
  /** flag that indicates if this event simulates a touch */
  const unsigned int _touchFlag;
  /** flag that indicates if this event simulates a stylus */
  const unsigned int _stylusFlag;
    /** flag that indicates if this event simulates a stylus */
  const unsigned int _winTabFlag;
  /** mouse button identifier */
  const MouseButton  _buttonPressed;
  /** flag that indicates if we have a true release */
  int _trueRelease;
};

#endif // CATVidMouseEventArgs_H
