// COPYRIGHT Dassault Systemes 2022
//-------------------------------------------------------------------------------------------------
#pragma once

#include <UIVCoreTools.h>

class CATBaseUnknown;

/**
 * Visitor that allows to parse a hierarchical structure (ex: CID, Dialog)
 *
 * Usage:
 *  1 - Create one of the existing CATSYPVisitor
 *  2 - QueryInterface the object you want to visit with CATISYPVisitorActor interface
 *  3 - Call the Accept (with created visitor) method (CATISYPVisitorActor)
 */
class ExportedByUIVCoreTools CATSYPVisitor
{
public:

  enum VisitorEnterAction { VisitEnterOk = 0, VisitEnterReturnAndContinue };
  enum VisitorVisitAction { VisitOk = 0, VisitReturnAndContinue };

  /**
   * Called by a CATISYPVisitorActor#Accept method.
   * @return VisitEnterOk if the Accept method must be called, VisitEnterReturnAndContinue if Accept must not be called.
   */
  virtual CATSYPVisitor::VisitorEnterAction VisitEnter(CATBaseUnknown *iObject) = 0;

  /**
   * Called by a CATISYPVisitorActor#Accept method.
   * @return VisitOk if the content of CATISYPVisitorActor must be processed, VisitReturnAndContinue to prevent processing the content.
   */
  virtual CATSYPVisitor::VisitorVisitAction Visit(CATBaseUnknown *iObject) = 0;

  /**
   * Called by a CATISYPVisitorActor#Accept method.
   * @return 1 if the Accept method must continue, 0 if it has to be interrupted.
   */
  virtual int VisitLeave(CATBaseUnknown *iObject) = 0;
};
