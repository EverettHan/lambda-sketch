/* -*-c++-*- */
#ifndef CATSysMacSettingController_H
#define CATSysMacSettingController_H

// COPYRIGHT DASSAULT SYSTEMES 2003

// System framework
#include "IUnknown.h"   
#include "CATBaseObject.h"
#include "CATSafeArray.h"
#include "CATBoolean.h"
#include "CAT_VARIANT_BOOL.h"
#include "CATAutoConversions.h"
#include "CATDataType.h"
#include "JS0SETT.h"
#include "CATSettingInfo.h"
#include "CATSysSettingController.h"
#include "CATSysAutoSettingController.h"
#include "CATSysSettingCtrlNotif.h"
#include "CATCreateClassInstance.h" // For CATAddOMFactoryFunction

// TIE for the 3 generic interfaces 
#include "TIE_CATIASettingController.h"
#include "TIE_CATICreateInstance.h"
#include "TIE_CATISysSettingController.h"

#include "CATSysParamMap.h"

/**
 * Declares a setting controller.
 * <br><b>Role</b>: Declares a class that implements a setting controller. 
 * The controller implements the interface @href CATISysSettingController
 * for managing the generic operations as (Save, Commit, ResetToAdminValues)
 * on the setting controller. To access the specific parameters it 
 * must implement an interface BrandIFWNameSettingAtt.
 * The name of the class must be BrandFWNameSettingCtrl. 
 * @param Brand
 *   The brand to which this controller belongs
 * @param FW
 *   The framework in which the controller is implemented
 * @param Name
 *   The name of the controller
 */
#define CATDeclareSettingCtrl(Brand,FW,Name)				\
CATDeclareClass;							\
private:								\
static Brand##FW##Name##SettingCtrl* _TheCtrl;				\
Brand##FW##Name##SettingCtrl (const char * iSettingName);		\
public:									\
static HRESULT GetTheController(const IID & iIID,			\
				CATBaseUnknown**oItf)


/**
 * Declares a settings controller for Automation.
 * <br><b>Role</b>: Declares a class that implements a settings controller. 
 * The controller implements the interface @href CATIASettingController 
 * for managing the generic operations as (Save, Commit, ResetToAdminValues)
 * on the setting controller. To access the specific parameters it
 * must implement an interface BrandIAFWNameSettingAtt for Automation.
 * The name of the class must be BrandFWNameAutoSettingCtrl. 
 * This class will form an Object Modeler component with the 
 * BrandFWNameSettingCtrl that implement the five following interfaces:
 * <ul>
 *  <li><tt> BrandIFWNameSettingAtt</tt></li>
 *  <li><tt> BrandIANameSettingAtt</tt></li>
 *  <li><tt> @href CATISysSettingController </tt></li>
 *  <li><tt> @href CATIASettingController </tt></li>
 *  <li><tt> @href CATICreateInstance </tt></li>
 * </ul>
 * @param Brand
 *  The brand to which this controller belongs
 * @param FW
 *   The framework in which the controller is implemented
 * @param Name
 *   The name of the controller
 */
#define CATDeclareAutoSettingCtrl(Brand,FW,Name)			\
CATDeclareClass;							\
public:									\
Brand##FW##Name##AutoSettingCtrl();					\
virtual ~Brand##FW##Name##AutoSettingCtrl()				\



/**
 * Macro used to define a setting controller.
 * <br><b>Role</b>: Defines a class that implements a settings controller. 
 * The controller implements the interface @href CATISysSettingController for 
 * managing the generic operations (Save, Commit, ResetToAdminValues) on the 
 * setting controller. To access the specific parameters it must 
 * implement an interface which name is BrandIFWNameSettingAtt.
 * It implements the new instantiation mechanism (CATAddOMFactoryFunction) too, 
 * the entry "Brand##FW##Name##SettingCtrl OMFactoryFunctionType libMyLibrary" must be added
 * to your framework .func dictionary.
 * Thus the following includes must be used in the source code:
 *	<br><tt> #include "TIE_BrandIFWNameSettingAtt.h" </tt>
 * @param Brand
 *   The brand to which this controller belongs
 * @param FW
 *   The framework in which the controller is implemented
 * @param Name
 *   The name of the controller
 * @param SettingName
 *   The name of the setting file used by the controller
 */
