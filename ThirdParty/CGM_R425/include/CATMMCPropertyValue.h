#ifndef CATMMCPROPERTYVALUE_H
#define CATMMCPROPERTYVALUE_H

#include "CATMMediaCore.h"
#include "CATMMCPropertyType.h"
#include "CATMMCPropertyValueBase.h"
#include "CATMMCReturnCode.h"
#include "CATSysTSBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATListOfFloat.h"
#include "DSYSysCommon.h"
//@MMNJNinf @QDesc: Value type declaration
//@MMNJNinf @FDesc: Value type declaration supported by property.

template <class Key> struct CATMMCPropertyValue_GetType
{
  CATUnicodeString GetType() {
    return CATUnicodeString();
  }
};

template <> struct CATMMCPropertyValue_GetType<BYTE*>
{
  CATUnicodeString GetType() {
    return CATMMCPropertyTypeConv::GetAsUnicode(bytePtrType);//CATMMCPropertyValue_GetStringType();
  }
};


ExportedByCATMMediaCore CATUnicodeString CATMMCPropertyValue_GetStringType();
template <> struct CATMMCPropertyValue_GetType<CATUnicodeString>
{
  CATUnicodeString GetType() {
    return CATMMCPropertyTypeConv::GetAsUnicode(stringType);//CATMMCPropertyValue_GetStringType();
  }
};

template <> struct CATMMCPropertyValue_GetType<CATBoolean>
{
  CATUnicodeString GetType() {
    return CATMMCPropertyTypeConv::GetAsUnicode(booleanType);
//  return "float";
  }
};

template <> struct CATMMCPropertyValue_GetType<float>
{
  CATUnicodeString GetType() {
    return CATMMCPropertyTypeConv::GetAsUnicode(floatType);
//  return "float";
  }
};

template <> struct CATMMCPropertyValue_GetType<double>
{
  CATUnicodeString GetType() {
    return CATMMCPropertyTypeConv::GetAsUnicode(doubleType);
  }
};

template <> struct CATMMCPropertyValue_GetType<CATINT32>
{
  CATUnicodeString GetType() {
    return CATMMCPropertyTypeConv::GetAsUnicode(intType);
//  return "CATINT32";
  }
};

template <> struct CATMMCPropertyValue_GetType<CATUINT32>
{
  CATUnicodeString GetType() {
    return CATMMCPropertyTypeConv::GetAsUnicode(uintType);
//  return "CATUINT32";
  }
};

template <> struct CATMMCPropertyValue_GetType<CATListOfFloat>
{
  CATUnicodeString GetType() {
    return CATMMCPropertyTypeConv::GetAsUnicode(floatListType);
  }
};

template <> struct CATMMCPropertyValue_GetType<CATSysTSBaseUnknown*>
{
  CATUnicodeString GetType() {
    return CATMMCPropertyTypeConv::GetAsUnicode(baseUnknownPtrType);
  }
};



template <class Key> struct CATMMCPropertyValue_Comparator
{
  bool AreValuesPurelyIdentical(const Key &t1, const Key &t2) {
    return t1==t2;
  }
};
ExportedByCATMMediaCore bool CATMMCPropertyValue_StringComparator(const CATUnicodeString &t1, const CATUnicodeString &t2);
template <> struct CATMMCPropertyValue_Comparator<CATUnicodeString>
{
  bool AreValuesPurelyIdentical(const CATUnicodeString &t1, const CATUnicodeString &t2) {
    return CATMMCPropertyValue_StringComparator(t1,t2);//CATMMCPropertyValue_GetStringType();
  }
};
ExportedByCATMMediaCore bool CATMMCPropertyValue_LstFloatComparator(const CATListOfFloat &t1, const CATListOfFloat &t2);
template <> struct CATMMCPropertyValue_Comparator<CATListOfFloat>
{
  bool AreValuesPurelyIdentical(const CATListOfFloat &t1, const CATListOfFloat &t2) {
    return CATMMCPropertyValue_LstFloatComparator(t1,t2);//CATMMCPropertyValue_GetStringType();
  }
};


  
template <class T, class Identifier = CATMMCPropertyValue_GetType<T>, class Comparator = CATMMCPropertyValue_Comparator<T> > 
class CATMMCPropertyValueReal : public CATMMCPropertyValueBase
{
public:
  /**
   * Constructor.
   * @param iValue the value to set in the CATMMCPropertyValueReal.
   */
  CATMMCPropertyValueReal(T iValue)
    :CATMMCPropertyValueBase()
    ,m_value(iValue)
  {
  };

  /**
   * Copy constructor.
   * @param iRealValue the input CATMMCPropertyValueReal to copy.
   */
  CATMMCPropertyValueReal(const CATMMCPropertyValueReal<T>& iRealValue)
    :CATMMCPropertyValueBase()
    ,m_value(iRealValue.m_value)
    {
    };

  /**
   * Desctructor
   */
  virtual ~CATMMCPropertyValueReal() {};

