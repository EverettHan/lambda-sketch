
// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATDlgInclude.h"
#include "CATDlgUtility.h"
#include "DI0BUILD.h"

//---------------------------------------------------------------------------
// CATDialog rep types
//---------------------------------------------------------------------------
#define CATDLGNOTHING             0
#define CATDLGDOCUMENT            1
#define CATDLGDIALOG              2
#define CATDLGNOTIFY              3
#define CATDLGFILE                4
#define CATDLGCONTAINER          11
#define CATDLGSPLITTER           12
#define CATDLGTABCONTAINER       13
#define CATDLGTABPAGE            14
#define CATDLGFRAME              15
#define CATDLGICONBOX            16
#define CATDLGBLACKBOX           19
#define CATDLGTOOLBAR            21
#define CATDLGSTATUSBAR          22
#define CATDLGBARMENU            31
#define CATDLGSUBMENU            32
#define CATDLGCONTEXTUALMENU     33
#define CATDBCOMPONENT          100
#define CATDLGPUSHITEM          131
#define CATDLGRADIOITEM         132
#define CATDLGCHECKITEM         133
#define CATDLGSEPARATORITEM     134
#define CATDLGSEPARATOR         121
#define CATDLGLABEL             122
#define CATDLGPROGRESS          123
#define CATDLGPUSHBUTTON        101
#define CATDLGRADIOBUTTON       102
#define CATDLGCHECKBUTTON       103
#define CATDLGSELECTORLIST      104
#define CATDLGMULTILIST         105
#define CATDLGCOMBO             106
#define CATDLGEDITOR            107
#define CATDLGSPINNER           108
#define CATDLGSLIDER            109
#define CATDLGSCROLLBAR         110
#define CATDLGCUSTOMCOMPONENT   111
#define CATDLGLITTERALEDITOR    112

extern CATDlgStyle ExportedByDI0BUILD CastStyle (const CATString & strStyle);
//
extern CATString ExportedByDI0BUILD CastStyle (int repKind, CATDlgStyle valStyle);
//
extern Orientation ExportedByDI0BUILD CastOrientation (int layout);
//
extern CATDlgAttachment ExportedByDI0BUILD CastAttachment (int attachment, int position);
//
extern CATUnicodeChar ExportedByDI0BUILD CastMnemonic (const CATUnicodeString & valEditor);
//
extern CATDlgIconType ExportedByDI0BUILD CastIconType (int valCombo);
//
extern int ExportedByDI0BUILD CastDefaultButton (int valCombo);
//
extern CATDlgControl::CATDlgMagnitude ExportedByDI0BUILD CastMagnitude (const CATString & valValMagnitude);
//
extern CATDlgControl::CATDlgUnit ExportedByDI0BUILD CastUnit (const CATString & valValUnit);
//
extern int ExportedByDI0BUILD IsDLGContainer (int repKind);
//
extern int ExportedByDI0BUILD IsDLGComponent (int repKind);
//
extern CATString ExportedByDI0BUILD GetDLGString (int repKind);
//
extern CATString ExportedByDI0BUILD GetDLGIcon (int repKind);
//
extern CATString ExportedByDI0BUILD CastJustification (int valJustification);



