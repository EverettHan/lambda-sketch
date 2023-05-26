#ifndef UIUTIL_H
#define UIUTIL_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "DI0PANV2.h"

#ifdef _LANGUAGE_CPLUSPLUS

class CATDialog;

/**
 * @nodoc 
 */
typedef char            CATCar;
/**
 * @nodoc 
 */
typedef unsigned char   CATUChar;
/**
 * @nodoc 
 */
typedef short           CATShort;
/**
 * @nodoc 
 */
typedef unsigned short  CATUShort;
/**
 * @nodoc 
 */
typedef int             CATInt;
/**
 * @nodoc 
 */
typedef unsigned int    CATUInt;
/**
 * @nodoc 
 */
typedef long            CATLong;
/**
 * Unsigned long .
 */
typedef unsigned long   CATULong;
/**
 * @nodoc 
 */
typedef float           CATFloat;
/**
 * @nodoc 
 */
typedef double          CATDouble;
/**
 * Boolean used in the Dialog Framework. 
 * @param FALSE 
 * @param TRUE 
 */
typedef short           CATBool;

#ifndef TRUE
/**
 * @nodoc 
 */
#define TRUE         1
#endif

#ifndef FALSE
/**
 * @nodoc 
 */
#define FALSE        0
#endif

#include "CATString.h"
#include "CATUnicodeString.h"

// Following definitions are specific to Windows OS
// but are not linked to our DRIVER_WINDOWS implementation.
// Thus we check for _WINDOWS_SOURCE instead of DRIVER_WINDOWS
#ifdef _WINDOWS_SOURCE

/**
 * @nodoc 
 */
typedef DWORD DROPEFFECT;
/**
 * @nodoc 
 */
#define      DROPEFFECT_NONE ( 0 )
/**
 * @nodoc 
 */
#define      DROPEFFECT_COPY ( 1 )
/**
 * @nodoc 
 */
#define      DROPEFFECT_MOVE ( 2 )
/**
 * @nodoc 
 */
#define      DROPEFFECT_LINK ( 4 )
/**
 * @nodoc 
 */
#define      DROPEFFECT_SCROLL       ( 0x80000000 )

#else // ! _WINDOWS_SOURCE

#ifndef _POINTL_DEFINED
#define _POINTL_DEFINED

/**
 * Structure representing a point.
 * @param x
 * @param y
 */
typedef struct _POINTL
{
  CATInt x;
  CATInt y;
} POINTL;

#endif // _POINTL_DEFINED

/**
 * Mouse drop effect mode.
 * @param DROPEFFECT_NONE
 * @param DROPEFFECT_COPY
 * @param DROPEFFECT_MOVE
 * @param DROPEFFECT_LINK
 * @param DROPEFFECT_SCROLL
 */
typedef enum tagDROPEFFECT
{
        DROPEFFECT_NONE   = 0,
        DROPEFFECT_COPY   = 1,
        DROPEFFECT_MOVE   = 2,
        DROPEFFECT_LINK   = 4,
        DROPEFFECT_SCROLL = 0x80000000
}DROPEFFECT;

/**
 * @nodoc 
 */
#define MK_LBUTTON          0x0001
/**
 * @nodoc 
 */
#define MK_RBUTTON          0x0002
/**
 * @nodoc 
 */
#define MK_SHIFT            0x0004
/**
 * @nodoc 
 */
#define MK_CONTROL          0x0008
/**
 * @nodoc 
 */
#define MK_MBUTTON          0x0010

#endif



#include <stdio.h>

/**
 * Style type.
 * <br><b>Role:</b> It's the style of your dialog'object. The style can be a composition 
 * of several style. Example : CATDlgFraNoFrame|CATDlgFraNoTitle. Each class lists its allowed type.  
 */
#define USE_CATDlgStyle_64
#ifdef USE_CATDlgStyle_64
typedef CATULONG64 CATDlgStyle;
#else // USE_CATDlgStyle_64
typedef unsigned long CATDlgStyle;
#endif // USE_CATDlgStyle_64

/**
 * Array index type.
 */
typedef unsigned short CATDlgTabIndex;

/**
 * Attachment mode.
 * @param CATDlgUnspecified
 * @param CATDlgTopOrLeft
 * @param CATDlgTopOrLeftRelative
 * @param CATDlgRightOrBottom
 * @param CATDlgRightOrBottomRelative
 * @param CATDlgCenter
 * @param CATDlgCenterRelative
 */
