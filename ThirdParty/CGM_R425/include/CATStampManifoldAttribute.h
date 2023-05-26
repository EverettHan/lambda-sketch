#ifndef CATStampManifoldAttribute_h
#define CATStampManifoldAttribute_h

// COPYRIGHT DASSAULT SYSTEMES  2013

#include "CATCGMNewArray.h"
#include "CATManifoldAttribute.h"
#include "CATPersistentCell.h"
#include "CATSoftwareConfiguration.h"
#include "ListPOfCATCellManifold.h"
#include "CATCell.h"
#include "ListPOfCATFace.h"

class CATCloneManager;
class CATTransfoManager;

class ExportedByPersistentCell CATStampManifoldAttribute : public CATManifoldAttribute
{
public:
  CATCGMDeclareAttribute (CATStampManifoldAttribute,CATManifoldAttribute);

  CATStampManifoldAttribute();
  //CATStampManifoldAttribute(ListPOfCATCellManifold iStampSupports[2]);
  ~CATStampManifoldAttribute();
  CATCGMNewClassArrayDeclare;      // Pool allocation

  CATCellManifoldGroupNavigator* CreateGroupNavigator(CATLiveBody * iLiveBody, const CATTopData & iTopData, CATCellManifoldGroup * iGroup) const;
  CATManifoldAttribute* CreateImageManifoldAttribute(CATLiveBody &iLiveBody, CATLISTP(CATManifoldAttribute) &iParentManifoldAttributes) const;
  CATManifoldAttribute* Clone(CATCloneManager& iCloneManager) const;
  void Move3D(CATTransfoManager& iTransfoManager);
  void GetColor(int &oR, int &oG, int &oB) const;

  CATStampManifoldAttribute* GetAsStampManifoldAttribute();
  virtual CATBoolean HaveSameType(CATManifoldAttribute &iOtherManifoldAttribute)const;
  virtual CATBoolean IsEquivalentTo(const CATManifoldAttribute &iOtherManifoldAttribute, CATGeoFactory * iFactory) const;

  virtual void Dump(CATCGMOutput& iWhereToWrite) const;
  void Stream(CATCGMStream & ioStream) const;
  void UnStream(CATCGMStream& ioStream);

  //------------------------------------------------------------
  // Stamp specific methods
  //------------------------------------------------------------
  //void GetStampSupports(ListPOfCATCellManifold oStampSupports[2]) const;
  //------------------------------------------------------------

protected:
  virtual CATManifoldAttribute * CreateImageAttribute(const CATLISTP(CATCellManifoldGroup) &iParentGroups, 
                                                      const CATCellManifoldGroup           &iImageCellManifoldGroup, 
                                                      CATCellManifoldsManager &iCellManifoldsManager) const;

  short CompareCells(const CATCell *iRefCell, const CATCell *iResultCell) const;
  CATBoolean CompareFaceLists(const ListPOfCATFace &iThisFaceList, const ListPOfCATFace &iOtherFaceList, CATBoolean iPrintDebugInfo = TRUE) const;
  CATBoolean CompareCMList(const ListPOfCATCellManifold &iThisList, const ListPOfCATCellManifold &iOtherList) const;

private:
  CATSoftwareConfiguration* GetConfig() const;
  CATSoftwareConfiguration* _Config;

  //------------------------------------------------------------
  // Stamp specific data
  //------------------------------------------------------------
  //ListPOfCATCellManifold _StampSupports[2];
  //------------------------------------------------------------
};

#endif

