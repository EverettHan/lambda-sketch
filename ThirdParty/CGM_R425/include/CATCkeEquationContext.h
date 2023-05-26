
/**
 * @level Protected
 * @usage U1
 */
// COPYRIGHT DASSAULT SYSTEMES  1996
//=============================================================================
//
// CATCkeEquationContext:  temporaire mais factory d'integer etc.......
//
//=============================================================================
#ifndef CATCkeEquationContext_H
#define CATCkeEquationContext_H

// module
#include "CATLifDictionary.h"

// Include editeur
#include "CATCkeContext.h"
#include "CATICkeExpressionForwards.h"

// pour simplifier, on include
//#include "CATCkeMethodFactory.h"
#include "CATCkeDictionary.h"

// classe des exceptions
#include "CATCkeContext.h"
#include "CATICkeArg.h" 

#include "CATCkeEquationExc.h"

class CATCkeExprFactory;
class CATCkeParseError;


struct ExportedByCATLifDictionary CATCkeEquationContext : CATCkeContext
{
  static CATCkeDictionary* GetDictionary();
};


#define CATCKEDictionary            CATCkeEquationContext::GetDictionary()
#define CATCKEMethodFactory         (&(CATCkeMethodFactory::myFactory_))
#define CATCKEInternalExprFactory   CATCkeExprFactory::ExprFactory

#endif







































































