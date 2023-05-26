#ifndef CATVidFraToolbar_h
#define CATVidFraToolbar_h

// COPYRIGHT Dassault Systemes 2011

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidFraPanel.h>
#include <CATVid.h>

// System framework
#include <CATBoolean.h>

/**
 * @ingroup VIDFrame
 * Class representing an immersive toolbar.
 * By default, a CATVidFraToolbar is docked on the top docking area dedicated to toolbars.
 *
 * The following code is an example of a CATVidFraToolbar use : 
 * @code
 *   CATVidFraToolbar * pToolbar = new CATVidFraToolbar(this, "Name");
 *   pToolbar->SetApplicativeWidget(myWidget);
 *   pToolbar->SetVisibleFlag(TRUE);
 * @endcode
 *
 * Warning : the CATVidFraToolbar class usage is restricted to a limited set of allowed applicative widgets.
 */
class ExportedByVisuDialog CATVidFraToolbar : public CATVidFraPanel
{
  CATDeclareClass;

  public:

  /**
    * Constructs a CATVidFraToolbar
    * @param i_pParent
    * Parent command
    * @param i_pIdentifier
    * Label identifier
    */
  CATVidFraToolbar(CATCommand *i_pParent, const CATString& i_pIdentifier);

  /**
    * Default constructor, used internally.
    */
  CATVidFraToolbar();

  /**
   * Sets the docking priority used to compute the order of the docked windows 
   * in the StrongDockLevel layout.
   * The smaller the priority is, the closer to the center area the docked window is.
   * If two windows docked in the same area have the same priority, the last docked window will be
   * placed closer to the center area than the first one.
   * For example, if two windows are docked in the Left area, the window with the higher priority
   * will be placed on the Left of the other one.
   * By default, the DockPriority property is set to 0.
   */
  void SetDockPriority(int i_priority);

  /**
   * Specifies whether the window uses a background or not.
   * By default, the UseBackgroundFlag property is set to TRUE.
   */
  void SetUseBackgroundFlag(CATBoolean i_useBackgroundFlag);

  /**
   * Sets the scrollbar policy (see @ref CATVid#ScrollbarPolicy).
   * Default policy is @c AsNeeded (see @ref CATVid#AsNeeded).
   *
   * @param i_scrollbarPolicy the scrollbar policy.
   */
  void SetScrollbarPolicy(CATVid::ScrollbarPolicy i_scrollbarPolicy);

  /**
   * @return the current scrollbar policy.
   * @see CATVid#ScrollbarPolicy
   */
  CATVid::ScrollbarPolicy GetScrollbarPolicy() const;

  /**
   * Specifies which animation is used when the visibility property of the window content is changed.
   * @param i_visibilityPolicy the visibility policy. 
   * Default value is CATVid::SlideTToBAnimation.
   * @see CATVidFraPanel#SetContentVisibleFlag
   * @see CATVid#VisibilityPolicy
   */
  void SetContentVisibilityPolicy(CATVid::VisibilityPolicy i_visibilityPolicy);

protected:

  virtual ~CATVidFraToolbar();

  // Overriden methods
  virtual HRESULT ReadWindowPreferences(CATBoolean i_positionAndDimensionOnly = FALSE);

  private:

  // Copy constructor and equal operator
  // -----------------------------------
  CATVidFraToolbar (CATVidFraToolbar &);
  CATVidFraToolbar& operator=(CATVidFraToolbar&);
};

#endif // CATVidFraToolbar_h