enum CATDlgAttachment { CATDlgUnspecified,                 // 0
        CATDlgTopOrLeft,      CATDlgTopOrLeftRelative,     // 1 , 2
        CATDlgRightOrBottom,  CATDlgRightOrBottomRelative, // 3 , 4
        CATDlgCenter,         CATDlgCenterRelative } ;     // 5 , 6

/**
 * Beep.
 * @param CATDlgBeepInfo
 * @param CATDlgBeepAsterix
 * @param CATDlgBeepWarning
 * @param CATDlgBeepExclamation
 * @param CATDlgBeepError
 * @param CATDlgBeepQuestion
 */
enum CATDlgBeepType {
    CATDlgBeepInfo, CATDlgBeepAsterix = CATDlgBeepInfo,
    CATDlgBeepWarning, CATDlgBeepExclamation = CATDlgBeepWarning,
    CATDlgBeepError,
    CATDlgBeepQuestion
};

/** @nodoc */
typedef unsigned long KEY;

#include "CATDlgKeySym.h"

/**
 * Orientation mode.
 * @param Vertical
 * @param Horizontal
 */
enum     Orientation   { Vertical, Horizontal };

/**
 * Alignment mode.
 * @param TopOrLeft
 * @param RightOrBottom
 * @param Center
 */
enum     Alignment     { TopOrLeft, RightOrBottom, Center };

/**
 * Insertion mode.
 * @param After
 * @param Before
 */
enum     InsertionMode { After, Before };

/**
 * @nodoc 
 * Icon type.
 * deprecated
 */
enum CATDlgIconType { Default, General, Creation, Modification, Analysis, NonTransparent};

/**
 * Sort order for CATDlgMultiList.
 * @param AlphabeticalOrder
 * @param NumericalOrder
 * @param UserDefinedOrder
 */
enum CATDlgLstSortOrder {
  AlphabeticalOrder,
  NumericalOrder,
  UserDefinedOrder
};

/**
 * @nodoc 
 */
#define CATULong_ALONE            (1 << 1)
/**
 * @nodoc 
 */
#define CATULong_CATIA            (1 << 2)

#endif // _LANGUAGE_CPLUSPLUS

// CATDialog styles
//-----------------
/**
 * @nodoc 
 */
#define CATDlgNoExternResource    (1U << 31)
/**
 * @nodoc 
 */
#define CATDlgGridLayout          (1 << 0)
/**
 * @nodoc 
 */
#define CATDlgShow                (1 << 1)
/**
 * @nodoc 
 */
#define CATDlgHide                (1 << 2)
/**
 * @nodoc 
 */
#define CATDlgEnable              (1 << 3)
/**
 * @nodoc 
 */
#define CATDlgDisable             (1 << 4)
/**
 * @nodoc 
 */
#define CATDlgUndefined           (1 << 5)
/**
 * @nodoc 
 */
#define CATDlgDataAdd             (1 << 6)
/**
 * @nodoc 
 */
#define CATDlgDataModify          (1 << 7)
/**
 * @nodoc 
 */
#define CATDlgPowerInputLink      (1 << 8)

// CATDlgDocument (Document Window) styles
//----------------------------------------
/**
 * @nodoc 
 */
#define CATDlgWndFrameMDI         (1 << 16)

// CAUTION. RESERVED              (1 << 17)
// CAUTION. RESERVED              (1 << 18)

/**
 * @nodoc 
 */
#define CATDlgWndOleMode          (1 << 26)
/**
 * @nodoc 
 */
#define CATDlgWndOleInPlace       (1 << 27)

// CATDlgDialog + CATDlgNotify + CATDlgFile styles
//------------------------------------------------
/**
 * @nodoc 
 */
#define CATDlgWndModal            (1 << 9)

// CATDlgDialog + CATDlgNotify styles
//-----------------------------------
/**
 * @nodoc 
 */
#define CATDlgWndHELP             (1 << 12)

// CATDlgDialog (Dialog Window) styles
//------------------------------------
/**
 * @nodoc 
 */
#define CATDlgWndSavePreferences  (1 << 7)
/**
 * @nodoc 
 */
#define CATDlgWndOK               (1 << 10)
/**
 * @nodoc 
 */
#define CATDlgWndCANCEL           (1 << 11)
/**
 * @nodoc 
 */
