#ifndef CATCellManifoldPatternNavigator2_H
#define CATCellManifoldPatternNavigator2_H

#include "CATCellManifoldPatternNavigator.h"
#include "AdvOpeInfra.h"

class CATGeoFactory;
class CATSoftwareConfiguration;
class CATDeclarativeManifold;
class CATLiveBody;

class ExportedByAdvOpeInfra CATCellManifoldPatternNavigator2 : public CATCellManifoldPatternNavigator
{

public:

  // Constructor
  CATCellManifoldPatternNavigator2(const CATTopData &iData, CATLiveBody* iLiveBody, CATCellManifoldGroup* iNetworkGroup); 
  CATCellManifoldPatternNavigator2(CATDRepNavigator * iDrepNavigator, CATCellManifoldGroup* iNetworkGroup); 
  CATCellManifoldPatternNavigator2(CATCellManifoldPatternNavigator * iPatternNavigator);

  // DO NOT USE : For Unstream Only
  CATCellManifoldPatternNavigator2();

  // Destructor
  virtual ~CATCellManifoldPatternNavigator2();

  // Regarde si la reference a un fillet a la base
  // @nocgmitf
  //-------------------------------------------------------------------------------------
  CATBoolean HasFilletOnSupport();

  // @nocgmitf
  HRESULT GetRibbonsOnSupportReferenceDM(CATLISTP(CATDeclarativeManifold) & oRibbonOnSupportReferenceDM); 
  
  // @nocgmitf
  HRESULT GetBaseRibbonCellManifolds(CATLISTP(CATCellManifold) &oBaseRibbonCellManifolds);

  // @nocgmitf
  virtual CATCellManifoldPatternNavigator2 * IsCATCellManifoldPatternNavigator2();

  static CATBoolean HasFreeSupportEdge(CATGeoFactory & iFactory, CATSoftwareConfiguration & iConfig, CATDeclarativeManifold & iBoneFillet, CATLiveBody & iLiveBody, ListPOfCATEdge & oFreeEdgeList);

};

#endif
