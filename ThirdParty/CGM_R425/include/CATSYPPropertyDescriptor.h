#ifndef CATSYPPropertyDescriptor_H
#define CATSYPPropertyDescriptor_H

#include <IntroInfra.h>
#include <CATUnicodeString.h>
#include <CATBaseUnknown.h>
#include <CATSysMacroPtr.h>
#include <CATSYPDescriptorBase.h>
#include <UIVCoreToolsInline.h>
#include <CATSYPRefCounted.h>
class CATSYPObjectGet;

/**
* Data class containing the description of a property.
* It is used by introspection mechanisms. 
* Recovered from a CATISYPIntrospectable.
* @see CATISYPIntrospectable
*/
class ExportedByIntroInfra CATSYPPropertyDescriptorBase : public CATSYPDescriptorBase
{
public:

  /**
   * Enumerates the possible types of a property.
   */
  enum Type
  {
    /** The property is of an unknown type (use the GetType() method
        to have the real type) */
    Type_Unknown = 0, 
    /** The property is an int */
    Type_int, 
    /** The property is a float */
    Type_float, 
    /** The property is a double */
    Type_double, 
    /** The property is a CATUnicodeString */
    Type_CATUnicodeString,
    /** The property is a CATString */
    Type_CATString,
    /** The property is a CATTime */
    Type_CATTime
  };

  /**
   * Enumerates the access mode of an entry.
   */
  enum Access
  {
    /** The entry is accessible to read and write*/
    ReadWrite=0, 
    /** The entry is accessible to read*/
    ReadOnly, 
    /** The entry is accessible to write*/
    WriteOnly
  };

  /**
  * Default constructor. Build an invalid descriptor, 
  * that can be filled by a operator=.
  */
  CATSYPPropertyDescriptorBase(CATSYPDescriptorBase::IntrospectableEntryType i_type):CATSYPDescriptorBase(i_type)
  {
    _access=CATSYPPropertyDescriptorBase::ReadWrite;
  }

  ~CATSYPPropertyDescriptorBase(){}

  /**
  * Constructor in case of class property.
  * @param i_name name of the property
  * @param i_type type of the property ("int", "CATUnicodeString"...)
  * @param i_access accessibility of the property.
  * <br><b>Legal values</b>: 0 if the property is in read/write access,
  * 1 if the property is read only.
  * @param i_className [optionnal] the class definnig the property
  * @param i_tweakType [optionnal] the type usefull when buiding a tweaker. Ex: "bool" for an int used as a bool, "filePath" for a CATUnicodeString...
  * @param i_category [optionnal] the category of the property, to allow grouping of properties
  * @param i_description [optionnal] the description of the property
  */
  CATSYPPropertyDescriptorBase(
    const CATUnicodeString& i_name,
    const CATUnicodeString& i_declarativeName,
    const CATUnicodeString& i_type, 
    CATSYPPropertyDescriptorBase::Access i_access, 
    const CATUnicodeString& i_className, 
    const CATUnicodeString& i_tweakType, 
    const CATUnicodeString& i_category, 
    const CATUnicodeString& i_description,
    int i_valueTypeFlag, 
    int i_uiPriority,
    CATSYPDescriptorBase::IntrospectableEntryType i_entryType):CATSYPDescriptorBase(i_entryType, i_className)
  {
    _name = i_name;
    _declarativeName = i_declarativeName;
    _type = i_type;
    _access = i_access;
    _category = i_category;
    _tweakType = i_tweakType;
    _description = i_description;
    _className = i_className;
    _valueTypeFlag = i_valueTypeFlag;
    _uiPriority=i_uiPriority;
  }

  /**
  * Copy Constructor.
  */
  CATSYPPropertyDescriptorBase(const CATSYPPropertyDescriptorBase & i_toCopy):CATSYPDescriptorBase(i_toCopy)
  {
    _name = i_toCopy._name;
    _declarativeName = i_toCopy._declarativeName;
    _type = i_toCopy._type;
    _access = i_toCopy._access;
    _category = i_toCopy._category;
    _description = i_toCopy._description;
    _tweakType = i_toCopy._tweakType;
    _className = i_toCopy._className;
    _valueTypeFlag = i_toCopy._valueTypeFlag;
    _uiPriority=i_toCopy._uiPriority;
  }

  /**
  * Operator=
  */
  CATSYPPropertyDescriptorBase& operator=(const CATSYPPropertyDescriptorBase & i_toCopy)
  {
    CATSYPDescriptorBase::operator=(i_toCopy);
    _name = i_toCopy._name;
    _declarativeName = i_toCopy._declarativeName;
    _type = i_toCopy._type;
    _access = i_toCopy._access;
    _category = i_toCopy._category;
    _description = i_toCopy._description;
    _tweakType = i_toCopy._tweakType;
    _className = i_toCopy._className;
    _valueTypeFlag = i_toCopy._valueTypeFlag;
    _uiPriority=i_toCopy._uiPriority;
    return *this;
  }
  /**
  * @return the name of the property
  */
  const CATUnicodeString& GetName() const {return _name;}
  /**
  * @return the declarative name of the property
  */
  const CATUnicodeString& GetDeclarativeName() const {return _declarativeName;}

