#include "VE0FONT.h"
#ifndef CATOpenTypeFont_H
#define CATOpenTypeFont_H
//
// Copyright 3dPLM (Dassault Systemes) 2004
//----------------------------------------------------------------
// Abstract : OpenType Font: Adobe fonts
// this class is responsible for rendering OpenType Fonts with TTF oultines
// as well as opentype fonts with Type2 CFF outlines.
// so a normal TTF file can be viewed if it is renamed as .OTF,.otf
// ----------------------------------------------------------------
//  Usage :   Creation of 2D or 3D geometric texts
// ----------------------------------------------------------------
//  Inheritance : CATOpenTypeFont
//                  CATFont
// ----------------------------------------------------------------
// responsible : ETS
// ----------------------------------------------------------------

#include "CATOutlineFont.h"
#include "CATListPV.h"
#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATI18NTypes.h"
#include "SGInfra.h"
#include "CATOpenTypeTables.h"

class CATOpenTypeGlyph;

struct OTFMetricsStruct
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

// this structure is only for CIDKeyed fonts
// as many font dicts are there that many of such objects 
// have to be initiallized
// some values which we need to put here
// but are not using all except for the widths for now
class PrivateDICT
{
public:
  int defaultWidth;
  int nominalWidth;
  unsigned char **_pLocalSubrArray;   // this array is the local subroutines per font
  int      *_pLocalSubrSizeArray;
  unsigned int  _localSubrCount;
  int _subrs;      // local subroutine offset
  int _stdHW;
  int _stdVW;

  PrivateDICT()
  {
    defaultWidth = 0;
    nominalWidth = 0;
	_pLocalSubrArray = NULL;
	_pLocalSubrSizeArray = NULL;
	_localSubrCount = 0;
	_subrs = 0;
    _stdHW = -1;
    _stdVW = -1;

  }

  ~PrivateDICT()
  {
    defaultWidth = 0;
    nominalWidth = 0;
    if ( (_localSubrCount > 0 ) && (NULL != _pLocalSubrArray) )
    {
      int cntr = 0;
      for (cntr = 0; cntr < _localSubrCount; cntr++)
      {
        CATSysDeleteTab(_pLocalSubrArray[cntr]);
      }
    }
    CATSysDeleteTab(_pLocalSubrSizeArray);
    CATSysDeleteTab(_pLocalSubrArray);

    _localSubrCount = 0;
    _subrs = 0;
    _stdHW = -1;
    _stdVW = -1;

  }

};

// this structure is only for CIDKeyed fonts
// as many font dicts are there that many of such objects 
// have to be initiallized
class FontDICT
{
public :
  // some values which we need to put here
  // but are not using all except for privateDICT for now
  unsigned int privateDICTOffset ;   // this is the private dict offset for each of these FONT DICTS
  int          privateDictSize;      // the size of this dict

  FontDICT()
  {
    privateDICTOffset = 0;
    privateDictSize   = 0;
  }

};


// the below structure is meant for OTF fonts with CFF data
// ************************************************************************
// ************************************************************************
// OTF files with CFF font data can contain more than one font
// This structure should be used to hold the information for each
// font in the file. The number of fonts are determined by the variable
// _numberOfCFFFonts in the class CATOpenTypeFont
// ************************************************************************
class CATCFFFontInfo
{
public:
                                // using SID the actual string can
                                // be obtained from the string Index table
  unsigned short version;       // this is an SID
  unsigned short Notice;        // this is an SID
  unsigned short Copyright;     // this is an SID
  unsigned short FullName;      // this is an SID
  unsigned short FamilyName;    // this is an SID
  unsigned short Weight;        // this is an SID

  CATBoolean isFixedPitch;          // boolean
  float      ItalicAngle;           // number
  float      UnderlinePosition;     // number
  float      UnderlineThickness;    // number
  short      PaintType;             // number
  short      CharstringType;        // number

  float      FontMatrix[6];         // array
  float      FontBBox[4];           // array;

  long       UniqueID;              // number
  float      StrokeWidth;           // number
  float*     XUID;                  // array will be init later

  unsigned int       charset;                // charset offset
  unsigned int       Encoding;               // encoding offset
  unsigned int       CharStrings;            // CharStrings offset

  unsigned short*  CharSetArray;    // SID array from charset offset

  int                PrivateDictSize;         
  unsigned int       PrivateDictOffset;

  int       SyntheticBase;          // synthetic base font index

  unsigned int       FDArray;                // FDArray offset
  unsigned int       FDSelect;               // FDSelect offset

  unsigned char* FDSelectorArray;

