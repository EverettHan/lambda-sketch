//===================================================================
// COPYRIGHT Dassault Systemes 2017/12/04
//===================================================================
// CATOmyGanttDiagramGenerator.cpp
// Header definition of class CATOmyGanttDiagramGenerator
//===================================================================
//
// Usage notes:
// Generates a Gantt Diagram with the given xMQL Request statistics.
// Useful to have a view of which requests have been executed in parallel / sequential.
// Useful for cloud setups, with high network latency.
//
//===================================================================
//  2017/12/04 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATOmyGanttDiagramGenerator_H
#define CATOmyGanttDiagramGenerator_H

#include "CATOmyGanttDiagram.h"
#include "CATOmxUTF8String.h"
#include "CATOmxJsonObject.h"
#include "CATOmxJsonItem.h"
#include "CATOmyGanttDiagramSerie.h"

class ExportedByCATOmyGanttDiagram CATOmyGanttDiagramGenerator
{
public:
  CATOmyGanttDiagramGenerator(const CATOmxJsonObject& iStatistics, const CATOmxJsonObject& iConfig);
  virtual ~CATOmyGanttDiagramGenerator();

  HRESULT Generate();

private:
  CATOmyGanttDiagramGenerator (CATOmyGanttDiagramGenerator &);
  CATOmyGanttDiagramGenerator& operator=(CATOmyGanttDiagramGenerator&);

  HRESULT _CheckConfig();
  HRESULT _ParseStatistics(const CATOmxJsonObject& iStatistic, CATOmyGanttDiagramSerie& ioDiagramSerie);
  HRESULT _GetFieldValue(const CATOmxJsonObject& iConfig, const CATUnicodeString& iConfigFieldName, const CATUnicodeString& iDefaultFieldName, const CATOmxJsonObject& iStatistics, CATOmxJsonItem& oValue);

  CATOmxJsonObject _Config;
  CATOmxJsonObject _Statistics;
};

#endif