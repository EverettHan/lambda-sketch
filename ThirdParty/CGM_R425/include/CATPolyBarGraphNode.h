// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBarGraphNode.h
//
//===================================================================
// August 2011  Creation NDO
// December 2014  JXO: 32 bits for _Count and _ListSize
//===================================================================
#ifndef CATPolyBarGraphNode_H
#define CATPolyBarGraphNode_H

#include "CATBoolean.h"
#include "CATErrorDef.h"


/**
 * Definition of a node.
 *
 * A node in the context of the bar-graph consists of references to its adjacent bars.
 * Its adjacent bars are sorted around the node to define fans of bars which can be open or closed.
 * There could be several fans around a node.
 * The following rules apply:
 * <ul>
 *   <li> (a) The index of the valid bars is strictly greater than 0.  The index of 0 and (-1) define two tags:
 *            the end of an open fan (TOF) and the end of a closed fan sequence (TCF), respectively.
 *   <li> (b) If the fan is open around the node, then the sequence always begins at the start of an open fan.
 *   <li> (b) An index of 0 in that sequence signals the end of an open fan; the next index is the beginning of a new fan.
 *   <li> (c) If the fan is closed, then the sequence ends by the tag (-1) unless there is only one fan in the sequence,
 *            in which case there is no tag at the end of the sequence.  In a closed fan, the first bar follows the last one.
 * </ul>
 *
 * The sorting order of the bars is the same for all nodes (CW if the facets have CCW orientation or the opposite.)
 */
class CATPolyBarGraphNode
{

public:

  inline CATPolyBarGraphNode ();
  inline ~CATPolyBarGraphNode ();

  // Warning shallow copy
  CATPolyBarGraphNode& operator=(CATPolyBarGraphNode const& node) = default;
  inline CATPolyBarGraphNode& operator=(CATPolyBarGraphNode&& node);

  void Absorb (CATPolyBarGraphNode& iRHS);

  /**
   * Copies the data from the array iFans to the node.
   */
  HRESULT Copy (const unsigned int* iFans, const unsigned int iSize);

  /**
   * Disconnects the node from all the bars.
   */
  void Clear ();

  // Recycling.
  inline CATBoolean IsValid () const;
  inline void Invalidate (unsigned int n);  // Invalidates the node and stores n.
  inline unsigned int Validate ();          // Returns n and validates the node.

public:

  /**
   * Returns the number of bars around the node and the end-of-fan markers.
   */
  inline unsigned int GetCount () const;

  /**
   * Returns the number of bars around the node.
   */
  unsigned int GetNbBars () const;

  /**
   * Returns the number of bars and fans around the node.
   */
  unsigned int GetNbBars (unsigned int& oNbFans) const;

  /**
   * Given i with 0 <= i and i < GetCount (), returns the index of a bar or a tag.
   */
  inline unsigned int GetBarOrTag (unsigned int i) const;

  inline unsigned int& GetBarOrTag (unsigned int i);

public:

  // Bar management.

  /**
   * Inserts a bar in a new fan.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> if the bar is inserted in the fan;
   *   <li> <tt>E_FAIL</tt> if an error occurs.
   * </ul>
   */
  HRESULT Insert (const unsigned int iBar);

  /**
   * Inserts a bar after a bar in an existing fan.
   * If the previous bar is followed by another bar, then the bar is inserted between these two bars
   * and the inserted bar becomes adjacent to the two bars.
   * @param iPreviousBar
   *   The previous bar in the fan.
   * @param iBar
   *   The bar to insert. The bar should not already be in the fan around the node.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> if the bar is inserted in the fan;
   *   <li> <tt>E_FAIL</tt> if an error occurs.
   * </ul>
   */
  HRESULT InsertAfter (const unsigned int iPreviousBar, const unsigned int iBar);

  /**
   * Inserts a bar after a bar in an existing fan.
   * If the next bar is preceded by another bar, then the bar is inserted between these two bars
   * and the inserted bar becomes adjacent to the two bars.
   * @param iBar
   *   The bar to insert. The bar should not already be in the fan around the node.
   * @param iNextBar
   *   The next bar in the fan. It must be at the beginning of an open fan.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> if the bar is inserted in the fan;
   *   <li> <tt>E_FAIL</tt> if an error occurs.
   * </ul>
   */
  HRESULT InsertBefore (const unsigned int iBar, const unsigned int iNextBar);

