#ifndef IVISTEXTUREFORMAT_H_
#define IVISTEXTUREFORMAT_H_

struct IVisTextureFormat
{
  enum Type
  {
    eUnknownFormat = -1,
    eA8_UNORM,
    eR8_UNORM,
    eR8G8_UNORM, // deprecated naming
    eL8A8_UNORM = eR8G8_UNORM, // alias correct-name
    eR8G8B8_UNORM,
    eR8G8B8A8_UNORM,
    eR8G8B8A8_UINT,
    eB8G8R8_UNORM,
    eB8G8R8A8_UNORM,
    eR8G8B8A8_UNORM_SRGB,
    eDXT1,
    eDXT3,
    eDXT5,
    eR16_FLOAT,
    eR16G16B16A16_FLOAT,
    eR16G16B16A16_UNORM,
    eR16G16B16A16_SNORM,
    eR16G16B16A16_INT,
    eR16G16B16A16_UINT,

    eR32_FLOAT,
    eR32G32B32_FLOAT,
    eR32G32B32A32_FLOAT,
    eR32G32B32A32_INT,
    eR32G32B32A32_UINT,
    eR10G10B10A2_UNORM,
    eR10G10B10_A2_UINT,
    eBC4_UNORM,
    eBC5_UNORM,
    eBC6H_UFLOAT, 
    eBC7_UNORM,
    eBC7_UNORM_SRGB,

    //Depth/Stencil format
    eD32_FLOAT_S8X24_UINT,
    eD32_FLOAT,
    eD24_UNORM_S8_UINT,
    eD24_UNORM,
    eD16_UNORM,
    
    eUndefined,
    eNbFormat
  };
};

#endif //IVISTEXTUREFORMAT_H_
