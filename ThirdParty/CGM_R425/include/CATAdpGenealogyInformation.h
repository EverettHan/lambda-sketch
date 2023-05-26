//===================================================================
// COPYRIGHT Microsoft 2012/06/28
//===================================================================
// CATAdpGenealogyInformation.cpp
// Header definition of class CATAdpGenealogyInformation
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2012/06/28 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATAdpGenealogyInformation_H
#define CATAdpGenealogyInformation_H

#include "CATAdpLifecycleOperation.h"
#include "CATPLMID.h"
#include "CATOmxDefaultCollecManager.h"
//-----------------------------------------------------------------------

struct CATAdpGenealogyInformation
{
private:
  CATPLMID _Input;
  CATAdpLifecycleOperation::Operation _Operation;
  CATPLMID _Related;
  friend class CATAdpPLMGenealogyInformation;
public:
  CATAdpGenealogyInformation() {};
  CATAdpGenealogyInformation(CATPLMID iInput, CATAdpLifecycleOperation::Operation iOperation, CATPLMID iRelated) :
    _Input(iInput), _Operation(iOperation), _Related(iRelated) {}
  CATAdpGenealogyInformation& operator=(const CATAdpGenealogyInformation& iCopy) { _Input = iCopy._Input; _Operation = iCopy._Operation; _Related = iCopy._Related; return *this; }

  const CATPLMID Input() const { return _Input; };
  const CATAdpLifecycleOperation::Operation Operation() const { return _Operation; }
  const CATPLMID Related() const { return _Related; }
};
template <> CATOmxCollecManager & CATOmxDefaultCollecManager<CATAdpGenealogyInformation>::manager(); // For MacOSX compilation;
//-----------------------------------------------------------------------

#endif
