
// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATWBBlackBoxIntervalEval.h
// Header definition of CATWBBlackBoxIntervalEval
//
//===================================================================
//
// Usage notes: A class for evaluation of White Boxes equations support in CDS.
//
//===================================================================
//
//   /04/07 KJD  Creation (Dassault System.)
//   /07/07 VTN  Modified (Dassault System.)
// 25/01/23 Q48  Black-box rearchitecture to support clone
//                  - behind define WBx_BBx_Rearchitecture (inactive)
//===================================================================

#ifndef CATWBBlackBoxIntervalEval_h
#define CATWBBlackBoxIntervalEval_h

// Base class
#include "CATWBBlackBox.h"

// ExportedBy
#include "CATWhiteBoxSolver.h"

// C++ 11
#include "CATCDSVirtual.h"

// PTO/PKC : temporaire
#include "CATSysErrorDef.h"

// CDS
#include "CATCDSArray.h"

#ifndef STD_CALL
#ifdef _WINDOWS_SOURCE
#define STD_CALL __stdcall
#else
#define STD_CALL
#endif
#endif

// WBx
class CATWBValue;
class CATWBFactory;
class CATWBManager;
class CATWBExpression;
class CATWBEnvironment;
class CATWBHeuristics;
class CATWBHeuristicsNGrad;

enum CATWBHeuristicsType
{
   HeuristicsNGrad
   // to add new heuristics here
};

//-----------------------------------------------------------------------

class ExportedByCATWhiteBoxSolver CATWBBlackBoxIntervalEval : public CATWBBlackBox
{
protected:

   CATWBBlackBoxIntervalEval();

public:

   virtual ~CATWBBlackBoxIntervalEval();

public:

   // Required for CATCkeWBBlackBox
   virtual double Eval();

protected:

   virtual void   Eval(CATWBValue & oValue) CATCDSOverride;

private:

   virtual void   Eval_NGrad (const CATWBBlackBoxOperator * iBBxOp,
                              const CATWBEnvironment      & iEnv,
                                    CATWBHeuristicsNGrad  * iHeuristic,
                                    CATWBValue            & oValue) const CATCDSFinal;

public:

   virtual int    StopEval () ; // to be removed
   virtual  HRESULT  STD_CALL StopEval(int & oResult) const;

#ifndef WBx_BBx_Rearchitecture
    virtual void                 SetWBHeuristicsType (const CATWBHeuristicsType &iType) ;
#endif

   virtual CATWBHeuristicsType  GetWBHeuristicsType () const CATCDSFinal;

#ifdef WBx_BBx_Rearchitecture
   virtual int                  CreateHeuristics (CATWBBlackBoxOperator * iBBxOp) CATCDSFinal;
#else
   virtual int                  CreateHeuristics (CATWBManager *ipManager);
#endif

   virtual CATWBHeuristics    * GetWBHeuristics  (const CATWBBlackBoxOperator * iBBxOp) const CATCDSFinal;

protected :

#ifdef WBx_BBx_Rearchitecture
   const CATWBHeuristicsType _HeuristicsType;
#else
         CATWBHeuristicsType _HeuristicsType;
#endif

private:

   CATCDSArray<CATWBHeuristics*> _pHeuristics;
};

//-----------------------------------------------------------------------

#endif
