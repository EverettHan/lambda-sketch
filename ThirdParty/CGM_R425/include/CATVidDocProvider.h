#ifndef CATVidDocProvider_H
#define CATVidDocProvider_H

#include "VisuDialogEx.h"
#include "CATBoolean.h"
#include "CATBaseUnknown.h"

class IntrospectionParserManager;
class CATUnicodeString;
class l_CATVidCtlForm;

 
/**
* Interface to provide documentation for classes, methods, introspectable properties, enums ...
* @see CATVidDoxygenXMLDocProvider
*/
class ExportedByVisuDialogEx CATVidDocProvider : public CATBaseUnknown
{
  CATDeclareClass;

public :
  /**
   * @return richtext documentation for given class
  */
  virtual CATUnicodeString GetXHTMLClassDocumentation(const CATUnicodeString& i_ClassName, CATBoolean i_FullDoc = FALSE) const = 0;
  /**
   * @return plain text documentation for given class
  */
  virtual CATUnicodeString GetClassDocumentation(const CATUnicodeString& i_ClassName, CATBoolean i_FullDoc = FALSE) const = 0;
  /**
   * @param i_FormattedMethodName short signature of the method : "ClassName::FunctionName"
   * @return richtext documentation for given method
  */
  CATUnicodeString GetXHTMLMethodDocumentation(const CATUnicodeString& i_FormattedMethodName, CATBoolean i_AllowCodeExample = FALSE) const;
  /**
   * @param i_FormattedMethodName short signature of the method : "ClassName::FunctionName"
   * @return plain text documentation for given method
  */
  CATUnicodeString GetMethodDocumentation(const CATUnicodeString& i_FormattedMethodName, CATBoolean i_AllowCodeExample = FALSE) const;
  /**
   * @param i_ClassName the class name
   * @param i_ClassName the method name
   * @return richtext documentation for given method of given class
  */
  virtual CATUnicodeString GetXHTMLMethodDocumentation(const CATUnicodeString& i_ClassName, const CATUnicodeString& i_MethodName, CATBoolean i_AllowCodeExample = FALSE) const = 0;
  /**
   * @param i_ClassName the class name
   * @param i_ClassName the method name
   * @return plain text documentation for given method of given class
  */
  virtual CATUnicodeString GetMethodDocumentation(const CATUnicodeString& i_ClassName, const CATUnicodeString& i_MethodName, CATBoolean i_AllowCodeExample = FALSE) const = 0;
  /**
   * @param i_FormattedMethodName short signature of the method : "ClassName::FunctionName"
   * @return richtext documentation for given method
  */
  CATUnicodeString GetXHTMLPropertyDocumentation(const CATUnicodeString& i_ClassName, const CATUnicodeString& i_PropertyName, CATBoolean i_AllowCodeExample = FALSE) const;
  /**
   * @param i_FormattedMethodName short signature of the method : "ClassName::FunctionName"
   * @return  plain text documentation for given method
  */
  CATUnicodeString GetPropertyDocumentation(const CATUnicodeString& i_ClassName, const CATUnicodeString& i_PropertyName, CATBoolean i_AllowCodeExample = FALSE) const;
  /**
   * @param i_FormattedEnumName short signature of the method : "ClassName::EnumName"
   * @return richtext documentation for given method
  */
  // virtual CATUnicodeString GetEnumDocumentation(CATUnicodeString i_FormattedEnumName)
  // {
    // int dotsPosition = i_FormattedEnumName.SearchSubString("::");
    // CHECK_TRUE_RETV_MSG(dotsPosition == -1, CATVidDocRichText(), "Bad formatting of funciton name, should be : ClassName::FunctionName");
    // CATUnicodeString className = i_FormattedEnumName.SubString(0, dotsPosition);
    // CATUnicodeString functionName = i_FormattedEnumName.SubString(dotsPosition + 2, i_FormattedEnumName.GetLengthInChar());
    // return GetMethodDocumentation(className, functionName);
  // }
  /**
   * @param i_ClassName the class name
   * @param i_MethodName the method name
   * @return richtext documentation for given method of given class
  */
  virtual CATUnicodeString GetXHTMLEnumDocumentation(const CATUnicodeString& i_ClassName, const CATUnicodeString& i_EnumName) const = 0;
  /**
   * @param i_ClassName the class name
   * @param i_MethodName the method name
   * @return plain text documentation for given method of given class
  */
  virtual CATUnicodeString GetEnumDocumentation(const CATUnicodeString& i_ClassName, const CATUnicodeString& i_EnumName) const = 0;
  /**
   * @param i_ClassName the class name
   * @param i_EnumName the enum name
   * @param i_EnumValue the enum value
   * @return richtext documentation for given enum value
  */
  virtual CATUnicodeString GetXHTMLEnumValueDocumentation(const CATUnicodeString& i_ClassName, const CATUnicodeString& i_EnumName, const CATUnicodeString& i_EnumValue) const = 0;
  /**
   * @param i_ClassName the class name
   * @param i_EnumName the enum name
   * @param i_EnumValue the enum value
   * @return plain text documentation for given enum value
  */
  virtual CATUnicodeString GetEnumValueDocumentation(const CATUnicodeString& i_ClassName, const CATUnicodeString& i_EnumName, const CATUnicodeString& i_EnumValue) const = 0;
  /**
   * @param i_EnumType the enum type, formatted as follow : Class:Enum or Class__Enum
   * @param i_EnumValue the enum value
   * @return richtext documentation for given enum value
  */
  CATUnicodeString GetXHTMLEnumValueDocumentation(const CATUnicodeString& i_EnumType, const CATUnicodeString& i_EnumValue) const;
  /**
   * @param i_EnumType the enum type, formatted as follow : Class:Enum or Class__Enum
   * @param i_EnumValue the enum value
   * @return plain text documentation for given enum value
  */
  CATUnicodeString GetEnumValueDocumentation(const CATUnicodeString& i_EnumType, const CATUnicodeString& i_EnumValue) const;
  /**
   * Format XHTML to be parsable for the VID XHTML text editor (@c CATVidCtlTextEditor)
   * Practically, it writes the xml header, and tags html and body.
   */
  static CATUnicodeString FormatXHTMLForDocument(const CATUnicodeString& i_xhtmlString);
  
};

#endif //CATVidDocProvider_H
