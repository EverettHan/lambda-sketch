#pragma once

#include <UIVCoreTools.h>
#include <CATSYPEventSubscriberEventListener.h>
#include <nlohmann/json.hpp>
#include <functional>
#include <CATSYPDataSourceParameters.h>
/**
 * @brief The base class of DataSource allowing model view classes to request on the fly needed data, with an asynchronous protocol. *
 */
class ExportedByUIVCoreTools CATSYPAbstractDataSource : public CATSYPEventSubscriberEventListener
{
  CATDeclareClass;
public:
  /**
   * @brief This method is called by a view to request model items.
   *
   * @param i_request a TreeNodesRequestParameters specifying the part of the structure being requested
   * @param i_successCallback a lambda function that has to be called when the data is available. It can be called directly in the method if the data is synchronously found, or later on in async cases.
   */
  virtual void RequestModelItems(const CATSYPDataSourceParameters::TreeNodesRequestParameters &i_request, std::function<void(const CATSYPDataSourceParameters::TreeNodesAnswerParameters &)> i_successCallback) = 0;
  virtual void RequestModelChange(const CATSYPDataSourceParameters::ModelChangeParameters &i_request, std::function<void(const CATSYPDataSourceParameters::ModelChangeParameters &)> i_correctionCallback) = 0;
  virtual void RequestSelectionChange(const CATSYPDataSourceParameters::SelectionChangeParameters &i_request, std::function<void(const CATSYPDataSourceParameters::SelectionChangeParameters &i_selectionAnswer)> i_correctionCallback) {}

  /**
   * Get the @c ModelChanged event.
   *
   * The @c ModelChanged event is dispatched from the data source when the model has changed (added node, removed node, node attributes updated)
   *
   * @par EventProperties
   *   - Name: @c "ModelChanged"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPModelChangedEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent *ModelChanged();

  /**
  * Get the @c SelectionChanged event.
  *
  * The @c SelectionChanged event is dispatched from the data source when the selection has changed (nodes added to the selection, nodes removed from the selection)
  *
  * @par EventProperties
  *   - Name: @c "SelectionChanged"
  *   - Type of propagation: @c NoPropagation
  *   - Type of argument: @ref CATSYPSelectionChangedEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on
  * the returned pointer.
  */
  static CATSYPEvent *SelectionChanged();
};
