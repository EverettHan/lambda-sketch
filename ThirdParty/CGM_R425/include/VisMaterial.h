//===================================================================
// COPYRIGHT Dassault Systemes 2017-02-08
//===================================================================
// VisMaterial.cpp
// Header definition of class VisMaterial
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2017-02-08 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef VisMaterial_H
#define VisMaterial_H

#include "SGInfra.h"
#include "VisMaterialTextureSampler.h"
#include "VisMaterialEnum.h"
#include "CATVizBaseIUnknown.h"
#include "CAT3x3Matrix.h"
#include <unordered_map>
#include <vector>
#include "CATPixelImage.h"
#include "VisMaterialNotification.h"
#include "IVisTexturePtr.h"
#include "VisMaterialParameter.h"
#include "CATMathVectorf.h"

class VisMaterialModel;
class IVisTexture;
class CATCallbackManager;
class CATGraphicMaterial;
class VisMaterialHolder;
class CATVrml2Options;
class VisMaterialPrivateFactory;
class VisMaterialFactory;
class VisJSONValue;

//==============================================================================
// Inheritance
// -----------
// VisMaterial
//    CATVizBaseIUnknown
//
//==============================================================================
// Abstract
// --------
//  This class represents a material instance. It adhers to a material model and
//  contains values for all the parameters of the model.
//
//==============================================================================
// Usage
// -----
// Creation: Use VisMaterialFactory
//    VisMaterialFactory factory;
//    const VisMaterialModel* pModel = factory.GetSpecularGlossinessModel();
//    VisMaterial* pVisMat = factory.CreateMaterial(pModel);
//
// Change parameter values:
//    pVisMat->SetParameterValue1f(pVisMat->GetParameterIndex("transparency"), 0.5f);
//
// Get parameter values:
//    float valf(0.f);
//    pVisMat->GetParameterValue1f(pVisMat->GetParameterIndex("transparency"), valf);
//
//==============================================================================
// Further reading
// ---------------
// SGInfra / SGInfra.m / Doc /
//    / VisMaterialAPICodeSamples.md: code samples
//    / VisMaterialModelParameterInfo.md: Parameter list for all models
// @see VisMaterialFactory, CATMaterialApplicationOperations
//
//==============================================================================

class ExportedBySGInfra VisMaterial : public CATVizBaseIUnknown
{
  friend VisMaterialPrivateFactory;
  friend VisMaterialFactory;
  friend VisMaterialHolder;
  friend CATVrml2Options; // for ConvertToLegacyMaterial
  friend class CATCacheOfDestroyedElements;

protected:

  // Standard constructors and destructors
  // -------------------------------------
  virtual ~VisMaterial ();

public:

  /**
  * Lifecycle management. Release when material is no more needed.
  */
  virtual ULONG __stdcall AddRef();
  virtual ULONG __stdcall Release();

  /**
  * Return material model object
  */
  const VisMaterialModel* GetMaterialModel() const;

  /**
  * Get callback manager which send notifications
  */
  inline CATCallbackManager *GetCallbackManager() const;

  /**
  * @return number of parameters defined for this material model
  */
  int GetNumberOfParameters() const;

  /**
  * Return name of parameter when provided with index.
  * Valid range of iIndex is [0, GetNbParams()-1].
  * In case of invalid index this function returns "Invalid" name
  */
  const CATUnicodeString& GetParameterName(int iIndex) const;

  /**
  * Function to get parameter index from parameter name.
  * @return: -1 if parameter name is invalid
  */
  int GetParameterIndex(const CATUnicodeString& iParameterName) const;

  /**
  * Function to get or set the active technique
  * @returns
  *   E_INVALIDARG: if the technique does not exist
  */
  HRESULT SetActiveTechnique(const CATUnicodeString& iTechnique);
  HRESULT GetActiveTechnique(CATUnicodeString& oTechnique) const;

