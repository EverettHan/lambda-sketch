// COPYRIGHT Dassault Systemes 2022
//-------------------------------------------------------------------------------------------------
#pragma once

#include <IUnknown.h>
#include <UIVCoreTools.h>
#include <CATSYPVisitor.h>
#include <nlohmann/json.hpp>

class CATBaseUnknwon;

/**
 * Visitor dedicated to parse a hierarchical structure (CID / Dialog) to dump properties.
 * The IID is used to retrieve properties of the visited structure.
 * The interface must inherit from CATSYPGenericUIDump.
 * The same visitor can be used to visit multiple components.
 *
 * Usage:
 *    CATSYPGenericUIDumpVisitor visitor(IID_OfInterfaceInheritingFromCATSYPGenericUIDump);
 *    CATISYPVisitorActor_var spVisitorActor1(pObjToVisit1), spVisitorActor2(pObjToVisit2);
 *    if(spVisitorActor1!=NULL_var)
 *      spVisitorActor1->Accept(visitor);
 *    if(spVisitorActor2!=NULL_var)
 *      spVisitorActor2->Accept(visitor);
 *    nlohmann::json dumpResultAll = visitor.GetDump();
 *
 *    nlohmann::json dumpResult1 = dumpResultAll[0];
 *    nlohmann::json dumpResult2 = dumpResultAll[1];
 *
 * @see CATSYPVisitor
 */
class ExportedByUIVCoreTools CATSYPGenericUIDumpVisitor : public CATSYPVisitor
{
public:
  /**
   * Constructor
   * @param iIID is the interface that defines properties to be dumped
   * The interface must inherit from CATSYPGenericUIDump.
   */
  CATSYPGenericUIDumpVisitor(const IID &iIID);
  virtual ~CATSYPGenericUIDumpVisitor();

  virtual CATSYPVisitor::VisitorEnterAction VisitEnter(CATBaseUnknown *iObject) override;

  virtual CATSYPVisitor::VisitorVisitAction Visit(CATBaseUnknown *iObject) override;

  virtual int VisitLeave(CATBaseUnknown *iObject) override;

  /**
   * The visitor can be used to visit multiple components.
   * So, this method returns a nlohmann json array for each visited component.
   * Each element of the array contains a nlohmann json object listing the the properties
   * of the first element of the structure and there is an additional property
   * named "content" (a nlohmann json array) that contains children properties ...
   */
  virtual nlohmann::json GetDump();

  /**
   * @brief Clears dump of all visited components. Visitor can be reused to visit other components
   */
  virtual void Clear();

private:
  CATSYPGenericUIDumpVisitor();
  CATSYPGenericUIDumpVisitor(const CATSYPGenericUIDumpVisitor &);
  CATSYPGenericUIDumpVisitor &operator=(const CATSYPGenericUIDumpVisitor &);

  nlohmann::json _jsonResult;
  nlohmann::json::json_pointer _jsonPointer;
  IID _iidSYPUIDump;
};