  int       FontDictCount;          // number of font DICTS - only CIDKeyed fonts

  FontDICT      *FontDictTable;     // the FD table
  PrivateDICT   *privateDictTable;  // the private DICTs for each FD
  
  unsigned short PostScript;        // SID, embedded PS language code

  unsigned char **cffCharStringArray;   // this array is the complete CharStrings for all the glyphs in this font
                                        // this is font specific so we put it here.
  int *charStringsSizeTable;
  unsigned short charStringCount;

  char useStandardEncoding;
  

  // these following members are private dictionary values for this font
  // using only the members needed for now.
  
  int StdHW;
  int StdVW;

  int Subrs;      // local subroutine offset

  int defaultWidthX;

  int nominalWidthX;

  unsigned char **localSubrArray;   // this array is the local subroutines per font
  int            *localSubrSizeArray;
  unsigned int    localSubrCount;

  // some more are present but it is not needed to currently support them
 
  // here below we initialize all the default values for the above
  // variables.

  CATCFFFontInfo()
  {
    isFixedPitch          = 0;      
    ItalicAngle           = 0.f;       
    UnderlinePosition     = -100.f; 
    UnderlineThickness    = 50.f;
    PaintType             = 0;         
    CharstringType        = 2;    

    FontMatrix[0]         = 0.001f;     
    FontMatrix[1]         = 0.f;     
    FontMatrix[2]         = 0.f;     
    FontMatrix[3]         = 0.001f;     
    FontMatrix[4]         = 0.f;     
    FontMatrix[5]         = 0.f;     
    
    FontBBox[0]           = 0.f;       
    FontBBox[1]           = 0.f;       
    FontBBox[2]           = 0.f;
    FontBBox[3]           = 0.f;

    UniqueID              = -1;          
    StrokeWidth           = 0.f;       
    XUID                  = NULL;              

    charset               = 0;           
    Encoding              = 0;           
    CharStrings           = 0;       

    PrivateDictSize       = -1;   
    PrivateDictOffset     = 0;

    SyntheticBase         = -1;
    PostScript            = (unsigned short)-1;
    
    FDArray               = (unsigned int)-1;
    FDSelect              = (unsigned int)-1;

    FDSelectorArray       = NULL;

    FontDictCount         = 0;

    FontDictTable         = NULL;
    privateDictTable      = NULL;

    version               = (unsigned short)-1;   
    Notice                = (unsigned short)-1;    
    Copyright             = (unsigned short)-1;
    FullName              = (unsigned short)-1;
    FamilyName            = (unsigned short)-1;
    Weight                = (unsigned short)-1;

    cffCharStringArray    = NULL; 
    charStringsSizeTable  = NULL;

    CharSetArray          = NULL;

    charStringCount       = 0;

    useStandardEncoding  = 0;

    // private dict members
    StdHW                 = -1;
    StdVW                 = -1;

    Subrs                 = 0;   

    defaultWidthX         = 0;
    nominalWidthX         = 0;

    localSubrArray        = NULL;   
    localSubrSizeArray    = NULL;

    localSubrCount        = 0;

  // all -1 defaults mean that they dont have an initial value and
  // hence must not be considered while being used

  }
  ~CATCFFFontInfo()
  {
    if(XUID)
    {
     delete XUID;
     XUID =  NULL;
    }

    if(NULL != cffCharStringArray)
    {
      int i = 0;
      for(i = 0 ; i < charStringCount; i ++ )
      {
        if(cffCharStringArray[i])
          delete [] cffCharStringArray[i];
      }
      delete [] cffCharStringArray;
      cffCharStringArray = NULL;
    }

    if(NULL != charStringsSizeTable)
    {
      delete [] charStringsSizeTable;
      charStringsSizeTable = NULL;
    }
    
    if(NULL != localSubrArray)
     {
       unsigned int i = 0;
       for(i = 0 ; i < localSubrCount; i ++ )
       {
         if(localSubrArray[i])
           delete [] localSubrArray[i];
       }
       delete [] localSubrArray;
       localSubrArray = NULL;
       localSubrCount = 0;
     }

    if(NULL != localSubrSizeArray)
    {
      delete [] localSubrSizeArray;
      localSubrSizeArray = NULL;
    }
    if( NULL != FontDictTable)
    {
      delete [] FontDictTable;
      FontDictTable = NULL;
    }
    if( NULL != privateDictTable)
    {
      delete [] privateDictTable;
      privateDictTable = NULL;
    }

    if(NULL != CharSetArray)
      delete CharSetArray;
    CharSetArray = NULL;

    if(NULL != FDSelectorArray)
      delete [] FDSelectorArray;
    FDSelectorArray = NULL;
  }
 
};
// ************************************************************************