  /**
  * Functions to get or set float paramter values
  * @returns
  *   E_INVALIDARG: if either if the below conditions is valide,
  *     iIndex is invalid i.e. either < 0 or there is no parameter corresponding to this index
  *     Parameter size is not matching with function call or iNbElem
  *     Parameter type is not 'VisMaterialParameter::eFloat' or 'VisMaterialParameter::eFloatParam'
  */
  HRESULT SetParameterValue1f(const int iIndex, const float iVal);
  HRESULT GetParameterValue1f(const int iIndex, float &oVal) const;

  HRESULT SetParameterValue2f(const int iIndex, const float iVal1, const float iVal2);
  HRESULT GetParameterValue2f(const int iIndex, float &oVal1, float &oVal2) const;

  HRESULT SetParameterValue3f(const int iIndex, const float iVal1, const float iVal2, const float iVal3);
  HRESULT GetParameterValue3f(const int iIndex, float &oVal1, float &oVal2, float &oVal3) const;

  HRESULT SetParameterValue4f(const int iIndex, const float iVal1, const float iVal2, const float iVal3, const float iVal4);
  HRESULT GetParameterValue4f(const int iIndex, float &oVal1, float &oVal2, float &oVal3, float &oVal4) const;

  HRESULT SetParameterValuesf(const int iIndex, const float* iVal, int iNbElem);
  HRESULT GetParameterValuesf(const int iIndex, float* oVal, int oValAllocationSz) const; // client needs to allocate oVal with GetNumberOfElements() size

  /**
  * Functions to get or set int paramter values
  * @returns
  *   E_INVALIDARG: if either if the below conditions is valide,
  *     iIndex is invalid i.e. either < 0 or there is no parameter corresponding to this index
  *     Parameter size is not matching with function call or iNbElem
  *     Parameter type is not 'VisMaterialParameter::eInt'
  */
  HRESULT SetParameterValue1i(const int iIndex, const int iVal);
  HRESULT GetParameterValue1i(const int iIndex, int &oVal) const;

  HRESULT SetParameterValuesi(const int iIndex, const int* iVal, int iNbElem);
  HRESULT GetParameterValuesi(const int iIndex, int* oVal, int iNbElem) const; // client needs to allocate oVal with GetNumberOfElements() size

  /**
  * Functions to set or get texture for a paramter
  * Note: This texture can be of certain formats only (uncompressed or BC1, BC2, BC3).
  *       These formats are streamed in CGR and are supported by all render engines (like Web etc)
  *       Texture of any other format will be set as performance texture (if there is no performance texture already set)
  * @returns
  *   E_INVALIDARG: if either if the below conditions is valide,
  *     - iIndex is invalid i.e. either < 0 or there is no parameter corresponding to this index
  *     - Parameter is not texturable (it is not of the type 'VisMaterialParameter::eFloatParam' or 'VisMaterialParameter::eTexture'
  *   S_FALSE: either of the cases
  *     - ipTex is same as existing texture (nothing is done) OR
  *     - texture is set as performance texture
  */
  HRESULT SetParameterTexture(const int iIndex, const IVisTexturePtr &ipTex);
  HRESULT GetParameterTexture(const int iIndex, IVisTexturePtr &opTex) const;

  /**
  * Functions to set or get performance texture for given parameter
  * Note: This texture can be of any format.
  *       This texture will be used with same sampler as the main texture.
  *       Performance texture is used by native render engine. It is "as is" streamed in CGR.
  *       Use this texture to improve rendering performance on native render engine (or saving space by providing compressed texture)
  * @returns
  *   E_INVALIDARG: if either if the below conditions is valide,
  *     - iIndex is invalid i.e. either < 0 or there is no parameter corresponding to this index
  *     - Parameter is not texturable (it is not of the type 'VisMaterialParameter::eFloatParam' or 'VisMaterialParameter::eTexture'
  *   S_FALSE: ipTex is same as existing texture (nothing is done)
  */
  HRESULT SetParameterPerformanceTexture(const int iIndex, const IVisTexturePtr &ipTex);
  HRESULT GetParameterPerformanceTexture(const int iIndex, IVisTexturePtr &opTex) const;

