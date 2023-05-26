#ifndef CATDRepNavigator2_H
#define CATDRepNavigator2_H

#include "AdvOpeInfra.h"
#include "CATDRepNavigator.h"


class ExportedByAdvOpeInfra CATDRepNavigator2 : public CATDRepNavigator
{
public:
  CATCGMNewClassArrayDeclare;      // Pool allocation
  // Constructor
  CATDRepNavigator2(const CATTopData &iData, CATLiveBody* iLiveBody); 

  // Destructor
  virtual ~CATDRepNavigator2();

  // @nocgmitf
  CATBoolean IsPatternBaseRibbon(CATCellManifold * iCM);

protected:
  virtual CATCellManifoldPatternNavigator * CreateCATCellManifoldPatternNavigator(const CATTopData &iData, CATLiveBody* iLiveBody, CATCellManifoldGroup* iNetworkGroup); 
  virtual CATCellManifoldPatternNavigator * CreateCATCellManifoldPatternNavigator(CATDRepNavigator * iDrepNavigator, CATCellManifoldGroup* iNetworkGroup); 
  virtual CATCellManifoldPatternNavigator * CreateCATCellManifoldPatternNavigator(CATCellManifoldPatternNavigator * iPatternNavigator);

private:
  void CreatePatternBaseRibbonCMHT();
 CATCGMHashTable* _PatternBaseRibbonCMHT;

};

#endif