//YWG-------------------------------------------------------------------------
struct KerningTable
{
	int _glyphL;
	int _glyphR;
	int _kernValue;
};

//// struct for storing GPOS x and y positioning.
//struct GPOSInfo
//{
//  int xAdj;
//  int yAdj;
//
//  GPOSInfo()
//  {
//    xAdj = 0;
//    yAdj = 0;
//  }
//  // to add any other type of info
//};

//-------------------------------------------------------------------------
struct EnvOpenTypeFontHeaderType
{
   char* _OTFFamilyName; // _OTFFamilyName example: "Helvetica Narrow" NULL if not initialized
};

struct EnvOpenTypeFontGeneralInformationType
{
   int _EnvOutlineFontGenInfoIndex;    // index into CATOutlineFont::sEnvOutlineFontGenInfo
   EnvOpenTypeFontHeaderType* _Header; // NULL if not filled 
};

//--------------------------------------------------------------------------   

typedef struct
{
   unsigned short pt_code;
   float          x;
   float          y;
} OTFGlyphContourPoint;

// pt_code
// the below defines are neaded for OTF files with TTF outlines
//************************************************/

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

//************************************************/


//--------------------------------------------------------------------------   
class ExportedBySGInfra CATOpenTypeFont : public CATOutlineFont
{
   CATDeclareClass_Deprec;

   public:

   // constructors
      CATOpenTypeFont();
      CATOpenTypeFont(const int iFontIndex);

   // Destructor
      virtual ~CATOpenTypeFont();

   // Initialize static data
      static void sInitializeOpenTypeStaticData();
   // Reset static data
      static void sResetOpenTypeEnvironment();

   // Compute the environment TrueType font information
	  static void sComputeOpenTypeFontGeneralInformation();

	/** @deprecated */  
    // +++ AZX - Jan 07 - R18 Highlight - TTF Versioning
    // function for getting font pointer to render TTF text using OTF class
    static CATFont* sGetOTFForTTF(const int iFontIndex);
    // --- AZX - Jan 07 - R18 Highlight - TTF Versioning

   // Font Data
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
      CATOpenTypeGlyph * GetGlyph(CATUC2Bytes iCharCode);
      //TUV 28 Jul 2008 IR 617113
      // If this open type font is stand along, font face offset will be zero
      // If this open type font belongs to True type collection font, font offset will
      // hold the value of offset for the offset table 
      CATULONG32 GetFontFaceOffset();

      int *  _ctx;

      int _cjkFontHeight;
      int _cjkUnix;


      int _otfCFFCount;

      int _keyOTF;  // 0 : OTF with TTF outlines, 1 : OTF with CFF outlines

      int _isCIDKeyed;

      CATULONG32 _cffTableOffset;

      CATCFFFontInfo *CFFFontInfo; // this variable is used in case
                                   // of OTF files with CFF font info
                                   // currently we only support the first font
                                   // in the CFF table. If we plan to support
                                   // multiple fonts in the same file then
                                   // we must allocate as many such structures
                                   // as there are fonts in the CFF table.

      int _cffFontIndex;           // this value is the index of the font
                                   // that you want to use. Since OTF Cff files
                                   // can have more than one font.
                                   
                                   // to choose the font use the _otfCFFCount
                                   // and iterate through the _cffFontNamesList
                                   
      CATString *_cffFontNamesList; // the names of the fonts inside this file.

      CATString *_cffStringIndexTable;  // the names of the glyphs are in this array


      unsigned char **_globalSubrArray;   // this array is the global subroutines in this font
      int            *_globalSubrSizeArray;
      unsigned int    _globalSubrCount;


      char _useStandardEncoding;
    
      CATBoolean _isPair;         // This is used to determine if GPOS info is for single glyph or pair

public:

     static void readShort(unsigned char*,int, void*);
     static void readLong(unsigned char*,int, void *);
     static void readThreeBytes(unsigned char*,int,void *);
     static char* readNibble(unsigned char);

public:


      HRESULT GetFontMetrics(FILE *ipFile ,OTFMetricsStruct &oMetrics);

      // this function returns a list of polygons (triangles) in order to 
      // display the text in polygon mode. The CAT2DGeomTextTriPrimitiveList
      // struct is declared in CAT2DGeomTextStructures.h. To fill it ref. to 
      // CATTriPrimGlyph::Show2DGlyph(). The transformation of polygons is done
      // in the caller class.
      HRESULT GetTextPolygon(CATUnicodeString iText,CAT2DGeomTextAttributeSet &iGeomAttSet,CAT2DGeomTextTriPrimitiveList & oTextPolygons);