#define CATDlgWndPREVIEW          (1 << 16)
/**
 * @nodoc 
 */
#define CATDlgWndAPPLY            (1 << 13)
/**
 * @nodoc 
 */
#define CATDlgWndCLOSE            (1 << 23)
/**
 * @nodoc 
 */
#define CATDlgWndBtnOKCancel      (1 << 25)
/**
 * @nodoc 
 */
#define CATDlgWndBtnOKCancelPreview (1 << 26)
/**
 * @nodoc 
 */
#define CATDlgWndBtnOKApplyClose  (1 << 27)
/**
 * @nodoc 
 */
#define CATDlgWndBtnWizard        (1U << 31)
/**
 * @nodoc 
 */
#define CATDlgWndBtnClose         (1 << 28)
/**
 * @nodoc 
 */
#define CATDlgWndNoButton         (1 << 14)
/**
 * @nodoc
 * obsolete
 */
#define CATDlgWndBtnBottom        (1 << 19)
/**
 * @nodoc 
 */
#define CATDlgWndTitleBarHelp     (1 << 24)
/**
 * @nodoc 
 */
#define CATDlgWndSmallDecoration  (1 << 15)
/**
 * @nodoc 
 */
#define CATDlgWndNoDecoration     (1 << 20)
/**
 * @nodoc 
 */
#define CATDlgWndNoResize         (1 << 18)
/**
 * @nodoc 
 */
#define CATDlgWndAutoResize       (1 << 22)
/**
 * @nodoc 
 */
#define CATDlgWndChildMDI         (1 << 17)
/**
 * @nodoc 
 */
#define CATDlgWndPointerLocation  (1 << 21)
/**
 * @nodoc 
 */
#define CATDlgWndTopRight         (1 << 29)
/**
 * @nodoc 
 */
#define CATDlgWndKeepRatio        (1 << 30)

// CAUTION. RESERVED              (1ULL << 32)
// CAUTION. RESERVED              (1ULL << 33)
// CAUTION. RESERVED              (1ULL << 34)

// CATDlgNotify (Notify window) styles
//------------------------------------
/**
 * @nodoc 
 */
#define CATDlgNfyAbortRetryIgnore (1 << 19)
/**
 * @nodoc 
 */
#define CATDlgNfyOK               (1 << 20)
/**
 * @nodoc 
 */
#define CATDlgNfyOKCancel         (1 << 21)
/**
 * @nodoc 
 */
#define CATDlgNfyRetryCancel      (1 << 22)
/**
 * @nodoc 
 */
#define CATDlgNfyYesNo            (1 << 23)
/**
 * @nodoc 
 */
#define CATDlgNfyYesNoCancel      (1 << 24)
/**
 * @nodoc 
 */
#define CATDlgNfyAction           (1 << 25)
/**
 * @nodoc 
 */
#define CATDlgNfyInformation      (1 << 26)
/**
 * @nodoc 
 */
#define CATDlgNfyWarning          (1 << 27)
/**
 * @nodoc 
 */
#define CATDlgNfyError            (1 << 28)

// CATDlgFile & CATDlgStdFile (File/Folder Selection window) styles
//-----------------------------------------------------------------
/**
 * @nodoc 
 */
#define CATDlgFileSave            (1 << 23)
/**
 * @nodoc 
 */
#define CATDlgStdFileSave         (1 << 23)
/**
 * @nodoc 
 */
#define CATDlgFileOverwritePrompt (1 << 24)
/**
 * @nodoc 
 */
#define CATDlgStdFileOverwritePrompt (1 << 24)
/**
 * @nodoc 
 */
#define CATDlgFileMultisel        (1 << 25)
/**
 * @nodoc 
 */
#define CATDlgStdFileMultisel     (1 << 25)
/**
 * @nodoc 
 */
#define CATDlgFolderChooser       (1 << 28)
/**
 * @nodoc 
 */
#define CATDlgStdFolderChooser    (1 << 28)
/**
 * @nodoc 
 */
#define CATDlgStdFileReadOnly     (1 << 29)
/**
 * @nodoc 
 */
#define CATDlgStdFilePreview      (1 << 30)

// CATDlgFindAndReplace styles
//-----------------------------------------------------------------
/**
 * @nodoc
 */
#define CATDlgStdFind             (1 << 23)
/**
 * @nodoc
 */
#define CATDlgStdReplace          (1 << 24)
/**
 * @nodoc
 */
