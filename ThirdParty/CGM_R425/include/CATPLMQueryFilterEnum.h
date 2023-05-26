/**
* @level Protected
* @usage U3
*/
#ifndef __CATPLMQueryFilterEnum_h
#define __CATPLMQueryFilterEnum_h
#include "CATPLMServicesItf.h"
#include "CATSysErrorDef.h"
#include "CATOmxArray.h"

/**
* Definition of the possible query modes.
* <tt> Possible values:</tt>
* <dl>
* @param <tt>BASIC_QUERY</tt>   <dd> Query by attributes.
* @param <tt>EXPAND_QUERY</tt>  <dd> Query by object, returns all children.
* @param <tt>OPEN_QUERY</tt>    <dd> Query by object, returns all objects informations.
* @param <tt>VALIDITY_QUERY</tt><dd> Internal use, no documentation available.
* </dl>
*/
enum QueryMode { BASIC_QUERY = 0, EXPAND_QUERY = 1, OPEN_QUERY = 2, MATURITY_QUERY = 3, VALIDITY_QUERY = 4, UNINITIALIZED_QUERY = 5, NAVIGATE_QUERY = 6 };

/**
* Definition of the possible query info.
* <tt> Possible values:</tt>
* <dl>
* @param <tt>PLMQY_ATTRIBUTES</tt>   <dd> attribute.
* @param <tt>PLMQY_EXTENSIONS</tt>  <dd> Extension.
* @param <tt>PLMQY_STREAMS</tt>    <dd> Stream.
* @param <tt>PLMQY_RELATIONS</tt><dd> SemanticRelation.
* @param <tt>PLMQY_PATHTYPES</tt><dd> path type.
* </dl>
*/
enum QueryInfo { PLMQY_ATTRIBUTES = 0, PLMQY_EXTENSIONS = 1, PLMQY_STREAMS = 2, PLMQY_RELATIONS = 3, PLMQY_PATHTYPES = 4 };

class ExportedByCATPLMServicesItf CATPLMOrderQueryInfo
{
  friend class FilterGenericClauses;
private:
  static CATOmxArray<int> Get();
};

/**
* Definition of the possible query info.
* <tt> Possible values:</tt>
* <dl>
* @param <tt>PLMQY_ALL</tt>   <dd> all.
* @param <tt>PLMQY_NONE</tt>  <dd> none.
* @param <tt>PLMQY_ONLYEXTNAME</tt>  <dd> Restricted usage to PLMQY_EXTENSIONS.
* @param <tt>PLMQY_PUREPATHTYPE</tt>  <dd> Restricted usage to PLMQY_PATHTYPES (PLMQY_PATHTYPES, PLMQY_PUREPATHTYPE):
                                                 Path types that don't inherit from SemanticRelation are returned (<=>pure path type).
                                                 Path types that inherit from SemanticRelation are NOT returned.
                                                 All attributes are returned.
* @param <tt>PLMQY_PUREPATHTYPE_ID_ONLY</tt><dd> Restricted usage to PLMQY_PATHTYPES (PLMQY_PATHTYPES, PLMQY_PUREPATHTYPE_ID_ONLY):
                                                 Path types that don't inherit from SemanticRelation are returned (<=>pure path type).
                                                 Path types that inherit from SemanticRelation are NOT returned.
                                                 Only id is returned.
* @param <tt>PLMQY_ALLPATHTYPE_ID_ONLY</tt> <dd> Restricted usage to PLMQY_PATHTYPES (PLMQY_PATHTYPES, PLMQY_ALLPATHTYPE_ID_ONLY):
                                                 Path types that don't inherit from SemanticRelation are returned (<=>pure path type).
                                                 Path types that inherit from SemanticRelation are returned too.
                                                 Only id is returned.
* @param <tt>PLMQY_SR_ID_IDREL_ONLY</tt>    <dd> Restricted usage to PLMQY_PATHTYPES (PLMQY_PATHTYPES, PLMQY_SR_ID_IDREL_ONLY):
                                                 Path types that don't inherit from SemanticRelation are not returned (<=>pure path type).
                                                 Path types that inherit from SemanticRelation are returned
                                                 Only id/idrel are returned.
  WARNING WARNING WARNIG: Today, please don't use (PLMQY_PATHTYPES, PLMQY_ALL_PATHTYPE) and (PLMQY_PATHTYPES, PLMQY_ALL_PATHTYPES_ID_ONLY), functionality is not fully implemented.
* </dl>
*/
enum QueryValue { PLMQY_ALL = 0, PLMQY_NONE = 1, PLMQY_ONLYEXTNAME = 2, PLMQY_PUREPATHTYPE = 3, PLMQY_PUREPATHTYPE_ID_ONLY = 4, PLMQY_ALLPATHTYPE_ID_ONLY = 6, PLMQY_SR_ID_IDREL_ONLY = 7 };

