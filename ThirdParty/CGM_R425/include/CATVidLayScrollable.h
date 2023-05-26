// COPYRIGHT Dassault Systemes 2005 
//===================================================================
//
// CATVidLayScrollable.h
// Header definition of CATVidLayScrollable
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Oct 2005  Creation: Code generated by the CAA wizard  jov
//===================================================================
#ifndef CATVidLayScrollable_H
#define CATVidLayScrollable_H
#include <CATVidCtl.h>
#include <CATBoolean.h>
#include <CATMathPoint2Df.h>
#include <CATMathVector2Df.h>
class CATVidCtlScrollbar;
class CATVidLayGrid;
class CATVidGPSquare;
class CATVidMouseEventArgs;
class CATVidMouseWheelEventArgs;
/**
 * @ingroup VIDLayout
 * The aim of this component is to display a partial view of a widget.
 * It displays scrollbar to move the visible part of the widget.
 * This widget NEEDS to be redesigned and refactored.
 * @image html CATVidLayScrollable.PNG "Standard scrollable in V6 theme"
 * @image html CATVidLayScrollable-Bright.png "Standard scrollable in V6 theme, bright ambiance"
 * @image html CATVidLayScrollable-3DViaShape.PNG "Standard scrollable in 3DViaShape theme"
 */
class ExportedByVisuDialog CATVidLayScrollable: public CATVidCtl
{
  CATDeclareClass;
public:
  /** Constructor */
  CATVidLayScrollable ();
  /** Constructor */
  CATVidLayScrollable (CATCommand *i_pParent, const CATString & i_pIdentifier);
  /**
   * Sets the scrollable content.
   * @param i_pHandledWidget the scrollable content
   */
  void SetHandledWidget(CATVidWidget* i_pHandledWidget);
  /**
   * @returns the scrollable content.
   */
  CATVidWidget* GetHandledWidget();
  /**
   * Modify the scrollbar percentage value for a given scrollbar
   * @param i_scrollbarType 0 for vertical, 1 for horizontal
   * @param i_percentage the scrollbar percentage value to assign
   */
  void ChangeScrollPercentage(unsigned char i_scrollbarType, float i_percentage);
  /**
   * Gets the scrollbar percentage value for a given scrollbar type
   * @param i_scrollbarType 0 for vertical, 1 for horizontal
   * @return the scrollbar percentage
   */
  float GetScrollPercentage(unsigned char i_scrollbarType) const;
  /**
   * Sets the side to display the vertical scrollbar.
   *  @param i_side 0 for left, 1 for right
   */
  void SetVerticalScrollbarSide(unsigned char i_side);
  /**
   * @return the side of the vertical scrollbar. 0 for left (default), 1 for right.
   */
  unsigned char GetVerticalScrollbarSide() const;
  /**
   * Sets the side to display the horizontal scrollbar.
   *  @param i_side 0 for bottom (default), 1 for top
   */
  void SetHorizontalScrollbarSide(unsigned char i_side);
  /**
   * @return the side of the horizontal scrollbar.0 for bottom (default), 1 for top.
   */
  unsigned char GetHorizontalScrollbarSide() const;
  /**
   * Sets the pickflag of the scrollable background.
   *  @param i_flag FALSE by default
   */
  void SetPickableBackgroundFlag(const CATBoolean& i_flag);
  /**
   * @return the pickflag of the scrollable background.
   */
  CATBoolean GetPickableBackgroundFlag() const;
  /**
   * Sets a value in pixel for each scroll step for a given scrollbar.
   * Default value is 1. Minimum value is 1. 
   * @param i_quantization the quantization value
   * @param i_scrollbarType 0 for vertical, 1 for horizontal
   */
  void SetQuantization(float i_quantization, unsigned char i_scrollbarType);
  /**
   * Gets the quantization value for a given scrollbar.
   * @param i_scrollbarType 0 for vertical, 1 for horizontal
   * @return the quantization value.
   */
  float GetQuantization(unsigned char i_scrollbarType) const;
  /**
   * Sets an offset value in pixel that is not taken in account when modifying scrollbar value.
   * @param i_quantizationOffset the i_quantizationOffset value. Must be > 0
   * @param i_scrollbarType 0 for vertical, 1 for horizontal
   */
  void SetQuantizationOffset(float i_quantizationOffset, unsigned char i_side);//0:vertical, 1:horizontal
  /**
   * Gets the quantization offset value for a given scrollbar.
   * @param i_scrollbarType 0 for vertical, 1 for horizontal
   * @return the quantization offset value.
   */
  float GetQuantizationOffset(unsigned char i_scrollbarType) const;
  /**
   * Sets the first step of the viewport for a given orientation. 
   * @param i_scrollbarType 0 for vertical, 1 for horizontal
   * @param i_stepNumber the step corresponding to the offset value to assign to the scrollbar
   */
  void SetFirstStep(int i_stepNumber, unsigned char i_scrollbarType);
  /**
   * Returns the first step of the viewport for a given orientation. 
   * @param i_scrollbarType 0 for vertical, 1 for horizontal
   * @return the quantization offset value.
   */
  int GetFirstStep(unsigned char i_scrollbarType);
  /**
   * Sets the first step of the viewport for the vertical orientation. 
   * @param i_stepNumber the step corresponding to the offset value to assign to the scrollbar
   */
  void SetFirstStepV(int i_stepNumber);
  /**
   * Returns the first step of the viewport for the vertical orientation. 
   * @return the quantization offset value.
   */
  int GetFirstStepV();
  /**
   * Sets the first step of the viewport for the horizontal orientation. 
   * @param i_stepNumber the step corresponding to the offset value to assign to the scrollbar
   */
  void SetFirstStepH(int i_stepNumber);
  /**
   * Returns the first step of the viewport for the horizontal orientation. 
   * @return the quantization offset value.
   */
  int GetFirstStepH();
  /**
   * Moves up the viewport by 1 step
   */
  bool LineUp();
 /**
   * Moves down the viewport by 1 step
   */
  bool LineDown();
  /**
   * Moves left the viewport by 1 step
   */
  bool LineLeft();
  /**
   * Moves right the viewport by 1 step
   */
  bool LineRight();
  /**
   * Moves the viewport by its height to the top
   */
  bool PageUp();
  /**
   * Moves the viewport by its height to the bottom
   */
  bool PageDown();
  /**
   * @return the presenter interface used by the scrollable
   * @see CATISYPPresenter
   */
  virtual CATISYPPresenter_var GetItem();
  /**
   * @return the notification sent when a scroll is performed.
   */
  CATNotification *GetScrollActionNotification() const;
  /**
   * @see CATVidWidget#Update
   */
  virtual void Update();

