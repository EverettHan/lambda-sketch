// COPYRIGHT Dassault Systemes 2004

/** 
  * @CAA2Level L1
  * @CAA2Usage U3
  */

#ifndef CATIIniDocumentLayersDefinition_H
#define CATIIniDocumentLayersDefinition_H

#include "UIModelInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

class CATIIniLayer;
class CATListPtrCATIIniLayer;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATIIniDocumentLayersDefinition;
#else
extern "C" const IID IID_CATIIniDocumentLayersDefinition ;
#endif

//------------------------------------------------------------------

/**
 * Interface for layer management.
 * <b>Role</b>:
 * This interface is implemented on V6 concerned representations: Parts and Drawings.
 * <br>
 * To query or modify the layers do not implement this interface, just query the representation on this interface.
 * <br>
 * A layer is managed by a pointer to the @href CATIIniLayer interface.
 * <br>
 * The layers you will manage with this interface are stored with the representation in database
 * <br>
 * You may query this interface on the result object of @href CATFrmEditor::GetEditedContents,
 * or on the objects in the result path of @href CATFrmEditor::GetUIActiveObject.
 */
class ExportedByUIModelInterfaces CATIIniDocumentLayersDefinition: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

/**
 * Retrieves the layer list.
 * @param opList
 *   The list of layers. This pointer must be NULL when calling the method.
 *   You have to Release each object of the returned list and then Release the returned list pointer after use.
 * @return
 * <br><b>Legal values</b>:<ul>
 * <li>S_OK if a layers list was found</li>
 * <li>E_FAIL no layers list was found</li></ul>
 */
    virtual HRESULT GetList (CATListPtrCATIIniLayer* &opList) = 0;

/**
 * Retrieves a layer by its name.
 * @param iName
 *   The layer name.
 * @param opLayer
 *   The layer found.
 * @return
 * <br><b>Legal values</b>:<ul>
 * <li>S_OK if the layer was found</li>
 * <li>E_FAIL if the layer does not exist</li></ul>
 */
    virtual HRESULT Find (CATUnicodeString  iName,
                          CATIIniLayer*        &opLayer) = 0;
    
/**
 * Retrieves a layer by its number.
 * @param iLayerNumber
 *   The layer number.
 * @param opLayer
 *   The layer found.
 * @return
 * <br><b>Legal values</b>:<ul>
 * <li>S_OK if the layer was found</li>
 * <li>E_FAIL if the layer does not exist</li></ul>
 */
    virtual HRESULT Find (int        iLayerNumber,
                          CATIIniLayer* &opLayer) = 0;

/**
 * Retrieves the current layer.
 * @param opLayer
 *   The Layer. (<tt>NULL</tt> if there is no current layer)
 * @return
 * <br><b>Legal values</b>:<ul>
 * <li>S_OK if the current layer was found</li>
 * <li>E_FAIL if no current layer was found</li></ul>
 */
    virtual HRESULT GetCurrent (CATIIniLayer* &opLayer) = 0;

/**
 * Changes the current layer.
 * <b>Role</b>:
 * Set a layer as the current one.
 * This recomputes the visualization because the current layer is always visible so it belongs to the current visualization filter.
 * @param ipLayer
 *   The layer. (<tt>NULL</tt> if no current layer is needed)
 * @return
 * <br><b>Legal values</b>:<ul>
 * <li>S_OK if the current layer was changed</li>
 * <li>E_FAIL if no current layer was found</li></ul>
 */
    virtual HRESULT SetCurrent (CATIIniLayer* &ipLayer) = 0;

/**
 * Adds a Layer.
 * <b>Role</b>:
 * Adds a new layer to the layers list.
 * Notice: you do not create the layer. All the layers always exist, you may just change their default name or give them a description.
 * The layers list only contains the modified layers.
 * @param opLayer
 *   The created layer.<ul>
 *   <li>If a new layer was created, opLayer is set and the returned HRESULT is S_OK ;</li>
 *   <li>If an existing layer with the same number but with a different name was found, this layer is renamed, opLayer is set NULL and the returned HRESULT is S_OK ;</li>
 *   <li>If an existing layer with the same number and the same name was found, opLayer is set to this layer and the returned HRESULT is S_FALSE ;</li></ul>
 * @param iLayerNumber
 *   The layer number.
 * @param iLayerName
 *   The layer name (optional). If this name is blank, the default name of the layer will be kept.
 *   The default name is built with the "Layer" word (depends on your language) and the layer number.
 * @param iLayerComment
 *   The layer comment (optional).
 * @return
 * <br><b>Legal values</b>:<ul>
 * <li>S_OK if the layer was correctly added</li>
 * <li>S_FALSE if this layer already exists in the list</li>
 * <li>E_FAIL if the layer could not be added</li></ul>
 */
    virtual HRESULT Add (CATIIniLayer* &opLayer,
                         int iLayerNumber,
                         CATUnicodeString iLayerName = "",
                         CATUnicodeString iLayerComment = "") = 0;

/**
 * Removes a layer.
 * @param ipLayer
 * The layer to remove from the list.
 * Notice: you do not delete the layer. All the layers always exist, the layers list only contains the modified layers.
 * @return
 * <br><b>Legal values</b>:<ul>
 * <li>S_OK if the layer was correctly removed</li>
 * <li>E_FAIL if the layer does not exist</li></ul>
 */
    virtual HRESULT Remove (CATIIniLayer* &ipLayer) = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------

#endif
