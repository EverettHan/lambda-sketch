// COPYRIGHT DASSAULT SYSTEMES 2017
//=============================================================================
//
// CATWbDebug:
//  - Debug class for WhiteBoxes
//=============================================================================
//=============================================================================
// Usage notes:
//=============================================================================
// 03/04/17 Q48 Creation (borrowed heavily from CATGeoOpDebug)
// 25/04/17 PKC compilation warning
// 24/07/18 R1Y Added PrintExp() and two categories (EQPR and TRANS).
// 29/04/19 R1Y Added WBX_IF_TRACE()
// 18/07/19 Q48 ExportedBy and protection by #ifdef
//=============================================================================
#ifndef CATWBDebug_H
#define CATWBDebug_H

// To activate the trace
//=======================

#include "CATWBDebugSwitch.h"

// ------------------------------------------------------------------------
// Put even the includes behind #ifdef so that we don't enlarge the build
// impact for CDS
// ------------------------------------------------------------------------
// Removed CATCDSStream from this header file --> no more enlarged build
// for CDS --> keep the class defined even if debug is not active. This
// is useful because then the debug can be activated and not change the
// public classes / functions of the dll
// ------------------------------------------------------------------------
//#ifdef WBX_DEBUG_TRACE

// Exported by
#include "WhiteBoxMath.h"

// Basic types
#include "CATCDSBoolean.h"
#include "CATCDSString.h"

// White box
#include "CATWBTypes.h"

// Output
//#include <iostream.h>
//#include "CATCDSStream.h" // allows cout / endl
//#include "CATCGMOutput.h" // allows cgmout / cgmendl but not accessible from here

class CATWBExpression;
class CATWBValue;

//#endif // WBX_DEBUG_TRACE

// -------------------------
// Crude debug trace macros
// -------------------------

#ifdef WBX_DEBUG_TRACE

#define WBX_DEBUG_CMD(Code) Code
#define WBX_DEBUG_INIT(Code) Code,

#define OBJ(ObjToPrint) CATWBDebug::Str(ObjToPrint)

//#define GETWBXTRACE CATWBDebug* _WBxDebug = CATWBDebug::GetWBDebug()
//#define GETWBXTRACE_INTERNAL _WBxDebug = CATWBDebug::GetWBDebug()
#define WBX_DEBUG_DECLARE protected: static CATWBDebug* _WBxDebug;
#define WBX_DEBUG_DEFINE(Class) CATWBDebug* Class::_WBxDebug = CATWBDebug::GetWBDebug();

#define WBX_TABS _WBxDebug->Tabs_Print()
#define WBX_TRACE_INDENT_INC _WBxDebug->Tabs_Increase(1)
#define WBX_TRACE_INDENT_DEC _WBxDebug->Tabs_Decrease(1)

#define WBX_CAT(cat) CATWBDebug::WBX_TRACE::WBX_TRACE_CAT_##cat
#define WBX_LEV(lev) CATWBDebug::WBX_TRACE::WBX_TRACE_LEVEL_##lev

#define WBX_TRACE_ACTIVE(cat, lev) _WBxDebug->ActiveTrace(WBX_CAT(cat), WBX_LEV(lev))

#define WBX_HEAD(cat, lev) cout << "WBx-" << #cat << "-" << #lev << ": ";

#define WBX_TRACE(cat, lev, a) {if (WBX_TRACE_ACTIVE(cat, lev)) { WBX_HEAD(cat, lev); cout << a << endl; } else {}}
#define WBX_TRACE_TAB(cat, lev, a) {if (WBX_TRACE_ACTIVE(cat, lev)) { WBX_TABS; WBX_TRACE(cat, lev, a) } else {}}

#define WBX_IF_TRACE(cat, lev, cond, txt) if (cond) { WBX_TRACE(cat, lev, txt); } else {}

#define WBX_ENDL(cat, lev) WBX_TRACE(cat, lev, "")

#define WBX_TRACE_CALL(cat, lev, func) {if (WBX_TRACE_ACTIVE(cat, lev)) { func; } else {}}
#define WBX_IF_TRACE_CALL(cat, lev, cond, func) {if (cond) { WBX_TRACE_CALL(cat, lev, func); } else {}}

//#define WBX_IFELSE_TRACE(Cond, cat, lev1, lev2, a) if (Cond) { WBX_TRACE(cat, lev1, a); } else { WBX_TRACE(cat, lev2, a); }
#define WBX_IFELSE_TRACE_TAB(Cond, cat, lev1, lev2, a) if (Cond) { WBX_TRACE_TAB(cat, lev1, a); } else { WBX_TRACE_TAB(cat, lev2, a); }

//#define WBX_IFELSE_ENDL(Cond, lev1, lev2) if (Cond) { WBX_ENDL(cat, lev1); } else { WBX_ENDL(cat, lev2); }

#define WBX_TRACE_SET_INTERNAL _factory._InternalMode = TRUE;
#define WBX_TRACE_SET_EXTERNAL _factory._InternalMode = FALSE;

