#ifndef CATCellManifoldGroupSplitterUtilities_H
#define CATCellManifoldGroupSplitterUtilities_H

#include "AdvOpeInfra.h"
#include "CATCGMNewArray.h"
#include "ListPOfCATCellManifoldGroup.h"
#include "ListPOfCATCellManifold.h"
#include "ListPOfListPOfCATCellManifolds.h"
#include "ListPOfListPOfCATCellManifoldGroups.h"
#include "ListPOfCATListOfShort.h"
#include "CATBoolean.h"
#include "CATListOfInt.h"
#include "CATCellManifoldGroupCarrier.h"

class CATCellManifoldGroupLayer;
class CATXBooleanTrue;
class CATTrimByThick;

class ExportedByAdvOpeInfra CATCellManifoldGroupSplitterUtilities
{
public:
  CATCGMNewClassArrayDeclare;      // Pool allocation

  CATCellManifoldGroupSplitterUtilities(CATCellManifoldGroupCarrier * iCellManifoldGroupCarrier);
  virtual ~CATCellManifoldGroupSplitterUtilities();

  HRESULT OrganizeImageByGroup(ListPOfCATCellManifoldGroup &iCellManifoldGroupsToCarry,
                               ListPOfCATCellManifold &iParentLeavesImages, 
                               CATListOfShort* iParentLeavesImagesType,
                               ListPOfListPOfCATCellManifolds &oParentLeavesImagesByGroup, 
                               ListPOfCATListOfShort &oParentLeavesImagesTypeByGroup,
                               CATCellManifoldGroupLayer* GroupLayer);

private:
  HRESULT ComputeInitialDatas(CATCellManifoldGroupLayer* iGroupLayer,const CATListOfInt &iType);
  CATBoolean CellManifoldMatch(ListPOfCATCellManifold &iList1, ListPOfCATCellManifold &iList2);
	int FindBestCellManifoldMatch(ListPOfCATCellManifold &iCMList,ListPOfListPOfCATCellManifolds &iListOfOtherTypeListOfCellManifolds);

	HRESULT SortParentLeavesImagesByGroupAndByType(ListPOfCATCellManifold &iParentLeavesImages,
		ListPOfListPOfCATCellManifolds &oParentLeavesImagesByGroupAndByType,
		int &oNbFinalGroups);

private:
  CATBoolean _InitialDataComputed,_SubdivisionOrderInJournal;
  ListPOfCATCellManifoldGroup _GroupsInInput;
  
	ListPOfListPOfCATCellManifolds _InputGroupsImagesInOutput;
	ListPOfListPOfCATCellManifolds _OutputCellsManifoldSortedByType;
  CATListOfInt _Types;

  CATIPGMTopOperator* _TBTOperatorItf;
  CATTrimByThick    * _TBTOperator;

  CATCellManifoldGroupCarrier * _CellManifoldGroupCarrier;
};
#endif
