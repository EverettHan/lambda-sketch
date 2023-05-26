// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATIOmbNonCATIADocument.h
// Define the CATIOmbNonCATIADocument interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Jul 2004  Creation: Code generated by the CAA wizard  cfo
//===================================================================

/**
* @deprecated V5R201 use instead CATIOmbNonCATIAStreamDescriptor
* @href CATIOmbNonCATIAStreamDescriptor
* @level Private
* @usage U3
*/

#ifndef CATIOmbNonCATIADocument_H
#define CATIOmbNonCATIADocument_H

#include "CATOmbNonCATIADocument.h"
#include "CATBaseUnknown.h"
#include "CATIOmbNonCATIAStreamDescriptor.h"
class CATUnicodeString;
class CATIOmbNonCATIASDPersistencyMngt;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATOmbNonCATIADocument IID IID_CATIOmbNonCATIADocument;
#else
extern "C" const IID IID_CATIOmbNonCATIADocument ;
#endif

//------------------------------------------------------------------

/**
 * @nodoc deprecated V5R201 use instead CATIOmbNonCATIAStreamDescriptor
 * This interface is used to add specific behaviors of Non CATIA doucument
 */
class ExportedByCATOmbNonCATIADocument CATIOmbNonCATIADocument: public CATIOmbNonCATIAStreamDescriptor
{
  CATDeclareInterface;
 public:
};



#endif
