#ifndef CATVidMouseWheelEventArgs_H
#define CATVidMouseWheelEventArgs_H

#include <VisuDialog.h>

#include <CATVidMouseEventArgs.h>
#include <CATBaseUnknown_WR.h>
#include <CATMathPoint2Df.h>
#include <CATUnicodeString.h>

class CATVizViewer;
class CATVidWidget;
struct CATVidMouseEventData;

/** @ingroup VIDGP
 * Dispatching arguments for mouse wheel events of @ref CATVidGP.
 *
 * @see CATVidGP::Wheel
 */
class ExportedByVisuDialog CATVidMouseWheelEventArgs : public CATVidMouseEventArgs
{
  CATDeclareClass;
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
  CATVidMouseWheelEventArgs(CATSYPEvent *i_pEvent, 
                       CATULONG32 i_timestamp, 
                       CATVizViewer *i_pViewer,
                       const CATMathPoint2Df &i_mousePositionInViewer, 
                       Modifiers i_modifiers,
                       int i_wheelValue);

  /**
   * Initialize this class from @ref CATVidMouseEventData.
   *
   * @param i_pEvent the event dispatched. Can't be @c NULL.
   *
   * @param i_mouseData the mouse data. Its @ref CATVidMouseEventData#wrViewer 
   * can't be @c NULL.
   */
  CATVidMouseWheelEventArgs(CATSYPEvent *i_pEvent, 
                       const CATVidMouseEventData &i_mouseData);

  /** Destroy this class */
  virtual ~CATVidMouseWheelEventArgs();

  /**
   * Get the wheel value.
   *
   * @return the wheel.
   */
  int GetWheelValue() const;

private:
  CATVidMouseWheelEventArgs(const CATVidMouseWheelEventArgs &);
  CATVidMouseWheelEventArgs &operator=(const CATVidMouseWheelEventArgs &);
private:
  /** wheel value*/
  const int _wheelValue;
};

#endif // CATVidMouseWheelEventArgs_H
