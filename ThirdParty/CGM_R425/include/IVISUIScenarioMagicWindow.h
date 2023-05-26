// COPYRIGHT DASSAULT SYSTEMES 2013

#ifndef IVISUIScenarioMagicWindow_H
#define IVISUIScenarioMagicWindow_H

#include "IVInterfaces.h"
#include "CATSysErrorDef.h"
#include "IVISUIScenario.h"

class IVISUIMarker;
class IVISUIMarker_var;
class IVISUIPositionedElement;
class IVISUIPositionedElement_var;
class CATMathTransformation;

extern ExportedByIVInterfaces IID IID_IVISUIScenarioMagicWindow;


/**
 * Interface enabling a 'Magic Window' Augmented Reality (AR) scenario.
 * <strong>Role</strong>: This interface allows the user to see virtual objects superimposed to the real world.
 * The user looks at a device, typically a mobile device equipped with a video camera, and sees the real world on the screen, filmed in real-time.
 * By overlaying virtual objects on top of the filemd image, the user seems to be looking through a magic window, 
 * since objects invisible to the naked eye appear on the screen, and seem to be anchored to the real world.
 *
 * @example
 * <pre>
 * // In this example, the position of a marker relative to the camera is retrieved.
 * // NOTE: Pointer and return values checks have been left out for clarity.
 *
 * // Get SUI Manager
 * IVISUIManager* pSUIManager = IVISUIManager::GetManager();
 *
 * // Register a Magic Window Scenario
 * IVISUIScenarioMagicWindow_var hScenario = pSUIManager->RegisterScenario(IID_IVISUIScenarioMagicWindow);
 *
 * // Create a Marker and add it to the Scenario
 * IVISUIMarker_var hMarker = hScenario->CreateMarker("DefaultMarker");
 *
 * // Set physical width and height of the printed marker in mm
 * double markerSize = 134.;
 * hMarker->SetSize(markerSize, markerSize);
 *
 * // Add Marker to the Scenario
 * hScenario->AddMarker(hMarker);
 *
 * // If you want the virtual world to move around a given marker, call #SetVirtualWorldOrigin
 * hScenario->SetVirtualWorldOrigin(hMarker);
 *
 * // Activate the Scenario on a Viewer
 * hScenario->Activate(pViewer);
 *
 * // Now modifying the position of the camera relative to the marker will modify the virtual viewpoint
 *
 * ...
 *
 * // Instead, if you wish to move the physical marker and retrieve its virtual position, call
 * hScenario->SetVirtualWorldOrigin(NULL_var);
 *
 * CATMathTransformation virtualPose = hMarker->GetVirtualGlobalMatrix();
 *
 * ...
 *
 * // NOTE: You can ask to be called back every time the position of the marker is updated by creating a listener class.
 * // @see AddIVEventHandler, IVSUIEvents
 *
 *
 * IVISUIMarker* pMarker = NULL;
 * pMarker = hMarker;
 * AddIVEventHandler(pMarker, IVSUIEvents::SUIEntityUpdated(), 
 *                   pListener, &MySUIListener::SUIEventCB);
 *
 * // Assuming a MySUIListener class defined as:
 *
 * class MySUIListener : public CATBaseUnknown
 * {
 *    CATDeclareClass;
 *
 * public: 
 *   IVTstSUIListener() : CATBaseUnknown() {};
 *   virtual ~IVTstSUIListener() {};
 *
 *   // This method will be called every time the emitter SUI Element, here the marker, is updated
 *   void SUIEventCB(CATBaseUnknown* ipSender, CATSYPEventArgs* ipArgs)
 *   {
 *     IVISUIMarker_var hMarker = ipSender;
 *     CATMathTransformation virtualPose = hMarker->GetVirtualGlobalMatrix();
 *      
 *     // TODO: Use virtual pose here
 *
 *   };
 * };
 * </pre>
 * 
 *
 * @see IVISUIManager, IVISUIScenario, IVISUIPhysicalEnvironment
 */
class ExportedByIVInterfaces IVISUIScenarioMagicWindow : public IVISUIScenario
{

  CATDeclareInterface;

public:

  /**
  * @nodoc
  * Internal use only.
  */
  virtual HRESULT RegisterConfigurationParameters() = 0;

  /**
  * @nodoc
  * Internal use only.
  */
  virtual CATBaseUnknown_var GetConfigurationParameters() const = 0;

