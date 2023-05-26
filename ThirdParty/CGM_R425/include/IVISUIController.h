#ifndef IVISUIController_H
#define IVISUIController_H

// COPYRIGHT DASSAULT SYSTEMES 2020

#include "IVInterfaces.h"
#include "CATSysErrorDef.h"
#include "IVISUIPositionedElement.h"
#include "IVDeviceAtomicType.h"
#include "IVDeviceDataType.h"

class CATUnicodeString;

extern ExportedByIVInterfaces IID IID_IVISUIController;

/**
* Interface representing the user's controller.
* <strong>Role</strong>: Controller is a specialization of PositionedElement representing a controller of the user.
* Through inheritance, its position and orientation in the world can be retrieved.
* This element can be attached to a User Element (in which case, it will benefit from this Element's semantic), or to any other kind of Element (with no semantic in that case).
*
* @see IVISUIPositionedElement, IVISUICyclops
*/


class ExportedByIVInterfaces IVISUIController : public IVISUIPositionedElement
{

  CATDeclareInterface;

public:

  //=============================================================================
  // MESH
  //=============================================================================

  /**
  * Displays or removes the controller's mesh.
  *   @param iOnOff [in]
  *   If iOnOff is true, the mesh is displayed. If iOnOff is false, the mesh is removed and the controller will not be visible in the scene.
  *   @note See the SetMesh(...) method below for choosing the controller's mesh.
  *   @note This only deals with the mesh itself. To display or remove the textures on the controllers, see the SetTexture(...) method below.
  */
  virtual void DisplayMesh(bool iOnOff) = 0;

  /**
  * Returns whether or not the mesh is displayed.
  *   @return
  *   True if the mesh is displayed, else false.
  */
  virtual bool MeshDisplayed() = 0;
  /**
  * Updates the mesh corresponding to the controller
  *
  * @param iCGRMesh [in]
  *   The CGR mesh that will be used, e.g. "OpenVR_Controller.cgr". It needs to exist in a Rsc/RscCNext module.
  * @param iSystemType [in]
  *   The type of system whose controllers you need updated, e.g. IV_VIVE, IV_WINDOWSMR... See the IVDeviceSystemType list in IVDeviceDataType.h
  *   If the parameter is unused, the currently available controllers, whichever type they are, will be updated.
  */
  virtual void SetMesh(CATUnicodeString const& iCGRMesh, IVDeviceSystemType iSystemType = IV_UNKNOWN_SYSTEM_TYPE) = 0;

  /**
  * Updates the mesh corresponding to the controller
  *
  * @param iSystemType [in]
  *   The type of controller system whose mesh you seek., e.g. IV_VIVE, IV_WINDOWSMR... See the IVDeviceSystemType list in IVDeviceDataType.h
  *   If the parameter is unused, the currently available controllers, whichever type they are, will be updated.
  */
  virtual CATUnicodeString GetMesh(IVDeviceSystemType iSystemType = IV_UNKNOWN_SYSTEM_TYPE) = 0;


  //=============================================================================
  // TEXTURES
  //=============================================================================

  /**
  * Specifies the number of textures that are meant to be set on a controller's item.
  * As of now on the available HTC Vive / Windows MR controllers, the only item large enough to sustain more than 1 item is the touchpad. 
  * Hence, for this item (iIndex == IV_TOUCHPAD_ITEM), this method needs to be called prior to setting the textures using the SetTexture(...) method below.
  * For all other existing items, as of now, only one texture per item is allowed and calling this method is not needed. 
  * 
  * @param iItem [in]
  *   The item which layout needs to be updated.
  * @param iNbOfTextures [in]
  *   The number of textures that will be set on the item.
  *   See ascii representations below to have a better idea on the layout that will be used, depending on the number of textures.
  *   Globally, the textures' indices, as shown in the ascii art, will begin at the top then in clowkwise order.  
  *   These indices will be used as iIndex parameter in the SetTexture(...) method. 
  * @param iPairLayout [in]
  *   This parameter will be useful only if iNbOfTextures == 2 : in which case the user can choose between an horizontal and a vertical layout.
  *   if iPairLayout == false, the two textures will be set horizontally, else they will be set vertically (see ascii art below).
  * 
  *  
  *  iNbOfTextures == 1
  * 
  *       *  *
  *    *        *
  *   *     0    *
  *   *          *
  *    *        *
  *       *  *
  * 
  *  iNbOfTextures == 2
  *  iPairLayout == 0       iPairLayout == 1
  *       *  *                   *  *
  *    *        *             *    0   *
  *   * 0      1 *           *          *
  *   *          *           *          *
  *    *        *             *    1   *
  *       *  *                   *  *
  * 
  *  iNbOfTextures == 3    iNbOfTextures == 4
  *       *  *                   * 0 *
  *    *    0   *             *        *
  *   *          *           * 3      1 *
  *   *  2    1  *           *          *
  *    *        *             *    2   *
  *       *  *                   *   *
  * 
  *  iNbOfTextures == 5   iNbOfTextures >= 6 && <=8
  * 
  *       *  *                   *  *
  *    *    0   *             *    0   *
  *   * 4      1 *           * ...    1 *
  *   *          *           *        2 *
  *    * 3    2 *             *  4  3  *
  *       *  *                   *   *
  * 
  *       
  */
  virtual void SetTextureLayout(const IVDeviceControllerItem& iItem, int iNbOfTextures, bool iPairLayout = false) = 0;

