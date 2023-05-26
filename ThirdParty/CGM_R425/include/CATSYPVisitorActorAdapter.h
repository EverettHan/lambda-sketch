// COPYRIGHT Dassault Systemes 2022
//-------------------------------------------------------------------------------------------------
#pragma once

#include <UIVCoreTools.h>
#include <CATISYPVisitorActor.h>

class CATSYPVisitor;

/**
 * Adapter for CATISYPVisitorActor implementation.
 * A generic implementation to accept the visitor.
 *
 * If the component does not have any child, no need to override Accept method.
 * You just have to inherit from this adapter and add appropriate CATImplementClass
 *
 * If the component have some children that need to be accepted, inherit from this class and override the
 * AcceptContent method. This method must retrieve chidren and call the Accept method.
 *
 * For components that are CATISYPIntrospectable objects, the CATSYPObjectVisitorActorAdapter already exist.
 * This adapter provides an implementation for the AcceptContent method. You might have nothing to do as an extension
 * already exist for main CID components objcts.
 *
 * @see CATISYPVisitorActor
 */
class ExportedByUIVCoreTools CATSYPVisitorActorAdapter : public CATISYPVisitorActor
{
public:
  CATSYPVisitorActorAdapter();
  virtual ~CATSYPVisitorActorAdapter();

  // Implementation of CATISYPVisitorActor
  virtual int Accept(CATSYPVisitor &iVisitor) override;

protected:
  // This method can be override to Accept children if any and if they need to be visited
  virtual int AcceptContent(CATSYPVisitor &iVisitor);

private:
  CATSYPVisitorActorAdapter(const CATSYPVisitorActorAdapter &);
  CATSYPVisitorActorAdapter &operator=(const CATSYPVisitorActorAdapter &);
};
