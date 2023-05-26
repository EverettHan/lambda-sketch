#ifndef CATPhysicalMaterialHolder_H
#define CATPhysicalMaterialHolder_H

#include "CATGraphicMaterial.h"

class CATIPhysicalMaterial;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                       ATTENTION: DO NOT USE THIS INTERFACE ANYMORE.                       * 
 *                      ----------------------------------------------                       *    
 * This interface will be depricated and all users will be asked to migrate.                 *
 * New API to use: VisMaterial with model type "SpecularGlossiness"                          *
 * SpecularGlossiness model is defined with parameters exactly same as CATIPhysicalMaterial  *
 * For detailed information, please consult,                                                 *
 *           http://wikitechno/wiki/index.php/New_material_API_and_related_services          *
 * Sample code can be found here, (beter viewed in DSXplore)                                 *
 *           SGInfra\SGInfra.m\Doc\VisMaterialAPICodeSamples.md                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

class ExportedBySGInfra CATPhysicalMaterialHolder : public CATGraphicMaterial
{    
  CATDeclareClass;

public:      


  //do not forget to do AddReference after that call (weird CATGraphicMaterial lifecycle)
  //iConfig is the path (full or relative to your js config 
  static CATPhysicalMaterialHolder* CreateInstance(const char* iConfig = NULL);  
  static CATPhysicalMaterialHolder* CreateInstanceFromBuffer(const char* iConfig = NULL);  
  
  CATPhysicalMaterialHolder();  

  HRESULT SetConfigurationFromFile(const char* iConfig);
  HRESULT SetConfigurationFromBuffer(const char* iBuffer);
  
  HRESULT Save(const char* oFile) const;
  
  CATPhysicalMaterialHolder(const CATPhysicalMaterialHolder & material);

#if defined(REMOVE_USELESS_INCLUDE) 
#pragma message ("BADREM : FDT1 2022/06/30 "  __FILE__  " CATPhysicalMaterialHolder::~CATPhysicalMaterialHolder is a forbidden method, please use Release method instead. ")
protected:
#endif
  virtual ~CATPhysicalMaterialHolder();

public:
  virtual CATGraphicMaterial* Clone() const;

  inline virtual CATGraphicMaterialType GetMatType() const;

  inline CATIPhysicalMaterial* GetMaterial();
  inline const CATIPhysicalMaterial* GetMaterial() const;
  
  virtual void Stream(CATStreamer& oStream,int iSaveType = 0);  
  virtual void UnStream(CATStreamer& iStream);

  virtual void SendMaterialNotification(CATMaterialNotificationType iType);

  virtual bool IsAlphaTestEnabled() const;


private :    

  CATIPhysicalMaterial* m_PhysicalMaterial;

  void _StreamTexture(CATStreamer& oStream, const char* iPath);
  void _StreamTexture(CATStreamer& oStream, CATPixelImage* iPixImg);
  void _UnstreamTexture(CATStreamer& iStream, CATPixelImage*& oPixImg);

  void _AdaptGraphicMaterial(CATIPhysicalMaterial* iPhysicalMAterial, CATStreamer& oStream); // XK7 

  //Overriding these methods will break the engine behavior
  virtual float GetCoefficient(const CATCoefficientType iParam) const;
  virtual void SetCoefficient(const CATCoefficientType iParam,float iValue);

  enum CATMaterialPropertyType
  {
    Diffuse,
    Specular,
    Blend,
    Transparency,
    ReflectivityType,
    Glossiness,
    TextureConfig,
    End
	};

  // [EOO2] obsolete code?
  //void LoadConfiguration(const char* iConfig, float& oVersion);

  HRESULT GetParameterFromConfig(const char* iConfig, const char* iToken, float& oR ,float& oG, float& oB);
  HRESULT GetParameterFromConfig(const char* iConfig, const char* iToken, float& oCATGraphiMaterialProperty);
  HRESULT GetParameterFromConfig(const char* iConfig, const char* iToken, CATTextureFilter& oMinf, CATTextureFilter& oMagf, CATTextureWrapping& oWrapS, CATTextureWrapping& oWrapT);

};


inline CATIPhysicalMaterial* CATPhysicalMaterialHolder::GetMaterial()
{
  return m_PhysicalMaterial;
}

inline const CATIPhysicalMaterial* CATPhysicalMaterialHolder::GetMaterial() const
{
    return m_PhysicalMaterial; 
}

inline CATGraphicMaterialType CATPhysicalMaterialHolder::GetMatType() const
{
  return REPhysicalMaterial;
}

#endif // CATPhysicalMaterialHolder_H
