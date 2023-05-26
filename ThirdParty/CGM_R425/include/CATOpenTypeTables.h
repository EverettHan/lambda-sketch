#ifndef CATOpenTypeTables_H
#define CATOpenTypeTables_H


// CATIA CXR1 Framework VFW2
// Copyright Dassault Systemes 1996
//----------------------------------------------------------------
// Abstract : Font Table
// ----------------------------------------------------------------
//  Usage :   Creation of 2D or 3D geometric texts
//			  Storing OpenType Tables				
// ----------------------------------------------------------------
//  Inheritance : 
// ----------------------------------------------------------------
// ----------------------------------------------------------------
//  Responsible : NPE3 
// ----------------------------------------------------------------
//  Main Methods :

//#include "CATFont.h"
#include <map>
#include <vector>
#include <unordered_map>
#include <string>
#include "CATMath.h"
#include "CATUnicodeChar.h"
#include "CATUnicodeString.h"
#include "CATSysMacroPtr.h"

//Enum for tables
enum OTTableEnum
{
	CFF,
	CMAP,
	GDEF,
	GLYF,
	GPOS,
	GSUB,
	HEAD,
	HHEA,
	HMTX,
	KERN,
	LOCA,
	MAXP,
	NAME,
	OS2	,
	PCLT,
	POST,
	VHEA,
	VMTX,
	NOT_SUPPORTED
};

//Offset structure
struct TableOffset
{
	CATULONG32 offset = 0;
	CATULONG32 tableLength = 0;
};

struct FontMetricsStruct
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

//------------------------------START: Common Tables ------------------------
// creating a struture of type ScriptRecord.
struct ScriptRecord
{
public:
	char SciptTag[5];
	unsigned short ScriptOffset;
};

//structure of type ScriptListTable
struct ScriptListTable
{
public:
	//Number of ScriptRecords
	unsigned short ScriptCount = 0;
	//Array of ScriptRecords, listed alphabetically by script tag, #scriptRecord = ScriptCount
	ScriptRecord * pScriptRecord = NULL;
};
// creating a struture of type LangSysRecord.
struct LangSysRecord
{
public:
	//4-byte LangSysTag identifier
	char LangSysTag[5];
	//Offset to LangSys table, from beginning of Script table
	unsigned short LangSysOffset;
};

//structure of type ScriptTable
struct ScriptTable
{
public:
	//Offset to default LangSys table, from beginning of Script table — may be NULL
	unsigned short defLangSysOffset = 0;
	//Number of LangSysRecords for this script — excluding the default LangSys
	unsigned short langSysCount = 0;
	//	Array of LangSysRecords, listed alphabetically by LangSys tag
	LangSysRecord * pLangSysRecord = NULL;
};




// creating a struture of type OTFeatureRecord.
struct OTFeatureRecord
{
public:
	//4-byte feature identification tag
	char FeatureTag[5];
	//Offset to Feature table, from beginning of FeatureList
	unsigned short FeatureOffset=0;
};



//common header schema for GPOS and GSUB
struct GPOSGSUBHeader
{
public:
	//Offset to ScriptList table, from beginning of GPOS table
	unsigned short ScriptListOffset = 0;
	//Offset to FeatureList table, from beginning of GPOS table
	unsigned short FeatureListOffset = 0;
	//Offset to LookupList table, from beginning of GPOS table
	unsigned short LookupListOffset = 0;
};

class OpenTypeCommonTables
{
public:
	GPOSGSUBHeader header;
	ScriptListTable scriptList;
	ScriptTable * pScriptTable=NULL;

	//flag for tables filled or not filled
	CATBoolean _btablesFilled;

	//constructor
	OpenTypeCommonTables();
	//destructor
	~OpenTypeCommonTables();
	//Clean Memory function
	void CleanCommonTablesMemory();
	/*@nodoc*/
	/*function to fill CommonTables*/
	HRESULT ReadCommonTables(FILE * ipFile, TableOffset tableOfftSets);
	/*@nodoc*/
	HRESULT GetScriptTabOffsetForScript(char iscriptTag[5], unsigned short & oscriptTableOffset, unsigned short & oScriptIndex);

};
//------------------------------END: Common Tables ------------------------

//---------------------------------------Start: GPOS ------------------------

