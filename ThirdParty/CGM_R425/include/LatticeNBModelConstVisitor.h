//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2021
//=============================================================================
//
// LatticeNBModelConstVisitor.h
//
//=============================================================================
// 2021-10-12  XXC: Creation.
//=============================================================================

#ifndef LatticeNBModelConstVisitor_H
#define LatticeNBModelConstVisitor_H

#include "ExportedByLatticeModel.h"
#include "LatticeNBModel.h"
#include "CATSysErrorDef.h"

class LatticePatternNBModel;

class ExportedByLatticeModel LatticeNBModelConstVisitor
{
public:

  virtual ~LatticeNBModelConstVisitor() {}

public:

  /**
  * Inline method that forwards the request to the lattice implementation.
  * If it accepts visitors, the lattice implementation calls back the visit methods
  * with the concrete types or the default method.
  */
  inline HRESULT Visit(const LatticeNBModel& iLattice);

public:

  // Calls back the generic implementation of the visitor
  // (when the concrete type is not supported.)
  virtual HRESULT VisitDefault(const LatticeNBModel& iLattice);

public:

  /** @name Concrete types different from default implementation.
  @{ */

  virtual HRESULT VisitConcrete(const LatticeNBModel& iLattice);
  virtual HRESULT VisitConcrete(const LatticePatternNBModel& iLattice);
};

inline HRESULT LatticeNBModelConstVisitor::Visit(const LatticeNBModel& iLattice)
{
  return iLattice.Accept(*this);
}

#endif
