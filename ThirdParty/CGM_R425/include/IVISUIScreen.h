// COPYRIGHT DASSAULT SYSTEMES 2012

#ifndef IVISUIScreen_H
#define IVISUIScreen_H

#include "IVInterfaces.h"
#include "CATSysErrorDef.h"

#include "IVISUIPositionedElement.h"


extern ExportedByIVInterfaces IID IID_IVISUIScreen;

/**
* Enumeration specifying the stereoscopy of a screen.
* <strong>Role</strong>: The stereoscopy is used by ScreenElement to specify whether the screen has an active stereoscopy or a passive on or none.
*
* @see IVISUIScreen
*/
enum IVSUIStereoscopySpecifier
{
  e_IV_Stereoscopy_None = 0,
  e_IV_Stereoscopy_Active,
  e_IV_Stereoscopy_Passive_Left,
  e_IV_Stereoscopy_Passive_Right,
  e_IV_Stereoscopy_Passive_SideBySide,
  e_IV_Stereoscopy_Passive_SideBySide_Compositor,
  e_IV_Stereoscopy_Passive_SideBySide_QuadViews
};

/**
* Enumeration specifying the reality mode of a screen.
* <strong>Role</strong>: The reality mode is used by ScreenElement to specify whether the screen is a see-through one or not.
*
* @see IVISUIScreen
*/
enum IVSUIRealityMode
{
  e_IV_Virtual_Reality = 0,
  e_IV_Augmented_Reality
};

/**
* Enumeration specifying the clipping mode of a screen.
* <strong>Role</strong>: The clipping mode is used to specify fixed near or far plane.
*
* @see IVISUIScreen
*/
enum IVSUIScreenClippingMode
{
  e_IV_Clipping_None = 0,
  e_IV_Clipping_Near,
  e_IV_Clipping_Far,
  e_IV_Clipping_Near_Far,
  e_IV_Clipping_Minimum_Near_Far
};
  
/**
* Interface representing physical screen.
* <strong>Role</strong>: Screen is a specialization of PositionedElement representing the screens on which the scene is rendered.
* Through inheritance, its position and orientation in the world can be retrieved. Its position is the position of its center
* and its orientation is the orientation according to the screen referential with x axis for the width screen axis and y axis for the height 
* screen axis.
*
* @see IVISUIPositionedElement, IVISUIPhysicalEnvironment
*/

class ExportedByIVInterfaces IVISUIScreen: public IVISUIPositionedElement
{

  CATDeclareInterface;

public:
  
 /**
  * Retrieves the Size of the Screen.
  *
  * @param [out] oWidth
  *   The retrieved screen's width in millimeters.
  * <br><strong>Precondition</strong>:
  * <tt>oWidth</tt> should be set to <tt>NULL</tt> before calling this method.
  * @param [out] oHeight
  *   The retrieved screen's height in millimeters.
  * <br><strong>Precondition</strong>:
  * <tt>oHeight</tt> should be set to <tt>NULL</tt> before calling this method.
  *
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oWidth</tt> and <tt>oHeight</tt> are successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oWidth</tt> or <tt>oHeight</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The tt>oWidth</tt> or <tt>oHeight</tt> were not set to <tt>NULL</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT GetSize(double& oWidth, double& oHeight) const = 0;

 /**
  * Retrieves the Resolution of the Screen.
  *
  * @param [out] oWidth
  *   The retrieved screen's width in pixels.
  * <br><strong>Precondition</strong>:
  * <tt>oWidth</tt> should be set to <tt>NULL</tt> before calling this method.
  * @param [out] oHeight
  *   The retrieved screen's height in pixels.
  * <br><strong>Precondition</strong>:
  * <tt>oHeight</tt> should be set to <tt>NULL</tt> before calling this method.
  *
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oWidth</tt> and <tt>oHeight</tt> are successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oWidth</tt> or <tt>oHeight</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The tt>oWidth</tt> or <tt>oHeight</tt> were not set to <tt>NULL</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT GetDisplayResolution(int& oWidth, int& oHeight) const = 0;

  /**
   * Sets the Resolution of the Screen.
   *
   * @param [in] iWidth
   *   The desired screen width
   * @param [in] iHeight
   *   The desired screen height
   *
   * @return
   *   An HRSULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The desired <tt>iWidth</tt> and <tt>iHeight</tt> are successfully set</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The desired <tt>iWidth</tt> or <tt>iHeight</tt> could not be set</dd>
  *   </dl>
  */
  virtual HRESULT SetDisplayResolution(int iWidth, int iHeight) = 0;