 /**
  * Sets the image source.
  * Allows to choose between a live video feed or a video or image file as input.
  *
  * @param iType [in]
  * The type of the image source.
  * Legal values are:
  * <dl>
  *  <dt>"IVVideoCapture"</dt>
  *  <dd>to use a live video camera feed such as a webcam</dd>
  *
  *   <dt>"IVVideoFileCapture"</dt>
  *   <dd>to use a video file</dd>
  *
  *   <dt>"IVImageFileCapture"</dt>
  *   <dd>to use an image file</dd>
  * </dl>
  *
  * @param iName [in]
  * The name of the image source.
  * Legal values depend on the type of the source:
  * <dl>
  * <dt>"0" or "1"</dt>
  * <dd>Allows to switch from a camera to another if many cameras are supported by the device.
  * Can only be used if iType has been set to "IVVideoCapture"</dd>
  *
  * <dt>The full path of a file containing a video.</dt>
  * <dd>Can only be used if iType has been set to "IVVideoFileCapture"</dd>
  *
  * <dt>The full path of a file containing an image.</dt>
  * <dd>Can only be used if iType has been set to "IVImageFileCapture"</dd>
  * </dl>
  *
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd><tt>iType</tt> and <tt>iName</tt> have been successfully set</dd>
  *     <dt>E_FAIL</dt>
  *     <dd><tt>iType</tt> or <tt>iName</tt> could not be set</dd>
  *   </dl>
  */
  virtual HRESULT SetImageSource(const CATUnicodeString& iType, const CATUnicodeString& iName) = 0;

  /**
   * Creates a trackable marker from an image file.
   * The image of the marker should be printed, or displayed on a screen.
   * When filmed by the camera, the marker will be detected and its pose relative to the camera will be computed.
   * 
   * The detection uses computer vision algorithms and is sensitive to changes in lighting conditions, occlusions and camera blur.
   * Some image patterns can be detected more easily than others. This ease to track can be retrieved using IVISUIMarker#GetEfficiency
   *
   * @param iFilename [in] 
   *   The name of the file containing the image pattern to track.
   *   This is typically an image file in raster format with a distinctive pattern and preferably a black frame surrounding it to speed up detection.
   *
   * @param oMarker [out, IUnknown#Release] 
   *   The marker corresponding to the image to track.
   *
   * @return
   *   An HRESULT value.
   *   <br><strong>Legal values</strong>:
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dd><tt>oMarker</tt> has been successfully created</dd>
   *     <dt>E_FAIL</dt>
   *     <dd><tt>oMarker</tt> could not be created</dd>
   *   </dl>
   */
   virtual HRESULT CreateMarker(const CATUnicodeString& iFilename, IVISUIMarker*& oMarker) = 0;
  /**
   * @nodoc
   * Non-CAA signature.
   */
   virtual IVISUIMarker_var CreateMarker(const CATUnicodeString& iFilename) = 0;

  /**
   * Adds a marker to the Scenario 
   *
   * @param iMarker [in] 
   *   The marker to add.
   *   The marker must have been created using #CreateMarker
   *   Every time a marker is added, it gets tracked in real-time.
   *   Since tracking is expensive, it is recommended to limit the number of markers to track at the same time.
   *   Usually, best performance is achieved when using a single marker.
   *   As soon as you no longer need to track a marker, remove it using #RemoveMarker
   *   To retrieve a marker, as well as all other elements of the current scenario, @see IVISUIPhysicalEnvironment
   *
   * @return
   *   An HRESULT value.
   *   <br><strong>Legal values</strong>:
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dd><tt>iMarker</tt> has been successfully added</dd>
   *     <dt>E_FAIL</dt>
   *     <dd><tt>iMarker</tt> could not be added</dd>
   *   </dl>
   */
   virtual HRESULT AddMarker(IVISUIMarker* iMarker) = 0;
  /**
   * @nodoc
   * Non-CAA signature.
   */
   virtual HRESULT AddMarker(IVISUIMarker_var& iMarker) = 0;

  /**
   * Removes a marker from the Scenario 
   *
   * @param iMarker [in] 
   *   The marker to remove.
   *   The marker must have been previously added using #AddMarker
   *   Once a marker is removed, it is no longer tracked.
   *   Since tracking is expensive, it is recommended to limit the number of markers to track at the same time.
   *   Usually, best performance is achieved when using a single marker.
   *   To retrieve a marker, as well as all other elements of the current scenario, @see IVISUIPhysicalEnvironment
   *
   * @return
   *   An HRESULT value.
   *   <br><strong>Legal values</strong>:
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dd><tt>iMarker</tt> has been successfully removed</dd>
   *     <dt>E_FAIL</dt>
   *     <dd><tt>iMarker</tt> could not be removed</dd>
   *   </dl>
   */
   virtual HRESULT RemoveMarker(IVISUIMarker* iMarker) = 0;
  /**
   * @nodoc
   * Non-CAA signature.
   */
   virtual HRESULT RemoveMarker(IVISUIMarker_var& iMarker) = 0;

