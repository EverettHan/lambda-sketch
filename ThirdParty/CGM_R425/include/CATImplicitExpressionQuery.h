#ifndef CATImplicitExpressionQuery_H
#define CATImplicitExpressionQuery_H

#include "GMScalarFieldsOperators.h"

#include "CATBoolean.h"
#include "CATUnicodeString.h"

// CGM
#include "CATICGMObject.h"

// Scalar Fields
#include "SFTypes.h"
#include "CATImplicitResource.h"
#include "CATSFDagNodeQuery.h"

// STD
#include <memory>

namespace SF
{
  class SFDagNode;
  class SFResourceResolver;

  using  SFDagNodePtr = std::shared_ptr<SFDagNode>;
  using  SFResourceResolverPtr = std::shared_ptr<SFResourceResolver>;
}

/**
 * CATImplicitExpressionQuery contains a set of services which allow you get information
 * on the implicit Direct Acyclic Graph (DAG) used to generate a scalar field.
 *
 * If you build an instance of this from an existing DAG root it will provide
 * those services on the provided DAG.
 *
 * If you build an instance of this class giving directly an implicit expression
 * it will build the DAG for you. Based on whether you have provided a resolver
 * or not the DAG will be in fullyResolved or unresolvedRef state, meaning the nodes
 * of the DAG associated with dependencies or resources will be either in unresolved
 * (no pointers to CGMObjects or resources) or resolved state.
 * The DAG is obviously much quicker to build in unresolvedRef state, i.e. when
 * not providing a resolver as resolving some of the DAG nodes requires to build
 * their associated signed distance field.
 * If on the other hand you need to access the pointers of the dependencies and resources
 * building the CATImplicitExpressionQuery through the CATImplicitBodyQuery is probably
 * the best way as it will build and set the resolver for you.
 *
 * The most convenient way to build an instance of this class is using
 * the CATImplicitBodyQuery::GetExpressionQuery to which you can
 * give a CATImplicitExpressionQuery::State to control in which state you want
 * to get your expression query.
 */
class ExportedByGMScalarFieldsOperators CATImplicitExpressionQuery
{
  friend class CATImplicitBodyQuery;
  friend class CATImplicitExpressionBuilder;

public:
  /**
   * See the discussion the class description.
   */
  enum class State { fullyResolved, unresolvedRef, inError};


  typedef std::unique_ptr<CATImplicitExpressionQuery>      UPtr;
  typedef std::shared_ptr<CATImplicitExpressionQuery>      Ptr;

  /**
   * ctor
   *
   * You should probably not use this constructor directly but go through CATImplicitBodyQuery
   * see description of this class and CATImplicitBodyQuery for more details on why it
   * might be more convenient.
   *
   * To build a CATImplicitExpressionQuery you need to provide the expression you want
   * to query and an optional resolver. If you don't provide the resolver you
   * will still be able to navigate the DAG that was built from the expression
   * but you won't have access to any of it's dependencies and resources.
   * This can be useful if you treat your expression as a template of expression
   * that you want to use in different contexts.
   * If on the other hand you want to query the DAG dependencies and resources with
   * respect to a specific context you have to provide it's associated resolver.
   * And in fact it is what CATImplicitBodyQuery does for you. Here this simple
   * constructor won't allow you to do that.
   */
  CATImplicitExpressionQuery(const SF::SFExpression& iImplicitExpression);

  /**
   * Default copy ctor
   */
  CATImplicitExpressionQuery(CATImplicitExpressionQuery&& iOther) noexcept;

  /**
   * dtor
   */
  virtual ~CATImplicitExpressionQuery();

  /**
   * Get an expression path for the root of the DAG. You don't access DAG nodes directly
   * instead you get an opaque handle to them. It is through these handle that you can retrieve
   * information on the nodes via the APIs of CATImplicitExpressionQuery.
   *
   * The handles are designed in a way so that with some additions they might become stable links
   * to a specific node of in a specific graph that can be persisted along with the graph.
   * But as there is no use case for this at this point they those additions are not there yet. If you
   * need to use them that way please talk to us first.

   * @return an SF::SFExpressionPath which is an opaque handle to the node of the graph.
   */
  const SF::SFExpressionPath GetRootPath();

