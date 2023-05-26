#ifndef CATCellManifoldStampNavigator_H
#define CATCellManifoldStampNavigator_H

#include "CATPersistentCell.h"

#include "CATCellManifoldStampNavigatorInterface.h"
#include "CATCellManifoldGroupNavigator.h"
#include "CATDRepNavigator.h"
#include "CATStampManifoldAttribute.h"
#include "ListPOfCATCellManifold.h"
#include "ListPOfCATCellManifoldGroup.h"

class CATLiveBody;
class CATCellManifold;
class CATCellManifoldGroup;

class ExportedByPersistentCell CATCellManifoldStampNavigator : public CATCellManifoldStampNavigatorInterface
{
public:

  // Constructor
  CATCellManifoldStampNavigator();
  CATCellManifoldStampNavigator(CATLiveBody * iLiveBody, CATCellManifoldGroup * iNetworkGroup);
  CATCellManifoldStampNavigator(CATDRepNavigator * iDrepNavigator, CATCellManifoldGroup * iNetworkGroup);
  CATCellManifoldStampNavigator(CATCellManifoldStampNavigator *iStampNavigator);

  //-------------------------------------------------------------------------------------------------------
  // Surcharge du new/delete
  //-------------------------------------------------------------------------------------------------------
  // Attribute Declaration
  CATCGMDeclareManifoldNavigator(CATCellManifoldStampNavigator, CATCellManifoldStampNavigatorInterface);
  //CATCGMNewClassArrayDeclare;      // Pool allocation

  // Destructor
  virtual ~CATCellManifoldStampNavigator();

  CATCellManifoldStampNavigator * GetAsStampNavigator();

  //Interface methods
  virtual HRESULT GetNetworkGroup(CATCellManifoldGroup *& oNetworkGroup) const;

  virtual HRESULT GetAllCellManifolds(ListPOfCATCellManifold & oCellManifolds) const;
  

  INLINE virtual CATLiveBody& GetLiveBody() const;

  //-------------------------------------------------
  //   Stream / Unstream 
  //-------------------------------------------------
  void Stream(CATCGMStream& ioStr, CATGeoFactory * iFactory) const;
  void UnStream(CATCGMStream& ioStr, CATGeoFactory * iFactory);


protected:

  void Init(CATLiveBody * iLiveBody, CATCellManifoldGroup * iNetworkGroup);
  void GetStampManifoldAttribute(CATStampManifoldAttribute *& oStampAttr);

private:

  CATLiveBody * _LiveBody;
  CATCellManifoldGroup * _NetworkGroup;
  CATStampManifoldAttribute * _StampAttr;
};

INLINE CATLiveBody& CATCellManifoldStampNavigator::GetLiveBody() const
{
  return *_LiveBody;
}

// ---------------------------------------
// CATCreateCellManifoldStampNavigator
// ---------------------------------------
ExportedByPersistentCell CATCellManifoldStampNavigator * CATCreateCellManifoldStampNavigator(CATLiveBody * iLiveBody, CATCellManifoldGroup * iNetworkGroup);

#endif
