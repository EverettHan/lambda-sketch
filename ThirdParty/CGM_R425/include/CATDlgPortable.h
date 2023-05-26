
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef UIFPORT_H
#define UIFPORT_H

#ifdef DRIVER_MAINWIN
#include "CATPreMainwin.h"
#include "CATMainwin.h"
#endif

#include                               <stdio.h>
#include                               <stdlib.h>

#ifdef DRIVER_MOTIF
// SCA : Portage AIX 6.1
#include                                <Xm/Xm.h>
#include                                <X11/Xmu/Editres.h>
/** @linux fbq 2004-04-15.15:35:10 [Linux port - Widget not defined in Editres.h] **/
//#ifndef _LINUX_SOURCE
//#include                                <X11/Xmu/Editres.h>
//#include                                <Xm/Xm.h>
//#else
//#include                                <Xm/Xm.h>
//#include                                <X11/Xmu/Editres.h>
//#endif
#include                                <Xm/AtomMgr.h>
#include                                <Xm/ArrowB.h>
#include                                <Xm/CascadeB.h>
#include                                <Xm/DrawingA.h>
#include                                <Xm/Form.h>
#include                                <Xm/Frame.h>
#include                                <Xm/FileSB.h>
#include                                <Xm/Label.h>
#include                                <Xm/List.h>
#include                                <Xm/ListP.h>
#include                                <Xm/MainW.h>
#include                                <Xm/MessageB.h>
#include                                <Xm/PushB.h>
#include                                <Xm/PushBG.h>
#include                                <Xm/Protocols.h>
#include                                <Xm/RowColumn.h>
#include                                <Xm/RowColumnP.h>
#include                                <Xm/Scale.h>
#include                                <Xm/ScrollBar.h>
#include                                <Xm/ScrolledW.h>
#include                                <Xm/Separator.h>
#include                                <Xm/Text.h>
#include                                <Xm/ToggleB.h>
#endif
           
#if defined(DRIVER_WINDOWS) || defined(DRIVER_MAINWIN)
#if defined(DRIVER_MAINWIN)
#define WCHAR wchar_t
#endif
#if defined(_MFC_VER) && _MFC_VER>=0x0800
#include                                <windef.h>
#else
#include                                <afxwin.h>
#include                                <afxext.h>
#endif
#if defined(DRIVER_MAINWIN)
#undef WCHAR
#endif
// SCA : 64 bits
// #define size_t int
#include                                <stddef.h>
#endif

#ifdef DRIVER_PIDOBA
// CSA : Pour memcpy dans l_CATDlgList.
#include <string.h>
#endif

#endif
