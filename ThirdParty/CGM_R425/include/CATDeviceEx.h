#ifndef CATDeviceEx_H_
#define CATDeviceEx_H_

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                                                                                //
//      8888888b.   .d88888b.       888b    888  .d88888b. 88888888888      888     888  .d8888b.  8888888888                                                                     //
//      888  "Y88b d88P" "Y88b      8888b   888 d88P" "Y88b    888          888     888 d88P  Y88b 888                                                                            //
//      888    888 888     888      88888b  888 888     888    888          888     888 Y88b.      888                                                                            //
//      888    888 888     888      888Y88b 888 888     888    888          888     888  "Y888b.   8888888                                                                        //
//      888    888 888     888      888 Y88b888 888     888    888          888     888     "Y88b. 888                                                                            //
//      888    888 888     888      888  Y88888 888     888    888          888     888       "888 888                                                                            //
//      888  .d88P Y88b. .d88P      888   Y8888 Y88b. .d88P    888          Y88b. .d88P Y88b  d88P 888                                                                            //
//      8888888P"   "Y88888P"       888    Y888  "Y88888P"     888           "Y88888P"   "Y8888P"  8888888888                                                                     //
//                                                                                                                                                                                //
//                                                                                                                                                                                //
//                                                                                                                                                                                //
//      8888888          888                                      888                                                                                           888               //
//        888            888                                      888                                                                                           888               //
//        888            888                                      888                                                                                           888               //
//        888   88888b.  888888 .d88b.  888d888 88888b.   8888b.  888      88888b.  888  888 888d888 88888b.   .d88b.  .d8888b   .d88b.        .d88b.  88888b.  888 888  888      //
//        888   888 "88b 888   d8P  Y8b 888P"   888 "88b     "88b 888      888 "88b 888  888 888P"   888 "88b d88""88b 88K      d8P  Y8b      d88""88b 888 "88b 888 888  888      //
//        888   888  888 888   88888888 888     888  888 .d888888 888      888  888 888  888 888     888  888 888  888 "Y8888b. 88888888      888  888 888  888 888 888  888      //
//        888   888  888 Y88b. Y8b.     888     888  888 888  888 888      888 d88P Y88b 888 888     888 d88P Y88..88P      X88 Y8b.          Y88..88P 888  888 888 Y88b 888      //
//      8888888 888  888  "Y888 "Y8888  888     888  888 "Y888888 888      88888P"   "Y88888 888     88888P"   "Y88P"   88888P'  "Y8888        "Y88P"  888  888 888  "Y88888      //
//                                                                         888                       888                                                                 888      //
//                                                                         888                       888                                                            Y8b d88P      //
//                                                                         888                       888                                                             "Y88P"       //
//                                                                                                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/************************************************************************/
/* Defines                                                              */
/************************************************************************/
#define CATDEVICEEXT_ID_A2X               78

#define CATDEVICEEX_LAST_MOUSE_POSITION_SUPPPORTED

/************************************************************************/
/* Global includes                                                      */
/************************************************************************/

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/
#include "A2XService.h"
#include "CATBaseUnknown.h"
#include "CATDevice.h"
#include "CATKeybdEvent.h"
#include "CATMathPoint2Df.h"
#include "CATModelIdentificator.h"
#include "CATPickPathList.h"
#include "CATSysMacros.h"
#include "DSYSysCommon.h"
#include "DSYSysJSON.h"
#include "DSYString.h"
#include "DSYStringView.h"
#include "DSYSysStdIO.h"
#include "DSYSysTrace.h"
#include "list.h"

/************************************************************************/
/* Classes declaration                                                  */
/************************************************************************/

/**
 * @namespace VisuA2X
 */
namespace VisuA2X
{
  /**
 * @struct ODT
 */
  struct ODT
  {
    /// Action file descriptor.
    DSYSysFileDescriptor _EventFileDesc;

    /// Action file descriptor.
    DSYSysFileDescriptor _EventFileDescWeb;

    // Action file version
    CATUnicodeString _ActionFileVersion = "1.0";
  };

