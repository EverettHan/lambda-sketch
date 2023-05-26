#ifndef _CATIPhysicalMaterial_h
#define _CATIPhysicalMaterial_h

#include "vPhysicalMaterialLib.h"
#include "CATSysErrorDef.h"
#include <stddef.h>

class CATUnicodeString;
class CATString;
class CATPixelImage;
class CAT3x3Matrix;
class CAT4x4Matrix;
class CATPhysicalMaterialHolder;

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

class CATIPhysicalMaterial
{
  friend class CATPhysicalMaterialHolder;

public:      
  
  virtual ~CATIPhysicalMaterial() {};    

  virtual HRESULT SetParameterMode(VPM::ParameterFloat::Type iParameter, VPM::ParameterMode::Type iMode) = 0;  
  virtual HRESULT SetParameterMode(VPM::ParameterFloat3::Type iParameter, VPM::ParameterMode::Type iMode) = 0;

  virtual VPM::ParameterMode::Type GetParameterMode(VPM::ParameterFloat::Type iParameter ) const = 0;
  virtual VPM::ParameterMode::Type GetParameterMode(VPM::ParameterFloat3::Type iParameter) const = 0;
  
  virtual HRESULT SetParameter(VPM::ParameterFloat::Type iParameter, const char* iTexture) = 0;
  virtual HRESULT SetParameter(VPM::ParameterFloat::Type iParameter, CATPixelImage* iTexture) = 0;
  virtual HRESULT SetParameterSampling(VPM::ParameterFloat::Type iParameter, const VPM::TextureSampler& iSampler) = 0;
  virtual HRESULT SetParameter(VPM::ParameterFloat::Type iParameter, float iValue) = 0;  
  virtual HRESULT SetParameterUvTransformation(VPM::ParameterFloat::Type iParameter, const CAT3x3Matrix& iUvTransformation) = 0;

  virtual HRESULT SetParameter(VPM::ParameterFloat3::Type iParameter, const char* iTexture) = 0;
  virtual HRESULT SetParameter(VPM::ParameterFloat3::Type iParameter, CATPixelImage* iTexture) = 0;
  virtual HRESULT SetParameterSampling(VPM::ParameterFloat3::Type iParameter, const VPM::TextureSampler& iSampler) = 0;
  virtual HRESULT SetParameter(VPM::ParameterFloat3::Type iParameter, const VPM::Float3& iValue) = 0;
  virtual HRESULT SetParameterUvTransformation(VPM::ParameterFloat3::Type iParameter, const CAT3x3Matrix& iUvTransformation) = 0;
  
  //Map Type
  virtual HRESULT SetParameter(VPM::ParameterMap::Type iParameter, const char* iTexture) = 0;
  virtual HRESULT SetParameter(VPM::ParameterMap::Type iParameter, CATPixelImage* iTexture) = 0;
  virtual HRESULT SetParameterSampling(VPM::ParameterMap::Type iParameter, const VPM::TextureSampler& iSampler) = 0;
  virtual HRESULT SetParameterUvTransformation(VPM::ParameterMap::Type iParameter, const CAT3x3Matrix& iUvTransformation) = 0;
  virtual HRESULT SetParameterEnabled(VPM::ParameterMap::Type iParameter, const bool iEnable) = 0;

  virtual HRESULT GetParameter(VPM::ParameterFloat::Type iParameter, CATString& oValue) const = 0;  
  virtual HRESULT GetParameter(VPM::ParameterFloat::Type iParameter, float& oValue) const = 0;
  virtual HRESULT GetParameterSampling(VPM::ParameterFloat::Type iParameter, VPM::TextureSampler& oSampler) const = 0;
  virtual const CATPixelImage* GetPixelImage(VPM::ParameterFloat::Type iParameter) const = 0;
  virtual CATPixelImage* GetPixelImage(VPM::ParameterFloat::Type iParameter) = 0;
  virtual HRESULT GetParameterUvTransformation(VPM::ParameterFloat::Type iParameter, CAT3x3Matrix& oUvTransformation) const = 0;