  /**
  * Functions to set or get texture sampler values
  * @returns
  *   E_INVALIDARG: if either if the below conditions is valide,
  *     iIndex is invalid i.e. either < 0 or there is no parameter corresponding to this index
  *     Parameter is not texturable (it is not of the type 'VisMaterialParameter::eFloatParam' or 'VisMaterialParameter::eTexture'
  *   S_FALSE: iSampler is same as existing sampler
  */
  HRESULT SetParameterSampler(const int iIndex, const VisMaterialTextureSampler &iSampler);
  HRESULT GetParameterSampler(const int iIndex,       VisMaterialTextureSampler &oSampler) const;

  /**
  * Function to query if multiplication and addition coefficents are supported by given parameter
  * @returns
  *   S_OK: if the parameter was successfully queried and oMADSupported is useable
  *   E_INVALIDARG: if either of the below conditions is valid,
  *     iIndex is invalid i.e. either < 0 or there is no parameter corresponding to this index
  */
  HRESULT IsMADSupported(const int iIndex, bool& oMADSupported) const;

  /**
  * Function to query if the given parameter is texturable
  * @returns
  *   S_OK: if the parameter was successfully queried and oTexturable is useable
  *   E_INVALIDARG: if either of the below conditions is valid,
  *     iIndex is invalid i.e. either < 0 or there is no parameter corresponding to this index
  */
  HRESULT IsParameterTexturable(const int iIndex, bool& oTexturable) const;

  /**
  * Function to set multiplication and addition coefficents for given parameter
  * @returns
  *   E_FAIL: if MAD is not supported by given parameter
  *   E_INVALIDARG: if either if the below conditions is valide,
  *     iIndex is invalid i.e. either < 0 or there is no parameter corresponding to this index
  *   S_FALSE: if iMCoefficient and iACoefficient values are same as existing MAD coefficients
  */
  HRESULT SetParameterMADModifier1f(const int iIndex, float iMCoefficient = 1.0, float iACoefficient = 0.0);
  HRESULT SetParameterMADModifier3f(const int iIndex, const CATMathVectorf& iMCoefficient = 1.0, const CATMathVectorf& iACoefficient = 0.0);

  /**
  * Function to get multiplication and addition coefficents for given parameter
  * @returns
  *   E_FAIL: if MAD is not supported by given parameter
  *   E_INVALIDARG: if either if the below conditions is valide,
  *     iIndex is invalid i.e. either < 0 or there is no parameter corresponding to this index
  *   S_FALSE: if MAD is not set explicitly i.e. it has default values
  */
  HRESULT GetParameterMADModifier1f(const int iIndex, float& oMCoefficient, float& oACoefficient) const;
  HRESULT GetParameterMADModifier3f(const int iIndex, CATMathVectorf& oMCoefficient, CATMathVectorf& oACoefficient) const;

  // DEPRECATED: Use CATMaterialApplicationOperations::SetParameterUvSlot
  HRESULT SetParameterUvSlot(const int iIndex, const VisMaterialEnum::UVSlot iUvSlot);
  // DEPRECATED: Use CATMaterialApplicationOperations::GetParameterUvSlot
  HRESULT GetParameterUvSlot(const int iIndex, VisMaterialEnum::UVSlot& oUvSlot) const;

  /**
  * Function to reset values of a particular parameter. This will set below values:
  *   Numeric values (float / int) will be set to 0
  *   Texture and sampler values, if set, will be removed
  *   MAD coefficents will be removed and set to default i.e. multiplier = 1.f and adder = 0.f
  * @returns
  *   E_INVALIDARG: if either if the below conditions is valide,
  *     iIndex is invalid i.e. either < 0 or there is no parameter corresponding to this index
  */
  HRESULT ResetParameterValue(const int iIndex);

  virtual bool isConvertedFromREPhysicalMaterial() const;

