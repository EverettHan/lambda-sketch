#ifndef IVIImageDevice_H
#define IVIImageDevice_H

//COPYRIGHT DASSAULT SYSTEMES 2013

#include "IVInterfaces.h"

#include "CATSysErrorDef.h"
#include "CATListOfCATUnicodeString.h"
#include "CATBaseUnknown.h"
#include "IVDataType.h"

class CATPixelImage;

extern ExportedByIVInterfaces IID IID_IVIImageDevice;

/**
* Interface representing a Augmented Reality device, made up of a video camera and an optional with motion-detection sensor (e.g. a gyroscope).
* Its image processing capabilities allow to retrieve its pose relative to a tracked pattern.
*/
class ExportedByIVInterfaces IVIImageDevice : public CATBaseUnknown
{

  CATDeclareInterface;

public:

 /**
  * @nodoc
  * Internal use only.
  * See IVIImageDeviceCore
  */
  virtual void RequestImageBuffer() = 0;

  /**
  * @nodoc
  * Internal use only.
  * See IVIImageDeviceCore
  */
  virtual const unsigned char* const GetImageBuffer() const = 0;

 /**
  * @nodoc
  * Internal use only.
  * Retrieves the current frame being processed as a CATPixelImage.
  */
  virtual CATPixelImage* GetImage() = 0;

 /**
  * @nodoc
  * Internal use only.
  * Returns 1 if the image is flipped, i.e. upside-down.
  */
  virtual unsigned int IsFlipped() const = 0;

 /**
  * @nodoc
  * Internal use only.
  * Returns 1 if the image is mirrored, i.e. flipped right-to-left
  */
  virtual unsigned int IsMirrored() const = 0;

  
 /**
  * @nodoc
  * Internal use only.
  * Returns the index of the frame in a sequence, starting at 1.
  * Returns 0 if no such information is available.
  * See IVIImageDeviceCore and IVImageCapture
  */
  virtual unsigned int GetFrameIndex() const = 0;

  
 /**
  * @nodoc
  * Internal use only.
  * Returns the time the frame was captured by the device.
  * The format of the timestamp may vary from a device to another and is implementation-specific.
  * If the source is a video file, the time returned is a double value representing to the number fo seconds elapsed since the beginning of the video.
  * This information should be used with great care. It can only provide the elapsed time between two frame captures from the same device.
  * It may be useful in image processing scenarios requiring camera motion prediction.
  * Returns -1 if no such information is available.
  * See IVIImageDeviceCore and IVImageCapture
  */
  virtual double GetNativeTimestamp() const = 0; 


 /**
  * @nodoc
  * Internal use only.
  * Retrieves the timestamp of the event corresponding to the current state of the device.
  * For compatibility reasons accross OSes, the returned timestamp is a signed 64-bit integer representing the number of milliseconds elapsed since the 1st of January 1970 (a common standard).
  * The returned value is therefore an absolute UTC date, which can be used for logging, streaming and interoperability.
  * This value can be negative to encode dates before 1970, but unless the system settings have been set to absurd values, such a situation should not occur.
  *
  * @return
  *   the number of milliseconds elapsed since the 1st of January 1970.
  *
  * See IVIDevice
  */
  virtual IVTimestamp GetTimestamp() const = 0; 


  //
  // GPU Mode
  //

 /**
  * @nodoc
  * Internal use only.
  * Returns 1 if the image is handled directly by the the GPU.
  * In such a case, the methods to access texture information may be used for faster performance.
  * This is typically the case on iOS devices.
  */
  virtual unsigned int GetGPUMode() const = 0;

 /**
  * @nodoc
  * Internal use only.
  * There can be 2 textures on the GPU for the same frame, e.g. a luma and a chroma
  */
  virtual unsigned int GetTextureCount() const = 0;

 /**
  * @nodoc
  * Internal use only.
  * Retrieves the width of the image in pixels
  */
  virtual unsigned int GetTextureWidth(unsigned int iTextureIndex) const = 0;

 /**
  * @nodoc
  * Internal use only.
  * Retrieves the height of the image in pixels
  */
  virtual unsigned int GetTextureHeight(unsigned int iTextureIndex) const = 0;

 /**
  * @nodoc
  * Internal use only.
  * Retrieves the ID of the texture on the GPU. i.e. the corresponding Gluint
  */
  virtual unsigned int GetTextureID(unsigned int iTextureIndex) = 0;

 /**
  * @nodoc
  * Internal use only.
  * Retrieves the target of the texture on the GPU. i.e. the corresponding Glenum (e.g. GL_TEXTURE2D)
  */
  virtual unsigned int GetTextureTarget(unsigned int iTextureIndex) const = 0;

 /**
  * @nodoc
  * Internal use only.
  * Retrieves the format of the texture on the GPU (e.g. kCVPixelFormatType_420YpCbCr8BiPlanarFullRange)
  */
  virtual unsigned int GetPixelFormat(unsigned int iTextureIndex) const = 0;

 /**
  * @nodoc
  * Internal use only.
  * Returns detailed information on all available video cameras.
  */
  virtual const CATListOfCATUnicodeString& GetAvailableVideoCameras() const = 0;
  
 /**
  * @nodoc
  * Internal use only.
  * Returns the number of physical video cameras available
  */
  virtual unsigned int GetCameraCount() const = 0;

 /**
  * @nodoc
  * Internal use only.
  * Manually updates a device which has been created using IVDeviceConfiguration::IV_MANUAL_UPDATE.
  * Returns 0 if the update failed, 1 otherwise.
  */
  virtual unsigned int Update() const = 0;
};

CATDeclareHandler(IVIImageDevice, CATBaseUnknown);

//------------------------------------------------------------------

#endif // IVIImageDevice_H