  /**
   * Retrieves the offset of the screen in video memory.
   *
   * @param [out] oXOffset
   *   The retrieved screen's x offset in pixels.
   * <br><strong>Precondition</strong>:
   * <tt>oXOffset</tt> should be set to <tt>NULL</tt> before calling this method.
   * @param [out] oYOffset
   *   The retrieved screen's y offset in pixels.
   * <br><strong>Precondition</strong>:
   * <tt>oYOffset</tt> should be set to <tt>NULL</tt> before calling this method.
   *
   * @return
   *   An HRESULT value.
   *   <br><strong>Legal values</strong>:
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dd>The requested <tt>oXOffset</tt> and <tt>oYOffset</tt> are successfully retrieved</dd>
   *     <dt>E_FAIL</dt>
   *     <dd>The requested <tt>oXOffset</tt> or <tt>oYOffset</tt> could not be retrieved</dd>
   *     <dt>E_INVALIDARG</dt>
   *     <dd>The tt>oXOffset</tt> or <tt>oYOffset</tt> were not set to <tt>NULL</tt> by the caller</dd>
   *   </dl>
   */
  virtual HRESULT GetDisplayPosition(int& oXOffset, int& oYOffset) const = 0;

  /**
   * Sets the offset of the screen in video memory.
   *
   * @param [in] iXOffset
   *   The desired screen x offset
   * @param [in] iYOffset
   *   The desired screen  y offset
   *
   * @return
   *   An HRSULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The desired <tt>iXOffset</tt> and <tt>iYOffset</tt> are successfully set</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The desired <tt>iXOffset</tt> or <tt>iYOffset</tt> could not be set</dd>
  *   </dl>
  */
  virtual HRESULT SetDisplayPosition(int iXOffset, int iYOffset) = 0;

 /**
  * Retrieves the Referent Wall Status of the Screen. Some Screens could be used as a wall and as a referent for 2D viewpoint.
  *
  * @param [out] oReferentWallMode
  *   The Referent Wall Status.
  * <br><strong>Precondition</strong>:
  * <tt>oReferentWallMode</tt> should be set to <tt>NULL</tt> before calling this method.
  *
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oReferentWallMode</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oReferentWallMode</tt> could not be retrieved</dd>
  *     <dt>E_INVALIDARG</dt>
  *     <dd>The <tt>oReferentWallMode</tt> was not set to <tt>NULL</tt> by the caller</dd>
  *   </dl>
  */
  virtual HRESULT GetReferentWallMode(unsigned int& oReferentWallMode) const = 0;

 /**
  * Retrieves the stereo mode of the Screen.
  *
  * @return
  *   The IVSUIStereoscopySpecifier corresponding to the stereoscopy mode.
  */
  virtual IVSUIStereoscopySpecifier GetStereoscopyMode() const = 0;

 /**
  * Sets the stereoscopy mode of the Screen.
  *
   * @param [in] iStereoscopyMode the desired stereoscopy mode.
  *   The IVSUIStereoscopySpecifier corresponding to the stereoscopy mode.
  */
  virtual void SetStereoscopyMode(IVSUIStereoscopySpecifier iStereoscopyMode) const = 0;

};

CATDeclareHandler(IVISUIScreen, IVISUIPositionedElement);

#endif

