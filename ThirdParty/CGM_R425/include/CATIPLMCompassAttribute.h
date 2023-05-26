// COPYRIGHT Dassault Systemes 2006
#ifndef CATIPLMCompassAttribute_H
#define CATIPLMCompassAttribute_H

#include <CATAfrItf.h>
#include <CATBaseUnknown.h>
#include <CATUnicodeString.h>

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIPLMCompassAttribute;
#else
extern "C" const IID IID_CATIPLMCompassAttribute ;
#endif

/**
 * PLM compass attribute entry
 */
class ExportedByCATAfrItf CATIPLMCompassAttribute: public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	 * Get item label
	 **/
	virtual HRESULT GetLabel( CATUnicodeString &oLabel ) = 0;
	/**
	 * Item selected
	 **/
	virtual void OnSelect( void ) = 0;
	/**
	 * Item activated
	 **/
	virtual bool IsActive( void ) = 0;
};

CATDeclareHandler( CATIPLMCompassAttribute, CATBaseUnknown );

#endif