#define CATImplementSettingCtrlNew(Brand,FW,Name,SettingName)		\
CATBaseUnknown* Brand##FW##Name##SettingCtrlExtCreateInstance() \
{  \
  CATBaseUnknown * rcBU = NULL;  \
  HRESULT hres=Brand##FW##Name##SettingCtrl::GetTheController(IID_CATISysSettingController,&rcBU); \
  if (FAILED(hres)) \
	rcBU = NULL;	\
  return rcBU ; \
} \
CATAddOMFactoryFunction(Brand##FW##Name##SettingCtrl,Brand##FW##Name##SettingCtrlExtCreateInstance) \
/* TIE for  CATISysSettingController and Name##Att*/			\
/* the include must be done in the code */				\
CATImplementClass(Brand##FW##Name##SettingCtrl,Implementation,		\
		  CATSysSettingController,CATNull);			\
TIEchain_CATISysSettingController(Brand##FW##Name##SettingCtrl);	\
TIEchain_##Brand##I##FW##Name##SettingAtt(Brand##FW##Name##SettingCtrl);\
									\
Brand##FW##Name##SettingCtrl*						\
		Brand##FW##Name##SettingCtrl::_TheCtrl=NULL;		\
static CATSysParamMap * Brand##FW##Name##ParamMap=NULL;		\
HRESULT Brand##FW##Name##SettingCtrl::GetTheController(const IID &iIID,	\
			                     CATBaseUnknown**oItf)	\
{									\
   HRESULT hres =S_OK;			  				\
   if (oItf==NULL) return E_FAIL;					\
   if ( _TheCtrl==NULL)							\
     {									\
        _TheCtrl =new Brand##FW##Name##SettingCtrl( #SettingName);	\
        if (_TheCtrl==NULL) return E_OUTOFMEMORY;			\
        HRESULT hres =_TheCtrl->Initialize();			        \
        if (FAILED(hres)) return E_FAIL;				\
        /* first commit to begin the rollback system	*/		\
        hres =_TheCtrl->Commit();					\
     }									\
  /* in order to force a call to Initialize() in DumpMode*/		\
  /*if (CATSysSettingController::ReadDumpMode())*/			\
  /*  {							*/		\
  /*    CATSysSettingController *tmp= NULL;		*/		\
  /*    tmp =( CATSysSettingController *)_TheCtrl->GetImpl();*/		\
  /*     if ( tmp ) tmp->Dump();	*/				\
  /*  }	*/								\
									\
  _TheCtrl->_ParamMap = Brand##FW##Name##ParamMap;			\
  hres =  _TheCtrl->QueryInterface ( iIID, (void**) oItf);		\
  return hres;								\
}




/**
 * Macro used to define a setting controller.
 * <br><b>Role</b>: Defines a class that implements a settings controller. 
 * The controller implements the interface @href CATISysSettingController for 
 * managing the generic operations (Save, Commit, ResetToAdminValues) on the 
 * setting controller. To access the specific parameters it must 
 * implement an interface which name is BrandIFWNameSettingAtt.
 * It implements the @href CATICreateInstance interface too.
 * Thus the following includes must be used in the source code:
 *	<br><tt> #include "TIE_BrandIFWNameSettingAtt.h" </tt>
 * @param Brand
 *   The brand to which this controller belongs
 * @param FW
 *   The framework in which the controller is implemented
 * @param Name
 *   The name of the controller
 * @param SettingName
 *   The name of the setting file used by the controller
 */
#define CATImplementSettingCtrl(Brand,FW,Name,SettingName)		\
/* CATICreateInstance*/							\
class Brand##FW##Name##SettingCtrlExt : public CATBaseUnknown		\
{									\
CATDeclareClass;							\
public:									\
HRESULT __stdcall CreateInstance(void **oPPV);				\
};									\
CATImplementClass(Brand##FW##Name##SettingCtrlExt,CodeExtension,	\
                  CATBaseUnknown,Brand##FW##Name##SettingCtrl);		\
TIE_CATICreateInstance(Brand##FW##Name##SettingCtrlExt);		\
									\
HRESULT Brand##FW##Name##SettingCtrlExt::CreateInstance(void **oPPV)    \
{									\
  HRESULT hres= E_FAIL;							\
  if (oPPV == NULL)  return hres;					\
  CATISysSettingController *Ctrl=NULL;					\
  hres=Brand##FW##Name##SettingCtrl::GetTheController(			\
	     			IID_CATISysSettingController,		\
	                        (CATBaseUnknown**)&Ctrl);		\
  if (( hres != S_OK) || ( Ctrl == NULL))  return E_FAIL;		\
  *oPPV = Ctrl;								\
  return S_OK;								\
}									\
/* TIE for  CATISysSettingController and Name##Att*/			\
/* the include must be done in the code */				\
CATImplementClass(Brand##FW##Name##SettingCtrl,Implementation,		\
		  CATSysSettingController,CATNull);			\
TIEchain_CATISysSettingController(Brand##FW##Name##SettingCtrl);	\
TIEchain_##Brand##I##FW##Name##SettingAtt(Brand##FW##Name##SettingCtrl);\
									\
Brand##FW##Name##SettingCtrl*						\
		Brand##FW##Name##SettingCtrl::_TheCtrl=NULL;		\
static CATSysParamMap * Brand##FW##Name##ParamMap=NULL;		\
HRESULT Brand##FW##Name##SettingCtrl::GetTheController(const IID &iIID,	\
			                     CATBaseUnknown**oItf)	\
{									\
   HRESULT hres =S_OK;			  				\
   if (oItf==NULL) return E_FAIL;					\
   if ( _TheCtrl==NULL)							\
     {									\
        _TheCtrl =new Brand##FW##Name##SettingCtrl( #SettingName);	\
        if (_TheCtrl==NULL) return E_OUTOFMEMORY;			\
        HRESULT hres =_TheCtrl->Initialize();			        \
        if (FAILED(hres)) return E_FAIL;				\
        /* first commit to begin the rollback system	*/		\
        hres =_TheCtrl->Commit();					\
     }									\
  /* in order to force a call to Initialize() in DumpMode*/		\
  /*if (CATSysSettingController::ReadDumpMode())*/			\
  /*  {							*/		\
  /*    CATSysSettingController *tmp= NULL;		*/		\
  /*    tmp =( CATSysSettingController *)_TheCtrl->GetImpl();*/		\
  /*     if ( tmp ) tmp->Dump();	*/				\
  /*  }	*/								\
									\
  _TheCtrl->_ParamMap = Brand##FW##Name##ParamMap;			\
  hres =  _TheCtrl->QueryInterface ( iIID, (void**) oItf);		\
  return hres;								\
}





/**
 * Macro used to define a setting controller for Automation.
 * <br><b>Role</b>: Defines a class that implements a settings controller. 
 * The controller implements the interface @href CATIASettingController for 
 * managing the generic operations (Save, Commit, ResetToAdminValues) on the 
 * setting controller. To access the specific parameters it must 
 * implement an interface which name is BrandIANameSettingAtt.
 * Thus the following include must be used in the source code:
 *	<br><tt> #include "TIE_BrandIAFWNameSettingAtt.h" </tt>
 * This class will form an Object Modeler component with the 
 * BrandFWNameSettingCtrl that implements the five following interfaces:
 * <ul>
 *  <li><tt> BrandIFWNameSettingAtt</tt></li>
 *  <li><tt> BrandIANameSettingAtt</tt></li>
 *  <li><tt> @href CATISysSettingController </tt></li>
 *  <li><tt> @href CATIASettingController </tt></li>
 *  <li><tt> @href CATICreateInstance </tt></li>
 * </ul>
 * @param Brand
 *   The brand to which belong this controller belongs
 * @param FW
 *   The framework in which the controller is implemented
 * @param Name
 *   The name of the controller
 */
#define CATImplAutoSettingCtrl(Brand,FW,Name)				\
/* The automation is an extension of the C++ */				\
CATImplementClass(Brand##FW##Name##AutoSettingCtrl,DataExtension,	\
		  CATBaseUnknown,					\
		  Brand##FW##Name##SettingCtrl);			\
TIEchain_##Brand##IA##Name##SettingAtt(Brand##FW##Name##AutoSettingCtrl);\
	       								\
Brand##FW##Name##AutoSettingCtrl::Brand##FW##Name##AutoSettingCtrl(){}  \
Brand##FW##Name##AutoSettingCtrl::~Brand##FW##Name##AutoSettingCtrl(){} \
									\





/**
 * Macro implementing the method retrieving information concerning a setting parameter.
 * <br><b>Role</b>: For each settings' attribute of a setting controller, 
 * the BrandIFWNameSettingAtt interface must define a CATSettingInfo 
 * retrieving method. The same method must be implemented too in the 
 * Automation context.
 * Thus the implementation class that has been defined with the 
 * macros @href CATDeclareAutoSettingCtrl and @href CATImplAutoSettingCtrl 
 * must implement the following method:
 *  <br><tt> HRESULT BrandFWNameAutoSettingCtrl::GetParamNameInfo(CATBSTR & AdminLevel,	unsigned char &oModified, unsigned char &oLocked)</tt>
 * @param Brand
 *   The brand to which this controller belongs 
 * @param FW
 *   The framework in which the controller is implemented
 * @param Name
 *   The name of the controller
 * @param ParamName
 *   The name of the setting parameter
 */
#define CATImplAutoSettingCtrlInfoMethod(Brand,FW,Name,ParamName)	\
HRESULT Brand##FW##Name##AutoSettingCtrl::Get##ParamName##Info(		\
					CATBSTR & AdminLevel,		\
					CATBSTR & oLocked,		\
					CAT_VARIANT_BOOL & oModif)		\
{									\
  HRESULT hres = E_FAIL;						\
  Brand##I##FW##Name##SettingAtt *Att=NULL;				\
  hres = QueryInterface ( IID_##Brand##I##FW##Name##SettingAtt,		\
			  (void**)&Att);				\
  if (FAILED(hres))							\
    return hres;							\
  CATSettingInfo Info;							\
  hres = Att->Get##ParamName##Info( &Info);				\
  if (FAILED(hres))							\
    return hres;							\
  CATUnicodeString Level;						\
  CATSysSettingController::MapLevel( Info, Level);			\
  Level.ConvertToBSTR(  &AdminLevel);					\
  oModif = BOOL_TO_VARBOOL(Info._Explicit);				\
  CATUnicodeString Lock;						\
  CATSysSettingController::MapLock(Info, Lock);				\
  Lock.ConvertToBSTR(  &oLocked);					\
  Att->Release();							\
  return S_OK;								\
}									\



/**
 * Begins the implementation sequence of the methods dealing with the locks of a setting parameter.
 * <br><b>Role</b>: For each parameter exposed by a setting controller 
 * in its interface BrandIFWNameSettingAtt, a method dealing with the lock
 * and a method retrieving the information concerning the parameter must be 
 * available. 
 * This macro begins the macro sequence that should be used in conjunction 
 * with @href CATSysAddImplSettingCtrlLocks 
 * and @href CATSysEndImplSettingCtrlLocks
 * This sequence will implement the two following methods:
 * <ul>
 *  <li><tt>HRESULT BrandFWNameSettingCtrl::GetInfoParamName(CATSettingInfo* oInfo)</tt></li>
 *  <li><tt>HRESULT BrandFWNameSettingCtrl::SetLockParamName (unsigned char iLock)</tt></li>
 * </ul>
 * <p>If the controller's parameter is built from many
 * CATSysSettingController's attributes then the name of the other attributes 
 * must be specified by using the @href CATSysAddImplSettingCtrlLocks macro for 
 * each attribute. These attributes are semantically bounded and thus are 
 * locked or unlocked together.</p> 
 * @param Brand
 *   The brand to which this controller belongs
 * @param FW
 *   The framework in which the controller is implemented
 * @param Name
 *   The name of the controller
 * @param ParamName
 *   The name of the setting's parameter used in the method's name
  * @param AttrName
 *   The name of the first underlying setting's attribute
 */
#ifdef _LINUX_SOURCE
#define CATSysBeginImplSettingCtrlLocks(Brand,FW,Name,ParamName,AttrName)\
HRESULT Brand##FW##Name##SettingCtrl::Get##ParamName##Info (		\
						CATSettingInfo* oInfo)	\
{									\
  HRESULT hres= (GetInfo ( #AttrName, oInfo));				\
  if (SUCCEEDED(hres) && (oInfo))					\
    {									\
       oInfo->SetFunc((CATSysSettingCtrlInfoMethod)			\
  		&Brand##FW##Name##SettingCtrl::Get##ParamName##Info,	\
  		       (CATSysSettingCtrlLockingMethod)			\
  		&Brand##FW##Name##SettingCtrl::Set##ParamName##Lock,	\
  			_TheCtrl, #ParamName);				\
    }									\
  return hres;								\
}									\
static char* Brand##FW##Name##ParamName[]={(char *)#ParamName,(char *)#AttrName		
#else
#define CATSysBeginImplSettingCtrlLocks(Brand,FW,Name,ParamName,AttrName)\
HRESULT Brand##FW##Name##SettingCtrl::Get##ParamName##Info (		\
						CATSettingInfo* oInfo)	\
{									\
  HRESULT hres= (GetInfo ( #AttrName, oInfo));				\
  if (SUCCEEDED(hres) && (oInfo))					\
    {									\
       oInfo->SetFunc((CATSysSettingCtrlInfoMethod)			\
  		&Brand##FW##Name##SettingCtrl::Get##ParamName##Info,	\
  		       (CATSysSettingCtrlLockingMethod)			\
  		&Brand##FW##Name##SettingCtrl::Set##ParamName##Lock,	\
  			_TheCtrl, #ParamName);				\
    }									\
  return hres;								\
}									\
static char* Brand##FW##Name##ParamName[]={(char *)#ParamName,(char *)#AttrName	
#endif


/**
 * Continues the implementation sequence of the methods dealing with the locks of a setting parameter.
 * <br><b>Role</b>: This macro declares that the current controller's parameter 
 * is built from at least one other @href CATSysSettingController attribute.
 * This attribute AttrName is semantically bounded with the first one declared
 * as the third argument of the @href CATSysBeginImplSettingCtrlLocks </p>
 * @param Brand
 *   The brand to which this controller belongs
 * @param FW
 *   The framework in which the controller is implemented
 * @param Name
 *   The name of the controller
 * @param ParamName
 *   The name of the setting parameter used in the method's name
 * @param AttrName
 *   The name of one other underlying setting attribute
 */
#define CATSysAddImplSettingCtrlLocks(Brand,FW,Name,ParamName,AttrName)	\
					,(char*)#AttrName			\



/**
 * Ends the implementation sequence of the methods dealing with the locks of a setting parameter.
 * <br><b>Role</b>:This macro ends the macro sequence that have been begun
 * with  @href CATSysBeginImplSettingCtrlLocks .
 * The two following methods are now implemented:
 * <ul>
 *  <li><tt>HRESULT BrandFWNameSettingCtrl::GetParamNameInfo(CATSettingInfo* oInfo)</tt></li>
 *  <li><tt>HRESULT BrandFWNameSettingCtrl::SetLockParamName (unsigned char iLock)</tt></li>
 * </ul>
 * @param Brand
 *   The brand to which this controller belongs
 * @param FW
 *   The framework in which the controller is implemented
 * @param Name
 *   The name of the controller
 * @param ParamName
 *   The name of the setting's parameter used in the method's name
 */
#define CATSysEndImplSettingCtrlLocks(Brand,FW,Name,ParamName)		\
					,NULL};				\
static CATSysParamMap Brand##FW##Name##ParamName##Map (			\
					&Brand##FW##Name##ParamMap,	\
					Brand##FW##Name##ParamName);	\
HRESULT Brand##FW##Name##SettingCtrl::Set##ParamName##Lock (		\
					unsigned char iLock)		\
{									\
  HRESULT hres = S_OK;							\
  if ( iLock ==FALSE)							\
    {									\
      int i =0;								\
      /* [0] =  #ParamName   */						\
      while (Brand##FW##Name##ParamName[i+1])				\
	{								\
	  hres+=Unlock(Brand##FW##Name##ParamName[i+1]);		\
	  i++;								\
	}								\
    }									\
  else									\
    {									\
      int i =0;								\
      while (Brand##FW##Name##ParamName[i+1])				\
	{								\
	  hres+=Lock( Brand##FW##Name##ParamName[i+1]);			\
	  i++;								\
	}								\
    }									\
 if (hres != S_OK)							\
   return E_FAIL;							\
 else									\
   return hres;								\
}									\

					
/**
 * Implements the methods dealing with the locks of a seting parameter.
 * <br><b>Role</b>: For each parameter exposed by a settings controller 
 * in its interface BrandIFWNameSettingAtt, a method dealing with the lock 
 * and a method retrieving the information concerning the parameter must be 
 * available.
 * This macro will implement the three following methods:
 * <ul>
 *  <li><tt>HRESULT BrandFWNameSettingCtrl::GetParamNameInfo(CATSettingInfo* oInfo)</tt></li>
 *  <li><tt>HRESULT BrandFWNameSettingCtrl::SetLockParamName (unsigned char iLock)</tt></li>
 * </ul>
 * <br>This macro must be used if the controller's parameter represents only
 * one CATSysSettingController's attribute. It is equivalent to the use of the
 * two macro  @href CATSysBeginImplSettingCtrlLocks 
 * and @href CATSysEndImplSettingCtrlLocks in the following sequence :
 * <br><tt>CATSysBeginImplSettingCtrlLocks(Brand,FW,Name,ParamName,AttrName)</tt>
 * <br><tt>CATSysEndImplSettingCtrlLocks(Brand,FW,Name,ParamName)</tt>
 * @param Brand
 *   The brand to which this controller belongs
 * @param FW
 *   The framework in which the controller is implemented
 * @param Name
 *   The name of the controller
 * @param ParamName
 *   The name of the setting's parameter which is used in the method's name
  * @param AttrName
 *   The name of the unique underlying setting's attribute
 */
#if defined(_LINUX_SOURCE) || defined(_DARWIN_SOURCE) || defined(_IOS_SOURCE)|| defined (_ANDROID_SOURCE)

#define CATSysImplementSettingCtrlLocks(Brand,FW,Name,ParamName,AttrName)  \
static char* Brand##FW##Name##ParamName[]={(char *)#ParamName,(char *)#AttrName,NULL};  \
static CATSysParamMap Brand##FW##Name##ParamName##Map (			\
					&Brand##FW##Name##ParamMap,	\
					Brand##FW##Name##ParamName);	\
HRESULT Brand##FW##Name##SettingCtrl::Get##ParamName##Info (		\
						CATSettingInfo* oInfo)	\
{									\
  /* If the Controller parameter is made from many attributes   */	\
  /* Only the first one will be used for the GetInfo but all    */	\
  /* will be locked						*/	\
  HRESULT hres =GetInfo ( #AttrName, oInfo);				\
  if (SUCCEEDED(hres) && (oInfo))					\
    {									\
       oInfo->SetFunc((CATSysSettingCtrlInfoMethod)			\
  		&Brand##FW##Name##SettingCtrl::Get##ParamName##Info,	\
  		       (CATSysSettingCtrlLockingMethod)			\
  		&Brand##FW##Name##SettingCtrl::Set##ParamName##Lock,	\
  			_TheCtrl, #ParamName);				\
    }									\
  return hres;								\
}									\
									\
HRESULT Brand##FW##Name##SettingCtrl::Set##ParamName##Lock (		\
					unsigned char iLock)		\
{									\
  if ( iLock ==FALSE)							\
    return  Unlock ( #AttrName);					\
  else									\
    return Lock (#AttrName);						\
}									
#else

#define CATSysImplementSettingCtrlLocks(Brand,FW,Name,ParamName,AttrName)  \
static char* Brand##FW##Name##ParamName[]={(char *)#ParamName,(char *)#AttrName,NULL};  \
static CATSysParamMap Brand##FW##Name##ParamName##Map (			\
					&Brand##FW##Name##ParamMap,	\
					Brand##FW##Name##ParamName);	\
HRESULT Brand##FW##Name##SettingCtrl::Get##ParamName##Info (		\
						CATSettingInfo* oInfo)	\
{									\
  /* If the Controller parameter is made from many attributes   */	\
  /* Only the first one will be used for the GetInfo but all    */	\
  /* will be locked						*/	\
  HRESULT hres =GetInfo ( #AttrName, oInfo);				\
  if (SUCCEEDED(hres) && (oInfo))					\
    {									\
       oInfo->SetFunc((CATSysSettingCtrlInfoMethod)			\
  		&Brand##FW##Name##SettingCtrl##::Get##ParamName##Info,	\
  		       (CATSysSettingCtrlLockingMethod)			\
  		&Brand##FW##Name##SettingCtrl##::Set##ParamName##Lock,	\
  			_TheCtrl, #ParamName);				\
    }									\
  return hres;								\
}									\
									\
HRESULT Brand##FW##Name##SettingCtrl::Set##ParamName##Lock (		\
					unsigned char iLock)		\
{									\
  if ( iLock ==FALSE)							\
    return  Unlock ( #AttrName);					\
  else									\
    return Lock (#AttrName);						\
}									
#endif







/**
 * Implements the methods dealing with the locks of a seting parameter in the Automation context.
 * <br><b>Role</b>: For each parameter exposed by a settings controller 
 * in its interface BrandIANameSettingAtt, a method dealing with the lock 
 * and a method retrieving the information concerning the parameter must be 
 * available.
 * This macro will implement the three following methods:
 * <ul>
 *  <li><tt>HRESULT BrandFWNameAutoSettingCtrl::GetParamNameInfo(CATSettingInfo* oInfo)</tt></li>
 *  <li><tt>HRESULT BrandFWNameSettingCtrl::SetLockParamName (unsigned char iLock)</tt></li>
 * </ul>
 * <br>This macro must be used if the controller's parameter represents only
 * one CATSysSettingController's attribute. It is equivalent to the use of the
 * two macros  @href CATSysBeginImplSettingCtrlLocks 
 * and  @href CATSysEndImplSettingCtrlLocks in the following sequence:
 * <br><tt>CATSysBeginImplSettingCtrlLocks(ClassName,ParamName,AttrName)</tt>
 * <br><tt>CATSysEndImplSettingCtrlLocks(ClassName,ParamName)</tt>
 * @param ClassName
 *   The class name of the object implementing the controller
 * @param ParamName
 *   The name of the setting's parameter used in the method's name
 */
#define CATSysImplAutoSettingCtrlLocks(Brand,FW,Name,ParamName)		\
CATImplAutoSettingCtrlInfoMethod(Brand,FW,Name,ParamName)		\
									\
HRESULT Brand##FW##Name##AutoSettingCtrl::Set##ParamName##Lock (	\
					CAT_VARIANT_BOOL iLock)		\
{									\
  HRESULT hres = E_FAIL;						\
  Brand##I##FW##Name##SettingAtt *Att=NULL;				\
  hres = QueryInterface ( IID_##Brand##I##FW##Name##SettingAtt,		\
			  (void**)&Att);				\
  hres = Att->Set##ParamName##Lock (VARBOOL_TO_BOOL(iLock));				\
  Att->Release();							\
  return hres;								\
}									\






/**
 * Declares the methods dealing with the setting parameter locks.
 * <br><b>Role</b>: For each parameter exposed by a settings controller 
 * in its interface BrandIFWNameSettingAtt a method dealing with the lock 
 * and a method retrieving the information concerning the parameter must be 
 * available. 
 * This macro will declare the three following methods in the class 
 * implementing the two interfaces:
 * <ul>
 *  <li><tt>HRESULT BrandFWNameSettingCtrl::GetParamNameInfo(CATSettingInfo* oInfo)</tt></li>
 *  <li><tt>HRESULT BrandFWNameSettingCtrl::SetParamNameLock(unsigned char iLock)</tt></li>
 * </ul>
 * <br>The implementation macros are @href CATSysBeginImplSettingCtrlLocks , 
 * @href CATSysAddImplSettingCtrlLocks and @href CATSysEndImplSettingCtrlLocks 
 * or @href CATSysImplementSettingCtrlLocks
 * @param ClassName
 *   The class name of the objet implementing the controller
 * @param ParamName
 *   The name of the setting's parameter used in the method's name
 */
#if defined (_LINUX_SOURCE) || defined (_ANDROID_SOURCE)
#define CATSysDeclareSettingCtrlLocks(ParamName)			\
HRESULT Set##ParamName##Lock(unsigned char iLock);			\
HRESULT Get##ParamName##Info(CATSettingInfo* oInfo)			
#else
#define CATSysDeclareSettingCtrlLocks(ParamName)			\
HRESULT Set##ParamName##Lock (unsigned char iLock);			\
HRESULT Get##ParamName##Info(CATSettingInfo* oInfo)			
#endif

/**
 * Declares the methods dealing with the setting parameter locks.
 * <br><b>Role</b>: For each parameter exposed by a settings controller 
 * in its interface BrandIANameSettingAtt a method dealing with the lock 
 * and a method retrieving the information concerning the parameter must be 
 * available. 
 * This macro will declare the three following methods in the class 
 * implementing the two interfaces:
 * <ul>
 *  <li><tt>HRESULT BrandIANameSettingCtrl::GetParamNameInfo(CATSettingInfo* oInfo)</tt></li>
 *  <li><tt>HRESULT BrandIANameSettingCtrl::SetParamNameLock(unsigned char iLock)</tt></li>
 * </ul>
 * <br>The implementation macro is @href CATSysImplAutoSettingCtrlLocks 
 * @param ClassName
 *   The class name of the object implementing the controller
 * @param ParamName
 *   The name of the setting's parameter used in the method's name
 */
#define CATSysDeclareAutoSettingCtrlLocks(ParamName)			\
HRESULT Set##ParamName##Lock (CAT_VARIANT_BOOL iLock);			\
HRESULT Get##ParamName##Info(CATBSTR & AdminLevel,			\
			     CATBSTR & oLocked,				\
	                     CAT_VARIANT_BOOL &oModified)			\






/**
 * Dispatches an event when a setting single parameter is modified.
 * <br><b>Role</b>: For each parameter exposed by a settings controller 
 * it is possible to dispatch an event when this parameter is modified.
 * This macro can be used in the implementation of the SetParam method if
 * the dispatching of the event @href CATSysSettingController#Param_Updated
 * is needed.
 * @param ParamName
 *   The name of the parameter
 */
#define CATSysSettingCtrlDispatch(ParamName)				\
CATSettingInfo Info;							\
HRESULT hres= Get##ParamName##Info( &Info);				\
CATSysSettingCtrlNotif *Notif = NULL;					\
Notif = new CATSysSettingCtrlNotif(SettingCtrl_Updated(), &Info);	\
GetDefaultCallbackManager(this)->DispatchCallbacks( Param_Updated(),	\
						    Notif,this)		\





#endif