// struct for storing GPOS x and y positioning.
struct GPOSInfo
{
	int xAdj;
	int yAdj;

	GPOSInfo()
	{
		xAdj = 0;
		yAdj = 0;
	}
	// to add any other type of info
};


//---------------------------------------START: NEW GPOS ------------------------

//struct RangeRecord
struct RangeRecord
{
public:
	//First glyph ID in the range
	unsigned short startGlyphID = 0;
	//Last glyph ID in the range
	unsigned short endGlyphID = 0;
	//Coverage Index of first glyph ID in range
	unsigned short startCoverageIndex = 0;
};



struct OTCoverageTable
{
	unsigned short coverageFormat = 0;

	//------------Coverage Format 1 ---------------//
	//Number of glyphs in the glyph array
	unsigned short glyphCount = 0;
	//Array of glyph IDs — in numerical order
	//unsigned short * pGlyphArray = NULL;
	std::vector<unsigned short> vecGlyphArray = {};
	//------------Coverage Format 1 ---------------//

	//------------Coverage Format 2 ---------------//
	//Number of RangeRecords
	unsigned short rangeCount = 0;
	//Array of glyph ranges — ordered by startGlyphID.
	//RangeRecord * pRangeRecords = NULL;
	std::vector<RangeRecord> vecRangeRecords = {};
	//------------Coverage Format 2 ---------------//

};
struct ValuRecordStruct
{
	short ValueRecordArray[9] = { 0,0,0,0,0,0,0,0,0 };
};


struct OTLookup
{
	unsigned short subTableCount = 0;
	unsigned short lookupType = 0;
	unsigned short lookupFlag = 0;
	//coverage table
	OTCoverageTable sCovTable;
};

//---------------START: SingleAdjustment Positioning (LookupType 1)---------------
struct SingleAdjustmentPos
{
	//posFormat
	unsigned short PosFormat = 0;
	unsigned short valueFormat = 0;
	unsigned short valueCount = 0;
	std::vector<ValuRecordStruct> vecValueRecords = {};
	OTCoverageTable sCovTable;
};
//---------------END: SingleAdjustment Positioning (LookupType 1)---------------
struct PairAdjustmentPos
{
	//posFormat
	unsigned short PosFormat = 0;
	unsigned short valueFormat1 = 0;
	unsigned short valueFormat2 = 0;
	unsigned short pairSetCount = 0;

	std::vector<short> vecpairValueCount = {};

	std::vector<std::vector<short>> vecSecongGlyphs = {};

	std::vector<std::vector<ValuRecordStruct>> vecValueRecordArray1 = {};
	std::vector<std::vector<ValuRecordStruct>> vecValueRecordArray2 = {};

	//ValuRecordStruct ** ppValueRecordArray = NULL;
	//coverage table
	OTCoverageTable sCovTable;


};
//---------------END: Pair Adjustment Positioning (LookupType 2)---------------


//---------------START: Mark-to-Base Attachment Positioning (LookupType 4)---------------
//structure for DeviceTable
struct DeviceTable
{
public:
	//Smallest size to correct, in ppem
	unsigned short 	startSize = 0;
	//Largest size to correct, in ppem
	unsigned short	endSize = 0;
	//Format of deltaValue array data : 0x0001, 0x0002, or 0x0003
	unsigned short	deltaFormat = 0;
	//Array of compressed data
	//unsigned short	* deltaValue = NULL;
};
//creating AnchorTable stucture for more easy data storage
//in actual font all AnchorFormat tables have this data common
struct AnchorTable
{
public:
	//format
	unsigned short fmt = 0;
	//Horizontal value, in design units
	short	xCoordinate = 0;
	//Vertical value, in design units
	short	yCoordinate = 0;
};
//structure Anchor Format 1
struct AnchorFmt1 : public AnchorTable
{
	//Format identifier, = 1
	unsigned short	anchorFormat = 1;
	//constructor for conversion
	AnchorFmt1(const AnchorTable & anchTab) : AnchorTable(anchTab) {	};
	//default ctor
	AnchorFmt1()
	{
		anchorFormat = 1;
	}
};

//structure Anchor Format 2
struct AnchorFmt2 : public AnchorTable
{
	//Format identifier, = 2
	unsigned short	anchorFormat = 2;
	