  /**
  * @return the name of the class definnig the property
  */
  const CATUnicodeString& GetClassName() const {return _className;}

  /**
  * @return the type of the property as a string ("int", "CATUnicodeString"...)
  */
  const CATUnicodeString& GetType() const {return _type;}

  /**
  * Returns the type of the property as an enum.
  * If the returned type is equal to Type_Unknown, use the GetType() method 
  * to have the real type.
  */
  CATSYPPropertyDescriptorBase::Type GetPropertyType() const;

  /**
  * @return the description of the property
  */
  const CATUnicodeString& GetDecription() const {return _description;}

  /**
  * @return the category of the property, to allow grouping of properties
  */
  const CATUnicodeString& GetCategory() const {return _category;}

  /**
  * @return the type usefull when buiding a tweaker. Ex: "bool" for an int used as a bool, "filePath" for a CATUnicodeString...
  */
  const CATUnicodeString& GetTweakType() const {return _tweakType;}

  /**
  * @return the accessibility of the property.
  * <br><b>Legal values</b>: 0 if the property is in read/write access,
  * 1 if the property is read only.
  */
  CATSYPPropertyDescriptorBase::Access GetAccess() const{return _access;}

  /**
  * @return the flag indicating if the property is a boxing value or a CATBaseUnknown
  */
  int GetValueTypeFlag() const
  {
    return _valueTypeFlag;
  }
  int GetUIPriority()const{return _uiPriority;}
private:
  CATUnicodeString _name;
  CATUnicodeString _declarativeName;
  CATUnicodeString _className;
  CATUnicodeString _type;
  CATUnicodeString _description;
  CATUnicodeString _category;
  CATUnicodeString _tweakType;
  int _valueTypeFlag;
  int _uiPriority;
  CATSYPPropertyDescriptorBase::Access _access;
};

/**
* Pointer on a function that gets the value of an attached property.
*
* @param i_pImplementation the object on which the property is get
*
* @param i_index 
*
* @return the boxed value get from the attached property
*/
typedef CATBaseUnknown_var (* CATSYPGetAttachedPropertyFunc)(CATBaseUnknown* i_pImplementation, const CATBaseUnknown_var & i_index);

/**
* Pointer on a function that sets the value of an attached property.
*
* @param i_pImplementation the object on which the property is get
*
* @param i_index 
*
* @param i_spPropertyValue the value to set
*/
typedef void (* CATSYPSetAttachedPropertyFunc)(CATBaseUnknown* i_pImplementation, const CATBaseUnknown_var & i_index, const CATBaseUnknown_var & i_spPropertyValue);

/**
* Pointer on a function that gets the value of a property.
*
* @param i_pImplementation the object on which the property is set
*
* @return the boxed value get from the property.
*/
typedef CATBaseUnknown_var (* CATSYPGetPropertyFunc)(CATBaseUnknown* i_pImplementation);

typedef CATBaseUnknown_var (* CATSYPCallMethodFunc)(CATBaseUnknown* i_pImplementation);


/**
* Pointer on a function that gets the value of a property.
*
* @param i_pImplementation the object on which the property is get
*
* @param i_spPropertyValue the value to set
*/
typedef void (* CATSYPSetPropertyFunc)(CATBaseUnknown* i_pImplementation, const CATBaseUnknown_var & i_spPropertyValue);



/**
* Interface to retrieve a property value for a given object.
*
* Classes that inherit from this base class are intended to be shared
* among CATSYPPropertyDescriptor objects that describe a same property
* (using the AddRef/Release mechanism from CATBaseUnknown).
*
* The virtual member function Get performs the get operation on the given
* pointer on a CATBaseUnknown object.
*/

class ExportedByIntroInfra CATSYPMethodCaller : public CATSYPRefCounted
{
public:

  /** Default constructor */
  CATSYPMethodCaller();

  /** Destructor */
  virtual ~CATSYPMethodCaller();

  /**
  * Returns the property value for @a i_pImplementation object.
  *
  * @param i_pImplementation a pointer on the object for which the property
  * value is requested. Can't be @c NULL.
  *
  * @return the boxed value get for the property represented by this CATSYPPropertyGetter
  * or NULL_var in case of failure.
  */
  virtual CATBaseUnknown_var Call(CATBaseUnknown * i_pImplementation) = 0;

private:
  // Copy constructor and assignement operator are disabled
  CATSYPMethodCaller(const CATSYPMethodCaller &);
  CATSYPMethodCaller& operator= (const CATSYPMethodCaller &);
};

