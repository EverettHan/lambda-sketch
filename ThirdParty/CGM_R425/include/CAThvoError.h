#ifndef CAThvoError_H
#define CAThvoError_H

#include "CATTopOpInError.h"
#include "CATCGMOutput.h"
#include "CATBasicTopologicalOpe.h"

ExportedByCATBasicTopologicalOpe CATTopOpInError * CAThvoCreateInvalidInternalDataError(const char * iFileName, int iLine);

ExportedByCATBasicTopologicalOpe CATTopOpInError * CAThvoCreateInvalidInputDataError(const char * iFileName, int iLine);

// --------------------------------------------------------------------------------------------------------
// le #define suivant permet, pour l'environnement de l'HybridVariableOffset, de lancer une exception
// --------------------------------------------------------------------------------------------------------

// You have to write : 
//     CAThvoInputError;
// DO NO FORGET THE ; AFTER THIS MACRO
#define CAThvoInputError \
  CATThrow(CAThvoCreateInvalidInternalDataError(__FILE__,__LINE__))
  //  { cgmout << "HybridVariableOffset Error -- Invalid input data" << cgmendl; \
  //  CATTopOpInError * Error = new CATTopOpInError( TopOpInInvalidOperator,"TopOpInInvalidOperator", TopOpInFile ); \
  //  CATThrow(Error); }

// --------------------------------------------------------------------------------------------------------
// le #define suivant permet, pour l'environnement de l'HybridVariableOffset, de lancer une exception
// --------------------------------------------------------------------------------------------------------

// You have to write : 
//     CAThvoInternalError;
// DO NO FORGET THE ; AFTER THIS MACRO
#define CAThvoInternalError \
  CATThrow(CAThvoCreateInvalidInternalDataError(__FILE__,__LINE__))
   // { cgmout << "HybridVariableOffset Error -- Invalid internal data" << cgmendl; \
   // CATTopOpInError * Error = new CATTopOpInError("TopOpInAllTopo_ERR_7505", TopOpInFile ); \
   // CATThrow(Error); }

// --------------------------------------------------------------------------------------------------------
// le #define suivant permet, pour l'environnement de l'HybridVariableOffset, de lancer une exception
// si un pointeur ou un entier est nul
// CAThvoAssert(ptvalue);
// remplace
// if (!tptvalue) CATThrowForNullPointer();
//
// Astuce de code
// le test de ptvalue s'ecrit if (! (ptvalue))
// Ainsi on peut accepter le test de plusieurs variables.
//  CAThvoAssert(ptvalue1 && ptvalue2 && ... && ptvalueN);
// --------------------------------------------------------------------------------------------------------

ExportedByCATBasicTopologicalOpe void CATThrowForNullPointerThvo( const char * iFileName, int iLine );

#define CAThvoAssert(ptvalue) \
{ \
  if ( !(ptvalue) )                                        \
    CATThrowForNullPointerThvo(__FILE__,__LINE__); \
}
   // { if (! (ptvalue)) { \
   // cgmout << "HybridVariableOffset Error -- Invalid internal data" << cgmendl; \
   // CATTopOpInError * Error = new CATTopOpInError("TopOpInAllTopo_ERR_7505", TopOpInFile ); \
   // CATThrow(Error); } }

#endif
