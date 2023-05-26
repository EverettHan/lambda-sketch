// COPYRIGHT DASSAULT SYSTEMES 2015
//=============================================================================
//
// CATCDSExpressionTerm:
//   Common expression parser
//
//=============================================================================
//  Feb 2015  Creation                         TE9
//=============================================================================

#ifndef CATCDSExpressionTerm_h
#define CATCDSExpressionTerm_h

#include "CATCDSDebug.h"

#ifdef CDS_DEBUG

#include "CATCDSUtilities.h"

#include "CATCDSBoolean.h"
#include "CATCDSString.h"

class CATCDSStream;

enum CATCDSExpressionType {
  ttNone, ttNumber, ttName,
  ttError, ttEnd,
  ttPlus = '+', ttMinus = '-', ttMul = '*', ttDiv = '/', ttPower = '^',
  ttComma = ',',
  ttLP = '(', ttRP = ')',
  ttInterval = '[', ttRB = ']'
};

struct CATCDSExpressionNode {
  CATCDSExpressionType _type;
  const char * _name;
  double _value;
};

class ExportedByCATCDSUtilities CATCDSExpressionTerm {
public:
  static CATCDSExpressionTerm * Create();
  static CATCDSExpressionTerm * Create(CATCDSExpressionType iType);
  static CATCDSExpressionTerm * Create(const double iValue);
  static CATCDSExpressionTerm * Create(const CATCDSString & iName);
  static void Destroy(CATCDSExpressionTerm *& ipTerm);

  CATCDSExpressionTerm();
  CATCDSExpressionTerm(CATCDSExpressionType iType);
  CATCDSExpressionTerm(const double iValue);
  CATCDSExpressionTerm(const CATCDSString & iName);
  ~CATCDSExpressionTerm();

  int GetPriority(CATCDSBoolean iFirstArg) const;
  static CATCDSBoolean IsNeedParenthesis(const CATCDSExpressionTerm * ipTerm1,
                                         const CATCDSExpressionTerm * ipTerm2,
                                         CATCDSBoolean iFirstArg,
                                         CATCDSBoolean iAllBraces = FALSE);
  void ReduceWithLeft();
  void ReduceWithRight();
  void SimplifyFullConstant();
  void SimplifyHalfConstant();

  CATCDSBoolean CheckTerm(const CATCDSExpressionNode iaNodes[], int & iPos) const;

  void Print(CATCDSStream & os, CATCDSBoolean iAllBraces = FALSE) const;
  void Dump(CATCDSStream & os, int iIndent) const;

  CATCDSExpressionType _type;
  CATCDSExpressionTerm * _pTerm1;
  CATCDSExpressionTerm * _pTerm2;
  CATCDSString _name;
  double _value;
};

#endif
#endif

