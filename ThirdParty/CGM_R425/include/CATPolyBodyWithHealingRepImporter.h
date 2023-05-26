//=============================================================================
// COPYRIGHT Dassault Systemes 2022
//=============================================================================
//
// CATPolyBodyWithHealingRepImporter.h
//
//=============================================================================
// 2022-05-11 JXO
//=============================================================================

#ifndef CATPolyBodyWithHealingRepImporter_H
#define CATPolyBodyWithHealingRepImporter_H


#include "CATPolyVisuBuildOper.h"

#include "CATErrorDef.h" 
#include "CATBoolean.h"


class CATPolyBody;
class CATMapOfPtrToPtr;
class CATRep;

class ExportedByPolyVisuBuildOper CATPolyBodyWithHealingRepImporter
{
public:
  static HRESULT CleanRep(CATRep& iRep, CATPolyBody*& oPolyBody, CATMapOfPtrToPtr* oMapOfCellsToRepAndGPs);

protected:
  CATPolyBodyWithHealingRepImporter();
  virtual ~CATPolyBodyWithHealingRepImporter();
};
#endif 
