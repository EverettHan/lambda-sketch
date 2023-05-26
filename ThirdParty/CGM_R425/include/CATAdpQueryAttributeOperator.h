// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATAdpQueryAttributeOperator.h
// Header definition of  enum
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Feb 2010  Creation: ECN
//===================================================================
/**
* @level Protected
* @usage U2
*/
#ifndef CATAdpQueryAttributeOperator_H
#define CATAdpQueryAttributeOperator_H

#include "CATPLMQueryFilterEnum.h"

/**
* Defines the operator corresponding to the attribute value for query.
* <br><b>Role:</b>Description of the available operators defining a filter to query on database.  
* <dt> <code><b>COND_EQUAL</b></code>     <dd> Equal operator. It can be applied on string or numerical values.
* <dt> <code><b>COND_NOT_EQUAL</b></code>      <dd> Not equal oeprator.
* <dt> <code><b>COND_GREATER</b></code>     <dd> Greater than operator. 
* <dt> <code><b>COND_LESS_OR_EQUAL</b></code>     <dd> Less than or equal to operator.
* <dt> <code><b>COND_LESS</b></code>      <dd> Less than operator.
* <dt> <code><b>COND_GREATER_OR_EQUAL</b></code>      <dd> Greater than or equal operator
* <dt> <code><b>COND_LIKE</b></code>      <dd> Which contains substring operator
* <dt> <code><b>COND_NOT_LIKE</b></code>      <dd> Which not contains substring operator
*/

namespace CATAdpQueryAttributeOperator {
  enum QueryOperator { COND_EQUAL=0, COND_NOT_EQUAL=1,COND_GREATER=2, COND_LESS_OR_EQUAL=3, COND_LESS =4, COND_GREATER_OR_EQUAL=5,COND_LIKE=6,COND_NOT_LIKE=7};

  enum LogicalOperator { OR=0, AND=1};

  RelationalOperator::Op ToRelationalOperator(QueryOperator iOperator);
}

#endif
