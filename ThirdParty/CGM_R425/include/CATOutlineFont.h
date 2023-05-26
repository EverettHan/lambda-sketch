#include "SGInfra.h"
#ifndef CATOutlineFont_H
#define CATOutlineFont_H
//
// CATIA CXR1 Framework VFW2
// Copyright Dassault Systemes 1996
//----------------------------------------------------------------
// Abstract : Outline fonts (Abstract class)
// ----------------------------------------------------------------
//  Usage :   Creation of 2D or 3D geometric texts
// ----------------------------------------------------------------
//  Inheritance : CATOutlineFont
//                  CATFont
// ----------------------------------------------------------------
//  Main Methods :
//
//----------------------------------------------------------------------------
//       

#include "CATFont.h"

struct EnvOutlineFontHeaderType
{
	char* _FamilyName;     /* family name examples:
												 . ITC Avant garde Gothic
												 . Berthold Garamond
												 . Goudy Text MT
												 . Minion 
												 NULL if not filled */
	char* _FullName;       /* NULL if not filled */
	char* _FontName;       /* NULL if not filled */
	char* _ShortTabName;   /* NULL if not filled */
	char* _LongTabName;    /* NULL if not filled */
	short _Pitch;          /* -1: not filled, 0:fixed, 1:proportional */
	int _PCLStrokeWeight;  /* -7:Ultra Thin, -6:Extra Thin, -5:Thin, 
												 -4:Extra Light, -3:Light, -2:Demilight, -1:Semilight,
												 0:Book,Text,Regular... , 1:Semibold (Medium, when 
												 darker than Book), 2:Demibold, 3:Bold, 4:Extra Bold,
												 5:Black, 6:Extra Black, 7:Ultra Black, Ultra,  
												 -1000:not filled. About these values, see the 
												 TrueType documentation, PCLT table */
	char* _Weight;         /* Ultra-light,
												 Light, Thin,
												 Regular, Roman, Book,
												 Medium, Demi,
												 Bold,
												 Ultra-bold,
												 Heavy, Black ...
												 NULL if not filled */
	short _Width;          /* -4: Ultra-condensed
												 -3: Compressed/Compact/Narrow/Extra-condensed ,
												 -2: Condensed ,
												 -1: Semi-condensed,
												 0: Roman/Medium
												 1: Semi-expanded,
												 2: Extended/Expanded,
												 3: Extra-expanded,
												 4: Ultra-expanded 
												 -1000 if not filled */
	float _ItalicAngle;    /* -1000. if not filled */
	short _ItalicFlag;     /* boolean. -1: not filled, 0:not italic, 1:italic */
	short _BoldFlag;       /* boolean. -1: not filled, 0:not bold, 1:bold  */
	unsigned short _CapHeight; /* 60000 if not filled */
};
struct EnvOutlineFontGeneralInformationType
{
	int _EnvFontGenInfoIndex; /* index into CATFont::sEnvFontgenInfo */
	EnvOutlineFontHeaderType* _Header; /* NULL if not filled */
};

class CATGlyphCodeList;

//--------------------------------------------------------------------------   
class ExportedBySGInfra CATOutlineFont : public CATFont
{
public:

	// constructors
	CATOutlineFont();
	CATOutlineFont(const int iFontIndex);

	// Destructor
	virtual ~CATOutlineFont();

	// 2D Geometric Texts management
	void SetQuality ( const double iQuality ); /* SAG, percentage / cap line ,
																						 1.: cap line */
	double GetQuality (); /* percentage / cap line */
	void ResetQuality();

	// Initialize the showing of the text (fills _GlyphToLoadAndTessList and
	// _GlyphToTessList)
	void InitTextShow(const CATUnicodeString& iString);
	void InitTextShow(const CATUC2Bytes * iString, const int iCharCount);

	// Initialize static data
	static void sInitializeOutlineStaticData();
	// Reset static data
	static void sResetOutlineEnvironment();

	// Get general information on a outline font from index (index comprised
	// between 0 and the value returned by CATFont::sGetFontCount-1).
	// We garantee that there are not two (or more)
	// (oShortTabName,oBold,oItalic) u-ple equal to each others for 2 different
	// iIndex values (we introduced numbers into oShortTabName if necessary to
	// garantee that).
	// This service does not load the font.
	// CAUTION: oLongTabName and oShortTabName should not be stored in persistant
	// data since they can evolve in the future. The only data determining a font
	// which ensure unicity and should be stored is the oName (file name)
	// given by CATFont::sGetFontGeneralInformation 
	static void sGetFontOtherGeneralInformation(
		int iIndex,             
		CATString& oLongTabName, /* font name to put in the tab if 
														 the tab's width is big.
														 It contains the family name,
														 weight, width, and other specific
														 attributes. For example
														 "Arial Black" or "Swiss721 Ex BT"*/
														 CATString& oShortTabName, /* font name to put in the tab if 
																											 the tab's width is small. It can
																											 also contain space characters */
																											 int& oBold,              /* 0:not bold , 1:bold */
																											 int& oItalic,            /* 0:normal, 1:italic */
																											 CATString& oFamilyName,  /* family name examples:
																																								. ITC Avant garde Gothic
																																								. Berthold Garamond
																																								. Goudy Text MT
																																								. Minion */
																																								int& oPitch,             /* 0: fixed , 1:variable */
																																								float& oItalicAngle,
																																								CATString& oWeight,      /* "Undef" if not defined
																																																				 Thin , Light,
																																																				 Regular, Roman, Book,              
																																																				 Medium, Demi 
																																																				 Bold,
																																																				 Black, Heavy,             
																																																				 Display, Nord, Poster, Super */
																																																				 CATString& oFullName,    /* "Undef" if not defined */
																																																				 CATString& oFontName     /* "Undef" if not defined */
																																																				 );

