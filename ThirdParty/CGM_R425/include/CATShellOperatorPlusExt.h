#ifndef CATShellOperatorPlusExt_H
#define CATShellOperatorPlusExt_H
//---------------------------------------------------------------------
// CATShellOperatorPlusExt
// 
// Extensible de l'operateur de shell.
//
//
// COPYRIGHT DASSAULT SYSTEMES  2010
// 
// --------------------------------------------------------------------
//  Mar. 2010                       Creation                      JJ3
//---------------------------------------------------------------------

#include "CATCleverOffset.h"
#include "CATDRepExtTopOperator.h"
#include "CATString.h"

class CATContextForFastRun;
class CATShellOperatorPlusContextForFastRun;

class ExportedByCATCleverOffset CATShellOperatorPlusExt : public CATDRepExtTopOperator
{

public:
  CATShellOperatorPlusExt(CATTopOperator *iOperateur = NULL);
  ~CATShellOperatorPlusExt();

  CATCGMNewClassArrayDeclare;        // Pool allocation

  // VoB
  virtual CATBoolean IsVoBSupported();

  /** ID pour CGMReplay */
  virtual const CATString * GetOperatorId() const;
  /** ID pour CGMReplay */
  static const CATString * GetDefaultOperatorId() { return & _OperatorName; };

protected :

  // Operator generic name 
  static CATString _OperatorName;
};

#endif
