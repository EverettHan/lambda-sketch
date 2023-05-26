// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATVidCtlMenuItem.h
// Header definition of CATVidCtlMenuItem
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jun 2007  Creation: jov
//===================================================================
#ifndef CATVidCtlMenuItem_H
#define CATVidCtlMenuItem_H

#include <VisuDialog.h>
#include <CATCommand.h>
#include <CATUnicodeString.h>

class CATVidCtlMenuItem;
class CATDlgContextualMenu;
class CATDlgPushItem;
class l_CATVidCtlMenuItem;
class CATSYPEventHandlersSupport;
class CATSYPEvent;
class CATSYPEventHandler;
class CATSYPEventArgs;

//-----------------------------------------------------------------------
/**
 * @ingroup VIDControls
 */
class ExportedByVisuDialog CATVidCtlMenuItem: public CATCommand
{
  CATDeclareClass;
public:
  // Standard constructors
  // ---------------------
  CATVidCtlMenuItem ();
  CATVidCtlMenuItem (CATCommand *i_pParent, const CATString & i_pIdentifier);

  void SetText(const CATUnicodeString& i_text);
  const CATUnicodeString& GetText() const;

  void SetIconName(const CATUnicodeString& i_iconName);
  const CATUnicodeString& GetIconName() const;

  void SetEnableFlag(CATBoolean i_enableFlag);
  CATBoolean GetEnableFlag() const;

  void SetVisibleFlag(CATBoolean i_visibleFlag);
  CATBoolean GetVisibleFlag() const;

  CATNotification* GetMenuItemSelectedNotification();

  l_CATVidCtlMenuItem* GetVidLetter(){return _pLetter;};

  /**
   * Add a handler for a given event.
   *
   * The handlers will be called in the order of their registration.
   *
   * If this function is called during the dispatch of an event, the
   * registered event handler won't be called for this dispatch but
   * will only be called for next dispatches.
   *
   * It is possible to call mutliple times this function with the same
   * event and the same handler instance. In that case there will be
   * multiple registrations; no checks are made for duplication (the
   * caller will have to call @ref #RemoveHandler multiple times).
   *
   * @param i_pEvent the event that we are interested in. Note that @c
   * AddRef will be called on the event. Can't be @c NULL.
   *
   * @param i_pHandler the handler to call. Can't be @c NULL. 
   * @c AddRef will be called on this pointer. Note that the type of 
   * @c CATSYPEventArgs supported by this handler will be compared to
   * the type of arguments of the event. It must be a super-type of
   * the one of the event.
   *
   * @param i_handleConsumedEvents @c !=0 if the handler should be
   * called for consumed events.
   *
   * @return @c !=0 if succeeded, @c 0 if failed to add handler due to
   * invalid input or internal error (in that case a @ref FAILURE has
   * been raised).
   *
   * @see #RemoveHandler
   */
   int AddHandler(CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler, int i_handleConsumedEvents = 0);

  /**
   * Remove an handler for an event.
   *
   * If this function is called during the dispatch of an event, the
   * unregistered event handler will be called for this dispatch but
   * will not be called for next dispatches.
   *
   * If the same handler has been added multiple times, this function
   * removes the first found registration (starting the look up from
   * the most ancient registration).
   *
   * @param i_pEvent the event. Can't be @c NULL.
   *
   * @param i_pHandler the handler. Can't be @c NULL.
   *
   * @return @c !=0 if succeeded, @c 0 if failed to remove handler due
   * to invalid input or internal error (in that case a @ref FAILURE has
   * been raised) or if the handler was never registered for the given
   * event (in that case NO @ref FAILURE is raised, it is valid to do
   * so; this is important for auto-remove handlers).
   *
   * @see #AddHandler
   */
  int RemoveHandler(CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler);

  /**
   * Dispatch the event.
   *
   * The propagation mode of the event is not used since there is no
   * tree of CATVidCtlMenuItem (@ref CATSYPEvent#GetPropagation).
   *
   * The list of handlers that will be called will be frozen before
   * the first handler is called; as a consequence, changes in the
   * handlers for the event won't have any effect on the dispatch of
   * this event (but will have effect on next dispatches, even on
   * dispatches that may be triggered by handlers of this event).
   *
   * This call is synchronous; it is blocking until the dispatch is
   * ended.
   *
   * The origin on the event argument (@ref CATSYPEventArgs#GetOrigin)
   * must be either @c NULL or equal to this object. If @c NULL, it
   * will be positioned by this function to this object.
   *
   * The instance of arguments used on this function will be passed to
   * all handlers called during the dispatch.
   * 
   * @param i_pArgs the arguments of the event to dispatch (the
   * dispatched event is retreived though @ref
   * CATSYPEventArgs#GetEvent). @ref CATSYPEventArgs#GetOrigin must be
   * either this object of @c NULL.
   *
   * @return @c !=0 if the dispatch succeeded, @c 0 if failed.
   *
   * @see #AddHandler
   * @see #RemoveHandler
   */
  int Dispatch(CATSYPEventArgs *i_pArgs); 

protected:
  virtual ~CATVidCtlMenuItem ();

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidCtlMenuItem (CATVidCtlMenuItem &);
  CATVidCtlMenuItem& operator=(CATVidCtlMenuItem&);

  void Listen(CATDlgPushItem* i_pPushItem);
  void OnMenuItemActivateCB(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData );

private:
  CATUnicodeString _text;
  CATUnicodeString _iconName;
  CATBoolean _enableFlag;
  CATBoolean _visibleFlag;
  l_CATVidCtlMenuItem* _pLetter;
  /** support for events */
  CATSYPEventHandlersSupport *_pSupport;
private:
  // --------------------------------------------------------------------------
  // Friend
  // --------------------------------------------------------------------------
  friend class l_CATVidCtlMenuItem;
};

//-----------------------------------------------------------------------

#endif
