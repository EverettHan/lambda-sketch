#ifndef CATPLMValue_h
#define CATPLMValue_h


/**
* @level Private
* @usage U1
*/

/**@SOM*/
// small checks
#if defined (private) || defined(friend) || defined (protected)

#error Forbidden re-define of 'private', 'friend' or 'protected'
// Fatal error on solaris
@error

#endif


#define AuthorizedModule 999
#define CATPLMIntegration         AuthorizedModule
#define CATPLMIntegAccessUtils    AuthorizedModule
#define CATPLMIntegrationAccess   AuthorizedModule
#define CATPLMIntegrationBase     AuthorizedModule
#define CATPLMIntegrationAccessBase   AuthorizedModule
#define CATPLMValue_UT            AuthorizedModule
#define CATPLMIntegrationUse      AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error This header is for internal use only
// Fatal error on solaris
@error
#endif


#undef CATPLMIntegration
#undef CATPLMIntegAccessUtils
#undef CATPLMIntegrationAccess
#undef CATPLMIntegrationAccessBase
#undef CATPLMIntegrationBase
#undef CATPLMValue_UT
#undef CATPLMIntegrationUse


#if _MK_MODNAME_ == AuthorizedModule
#pragma message("[Warning] Delared module has not been undeclared correctly.")
#endif
#undef AuthorizedModule

// end of checks

/**@EOM*/

#include "CATIPLMValueReader.h"
#include "CATIPLMValueWriter.h"
#include "CATPLMIntegrationBase.h"
#include "CATBinary.h"
#include "CATOmxAny.h"


/**
* Classe qui surcharge le CATVariant pour le PLM
* Implement CATIPLMValueReader
*
* Attention, on ne peut faire SetValue qu'une fois.
*
* TODO : operator==
*        AsString
*/


class ExportedByCATPLMIntegrationBase CATPLMValue : public CATIPLMValueReader
{

  CATDeclareClass;


public:
  CATPLMValue();
  ~CATPLMValue();

  CATIPLMValueReader::Type GetType();

  /**
  * @href CATIPLMValueReader#GetSize
  */
  HRESULT GetSize(unsigned int & oSize);

  /**
  * @href CATIPLMValueReader#IsMultiValuated
  */
  HRESULT IsMultiValuated();

  /**
  * @href CATIPLMValueReader#GetIntValue
  */
  HRESULT GetIntValue(int & oValue, unsigned int index = 1);

  /**
  * @href CATIPLMValueReader#GetDoubleValue
  */
  HRESULT GetDoubleValue(double & oValue, unsigned int index = 1);

  /**
  * @href CATIPLMValueReader#GetStringValue
  */
  HRESULT GetStringValue(CATUnicodeString & oValue, unsigned int index = 1);

  /**
  * @href CATIPLMValueReader#GetTimeValue
  */
  HRESULT GetTimeValue(CATTime & oValue, unsigned int index = 1);

  /**
  * @href CATIPLMValueReader#GetBinaryValue
  */
  HRESULT GetBinaryValue(CATBinary & oValue, unsigned int index = 1);

  /**
  * @href CATIPLMValueReader#GetIntValue
  */
  HRESULT GetBooleanValue(CATBoolean & oValue, unsigned int index = 1);


  HRESULT GetOmxAny(CATOmxAny &oValue);

  /*
  * @href CATIPLMValueReader#IsUnset
  */
  CATBoolean IsUnset();
  // CATIPLMValueWriter

  /**
  * @href CATIPLMValueWriter@SetValue
  */
  HRESULT SetValue(const int iValue);

  /**
  * @href CATIPLMValueWriter@SetValue
  */
  HRESULT SetValue(const CATListOfInt &iValue);

  /**
  * @href CATIPLMValueWriter@SetValue
  */
  HRESULT SetValue(const double iValue);

  /**
  * @href CATIPLMValueWriter@SetValue
  */
  HRESULT SetValue(const CATListOfDouble &iValue);

  /**
  * @href CATIPLMValueWriter@SetValue
  */
  HRESULT SetValue(const CATUnicodeString & iValue);
  /**
  * @href CATIPLMValueWriter@SetValue
  */
  HRESULT SetValue(const CATListOfCATUnicodeString &iValue);

  /**
  * @href CATIPLMValueWriter@SetValue
  */
  HRESULT SetValue(const CATTime &iValue);
  /**
  * @href CATIPLMValueWriter@SetValue
  */
  HRESULT SetValue(const CATBinary &iValue);
  /**
  * @href CATIPLMValueWriter@SetValue
  */
  HRESULT SetValue(const CATBoolean &iValue);
  /**
  * @href CATIPLMValueWriter@SetValue
  */
  HRESULT SetValue(const CATListOfCATBoolean &iValue);

  HRESULT SetOmxAny(const CATOmxAny &iValue);

  /*
  * Specify if attribute is to be unset
  */
  HRESULT Unset();


  // methode non exposee
  //HRESULT SetValue(const CATVariant &iValue);
  HRESULT AsString(CATUnicodeString & oString);


private:
  bool IsMultiBinary();
  CATOmxAny _value;
  CATBoolean _isUnset, _isList;
};



#endif
