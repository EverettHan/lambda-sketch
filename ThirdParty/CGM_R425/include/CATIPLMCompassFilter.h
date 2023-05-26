// COPYRIGHT Dassault Systemes 2004
#ifndef CATIPLMCompassFilter_H
#define CATIPLMCompassFilter_H

#include <CATAfrItf.h>
#include <CATBaseUnknown.h>
#include <CATUnicodeString.h>
#include <CATListOfCATString.h>
#include <CATLISTV_CATBaseUnknown.h>

class CATListPtrCATPathElement;
class CATPLMCompassMode;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIPLMCompassFilter;
#else
extern "C" const IID IID_CATIPLMCompassFilter ;
#endif

/**
 * Interface that 'PLM Compass Filter' should implement.
 * 'PLM Compass Filter' are responsible for selection filtering
 * and overlay text and icon generation.
 */
class ExportedByCATAfrItf CATIPLMCompassFilter: public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	 * Label data request.
	 * iMode is the current compass mode, see CATPLMCompassMode
	 * iInput is the list of CATPathElement for which display data is requested
	 * oOutput is the list of label data to display, see CATPLMCompassLabel. The list may contain
	 * a different numbre of items than iInput if some filtering occure.
	 * oProperties is the list of 'properties' to display for each object.
	 * oLegend is the list of legend entry (implement CATIPLMCompassLegend)
	 **/
	virtual HRESULT GetLabels( const CATPLMCompassMode &iMode,
		                       const CATListPtrCATPathElement &iInput,
		                       CATLISTV(CATBaseUnknown_var) &oOutput,
		                       CATListOfCATString &oProperties ) = 0;
};

CATDeclareHandler( CATIPLMCompassFilter, CATBaseUnknown );

#endif
