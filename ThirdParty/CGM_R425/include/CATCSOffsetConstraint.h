// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATCSOffsetConstraint.h
// Header definition of CATCSOffsetProfile
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Apr 2012  Creation                 CHU/BF8
//===================================================================

#ifndef CATCSOffsetConstraint_H
#define CATCSOffsetConstraint_H

#include "CATCDSVirtual.h"
#include "CATCSConstraint.h"
#include "CATCDSEnums.h"

class CATCSVariable;
class CATCSNOffsetConstraint;
class CATCSProfile2D;

class ExportedBySolverInterface CATCSOffsetConstraint : public CATCSConstraint
{
public :

  CATCSOffsetConstraint();

  /**
  * A constraint offset is used only for the profile object/
   * The pattern will be automatically deleted with the solver instance.
   * @param
   * ipBaseProfile Pointer on the profile which will be used as the base for computing the offset
   * @param
   * ipOffsetProfile Pointer on the profile which will be used as the offset
   * @param
   * ipOffsetVariable Pointer on the variable which will be used to compute each offset of each component.
  */
  CATCSOffsetConstraint(
    CATCSProfile2D* ipBase,
    CATCSProfile2D* ipOffset,
    CATCSVariable* ipOffsetVariable);

  CATCSOffsetConstraint(
    CATCSProfile2D* ipBase,
    CATCSProfile2D* ipOffset,
    CATCSVariable** iapOffsetVariables);

  virtual ~CATCSOffsetConstraint();

  virtual CATCSType GetType() const CATCDSOverride;

  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  virtual void GetGeometries(CATCSProfile2D* &opBase,CATCSProfile2D* &opOffset);
  virtual void GetGeometries(CATCSProfile2D* &opBase,CATCSProfile2D* &opOffset,  CATCSVariable* &opVariable);
  virtual void GetGeometries(CATCSProfile2D* &opBase,CATCSProfile2D* &opOffset,  CATCSVariable** &oapVariable);
  virtual CATCSVariable* GetNextVariable(int& ioIter);

  virtual CATCDSBoolean GetBorderVerticesAlignment();
  virtual void SetBorderVerticesAlignment(CATCDSBoolean isAligned);
  void SetGeometries(CATCSProfile2D* ipBase,CATCSProfile2D* ipOffset, CATCSVariable* ipVariables);
  void SetGeometries(CATCSProfile2D* ipBase,CATCSProfile2D* ipOffset, CATCSVariable** iapVariables);

  CATCSNOffsetConstraint* GetOffsetConstraintNode();

  inline void ResetOffsetMonoParametric(); // used when the offset curve is deleted

  CATCDSBoolean IsAMultipleVariableOffset();

private:
    CATCSProfile2D* _pBase;
    CATCSProfile2D* _pOffset;
    CATCSVariable* _pOffsetVariable;
    CATCSVariable** _apOffsetVariables;
};

CATCDSLISTP_DECLARE(CATCSOffsetConstraint);

inline void CATCSOffsetConstraint::ResetOffsetMonoParametric() { // used when the offset curve is deleted
  _pBase = 0;
  _pOffset = 0;
  _pOffsetVariable = 0;
  if(_apOffsetVariables)
    delete[] _apOffsetVariables;
  _apOffsetVariables = 0;
}

#endif
