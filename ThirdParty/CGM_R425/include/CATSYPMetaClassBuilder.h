#ifndef CATSYPMetaClassBuilder_H
#define CATSYPMetaClassBuilder_H

#include <CATBaseUnknown.h>
#include <IntroInfra.h>
#include <CATSYPHashMap.h>
#include <CATUnicodeString.h>
#include <CATSYPPropertyDescriptor.h>
#include <CATSYPCommandCallbackDescriptor.h>

class CATSYPMetaClass;
class CATSYPEvent;
class CATSYPEventHandler;
class CATUnicodeString;
class CATSYPAttachedPropertyDescriptor;
class CATSYPEventDescriptor;
class CATSYPEventHandlerDescriptor;
class CATSYPEventHandlersSupportDescriptor;
class CATSYPCommandNotificationDescriptor;

/**
 * Structure wearing all informations for a property descriptor.
 */
struct CATSYPMetaClassBuilderPropertyStruct
{
    const char* _name;
    const char* _declarativeName;
    const char*  _type;
    CATSYPPropertyDescriptor::Access _access;
    const char* _tweakType; 
    int _valueTypeFlag;
    CATSYPGetPropertyFunc  _getPropertyObj;
    CATSYPSetPropertyFunc  _setPropertyObj;
    int _uiPriority;
};

/**
 * Structure wearing all informations for a property descriptor.
 */
struct CATSYPMetaClassBuilderPropertyStruct_int
{
    const char* _name;
    const char* _declarativeName;
    const char*  _type;
    CATSYPPropertyDescriptor::Access _access;
    const char* _tweakType; 
    int _valueTypeFlag;
    CATSYPGetPropertyFunc_int  _getPropertyObj;
    CATSYPSetPropertyFunc_int  _setPropertyObj;
    int _uiPriority;
};
/**
 * Structure wearing all informations for a property descriptor.
 */
struct CATSYPMetaClassBuilderPropertyStruct_CATUnicodeString
{
    const char* _name;
    const char* _declarativeName;
    const char*  _type;
    CATSYPPropertyDescriptor::Access _access;
    const char* _tweakType; 
    int _valueTypeFlag;
    CATSYPGetPropertyFunc_CATUnicodeString  _getPropertyObj;
    CATSYPSetPropertyFunc_CATUnicodeString  _setPropertyObj;
    int _uiPriority;
};

/**
 * Structure wearing all informations for an attached property descriptor.
 */
struct CATSYPMetaClassBuilderAttachedPropertyStruct
{
    const char* _name;
    const char* _declarativeName;
    const char* _type;
    CATSYPPropertyDescriptor::Access _access;
    const char* _tweakType; 
    int _valueTypeFlag;
    CATSYPGetAttachedPropertyFunc  _getPropertyObj;
    CATSYPSetAttachedPropertyFunc  _setPropertyObj;
    int _uiPriority;
};

/**
 * Structure wearing all informations for a property descriptor.
 */
struct CATSYPMetaClassBuilderMethodStruct
{
    const char* _name;
    const char* _declarativeName;
    const char*  _type;
    int _valueTypeFlag;
    CATSYPCallMethodFunc  _callMethodObj;
};
/**
 * Structure wearing all informations for an event descriptor.
 */
struct CATSYPMetaClassBuilderEventStruct
{
    CATUnicodeString _name;
    CATSYPEvent *(*_pEventFunc)();
};
/**
 * Structure wearing all informations for an event handler descriptor.
 */
struct CATSYPMetaClassBuilderEventHandlerStruct
{
    CATUnicodeString _name;
    CATMetaClass *_pArgsType;
    CATSYPEventHandler * (* _pHandlerGetterFunc)(CATBaseUnknown *);
};
/**
 * Structure wearing all informations for a command notification descriptor.
 */
struct CATSYPMetaClassBuilderCommandNotificationStruct
{
    CATUnicodeString _name;
    const CATUnicodeString _className;
};
/**
 * Structure wearing all informations for a command callback descriptor.
 */
struct CATSYPMetaClassBuilderCommandCallbackStruct
{
    CATUnicodeString _name;
    CATCommandMethod _pCommandCallbackFunc;
};