  /**
   * @class CATDeviceEx
   */
  class CATDeviceEx
  {
  #ifdef DSY_SYS_BAN_EVIL_CONSTRUCTORS_MACROS_DEFINED
    DSYSysBanEvilConstructors(CATDeviceEx);
  #endif  // DSY_SYS_BAN_EVIL_CONSTRUCTORS_MACROS_DEFINED

    ///////////////////////////////////////////
    ////// Types/Constants/Struct/Enum ////////
    ///////////////////////////////////////////
  public:

    ///////////////////////////////////////////
    ///////////////// Methods /////////////////
    ///////////////////////////////////////////
  public:
    /// Constructor (default).
    CATDeviceEx(DSYSysTraceHandle ihTrace = nullptr)
    : m_PickingOption(0)
    , m_hTrace(nullptr)
    , m_pODT(nullptr)
    {
      // Reset position.
      TrapInitPositionReset();
    }

    /// Destructor.
    virtual ~CATDeviceEx()
    {
      // Reset pick path list.
      m_PickPathList.Reset();

      // Reset.
      m_hTrace = nullptr;
      m_pODT = nullptr;
    }

    /// Get trace handle.
    DSYSysTraceHandle TraceHandleGet(void) const
    { return m_hTrace; }

    /// Set trace handle.
    void TraceHandleSet(DSYSysTraceHandle ihTrace = nullptr)
    { m_hTrace = ihTrace; }

    /// Get gesture.
    CATUnicodeString& WebGestureGet(void)
    { return m_Gesture; }

    /// Get pick path list object.
    CATPickPathList& PickPathListGet(void)
    { return m_PickPathList; }

    /// Reset position.
    void TrapInitPositionReset(void)
    { _TrapInitPosition.x = _TrapInitPosition.y = -1; }

    /// Set ODT structure.
    void OdtSet(VisuA2X::ODT* ipOdtStruct)
    { m_pODT = ipOdtStruct; }

    /// Get ODT structure.
    VisuA2X::ODT* OdtGet(void) const
    { return m_pODT; }

    ///////////////////////////////////////////
    ///////////////// Members /////////////////
    ///////////////////////////////////////////
  public:
    /// Keep native picking flag.
    int m_PickingOption;

    /// Position.
    CATMathPoint2Df _TrapInitPosition;

#ifdef CATDEVICEEX_LAST_MOUSE_POSITION_SUPPPORTED
    /// Last mouse event position.
    CATMathPoint2Df _LastMouseEventPosition;
#endif  // CATDEVICEEX_LAST_MOUSE_POSITION_SUPPPORTED

  protected:
    /// Gesture (string).
    CATUnicodeString m_Gesture;

    /// List of pick path.
    CATPickPathList m_PickPathList;

  private:
    /// Trace handle.
    DSYSysTraceHandle m_hTrace;

    /// Structure for ODT.
    VisuA2X::ODT* m_pODT;
  };

} // namespace VisuA2X

/************************************************************************/
/* Functions declaration                                                */
/************************************************************************/

/**
 * @namespace VisuA2X
 */
namespace VisuA2X
{
  //=======================================================================
  inline CATDeviceEx* ExtensionGet(const CATDevice& irDevice)
  //=======================================================================
  { return (VisuA2X::CATDeviceEx *)irDevice.ExtensionGet(CATDEVICEEXT_ID_A2X); }

  //=======================================================================
  inline void* ExtensionAttach(CATDevice& irDevice, void* ipExtension, bool iForceReplace = true)
  //=======================================================================
  { return (VisuA2X::CATDeviceEx *)irDevice.ExtensionAttach(CATDEVICEEXT_ID_A2X, ipExtension, iForceReplace); }

  //=======================================================================
  inline bool ExtensionDetach(CATDevice& irDevice, void** oppExtension = nullptr)
  //=======================================================================
  { return irDevice.ExtensionDetach(CATDEVICEEXT_ID_A2X, oppExtension); }

  /************************************************************************/
  /************************************************************************/

  //=======================================================================
  inline bool IsA2X(const CATDevice* ipDevice = nullptr)
  //=======================================================================
  {
    if( nullptr != ipDevice )
    { return nullptr != ExtensionGet(*ipDevice); }
    else
    { return (0 != isA2X()); }
  }

