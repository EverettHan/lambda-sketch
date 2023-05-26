#ifndef VisMaterialConversion_H
#define VisMaterialConversion_H

#include "SGInfra.h"
#include "VisMaterial.h"
#include "VisMaterialModelVersion.h"

namespace VisMaterialConversion {
  enum class Result{
    eLossless,
    eLossy,
    eUnsupported
  };

  /*Both functions below return:
  * eLossless     if lossless conversion possible
  * eLossy        if lossy conversion possible
  * eUnsupported  if conversion is not implemented or not supported

  * Verifies if iSrcMaterial is possible to convert to a new VisMaterial with type iDestTypeDesc
  *
  * Material of the type DSPBR 2019x will be lossy converted to DSPBR 2021x if at least one of the following is true:
  *  -Sheen value and respecive MAD modifier is larger than 0.0 (of very small threshold ~0.001f)
  *  -All of the Emission, Emission Color, and Clearcoat values and respective MAD modifiers are larger than 0.0 (of very small threshold ~0.001f)
  * otherwise, lossless conversion takes place
  *
  * Coversion is unsupported if input material contains compressed albedo or sheen textures or if these textures contain different UV transformations
  *
  * Any other material combinaions are unsupported
  */
  ExportedBySGInfra Result IsConversionPossible(const VisMaterial& iSrcMaterial, const VisMaterialModelVersion::TypeDesc& iDestTypeDesc) noexcept;

  /*
  * The outputMaterial parameters are altered if lossless or lossy conversion is possible
  * returns: the same as IsConversionPossible
  */
  ExportedBySGInfra Result VisMaterialConvert(const VisMaterial& iMaterial, VisMaterial& oMaterial) noexcept;
}

#endif
