/* -*-c++-*- */
#ifndef CATPLMOperationBehavior_H
#define CATPLMOperationBehavior_H
//
// CATIA Version 6 Release 208
// Copyright   : Dassault Systemes 2009
//-----------------------------------------------------------------------------
// Description :
// C++ class header file for the class named "CATPLMOperationBehavior"
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Inheritance : CATPLMOperationBehavior
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//

/**
* @level Protected
* @usage U1
*/

#include "CATPLMModelBuilder.h"
#include "CATBooleanDef.h"
#include "CATPLMQEConstants.h"
#include "CATOmxDeprecated.h"

using namespace CATPLMQEConstants;

/**
 * Describe the behavior of an operation added to a CATPLMOperationContext:
 * -CATPLMOCFiltering describes whether or not the given operation must take into account the last applied filter.
 *  (@see CATPLMOperationContext::ApplyFilter):
 *       CATPLMOCFiltering::Disable: last applied filter is not taken into account for the given operation.
 *       CATPLMOCFiltering::Enable : last applied filter is taken into account for the given operation.
 * -CATPLMOCGraphFilterMode describe what action to perform with the result query:
 *       CATPLMOCGraphFilterMode::Append:       if an occurrence graph is pre-existing, it is reused.
 *                                              Occurrences resulting of the operations are added to the pre-existing occurrence graph.
 *       CATPLMOCGraphFilterMode::Flush:        if an occurrence graph is pre-existing, it is flushed before refreshing the model.
 *                                              Only the occurrences resulting of the operations execution is kept.
 *       CATPLMOCGraphFilterMode::Merge:        if an occurrence graph is pre-existing, the result of the query will be merged with
 *                                              that graph in pessimistic mode. Previous sub-graph will be fully recalculated.
 *       CATPLMOCGraphFilterMode::Update:       if an occurrence graph is pre-existing, the result of the query will be merged with
 *                                              that graph in optimistic mode. Previous sub-graph will be partially recalculated.
 *       CATPLMOCGraphFilterMode::PartialFlush: if an occurrence graph is pre-existing, the result of the query will be merged with
 *                                              that graph. Previous sub-graph will be flushed and entirely recalculated before refreshing the model.
 * -CATPLMOCOptimized describes whether or not the given operation must be optimized with previously logged operations.
 *  (@see CATPLMOperationContext::Log Optimization):
 *       CATPLMOCOptimized::Disable: current operation will never be optimized with previously logged operations.
 *       CATPLMOCOptimized::Enable : current operation might be optimized with previously logged operations.
 */
class ExportedByCATPLMModelBuilder CATPLMOperationBehavior
{
public:
  /**
   * constructors
   */
  CATPLMOperationBehavior() = default;
  CATPLMOperationBehavior(CATPLMOCFiltering iFiltering) : m_filtering(iFiltering) {}
  CATPLMOperationBehavior(CATPLMOCGraphFilterMode iGraphFilterMode) : m_graphFilterMode(iGraphFilterMode) {}
  CATPLMOperationBehavior(CATPLMOCFiltering iFiltering, CATPLMOCGraphFilterMode iGraphFilterMode) : m_filtering(iFiltering), m_graphFilterMode(iGraphFilterMode) {}
  CATPLMOperationBehavior(const CATPLMOperationBehavior& iOther) = default;
  CATPLMOperationBehavior(CATPLMOperationBehavior&& iOther) = default;

  // detructor
  ~CATPLMOperationBehavior() = default;

  // assignment
  CATPLMOperationBehavior& operator=(const CATPLMOperationBehavior& iOther) = default;
  CATPLMOperationBehavior& operator=(CATPLMOperationBehavior&& iOther) = default;

  void SetFiltering(CATPLMOCFiltering iOtherFiltering) { m_filtering = iOtherFiltering; }
  void SetGraphFilterMode(CATPLMOCGraphFilterMode iGraphFilterMode) { m_graphFilterMode = iGraphFilterMode; }
  void SetOptimized(CATPLMOCOptimized iOtherOptimized) { m_optimized = iOtherOptimized; }

  CATPLMOCFiltering          GetFiltering() const { return m_filtering; }
  CATPLMOCGraphFilterMode    GetGraphFilterMode() const { return m_graphFilterMode; }
  CATPLMOCOptimized          GetOptimized() const { return m_optimized; }

  int operator==(const CATPLMOperationBehavior& iOtherBehavior) const
  {
    return (m_filtering == iOtherBehavior.m_filtering) && (m_graphFilterMode == iOtherBehavior.m_graphFilterMode) && (m_optimized == iOtherBehavior.m_optimized) ? 1 : 0;
  }

  CATBoolean CanBeCompactedWith(const CATPLMOperationBehavior& iOtherBehavior) const
  {
    return (m_filtering == iOtherBehavior.m_filtering) && (m_graphFilterMode == iOtherBehavior.m_graphFilterMode) ? 1 : 0;
  }

private:

  CATPLMOCFiltering       m_filtering{ CATPLMOCFiltering::Enable };
  CATPLMOCGraphFilterMode m_graphFilterMode{ CATPLMOCGraphFilterMode::Merge };
  CATPLMOCOptimized       m_optimized{ CATPLMOCOptimized::Enable };
};

#endif
