#ifndef CATVisAlphaFilter_H
#define CATVisAlphaFilter_H
//
// CATIA Version 5 Release 15 Framework Visualization
// Copyright Dassault Systemes 2004

#include "CATVisFilter.h"

class ExportedBySGInfra CATVisAlphaFilter : public CATVisFilter 
{
    CATDeclareVisFilter(CATVisAlphaFilter);
public :
    static CATVisAlphaFilter* Create(const float i_alpha);
    void SetAlphaFilterValue (const float i_alpha);
    void GetAlphaFilterValue ( float& o_alpha);

protected :
  CATVisAlphaFilter(const float i_alpha);
  virtual ~CATVisAlphaFilter();
};
#endif 
