//*===========================================================================*
//* COPYRIGHT DASSAULT SYSTEMES 1996                                          *
//*===========================================================================*
//*                                                                           *
//*  IEnumSTATSTG                                                             *
//*                                                                           *
//*  Usage Notes:                                                             *
//*===========================================================================*
//*  Creation mars 1997                                                       *
//*===========================================================================*
#ifndef __CATIENUMSTATSTG
#define __CATIENUMSTATSTG

#include "JS0COMP.h"
#include "CATWTypes.h"
#include "IUnknown.h"

class CATIEnumSTATSTG : public IUnknown
{
public:
  virtual HRESULT __stdcall Next( ULONG iCelt,
				  STATSTG FAR* rgelt,
				  ULONG FAR* opceltFetched) = 0;
        
  virtual HRESULT __stdcall Skip( ULONG icelt) = 0;
        
  virtual HRESULT __stdcall Reset( void) = 0;
        
  virtual HRESULT __stdcall Clone( CATIEnumSTATSTG FAR*FAR* ppenum) = 0;
       
};

#endif
