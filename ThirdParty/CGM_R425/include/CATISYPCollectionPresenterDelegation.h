#ifndef _CATISYPCollectionPresenterDelegation_H
#define _CATISYPCollectionPresenterDelegation_H

#include <CATBaseUnknown.h>
#include <IntroInfra.h>

class CATISYPIntrospectable_var;

extern ExportedByIntroInfra IID IID_CATISYPCollectionPresenterDelegation;

/** @ingroup groupCIDIntrospection
 * Interface used for NLS building after graphic sypstyle navigation.
 * Interface implemented by components that want provide elements different from Collection/Presenter.
 */
class ExportedByIntroInfra CATISYPCollectionPresenterDelegation : public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	 * Gets delegation object   
   * @return the object from which collection/presenter will be searched. (Instead of being searched from "this" object when this interface is not implemented).
	 */
	virtual CATISYPIntrospectable_var GetDelegationObject() = 0;
	
};
CATDeclareHandler( CATISYPCollectionPresenterDelegation, CATBaseUnknown );

#endif