/**
* Interface to retrieve a property value for a given object.
*
* Classes that inherit from this base class are intended to be shared
* among CATSYPPropertyDescriptor objects that describe a same property
* (using the AddRef/Release mechanism from CATBaseUnknown).
*
* The virtual member function Get performs the get operation on the given
* pointer on a CATBaseUnknown object.
*/

class ExportedByIntroInfra CATSYPPropertyGetter : public CATSYPRefCounted
{
public:

  /** Default constructor */
  CATSYPPropertyGetter();

  /** Destructor */
  virtual ~CATSYPPropertyGetter();

  /**
  * Returns the property value for @a i_pImplementation object.
  *
  * @param i_pImplementation a pointer on the object for which the property
  * value is requested. Can't be @c NULL.
  *
  * @return the boxed value get for the property represented by this CATSYPPropertyGetter
  * or NULL_var in case of failure.
  */
  virtual CATBaseUnknown_var Get(CATBaseUnknown * i_pImplementation) = 0;
  virtual int Get_int(CATBaseUnknown * i_pImplementation){return 0;}
  virtual CATUnicodeString Get_CATUnicodeString(CATBaseUnknown * i_pImplementation){return "";}
  virtual CATSYPPropertyDescriptorBase::Type GetPropertyType(){return CATSYPPropertyDescriptorBase::Type_Unknown;}

private:

  // Copy constructor and assignement operator are disabled
  CATSYPPropertyGetter(const CATSYPPropertyGetter &);
  CATSYPPropertyGetter & operator= (const CATSYPPropertyGetter &);
};

/**
* Implements @ref CATSYPPropertyGetter interface by using a pointer on a
* regular/static function.
*
* This class is mainly used by the introspection mechanism as the standard
* way to get a property.
*/
class ExportedByIntroInfra CATSYPStaticPropertyGetter : public CATSYPPropertyGetter
{
public:

  /**
  * Construct a CATSYPStaticPropertyGetter object by filling it with a pointer
  * on a function that is able to perform the get operation.
  *
  * @param i_pGetterFunc a function pointer that is able to perform the
  * get operation. Can't be @c NULL.
  */
  CATSYPStaticPropertyGetter(CATBaseUnknown_var (*i_pGetterFunc) (CATBaseUnknown *));

  /** Destructor */
  virtual ~CATSYPStaticPropertyGetter();

  /** @copydoc CATSYPPropertyGetter#Get */
  virtual CATBaseUnknown_var Get(CATBaseUnknown * i_pImplementation);

private:

  // Copy constructor and assignement operator are disabled
  CATSYPStaticPropertyGetter(const CATSYPStaticPropertyGetter &);
  CATSYPStaticPropertyGetter & operator= (const CATSYPStaticPropertyGetter &);

  /**
  * A function pointer that is able to perform the get operation.
  * This function takes in parameter a pointer on the object on which the get
  * operation must be performed and must return the boxed value get or NULL_var
  * if it failed.
  */
  CATBaseUnknown_var (*_pGetterFunc) (CATBaseUnknown *);
};

/**
* Interface to set the value of a property for a given object.
*
* Classes that inherit from this base class are intended to be shared
* among CATSYPPropertyDescriptor objects that describe a same property
* (using the AddRef/Release mechanism from CATBaseUnknown).
*
* The virtual member function Set performs the set operation on the given
* pointer on a CATBaseUnknown object using the given boxed value.
*/
class ExportedByIntroInfra CATSYPPropertySetter : public CATSYPRefCounted
{
public:
  /** Default constructor */
  CATSYPPropertySetter();

  /** Destructor */
  virtual ~CATSYPPropertySetter();

  /**
  * Set the value of a property for @a i_pImplementation object.
  *
  * @param i_pImplementation a pointer on the object for which the property value
  * is set. Can't be @c NULL.
  *
  * @param i_spValue the boxed value to set to the property.
  */
  virtual void Set(CATBaseUnknown * i_pImplementation, const CATBaseUnknown_var & i_spValue) = 0;
  virtual void Set_int(CATBaseUnknown * i_pImplementation, int i_value){}
  virtual void Set_CATUnicodeString(CATBaseUnknown * i_pImplementation, CATUnicodeString i_value){}
  virtual CATSYPPropertyDescriptorBase::Type GetPropertyType(){return CATSYPPropertyDescriptorBase::Type_Unknown;}

private:

  // Copy constructor and assignement operator are disabled
  CATSYPPropertySetter(const CATSYPPropertySetter &);
  CATSYPPropertySetter & operator= (const CATSYPPropertySetter &);
};

/**
* Implements @ref CATSYPPropertySetter interface by using a pointer on a
* regular/static function.
*
* This class is mainly used by the introspection mechanism as the standard
* way to set a property.
*/
class ExportedByIntroInfra CATSYPStaticPropertySetter : public CATSYPPropertySetter
{
public:

