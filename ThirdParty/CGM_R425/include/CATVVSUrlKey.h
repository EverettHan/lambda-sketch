/**
 * @level Protected
 * @usage U1
 */

#ifndef __CATVVSUrlKey_H
#define __CATVVSUrlKey_H

#include "VVSUrlUtils.h"
#include "CATVVSUrl.h"

class ExportedByVVSUrlUtils CATVVSUrlKey
{
public:

	CATVVSUrlKey();
	CATVVSUrlKey(const CATVVSUrl& VVSUrl);

  inline CATUINT32 HashFunc() const {return m_HashKey;}
  inline const CATVVSUrl& GetVVSUrl() const {return m_VVSUrl;}
	CATBoolean operator== ( const CATVVSUrlKey& in_key) const;
  inline CATBoolean operator!= ( const CATVVSUrlKey& in_key) const {return !operator==(in_key);}

private:
	CATVVSUrl m_VVSUrl;       
	CATUINT32 m_HashKey;
}; 

#endif

