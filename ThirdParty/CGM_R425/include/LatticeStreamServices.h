#ifndef LatticeGMOperators_H
#define LatticeGMOperators_H

#include "ExportedByLatticeModel.h"

#include "CATSysErrorDef.h"
// #include "CATCGMScaleCategoryDef.h"

class LatticeNBModel;
class LatticePatternNBModel;
class CATMathStream;

class ExportedByLatticeModel LatticeStreamServices
{
public:
  LatticeStreamServices() = default;
  ~LatticeStreamServices() {}

public:
  static HRESULT Stream(CATMathStream & ioStream, const LatticeNBModel& iLattice);
  static HRESULT UnStream(CATMathStream & iStream, LatticeNBModel *& oLattice);

private:

  static HRESULT StreamBaseLattice(CATMathStream & ioStream, const LatticeNBModel& iLattice,
                                   const unsigned short iStreamVersion);
  static HRESULT StreamPatternLattice(CATMathStream & ioStream, const LatticePatternNBModel& iLattice,
                                      const unsigned short iStreamVersion);

  static HRESULT UnStreamBaseLattice(CATMathStream & iStream, LatticeNBModel& oLattice,
                                     const unsigned short iStreamVersion);
  static HRESULT UnStreamPatternLattice(CATMathStream & iStream, LatticePatternNBModel& oLattice,
                                        const unsigned short iStreamVersion);
};

#endif
