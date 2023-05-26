/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2002

//===================================================================
//
// CATIDocumentFiltersDefinition.h
// Define the CATIDocumentFiltersDefinition interface
//
//===================================================================
//
// Usage notes:
//   Document Layers Filter management
//
//===================================================================
#ifndef CATIDocumentFiltersDefinition_H
#define CATIDocumentFiltersDefinition_H

#include "UIModelInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATDocumentDefinitionStatus.h"
#include "CATUnicodeString.h"

class CATLayersFilter;
class CATListPtrCATLayersFilter;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATIDocumentFiltersDefinition;
#else
extern "C" const IID IID_CATIDocumentFiltersDefinition ;
#endif

//------------------------------------------------------------------

/**
 * Interface for Layers Filter management on Documents
 */
class ExportedByUIModelInterfaces CATIDocumentFiltersDefinition: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

/** @nodoc
 * Give the Layers Filters definition status of the document.
 * <b>Role</b>:
 * Return the document Layers Filters definition status. 
 * @param oStatus
 *   The document definition status.
 * <br><b>Legal values</b>: <ul>
 * <li><tt>CATDefinitionInSettings</tt>: the Layers Filters definition is stored in the CATSettings.</li>
 * <li><tt>CATDefinitionInDocument</tt>: the Layers Filters definition is stored within the document.</li>
 * </ul>
 */
    virtual HRESULT GetStatus (CATDocumentDefinitionStatus &oStatus) = 0;

/**
 * Give the Layers Filter list of the document.
 * <b>Role</b>:
 * Return the list of Layers Filters. 
 * @param opList
 *   The list of Layers Filters.
 */
    virtual HRESULT GetList (CATListPtrCATLayersFilter* &opList) = 0;

/**
 * Find a Layers Filter into the document.
 * <b>Role</b>:
 * Return the Layers Filter found. 
 * @param iName
 *   The Layers Filter name.
 * @param opFilter
 *   The Layers Filter if found.
 */
    virtual HRESULT Find (CATUnicodeString  iName,
                          CATLayersFilter* &opFilter) = 0;
    
/**
 * Give the Layers Filter set as current for the document.
 * <b>Role</b>:
 * Return the current Layers Filter. 
 * @param opFilter
 *   The Layers Filter set as current.
 */
    virtual HRESULT GetCurrent (CATLayersFilter* &opFilter) = 0;

/**
 * Set a Layers Filter as current.
 * <b>Role</b>:
 * Set a current Layers Filter. 
 * @param ipFilter
 *   The Layers Filter to set as current.
 */
    virtual HRESULT SetCurrent (CATLayersFilter* &ipFilter) = 0;

/**
 * Add a Layers Filter into the document.
 * <b>Role</b>:
 * Create a new Layers Filter. 
 * @param opFilter
 *   The created Layers Filter.
 * @param iFilterName
 *   The name of Filters.
 * @param iContent
 *   The Filter description.
 * @param iCheckMode
 *   The Filter description check mode. <br>
 *   0: No Check (Default Value)
 *   1: Check NLS contents
 *   2: Check and convert from trans-format to NLS contents
 * @param iDisplayError
 *   The Filter check error display mode. <br>
 *   0: No display (Default Value)
 *   1: Display a error within a dialog box
 */
    virtual HRESULT Add (CATLayersFilter* &opFilter,
                         CATUnicodeString iLayerName,
                         CATUnicodeString iLayerComment,
                         int iModeCheck = 0,
                         int iDisplayError = 0) = 0;

/**
 * Remove a Layers Filter from the document.
 * <b>Role</b>:
 * Delete a Layers Filter. 
 * @param ipFilter
 *   The Layers Filter to delete.
 */
    virtual HRESULT Remove (CATLayersFilter* &ipFilter) = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------
//                             Handler
//------------------------------------------------------------------

CATDeclareHandler (CATIDocumentFiltersDefinition, CATBaseUnknown);

#endif
