// COPYRIGHT Dassault Systemes 2008
//===================================================================

/** 
  * @CAA2Level L1
  * @CAA2Usage U3
  */ 

#ifndef CATIIniDocumentFiltersDefinition_H
#define CATIIniDocumentFiltersDefinition_H

#include "UIModelInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"

class CATIIniLayersFilter;
class CATListPtrCATIIniLayersFilter;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATIIniDocumentFiltersDefinition;
#else
extern "C" const IID IID_CATIIniDocumentFiltersDefinition ;
#endif

//------------------------------------------------------------------

/**
 * Interface for layers filter management.
 * <b>Role</b>:
 * This interface is implemented on V6 concerned representations: Parts and Drawings.
 * <br>
 * To query or modify the filters do not implement this interface, just query the representation on this interface.
 * <br>
 * A filter is managed by a pointer to the @href CATIIniLayersFilter interface.
 * <br>
 * The filters you will manage with this interface are stored with the representation in database
 * <br>
 * You may query this interface on the result object of @href CATFrmEditor::GetEditedContents,
 * or on the objects in the result path of @href CATFrmEditor::GetUIActiveObject.
 */
class ExportedByUIModelInterfaces CATIIniDocumentFiltersDefinition: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

/**
 * Check mode for layer filter description.
 * <b>Role</b>:
 * Lists the different check modes that can be applied to a layer filter description.<br>
 *   @param NoCheck 
 *      No check at all
 *   @param CheckNLS 
 *      Check NLS contents
 *   @param CheckAndConvert 
 *      Check and convert from trans-format to NLS contents
 */
    enum FilterContentCheckMode {NoCheck, CheckNLS, CheckAndConvert};

/**
 * Retrieves the layers filter list.
 * <b>Role</b>:
 * @param opList
 *   The list of filters.
 * @return
 * <br><b>Legal values</b>:<ul>
 * <li>S_OK if a filters list was found</li>
 * <li>E_FAIL no filters list was found</li></ul>
 */
    virtual HRESULT GetList (CATListPtrCATIIniLayersFilter* &opList) = 0;

/**
 * Retrieves a filter by its name.
 * <b>Role</b>:
 * @param iName
 *   The filter name.
 * @param opFilter
 *   The filter found.
 * @return
 * <br><b>Legal values</b>:<ul>
 * <li>S_OK if the filter was found</li>
 * <li>E_FAIL if the filter does not exist</li></ul>
 */
    virtual HRESULT Find (CATUnicodeString  iName,
                          CATIIniLayersFilter* &opFilter) = 0;
    
/**
 * Retrieves the current filter.
 * <b>Role</b>:
 * @param opFilter
 *   The filter set as current.
 * @return
 * <br><b>Legal values</b>:<ul>
 * <li>S_OK if the current filter was found</li>
 * <li>E_FAIL if no current filter was found</li></ul>
 */
    virtual HRESULT GetCurrent (CATIIniLayersFilter* &opFilter) = 0;

/**
 * Changes the current filter.
 * <b>Role</b>:
 * Sets a filter as the current one. This recomputes the visualization.
 * @param ipFilter
 *   The filter to set as current.
 * @return
 * <br><b>Legal values</b>:<ul>
 * <li>S_OK if the current filter was changed</li>
 * <li>E_FAIL if no current filter was found</li></ul>
 */
    virtual HRESULT SetCurrent (CATIIniLayersFilter* &ipFilter) = 0;

/**
 * Creates a filter.
 * <b>Role</b>:
 * Creates a new filter and adds it to the filters list. 
 * @param opFilter
 *   The created filter.<ul>
 *   <li>If no filter with same name or same content already exists, a new filter is created, its pointer is returned and the return code is S_OK.</li>
 *   <li>If a filter with same name already exists, its description is changed, its pointer is returned and the return code is S_OK.</li>
 *   <li>If a filter with same description already exists, its name is changed, its pointer is returned and the return code is S_OK.</li>
 *   <li>If a filter with same description AND same name already exists, its pointer is returned and the return code is S_FALSE.</li></ul>
 * @param iFilterName
 *   The name of the filter.
 * @param iFilterContent
 *   The filter description.
 * @param iCheckMode
 *   The filter description check mode.
 * @param iDisplayError
 *   The filter check error display mode. <ul>
 *   <li>FALSE: No display (Default Value)</li>
 *   <li>TRUE: Display a error within a dialog box</li></ul>
 * @return
 * <br><b>Legal values</b>:<ul>
 * <li>S_OK if the filter was correctly created</li>
 * <li>S_FALSE if this filter already exists</li>
 * <li>E_FAIL if the filter could not be created</li></ul>
 */
    virtual HRESULT Add (CATIIniLayersFilter* &opFilter,
                         CATUnicodeString iFilterName,
                         CATUnicodeString iFilterContent,
                         FilterContentCheckMode iCheckMode = NoCheck,
                         CATBoolean iDisplayError = FALSE) = 0;

/**
 * Removes a filter.
 * <b>Role</b>:
 * Deletes a filter and removes it from the filters list. 
 * @param ipFilter
 *   The filter to delete.
 * @return
 * <br><b>Legal values</b>:<ul>
 * <li>S_OK if the filter was correctly removed</li>
 * <li>E_FAIL if the filter does not exist</li></ul>
 */
    virtual HRESULT Remove (CATIIniLayersFilter* &ipFilter) = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------

#endif
