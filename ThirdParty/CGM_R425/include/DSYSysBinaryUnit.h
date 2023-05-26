# ifndef _DSYSYSBINARYUNIT
# define _DSYSYSBINARYUNIT

// COPYRIGHT DASSAULT SYSTEMES 2008

/************************************************************************/
/* Defines                                                              */
/************************************************************************/

/************************************************************************/
/* Global includes                                                      */
/************************************************************************/

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/
#include "CATDataType.h"
#include "DSYSysCommon.h"

/************************************************************************/
/* Functions prototypes                                                 */
/************************************************************************/
/// Definition of binary unit constants
const CATLONG64 DSYSysKibiByteInBits = DSYSysI64PostFix(8192);
const CATLONG64 DSYSysMebiByteInBits = DSYSysI64PostFix(8388608);
const CATLONG64 DSYSysGibiByteInBits = DSYSysI64PostFix(8589934592);
const CATLONG64 DSYSysTebiByteInBits = DSYSysI64PostFix(8796093022208);

const CATLONG64 DSYSysKibiByteInBytes = DSYSysI64PostFix(1024);
const CATLONG64 DSYSysMebiByteInBytes = DSYSysI64PostFix(1048576);
const CATLONG64 DSYSysGibiByteInBytes = DSYSysI64PostFix(1073741824);
const CATLONG64 DSYSysTebiByteInBytes = DSYSysI64PostFix(1099511627776);

const CATLONG64 DSYSysKiloByteInBits = DSYSysI64PostFix(8000);
const CATLONG64 DSYSysMegaByteInBits = DSYSysI64PostFix(8000000);
const CATLONG64 DSYSysGigaByteInBits = DSYSysI64PostFix(8000000000);
const CATLONG64 DSYSysTeraByteInBits = DSYSysI64PostFix(8000000000000);

const CATLONG64 DSYSysKiloByteInBytes = DSYSysI64PostFix(1000);
const CATLONG64 DSYSysMegaByteInBytes = DSYSysI64PostFix(1000000);
const CATLONG64 DSYSysGigaByteInBytes = DSYSysI64PostFix(1000000000);
const CATLONG64 DSYSysTeraByteInBytes = DSYSysI64PostFix(1000000000000);

/// Binary unit enumeration
enum DSYSysBinaryUnit
{
  DSYSysBit = 0
, DSYSysByte

  /// Binary prefix
, DSYSysKibiBit,  DSYSysMebiBit,  DSYSysGibiBit,  DSYSysTebiBit
, DSYSysKibiByte, DSYSysMebiByte, DSYSysGibiByte, DSYSysTebiByte

  /// SI prefix
, DSYSysKiloBit,  DSYSysMegaBit,  DSYSysGigaBit,  DSYSysTeraBit
, DSYSysKiloByte, DSYSysMegaByte, DSYSysGigaByte, DSYSysTeraByte
};

///
static DSYSysBinaryUnit DSYSysBinaryByteFormat(const double iBytes, double& oBytes)
{
  // TeraBytes
  if ( (oBytes = (iBytes / DSYSysTebiByteInBytes)) >= 1.0 )
    return DSYSysTebiByte;

  // GigaBytes
  if ( (oBytes = (iBytes / DSYSysGibiByteInBytes)) >= 1.0 )
    return DSYSysGibiByte;

  // MegaBytes
  if ( (oBytes = (iBytes / DSYSysMebiByteInBytes)) >= 1.0 )
    return DSYSysMebiByte;

  // KiloBytes
  if ( (oBytes = (iBytes / DSYSysKibiByteInBytes)) >= 1.0 )
    return DSYSysKibiByte;

  // Bytes
  oBytes = iBytes;
  return DSYSysByte;
}

///
static DSYSysBinaryUnit DSYSysSIByteFormat(const double iBytes, double& oBytes)
{
  // TeraBytes
  if ( (oBytes = (iBytes / DSYSysTeraByteInBytes)) >= 1.0 )
    return DSYSysTeraByte;

  // GigaBytes
  if ( (oBytes = (iBytes / DSYSysGigaByteInBytes)) >= 1.0 )
    return DSYSysGigaByte;

  // MegaBytes
  if ( (oBytes = (iBytes / DSYSysMegaByteInBytes)) >= 1.0 )
    return DSYSysMegaByte;

  // KiloBytes
  if ( (oBytes = (iBytes / DSYSysKiloByteInBytes)) >= 1.0 )
    return DSYSysKiloByte;

  // Bytes
  oBytes = iBytes;
  return DSYSysByte;
}

///
#ifndef NETWORK_STATISTICS_FORMAT_SYNCHRO
#define NETWORK_STATISTICS_FORMAT_SYNCHRO
///
static DSYSysBinaryUnit DSYSysSIBitFormat(const double iBytes, double& oBits)
{
  // Set to bits
  double iBits = iBytes * 8.;

  // TeraBits
  if ( (oBits = (iBits / DSYSysTeraByteInBytes)) >= 1.0 )
    return DSYSysTeraBit;

  // GigaBits
  if ( (oBits = (iBits / DSYSysGigaByteInBytes)) >= 1.0 )
    return DSYSysGigaBit;

  // MegaBits
  if ( (oBits = (iBits / DSYSysMegaByteInBytes)) >= 1.0 )
    return DSYSysMegaBit;

  // KiloBits
  if ( (oBits = (iBits / DSYSysKiloByteInBytes)) >= 1.0 )
    return DSYSysKiloBit;

  // Bits
  oBits = iBits;
  return DSYSysBit;
}
#endif  // NETWORK_STATISTICS_FORMAT_SYNCHRO

/************************************************************************/
/* Classes declaration                                                  */
/************************************************************************/

#endif  // _DSYSYSBINARYUNIT