#define CATDlgStdGotoLine         (1 << 25)

// MDI Layout styles
//------------------
/**
 * @nodoc 
 */
#define CATDlgTileHorizontal      (1 << 0)
/**
 * @nodoc 
 */
#define CATDlgTileVertical        (1 << 1)
/**
 * @nodoc 
 */
#define CATDlgTileSkipHidden      (1 << 2)

// Toolbar
//--------
/**
 * @nodoc 
 */
#define CATDlgTlbDockOnTop        (1 << 17)
/**
 * @nodoc 
 */
#define CATDlgTlbDockOnBottom     (1 << 18)
/**
 * @nodoc 
 */
#define CATDlgTlbDockOnLeft       (1 << 19)
/**
 * @nodoc 
 */
#define CATDlgTlbDockOnRight      (1 << 20)
/**
 * @nodoc 
 */
#define CATDlgTlbUnDock           (1 << 21)
/**
 * @nodoc 
 */
#define CATDlgTlbIconBox          (1 << 22)
/**
 * @nodoc 
 */
#define CATDlgTlbDockableFrame    (1 << 23)

// CAUTION. RESERVED              (1 << 24)
// CAUTION. RESERVED              (1 << 25)
// CAUTION. RESERVED              (1 << 26)
// CAUTION. RESERVED              (1 << 27)

// Iconbox
//--------
// CAUTION. RESERVED              (1 << 22)
/**
 * @nodoc 
 */
#define CATDlgIboxNoHandler    (1 << 23)
/**
 * @nodoc 
 */
#define CATDlgIboxFullPopup    (1 << 24)

// Menu
//-----
/**
 * @nodoc 
 */
#define CATDlgCtxEmpty        (1 << 17)
/**
 * @nodoc 
 */
#define CATDlgCtxNoConcat     (1 << 18)

// Item
//-----

// Control
//--------
/**
 * @nodoc
 */
#define CATDlgCtlDouble           (1 << 17)


// Splitter
//---------
/**
 * @nodoc 
 */
#define CATDlgSplResizeFirstPane  (1 << 20)

// Frame
//------
/**
 * @nodoc 
 */
#define CATDlgFraNoTitle          (1 << 18)
/**
 * @nodoc 
 */
#define CATDlgFraNoFrame          (1 << 19)
/**
 * @nodoc 
 */
#define CATDlgFraNoMargin         (1 << 20)
/**
 * @nodoc 
 */
#define CATDlgFraResizeActiveUnderContainer (1 << 21)

// Container
//----------
/**
 * @nodoc 
 */
#define CATDlgAutoScroll          (1 << 22)

// Lists
//------
/**
 * @nodoc 
 */
#define CATDlgLstMultisel         (1 << 18)
/**
 * @nodoc 
 */
#define CATDlgLstAutoSort         (1 << 19)
/**
 * @nodoc 
 */
#define CATDlgLstPerformance      (1 << 20)
/**
 * @nodoc 
 */
#define CATDlgLstAllowEmptyCells  (1 << 21)

// CheckButton and Item
//-----------------------
/**
 * @nodoc 
 */
#define CATDlgCheck               (1 << 18)
/**
 * @nodoc 
 */
#define CATDlgUncheck             (1 << 19)

// CheckButton and RadioButton
//----------------------------
/**
 * @nodoc
 */
#define CATDlgBtnNoIndicator      (1 << 20)

// CheckButton, RadioButton and PushButton
//----------------------------------------
/**
 * @nodoc
 */
#define CATDlgBtnIconAndText      (1 << 21)

// PushButton
//-----------
/**
 * @nodoc 
 */
#define CATDlgPusRepetitive       (1 << 18)
/**
 * @nodoc 
 */
#define CATDlgPusNoShadow         (1 << 19)

// Slider and Separator
//-----------------------
/**
 * @nodoc 
 */
#define CATDlgCtrHorizontal       (1 << 18)
/**
 * @nodoc 
 */
#define CATDlgCtrVertical         (1 << 19)
/**
 * @nodoc 
 */
#define CATDlgSldNoValue          (1 << 20)

// Label
//-------
/**
 * @nodoc 
 */
#define CATDlgLabRight            (1 << 18)
/**
 * @nodoc 
 */
#define CATDlgLabCenter           (1 << 19)
/**
 * @nodoc 
 */
#define CATDlgLabLeft             (1 << 20)
/**
 * @nodoc 
 */