  /**
   * Gets the type of value of CATMMCPropertyValueReal
   * @return a string defining the type of CATMMCPropertyValueReal
   */
  virtual CATUnicodeString GetType() const
    {
      Identifier identifier;
      return identifier.GetType();
    };

  /**
   * Returns a copy of CATMMCPropertyValueReal
   * @return a pointer on created CATMMCPropertyValueBase. Pointer has to be deleted.
   */
  virtual CATMMCPropertyValueBase* Duplicate() const
    {
      return new CATMMCPropertyValueReal<T>(*this);
    };

  /**
   * Applies the value from a CATMMCPropertyValueBase.
   * @param iPropertyValue the CATMMCPropertyValueBase to get the value of type T from.
   * @return if CATMMCPropertyValueBase is of the same type, and its value set with new one, return CATMmRCOK, CATMmRcFailed otherwise.
   */
  virtual CATMmRC SetValueFromProperty(const CATMMCPropertyValueBase& iPropertyValue)
    {
      if(GetType().GetLengthInChar()<=0)
        return CATMmRcFailed;
      if(iPropertyValue.GetType().GetLengthInChar()<=0)
        return CATMmRcFailed;
      if(2!=GetType().Compare(iPropertyValue.GetType()))
        return CATMmRcFailed;
      const CATMMCPropertyValueBase* pIValB=&iPropertyValue;
      const CATMMCPropertyValueReal<T>* pIValReal=(const CATMMCPropertyValueReal<T>*)pIValB;
      return SetValue(pIValReal->GetValue());
    };

  /**
   * Check that both values have same types and values.
   * @param iPropertyValue the CATMMCPropertyValueBase to check its type and value.
   * @return if CATMMCPropertyValueBase is of the same type and value, return TRUE, FALSE otherwise.
   */
  virtual bool IsPurelyIdenticalTo(const CATMMCPropertyValueBase& iPropertyValue) const
    {
      if(GetType().GetLengthInChar()<=0)
        return FALSE;
      if(iPropertyValue.GetType().GetLengthInChar()<=0)
        return FALSE;
      if(2!=GetType().Compare(iPropertyValue.GetType()))
        return FALSE;
      const CATMMCPropertyValueBase* pIValB=&iPropertyValue;
      const CATMMCPropertyValueReal<T>* pIValReal=(const CATMMCPropertyValueReal<T>*)pIValB;
      Comparator comparator;
      return comparator.AreValuesPurelyIdentical(GetValue(),pIValReal->GetValue());
    };

  /** @name Accesssing property of type: T*/
  /**@{*/
  /**
   * Set the value of type T .
   * @param iValue the new value.
   */
  virtual CATMmRC SetValue(T iValue)
    {
      m_value=iValue;
      return CATMmRcOK;
    };
  /**
   * Get the value of type T.
   * @return the value for this property.
   */
  virtual T GetValue() const
    {
      return m_value;
    };
  /**@}*/

  /**
   * Sets the value with the one from CATMMCPropertyValueBase.
   */
  CATMMCPropertyValueReal<T>& operator=(const CATMMCPropertyValueReal<T>& iRealValue)
    {
      if(this!=&iRealValue)
        m_value=iRealValue.m_value;
      return *this;
    };

private:
  CATMMCPropertyValueReal();
  T     m_value;
};



template <class T>
bool GetPropertyValue(const CATMMCPropertyValueBase& iProperty, T& oValue)
{											 			
	CATUnicodeString lPropType = iProperty.GetType();		      
	//Stringify T class
	CATMMCPropertyValue_GetType<T>	lType;
  if( 2!=lPropType.Compare(lType.GetType()) )
    return FALSE;

  oValue = ((const CATMMCPropertyValueReal<T>&)iProperty).GetValue();
	return TRUE;
}

template <class T>
bool SetPropertyValue(CATMMCPropertyValueBase& oProperty, const T& iValue)
{											 			
	CATUnicodeString lPropType = oProperty.GetType();		      
	//Stringify T class
	CATMMCPropertyValue_GetType<T>	lType;
  if( 2!=lPropType.Compare(lType.GetType()) )
    return FALSE;

  ((CATMMCPropertyValueReal<T>&)oProperty).SetValue(iValue);		
	return TRUE;
}