  /**
  * Construct a CATSYPStaticPropertySetter object by filling it with a pointer
  * on a function that is able to perform the set operation.
  *
  * @param i_pSetterFunc a function pointer that is able to perform the
  * set operation. Can't be @c NULL.
  */
  CATSYPStaticPropertySetter(void (*i_pSetterFunc) (CATBaseUnknown *, const CATBaseUnknown_var &));

  /** Destructor */
  virtual ~CATSYPStaticPropertySetter();

  /** @copydoc CATSYPPropertySetter#Set */
  virtual void Set(CATBaseUnknown * i_pImplementation, const CATBaseUnknown_var& i_spPropertyValue);
private:

  // Copy constructor and assignement operator are disabled
  CATSYPStaticPropertySetter(const CATSYPStaticPropertySetter &);
  CATSYPStaticPropertySetter & operator= (const CATSYPStaticPropertySetter &);

  /**
  * A function pointer that is able to perform the set operation.
  * This function takes in parameter a pointer on the object on which the set
  * operation must be performed and also the boxed value to set.
  */
  void (*_pSetterFunc) (CATBaseUnknown *, const CATBaseUnknown_var &);
};

/**
* Interface to retrieve an attached property value for a given object.
*
* Classes that inherit from this base class are intended to be shared
* among CATSYPPropertyDescriptor objects that describe a same attached property
* (using the AddRef/Release mechanism from CATBaseUnknown).
*
* The virtual member function Get performs the get opertation on the given
* pointer on a CATBaseUnknown object.
*/
class ExportedByIntroInfra CATSYPAttachedPropertyGetter : public CATSYPRefCounted
{
public:

  /** Default constructor */
  CATSYPAttachedPropertyGetter();

  /** Destructor */
  virtual ~CATSYPAttachedPropertyGetter();

  /**
  * Returns the property value for @a pImplementation object.
  *
  * @param i_pImplementation a pointer on the object for which the property value
  * is requested. Can't be @c NULL.
  *
  * @param i_spChild the child on which the attached property has been defined
  *
  * @return the boxed value get for the property represented by this CATSYPAttachedPropertyGetter
  * or NULL_var in case of failure.
  */
  virtual CATBaseUnknown_var Get(CATBaseUnknown * i_pImplementation, const CATBaseUnknown_var & i_spChild) = 0;
  virtual int Get_int(CATBaseUnknown * i_pImplementation, const CATBaseUnknown_var & i_spChild){return 0;}
  virtual CATUnicodeString Get_CATUnicodeString(CATBaseUnknown * i_pImplementation, const CATBaseUnknown_var & i_spChild){return "";}
  virtual CATSYPPropertyDescriptorBase::Type GetPropertyType(){return CATSYPPropertyDescriptorBase::Type_Unknown;}

private:

  // Copy constructor and assignement operator are disabled
  CATSYPAttachedPropertyGetter(const CATSYPAttachedPropertyGetter &);
  CATSYPAttachedPropertyGetter & operator= (const CATSYPAttachedPropertyGetter &);
};

/**
* Implements @ref CATSYPAttachedPropertyGetter interface by using a pointer on a
* regular/static function.
*
* This class is mainly used by the introspection mechanism as the standard
* way to get an attached property.
*/
class ExportedByIntroInfra CATSYPStaticAttachedPropertyGetter : public CATSYPAttachedPropertyGetter
{
public:

  /**
  * Construct a CATSYPStaticAttachedPropertyGetter object by filling it with a pointer
  * on a function that is able to perform the get operation.
  *
  * @param i_pGetterFunc a pointer on a function that is able to perform the
  * get operation. Can't be @c NULL.
  */
  CATSYPStaticAttachedPropertyGetter(CATBaseUnknown_var (*i_pGetterFunc) (CATBaseUnknown *, const CATBaseUnknown_var &));

  /** Destructor */
  virtual ~CATSYPStaticAttachedPropertyGetter();

  /** @copydoc CATSYPAttachedPropertyGetter#Get */
  virtual CATBaseUnknown_var Get(CATBaseUnknown * i_pImplementation, const CATBaseUnknown_var & i_spChild);

private:

  // Copy constructor and assignement operator are disabled
  CATSYPStaticAttachedPropertyGetter(const CATSYPStaticAttachedPropertyGetter &);
  CATSYPStaticAttachedPropertyGetter & operator= (const CATSYPStaticAttachedPropertyGetter &);

  /**
  * A function pointer that is able to perform the get operation.
  * This function takes in parameter a pointer on the object on which the get
  * operation must be performed and also the child that holds the attached property.
  * It must return the boxed value get or NULL_var in case of failure.
  */
  CATBaseUnknown_var (*_pGetterFunc) (CATBaseUnknown *, const CATBaseUnknown_var &);
};

/**
* Interface to set the value of an attached property for a given object. 
*
* Classes that inherit from this base class are intended to be shared
* among CATSYPPropertyDescriptor objects that describe a same attached property
* (using the AddRef/Release mechanism from CATBaseUnknown).
*
* The virtual member function Set performs the set operation on the given
* pointer on a CATBaseUnknown object.
*/
class ExportedByIntroInfra CATSYPAttachedPropertySetter : public CATSYPRefCounted
{
public:

