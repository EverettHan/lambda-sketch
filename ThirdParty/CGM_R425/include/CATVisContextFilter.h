#ifndef CATVisContextFilter_H
#define CATVisContextFilter_H
//
// CATIA Version 5 Release 15 Framework Visualization
// Copyright Dassault Systemes 2004

#include "SGInfra.h"
#include "CATVisFilter.h"
#include "CATErrorDef.h"

#include "list.h"

class CATVisContextFilterValue;
class CATVisContextFilterPath;
class CATVisContextFilterStrategy;

class CATRepPath;
class CATPathElement;

//++ SGCAAPlan
class IVisSGContextFilter;
//-- SGCAAPlan

class ExportedBySGInfra CATVisContextFilter  : public CATVisFilter 
{
	CATDeclareVisFilter(CATVisContextFilter);

public :
	//++ SGCAAPlan
	CATVisDeclarePublicInterfaceAdhesion(CATVisContextFilter, IVisSGContextFilter, CATVisContextFilterIVisSGContextFilterBOAImpl);
	//-- SGCAAPlan

	static CATVisContextFilter* Create(CATVisContextFilterStrategy* iStrategy, unsigned int iNegativeVisibilityMode = 0);

	HRESULT AddPath(CATPathElement* iPath, const CATVisContextFilterValue& iValue) ; 
	HRESULT RemovePath(CATPathElement* iPath);
	void Empty();

	HRESULT IsPathVisible(CATPathElement* iPath);
	HRESULT IsPointsMadeVisible(CATPathElement* iPath); //UO4 TSK3716061+
	HRESULT IsAxesMadeVisible(CATPathElement* iPath);
	HRESULT IsWiresMadeVisible(CATPathElement* iPath); //UO4 TSK3716061-

	/**
	 * @brief Returns a pointer to the CATVisContextFilterPath associated to iIndex
	 * 
	 * @param iIndex 
	 * @param oPath [out, IUnknown#Release]
	 * @return HRESULT 
	 */
	HRESULT GetPath(size_t iIndex, CATVisContextFilterPath*& oPath) const;

	/** Returns the number of pathes added below this filter */
	size_t GetNumPaths() const;

	/** Returns 1 if we are in negative visibility mode, 0 otherwise */
	unsigned int GetNegativeVisibilityMode() const;

	/** Returns the strategy internally used by the filter */
	HRESULT GetStrategy(CATVisContextFilterStrategy*& oStrategy) const;

	void Initialize();

protected:
	CATVisContextFilter(CATVisContextFilterStrategy* iStrategy, unsigned int iNegativeVisibilityMode);
	virtual ~CATVisContextFilter();
};
#endif 
