#ifndef CATVisLayerFilter_H
#define CATVisLayerFilter_H
//
// CATIA Version 5 Release 15 Framework Visualization
// Copyright Dassault Systemes 2004

#include "CATVisFilter.h"

#include "SGInfra.h"
#include "CATVisFilterMergeMode.h"
//++ SGCAAPlan
class IVisSGLayerFilter;
//-- SGCAAPlan

class ExportedBySGInfra CATVisLayerFilter  : public CATVisFilter 
{
    CATDeclareVisFilter(CATVisLayerFilter);

public :
  //++ SGCAAPlan
  CATVisDeclarePublicInterfaceAdhesion(CATVisLayerFilter, IVisSGLayerFilter, CATVisLayerFilterIVisSGLayerFilterBOAImpl);
  //-- SGCAAPlan

	static CATVisLayerFilter* Create(const unsigned char filter[1024], CATVisFilterMergeMode iMode);

    void Modify(const unsigned char filter[1024], CATVisFilterMergeMode iMode);
    void UpdateLayerFilter(const unsigned char iCurrentFilter[1024]);
    void GetLayerFilter(unsigned char oFilter[1024], CATVisFilterMergeMode& oMode);

	virtual unsigned char GetType() const;
	
protected :
	CATVisLayerFilter(const unsigned char filter[1024], CATVisFilterMergeMode iMode);
	virtual ~CATVisLayerFilter();
};
#endif 
  
  
