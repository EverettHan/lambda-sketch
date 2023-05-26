// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATIKbeInputsPhysicalImport.h
// Define the CATIKbeInputsPhysicalImport interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Aug 2009  Creation: Code generated by the CAA wizard  TZS
//===================================================================
#ifndef CATIKbeInputsPhysicalImport_H
#define CATIKbeInputsPhysicalImport_H

#include "KnowledgeItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByKnowledgeItf IID IID_CATIKbeInputsPhysicalImport;
#else
extern "C" const IID IID_CATIKbeInputsPhysicalImport;
#endif

//------------------------------------------------------------------

class ExportedByKnowledgeItf CATIKbeInputsPhysicalImport: public CATBaseUnknown
{
  CATDeclareInterface;

  public:
      // Sets the root to build path afterwards
      virtual HRESULT SetRoot(const CATBaseUnknown_var &iRoot) = 0;
      // Sets the destination that will receive the import
      virtual HRESULT SetDestination(const CATBaseUnknown_var &iDest) = 0;
      // Creates the import if is possible/required
      // Returns
      // S_OK: the import was successfully created and stored in oCreated
      // S_FALSE: it was not necessary to create the import
      // E_FAIL: the import creation failed (maybe the root was not set with SetRoot before usage)
      virtual HRESULT CreateImport(const CATBaseUnknown_var &iToImport, CATBaseUnknown_var &oCreatedImport) = 0;
      
};
CATDeclareHandler(CATIKbeInputsPhysicalImport,CATBaseUnknown);
//------------------------------------------------------------------

#endif