  /**
   * Sets an element as the origin of the virtual world  
   *
   * @param iOrigin [in] 
   *   The element to use as the origin of the virtual world.
   *   It is typically a marker which has been previously added using #AddMarker.
   *
   * @return
   *   An HRESULT value.
   *   <br><strong>Legal values</strong>:
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dd><tt>iOrigin</tt> has been successfully set</dd>
   *     <dt>E_FAIL</dt>
   *     <dd><tt>iOrigin</tt> could not be set</dd>
   *   </dl>
   */
   virtual HRESULT SetVirtualWorldOrigin(IVISUIPositionedElement* iOrigin) = 0;
  /**
   * @nodoc
   * Non-CAA signature.
   */
   virtual HRESULT SetVirtualWorldOrigin(IVISUIPositionedElement_var& iOrigin) = 0;

  /**
   * Computes the efficiency of a marker.
   * The higher the efficiency value, the better the marker will be tracked.
   *
   * @param iMarker [in] 
   *   The marker to evaluate has been previously created using #CreateMarker.
   *
   * @param oEfficiency [out]
   *   A real value between 0 and 1, representing the efficiency of the marker for the current scenario.
   *   The closest this value is to 1, the better the marker is tracked.
   *
   *   For best results :
   *     - avoid pictures with symmetry
   *     - use a frame around the picture to increase detection speed
   *     - use varied pictures with details and texture 
   *     - avoid pictures with flat solid colored areas
   *
   *  Some efficient markers are provided in the ARMarkers subdirectory in your runtime view.
   *  For each marker you will also find a corresponding pdf file to help you print it at the correct scale.
   *
   * @return
   *   An HRESULT value.
   *   <br><strong>Legal values</strong>:
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dd><tt>iMarker</tt> has been successfully evaluated</dd>
   *     <dt>E_FAIL</dt>
   *     <dd><tt>iMarker</tt> could not be evaluated</dd>
   *   </dl>
   */
   virtual HRESULT GetMarkerEfficiency(IVISUIMarker* iMarker, double& oEfficiency) = 0;
  /**
   * @nodoc
   * Non-CAA signature.
   */
   virtual double GetMarkerEfficiency(IVISUIMarker_var& iMarker) = 0;

 /**
  * Sets the size of the Marker in millimeters.
  * This is the real-world size of the printed marker, as measured accurately using a ruler.
  * The width corresponds to the dimension along the x axis, and the height to the dimension along the y axis.
  *
  * @param iMarker [in] 
  *   The marker which needs to have its size changed.
  * @param iWidth [in]
  *   The width of the marker in millimeters.
  * @param iHeight [in]
  *   The height of the marker in millimeters.
  */
  virtual void SetMarkerSize(IVISUIMarker_var& iMarker, double iWidth, double iHeight) = 0;

 /**
  * Sets the tracking algorithm to use for the AR experience.
  *
  * @param iTrackingAlgo [in] 
  *   The algorithm to use for the tracking.
  *   See IVARDeviceConfiguration and IVARDeviceConfiguration#TrackingAlgorithm
  */
  //virtual void SetTrackingAlgorithm(unsigned int iTrackingAlgo) = 0;

 /**
  * Sets the offset of the virtual object relative to the origin of the virtual world.
  * This matrix only makes sense when #SetVirtualWorldOrigin has been called.
  *
  * It can be used to :
  *   - center the virtual object if it does not share the origin of the virtual world.
  *   - scale the virtual object if sclae 1:1 is not required for the experience (e.g. when you want a virtual car to fit inside a marker)
  *   - rotate the virtual object if it does not share the same orientation as the virtual world.
  * 
  * @param iTransfo [in]
  *   The local transformation to apply to the virtual object relative to the origin the virtual world
  */
  virtual void SetVirtualModelOffset(const CATMathTransformation& iTransfo) = 0;

 /**
  * Returns the offset of the virtual model relative to the origin of the virtual world.
  * @see #SetVirtualModelOffset
  * 
  * @return 
  *   The transformation corresponding to the offset
  */
  virtual CATMathTransformation GetVirtualModelOffset() const = 0;

 /**
  * Allows to check if the current camera has valid calibration data.
  * 
  * @return 
  *   1 if the current camera has valid calibration data,
  *   0 otherwise.
  */
  virtual unsigned int IsCameraCalibrated() = 0;

