//=====================================================================================
// COPYRIGHT DASSAULT SYSTEMES 2003
//=====================================================================================
// Creation AJM  12.Nov.2003
//
// Interface for body check operator rules
//=====================================================================================

#ifndef __CATBodyCheckerRules_h__
#define __CATBodyCheckerRules_h__

#include "CATBoolean.h"
#include "CATGeometryType.h"
#include "CATBodyChecker.h"

//=============================================================================

#define BC_RULE_CODE_LENGTH 6

//=============================================================================

// Enumerations for BodyChecker Operator Type

enum BodyCheckerOperatorType
{
  CATBodyCheckerType_CAA        = 0,
  CATBodyCheckerType_InternalDS = 1
};

//=============================================================================

#include "CATCGMLISTPP_Declare.h"

class CATBodyCheckerRuleDef;

CATCGMLISTPP_DECLARE(CATBodyCheckerRuleDef);

typedef CATLISTP(CATBodyCheckerRuleDef) ListPOfCATBodyCheckerRuleDef;

//=============================================================================

class ExportedByCATTopologicalOperators CATBodyCheckerRules 
{
  public:

    static CATBoolean GetDefaultRulesForMode(CATBodyChecker::CheckMode ieCheckerMode, CATLISTP(CATBodyCheckerRuleDef) &olsCheckRuleDefs);

    static CATBoolean CheckRuleDefs();

    static int GetNbRules();

    static CATBodyChecker::CheckRuleID GetRule(int iRank);

    static CATBodyCheckerRuleDef* GetRuleDefinition(CATBodyChecker::CheckRuleID iRule);

    static CATBodyCheckerRuleDef* GetRuleDefinition(const char *iRuleCode);

    static CATBodyChecker::CheckMode GetRuleCheckMode(CATBodyChecker::CheckRuleID iRule);

    static CATGeometricType GetTargetType(CATBodyChecker::CheckRuleID iRule);

    static char* GetRuleCode(CATBodyChecker::CheckRuleID iRule);

    static CATBoolean GetRuleDefsFromCodes(CATUnicodeString &strRuleCodes, CATLISTP(CATBodyCheckerRuleDef) &olsCheckRuleDefs);

  protected:

    static CATBoolean            _bCheckRuleDefsDoneOK;

    static CATBodyCheckerRuleDef *GetRuleDefs();
};

//=============================================================================

typedef struct ExportedByCATTopologicalOperators CATBodyCheckerRuleParam
{
public:
  double _dMinCurvatureRadiusCurve;
  double _dMinCurvatureRadiusSurface;
  double _dMinTopologicalEdgeLength;

  CATBodyCheckerRuleParam();
  virtual ~CATBodyCheckerRuleParam();
  CATBodyCheckerRuleParam(const CATBodyCheckerRuleParam& iToCopy);
  CATBodyCheckerRuleParam& operator = (const CATBodyCheckerRuleParam& iToCopy);
  void MakeParamsAbsolute();

protected:
  void DoCopy(const CATBodyCheckerRuleParam& iToCopy);
} CATBCRuleParam;

typedef struct CATBodyCheckerRuleParamExt
{

public:
  CATBodyChecker::CheckRuleID    _ruleID;
  size_t                         _DataSize;
  void*                          _pData;

} CATBCRuleParamExt;

//=============================================================================

class ExportedByCATTopologicalOperators CATBodyCheckerRuleDef
{
  friend class CATBodyCheckerRules;

public:
  CATBodyCheckerRuleDef(CATBodyChecker::CheckRuleID iRule);
  virtual ~CATBodyCheckerRuleDef();

  CATBodyCheckerRuleDef* Clone();
  CATBoolean operator == (const CATBodyCheckerRuleDef& iToCompare);

  char* GetRuleCode() const 
    { return (char*)&_ruleCode; }
  CATBodyChecker::CheckRuleID GetRuleID() const
    { return _ruleID; }
  CATBodyChecker::CheckMode GetRuleCheckMode() const
    { return _checkMode; }
  CATGeometricType GetTargetType() const
    { return _targetGeometryType; }

protected:
  char                           _ruleCode[BC_RULE_CODE_LENGTH];
  CATBodyChecker::CheckRuleID    _ruleID;
  CATBodyChecker::CheckMode      _checkMode;
  CATGeometricType               _targetGeometryType;

private:
  CATBodyCheckerRuleDef(char                         pruleCode[BC_RULE_CODE_LENGTH],
                        CATBodyChecker::CheckRuleID  ruleID,
                        CATBodyChecker::CheckMode    checkMode,
                        CATGeometricType             targetGeometryType);
  CATBodyCheckerRuleDef();
  CATBodyCheckerRuleDef(const CATBodyCheckerRuleDef& iToCopy);
  CATBodyCheckerRuleDef& operator = (const CATBodyCheckerRuleDef& iToCopy);
};

typedef CATBodyCheckerRuleDef CATBCRuleDef;

//=============================================================================

#endif // __CATBodyCheckerRules_h__

