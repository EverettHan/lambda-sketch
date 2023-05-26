#ifndef CATVidVisibilityAtReplayArgs_H
#define CATVidVisibilityAtReplayArgs_H


#include <VisuDialog.h>

#include <CATSYPEventArgs.h>

/** @ingroup groupVidRecord
 * Arguments for event @ref CATVidGP#VisibilityAtReplay.
 *
 * @see CATVidGP#VisibilityAtReplay
 */
class ExportedByVisuDialog CATVidVisibilityAtReplayArgs : public CATSYPEventArgs
{
  CATDeclareClass;
public:
  /** @copydoc CATSYPEventArgs#CATSYPEventArgs
   * @param i_expectedVisibleState the visible state of the origin GP
   * that was expected by replay infrastructure and that was not the
   * current one.
   */
  CATVidVisibilityAtReplayArgs(CATSYPEvent *i_pEvent, int i_expectedVisibleState);

  /** Destroy this class */
  virtual ~CATVidVisibilityAtReplayArgs();

  /**
   * Get the visible state of the origin GP (@ref #GetOrigin) that was
   * expected by the replay infrastructure and that was not the
   * current one.
   *
   * @return @c !=0 if the origin was expected to be visible and was
   * invisible, @c 0 if the origin was expected invisible and was
   * visible.
   */
  int GetExpectedVisibleState() const;
private:
  CATVidVisibilityAtReplayArgs(const CATVidVisibilityAtReplayArgs &);
  CATVidVisibilityAtReplayArgs &operator=(const CATVidVisibilityAtReplayArgs &);
private:
  /** @c !=0 if the origin was expected to be visible by replay */
  int _expectedVisibleState;
};


#endif // CATVidVisibilityAtReplayArgs_H