  /**
  * Retrieves the number of textures on an item. 
  *
  * @param iItem [in]
  *   The item which layout needs to be updated.
  * @param oNbOfTextures [out]
  *   The number of textures that are set on the item.
  *   See ascii representations above to have a better idea on the layout that will be used, depending on the number of textures.
  * @param oPairLayout [out]
  *   This parameter will be useful only if oNbOfTextures == 2 : in which it will differenciate bewteen an horizontal and a vertical layout.
  *   if oPairLayout == false, the two textures are set horizontally, else they are set vertically (see ascii art above).
  * 
  */
  virtual void GetTextureLayout(const IVDeviceControllerItem& iItem, int& oNbOfTextures, bool& oPairLayout) = 0;


  /**
  * Sets a texture on a controller's item (button/analog).
  * It will replace the potential default texture on the item (e.g. the navigation textures used in the HMD scenario).
  *
  * @param iItem [in]
  *   The item which texture will be updated.
  * @param iTexture [in]
  *   The name of a texture png file found in the resources, e.g. "Teleport.png"
  *   If an empty texture is entered (iTexture == ""), the texture on this layout position will be removed.
  * @param iPixToMM [in]
  *   This parameter is used to determine the size of the texture on the item, depending on the pixel size of the original png. 
  * @param iIndex [in]
  *   The index of the texture on the item, according to the layout defined in the SetTextureLayout above.
  *   iIndex must be an int between 0 and the number of texture - 1 (see the iNbOfTexture parameter in the aforementioned method).
  */
  virtual void SetTexture(const IVDeviceControllerItem& iItem, CATUnicodeString const& iTexture, double iPixToMM = 0.03, int iIndex = 0) = 0;

  /**
  * Returns the texture at a given position on an item.
  *
  * @param iItem [in]
  *   The item on which to look for the texture.
  * @param oTexture [out]
  *   The name of the texture png.
  * @param oPixToMM [out]
  *   Use this to set the size of the icon on the item, depending on the pixel size of the png.
  * @param oXPos [out]
  *   The horizontal position of the texture on the item, between -1 and 1.
  * @param oYPos [out]
  *   The vertical position of the texture on the item, between -1 and 1.
  * @param iIndex [in]
  *   The index of the texture on the item, according to the layout defined in the SetTextureLayout above.
  *   iIndex must be an int between 0 and the number of texture - 1 (see the iNbOfTexture parameter in the aforementioned method).
  */
  virtual void GetTexture(const IVDeviceControllerItem& iItem, CATUnicodeString& oTexture, double& oPixToMM, double& oXPos, double& oYPos, int iIndex = 0) = 0;

  /**
  *  Activates or deactivates the navigation textures - which are the default textures - on the controller, if any,
  *  and the navigation behaviour that comes with it (translation, rotation, teleport, examine).
  *  Use this when needing to use SetTexture in order to avoid colliding textures, 
  *  or use it to put back the navigation textures.
  *  @param iOnOff [in]
  *    if true, the navigation is activated / if false, it is deactivated.
  */
  virtual void ToggleNavigationTextures(bool iOnOff) = 0;


  //=============================================================================
  // TOOLTIPS
  //=============================================================================

  /**
  * Sets a tooltip near a controller's item.
  * 
  * @param iItem [in]
  *   The item near which to put the tooltip.
  * @param iText [in]
  *   The tooltip's text.
  */
  virtual void SetTooltip(const IVDeviceControllerItem& iItem, CATUnicodeString const& iText) = 0;

  /**
  * Gets the tooltip, if any, belonging to an item.
  *
  * @param iItem [in]
  *   The item which may or may not have a tooltip
  * @param oText [out]
  *   The tooltip's text.
  */
  virtual void GetTooltip(const IVDeviceControllerItem& iItem, CATUnicodeString& oText) = 0;

  /**
  * Resets (erases) the tooltip near a controller's item.
  *
  * @param iItem [in]
  *   The item which tooltip needs to be reset.
  */
  virtual void ResetTooltip(const IVDeviceControllerItem& iItem) = 0;

  /**
  * Resets (erases) all tooltips around the controller.
  */
  virtual void ResetTooltips() = 0;


  /**
  * Displays or removes the controller's analog feedback, which shows the finger's position on the analog.
  *   @param iOnOff [in]
  *   If iOnOff is true, the feedback is displayed. If iOnOff is false, the feedback is removed.
  */
  virtual void DisplayAnalogFeedback(bool iOnOff) = 0;

  /**
  * Returns whether or not the analog feedback is activated.
  *   @return
  *   True if the analog feedback is displayed, else false.
  */
  virtual bool AnalogFeedbackDisplayed() = 0;
};

CATDeclareHandler(IVISUIController, IVISUIPositionedElement);

#endif
