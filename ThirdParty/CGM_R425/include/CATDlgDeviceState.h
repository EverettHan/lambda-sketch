#ifndef CATDlgDeviceState_H
#define CATDlgDeviceState_H

#include "DI0PANV2.h"

#include "CATBoolean.h"

/** 
 * Class to define the state of a device
 */
class ExportedByDI0PANV2 CATDlgDeviceState
{
public:
	/**
	 * Enum describing the orientation of the device (matches iOS conventions)
	 */
	enum Orientation {
		OrientationUnknown = 0,
		OrientationPortrait = 1,           // Home button below the display
		OrientationPortraitUpsideDown = 2, // Home button above the display
		OrientationLandscapeLeft = 3,      // Home button on the right of the display
		OrientationLandscapeRight = 4      // Home button on the left of the display
	};

	/**
	 * Get the current orientation
	 * @return the device orientation
	 */
	static CATDlgDeviceState::Orientation GetOrientation();

	/**
	 * Lock the device orientation in its current orientation
	 */
	static void LockOrientation();

	/**
	 * Unlock the device orientation
	 */
	static void UnlockOrientation();

	/**
	 * Check if the device orientation is locked
	 * @return TRUE if the orientation is locaked, FALSE otherwise
	 */
	static CATBoolean IsOrientationLocked();

private:
	static CATBoolean _isOrientationLocked;
};

#endif
