#ifndef CATFont_H
#define CATFont_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @CAA2Level L1
* @CAA2Usage U1
*/

//
// CATIA CXR1 Framework VFW2
// Copyright Dassault Systemes 1996
//----------------------------------------------------------------
// Abstract : Font: font for geometric texts
// ----------------------------------------------------------------
//  Usage :   Creation of 2D or 3D geometric texts
// ----------------------------------------------------------------
//  Inheritance : none
// ----------------------------------------------------------------
//  Main Methods :
//            Font management
//               sGetFontCount
//               sGetFontName
//               sGetDefaultFont
//               sGetFont
//               Get
//
//----------------------------------------------------------------------------
//       

#include "SGInfra.h"
#include "CATError.h"
#include "CAT2DGeomTextStructures.h"
#include "CATMathPointf.h"
#include "CATMathPoint2Df.h"
#include <sys/types.h>

#include "CATFontMetricsStructures.h"
#include "CATListPV.h"
#include "CATMacForRtti.h"

#include <map>

/** @nodoc */
#define MAX_SUFFIX_LENGTH 20
/** @nodoc */
#define MAX_FONT_ROOT_COUNT 15
/** @nodoc */
#define MAX_FONT_DIR_LENGTH 1024
/** @nodoc */
#define MAX_FONT_NAME_LENGTH 160
/** @nodoc */
#define PIXMAP_BASE_HEIGHT 60
/** @nodoc */
#define PIXMAP_LOW_QUALITY_HEIGHT 20
/** @nodoc */
#define PIXMAP_ANGLE_EQUALITY_CRITERION 5.
/** @nodoc */
#define BITMAP_MAPPING_TABLE_DIMENSION 5
/** @nodoc */
#define BITMAP_FONT_MAXIMUM_HEIGHT 30 /* in pixels */

#ifdef _WINDOWS_SOURCE
#define SUB_DIR "\\"
#define SEPARATOR ';'
#else
#define SUB_DIR "/"
#define SEPARATOR ':'
#endif

class CATFont;
class CATGlyph;
class CATPixmapGlyph;
class CATViewpoint;
class CATExtendableGenInfGlyph;
class CATFontStaticEnvironment;

/** @nodoc */
struct EnvFontGeneralInformationType
{
	char* _Name;       /* file name */
	char* _Path;
	char _Suffix[5];   /* may be font, FONT, pfb, PFB, pfa, PFA, ps, PS, ttf or TTF. With a '\0' at the end */
	char* _Script;     /* character set */
	short _Format;     /* 0:stroke, 1:Type 1, 2:TrueType, 3:CID , 4: OTF*/
	CATULONG32  _FontFaceOffset;/* TUV 2 June 2009 For TTC.Offset value of font combined in true type collection font*/
	CATFont* _Pointer; /* NULL if not loaded */
};

/** @nodoc */
struct PixmapToShowInformationType
{
	CATPixmapGlyph* _Pixmap; 
	float _ApplicationPoint[2];
};

/** @nodoc */
struct PixmapRenderingInformationType
{
	CATViewpoint* _ViewPoint;             /* for the ComputePixelFromModel method*/
	unsigned char _Color[3];              /* 0:red, 1:green, 2:blue    */
	float _mmInSupportUnit;               /* Render.GetMMInSupportUnit */
	float _Ratio;                         /* Render.GetPixelRatioWH    */
	float _Width;                         /* Render.GetWidthAndHeight  */
	float _Height;
	float _RenderedAngle;
	float _BaseModelToRenderedPixelsRatio;/* Base Model -> rendered pixels ratio */
	int _Quality;                         /* 0:base , 1:low */
};

//--------------------------------New CATFont------------------------------------------   
/** @nodoc */
enum CATFontType {All_Type_Font = -1, Stroke_Font, Type1_Font, TrueType_Font, CID_Font, OpenType_Font};
/** @nodoc */
enum CATFontStyle {Regular, Bold, Italic, BoldItalic};

//--------------------------------------------------------------------------   
/**
* Class to manage font for geometric texts.
* <b>Role</b>: Creation of 2D or 3D geometric texts.
*/
class ExportedBySGInfra CATFont
{
	CATDeclareClass_Deprec;

public:


	// constructors
	/** @nodoc */
	CATFont();

	/** @nodoc: deprecated constructor V5R19: use @href sGetFont*/
	CATFont(const int iIndex);

	/** @nodoc */
	virtual ~CATFont();

	// Font count
	/**
	* Returns the number of available fonts.
	*/
	static int sGetFontCount();

	// Get font general information from font index (index comprised between 0 and
	// the value returned by sGetFontCount-1)
	/** @nodoc */
	static void sGetFontGeneralInformation (int iIndex,
		CATString& oName,    // font name, "0003a___.pfb" or "SSS1.font" for example 
		int& oFormat,        // 0:stroke, 1:PostScript 
		CATString& oScript); // character set. "Western", "Japanese","Unicode" ... Not available in CXR1.(always "Undef") 

	/**
	* Returns general information on a outline font.
	* Do not use this method after release V5R15.
	* @param iIndex
	*    the index of the font.
	*    the index is comprised between 0 and the value returned by @href #sGetFontCount-1)
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
	static void sGetFontOtherGeneralInformation(int iIndex,             
		CATString& oLongTabName,
		CATString& oShortTabName, 
		int& oBold,              
		int& oItalic,            
		CATString& oFamilyName,  
		int& oPitch,             
		float& oItalicAngle,
		CATString& oWeight,      
		CATString& oFullName,    
		CATString& oFontName );

	/**
	* Returns general information on a outline font.
	* Do not use this method after release V5R15.
	* @param iIndex
	*    the index of the font.
	*    the index is comprised between 0 and the value returned by @href #sGetFontCount-1)
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
	static void sGetFontOtherGeneralInformation(int iIndex,             
		CATUnicodeString& oLongTabName,
		CATUnicodeString& oShortTabName, 
		int& oBold,              
		int& oItalic,            
		CATUnicodeString& oFamilyName,  
		int& oPitch,             
		float& oItalicAngle,
		CATUnicodeString& oWeight,      
		CATUnicodeString& oFullName,    
		CATUnicodeString& oFontName );

	// Get font name from font index (index comprises between 1 and the value returned by sGetFontCount)
	/** @nodoc */
	static char *sGetFontName (const int iIndex);

	// Get default font name (this fonts contains all current code page character set characters)
	// these 3 pointers must not be desallocated. The software do it itself
	/** @nodoc */
	static void sGetDefaultFont(char*& oDefaultFontName, char*& oDefaultVariablePitchFontName, char*& oDefaultFixedPitchFontName ); 

	// Compute the CAT2DGeomTextAttributeSet for given text parameters
	/** @nodoc */
	static void sComputeGeomAttributeSet (CAT2DGeomTextAttributeSet& oGeomAttSet,
		const float iPoint[2],
		CATUnicodeString iString,
		const float iHeight=10.,
		const int iHorJustification = 1,//0: normal, 1:center, 2:opposite for a code page where characters are
		//displayed in a directional way from left to right, normal = left and opposite = right 
		const int iVerJustification = 3,//0: top, 1:cap, 2:half, 3:base, 4:bottom
		const int iPitch = 0, //0: fixed, 1:variable 
		const CATFont* iFont = NULL,// the NULL value signify the default font.
		const int iPath = 0, // 0: normal, 1:top to bottom, 2:inverse, 3:bottom to top
		const float iOrientationAngle = 0.f,// orientation angle in degrees
		const float iSpacingFactor = -10000.f, // default: stroke font: 1/7 Type 1 font: 0. spacing factor for space between characters
		const float iCompFactor = 1.f,// compression/extension factor
		const float iSlantAngle = 0.f,// slant angle in degrees. The slant transformation has the following matrix: 
		// +-                   -+
		// ! 1  sin(iSlantAngle) !
		// !                     !
		// ! 0  cos(iSlantAngle) ! 
		// +-                   -+
		// For example, when 0<iSlantAngle<90 , it can be considered as the composition of the two following transformations:
		//  . Y affinity with a cos(iSlantAngle) coefficient
		//  . shear transformation ("transvection" or "cisaillement" in french) whose:
		//  . X axis is the the axis whose each point is invariant
		//  . top-right coefficient of the matrix is tangent(iSlantAngle)
		const int iKerningEnable = 0,
		const unsigned int iTextVersion = 0xFFFFFFFF);