  virtual HRESULT GetParameter(VPM::ParameterFloat3::Type iParameter, CATString& oValue) const = 0;
  virtual HRESULT GetParameter(VPM::ParameterFloat3::Type iParameter, VPM::Float3& oValue) const = 0;    
  virtual HRESULT GetParameterSampling(VPM::ParameterFloat3::Type iParameter, VPM::TextureSampler& oSampler) const = 0;
  virtual const CATPixelImage* GetPixelImage(VPM::ParameterFloat3::Type iParameter) const = 0;
  virtual CATPixelImage* GetPixelImage(VPM::ParameterFloat3::Type iParameter) = 0;
  virtual HRESULT GetParameterUvTransformation(VPM::ParameterFloat3::Type iParameter, CAT3x3Matrix& oUvTransformation) const = 0;
  
  //Map Type
  virtual HRESULT GetParameter(VPM::ParameterMap::Type iParameter, CATString& oValue) const = 0;
  virtual HRESULT GetParameterSampling(VPM::ParameterMap::Type iParameter, VPM::TextureSampler& oSampler) const = 0;
  virtual const CATPixelImage* GetPixelImage(VPM::ParameterMap::Type iParameter) const = 0;
  virtual CATPixelImage* GetPixelImage(VPM::ParameterMap::Type iParameter) = 0;
  virtual HRESULT GetParameterUvTransformation(VPM::ParameterMap::Type iParameter, CAT3x3Matrix& oUvTransformation) const = 0;
  virtual HRESULT GetParameterEnabled(VPM::ParameterMap::Type iParameter, bool& iEnable) const = 0;


  virtual bool IsPixelImage(VPM::ParameterFloat::Type iParameter) const = 0;
  virtual bool IsPixelImage(VPM::ParameterFloat3::Type iParameter) const = 0;
  virtual bool IsPixelImage(VPM::ParameterMap::Type iParameter) const = 0;

  virtual HRESULT RefreshPixelImage(VPM::ParameterFloat::Type iParameter) = 0;
  virtual HRESULT RefreshPixelImage(VPM::ParameterFloat3::Type iParameter) = 0;
  virtual HRESULT RefreshPixelImage(VPM::ParameterMap::Type iParameter) = 0;

  /******************************************* MAD Modifier *******************************************/
  //M(iMCoefficient, iACoefficient, iValue) = iMCoefficient*iValue + iACoefficient 
  //Warning : Not Yet optimized when using mad modifiers on scalar mode parameter. Please update the value of the parameter instead of using MAD modifier for scalar params
  virtual HRESULT SetMadModifier(VPM::ParameterFloat::Type iParameter, float iMCoefficient = 1.0, float iACoefficient = 0.0) = 0;
  virtual HRESULT SetMadModifier(VPM::ParameterFloat3::Type iParameter, const VPM::Float3& iMCoefficient, const VPM::Float3& iACoefficient) = 0;
  //Mad modifiers not allowed on maps
  //virtual HRESULT SetMadModifier(VPM::ParameterMap::Type iParameter, const VPM::Float3& iMCoefficient, const VPM::Float3& iACoefficient) = 0;

  virtual HRESULT GetMadModifier(VPM::ParameterFloat::Type iParameter, float& iMCoefficient, float& iACoefficient) const = 0;
  virtual HRESULT GetMadModifier(VPM::ParameterFloat3::Type iParameter, VPM::Float3& iMCoefficient, VPM::Float3&  iACoefficient) const = 0;
  //Mad modifiers not allowed on maps
  //virtual HRESULT GetMadModifier(VPM::ParameterMap::Type iParameter, VPM::Float3& iMCoefficient, VPM::Float3&  iACoefficient) const = 0;

  /******************************************* ALPHA Channel Management ***********************************************/

  virtual HRESULT SetAlphaMode(VPM::AlphaMode::Type iAlphaMode) = 0;
  virtual VPM::AlphaMode::Type GetAlphaMode() const = 0;
  virtual HRESULT SetAlphaTest(bool iValue) = 0;
  virtual bool IsAlphaTestEnabled() const = 0;

  virtual float GetDiffuseAlphaMultiplier() const = 0;
  virtual void  SetDiffuseAlphaMultiplier(float iAlphaMultiplier) = 0;


