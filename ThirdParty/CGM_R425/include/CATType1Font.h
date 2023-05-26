#include "SGInfra.h"
#ifndef CATType1Font_H
#define CATType1Font_H
//
// CATIA CXR1 Framework VFW2
// Copyright Dassault Systemes 1996
//----------------------------------------------------------------
// Abstract : Type1 Font: Adobe fonts
// ----------------------------------------------------------------
//  Usage :   Creation of 2D or 3D geometric texts
// ----------------------------------------------------------------
//  Inheritance : CATType1Font
//                  CATPostScriptFont
//                    CATOutlineFont
//                      CATFont
// ----------------------------------------------------------------
//  Main Methods :
//               SetQuality
//               GetQuality
//               ResetQuality
//
//----------------------------------------------------------------------------
//       

#include "CATPostScriptFont.h"

class CATPostScriptGlyph;

#define STORED_MOST_COMMON_WIDTH_DIMENSION 12
#define COMPUTED_MOST_COMMON_WIDTH_DIMENSION 40

struct EnvType1FontHeaderType
{
short _InfPresent;      /* boolean. -1:not filled, 0:.inf not present,
                           1:.inf present */ 
char* _MSMenuName;      /* NULL if not filled */
};
struct EnvType1FontGeneralInformationType
{
int _EnvPostScriptFontGenInfoIndex; /* index into 
                                CATPostScriptFont::sEnvPostScriptFontGenInfo */
EnvType1FontHeaderType* _Header; /* NULL if not filled */
};

