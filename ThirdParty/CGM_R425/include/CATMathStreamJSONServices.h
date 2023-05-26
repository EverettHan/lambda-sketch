#ifndef CATMathStreamJSONServices_H
#define CATMathStreamJSONServices_H


#include "CATIAV5Level.h"
#ifdef CATIAR425 

#include "DSYExport.h"
#include "CATUnicodeString.h"
#include <vector>
#include <string>
#include <map>
#include <unordered_map>


#include "DSYSysJSON.h"


/**
  macro to gen a param from a JSON stream (use CATMathStreamJSONServices )
  CM_CheckAndGetParam(jsonstream, "parmaname", outputresu )

  return true if the parameter is found in jsonstream and outputresu contains the data.
*/
#define CMSJS_CheckAndGetParam CATMathStreamJSONServices::Default().CheckAndGet
#define CMSJS_InitArraySize(from, name,iArray) iArray.resize(from[name].ToArray().Count()>iArray.size()?from[name].ToArray().Count():iArray.size());

#define CMSJSLoadJsonFile(filename, jsondata) CATMathStreamJSONServices::OpenJsonFile(filename, jsondata); CATMathStreamJSONServices::Default().LoadSubFile(jsondata);
#define CMSJS_PrettyJSON(jsonval) CATMathStreamJSONServices::Beautify(jsonval)

/**
  Different service accessible via a singleton CATMathStreamJSONServices::Default()
  to help parse and get parameter from  input file ( json,... )
  and replace some token by variable value like for example
    $ADL_ODT_INT
    ...

*/
class DSYExport CATMathStreamJSONServices
{
public:

  /**
   *  open the json stream from a file.
   *  @param iFilename a valid path on a valid json file.
   * **/
  static bool OpenJsonFile(const char * iFilename,DSYSysJSONValue  &oStream);
  static CATUnicodeString Beautify(DSYSysJSONValue & value, CATUnicodeString tab=CATUnicodeString("  "));

  static CATMathStreamJSONServices &  Default();//Singleton acces 
 /**
   @brief construct a CATMathStreamJSONServices instance , you can also use the singleton via CATMathStreamJSONServices::Default().method

   @param autoRegisterStandardVariable if true call RegisterEnvVariable with the value:
     ADL_ODT_IN
     ADL_ODT_OUT
     ADL_IMAGE_DOS_DIR
     ADL_IMAGE_DIR
     ODT_LOG_NAME
 */
  CATMathStreamJSONServices(bool autoRegisterStandardVariable = true, bool iLogWarning = false, bool iLogOnVariableChange = false, bool iLogOnReadfromfile = false);


  /**
    @brief Register Variable ($keyword) which will be replace by ReplaceVariables with the replacement value
    @param[in] ikeyword Symbol to be replaced
    @param[in] ireplacement replacement value

    for example :

    CATMathStreamJSONServices:Default.RegisterVariable("USER","toto");
    CATMathStreamJSONServices:Default.RegisterVariable("Computer","LP5-XYZ");
    auto newstring = CATMathStreamJSONServices:Default.ReplaceVariables("Dear $User Your Computer is $Computer!");
    //newstring will contains 'Dear toto Your Computer is LP5-XYZ!"'

  */
  bool RegisterVariable(CATUnicodeString ikeyword, CATUnicodeString ireplacement);

  /**
    @brief same as RegisterVariable but second parameter will be found with a 'getenv' (if getenv return nullptr a warning is printed')
    @parameter iEnvVarName name of an environement variable
  */
  bool RegisterEnvVariable(CATUnicodeString iEnvVarName);
  

  /**
    @brief Replace $Variable by the replacement value previously register by Register...Variable or using ireplacementMap if not null

    CATMathStreamJSONServices:Default.RegisterEnvVariable("ADL_ODT_IN");
    CATMathStreamJSONServices:Default.RegisterVariable("Computer","LP5-XYZ");
    auto newstring = CATMathStreamJSONServices:Default.ReplaceVariables("file is on $Computer in path $ADL_ODT_IN");
    //newstring will contains 'file is on LP5-XYZ in path E:\WS\CATManufUtilities.tst\FunctionTest\InputData'

  */
  CATUnicodeString ReplaceVariables(const CATUnicodeString &initial, std::map<CATUnicodeString, CATUnicodeString> * ireplacementMap = nullptr);
  CATUnicodeString ReplaceVariables(const char* initial, std::map<CATUnicodeString, CATUnicodeString>  * ireplacementMap = nullptr);
  std::string ReplaceVariables(const std::string &initial, std::map<CATUnicodeString, CATUnicodeString>  * ireplacementMap = nullptr);

