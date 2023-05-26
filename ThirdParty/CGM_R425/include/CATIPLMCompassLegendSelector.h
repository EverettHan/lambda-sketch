// COPYRIGHT Dassault Systemes 2006
#ifndef CATIPLMCompassLegendSelector_H
#define CATIPLMCompassLegendSelector_H

#include <CATBaseUnknown.h>
#include <CATListOfCATUnicodeString.h>
#include <CATAfrItf.h>
#include <CATUnicodeString.h>
#include <CATSysWeakRef.h>

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIPLMCompassLegendSelector;
#else
extern "C" const IID IID_CATIPLMCompassLegendSelector ;
#endif

class CATPLMCompass;

/**
 * Interface that 'PLM Compass Filter' should implement.
 * 'PLM Compass Filter' are responsible for selection filtering
 * and overlay text and icon generation.
 */
class ExportedByCATAfrItf CATIPLMCompassLegendSelector: public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	 * Get current attribute set
	 **/
	virtual HRESULT GetCurrentAttributeSet( CATPLMCompass *iCompass, CATUnicodeString &oAttributeSet ) = 0;
	/**
	 * Get list of available attribute sets
	 **/
	virtual HRESULT GetAttributeSetList( CATPLMCompass *iCompass, CATListOfCATUnicodeString &oAttributeSetList ) = 0;
	/**
	 * User request change of attribute set
	 **/
	virtual HRESULT OnCurrentAttributeSet( CATPLMCompass *iCompass, const CATUnicodeString &iAttributeSet ) = 0; 
};

CATDeclareHandler( CATIPLMCompassLegendSelector, CATBaseUnknown );

#endif
