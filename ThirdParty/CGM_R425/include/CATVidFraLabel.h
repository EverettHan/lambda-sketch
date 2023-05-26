#ifndef CATVidFraLabel_h
#define CATVidFraLabel_h

// COPYRIGHT Dassault Systemes 2011

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidFraPanel.h>
#include <CATMathPoint2Df.h>
#include <CATMathPointf.h>

// IntrospectionInfrastructure framework
#include <CATSYPDeclareEnumFactory.h>

class CATVidWidget;
class CATString;
class CATVidLay2DSyncToViewpointConstraints;
class CATViewpoint;

/**
 * @ingroup VIDFrame
 * Class representing a floating label embedding an immersive widget and linked to an anchor point 
 * of the containing viewer.
 *
 * This class has the same capabilities of the @ref #CATVidFraPanel class (e.g snapping and docking capability). 
 * The anchor point visibility is dependent on the label location : if the window is docked or 
 * attached to a group, the anchor point will not be visible.
 * 
 * @see CATVidFraPanel for a detailed description of the inherited capabilities.
 *
 * The following code is an example of a CATVidFraLabel use : 
 * @code
 *   CATVidFraLabel * pLabel = new CATVidFraLabel(this, "LabelName");
 *   pLabel->SetApplicativeWidget(myWidget);
 *   pLabel->SetTitle("My title");
 *   pLabel->SetIconName("MyIcon.png");
 *   pLabel->SetAnchorPoint(CATMathPointf(0.f, 0.f, 0.f));
 *   pLabel->SetOffsetPoint(CATMathPoint2Df(-100.0f, 100.0f));
 *   pLabel->SetVisibleFlag(TRUE);
 * @endcode
 */
class ExportedByVisuDialog CATVidFraLabel : public CATVidFraPanel
{
  CATDeclareClass;

  public:

  /**
    * Constructs a CATVidFraLabel
    * @param i_pParent
    * Parent command
    * @param i_pIdentifier
    * Label identifier
    */
  CATVidFraLabel(CATCommand *i_pParent, const CATString& i_pIdentifier);

  /**
    * Default constructor, used internally.
    */
  CATVidFraLabel();

  /**
    * Sets the anchor point, that is a 3D point (Z=0 for 2D point) used to link the specified 
    * viewpoint and the window, in dp (device independant pixels = pixels divided by density).
    * @see SetSpecifiedViewpoint
    */
  void SetAnchorPoint(const CATMathPointf &i_point);

  /**
    * Returns the anchor point.
    */
  const CATMathPointf& GetAnchorPoint() const;

  /**
    * Sets the link offset, that is the 2D offset starting from the window position to its anchor point.
    * This offset is used to initially display the window at the desired position.
    * For example, if you want to display your label window on the bottom right of its anchor point, you can 
    * write the following line :
    * @code
    * pLabel->SetOffsetPoint(CATMathPoint2Df(-100.0f, -100.0f));
    * @endcode
    *
    * @see SetAnchorPoint
    */
  void SetOffsetPoint(const CATMathPoint2Df &i_offsetPoint);

  /**
    * Returns the link offset, that is the 2D offset starting from the window position to its anchor point.
    */
  const CATMathPoint2Df& GetOffsetPoint() const;

  /**
    * Sets the viewpoint (2D or 3D) corresponding to the anchor point.
    * If not scpecified, or if NULL, the main viewpoint will be used.
    * @see SetAnchorPoint
    */
  void SetSpecifiedViewpoint(CATViewpoint* i_pSpecificViewpoint);
  CATViewpoint * GetSpecifiedViewpoint() const;

  /**
    * Specifies whether the window title bar can be made visible or not.
    * By default, the TitleBarVisibleFlag property is set to TRUE.
    * @see CATVidFraWindow::GetTitleBarVisibleState
    */
  void SetTitleBarVisibleFlag(CATBoolean i_titleBarVisibleFlag);

  /**
    * Returns TRUE if the window title bar can be made visible, FALSE otherwise.
    * By default, the TitleBarVisibleFlag property is set to TRUE.
    * @see CATVidFraWindow::GetTitleBarVisibleState
    */
  CATBoolean GetTitleBarVisibleFlag() const;

  /**
    * Specifies whether the window must use an anchor point to specify its position or not.
    * By default, the UseAnchorPointFlag property is set to TRUE.
    */
  void SetUseAnchorPointFlag(CATBoolean i_useAnchorPointFlag);