  /*
  * replace all sub file by the content of the subfile recursively.
  * @param ireplaceEnvVar auto replace all register variable in the file;
  */
  void LoadSubFile(DSYSysJSONValue & iofrom,bool ireplaceEnvVar=true, CATUnicodeString attributeName = CATUnicodeString());
  //JSON HELPER _____________________________________________________________________________
  // CheckAndGet will search into ifrom a property named (iname) of type typeof(oResu)
  // Remareque it the parameter 'iname' is a json filename , CheckAndGet will open it to find the parameter in
  // the sub file, this allow to split input file in several splitted files.
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, CATUnicodeString &oResu, bool ErrorIfNot = true);
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, std::vector<CATUnicodeString> &oResu, bool ErrorIfNot = true);
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, double &oResu, bool ErrorIfNot = true);
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, std::vector<double> &oResu, bool ErrorIfNot = true);
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, int &oResu, bool ErrorIfNot = true);
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, unsigned int &oResu, bool ErrorIfNot = true);
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, DSYSysJSONValue &oResu, bool ErrorIfNot = true);
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, std::vector<DSYSysJSONValue> &oResu, bool ErrorIfNot = true);
  //all kind of int
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, int8_t &oResu, bool ErrorIfNot = true);
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, uint8_t &oResu, bool ErrorIfNot = true);
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, int16_t &oResu, bool ErrorIfNot = true);
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, uint16_t &oResu, bool ErrorIfNot = true);
  //bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, int32_t &oResu, bool ErrorIfNot=true); 
  //bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, uint32_t &oResu, bool ErrorIfNot=true); 
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, int64_t &oResu, bool ErrorIfNot = true);
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, uint64_t &oResu, bool ErrorIfNot = true);
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, bool &oResu, bool ErrorIfNot = true);
  //all kind of int array
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, std::vector<int8_t> &oResu, bool ErrorIfNot = true);
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, std::vector<uint8_t> &oResu, bool ErrorIfNot = true);
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, std::vector<int16_t> &oResu, bool ErrorIfNot = true);
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, std::vector<uint16_t> &oResu, bool ErrorIfNot = true);
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, std::vector<int32_t> &oResu, bool ErrorIfNot = true);
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, std::vector<uint32_t> &oResu, bool ErrorIfNot = true);
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, std::vector<int64_t> &oResu, bool ErrorIfNot = true);
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, std::vector<uint64_t> &oResu, bool ErrorIfNot = true);
  bool CheckAndGet(DSYSysJSONValue & ifrom, const char*iname, std::vector<bool> &oResu, bool ErrorIfNot = true);


  /**
    class to override to add new type for CheckAndGet
  */
  class DSYExport CheckAndGetPlugin
  {
  public:
    /*
    must be override for your new type 
    
    example for CATMathPoint with json as {"X":0,"Y":0,"Z":2} 
    @code
    virtual bool CheckAndGet(CATMathStreamJSONServices & ibaseHelper, DSYSysJSONValue & ifrom, const char*iname,void *&datatocast,bool ErrorIfNot )
    {
      CATMathPoint & resu = *(CATMathPoint*)(datatocast);
      double X = resu.GetX();
      double Y = resu.GetY();
      double Z = resu.GetZ();
      ibaseHelper.CheckAndGet(ifrom,"X",X);
      ibaseHelper.CheckAndGet(ifrom,"Y",Z);
      ibaseHelper.CheckAndGet(ifrom,"Z",Z);
      resu.setX(X);resu.setX(Y);resu.setX(Z);
      return true;
    }
    @endcode
    
    */
    virtual bool CheckAndGet(CATMathStreamJSONServices & ibaseHelper, DSYSysJSONValue & ifrom, const char*iname,void *&datatocast,bool ErrorIfNot );
    virtual ~CheckAndGetPlugin();
  };


  template<typename USERTYPE>
  /**
    generic CheckAndGet for non-basic type like CATMathPoint {"X":0,"Y":0,"Z":0}, only itypeid type with a 
    a plugin register with RegisterUserCheckAndGet will be analyse.
  */
  bool CheckAndGet(DSYSysJSONValue & ifrom,const std::string itypeid, const char*iname, USERTYPE &oResu, bool ErrorIfNot = true)
  {
    bool resu = false;
    auto  find = _Plugins.find(itypeid);
    if (find!=_Plugins.end())
    {
      auto & plugin = _Plugins[itypeid];
      void * decast = (USERTYPE*)(&oResu);
      DSYSysJSONValue fromfile;                                           
      if (true==tryfromfile(ifrom,iname,fromfile)) //is it a sub file ? 
      {
        resu = plugin->CheckAndGet(*this,fromfile,iname,decast,ErrorIfNot);     
      }
      else
      {
        resu = plugin->CheckAndGet(*this,ifrom,iname,decast,ErrorIfNot);
      } 
    }
    else
    {
      printf("[Error] No CheckAndGetPlugin was register with RegisterUserCheckAndGet for the type='%s' cannot read\n",itypeid.c_str());
    }
    return resu;
  };
 
  bool RegisterUserCheckAndGet(const char * itypeid, CheckAndGetPlugin &iPlugin);
  void UnRegisterUserCheckAndGet(const char * itypeid);
  //DEBUG LOG Information 
  void SetLogWarning(bool ilog);
  bool GetLogWarning()const;
  void SetLogOnVariableChange(bool ilog);
  bool GetLogOnVariableChange()const;
  void SetLogOnReadFromFile(bool ilog);
  bool GetLogOnReadFromFile()const;


  /**
      Remove Cpp style comment 
        
      - multiline : /*  multiline comment *\/
      - monoline : // monoline 
      @param[in] initial : the initial source 
      @return initila with comment removed
    */
    static CATUnicodeString RemoveCppComment(const CATUnicodeString &initial);

    /**
      return true this json element is an array ( start by [ )
      @param json element
      @return true for a json array
    */
    static bool JSONIsArray(DSYSysJSONValue & iToTest, const char * prop=nullptr );

    /**
      return true this json element is an object ( start by { )
      @param json element
      @return true for a json object
    */
    static bool JSONIsObject(DSYSysJSONValue & iToTest , const char * prop=nullptr);


  std::map<CATUnicodeString, CATUnicodeString >  GetVariableMapping() const ;

    /**
    @brief
    Try to read the parameter name from an external json file
    this allow to split some json in different file in standard way
    {
      dimension:3,
      shape:["abc","def"]
    }
    become
    {
      dimension:3,
      shape:"otherfile.json"
    }
    with otherfile.json contains
    {
      shape:["abc","def"]
    }
  */
  bool tryfromfile(DSYSysJSONValue ifrom, CATUnicodeString name, DSYSysJSONValue & fromfile);
