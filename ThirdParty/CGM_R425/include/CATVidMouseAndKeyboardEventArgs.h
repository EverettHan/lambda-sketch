#ifndef CATVidMouseAndKeyboardEventArgs_H
#define CATVidMouseAndKeyboardEventArgs_H

#include "VisuDialog.h"
#include "CATSYPEventArgs.h"

class CATKeybdEvent;
class CATVidMouseEventArgs;

typedef unsigned int CATModifier;
typedef unsigned int CATKeyCode;

/** @ingroup VIDGP
 * 
 * Class for dispatching arguments of an event that must pass on the 
 * information of a mouse and/or a keyboard event.
 */
class ExportedByVisuDialog CATVidMouseAndKeyboardEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;

public:
  /** Destroy this class */
  virtual ~CATVidMouseAndKeyboardEventArgs();
  /**
   * Initialize this class with the arguments of a mouse event and/or with a 
   * keyboard event. At least one of the two pointers must not be @c NULL.
   *
   * @param i_pEvent the dispatched event.
   * @param i_pMouseEventArgs the mouse event arguments.
   * @param i_pKeyboardEvent the keyboard event.
   */
  CATVidMouseAndKeyboardEventArgs(CATSYPEvent * i_pEvent, CATVidMouseEventArgs * i_pMouseEventArgs, CATKeybdEvent * i_pKeyboardEvent);
  /**
   * @return information relayed about the mouse event, if a mouse event 
   * triggered the dispatch (@c NULL else).
   */
  CATVidMouseEventArgs * GetMouseEventArgs() const;
  /**
   * @return information relayed by the keyboard event, if a keyboard event
   * triggered the dispatch (@c NULL else). 
   */ 
  CATKeybdEvent * GetKeyboardEvent() const;
  /**
   * Shortcut function. Asserts that a keyboard event is defined. 
   *
   * @see CATKeybdEvent#GetKeyCodeType 
   */
  int         GetKeyCodeType() const;
  /**
   * Shortcut function. Asserts that a keyboard event is defined. 
   *
   * @see CATKeybdEvent#GetCharCode 
   */
  CATUINT32   GetCharCode() const;
  /**
   * Shortcut function. Asserts that a keyboard event is defined. 
   *
   * @see CATKeybdEvent#GetKeyCode 
   */
  CATKeyCode  GetKeyCode() const;
  /**
   * Shortcut function. Asserts that a keyboard event is defined. 
   *
   * @see CATKeybdEvent#GetModifier 
   */
  CATModifier GetModifier() const;
  /**
   * Shortcut function. Asserts that a keyboard event is defined. 
   *
   * @see CATKeybdEvent#IsRepeat 
   */
  int         IsRepeat() const;

private:
  /** Copy constructor. */
  CATVidMouseAndKeyboardEventArgs(const CATVidMouseAndKeyboardEventArgs &);
  /** Assignment operator. */
  CATVidMouseAndKeyboardEventArgs &operator=(const CATVidMouseAndKeyboardEventArgs &);
private:
  /**
   * Information to relay about a mouse event.
   */
  CATVidMouseEventArgs * _pMouseEventArgs;
  /**
   * Information to relay about a keyboard event.
   */
  CATKeybdEvent * _pKeyboardEvent;
};

#endif