  /** Default constructor */
  CATSYPAttachedPropertySetter();

  /** Destructor */
  virtual ~CATSYPAttachedPropertySetter();

  /**
  * Set the value of an attached property for @a i_pImplementation object.
  *
  * @param i_pImplementation a pointer on the object on which the CATSYPPropertyGetter
  * must perform the set operation
  *
  * @param i_spChild the child on which the attached property is defined
  *
  * @param i_spValue the boxed value to set to the property.
  */
  virtual void Set(CATBaseUnknown* i_pImplementation, const CATBaseUnknown_var & i_spChild, const CATBaseUnknown_var& i_spValue) = 0;
  virtual void Set_int(CATBaseUnknown * i_pImplementation, const CATBaseUnknown_var & i_spChild, int i_value){}
  virtual void Set_CATUnicodeString(CATBaseUnknown * i_pImplementation, const CATBaseUnknown_var & i_spChild, CATUnicodeString i_value){}
  virtual CATSYPPropertyDescriptorBase::Type GetPropertyType(){return CATSYPPropertyDescriptorBase::Type_Unknown;}

private:

  // Copy constructor and assignement operator are disabled
  CATSYPAttachedPropertySetter(const CATSYPAttachedPropertySetter &);
  CATSYPAttachedPropertySetter & operator= (const CATSYPAttachedPropertySetter &);
};

/**
* Implements @ref CATSYPAttachedPropertySetter interface by using a pointer on a
* regular / static function.
*
* This class is mainly used by the introspection mechanism as the standard
* way to set a property.
*/
class ExportedByIntroInfra CATSYPStaticAttachedPropertySetter : public CATSYPAttachedPropertySetter
{
public:

  /**
  * Construct a CATSYPStaticAttachedPropertySetter object by filling it with a pointer
  * on a function that is able to perform the set operation.
  *
  * @param i_pSetterFunc a pointer on a function that is able to perform the
  * set operation. Can't be @c NULL.
  */
  CATSYPStaticAttachedPropertySetter(void (*i_pSetterFunc) (CATBaseUnknown *, const CATBaseUnknown_var &, const CATBaseUnknown_var &));

  /** Destructor */
  virtual ~CATSYPStaticAttachedPropertySetter();

  /** @copydoc CATSYPAttachedPropertySetter#Set */
  virtual void Set(CATBaseUnknown * i_pImplementation, const CATBaseUnknown_var& i_spChild, const CATBaseUnknown_var& i_spPropertyValue);

private:

  // Copy constructor and assignement operator are disabled
  CATSYPStaticAttachedPropertySetter(const CATSYPStaticAttachedPropertySetter &);
  CATSYPStaticAttachedPropertySetter & operator= (const CATSYPStaticAttachedPropertySetter &);

  /**
  * A pointer on a function that is able to perform the set operation.
  * This function takes in parameter a pointer on the object on which the set
  * operation must be performed, the child element on which the attached property is defined
  * and also the boxed value so set.
  */
  void (*_pSetterFunc) (CATBaseUnknown *, const CATBaseUnknown_var& i_spChild, const CATBaseUnknown_var &);
};

