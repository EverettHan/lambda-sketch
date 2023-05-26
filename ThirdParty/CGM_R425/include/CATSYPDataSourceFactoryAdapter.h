#pragma once

#include "VisuDialog.h"
#include "CATISYPDataSourceFactory.h"


class CATSYPDataSourceFactoryAdapter;

/** 
 * Adapter for CATISYPDataSourceFactory implementation. 
 */
class ExportedByVisuDialog CATSYPDataSourceFactoryAdapter : public CATISYPDataSourceFactory
{
  CATDeclareClass;

public:

  /** Constructor */
  CATSYPDataSourceFactoryAdapter();
  /** Destructor */
  virtual ~CATSYPDataSourceFactoryAdapter();

  // CATISYPDataSourceFactory interface implementation
  virtual CATSYPAbstractDataSource* BuildDataSource();
};

