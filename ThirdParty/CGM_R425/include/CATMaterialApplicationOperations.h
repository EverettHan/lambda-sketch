#ifndef CATMaterialApplicationOperations_H_
#define CATMaterialApplicationOperations_H_

#include "SGInfra.h"
#include "CATUnicodeString.h"
#include "CAT4x4Matrix.h"
#include "CAT3x3Matrix.h"
#include "VisMaterialEnum.h"
#include "CATDataType.h"

class CATRep;
class CAT3DRep;
class CATGraphicMaterial;
class CATMaterialApplication;
class CATDecalProjector;
class CATMaterialIBLParameters;
class CATMappingOperator;
class VisMaterialApplication;
class IVisTexturePtr;
class IVisTexture;

/**
* Class to manage material mapping information associated with scene graph
* Role: CATMaterialApplication is public interface. It was exposed too early.
* We don't want to expose all material mapping related functionalities in CATMaterialApplication.
* This class lets apps set necessary information on material application which is not exposed in CATMaterialApplication.
* see @href CATMaterialApplication, VisMaterial, CATGraphicMaterial
*/

class ExportedBySGInfra CATMaterialApplicationOperations
{
public:

  //Un Id opaque serait pas mal.
  typedef CATMaterialApplication const* ApplicationId;

  //Doit lier l'application à la rep.
  static ApplicationId CreateMaterialApplication(CAT3DRep& iRep);

  //Doit devenir un chemin legacy
  static void SetMaterial(ApplicationId iId, CATGraphicMaterial*);
  static CATGraphicMaterial* GetMaterial(ApplicationId iId);

  static void SetInheritance(ApplicationId iId, int iInheritance, CATULONG32 iLayer);
  static void GetInheritance(ApplicationId iId, int &oInheritance, CATULONG32 &oLayer);

  //PDSFX basé sur une matière existante
  //static void SetMaterialOverride(ApplicationId iId, CATMaterialOverride*);

  //Suppose que CATDecalProjector ait la liste des reps sur lesquelles il est appliqué pour Maj.
  static void AddDecalProjector(ApplicationId iAppl, CATDecalProjector const* iProjector, bool iApply, bool iAttach, CATRep* iRep = NULL);

  static CATDecalProjector const* GetDecalProjector(ApplicationId iAppl);
  static bool IsDecalAttached(ApplicationId iId);
  static bool IsDecalApplied(ApplicationId iId);

  static void RemoveDecalProjector(ApplicationId iAppl);

  //Même remarque que pour le decal.
  static void AddIBLParameters(ApplicationId iAppl, const CATMaterialIBLParameters* iParameters, CATRep* iRep = NULL);

  static CATMaterialIBLParameters const* GetIBLParameters(ApplicationId iAppl);

  static void RemoveIBLParameters(ApplicationId iAppl);

  //Les UV transform avec en plus le slot d'application. Besoin UVW ? Comme avant, interdit scale non uniforme et mirror
  static void SetUVTransform(ApplicationId iAppl, /*unsigned int iSlotId,*/ float iPosU, float iPosV, float iRotation, float iScale, CATRep* iRep = NULL);

  // ---------------------------- NEW MATERIAL API ---------------------------------

  /**
    Parameters to not mess up the tangent space
  */
  class ExportedBySGInfra UVTransformation
  {
  public:

    inline UVTransformation() { };
    inline UVTransformation(const CAT3x3Matrix& iMatrix) { m_UvTransform = iMatrix; };

    /**
    * Setters to have the opportunity to check the parameter's validity
    */
    void ApplyTranslation(float iU, float iV);
    void ApplyRotation(float iAngle);
    /**
      Valid range [0.0, 1.0]
    */
    void ApplyScale(float iScale);

    inline const CAT3x3Matrix& GetMatrix() const { return m_UvTransform; };

  protected:
    CAT3x3Matrix m_UvTransform;
  };

  ///////////////////////////////////   MAPPING   PER UV SLOT   //////////////////////////////////////

  /**
  * Associate UVSlot with texture coordinate set which can be named TC set or result of a mapping operator.
  * in iName, name of TC projector or TC set to use, can't be empty
  * in iMOP, mapping operator used to generate/update texture coordinates, can be NULL in case of named TC set is used
  */
  static void SetExplicitMapping(ApplicationId iId, VisMaterialEnum::UVSlot iSlot, CATUnicodeString const& iName, CATMappingOperator* iMOP = NULL);

  /**
  * Get TCName/mapping operator associated with a UVSlot iSlot
  * out oTCName, name of TC projector or named TC set
  * return, mapping operator object if set otherwise NULL (in case of named TC set)
  */
  static CATMappingOperator* GetExpliciteMappingInfo(ApplicationId iId, VisMaterialEnum::UVSlot iSlot, CATUnicodeString& oTCName);

  /**
  * Associate UVSlot with given mapping operator type.
  * in iMOP, mapping operator type, can't be None
  * in iObjectTransform, object transform to use
  * NOTE: not all material types support mapping operator type. This function will not return any error in such case.
  */
  static void SetMappingOperator(ApplicationId iId, VisMaterialEnum::UVSlot iSlot, VisMaterialEnum::MappingOperator iMOP, const CAT4x4Matrix &iObjectTransform);

  /**
  * Get mapping operator information for given UVSlot (iSlot)
  * out oObjTransform, object transform associated
  * Return, mapping operator type on this UVSlot
  */
  static VisMaterialEnum::MappingOperator GetMappingOperatorInfo(ApplicationId iId, VisMaterialEnum::UVSlot iSlot, CAT4x4Matrix& oObjTransform);

