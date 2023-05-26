#ifndef CATCGMDumpTest_h_
#define CATCGMDumpTest_h_

//#define CNEXT_CLIENT
#define CGM_DUMPTEST

//#ifdef CNEXT_CLIENT
#ifdef CGM_DUMPTEST

#include "ExportedByCATMathStream.h"

// Prototype de la fonction.
//  - iNew est le r�sultat du test en cours.
//  - iPrevious est le r�sultat du test remplac� par iNew.
//  - iValue est un double caract�ristique (disponible localement) qui permet d'identifier le test.
ExportedByCATMathStream void _CATCGM_DumpTest_(const CATLONG32 iPrevious, const CATLONG32 iNew, const double iValue);

// Definition de la Macro (simple appel � la fonction).
#define CATCGMDUMPTEST(previousTest, newTest, value) _CATCGM_DumpTest_(previousTest, newTest, value);

#else // Macro non activ�e.
#define CATCGMDUMPTEST(previousTest, newTest, value)
#endif

#endif
