// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATVidCtlExpander.h
// Header definition of CATVidCtlExpander
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  March 2008  Creation: jov
//===================================================================
#ifndef CATVidCtlExpander_H
#define CATVidCtlExpander_H

#include <VisuDialog.h>
#include <CATVidCtlHeaderedContent.h>
#include <CATBoolean.h>

class CATSYPEvent;

/**
 * Base class for expander.
 * <b>Role</b>:
 * This widget is used to display or hide a content, by pressing a button. 
 * It inherits the generic component CATVidCtlHeaderedContent.
 * <br>
 * Create this CATVidCtlExpander by using factory static method CreateExpander.
 * @ingroup VIDControls
 */
class ExportedByVisuDialog CATVidCtlExpander : public CATVidCtlHeaderedContent
{
  CATDeclareClass;

public:

  /**
   * Constructs a CATVidCtlExpander.
   * No associsated style, use static factory CreateExpander
   */
  CATVidCtlExpander();

  /**
   * Constructs a CATVidCtlExpander with standard style.
   * @param i_pParent
   *   The parent of the widget.
   * @param i_pIdentifier
   *   The name of the widget.
   */
  static CATVidCtlExpander* CreateExpander(CATCommand *i_pParent, const CATString & i_pIdentifier);

  /**
   * Sets a flag that expands or collapses the contained widget.
   * @param i_expandedFlag
   * The flag that expands or collapses the contained widget.
   */
  virtual void SetExpandedFlag(CATBoolean i_expandedFlag);

  /**
   * Returns a flag that indicate if the contained widget is collapsed or expanded
   */
  CATBoolean GetExpandedFlag() const;

  /**
   * Sets a flag that allow to unexpand the expander under the same father..
   * @param i_exclusiveFlag
   */
  void SetExclusiveFlag(CATBoolean i_exclusiveFlag);

  /**
   * Returns a flag that indicate if the contained widget is exclusive
   */
  CATBoolean GetExclusiveFlag() const;

  /**
   * Sets a flag that display a thin border and a background around the expander content.
   * @param i_useBoundariesFlag
   */
  void SetUseBoundariesFlag(CATBoolean i_useBoundariesFlag);

  /**
   * Returns a flag that indicate if the content boundaries (thin border + background) are displayed or not.
   */
  CATBoolean GetUseBoundariesFlag() const;

  /** 
  * Sets the alignement(orientation) of the expender header. 
  * By default, value is CATVid::Top
  * This will involve a rebuild of the interface by the style processor.
  *
  *(In above ascii art, the thiny box is the expander header, the big box is the expander content) 
  * 
  * Side : Top
  *      ____________________  
  *     |                    |
  *     |____________________|
  *     |                    |
  *     |                    |     
  *     |                    |
  *     |                    |
  *     |____________________|
  *
  *  
  *  Side : Bottom
  * 
  *      ____________________  
  *     |                    |
  *     |                    |
  *     |                    |
  *     |                    |     
  *     |____________________|
  *     |                    |
  *     |____________________|
  * 
  *
  *  Side : Left
  *      ____________________  
  *     |    |               |
  *     |    |               |
  *     |    |               |
  *     |    |               |     
  *     |    |               |
  *     |    |               |
  *     |____|_______________| 
  *
  *
  *
  *  Side : Right
  *      ____________________  
  *     |               |    |
  *     |               |    |
  *     |               |    |
  *     |               |    |     
  *     |               |    |
  *     |               |    |
  *     |_______________|____|
  *
  * 
  */
  void SetAlignment(CATVid::Side i_headerAlignment);

  /** @return the expander header alignment*/
  CATVid::Side GetAlignment() const;

  /**
   * Notification when the expander is expanded
  */
  CATNotification *GetExpanderExpandNotification() const;

  /**
   * Notification when the expander is collapsed
  */
  CATNotification *GetExpanderCollapseNotification() const;

  /**
   * Get the @c Expanded event.
   * 
   * The @c Expanded event is emitted when the expander is expanded
   * 
   * @par EventProperties
   *   - Name: @c "Expanded"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent * Expanded();

  /**
   * Get the @c Collapsed event.
   * 
   * The @c Collapsed event is emitted when the expander is collapsed
   * 
   * @par EventProperties
   *   - Name: @c "Collapsed"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent * Collapsed();

  /**
   * Get the @c PreExpand event.
   * 
   * The @c PreExpand event is emitted when the expander is collapsed
   * 
   * @par EventProperties
   *   - Name: @c "PreExpand"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   * 
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent * PreExpand();

  virtual void Update();
  
  void SetUseExpandAnimationFlag(int i_useExpandAnimationFlag);
  int GetUseExpandAnimationFlag() const;

 /**
  * Ensure the visibility of children widget. @copydoc CATIVidEnsureVisible#EnsureWidgetVisibility.   
  */
  HRESULT EnsureWidgetVisibility(CATVidWidget* i_pWidget);

protected:

  CATVidCtlExpander(CATCommand *i_pParent, const CATString & i_pIdentifier);
  virtual ~CATVidCtlExpander ();
  
  void ComputeDefaultDataTemplateName(CATUnicodeString& o_dataTemplateName, CATUnicodeString& o_styleSheet) const;

  /**copydoc CATVidCtl#TemplateDataUpdated */
  virtual void TemplateDataUpdated();
private:
  void UpdateContentAnimation();
private:
  CATVid::Side _headerAlignment;
  CATBoolean _expandedFlag;
  CATBoolean _exclusiveFlag;
  CATBoolean _useBoundariesFlag;
  CATBoolean _useExpandAnimationFlag;
};

#endif