      // this function returns a list of polyLines in order to 
      // display the text in line mode using The CAT2DGeomTextPolylineList struct
      
      HRESULT GetTextPolyLine(CATUnicodeString iText,CAT2DGeomTextAttributeSet &iGeomAttSet,CAT2DGeomTextPolylineList & oTextPolyLine);
      //TUV 28 Jul 2008 IR 617113
      CATOpenTypeFont* GetAssociatedFontForCodeChar(CATUC2Bytes iCharCode,int& oGlyphIndex);
      CATOpenTypeFont* GetAssociatedFontForCodeChar(CATListValCATUnicodeString& iofontSearchList,int& ioSearchIndex,CATUC2Bytes iCharCode,int& oGlyphIndex); // SegoeUI Issue 18aug09
      CATOpenTypeFont* GetFontPtrForName(CATListValCATUnicodeString& iofontSearchList,const CATUnicodeString& associatedFontName);

      // use this function to fill the _otfCFFCount variable and also to init
      // the CFFFontInfo member variable to that number of fonts
      // and to init all the values in it.

      HRESULT InitOpenTypeCFFFonts(FILE *);  // this function inits all the CFF related stuff.
      HRESULT CreateCFFCharStrings(FILE *);  // function to populate the glyph charstrings
      HRESULT ReadPrivateDictData(FILE *);   // read the priv dict for CFF Fonts 
      HRESULT ReadPrivateDictDataForCIDFonts(FILE *ipFile); // read the priv dict(s) for CID Keyed CFF Fonts 
      HRESULT CreateCIDKeyedCharStrings(FILE *); // interpret CIDKeyed fonts and read each Priv Dict


      HRESULT GetGPOSInfo(CATUC2Bytes iLeftCharCode, CATUC2Bytes iRightCharCode,GPOSInfo& oGPOSL, GPOSInfo& oGPOSR, const CATBoolean& isComplexScript=FALSE);

	  HRESULT GetGDEFInfo(CATUC2Bytes iLeftCharCode, char& oCh);

      char *GetCharScript(CATUC2Bytes iCharCode);

      CATMathPoint2D GetDistanceForGlyph(CATUnicodeString i_lastString,
                                         CATOpenTypeFont *ipNextFont, CAT2DGeomTextAttributeSet & iGeomAttSet );
//--------------------------------------------------------------------------
      static int isTablePresent(FILE * stream, char * tabTag);

     // static HRESULT GetTableEntry(FILE * stream, char * tabTag, unsigned long & tabOffset, unsigned long & tabLength);


      // Read, from the font file, the diffrent tables (cf. ReadTableData method)
      // and, if possible replace the ReadTableData code.
      static HRESULT ReadNameTable(FILE * ipFile,
                                     CATUnicodeString &oFamilyName,
                                     CATUnicodeString &oSubfamilyName,
                                     CATUnicodeString &oFontIdentifier,
                                     CATUnicodeString &oFullName,
                                     CATUnicodeString &oFaceName,
                                     const CATULONG32 iFontFaceOffset = 0);

      static HRESULT ReadPostTable(FILE * ipFile,
                                     int &oItalicAngle,
                                     int &oUnderlinePosition,
                                     int &oUnderlineThickness,
                                     int &oIsFixedPitch,
                                     const CATULONG32 iFontFaceOffset = 0);

      static HRESULT ReadOS2Table(FILE * ipFile,
                                     int &oWeightClass,
                                     int &oWidthClass,
                                     CATULONG32 *oUCCharRange,
                                     const CATULONG32 iFontFaceOffset = 0);
	  

      //static HRESULT GetGlyphIndex(FILE *ipFile,unsigned short ic,int &oIndex); 

      static HRESULT ReadKernTable(FILE * ipFile, CATListPV & oKerningList,const CATULONG32 iFontFaceOffset=0);//YWG
      int GetKerningValue(CATUC2Bytes iLeftCharCode, CATUC2Bytes iRightCharCode);//YWG
      

   // Read, from the font file, its OTFFamilyName, 
   // isFixedPitch, Weight, Width, FullName, FontName and ItalicAngle
      static HRESULT ReadTableData(int iEnvOpenTypeFontGenInfoIndex);

      // CHECK - ETS

	 // TUV 16 Apr 10 HMA:TTC IR 047870
	  CATBoolean CheckIfAllCharactersPresent(int nCharCount,const unsigned short* pString);

