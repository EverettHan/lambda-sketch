//==========================================================================================
// COPYRIGHT DASSAULT SYSTEMES 2015
//==========================================================================================
//
//==========================================================================================
// JUN 15 Creation                                    NHD
//==========================================================================================

#ifndef CATLayerManagerV6Impl_H
#define CATLayerManagerV6Impl_H


#include "CATLayerManager.h"


class CATLayerManagerV6Impl
  :public CATLayerManager
{
public:
  CATLayerManagerV6Impl();
  virtual ~CATLayerManagerV6Impl();

  virtual HRESULT SetLayer(const unsigned int layer,int iComputeVisu);
  virtual HRESULT GetLayer();

};


#endif