/**
* Definition of the possible Filtered Expand behavior. (target = element which fill the filter conditions)
* <tt> Possible values:</tt>
* <dl>
* @param <tt>NO_STOP</tt>       <dd> Full paths are returned (only DEPTH can limit them).
* @param <tt>STOP_AT_FIRST</tt> <dd> Paths are cut at the first target element encountered.
* @param <tt>STOP_AT_LAST</tt>  <dd> Paths are cut to the lastest target element encountered.
* @param <tt>LEAF_ONLY</tt>     <dd> A path is returned if and only if the leaf element is targetted.
* </dl>
*/
enum FilteredExpandLimit { NO_STOP = 0, STOP_AT_FIRST = 1, STOP_AT_LAST = 2, LEAF_ONLY = 3 };

/**
* @deprecated
* Please use CATPLMQueryFilterEnum::SearchMode
*/
enum SearchMode { NORMAL_QUERY = 0, SEARCH_QUERY = 1, INDEX_QUERY = 2, SIMILAR_QUERY = 5 };

/**
* Definition of the possible modes for iterative filter.
* <tt> Possible values:</tt>
* <dl>
* @param <tt>Remove</tt>  <dd> The iterative filter will remove the input path.
* @param <tt>Keep</tt>  <dd> The iterative filter will keep the input path.
* </dl>
*/
namespace Iterative { enum Mode { Remove, Keep }; };

/**
* Possible direction for an expand on relationship.
* <tt> Possible values:</tt>
* <dl>
* @param <tt>Direct</tt>  <dd> Relationship expand in the from to to direction.
* @param <tt>Reverse</tt>  <dd> Relationship expand in the to to from direction.
* @param <tt>Both</tt>  <dd> Relationship expand both direction.
* </dl>
*/
namespace ExpandDirection { enum Mode { Default, Direct, Reverse, Both }; };

/**
* Should elements without any attributes in the select clause be returned or not?.
* <tt> Possible values:</tt>
* <dl>
* @param <tt>TrimElementWithoutSelection</tt>  <dd> This is the default.
*        To notice that in case of push expand, only the leaf part of the branch is trimed.
*        As soon as an element with selected attributes is found, the rest of the branch is unconditionally returned.
* @param <tt>NoTrim</tt>  <dd> The complete graph is returned, even element without selected attributes.
* </dl>
*/
namespace TrimMode { enum Mode { TrimElementWithoutSelection, NoTrimElementWithoutSelection }; };

/**
* This is the list of operators that can be used to express condition on attribute value
* And conversion from / to string
*/
namespace RelationalOperator
{
  enum Op
  {
    //  enum            value     prefered string        synonymous (also understood)
    UNKNOWN_OP = 0,             // ? 
    LIKE_OP = 1,                // LIKE                like
    NOT_LIKE_OP = 2,            // NOT_LIKE            not_like 
    GT_OP = 3,                  // GT                  > , gt
    GE_OP = 4,                  // GE                  GTEQ, >= , ge
    LT_OP = 5,                  // LT                  < , lt
    LE_OP = 6,                  // LE                  LTEQ, >= , le
    EQ_OP = 7,                  // EQ                  = , == , eq
    NOT_EQ_OP = 8,              // NOT_EQ              != , not_eq
    IN_LIST_OP = 9,             // IN                  in
                                // operator IN to use on mono-valuated attributes with a list as input
                                // to get objects whose attribute's value is in the list 
                                CONTAINS_ONEOF_OP = 10,     // CONTAINS_ONEOF      contains_oneof
                                                            // operator CONTAINS_ONEOF to use on multi-valuated attributes with a single value as input
                                                            // to get objects whose attribute's multivalue value contains this value
                                                            BETWEEN_OP = 11,            // BETWEEN             between
                                                            NOT_BETWEEN_OP = 12,        // NOT_BETWEEN         not_between
                                                            NOT_CONTAINS_ONEOF_OP = 13, // NOT_CONTAINS_ONEOF  not_contains_oneof 
                                                                                        // DON T USE IT. USAGE RESTRICTED TO INFRASTRUCTURE TEAM. USAGE RESTRICTED TO INFRASTRUCTURE TEAM. USAGE RESTRICTED TO INFRASTRUCTURE TEAM.
                                                                                        // XMQL ONLY! NOT IMPLEMENTED in PLMQL! PERMANENT RESTRICTION FOR PLMQL!
                                                                                        // operator NOT_CONTAINS_ONEOF to use on multi-valuated attributes with a single value as input
                                                                                        // to get objects whose attribute's multivalue value contains this value
                                                                                        NULL_OP = 14,               // DEPRECATED 
                                                                                                                    // Usage restricted to odt: it works only with monovaluated DATE and STRING on windows (XMQL) and on monovaluated STRING on linux (PLMQL)
                                                                                                                    NOT_NULL_OP = 15            // DEPRECATED 
                                                                                                                                                // Usage restricted to odt: it works only with monovaluated DATE and STRING on windows (XMQL) and on monovaluated STRING on linux (PLMQL)
  };

  // convert the prefered string or any of its synonymous to the enum
  ExportedByCATPLMServicesItf HRESULT FromString(const char *, Op& oRelOp);

  // Return the "prefered" string of the operator
  ExportedByCATPLMServicesItf const char * ToString(Op iRelOp);
};