  /**
   * Get the expression associated with this instance of CATImplicitExpressionQuery
   *
   * @return an SFExpresion that you can use with all the APIs able to consume directly
   * SFExpression instances. You should not try to keep or persist the SFExpression
   * for longer that your work session, if you need persistence of implicit specifications
   * you have to really on the operators that do put those specification on specific volumes
   * of a partitioned body.
   */
  const SF::SFExpression& GetExpression();

  /**
   * Get the expression associated with this instance of CATImplicitExpressionQuery
   * in a source representation that can be inspected. This is a convenience you should
   * not rely on that source representation for anything or persist it anywhere.
   *
   * @return a source representation of an SFExpression (mainly for inspection purposes
   *  if needed, don't use for anything else).
   */
  const CATUnicodeString  GetExpressionAsUnicodeString();

  /**
   * Get the expressionId if the provided expression path is
   * associated with a resourceToSF node or a dependency (a specific type
   * of resources).
   * Else you will get an empty expression which basically mean the node pointed by
   * the expression path has no associated ExpressionId.
   *
   * @param[in] iExpressionPath, the handle of the node for which you want to retrieve the expressionId.
   *
   * @return an SFExpression containing the expressionId.
   */
  const SF::SFExpression& GetExpressionId(const SF::SFExpressionPath& iExpressionPath);

  /**
   * Same as GetExpressionId but returns it as a CATUnicodeString. If you want to query yourself the
   * dependencies and resources of your implicit surface you can use this expressionId. Still you should
   * bear in mind that if you have retrieved a fullyResolved CATImplicitExpressionQuery you can
   * already retrieves all the dependencies and resources using the associated Get*** methods of this
   * class.
   *
   * @param[in] iExpressionPath, the handle of the node for which you want to retrieve the expressionId.
   *
   * @return a CATUnicodeString containing the expressionId.
   */
  const CATUnicodeString GetExpressionIdAsUnicodeString(const SF::SFExpressionPath& iExpressionPath);

  /**
   * Get the state of the expression query. If a resolver was provided upon creation,
   * the DAG dependencies and resources should be resolved in the context of that resolver
   * (unless they are not defined in that context) and GetState will return fullyResolved.
   * If the CATImplicitExpresionQuery was built without providing a resolver .i.e in not fully
   * resolved, then all the dependencies and resources will be unresolved, GetState will
   * return unresolvedRef.
   *
   * @return a CATImplicitExpressionQuery::State indicating if the CATImplicitExpressionQuery
   *  was built with a resolver or not and thus if dependencies and resources have a chance
   *  to be resolved (provided they are defined in the context of the provided resolver) or
   *  if no resolution was attempted.
   */
  CATImplicitExpressionQuery::State GetState();

  /**
   * Get you a valid expression path for the left hand child of the node
   * specified via iExpressionPath if any,
   *
   * @param[in] iExpressionPath, the path to the node of which you want to query
   *  left hand side child.
   *
   * @return the SFExpressionPath of the left hand side child.
   */
  SF::SFExpressionPath GetLHChild(const SF::SFExpressionPath& iExpressionPath);

  /**
   * Get you a valid expression path for the right hand child of the node
   * specified via iExpressionPath if any,
   *
   * @param[in] iExpressionPath, the path to the node of which you want to query
   *  right hand side child.
   *
   * @return the SFExpressionPath of the right hand side child.
   */
  SF::SFExpressionPath GetRHChild(const SF::SFExpressionPath& iExpressionPath);

  /**
   * Give you the type of node pointed by the provided expression path.
   *
   * @param[in] iExpressionPath, the path to the node of which you want to retrieve
   *  the type.
   *
   * @return SFNodeType of the node specified by iExpressionPath
   */
  SF::SFNodeType GetType(const SF::SFExpressionPath& iExpressionPath);

  /**
   * GetDependency get the dependency of a specific node of the implicit expression DAG with respect to the specified
   * implicit surface. Bear in mind that you could potentially want to associate the same expression to different
   * implicit surface and that it is only within a specific context that these can get resolved. You can see an expression
   * as a sort of template which gets complete only when associated with a specific context (for example an implicit surface).
   * The method return nullptr if the specified node is not a dependency node (you should check the type first).
   *
   * WARNING: If the CATImplicitExpression was built without resolver in unresolvedRef mode then you will retrieve
   * a nullptr even if it is a dependency node. See discussion in this class description for more details on unresolvedRef mode
   * versus fullyResolved mode.
   *
   * @param[in] iExpressionPath, the path to the dependency node for which you want to retrieve
   *  a pointer to the associated CGM object.
   *
   * @return a pointer to the CATICGMObject associated with the specified node
   */
  CATICGMObject* GetDependency(const SF::SFExpressionPath& iExpressionPath);

