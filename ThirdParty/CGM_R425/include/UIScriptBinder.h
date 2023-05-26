//===================================================================
// COPYRIGHT Dassault Systemes 2013/04/10
//===================================================================
// UIScriptBinder.cpp
// Header definition of class UIScriptBinder
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2013/04/10 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef UIScriptBinder_H
#define UIScriptBinder_H

#include "UIScriptBase.h"
#include "UIScriptBinderBase.h"

// System 
#include "CATBaseUnknown.h"

//ECMAScriptEngine
#include "ESValue.h"
#include "ESObject.h"
#include "ESString.h"
#include "ESFunction.h"
#include "ESNumber.h"
#include "ESBoolean.h"
#include "ESArray.h"

class UIScriptContext;

/**
* <b>Role</b>: class to create a binder that will provide several features related to IntrospectionInfrastructure FW in a given context.
*
* @see UIScriptBinderBase
*/
class ExportedByUIScriptBase UIScriptBinder: public UIScriptBinderBase
{
  CATDeclareClass; 
public:
  /**
  * constructor
  * @param i_Ctx the context where the binder will be registered.
  */
  UIScriptBinder (UIScriptContext* i_Ctx);
  
  /** @copydoc UIScriptBinderBase#RegisterTypes */
  virtual void RegisterTypes();

  /** @copydoc UIScriptBinderBase#UnregisterTypes */
  virtual void UnregisterTypes(); 
  
  /** @copydoc UIScriptBinderBase#Commit */
  virtual void Commit();
  
  /** @copydoc UIScriptBinderBase#GetProperties */
  virtual void GetProperties(CATCommand* i_This, CATListOfCATUnicodeString& o_Properties);

  /** @copydoc UIScriptBinderBase#GetProperty */
  virtual ES::Value GetProperty(CATCommand* i_This, const CATUnicodeString& i_PropName); 
 
  /** @copydoc UIScriptBinderBase#SetProperty */
  virtual CATBoolean SetProperty(CATCommand* i_This, const CATUnicodeString& i_PropName, const ES::Value& i_Value);
 
private:
  // Copy constructor and equal operator
  // -----------------------------------
  UIScriptBinder (UIScriptBinder &);
  UIScriptBinder& operator=(UIScriptBinder&);

  static void UIScriptDestructorCallBack(void* instance);

  static void OnTimeoutCB(CATCommand* iCmd, int iTime, void* iClientData);
 
  // Static methods used for bindings
  static ES::Object*  s_CreateElement(UIScriptContext* iCtx, const ES::String& iClassName);
  static void         s_EvaluateScript(UIScriptContext* iCtx, const ES::String& iScript);   
  static ES::String*  s_LoadJSON(UIScriptContext* iCtx, const ES::String& iFilePath);
  static ES::Array*   s_GetProperties(UIScriptContext* iCtx, CATCommand* iCmd);
  static ES::Value*   s_GetProperty(UIScriptContext* iCtx, CATCommand* iCmd, const ES::String& iPropName);
  static void         s_SetProperty(UIScriptContext* iCtx, CATCommand* iCmd, const ES::String& iPropName, const ES::Value& iValue);
  static void         s_AddEventListener(UIScriptContext* iCtx, CATCommand* iCmd, const ES::String& iEventType, const ES::Function& iEventListener);
  static void         s_RemoveEventListener(UIScriptContext* iCtx, CATCommand* iCmd, const ES::String& iEventType, const ES::Function& iEventListener);
  static void         s_Animate(UIScriptContext* iCtx, CATCommand* iCmd, const ES::Object& iParams, const ES::Number& iDuration, const ES::Number& iRepeatBehavior, const ES::Boolean& iAutoReverseFlag, const ES::String& iEasing);
  static void         s_DestroyNativeObject(UIScriptContext* iCtx, void* iPtr);
  static void         s_Connect(UIScriptContext* iCtx, CATCommand* iSource, const ES::String& iSourceName, CATCommand* iTarget, const ES::String& iTargetName);
  static void         s_SetTimeout(ES::Function& iFunction, int delay);

  friend class UIScriptTst_UIScriptBinder_StaticBindings;

};

//-----------------------------------------------------------------------

#endif
