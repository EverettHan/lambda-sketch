#ifndef CATGetGraphicCardVendorAndDeviceID_h
#define CATGetGraphicCardVendorAndDeviceID_h

#include "CATVisFoundation.h"

ExportedByCATVisFoundation void CATGetGraphicCardVendorAndDeviceID(unsigned int *oVendorID, unsigned int *oDeviceID);

enum EVendorID
{
  kATI = 4098,  // 0x1002
  kINTEL = 32902, // 0x8086
  kNVIDIA = 4318,  // 0x10DE
  kMALI = 4785,  // 0x12B1
  kQUALCOMM = 20803, // 0x5143
  kIMGTECH = 5274,  // 0x149A
  kAPPLE = 1452,  // 0x05AC
  kMESA = 10, // 0x000A
  kAMAZON = 7439, //0x1D0F
  kOther = 0,
  kNbVendor = 10      ///<Nb vendor
};

ExportedByCATVisFoundation void CATGetGraphicCardVendorID(EVendorID& oVendorID);

#endif
