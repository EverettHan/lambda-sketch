#ifndef CATVidEnum_H
#define CATVidEnum_H

#include <VisuDialog.h>
#include <CATSYPDeclareEnumFactory.h>

// CATVidDialogType------------------------------------------------------------
enum CATVidDialogType {
  CATVidImmersiveDialog, 
  CATVidDockDialog, 
  CATVidPhylactereDialog, 
  CATVidTopFloatDialog, 
  CATVidBottomFloatDialog, 
  CATVidBackgroundDialog, 
  CATVidGridDialog, 
  CATV3DDialog};

// CATVidLifeCycle-------------------------------------------------------------
/**
 * Possible life cycles for a window.
 * @see CATVidFraWindow#SetLifeCycle
 */
enum CATVidLifeCycle {
  /** 
   * The window life cycle is bound to its associated viewer life cycle.
   * The window cannot be created if no active viewer exists.
   * When the associated viewer is destroyed, the window is destroyed too.
   * If the window is closed (by clicking on the 'Close' button), the window is destroyed.
   */
  CATVidDocumentLC, 
  /** 
   * The window life cycle is bound to the application life cycle.
   * The window can be created even if no active viewer exists.
   * When the associated viewer is destroyed, the window is not destroyed but is
   * automatically extracted.
   * When the application is destroyed, the window is destroyed too.
   * If the window is closed (by clicking on the 'Close' button), the window is destroyed.
   */
  CATVidApplicationLC, 
  /** 
   * The window life cycle is bound to the application life cycle.
   * The window can be created even if no active viewer exists.
   * When the associated viewer is destroyed, the window is not destroyed but is
   * automatically extracted.
   * When the application is destroyed, the window is destroyed too.
   * If the window is closed (by clicking on the 'Close' button) and if the AutoCloseFlag property 
   * is set to FALSE, the window is not destroyed, only the CATVidFraWindow::Closed event is sent.
   */
  CATVidUserSideLC, 
  /** 
   * The window life cycle is bound to its associated viewer life cycle.
   * The window cannot be created if no active viewer exists.
   * When the associated viewer is destroyed, the window is destroyed too.
   * If the window is closed (by clicking on the 'Close' button) and if the AutoCloseFlag property 
   * is set to FALSE, the window is not destroyed, only the CATVidFraWindow::Closed event is sent.
   */
  CATVidUserSideDocumentLC
};

CATSYP_DECLARE_ENUMFACTORY(ExportedByVisuDialog, CATVidLifeCycle);

// CATVidState-----------------------------------------------------------------
enum CATVidState  {CATVidStateOff, CATVidStateOn, CATVidStateOver, CATVidStateOverOn, CATVidStateDisable, CATVidStatePick, CATVidStateViewport};

enum CATVidEchoMode {EchoNormal,NoEcho,EchoPassword};

// CATVidAlignment-----------------------------------------------------------------
typedef unsigned int CATVidHAlignment;
#define CATVidHAlignLeft   0
#define CATVidHAlignCenter 1
#define CATVidHAlignRight  2

typedef unsigned int CATVidVAlignment;
#define CATVidVAlignTop    0
#define CATVidVAlignCenter 1
#define CATVidVAlignBottom 2

typedef unsigned int CATVidLabelCropProperty;
#define CATVidLabelNoCrop       0
#define CATVidLabelCropCut      1
#define CATVidLabelCropWithDots 2

typedef unsigned int CATVidCtlEditorDataType;
#define CATVidCtlEditorText           0
#define CATVidCtlEditorInt            1
#define CATVidCtlEditorFloat          2
#define CATVidCtlEditorAlphabetical   3
#define CATVidCtlEditorNumerical      4
#define CATVidCtlEditorAlphanumerical 5
#define CATVidCtlEditorDouble         6
#define CATVidCtlEditorPassword       7

typedef unsigned int CATVidFlowOrientation;
#define CATVidFlowLeftToRight 0
#define CATVidFlowTopToBottom 1

// CATVidStyle-----------------------------------------------------------------
typedef unsigned long CATVidStyle;
#define CATVidWndClose              (1 << 1)
#define CATVidWndExtract            (1 << 2)
#define CATVidWndMinimize           (1 << 3)
#define CATVidWndNoDecoration       (1 << 5)
#define CATVidWndNoResize           (1 << 6)
#define CATVidWndNoMove             (1 << 7)
#define CATVidWndNoBarTitle         (1 << 8)

#define CATVidWndStandardButtons    (CATVidWndClose | CATVidWndExtract | CATVidWndMinimize)

/** the recording based on the viewer recording of mouse events */
#define VID_RECORD_LEVEL_VISU  2
/** the recording based on the algorithm described in @ref CATVidInteractionRecorderData */
#define VID_RECORD_LEVEL_INTERACTION 3

//++DEPRECATED
#define CATVidDocumentLF    CATVidDocumentLC
#define CATVidApplicationLF CATVidApplicationLC
//--DEPRECATED


#endif
