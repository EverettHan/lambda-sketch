//===================================================================
// COPYRIGHT Dassault Systemes 2018/06/07
//===================================================================
// CATPLMNLVSemantic.cpp
// Header definition of class CATPLMNLVSemantic
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2018/06/07 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATPLMNLVSemantic_H
#define CATPLMNLVSemantic_H

#include "CATPLMServicesNLV.h"
#include "CATUnicodeString.h"

class ExportedByCATPLMServicesNLV CATPLMNLVSemantic
{
public:

  /*
  This optional parameter enables to define answer JSON content.
  For this purpose you can select one of the 2 following possibilities:
  �	graph:       to return Semantic Version graph.
  �	attributes: to return list of created versions with detailed attributes only.
  If not set, return list of created versions including their ancestors.
  In case of graph activation, you can use any of the query parameters available to define Graph access:
  �	withCopyFrom
  �	withThumbnail
  �	withIsLastVersion
  �	withAttributes
  �	withAdjacentVersion
  */
  enum AnswerFormat
  {
    None,
    Graph, // to return Semantic Version graph.
    Attributes, // to return list of created versions with detailed attributes only.
    NullAnswerFormat
  };

  enum Intent
  {
    Null,              // Null
    Evolution,         // Main branch to describe next version replacement.
    Split,             // To provide parallel version edition.
    Fix,               // To provide local corrective solution of replacement. (Specialization of Split)
    Study,             // To initiate a branch in purpose of a design alternative. (Specialization of Split)
    Integrate,         // To declare version merge intent.
    SpinOff,           // Version initiated from one alternative from another Item.
    Import,            // To declare version merge intent cross family.
    Fore,              // �Insert before� version creation
    NoneIntent,        // Enable to define version family in case of duplicate
    Minor,             // Creation of a secondary version
    Last,              // Creation of a new version as last of current branch (ie creation of best so far version usable in replacement. process)
    LAST_SECONDARY,    // Creation of a new version as last of current branch, but not necessary from the last version
    New,               // Create a new version family preserving interoperability with current version. logicalid is kept
    Duplicate,         // Create a new version as a duplicate (no interoperability between versions). logicalid is not kept
    All
  };

  // Enum for Semantic version edges
  enum Operator
  {
    Null_Operator,
    add,
    remove
  };

  /*
   Provide a prefix to help re-identification mechanism in case of duplication. "DUPL_" is used as default value if this parameter is not present.
  */
  enum ClonePrefix {
    Prefix_DUPL,
    Prefix_NONE,
    Prefix_Null
  };

  /*
    * Convert AnswerFormat enum to short name string.
    * Example:
    *   AnswerFormat::Graph -> "graph"
    */
  static CATUnicodeString AnswerFormatToString(AnswerFormat iFormat);


  /*
  * Convert string to AnswerFormat enum.
  *
  * Example:
  *   "graph" -> AnswerFormat::Graph
  */
  static HRESULT StringToAnswerFormat(const CATUnicodeString& iString, AnswerFormat& oFormat);


  /*
  * Convert intent enum to short name string.
  * Example:
  *   Intent::Evolution -> "E"
  */
  static CATUnicodeString IntentToShortNameString(Intent iIntent);

  /*
  * Convert intent enum to full name string.
  * Example:
  *   Intent::Evolution -> "Evolution"
  */
  static CATUnicodeString IntentToFullNameString(Intent iIntent);

  /*
  * Convert string to intent enum.
  * It support short name and full name values.
  * Example:
  *   "Evolution" -> Intent::Evolution
  *   "E" -> Intent::Evolution
  */
  static HRESULT StringToIntent(const CATUnicodeString& iString, Intent& oIntent);


  /*
      * Convert ClonePrefix enum to short name string.
      * Example:
      *   AnswerFormat::DUPL -> "DUPL_"
      */
  static CATUnicodeString ClonePrefixToString(ClonePrefix iClonePrefix);


  /*
  * Convert string to ClonePrefix enum.
  *
  * Example:
  *   "DUPL_" -> ClonePrefix::DUPL
  */
  static HRESULT StringToClonePrefix(const CATUnicodeString& iString, ClonePrefix& oClonePrefix);


  /*
      * Convert ClonePrefix enum to short name string.
      * Example:
      *   Operator::add -> "add"
      */
  static CATUnicodeString OperatorToString(Operator iOperator);


  /*
  * Convert string to ClonePrefix enum.
  *
  * Example:
  *   "add" -> Operator::add
  */
  static HRESULT StringToOperator(const CATUnicodeString& iString, Operator& oOperator);

};

#endif