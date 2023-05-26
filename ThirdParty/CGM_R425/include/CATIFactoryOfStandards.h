/* -*-c++-*- */
#ifndef CATIFactoryOfStandards_h
#define CATIFactoryOfStandards_h
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 1999
//-----------------------------------------------------------------------------
//
// Interface CATIFactoryOfStandards
// 
//-----------------------------------------------------------------------------
// Usage Notes:
//
// Factory of standards
// Implemented by extension of CATFeatCont 
//
//-----------------------------------------------------------------------------
// Created cwz - Oct 99
//-----------------------------------------------------------------------------

/**
 * @level Private
 * @usage U3
 */

#include "AD0XXBAS.h"
#include "CATBaseUnknown.h"
#include "booleanDef.h"

extern ExportedByAD0XXBAS IID IID_CATIStandard ;
class CATIStandard;
class CATListPtrCATIStandard;
class CATListPtrCATBaseUnknown;

extern ExportedByAD0XXBAS IID IID_CATIFactoryOfStandards ;

class ExportedByAD0XXBAS CATIFactoryOfStandards : public CATBaseUnknown
{
  CATDeclareInterface;

	public:

	virtual HRESULT FindOrCreateFrom(const CATBaseUnknown* iOrigin, 
					 CATIStandard** oStandard, 
					 const IID &iIID=IID_CATIStandard, 
					 CATListPtrCATBaseUnknown** oOldRelatives=NULL, 
					 CATListPtrCATBaseUnknown** oNewRelatives=NULL) = 0;
	/* cas 1 :Factory = container de iOrigin
			=> *oStandard = iOrigin transforme en reference EXTERNE
	   cas 2 :Factory != container de iOrigin
			=> (2/1) si Factory contient deja une reference LOCALE (LocalRef) de iOrigin 
			creee apres la derniere modif de iOrigin : *oStandard = LocalRef ----> FIND
			=> (2/2) sinon : *oStandard = creation d'une reference LOCALE    ----> CREATE
	*/
	
	virtual HRESULT ListReferences(boolean local, CATListPtrCATIStandard** standards) = 0;
	// *standards : liste des references (locales ou non) contenues dans la Factory

	virtual HRESULT FindReferenceOf(const CATBaseUnknown* iObj, CATIStandard** oStand) = 0;
	// *oStand : reference (locale ou non) de iObj
};

CATDeclareHandler(CATIFactoryOfStandards,CATBaseUnknown);

#endif 