  /**
   * GetResource get the resource on which a specific node of the implicit expression DAG depends on with respect to the specified
   * implicit surface. Bear in mind that you could potentially want to associate the same expression to different
   * implicit surface and that it is only within a specific context that these can get resolved. You can see an expression
   * as a sort of template which gets complete only when associated with a specific context.
   *
   * There is a distinction between CATICGMObject which are called dependencies (consistent with some naming with CGM for
   * dependencies of CGM objects) and what we call resources which are also dependencies of the DAG with respect to a specific
   * context but which are not CATICGMObjects themselves.
   *
   * The method return nullptr if the specified node is not a resource node (you should check the type first).
   *
   * WARNING: If the CATImplicitExpression was built without resolver in unresolvedRef mode then you will retrieve
   * a nullptr even if it is a resource node. See discussion in this class description for more details on unresolvedRef mode
   * versus fullyResolved mode.
   *
   * @param[in] iExpressionPath, the path to the resource node for which you want to retrieve
   *  a pointer to the associated CATImplictiResource.
   *
   * @return a pointer to the CATImplcitResource associated with the specified node
   */
  CATImplicitResource* GetResource(const SF::SFExpressionPath& iExpressionPath);

  /**
   * Give you the resource type guid associated with the node pointed by the
   * provided expression path if it happen to be a resourceToSF node. Otherwise
   * you will get a GUID full of nulls.
   *
   * Resources are a bit special as far as persistence is concerned. Dependencies
   * are CGM Object and thus are managed via the usual dependency mechanism. Resources
   * instead are not CGM Objects but are still required to fully evaluated the DAG. Bar graphs
   * are good example of this. They are not per se CGM Objects but still need to be persisted
   * along with CATImplicitManifold like the CATImplicitSurface. For this reason they are
   * in fact persisted along with the CATImplicitSurface for example. To give a rough idea
   * resources are a form of dependencies of the graph that are not CGM objects, not geometries or
   * topologies or CATLaw and that are not meant to be shared by several CATImplicitManifold/CATImplicitSurface.
   * To be sure to uniquely identify types of resources we use globally unique identifiers like the
   * one used to uniquely identify COM interfaces and their implementations.
   *
   * @param[in] iExpressionPath, the path to the resource node for which you want to retrieve
   *  a type GUID.
   *
   * @return the GUID associated with the type of resources associated with the specified node.
   */
  const GUID GetResourceType(const SF::SFExpressionPath& iExpressionPath);

  /**
   * Give you the resource type tag (a string) associated with the node pointed by the
   * provided expression path if it happen to be a ResourceToSF node. Otherwise
   * you will get an empty string.
   * When you define new class deriving from ResourceToSF you obviously have to ensure
   * you are not reusing an existing tag. At some point you have a resolver in order
   * to instantiate all those resource. One of its role is to verify that
   * you are not asking him to resolves resource with conflicting type tag (or GUID, which is less likely :)).
   * See comments on ResourceToSF class.
   *
   * Although this is internal information this method is available here to ease inspection
   * of expression if needed. The type tag can be found in the source representation of the
   * expression that you can also retrieve via this API but just like the source representation
   * of the expression we don't guarantee this will be stable in time (even though there won't be much changes maybe).
   *
   * @param[in] iExpressionPath, the path to the resource node for which you want to retrieve
   *  a type Tag.
   *
   * @return the type tag
   */
  const CATUnicodeString GetResourceTypeTag(const SF::SFExpressionPath& iExpressionPath);

  /**
   * If expression path is associated with a node which bear a value this method
   * will return it. Will return NASFScalar other wise. This is useful for example to
   * retrieve value of constant parameters in the DAG with are nodes of type SCALAR
   *
   * @param[in] iExpressionPath, the path to the resource node for which you want to retrieve
   *  a value.
   *
   * @return SFScalar value associated with the node if any NASFScalar otherwise:
   */
  const SF::SFScalar GetValue(const SF::SFExpressionPath& iExpressionPath);

  /**
   * If expression path is associated with a node which has a specific node query implemented then
   * this method will return it
   *
   * @param[in] iExpressionPath, the path to the resource node for which you want to retrieve
   *  a value.
   *
   * @return 
   */
  const CATSFDagNodeQuery::Ptr GetNodeQuery(const SF::SFExpressionPath& iExpressionPath);