 /**
  * Returns the focal length of the current camera, in pixels.
  * 
  * @return 
  *   The focal length of the current camera, or, if there is no valid calibration data, an undefined negative value.
  *
  * @example
  * <pre>
  *
  * // Here is a typical usage of the API
  * // NOTE: For a more convenient API to use with CAT3DViewpoint, use GetCameraViewingAngle() instead!
  *
  * double focalLength  = -1;
  * IVISUIScenarioMagicWindow_var hARScenario = ... // retrieve MagicWindow scenario
  * if(hARScenario->IsCameraCalibrated())
  * {
  *   focalLength = hARScenario->GetCameraFocalLength();
  * }
  *
  * // To use this focal length to adjust a CAT3DViewpoint, you may proceed as follows:
  * if(focalLength > 0)
  * {
  *   double focalLengthOverImageHeight = focalLength / pixelHeight;
  *
  *   float halfAngle_rad = atan(1./(2.*focalLengthOverImageHeight)); 
  *   float halfAngle_deg = halfAngle_rad * CATRadianToDegree;
  * 
  *   p3DViewpoint->SetAngle(halfAngle_deg); // SetAngle uses the half vertical angle in degrees
  * }
  *
  * </pre>
  */
  virtual double GetCameraFocalLength() = 0;

 /**
  * Returns the vertical half angle of the camera.
  * 
  * @return 
  *   The vertical half angle of the camera, in degrees, ready to use with CAT3DViewpoint#SetAngle
  *   In case of an error, an undefined negative value is returned.
  *
  * @example
  * <pre>
  *
  * // Here is a typical usage of the API.
  *
  * IVISUIScenarioMagicWindow_var hARScenario = ... // retrieve MagicWindow scenario
  * if(hARScenario->IsCameraCalibrated())
  * {
  *   float halfAngle_deg = hARScenario->GetCameraViewingAngle();
  * 
  *   p3DViewpoint->SetAngle(halfAngle_deg); // SetAngle uses the half vertical angle in degrees
  * }
  *
  * </pre>
  */
  virtual float GetCameraViewingAngle() = 0;

 /**
  * Returns the tracking status of a marker.
  *
  * @param iMarker [in] 
  *   The marker to check, which has been previously created using #CreateMarker.
  * 
  * @return 
  *   1 if the given marker is tracked,
  *   0 otherwise.
  */
  virtual unsigned int IsMarkerTracked(IVISUIMarker_var& iMarker) = 0;

 /**
  * Activates or deactivates the rendering of the background.
  * Deactivating the rendering of the background allows addressing scenarios where the marker acts as a tangible interface in a fully virtual world.
  *
  * @param iActivateBG [in] 
  *   Set to 1 to activate background rendering (default)
  *   Set to 0 to disable background rendering
  */
  virtual void SetBackgroundRenderingMode(const unsigned int iActivateBG) = 0;

 /**
  * Retrieves the current state of the background rendering mode.
  *
  * @return 
  *   1 if background rendering has been activated (default)
  *   0 if background rendering has been disabled
  */
  virtual unsigned int GetBackgroundRenderingMode() = 0;

 /**
  * Activates or deactivates Mirror mode.
  * When the user is facing the display and the camera, he expects to see himself as if he were looking at a mirror.
  * In such a setup, the user expects to see his reflection and not what the camera sees.
  * Moving the marker to the right should move the virtual object to the right.
  *
  * Note that this will not only influence the way the background is rendered but also the matrix of the virtual objects, in order to be consistent.
  * In mirror mode, the standard matrix is therefore premultiplied by the 4x4 matrix with {-1, 1, 1, 1} as its diagonal.
  *
  * Note that it is impossible to detect where a camera is directed to relative to the screen.
  * Even if most laptops are equipped with front facing cameras, this is not the default configuration.
  * It is up to the user to mirror the image and the rendering, as needed, by simply activating this mode.
  *
  * @param iActivateMirror [in] 
  *   Set to 1 to activate mirror mode
  *   Set to 0 to disable mirror mode (default)
  */
  virtual void SetMirrorMode(const unsigned int iActivateMirror) = 0;

 /**
  * Retrieves the current state of the mirror rendering mode.
  *
  * @return 
  *   1 if mirror mode has been activated
  *   0 if mirror mode has been disabled (default)
  */
  virtual unsigned int GetMirrorMode() = 0;


};

CATDeclareHandler(IVISUIScenarioMagicWindow, IVISUIScenario);

#endif