protected:


  std::map<CATUnicodeString, CATUnicodeString >  _Variables;

  //debug prinf flag
  bool _LogWarning = true;
  bool _LogOnVariableChange = false;
  bool _LogOnReadFromFile = false;

  std::unordered_map<std::string,CheckAndGetPlugin*> _Plugins; 

  static CATMathStreamJSONServices _Default;
};


//______________________________________________________
// CheckAndGetPlugin helper

/**
CheckAndGetPluginArrays is generic helper to create Plugin for std::vector<ELEMENTYPE>, for any
ELEMENTYPE previously register by

CATMathStreamJSONServices::RegisterUserCheckAndGet

@code 
  CheckAndGetPluginMyType pluginMyType;
  CATMathStreamJSONServices::Default().RegisterUserCheckAndGet("MyType",pluginMyType);
  //then for vector just do 
  CheckAndGetPluginArrays<MyType> pluginMyTypeVector("MyType");
  CATMathStreamJSONServices::Default().RegisterUserCheckAndGet("std::vector<MyType>",pluginMyTypeVector);
  
  //now we can use 
  std::vector<MyType> data;
  CM_CheckAndGetParam(jsoninput,"std::vector<MyType>","id",data);

  
@code
*/
template<typename ELEMENTYPE >
class DSYExport CheckAndGetPluginArrays : public CATMathStreamJSONServices::CheckAndGetPlugin
{
public:
  CheckAndGetPluginArrays(const char * iNAME_ELEMENTTYPE)
  {
    _ElementType = iNAME_ELEMENTTYPE;
  }
    virtual bool CheckAndGet(CATMathStreamJSONServices & ibaseHelper, DSYSysJSONValue & ifrom, const char*iname,void *&datatocast,bool ErrorIfNot )
    {
      bool valid = true;
      std::vector<ELEMENTYPE> & resu = *(std::vector<ELEMENTYPE>*)(datatocast);
      std::vector<DSYSysJSONValue>  arraytyped;
      valid &= ibaseHelper.CheckAndGet(ifrom,iname, arraytyped,ErrorIfNot);//read arrays
      int i =0;
      if (valid)
      {
        for (auto & json:arraytyped )
        {
          DSYSysJSONObject fakeparent;
          fakeparent.Set(iname,json);
          DSYSysJSONValue fakeParentValue(fakeparent);
          ELEMENTYPE elem;
          bool  localvalid = ibaseHelper.CheckAndGet(fakeParentValue,_ElementType,iname,elem);
         
          valid &=localvalid; 
          if (localvalid==false)
          {
            CATUnicodeString jsonstr;
            json.Stringify(jsonstr);
            printf("[Error] %s[%d] is not a valid %s\n%s\n",iname,i,_ElementType,jsonstr.ConvertToChar());
          }
          resu.push_back(elem);
        }
        
      }
      return valid;
    }

    
protected:
   const char * _ElementType = nullptr;

};


