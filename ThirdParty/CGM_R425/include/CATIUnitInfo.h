/**
 * @level Protected
 * @usage U5
 */
/* -*-c++-*- */
#ifndef CATIUnitInfo_h
#define CATIUnitInfo_h

#include "AC0CATPL.h"
#include "CATBaseUnknown.h"


extern ExportedByAC0CATPL IID IID_CATIUnitInfo ;


class ExportedByAC0CATPL CATIUnitInfo : public CATBaseUnknown
{
  CATDeclareInterface;

  public:
  virtual double PersistentUnit () const = 0; 
};


CATDeclareHandler(CATIUnitInfo, CATBaseUnknown);

#endif 
