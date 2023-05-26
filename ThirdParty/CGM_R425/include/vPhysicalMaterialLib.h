#ifndef _vPhysicalMaterialLib_h
#define _vPhysicalMaterialLib_h

#include "CATVisColorf.h"

namespace VPM
{
  class  ParameterFloat
  {  
  public :

    typedef enum
    {
      eUnknown = -1,      
      eRoughness,      //Roughness is deprecated, please use glossiness instead.
      eGlossiness,      
      eAnisotropy,
      eAnisotropyAngle,
      eBumpFactor,
      eTransparency,
      eOpacity,      
      eEdgeColorBias,
      eDisplacement,
      //Non texturables here :
      eFlakesWeight,
      eFlakesStrength,
      eFlakesScale,
      eFlakesBump,
      eFlakesRoughness,
      eFlakesDensity,
      ePearlFlakesBump,
      ePearlFlakesDensity,
      eCoatingGlossiness,
      eCoatingBump,
      eCoatingScale,
      eCount
    } Type;

  private :
    ParameterFloat();
    ParameterFloat(const ParameterFloat&);
    ParameterFloat& operator=(const ParameterFloat&);
    ~ParameterFloat();
  };

  class  ParameterFloat3
  {
  public :

    typedef enum
    {    
      eUnknown = -1,
      eBaseColor,
      eSpecularReflectance0,
      eEmissiveColor,
      eEdgeColor,
      //Non texturables here :
      eFlakesColor,
      ePearlFlakesColor,
	    eCoatingSpecularReflectance0,
      eCount
    } Type;

  private :
    ParameterFloat3();
    ParameterFloat3(const ParameterFloat3&);
    ParameterFloat3& operator=(const ParameterFloat3&);
    ~ParameterFloat3();
  };

  class  ParameterMap
  {
  public :

    typedef enum
    {    
      eUnknown = -1,
      eNormalMap,
      eHeightMap,
      eCoatingNormalMap,
      eOcclusionMap,
      eCount    
    } Type;  

    typedef enum
    {
      eConventionUnknown = -1,
      eConventionPositiveY,
      eConventionNegativeY,
      eConventionCount
    }
    Convention;

  private :
    ParameterMap();
    ParameterMap(const ParameterMap&);
    ParameterMap& operator=(const ParameterMap&);
    ~ParameterMap();
  };

  class  ParameterMode
  {
  public :
    typedef enum
    {        
      eUnknown = -1,
      eScalar,
      eTexture,
      eCount    
    } Type;
  };

  class MappingOperator
  {
  public :
    enum Type
    {
      eNone,
      ePlanar,
      eSpherical,
      eCubic,
      eFiniteCylindrical,
      eInfiniteCylindrical, //NOTE : Unuspported in iRay so far
      eCount
    };

  private:
    MappingOperator();
    MappingOperator(const MappingOperator&);
    MappingOperator& operator=(const MappingOperator&);
    ~MappingOperator();
  };

  class AlphaMode
  {
  public:
    enum Type
    {
      ePhysicalMaterial,
      eDiffuseChannel,
      eCount
    };

  private:
    AlphaMode();
    AlphaMode(const AlphaMode&);
    AlphaMode& operator=(const AlphaMode&);
    ~AlphaMode();
  };

class FabricsMode
  {
  public:
    enum Type
    {
      eVelvet,
      eSilkVelvet,
      eSatin,
      eCount
    };

  private:
    FabricsMode();
    FabricsMode(const FabricsMode&);
    FabricsMode& operator=(const FabricsMode&);
    ~FabricsMode();
  };

  //REM : to remove if the kernel is available in VisualizationFoundation
  class  Float3
  {
  public :
    float x;
    float y;
    float z;    
    Float3(): x(0), y(0), z(0){}
    Float3(float ix, float iy, float iz) : x(ix), y(iy), z(iz){}
    Float3(float iValue)  : x(iValue), y(iValue), z(iValue){}
        
    void SetValues(float ix, float iy, float iz)
    {
      x = ix;
      y = iy;
      z = iz;
    }
  };

  class Filtering
  {
  public :
    enum Type
    {
      eNearest,
      eLinear,
      eNone,
      eCount
    };

  private:
    Filtering();
    Filtering(const Filtering&);
    Filtering& operator=(const Filtering&);
    ~Filtering();
  };

  class Wrapping
  {
  public :
    enum Mode
    {
      eRepeat,
      eClampToEdge,
      eClampToBorder,
      eMirror,
      eMirrorOnce,
      eCount
    };

  private:
    Wrapping();
    Wrapping(const Wrapping&);
    Wrapping& operator=(const Wrapping&);
    ~Wrapping();
  };

  class TextureSampler
  {
  public:
    Filtering::Type minFilter;
    Filtering::Type magFilter;
    Filtering::Type mipFilter;

    Wrapping::Mode texCoordUWrap;
    Wrapping::Mode texCoordVWrap;

    CATVisColorf borderColor;

    TextureSampler() : minFilter(Filtering::eLinear), magFilter(Filtering::eLinear), mipFilter(Filtering::eLinear),
        texCoordUWrap(Wrapping::eRepeat), texCoordVWrap(Wrapping::eRepeat), borderColor(0.0f, 0.0f, 0.0f, 1.0f) {}

    bool operator == ( const TextureSampler& iSrc ) const
    {
      return ( minFilter == iSrc.minFilter && magFilter == iSrc.magFilter && mipFilter == iSrc.mipFilter
        && texCoordUWrap == iSrc.texCoordUWrap && texCoordVWrap == iSrc.texCoordVWrap && borderColor == iSrc.borderColor );
    }
  };
}

#endif
