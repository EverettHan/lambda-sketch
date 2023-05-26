//===================================================================
// COPYRIGHT Dassault Systemes 2018/06/13
//===================================================================
// CATPLMNLVGraphBuilder.cpp
// Header definition of class CATPLMNLVGraphBuilder
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2018/06/13 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATPLMNLVGraphBuilder_H
#define CATPLMNLVGraphBuilder_H

#include "CATPLMServicesNLV.h"
#include "CATPLMNLVGraph.h"
#include "CATOmxJsonArray.h"

class ExportedByCATPLMServicesNLV CATPLMNLVGraphBuilder
{
public:
  CATPLMNLVGraphBuilder();
  virtual ~CATPLMNLVGraphBuilder();

  /*
  * Adds new nodes in the graph as JsonObject.
  */
  HRESULT AddNodes(const CATOmxJsonArray& iNodes);

  /*
  * Adds new node in the graph as JsonObject.
  */
  HRESULT AddNode(const CATOmxJsonObject& iNode);

  /*
  * Returns the built graph.
  * The returned graph is addrefed.
  * Do not forget to release it.
  */
  HRESULT Build(CATPLMNLVGraph*& oGraph);

private:
  CATPLMNLVGraphBuilder(CATPLMNLVGraphBuilder &);
  CATPLMNLVGraphBuilder& operator=(CATPLMNLVGraphBuilder&);

  HRESULT _BuildMajorEdges(CATPLMNLVGraphNode& iDescendant, CATOmxJsonArray& iAncestors);
  HRESULT _BuildMinorEdges(CATPLMNLVGraphNode& iDescendant, CATOmxJsonArray& iSecondaries);

  CATOmxSR<CATPLMNLVGraph> _spGraph;
};

#endif