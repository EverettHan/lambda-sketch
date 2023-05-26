#ifndef CATThickPlusExt_H
#define CATThickPlusExt_H
//---------------------------------------------------------------------
// CATThickPlusExt
// 
// Extensible de l'operateur de shell.
//
//
// COPYRIGHT DASSAULT SYSTEMES  2010
// 
// --------------------------------------------------------------------
//  Mar. 2010                       Creation                      JJ3
//  Aug. 2019                       PH delegation management      DPS
//---------------------------------------------------------------------

#include "CATCleverOffset.h"
#include "CATDRepExtTopOperator.h"
#include "CATString.h"
#include "CATIACGMLevel.h" // CATIAR422 ...

class CATContextForFastRun;
class CATThickPlusContextForFastRun;
class CATThick;

class ExportedByCATCleverOffset CATThickPlusExt : public CATDRepExtTopOperator
{

public:
  CATThickPlusExt(CATTopOperator *iOperateur = NULL);
  ~CATThickPlusExt();

  CATCGMNewClassArrayDeclare;        // Pool allocation

  CATContextForFastRun* GetContextForFastRun();
  CATThickPlusContextForFastRun* GetThickPlusContextForFastRun();
  CATContextForFastRun* GetOrCreateContextForFastRun();
  CATThickPlusContextForFastRun* GetOrCreateThickPlusContextForFastRun();
  
  //CATBody * GetOldInput();
  
  /** ID pour CGMReplay */
  virtual const CATString * GetOperatorId() const;
  /** ID pour CGMReplay */
  static const CATString * GetDefaultOperatorId() { return & _OperatorName; };


#ifdef CATIAR422
protected:
  //============================
  // Poly/Exact Config Management 
  //============================
  // virtual overrides
  virtual CATBoolean Is_PolyInputs_Allowed();
  virtual CATBoolean Is_MixedPolyExactInputs_Allowed();

  virtual int RunPolyOperator();
#endif


protected :

  // Operator generic name 
  static CATString _OperatorName;

  // UF9 : Redondant avec la declaration dans la classe mere
  // CATContextForFastRun* _Ctx;
};
#endif
