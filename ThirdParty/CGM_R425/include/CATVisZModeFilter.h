//===================================================================
// COPYRIGHT Dassault Systemes 2019-06-21
//===================================================================
// CATVisZModeFilter.cpp
// Header definition of class CATVisZModeFilter
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2019-06-21 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATVisZModeFilter_H
#define CATVisZModeFilter_H

#include "CATVisFilter.h"
#include "SGInfra.h"

//-----------------------------------------------------------------------

class  ExportedBySGInfra CATVisZModeFilter: public CATVisFilter
{
  CATDeclareVisFilter(CATVisZModeFilter);

public:
  //
  // TODO: Add your methods for this class here.
  //
  static CATVisZModeFilter* Create(const int zmode);
  void SetZMode(const int zMode);
  void GetZMode(int &zMode) const;

  // Copy constructor and equal operator
  // -----------------------------------
  CATVisZModeFilter(CATVisZModeFilter &) = delete;
  CATVisZModeFilter& operator=(CATVisZModeFilter&) = delete;

protected:
  // Standard constructors and destructors
  // -------------------------------------
  CATVisZModeFilter(const int zmode);
  virtual ~CATVisZModeFilter();
};

//-----------------------------------------------------------------------

#endif
