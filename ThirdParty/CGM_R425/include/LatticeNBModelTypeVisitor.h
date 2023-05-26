//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2021
//=============================================================================
//
// LatticeNBModelTypeVisitor.h
//
//=============================================================================
// 2021-10-12  XXC: Creation.
//=============================================================================

#ifndef LatticeNBModelTypeVisitor_H
#define LatticeNBModelTypeVisitor_H

#include "ExportedByLatticeModel.h"
#include "LatticeNBModelConstVisitor.h"

class ExportedByLatticeModel LatticeNBModelTypeVisitor : public LatticeNBModelConstVisitor
{
public:

  enum LatticeType
  {
    /** Lattice type unknown from this visitor */ eUnknownLattice = -1,
    /** LatticeNBModel type */ eBaseLattice = 0,
    /** LatticePatternNBModel */ ePatternLattice = 1,
  };

public:

  LatticeNBModelTypeVisitor() : _Type(eUnknownLattice) {}
  ~LatticeNBModelTypeVisitor() {}


  HRESULT GetType(const LatticeNBModel & iLattice, LatticeType & oType);

private:

  // Calls back the generic implementation of the visitor
  // (when the concrete type is not supported.)
  HRESULT VisitDefault(const LatticeNBModel& iLattice) override;

private:

  HRESULT VisitConcrete(const LatticeNBModel& iLattice) override;
  HRESULT VisitConcrete(const LatticePatternNBModel& iLattice) override;

private:
  LatticeType _Type;
};

#endif