	//Index to glyph contour point
	unsigned short anchorPoint = 0;
	//constructor for conversion
	AnchorFmt2(const AnchorTable & anchTab) : AnchorTable(anchTab) {	};
	//default ctor
	AnchorFmt2()
	{
		anchorFormat = 2;
		anchorPoint = 0;
	}

};
//structure Anchor Format 3
struct AnchorFmt3 : public AnchorTable
{
	//Format identifier, = 3
	unsigned short	anchorFormat = 3;
	//Offset to Device table (non-variable font) / VariationIndex table (variable font) for X coordinate,
	//from beginning of Anchor table (may be NULL)
	unsigned short xDeviceOffset = 0;
	//Offset to Device table (non-variable font) / VariationIndex table (variable font) for Y coordinate, 
	//from beginning of Anchor table (may be NULL)
	unsigned short yDeviceOffset = 0;
	//device table
	DeviceTable  deviceTable;
	//constructor for conversion
	AnchorFmt3(const AnchorTable & anchTab) : AnchorTable(anchTab) {	};
	//default ctor
	AnchorFmt3()
	{
		anchorFormat = 3;
		xDeviceOffset = 0;
		yDeviceOffset = 0;
	}

};
//structure for MarkArray
struct MarkRecord
{
	//Class defined for the associated mark.
	unsigned short markClass = 0;
	//Offset to Anchor table, from beginning of MarkArray table.
	unsigned short markAnchorOffset = 0;
};
//structure MarkArray table
struct MarkArrayTable
{
	//Number of MarkRecords
	unsigned short markCount = 0;
	//Array of MarkRecords, ordered by corresponding glyphs in the associated mark Coverage table.
	//MarkRecord * pMarkRecords = NULL;
	std::vector<MarkRecord> vecMarkRecords = {};
	//anchor table according to formats
	std::map<unsigned short, AnchorTable> anchorTabMap;
};

//structure BaseRecord 
struct BaseRecord
{
	//Array of offsets (one per mark class) to Anchor tables. Offsets are from beginning of BaseArray table, ordered by class.
	//unsigned short * pBaseAnchorOffset = NULL;
	std::vector<unsigned short> vecBaseAnchorOffset = {};
};
//structure BaseArray
struct BaseArray
{
	//Number of BaseRecords
	unsigned short baseCount = 0;
	//Array of BaseRecords, in order of baseCoverage Index.
	//BaseRecord * pBaseRecords = NULL;
	std::vector<BaseRecord> vecBaseRecords = {};
	//anchor table according to formats
	std::map<unsigned short, AnchorTable> anchorTabMap;
};

struct MarkBaseAttachment : OTLookup
{
	//posFormat
	unsigned short PosFormat = 0;
	unsigned short mcoverage = 0;
	unsigned short bcoverage = 0;
	unsigned short markClassCount = 0;
	unsigned short markoff = 0;
	unsigned short baseoff = 0;

	MarkArrayTable markArr;
	BaseArray baseArr;
	//anchor format
	unsigned short fmt = 0;

	OTCoverageTable sCovTable;

	//Extra coverage table for mark glyph
	OTCoverageTable sCovTableForMark;

	//coverage table

};
//---------------END: Mark-to-Base Attachment Positioning (LookupType 4)---------------

//---------------Start: Mark-to-Mark Attachment Positioning (LookupType 6)---------------

//structure Mark2Record
struct Mark2Record
{
	//Array of offsets (one per class) to Anchor tables. 
	//Offsets are from beginning of Mark2Array table, in class order.
	//unsigned short * pMark2AnchorOffsets = NULL;
	std::vector<unsigned short>  vecMark2AnchorOffsets = {};

};
//strcture for Mark2Array 
struct Mark2Array
{
public:
	//Number of Mark2 records
	unsigned int mark2Count = 0;
	//Array of Mark2Records, in Coverage order.
	//Mark2Record * pMark2Records = NULL;
	std::vector<Mark2Record> vecMark2Records = {};
	//anchor table according to formats
	std::map<unsigned short, AnchorTable> anchorTabMap;
};

