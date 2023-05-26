#pragma once

#include <UIVCoreTools.h>
#include <CATSYPEventSubscriberEventListener.h>
#include <nlohmann/json.hpp>
#include <functional>

namespace CATSYPDataSourceParameters
{
  /**
   * TreeNodeProperties
   */
  class ExportedByUIVCoreTools TreeNodeProperties
  {
  public:
    TreeNodeProperties(const nlohmann::json &i_json);
    TreeNodeProperties(
      const std::vector<int> &i_indexPath,
      const std::map<std::string, nlohmann::json> &i_properties,
      bool i_hasChildren);

    std::vector<int> GetIndexPath() const
    {
      return _indexPath;
    }

    const std::map<std::string, nlohmann::json>& GetProperties() const
    {
      return _properties;
    }

    bool HasChildren() const { return _hasChildren; }

    nlohmann::json ComputeJSON() const;

    bool operator==(const TreeNodeProperties &i_nodeProperties) const;

  private:

    std::vector<int> _indexPath;
    std::map<std::string, nlohmann::json> _properties;
    bool _hasChildren;
  };

  /**
   * SortAttributeModel
   */
  class ExportedByUIVCoreTools SortAttributeModel
  {
  public:
    enum Order
    {
      asc = 0,
      desc
    };

    SortAttributeModel(const nlohmann::json &i_json);

    const std::string &GetAttribute() const { return _attribute; }
    const SortAttributeModel::Order& GetOrder() const { return _order; }
    bool operator==(const SortAttributeModel& i_sortAttributeModel) const;

  private:

    std::string _attribute;
    SortAttributeModel::Order _order;
  };
  
  /**
   * TreeNodesRequestParameters
   */
  class ExportedByUIVCoreTools TreeNodesRequestParameters
  {
  public:
  
    // TODO complete this structure with filtering, grouping, etc...
    TreeNodesRequestParameters(const nlohmann::json &i_request);

    std::vector<std::string> GroupKeys() const { return _groupKeys; }

    int GetFirstNodeIndex() const { return _firstNodeIndex; }

    int GetLastNodeIndex() const { return _lastNodeIndex; }

    std::vector<SortAttributeModel> GetSortModel() const { return _sortModel; }
  
  private:

    std::vector<std::string> _groupKeys;
    int _firstNodeIndex;
    int _lastNodeIndex;
    std::vector<SortAttributeModel> _sortModel;
  };

  /**
   * TreeNodesAnswerParameters
   */
  class ExportedByUIVCoreTools TreeNodesAnswerParameters
  {
  public:
    TreeNodesAnswerParameters();
    TreeNodesAnswerParameters(const std::vector<TreeNodeProperties> &i_nodesProperties, int i_totalNumberOfNodes);

    void SetTreeNodesProperties(const std::vector<TreeNodeProperties> &i_nodesProperties) { _nodesProperties = i_nodesProperties; }
    const std::vector<TreeNodeProperties>& GetTreeNodesProperties() const { return _nodesProperties; }

    void SetTotalNumberOfNodes(int i_totalNumberOfNodes) { _totalNumberOfNodes = i_totalNumberOfNodes; }
    int GetTotalNumberOfNodes() const { return _totalNumberOfNodes; }

    nlohmann::json ComputeJSON() const;

    void SetNodeAsNotFound(bool i_notFound) {_notFound = i_notFound;}
    bool GetNodeAsNotFound() const {return _notFound;}

    bool operator==(const TreeNodesAnswerParameters &i_answer) const;

  private:
    // ADD the path of ID
    // ADD the offset (localIndex)
    std::vector<TreeNodeProperties> _nodesProperties;
    int _totalNumberOfNodes;
    bool _notFound;
  };

  /**
   * SelectionChangeParameters
   */
  class ExportedByUIVCoreTools SelectionChangeParameters
  {
  public:
    SelectionChangeParameters(){}
    SelectionChangeParameters(const nlohmann::json &i_json);
    SelectionChangeParameters(const std::vector<std::vector<int>> &i_addedNodes, const std::vector<std::vector<int>> &i_removedNodes);

    const std::vector<std::vector<int>>& GetAddedNodes() const { return _addedNodes; }
    const std::vector<std::vector<int>>& GetRemovedNodes() const { return _removedNodes; }

    bool operator==(const SelectionChangeParameters &i_answer) const;

    nlohmann::json ComputeJSON() const;

  private:
    std::vector<std::vector<int>> _addedNodes;
    std::vector<std::vector<int>> _removedNodes;
  };

  /**
   * ModelChangeParameters
   */
  class ExportedByUIVCoreTools ModelChangeParameters
  {
  public:
    ModelChangeParameters() {}
    ModelChangeParameters(const nlohmann::json &i_json);
    ModelChangeParameters(const std::string& i_operationType, const std::vector<TreeNodeProperties> &i_nodesProperties);

    /**
     * Returns the model change operation type. Can be equals to 'update'
     */
    const std::string &GetOperationType() const { return _operationType; }

    const std::vector<TreeNodeProperties>& GetTreeNodesProperties() const { return _nodesProperties; }

    nlohmann::json ComputeJSON() const;

    bool operator==(const ModelChangeParameters &i_answer) const;

  private:

    std::string _operationType;
    std::vector<TreeNodeProperties> _nodesProperties;
  };
};