  /************************************************************************/
  /************************************************************************/

  //=======================================================================
  static void DumpAsTrace(DSYSysTraceHandle ihTrace, CATPickPath& irPickPath)
  //=======================================================================
  {
    if( nullptr == ihTrace ) return;
    CATUnicodeString l_Indent;
    int l_SizeOfThePath = irPickPath.Size();
    DSYSysTraceInfo(ihTrace, "##### Pick Path (%p) ", &irPickPath);
    // Intersection.
    const CATMathPointf& l_rIntersection = irPickPath.GetIntersection();
    DSYSysTraceInfo(ihTrace, "Intersection [x:%f y:%f z:%f]", l_rIntersection.x, l_rIntersection.y, l_rIntersection.z);
    // Normal.
    const CATMathDirectionf& l_rNormal = irPickPath.GetNormal();
    DSYSysTraceInfo(ihTrace, "Normal [x:%f y:%f z:%f]", l_rNormal.x, l_rNormal.y, l_rNormal.z);
    for( int p = 0; p < l_SizeOfThePath; p++ )
    {
      l_Indent += " |";
      CATRep* l_pRep = irPickPath[p];
      if( nullptr != l_pRep )
      {
        CATBaseUnknown* l_pModel = NULL;
        const CATModelIdentificator* l_pModelId = l_pRep->GetIdentificator();
        if( nullptr != l_pModelId ) l_pModel = l_pModelId->GetId();
        DSYSysTraceInfo(ihTrace, "%s %s %s (%p)", l_Indent.ConvertToChar(), ((l_pModel)? l_pModel->IsA() : "???"), ((l_pRep->IsA3DRep())? "3D" : "2D"), l_pRep);
      }
      else
      { DSYSysTraceWarning(ihTrace, "%s", "!! CATRepPath == NULL !!\n"); }
    }
    DSYSysTraceInfo(ihTrace, "%s", "#####");
  }

  //=======================================================================
  static void DumpAsTrace(DSYSysTraceHandle ihTrace, CATPickPathList& irPickPathList)
  //=======================================================================
  {
    if( nullptr == ihTrace ) return;
    // Dump pick path list.
    ::list <CATPickPath>& l_rList = *irPickPathList.GetPickPathList();
    int l_Size = l_rList.length() - 1;
    CATPickPath* l_pPickPath = nullptr;
    for( int p = 0; l_pPickPath = l_rList[p]; p++ )
    {
      CATRep* l_pPickPathRep = l_pPickPath->GetTopRep();
      if( nullptr == l_pPickPathRep ) continue;
      DSYSysTraceInfo(ihTrace, "########## %d/%d", (p + 1), l_Size);
      VisuA2X::DumpAsTrace(ihTrace, *l_pPickPath);
      DSYSysTraceInfo(ihTrace, "%s", "##########");
    }
  }

