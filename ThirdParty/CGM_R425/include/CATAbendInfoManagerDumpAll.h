#ifndef CATAbendInfoManagerDumpAll_H
#define CATAbendInfoManagerDumpAll_H
// COPYRIGHT DASSAULT SYSTEMES 2000
// ==============================================================
// == Method                                                   ==
// ==============================================================
// == This method allows to dump the current values stored     ==
// == in AbendInfo's                                           ==
// ==============================================================
// ==  RESERVED FOR SPECIFIC USAGES  IN SPECIFIC FRAMEWORKS    ==
// ==  ------------------------------------------------------  ==
// ==============================================================
// == Restrictions
// == DO NOT USE IN SECONDARY THREAD (as most JS0GROUP class   ==
// ==                                 or methods)              ==
// == THIS METHOD IS NOT REENTRANT. AVOID TO USE IN SIG HANDLERS=
// ==============================================================
#include "CATAbendInfo.h"
ExportedByJS0ERROR void CATAbendInfoManagerDumpAll(FILE *fic,short int iReserved=0);

#endif
