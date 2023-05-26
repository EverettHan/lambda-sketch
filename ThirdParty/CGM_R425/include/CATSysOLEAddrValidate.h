//*===========================================================================*
//* COPYRIGHT DASSAULT SYSTEMES 2005                                          *
//*===========================================================================*
//*                                                                           *
//*  Usage Notes:                                                             *
//*===========================================================================*
//*  Creation mai 2005                                       adt              *
//*===========================================================================*
#ifndef CATSYSOLEADDRVALIDATE_H
#define CATSYSOLEADDRVALIDATE_H

#include "CATDataType.h"
#include "JS0COMP.h"
#include "CATWTypes.h"

//    imode =0 Ajout d'une adresse					     
//    imode =1 Suppression d'une adresse				     
//    imode =2 Recherche d'une adresse					     
    HRESULT ExportedByJS0COMP CATSysOLEAddrValidate ( IUnknown * iAddr, int iMode);

#endif
