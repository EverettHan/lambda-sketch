#ifndef CATCellManifoldGroupSplitterUtilitiesAdvBridge_H
#define CATCellManifoldGroupSplitterUtilitiesAdvBridge_H

#include "CATCGMNewArray.h"
#include "AdvOpeInfra.h"
#include "CATCellManifoldGroupSplitterUtilitiesBridge.h"
#include "ListPOfCATCellManifoldGroup.h"
#include "ListPOfCATCellManifold.h"
#include "CATListOfShort.h"
#include "ListPOfListPOfCATCellManifolds.h"
#include "ListPOfCATListOfShort.h"
#include "CATCellManifoldGroupLayer.h"

class CATCellManifoldGroupCarrier;
class CATCellManifoldGroupSplitterUtilities;


class ExportedByAdvOpeInfra CATCellManifoldGroupSplitterUtilitiesAdvBridge : public CATCellManifoldGroupSplitterUtilitiesBridge
{
public:
  CATCGMNewClassArrayDeclare;      // Pool allocation

  CATCellManifoldGroupSplitterUtilitiesAdvBridge(CATCellManifoldGroupCarrier * iCellManifoldGroupCarrier);

  virtual ~CATCellManifoldGroupSplitterUtilitiesAdvBridge();

  virtual HRESULT OrganizeImageByGroup(ListPOfCATCellManifoldGroup    & iCellManifoldGroupsToCarry,
                                       ListPOfCATCellManifold         & iParentLeavesImages, 
                                       CATListOfShort                 * iParentLeavesImagesType,
                                       ListPOfListPOfCATCellManifolds & oParentLeavesImagesByGroup, 
                                       ListPOfCATListOfShort          & oParentLeavesImagesTypeByGroup,
                                       CATCellManifoldGroupLayer      * iGroupLayer);

private:

  CATCellManifoldGroupSplitterUtilities * _Util;
};

extern "C" ExportedByAdvOpeInfra CATCellManifoldGroupSplitterUtilitiesAdvBridge * CATCreateCellManifoldGroupSplitterUtilitiesAdvBridge(CATCellManifoldGroupCarrier * iCellManifoldGroupCarrier);

#endif 

