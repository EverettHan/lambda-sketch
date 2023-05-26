#ifndef CATVidLayDock_h
#define CATVidLayDock_h

// COPYRIGHT Dassault Systemes 2005

// Local framework
#include <VisuDialog.h>
#include <CATVidLayCollection.h>
#include <CATVidRectangle.h>

// Mathematics framework
#include <CATMathPoint2Df.h>

class CATVidLayDockConstraints;
class CATVidLayConstraintsAndWidget;
class CATSYPEvent;

/**
 * A Layout that docks children to a specified area of the container
 * You can specify where controls are docked horizontally (left, center, or right)
 * and vertically (top, center, bottom) within the layout.
 * 
 * @par In CAPSYPStyle files
 * @code
 * <CATVidLayDock ...........>
 *   <MyWidgetA ........... CATVidLayDock.IndexedConstraints="..." />
 *   <MyWidgetB ........... CATVidLayDock.IndexedConstraints="..." />
 *   ....
 * </CATVidLayDock>
 * @endcode
 * IndexedConstraints is a CATVidLayDockConstraints.
 *
 *
 * @see CATVidLayDockConstraints
 * @see CATVidLayCollection
 * @see CATISYPCollection
 * @ingroup VIDLayout
 */

class ExportedByVisuDialog CATVidLayDock : public CATVidLayCollection
{
  CATDeclareClass;

public:

  // Standard constructor
  // --------------------
  CATVidLayDock();
  CATVidLayDock(CATCommand *i_pParent, const CATString & i_pIdentifier);

  /**
   * Retrieves the dock constraints associated to the given widget.
   */
  void GetConstraints(CATVidWidget* i_pWidget, CATVidLayDockConstraints& o_constraints);

  /**
   * Returns the computed center area of the dock layout, in device independant pixels (dp).
   */
  const CATVidRectangle& GetCenterArea() const;

  /**
   * Returns the minimum dimension of the center area of the dock layout, in device independant pixels (dp).
   */
  CATMathPoint2Df GetCenterAreaMinimumDimension() const;

  /**
   * Returns the @c LayoutModified event.
   * 
   * The @c LayoutModified event is emitted when the layout is modified
   * 
   * @par EventProperties
   *   - Name: @c "LayoutModified"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent * LayoutModified();

protected:

  virtual ~CATVidLayDock ();
  CATVidLayDock (CATVidLayDock &);
  CATVidLayDock& operator=(CATVidLayDock&);

  virtual CATVidLayConstraints* CreateConstraints();
  virtual void Layout();
  virtual void UpdateComputedMinimumDimension();
  virtual void InternalSetConstraints(CATVidWidget *i_pWidget, const CATVidLayConstraints& i_constraints);

private:

  /**
   * Updates the computed center area of the dock layout.
   */
  void SetCenterArea(const CATVidRectangle & i_centerArea);

  static int s_CompareCstAndWidgets(const void * i_ppCstAndWidget1, const void * i_ppCstAndWidget2);

  CATVidRectangle _centerArea;
};

#endif // CATVidLayDock_h
