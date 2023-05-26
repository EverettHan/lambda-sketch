/* -*-c++-*- */
//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2020
//------------------------------------------------------------------------------
//
// Creation for LocalStorage description access
// 
//------------------------------------------------------------------------------
// 10/01/2020 Creation                                                       VCS
//------------------------------------------------------------------------------

#ifndef __CATOmbLocalStorageDescription_H
#define __CATOmbLocalStorageDescription_H

// ObjectModelerBase
#include "CATOmbSelectiveLoading.h"

// ObjectModelerCollection
#include "CATOmxKeyString.h"

struct CATOmbLocalStorageDescriptionKeys
{
  CATOmbLocalStorageDescriptionKeys();
  ~CATOmbLocalStorageDescriptionKeys();

  const CATOmxKeyString LocalPath;
  const CATOmxKeyString OwnerId;
  const CATOmxKeyString IsOwner;
};
ExportedByCATOmbSelectiveLoading const CATOmbLocalStorageDescriptionKeys& LSKey();

#endif
