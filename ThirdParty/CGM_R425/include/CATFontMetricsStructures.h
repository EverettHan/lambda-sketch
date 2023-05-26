#ifndef CATFontMetricsStructures_H
#define CATFontMetricsStructures_H

// COPYRIGHT DASSAULT SYSTEMES 2005
/**  @CAA2Required  */  
//***********************************************************************************
//*  DON  T  DIRECTLY  INCLUDE  THIS  HEADER  IN  YOUR  APPLICATION  CODE.  IT  IS  *  
//*  REQUIRED  TO  BUILD  CAA  APPLICATIONS  BUT  IT  MAY  DISAPEAR  AT  ANY  TIME  *  
//***********************************************************************************

// ===================================================================
// This is an unmatured interface. The implementation is not finished.
// None of data in this interface is exposed yet in CAA2.
// ===================================================================

// ----------------------------------------------------------------
// Abstract : Structures to store and maintain font related metrics
// ----------------------------------------------------------------
//  Usage :   to be used by font metrics retrieval API
// ----------------------------------------------------------------
//   
//  Responsible : ETS (3DPLM)
//
// ----------------------------------------------------------------

// ----------------------------------------------------------------
//  structure to store Font Names
// ----------------------------------------------------------------

#include "CATI18NTypes.h"
#include "CATUnicodeString.h"

/** @nodoc */
struct CATFontNames
{
   CATUnicodeString FamillyName;
   CATUnicodeString SubFamillyName;
   CATUnicodeString FullName;
   CATUnicodeString PostScriptName;
   
   CATUnicodeString UniqueFontID;
   
   CATUnicodeString Version;
   
   CATUnicodeString TradeMark;
   CATUnicodeString CopyrightNotice;
};

// ----------------------------------------------------------------
//  structure to store Font Metrics
// ----------------------------------------------------------------
/** @nodoc */
struct CATFontMetrics
{
   enum CAT_FONT_WIDTH_CLASS
   {
      WIDTH_ULTRA_CONDENSED = 1,
      WIDTH_EXTRA_CONDENSED,
      WIDTH_CONDENSED,
      WIDTH_SEMI_CONDENSED,
      WIDTH_NORMAL,
      WIDTH_SEMI_EXPANDED,
      WIDTH_EXPANDED,
      WIDTH_EXTRA_EXPANDED,
      WIDTH_ULTRA_EXPANDED
   };
   
   enum CAT_FONT_WEIGHT_CLASS
   {
      WEIGHT_THIN        = 100,
      WEIGHT_ULTRA_LIGHT = 200,
      WEIGHT_LIGHT       = 300,
      WEIGHT_NORMAL      = 400,
      WEIGHT_MEDIUM      = 500,	
      WEIGHT_SEMI_BOLD   = 600,
      WEIGHT_BOLD        = 700,
      WEIGHT_ULTRA_BOLD  = 800,
      WEIGHT_BLACK       = 900
   };

   int WidthClass;
   int WeightClass;
   
   int FirstCharIndex;
   int LastCharIndex;
   
   int Ascent;
   int Descent;
   
   int CapHeight;
   
   int StemV;

   unsigned short WALength; // Length of WidthArray
   int *WidthArray;
   
   CATFontMetrics()
   {
      WidthClass  = WIDTH_NORMAL;
      WeightClass = WEIGHT_NORMAL;
      
      FirstCharIndex = 0x0020; // space character charcode
      LastCharIndex  = 0x0020; // space character charcode
      
      Ascent        = 0;
      Descent       = 0;

      CapHeight     = 0;
      
      StemV         = 80;

      WALength      = 0;
      WidthArray    = NULL; //0x0;
      
   }
   
   ~CATFontMetrics()
   {
      if(NULL != WidthArray)
      {
         delete [] WidthArray;
         WidthArray = NULL;
      }
   }
};

// ----------------------------------------------------------------
//  structure to store Horizontal Metrics of the Font
// ----------------------------------------------------------------
/** @nodoc */
struct CATFontHorHeader
{
   unsigned short maxAdvanceWidth;
   short minLSB;
   short minRSB;
   short xMaxExtent;
   
