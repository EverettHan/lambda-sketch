#ifndef VISTEXTUREFACTORYD3DINTEROP_H_
#define VISTEXTUREFACTORYD3DINTEROP_H_

#include "D3DInterop.h"
#include "IVisTexture.h"
#ifdef _WINDOWS_SOURCE
#include <wrl.h>
#endif

class VisTextureFactoryImpl;
class VisTextureD3DInterop;

#ifdef _WINDOWS_SOURCE
struct ID3D11Device;
struct ID3D11DeviceContext;
struct IDXGIFactory;
#endif

class ExportedByD3DInterop VisTextureFactoryD3DInterop
{
public :

  using DeviceID = uint32_t;

  static VisTextureD3DInterop* CreateD3DTextureInterop(const IVisTextureFormat::Type iFormat, unsigned int iWidth, unsigned int iHeight, unsigned int iMipMapAlloc, DeviceID iDevice = 0);
 #ifdef _WINDOWS_SOURCE 
  static DeviceID RegisterDevice(const Microsoft::WRL::ComPtr<ID3D11Device> &iDevice, const Microsoft::WRL::ComPtr<ID3D11DeviceContext> &iDeviceContext, const Microsoft::WRL::ComPtr<IDXGIFactory> &iFactory);
 #endif
private :

  static void _Init();

  static VisTextureFactoryImpl * s_impl;

};


#endif //VISTEXTUREFACTORYD3DINTEROP_H_
