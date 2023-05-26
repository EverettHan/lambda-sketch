#ifndef CATPLMCEStamp_H
#define CATPLMCEStamp_H

#include "CATPLMIdentificationAccess.h"
#include "CATTime.h"
#include "CATBooleanDef.h"
#include "IUnknown.h"
#include "CATDataType.h"
#include "CATOmxSR.h"
class CATOxCEStamp;
class CATBinary;
class CATUnicodeString;
//-----------------------------------------------------------------------

/**
* @level Private
* @usage U1
*/

typedef enum 
{
  CATPLMCEStamp_TimeType,
  CATPLMCEStamp_BinaryType
} CATPLMCEStamp_Type;

/**
 * Concurrent Engineering Stamp
 */
class ExportedByCATPLMIdentificationAccess CATPLMCEStamp
{
public:
  /** default constructor (builds an "invalid" CE stamp)*/
  inline CATPLMCEStamp() {}

  /** Copy Constructor */
  CATPLMCEStamp (const CATPLMCEStamp &);
 

  /** Destructor*/
  ~CATPLMCEStamp();

  /** Assignment Operator */
  CATPLMCEStamp& operator=(const CATPLMCEStamp&);

  /** strcmp like comparison*/
  int Compare(const CATPLMCEStamp& iOther) const;

  CATHashKey Hash() const;

  /** Equality operator (sorry for the legacy incoherent returned values types) */
  inline unsigned int operator==(const CATPLMCEStamp& iOther) const {return 0==Compare(iOther);}
  inline CATBoolean operator!=(const CATPLMCEStamp& iOther) const   {return 0!=Compare(iOther);}

  /**
  * Check if CATPLMCEStamp is completely built.
  * @return
  *  <ol>
  * 	 <li> TRUE  if CATPLMCEStamp is completely built </li>
  *	   <li> FALSE	if CATPLMCEStamp is not valid </li>
  *  </ol>   
  */
  CATBoolean IsValid() const;
  inline CATBoolean isValid() const {return IsValid();}

  /**
  * Streams the CEStamp to a CATBinary
  *
  * @param iStamp : The CEStamp to stream
  *        oStream : The CATBinary resulting from the streaming process
  *
  * @return 
  *    S_OK if everything went right
  */
  static HRESULT SaveAsBinary(const CATPLMCEStamp & iStamp, CATBinary & oStream);

  /**
  * Unstreams the CEStamp from a CATBinary
  *
  * @param iStream : The CATBinary to unstream
  *
  * @return 
  *    S_OK if everything went right
  */
  static HRESULT RestoreFromBinary(CATPLMCEStamp & oStamp, const CATBinary & iStream);

  /**
  * Streams the CEStamp to a scrambled string
  * <ul>
  * <li>Streamed value can only be used to rebuild a @href CATPLMCEStamp using @href CATPLMCEStamp#Unstream protocol.</li>
  * </ul>
  *
  * @param iStamp : The CEStamp to stream
  *        oStream : The scrambled string resulting from the streaming process
  *
  * @return 
  *    S_OK if everything went right
  */
  static HRESULT Stream(const CATPLMCEStamp & iStamp, CATUnicodeString & oStream);

  /**
  * Unstreams the CEStamp from a scrambled string generated thanks to @href CATPLMCEStamp#Stream protocol
  *
  * @param oStamp : the output (unstreamed) stamp
  *        iStream : The scrambled unicode string to unstream
  *
  * @return 
  *    S_OK if everything went right
  */
  static HRESULT Unstream(CATPLMCEStamp & oStamp, const CATUnicodeString & iStream);

  /**
  *  Get type of the CEStamp
  */
  HRESULT GetType(CATPLMCEStamp_Type & oType);

  /**
  * @nodoc, internal usage
  */
  explicit CATPLMCEStamp(const CATOxCEStamp* );
  inline const CATOxCEStamp* GetLetter() const {return m_CEStamp;}
private:
  // member data on letter (pattern enveloppe-letter)
  CATOmxSR<CATOxCEStamp> m_CEStamp;
};


//-----------------------------------------------------------------------
#endif
