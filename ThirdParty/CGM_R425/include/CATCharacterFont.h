#ifndef CATCharacterFont_H
#define CATCharacterFont_H
//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract:
//    Load X11 Font and Marker Font
//
//------------------------------------------------------------------------------
// Usage:    
//------------------------------------------------------------------------------
// Inheritance:
//      CATCharacterFont
//------------------------------------------------------------------------------
// Main methods:
//
//    Query
//       GetFontOffset
//       GetMarkerOffset
//       GetCharacterSize
//
//------------------------------------------------------------------------------

#include "SGInfra.h"

#if defined (_WINDOWS_SOURCE)
#include <wtypes.h>

#elif defined (_COCOA_SOURCE) 
#define VIS_CORE_TEXT
#if defined(_DARWIN_SOURCE)
  #ifndef __MAC_10_8 // version < 10.8
    // NCT : "interface" is used in IOHIDTypes.h but is redefined in IUnknown.h
    // We need to restore default interface meaning before including ApplicationServices.h and restore it again afterwards
    #ifdef interface
      #define ITF_BACKUP
      #undef interface
    #endif
    #include <ApplicationServices/ApplicationServices.h>
    #ifdef ITF_BACKUP
      #define interface struct
      #undef ITF_BACKUP
    #endif
  #else //__MAC_10_8                                                            
    // NCT/ODM : on OSX 10.8, SFNTLayoutTypes.h from CoreText redefines AnchorPoint type, which conflicts with CATAnchorPoint.h                                
    // Using __SFNTLAYOUTTYPES__ lets ignore SFNTLayoutTypes.h content and bypass issue                                                                        
    #define __SFNTLAYOUTTYPES__
    #ifdef interface
      #define ITF_BACKUP
      #undef interface
    #endif
    #include <CoreText/CoreText.h>
    #ifdef ITF_BACKUP
      #define interface struct
      #undef ITF_BACKUP
    #endif
  #endif //__MAC_10_8
#else // defined(_DARWIN_SOURCE)
  #ifdef __IPHONE_6_0
    // NCT : on iOS 6, SFNTLayoutTypes.h from CoreText redefines AnchorPoint type, which conflicts with CATAnchorPoint.h
    // Using __SFNTLAYOUTTYPES__ lets ignore SFNTLayoutTypes.h content and bypass issue
    #define __SFNTLAYOUTTYPES__
  #endif
  #include <CoreText/CoreText.h>
  #include <CoreFoundation/CoreFoundation.h>
#endif

#elif defined (_ANDROID_SOURCE)

// TODO

#elif defined (_LINUX_SOURCE) && defined (_GTK_SOURCE)

// TODO_GTK

#else
#include <Xm/Xm.h>
#endif

#include "CATUnicodeString.h"

#include "CATFreeType.h"
#include "CATMacForRtti.h"

#ifdef VISU_ENABLE_FREETYPE
class CATFreeTypeFactory;
class CATFreeTypeFace;
class CATFreeTypeFontFile;
#endif

class CATViewpoint;
class CATVizViewer;
void ExportedBySGInfra GetModelSizeOfAnnotation(CATUnicodeString *i_pString, CATViewpoint* i_pViewpoint, float& o_textWidth, float& o_textHeight);

class ExportedBySGInfra CATCharacterFont
{
   CATDeclareClass_Deprec;

public :
	enum {  MESSAGE_FONT=0,
			CAPTION_FONT=1,
			MESSAGE_FONT_BOLD=2,
			MESSAGE_FONT_ITALIC=3,
			MESSAGE_FONT_BOLD_ITALIC=4,
			NB_MAX_FONT = 5 };

#if defined (_WINDOWS_SOURCE) || defined (VIS_CORE_TEXT) || defined (_ANDROID_SOURCE) || defined (_NO_X11_SOURCE)
   CATCharacterFont ();
#else
   CATCharacterFont (Display *display = NULL);
#endif

   virtual void Destroy();

   int GetFontHeight (const int index);
   int GetFontOffset (const int index);
   int GetFontIndex  (const float ratio); // ratio = font_height/PixelFromModelRatio) 

   void GetStringSize (const CATUnicodeString &str, int *width, int *height, int *descent, const int index = 0);

   int GetDefaultHeight();

#if defined (_WINDOWS_SOURCE) || defined (VIS_CORE_TEXT) || defined (_ANDROID_SOURCE) || defined (_NO_X11_SOURCE)
  #ifdef _WINDOWS_SOURCE
   HFONT* _font;
   struct WindowsScreenDC
   {
     HDC _hdc;
     ~WindowsScreenDC();

     inline operator HDC ()
     {
       if (_hdc == NULL)
         _hdc = GetDC(NULL);
       return _hdc;
     }
   };

   static WindowsScreenDC s_screenDC;
  #elif defined (VIS_CORE_TEXT)
   HRESULT BuildFontFileFromCoreTextFont(CTFontRef ipCTfont);
   CFMutableArrayRef _fontArray;
  #elif defined (_LINUX_SOURCE) && defined (_GTK_SOURCE)
   // TODO_GTK
  #endif
   static unsigned int _currentFont;
   static unsigned int _currentHeight;
   static CATUnicodeString _currentFontName;
#else
  #ifdef VISU_ENABLE_FREETYPE
   static CATUnicodeString _currentFontName;
  #endif
   XFontStruct** fontStruct;
   Display *_display;
#endif

   int* _fontOffset;
   int _nb_font;
   int* _height;
   int* _descent;
   int* _leading;

#ifdef  VISU_ENABLE_FREETYPE
   void CreateFreeTypeFaces(CATUnicodeString const& iFontName);
   void DestroyFreeTypeFaces();

   CATFreeTypeFactory*	_freetypeFactory;
   CATFreeTypeFace**	_freetypeFace;
   static CATBoolean _sUseFreeType;
#endif

protected :
   ~CATCharacterFont(); //destructeur volontairement non virtuel pour eviter un appel a ~CATOGLCharacterFont depuis un mauvais thread.

private :
  
  HRESULT RetrieveFontMetrics(const char* iFontName, const unsigned int iFontStyle);
  
   int _defaultHeight[5];
};

#endif