	// Compute the global metrics of a text
	/** @nodoc */
	static void sComputeTextGlobalMetrics(CAT2DGeomTextBoundingBox& oTextGlobalMetrics,
		CATUnicodeString iString,
		CAT2DGeomTextAttributeSet& iGeomAttSet,// to compute this argument from the text attributes, use sComputeGeomAttributeSet.
		// It is necessary that the iFont argument be the same 
		const CATFont* iFont=NULL);            // the NULL value signify the default font.


	// The folowing version must disappear
	/** @nodoc */
	static char * sGetDefaultFont();

	/**
	* Get font pointer from font name (with suffix)
	* @param iFontName
	*     the name of the font. 
	* @param iVersion
	*    text version, use CATFont::sGetVisuFontCurrentVersion
	* @param bGetAlternateFont
	*	 when true, we find and return alternate font(can be null if alternate font not found) if currnt font is not found
	*/
	static CATFont * sGetFont(const char * iFontName, const unsigned int iVersion = 0xFFFFFFFF, bool bGetAlternateFont=false);


	// Unload font from font name (with suffix)
	/** @nodoc */
	static void sUnloadFont(const char * iFontName );

	// Change font path to new font path (include font name (with suffix))
	/** @nodoc */
	static void sChangeFontPath(const char * iFontName, const char * iFontPath);

	// Reset font environment
	/** @nodoc */
	static void sResetEnvironment();

	// Send error message
	/** @nodoc */
	static void sSendErrorMessage (const char *iClassName, CATError *iError);

	// Look for files from a given sub-directory name into several directory roots
	/** @nodoc */
	static void sLookForFilesFromGivenSubDirectory(char**& ioFontNameList,
		char**& ioFontPathList,
		int& ioFontCount,
		char* iSubDirectoryName,
		int iSuffixCount,
		char** iSuffix);

	// Update Font Name List to consider all fonts embedded in TTC fonts
	/** @nodoc */
	static  void sUpdateFontNameListForTTC(char**& ioFontNameList,
		char**& ioFontPathList,
		int iPrevFontCount,
		int& ioFontCount);

	// Get font information
	/**
	* Returns the font informations.
	* @param oName
	*    the name of the font.
	* @param oPath
	*    the path of the font file.
	* @param oFormat
	*    the format of the font (0: stroke font, 1: Type 1 font).
	* @param oPitch
	*    the font pitch (-1: undefined, 0: fixed, 1:variable).
	* @param oCharacterSet
	*    the character set of the font ("english", "west european", "japanese", "undistinguished" ...).
	* @param oBox
	*    the bounding box of the font (box = top, cap, bottom, right, left).
	*/
	void Get (char oName[100],// space provided by the calling service 
		char oPath[300],// space provided by the calling service 
		short& oFormat, // 0:stroke, 1:Type 1 
		short& oPitch,  // -1: undefined, 0:stroke, 1:variable 
		char oCharacterSet[30], // character set:
		//   . english
		//   . west european
		//   . east european
		//   . japanese
		//   . korean
		//   . traditional chinese
		//   . simplified chinese
		//   . symbol  
		//   . undistinguished 
		short oBox[5]); // box = top, cap, bottom, right, left 

	// Compute 2D text bounding box
	/** @nodoc */
	virtual void Compute2DGeomTextBoundingBox( const int iCharCount,
		const char* iString,
		const CAT2DGeomTextAttributeSet iGeomAttSet,
		CAT2DGeomTextBoundingBox& oBoundingBox,
		float*& oFirstSide,/* oFirstSide and oSecondSide are 2 tables,
											 their length is oCharCount+1, these
											 2 tables correspond to the ladder
											 of the characters boxes.
											 The i-th character, 0 <= i < oCharCount ,
											 is described by the following box:
											 oFirstSide[i], oFirstSide[i+1],
											 oSecondSide[i], oSecondSide[i+1].
											 oHalf is a table whose length is
											 2*(oCharCount+1). The points inside oHalf
											 are, each of them, between the correponding
											 points in oFirstSide and oSecondSide. Their
											 position correspond, in the case of a
											 right path for example, to the half line
											 between the base line and the cap line. */
											 float*& oHalf,
											 float*& oSecondSide);

