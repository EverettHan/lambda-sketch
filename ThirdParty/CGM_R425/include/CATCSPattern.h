// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATCSPattern.h
// Header definition of CATCSPattern
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2009  Creation                 Nikolay SNYTNIKOV
//===================================================================

#ifndef CATCSPattern_H
#define CATCSPattern_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"

#include "CATCSConstraint.h"

class CATCSGeometryLeaf;
class CATCSVariable;

//-----------------------------------------------------------------------

class ExportedBySolverInterface CATCSPattern : public CATCSConstraint
{
public:
  /**
   * C-tor of a pattern constraint.
   * A pattern constraint is a (n+1)-ary constraint of symmetry.
   * The pattern will be automatically deleted with the solver instance.
   */
  CATCSPattern();

  virtual ~CATCSPattern();

  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  void GetGeometries(
    CATCSGeometryLeaf *&opAxis,
    int &oNbGeometries,
    CATCSGeometryLeaf **&oapGeometries,
    CATCSVariable **&oapVariables,
    CATCAlignment *&oaAlignment);

  void SetGeometries(
    CATCSGeometryLeaf *ipAxis,
    int iNbGeometries,
    CATCSGeometryLeaf **iapGeometries,
    CATCSVariable **iapVariables,
    CATCAlignment *iaAlignment);
 
  CATCSGeometryLeaf *GetAxis() const;

  int GetNbOfVariables() const;
  
private:
  CATCSGeometryLeaf* _pAxis;
  int _nArgs;
  CATCSGeometryLeaf** _apArgs;
  CATCSVariable** _apVars;
  CATCAlignment* _aAlign;
};

//-----------------------------------------------------------------------

#endif