  /**
   * Links two bars around the node.
   * The two bars must be adjacent to the node.  They cannot be linked to other bars.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> if the bars are linked successfully;
   *   <li> <tt>S_FALSE</tt> if the bars are already linked around the node;
   *   <li> <tt>E_FAIL</tt> or another error code if an error occurs.
   * </ul>
   */
  HRESULT LinkBars (const unsigned int iBarFrom, const unsigned int iBarTo);

  /**
   * Unlinks two bars around the node.
   * The two bars must be adjacent to the node.  They must be linked to each other.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> if the bars are unlinked successfully;
   *   <li> <tt>S_FALSE</tt> if the bars are already unlinked around the node;
   *   <li> <tt>E_FAIL</tt> or another error code if an error occurs.
   * </ul>
   */
  HRESULT UnlinkBars (const unsigned int iBarFrom, const unsigned int iBarTo);

  /**
   * Removes a bar from a fan.
   */
  HRESULT Remove (const unsigned int iBar);

public:

  // Fans.

  inline static unsigned int TOF () {return 0;}
  inline static unsigned int TCF () {return (unsigned int) -1;}

  /**
   * Returns <tt>TRUE</tt> if <tt>b</tt> is the tag of an open fan.
   */
  inline static CATBoolean IsTOF (const unsigned int b);

  /**
   * Returns <tt>TRUE</tt> if <tt>b</tt> is the tag of a closed fan.
   */
  inline static CATBoolean IsTCF (const unsigned int b);

  /**
   * Returns <tt>TRUE</tt> if <tt>b</tt> is a tag.
   */
  inline static CATBoolean IsTag (const unsigned int b);

  /**
   * Returns <tt>TRUE</tt> if the index points to a bar in a closed fan.
   */
  inline CATBoolean IsClosedFan (unsigned int index) const;

  /**
   * Returns <tt>TRUE</tt> if the index points to a bar in an open fan.
   */
  inline CATBoolean IsOpenFan (unsigned int index) const;

  /**
   * Given an index of a bar in the fan, finds the index addressing a bar at the beginning of the fan sequence.
   * @return
   *   Returns the index of the first bar in the fan.
   */
  unsigned int StartIndexOfFan (unsigned int index) const;

  /**
   * Given an index of a bar in the fan, finds the index addressing a bar at the end of the fan sequence.
   * @return
   *   Returns the index of the last bar in the fan.
   */
  unsigned int EndIndexOfFan (unsigned int index) const;

  /**
   * Returns <tt>TRUE</tt> if the index points to the beginning bar in an open fan.
   */
  CATBoolean IsStartIndexOfOpenFan (unsigned int index) const;

  /**
   * Returns <tt>TRUE</tt> if the index points to the end bar in an open fan.
   */
  inline CATBoolean IsEndIndexOfOpenFan (unsigned int index) const;

  /**
   * Reverses a fan, given the index of a bar in the fan.
   */
  HRESULT ReverseFan (unsigned int index);

public:

  // Bar services.

  /**
   * Increments/Decrements the index in a fan sequence.
   * These methods will loop around closed fans.
   * If there is no previous or next index, the method returns FALSE.
   */
  CATBoolean PreviousIndex (unsigned int& index) const;
  CATBoolean NextIndex (unsigned int& index) const;

  /**
   * Given a bar, returns the previous bar in the fan around the node.
   * If the input bar is not found or if there is no previous bar (open fan),
   * then the method returns 0.
   */
  unsigned int PreviousBarInFan (const unsigned int iBar) const;

  /**
   * Given a bar, returns the next bar in the fan around the node.
   * If the input bar is not found or if there is no next bar (open fan),
   * then the method returns 0.
   */
  unsigned int NextBarInFan (const unsigned int iBar) const;

private:

  // Private bar services.

  /**
   * Returns the next bar in the fan given an index or 0 if there is none (open fan.)
   */
  inline unsigned int GetNextBar (unsigned int index) const;

  /**
   * Returns the previous bar in the fan given an index or 0 if there is none (open fan.)
   */
  inline unsigned int GetPreviousBar (unsigned int index) const;