	// Compute 2D text bounding box
	/** @nodoc */
	virtual void Compute2DGeomTextBoundingBox(CATUnicodeString iString, const CAT2DGeomTextAttributeSet iGeomAttSet, CAT2DGeomTextBoundingBox& oBoundingBox);

	// Show 2D Text
	// Warning: for an outline font, a call to CATOutlineFont::InitTextShow must
	//          be done once (only one is enough) to load the tesselation. In the
	//          case where this showing is done in a CATRender on a 
	//          CAT2DGeometricText, there is no use to do it since the
	//          CAT2DGeometricText constructor did it.
	/** @nodoc */
	virtual void* Show2DText ( int iRenderingType,// rendering type, corresponds also to the output:
		//   0: CAT2DGeomTextTriPrimitiveList*
		//   1: CAT2DGeomTextPixmapList*
		//   2: CAT2DGeomTextPolylineList*
		//   3: CAT2DGeomTextPixmap*
		PixmapRenderingInformationType* iRenderingInfo,// used if iRenderingType = 1 or 3 
		const int iCharCount,
		const unsigned short* iString,
		CAT2DGeomTextAttributeSet& iGeomAttSet,
		CAT2DGeomTextBoundingBox& iBoundingBox);

	// Compute the detailed metrics of a text
	/** @nodoc */
	void ComputeTextApplicativeMetrics(int& oFirstCharIndex,  /* oFirstCharIndex and oLastCharIndex
																														describe the string characters which are 
																														covered by the applicative rectangle.
																														only these characters are interesting. */
																														int& oLastCharIndex,
																														float*& oFirstSide,    /* oFirstSide and oSecondSide are 2 tables,
																																									 their length is 
																																									 2*(oSecondCharIndex-oFirstCharIndex+2). 
																																									 These 2 tables correspond to the ladder
																																									 of the characters boxes.
																																									 The i-th interesting character, 
																																									 0 <= i < oSecondCharIndex-oFirstCharIndex+1 ,
																																									 is described by the following box:
																																									 . first point:
																																									 oFirstSide[2*i] et [2*i+1]
																																									 . second point:
																																									 oFirstSide[2*(i+1)] et [2*(i+1)+1]
																																									 . third point:
																																									 oSecondSide[2*i] et [2*i+1]
																																									 . fourth point:
																																									 oSecondSide[2*(i+1)] et [2*(i+1)+1]
																																									 These two tables must be freed (using
																																									 "free") by the calling service.
																																									 */
																																									 float*& oSecondSide,
																																									 CATUnicodeString iString,
																																									 CAT2DGeomTextAttributeSet& iGeomAttSet,/* to compute this argument from the text
																																																													attributes, use sComputeGeomAttributeSet.
																																																													It is necessary that the iFont argument
																																																													be the same */
																																																													float* iApplicativePickingRectangle);/* length 6.
																																																																															 This describe an applicative picking
																																																																															 rectangle. Two sides of this rectangle
																																																																															 are parallel to the base line, and
																																																																															 the two opposite sides are perpendicular
																																																																															 to the base line.
																																																																															 . two points describing the intersection 
																																																																															 between the two rectangle sides which 
																																																																															 are perpendicular to the deplacement 
																																																																															 line, with the text half line (x,y of 
																																																																															 first point followed by x,y of second 
																																																																															 point). When moving along the axis of 
																																																																															 the deplacement direction, the first 
																																																																															 point is encountered before the second 
																																																																															 point.  
																																																																															 . 2 algebraic values along the 
																																																																															 unitary vector which is 
																																																																															 perpendicular to the deplacement 
																																																																															 direction (this unitary vector beeing
																																																																															 oriented so that the scalar product
																																																																															 with the up vector is positive, except
																																																																															 in vertical path where you take the base
																																																																															 vector instead of the up vector), from 
																																																																															 the text half line (center line if the 
																																																																															 path is vertical) towards the 2 
																																																																															 rectangle sides which are parallel to 
																																																																															 the deplacement line
																																																																															 (i.e except the sign, it corresponds
																																																																															 to the distances from the text half
																																																																															 line to these two rectangle sides). The 
																																																																															 first value correspond to the bottom side */

