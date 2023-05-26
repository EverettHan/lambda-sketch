#ifndef CATVis2DModeFilter_H
#define CATVis2DModeFilter_H
//
// CATIA Version 5 Release 15 Framework Visualization
// Copyright Dassault Systemes 2004

#include "SGInfra.h"
#include "CATVisFilter.h"
#include "CATVis2DModeType.h"
class CATMathPlane;
//++ SGCAAPlan
class IVisSG2DModeFilter;
//-- SGCAAPlan

class ExportedBySGInfra CATVis2DModeFilter  : public CATVisFilter 
{
    CATDeclareVisFilter(CATVis2DModeFilter);

public :
  //++ SGCAAPlan
  CATVisDeclarePublicInterfaceAdhesion(CATVis2DModeFilter, IVisSG2DModeFilter, CATVis2DModeFilterIVisSG2DModeFilterBOAImpl);
  //-- SGCAAPlan
	
	//---------------------------------------------------------------------------
  // Create the filter, with the plane defined in the base of the children of 
  // the filtering bag rep, and the 2DMode type (see CATVis2DModeType.h)
  //---------------------------------------------------------------------------
	static CATVis2DModeFilter* Create(const CATMathPlane& i_plane, CATVis2DModeType i_2DModeType);
	
  //---------------------------------------------------------------------------
  // Set/Get the plane in the base of the children of the filtering bag rep.
  //---------------------------------------------------------------------------
  void SetPlane(const CATMathPlane& i_plane);
  const CATMathPlane& GetPlane() const;

  //---------------------------------------------------------------------------
  // Set/Get the 2Dmode type. the CATVis2DModeType.h
  //---------------------------------------------------------------------------
  void Set2DModeType(CATVis2DModeType i_2DModeType);
  CATVis2DModeType Get2DModeType() const;

protected :
	CATVis2DModeFilter(const CATMathPlane& i_plane, CATVis2DModeType i_2DModeType);
	virtual ~CATVis2DModeFilter();

};
#endif 
  
  