  /**
   * Joins two open fans.
   * @param indexFan0B
   *   The beginning index of the first fan.
   * @param indexFan0E
   *   The end index of the first fan.
   * @param indexFan1B
   *   The beginning index of the second fan.
   * @return
   *   Returns S_OK if the two fans are joined successfully and E_FAIL otherwise.
   */
  HRESULT JoinFans (unsigned int indexFan0B, unsigned int indexFan0E, unsigned int indexFan1B);

private:

  unsigned int _Count; // : 16;     // Number of bars if _ListSize is 0; Otherwise, number of elements on _List (>= number of bars.)
  unsigned int _ListSize; // : 16;  // Number of elements (bars + end-of-fan markers) the list can contain.

  union
  {
    unsigned int  _B;
    unsigned int* _List;
  } _Bar;

  enum
  {
    eInvalidCount = 0xFFFFFFFF   // 16 bits.
  };

  friend class CATPolyBarGraphNodeBTIterator;
  friend class CATPolyBarGraphNodeFanIterator;

private:

  /**
   * Resizes the list of bars adjacent to the node.
   */
  HRESULT Resize (const unsigned int iSize);

  /**
   * Finds a bar adjacent to the node.
   * @return
   * <ul>
   *   <li> NotFound: The bar is not found (-1 as unsigned int).
   *   <li> The index of the bar found in the list: _Bar._List.
   * </ul>
   */
  unsigned int FindBar (const unsigned int iBar) const;

};


inline CATPolyBarGraphNode::CATPolyBarGraphNode ()
{
  _Count = 0;
  _ListSize = 0;
  _Bar._List = 0;
}

inline CATPolyBarGraphNode::~CATPolyBarGraphNode ()
{
  Clear ();
}

inline CATPolyBarGraphNode& CATPolyBarGraphNode::operator=(CATPolyBarGraphNode&& node) {
  _Count = node._Count;
  _ListSize = node._ListSize;
  _Bar._List = node._Bar._List;

  node._Count = eInvalidCount;
  node._ListSize = 0;
  node._Bar._List = nullptr;

  return *this;
}

inline unsigned int CATPolyBarGraphNode::GetCount () const
{
  return _Count;
}

inline unsigned int CATPolyBarGraphNode::GetBarOrTag (unsigned int i) const 
{
  return _ListSize ? _Bar._List[i] : _Bar._B;  // Given that 0 <= i and i < _Count.
}

inline unsigned int& CATPolyBarGraphNode::GetBarOrTag (unsigned int i)
{
  return _ListSize ? _Bar._List[i] : _Bar._B;  // Given that 0 <= i and i < _Count.
}

inline CATBoolean CATPolyBarGraphNode::IsValid () const
{
  return _Count != eInvalidCount;
}

inline void CATPolyBarGraphNode::Invalidate (unsigned int n)
{
  Clear ();
  if (_Count == 0 && !_ListSize)
  {
    _Count = eInvalidCount;
    _Bar._B = n;
  }
}

inline unsigned int CATPolyBarGraphNode::Validate ()
{
  if (_Count == eInvalidCount)
  {
    _Count = 0;
    return _Bar._B;
  }
  return 0;
}

inline CATBoolean CATPolyBarGraphNode::IsTOF (const unsigned int b)
{
  return b == 0;
}

inline CATBoolean CATPolyBarGraphNode::IsTCF (const unsigned int b)
{
  return b == (unsigned int) -1;
}

inline CATBoolean CATPolyBarGraphNode::IsTag (const unsigned int b)
{
  return IsTOF (b) || IsTCF (b);
}

inline CATBoolean CATPolyBarGraphNode::IsEndIndexOfOpenFan (unsigned int index) const
{
  if (index == _Count - 1)
    return FALSE;
  else
    return IsTOF (_Bar._List[index+1]);
}

inline CATBoolean CATPolyBarGraphNode::IsClosedFan (unsigned int index) const
{
  index = EndIndexOfFan (index);
  return !IsEndIndexOfOpenFan (index);
}

inline CATBoolean CATPolyBarGraphNode::IsOpenFan (unsigned int index) const
{
  return !IsClosedFan (index);
}

inline unsigned int CATPolyBarGraphNode::GetNextBar (unsigned int index) const
{
  return NextIndex (index) ? _Bar._List[index] : TOF ();
}

inline unsigned int CATPolyBarGraphNode::GetPreviousBar (unsigned int index) const
{
  return PreviousIndex (index) ? _Bar._List[index] : TOF ();
}

#endif
