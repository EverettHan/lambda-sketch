/**
 * @fullreview ERS-CVE 02:02:12
 * @error UDOO Y work non remis a NULL apres Release
 */
#ifndef CATToolbarFactory_h
#define CATToolbarFactory_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include <CATAfrFoundation.h>
#include <CATBaseUnknown.h>
#include <CATUnicodeString.h>

/**
* Base class to create a workbench factory.
* <b>Role</b>: To create a factory class for your workbench, 
* use the macro @href CATDeclareConfigurationFactory for the header file (.h) and   
* the @href CATImplementConfigurationFactory for the source file (.cpp). 
* @see CATIWorkbench
*/
class ExportedByCATAfrFoundation CATWorkshopConfigurationFactory :
  public CATBaseUnknown
{
public:
  
  /** @nodoc */
  CATWorkshopConfigurationFactory();
  virtual ~CATWorkshopConfigurationFactory();
  
  /** @nodoc */
  int IsAuthorized(const char *) const;
  
  /** @nodoc */
  virtual unsigned char        Support(const CATUnicodeString & EditName) = 0;
  /** @nodoc */
  virtual CATInterfaceObject * Create(const CATUnicodeString & ItfName) = 0;
};
/**
* Defines the header file of a workbench factory class.
* <b>Role</b>: To create an instance of your workbench, you must define a factory 
* interface which derives from CATIGenericFactory.<br>
* This interface is implemented using a factory class as an extension of 
* the CATApplicationFrame class and is created by the two macros <tt>CATDeclareConfigurationFactory</tt> 
* and @href CATImplementConfigurationFactory.  
* @param Config
*    The name of the workbench's class.This class must implement an interface which 
*    derives from @href CATIWorkbench 
*    <br>
*    <br>
* <b>Example:</b> <tt>MyWorkbenchFactory</tt> is a class which implements the <tt>IMyWorkbenchFactory</tt> 
*    factory interface, creates the <tt>MyWorkbench</tt> workbench and is defined in the
*    shared library myModule.dll
* <pre> 
* 1) The header file <tt>MyWorkbenchFactory.h</tt> must contain these two lines:
*
*       #include "CATWorkshopConfigurationFactory.h"
*       <b>CATDeclareConfigurationFactory</b>(MyWorkbench);
*
* 2) The source file <tt>MyWorkbenchFactory.cpp</tt> must contain these lines:
*
*       #include "MyWorkbench.h"
*       #include "MyWorkbenchFactory.h"
*
*       #include "TIE_IMyWorkbenchFactory.h"
*
*       CATImplementConfigurationFactory(MyWorkbench, IMyWorkbenchFactory);
*
* 3) To declare that CATApplicationFrame implements IMyWorkbenchFactory,  
*       insert the following line in the <b>interface dictionary</b>:
*
*       CATApplicationFrame    IMyWorkbenchFactory  myModule 
*
* 4) To declare that the factory creates an instance of the MyWorkbench class, 
*       insert the following line in the <b>factory dictionary</b>:
* 
*       MyWorkbench            IMyWorkbenchFactory      
* </pre>
* @see CATImplementConfigurationFactory, CATIWorkbench 
*/
#define CATDeclareConfigurationFactory(Config)                     \
class Config##Factory : public CATWorkshopConfigurationFactory     \
{                                                                  \
  CATDeclareClass;                                                 \
                                                                   \
public:                                                            \
                                                                   \
  Config##Factory();                                               \
  ~Config##Factory();                                              \
                                                                   \
  unsigned char        Support(const CATUnicodeString & EditName); \
  CATInterfaceObject * Create(const CATUnicodeString & ItfName);   \
};

#ifndef CATFrmMkStringFromDefine
/**
* @nodoc 
*/
#define CATFrmMkStringFromDefine1(x) #x
/**
* @nodoc 
*/
#define CATFrmMkStringFromDefine(x) CATFrmMkStringFromDefine1(x)
#endif

/**
* Defines the source file of the workbench factory class.
* <b>Role</b>: To create an instance of your workbench, you must define a factory 
* interface which derives from CATIGenericFactory.<br>
* This interface is implemented using a factory class as an extension of 
* the CATApplicationFrame class and is created by the two macros @href CATDeclareConfigurationFactory 
* and <tt>CATImplementConfigurationFactory</tt>.  
*
* @param Config
*    The name of the workbench's class. This class must implement an interface which 
*    derives from @href CATIWorkbench
* @param CFactory
*    The name of the workbench factory interface deriving from CATIGenericFactory. 
*    <br>
*    <br>
* <b>Example:</b> <tt>MyWorkbenchFactory</tt> is a class which implements the <tt>IMyWorkbenchFactory</tt> 
*    factory interface, creates the <tt>MyWorkbench</tt> workbench and is defined in the
*    shared library myModule.dll
* <pre> 
* 1) The header file <tt>MyWorkbenchFactory.h</tt> must contain these two lines:
*
*       #include "CATWorkshopConfigurationFactory.h"
*       CATDeclareConfigurationFactory(MyWorkbench);
*
* 2) The source file <tt>MyWorkbenchFactory.cpp</tt> must contain these lines:
*
*       #include "MyWorkbench.h"
*       #include "MyWorkbenchFactory.h"
*
*       #include "TIE_IMyWorkbenchFactory.h"
*
*       <b>CATImplementConfigurationFactory</b>(MyWorkbench, IMyWorkbenchFactory);
*
* 3) To declare that CATApplicationFrame implements IMyWorkbenchFactory,  
*       insert the following line in the <b>interface dictionary</b>:
*
*       CATApplicationFrame    IMyWorkbenchFactory  myModule 
*
* 4) To declare that the factory creates an instance of the MyWorkbench class, 
*       insert the following line in the <b>factory dictionary</b>:
* 
*       MyWorkbench            IMyWorkbenchFactory      
* </pre>
* @see CATDeclareConfigurationFactory, CATIWorkbench 
*/
#define CATImplementConfigurationFactory(Config, CFactory)                  \
TIE_##CFactory(Config##Factory);                                            \
                                                                            \
CATImplementKindOf(Config##Factory, CodeExtension,                          \
		   CATWorkshopConfigurationFactory, CATApplicationFrame);               \
                                                                            \
Config##Factory::Config##Factory()                                          \
{}                                                                          \
                                                                            \
Config##Factory::~Config##Factory()                                         \
{}                                                                          \
                                                                            \
unsigned char Config##Factory::Support(const CATUnicodeString & EditName)   \
{                                                                           \
  const CATUnicodeString editType = #Config;                                \
  return (editType == EditName);                                            \
}                                                                           \
                                                                            \
CATInterfaceObject * Config##Factory::Create                                \
  (const CATUnicodeString & ItfName)                                        \
{                                                                           \
  if (strcmp (CATFrmMkStringFromDefine(_MK_FWNAME_), "External") &&         \
      !IsAuthorized(CATFrmMkStringFromDefine(_MK_FWNAME_)))                 \
    return NULL;                                                            \
  CATBaseUnknown * work = new Config;                                       \
  CATInterfaceObject * inter = work->QueryInterface(ItfName.CastToCharPtr()); \
  work->Release(); work = NULL;      \
  return inter ; \
}

#endif
