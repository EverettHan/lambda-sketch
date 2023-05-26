#ifndef _VisSGObserverStructs_H_ 
#define _VisSGObserverStructs_H_


#include "VisSGUnionOfBitfields.h"
#include "vAssert.h"

#include <cstddef>
#include <cstdint>

class VisSGOrderTable;
class VisSGOccurrenceObserver;

/**
  Structure used to keep track of an Register/Unregister/RegisterSceneGraphEdge/UnregisterSceneGraphEdge/FeatureModified operation's lifecycle.
*/
class VisSGOperationContext
{
  friend class VisSGOccurrenceObserver;

public:
  VisSGOccurrenceObserver& GetObserver() const { return m_Observer;  }

protected:
  VisSGOperationContext(VisSGOccurrenceObserver& iObserver)
    : m_Observer(iObserver)
  {
  }

  ~VisSGOperationContext();
  VisSGOccurrenceObserver& m_Observer;
};

class VisSGOccurrenceUpdateData;

/**
  Structure used when triggering a feature update operation.
*/
class VisSGOccurrenceUpdateContext : public VisSGOperationContext
{
public:
  inline VisSGOccurrenceUpdateContext(VisSGOccurrenceObserver& iObs, VisSGOccurrenceUpdateData const& iUpdateData)
    : VisSGOperationContext(iObs)
    , m_UpdateData(iUpdateData)
  {
  }

  inline VisSGOccurrenceUpdateData const& GetUpdateData() const
  {
    return m_UpdateData;
  }

protected:
  VisSGOccurrenceUpdateData const& m_UpdateData;
};

/**
  Class to specialize regarding the kind of update operation.
*/
class VisSGOccurrenceUpdateData
{
public:
  // internal struct do not use!
  struct ModificationFlags {
    std::uint8_t m_RepGAS : 1;
    std::uint8_t m_SubGAS : 1;
    std::uint8_t m_Filter : 1;
    ModificationFlags()
      : m_RepGAS(false)
      , m_SubGAS(false)
      , m_Filter(false)
    {}
    ModificationFlags& operator|= (const ModificationFlags& iFlags)
    {
      m_RepGAS |= iFlags.m_RepGAS;
      m_SubGAS |= iFlags.m_SubGAS;
      m_Filter |= iFlags.m_Filter;
      return *this;
    }    
    ModificationFlags operator| (const ModificationFlags& iFlags) const
    {
      ModificationFlags ret(*this);
      ret |= iFlags;
      return ret;
    }   
    bool operator== (const ModificationFlags& iFlags) const
    {
      return m_RepGAS == iFlags.m_RepGAS
        && m_SubGAS == iFlags.m_SubGAS
        && m_Filter == iFlags.m_Filter;
    }
  };

public:
  inline VisSGFeatureType GetFeatureId() const
  {
    return m_FeatureShift;
  }

  inline FeatureFlag GetFeatureFlag() const
  {
    return 1 << static_cast<int> (m_FeatureShift);
  }

  inline bool IsModifiedRepGAS() const
  {
    return m_ModificationFlags.m_RepGAS;
  }

  inline bool IsModifiedSubGAS() const
  {
    return m_ModificationFlags.m_SubGAS;
  }
  
  inline bool IsModifiedFilter() const
  {
    return m_ModificationFlags.m_Filter;
  }

  // ModificationFlags is an internal structure which is supposed to evolve.
  // rather use the dedicated method to know what kind of flag has changed
  inline const ModificationFlags& GetModificationFlags() const
  {
    return m_ModificationFlags;
  }

protected:
  inline VisSGOccurrenceUpdateData(VisSGFeatureType iFeatureShift)
    : m_FeatureShift(iFeatureShift)
  {
  }

protected:
  VisSGFeatureType m_FeatureShift; 
  ModificationFlags m_ModificationFlags;
};


// Allow to keep track of different counters in 'VisSGObserver'.
// Mostly boilerplate code, but by using this class, it is possible to follow these
// counters while debugging using breakpoints.

// TBD @FPC1: Are these counters necessary? They seem to be used for the draw order.

class ObserverCounters
{
public:
  using count = std::size_t;

  ObserverCounters();
  ObserverCounters(const ObserverCounters&) = default;
  ObserverCounters& operator = (const ObserverCounters&) = default;
  ObserverCounters(ObserverCounters&&) = default;

  // Clears all data.
  void Clear();

  // Clears all but 'leavesCount'.
  void ClearUpdates();

  void SetNodesCreatedCount(count value) { nodesCreatedCount_ = value;  }
  count NodesCreatedCount() const { return nodesCreatedCount_; }
  void IncreaseNodesCreatedCount() { nodesCreatedCount_++; }
  void DecreaseNodesCreatedCount() { V_ASSERT(nodesCreatedCount_ >= 1); nodesCreatedCount_--; }

  void SetNodesModifiedCount(count value) { nodesModifiedCount_ = value; }
  count NodesModifiedCount() const { return nodesModifiedCount_; }
  void IncreaseNodesModifiedCount() { nodesModifiedCount_++; }
  void DecreaseNodesModifiedCount() { V_ASSERT(nodesModifiedCount_ >= 1); nodesModifiedCount_--; }

  void SetNodesMarkedForDeletionCount(count value) { nodesMarkedForDeletionCount_ = value; }
  count NodesMarkedForDeletionCount() const { return nodesMarkedForDeletionCount_; }
  void IncreaseNodesMarkedForDeletionCount() { nodesMarkedForDeletionCount_++; }
  void DecreaseNodesMarkedForDeletionCount() { V_ASSERT(nodesMarkedForDeletionCount_ >= 1);  nodesMarkedForDeletionCount_--; }

  void SetNodesDeletedCount(count value) { nodesDeletedCount_ = value;  }
  count NodesDeletedCount() const { return nodesDeletedCount_; }
  void IncreaseNodesDeletedCount() { nodesDeletedCount_++; }
  void DecreaseNodesDeletedCount() { V_ASSERT(nodesDeletedCount_ >= 1); nodesDeletedCount_--; }

  void SetLeavesCount(count value) { leavesCount_ = value; }
  count LeavesCount() const { return leavesCount_; }
  void IncreaseLeavesCount() { leavesCount_++; }
  void DecreaseLeavesCount() { V_ASSERT(leavesCount_ >= 1); leavesCount_--; }

private:
  count nodesCreatedCount_;
  count nodesModifiedCount_;
  count nodesMarkedForDeletionCount_;
  count nodesDeletedCount_;
  count leavesCount_;
};


#endif  // _VisSGObserverStructs_H_ 
