#ifndef CATCkePLMPolicy_h
#define CATCkePLMPolicy_h

// COPYRIGHT Dassault Systemes 2012 
#include <stddef.h>
#include "CATBoolean.h"
#include "CATBaseUnknown.h" // HRESULT
#include "CATUnicodeString.h" // HRESULT
#include "PLMDictionaryInterfaces.h"

class ExportedByPLMDictionaryInterfaces CATCkePLMPolicy 
{
	public:

		CATCkePLMPolicy(const CATUnicodeString &iPolicyName);
		~CATCkePLMPolicy();

    CATBoolean HasBeenFound () const;

    // Translate a signature
    CATBoolean GetNLSTranslationForSignature (const CATUnicodeString &iSignatureName,CATUnicodeString &NLSSignature) const;

private:
  		CATCkePLMPolicy(const CATCkePLMPolicy &Copy);
      CATUnicodeString _PolicyName;
};

#endif // CATCkePLMPolicy_h

