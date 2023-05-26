#ifndef CATVisViewportFilter_H
#define CATVisViewportFilter_H
//
// CATIA Version 5 Release 15 Framework Visualization
// Copyright Dassault Systemes 2004

#include "CATVisFilter.h"

class ExportedBySGInfra CATVisViewportFilter  : public CATVisFilter 
{
  CATDeclareVisFilter(CATVisViewportFilter);

public :
  static CATVisViewportFilter* Create(const int i_x, const int i_y, const int i_dx, const int i_dy);
  void SetViewport (const int i_x, const int i_y, const int i_dx, const int i_dy);
  void GetViewport (int& o_x, int& o_y, int& o_dx, int& o_dy);

protected :
  CATVisViewportFilter(const int i_x, const int i_y, const int i_dx, const int i_dy);
  virtual ~CATVisViewportFilter();
};
#endif 