  //=======================================================================
  static HRESULT PickPathToJson(DSYSysJSONValue& orJsonValue, CATPickPath& irPickPath)
  //=======================================================================
  {
    HRESULT l_hRes = E_FAIL;

    // Reset.
    orJsonValue.SetNull();

    do
    {
      // Retrieve Rep path.
      CATRep* l_pPickPathRep = irPickPath.GetTopRep();
      if( nullptr == l_pPickPathRep ) break;

      DSYSysJSONArray l_JsonArray;
      DSYSysJSONObject l_JsonObj;
      DSYSysJSONObject l_JsonObjPickPath;
      DSYSysJSONValue l_JsonValue;

      // Pick path size.
      int l_SizeOfThePath = irPickPath.Size();
      l_JsonObjPickPath.Push(DSYSysJSONPair("size", l_SizeOfThePath));

      // Intersection.
      // "intersection": [x y z]
      const CATMathPointf& l_rIntersection = irPickPath.GetIntersection();
      l_JsonValue.Set(l_rIntersection.x); l_JsonArray.Push(l_JsonValue);
      l_JsonValue.Set(l_rIntersection.y); l_JsonArray.Push(l_JsonValue);
      l_JsonValue.Set(l_rIntersection.z); l_JsonArray.Push(l_JsonValue);
      l_JsonObjPickPath.Push(DSYSysJSONPair("intersection", l_JsonArray));

      // Reset.
      l_JsonArray.Clear();
      
      // Normal.
      // "normal": [x y z]
      const CATMathDirectionf& l_rNormal = irPickPath.GetNormal();
      l_JsonValue.Set(l_rIntersection.x); l_JsonArray.Push(l_JsonValue);
      l_JsonValue.Set(l_rIntersection.y); l_JsonArray.Push(l_JsonValue);
      l_JsonValue.Set(l_rIntersection.z); l_JsonArray.Push(l_JsonValue);
      l_JsonObjPickPath.Push(DSYSysJSONPair("normal", l_JsonArray));
      
      // Reset.
      l_JsonArray.Clear();

      CATUnicodeString l_String;

      // Walk path list.
      for( int p = 0; p < l_SizeOfThePath; p++ )
      {
        CATRep* l_pRep = irPickPath[p];
        if( nullptr != l_pRep )
        {
          // Reset.
          l_JsonObj.Clear();

          CATBaseUnknown* l_pModel = NULL;
          const CATModelIdentificator* l_pModelId = l_pRep->GetIdentificator();
          if( nullptr != l_pModelId ) l_pModel = l_pModelId->GetId();

          l_JsonObj.Push(DSYSysJSONPair("modelid", ((l_pModel) ? l_pModel->IsA() : "???")));
          l_JsonObj.Push(DSYSysJSONPair("type", ((l_pRep->IsA3DRep()) ? "3D" : "2D")));
          if( 0 < l_String.BuildFromNum((uintptr_t)l_pRep, "%p") )
          { l_JsonObj.Push(DSYSysJSONPair("addr", l_String)); }

          // Set JSON object as value.
          l_JsonValue.Set(l_JsonObj);

          // Update array.
          l_JsonArray.Push(l_JsonValue);
        }
        else
        {
          // Bad model.
          l_JsonObj.Push(DSYSysJSONPair("modelid", "???"));
          l_JsonObj.Push(DSYSysJSONPair("type", "???"));
          l_JsonObj.Push(DSYSysJSONPair("addr", "???"));
        }
      }

      // Add array of pick path.
      l_JsonObjPickPath.Push(DSYSysJSONPair("reps", l_JsonArray));

      // Set JSON object as value.
      orJsonValue.Set(l_JsonObjPickPath);

      // Ok.
      l_hRes = S_OK;
    }
    while( false );

    // Done.
    return l_hRes;
  }

  //=======================================================================
  static void DumpAsTrace(DSYSysTraceHandle ihTrace, const CATKeybdEvent& irKeyBoardEvent, const bool iKeepKeyCodeOnly)
  //=======================================================================
  {
    DSYSysTraceInfo(ihTrace, "%s", "##### Keyboard Event");
    if( (iKeepKeyCodeOnly)  && (0 == irKeyBoardEvent.GetKeyCodeType()) )
    { DSYSysTraceInfo(ihTrace, "%s", "Keep only key code"); }
    else
    {
      DSYSysTraceInfo(ihTrace, "KeyCodeType: %d", irKeyBoardEvent.GetKeyCodeType());
      DSYSysTraceInfo(ihTrace, "keyCode: %u", irKeyBoardEvent.GetKeyCode());
      DSYSysTraceInfo(ihTrace, "modifier: %u", irKeyBoardEvent.GetModifier());
      DSYSysTraceInfo(ihTrace, "charCode: %u", irKeyBoardEvent.GetCharCode());
      if( irKeyBoardEvent.IsPressKey() ) DSYSysTraceInfo(ihTrace, "%s", "isPressKey: true");
      if( irKeyBoardEvent.IsReleaseKey() ) DSYSysTraceInfo(ihTrace, "%s", "isReleaseKey: true");
    }
    DSYSysTraceInfo(ihTrace, "%s", "#####");
  }

  /************************************************************************/
  /************************************************************************/

