#ifndef VISSGVISITOR_H
#define VISSGVISITOR_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "SGInfra.h"
#include "VisSGVisitorStrategyDefine.h"
#include "VisSGVisitorContext.h"
#include "VisDataType.h"
#include "CATBoolean.h"
#include "CATSysErrorDef.h"
class VisSGOperatingVisitor;
class IVisSGObject;
class IVisSGNode;
class IVisSGPrimitive;
class VisSGStrategy;
class VisSGPrimitiveItem;


/** 
 * Basic class of any Scene Graph Visit.
 * <b>Role</b>: This is the basic class that Scene Graph Visit has to C++ use.
 * It manages the SceneGraph visit and it is associated to an operating visitor 
 * that will do the operation to perfom on each element of the scene graph.
*/
class ExportedBySGInfra VisSGVisitor
{

public:

  VisSGVisitor();
  VisSGVisitor(VisSGOperatingVisitor* ipOperatingVisitor);
  ~VisSGVisitor();

  void AddRef(); 
  void Release();

  HRESULT SetOperatingVisitor(VisSGOperatingVisitor* ipOperatingVisitor);

  VisSGVisitorContext& GetVisitorContext();

  HRESULT GetStrategy(VisSGVisitorStrategyDefine& oStrategy) const;
  HRESULT SetStrategy(const VisSGVisitorStrategyDefine& iStrategy);

  // Visit Scene Graph
  HRESULT VisitSG(IVisSGObject& iObject);

  // Visit Scene Graph Nodes
  HRESULT BeginVisit(IVisSGNode& iNode, CATBoolean& oContinue);
  HRESULT Visit(IVisSGNode& iNode, CATBoolean& oContinue);
  HRESULT EndVisit(IVisSGNode& iNode);

  // Visit Scene Graph Primitives
  HRESULT BeginVisit(IVisSGPrimitive& iPrimitive, CATBoolean& oContinue);
  HRESULT Visit(IVisSGPrimitive& iPrimitive, CATBoolean& oContinue);
  HRESULT EndVisit(IVisSGPrimitive& iPrimitive);

  // Visit Scene Graph Tessellation
  HRESULT BeginVisit(VisSGPrimitiveItem& iPrimitiveItem, CATBoolean& oContinue);
  HRESULT Visit(VisSGPrimitiveItem& iPrimitiveItem, CATBoolean& oContinue);
  HRESULT VisitPoint(VisDataType iType, void* ipVertex1Position);
  HRESULT VisitLine(VisDataType iType, void* ipVertex1Position, void* ipVertex2Position);
  HRESULT VisitTriangle(VisDataType iType, void* ipVertex1Position, void* ipVertex2Position, void* ipVertex3Position);
  HRESULT EndVisit(VisSGPrimitiveItem& iPrimitiveItem);

private:

  VisSGVisitor(const VisSGVisitor& iVisitor);
  VisSGVisitor& operator = (const VisSGVisitor& iVisitor);

private:

  HRESULT PushMemento();
  HRESULT PopMemento();

  // Apply Strategy: continue or not the visit of a branch of scene graph according to strategy
  HRESULT BeginApplyStrategy(IVisSGNode& iNode, CATBoolean& oContinue);
  HRESULT ApplyStrategy(IVisSGNode& iNode, CATBoolean& oContinue);
  HRESULT EndApplyStrategy(IVisSGNode& iNode);
  HRESULT BeginApplyStrategy(IVisSGPrimitive& iPrimitive, CATBoolean& oContinue);
  HRESULT ApplyStrategy(IVisSGPrimitive& iPrimitive, CATBoolean& oContinue);
  HRESULT EndApplyStrategy(IVisSGPrimitive& iPrimitive);
  HRESULT BeginApplyStrategy(VisSGPrimitiveItem& iPrimitiveItem, CATBoolean& oContinue);
  HRESULT ApplyStrategy(VisSGPrimitiveItem& iPrimitiveItem, CATBoolean& oContinue);
  HRESULT ApplyStrategyOnPoint(VisDataType iType, void* ipVertex1Position, CATBoolean& oContinue);
  HRESULT ApplyStrategyOnLine(VisDataType iType, void* ipVertex1Position, void* ipVertex2Position, CATBoolean& oContinue);
  HRESULT ApplyStrategyOnTriangle(VisDataType iType, void* ipVertex1Position, void* ipVertex2Position, void* ipVertex3Position, CATBoolean& oContinue);
  HRESULT EndApplyStrategy(VisSGPrimitiveItem& iPrimitiveItem);

  // Data Conversion
  HRESULT ConvertComponent(VisDataType iInternalDataType, void* ipComponentValue, unsigned int iOffset, VisDataType iWantedDataType, void* opComponentValue) const;
  HRESULT SetComponent(VisDataType iDataType, unsigned int iComponentCount, void* ipComponent1Value, void* ipComponent2Value, void* ipComponent3Value, VisDataType& ioInternalDataType, void*& iopComponentValue) const;

private:

  // AddRef/Release
  unsigned int 	_nRef;

  // Operating Visitor
  VisSGOperatingVisitor* _pOperatingVisitor;

  // Strategy
  VisSGVisitorStrategyDefine _Strategy;
  VisSGStrategy** _pStrategyTab;
  unsigned int _StrategyCount;

  // Context
  VisSGVisitorContext _Context;
};

#endif