#define WBX_TRACE_DIFF(depth, lev1, lev2, a) WBX_IFELSE_TRACE_TAB(_WBxDebug->Depth_Differentiate_Equals(depth) /*&& !_factory._InternalMode*/, DIFF, lev1, lev2, a)
#define WBX_TRACE_COUNTER_DIFF_INC _WBxDebug->Depth_Differentiate_Increase();
#define WBX_TRACE_COUNTER_DIFF_DEC _WBxDebug->Depth_Differentiate_Decrease();

#else

#define WBX_DEBUG_CMD(Code)
#define WBX_DEBUG_INIT(Code)

#define OBJ(ObjToPrint)

//#define WBX_DEBUG_DECLARE
//#define WBX_DEBUG_DEFINE(Class)
#define WBX_DEBUG_DECLARE protected: static CATWBDebug* _WBxDebug;
#define WBX_DEBUG_DEFINE(Class) CATWBDebug* Class::_WBxDebug = NULL;

#define WBX_TRACE_INDENT_INC 
#define WBX_TRACE_INDENT_DEC 

//#define WBX_TRACE_ACTIVE(lev)

#define WBX_TRACE(cat, lev, a)
#define WBX_TRACE_TAB(cat, lev, a)

#define WBX_ENDL(cat, lev)

#define WBX_TRACE_CALL(cat, lev, func)
#define WBX_IF_TRACE_CALL(cat, lev, cond, func)

#define WBX_IF_TRACE(Cond, cat, lev, a)

#define WBX_TRACE_SET_INTERNAL
#define WBX_TRACE_SET_EXTERNAL

#define WBX_TRACE_DIFF(depth, lev1, lev2, a)
#define WBX_TRACE_COUNTER_DIFF_INC
#define WBX_TRACE_COUNTER_DIFF_DEC

#endif // WBX_DEBUG_TRACE

//#ifdef WBX_DEBUG_TRACE

class ExportedByWhiteBoxMath CATWBDebug
{
public:

  struct WBX_TRACE
  {
    /*typedef*/ // PKC 25/04/2017 useless typedef in C++, compilation warning 
    enum WBX_TRACE_CAT
    {
      WBX_TRACE_CAT_MIN = -1,
      WBX_TRACE_CAT_JSON,
      WBX_TRACE_CAT_LIFE,
      WBX_TRACE_CAT_EVAL,
      WBX_TRACE_CAT_DIFF,
      WBX_TRACE_CAT_EQPR,
      WBX_TRACE_CAT_TRANS,
      WBX_TRACE_CAT_SOLVE,
      WBX_TRACE_CAT_MAX
    };

    enum WBX_TRACE_LEVEL
    {
      WBX_TRACE_LEVEL_UNSET = -1,
      WBX_TRACE_LEVEL_OFF,
      WBX_TRACE_LEVEL_ERR,
      WBX_TRACE_LEVEL_WARN,
      WBX_TRACE_LEVEL_INFO,
      WBX_TRACE_LEVEL_VERB,
      WBX_TRACE_LEVEL_ALL
    };
  };

  //-----------------------------
  // Constructors and destructors
  //-----------------------------
protected:

  CATWBDebug();
  CATWBDebug(const CATWBDebug &);
  CATWBDebug & operator=(const CATWBDebug &);

public:

  virtual ~CATWBDebug();

  // Get the instance
  static CATWBDebug* GetWBDebug();

public:

  // Static utilities (for the "OBJ" macros")
  static CATCDSString Str(const CATCDSBoolean       iBool);
  static CATCDSString Str(const CATWBValue        & iValue);
  static CATCDSString Str(const CATWBEquationType   iType);
  static CATCDSString Str(const CATWBExpressionType iType);

public:

  CATCDSBoolean ActiveTrace(const WBX_TRACE::WBX_TRACE_CAT iCategory,
                            const WBX_TRACE::WBX_TRACE_LEVEL iLevel) const;
  
  
  void Tabs_Print() const;
  void Tabs_Increase(const int iNum = 1);
  void Tabs_Decrease(const int iNum = 1);

  CATCDSBoolean Depth_Differentiate_Equals(const int iDepth) const;
  void Depth_Differentiate_Increase();
  void Depth_Differentiate_Decrease();

  void PrintExp(const char            * const iPreString,
                const CATWBExpression * const iExpression,
                const char            * const iPostString) const;

protected:
    
  static CATWBDebug * _TheCATWBDebug;  // singleton instance

protected:

  void CommonInitialize();
  void InitTraceFromEnv();
  void InitTraceFromEnv(const WBX_TRACE::WBX_TRACE_CAT   iCategory,
                        const CATCDSString             & iCategoryStr);
    
  CATCDSBoolean CheckCategory(const WBX_TRACE::WBX_TRACE_CAT iCategory) const;
protected:

protected:
  
  int _Depth_Differentiate;

  CATCDSBoolean _TraceInit;

  WBX_TRACE::WBX_TRACE_LEVEL _TraceLevel[WBX_TRACE::WBX_TRACE_CAT_MAX];
  int                        _TraceTabs;
};
//#endif // WBX_DEBUG_TRACE
#endif // CATWBDebug_H