  //=======================================================================
  static void DumpAsOdt(VisuA2X::CATDeviceEx& irExtension, const CATMathPoint2Df& irPoint, CATPickPathList& irPickPathList)
  //=======================================================================
  {
    // Dump pick path list.
    VisuA2X::DumpAsTrace(irExtension.TraceHandleGet(), irPickPathList);

    VisuA2X::ODT* l_pOdt = irExtension.OdtGet();

    // File descriptor of ODT mode is opened.
    if( (nullptr != l_pOdt) && (nullptr != l_pOdt->_EventFileDesc._fs) )
    {
      DSYSysJSONValue l_JsonValue;
      DSYSysJSONArray l_JsonArray;
      DSYSysJSONObject l_JsonObjData, l_JsonObjInfo, l_JsonObjPoint;

      l_JsonObjInfo.Push(DSYSysJSONPair("version", "1.0"));
      l_JsonObjInfo.Push(DSYSysJSONPair("device", "mouse"));
      l_JsonObjPoint.Push(DSYSysJSONPair("x", (int)irPoint.x));
      l_JsonObjPoint.Push(DSYSysJSONPair("y", (int)irPoint.y));
      l_JsonObjData.Push(DSYSysJSONPair("point", l_JsonObjPoint));
      l_JsonObjData.Push(DSYSysJSONPair("webgesture", irExtension.WebGestureGet()));
      l_JsonObjData.Push(DSYSysJSONPair("pickingOption", irExtension.m_PickingOption));

      // Reset.
      l_JsonArray.Clear();

      CATPickPath* l_pPickPath = NULL;
      list<CATPickPath>& l_rList = *(irPickPathList.GetPickPathList());

      // Walk pick path list.
      for( int i = 0; l_pPickPath = l_rList[i]; i++ )
      {
        if( FAILED(VisuA2X::PickPathToJson(l_JsonValue, *l_pPickPath)) ) continue;
        l_JsonArray.Push(l_JsonValue);
      }

      // Push pick path list.
      l_JsonObjData.Push(DSYSysJSONPair("pickpathlist", l_JsonArray));

      // Data JSON object.
      l_JsonObjInfo.Push(DSYSysJSONPair("data", l_JsonObjData));

      // Set JSON object as value.
      l_JsonValue.Set(l_JsonObjInfo);

      CATUnicodeString l_DataString;

      // Convert to JSON string.
      if( SUCCEEDED(l_JsonValue.Stringify(l_DataString)) )
      {
        // Add new line.
        l_DataString += "\r\n";

        int l_Written = 0;
        auto strViewUtf8 = DSY::UCS::make_view<char, DSY::UCS::ToUTF8>(l_DataString);
        if( FAILED(DSYSysFPuts(strViewUtf8.data(), l_pOdt->_EventFileDesc, &l_Written)) )
        { DSYSysTraceError(irExtension.TraceHandleGet(), "%s Could NOT write content to action file", __func__); }
    
        // Force flush.
        DSYSysFFlush(l_pOdt->_EventFileDesc);
      }
    }
  }

