// COPYRIGHT Dassault Systemes 2022
//-------------------------------------------------------------------------------------------------
#pragma once

#include <UIVCoreTools.h>
#include <CATBaseUnknown.h>

extern ExportedByUIVCoreTools IID IID_CATISYPVisitorActor;

class CATSYPVisitor;

/**
 * Interface implemented by components that accept to be visited by a CATSYPVisitor
 * 
 * Components implementing this interface must inherit from CATSYPVisitorActorAdapter that
 * provide a visitor default implementation.
 */
class ExportedByUIVCoreTools CATISYPVisitorActor : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  /**
   * Entry point of the visitor.
   * Calls recursively VisitEnter, Visit and VisitLeave on the input visitor
   * to go through the component hierarchy.
   * @param iVisitor the visitor.
   */
  virtual int Accept(CATSYPVisitor &iVisitor) = 0;

};

CATDeclareHandler(CATISYPVisitorActor, CATBaseUnknown);
