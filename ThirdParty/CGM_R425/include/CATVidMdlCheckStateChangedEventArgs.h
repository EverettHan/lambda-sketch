//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2013/05/22
//===================================================================
// CATVidMdlCheckStateChangedEventArgs.h
// Header definition of class CATVidMdlCheckStateChangedEventArgs
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2013/05/22 Creation: Code generated by the 3DS wizard  JV8
//===================================================================

#ifndef CATVidMdlCheckStateChangedEventArgs_H
#define CATVidMdlCheckStateChangedEventArgs_H

#include <VisuDialog.h>
#include <CATSYPEventArgs.h>
#include <CATVidMdlIndex.h>

class CATSYPEvent;

/**
 * Argument class dispatched by a view class to indicate that the checkstate
 * of items has changed inside it.
 *
 * Listening to this event allows you to be warned that the checkstate has changed
 * in a particular view. When you receive this event, you can consult which
 * element have been checked or unchecked and what is the checkstate of this element by using
 * respectively the GetCheckedItem member function and GetCheckState member function.
 */
class ExportedByVisuDialog CATVidMdlCheckStateChangedEventArgs: public CATSYPEventArgs
{
  CATDeclareClass;
public:
  /** Default constructor */
  CATVidMdlCheckStateChangedEventArgs (CATSYPEvent * i_pEvent, const CATVidMdlIndex & i_checkedItem, CATBoolean i_checkedState, CATBoolean i_mixedState);
  /** Destructor */
  virtual ~CATVidMdlCheckStateChangedEventArgs ();

  /**
   * Get the model index of checked/unchecked item at the time
   * the event was sent.
   *
   * @returns the checked or unchecked item
   */
  const CATVidMdlIndex & GetCheckedItem() const;

  /**
   * Get the check state of the item
   *
   * @returns 1 if checked, 0 if unchecked
   */
  CATBoolean GetCheckState() const;

  /**
   * Get the mixed state of the item
   *
   * @returns 1 if in mixed state, 0 otherwise
   */
  CATBoolean GetMixedState() const;

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidMdlCheckStateChangedEventArgs (CATVidMdlCheckStateChangedEventArgs &);
  CATVidMdlCheckStateChangedEventArgs& operator=(CATVidMdlCheckStateChangedEventArgs&);

  /** checked or unchecked item (represented by its model index) */
  CATVidMdlIndex _checkedItem;

  /** check state of the item (1 for checked and 0 for unchecked) */
  CATBoolean _checkState;

  /** mixed state of the item (1 for mixed state and 0 otherwise) */
  CATBoolean _mixedState;
};

//-----------------------------------------------------------------------

#endif