  static void DumpAsOdt(VisuA2X::CATDeviceEx& irExtension, const CATKeybdEvent& irKeyBoardEvent,  const bool iKeepKeyCodeOnly = true)
  //=======================================================================
  //=======================================================================
  {
    // Logs.
    VisuA2X::DumpAsTrace(irExtension.TraceHandleGet(), irKeyBoardEvent, iKeepKeyCodeOnly);

    VisuA2X::ODT* l_pOdt = irExtension.OdtGet();

    do
    {
      // File descriptor of ODT mode is opened.
      if( (nullptr != l_pOdt) && (nullptr != l_pOdt->_EventFileDesc._fs) )
      {
        // Keep key code only.
        if( (iKeepKeyCodeOnly)  && (0 == irKeyBoardEvent.GetKeyCodeType()) ) break;

        DSYSysJSONValue l_JsonValue;
        DSYSysJSONObject l_JsonObjData;
        DSYSysJSONObject l_JsonObjInfo;

        if(l_pOdt->_ActionFileVersion == "1.0")
        {
          l_JsonObjInfo.Push(DSYSysJSONPair("version", "1.0"));
          l_JsonObjInfo.Push(DSYSysJSONPair("device", "keyboard"));
          l_JsonValue.Set(irKeyBoardEvent.GetKeyCodeType()); l_JsonObjData.Push(DSYSysJSONPair("keyCodeType", l_JsonValue));
          l_JsonValue.Set((CATLONG64)CATKeybdEvent::GetKeyFromCATKeyCode(irKeyBoardEvent.GetKeyCode())); l_JsonObjData.Push(DSYSysJSONPair("keyCode", l_JsonValue));
          l_JsonValue.Set((CATLONG64)irKeyBoardEvent.GetModifier()); l_JsonObjData.Push(DSYSysJSONPair("modifier", l_JsonValue));
          l_JsonValue.Set((CATLONG64)irKeyBoardEvent.GetCharCode()); l_JsonObjData.Push(DSYSysJSONPair("charCode", l_JsonValue));
          if( irKeyBoardEvent.IsPressKey() ) { l_JsonObjData.Push(DSYSysJSONPair("isPressKey", true)); }
          else if( irKeyBoardEvent.IsReleaseKey() ) { l_JsonObjData.Push(DSYSysJSONPair("isReleaseKey", true)); }
          l_JsonObjData.Push(DSYSysJSONPair("webgesture", irExtension.WebGestureGet()));
          l_JsonValue.Set((CATLONG64)irKeyBoardEvent._time); l_JsonObjData.Push(DSYSysJSONPair("time", l_JsonValue));
          l_JsonObjInfo.Push(DSYSysJSONPair("data", l_JsonObjData));
          // Set JSON object as value.
          l_JsonValue.Set(l_JsonObjInfo);
        }
        else if(l_pOdt->_ActionFileVersion == "1.1")
        {
            l_JsonObjInfo.Push(DSYSysJSONPair("version", l_pOdt->_ActionFileVersion ));
            l_JsonObjInfo.Push(DSYSysJSONPair("device", "keyboard"));

            l_JsonValue.Set((CATLONG64)irKeyBoardEvent.GetKeyCode()); l_JsonObjData.Push(DSYSysJSONPair("CATCode", l_JsonValue));

            l_JsonValue.Set((CATLONG64)CATKeybdEvent::GetKeyFromCATKeyCode(irKeyBoardEvent.GetKeyCode())); l_JsonObjData.Push(DSYSysJSONPair("key", l_JsonValue));
            l_JsonValue.Set((CATLONG64)irKeyBoardEvent.GetModifier()); l_JsonObjData.Push(DSYSysJSONPair("modifiers", l_JsonValue));
            if( irKeyBoardEvent.IsPressKey() ) { l_JsonObjData.Push(DSYSysJSONPair("isPressKey", true)); }
            else if( irKeyBoardEvent.IsReleaseKey() ) { l_JsonObjData.Push(DSYSysJSONPair("isReleaseKey", true)); }
            l_JsonObjData.Push(DSYSysJSONPair("webgesture", irExtension.WebGestureGet()));
            l_JsonValue.Set((CATLONG64)irKeyBoardEvent._time); l_JsonObjData.Push(DSYSysJSONPair("time", l_JsonValue));
            l_JsonObjInfo.Push(DSYSysJSONPair("data", l_JsonObjData));
            // Set JSON object as value.
            l_JsonValue.Set(l_JsonObjInfo);
        }



        // Convert to JSON string.
        CATUnicodeString l_DataString;
        if( SUCCEEDED(l_JsonValue.Stringify(l_DataString)) )
        {
          // Add new line.
          l_DataString += "\r\n";

          int l_Written = 0;
          auto strViewUtf8 = DSY::UCS::make_view<char, DSY::UCS::ToUTF8>(l_DataString);
          if( FAILED(DSYSysFPuts(strViewUtf8.data(), l_pOdt->_EventFileDesc, &l_Written)) )
          { DSYSysTraceError(irExtension.TraceHandleGet(), "%s Could NOT write content to action file", __func__); }
    
          // Force flush.
          DSYSysFFlush(l_pOdt->_EventFileDesc);
        }
      }
    }
    while( false );
  }
} // namespace VisuA2X

#endif  // CATDeviceEx_H_
