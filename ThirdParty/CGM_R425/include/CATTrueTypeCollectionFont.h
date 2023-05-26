#ifndef CATTrueTypeCollectionFont_H
#define CATTrueTypeCollectionFont_H
//
// Copyright 3dPLM (Dassault Systemes) 2004
//----------------------------------------------------------------
// Abstract :True Type collection Font: Adobe fonts
// this class is responsible for rendering True type collection Fonts
// ----------------------------------------------------------------
//  Usage :   Creation of 2D or 3D geometric texts
// ----------------------------------------------------------------
//  Inheritance : CATOpenTypeFont
//                  CATFont
// ----------------------------------------------------------------
// responsible : TUV
// ----------------------------------------------------------------
#include "CATOpenTypeFont.h"
//#include "VE0FONT.h"
#include "SGInfra.h"
//--------------------------------------------------------------------------   
class ExportedBySGInfra CATTrueTypeCollectionFont : public CATOpenTypeFont
{
   CATDeclareClass_Deprec;
   public:
   // constructors
      CATTrueTypeCollectionFont();
      CATTrueTypeCollectionFont(const int iFontIndex,const int fontFaceIndex=0);

   // Destructor
      virtual ~CATTrueTypeCollectionFont();

      static int sGetEmbeddedFontCount(const char* ipFontPath);
      static CATULONG32 sGetFontOffset(const char* ipFontName,const char* ipFontPath);

private:
       int _FontFaceIndex;
      // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
      CATTrueTypeCollectionFont (const CATTrueTypeCollectionFont &);
      CATTrueTypeCollectionFont & operator= (const CATTrueTypeCollectionFont &);
};
#endif 