  // STREAMING API FOR OCCURENCE CHECKER
  virtual HRESULT Serialize(VisJSONValue& matNode) const;

protected:
  HRESULT ConvertToLegacyMaterial(CATGraphicMaterial* iopMat) const;
  VisMaterial(const VisMaterialModel* ipModel);

  virtual HRESULT FastSetParameterValue(const int iIndex, const int iNbElem, const float iVal1, const float iVal2=0.f, const float iVal3=0.f, const float iVal4=0.f);
  virtual HRESULT FastSetParameterValue(const int iIndex, const int iNbElem, const float* iVal);
  virtual HRESULT FastGetParameterValue(const int iIndex, const int iNbElem, float &oVal1, float &oVal2, float &oVal3, float &oVal4) const;
  virtual HRESULT FastGetParameterValue(const int iIndex, const int iNbElem, float* oVal) const;

  HRESULT FastSetParameterValue(const int iIndex, const int iNbElem, const int* iVal);
  HRESULT FastGetParameterValue(const int iIndex, const int iNbElem, int* oVal) const;

private:

  struct _MADModifierf
  {
    float MCoefficient;
    float ACoefficient;
  };

  struct _MADModifier3f
  {
    CATMathVectorf MCoefficient;
    CATMathVectorf ACoefficient;
  };

  // Copy constructor and equal operator
  // -----------------------------------
  VisMaterial (VisMaterial &);
  VisMaterial& operator=(VisMaterial&);

/** Updates the display after a modification of the graphic material.
  * <ul>
  * CATRedrawNotification : redraw the window.<li>
  * CATUpdateTCNotification : recalculate texture coordinates and redraw the window.<li>
  * </ul>
  */
  void SendMaterialNotification(CATMaterialNotificationType iType,
    const int iParamIndex = -1, const bool iIsSparse = false);

  HRESULT SetPerformanceMaterial(VisMaterial* iPerfMat)const;
  inline const VisMaterial* GetPerformanceMaterial() const;
  HRESULT SetEvisuPerformanceMaterial(VisMaterial* iPerfMat)const;
  inline const VisMaterial* GetEvisuPerformanceMaterial() const;

  // Member variables
  const VisMaterialModel* m_pModel;
  CATCallbackManager *m_pCBManager;

  typedef std::unordered_map<int, IVisTexturePtr> TextureMap;
  typedef std::unordered_map<int, VisMaterialTextureSampler> SamplerMap;
  typedef std::unordered_map<int, _MADModifierf> MADModifierFloatMap;
  typedef std::unordered_map<int, _MADModifier3f> MADModifierFloat3Map;
  typedef std::unordered_map<int, VisMaterialEnum::UVSlot> UVSlotMap;

  HRESULT _SetParameterTexture(TextureMap &iMap, const int iIndex, const IVisTexturePtr &ipTex);
  HRESULT _GetParameterTexture(const TextureMap &iMap, const int iIndex, IVisTexturePtr &opTex) const;

  std::vector<float>    m_FloatValues;
  TextureMap            m_TextureMap;
  TextureMap            m_PerfTextureMap;
  SamplerMap            m_SamplerMap;
  MADModifierFloat3Map  m_MAD3f;
  MADModifierFloatMap   m_MADf;
  int                   m_ActiveTechnique;

  //This two are used only as an internal cache value
  //Hence, they have to be modifiable even as part of the const VisMaterial instance
  mutable VisMaterial*  m_PerformanceMaterial = nullptr;
  mutable VisMaterial*  m_EvisuPerformanceMaterial = nullptr;
};

//-----------------------------------------------------------------------

CATCallbackManager* VisMaterial::GetCallbackManager() const
{
  return m_pCBManager;
}

const VisMaterial* VisMaterial::GetPerformanceMaterial() const
{
  return m_PerformanceMaterial;
}

const VisMaterial* VisMaterial::GetEvisuPerformanceMaterial() const
{
  return m_EvisuPerformanceMaterial;
}

//-----------------------------------------------------------------------

#endif