/*
template <class T>
bool AreValuesPurelyIdentical(const T &t1, const T &t2)
{
  return t1==t2;
}
template <> bool ExportedByCATMMediaCore AreValuesPurelyIdentical<CATSysTSUnicodeString>(const CATSysTSUnicodeString &t1, const CATSysTSUnicodeString &t2);
template <> bool ExportedByCATMMediaCore AreValuesPurelyIdentical<CATListOfFloat>(const CATListOfFloat &t1, const CATListOfFloat &t2);
*/
template <>
class CATMMCPropertyValueReal<CATSysTSBaseUnknown*> : public CATMMCPropertyValueBase
{
public:
  CATMMCPropertyValueReal(CATSysTSBaseUnknown* iValue):CATMMCPropertyValueBase(),m_value(NULL)
  {
    if(iValue)
    {
      m_value=iValue;
      m_value->AddRef();
    }
  };
  CATMMCPropertyValueReal(const CATMMCPropertyValueReal<CATSysTSBaseUnknown*>& iRealValue):CATMMCPropertyValueBase(),m_value(NULL)
  {
    if(iRealValue.m_value)
    {
      m_value=iRealValue.m_value;
      m_value->AddRef();
    }
  };
  virtual ~CATMMCPropertyValueReal()
  {
    CATSysReleasePtr(m_value);
  };
  virtual CATUnicodeString GetType() const
  {
    return CATMMCPropertyTypeConv::GetAsUnicode(baseUnknownPtrType);
  };
  virtual CATMMCPropertyValueBase* Duplicate() const                                            { return new CATMMCPropertyValueReal<CATSysTSBaseUnknown*>(*this); };
  virtual CATMmRC SetValueFromProperty(const CATMMCPropertyValueBase& iPropertyValue)
    {
      if(GetType().GetLengthInChar()<=0)
        return CATMmRcFailed;
      if(iPropertyValue.GetType().GetLengthInChar()<=0)
        return CATMmRcFailed;
      if(2!=GetType().Compare(iPropertyValue.GetType()))
        return CATMmRcFailed;
      const CATMMCPropertyValueBase* pIValB=&iPropertyValue;
      const CATMMCPropertyValueReal<CATSysTSBaseUnknown*>* pIValReal=(const CATMMCPropertyValueReal<CATSysTSBaseUnknown*>*)pIValB;
      CATSysTSBaseUnknown*ptsBU=NULL;
      ptsBU=pIValReal->GetValue();
      CATMmRC rc=SetValue(ptsBU);
      CATSysReleasePtr(ptsBU);//One AddRef to release between GetValue and SetValue
      return rc;
    };
  virtual bool IsPurelyIdenticalTo(const CATMMCPropertyValueBase& iPropertyValue) const
    {
      if(GetType().GetLengthInChar()<=0)
        return FALSE;
      if(iPropertyValue.GetType().GetLengthInChar()<=0)
        return FALSE;
      if(0!=GetType().Compare(iPropertyValue.GetType()))
        return FALSE;
      const CATMMCPropertyValueBase* pIValB=&iPropertyValue;
      const CATMMCPropertyValueReal<CATSysTSBaseUnknown*>* pIValReal=(const CATMMCPropertyValueReal<CATSysTSBaseUnknown*>*)pIValB;
      CATSysTSBaseUnknown*ptsBU=NULL;
      ptsBU=pIValReal->GetValue();
      bool result=(m_value == ptsBU);
      CATSysReleasePtr(ptsBU);//One AddRef to release between GetValue and SetValue
      return result;
    };
  virtual CATMmRC SetValue(CATSysTSBaseUnknown* iValue)
    {
      CATSysReleasePtr(m_value);
      m_value=iValue;
      if(m_value)
        m_value->AddRef();
      return CATMmRcOK;
    };
  virtual CATSysTSBaseUnknown* GetValue() const
    {
      if(m_value)
        m_value->AddRef();
      return m_value;
    };
  CATMMCPropertyValueReal<CATSysTSBaseUnknown*>& operator=(const CATMMCPropertyValueReal<CATSysTSBaseUnknown*>& iRealValue)
    {
      if(this!=&iRealValue)
      {
        CATSysReleasePtr(m_value);
        m_value=iRealValue.m_value;
        if(m_value)
          m_value->AddRef();
      }
      return *this;
    };

private:
  CATMMCPropertyValueReal();
  CATSysTSBaseUnknown*     m_value;
};

typedef ExportedByCATMMediaCore CATMMCPropertyValueReal<BYTE*>                 CATMMCPropertyValueBytePtr;
typedef ExportedByCATMMediaCore CATMMCPropertyValueReal<CATUnicodeString>      CATMMCPropertyValueString;
typedef ExportedByCATMMediaCore CATMMCPropertyValueReal<CATBoolean>            CATMMCPropertyValueBoolean;
typedef ExportedByCATMMediaCore CATMMCPropertyValueReal<CATINT32>              CATMMCPropertyValueInt;
typedef ExportedByCATMMediaCore CATMMCPropertyValueReal<CATUINT32>             CATMMCPropertyValueUInt;
typedef ExportedByCATMMediaCore CATMMCPropertyValueReal<float>                 CATMMCPropertyValueFloat;
typedef ExportedByCATMMediaCore CATMMCPropertyValueReal<CATListOfFloat>        CATMMCPropertyValueFloatList;
typedef ExportedByCATMMediaCore CATMMCPropertyValueReal<CATSysTSBaseUnknown*>  CATMMCPropertyTSBaseUnknownPtr;


#endif
