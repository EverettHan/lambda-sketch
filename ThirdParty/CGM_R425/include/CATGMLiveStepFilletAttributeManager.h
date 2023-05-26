#ifndef CATGMLiveStepFilletAttributeManager_H
#define CATGMLiveStepFilletAttributeManager_H
//===================================================================
// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATGMLiveStepFilletAttributeManager.h
// 		
//===================================================================
//  Oct 2008  Creation: CWM
//===================================================================

#include "CATCGMNewArray.h"

#include "ListPOfCATCell.h"
#include "CATDataType.h"

class CATGeoFactory;
class CATSoftwareConfiguration;

class CATCGMAttribute;
class CATCGMAttrId;
class CATCell;

class CATGMLiveStepFilletAttributeManager
{
public:
  CATCGMNewClassArrayDeclare;      // Pool allocation

  CATGMLiveStepFilletAttributeManager(CATCGMAttrId* iAttrId);
  virtual ~CATGMLiveStepFilletAttributeManager();

  CATLONG32 PutAttributeOnCell(CATCell *iCell, CATCGMAttribute * iAttribute);

  void ReleaseAttributes();

protected:
  void AddCATCell(CATCell *iCell);
  virtual void ReleaseOneAttribute(CATCell *iCell, CATCGMAttribute * iAttribute);
  inline CATCGMAttrId* GetAttrId();

private:
  CATCGMAttrId* _AttrId;
  ListPOfCATCell _Cells;
};

inline CATCGMAttrId* CATGMLiveStepFilletAttributeManager::GetAttrId()
{
  return _AttrId;
}

#endif