//--------------------------------------------------------------------------   
class ExportedBySGInfra CATType1Font : public CATPostScriptFont
{
  CATDeclareClass_Deprec;
 public:

// constructors
    CATType1Font();
    CATType1Font(const int iFontIndex);

// Destructor
    virtual ~CATType1Font();

// Initialize static data
    static void sInitializeType1StaticData();
// Reset static data
    static void sResetType1Environment();

//  Determine, for a PostScript character name, its unicode code and duplicate
//  unicode code (two unicode codes for the same  PostScript character name) 
    static void sDetermineUnicodeCode(char* iCharacterName,
                unsigned short& oUnicodeCode,          /* 0 if not defined */
                unsigned short& oDuplicateUnicodeCode);/* 0 if not defined */

// Mappings 
// CATFont2DMapping _BitmapMapping[BITMAP_MAPPING_TABLE_DIMENSION];
                                     /* dimension _BitmapVersionCount */
// Matrix
    float _Matrix[4]; /* a11, a12, a21, a22. aij: i=line, j=column 
                         in matrix european notation. Applied during 
                         descriptions interpretation for tesselation.
                         European notation means that the application of
                         this matrix to a vector will be the following:
                           +-      -+ +- -+   +-           -+
                           !a11  a12! ! x !   !a11*x + a12*y!
                           !a21  a22!*! y ! = !a21*x + a22*y!
                           +-      -+ +- -+   +-           -+
                         Note that the order of the matrix coefficients is
                         not the order in which there are in the PostScript
                         font /FontMatrix keyword: in the /FontMatrix keyword
                         the order correspond to american matrix notation. */
// Subrs
    int _SubrCount;
    unsigned int *_SubrLength;
    char **_Subr;

// Compute the environment Type 1 font information
   static void sComputeType1FontGeneralInformation();

//--------------------------------------------------------------------------
 private:
// Read an item from an ascii text
   static int sReadAsciiTextItem(char* iAsciiText, char* iItem, char* oLine);

// Read an item from a PFB text
   static int sReadPFBTextItem(char* iPFBText, char* iItem, char* oLine);

// Load the header of the main PostScript file (.pfa or .ps)
   static char* sLoadFileItselfHeader(char* iFilePath); /* the char*
                                                    returned must be 
                                                    desallocated (through free)
                                                    by the calling service */

// Load the header of a .pfb file
   static char* sLoadPFBHeader(char* iFilePath); /* the char*
                                                    returned must be 
                                                    desallocated (through free)
                                                    by the calling service */

// Initialize the static general information for the font given through the
// parameter 
   static void sInitializeType1StaticFontInformation(
                                                int iEnvType1FontGenInfoIndex);

// Read, from the font file header, the following items: FamilyName, FullName, 
// FontName, isFixedPitch, Weight and ItalicAngle  
   static void sReadFileItselfHeaderGeneralInformation(
                                   int iPFBFile, /* boolean. Necessary because
                                                    the PFB header is not in
                                                    ascii under unix */
                                   char* iText, /* header, set of lines */
                                   int iEnvType1FontGenInfoIndex
                                            );

// Read, from the current font header, the other informations
   void ReadFileItselfHeaderOtherInformation(
                                   int iPFBFile,/* boolean. Necessary because
                                                    the PFB header is not in
                                                    ascii under unix */
                                   char* iText, /* header, set of lines */
                        								   int* oNotAlreadySupportedWellKnownPostScriptEncoding,
                                                /* boolean. If the font encoding is a well-known
											                                    	   PostScript encoding, which is not the Standard
                                                   Encoding (which we support nowadays), we return
                                                   in this boolean that the encoding is not yet
                                                   implemented */ 
                                   char oEncoding[256][31],
                                                /* font encoding table. The calling service must
												                                       make it point to a char[256][31] */
                                   int* oEncodingLength);
                                                /* effective oEncoding table length */

// Read, from the .inf file, its PCLStrokeWeight, MSMenuName and CapHeight,
// if the .inf file exists
   static void sReadInfGeneralInformation(int iEnvType1FontGenInfoIndex);

// Read the private dictionary
   void ReadPrivateDictionary( char* iDecodedTable, int iTableLength);

// Update the CATFont _CharacterSet variable
    void UpdateCharacterSet();

// Compute the base stem width
    void ComputeBaseStemWidth();

// Compute the bitmap mappings
//    void ComputeBitmapMappings();

// Tesselate the whole font
    void TesselateWholeFont(int iUpdateBoundingBox);

// Read the encoding from an ascii text
    static int sReadAsciiTextEncoding(char* iAsciiText,
                                      int* oNotAlreadySupportedWellKnownPostScriptEncoding,
                                      char oEncoding[256][31],     
                                      int* oEncodingLength);

// Read the encoding from a PFB text
    static int sReadPFBTextEncoding(char* iPFBText,
                                    int* oNotAlreadySupportedWellKnownPostScriptEncoding,
                                    char oEncoding[256][31],     
                                    int* oEncodingLength);

// Environment Type 1 font count
static int sEnvType1FontCount;
// General information about Type 1 fonts (effective length is 
// sEnvType1FontCount after filling)
static EnvType1FontGeneralInformationType* sEnvType1FontGenInfo;
// Flag to indicate if sEnvType1FontGenInfo has been filled
static int sEnvType1FontGenInfoFilled;
// Font index into sEnvType1FontGenInfo
short _EnvType1FontGenInfoIndex;

// Language group
    short _LanguageGroup; /* 1: asian , 0:other */

// Stems dominant widths
    double _HorStemsStoredDominantWidth;   /* in character coordinates */
    double _VerStemsStoredDominantWidth;   /* before _Matrix application. */
    short  _HorStemsComputedDominantWidth; /* see Adobe Type 1 Font Format */
    short  _VerStemsComputedDominantWidth; /* page 42 */
    double _HorStemsStoredMostCommonWidth[STORED_MOST_COMMON_WIDTH_DIMENSION];
    short  _HorStemsStoredMostCommonWidthCount;
    double _VerStemsStoredMostCommonWidth[STORED_MOST_COMMON_WIDTH_DIMENSION];
    short  _VerStemsStoredMostCommonWidthCount;
    double _BaseStemWidth;
    static short sHorStemsComputedWidth
                    [COMPUTED_MOST_COMMON_WIDTH_DIMENSION];
    static short sHorStemsComputedFrequency
                    [COMPUTED_MOST_COMMON_WIDTH_DIMENSION];
    static short sHorStemsComputedWidthCount;
    static short sVerStemsComputedWidth
                    [COMPUTED_MOST_COMMON_WIDTH_DIMENSION];
    static short sVerStemsComputedFrequency
                    [COMPUTED_MOST_COMMON_WIDTH_DIMENSION];
    static short sVerStemsComputedWidthCount;

// Work font hints
//   static CATPostScriptFontHints* sWorkFontHints; 

// Blue values
    short _BlueValuesPairCount;
    short _BlueValues[14]; 
// Other blues
    short _OtherBlueValuesPairCount;
    short _OtherBlues[10];
// Family Blues
    short _FamilyBlueValuesPairCount;
    short _FamilyBlues[14];
// Family other blues
    short _FamilyOtherBlueValuesPairCount;
    short _FamilyOtherBlues[10];
// Blue scale
    double _BlueScale;
// Blue shift
    short _BlueShift;
// BlueFuzz
    short _BlueFuzz;    

//--------------------------------------------------------------------------

};

// CATType1Font_H
#endif 









