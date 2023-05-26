#pragma once

#include <VisuDialog.h>
#include <CATSYPAbstractDataSource.h>
#include <CATIVidMdl.h>
#include <CATVidMdlIndex.h>
#include <CATIVidMdlSelectionModel.h>
#include <nlohmann/json.hpp>

class CATVidMdlSortFilterProxy;
class CATVidMdlSelectionChangedEventArgs;
class CATVidMdlStructureChangedEventArgs;

class ExportedByVisuDialog CATSYPVidModelDataSource : public CATSYPAbstractDataSource
{
public:
  /**
   * @brief Construct a new CATSYPVidModelDataSource object
   *
   * @param i_spVidMdl
   */
  CATSYPVidModelDataSource(const CATIVidMdl_var &i_spVidMdl, const CATIVidMdlSelectionModel_var &i_spSelectionModel = NULL_var);
  
  /**
   * @brief Destroy the CATSYPVidModelDataSource object
   *
   */
  virtual ~CATSYPVidModelDataSource();

  /** @ Warning: The current implementation of the interface has some strong limitations (no sorting, no filtering yet). 
   *  @copydoc CATSYPAbstractDataSource#RequestModelItems
   */
  virtual void RequestModelItems(const CATSYPDataSourceParameters::TreeNodesRequestParameters &options, std::function<void(const CATSYPDataSourceParameters::TreeNodesAnswerParameters &)> i_successCallback) override;
  /** @copydoc CATSYPAbstractDataSource#RequestModelChange*/
  virtual void RequestModelChange(const CATSYPDataSourceParameters::ModelChangeParameters &i_request, std::function<void(const CATSYPDataSourceParameters::ModelChangeParameters &)> i_correctionCallback) override;
  /** @copydoc CATSYPAbstractDataSource#RequestSelectionChange*/
  virtual void RequestSelectionChange(const CATSYPDataSourceParameters::SelectionChangeParameters &i_request, std::function<void(const CATSYPDataSourceParameters::SelectionChangeParameters &)> i_correctionCallback) override;

  void SetPropertyToDisplayInTreeColumn(const std::string& i_propertyToDisplayInTreeColumn);
  std::string GetPropertyToDisplayInTreeColumn() const;

private:
  /**
   * @brief Callback that listen to CID model changes to push notification on the data source. 
   *
   * @param i_pSender the sender of the event, that is a CATIVidMdl implementation
   * @param i_pArgs the event args, that own information regarding structure modification
   */
  void _OnModelChanged(CATBaseUnknown *i_pSender, CATVidMdlStructureChangedEventArgs *i_pArgs);
  void _OnSelectionChanged(CATBaseUnknown * i_pSender, CATVidMdlSelectionChangedEventArgs * i_pArgs);
private:

  CATIVidMdl_var _spVidModel;
  CATIVidMdlSelectionModel_var _spSelectionModel;
  std::string _propertyToDisplayInTreeColumn;
  std::vector<CATVidMdlSortFilterProxy*>_pFilterProxies;
  std::vector<CATSYPDataSourceParameters::SortAttributeModel> _sortModel;
};
