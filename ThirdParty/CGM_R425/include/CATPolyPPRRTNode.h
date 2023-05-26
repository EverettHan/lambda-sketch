// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPPRRTNode.h
//
//===================================================================
//
// Usage notes: Class representing a node in a Rapidly exploring
// Random Trees (see also CATPolyPPRRT).
//
//===================================================================
// 2013-03-13 XXC: Creation
//===================================================================

#ifndef CATPolyPPRRTNode_HH
#define CATPolyPPRRTNode_HH

#include "PolyPathPlanning.h"
#include "CATDynamicKDTree.h"
#include "CATDynamicKDTreeNode.h"

#include "CATListPV.h"

class CATPolyPPRRT;
class CATPolyPPCartesianProduct;
//class CATPolyPPPosition;
#include "CATPolyPPPosition.h"


#ifdef ENABLE_PP_MT
#include <atomic>
#endif

/** Class representing a node in a Rapidly exploring Random Tree (RRT)
 *  CATPolyPPRRT, the main structure used in the n-dimensional Path
 *  Planning solver CATPolyPathPlanningSolver. This simple structure
 *  only contains a configuration (the position of the moving
 *  object(s)) and a list of children (subtrees). It also derives from
 *  the CATDynamicKDTreePoint structure in order to allow its
 *  indexation in a k-d-tree and to be able to make some nearest
 *  neighbor search queries.
 */
class ExportedByPolyPathPlanning CATPolyPPRRTNode : public CATDynamicKDTreePoint
{
 public:
  /** Construction of a RRT node from a configuration and its parent
   *  in the tree. Take notes that it works as a container for the
   *  configuration and that it is deleted with the node in the class
   *  destructor.
   */
  CATPolyPPRRTNode(CATPolyPPRRTNode * iParent, CATPolyPPPosition * iConfiguration,CATPolyPPRRT *iTree = nullptr );
  ~CATPolyPPRRTNode();

  CATPolyPPRRT*GetTree() const {return _Tree;};


  INLINE CATBoolean OnContactSpace() const;
  INLINE void IsOnCSpace(double iInitialRadiusValue);
  INLINE double GetRadius() const;
  //INLINE void IncreaseRadius();
  //INLINE void DecreaseRadius();

#ifdef ENABLE_PP_MT
  INLINE CATBoolean aOnContactSpace() const;
  INLINE void aIsOnCSpace(double iInitialRadiusValue);
  INLINE double aGetRadius() const;
  //INLINE void aIncreaseRadius();
  //INLINE void aDecreaseRadius();
#endif


  INLINE CATPolyPPPosition * GetConfiguration() const;
  INLINE const CATPolyPPRRTNode * GetParent() const;
  void ChangeParent(CATPolyPPRRTNode & iNewParent);
  void RemoveChild(CATPolyPPRRTNode &iChild);

  INLINE int GetNbChildren() const;
  INLINE const CATPolyPPRRTNode * GetChild(unsigned int i) const;
  INLINE CATPolyPPRRTNode * GetChild(unsigned int i);
  int AddFailed(int inc=1) {
    return _failed+=inc;
  };
  int GetNbFailed() const 
  {
    return _failed;
  }

  double GetCostToParent() const;
  double GetCostToRoot() const ;

  void SetCostToParent(double iCost);
  void SetCostToRoot(double iCost);
 public:
  const double & operator[](int idx) const;
  unsigned int Dimension() const;

  std::string toJSON(bool withChildren=true);

 private:
  INLINE void AddChild(CATPolyPPRRTNode * iChild);

  CATPolyPPRRTNode( const CATPolyPPRRTNode& iOther );
  CATPolyPPRRTNode& operator=( const CATPolyPPRRTNode& iOther );

 public:
  CATBoolean _OnCSpace;
#ifdef ENABLE_PP_MT
  std::atomic<bool> m_OnCSpace;
  std::atomic<double> m_Radius;
  std::atomic<int> _failed=0; //mac issue
#else
  int _failed=0;
#endif
  double _Radius, _Limite;
  CATPolyPPPosition * _Configuration;
  CATPolyPPRRTNode * _Father;
  CATListPV _Children;

  CATPolyPPRRT * _Tree = nullptr;

  
  double _CostToParent=0;
  double _CostToRoot=0;
  
};

INLINE CATBoolean CATPolyPPRRTNode::OnContactSpace() const
{
  return _OnCSpace;
}

INLINE void CATPolyPPRRTNode::IsOnCSpace(double iInitialRadiusValue)
{
     if (!_OnCSpace) {
         _OnCSpace = TRUE;
         _Radius = _Limite = iInitialRadiusValue;
     }
  /* else DecreaseRadius(); */
}

INLINE double CATPolyPPRRTNode::GetRadius() const
{
  return _Radius;
}

/*INLINE void CATPolyPPRRTNode::IncreaseRadius()
{
  if (_Radius < _Limite*10.0)
    _Radius += _Radius*0.05;
}

INLINE void CATPolyPPRRTNode::DecreaseRadius()
{
  if (_Radius > _Limite*0.1)
    _Radius -= _Radius*0.03;
}*/

#ifdef ENABLE_PP_MT

INLINE CATBoolean CATPolyPPRRTNode::aOnContactSpace() const
{;
  return OnContactSpace();
    //test return m_OnCSpace.load( std::memory_order_acquire );
}

INLINE void CATPolyPPRRTNode::aIsOnCSpace(double iInitialRadiusValue)
{
    IsOnCSpace(iInitialRadiusValue);
    /*test if( !m_OnCSpace.load( std::memory_order_acquire ) )
    {
        m_Radius.store( iInitialRadiusValue, std::memory_order_relaxed );
        m_OnCSpace.store( true, std::memory_order_release );//release acts as a barrier to reorder relaxed instructions
    }*/
    // else DecreaseRadius(); 
}

INLINE double CATPolyPPRRTNode::aGetRadius() const
{
   //test return m_Radius.load( std::memory_order_acquire );
   return GetRadius();
}

/*INLINE void CATPolyPPRRTNode::aIncreaseRadius()
{
    double r =  m_Radius.load( std::memory_order_acquire );
    if( r < _Limite * 10.0 )
        m_Radius.store( r + r*0.02, std::memory_order_release );
}

INLINE void CATPolyPPRRTNode::aDecreaseRadius()
{
    double r =  m_Radius.load( std::memory_order_acquire );
    if( r > _Limite*0.1)
        m_Radius.store( r - r*0.02, std::memory_order_release );
}*/

#endif

INLINE CATPolyPPPosition * CATPolyPPRRTNode::GetConfiguration() const
{
  return _Configuration;
}

INLINE const CATPolyPPRRTNode * CATPolyPPRRTNode::GetParent() const
{
  return _Father;
}

INLINE int CATPolyPPRRTNode::GetNbChildren() const
{
  return _Children.Size();
}

INLINE const CATPolyPPRRTNode * CATPolyPPRRTNode::GetChild(unsigned int i) const
{
  return (CATPolyPPRRTNode *) _Children[i];
}

INLINE CATPolyPPRRTNode * CATPolyPPRRTNode::GetChild(unsigned int i)
{
  return (CATPolyPPRRTNode *) _Children[i];
}

INLINE void CATPolyPPRRTNode::AddChild(CATPolyPPRRTNode * iChild)
{
  _Children.Append(iChild);
}

#endif
