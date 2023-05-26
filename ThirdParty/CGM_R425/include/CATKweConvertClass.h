//===================================================================
// CATKweConvertClass
// Header definition of class CATKweConvertClass
//===================================================================
//
// Usage notes: Trace objects repository
//
//===================================================================
//  24.11.20 Creation KJD
//===================================================================/**

#ifndef CATKweConvertClass_h
#define CATKweConvertClass_h

#include "CATLifSpecs.h"
#include "CATICkeSignature.h"

// FW SystemTS
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATUnicodeChar.h"
#include "DSYSysTSLib.h"

#include "CATLISTV_CATBaseUnknown.h"
#include "CATCollecRoot.h"
#include "CATListOfInt.h"

class CATIType_var;
class CATICkeType_var;
class CATICkeArg_var;
class CATICkeMagnitude_var;
class CATIAlias_var;
class CATPathElement;
class CATIKwePythonScript_var;
class CATCkeEvalContext;
class CATIKweAppResourcesTable_var;
class CATIKweResourceTableProvider_var;

//----------------------------------------------------------------------
// CATKweConvertClass
//----------------------------------------------------------------------
class ExportedByCATLifSpecs CATKweConvertClass : public CATBaseUnknown
{
  CATDeclareClass;
public:
  CATKweConvertClass();
  virtual ~CATKweConvertClass();
  virtual CATKweConvertClass& operator<<(const char* c);
  virtual CATKweConvertClass& operator<<(char c);
  virtual CATKweConvertClass& operator<<(bool v);
  virtual CATKweConvertClass& operator<<(int v);
  virtual CATKweConvertClass& operator<<(long v);
  virtual CATKweConvertClass& operator<<(short v);
  virtual CATKweConvertClass& operator<<(unsigned v);
  virtual CATKweConvertClass& operator<<(double v);
  virtual CATKweConvertClass& operator<<(float v);
  virtual CATKweConvertClass& operator<<(void* v);

  virtual CATKweConvertClass& operator<<(const CATUnicodeString& v);
  virtual CATKweConvertClass& operator<<(CATUnicodeChar v);
  virtual CATKweConvertClass& operator<<(const CATBoolean& iBool);
  virtual CATKweConvertClass& operator<<(const CATBaseUnknown_var& ihUnk);
  virtual CATKweConvertClass& operator<<(const CATLibStatus& iStatus);
  virtual CATKweConvertClass& operator<<(const CATIType_var& iType);
  virtual CATKweConvertClass& operator<<(const CATICkeType_var& iType);
  virtual CATKweConvertClass& operator<<(const CATICkeNaming_var& iName);
  virtual CATKweConvertClass& operator<<(const CATICkeSignature_var& iSign);
  virtual CATKweConvertClass& operator<<(const CATICkeSignature::Mode& iMode);
  virtual CATKweConvertClass& operator<<(const CATICkeArg_var& iType);
  virtual CATKweConvertClass& operator<<(const CATICkeMagnitude_var& iMagn);
  virtual CATKweConvertClass& operator<<(const CATCkeEvalContext* iEvalCtx);
  virtual CATKweConvertClass& operator<<(const CATCollecRoot* liste);
  virtual CATKweConvertClass& operator<<(const CATListOfInt* liste);
  virtual CATKweConvertClass& operator<<(const CATIKweAppResourcesTable_var& ihResTable);
  virtual CATKweConvertClass& operator<<(const CATIKweResourceTableProvider_var& ihResTabProv);

  virtual CATKweConvertClass& operator<<(CATKweConvertClass&);
  virtual CATKweConvertClass& operator<<(CATKweConvertClass& (*f)(CATKweConvertClass&));

  //External implementation
  virtual CATKweConvertClass& operator<<(CATPathElement* iPathElt) { return *this; };
  virtual CATKweConvertClass& operator<<(const CATIKwePythonScript_var& iPyScript) { return *this; };


  void Endl();
  void Flush();
  CATUnicodeString TranslateHR(const HRESULT iHr);

  CATUnicodeString _Trace;
};

ExportedByCATLifSpecs CATKweConvertClass& endl(CATKweConvertClass& trace);
ExportedByCATLifSpecs CATKweConvertClass& flush(CATKweConvertClass& trace);

#endif