//PLugin that handle CATMathTypes 

/*
* Call this to enable the catmathtype plugin
* @param iService if null CATMathStreamJSONServices::Default is use 
*/
bool DSYExport RegisterCheckAndGetCATMathExtension(CATMathStreamJSONServices * iService=nullptr);

/**
 Plugin to read CATMathPoint from json
 2 json format are accepted
 
 @code
 //by coordinate
 "MyPoint":{ "X":0,"Y":0,"Z":0 }
 //by array
 "MyPoint":[0,0,0]
 @endcode
*/
class DSYExport CheckAndGetPluginCATMathPoint : public CATMathStreamJSONServices::CheckAndGetPlugin
  {
  public:
    virtual bool CheckAndGet(CATMathStreamJSONServices & ibaseHelper, DSYSysJSONValue & ifrom, const char*iname,void *&datatocast,bool ErrorIfNot );
};

/**
 Plugin to read CATMathVector from json
 2 json format are accepted
 
 @code
 //by coordinate
 "MyPoint":{ "X":0,"Y":0,"Z":0 }
 //by array
 "MyPoint":[0,0,0]
 @endcode
*/
class DSYExport CheckAndGetPluginCATMathVector : public CATMathStreamJSONServices::CheckAndGetPlugin
  {
  public:
  
    virtual bool CheckAndGet(CATMathStreamJSONServices & ibaseHelper, DSYSysJSONValue & ifrom, const char*iname,void *&datatocast,bool ErrorIfNot );
};


/**
 Plugin to read CATMath3x3Matrix from json
 2 json format are accepted (depends on CATMathVector format @see CheckAndGetPluginCATMathVector) 
 
 @code
 //by coordinate
 "MyMatrix":{
   "XAxis": ValidJSONForCATMathVector..},
   "YAxis": ValidJSONForCATMathVector..},
   "ZAxis": ValidJSONForCATMathVector..}
   }
 //by array
 "MyMatrix":[0,0,0,0,0,0,0,0,0];
 @cendode
*/
class DSYExport CheckAndGetPluginCATMath3x3Matrix : public CATMathStreamJSONServices::CheckAndGetPlugin
  {
  public:
    virtual bool CheckAndGet(CATMathStreamJSONServices & ibaseHelper, DSYSysJSONValue & ifrom, const char*iname,void *&datatocast,bool ErrorIfNot );    
};


/**
 Plugin to read CATMathAxis from json
 2 json format are accepted (depends on CATMathPoint,CATMath3x3Matrix format @see CheckAndGetPluginCATMathVector) 
 
 @code
 //by coordinate
 "MyAxis":{
   "Position": ValidJSONForCATMathPoint..},
   "Orientation": ValidJSONForCATMath3x3Matrix..}
   }
 //by array
 "MyAxis":[0,0,0,0,0,0,0,0,0, 0,0,0];
 @cendode
*/
class DSYExport CheckAndGetPluginCATMathAxis : public CATMathStreamJSONServices::CheckAndGetPlugin
  {
  public:
    virtual bool CheckAndGet(CATMathStreamJSONServices & ibaseHelper, DSYSysJSONValue & ifrom, const char*iname,void *&datatocast,bool ErrorIfNot );    
};


/**
 Plugin to read CATMathTransformation from json
 2 json format are accepted (depends on CATMathPoint,CATMath3x3Matrix format @see CheckAndGetPluginCATMathVector) 
 
 @code
 //by coordinate
 "MyTransfo":{
   "Position": ValidJSONForCATMathPoint..},
   "Orientation": ValidJSONForCATMath3x3Matrix..}
   }
 //by array
 "MyTransfo":[0,0,0,0,0,0,0,0,0, 0,0,0];
 @cendode
*/
class DSYExport CheckAndGetPluginCATMathTransformation : public CATMathStreamJSONServices::CheckAndGetPlugin
  {
  public:
    virtual bool CheckAndGet(CATMathStreamJSONServices & ibaseHelper, DSYSysJSONValue & ifrom, const char*iname,void *&datatocast,bool ErrorIfNot );    
};


#endif //R425

#endif
