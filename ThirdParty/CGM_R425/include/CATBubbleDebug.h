#ifndef CATBubbleDebug_H
#define CATBubbleDebug_H

// This class if for ODT Record Engine internal use.
// Please don't use it.

#include "DI0PANV2.h"

#ifdef DRIVER_WINDOWS

#include "CATDlgPortable.h"
#include "CATUnicodeString.h"

class CATDialog;

class ExportedByDI0PANV2 CATBubbleDebug
{
  
public :

  CATBubbleDebug(HWND hwndDocumentWindow);
  ~CATBubbleDebug();

  static CATBoolean IsVisualDebug();
  static CATBubbleDebug * GetInstance();
  static void DeleteInstance();

  // methodes directes pour le debug,
  void DrawBubbleDebug(HWND hwndDocumentWindow,CATUnicodeString s,CATBoolean SetToLastposition=0,int timer=2000,int posX=-1,int posY=-1);
  void DrawMouseDebug(HWND hwndDocumentWindow,int posX=-1,int posY=-1);
  
private :

  void Draw();
  void SetCurrentDialog( HWND hwndDocumentWindow);
  void SetPosition(int x, int y);
  void GetLastPosition(int &x, int &y);
  void MoveTheWindow(int x, int y);
  void SetText(CATUnicodeString text);
  CATUnicodeString GetText();
  void ShowMouseOnly();
  void SetVisibility(int);
  void Set(HWND hwndDocumentWindow,CATUnicodeString text);

  static CATBubbleDebug * _Bubble;
  int _Type;
  int _Width;
  int _Height;
  int _CursorSizeX;
  int _CursorSizeY;
  static int _LastPositionX;
  static int _LastPositionY;
  int _PositionX;
  int _PositionY;
  int _ShowMouseOnly;
  CATUnicodeString _Text;
  HDC _hMemDC;
  HWND _Window;

  void Draw( HDC iDC );
  static LRESULT WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
  LRESULT myWndProc(UINT message, WPARAM wParam, LPARAM lParam);

  static CATBoolean _showBubbles;
};

#endif
#endif
