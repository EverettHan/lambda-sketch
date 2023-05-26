#ifndef _CATPLMCompletionLevel_H
#define _CATPLMCompletionLevel_H
/**
* @level Private
* @usage U1
*/
#include "CATPLMIdentificationAccess.h"

#include "IUnknown.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"
#include "CATDbBinary.h"
#include "CATDataType.h"
#include "CATPLMID.h" // include indirect

#include "CATPLMRepositoryName.h"
#include "CATPLMIdentificationAccessMacros.h"
#include "CATOmxCompare.h"

/** obsolete, meaningless*/
enum CATPLMCompletionLevelFormat { CATPLMCompletionLevel_Unicode, CATPLMCompletionLevel_Undefined };

//deprecated use expanded macro instead
#define CATPLMCompletionLevel_Full       CATPLMCompletionLevel::Level_Full()
#define CATPLMCompletionLevel_Navigation CATPLMCompletionLevel::Level_Navigation()
#define CATPLMCompletionLevel_Light      CATPLMCompletionLevel::Level_Light()

/**
 * very complex stuff to manage UWP completion level (should be an enum)
 * there are 4 states:
 *  Light:      UWP light mode (3DIndex, no attributes)
 *  Navigation: UWP nav mode  (only a subset of M1 attributes used in display name are available)
 *  Full:       UWP full mode (objects is fully loaded from M1)
 *  Null/Empty/Unset: default mode, strictly equivalent to Full
 */
class CATPLMCompletionLevel
{
public:
  /** default constructor */
  inline CATPLMCompletionLevel() :_Value(0) {}

  /**deprecated, use operator== */
  inline HRESULT IsEqual(const CATPLMCompletionLevel & iOther, CATBoolean & oEqual) const { oEqual = (CATBoolean)this->operator==(iOther); return S_OK; }

  /**
  * Returns FALSE if not valuated
  */
  inline explicit operator bool() const { return _Value != 0; }

  /**deprecated, meaningless */
  unsigned int ComputeHashKey() const { return _Value; }
  HRESULT ComputeHashKey(unsigned int &oKey) const { oKey = ComputeHashKey(); return S_OK; }

  /** comparison */
  int operator == (const CATPLMCompletionLevel& iToCompare) const { return _Value == iToCompare._Value; }
  int operator != (const CATPLMCompletionLevel& iToCompare) const { return _Value != iToCompare._Value; }
  int Compare(const CATPLMCompletionLevel& other) const { return CATOmxCompare(_Value, other._Value); }

  /**deprecated, meaningless */
  inline HRESULT GetFormat(CATPLMCompletionLevelFormat& oFormat) const { oFormat = CATPLMCompletionLevel_Unicode; return S_OK; }

  /**deprecated, meaningless */
  ExportedByCATPLMIdentificationAccess HRESULT SetUnicode(const CATUnicodeString & iUnicode);
  ExportedByCATPLMIdentificationAccess HRESULT GetUnicode(CATUnicodeString & oUnicode) const;

  /**deprecated, meaningless */
  inline HRESULT Reset() { this->operator=(CATPLMCompletionLevel()); return S_OK; }

  inline bool IsLightOrNav() const { return _Value == 2 || _Value == 3; }
  inline bool IsFullOrUnset() const { return !IsLightOrNav(); }

  static inline const CATPLMCompletionLevel Level_Full() { return CATPLMCompletionLevel(1); }
  static inline const CATPLMCompletionLevel Level_Navigation() { return CATPLMCompletionLevel(2); }
  static inline const CATPLMCompletionLevel Level_Light() { return CATPLMCompletionLevel(3); }

private:
  inline CATPLMCompletionLevel(signed char iValue) :_Value(iValue) {}

  signed char  _Value;
};

extern const ExportedByCATPLMIdentificationAccess CATPLMCompletionLevel CATPLMCompletionLevel_Null;

#endif