struct MarkMarkAttachment
{
	//posFormat
	unsigned short PosFormat = 0;
	//Offset to Combining Mark Coverage table, from beginning of MarkMarkPos subtable.
	unsigned short	mark1CoverageOffset = 0;
	//Offset to Base Mark Coverage table, from beginning of MarkMarkPos subtable.
	unsigned short	mark2CoverageOffset = 0;
	//Number of Combining Mark classes defined
	unsigned short	markClassCount = 0;
	//Offset to MarkArray table for mark1, from beginning of MarkMarkPos subtable.
	unsigned short	mark1ArrayOffset = 0;
	//Offset to Mark2Array table for mark2, from beginning of MarkMarkPos subtable.
	unsigned short	mark2ArrayOffset = 0;

	MarkArrayTable markArr;
	Mark2Array mark2Arr;
	BaseArray baseArr;
	
	//anchor format
	unsigned short fmt = 0;
	OTCoverageTable sCovTable;

	//Extra coverage table formar2
	OTCoverageTable sCovTableForMark2;

};

//---------------END: Mark-to-Mark Attachment Positioning (LookupType 6)---------------

struct OTLookupTableRecord
{
	//when want to use check for lookup type and cast accordingly
	//# = subtablecount
	std::map<int, SingleAdjustmentPos> mapSingleAdjustPos = {};
	std::unordered_map<int, PairAdjustmentPos> mappairAdjustPos  = {};
	std::map<int, MarkBaseAttachment> mapMarkBaseAdjustPos  = {};
	std::map<int, MarkMarkAttachment> mapMarkMarkAdjustPos  = {};
	unsigned short lookupType = 0;
	unsigned short lookupFlag = 0;
	unsigned short subTableCount = 0;
};

struct OTFeature
{
	char featTag[5];
	unsigned short featureParam = 0;

	unsigned short requiredLookupCount = 0;
	unsigned short lookupCount = 0;
	//# = requiredLookUpCount
	std::vector< OTLookupTableRecord> vecLookupTableRecords = {};
	~OTFeature()
	{
		vecLookupTableRecords.clear();
	}
};
//structure for FeatureList Table
struct OTFeatureListTable
{
public:
	//Number of FeatureRecords in this table
	unsigned short featureCount=0;
	//Array of FeatureRecords — zero-based (first feature has FeatureIndex = 0), listed alphabetically by feature tag
	OTFeatureRecord * pFeatureRecords = NULL;
};
struct OTLangSysTable
{
public:
	//Index of a feature required for this language system; if no required features = 0xFFFF
	unsigned short reqFeatureIndex = 0;
	//Number of feature index values for this language system — excludes the required feature
	unsigned short requiredFeatureCount = 0;

};
//each script has number of features this structure is for the same
struct OTScriptFeatures
{
	std::vector< OTFeature> sFeatures = {};
	~OTScriptFeatures()
	{
		sFeatures.clear();
	}
};

struct OTGPOS
{
	//table offset
	TableOffset tabOffSet;
	//LangSys Table
	OTLangSysTable * pLangSysTable=NULL;
	//FeatureList Table
	OTFeatureListTable featureList;
	//ScriptFeatures
	//OTScriptFeatures * pScriptFeatures;
	std::map<int, OTScriptFeatures> mapScriptFeatures = {};
	
	OTGPOS()
	{
		pLangSysTable = NULL;
		mapScriptFeatures = {};
	}
};
//---------------------------------------END: NEW GPOS ------------------------



//---------------------------------------START: CMAP------------------------
struct CmapHeader
{
	unsigned short version = 0;			  //Version Number(Set to 0)	
	unsigned short numEncodingTables = 0; //Number of encoding subtables
	//CmapEncoding * encodingRecords = NULL; 
};

struct CmapTab
{
	CmapHeader _header;

	TableOffset tabOffSet;

	unsigned short segCount = 0; //variable needed for calculating the glyph index
	unsigned short *pendCount = NULL;
	unsigned short *pstartCount = NULL;
	unsigned short *pidDelta = NULL;
	unsigned short *pidRangeOffset = NULL;
	unsigned short symbolFont = 0;
	CATULONG32 subTableOffset = 0;
	CATULONG32 idRangeOffsetAdd = 0;
	unsigned short * pGlyphIndices = NULL;
	CmapTab()
	{
		pGlyphIndices = (unsigned short*)calloc(65535, sizeof(unsigned short));
		pendCount = NULL;
		pstartCount = NULL;
		pidDelta = NULL;
		pidRangeOffset = NULL;
	}
};