   CATFontHorHeader()
   {
      maxAdvanceWidth = 0;
      minLSB          = 0;
      minRSB          = 0;
      xMaxExtent      = 0;
   }
};

// ----------------------------------------------------------------
//  structure to store Horizontal Metrics of the glyph
// ----------------------------------------------------------------
/** @nodoc */
struct CATGlyphHorHeader
{
   unsigned short AdvanceWidth;
   short LSB;
   short RSB;
   short xExtent;
   
   CATGlyphHorHeader()
   {
      AdvanceWidth  = 0;
      LSB           = 0;
      RSB           = 0;
      xExtent       = 0;
   }
};

// ----------------------------------------------------------------
//  structure to store Vertical Metrics of the Font
// ----------------------------------------------------------------
/** @nodoc */
struct CATFontVerHeader
{
   unsigned short maxAdvanceHeight;
   short minTSB;
   short minBSB; 
   short yMaxExtent;
   
   CATFontVerHeader()
   {
      maxAdvanceHeight = 0;
      minTSB           = 0;
      minBSB           = 0;
      yMaxExtent       = 0;
   }
};

// ----------------------------------------------------------------
//  structure to store Vertical Metrics of the Glyph
// ----------------------------------------------------------------
/** @nodoc */
struct CATGlyphVerHeader
{
   unsigned short AdvanceHeight;
   short TSB;
   short BSB;     
   short yExtent;
   
   CATGlyphVerHeader()
   {
      AdvanceHeight = 0;
      TSB           = 0;
      BSB           = 0;
      yExtent       = 0;
   }
};

// ----------------------------------------------------------------
// structure containing Glyph information
// This could be control points or final polyline points
// Number of contours, bBox of glyph etc.
// ----------------------------------------------------------------
/** @nodoc */
struct CATGlyphInfo
{
   // will be defined later
};

// ----------------------------------------------------------------
// structure containing PANOSE data
// and panose related enums
// ----------------------------------------------------------------
/** @nodoc */
struct CATFontPanose
{
   enum PANOSE_FAMILY_KIND
   {
      PANOSE_FAMILY_KIND_ANY,
      PANOSE_FAMILY_KIND_NO_FIT,
      PANOSE_FAMILY_KIND_TEXT_AND_DISPLAY,
      PANOSE_FAMILY_KIND_SCRIPT,
      PANOSE_FAMILY_KIND_DECORATIVE,
      PANOSE_FAMILY_KIND_PICTORIAL
   };
   
   enum PANOSE_SERIF_STYLE
   {
      PANOSE_SERIF_STYLE_ANY,
      PANOSE_SERIF_STYLE_NO_FIT,
      PANOSE_SERIF_STYLE_COVE,
      PANOSE_SERIF_STYLE_OBTUSE_COVE,
      PANOSE_SERIF_STYLE_SQUARE_COVE,
      PANOSE_SERIF_STYLE_OBTUSE_SQUARE_COVE,
      PANOSE_SERIF_STYLE_SQUARE,
      PANOSE_SERIF_STYLE_THIN,
      PANOSE_SERIF_STYLE_BONE,
      PANOSE_SERIF_STYLE_EXAGGERATED,
      PANOSE_SERIF_STYLE_TRIANGLE,
      PANOSE_SERIF_STYLE_NORMAL_SANS,
      PANOSE_SERIF_STYLE_OBTUSE_SANS,
      PANOSE_SERIF_STYLE_PERP_SANS,
      PANOSE_SERIF_STYLE_FLARED,
      PANOSE_SERIF_STYLE_ROUNDED
   };
   
   enum PANOSE_WEIGHT
   {
      PANOSE_WEIGHT_ANY,
      PANOSE_WEIGHT_NO_FIT,
      PANOSE_WEIGHT_VERY_LIGHT,
      PANOSE_WEIGHT_LIGHT,
      PANOSE_WEIGHT_THIN,
      PANOSE_WEIGHT_BOOK,
      PANOSE_WEIGHT_MEDIUM,
      PANOSE_WEIGHT_DEMI,
      PANOSE_WEIGHT_BOLD,
      PANOSE_WEIGHT_HEAVY,
      PANOSE_WEIGHT_BLACK,
      PANOSE_WEIGHT_NORD
   };
   
