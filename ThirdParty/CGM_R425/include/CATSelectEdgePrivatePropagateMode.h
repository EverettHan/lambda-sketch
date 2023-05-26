// COPYRIGHT DASSAULT SYSTEMES 2022, ALL RIGHTS RESERVED.
//===================================================================
//
// Header definition of CATSelectEdgePrivatePropagateMode
//
//===================================================================

//===================================================================
//  Created By QF2
//  June 2022
//===================================================================
#ifndef CATSelectEdgePrivatePropagateMode_H
#define CATSelectEdgePrivatePropagateMode_H

// include
#include "CATSelectEdgePropagateMode.h"
#include <functional>
#include "CATSysBoolean.h"

class CATBody;
class CATEdge;
class CATVertex;
class CATDomain;                        


// Type def pour AIX 
// ------------------------------------------------------------------
#ifndef _AIX_SOURCE

// Ne compile pas sous AIX... ca serait trop simple...
typedef std::function<CATBoolean(CATBody *ipBody, CATVertex *iCurrVertex, CATEdge * iCurrEdge, CATEdge *iCandidateEdge)>  CSEPropagationFunction;

#else

typedef CATBoolean (*CSEPropagationFunction) (CATBody *ipBody, CATVertex *iCurrVertex, CATEdge * iCurrEdge, CATEdge *iCandidateEdge);

#endif

//==============================================================================
// Define PRIVATE propagation  mode
//==============================================================================

const CATSelectEdgePropagateMode CSE_CUSTOM_PROPAG_FUNCTION = (CATSelectEdgePropagateMode) 101;


#endif /* CATSelectEdgePrivatePropagateMode_H */