//---------------------------------------End: CMAP ------------------------

//---------------------------------------START: maxp------------------------

struct MaxpTab
{
	TableOffset tabOffSet;
	unsigned short maxp = 0;

	CATBoolean bProcessed = FALSE;
};
//---------------------------------------End: maxp ------------------------

//---------------------------------------START: GDEF------------------------

struct GDEFTab
{
public:
	TableOffset tabOffset;

	unsigned short glyphClassDefOffset = 0;
	unsigned short classFormat = 0;
	//start glyph
	unsigned short startGlyph = 0;
	//glyph count
	unsigned short glyphCount = 0;

	unsigned short * classValues = NULL;
	//range count
	unsigned short range_count = 0;

	unsigned short * startGlyphIds = NULL;
	unsigned short * endGlyphIds = NULL;
		
};
//---------------------------------------END: GDEF------------------------

//---------------------------------------START: CFF------------------------

struct CFFTab
{
	TableOffset tabOffSet;
};

//---------------------------------------END: CFF------------------------

//---------------------------------------START: glyf------------------------


struct GlyfRecord
{
	short numContours = 0;
	short xmin = 0;
	short ymin = 0;
	short xmax = 0;
	short ymax = 0;

	GlyfRecord(short inumContours, short iXmin, short iYmin, short iXmax, short iYmax)
	{
		numContours = inumContours;
		xmin = iXmin;
		ymin = iYmin;
		xmax = iXmax;
		ymax = iYmax;
	}
	GlyfRecord()
	{
		numContours = 0;
		xmin = 0;
		ymin = 0;
		xmax = 0;
		ymax = 0;
	}
};

struct GLYFTab
{
	TableOffset tabOffSet;
	std::vector<GlyfRecord> vecGlyfRecords = {};
};
//---------------------------------------END: glyf------------------------

//---------------------------------------START: GSUB------------------------
struct GSUBTab
{
	TableOffset tabOffSet;
};
//---------------------------------------END: GSUB------------------------

//---------------------------------------START: HEAD------------------------
struct HEADTab
{
	TableOffset tabOffSet;
	
	unsigned short unitsPerEm = 0;
	short indexToLocFormat = 0;
	short glyphDataFormat = 0;

};
//---------------------------------------END: HEAD------------------------


//---------------------------------------START: HHEA------------------------
struct HHEATab
{
	TableOffset tabOffSet;

	short ascender = 0;
	short descender = 0;
	short lineGap = 0;
	unsigned short advanceWidthMax = 0;
	short minLeftSideBearing = 0;
	short minRightSideBearing = 0;
	short xMaxExtent = 0;
	unsigned short numberOfHMetrics = 0;

};
//---------------------------------------END: HHEA------------------------

//---------------------------------------START: HMTX------------------------
struct longHorMetricRecord
{
	unsigned short advanceWidth; //Advance width, in font design units.
	short lsb; // Glyph left side bearing, in font design units.
};

struct HMTXTab
{
	TableOffset tabOffSet;
	longHorMetricRecord* pHorMetricTable = NULL;


	~HMTXTab()
	{
		CATSysDeleteTab(pHorMetricTable);
	}
};
//---------------------------------------END: HMTX------------------------

//---------------------------------------START: kern------------------------

struct KerningTab
{
	TableOffset tabOffSet;
	//map to store hash of kern
	std::unordered_map<int, int> mapKernValues;
};
//---------------------------------------END: kern------------------------

//---------------------------------------START: loca------------------------
struct LOCATab
{
	TableOffset tabOffSet;
	
	//short version
	//The actual local offset divided by 2 is stored. The value of n is numGlyphs + 1. The value for numGlyphs is found in the 'maxp' table.
	unsigned short * pShortGlyphOffsets = NULL;

	//long version
	//The actual local offset is stored. The value of n is numGlyphs + 1. The value for numGlyphs is found in the 'maxp' table.
	CATULONG32 * pLongGlyphOffsets = 0;

