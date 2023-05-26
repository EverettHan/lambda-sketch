//=============================================================================
// COPYRIGHT Dassault Systemes 2012
//=============================================================================
// CATVidActionChangedEventArgs.cpp
// Header definition of class CATVidActionChangedEventArgs
//=============================================================================
// 2012/03/26 Creation: Code generated by the 3DS wizard LD5
//=============================================================================

#ifndef CATVidActionChangedEventArgs_H
#define CATVidActionChangedEventArgs_H

#include <VisuDialog.h>
#include <CATSYPEventArgs.h>
class CATVidAction;
class CATSYPEvent;

//-----------------------------------------------------------------------------
/** @ingroup groupVidMenu
 *
 * Those event arguments can be used for all events sent each time that an
 * the exclusively checked action changes in an exclusive action group.
 *
 * If the action group is not exclusive, it is never sent.
 */
class ExportedByVisuDialog CATVidActionChangedEventArgs: public CATSYPEventArgs
{
  CATDeclareClass;
public:
  /** 
   * Initializes this class.
   *
   * @param i_pEvent the dispatched event. Can't be @c NULL. 
   * 
   * @param i_pAction a pointer to the action that has been checked. Cannot be 
   * @c NULL. @c AddRef is called on the pointer.
   */
  CATVidActionChangedEventArgs(CATSYPEvent * i_pEvent, CATVidAction * i_pAction);

  /** Destroy this class. */
  virtual ~CATVidActionChangedEventArgs();

  /**
   * @return a pointer to the action that has been checked. @c AddRef has not 
   * been called on the return pointer. Cannot be @c NULL.
   */
  CATVidAction * GetAction() const;

private:
CATVidActionChangedEventArgs (CATVidActionChangedEventArgs &);
CATVidActionChangedEventArgs& operator=(CATVidActionChangedEventArgs&);

 /** 
  * The new action.
  */
  CATVidAction * _pAction;

};

//-----------------------------------------------------------------------

#endif
