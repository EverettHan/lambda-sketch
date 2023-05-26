#ifndef VISSGVISITORCONTEXT_H
#define VISSGVISITORCONTEXT_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "SGInfra.h"
#include "VisAttributeID.h"
#include "VisDataType.h"
#include "CATBoolean.h"
#include "CATSysErrorDef.h"
#include "VisVertexComponent.h"
#include "VisSGVisitorStrategyDefine.h"
class IVisSGFilter;
class CAT3DBoundingSphere;
class CAT4x4Matrix;
class VisSGVisitorMemento;
class VisSGStrategy;


/** 
 * Basic class of context of Scene Graph Visit.
 * <b>Role</b>: This is the class that Scene Graph Visit has to C++ use to define its current context.
 * It manages the SceneGraph visit context for current element of the scene graph.
*/
class ExportedBySGInfra VisSGVisitorContext
{
  friend class VisSGVisitor;
  friend class VisSGVisitorMemento;
  friend class TestVisSGVisitorContext;

public:

  VisSGVisitorContext();
  ~VisSGVisitorContext();

  HRESULT GetStrategy(VisSGVisitorStrategyDefine& oStrategy) const;
  HRESULT SetStrategy(const VisSGVisitorStrategyDefine& iStrategy, VisSGStrategy** ipStrategyTab, unsigned int iStrategyCount);

  // Visit Scene Graph Node Attributes
  HRESULT GetAttribute(const VisAttributeID iAttributeID, const VisDataType iType, void *oValue) const;
  HRESULT SetAttribute(const VisAttributeID iAttributeID, const VisDataType iType, void *iValue);

  HRESULT AddFilter(IVisSGFilter& iFilter);
  HRESULT RemoveFilter(IVisSGFilter& iFilter);

  HRESULT GetLocalToGlobalMatrix(CAT4x4Matrix& oMatrix) const;

  HRESULT GetBoundingElement(CAT3DBoundingSphere& oBoundingElement) const;
  HRESULT SetBoundingElement(const CAT3DBoundingSphere& iBoundingElement);

  // Visit Scene Graph Primitive Attributes
  HRESULT GetId(unsigned int& oID) const;
  HRESULT SetId(unsigned int iID);

  // Visit Scene Graph Tesselated Geometry Attributes
  enum VisitorPrimitiveItemType
  {
    VisitorPrimitiveItemType_None     = 0,
    VisitorPrimitiveItemType_Point    = 1,
    VisitorPrimitiveItemType_Line     = 2,
    VisitorPrimitiveItemType_Triangle = 3
  };  
  HRESULT SetPrimitiveItemType(VisitorPrimitiveItemType iPrimitiveItemType);
  HRESULT GetPointComponent(VisVertexComponent iComponent, VisDataType iType, void* opVertex1Value) const;
  HRESULT SetPointComponent(VisVertexComponent iComponent, VisDataType iType, void* ipVertex1Value);
  HRESULT GetLineComponent(VisVertexComponent iComponent, VisDataType iType, void* opVertex1Value, void* opVertex2Value) const;
  HRESULT SetLineComponent(VisVertexComponent iComponent, VisDataType iType, void* ipVertex1Value, void* ipVertex2Value);
  HRESULT GetTriangleComponent(VisVertexComponent iComponent, VisDataType iType, void* opVertex1Value, void* opVertex2Value, void* opVertex3Value) const;
  HRESULT SetTriangleComponent(VisVertexComponent iComponent, VisDataType iType, void* ipVertex1Value, void* ipVertex2Value, void* ipVertex3Value);

private:

  VisSGVisitorContext(const VisSGVisitorContext& iVisitorContext);
  VisSGVisitorContext& operator = (const VisSGVisitorContext& iVisitorContext);

private:

  // Manage memento for BeginVisitonOperatingVisitor, BeginApplyStrategy, PushMemento
  HRESULT GetBeginVisitOnOperatingVisitorUse(CATBoolean& oBeginVisitOnOperatingVisitorUse) const;
  HRESULT SetBeginVisitOnOperatingVisitorUse(CATBoolean iBeginVisitOnOperatingVisitorUse);

  HRESULT GetBeginApplyStrategyUse(CATBoolean& oBeginApplyStrategyUse) const;
  HRESULT SetBeginApplyStrategyUse(CATBoolean iBeginApplyStrategyUse);

  HRESULT GetPushMementoUse(CATBoolean& oPushMementoUse) const;
  HRESULT SetPushMementoUse(CATBoolean iPushMementoUse);

  // Manage memento
  HRESULT PushMemento();
  HRESULT PopMemento();

  // Data Conversion
  HRESULT ConvertData(VisDataType iInternalDataType, void* ipInternalDataValue, unsigned int iOffset, VisDataType iWantedDataType, void* opDataValue) const;
  HRESULT SetData(VisDataType iDataType, void* ipDataValue, VisDataType& ioInternalDataType, void*& iopInternalDataValue) const;
  HRESULT SetData(VisDataType iDataType, void* ipDataValue, VisDataType& ioInternalDataType, void*& iopInternalDataValue, unsigned char& oInternalDataModification) const;
  HRESULT SetData(VisDataType iDataType, unsigned int iDataCount, void* ipData1Value, void* ipData2Value, void* ipData3Value, VisDataType& ioInternalDataType, void*& iopInternalDataValue) const;
  HRESULT SetData(VisDataType iDataType, unsigned int iDataCount, void* ipData1Value, void* ipData2Value, void* ipData3Value, VisDataType& ioInternalDataType, void*& iopInternalDataValue, unsigned char& oInternalDataModification) const;

private:

  // Strategy
  VisSGVisitorStrategyDefine _Strategy;
  VisSGStrategy** _pStrategyTab;
  unsigned int _StrategyCount;

  // Memento
  VisSGVisitorMemento* _pMemento;
  VisSGVisitorMemento** _pMementoTab;
  unsigned int _MementoTabSize;

  // Operating Visitor Modes
  CATBoolean _BeginVisitOnOperatingVisitorUse;

  // Visitor Modes
  CATBoolean _BeginApplyStrategyUse;
  CATBoolean _PushMementoUse;

  // Node Attributes
  VisDataType _AttributeDataTypeTab[VIS_ATTRIBURE_ID_COUNT];
  void* _pAttributeTab[VIS_ATTRIBURE_ID_COUNT];
  unsigned int _InheritanceMode;
  CAT4x4Matrix* _pLocalToGlobalMatrix;
  CAT3DBoundingSphere* _p3DBoundingElement;

  // Primitive Attributes
  unsigned int _ID;

  // Primitive Item Attributes
  unsigned char _Type;
  VisDataType _VertexComponentDataTypeTab[VIS_VERTEX_COMPONENT_COUNT];
  void* _pVertexComponentTab[VIS_VERTEX_COMPONENT_COUNT];
};

#endif