	/*~LOCATab()
	{
		CATSysDeleteTab(pShortGlyphOffsets);
		CATSysDeleteTab(pLongGlyphOffsets);
	}*/
};
//---------------------------------------END: loca------------------------

//---------------------------------------START: name------------------------


struct NAMETab
{
	TableOffset tabOffSet;
	// Number of name records.
	unsigned short recordCount = 0;
	
	//Instead of NameRecords which stores all data we are storing only what we need now
	
	CATUnicodeString copyright;
	CATUnicodeString familyName;
	CATUnicodeString subFamilyName;
	CATUnicodeString uniqueFontID;
	CATUnicodeString fullName;
	CATUnicodeString version;
	CATUnicodeString PostScriptFontName;
	CATUnicodeString Trademark;

};
//---------------------------------------END: name------------------------

//---------------------------------------START: os/2------------------------
struct OS2Tab
{
	TableOffset tabOffSet;

	unsigned short weightClass = 0;
	unsigned short widthClass = 0;
	CATULONG32 * pUCCharRange = NULL;

	int avgCharWidth = 0;
	int fsSelection = 0;
	int firstChar = 0;
	int lastChar = 0;
	int ascent = 0;
	int descent = 0;

	//Panose info-->
	int familyType = 0;
	int serifStyle = 0;
	int weight = 0;
	int proportion = 0;
	int contrast = 0;
	int strokeVariation = 0;
	int armStyle = 0;
	int letterForm = 0;
	int midLine = 0;
	int xHeight = 0;
	//<--- Panose info


};
//---------------------------------------END: os/2------------------------

//---------------------------------------START: PCLT------------------------
struct PCLTTab
{
	TableOffset tabOffSet;

	unsigned short pitch = 0;
};
//---------------------------------------END: PCLT------------------------

//---------------------------------------START: post------------------------
struct POSTTab
{
	TableOffset tabOffSet;
	//italic angle
	short italicAngle = 0;
	short underlinePosition = 0;
	short underlineThickness = 0;
	unsigned int isFixedPitch = 0;

	unsigned short numberOfVMetrics = 0;
};
//---------------------------------------END: post------------------------

//---------------------------------------START: vhea------------------------
struct VHEATab
{
	TableOffset tabOffSet;
	
	short ascent = 0;
	short descent = 0;

	unsigned short maxAdvanceHeight=0;
	short minTSB=0;
	short minBSB=0;
	short yMaxExtent=0;

	unsigned short numberOfVerMetrics = 0;
};
//---------------------------------------END: vhea------------------------

//---------------------------------------START: vmtx------------------------
struct longVerMetricRecord
{
	unsigned short advanceHeight=0;
	short tsb=0; // top side bearing;
};

struct VMTXTab
{
	TableOffset tabOffSet;

	longVerMetricRecord* pVerMetricRec = NULL;

};
//---------------------------------------END: vmtx------------------------

//Structure for font file type
enum EFontType
{
	//OpenTypeFont
	E_OTF,
	//TrueTypeFont
	E_TTF,
	//NotDefined
	E_NOT_DEFINED
};

class CATOpenTypeTables
{
private:
	// Map of string vs enum of open type tables
	static std::map<std::string, OTTableEnum> _sStrToEnumMap;
	/** @ nodoc */
	void FillMapOfTableEnum();
	/** @ nodoc */
	OTTableEnum GetEnumForTable(std::string & iTableName);

	//font file type, otf, ttf, other
	//1 : OTF
	//2 : TTF
	//0 : Unknown
	EFontType _eFontType;

	//GPOS 
	//GPOSTab *  _gposTable;
	//cmap
	CmapTab * _cmapTable;
	//maxp
	MaxpTab _maxpTable;
	//GDEF
	GDEFTab _gdefTable;
	//CFF
	CFFTab _cffTable;
	//glyf
	GLYFTab _glyfTab;
	//gsub
	GSUBTab _gsubTab;
	//head
	HEADTab _headTab;
	//hhea
	HHEATab _hheaTab;
	//hmtx 
	HMTXTab _hmtxTab;
	//kern
	KerningTab _kernTab;
	//loca
	LOCATab _locaTab;
	//name
	NAMETab _nameTab;
	//os/2
	OS2Tab _os2Tab;
	//PCLT
	PCLTTab _pcltTab; 
	//post
	POSTTab _postTab;
	//vhea
	VHEATab _vheaTab;
	//vmtx
	VMTXTab _vmtxTab;

