#ifndef CATPolyPathPlanningObserver_h
#define CATPolyPathPlanningObserver_h

// ExportedBy
#include "PolyBodyBVHOperators.h"

// PolyhedralMathematics
#include "CATCGMSharedPtr.h"
#include "CATRefCounted.h"

// System
#include "CATErrorDef.h"

// PolyhedralBodyOperators
#include "CATPolyPPPath.h"
#include "CATPolyPPRRT.h"

class CATPolyPPDefinition;

class ExportedByPolyBodyBVHOperators CATPolyPathPlanningObserver : public CATRefCounted
{
  public:
  typedef CATCGMSharedPtr<CATPolyPathPlanningObserver> SPtr;
  virtual void SetProblemDefinition(CATPolyPPDefinition &iDef) = 0;
  virtual void RunStep() = 0;
  virtual void RanStep(HRESULT hr) = 0;

  /**
   * @brief this method is called when we found a valid path between 2 input point it can be :
   *   - between Start and Target
   *   - or between Start and Intermediate1 then Intermediate1 and Intermediate2  then ... then IntermediateLast and Target
   * 
   * Example of implementation for multiSolution:
   * \snippet PPTutoMain.cpp PPMultiSolution
   * 
   * @param[in] iValidSection a valid path between 2 point  (should be release/delete  by user )
   * @param[in] iTreeFromSectionStart a tree where all the branch are valid starting from the first point of the path
   * @param[in] iTreeFromSectionTarget may be nullptr , a tree where all the branch are valid  starting from the last point of the path.
   *
   * @return must return false to keep growing tree , return true to validate the path and stop the growing
   * */
  virtual bool OnPathFound(CATPolyPPPath *iValidSection, CATPolyPPRRT::SPtr &iTreeFromSectionStart, CATPolyPPRRT::SPtr &iTreeFromSectionTarget)
  { // default behaviour
    if (iValidSection)
      delete iValidSection;
    return true;
  };
};

#endif
