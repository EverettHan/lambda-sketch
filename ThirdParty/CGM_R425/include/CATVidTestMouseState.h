#ifndef CATVidTestMouseState_H
#define CATVidTestMouseState_H

#include <VisuDialog.h>

#include <CATVidMouseState.h>
#include <CATSYPHashMap.h>
#include <CATBaseUnknown_WR.h>
#include <CATMathPoint2Df.h>

/** @ingroup VIDCore
 * Implementation of @ref CATVidMouseState that can be used to by
 * tests to override the object used to access to the state of the
 * mouse device.
 *
 * This object is meant to be used with @ref
 * CATVidDeviceStates#SetMouseState.
 *
 * @par For Tests Only
 * Please only use this object in tests, never is production code.
 *
 * @see CATVidDeviceStates
 * @see CATVidMouseState
 */
class ExportedByVisuDialog CATVidTestMouseState : public CATVidMouseState
{
  CATDeclareClass;
public:
  /** Initialize this class */
  CATVidTestMouseState();
  
  /** Destroy this class */
  virtual ~CATVidTestMouseState();

  /**
   * Set the mouse position that should be returned by @ref
   * #GetViewerMousePosition when called on the given viewer.
   *
   * @param i_pVizViewer the viewer. Can't be @c NULL. Only a
   * weak-reference will be kept on the viewer.
   *
   * @param i_viewerMousePosition the position of the mouse in the
   * viewer.
   */
  void SetViewerMousePosition(CATVizViewer *i_pVizViewer, const CATMathPoint2Df &i_viewerMousePosition);

  /** 
   * @copydoc CATVidMouseState#GetViewerMousePosition 
   *
   * @par Special Behavior
   * If @ref #SetViewerMousePosition has never been called for @a
   * i_pVizViewer, then this implementation will raise a @ref FAILURE
   * and return a point will both coordinates to 0.
   */
  virtual CATMathPoint2Df GetViewerMousePosition(CATVizViewer *i_pVizViewer);

private:
  CATVidTestMouseState(const CATVidTestMouseState &);
  CATVidTestMouseState &operator=(const CATVidTestMouseState &);
public:
  /**
   * A key in @ref #_viewerPositions map.
   *
   * It keeps a weak-reference on the @ref CATVizViewer it
   * points. 
   *
   * Its hash-code is based on the memory adress of the @c
   * CATVizViewer. This hash is kept in the state of this object so
   * that it never changes, even after the picture have been
   * destroyed.
   *
   * Its comparison is based on the stored hash first, and then the
   * viewer reference. Note that after the viewer has been destroyed,
   * two keys pointing different pictures but having the same hash
   * will be equal (for @c operator==). If this key is used in an
   * hash-map, that means that two different keys in the hash-map will
   * be equal.  As a consequence, before using this class, you should
   * ensure that this is not an issue for this hash-map.
   */
  class Key {
  public:
    /**
     * Initialize the class.
     *
     * @param i_pVizViewer the viewer. Can't be @c NULL.
     */
    Key(CATVizViewer *i_pVizViewer);
    
    /** Copy constructor. */
    Key(const Key &i_other);

    /** Destroy this class */
    ~Key();

    /**
     * Compare two keys.
     *
     * It will first compare hash-codes. If hash-codes are equal, it
     * will try to compare viewers. If both keys point destroyed
     * viewers, they will be considered equal.
     */
    friend int operator==(const Key &i_left, const Key &i_right);

    /**
     * Get the hash-code computed from the address of the viewer.
     *
     * @return the hash-code. It won't change even after the viewer is
     * destroyed.
     */
    int HashCode() const;
  private:
    Key &operator=(const Key&);
  private:
    /** the hash code based on the address of the viewer */
    const int _hashCode;
    /** weak-ref on the viewer */
    CATBaseUnknown_WR _wrefViewer;    
  };
private:
  /** map associating the position for each viewer */
  CATSYPHashMap<Key, CATMathPoint2Df> _viewerPositions;
};

#endif // CATVidTestMouseState_H