	OTGPOS * _sGposTable;

	std::unordered_map<OTTableEnum, CATBoolean> _mapOTTableExistence = {};
	//commonTable
	OpenTypeCommonTables _commonTable;

	//booleans to check for table is filled or not
	CATBoolean _bGDEFFilled;

	CATULONG32 FontFaceOffset = 0;

	CATBoolean _isTablesParsed = FALSE;
	/** @ nodoc */
	void CleanGPOSTab();
	/** @ nodoc */
	void CleanGlyfTab();
	/** @ nodoc */
	HRESULT ReadCoverageTable(FILE * ipFile, unsigned int iCoverageTableOffset, OTCoverageTable & oCovTab);
	/** @ nodoc */
	HRESULT ReadGDEFTable(FILE * ipFile);
	/** @ nodoc */
	HRESULT ReadCMAPTab(FILE * ipFile);	
	/**@ nodoc*/
	HRESULT ReadMaxpTab(FILE * ipFile);
	/**@ nodoc*/
	HRESULT ReadNameTable(FILE * ipFile);
	/**@ nodoc*/
	HRESULT ReadOS2Table(FILE * ipFile);
	/**@ nodoc*/
	HRESULT ReadPostTable(FILE * ipFile);
	/** @ nodoc */
	HRESULT ReadOTGPOSTable(FILE * ipFile);
	/** @ nodoc */
	HRESULT ReadKerningtable(FILE* ipFile);
	/** @ nodoc */
	HRESULT ReadHeadTable(FILE* ipFile);
	/** @ nodoc */
	HRESULT ReadHHEATable(FILE* ipFile);
	/** @ nodoc */
	HRESULT ReadPCLTTable(FILE* ipFile);
	/** @ nodoc */
	HRESULT ReadHMTXtable(FILE* ipFile);
	/** @ nodoc */
	HRESULT ReadLOCATable(FILE* ipFile);
	/** @ nodoc */
	HRESULT ReadGlyfTable(FILE* ipFile);
	/** @ nodoc */
	HRESULT ReadVHEATable(FILE* ipFile);
	/** @ nodoc */
	HRESULT ReadVMTXTable(FILE* ipFile);
	/** @ nodoc */
	HRESULT ReComputeTableEntry(FILE * ipFile, OTTableEnum itab, CATULONG32& oTableOffset, CATULONG32& oTableLength);
	

public:
	//constructors
	CATOpenTypeTables();
	CATOpenTypeTables(EFontType eFontType);

	//destructor 
	~CATOpenTypeTables();

	/** @ nodoc */
	//Function to get all supported table offsets 
	HRESULT FillTableEntries(FILE* ipFile, const CATULONG32 iFontFaceOffset, EFontType iEFontType);
	/** @ nodoc */
	HRESULT FillTableEntries(const char * ifilePath, const CATULONG32 iFontFaceOffset, EFontType iEFontType);
	/**@ nodoc*/
	HRESULT GetGDEFInfoFromOTTable(CATUC2Bytes iLeftCharCode, char& oCh);
	/**@ nodoc*/
	HRESULT GetGlyphIndexFromOTTable(unsigned short inputChar, int &oindex);
	/**@ nodoc*/
	HRESULT GetGPOSInfoFromOTTable(CATUC2Bytes iLeftCharCode, CATUC2Bytes iRightCharCode, GPOSInfo& oGPOSL, GPOSInfo& oGPOSR, char  scriptTag[5],const CATBoolean& isComplexScript=FALSE);
	/**@ nodoc*/
	HRESULT GetOS2TableInfo(int &oWeightClass, int &oWidthClass, CATULONG32 *oUCCharRange=NULL);
	/**@ nodoc*/
	int CheckGyphInCoverage(CATUC2Bytes iLeftCharCode, OTCoverageTable & iCovTable, int & oCoverageIndex);
	/**@ nodoc*/
	HRESULT GetPostTable(int &oItalicAngle, int &oUnderlinePosition, int &oUnderlineThickness, int &oIsFixedPitch);
	/**@ nodoc*/
	//Get TableEntry to get offset and table length
	HRESULT GetTableEntry(OTTableEnum iTab, CATULONG32 & oTableOffset, CATULONG32 & oTableLength);
	/**@ nodoc*/
	int GetKerningValue(CATUC2Bytes iLeftCharCode, CATUC2Bytes iRightCharCode);
	/**@ nodoc*/
	HRESULT GetFontMetrics(EFontType iEFontType, int & height, int & ascent, int & descent, int & internalLeading, int & externalLeading,
		int & averageCharWidth,	int & maxWidthChar,	int & firstChar, int & lastChar,
		int & defaultChar, int & breakChar,	int & italic, int & underlined,
		int & struckout, int & pitch,int & charSet, int & oCjkUnix);
	
