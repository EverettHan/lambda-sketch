#ifndef VISTEXTURED3DINTEROP_H_
#define VISTEXTURED3DINTEROP_H_

#include "D3DInterop.h"
#include "IVisTexturePtr.h"

struct ID3D11Texture2D;

class ExportedByD3DInterop VisTextureD3DInterop
{
public:
  VisTextureD3DInterop(): m_D3DTexture(NULL), m_Locked(false){};
  VisTextureD3DInterop(const IVisTexturePtr &iTexture);
  ~VisTextureD3DInterop(); 

  IVisTexturePtr& GetIVisTexture() {return m_iVisTexture;}
  ID3D11Texture2D* GetD3DTexture() {return m_D3DTexture;}
  
  HRESULT Lock();
  HRESULT Unlock();
  void SyncUpdateInterop(IVisTexturePtr &srcTexture);

  bool IsLocked(){return m_Locked;}

private:
  IVisTexturePtr m_iVisTexture;
  ID3D11Texture2D* m_D3DTexture;
  bool m_Locked;
};


#endif //VISTEXTURED3DINTEROP_H_
