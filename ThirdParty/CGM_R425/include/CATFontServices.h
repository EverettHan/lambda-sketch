#ifndef CATFontServices_H
#define CATFontServices_H

// COPYRIGHT DASSAULT SYSTEMES 2005
//
// CATIA Framework VisualizationBase
// ----------------------------------------------------------------
//  Abstract    : The aim is to provide a set of functions/API that
//                will allow its users access to certain font
//                related metrics and information.  Users in need
//                of these font related information can obtain it
//                through these APIs without loading the font.
//                Currently, obtaining a small set of font related
//                information is through the CATFont exposed
//                functions.  None of this functionality is 
//                CAA-exposed as of now.
// ----------------------------------------------------------------
//  Usage       : Global Font Service for End Users, Ecosystem or 
//                DS Programmers
// ----------------------------------------------------------------
//  Inheritance : None
// ----------------------------------------------------------------
//  Main APIs   :
//                CATFontGetFontList
//                CATFontGetFont
//                CATFontGetFontGeneralInformation
//                CATFontGetFontOtherGeneralInformation
//                CATFontGetFontNames
//                CATFontGetFontMetrics
//----------------------------------------------------------------------------
//       

// System
#include "CATUnicodeString.h"
#include "CATString.h"
#include "CATListOfCATUnicodeString.h"

// VisualizationBase
#include "SGInfra.h"
#include "CATFontMetricsStructures.h"

// Forward Reference
// VisualizationBase
class CATFont;
class CAT2DGeometricTextGP;

// FONT SERVICE APIs

// Global Font Service APIs that exports the list of Font Full Name those are available (Without loading the font)
ExportedBySGInfra HRESULT CATFontGetFontList(CATListOfCATUnicodeString& oFontNameList);

// A new global Service that returns the font pointer corresponding to the input font full name.
ExportedBySGInfra HRESULT CATFontGetFont(const CATUnicodeString& iFontNames, CATFont * &oFont);
  
// Get font general information from font pointer.
ExportedBySGInfra HRESULT CATFontGetFontGeneralInformation(CATFont *iFont,      
                                         CATString &oName,    // - font name, "0003a___.pfb" or "SSS1.font" for example
                                         int &oFormat,        // - 0:Stroke, 1: PostScript
                                         CATString &oScript); // - Character Set, "Western", "Japanese", "Unicode"
                                                              // Not available in CXR1. (always "Undef")
                                                        
/**
 * Returns general information on a outline font.
 * @param iFont
 *    the pointer to the font.
 * @param oLongTabName
 *    the long name of the font.
 * @param oShortTabName
 *    the short name of the font.
 * @param oBold
 *    the font style (0: not bold, 1: bold).
 * @param oItalic
 *    the font style (0: normal, 1: italic).
 * @param oFamilyName
 *    the family name of the font.
 * @param oPitch
 *    the font pitch (0: fixed, 1: variable).
 * @param oItalicAngle
 *    the angle of italic style font.
 * @param oWeight
 *    the font weight.
 * @param oFullName
 *    the full name of the font.
 * @param oFontName
 *    the name of the font.
 */
ExportedBySGInfra HRESULT CATFontGetFontOtherGeneralInformation(CATFont* iFont,
                                              CATUnicodeString& oLongTabName,
                                              CATUnicodeString& oShortTabName,
                                              int& oBold,
                                              int& oItalic,
                                              CATUnicodeString& oFamilyName,
                                              int& oPitch,
                                              float& oItalicAngle,
                                              CATUnicodeString& oWeight,
                                              CATUnicodeString& oFullName,
                                              CATUnicodeString& oFontName);

// Get font full name and file name from font pointer
ExportedBySGInfra HRESULT CATFontGetFontNames(CATFont* iFont,
                            CATUnicodeString& oFullName,
                            CATUnicodeString& oFileName);
  
/*    * Returns the Font metrics like Ascent,Descent,CapHeight,StemV,FirstChar,LastChar and WidthArray;
      * oWidthArray is allocated inside. After usage you need to free the memory
      * in CFF fonts multiple fonts can be embedded. This is not yet supported and so the last parameter
      * is delfaulted to 0. When this facility is available you can use this parameter to select the font
      * StemV for TTF will return 0; This is only for OTF CFF fonts      
*/
ExportedBySGInfra HRESULT CATFontGetFontMetrics(CATFont* iFont,
                              CATFontMetrics& oFontMetrics);


//  Get font pointer from font name (with suffix) and text version to be used 
ExportedBySGInfra HRESULT CATFontGetFontForVersion(const char * ipFontName, CATFont* &opFont, int iVersion = 0);

//  Check font pointer to be consistant with text version to be used.
ExportedBySGInfra HRESULT CATFontCheckFontForVersion(CATFont* &iopFont, int iVersion = 0);

// Font Linking support for SVG/PDF

ExportedBySGInfra HRESULT CATGetTextPartsByFont(CAT2DGeometricTextGP* ipGeomTextGP , CATListPV &oTextGPList); 
/*    * Because of the font linking, single string may be diaplayed using different fonts.
      * This API returns individual string parts that are displayed by each font.
      * e.g. if string is ABC$$DEF, API will return 3 strings ABC,$$,DEF and 3 fonts in font list Arial, MS Mincho,Arial.
      * ($ = Any character from linked font may be CJK character/Hindi charcter)
      * if string is displayed by Base font completely, 0 strings and 0 fonts are returned.
      * if string is displayed completely by linked font,1 string and pointer to linked font is returned.
*/
ExportedBySGInfra HRESULT CATGetTextPartsAndFontByFont(CATUnicodeString & iString , CATFont *ipFont, CATListOfCATUnicodeString &oListStringParts, CATListPV &oFontPtrList );



#endif
