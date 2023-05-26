#include "VE0FONT.h"
#ifndef CATTrueTypeFont_H
#define CATTrueTypeFont_H
//
// CATIA CXR1 Framework VFW2
// Copyright Dassault Systemes 1996
//----------------------------------------------------------------
// Abstract : TrueType Font: Adobe fonts
// ----------------------------------------------------------------
//  Usage :   Creation of 2D or 3D geometric texts
// ----------------------------------------------------------------
//  Inheritance : CATTrueTypeFont
//                  CATFont
// ----------------------------------------------------------------
//  Main Methods :
//
//----------------------------------------------------------------------------
// Limitations of the first implementation:
// ----------------------------------------
// Since (read page 20) "Microsoft strongly (in bold) recommends using a
// Unicode 'cmap' for all fonts", we will, in a first implementation, limit
// ourself to the support of TrueType fonts effectively containing this table.
// Since the Windows unicode table is obligatorily in the format number 4,
// we will suppose that a unicode sub-table in the format number 4 exists
// in the cmap table. We are aware that symbols fonts are liable not to work.
//    The day we will add the symbol fonts support, we will have to read,
// in the 'name' table, the NameRecords whose encoding is 0. 
//    We will output the family name, font name ... in the american language
// in a first implementation. Other languages name may be stored in the font
// ('name' table) which would be worth an advanced NLS implementation.       
//
// Suppositions that have been made. To check during tests:
// --------------------------------------------------------
//    We supposed that the PostScript name in the 'name' table was the
// font name provided by sGetFontOtherGeneralInformation. This might be proved
// to be wrong.

#include "CATOutlineFont.h"
#include "CATListPV.h"
#include "CATUnicodeString.h"
#include "CATI18NTypes.h"
#include "CATDataType.h"
#include "SGInfra.h"
#include "CATOpenTypeTables.h"

class CATTrueTypeGlyph;

struct TTFMetricsStruct
{
	int _height;
	int _ascent;
	int _descent;
	int _internalLeading;
	int _externalLeading;
	int _averageCharWidth;
	int _maxWidthChar;
	int _firstChar;
	int _lastChar;
	int _defaultChar;
	int _breakChar;
	int _italic;
	int _underlined;
	int _struckout;
	int _pitch;
	int _charSet;

};

//-------------------------------------------------------------------------
struct EnvTrueTypeFontHeaderType
{
   char* _TTFFamilyName; // _TTFFamilyName example: "Helvetica Narrow" NULL if not initialized
};

struct EnvTrueTypeFontGeneralInformationType
{
   int _EnvOutlineFontGenInfoIndex;    // index into CATOutlineFont::sEnvOutlineFontGenInfo
   EnvTrueTypeFontHeaderType* _Header; // NULL if not filled 
};

//--------------------------------------------------------------------------   
typedef struct
{
   unsigned short pt_code;
   float          x;
   float          y;
} GlyphContourPoint;

// pt_code
#define BEGIN_POLYLINE   0x0001
#define MID_POLYLINE     0x0002
#define END_POLYLINE     0x0004

#define BEGIN_SPLINE     0x0008
#define MID_SPLINE       0x0010
#define END_SPLINE       0x0020

#define BEGIN_CONTOUR    0x0040
#define END_CONTOUR      0x0080


#define TTF_QUAD_SPLINE         0x0100
#define TTF_CUBIC_SPLINE        0x0200
#define TTF_SIXCONTROL_SPLINE   0x0400
#define TTF_SEVCONTROL_SPLINE   0x0800
#define TTF_EIGCONTROL_SPLINE   0x1000
#define TTF_MULTICONTROL_SPLINE 0x2000


//--------------------------------------------------------------------------   
class ExportedBySGInfra CATTrueTypeFont : public CATOutlineFont
{
   CATDeclareClass_Deprec;

   public:

   // constructors
      CATTrueTypeFont();
      CATTrueTypeFont(const int iFontIndex);

   // Destructor
      virtual ~CATTrueTypeFont();

   // Initialize static data
      static void sInitializeTrueTypeStaticData();
   // Reset static data
      static void sResetTrueTypeEnvironment();

