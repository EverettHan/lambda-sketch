#ifndef CATMathJSONServices_H
#define CATMathJSONServices_H

#include "CATIAV5Level.h"

#ifdef CATIAR425 

#include "DSYSysJSON.h"
#include "DSYExport.h"

#include <vector>
#include <string>

class CATMathVector;
class CATMathPoint;
class CATMath3x3Matrix;
class CATMathTransformation;
class CATMathAxis;


/**
 * namespace with method to convert CATMath... into JsonValue via DSYSysJson :
 *  - CATMathJSON::math(...) convert DSYSysJSONValue to CATMath...
 *  - CATMathJSON::json(...) convert CATMath... to DSYSysJSONValue
 * 
 * check the different CATMathJSON::json to see the how math object are decomposed in JSON Data model.
 * 
 * Current type implemented (will evolved in time):
 *  - CATMathPoint, CATMathVector => {"X":1.0,"Y":2.0,"Z":3.0 }
 *  - CATMath3x3Matrix  => {"I":{"X":1.0,"Y":0.0,"Z":0.0 },"J":{"X":1.0,"Y":1.0,"Z":0.0 },"K":{"X":0.0,"Y":0.0,"Z":1.0 }}
 *  - CATMathTransformation, CATMathAxis => {"Position":{sameasVector},"Orientation":{sameAs3x3Matrix}  }
 * 
 * @section HOWTOJSONMATH Save CATMath... to json 
 * 
 * 
 * @code 
 *    CATMathTransformation TransfoA(CATMathVector(0,0,2));
 *    CATMathTransformation TransfoB(CATMathVector(0,0,3));
 * 
 *    DSYSysJSONObject toSave;
 *    
 *    CATMathJSON::addTo(toSave,"A",CATMathJSON::json(TransfoA)); // equivalent to toSave.Push(DSYSysJSONPair("A",CATMathJSON::json(TransfoA)));
 *    CATMathJSON::addTo(toSave,"B",CATMathJSON::json(TransfoB,CATMathJSON::Options(true) ));
 * 
 *    std::ofstream filejson("monfichier.json");
 *    filejson << CATMathJSON::toString(DSYSysJSONValue(toSave));
 * @endcode
 *  Should look like
 * @code
 *  {
 *    "A":{
 *          "Position":{"X":0,"Y":0,"Z":2},
 *          "Orientation":{
 *            "I":{ "X":1,"Y":0,"Z":0},
 *            "J":{ "X":0,"Y":1,"Z":0},
 *            "K":{ "X":0,"Y":0,"Z":1}
 *           }
 *        },
 *     "B":[1,0,0, 0,1,0, 0,0,1, 0,0,3]
 *  }
 * @endcode 
 * 
 * @section HOWTOMATHJSON Load  CATMath... from json 
 * 
 * @code
 *    DSYSysJSONValue jsonData = CATMathJson::readFromFile("monfichier.json");
 *    CATMathTransformation TransfoA;
 *    CATMathTransformation TransfoB;
 * 
 *    CATMathJSON::math( jsonData["A"], TransfoA);
 *    CATMathJSON::math( jsonData["B"], TransfoB);
 *    
 * @endcode
 */
namespace CATMathJSON
{
  class DSYExport Options
  {
    public:
    Options(bool iAsArray = false );
    
    bool asArray = false;//!< if true the math object with coefficient will be dump has array
  };

  /**
  * @brief Add an attribute to an object
  * @remark
  *   equivalent to Push method of DSYSysJSONObject
  * @code
  *    CATMathJSON::addTo(obj,"ID",value);
  *    obj.Push(DSYSysJSONPair("ID",value));
  * @endcode
  */
  template< typename jsonTYPE >
  void addTo(DSYSysJSONObject & obj, const char * ID, const jsonTYPE & value)
  {
    DSYSysJSONPair pair(ID, value);
    obj.Push(pair);
  }
  
  /**
   * Open a json file
   * @param[in] iFilename valid file path name
  */
  DSYSysJSONValue DSYExport readFromFile(const char * iFilename);
  
  /**
   * write the json value in text format into a text file.
   * @param[in] iFilename valid file path name
  */
  bool DSYExport writeToFile(const DSYSysJSONValue & iValue,const char *iFilename);

