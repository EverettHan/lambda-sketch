// COPYRIGHT DASSAULT SYSTEMES 2020, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyNavRepHelpers.h
//
//===================================================================
//
// August 2020  Creation: JXO
//===================================================================
#ifndef CATPolyNavRepHelpers_H
#define CATPolyNavRepHelpers_H

#include "PolyVizUtils.h"

// Visu
class CATRep;

// System
#include "CATUnicodeString.h"
#include "CATErrorDef.h"
#include "CATIAV5Level.h"

/**
 * Various services used for NavReps
 */
class ExportedByPolyVizUtils CATPolyNavRepHelpers
{
public:
  /**
   * Masks to be passed as option
   */
  enum eOptionMasks
  {
    eQuantBBoxPerGP                 = 0x01,
    eBBoxPerRep                     = 0x02,
    ePositionBoxCompression         = 0x04,
    eNormalOct16Compression         = 0x08,
    eNormalOct24Compression         = 0x10
  };
  /**
   * Saves a cgr with the PLAYREP header.
   */
  static HRESULT WritePlayRep(const CATUnicodeString& localPath, CATRep* rep,
    const int sagMode, const double sag, const double sagCurve,
    const double deviation,
    CATBoolean iNewVersion = FALSE, int iOptions = eQuantBBoxPerGP | ePositionBoxCompression | eNormalOct16Compression /* Use enums with | */);
  /**
   * Reads a cgr with header.
   */
  static CATRep * ReadCGR(const CATUnicodeString& localPathAV1,
    int& sagMode, double& sag, double& sagCurve,
    int & cgrType);

private:
  CATPolyNavRepHelpers();
  ~CATPolyNavRepHelpers();
};


#endif
