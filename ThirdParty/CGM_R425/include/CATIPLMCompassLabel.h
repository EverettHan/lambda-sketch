// COPYRIGHT Dassault Systemes 2004
#ifndef CATIPLMCompassLabel_H
#define CATIPLMCompassLabel_H

#include <CATAfrItf.h>
#include <CATBaseUnknown.h>
#include <CATUnicodeString.h>
#include <CATString.h>

class CATMathPointf;
class CATPathElement;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIPLMCompassLabel;
#else
extern "C" const IID IID_CATIPLMCompassLabel ;
#endif

/**
 */
class ExportedByCATAfrItf CATIPLMCompassLabel: public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	 * Label data access. Returns the label for property 'iProperty'.
	 **/
	virtual CATUnicodeString GetLabel( const CATString &iProperty ) = 0;
	/**
	 * Label data access. Returns the icon for property 'iProperty'.
	 **/
	virtual CATUnicodeString GetIcon( const CATString &iProperty ) = 0;
	/**
	 * Get anchor point 3D position
	 **/
	virtual HRESULT GetAnchor( CATMathPointf &oAnchor ) = 0;
	/**
	 * Get path element of object
	 **/
	virtual CATPathElement *GetPath( void ) = 0;
};

CATDeclareHandler( CATIPLMCompassLabel, CATBaseUnknown );

#endif