  /**
  * @brief convert math object CATMathVector to json data object
  * 
  * @param[in] iAsArray if true the json object will be an array that contains the coeff of the object (less readable than in structure but more compact)
  * 
  * @code
  *   CATMathVector V(1,2,3);
  *   DSYSysJSONValue asStruct = CATMathJSON::json(V);
  *   DSYSysJSONValue asArray = CATMathJSON::json(V,true);
  *   DSYSysJSONObject sample;
  *   CATMathJSON::addTo(sample,"asStruct",asStruct); 
  *   CATMathJSON::addTo(sample,"asArray",asArray);
  *   //sample contains this data 
  *   // {
  *   //  "asStruct":{ "X":1,"Y":2,"Z":3},
  *   //  "asArray": [1,2,3]
  *   // }
  * 
  * @endcode
  **/
  DSYSysJSONValue DSYExport json(const CATMathVector &oData,const Options & iOptions=Options());
  bool DSYExport math(const DSYSysJSONValue & iJSON, CATMathVector & oData);


  /**
  * @brief convert math object CATMathPoint to json data object
  * 
  * @param[in] iAsArray if true the json object will be an array that contains the coeff of the object (less readable than in structure but more compact)
  * 
  * @code
  *   CATMathPoint V(1,2,3);
  *   DSYSysJSONValue asStruct = CATMathJSON::json(V);
  *   DSYSysJSONValue asArray = CATMathJSON::json(V,true);
  *   DSYSysJSONObject sample;
  *   CATMathJSON::addTo(sample,"asStruct",asStruct); 
  *   CATMathJSON::addTo(sample,"asArray",asArray);
  *   //sample contains this data 
  *   // {
  *   //  "asStruct":{ "X":1,"Y":2,"Z":3},
  *   //  "asArray": [1,2,3]
  *   // }
  * 
  * @endcode
  **/
  DSYSysJSONValue DSYExport json(const CATMathPoint &oData,const Options & iOptions=Options());
  bool DSYExport math(const DSYSysJSONValue & iJSON, CATMathPoint & oData);

  
  /**
  * @brief convert math object CATMath3x3Matrix to json data object
  * 
  * @param[in] iAsArray if true the json object will be an array that contains the coeff of the object (less readable than in structure but more compact)
  * 
  * @code
  *   CATMath3x3Matrix M;//Identity
  *   DSYSysJSONValue asStruct = CATMathJSON::json(V);
  *   DSYSysJSONValue asArray = CATMathJSON::json(V,true);
  *   DSYSysJSONObject sample;
  *   CATMathJSON::addTo(sample,"asStruct",asStruct); 
  *   CATMathJSON::addTo(sample,"asArray",asArray);
  *   //sample contains this data 
  *   // {
  *   //  "asStruct":{ 
  *   //                 "I":{ "X":1,"Y":0,"Z":0},
  *   //                 "J":{ "X":0,"Y":1,"Z":0},
  *   //                 "K":{ "X":0,"Y":0,"Z":1}
  *   //              },
  *   //  "asArray": [1,0,0,0,1,0,0,0,1]
  *   // }
  * 
  * @endcode
  **/
  DSYSysJSONValue DSYExport json(const CATMath3x3Matrix &oData,const Options & iOptions=Options());
  bool DSYExport math(const DSYSysJSONValue & iJSON, CATMath3x3Matrix & oData);


  /**
  * @brief convert math object CATMathTransformation to json data object
  * 
  * @param[in] iAsArray if true the json object will be an array that contains the coeff of the object (less readable than in structure but more compact)
  * 
  * @code
  *   CATMathTransformation M;//Identity
  *   DSYSysJSONValue asStruct = CATMathJSON::json(V);
  *   DSYSysJSONValue asArray = CATMathJSON::json(V,true);
  *   DSYSysJSONObject sample;
  *   CATMathJSON::addTo(sample,"asStruct",asStruct); 
  *   CATMathJSON::addTo(sample,"asArray",asArray);
  *   //sample contains this data 
  *   // {
  *   //  "asStruct":{ 
  *   //        "Position":{"X":0,"Y":0,"Z":0},
  *   //        "Orientation":{
  *   //                "I":{ "X":1,"Y":0,"Z":0},
  *   //                "J":{ "X":0,"Y":1,"Z":0},
  *   //                "K":{ "X":0,"Y":0,"Z":1}
  *   //                 }
  *   //              },
  *   //  "asArray": [1,0,0,0,1,0,0,0,1, 0,0,0]
  *   // }
  * 
  * @endcode
  **/
  DSYSysJSONValue DSYExport json(const CATMathTransformation &oData,const Options & iOptions=Options());
  bool DSYExport math(const DSYSysJSONValue & iJSON, CATMathTransformation & oData);


