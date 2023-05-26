//===================================================================
// COPYRIGHT Dassault Systemes 2022/03/18
//===================================================================

#ifndef CATISYPDataSourceFactory_H
#define CATISYPDataSourceFactory_H

#include "VisuDialog.h"
#include "CATBaseUnknown.h"

class CATSYPAbstractDataSource;

extern ExportedByVisuDialog  IID IID_CATISYPDataSourceFactory;

/**
 * Interface to fetch or modify data inside a model of a model/view layout (e.g: CATVidCtlAbstractItemsView, CATListView, CATTreeView) 
 */
class ExportedByVisuDialog CATISYPDataSourceFactory : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  virtual CATSYPAbstractDataSource* BuildDataSource() = 0;
 };

CATDeclareHandler( CATISYPDataSourceFactory, CATBaseUnknown );

#endif