namespace SemanticRelation
{
  /**
  * Definition of the possible Semantic Relation modes.
  * <tt> Possible values:</tt>
  * <dl>
  * @param <tt>FullSR</tt>    <dd> SRv1 mode. PLMIDs + Synchro status + Data
                              <dd> SRv2 mode. PLMIDs + Synchro status + Data + Link on attribute
  * @param <tt>LightSR</tt>   <dd> SRv1 mode. PLMIDs + NO Synchro status + Data (Synchro status computed on client side)
                              <dd> SRv2 mode. PLMIDs + NO Synchro status + Data + Link on attribute (Synchro status computed on client side)
  * @param <tt>SlimSR</tt>    <dd> SRv3 mode. PLMIDs only
  * @param <tt>Mixed</tt>     <dd> Mixed mode: SRv1 / SRv2 / SRv3 - Inconsistent mode.
  * @param <tt>None</tt>      <dd> No Semantic Relation mode.
  * </dl>
  */
  enum Mode
  {
    FullSR,     // SRv1
    LightSR,    // SRv2
    SlimSR,     // SRv3
    MixedSR,    // Mix of SRv1 / SRv2 / SRv3 - Inconsistent mode.
    NoneSR      // No Semantic Relation
  };

  ExportedByCATPLMServicesItf const char * ToString(Mode iMode);
}

namespace CaseSensitivity
{
  enum eProp
  {
    eCaseSensitive,
    eCaseInsensitive,
    eNone
  };
};

// C Create R Read U Update D Delete
namespace TableViewsCRUD
{
  enum eProp
  {
    eNone = 0,
    eMaster = 1,
    eDetail = 2,
    eView = 3
  };
};

namespace ConditionalOperator
{
  enum eProp
  {
    eAnd = 0,
    eOr = 1,
    eNone = 3
  };
};

namespace CATPLMQueryFilterEnum
{
  /**
  * Definition of the possible query modes.
  * <tt> Possible values:</tt>
  * <dl>
  * @param <tt>BASIC_QUERY</tt>   <dd> Query by attributes.
  * @param <tt>EXPAND_QUERY</tt>  <dd> Query by object, returns all children.
  * @param <tt>OPEN_QUERY</tt>    <dd> Query by object, returns all objects informations.
  * @param <tt>VALIDITY_QUERY</tt><dd> Internal use, no documentation available.
  * </dl>
  */
  enum QueryMode { BASIC_QUERY = 0, EXPAND_QUERY = 1, OPEN_QUERY = 2, MATURITY_QUERY = 3, VALIDITY_QUERY = 4, UNINITIALIZED_QUERY = 5, NAVIGATE_QUERY = 6 };

  /**
  * Definition of the possible Search modes.
  * <tt> Possible values:</tt>
  * <dl>
  * @param <tt>NORMAL_QUERY</tt>  <dd> Query on the VPLM server.
  * @param <tt>SEARCH_QUERY</tt>  <dd> Query on the Indexed server from client.
  * @param <tt>INDEX_QUERY</tt>   <dd> Expand on the Indexed server from server (CV servlet).
  * @param <tt>SIMILAR_QUERY</tt> <dd> Looks in index to find a similar element.
  * </dl>
  */
  enum SearchMode { NORMAL_QUERY = 0, SEARCH_QUERY = 1, INDEX_QUERY = 2, SIMILAR_QUERY = 5 };

  /**
  * Definition of the possible open modes.
  *========================================================
  *        Possible values:  NORMAL / SELECTCLAUSEMAPPING
  *========================================================
  * -> NORMAL :
  *
  *  When using normal mode, a separate request is sent for each kind of type. That means if you have
  *  N differents types, you will send N requests.
  *
  *======================================
  *
  * -> SELECTCLAUSEMAPPING :
  *
  *  Tries to reduce the number of requests sent by mapping requests with select clause attributes. That's mean if
  *  several types have:
  *                       1/ defined the same select clause
  *                       2/ metatype is Relation or Business
  *                       3/ have the same metatype
  * then :
  *                       1/ we gather objects in the same request
  *                       2/ we send only one request
  *
  * </dl>
  */
  enum OpenMode { NORMAL = 0, SELECTCLAUSEMAPPING = 1 };

  /**
  * Definition of the possible modes for explicit filter.
  * <tt> Possible values:</tt>
  * <dl>
  * @param <tt>Remove</tt>  <dd> The explicit filter will remove the input path.
  * @param <tt>Keep</tt>  <dd> For future use : the keep mode is not yet implemented.
  * </dl>
  */
  enum ExplicitMode { Remove = 0 /*, Keep = 1 */ };

  /**
  * Definition of the possible behavior for explicit filter.
  * <tt> Possible values:</tt>
  * <dl>
  * @param <tt>Physical</tt>  <dd> The input path will match on physical id.
  * @param <tt>Major</tt>  <dd> The input path will match on major id, allowing minor version of object to react to the filter.
  * </dl>
  */
  enum ExplicitBehavior { Physical = 0, Major = 1 };
};

#endif