  /**
    * Returns TRUE if the window must use an anchor point to specify its position, FALSE otherwise.
    * By default, the UseAnchorPointFlag property is set to TRUE.
    */
  CATBoolean GetUseAnchorPointFlag() const;

  /**
    * Specifies whether the anchor point must be visible or not.
    * The anchor point visibility is dependent on the AnchorPointVisibleFlag property, on the type of window
    * (CATVidPhylactereDialog, CATVidFraLabel, ...) and on its location : if the window is docked or 
    * attached to a group, the anchor point will not be visible.
    * If a window is not visible, its anchor point is not visible either.
    * @see CATVidFraWindow::GetAnchorPointVisibleState
    */
  void SetAnchorPointVisibleFlag(CATBoolean i_anchorPointVisibleFlag);

  /**
    * Returns TRUE if the anchor point must be visible, FALSE otherwise.
    * The anchor point visibility is dependent on the AnchorPointVisibleFlag property, on the type of window
    * (CATVidPhylactereDialog, CATVidFraLabel, ...) and on its location : if the window is docked or 
    * attached to a group, the anchor point will not be visible.
    * If a window is not visible, its anchor point is not visible either.
    * @see CATVidFraWindow::GetAnchorPointVisibleState
    */
  CATBoolean GetAnchorPointVisibleFlag() const;

  /**
    * Specifies whether the window position must be updated when the anchor point position is modified or not.
    * By default, the FollowAnchorPointFlag property is set to FALSE.
    */
  void SetFollowAnchorPointFlag(CATBoolean i_followAnchorPointFlag);

  /**
    * Returns TRUE if the window position must be updated when the anchor point position is modified, 
    * FALSE otherwise.
    * By default, the FollowAnchorPointFlag property is set to FALSE.
    */
  CATBoolean GetFollowAnchorPointFlag() const;

	/**
     * Sets the color of the attached line.
     */
    void SetAttachedLineColor(const CATVidColor& i_attachedLineColor);

    /**
     * Returns the color of the attached line.
     */
    CATVidColor GetAttachedLineColor() const;

    /**
     * Sets the border color of the attached line.
     */
    void SetAttachedLineBorderColor(const CATVidColor& i_attachedLineBorderColor);

    /**
     * Returns the border color of the attached line.
     */
    CATVidColor GetAttachedLineBorderColor() const;


  /**
   * Possible types of attachment between the window and its anchor point.
   */
  enum AttachmentType
  {
    /** The attachment is a line */
    LineAttachment = 0, 
    /** The attachment is a triangle */
    TriangleAttachment,
  };

  /**
   * Sets the type of attachment between the window and its anchor point.
   * By default, the AttachmentType property is set to LineAttachment.
   */
  void SetAttachmentType(CATVidFraLabel::AttachmentType i_attachmentType);

  /**
   * Returns the type of attachment between the window and its anchor point.
   */
  CATVidFraLabel::AttachmentType GetAttachmentType() const;

  /**
    * Specifies whether the user preferences must be restored to set the initial window position or not.
    * If not, the initial position of the window will be computed from its anchor point.
    * This method must be called before the first call to SetVisibleFlag.
    * By default, the RestoreUserPreferencesFlag property is set to FALSE.
    */
  void SetRestoreUserPreferencesFlag(CATBoolean i_restoreUserPreferencesFlag);

  /**
    * Returns TRUE if the user preferences must be restored to set the initial window position, FALSE otherwise.
    */
  CATBoolean GetRestoreUserPreferencesFlag() const;

  /**
    * Specifies whether the window background is draggable, i.e if the window can be moved 
    * when the user is dragging the background, or not.
    * By default, the BackgroundDraggableFlag property is set to FALSE.
    */
  void SetBackgroundDraggableFlag(CATBoolean i_backgroundDraggableFlag);

  protected:

  virtual ~CATVidFraLabel();

  void BuildDefaultProperties();

  // Overriden methods
  virtual HRESULT ReadWindowPreferences(CATBoolean i_positionAndDimensionOnly = FALSE);

  private:

  // Copy constructor and equal operator
  // -----------------------------------
  CATVidFraLabel (CATVidFraLabel &);
  CATVidFraLabel& operator=(CATVidFraLabel&);
};

CATSYP_DECLARE_ENUMFACTORY(ExportedByVisuDialog, CATVidFraLabel__AttachmentType);

#endif // CATVidFraLabel_h
