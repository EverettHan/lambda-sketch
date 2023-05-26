#ifndef IVIARDevice_H
#define IVIARDevice_H

//COPYRIGHT DASSAULT SYSTEMES 2013

#include "IVInterfaces.h"

#include "CATBaseUnknown.h"
#include "CATSysErrorDef.h"
#include "IVIImageDevice.h"
#include "CATMathTransformation.h"

extern ExportedByIVInterfaces IID IID_IVIARDevice;

/**
 * Interface representing a Augmented Reality device, made up of a video camera and an optional motion-detection sensor (e.g. a gyroscope).
 * Its image processing capabilities allow to retrieve its pose relative to a tracked pattern.
 */
class ExportedByIVInterfaces IVIARDevice : public CATBaseUnknown
{

CATDeclareInterface;

public:

  /**
   * @nodoc
   */
  virtual HRESULT GetPose(CATMathTransformation& oPose) const = 0;
  
 /**
  * Retrieves the current Image Device used by the AR library
  */
  virtual IVIImageDevice_var GetImageDevice() const = 0;

 /**
  * Sets the physical size of the marker
  *
  * @param iMarkerPhysicalWidthInMm [in]
  *   The physical size of the marker in mm
  *   This information will be used to scale the virtual objects to their correct size.
  */
  virtual void SetMarkerSize(double iMarkerPhysicalWidthInMm) = 0;

 /**
  * Gets the physical size of the marker
  *
  * @return 
  *   The physical size of the marker in mm
  */
  virtual double GetMarkerSize() const = 0;

 /**
  * Gets the tracking efficiency of the marker
  *
  * @return 
  *   The efficiency of the marker. @see IVISUIScenarioMagicWindow
  */
  virtual double GetMarkerEfficiency() const = 0;

 /**
  * Gets the tracking status of the marker
  *
  * @return 
  *   1 if the marker is being tracked,
  *   0 otherwise
  */
  virtual unsigned int IsMarkerTracked() const = 0;

 /**
  * Gets the estimated focal length of the camera.
  * @see IVISUIScenarioMagicWindow
  *
  * @return
  *   The focal length, in pixels
  */
  virtual double GetFocalLength() const = 0;

 /**
  * @nodoc
  * Internal use only.
  * Use methods such as #GetFocalLength instead
  * Returns the camera calibration parameters as a string.
  * @see IVARDeviceConfiguration
  */
  virtual CATUnicodeString GetCameraCalibrationParameters() const = 0;

};

CATDeclareHandler(IVIARDevice, CATBaseUnknown);

#endif // IVIARDevice_H
