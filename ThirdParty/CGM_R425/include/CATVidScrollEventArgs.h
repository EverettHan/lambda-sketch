//=============================================================================
// COPYRIGHT Dassault Systemes 2012/01/18
//=============================================================================
// CATVidScrollEventArgs.cpp
// Header definition of class CATVidScrollEventArgs
//=============================================================================
//  2012/01/18 Creation: Code generated by the 3DS wizard LD5
//=============================================================================

#ifndef CATVidScrollEventArgs_H
#define CATVidScrollEventArgs_H

#include <VisuDialog.h>
#include <CATSYPEventArgs.h>
#include <CATMathPoint2Df.h>
class CATSYPEvent;

//-----------------------------------------------------------------------------

class ExportedByVisuDialog CATVidScrollEventArgs: public CATSYPEventArgs
{
  CATDeclareClass;
public:
  /** 
   * Initializes this class.
   *
   * @param i_pEvent the dispatched event. Can't be @c NULL.
   * 
   * @param i_scrollDelta how much the scrolled widget has moved inside the 
   * viewport during the scroll event, in pixels x pixels.
   */
  CATVidScrollEventArgs(CATSYPEvent * i_pEvent, const CATMathPoint2Df i_scrollDelta);

  /** Destroy this class. */
  virtual ~CATVidScrollEventArgs();

  /**
   * @return how much the scrolled widget has moved inside the viewport during
   * the scroll event, in pixels x pixels.
   */
   CATMathPoint2Df GetScrollDelta() const;

private:
CATVidScrollEventArgs (CATVidScrollEventArgs &);
CATVidScrollEventArgs& operator=(CATVidScrollEventArgs&);

 /** 
  * The delta of scroll offset that corresponds to this scroll event.
  */
  const CATMathPoint2Df _scrollDelta;

};

//-----------------------------------------------------------------------

#endif