  /**
  * @brief convert math object CATMathAxis to json data object
  * 
  * @param[in] iAsArray if true the json object will be an array that contains the coeff of the object (less readable than in structure but more compact)
  * 
  * @code
  *   CATMathAxis M;//Identity
  *   DSYSysJSONValue asStruct = CATMathJSON::json(V);
  *   DSYSysJSONValue asArray = CATMathJSON::json(V,true);
  *   DSYSysJSONObject sample;
  *   CATMathJSON::addTo(sample,"asStruct",asStruct); 
  *   CATMathJSON::addTo(sample,"asArray",asArray);
  *   //sample contains this data 
  *   // {
  *   //  "asStruct":{ 
  *   //        "Position":{"X":0,"Y":0,"Z":0},
  *   //        "Orientation":{
  *   //                "I":{ "X":1,"Y":0,"Z":0},
  *   //                "J":{ "X":0,"Y":1,"Z":0},
  *   //                "K":{ "X":0,"Y":0,"Z":1}
  *   //                 }
  *   //              },
  *   //  "asArray": [1,0,0,0,1,0,0,0,1, 0,0,0]
  *   // }
  * 
  * @endcode
  **/
  DSYSysJSONValue DSYExport json(const CATMathAxis &oData,const Options & iOptions=Options());
  bool DSYExport math(const DSYSysJSONValue & iJSON, CATMathAxis & oData);


  
  template<typename BasicType>
  DSYSysJSONValue json(const BasicType & iVal,const Options & iOptions=Options())
  {
    DSYSysJSONValue V;V.Set(iVal); return V;
  }


  template<typename Type>
  DSYSysJSONValue json(const std::vector<Type> & iArray,const Options & iOptions=Options())
  {
    DSYSysJSONArray arrayJson;
    for(auto & e : iArray )
    {
      arrayJson.Push(json(e,iOptions));
    }
    return json(arrayJson);
  };

  bool DSYExport math(const DSYSysJSONValue & iValue, double& oValue);
  bool DSYExport math(const DSYSysJSONValue & iValue, int& oValue);
  bool DSYExport math(const DSYSysJSONValue & iValue, std::string & oValue);
  bool DSYExport math(const DSYSysJSONValue & iValue, DSYSysJSONValue & oValue);

  template<typename BasicType>
  bool math(const DSYSysJSONValue & iValue, std::vector<BasicType> &oArray )
  {
    bool resu = true;
    if (iValue.IsArray())
    {
      DSYSysJSONArray & a = ((DSYSysJSONValue&)iValue).ToArray();
      a.Every([&](auto & v)
      {
        BasicType oVal;
        resu = math(v,oVal);
        oArray.push_back(oVal);
        return resu;
      }
      );
    }
    else
    {
      resu = false;
    }
    return resu;
  };

  typedef enum JSONTextFormatEnum
  {
    COMPACT,  /*!< no new line all the json is compacted without white space ,not very human readable but compact */
    EXPANDED, /*!< all node of the json are expanded in a tree structure with newline and tabulation for each scope */
    PRETTY    /*!< same a expand but some array of basic type (number,string) stay on one line, it is readable but more compact that EXPANDED */
  } JSONTextFormat ;


  /**
   * transform JsonValue into string
   * @param[in]  iValue the json value to transform in string
   * @param[in]  iFormat default PRETTY, how the string is formatted @see JSONTextFormat
  */
  std::string DSYExport toString(const DSYSysJSONValue & iValue, JSONTextFormat iFormat = PRETTY );

  bool DSYExport toBsonFile(const DSYSysJSONValue & iValue,std::string filename);
  DSYSysJSONValue DSYExport fromBson(std::istream & iStream );
  DSYSysJSONValue DSYExport fromBsonFile(std::string & filename );
}
#else
  #ifdef _WINDOWS_SOURCE
    #pragma message("DSYSysJson not available in before R425")
  #endif 
#endif

#endif