   enum PANOSE_PROPORTION
   {
      PANOSE_PROPORTION_ANY,
      PANOSE_PROPORTION_NO_FIT,
      PANOSE_PROPORTION_OLD_STYLE,
      PANOSE_PROPORTION_MODERN,
      PANOSE_PROPORTION_EVEN_WIDTH,
      PANOSE_PROPORTION_EXPANDED,
      PANOSE_PROPORTION_CONDENSED,
      PANOSE_PROPORTION_VERY_EXPANDED,
      PANOSE_PROPORTION_VERY_CONDENSED,
      PANOSE_PROPORTION_MONOSPACED
   };
   
   enum PANOSE_CONTRAST
   {
      PANOSE_CONTRAST_ANY,
      PANOSE_CONTRAST_NO_FIT,
      PANOSE_CONTRAST_NONE,
      PANOSE_CONTRAST_VERY_LOW,
      PANOSE_CONTRAST_LOW,
      PANOSE_CONTRAST_MEDIUM_LOW,
      PANOSE_CONTRAST_MEDIUM,
      PANOSE_CONTRAST_MEDIUM_HIGH,
      PANOSE_CONTRAST_HIGH,
      PANOSE_CONTRAST_VERY_HIGH
   };
   
   enum PANOSE_STROKE_VARIATION
   {
      PANOSE_STROKE_VARIATION_ANY,
      PANOSE_STROKE_VARIATION_NO_FIT,
      PANOSE_STROKE_VARIATION_GRADUAL_DIAGONAL,
      PANOSE_STROKE_VARIATION_GRADUAL_TRANSITIONAL,
      PANOSE_STROKE_VARIATION_GRADUAL_VERTICAL,
      PANOSE_STROKE_VARIATION_GRADUAL_HORIZONTAL,
      PANOSE_STROKE_VARIATION_RAPID_VERTICAL,
      PANOSE_STROKE_VARIATION_RAPID_HORIZONTAL,
      PANOSE_STROKE_VARIATION_INSTANT_VERTICAL
   };
   
   enum PANOSE_ARM_STYLE
   {
      PANOSE_ARM_STYLE_ANY,
      PANOSE_ARM_STYLE_NO_FIT,
      PANOSE_ARM_STYLE_STRAIGHT_ARMS_HORIZONTAL,
      PANOSE_ARM_STYLE_STRAIGHT_ARMS_WEDGE,
      PANOSE_ARM_STYLE_STRAIGHT_ARMS_VERTICAL,
      PANOSE_ARM_STYLE_STRAIGHT_ARMS_SINGLE_SERIF,
      PANOSE_ARM_STYLE_STRAIGHT_ARMS_DOUBLE_SERIF,
      PANOSE_ARM_STYLE_NONSTRAIGHT_ARMS_HORIZONTAL,
      PANOSE_ARM_STYLE_NONSTRAIGHT_ARMS_WEDGE,
      PANOSE_ARM_STYLE_NONSTRAIGHT_ARMS_VERTICAL,
      PANOSE_ARM_STYLE_NONSTRAIGHT_ARMS_SINGLE_SERIF,
      PANOSE_ARM_STYLE_NONSTRAIGHT_ARMS_DOUBLE_SERIF
   };
   
