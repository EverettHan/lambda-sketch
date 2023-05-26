#ifndef CATElfOpenBase_H
#define CATElfOpenBase_H

#include "CATELFMathKernel.h"

extern "C" ExportedByCATELFMathKernel
 void eyflsh ();

extern "C" ExportedByCATELFMathKernel
 void ehalmxc (int* iplace);

extern "C" ExportedByCATELFMathKernel
 void ehumem (int* size);

extern "C" ExportedByCATELFMathKernel
 void ehucpu (int &Nbcpu);

#ifdef _ELF_WINDOWS
#define Long64 __int64
#else
#define Long64 long long
#endif

#endif
