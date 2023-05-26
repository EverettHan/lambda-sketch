
#ifndef CATPLMRepositoryName_H
#define CATPLMRepositoryName_H

/**
 * @level Protected
 * @usage U1
 */
#include "CATPLMIdentificationAccess.h"

#include "CATBaseUnknown.h"
#include <string.h>
#include "CATBoolean.h"
#include "CATPLMIdentificationAccessMacros.h"

class CATPLMID_Any;

/**
 * Name of a provider
 * @see CATPLMRepositoryNames for some known constants.
 */
class ExportedByCATPLMIdentificationAccess CATPLMRepositoryName
{
public:
  inline CATPLMRepositoryName() :_Index(0) {}
  /**
  * Build a reference on a Type of Repository
  */
  CATPLMRepositoryName(const char * iTypeOfRepository);

  /**
  * Check if repository type is valuated or unset.
  *
  * @return
  *      TRUE    if unset<br>
  *      FALSE   if valuated<br>
  */
  inline explicit operator bool() const { return _Index != 0; }
  inline int IsNull() const { return _Index == 0; }
  /**
  * Converts the RepositoryName to a char *.
  * @return
  *   The char*
  */
  const char* ConvertToChar() const;
  CATUnicodeString ToString() const;
  /**
  * Get the length of the RepositoryName, as char count.
  *
  * @return
  *   Character count.
  */
  int GetLengthInChar() const;

  /** destructor */
  inline ~CATPLMRepositoryName() {}

  /**
  * Build by copy a reference on a Type of Repository
  *
  * @param iCopy
  *   Origin of Copy
  */
  inline CATPLMRepositoryName(const CATPLMRepositoryName &iCopy) :_Index(iCopy._Index) {}

  /**
  * Assign by a reference on a Type of Repository
  *
  * @param iCopy
  *   Origin of Copy
  */
  inline CATPLMRepositoryName& operator=(const CATPLMRepositoryName& iCopy) { _Index = iCopy._Index; return *this; }

  /**
   * comparison
   */
  inline bool operator == (const CATPLMRepositoryName & iToCompare) const { return _Index == iToCompare._Index; }
  inline bool operator != (const CATPLMRepositoryName & iToCompare) const { return _Index != iToCompare._Index; }

  /**
   * Computes (a bad) HashKey
   *
   */
  unsigned int ComputeHashKey() const;

private:
  int _Index;
};

/** prefer using default constructor */
extern const ExportedByCATPLMIdentificationAccess CATPLMRepositoryName CATPLMRepositoryName_Null;

#endif
