#ifndef CATVidFlickEventArgs_H
#define CATVidFlickEventArgs_H

#include <VisuDialog.h>

#include <CATVidInputEventArgs.h>
#include <CATBaseUnknown_WR.h>
#include <CATMathPoint2Df.h>
#include <CATMathVector2Df.h>

class CATVizViewer;

/** @ingroup VIDGP
 * Dispatching arguments for a flick event of @ref CATVidGP.
 *
 * @see CATVidGP::Flick
 */
class ExportedByVisuDialog CATVidFlickEventArgs : public CATVidInputEventArgs
{
  CATDeclareClass;
public:
  /** 
   * Initialize this class.
   *
   * The constructor is protected since this class should be a base
   * class for other events.
   *
   * @param i_pEvent the event dispatched. Can't be @c NULL.
   *
   * @param i_timestamp the timestamp in milli-seconds of the
   * interaction represented by the dispatch of the event.
   */
  CATVidFlickEventArgs(CATSYPEvent *i_pEvent, 
                       CATULONG32 i_timestamp, 
                       CATVizViewer *i_pViewer, 
                       const CATMathPoint2Df& i_flickOrigin, 
                       const CATMathVector2Df& i_flickVector, 
                       int i_flickDuration);

public:
  /** Destroy this class */
  virtual ~CATVidFlickEventArgs();

  /**
   * Get the viewer in which the event occured.
   *
   * @return the viewer. @c NULL if the viewer has been destroyed or
   * if an internal error occured. No @c AddRef has been done on the
   * returned value.
   */
  CATVizViewer *GetViewer() const;

  const CATMathPoint2Df& GetFlickOrigin() const;
  const CATMathVector2Df& GetFlickVector() const;
  int GetFlickDuration() const;

private:
  CATVidFlickEventArgs(const CATVidFlickEventArgs &);
  CATVidFlickEventArgs &operator=(const CATVidFlickEventArgs &);
private:
  /** a weakreference on the @ref CATVizViewer used to defined the
      mouse position */
  const CATBaseUnknown_WR _wrViewer;

  CATMathPoint2Df _flickOrigin;
  CATMathVector2Df _flickVector;
  int _flickDuration;
};

#endif // CATVidFlickEventArgs_H
