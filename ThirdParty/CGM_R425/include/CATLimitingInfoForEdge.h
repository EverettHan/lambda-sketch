#ifndef CATLimitingInfoForEdge_H
#define CATLimitingInfoForEdge_H


#include "ExportedByRIBLight.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATVertex.h"
#include "CATBoolean.h"

class CATBody;
class CATShell;
class CATBlendVertexSpec;
class CATDynEdgeFilletRibbon;

enum CATLimitingType{ LimitingForBlendVertex, LimitingForDeadLock, LimitingTypeUnknown };

class ExportedByRIBLight CATLimitingInfoForEdge  
{
public:

  CATLimitingInfoForEdge( CATBody *iBody, const ListPOfCATEdge & iSpecEdges );
  ~CATLimitingInfoForEdge();

  void SetPartingShell( CATShell *iPartingShell, int iNumber );

  void SetSpecForBlendVertex( CATBlendVertexSpec *iSpecBV );
  void SetSpecForDeadLock( CATDynEdgeFilletRibbon *iSpecDL );
  void SetRibbonEdges(const ListPOfCATEdge &iRibbonEdges );
  void SetKeptEdges( CATEdge *iEdgeToKeep );
  void SetKeptEdges( const ListPOfCATEdge &iKeptEdges );
  void SetVertexToSimplify( CATVertex *iVertex );
  void SetUsed();
  
  void ReplaceSpecEdges(const ListPOfCATEdge &iNewSpecEdges );
  void ReplaceRibbonEdges(const ListPOfCATEdge &iNewRibEdges );
  void RemoveDuplicatesOfSpecEdges();
  void RemoveDuplicatesOfRibbonEdges();

  CATLimitingType GetType();
  CATBody* GetBody();
  void* GetSpecForBV();
  void* GetSpecForDL();
  const ListPOfCATEdge &GetSpecEdges();
  int GetNumberOfSpecEdges();
  const ListPOfCATEdge &GetRibbonEdges();
  int GetNumberOfRibbonEdges();
  CATBoolean IsUsed();
  const ListPOfCATEdge &GetKeptEdges();

  int GetNumberPartingShell();

  const ListPOfCATVertex &GetVertexToSimplify();

// ### CPT : after having changed impacted sources!!! private:
  CATBody *_Body;
  ListPOfCATEdge _SpecEdges;
  ListPOfCATEdge _RibbonEdges;
  CATShell *_PartingShell;
  int _NoPartingShell;
  void *_SpecForBV; // For Vertex Blend configuration
  void *_SpecForDL; // For Deadlock configurations
  ListPOfCATVertex _VertexToSimplify;  
  ListPOfCATEdge _EdgesToKeep;
  CATBoolean _Used;
};

#endif
