// Copyright Dassault Systemes 2000
#ifndef CATICkeEvaluator_h
#define CATICkeEvaluator_h
//////////////////////////////////////////////////////////////////////////
//
//
//	Cke Engineering Equations Interfaces
// 	Evaluator Interface declaration
//
//////////////////////////////////////////////////////////////////////////
#include "CATLifSpecs.h"
#include "CATListValCATICkeParm.h"
#include "CATBaseUnknown.h"
#include "CATICkeParm.h"
#include "CATICkeRelationForwards.h"
#include "CATKweActivateEKLPerfos.h"

class CATCkeEvalContext;

// OLE
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATICkeEvaluator;
#else
extern "C" const IID IID_CATICkeEvaluator;
#endif

class ExportedByCATLifSpecs CATICkeEvaluator : public CATBaseUnknown
{

public:

  // tests if this evaluator can be used
  virtual CATCke::Boolean IsRunnable() const = 0;

  // layer management : there is always one at least (1 to N)
  virtual  void SelectLayer(int i) = 0;
  virtual  void RemoveLayer(int i) = 0;
  virtual  void NewLayer(int iToReach = -1) = 0;
  virtual  void DeleteLayers() = 0;
  virtual  int 	Layers() const = 0;
  virtual  int 	CurrentLayer() const = 0;

  // working on a layer : working on parameters and Results
  virtual int             ParmNumber()  const = 0;
  virtual void            Assign(int i, const CATICkeParm_var &p) = 0;

  virtual void            SetParameters(CATCkeListOfParm l) = 0;

  virtual CATICkeParm_var GetParm(int i) const = 0;
  virtual CATICkeParm_var Result()  const = 0;
  virtual void            Push(const CATICkeParm_var &p) = 0;
  virtual void            Clear() = 0;  // resets current layer

  // expression evaluation
  virtual void  Evaluate(const CATCkeEvalContext *p = NULL) = 0;

  // Check magnitude homogeneity : Raise CATCkeErrorMKS
  // returns true if OK 
  virtual CATCke::Boolean CheckMagnitude(CATICkeMKSUnit_var &mks,
    const CATCkeEvalContext *p = NULL) const = 0;

  // direct evaluation
  virtual void Do(CATCkeListOfParm plist, const CATICkeParm_var &p, const CATCkeEvalContext *pevalcontext = NULL) const = 0;

private:

  // 2 define ClassName
  CATDeclareInterface;

};

CATDeclareHandler(CATICkeEvaluator, CATBaseUnknown);

#endif


