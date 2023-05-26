#ifndef CATCompClassicRepDefaultImpl_h_
#define CATCompClassicRepDefaultImpl_h_

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS
#include "CATCompClassicRep.h"
#include "CATSGComposite.h"
#include "CATSGCompositeHost.h"

class CATRep;
class CAT3DBoundingSphere;

class ExportedBySGComposites CATCompClassicRepDefaultImpl : public CATSGCompositeHost1<CATCompClassicRep, CATSGComposite>
{
public:
	CATCompClassicRepDefaultImpl();
	virtual ~CATCompClassicRepDefaultImpl();


	virtual unsigned int GetSizeInBytes(const int iIncludeStructuralSize = 1);

	virtual HRESULT		SetRep(CATRep* iRep, CATBoolean iRelease = TRUE);
	virtual CATRep* 	  GetRep();
    virtual const CATRep* GetRep() const;

	virtual HRESULT		GetBoundingSphere(CAT3DBoundingSphere& oBoundingSphere) const;

private:
	CATRep* 	_rep;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // CATCompClassicRepDefaultImpl_h_
