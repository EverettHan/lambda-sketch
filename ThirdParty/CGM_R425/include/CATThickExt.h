#ifndef CATThickExt_H
#define CATThickExt_H
//---------------------------------------------------------------------
// CATThickExt
// 
// Extensible de l'operateur de CATThick.
//
//
// COPYRIGHT DASSAULT SYSTEMES  2010
// 
//---------------------------------------------------------------------


#include "Thick.h"
#include "CATDRepExtTopOperator.h"
#include "CATBody.h"

class CATContextForFastRun;
class CATThickContextForFastRun;
class CATThick;

class ExportedByThick CATThickExt : public CATDRepExtTopOperator
{

public:
  CATThickExt();
  ~CATThickExt();

  CATCGMNewClassArrayDeclare;        // Pool allocation

  // Methodes contexte Fast Run
  CATContextForFastRun* GetContextForFastRun();
  CATThickContextForFastRun* GetThickContextForFastRun();
  CATContextForFastRun* GetOrCreateContextForFastRun();
  CATThickContextForFastRun* GetOrCreateThickContextForFastRun();

private:
  
};


#endif
