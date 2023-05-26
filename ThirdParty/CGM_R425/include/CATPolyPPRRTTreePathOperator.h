#ifndef CATPolyPPRRTTreePathOperator_h
#define CATPolyPPRRTTreePathOperator_h

// ExportedBy
#include "PolyBodyBVHOperators.h"

#include <vector>

// PolyhedralMathematics
#include "CATCGMSharedPtr.h"
#include "CATRefCounted.h"

// System
#include "CATErrorDef.h"

// PolyhedralBodyOperators
#include "CATPolyPPPath.h"
#include "CATPolyPPRRT.h"
#include "CATPolyPPConfigurationChecker.h"



/**
 * @brief Operator that will do some work on tree and path (optimize, reduce, grow , ...)
 * */
class ExportedByPolyBodyBVHOperators CATPolyPPRRTTreePathOperator : public CATRefCounted
{
  public:
  typedef CATCGMSharedPtr<CATPolyPPRRTTreePathOperator> SPtr;

  CATPolyPPRRTTreePathOperator();
  virtual ~CATPolyPPRRTTreePathOperator();

  virtual void SetTreeFromStart(CATPolyPPRRT::SPtr &iFromStart);
  virtual void SetTreeFromTarget(CATPolyPPRRT::SPtr &iFromTarget);

  // add list of checker (several if we want to use multithread)

  virtual void Run(CATPolyPPPath *iValidPath) = 0;

  protected:
  CATPolyPPRRT::SPtr _TreeFromStart;
  CATPolyPPRRT::SPtr _TreeFromTarget;
};

class ExportedByPolyBodyBVHOperators CATPolyPPRRTTreePathMultiSolution : public CATPolyPPRRTTreePathOperator
{
  public:
  typedef CATCGMSharedPtr<CATPolyPPRRTTreePathMultiSolution> SPtr;

  class ExportedByPolyBodyBVHOperators StopCriteria : public CATRefCounted
  {
    public:
    typedef CATCGMSharedPtr<StopCriteria> SPtr;
    virtual bool StopSearching(CATPolyPPPath *iNewPath) = 0;
  };

  /**
   * @brief Basic Stop criteria that stop after N solution.
   * */
  class ExportedByPolyBodyBVHOperators StopAfterNSolution : public StopCriteria
  {
    public:
    StopAfterNSolution(int N = 1);
    bool StopSearching(CATPolyPPPath *iNewPath);
    protected:
    int _N;
    int _nbFound = 0;
  };

  void SetStopCriteria(StopCriteria::SPtr &iCriteria);

  void SetDoPathOptim(bool iEnable);

  /**
   *  this is a list if we want to do multithread check
   * */
  void SetCheckerList(std::vector<CATPolyPPConfigurationChecker::SPtr> & iCheckers );

  virtual void Run(CATPolyPPPath *iValidPath);

  std::vector<CATPolyPPPath *>  &GetComputedPath()
  {
    return _ComputedPath;
  }
  protected:
  StopCriteria::SPtr _StopCriteria;
  bool _oPathOptim;
  std::vector<CATPolyPPPath *> _ComputedPath;
  std::vector<CATPolyPPConfigurationChecker::SPtr> _Checkers;
};

#endif