  /************************************** BUMP MANAGEMENT ***************************************/
  virtual HRESULT SetNormalMapConvention(VPM::ParameterMap::Convention iConvention) = 0;
  virtual VPM::ParameterMap::Convention GetNormalMapConvention() const = 0;

  virtual HRESULT SetUseNormalMap(bool iValue) = 0; 
  virtual bool GetUseNormalMap() const = 0; 

  virtual HRESULT SetUseHeightMap(bool iValue) = 0; 
  virtual bool GetUseHeightMap() const = 0; 

  virtual HRESULT SetNormalMap(const char* iValue) = 0;
  virtual const char* GetNormalMap() const = 0;

  virtual HRESULT SetHeightMap(const char* iValue) = 0;
  virtual const char* GetHeightMap() const = 0;

  /************************************** Coating MANAGEMENT ***************************************/
  virtual void SetCoating(bool iEnabled) = 0;
  virtual bool GetCoating() const = 0;
  virtual void SetProceduralCoating(bool iEnabled) = 0;
  virtual bool GetProceduralCoating() const = 0;

  /************************************** Fabrics MANAGEMENT ***************************************/
  virtual void SetFabrics(bool iEnabled) = 0;
  virtual bool GetFabrics() const = 0;

  virtual HRESULT SetFabricsMode(VPM::FabricsMode::Type iFabricsMode) = 0;
  virtual VPM::FabricsMode::Type GetFabricsMode() const = 0;

  /************************************** Flakes MANAGEMENT ***************************************/
  virtual void SetFlakes(bool iEnabled) = 0;
  virtual bool GetFlakes() const = 0;
  
  virtual const char* GetFlakesMap() const = 0;

  /*********************** Sampling for normal and flakes maps MANAGEMENT ***********************/
  virtual HRESULT SetMapsSampling(const VPM::TextureSampler& iSampler) = 0;
  virtual const VPM::TextureSampler& GetMapsSampling() const = 0;

  /************************************** MAPPING OPS ******************************************/  
  virtual HRESULT SetMappingOperator(VPM::MappingOperator::Type iType) = 0;
  virtual VPM::MappingOperator::Type GetMappingOperator() const = 0;

  virtual HRESULT SetObjectTransformation(const CAT4x4Matrix& iObjectTransformation) = 0;
  virtual HRESULT SetUvTransformation(const CAT3x3Matrix& iObjectTransformation) = 0;

  virtual HRESULT GetObjectTransformation(CAT4x4Matrix& oObjectTransformation) const = 0;
  virtual HRESULT GetUvTransformation(CAT3x3Matrix& oObjectTransformation) const = 0;

  virtual HRESULT SetRepeatU(bool iUvRepeat) = 0;
  virtual bool    GetRepeatU() const = 0;

  virtual HRESULT SetRepeatV(bool iUvRepeat) = 0;
  virtual bool    GetRepeatV() const = 0;

  virtual CATIPhysicalMaterial* Copy(CATPhysicalMaterialHolder* iPhyMatHolder = NULL) = 0;

  typedef enum  //I can not avoid downcast at some point so this stands for safe cast
  {
    eNone = -1,
    evPhysicalMaterial,
    eTypeCount
  } Type;  

  //I can not avoid downcast at some point so this stands for safe cast
  virtual Type GetType() const = 0;

  //useful for stream\unstream
  //I dont want to steram enum as it might lead to hard-to-detect bugs
  virtual const char* GetName(VPM::ParameterFloat::Type iType) const = 0;
  virtual const char* GetName(VPM::ParameterFloat3::Type iType) const = 0;
  virtual const char* GetName(VPM::ParameterMap::Type iType) const = 0;

  virtual VPM::ParameterFloat::Type GetFloatType(const char* iName) const = 0;
  virtual VPM::ParameterFloat3::Type GetFloat3Type(const char* iName) const = 0;
  virtual VPM::ParameterMap::Type GetMapType(const char* iName) const = 0;

protected :

  virtual HRESULT LoadConfiguration(const char* iConfig, float& oVersion) = 0;
  virtual HRESULT LoadConfigurationFromBuffer(const char* iConfig, float& oVersion) = 0;
  virtual HRESULT Serialize(CATUnicodeString& oSerialization) const = 0;  

  CATIPhysicalMaterial() {};
 
};

#endif
