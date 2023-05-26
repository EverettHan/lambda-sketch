#ifndef CATWorkshopFactory_h
#define CATWorkshopFactory_h

// COPYRIGHT DASSAULT SYSTEMES 1999

#include <CATAfrFoundation.h>
#include <CATBaseUnknown.h>
#include <CATUnicodeString.h>

/**
* Base class to create a workshop factory.
* <b>Role</b>: To create a factory class for your workshop, 
* use the macro @href CATDeclareWorkshopFactory for the header file (.h) and   
* the @href CATImplementWorkshopFactory for the source file (.cpp). 
* @see CATIWorkshop
*/
class ExportedByCATAfrFoundation CATWorkshopFactory : public CATBaseUnknown
{
public:
  
  /** @nodoc */
  CATWorkshopFactory();
  virtual ~CATWorkshopFactory();
  
  /** @nodoc */
  int IsAuthorized(const char *) const;
  
  /** @nodoc */
  virtual unsigned char        Support(const CATUnicodeString & EditName) = 0;
  /** @nodoc */
  virtual CATInterfaceObject * Create(const CATUnicodeString & ItfName) = 0;
};

/**
* Defines the header file of a workshop factory class.
* <b>Role</b>: To create an instance of your workshop, you must define a factory 
* interface which derives from CATIGenericFactory.<br>
* This interface is implemented using a factory class as an extension of 
* the CATApplicationFrame class and is created by the two macros <tt>CATDeclareWorkshopFactory</tt> 
* and @href CATImplementWorkshopFactory.  
* @param Workshop
*    The name of the workshop's class. This class must implement @href CATIWorkshop.
*    <br>
*    <br>
* <b>Example:</b> <tt>MyWorkshopFactory</tt> is a class which implements the <tt>IMyWorkshopFactory</tt> 
*    factory interface, creates the <tt>MyWorkshop</tt> workshop and is defined in the
*    shared library myModule.dll
* <pre> 
* 1) The header file <tt>MyWorkshopFactory.h</tt> must contain these two lines:
*
*       #include "CATWorkshopFactory.h"
*       <b>CATDeclareWorkshopFactory</b>(MyWorkshop);
*
* 2) The source file <tt>MyWorkshopFactory.cpp</tt> must contain these lines:
*
*       #include "MyWorkshop.h"
*       #include "MyWorkshopFactory.h"
*
*       #include "TIE_<tt>IMyWorkshopFactory</tt>.h"
*
*       CATImplementWorkshopFactory(MyWorkshop, IMyWorkshopFactory);
*
* 3) To declare that CATApplicationFrame implements IMyWorkshopFactory,  
*       insert the following line in the <b>interface dictionary</b>:
*
*       CATApplicationFrame    IMyWorkshopFactory  myModule 
*
* 4) To declare that the factory creates an instance of the MyWorkshop class, 
*       insert the following line in the <b>factory dictionary</b>:
* 
*       MyWorkshop            IMyWorkshopFactory      
* </pre>
* @see CATImplementWorkshopFactory, CATIWorkshop 
*/
#define CATDeclareWorkshopFactory(Workshop)                        \
class Workshop##Factory : public CATWorkshopFactory                \
{                                                                  \
  CATDeclareClass;                                                 \
                                                                   \
public:                                                            \
                                                                   \
  Workshop##Factory();                                             \
  ~Workshop##Factory();                                            \
                                                                   \
  unsigned char        Support(const CATUnicodeString & EditName); \
  CATInterfaceObject * Create(const CATUnicodeString & ItfName);   \
};

#ifndef CATFrmMkStringFromDefine
/** @nodoc */
#define CATFrmMkStringFromDefine1(x) #x
/** @nodoc */
#define CATFrmMkStringFromDefine(x) CATFrmMkStringFromDefine1(x)
#endif

/**
* Defines the source file of the workshop factory class.
* <b>Role</b>: To create an instance of your workshop, you must define a factory 
* interface which derives from CATIGenericFactory.<br>
* This interface is implemented using a factory class as an extension of 
* the CATApplicationFrame class and is created by the two macros @href CATDeclareWorkshopFactory 
* and <tt>CATImplementWorkshopFactory</tt>.  
*
* @param Workshop
*    The name of the workshop's class. This class must implement @href CATIWorkshop.
* @param WFactory
*    The name of the workshop factory interface deriving from CATIGenericFactory. 
*    <br>
*    <br>
* <b>Example:</b> <tt>MyWorkshopFactory</tt> is a class which implements the <tt>IMyWorkshopFactory</tt> 
*    factory interface, creates the <tt>MyWorkshop</tt> workshop and is defined in the
*    shared library myModule.dll
* <pre> 
* 1) The header file <tt>MyWorkshopFactory.h</tt> must contain these two lines:
*
*       #include "CATWorkshopFactory.h"
*       CATDeclareWorkshopFactory(MyWorkshop);
*
* 2) The source file <tt>MyWorkshopFactory.cpp</tt> must contain these lines:
*
*       #include "MyWorkshop.h"
*       #include "MyWorkshopFactory.h"
*
*       #include "TIE_IMyWorkshopFactory.h"
*
*       <b>CATImplementWorkshopFactory</b>(MyWorkshop, IMyWorkshopFactory);
*
* 3) To declare that CATApplicationFrame implements IMyWorkshopFactory,  
*       insert the following line in the <b>interface dictionary</b>:
*
*       CATApplicationFrame    IMyWorkshopFactory  myModule 
*
* 4) To declare that the factory creates an instance of the MyWorkshop class, 
*       insert the following line in the <b>factory dictionary</b>:
* 
*       MyWorkshop            IMyWorkshopFactory      
* </pre>
* @see CATDeclareWorkshopFactory, CATIWorkshop 
*/
#define CATImplementWorkshopFactory(Workshop, WFactory)                     \
TIE_##WFactory(Workshop##Factory);                                          \
                                                                            \
CATImplementKindOf(Workshop##Factory, CodeExtension,                        \
		   CATWorkshopFactory, CATApplicationFrame);                \
                                                                            \
Workshop##Factory::Workshop##Factory()                                      \
{}                                                                          \
                                                                            \
Workshop##Factory::~Workshop##Factory()                                     \
{}                                                                          \
                                                                            \
unsigned char Workshop##Factory::Support(const CATUnicodeString & EditName) \
{                                                                           \
  const CATUnicodeString editType = #Workshop;                              \
  return (editType == EditName);                                            \
}                                                                           \
                                                                            \
CATInterfaceObject * Workshop##Factory::Create                              \
  (const CATUnicodeString & ItfName)                                        \
{                                                                           \
  if (!IsAuthorized(CATFrmMkStringFromDefine(_MK_FWNAME_)))                 \
    return NULL;                                                            \
  CATBaseUnknown * work = new Workshop;                                     \
  CATInterfaceObject * inter =  work->QueryInterface(ItfName.CastToCharPtr());  \
  work->Release(); \
  return inter ; \
}

#endif
