#ifndef CATPostScriptFont_H
#define CATPostScriptFont_H
//
// CATIA CXR1 Framework VFW2
// Copyright Dassault Systemes 1996
//----------------------------------------------------------------
// Abstract : Type1 Font: Adobe fonts
// ----------------------------------------------------------------
//  Usage :   Creation of 2D or 3D geometric texts
// ----------------------------------------------------------------
//  Inheritance : CATPostScriptFont
//                  CATFont
// ----------------------------------------------------------------
//  Main Methods :
//               SetQuality
//               GetQuality
//               ResetQuality
//
//----------------------------------------------------------------------------
//       

#include "SGInfra.h"
#include "CATOutlineFont.h"
#include "CATFontMetricsStructures.h"

struct EnvPostScriptFontHeaderType
{
   short _AfmPresent;      /* boolean. -1:not filled, 0:.afm not present, 1:.afm present */ 
};

struct EnvPostScriptFontGeneralInformationType
{
   int _EnvOutlineFontGenInfoIndex; /* index into CATOutlineFont::sEnvOutlineFontGenInfo */
   EnvPostScriptFontHeaderType* _Header; /* NULL if not filled */
};

struct RelatedTrueTypeType
{
   int _Height;
   int _Width;
   int _Weight;  
   int _Italic; /* boolean */
   int _CharSet;
   int _PitchAndFamily;
   unsigned short* _FaceName; /* in unicode, 0 at the end */
   int _Unicode; /* 0: not unicode (symbols) 1: unicode */
};

struct RelatedTTFFullName
{
   // PostScript font file name (with suffix)
   char* _PostScriptFileName;
   // Related TrueType full name
   char* _TrueTypeFullName;
};

struct FontSpecificGlyphInfo
{
	char _name[200];          /* type 1 name */
	unsigned short _code; /* code in decimal */
  //For IR-019693 Visualization of characters <, > is KO for PS font "Universal Math1 BT". 
  int             _duplicateCode;
  int             _stdCode;
  int             _stdDuplicateCode;
  FontSpecificGlyphInfo()
  {
    _name[0]='\0';
    _code = 0;
    _duplicateCode = 0;
    _stdCode = 0;
    _stdDuplicateCode = 0;
  }
};

//--------------------------------------------------------------------------   
class ExportedBySGInfra CATPostScriptFont : public CATOutlineFont
{
   public:
   
      CATPostScriptFont();
      CATPostScriptFont(const int iFontIndex);
      virtual ~CATPostScriptFont();
      
      // Initialize static data
      static void sInitializePostScriptStaticData();
      // Reset static data
      static void sResetPostScriptEnvironment();
      
      // Get PostScript font information
      // Note that we prefer to output these informations through This method instead
      // of the sGetFontOtherGeneralInformation method because the purpose of the
      // sGetFontOtherGeneralInformation is to display the tab. It loads information
      // in memory, whether the font is loaded or not. Information which is clearly
      // made to be used to draw texts should not be loaded for the occasion of the 
      // tab generation. This justify this choice.
      void Get (int& oUnderlinePosition, /* in font coordinate system. To use
                                         this value to create an underline
                                         under a CAT2DGeometricTextGP, you
                                         must apply the following factor to
                                         this parameter, to obtain a
                                         coordinate in the
                                         CAT2DGeometricTextGP coordinate
                                         system:
                                         (Height in input to GP)/oCapHeight)
                                         If UnderlinePosition is not
                                         defined in the font, this
                                         parameter equals -10000 */
                int& oUnderlineThickness /* must be used the same way than
                                         oUnderlinePosition */
                                         );

      // Get postscript font metrics
      HRESULT GetPSFontMetrics(char *iFilePath, CATFontMetrics &oMetrics);
      
      // Is the .afm present
      int _AfmPresent; /* boolean */
      
      // Related TrueType font
      RelatedTrueTypeType* _RelatedTrueType; /* NULL if no related TrueType */
      
      //--------------------------------------------------------------------------
   protected:
      