  /**
   * GetDependenciesByType will return the list of resources of the specified type along with the expression paths of the associated
   * node of the implicit expression DAG along with the associated expression paths.
   * This method is to be used for resources that are CGM objects, for other types of resources (ex Bar Graph)
   * use GetResourcesByType instead. oExpressionPaths[i-1] is associated with oCGMResources[i] with i in
   * [1..oCGMResourcesSize]
   *
   * @param[out] oCGMResources, list of pointers to CGM Object
   * @param[out] oExpressionPaths, list of expression paths.
   *
   * @return S_OK if everything could proceed as expected.
   */
  HRESULT GetDependenciesByType(const GUID& iResourceTypeGUID, CATLISTP(CATICGMObject)& oCGMResources, SF::SFExpressionPaths& oExpressionPaths);

  /**
   * GetFilteredDependenciesByType will return the raw list of resources used by the expression. GetDependencyByType can return several
   * time the same resources if it appears several time in the expression (with the associated expression paths) while this method
   * will filter out duplicates in the output.
   *
   * This method is to be used for resources that are CGM objects, for other types of resources (ex Bar Graph)
   * use GetResourcesByType instead. oExpressionPaths[i-1] is associated with oCGMResources[i] with i in
   * [1..oCGMResourcesSize]
   *
   * @param[out] oCGMResources, list of pointers to CGM Object
   * @param[out] oExpressionPaths, list of expression paths.
   *
   * @return S_OK if everything could proceed as expected.
   */
  HRESULT GetFilteredDependenciesByType(const GUID& iResourceTypeGUID, CATLISTP(CATICGMObject)& oCGMResources, SF::SFExpressionPaths& oExpressionPaths);

  /**
   * GetResourcesByType will return the list of resources of the specified type along with the expression paths of the associated
   * node of the implicit expression DAG. This method is to be used for resources that are not CGM objects (ex. BarGraph), for resources that
   * are CGM objects please check (GetDependenciesByType). oExpressionPaths[i-1] is associated with oResources[i] with i in
   * [1..oCGMResourcesSize]
   *
   * @param[out] oResources, list of pointers to CATImplicitResource
   * @param[out] oExpressionPaths, list of expression paths.
   *
   * @return S_OK if everything could proceed as expected.
   */
  HRESULT GetResourcesByType(const GUID& iResourceTypeGUID, ListPOfCATImplicitResource& oResources, SF::SFExpressionPaths& oExpressionPaths);

  /**
   * GetFilteredResourcesByType will return the raw list of resources of the specified. Each resource will be put once in the oResources
   * output if the same resource is used in several places of the DAG duplicates in the output are filtered. If you want instead
   * a complete list of the resources along with the occurrence in the DAG use GetFilteredDependenciesByType instead.
   * This method is to be used for resources that are not CGM objects (ex. BarGraph), for resources that
   * are CGM objects please check (GetDependenciesByType). oExpressionPaths[i-1] is associated with oResources[i] with i in
   * [1..oCGMResourcesSize]
   *
   * @param[out] oResources, list of pointers to CATImplicitResource
   * @param[out] oExpressionPaths, list of expression paths.
   *
   * @return S_OK if everything could proceed as expected.
   */
  HRESULT GetFilteredResourcesByType(const GUID& iResourceTypeGUID, ListPOfCATImplicitResource& oResources, SF::SFExpressionPaths& oExpressionPaths);

  /**
   * This method will write to the specified file a GraphViz file iFilePath.gv that you can visualize with the following command:
   * <Path to Graphviz folder>\bin\dot -Tpng filename.gv -o filename.png
   * (provided that you have GraphViz installed)
   *
   * Although GetExpressionAsUnicode provide a 'source' representation of the DAG it is not necessarily to use even
   * for introspections only, it might be much more easy to visualize you graph.
   *
   * WARNING ! Supported GraphViz format/version is 'dot - Graphviz version 2.47.0 (20210316.0004)'. There is no special guarantee
   * that this method will work fine for other version.
   *
   * @param iFilePath, name of the graph viz file that you want to write.
   *
   * @return S_OK if it was possible to write the file all right.
   */
  HRESULT DumpGraph(CATUnicodeString& iFilePath);