	//returning UnicodeString
	static void sGetFontOtherGeneralInformation(
		int iIndex,             
		CATUnicodeString& oLongTabName, /* font name to put in the tab if 
																		the tab's width is big.
																		It contains the family name,
																		weight, width, and other specific
																		attributes. For example
																		"Arial Black" or "Swiss721 Ex BT"*/
																		CATUnicodeString& oShortTabName, /* font name to put in the tab if 
																																		 the tab's width is small. It can
																																		 also contain space characters */
																																		 int& oBold,              /* 0:not bold , 1:bold */
																																		 int& oItalic,            /* 0:normal, 1:italic */
																																		 CATUnicodeString& oFamilyName,  /* family name examples:
																																																		 . ITC Avant garde Gothic
																																																		 . Berthold Garamond
																																																		 . Goudy Text MT
																																																		 . Minion */
																																																		 int& oPitch,             /* 0: fixed , 1:variable */
																																																		 float& oItalicAngle,
																																																		 CATUnicodeString& oWeight,      /* "Undef" if not defined
																																																																		 Thin , Light,
																																																																		 Regular, Roman, Book,              
																																																																		 Medium, Demi 
																																																																		 Bold,
																																																																		 Black, Heavy,             
																																																																		 Display, Nord, Poster, Super */
																																																																		 CATUnicodeString& oFullName,    /* "Undef" if not defined */
																																																																		 CATUnicodeString& oFontName     /* "Undef" if not defined */
																																																																		 );
	// Load a decription list 
	// This service supposes (and does not check) that, for each glyph:
	//   . _CharacterTable[GlyphCode]!=NULL (lets call him ExtendableGenInfGlyph)
	//   . ExtendableGenInfGlyph->_Glyph==NULL
	// For a given code, if this service determines that there is no associated
	// description, the service lets the ExtendableGenInfGlyph in the following 
	// state: 
	//   . ExtendableGenInfGlyph->_Glyph==NULL 
	//   . ExtendableGenInfGlyph->_BoundingBox[0]==-30000
	virtual void LoadDescriptionList(
		int iCodeCount,
		unsigned short* iCodeList); /* unicode codes */
	// Load,for a glyph list, the glyphs descriptions, and fill consequently
	// _GlyphToTessList
	// This service supposes (and does not check) that, for each glyph:
	//   . _CharacterTable[GlyphCode]!=NULL (lets call him ExtendableGenInfGlyph)
	//   . ExtendableGenInfGlyph->_Glyph==NULL
	// A normal context to call this service is that the calling service is
	// nearly sure that the descriptions exists (the bounding boxes have already
	// been loaded).
	// Anyway, for a given code, if this service determines that there is no 
	// associated description, the service lets the ExtendableGenInfGlyph in the 
	// following state: 
	//   . ExtendableGenInfGlyph->_Glyph==NULL 
	//   . ExtendableGenInfGlyph->_BoundingBox[0]==-30000
	void LoadAndPrepareToTessGlyphList(int iGlyphCount,
		unsigned short* iGlyphList); 
	// Tesselate a glyph list
	// This service supposes (and does not check) that, for each glyph:
	//   . _CharacterTable[GlyphCode]!=NULL (lets call him ExtendableGenInfGlyph)
	//   . ExtendableGenInfGlyph->_Glyph!=NULL (lets call him Glyph)
	//   . Glyph->_TriPrimPtr[0]==NULL
	void TessGlyphList(int iGlyphCount,
		unsigned short* iGlyphList, 
		int iUpdateBoundingBox);
	// List of the descriptions which have to be loaded and tesselated
	CATGlyphCodeList* _GlyphToLoadAndTessList;  
	// List the descriptions which have to be tesselated
	CATGlyphCodeList* _GlyphToTessList;     
	// Flag indicating if the glyph boxes have been loaded at the font construction
	int _GlyphBoxesLoadedAtBeginning;
	// Quality
	double _Quality[2]; /* SAG, percentage / cap line , 1.: cap line  
											-1. if not stored 
											First index:  visualization quality
											second index: applicative quality */
	// Environment outline font count
	static int sEnvOutlineFontCount;
	// General information about outline fonts (effective length is 
	// sEnvOutlineFontCount after filling)
	static EnvOutlineFontGeneralInformationType* sEnvOutlineFontGenInfo;
	// Font index into sEnvOutlineFontGenInfo
	short _EnvOutlineFontGenInfoIndex;

	//--------------------------------------------------------------------------
protected:
	// Initialize the static general information for the font given through the
	// parameter 
	static void sInitializeOutlineStaticFontInformation(
		int iEnvOutlineFontGenInfoIndex);
	// Conversions on integers and floats 
	static void sConvert2BytesFromBigEndianToSystem(void* o2BytesPtr,
		void* i2BytesPtr);
	static void sConvert4BytesFromBigEndianToSystem(void* o4BytesPtr,
		void* i4BytesPtr);
	static void sConvertnBytesFromBigEndianToSystem(void* onBytesPtr,
		void* inBytesPtr,
		int iByteCount);
	// Flag to indicate if sEnvOutlineFontGenInfo has been filled
	static int sEnvOutlineFontGenInfoFilled;

	//--------------------------------------------------------------------------
private:
	// rename outline fonts general information so that N-Uple be unique
	static void sRenameOutlineFontGeneralInformationUniqueNUple();

	// Tesselation Quality Index
	int _TessQualIndex;

	//--------------------------------------------------------------------------

};

// CATOutlineFont_H
#endif 