  /**
  * Reset mapping information for given slot
  * For iSlot=eUVSlot_Default, mapping is set to explicit mapping with DEFAULT_TC_SET and no mapping operator
  */
  static void ResetMapping(ApplicationId iId, VisMaterialEnum::UVSlot iSlot);



  ///////////////////////////////////   UV TRANSFORM   //////////////////////////////////////
  /**
  * Set UV transform for given UV slot
  */
  static void SetUVTransform(ApplicationId iId, VisMaterialEnum::UVSlot iSlot, UVTransformation const& iTrans);

  /**
  * Get transformation matrix used for given UVSlot
  */
  static CAT3x3Matrix GetUVTransform(ApplicationId iId, VisMaterialEnum::UVSlot iSlot);

  /**
  * Set UV transform semantic
  */
  static HRESULT SetUVTrfSemantic(ApplicationId iId, const VisMaterialEnum::UVTrfSemantic& iUvTrfSemantic);

  /**
  * Get UV transform semantic
  */
  static HRESULT GetUVTrfSemantic(ApplicationId iId, VisMaterialEnum::UVTrfSemantic& oUvTrfSemantic);

  ///////////////////////////////////   MATERIAL PER PARAMETER PROPERTIES   ///////////////////////////
  /**
  * Set UV transform for given material parameter. Not all material models support this functionality.
  * @returns
  *   E_INVALIDARG: Material is either null or not of the type REVisMaterial
  *   S_FALSE: iParamIndex is invalid or it is not texturable (it is not of the type 'VisMaterialParameter::eFloatParam' or 'VisMaterialParameter::eTexture'
  */
  static HRESULT SetParameterUVTransform(ApplicationId iId, const int iParamIndex, UVTransformation const& iTrans);

  /**
  * Get transformation matrix used for given material parameter. Not all material models support this functionality.
  * @returns
  *   E_INVALIDARG: Material is either null or not of the type REVisMaterial
  *   S_FALSE: iParamIndex is invalid or it is not texturable (it is not of the type 'VisMaterialParameter::eFloatParam' or 'VisMaterialParameter::eTexture'
  */
  static HRESULT GetParameterUVTransform(ApplicationId iId, const int iParamIndex, CAT3x3Matrix &oMat);

  /**
  * Function to set UVSlot for given parameter. Not all material models support this functionality.
  * @returns
  *   E_INVALIDARG: Material is either null or not of the type REVisMaterial
  *   S_FALSE: iParamIndex is invalid
  *            or it is not texturable (it is not of the type 'VisMaterialParameter::eFloatParam' or 'VisMaterialParameter::eTexture'
  *            or iUvSlot is same as currently set UvSlot (nothing is changed)
  */
  static HRESULT SetParameterUVSlot(ApplicationId iId, const int iParameterIndex, VisMaterialEnum::UVSlot iSlot);

  /**
  * Function to get UVSlot for given parameter. Not all material models support this functionality.
  * @returns
  *   E_INVALIDARG: Material is either null or not of the type REVisMaterial
  *   S_FALSE: iParamIndex is invalid
  *            or it is not texturable (it is not of the type 'VisMaterialParameter::eFloatParam' or 'VisMaterialParameter::eTexture'
  *            or if UV slot is not set explicitly i.e. it has default values (VisMaterialEnum::eUVSlot_Default)
  */
  static HRESULT GetParameterUVSlot(ApplicationId iId, const int iParameterIndex, VisMaterialEnum::UVSlot &oSlot);


  ///////////////////////////////////   TEXTURE PER UV SLOT   //////////////////////////////////////

  /**
  * Returns true if channel texture can be set of given UV slot
  * Currently supported UV slots: eUVSlot_Lightmap
  */
  static bool IsChannelTextureSupported(VisMaterialEnum::UVSlot iSlot);

  /**
  * Set texture on a UV channel for given material application
  * Supported UV channels: eUVSlot_Lightmap
  * @return S_OK, if texture is set on the UVSlot
  *         E_INVALIDARG, in case of unsupported UVSlot
  */
  static HRESULT SetChannelTexture(ApplicationId iId, VisMaterialEnum::UVSlot iSlot, const IVisTexturePtr &iTexture);

  /**
  * Get texture set on a UV channel of given material application
  */
  static const IVisTexturePtr &GetChannelTexture(ApplicationId iId, VisMaterialEnum::UVSlot iSlot);



  ///////////////////////////////////   OTHER   //////////////////////////////////////

  /**
  * Set a property value for given material application
  * The value must match the property.
  * @return S_OK, if the property value can be changed
  *         E_INVALIDARG, in case of invalid property enum or value
  */
  static HRESULT SetPropertyValue(ApplicationId iId, VisMaterialEnum::Property iProperty, unsigned int iValue);

  /**
  * Get a property value for given material application
  * @return S_OK, if the property value can be changed
  *         E_INVALIDARG, in case of invalid property enum
  */
  static HRESULT GetPropertyValue(ApplicationId iId, VisMaterialEnum::Property iProperty, unsigned int& oValue);

  // -------------------------------------------------------------------------------

  /* DEPRECATED: DO NOT USE. To be removed soon. */
  static void SetGPUMapping(ApplicationId iId, VisMaterialEnum::UVSlot iSlot, VisMaterialEnum::MappingOperator iMOP, const CAT4x4Matrix &iObjectTransform);
  static VisMaterialEnum::MappingOperator GetGPUMappingInfo(ApplicationId iId, VisMaterialEnum::UVSlot iSlot, CAT4x4Matrix& oObjTransform);

  // Note: AddRef is NOT done on returned object
  static VisMaterialApplication* GetImpl(ApplicationId iId);

};

#endif