	/**@ nodoc*/
	HRESULT GetNumHorMetricsFromHHEATab(unsigned short& nunmHorMetrics);
	/**@ nodoc*/
	HRESULT GetHorMetricRecordFromHHEATab(const unsigned short index, longHorMetricRecord & oLHM);
	/**@ nodoc*/
	HRESULT GetIndexToLocFormatFromHeadTab(short & oIndexToLocFormat);
	/**@ nodoc*/
	HRESULT GetGlyphOffsetFromLoca(const short iIndexToLocFormat, const int iCharIndex, unsigned short& oshortGlyfOffset, CATULONG32& oLongGlyfOffset);
	/**@ nodoc*/
	//HRESULT GetGlyphTTFOutlinesOfGlyf(int iCharIndex, int& oNumberOfPoints, OTFGlyphContourPoint** oGlyphContourPoints, int& oNumContours);
	/*HRESULT GetGlyphTTFOutlinesOfGlyf(int iCharIndex, int& oNumberOfPoints, OTFGlyphContourPoint** oGlyphContourPoints, int& oNumContours,
		int& isGlyphComposite, unsigned short*& endPointsPtr, int glyfCount, int useMyMetric, int totalNumContours);*/
	/**@ nodoc*/
	HRESULT GetTTFCharBoundingBoxFromOTTable(int charIndex, int& oYmax, int& oYmin, int& oXmax, int& oXmin);
	/**@ nodoc*/
	HRESULT GetFontNamesData(CATUnicodeString& CopyrightNotice, CATUnicodeString& FamillyName, CATUnicodeString& SubFamillyName, CATUnicodeString& UniqueFontID,
		CATUnicodeString& FullName, CATUnicodeString& Version, CATUnicodeString& PostScriptName, CATUnicodeString& TradeMark);
	/**@ nodoc*/
	int IsTablePresent(OTTableEnum iTab);
	/**@ nodoc*/
	HRESULT GetFontHeaderDataFromHHEA(unsigned short& oAdvanceWidthMax, short& oMinLeftSideBearing, short& oMinRightSideBearing, short& oXMaxExtent);
	
	/**@ nodoc*/
	HRESULT GetXExtentsOfGlyph(int charIndex, short& oXmax, short& oXmin);
	/**@ nodoc*/
	HRESULT GetYExtentsOfGlyph(int charIndex, short & oYmax, short & oYmin);
	/**@ nodoc*/
	HRESULT GetPanoseInfo(int & familyType, int& serifStyle, int& weight, int& proportion, int& contrast, int& strokeVariation,
		int& armStyle, int& letterForm, int& midLine, int& xHeight);
	/**@ nodoc*/
	CATBoolean IsFontFileParsed();
	/**@ nodoc*/
	HRESULT GetVHEAInfo(unsigned short & maxAdvanceHeight, short & minTSB, short & minBSB,	short & yMaxExtent);
	/**@ nodoc*/
	HRESULT GetNumverMetricsFromVHEA(unsigned short& numHorMetrc);
	/**@ nodoc*/
	HRESULT GetVerMetricRecordFromVHEATab(const unsigned short index, longVerMetricRecord& oLVM);
	/**@ nodoc*/
	HRESULT GetCharWidthArray(unsigned short& oWALength, int*& oWidthArray);
	/**@ nodoc*/
	HRESULT GetAllGlyphIndices(int* opIndices, unsigned short iStartChar, unsigned short iEndChar);
};
#endif

