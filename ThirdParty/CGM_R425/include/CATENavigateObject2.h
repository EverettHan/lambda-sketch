/* -*-c++-*- */
#ifndef CATENavigateObject2_h
#define CATENavigateObject2_h

// COPYRIGHT DASSAULT SYSTEMES 2019


#include "CATOmnMain.h"
#include "CATINavigateObject2.h"
#include "IUnknown.h"

class ExportedByCATOmnMain CATENavigateObject2 : public CATINavigateObject2
{
public:
  virtual HRESULT HasChildren(CATBoolean& oHasChildren);
};


#endif

