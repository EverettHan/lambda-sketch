//*===========================================================================*
//* COPYRIGHT DASSAULT SYSTEMES 2003                                          *
//*===========================================================================*
//*                                                                           *
//*  Advanced Function for STDLib                                             *
//*                                                                           *
//*  Usage Notes:                                                             *
//*===========================================================================*
//*  Creation october 2003                                   adt              *
//*===========================================================================*
#ifndef CATLIB64_H
#define CATLIB64_H
#include "CATLibEx.h"
#include "CATDataType.h"
#include "CATTSLib.h"



HRESULT ExportedByJS0STDLIB CATFileStat64 ( CATUnicodeString *iPath, 
					    CATFileInfo64 *oStat,
					    int iFlag=0);
                        
inline HRESULT CATFileStat64(const CATUnicodeString & iPath, CATFileInfo64 *oStat, int iFlag = 0)
{
    CATUnicodeString l_szPath = iPath;
    return CATFileStat64(&l_szPath, oStat, iFlag);
}

#endif