/**
 * Class of builders that is instanciated by sypintro for each
 * declared introspecable class, by a generated exter "c" function, found
 * in the appropriate library referenced in a CATFactory dictionnary file.
 * This function is called from CATSYPMetaClass#ForName method.
 * The lifr cycle of the class is very short, has it is created only to instanciate 
 * a singleton CATSYPMetaClass for a requested class.
 */
class ExportedByIntroInfra CATSYPMetaClassBuilder
{
public:
  /** Constructor */
  CATSYPMetaClassBuilder();
  /** Destructor */
  ~CATSYPMetaClassBuilder();
  /** @return the build meta class*/
  CATSYPMetaClass* GetMetaClass();

  /** Sets the name of the class */
  void SetName(const char* i_pClassName);
  /** Sets the event handler descriptor of the class */
  void SetEventHandlersSupportDescriptor(CATSYPEventHandlersSupportDescriptor* i_pEventHandlersSupportDescriptor);
  /** Sets the instanciate function of the class.*/
  void SetInstanciateFunc(CATBaseUnknown* (* i_pInstanciateFunc)());
  /** Sets the parent sypmetaclass/*/
  void SetParentMetaClass(CATSYPMetaClass* i_pParentMetaClass);

  void SetProperties_int(const int& i_nbProperties, const CATSYPMetaClassBuilderPropertyStruct_int* i_pProperties);
  void SetProperties_CATUnicodeString(const int& i_nbProperties, const CATSYPMetaClassBuilderPropertyStruct_CATUnicodeString* i_pProperties);

  /** Sets all properties, as an array of struct.*/
  void SetProperties(const int& i_nbProperties, const CATSYPMetaClassBuilderPropertyStruct* i_pProperties);
  /** Sets all attached properties, as an array of struct.*/
  void SetAttachedProperties(const int& i_nbProperties, const CATSYPMetaClassBuilderAttachedPropertyStruct* i_pProperties);
  /** Sets all methods, as an array of struct.*/
  void SetMethods(const int& i_nbMethods, const CATSYPMetaClassBuilderMethodStruct* i_pMethods);
  /** Sets all events, as an array of struct.*/
  void SetEvents(const int& i_nbEvents, const CATSYPMetaClassBuilderEventStruct* i_pEvents);
  /** Sets all event handlers, as an array of struct.*/
  void SetEventHandlers(const int& i_nbEventHandlers, const CATSYPMetaClassBuilderEventHandlerStruct* i_pEventHandlers);
  /** Sets all command notifications, as an array of struct.*/
  void SetCommandNotifications(const int& i_nbCommandNotifications, const CATSYPMetaClassBuilderCommandNotificationStruct* i_pCommandNotifications);
  /** Sets all command callbacks, as an array of struct.*/
  void SetCommandCallbacks(const int& i_nbCommandCallbacks, const CATSYPMetaClassBuilderCommandCallbackStruct* i_pCommandCallbacks);

  void CreateMetaClass(
  CATBaseUnknown* (* i_pInstanciateFunc)(), 
  const char* i_parentMetaClassName);

  void CreateMetaClass(
  CATBaseUnknown* (* i_pInstanciateFunc)(), 
  const char* i_parentMetaClassName, 
  CATSYPEventHandlersSupportDescriptor *i_pEventHandlersSupportDescriptor);

  /** 
   * This method just instanciate the meta class; it exists because of 
   * a class friendship and a private constructor of CATSYPMetaClass
   * @see CATSYPMetaClass#CATSYPMetaClass
   */
  void CreateMetaClass();  
public:
  const char* _className;
  const char* _declarativeClassName;
  const char* _aliasClassNamespace;
  CATSYPHashMap<CATUnicodeString, CATSYPDescriptorBase*>* _pEntries;
  CATSYPEventHandlersSupportDescriptor *_pEventHandlersSupportDescriptor;
  CATBaseUnknown* (* _pInstanciateFunc)();
  CATSYPMetaClass* _pParentMetaClass;
  CATSYPMetaClass* _pMetaClass;
};
#endif
