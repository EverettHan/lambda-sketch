/* -*-C++-*- */
#ifndef CATCellManifoldStampNavigatorInterface_H
#define CATCellManifoldStampNavigatorInterface_H
// ----------------------------------------------------------------------------------------------//
// COPYRIGHT DASSAULT SYSTEMES 2013
// ----------------------------------------------------------------------------------------------//
#include "CATCellManifoldGroupNavigator.h"
#include "CATGMModelInterfaces.h"

class CATLiveBody;
class CATCellManifoldGroup;

class ExportedByCATGMModelInterfaces CATCellManifoldStampNavigatorInterface : public CATCellManifoldGroupNavigator
{
public:

  // Constructor
  CATCellManifoldStampNavigatorInterface();

  // Destructor
  virtual ~CATCellManifoldStampNavigatorInterface();

  //------------------------
  // Surcharge du new/delete
  //------------------------
  CATCGMNewClassArrayDeclare;      // Pool allocation

  CATCellManifoldStampNavigatorInterface * GetAsStampNavigatorInterface();

  virtual HRESULT GetNetworkGroup(CATCellManifoldGroup *& oNetworkGroup) const = 0;

  virtual HRESULT GetAllCellManifolds(ListPOfCATCellManifold & oCellManifolds) const = 0;


  virtual CATLiveBody& GetLiveBody() const = 0;

protected:
  void Dump(CATCGMOutput& Output);
};

#endif