	// Show 2D Text (must disappear)
	/** @nodoc */
	virtual void* Show2DText ( int iRenderingType, // rendering type, corresponds also to the output:
		//   0: CAT2DGeomTextTriPrimitiveList*
		//   1: CAT2DGeomTextTriPixmapList*
		//   2: CAT2DGeomTextPolylineList*
		//   3: CAT2DGeomTextBezierContourList*
		float iModelToRenderedPixelsRatio,// used if iRenderingType = 1 
		unsigned char* Color, // 0:red, 1:green, 2:blue 
		const int iCharCount,
		const char *iString,
		CAT2DGeomTextAttributeSet& iGeomAttSet,
		CAT2DGeomTextBoundingBox& iBoundingBox); 

	// Initialize the showing of the text
	/** @nodoc */
	virtual void InitTextShow(const CATUnicodeString& iString);
	/** @nodoc */
	virtual void InitTextShow(const CATUC2Bytes * iString, const int iCharCount);

	// Tesselate 2D Text (must disappear)
	/** @nodoc */
	virtual void* Tess2DText ( int& iTessType, /* 0:stroke,1:filled */
		const int iCharCount,
		const char *iString,
		CAT2DGeomTextAttributeSet& iGeomAttSet,
		CAT2DGeomTextBoundingBox& iBoundingBox);
	// in fact, the void* can be one of the following types:
	//. CAT2DGeomTextPolylineList* (polyline list)
	//. CAT2DGeomTextTriPrimitiveList* (triangle primitives list)

	// Get the text polylines for the input text
	/** @nodoc */
	virtual HRESULT GetTextPolyLine(CATUnicodeString iText,CAT2DGeomTextAttributeSet &iTextAtt,CAT2DGeomTextPolylineList &oTextPolyLine);

	// Texts filling
	/** @nodoc */
	static short sTextFill; // 0: texts are not filled , 1:texts are filled

	// Texts quality
	/** @nodoc */
	static double sTextQual; // value for CATTextQual environment variable: SAG, percentage / cap line , 1.: cap line 

	// Environment font count
	/** @nodoc */
	static int sEnvFontCount;

	// General information about fonts (effective length is sEnvFontCount after filling)
	/** @nodoc */
	static EnvFontGeneralInformationType* sEnvFontGenInfo;

	// Rendering switch values (in rendering coordinates *)
	/** @nodoc */
	double _RenderingSwitchValue[BITMAP_MAPPING_TABLE_DIMENSION+1];
	/* values where we switch, during visulization rendering,
	between triangular primitives non stroke font, bitmap and
	default stroke font for little heights. This value is in 
	rendering coordinates, in pixel count:
	0: stroke to the first bitmap switch
	1: first bitmap to second bitmap switch
	2: second bitmap to third bitmap switch
	...
	BITMAP_MAPPING_TABLE_DIMENSION:
	"BITMAP_MAPPING_TABLE_DIMENSION"-th bitmap to
	triangular primitives switch */

	// Font index into sEnvFontGenInfo
	/** @nodoc */
	short _Index;

	// Font name
	/** @nodoc */
	char* _Name;

	// Font path
	/** @nodoc */
	char* _Path;

	// Font format
	/** @nodoc */
	short _Format;  // 0:stroke, 1:Type 1, 2:TrueType, 3:CID

	// Font pitch
	/** @nodoc */
	short _Pitch; // -1: undefined, 0: fixed, 1:variable

	// Font type
	/** @nodoc */
	short _Type;  // 0: text font, 1: lineic element pattern font

	// Font character set
	/** @nodoc */
	char* _CharacterSet; //character set (nowadays 1 only, later the multi
	//character sets defined in a font will be supported):
	//. english
	//. west european
	//. east european
	//. japanese
	//. korean
	//. traditional chinese
	//. simplified chinese
	//. symbol  
	//undistinguished 