      // some services for
      // CATType1Font::sComputeType1FontGeneralInformation and
      // CATCIDFont::sComputeCIDFontGeneralInformation
      static void sInitializeItalicAndBoldNames(char oItalicStringTable[12][8],char oBoldStringTable[18][8]);
      static void sModifyShortTabNameToOurTaste(char ioShortTabName[60]);
      static void sFillItalicInformation(EnvOutlineFontHeaderType* iOutlineHeader,int iItalicStringTableLength,char iItalicStringTable[12][8],char oLongItalicString[8],char oShortItalicString[8]);
      static void sFillBoldInformation(EnvOutlineFontHeaderType* iOutlineHeader,int iBoldStringTableLength,char iBoldStringTable[18][8],char oBoldString[8],char oShortBoldString[8]);
      static void sSupressItalicAndBoldStringFromLongTabName(char iLongItalicString[8],char iBoldString[8],char oLongTabName[100]);
      static void sSupressItalicAndBoldStringFromShortTabName(char iShortItalicString[8],char iShortBoldString[8],char oShortTabName[100]);
      static HRESULT sComputeWidthFromLongTabName(char iLongTabName[100],short &oWidth);
      
      // Environment PostScript font count
      static int sEnvPostScriptFontCount;
      // General information about PostScript fonts (effective length is 
      // sEnvPostScriptFontCount after filling)
      static EnvPostScriptFontGeneralInformationType* sEnvPostScriptFontGenInfo;
      
      // Initialize the static general information for the font given through the
      // parameter 
      static void sInitializePostScriptStaticFontInformation(
         int iEnvPostScriptFontGenInfoIndex);
      
      // Read, from the .afm file, its Weight, ItalicAngle, IsFixedPitch,
      // FontName, CapHeight, UnderlinePosition and UnderlineThickness
      // if the .afm file exists
      static void sReadAfmGeneralInformation(int iEnvPostScriptFontGenInfoIndex);
      
      // Read, from the .afm file, its UnderlinePosition and UnderlineThickness
      void ReadAfmOtherGeneralInformation();
      
      // Read, from the .afm file, the glyph bounding boxes
      virtual void ReadAfmOtherInformation();
      
      // Search for UnicodeCode for the CharacterName for FontSpecific  EncodingScheme
      void DetermineFontSpecificUnicodeCode(char* iCharacterName,
        unsigned short& oFontSpecificUnicodeCode,
        unsigned short& oFontSpecificDuplicateUnicodeCode,
        unsigned short& oStdUnicodeCode,
        unsigned short& oStdDuplicateUnicodeCode);


      // Return Encoding scheme i.e. FontSpecific or AdobeStandardEncoding
      void EncodingScheme(int& oFontSpecificEncoding);

      // Decrypt
      void sDecrypt(int& ioKey, unsigned char* iData, unsigned char* oData, int iLength);
      
      // Determine a glyph bounding box. This service looks into _GlyphBoundingBox
      //  int DetermineBoundingBox(unsigned short iKey,
      //                           short oBoundingBox[4]); /* must be allocated by
      //                                                       the calling service.
      //                                                       0:top, 1:bottom, 
      //                                                       2:right, 3:left */
      //                                                   /* the return value of the
      //                                                      function (int) is a 
      //                                                      boolean which indicates
      //                                                      if the unicode code has
      //                                                      been found */ 
      
      // Font index into sEnvPostScriptFontGenInfo
      short _EnvPostScriptFontGenInfoIndex;
      
      // Underline position and thickness
      short _UnderlinePosition;
      short _UnderlineThickness; 
      
      // Read an item from an ascii file
      static int sReadAsciiFileItem(char* iFilePath,char* iItem,char* oLine);
      
      // Related TrueType FullName table
      static int sRelatedTrueTypeFullNameCount;
      static RelatedTTFFullName* sRelatedTrueTypeFullName;
      
      //--------------------------------------------------------------------------
   private:
      
      // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
      CATPostScriptFont (const CATPostScriptFont &);
      CATPostScriptFont & operator= (const CATPostScriptFont &);
      
      int _FontSpecificGlyphCount;
      int _FontSpecificEncoding;
      FontSpecificGlyphInfo _FontSpecificGlyph[256];
};
// CATPostScriptFont_H
#endif 


