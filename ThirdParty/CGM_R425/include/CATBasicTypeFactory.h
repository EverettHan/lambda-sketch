#ifndef _CATBasicTypeFactory_H
#define _CATBasicTypeFactory_H

#include <IntroInfra.h>
#include <CATBaseUnknown.h>
#include <CATListOfCATUnicodeString.h>
#include <CATUnicodeString.h>
#include <CATSYPFactoryResult.h>

class CATString;

/**
* This utility function will help you to transform a string into list of strings, for use in Factory functions.
*   - In the case of a list of values separated by spaces, it will split it and return a list of these values (in o_firstList)
*     Ex : "15 200 120 255" -> {"15","200","120","255"}
*   - In the case of a list of value names + values (format is "ValueName1=Value1 ValueName2=Value2 ...")
*     It will return two lists :
*     o_firstList will contain the name of the values
*     o_secondList will contain the values itselves
*     Ex : "x=1 y=2 xSpan=2 attach=RL" -> {"x","y","xSpan","attach"} & {"1","2","2","RL"}
*/
extern "C" ExportedByIntroInfra 
HRESULT ParseAttributeString(const CATUnicodeString &i_string, CATListOfCATUnicodeString& o_firstList, CATListOfCATUnicodeString& o_secondList, const CATUnicodeString& i_separatorChar=" ");

/**
* CATMathPointf factory
* <FormatDocumentation>
* Expected : 3 floats, corresponding to the 3 coordinates of a point : x,y,z
* <FormatDocumentation>
* <FormatRegExp>
* "\\d*(\\.\\d*f?)?\\s\\d*(\\.\\d*f?)?\\s\\d*(\\.\\d*f?)?\"
* <FormatRegExp>
*/
extern "C" ExportedByIntroInfra 
CATSYPFactoryResult CATSYPCATMathPointfFactory(const CATUnicodeString& i_string);
extern "C" ExportedByIntroInfra 
HRESULT CATSYPCATMathPointfSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

extern "C" ExportedByIntroInfra 
CATSYPFactoryResult CATSYPintFactory(const CATUnicodeString& i_string);
extern "C" ExportedByIntroInfra 
HRESULT CATSYPintSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

extern "C" ExportedByIntroInfra 
CATSYPFactoryResult CATSYPdoubleFactory(const CATUnicodeString& i_string);
extern "C" ExportedByIntroInfra 
HRESULT CATSYPdoubleSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

extern "C" ExportedByIntroInfra 
CATSYPFactoryResult CATSYPfloatFactory(const CATUnicodeString& i_string);
extern "C" ExportedByIntroInfra 
HRESULT CATSYPfloatSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

extern "C" ExportedByIntroInfra 
CATSYPFactoryResult CATSYPCATUnicodeStringFactory(const CATUnicodeString& i_string);
extern "C" ExportedByIntroInfra 
HRESULT CATSYPCATUnicodeStringSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

extern "C" ExportedByIntroInfra 
CATSYPFactoryResult CATSYPCATUnicodeCharFactory(const CATUnicodeString& i_string);
extern "C" ExportedByIntroInfra 
HRESULT CATSYPCATUnicodeCharSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

extern "C" ExportedByIntroInfra 
CATSYPFactoryResult CATSYPCATListOfCATUnicodeStringFactory(const CATUnicodeString& i_string);
extern "C" ExportedByIntroInfra 
HRESULT CATSYPCATListOfCATUnicodeStringSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

extern "C" ExportedByIntroInfra 
CATSYPFactoryResult CATSYPCATStringFactory(const CATUnicodeString& i_string);
extern "C" ExportedByIntroInfra 
HRESULT CATSYPCATStringSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

extern "C" ExportedByIntroInfra
CATSYPFactoryResult CATSYPCATMathPoint2DfFactory(const CATUnicodeString& i_string);
extern "C" ExportedByIntroInfra 
HRESULT CATSYPCATMathPoint2DfSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

extern "C" ExportedByIntroInfra
CATSYPFactoryResult CATSYPCATMathDirection2DfFactory(const CATUnicodeString& i_string);
extern "C" ExportedByIntroInfra 
HRESULT CATSYPCATMathDirection2DfSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

extern "C" ExportedByIntroInfra
CATSYPFactoryResult CATSYPCATMathVector2DfFactory(const CATUnicodeString& i_string);
extern "C" ExportedByIntroInfra 
HRESULT CATSYPCATMathVector2DfSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

extern "C" ExportedByIntroInfra
CATSYPFactoryResult CATSYPCATMathVectorfFactory(const CATUnicodeString& i_string);
extern "C" ExportedByIntroInfra 
HRESULT CATSYPCATMathVectorfSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

extern "C" ExportedByIntroInfra
CATSYPFactoryResult CATSYPCATMathQuaternionFactory(const CATUnicodeString& i_string);
extern "C" ExportedByIntroInfra 
HRESULT CATSYPCATMathQuaternionSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

extern "C" ExportedByIntroInfra 
CATSYPFactoryResult CATSYPCATMathPointFactory(const CATUnicodeString& i_string);
extern "C" ExportedByIntroInfra 
HRESULT CATSYPCATMathPointSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

extern "C" ExportedByIntroInfra
CATSYPFactoryResult CATSYPCATMathVectorFactory(const CATUnicodeString& i_string);
extern "C" ExportedByIntroInfra 
HRESULT CATSYPCATMathVectorSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

extern "C" ExportedByIntroInfra
CATSYPFactoryResult CATSYPCATMathDirectionFactory(const CATUnicodeString& i_string);
extern "C" ExportedByIntroInfra 
HRESULT CATSYPCATMathDirectionSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

extern "C" ExportedByIntroInfra
CATSYPFactoryResult CATSYPCATMathDirectionfFactory(const CATUnicodeString& i_string);
extern "C" ExportedByIntroInfra 
HRESULT CATSYPCATMathDirectionfSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

extern "C" ExportedByIntroInfra
CATSYPFactoryResult CATSYPCATMathLineFactory(const CATUnicodeString& i_string);
extern "C" ExportedByIntroInfra 
HRESULT CATSYPCATMathLineSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

extern "C" ExportedByIntroInfra
CATSYPFactoryResult CATSYPCATMathPlaneFactory(const CATUnicodeString& i_string);
extern "C" ExportedByIntroInfra 
HRESULT CATSYPCATMathPlaneSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

/*extern "C" ExportedByIntroInfra
CATSYPFactoryResult CATSYPCATTimeFactory(const CATUnicodeString & i_string);*/
extern "C" ExportedByIntroInfra
HRESULT CATSYPCATTimeSerializer(const CATBaseUnknown_var & i_spCBU, CATUnicodeString & o_string);

#endif
