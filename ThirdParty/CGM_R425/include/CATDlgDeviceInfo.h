#ifndef CATDlgDeviceInfo_H
#define CATDlgDeviceInfo_H

#include "DI0PANV2.h"

#include "CATBoolean.h"

class CATUnicodeString;

/** 
 * Class to get some info about the device
 */
class ExportedByDI0PANV2 CATDlgDeviceInfo
{
public:
	/**
	 * Enum describing the device model
	 */
	enum Model {
		Model_Unknown,
		Model_iPhone,              // iPhone 3G/3GS     (low resolution)
		Model_iPhoneRetina,        // iPhone 4/4S       (retina)
		Model_iPhoneRetina_4inch,  // iPhone 5/5C/5S/SE (retina 4")
		Model_iPhone6,             // iPhone 6/6S/7     (retina 4.7")
		Model_iPhone6Plus,         // iPhone 6+/6S+/7+  (retina 5.5")
		Model_iPad,                // iPad 1/2          (low resolution)
		Model_iPadMini,            // iPad Mini         (low resolution)
		Model_iPadRetina,          // iPad 3/4/Air/Air2 (retina)
		Model_iPadMiniRetina,      // iPad Mini/3/4     (retina)
		Model_iPadPro_9_7inch,     // iPad Pro 9.7"     (retina)
		Model_iPadPro_12_9inch     // iPad Pro 12.9"    (retina)
	};

	/**
	 * Get the device model
	 * @return the device model
	 */
	static CATDlgDeviceInfo::Model GetModel();

	/**
	 * Compare the device software version
	 */
	static CATBoolean IsSystemVersionEqualTo(const CATUnicodeString& iVersion);
	static CATBoolean IsSystemVersionGreaterThan(const CATUnicodeString& iVersion);
	static CATBoolean IsSystemVersionGreaterThanOrEqualTo(const CATUnicodeString& iVersion);
	static CATBoolean IsSystemVersionSmallerThan(const CATUnicodeString& iVersion);
	static CATBoolean IsSystemVersionSmallerThanOrEqualTo(const CATUnicodeString& iVersion);
};

#endif
