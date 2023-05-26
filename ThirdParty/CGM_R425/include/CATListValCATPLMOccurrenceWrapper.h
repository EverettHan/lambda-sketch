// COPYRIGHT Dassault Systemes 2013
//===================================================================
//
// CATListOfCATPLMOccurrenceWrapper.h
// Header definition of CATListValCATPLMOccurrenceWrapper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
#ifndef CATListValCATPLMOccurrenceWrapper_h
#define CATListValCATPLMOccurrenceWrapper_h

#include "CATPLMIdentificationAccessOccWrapper.h"

class CATPLMOccurrenceWrapper;

#include "CATLISTV_Clean.h"
#define CATLISTV_Append
#define	CATLISTV_AppendList
#define	CATLISTV_RemovePosition
#define CATLISTV_RemoveAll
#include "CATLISTV_Declare.h"

#undef   CATCOLLEC_ExportedBy
#define  CATCOLLEC_ExportedBy    ExportedByCATPLMIdentificationAccessOccWrapper

CATLISTV_DECLARE( CATPLMOccurrenceWrapper );

#endif