   enum PANOSE_LETTER_FORM
   {
      PANOSE_LETTER_FORM_ANY,
      PANOSE_LETTER_FORM_NO_FIT,
      PANOSE_LETTER_FORM_NORMAL_CONTACT,
      PANOSE_LETTER_FORM_NORMAL_WEIGHTED,
      PANOSE_LETTER_FORM_NORMAL_BOXED,
      PANOSE_LETTER_FORM_NORMAL_FLATTENED,
      PANOSE_LETTER_FORM_NORMAL_ROUNDED,
      PANOSE_LETTER_FORM_NORMAL_OFF_CENTER,
      PANOSE_LETTER_FORM_NORMAL_SQUARE,
      PANOSE_LETTER_FORM_OBLIQUE_CONTACT,
      PANOSE_LETTER_FORM_OBLIQUE_WEIGHTED,
      PANOSE_LETTER_FORM_OBLIQUE_BOXED,
      PANOSE_LETTER_FORM_OBLIQUE_FLATTENED,
      PANOSE_LETTER_FORM_OBLIQUE_ROUNDED,
      PANOSE_LETTER_FORM_OBLIQUE_OFF_CENTER,
      PANOSE_LETTER_FORM_OBLIQUE_SQUARE
   };
   
   enum PANOSE_MID_LINE
   {
      PANOSE_MID_LINE_ANY,
      PANOSE_MID_LINE_NO_FIT,
      PANOSE_MID_LINE_STANDARD_TRIMMED,
      PANOSE_MID_LINE_STANDARD_POINTED,
      PANOSE_MID_LINE_STANDARD_SERIFED,
      PANOSE_MID_LINE_HIGH_TRIMMED,
      PANOSE_MID_LINE_HIGH_POINTED,
      PANOSE_MID_LINE_HIGH_SERIFED,
      PANOSE_MID_LINE_CONSTANT_TRIMMED,
      PANOSE_MID_LINE_CONSTANT_POINTED,
      PANOSE_MID_LINE_CONSTANT_SERIFED,
      PANOSE_MID_LINE_LOW_TRIMMED,
      PANOSE_MID_LINE_LOW_POINTED,
      PANOSE_MID_LINE_LOW_SERIFED
   };
   
   enum PANOSE_XHEIGHT
   {
      PANOSE_XHEIGHT_ANY,
      PANOSE_XHEIGHT_NO_FIT,
      PANOSE_XHEIGHT_CONSTANT_SMALL,
      PANOSE_XHEIGHT_CONSTANT_STANDARD,
      PANOSE_XHEIGHT_CONSTANT_LARGE,
      PANOSE_XHEIGHT_DUCKING_SMALL,
      PANOSE_XHEIGHT_DUCKING_STANDARD,
      PANOSE_XHEIGHT_DUCKING_LARGE
   };
   
   int FamilyType;
   int SerifStyle;
   int Weight;
   int Proportion;
   int Contrast;
   int StrokeVariation;
   int ArmStyle;
   int LetterForm;
   int MidLine;
   int XHeight;
   
   CATFontPanose()
   {
      FamilyType      = PANOSE_FAMILY_KIND_ANY;
      SerifStyle      = PANOSE_SERIF_STYLE_ANY;
      Weight          = PANOSE_WEIGHT_ANY;
      Proportion      = PANOSE_PROPORTION_ANY;
      Contrast        = PANOSE_CONTRAST_ANY;
      StrokeVariation = PANOSE_STROKE_VARIATION_ANY;
      ArmStyle        = PANOSE_ARM_STYLE_ANY;
      LetterForm      = PANOSE_LETTER_FORM_ANY;
      MidLine         = PANOSE_MID_LINE_ANY;
      XHeight         = PANOSE_XHEIGHT_ANY;
   }
};

// ----------------------------------------------------------------
// structure containing Postscript related data
// ----------------------------------------------------------------
/** @nodoc */
struct CATFontPostScriptInfo
{
   float ItalicAngle;
   
   int UnderlinePosition;
   int UnderlineThickness;
   
   unsigned int isFixedPitch;
   
   CATFontPostScriptInfo()
   {
      ItalicAngle         = 0;
      UnderlinePosition   = 0;
      UnderlineThickness  = 0;  
      isFixedPitch        = 0;
   }
};

// ----------------------------------------------------------------
// structure containing Kerning data
// the function will return a CATListPV of this structure.
// ----------------------------------------------------------------
/** @nodoc */
struct CATKerningValue
{
   CATUC2Bytes LeftCharCode;
   CATUC2Bytes RightCharCode;
   int KerningValue;
}; 

#endif //CATFontMetricsStructures_H


