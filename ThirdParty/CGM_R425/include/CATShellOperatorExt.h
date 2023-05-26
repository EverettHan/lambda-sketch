#ifndef CATShellOperatorExt_H
#define CATShellOperatorExt_H
//---------------------------------------------------------------------
// CATShellOperatorExt
// 
// Extensible de l'operateur de shell.
//
//
// COPYRIGHT DASSAULT SYSTEMES  2010
// 
// --------------------------------------------------------------------
//  Mar. 2010                       Creation                      JJ3
//---------------------------------------------------------------------

#include "Thick.h"
#include "CATDRepExtTopOperator.h"

class CATContextForFastRun;
class CATShellOperatorContextForFastRun;

class ExportedByThick CATShellOperatorExt : public CATDRepExtTopOperator
{

public:
  CATShellOperatorExt(CATTopOperator *iOperateur = NULL);
  ~CATShellOperatorExt();

  CATCGMNewClassArrayDeclare;        // Pool allocation

  // VoB
  virtual CATBoolean IsVoBSupported();

};

#endif
