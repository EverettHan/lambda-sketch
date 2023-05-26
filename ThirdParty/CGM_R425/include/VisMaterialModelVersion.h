#ifndef VisMaterialModelVersion_H
#define VisMaterialModelVersion_H

#include <unordered_map>
#include <unordered_set>

#include "SGInfra.h"
#include "CATUnicodeString.h"


namespace VisMaterialModelVersion {
  enum class Type {
    Invalid,
    Visu_Basic,
    Visu_SpecularGlossiness,
    Visu_ShaderOverride,
    Visu_DSPBR,

    MPM_Complex,
    MPM_AnisotropicMetal,
    MPM_Basic,
    MPM_CarPaint,
    MPM_ClearGlass,
    MPM_ColoredGlass,
    MPM_Diamond,
    MPM_Diffuse,
    MPM_Emissive,
    MPM_FrostedGlass,
    MPM_PolishedMetal,
    MPM_PolishedPlastic,
    MPM_SatinatedMetal,
    MPM_SoftPlastic,
    MPM_Translucent,

    MIA_Complex,
    MIA_Diffuse,
    MIA_Diamond,
    MIA_ClearGlass,
    MIA_ColoredGlass,
    MIA_FrostedGlass,
    MIA_SoftPlastic,
    MIA_PolishedPlastic,
    MIA_PolishedMetal,
    MIA_AnisotropicMetal,
    MIA_SatinatedMetal,
    MIA_ReflectiveTranslucent,
    MIP_CarPaint,
    MIP_MetallicPaint,

    XRite_CarPaint2,
    MDL_Generic,
  };

  enum class Release {
    Invalid = 0,
    R2018X = 4200,
    R2019X = 4210,
    R2020X = 4220,
    R2021X = 4230,
    R2022X = 4240,
    R2023X = 4250,
  };

  enum class Family { Invalid, Visu, MPM, MIA, XRite, MDL };

  /**

  * Type Description is designed as an update of the CATUnicodeString based material model type
  * The main difference is that is contains a Release version to support VisMaterialModel versioning
  * Family field is a convenience property to query material origin
  * The CATUnicodeString label is still there be compatible with the past versions of VisMaterial API

  * Construction examples:
  * TypeDesc(Type::Visu_DSPBR, Release::R2021X)
  * TypeDesc(Type::MPM_Complex, Release::R2019X)
  *
  * Not all the combinations of the Type and Release return exactly unique VisMaterialModel
  * Setting of a particular label and family is not advised, because not all combinations are supported
  */
  struct ExportedBySGInfra TypeDesc {

    Type    type;             // the main identifier
    Release release;          // the version of the type, making it potentially unique

    CATUnicodeString  label;  // Backward compatibility field. AVOID quering this property to check material model version
    Family  family;           // convenience field to destinguish big classes of materialy types; not sure if needed

    //Constructs an invalid TypeDesc
    TypeDesc();

    //copy
    TypeDesc& operator=(const TypeDesc& iTypeDesc);
    TypeDesc(const TypeDesc& iTypeDesc);

    //move
    TypeDesc& operator=(TypeDesc&& iTypeDesc);
    TypeDesc(TypeDesc&& iTypeDesc);

    /*
    * This should be your default constructor
    * Preferred constructor for a type description of a material model of any supported release
    */
    TypeDesc(const Type iType, const Release iRelease);

    /*
    * Comparison is performed only on type and release, but not on label and family
    * Consider IsStrictEqual, but you probably don't need it
    */
    bool operator==(const TypeDesc& rhs) const;
    bool operator!=(const TypeDesc& rhs ) const;

    /*
    * Method to be used by the unstreaming from cgr and 3dx
    *
    * iLabel is expected to have a form of "prefix.type[@release]"
    *  - prefix is mandatory non-empty string, followed by a "."
    *  - release is an optional string with "@" at the beginning
    *  - type is non-empty string
    * However not all of the valid strings correspond to a valid material model desccription.
    *
    * There are also specific exception to support legacy typing: " @17x"
    * For example, "Visu.SpecularGlossiness" and "Visu.SpecularGlossiness@17x" are valid and supported labels
    * "Visu.SpecularGlossiness@19x" or "MPM.Complex@R2020x is still unexpected
    *
    * An arbitrary string will result in E_UNEXPECTED
    */
    static HRESULT FromString(const CATUnicodeString& iLabel, TypeDesc& oTypeDesc);
    static const TypeDesc InvalidTypeDesc;
    static const std::unordered_set<TypeDesc> supportedMaterialModelVersions;
  private:
    TypeDesc(const Type);
    TypeDesc(const Type, const Release, const CATUnicodeString&, const Family);
    static const std::pair<Release, Family> GetDefaultReleaseFamilyFromType(const Type);
    static const CATUnicodeString GetLabelFromTypeRelease(const Type, const Release);
    static const std::unordered_map<Type, const CATUnicodeString> _labelFromType;

    /*
    *  This map to be used in the unstreaming code to get a correct VisMaterialModelVersion::Release from the string representation
    *  A suffix in the form "@R2021x", "@R2022x", etc. is supposed to be used for streaming of the TypeDesc in CGR or 3DX after 21x FD01
    *
    * "modelName@17x" - this is the only way how @ ,followed by the "@17x" can appear. All other variants like @18x or @20x are impossible or illegal.
    */

    /*
    * I'm not comfortable with injecting the hash implementaion into the std namespace for CATUnicodeString
    */
    struct Hash_for_CATUnicodeString {
      std::size_t operator()(const CATUnicodeString& iLabel) const noexcept {
        return iLabel.ComputeHashKey();
      }
    };

    static const std::unordered_map<CATUnicodeString, Release, Hash_for_CATUnicodeString> _validReleaseSuffix;
    static const std::unordered_map<CATUnicodeString, Family, Hash_for_CATUnicodeString> _validFamilyPrefix;
  };
} //namespace VisMaterialModelVersion

// custom specializations of std::hash is injected in namespace std for TypeDesc and Type
namespace std {
  template<> struct hash<VisMaterialModelVersion::TypeDesc> {
    std::size_t operator()(const VisMaterialModelVersion::TypeDesc& iTypeDesc) const noexcept {
      return static_cast<int>(iTypeDesc.release) * 100 + static_cast<int>(iTypeDesc.type) * 10;
    }
  };

  template<> struct hash<VisMaterialModelVersion::Type> {
    std::size_t operator()(const VisMaterialModelVersion::Type iType) const noexcept {
      return static_cast<std::size_t>(iType);
    }
  };
}

#endif
