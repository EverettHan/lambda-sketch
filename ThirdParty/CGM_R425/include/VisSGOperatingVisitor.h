#ifndef VISSGOPERATINGVISITOR_H
#define VISSGOPERATINGVISITOR_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "SGInfra.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "VisDataType.h"
class VisSGVisitor;
class IVisSGObject;
class VisSGPrimitiveItem;


/** 
 * Basic class of Scene Graph visit.
 * <b>Role</b>: This is the basic class that any Scene Graph Visitor has to C++ derive from.
 * It represents an operation to be performed on each element of a scene graph.
*/

class ExportedBySGInfra VisSGOperatingVisitor : public CATBaseUnknown
{
public:

  VisSGOperatingVisitor();
  virtual ~VisSGOperatingVisitor();

  // Visit Scene Graph Objects
  virtual HRESULT BeginVisit(IVisSGObject& iObject, CATBoolean& oContinue);
  virtual HRESULT Visit(IVisSGObject& iObject, CATBoolean& oContinue);
  virtual HRESULT EndVisit(IVisSGObject& iObject);

  // Visit Scene Graph Tessellation
  virtual HRESULT BeginVisit(VisSGPrimitiveItem& iPrimitiveItem, CATBoolean& oContinue);
  virtual HRESULT Visit(VisSGPrimitiveItem& iPrimitiveItem, CATBoolean& oContinue);
  virtual HRESULT VisitPoint(VisDataType iType, void* ipVertex1Position);
  virtual HRESULT VisitLine(VisDataType iType, void* ipVertex1Position, void* ipVertex2Position);
  virtual HRESULT VisitTriangle(VisDataType iType, void* ipVertex1Position, void* ipVertex2Position, void* ipVertex3Position);
  virtual HRESULT EndVisit(VisSGPrimitiveItem& iPrimitiveItem);

private:

  VisSGOperatingVisitor(const VisSGOperatingVisitor& iOperatingVisitor);
  VisSGOperatingVisitor& operator = (const VisSGOperatingVisitor& iOperatingVisitor);

protected:

  virtual HRESULT GetVisitor(VisSGVisitor*& opVisitor);

protected:

  VisSGVisitor* _pVisitor;
};

#endif 

