/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2002

//===================================================================
//
// CATIDocumentLayersDefinition.h
// Define the CATIDocumentLayersDefinition interface
//
//===================================================================
//
// Usage notes:
//   Document Layer management
//
//===================================================================
#ifndef CATIDocumentLayersDefinition_H
#define CATIDocumentLayersDefinition_H

#include "UIModelInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATDocumentDefinitionStatus.h"
#include "CATUnicodeString.h"

class CATLayer;
class CATListPtrCATLayer;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATIDocumentLayersDefinition;
#else
extern "C" const IID IID_CATIDocumentLayersDefinition ;
#endif

//------------------------------------------------------------------

/**
 * Interface for Layer management on Documents.
 */
class ExportedByUIModelInterfaces CATIDocumentLayersDefinition: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

/** @nodoc
 * Gives the Layers definition status of the document.
 * <b>Role</b>:
 * Return the document Layers Filters definition status. 
 * @param oStatus
 *   The document definition status.
 * <br><b>Legal values</b>: <ul>
 * <li><tt>CATDefinitionInSettings</tt>: the Layer definition is stored in the CATSettings.</li>
 * <li><tt>CATDefinitionInDocument</tt>: the Layer definition is stored within the document.</li>
 * </ul>
 */
    virtual HRESULT GetStatus (CATDocumentDefinitionStatus &oStatus) = 0;

/**
 * Gives the Layer list of the document.
 * <b>Role</b>:
 * Return the list of Layers. 
 * @param opList
 *   The list of Layers.
 */
    virtual HRESULT GetList (CATListPtrCATLayer* &opList) = 0;

/**
 * Finds a Layer into the document.
 * <b>Role</b>:
 * Return the Layer found. 
 * Lifecycle rules deviation: No AddRef is performed on the returned value. 
 * @param iName
 *   The Layer name.
 * @param opLayer
 *   The Layer if found.
 */
    virtual HRESULT Find (CATUnicodeString  iName,
                          CATLayer*        &opLayer) = 0;
    
/**
 * Finds a Layer into the document.
 * <b>Role</b>:
 * Return the Layer found. 
 * @param iLayerNumber
 *   The Layer number.
 * @param opLayer
 *   The Layer if found.
 */
    virtual HRESULT Find (int        iLayerNumber,
                          CATLayer* &opLayer) = 0;

/**
 * Gives the Layer set as current for the document.
 * <b>Role</b>:
 * Return the current Layer. 
 * @param opLayer
 *   The Layer. (The 'None' Layer address is <tt>NULL</tt>)
 */
    virtual HRESULT GetCurrent (CATLayer* &opLayer) = 0;

/**
 * Sets a Layer as current.
 * <b>Role</b>:
 * Set a current Layer. 
 * @param ipLayer
 *   The Layer. (The 'None' Layer address is <tt>NULL</tt>)
 */
    virtual HRESULT SetCurrent (CATLayer* &ipLayer) = 0;

/**
 * @nodoc
 */
    virtual HRESULT GetGeneral (CATLayer* &opLayer) = 0;

/**
 * Adds a Layer into the document.
 * <b>Role</b>:
 * Create a new Layer. 
 * @param opLayer
 *   The created Layer.
 * @param iLayerNumber
 *   The Layer number.
 * @param iLayerName
 *   The name of Layers. (Optional)
 */
    virtual HRESULT Add (CATLayer* &opLayer,
                         int iLayerNumber,
                         CATUnicodeString iName = "",
                         CATUnicodeString iLayerComment = "") = 0;

/**
 * Removes a Layer from the document.
 * <b>Role</b>:
 * Delete a Layer. 
 * @param ipLayer
 *   The Layer to delete.
 */
    virtual HRESULT Remove (CATLayer* &ipLayer) = 0;

/**
 * Sets the persistence mode.
 * <b>Role</b>:
 * Tells whether the layer modifications have to be stored in the persistent data or not. 
 * If not, they can be saved or cancelled later using RegisterModifications or CancelModifications.
 * The modifications on layers are: layer creation, layer name modification and layer destruction.
 * The modifications are done on the layers 
 * @param iMode
 *   TRUE  : the modifications are stored in the persistent data.
 *   FALSE : the modifications are NOT stored in the persistent data.
 */
    virtual HRESULT SetPersistentMode (CATBoolean iMode) = 0;

/**
 * Saves the modifications.
 * <b>Role</b>:
 * Save the modifications done since SetPersistentMode (FALSE) was called. 
 */
    virtual HRESULT RegisterModifications () = 0;

/**
 * Cancels the modifications.
 * <b>Role</b>:
 * Cancels the modifications done since SetPersistentMode (FALSE) was called. 
 */
    virtual HRESULT CancelModifications () = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------
//                             Handler
//------------------------------------------------------------------

CATDeclareHandler (CATIDocumentLayersDefinition, CATBaseUnknown);

#endif
