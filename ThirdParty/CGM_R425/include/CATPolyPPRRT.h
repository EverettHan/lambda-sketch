// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPPRRT.h
//
//===================================================================
//
// Usage notes: Main class for representing Rapidly exploring Random
// Trees.
//
//===================================================================
//
// 2013-03-09 XXC: Creation
// 2013-10-07 JXO: CATPolyPPRRTNode as an output of AddConfiguration
//===================================================================

#ifndef CATPolyPPRRT_HH
#define CATPolyPPRRT_HH

#include "CATDynamicKDTree.h"
#include "CATPolyPPRRTNode.h"
#include "CATPolyRefCounted.h"
#include "CATCGMSharedPtr.h"
#include "PolyPathPlanning.h"

class CATPolyPPTopologicalPoint;
class CATPolyPPTopologicalSpace;
class CATPolyPPCartesianProduct;

class CATPolyPPRRTNodeRandomizer;

#ifdef ENABLE_PP_MT
#include "CATPolySharedMutex.h"
#include <mutex>
#endif

#include <cstring> //memcpy Linux
#include <deque>
#include <set> //remarks <unorderd_set> works but create name conflict with VisualizationInterfaces\PublicInterfaces\list.h error C2872: 'list': ambiguous symbol
/** Main class for representing Rapidly exploring Random
 *  Trees.
 */
class ExportedByPolyPathPlanning CATPolyPPRRT : public CATPolyRefCounted // to make it sharable
{
  public:
  typedef CATCGMSharedPtr<CATPolyPPRRT> SPtr;
    
  /**
   * Simple visitor pattern
   * */  
  class ExportedByPolyPathPlanning Visitor
  {
    public:
    /**
     * must return true to visit deeper;
     * */
    virtual bool DoVisit(CATPolyPPRRTNode & iNode) {return true;};

    void Start(CATPolyPPRRT & iTree);
    void Start(CATPolyPPRRTNode & iNode);
  };
  
  
  CATPolyPPRRT(CATBoolean iWithNodeRandomizer = FALSE);

  static SPtr Create(CATBoolean iWithNodeRandomizer = FALSE){return SPtr(new CATPolyPPRRT(iWithNodeRandomizer));};

  ~CATPolyPPRRT();

  HRESULT GetNearestNeighbor(const CATPolyPPPosition *iNewNeighbor, CATPolyPPRRTNode *&oNeighborhood, bool iCDIST = true);
  HRESULT GetNearestNeighbors(const CATPolyPPPosition *iNewNeighbor, CATPolyPPRRTNode **oNeighborhood, int nbNeighbors, bool iCDIST = true);

  HRESULT GetNearestNeighbors(const CATPolyPPPosition *iNewNeighbor, double iRadiusDist, std::vector<CATPolyPPRRTNode *> &oNeighborhood, bool iCDIST = true);

  HRESULT AddConfiguration(CATPolyPPPosition *iConfiguration, CATPolyPPRRTNode *iParent, CATPolyPPRRTNode **opNode = 0);
  HRESULT RemoveNode(CATPolyPPRRTNode &iNode);

  HRESULT Initialize(CATPolyPPPosition *iStart, double **iBox);

  /** Get a node in the tree according to a non-uniform distribution
   *  over the node. A weight is assigned to each node according to
   *  the number of time a node has been chosen. The more a node has
   *  been chosen, the less it will be chosen in the future. Allows to
   *  grow the three from new nodes.
   */
  CATPolyPPRRTNode *GetRandomNode();

  
  /**
   * @brief return the current leaf
   * @remark valid only if your are not changing the tree in the same time (multi thread).
   * */
  std::vector<CATPolyPPRRTNode*> GetLeafs() ;

  private:
  CATPolyPPRRTNode *_Last;

#ifdef ENABLE_PP_MT

#ifdef _WINDOWS_SOURCE
  typedef shared_mutex MyMutex;
  typedef shared_lock<MyMutex> MySharedLock;
#else
  typedef std::mutex MyMutex;
  typedef std::unique_lock<MyMutex> MySharedLock; // todo impl shared_lock on Linux
#endif
  mutable MyMutex m_Mut;

  std::atomic<unsigned long> _nbAddedConfig = 0;
  std::atomic<CATPolyPPRRTNode *> _aLast;

  public:
  INLINE const double **GetMinimalBox() { return (const double **)_Box; }
  INLINE CATPolyPPRRTNode *GetLastInsertedNode()
  {
    std::unique_lock<MyMutex> lck(m_Mut);
    return _Last;
  }
  INLINE const CATPolyPPRRTNode *GetRoot() const
  {
    std::unique_lock<MyMutex> lck(m_Mut);
    return _Root;
  }
  INLINE void SetTarget(CATPolyPPRRTNode *ipNode) { _aLast.store(ipNode, std::memory_order_release); }
  INLINE const CATPolyPPRRTNode *aGetLastInsertedNode() const { return _aLast.load(std::memory_order_acquire); }
  INLINE unsigned long GetNbAddedConfig() const { return _nbAddedConfig; }
  INLINE void GetMinimalBox(double *(&ioBox)[2])
  {
    MySharedLock lck(m_Mut);
    memcpy(ioBox[0], _Box[0], sizeof(double) * _Dimension);
    memcpy(ioBox[1], _Box[1], sizeof(double) * _Dimension);
  }

#else
  unsigned long _nbAddedConfig = 0;

  public:
  INLINE const double **GetMinimalBox() { return (const double **)_Box; }
  INLINE CATPolyPPRRTNode *GetLastInsertedNode() { return _Last; }
  INLINE const CATPolyPPRRTNode *GetRoot() const { return _Root; }
  INLINE unsigned long GetNbAddedConfig() const { return _nbAddedConfig; }
#endif

  public:
  HRESULT Search(const CATDynamicKDTreeNode *iNode, const CATPolyPPPosition *iNewNeighbor, CATPolyPPRRTNode *&oNeighborhood, double iBoxDistance, double &ioBestDistanceSoFar, bool iCDIST);
  HRESULT Search(const CATDynamicKDTreeNode *iNode, const CATPolyPPPosition *iNewNeighbor, CATPolyPPRRTNode **oNeighborhood, double *oDistances, int nbNeighbors, double iBoxDistance, double &ioBestDistanceSoFar, bool iCDIST);

  typedef struct PPNodeAndDist_st
  {
    CATPolyPPRRTNode *Node;
    double dist;
  } PPNodeAndDist;

  HRESULT Search(const CATDynamicKDTreeNode *iNode, const CATPolyPPPosition *iNewNeighbor,
                 std::deque<PPNodeAndDist> &oNeighborhood, double iRadiusDist, double iBoxDistance, double &ioBestDistanceSoFar, bool iCDIST);


  std::string toJson();
  
  private:
  CATPolyPPRRT(const CATPolyPPRRT &o);
  CATPolyPPRRT &operator=(const CATPolyPPRRT &o);

  double *_Box[2];
  CATPolyPPRRTNode *_Root;
  CATDynamicKDTree *_KDTree; // For neighboring purpose.
  CATPolyPPRRTNodeRandomizer *_Randomizer;
  unsigned _Dimension;
  std::set<CATPolyPPPosition *> _AddedConfiguration;

  
};

#endif