   // Environment Type 1 font count
      static int sEnvOpenTypeFontCount;

   // General information about OpenType fonts (effective length is sEnvOpenTypeFontCount after filling)
      static EnvOpenTypeFontGeneralInformationType* sEnvOpenTypeFontGenInfo;

   // Flag to indicate if sEnvOpenTypeFontGenInfo has been filled
      static int sEnvOpenTypeFontGenInfoFilled;

      // +++ AZX - Jan 07 - R18 Highlight - TTF Versioning
      // array for holding OTF for TTF font pointers 
      static CATOpenTypeFont** _spOTFForTTFPointers; 
      static int _sNbFonts;
      // --- AZX - Jan 07 - R18 Highlight - TTF Versioning

   // Font index into sEnvOpenTypeFontGenInfo
      short _EnvOpenTypeFontGenInfoIndex;

      CATListPV _glyphList;
    
      CATListPV _kerningList;//YWG

			CATOpenTypeFont* GetAssociatedFontForCodeCharInternal(CATListValCATUnicodeString& iofontSearchList, int& ioSearchIndex, CATUC2Bytes iCharCode, int& oGlyphIndex);
      // Copies all the glyph index values
      // Caller is responsible for allocation and deallocation of the memory.
      HRESULT GetAllGlyphIndices(int* opIndices, unsigned short iStartChar = 0, unsigned short iEndChar = 65535);

   private:

      // helper function for GPOS
      int isInCoverage(FILE* ipFile,unsigned int iCoverageTableOffset,CATUC2Bytes iLeftCharCode, int & oGlyphIndex);

      CATOpenTypeFont* GetFontPtrFromValueString(CATListValCATUnicodeString& iofontSearchList,const CATUnicodeString& valueString, CATUC2Bytes iCharCode,int& oGlyphIndex); // SegoeUI Issue 18aug09
      CATUnicodeString GetRegSimulationFilePath();
      void GetListOfCommaSeparatedStrings(CATListValCATUnicodeString& oCommaSeparatedList,const CATUnicodeString iString);
      CATOpenTypeFont* GetSameStyleFont(CATOpenTypeFont* pFont,
                                        int oBold,int oItalic,
                                        CATUC2Bytes iCharCode,
                                        int& oStyledGlyphIndex);

      CATUnicodeString  GetCommonString(CATUnicodeString & iStrFamilyName,CATUnicodeString & iStrFileName);
      CATOpenTypeFont* GetRequiredFontForStyle(CATUnicodeString & iStrFamilyName,
                                               CATUnicodeString & iStrCommonString,
                                               int oBoldRequired,int oItalicRequired,
                                               CATUC2Bytes iCharCode,
                                               int& oGlyphIndex);
      CATBoolean CheckFontForFamilyAndStyle (CATUnicodeString& iStrFamilyName,
                                             int i,
                                             int oBoldRequired,
                                             int oItalicRequired);
	  // TTE Support To look for the given CharCode in TTE files
	  CATOpenTypeFont* GetAssociatedTTEFont(CATUC2Bytes iCharCode,int& oGlyphIndex);
	  void GetAllAssociatedTTEFonts(CATListValCATUnicodeString& ioListOfTTE);
	  

      // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
      
      CATOpenTypeFont (const CATOpenTypeFont &);
      CATOpenTypeFont & operator= (const CATOpenTypeFont &);

			CATOpenTypeFont* GetFontPtrFromValueString(CATListValCATUnicodeString& iofontSearchList, const CATListValCATUnicodeString& valueListString, CATUC2Bytes iCharCode, int& oGlyphIndex);
public:
      // Return information about outline present in the OpenType Font
      // return value :
	  // 0 : if CFF table is absent  (TTF outline Font)
	  // 1 : if CFF table is present (CFF outline Font)
      int isCFFTablePresent();
      // Return information about composite glyph
      // @param oIsComposite equals: 
      //          - "1" if glyph is composite
      //          - "0" if not
      // @param oNbGlyph equals: 
      //          - "1", if glyph is not composite
      //          - number of glyph, if glyph is composite
      // @param oCompositeGlyphContourList
      //          - number of contour for each glyph
      HRESULT GetGlyphCompositeInfo(CATUC2Bytes iCharCode, int &oIsComposite, int &oNbGlyph, CATListOfInt &oCompositeGlyphContourList);
private:
	CATBoolean _bGPOSTableExists;
	CATBoolean _bGDEFExists; 
	CATBoolean _bKerningTabRead;

public:
	CATOpenTypeTables _openTypeTabs;
};
#endif 










