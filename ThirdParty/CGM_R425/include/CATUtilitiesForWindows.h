/**************************************************************************************************/
/**************************************************************************************************/
/*                                                                                                */
/*         WARNING - THIS FILE IS IDENTICAL BETWEEN V5 AND V6 - PLEASE KEEP IT IDENTICAL          */
/*                                                                                                */
/**************************************************************************************************/
/**************************************************************************************************/

#ifndef CATUtilitiesForWindows_H
#define CATUtilitiesForWindows_H

#include "DI0PANV2.h"

#include "CATDlgUtility.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

class IDataObject;

#ifdef DRIVER_WINDOWS

class CRect;

BOOL CATDlgIsAnEditor(HWND hW);
BOOL CATDlgIsACombo(HWND hW);
BOOL CATDlgIsASelectorList(HWND hW);
BOOL CATDlgIsAMultiList(HWND hW);
BOOL CATDlgIsMaximizedWithoutBorders();
void CATDlgClipOpaqueDescendants(HWND hAncestor, HWND hParent, CRect& interRect1, HDC hdc);
CATUnicodeString CATDlgGetWindowTitle(HWND hWnd);
ExportedByDI0PANV2 int CATGetNearestMonitorRect(CRect &rectIn, CRect &rectMon, int& numberOfMonitors, int useIntersectionRect =0);
ExportedByDI0PANV2 int IsWindowsVista();
ExportedByDI0PANV2 int IsWindows7();
ExportedByDI0PANV2 int IsWindows8();
ExportedByDI0PANV2 int IsWindows10();
ExportedByDI0PANV2 int GetWindows10Version();
ExportedByDI0PANV2 int IsAeroGlass();
ExportedByDI0PANV2 float GetDPIScalingFactor();
ExportedByDI0PANV2 int CATPutFilePathsIntoClipBoard(const CATListOfCATUnicodeString& iFilePaths); // for tst purposes.
ExportedByDI0PANV2 void* CreateCursorWnd(int bufsize, const unsigned char* iBuf);
ExportedByDI0PANV2 char* ClipboardFormatToString( CLIPFORMAT dwFormat, int& retCode);

#endif

ExportedByDI0PANV2 CATBoolean CATDlgShowVirtualKeyboard(CATBoolean show);
ExportedByDI0PANV2 int CATGetFilesFromDataObject(IDataObject* iDataObject,CATListOfCATUnicodeString& oFilePaths);
ExportedByDI0PANV2 HRESULT CATGetStringFromDataObject(IDataObject* iDataObject,CATUnicodeString& oString);

#endif
