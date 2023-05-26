#ifndef CATIPLMFilterConfigPrivate_H
#define CATIPLMFilterConfigPrivate_H

/**
* @level Protected
* @usage U3
*/
#ifndef NEW_CONFIG_FILTERS
#define NEW_CONFIG_FILTERS
#endif
//#include "ExportedByCATPLMServices.h" --> limited access
#include "CATPLMFilterCfgLimitedAccess.h"

#include "CATBaseUnknown.h"

class CATUnicodeString;
class CATIPLMFilterConfig;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMFilterCfgLimitedAccess IID IID_CATIPLMFilterConfigPrivate;
#else
extern "C" const IID IID_CATIPLMFilterConfigPrivate;
#endif

/**
 * Interface giving access to private evaluation data of Config Filter
 */
class ExportedByCATPLMFilterCfgLimitedAccess CATIPLMFilterConfigPrivate : public CATBaseUnknown
{
    CATDeclareInterface;    

	public:

       /**
	      * Clone config filter object 
        * @param oConfigFilter
        *   Pointer on newly created object.
  	    */
        virtual HRESULT Clone (CATIPLMFilterConfig** oConfigFilter) const = 0;

		/**
		* Get a configuration filter stream into an XML string
		* @param oXMLStream
		*        the XML stream
		* @param iWithHeader
		*        Generate the XML file with a header or not
		**/
		virtual HRESULT GetXMLStream (CATUnicodeString& oXMLStream, const CATBoolean& iWithHeader = TRUE)const = 0;

};

#endif