  /**
   * Sets the horizontal scroll value.
   */
  void SetHScrollbarValue( const int& i_HScrollbarValue);
  /**
   * @return the horizontal scroll value
   */
  int GetHScrollbarValue() const;

  /**
   * Sets the vertical scroll value.
   */
  void SetVScrollbarValue( const int& i_VScrollbarValue);
  /**
   * @return the vertical scroll value
   */
  int GetVScrollbarValue() const;
  /**
   * @return the dimension of the horizontal scrollbar
   */
  CATMathPoint2Df GetHScrollbarDimension() const;
  /**
   * @return the dimension of the vertical scrollbar
   */
  CATMathPoint2Df GetVScrollbarDimension() const;
protected:
  virtual ~CATVidLayScrollable ();
  virtual void TunnelInformation(const CATVidInformation& i_information);
  virtual void ChildWidgetDeleted(CATVidWidget* i_pDeletedChild);
  virtual void UpdateComputedMinimumDimension();
  virtual void SetComputedMinimumDimension(const CATMathPoint2Df& i_computedMinimumDimension);
private:
  CATVidLayScrollable (CATVidLayScrollable &);
  CATVidLayScrollable& operator=(CATVidLayScrollable&original);
  void OnSlide (CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData );
  void HandledWidgetModifiedCB(CATCallbackEvent, void*, CATNotification* i_pEvent, CATSubscriberData , CATCallback);
  void HandledWidgetMinimumDimensionCB(CATCallbackEvent, void*, CATNotification* i_pEvent, CATSubscriberData , CATCallback);
  float QuantizeValue(float i_valueToQuantization, float i_quantizationOffset, float i_quantization, int& o_step) const;
  void BuildScrollable();
  /** 
   * Handler for @ref CATVidGP#Drag event
   * uses the drag event of the gp to compute the scroll. Consumes the event.
   * @note only if the drag comes from a touch manipulation.
   *
   * This handler must only be registered on a CATVidLayScrollable.
   */ 
  void HandleDrag(CATBaseUnknown *i_pSender, CATVidMouseEventArgs *i_pArgs);
  /** 
   * Handler for @ref CATVidGP#ReleaseEvt event
   * called when receiving a ReleaseEvt from the manipulated gp. Consumes the event.
   * @note only do treatment if the release comes after a touch manipulation.
   *
   * This handler must only be registered on a CATVidLayScrollable.
   */ 
  void HandleReleaseEvt(CATBaseUnknown *i_pSender, CATVidMouseEventArgs *i_pArgs);
  /** 
   * Handler for @ref CATVidGP#MouseWheelm event
   * called when a mouse wheel is done over a widet, consumes the event.
   *
   * This handler must only be registered on a CATVidLayScrollable.
   */ 
  void HandleMouseWheel(CATBaseUnknown *i_pSender, CATVidMouseWheelEventArgs *i_pArgs);

private:

  CATBoolean GetHScrollbarVisibleState(){return _needHorizontalScroolbarFlag;}

  CATVidLayGrid*      _pLayGrid;
  CATVidCtlScrollbar* _pHorizontalScrollbar;
  CATVidCtlScrollbar* _pVerticalScrollbar;
  CATVidWidget*       _pHandledWidget;
  CATVidGPSquare*     _pBackground;
  CATVidCtl*          _pPresenter;
  CATBoolean _updating;
  CATBoolean _needHorizontalScroolbarFlag;
  CATBoolean _needVerticalScroolbarFlag;
  unsigned int _horizontalScrollbarSide;
  unsigned int _verticalScrollbarSide;
  unsigned int _pickableBackgroundFlag  :1;
  float _quantizationOffsetH;
  float _quantizationOffsetV;
  float _quantizationH;
  float _quantizationV;

  /** last touch position */
  CATMathPoint2Df _lastPosition;
  /** current touch translation */
  CATMathVector2Df _translation;
  int _VScrollbarValue;
  int _HScrollbarValue;

  /**
   * @name Deprecated members
   */
  /*@{*/ 
public:
  void SetCellSpacing(int i_cellSpacing);
  void SetColor(unsigned char i_r, unsigned char i_g, unsigned char i_b, unsigned char i_a);
  float GetQuantization() const;
  float GetQuantizationOffset() const;
  /*@}*/ 


  friend class l_CATVidCtlLegacyBaseCombo;//For HScrollbar visible state need.
};
//-----------------------------------------------------------------------
#endif

