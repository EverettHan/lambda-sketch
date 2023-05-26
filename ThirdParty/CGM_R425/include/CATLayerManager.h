//==========================================================================================
// COPYRIGHT DASSAULT SYSTEMES 2015
//==========================================================================================
//
//==========================================================================================
// JUN 15 Creation                                    NHD
//==========================================================================================

#ifndef CATLayerManager_H
#define CATLayerManager_H


#include "CATVisItf.h"
#include <IUnknown.h>


class ExportedByCATVisItf CATLayerManager
{
public:
  static CATLayerManager* Get();
  virtual ~CATLayerManager() {};

  virtual HRESULT SetLayer(const unsigned int layer,int iComputeVisu) = 0;
  virtual HRESULT GetLayer() = 0;

public:

  static void Register(CATLayerManager* iObjToRegister);


public:
static CATLayerManager* _pObj;

};



#endif
