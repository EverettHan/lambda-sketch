#ifndef CATIPLMFilterConfigPersistentDefinition_H
#define CATIPLMFilterConfigPersistentDefinition_H

/**
* @level Protected
* @usage U3
*/

//#include "ExportedByCATPLMServices.h" --> limited access
#include "CATPLMFilterCfgLimitedAccess.h"

#include "CATBaseUnknown.h"

class CATPLMID;
class CATBinary;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMFilterCfgLimitedAccess IID IID_CATIPLMFilterConfigPersistentDefinition;
#else
extern "C" const IID IID_CATIPLMFilterConfigPersistentDefinition;
#endif

/**
 * Interface giving access to private evaluation data of Config Filter
 */
class ExportedByCATPLMFilterCfgLimitedAccess CATIPLMFilterConfigPersistentDefinition : public CATBaseUnknown
{
    CATDeclareInterface;    

	public:

 
        /**
	    * Get Identifier of the Config Filter
        * @param iCHId
        *    Identifier of the config Filter.
  	    */
        virtual HRESULT GetPLMID              ( CATPLMID & oCHId ) const = 0;
        /**
	    * Get compiled binary form of the Config Filter
        * @param oEncodingVersion
        *    Encoding version of the binary data.
        * @param oCompiledQuery
        *    Binary data.
  	    */
        virtual HRESULT GetCompiledBinaryForm ( CATBinary & oCompiledQuery ) const = 0;

};

#endif