   // Compute the environment TrueType font information
	  static void sComputeTrueTypeFontGeneralInformation();

   // OpenGL Font Data
      CATUnicodeString _familyName;
      CATUnicodeString _fullName;
      CATUnicodeString _faceName;
      CATUnicodeString _subFamilyName;  
      CATUnicodeString _fontIdentifier; 
      
      int    _textVertexCount;
      int    _textContourCount;
      int*   _textContourPtsArray;

      int    _fontOffset;
      char * _initGlyph;
      float  _bitmapHeight;

      float  _heightScaleCoef;
      float  _widthScaleCoef;

      CATListPV GetGlyphOutline(CATUC2Bytes iCharCode);
      HRESULT GetGlyphMetrics(CATUC2Bytes iCharCode, int * oHeight, int * oWidth);
      CATTrueTypeGlyph * GetGlyph(CATUC2Bytes iCharCode);

      int *  _ctx;

      int _cjkFontHeight;
      int _cjkUnix;

#ifdef _WINDOWS_SOURCE
      LOGFONT _logfont;
      HDC    _hDC;
      HFONT  _hFont;

#endif

      HRESULT GetCharBoundingBox(FILE *ipFile ,unsigned short ic, int &oYmax, int &oYmin, int &oXmax, int &oXmin);
      HRESULT GetFontMetrics(FILE *ipFile ,TTFMetricsStruct &oMetrics);

      // this function returns a list of polygons (triangles) in order to 
      // display the text in polygon mode. The CAT2DGeomTextTriPrimitiveList
      // struct is declared in CAT2DGeomTextStructures.h. To fill it ref. to 
      // CATTriPrimGlyph::Show2DGlyph(). The transformation of polygons is done
      // in the caller class.
      HRESULT GetTextPolygon(CATUnicodeString iText,CAT2DGeomTextAttributeSet &iGeomAttSet,CAT2DGeomTextTriPrimitiveList & oTextPolygons);

      // this function returns a list of polyLines in order to 
      // display the text in line mode using The CAT2DGeomTextPolylineList struct
      
      HRESULT GetTextPolyLine(CATUnicodeString iText,CAT2DGeomTextAttributeSet &iGeomAttSet,CAT2DGeomTextPolylineList & oTextPolyLine);

      // Read, from the font file, the diffrent tables (cf. ReadTableData method)
      // and, if possible replace the ReadTableData code.
      static HRESULT ReadNameTable (FILE * ipFile,
                                      CATUnicodeString &oFamilyName,
                                      CATUnicodeString &oSubfamilyName,
                                      CATUnicodeString &oFontIdentifier,
                                      CATUnicodeString &oFullName,
                                      CATUnicodeString &oFaceName);

      static HRESULT ReadPostTable(FILE * ipFile,
                                    int &oItalicAngle,
										                int &oUnderlinePosition,
                                    int &oUnderlineThickness,
                                    int &oIsFixedPitch);

      static HRESULT ReadOS2Table(FILE * ipFile,
                                    int &oWeightClass,
                                    int &oWidthClass,
                                    CATULONG32 *oUCCharRange);
	  


   // Read, from the font file, its TTFFamilyName, 
   // isFixedPitch, Weight, Width, FullName, FontName and ItalicAngle
      static void ReadTableData(int iEnvTrueTypeFontGenInfoIndex);

   // Environment Type 1 font count
      static int sEnvTrueTypeFontCount;

   // General information about TrueType fonts (effective length is sEnvTrueTypeFontCount after filling)
      static EnvTrueTypeFontGeneralInformationType* sEnvTrueTypeFontGenInfo;

   // Flag to indicate if sEnvTrueTypeFontGenInfo has been filled
      static int sEnvTrueTypeFontGenInfoFilled;

   // Font index into sEnvTrueTypeFontGenInfo
      short _EnvTrueTypeFontGenInfoIndex;

      CATListPV _glyphList;
    
   private:
      // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
      CATTrueTypeFont (const CATTrueTypeFont &);
      CATTrueTypeFont & operator= (const CATTrueTypeFont &);

   public:
          CATOpenTypeTables _openTypeTabs;
};
#endif 









