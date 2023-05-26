#ifndef CATCellManifoldGroupSplitter_H
#define CATCellManifoldGroupSplitter_H

#include "CATCellManifoldGroupCarrier.h"
#include "AdvOpeInfra.h"

class CATIPGMTrimByThick;
class CATIPGMTopOperator;
class CATTrimByThick;


class ExportedByAdvOpeInfra CATCellManifoldGroupSplitter : public CATCellManifoldGroupCarrier
{
public:

  CATCGMDeclareManifoldAgent(CATCellManifoldGroupSplitter, CATCellManifoldGroupCarrier);

  // Constructor
  CATCellManifoldGroupSplitter(CATIPGMTrimByThick* iTBTOperator);
  CATCellManifoldGroupSplitter(CATTrimByThick* iTBTOperator);
  CATCellManifoldGroupSplitter();

  // Destructor
  virtual ~CATCellManifoldGroupSplitter();

  INLINE virtual CATCellManifoldGroupSplitter * GetAsCellManifoldGroupSplitter();

  virtual int GetPriority();
  virtual CATDeclarativeManifoldAgent* Clone();

protected:
  virtual HRESULT OrganizeImageByGroup(ListPOfCATCellManifoldGroup &iCellManifoldGroupsToCarry,
                                       ListPOfCATCellManifold &iParentLeavesImages, 
                                       CATListOfShort* iParentLeavesImagesType,
                                       ListPOfCATCellManifoldGroup & iParentSonsImages,
                                       ListPOfListPOfCATCellManifolds &oParentLeavesImagesByGroup, 
                                       ListPOfCATListOfShort &oParentLeavesImagesTypeByGroup,
                                       ListPOfListPOfCATCellManifoldGroups & oParentSonsImagesByGroup,
                                       CATCellManifoldGroupLayer* GroupLayer);
  HRESULT ComputeInitialDatas(CATCellManifoldGroupLayer* iGroupLayer,const CATListOfInt &iType);

private:
  CATBoolean CellManifoldMatch(ListPOfCATCellManifold &iList1, ListPOfCATCellManifold &iList2);
	int FindBestCellManifoldMatch(ListPOfCATCellManifold &iCMList,ListPOfListPOfCATCellManifolds &iListOfOtherTypeListOfCellManifolds);

	HRESULT SortParentLeavesImagesByGroupAndByType(ListPOfCATCellManifold &iParentLeavesImages,
		ListPOfListPOfCATCellManifolds &oParentLeavesImagesByGroupAndByType,
		int &oNbFinalGroups);

private:
  CATIPGMTopOperator* _TBTOperatorItf;
  CATTrimByThick* _TBTOperator;
  CATBoolean _InitialDataComputed,_SubdivisionOrderInJournal;
  ListPOfCATCellManifoldGroup _GroupsInInput;
  
	ListPOfListPOfCATCellManifolds _InputGroupsImagesInOutput;
	ListPOfListPOfCATCellManifolds _OutputCellsManifoldSortedByType;
  CATListOfInt _Types;
};

INLINE CATCellManifoldGroupSplitter * CATCellManifoldGroupSplitter::GetAsCellManifoldGroupSplitter()
{
  return this;
}
#endif