	// Font Box
	/** @nodoc */
	short _Box[5] ; // top, cap, bottom, right, left

	// Font Bounding Box
	/** @nodoc */
	short _BoundingBox[6]; // 0:top, 1:bottom, 2:right, 3:left, 4,5: top and bottom of the character set made
	// of the font character set without the symbols

	// Font description 
	/** @nodoc */
	void* _CharacterTable[65536]; // - stroke font case: this void* is a CATStrokeGlyph*
	// - other case: this void* is a CATExtendableGenInf*

	// Bitmap version count
	/** @nodoc */
	short _BitmapVersionCount; // must be in CATFont.h and not CATType1Font.h because used by CATRender

	// Default stroke font
	/** @nodoc */
	static CATFont* sDefaultStrokeFont;

	// Visualization pixel width/height (supposing it is the same, approximation) in mm
	/** @nodoc */
	static double sVisualizationPixelHeight;

	// Pixmap base height in millimeters
	/** @nodoc */
	static double sPixmapBaseHeightInMM;

	/**
	* Returns the font style.
	* Limitation : It is not possible to retrieve bold and bold-italic status for Stroke fonts.
	* @param iIndex
	*    the index of the font.
	* @param oBold
	*    indicates if the font is bold style (0: regular , 1: bold).
	* @param oItalic
	*    indicates if the font is italic style (0: normal , 1: italic).
	*/
	static void sGetFontStyle (int iIndex, int& oBold, int& oItalic);

	// Current font display version
	/** @nodoc */
	static int sGetVisuFontCurrentVersion();

	/**
	* Returns the font index.
	* @return
	* <br><b>Legal values</b>: the index is comprised between 0 and the value returned by @href #sGetFontCount-1)
	*/
	inline int GetIndex ();

	//--------------------------------------------------------------------------

protected:

	// Compute default font name
	// among these strings, several may contain the same string (not the same pointer)
	static void sComputeDefaultFontName(char** oBasicFont, char** oBasicVariablePitchFont, char** oBasicFixedPitchFont, char** oStrokeFont);

	// Compute the minimum bitmap height
	short ComputeMinBitmapHeight(); // in pixel count

	// Initialization of static data
	static void sInitializeStaticData();

	// Applicative pixel width and height (for print for example) in mm
	static double sApplicativePixelHeight[2];

	// Environment fonts
	static CATFontStaticEnvironment sStaticEnvironment;
	static short sEnvFontRootCount;
	static char* sEnvFontRoot[MAX_FONT_ROOT_COUNT];   // directories with font directories
	static int sEnvFontAllocatedCount;
	static char* sDefaultFontName;
	static char* sDefaultVariablePitchFontName;
	static char* sDefaultFixedPitchFontName;
	static char* sDefaultStrokeFontName;
	static int sEnvIncludingTTEFontCount; // pk2 TTE Support

	// Tesselated text
	static CAT2DGeomTextTriPrimitiveList s2DTextTriPrimitives; 
	static CAT2DGeomTextPolylineList s2DTextPolylines;
	static CAT2DGeomTextPixmap s2DTextPixmap;
	static int s2DTextPixmapToShowAllocatedCount;
	static PixmapToShowInformationType* s2DTextPixmapToShow;
	static CAT2DGeomTextPixmapList s2DTextPixmaps;
	// static CAT2DGeomTextBitmapList s2DTextBitmaps;

	// Font description  
	unsigned short _DefaultCharacterCode;
	CATGlyph* _DefaultCharacterDescription;

	//-------------------------- New CATFont ------------------------------------------------
public:

	/** @nodoc */
	CATFontType    GetFontType();

	/** @nodoc */
	CATFontStyle   GetFontStyle();

	/** @nodoc */
	void           GetFontPath(CATUnicodeString & oFileName, CATUnicodeString & oFileDir);

	/** @nodoc */
	void           SetFontPath(CATUnicodeString & iFileName, CATUnicodeString & iFileDir);

protected:

	void    SetFontType(CATFontType iFontType);
	void    SetFontStyle(CATFontStyle iFontStyle);

public:

	/** @nodoc */
	/*
	* Returns the Font metrics like Ascent,Descent,CapHeight,StemV,FirstChar,LastChar and WidthArray;
	* oWidthArray is allocated inside. After usage you need to free the memory
	* in CFF fonts multiple fonts can be embedded. This is not yet supported and so the last parameter
	* is delfaulted to 0. When this facility is available you can use this parameter to select the font
	* StemV for TTF will return 0; This is only for OTF CFF fonts
	*/
	HRESULT GetFontMetrics(CATFontMetrics&);               // Basic font metrics

	/** @nodoc */
	// required for font metrics API, internal use only
	// TUV 2 June 2009 Additional argument of FontfaceOffset for TTC
	static HRESULT GetTableEntry(FILE * stream, char * tabTag, CATULONG32 & tabOffset, CATULONG32 & tabLength,const CATULONG32 iFontFaceOffset=0);

	/** @nodoc */
	// required for font metrics API, internal use only
	// TUV 2 June 2009 Additional argument of FontfaceOffset for TTC
	static HRESULT GetGlyphIndex(FILE *ipFile,unsigned short inputChar,int &oindex,const CATULONG32 iFontFaceOffset=0);

	/** @nodoc */
	// Get Glyph IDs for all requested characters (default, from 0 to 65535)
	// opIndices must be allocated by caller (size = iEndChar - iStartChar + 1)
	static HRESULT GetAllGlyphIndices(FILE *ipFile, int *opIndices, unsigned short iStartChar=0, unsigned short iEndChar=65535, const CATULONG32 iFontFaceOffset=0);

	/** @nodoc */
	// Names of the font
	HRESULT GetFontNames(CATFontNames&);

	/** @nodoc */
	// Global Horizontal header Info
	HRESULT GetFontHorHeader(CATFontHorHeader&);

	/** @nodoc */
	// Glyph Horizontal Metrics
	HRESULT GetGlyphHorHeader(const CATUC2Bytes icharCode,CATGlyphHorHeader&); 

	/** @nodoc */
	// Global Vertical Header Info
	HRESULT GetFontVerHeader(CATFontVerHeader&);

	/** @nodoc */
	// Glyph Vertical Metrics
	HRESULT GetGlyphVerHeader(const CATUC2Bytes icharCode,CATGlyphVerHeader&);

	/** @nodoc */
	// Glyph informations (Yet to define)
	HRESULT GetGlyphInfo(CATGlyphInfo&);

	/** @nodoc */
	// Panose Info
	HRESULT GetFontPanoseInfo(CATFontPanose&);

	/** @nodoc */
	// Postscript Info
	HRESULT GetFontPostscriptInfo(CATFontPostScriptInfo&);

	/** @nodoc */
	// kerning table
	HRESULT GetKerningTable(CATListPV&);

	/** @nodoc */
	// Font metrics for Print use only
	HRESULT GetPrintFontMetrics(int& oAscent,int& oDescent, int& oCapHeight, int& oStemV, int& oFirstChar, int& oLastChar, int& oWidthArrayLength, int*& oWidthArray);

private:

	void GetCharWidthArray(FILE* ipFile,unsigned short& oWALength, int*& oWidthArray,const CATULONG32 iFontFaceOffset = 0);
	static void sUpdateFontNameListForTTE(char**& ioFontNameList,char**& ioFontPathList,int& ioFontCount);
private:

	CATUnicodeString     _fileName;
	CATUnicodeString     _fileDir;
	CATFontType          _fontType;
	CATFontStyle         _fontStyle;

	CATUnicodeString     _oldText;
	CATUnicodeString     _replacementFontName;
	static int					 _numProxyFontsInEnv;

public:

	/** @nodoc */
	int _totalPrimitiveCount;

	/** @nodoc */
	int _totalVertexCount;

	/** @nodoc */
	int _totalVertexIndicesCount;

private:
	/** @nodoc */
	static std::map<CATString, FILE *> _filePtrMap;
public:
	/** @nodoc */
	static HRESULT SearchFontFileInMap(char * fontFilePath, FILE * &filePtr);

};

int CATFont::GetIndex ()
{
	return _Index;
}

// CATFont_H
#endif 