#define CATDlgLabFramed           (1 << 21)

// Keyboard inputs
//----------------
/**
 * @nodoc 
 */
#define CATDlgEdtInhibateHistory  (1 << 14)
/**
 * @nodoc 
 */
#define CATDlgEdtPassword         (1 << 18)
/**
 * @nodoc 
 */
#define CATDlgEdtMultiline        (1 << 19)
/**
 * @nodoc 
 */
#define CATDlgEdtWrap             (1 << 20)
/**
 * @nodoc 
 */
#define CATDlgEdtInteger          (1 << 21)
/**
 * @nodoc 
 */
#define CATDlgEdtFloat            (1 << 22)
/**
 * @nodoc 
 */
#define CATDlgEdtAlphabetical     (1 << 23)
/**
 * @nodoc 
 */
#define CATDlgEdtNumerical        (1 << 24)
/**
 * @nodoc 
 */
#define CATDlgEdtAlphanumerical   (1 << 25)
/**
 * @nodoc 
 */
#define CATDlgEdtReadOnly         (1 << 26)
/**
 * @nodoc 
 */
#define CATDlgEdtDouble           CATDlgCtlDouble
/**
 * @nodoc 
 */
#define CATDlgEdtNoScrollBar      (1 << 27)
/**
 * @nodoc 
 */
#define CATDlgEdtStealFocus       (1 << 28)
/**
 * @nodoc 
 */
#define CATDlgEdtNoCR             (1 << 29)

// CAUTION. RESERVED              (1 << 30)

// Check and RadioButton
//------------------------
/**
 * @nodoc 
 */
#define CATDlgLabLeftTEXT         (1 << 18)

// Combobox
//---------
/**
 * @nodoc 
 */
#define CATDlgCmbDropDown         (1 << 18)
/**
 * @nodoc 
 */
#define CATDlgCmbUpSort           (1 << 19)
/**
 * @nodoc 
 */
#define CATDlgCmbEntry            (1 << 20)
/**
 * @nodoc 
 */
#define CATDlgCmbOptionStyle      (1 << 21)
/**
 * @nodoc 
 */
#define CATDlgCmbDouble           CATDlgCtlDouble
/**
 * @nodoc 
 */
#define CATDlgCmbColor            (1 << 22)
/**
 * @nodoc 
 */
#define CATDlgCmbLineType         (1 << 23)
/**
 * @nodoc 
 */
#define CATDlgCmbBitmap           (1 << 24)

// Spinners
//---------
/**
 * @nodoc 
 */
#define CATDlgSpnEntry            (1 << 18)
/**
 * @nodoc 
 */
#define CATDlgSpnUserIncrement    (1 << 19)
/**
 * @nodoc 
 */
#define CATDlgSpnDouble           CATDlgCtlDouble

// Submenu
//--------
/**
 * @nodoc 
 */
#define CATDlgMnuHelp             (1 << 17)
/**
 * @nodoc 
 */
#define CATDlgMnuPinnable         (1 << 18)
/**
 * @nodoc 
 */
#define CATDlgMnuWorkBench        (1 << 19)

// CATDlgStdFile styles
//-------------------------------------------------

#ifdef _LANGUAGE_CPLUSPLUS

/**
 * Structure representing a rectangle.
 * @param x
 * @param y
 * @param dx
 * @param dy
 */
typedef struct {
  int x;
  int y;
  int dx;
  int dy;
} DRECT;

/**
 * Structure representing a position.
 * @param x
 * @param y
 */
typedef struct {
  int x;
  int y;
} DPOS;

/**
 * Key accelerator type.
 * <b>Role:</b> Quick access to a command using a keystroke combination.
 */
typedef unsigned long CATDlgAccelerator;

// Some Utilities
//---------------
/**
 * @nodoc 
 * Converts a bitmap file to an RGB array; to bee freed  by delete []; rc = 0(OK), 1(not found), 2(invalid).
 */
ExportedByDI0PANV2 unsigned char * CATDlgBmp2Rgb ( const CATString& bmpName, int& nWidth, int& nHeight, int &rc);

/**
 * @nodoc 
 * Sends a beep.
 */
ExportedByDI0PANV2 HRESULT CATDlgBeep ( CATDlgBeepType iType, const CATDialog * iDlg = 0);

#endif // _LANGUAGE_CPLUSPLUS

#endif
