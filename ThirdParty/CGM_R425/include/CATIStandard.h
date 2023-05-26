/* -*-c++-*- */
#ifndef CATIStandard_h
#define CATIStandard_h
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 1999
//-----------------------------------------------------------------------------
//
// Interface CATIStandard
// 
//-----------------------------------------------------------------------------
// Usage Notes:
//
// Information on Standards (same interface for internal as well as external Standards)
// Implemented by extensions of CATSpecObject and CATEarlySpecAttr
//
//-----------------------------------------------------------------------------
// Created NLL - Aug 99   
// Modified cwz - Oct 99
//-----------------------------------------------------------------------------

/**
 * @level Private
 * @usage U3
 */

#include "AD0XXBAS.h"
#include "CATBaseUnknown.h"

class CATUnicodeString;
class CATTime;

extern ExportedByAD0XXBAS IID IID_CATIStandard ;

class ExportedByAD0XXBAS CATIStandard : public CATBaseUnknown
{

	public:  CATDeclareInterface;

	//HRESULT = E_UNEXPECTED pour tous les CATSpecObject / CATEarlySpecAttr non standardises !

	virtual HRESULT GetOrigin (const GUID& interfaceID, CATBaseUnknown** oOrigin) const = 0;
	// si reference locale : *oOrigin : reference de this
	// si reference externe : *oOrigin = this

	virtual HRESULT GetOriginContext (CATUnicodeString* Identifier) const = 0;
	//*Identifier : StorageName du document contenant l'origine

	virtual HRESULT GetCreationTime(CATTime* time) const = 0;
	//*time : date de creation

	virtual HRESULT GetLastModifTime(CATTime* time) const = 0;
	//*time : date de derniere modif

	virtual HRESULT IsSynchronized() const = 0;
	//S_OK si date de creation(this) >= date de derniere modif(origine) - sinon S_FALSE

	virtual HRESULT IsLocal() const = 0;
	//S_OK pour reference locale (environnement design)
	//S_FALSE pour reference externe (environnement catalogue)

	virtual HRESULT Reset() const = 0;
};

CATDeclareHandler(CATIStandard,CATBaseUnknown);

#endif 




/* 9908 nll
  virtual HRESULT GetOrigin(CATIStandard** oOrigin) const =0;

  virtual HRESULT IsSynchronized() const=0;

  virtual HRESULT IsExternal() const=0;

  virtual HRESULT CreateExternalStandard(const CATIContainer* iTargetCont,
					 CATIStandard** oExternalStandard)=0;
*/
