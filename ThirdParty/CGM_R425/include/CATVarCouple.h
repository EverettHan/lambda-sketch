/* */
//-----------------------------------------------------------------------
// DEPARTEMENT SAD               
// COPYRIGHT DASSAULT SYSTEMES 2000
//-----------------------------------------------------------------------
#ifndef CATVARCOUPLE_h
#define CATVARCOUPLE_h
#include "JS0LIB.h"  // exported by...
#include "CATUnicodeString.h"

class ExportedByJS0LIB CATVarCouple
{   
   public :

      typedef enum
      {
         CVC_OK,
         CVC_ExpandedVariableTooLong,
         CVC_UnableToExpandAVariable,
         CVC_VarNameNotSpecified,
         CVC_NoValueSpecified

      }ReturnCode;

      typedef enum
      {
         CVC_Yes,
         CVC_No
      }CVCAnswer;
 
      typedef enum
      {
        CVC_Undefined,
        CVC_SystemVariable,       
        CVC_FileTreeVariable,
        CVC_ReferenceVariable,
        CVC_Customised
      }CVCType;
   
   
	  
      CATVarCouple();
      ~CATVarCouple();

      // ++IK8 17:08:29
      CATUnicodeString get_Name ();      
      CATUnicodeString get_FullString ();
      CATUnicodeString get_CustomisedValue ();
      bool GetOriginalValue (CATUnicodeString &oValue);      
      bool GetValue(CATUnicodeString &oValue); 
      // @deprecated member functions (char * signatures):
      const char *               GetName  ();
      const char *               GetValue (); 
      const char *               GetFullString (); 
      const char *               GetOriginalValue (); 
      const char *               GetCustomisedValue ();
      // --IK8 17:08:29
      
      CATVarCouple::ReturnCode   SetCATVarCouple    (CATUnicodeString  varname,     CATUnicodeString varvalue);
      CATVarCouple::ReturnCode   SetCATVarCouple    (CATUnicodeString  varname,     CATUnicodeString varvalue,
                                                     CATVarCouple::CVCType VarType, CATUnicodeString  comment);
      void                       SetValue    (const CATUnicodeString * ipszValue);  // ++IK8 17:08:29 m_Value can contain Unicode characters (path...)
      void                       UpdateValue (CATUnicodeString  NewValue);
      void                       AppendValue (CATUnicodeString  NewValue);
      void                       SetName     (CATUnicodeString  varname);
      void                       Reset       ();
      void                       ResetCustomised();
      // ++IK8 17:08:29 m_Value can contain Unicode characters (path...)
      CATVarCouple::ReturnCode   ExpandVar   ();
      CATVarCouple::ReturnCode   ExpandVar   (const CATUnicodeString & user_name);
      // --IK8 17:08:29
      CATVarCouple::ReturnCode   CheckValue  ();

      CATVarCouple::CVCAnswer    GetOfficialVariableStatus();
      void                       SetOfficialVariableStatus(CATVarCouple::CVCAnswer a);
   
      CATVarCouple::CVCType      GetVariableType();
      void                       SetVariableType(CATVarCouple::CVCType t);

      CATUnicodeString           GetComment();
      void                       SetComment(CATUnicodeString c); 
      void                       SetCustomisedValue(CATUnicodeString val);
  private:
      CATUnicodeString  m_Name;
      CATUnicodeString  m_Value;
      CATUnicodeString  m_CustomisedValue;
      CATVarCouple::CVCType  m_Type; 
      CATUnicodeString  m_Comment;
      CATUnicodeString  m_FullString;
      CATVarCouple::CVCAnswer  m_IsVariableValued;
      CATVarCouple::CVCAnswer  m_IsOfficialVariable;
};

inline CATVarCouple::ReturnCode CATVarCouple::ExpandVar()
{
    return ExpandVar(CATUnicodeString());
}

inline CATUnicodeString CATVarCouple::get_Name()
{
    return m_Name;
}

inline CATUnicodeString CATVarCouple::get_FullString()
{
    return m_FullString;
}

inline CATUnicodeString CATVarCouple::get_CustomisedValue()
{
    return m_CustomisedValue;
}

#endif
