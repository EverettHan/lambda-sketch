// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPathPlanningSolver.h
//
//===================================================================


#ifndef CATPolyPathPlanningSolverCallback_HH
#define CATPolyPathPlanningSolverCallback_HH

#include "CATPolyDeprecated.h"
#include "PolyPathPlanning.h"

#include "CATRefCounted.h"
#include "CATCGMSharedPtr.h"

#include <mutex>

class CATPolyPPPosition;
class CATPolyPPRRTNode;
class CATPolyPPRRTNode;

/**
 * Callback interface on the AddConfiguration method (creation of branch of the tree ).
 *
 * To find a path , the solver generate a tree (or several), this callback
 * allow you to be informed when some branch are created or rejected by the algo.
 * It can be use to show information to the user during the RunStep / RunMt.
 *
 */
class ExportedByPolyPathPlanning CATPolyPathPlanningSolverCallback : public CATRefCounted
{
  public:
  typedef CATCGMSharedPtr<CATPolyPathPlanningSolverCallback> SPtr;
  CATPolyPathPlanningSolverCallback() {}
  /**
   * Called when a new configuration is added to the RR tree
   * @param iConfiguration
   *        the free configuration added to the tree.
   * @param iParent
   *        the node we are attaching the free configuration to.
   * @param iOnCSpace
   *        TRUE if the steering stoped before iNewConfiguration
   *        i.e. iOnCSpace = (iConfiguration != iNewConfiguration)
   * @param iRRTTree
   *        0 for start tree, 1 for end tree
   */
  virtual void AddConfiguration(CATPolyPPPosition *iConfiguration, CATPolyPPRRTNode *iParent, CATBoolean iOnCSpace = FALSE, int iRRTTree = 0) = 0;

  virtual void TestConfiguration(const CATPolyPPPosition *iConfiguration, int icollitiontype){};

  virtual void RejectConfiguration(const CATPolyPPPosition *iConfiguration, const CATPolyPPPosition *iFromPoint = nullptr){};

  /**
   * Called when a new configuration is added from a manualy expanded
   * tree. The parameters are the same than for standard
   * AddConfiguration. If not implemented (default behaviour), just
   * call the standard AddConfiguration method.
   */
  virtual void AddManualConfiguration(CATPolyPPPosition *iConfiguration, CATPolyPPRRTNode *iParent, CATBoolean iOnCSpace = FALSE, int iRRTTree = 0)
  {
    AddConfiguration(iConfiguration, iParent, iOnCSpace, iRRTTree);
  }

  /**
   * Called when the solver reach a target. The target can be an
   * intermediate one (see
   * CATPolyPPDefinition::AppendIntermediateTarget). When a target is
   * reached, the path found until then is constructed until this
   * target and a new planning is started between this target and the
   * next one.
   * @param iTarget
   *  the target which has just been reached and which was
   *  added to the problem definition by
   *  CATPolyPPDefinition::AppendIntermediateTarget or iTarget in the
   *  constructor methods.
   * @param iFinalTarget
   *  Set to TRUE if the target reached is the final
   *  one, which ends solving the problem.
   */
  virtual void ReachedTarget(CATPolyPPPosition *iTarget, CATBoolean iFinalTarget)
  {
  }

  /**
   *  Return TRUE when we try to connect tree to target or other tree
   */
  bool GetTryConnect() const
  {
    return _TryToConnect;
  }

  /**
    Don't use it  the solver will set this state
  */
  void SetTryConnect(bool iSolverTryToConnect)
  {
    _TryToConnect = iSolverTryToConnect;
  }

  /**
   * Called when a node change of parent.
   *
   * */
  virtual void RewireNode(CATPolyPPRRTNode &iNode, const CATPolyPPRRTNode *iPreviousParent, const CATPolyPPRRTNode *iNewParent)
  {
  }

  // internal  thread sage management
  //
  void Lock()
  {
    _mutex.lock();
  }
  void UnLock()
  {
    _mutex.unlock();
  }

  protected:
  virtual ~CATPolyPathPlanningSolverCallback() {}
  bool _TryToConnect = false;
  std::mutex _mutex;
};

#endif
