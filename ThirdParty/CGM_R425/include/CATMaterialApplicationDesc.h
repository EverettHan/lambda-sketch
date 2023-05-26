//#ifndef CATMaterialApplicationDesc_H_
//#define CATMaterialApplicationDesc_H_
//
//#include "SGInfra.h"
//#include "VisMaterialEnum.h"
//#include "CAT4x4Matrix.h"
//#include "CAT3x3Matrix.h"
//
//class VisMaterialApplication;
//class CATUnicodeString;
//class CATMappingOperator;
//class CATDecalProjector;
//class CATGraphicMaterial;
//class CATMaterialIBLParameters;
//
//class ExportedBySGInfra CATMaterialApplicationDesc
//{
//public:
//
//  /**
//    Parameters to not mess up the tangent space
//  */
//  class ExportedBySGInfra UVTransformation
//  {
//  public:
//
//    inline UVTransformation() { };
//    inline UVTransformation(const CAT3x3Matrix& iMatrix) { m_UvTransform = iMatrix; };
//
//    /**
//      Setters to have the opportunity to check the parameter's validity
//    */
//    void SetUVTranslation(float iU, float iV);
//    void SetUVRotation( float iAngle );
//    /**
//      Valid range [0.0, 1.0]
//    */
//    void SetUVScale( float iScale );
//    
//    inline const CAT3x3Matrix& GetMatrix() const  { return m_UvTransform;  };
//    
//  protected:
//    CAT3x3Matrix m_UvTransform;
//  };
//
//  CATMaterialApplicationDesc();
//  ~CATMaterialApplicationDesc();
//  
//  /**
//  * Set anything to the default values, no material, no decal, no mappings
//  */
//  void Reset(const VisMaterialApplication* pImpl=NULL);
//  
//  /**
//  * Set the material along with its inheritance values.
//  */
//  void SetMaterial(CATGraphicMaterial* iMat, unsigned int iInheritance, unsigned int iLayer);
//  
//  /**
//  * Set a decal projector.
//  */
//  void SetDecal(CATDecalProjector const* iProj, bool iAttached, bool iApplied);
//  
//  /**
//  * Set a IMB paramters.
//  */
//  void SetIBLParameters(CATMaterialIBLParameters const* iIBLParams);
//
//  /**
//  * Add a projector that will be applied on the geometry.
//  */
//  void AddTCProjector(CATMappingOperator* iMOP, CATUnicodeString const& iName);
//  
//  /**
//  * Add a mapping that will be generated on the GPU.
//  * return value 0< means invalid parameters
//  */
//  //int AddGPUMapping(VisMaterialEnum::GPUMapping iMOP, CAT4x4Matrix iObjectTransformation, CAT4x4Matrix const& iUVWTransformation);
//  
//  /**
//  * Same than previous, but no risk to mess up the tangent space.
//  * Return: -1 in case of adding failed, >=0 indicating index at which mapping is added
//  */
//  int AddGPUMapping(VisMaterialEnum::GPUMapping iMOP, const CAT4x4Matrix &iObjectTransformation, UVTransformation const& iTrans = UVTransformation());
//  
//  /**
//  * Add a mapping that will use the result of a projector.
//  * return value 0< means invalid parameters
//  */
//  //int AddExplicitMapping(CATUnicodeString const& iName, CAT4x4Matrix iUVWTransformation)
//  
//  /**
//  * Same than previous, but no risk to mess up the tangent space.
//  * Return: -1 in case of adding failed, >=0 indicating index at which mapping is added
//  */
//  int AddExplicitMapping(CATUnicodeString const& iName, UVTransformation const& iUVTransformation = UVTransformation());
//  
//  /**
//  * Associate a UV slot on the material to a mapping (GPU or Explicit).
//  */
//  void SetMappingOnSlot(VisMaterialEnum::UVSlot iSlot, unsigned int iMapping);
//  
//  /**
//  * Return the implementation
//  */
//  VisMaterialApplication const* GetImpl() const;
//  
//  /**
//  * Return the implementation, setting it to NULL on this. Could be a shortcut to fill 3DRep
//  */
//  VisMaterialApplication* StealImpl() const;
//  
//protected:
//  
//  mutable VisMaterialApplication* m_pImpl;
//  
//};
//
//#endif
