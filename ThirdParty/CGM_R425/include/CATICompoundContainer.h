/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATICompoundContainer_H
#define CATICompoundContainer_H
//
//	Interface implemented on container of type "AppliCont"
//		==> It enables to create application containers under it
//		==> The access to application containers must be done through this interface ( and not CATIContainer !!!)
//
//
//	04/98		slg/lbf
//
/**
 * @level Private
 * @usage U3
 */

#include "CATBaseUnknown.h"
#include "AD0XXBAS.h"
//
class CATUnicodeString;
class CATIContainer_var;



extern ExportedByAD0XXBAS IID IID_CATICompoundContainer ;


class ExportedByAD0XXBAS CATICompoundContainer : public CATBaseUnknown
{
	CATDeclareInterface;
  public:

	virtual
		CATIContainer_var GetApplicativeContainer ( const CATUnicodeString& ContName) = 0;

	virtual
		HRESULT GetApplicativeContainer ( const CATUnicodeString& ContName, CATIContainer_var& oAppliCont ) = 0;

  
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATICompoundContainer, CATBaseUnknown ) ;


#endif