  /**
   * This method allows to retrieve nodes ' expression paths in a flexible way.
   * it should be called providing a function with the following signature:
   * bool QueryFct(SFDagNode& iNode)
   * and should return true if you want to get expression path for that node
   * in the oExpressionPaths collection.
   *
   * @param iQueryFct, see expected function signature above.
   * @parem oExpressionPaths, collection of paths associated with the selected nodes.
   *
   * @return S_OK if everything went fine. Please note that this doesn't guarantee
   * that you have any expression path in the returned collection, it obviously all
   * depend of your query.
   */
  template<typename QueryFct>
  HRESULT GetNodes(QueryFct iQueryFct, SF::SFExpressionPaths& oExpressionPaths)
  {
    HRESULT hr = E_FAIL;

    typedef std::pair<SF::SFDagNodePtr , SF::SFExpressionPath> SFDagNodeWithPath;

    SF::SFExpressionPath expressionPath;

    std::vector<SFDagNodeWithPath> nodesToProcess;
    nodesToProcess.push_back(SFDagNodeWithPath(GetRoot(), expressionPath));

    SFDagNodeWithPath nodeWithPath;
    SF::SFDagNodePtr node = nullptr;
    SF::SFDagNodePtr lhs = nullptr;
    SF::SFDagNodePtr rhs = nullptr;
    SF::SFExpressionPath lhsExpressionPath;
    SF::SFExpressionPath rhsExpressionPath;

    while(nodesToProcess.size() > 0) {
      nodeWithPath = nodesToProcess.back();
      nodesToProcess.pop_back();
      node = nodeWithPath.first;
      if(node.get()!=nullptr) {
        bool selected = iQueryFct(*(node.get()));
        if(selected) {
          oExpressionPaths.push_back(nodeWithPath.second);
        }

      } else {
        lhs = node->GetLhs();
        lhsExpressionPath = nodeWithPath.second;
        lhsExpressionPath.push_back(SF::SFDAGLeftBranch);
        rhs = node->GetRhs();
        rhsExpressionPath = nodeWithPath.second;
        rhsExpressionPath.push_back(SF::SFDAGRightBranch);

        nodesToProcess.push_back(SFDagNodeWithPath(lhs, lhsExpressionPath));
        nodesToProcess.push_back(SFDagNodeWithPath(rhs, rhsExpressionPath));
      }
    }

    hr = S_OK;
    return hr;
  }

private:
  SF::SFDagNodePtr            _root;
  SF::SFResourceResolverPtr   _resolver;

  const SF::SFExpression      _expression;
  const SF::SFExpression      _empty;

  /**
   * ctor
   *
   * You should not use this constructor directly, it is meant to be used
   * by CATImplicitExpressionBuilder so that can query the DAG being built
   * through the builder.
   */
  CATImplicitExpressionQuery(SF::SFDagNodePtr iRoot);

  /**
   * ctor
   *
   * You should probably not use this constructor directly but go through CATImplicitBodyQuery
   * see description of this class and CATImplicitBodyQuery for more details on why it
   * might be more convenient.
   *
   * To build a CATImplicitExpressionQuery you need to provide the expression you want
   * to query and an optional resolver. If you don't provide the resolver you
   * will still be able to navigate the DAG that was built from the expression
   * but you won't have access to any of it's dependencies and resources.
   * This can be useful if you treat your expression as a template of expression
   * that you want to use in different contexts.
   * If on the other hand you want to query the DAG dependencies and resources with
   * respect to a specific context you have to provide it's associated resolver.
   * And in fact it is what CATImplicitBodyQuery does for you.
   */
  CATImplicitExpressionQuery(const SF::SFExpression& iImplicitExpression, SF::SFResourceResolverPtr iResolver);

  /**
   * @nodoc
   * Will return the node of the DAG pointed by the provided expression path.
   *
   * @param iExpressionPath opaque handle to the node for which you want to retrieve SF::SFDagNode::Ptr
   */
  SF::SFDagNodePtr       GetNode(const SF::SFExpressionPath& iExpressionPath);

  /**
   * @nodoc

   * Get the root of the expression.
   */
  SF::SFDagNodePtr       GetRoot();

  /**
   * Set the expression to be parsed by you CATImplicitExpressionQuery instance
   * to parse the built DAG. Should return a valid expression path for the root
   * of thy DAG.
   */
  HRESULT Init();

};

#endif // CATImplicitExpressionQuery_H