#define SYP_DECLARE_TYPED_ACCESSORS(i_type)\
  typedef void (* CATSYPSetPropertyFunc_##i_type)(CATBaseUnknown* i_pImplementation, i_type i_propertyValue);\
  typedef i_type (* CATSYPGetPropertyFunc_##i_type)(CATBaseUnknown* i_pImplementation);\
class ExportedByIntroInfra CATSYPStaticPropertyGetter_##i_type : public CATSYPPropertyGetter\
{\
public:\
  CATSYPStaticPropertyGetter_##i_type(i_type (*i_pGetterFunc) (CATBaseUnknown *));\
  virtual ~CATSYPStaticPropertyGetter_##i_type();\
  virtual CATBaseUnknown_var Get(CATBaseUnknown * i_pImplementation);\
  INLINE i_type Get_##i_type(CATBaseUnknown * i_pImplementation){return (*_pGetterFunc) (i_pImplementation);}\
  virtual CATSYPPropertyDescriptorBase::Type GetPropertyType(){return CATSYPPropertyDescriptorBase::Type_##i_type;}\
private:\
  CATSYPStaticPropertyGetter_##i_type(const CATSYPStaticPropertyGetter_##i_type &);\
  CATSYPStaticPropertyGetter_##i_type & operator= (const CATSYPStaticPropertyGetter_##i_type &);\
  i_type (*_pGetterFunc) (CATBaseUnknown *);\
};\
class ExportedByIntroInfra CATSYPStaticPropertySetter_##i_type : public CATSYPPropertySetter\
{\
public:\
  CATSYPStaticPropertySetter_##i_type(void (*i_pSetterFunc) (CATBaseUnknown *, i_type));\
  virtual ~CATSYPStaticPropertySetter_##i_type();\
  virtual void Set(CATBaseUnknown * i_pImplementation, const CATBaseUnknown_var& i_spPropertyValue);\
  virtual void Set_##i_type(CATBaseUnknown * i_pImplementation, i_type i_value);\
  virtual CATSYPPropertyDescriptorBase::Type GetPropertyType(){return CATSYPPropertyDescriptorBase::Type_##i_type;}\
private:\
  CATSYPStaticPropertySetter_##i_type(const CATSYPStaticPropertySetter_##i_type &);\
  CATSYPStaticPropertySetter_##i_type & operator= (const CATSYPStaticPropertySetter_##i_type &);\
  void (*_pSetterFunc) (CATBaseUnknown *, i_type);\
};

SYP_DECLARE_TYPED_ACCESSORS(CATUnicodeString);
SYP_DECLARE_TYPED_ACCESSORS(int);

class ExportedByIntroInfra CATSYPPropertyDescriptor : public CATSYPPropertyDescriptorBase
{
public:

  /**
  * Default constructor. Build an invalid descriptor, 
  * that can be filled by a operator=.
  */
  INLINE CATSYPPropertyDescriptor()
    : CATSYPPropertyDescriptorBase(CATSYPDescriptorBase::Property),
    _getPropertyObj(NULL),
    _setPropertyObj(NULL)
  {
  }

  /** Destructor */
  INLINE ~CATSYPPropertyDescriptor()
  {
    CATSysReleasePtr(_getPropertyObj);
    CATSysReleasePtr(_setPropertyObj);
  }

  /** 
  * Constructor with args.
  * @see CATSYPPropertyDescriptorBase
  * @param i_getPropertyObj [mandatory] a pointer on the get accessor object of the property
  * You do not have to Release this pointer after giving it to CATSYPPropertyDescriptor
  * since CATSYPPropertyDescriptor takes the ownership of it.
  * @param i_setPropertyObj [optional] a pointer on the set accessor object of the property
  * You do not have to Release this pointer after giving it to CATSYPPropertyDescriptor
  * since CATSYPPropertyDescriptor takes the ownership of it.
  */
  INLINE CATSYPPropertyDescriptor(
    const CATUnicodeString& i_name,
    const CATUnicodeString& i_declarativeName,
    const CATUnicodeString& i_type, 
    CATSYPPropertyDescriptor::Access i_access, 
    const CATUnicodeString& i_className, 
    const CATUnicodeString& i_tweakType, 
    const CATUnicodeString& i_category, 
    const CATUnicodeString& i_description,
    int i_valueTypeFlag,
    int i_uiPriority,
    CATSYPPropertyGetter * i_getPropertyObj,
    CATSYPPropertySetter * i_setPropertyObj) : CATSYPPropertyDescriptorBase(i_name, i_declarativeName, i_type, i_access, i_className, i_tweakType, i_category, i_description, i_valueTypeFlag, i_uiPriority, CATSYPDescriptorBase::Property)
  {
    _getPropertyObj = i_getPropertyObj;
    _setPropertyObj = i_setPropertyObj;
  }

  /** 
  * @deprecated, uses the previous constructor
  */
  INLINE CATSYPPropertyDescriptor(
    const CATUnicodeString& i_name,
    const CATUnicodeString& i_type, 
    CATSYPPropertyDescriptor::Access i_access, 
    const CATUnicodeString& i_className, 
    const CATUnicodeString& i_tweakType, 
    const CATUnicodeString& i_category, 
    const CATUnicodeString& i_description,
    int i_valueTypeFlag,
    CATSYPPropertyGetter * i_getPropertyObj,
    CATSYPPropertySetter * i_setPropertyObj) : CATSYPPropertyDescriptorBase(i_name, "", i_type, i_access, i_className, i_tweakType, i_category, i_description, i_valueTypeFlag, 1, CATSYPDescriptorBase::Property)
  {
    _getPropertyObj = i_getPropertyObj;
    _setPropertyObj = i_setPropertyObj;
  }

  /**
  * Copy Constructor.
  */
  INLINE CATSYPPropertyDescriptor(const CATSYPPropertyDescriptor & i_toCopy):CATSYPPropertyDescriptorBase(i_toCopy)
  {
    if (i_toCopy._getPropertyObj)
    {
      _getPropertyObj = i_toCopy._getPropertyObj;
      _getPropertyObj->AddRef();
    }
    else
      _getPropertyObj = NULL;

    if (i_toCopy._setPropertyObj)
    {
      _setPropertyObj = i_toCopy._setPropertyObj;
      _setPropertyObj->AddRef();
    }
    else
      _setPropertyObj = NULL;
  }

  /**
  * Operator=
  */
  INLINE CATSYPPropertyDescriptor& operator=(const CATSYPPropertyDescriptor & i_toCopy)
  {
    if (this != &i_toCopy)
    {
      CATSysReleasePtr(_getPropertyObj);
      CATSysReleasePtr(_setPropertyObj);

      CATSYPPropertyDescriptorBase::operator=(i_toCopy);
      if (i_toCopy._getPropertyObj)
      {
        _getPropertyObj = i_toCopy._getPropertyObj;
        _getPropertyObj->AddRef();
      }
      else
        _getPropertyObj = NULL;

      if (i_toCopy._setPropertyObj)
      {
        _setPropertyObj = i_toCopy._setPropertyObj;
        _setPropertyObj->AddRef();
      }
      else
        _setPropertyObj = NULL;
    }

    return *this;
  }

  /**
  * @return the getter property function pointer.
  */
  INLINE CATSYPPropertyGetter * GetGetterPropertyObject() const {return _getPropertyObj;}

  /**
  * @return the setter property function pointer.
  */
  INLINE CATSYPPropertySetter * GetSetterPropertyObject() const {return _setPropertyObj;}

private:

  CATSYPPropertyGetter * _getPropertyObj;
  CATSYPPropertySetter * _setPropertyObj;
};


class ExportedByIntroInfra CATSYPAttachedPropertyDescriptor : public CATSYPPropertyDescriptorBase
{
public:
  /**
  * Default constructor. Build an invalid descriptor, 
  * that can be filled by a operator=.
  */
  INLINE CATSYPAttachedPropertyDescriptor()
    : CATSYPPropertyDescriptorBase(CATSYPDescriptorBase::AttachedProperty)
    , _getPropertyObj(NULL)
    , _setPropertyObj(NULL)
  {
  }

  /** Destructor*/
  INLINE ~CATSYPAttachedPropertyDescriptor()
  {
    CATSysReleasePtr(_getPropertyObj);
    CATSysReleasePtr(_setPropertyObj);
  }

  /** 
  * Constructor with args.
  * @see CATSYPPropertyDescriptorBase
  * @param i_getPropertyObj [mandatory] a pointer on the get accessor object of the property
  * You do not have to Release this pointer after giving it to CATSYPAttachedPropertyDescriptor
  * since CATSYPAttachedPropertyDescriptor takes the ownership of it.
  * @param i_setPropertyObj [optional] a pointer on the set accessor object of the property
  * You do not have to Release this pointer after giving it to CATSYPAttachedPropertyDescriptor
  * since CATSYPAttachedPropertyDescriptor takes the ownership of it.
  */
  INLINE CATSYPAttachedPropertyDescriptor(
    const CATUnicodeString& i_name,
    const CATUnicodeString& i_declarativeName,
    const CATUnicodeString& i_type, 
    CATSYPPropertyDescriptorBase::Access i_access, 
    const CATUnicodeString& i_className, 
    const CATUnicodeString& i_tweakType, 
    const CATUnicodeString& i_category, 
    const CATUnicodeString& i_description,
    int i_valueTypeFlag,
    int i_uiPriority,
    CATSYPAttachedPropertyGetter * i_getPropertyObj,
    CATSYPAttachedPropertySetter * i_setPropertyObj) : CATSYPPropertyDescriptorBase(i_name, i_declarativeName, i_type, i_access, i_className, i_tweakType, i_category, i_description, i_valueTypeFlag, i_uiPriority,CATSYPDescriptorBase::AttachedProperty)
  {
    _getPropertyObj = i_getPropertyObj;
    _setPropertyObj = i_setPropertyObj;
  }

  /**
  * Copy Constructor.
  */
  INLINE CATSYPAttachedPropertyDescriptor(const CATSYPAttachedPropertyDescriptor & i_toCopy):CATSYPPropertyDescriptorBase(i_toCopy)
  {
    if (i_toCopy._getPropertyObj)
    {
      _getPropertyObj = i_toCopy._getPropertyObj;
      _getPropertyObj->AddRef();
    }
    else
      _getPropertyObj = NULL;

    if (i_toCopy._setPropertyObj)
    {
      _setPropertyObj = i_toCopy._setPropertyObj;
      _setPropertyObj->AddRef();
    }
    else
      _setPropertyObj = NULL;
  }

  /**
  * Operator=
  */
  INLINE CATSYPAttachedPropertyDescriptor& operator=(const CATSYPAttachedPropertyDescriptor & i_toCopy)
  {
    if (this != &i_toCopy)
    {
      CATSysReleasePtr(_getPropertyObj);
      CATSysReleasePtr(_setPropertyObj);

      CATSYPPropertyDescriptorBase::operator=(i_toCopy);
      if (i_toCopy._getPropertyObj)
      {
        _getPropertyObj = i_toCopy._getPropertyObj;
        _getPropertyObj->AddRef();
      }
      else
        _getPropertyObj = NULL;

      if (i_toCopy._setPropertyObj)
      {
        _setPropertyObj = i_toCopy._setPropertyObj;
        _setPropertyObj->AddRef();
      }
      else
        _setPropertyObj = NULL;
    }

    return *this;
  }

  /**
  * @return the getter property function pointer.
  */
  INLINE CATSYPAttachedPropertyGetter * GetGetterPropertyObject() const {return _getPropertyObj;}

  /**
  * @return the setter property function pointer.
  */
  INLINE CATSYPAttachedPropertySetter * GetSetterPropertyObject() const {return _setPropertyObj;}

private:

  CATSYPAttachedPropertyGetter * _getPropertyObj;
  CATSYPAttachedPropertySetter * _setPropertyObj;
};

class ExportedByIntroInfra CATSYPMethodDescriptor : public CATSYPPropertyDescriptorBase
{
public:

  /**
  * Default constructor. Build an invalid descriptor, 
  * that can be filled by a operator=.
  */
  INLINE CATSYPMethodDescriptor()
    : CATSYPPropertyDescriptorBase(CATSYPDescriptorBase::Method),
    _callMethodObj(NULL)
  {
  }

  /** Destructor */
  INLINE ~CATSYPMethodDescriptor()
  {
    CATSysReleasePtr(_callMethodObj);
  }

  /** 
  * Constructor with args.
  * @see CATSYPPropertyDescriptorBase
  * @param i_callMethodObj [mandatory] a pointer on the get accessor object of the property
  * You do not have to Release this pointer after giving it to CATSYPMethodDescriptor
  * since CATSYPMethodDescriptor takes the ownership of it.
  * You do not have to Release this pointer after giving it to CATSYPMethodDescriptor
  * since CATSYPMethodDescriptor takes the ownership of it.
  */
  INLINE CATSYPMethodDescriptor(
    const CATUnicodeString& i_name,
    const CATUnicodeString& i_declarativeName,
    const CATUnicodeString& i_type, 
    const CATUnicodeString& i_className, 
    int i_valueTypeFlag,
    CATSYPMethodCaller * i_callMethodObj) : CATSYPPropertyDescriptorBase(i_name, i_declarativeName, i_type, CATSYPPropertyDescriptorBase::ReadOnly, i_className, "", "", "", i_valueTypeFlag, 0, CATSYPDescriptorBase::Method)
  {
    _callMethodObj = i_callMethodObj;
  }

  /**
  * Copy Constructor.
  */
  INLINE CATSYPMethodDescriptor(const CATSYPMethodDescriptor & i_toCopy):CATSYPPropertyDescriptorBase(i_toCopy)
  {
    if (i_toCopy._callMethodObj)
    {
      _callMethodObj = i_toCopy._callMethodObj;
      _callMethodObj->AddRef();
    }
    else
      _callMethodObj = NULL;
  }

  /**
  * Operator=
  */
  INLINE CATSYPMethodDescriptor& operator=(const CATSYPMethodDescriptor & i_toCopy)
  {
    if (this != &i_toCopy)
    {
      CATSysReleasePtr(_callMethodObj);

      CATSYPPropertyDescriptorBase::operator=(i_toCopy);
      if (i_toCopy._callMethodObj)
      {
        _callMethodObj = i_toCopy._callMethodObj;
        _callMethodObj->AddRef();
      }
      else
        _callMethodObj = NULL;
    }

    return *this;
  }
  /**
  * @return the getter property function pointer.
  */
  INLINE CATSYPMethodCaller * GetCallerMethodObject() const {return _callMethodObj;}
private:

  CATSYPMethodCaller * _callMethodObj;
};

/**
* Implements @ref CATSYPMethodCaller interface by using a pointer on a
* regular/static function.
*
* This class is mainly used by the introspection mechanism as the standard
* way to get a property.
*/
class ExportedByIntroInfra CATSYPStaticMethodCaller : public CATSYPMethodCaller
{
public:

  /**
  * Construct a CATSYPStaticMethodCaller object by filling it with a pointer
  * on a function that is able to perform the get operation.
  *
  * @param i_pCallerFunc a function pointer that is able to perform the
  * get operation. Can't be @c NULL.
  */
  CATSYPStaticMethodCaller(CATBaseUnknown_var (*i_pCallerFunc) (CATBaseUnknown *));

  /** Destructor */
  virtual ~CATSYPStaticMethodCaller();

  /** @copydoc CATSYPMethodCaller#Get */
  virtual CATBaseUnknown_var Call(CATBaseUnknown * i_pImplementation);

private:

  // Copy constructor and assignement operator are disabled
  CATSYPStaticMethodCaller(const CATSYPStaticMethodCaller &);
  CATSYPStaticMethodCaller & operator= (const CATSYPStaticMethodCaller &);

  /**
  * A function pointer that is able to perform the get operation.
  * This function takes in parameter a pointer on the object on which the get
  * operation must be performed and must return the boxed value get or NULL_var
  * if it failed.
  */
  CATBaseUnknown_var (*_pCallerFunc) (CATBaseUnknown *);
};

#endif

