//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2023, ALL RIGHTS RESERVED.
//=============================================================================
//
// DESCRIPTION  : private stream option (internal use)
//                
//=============================================================================
// Creation YL3 Feb 2023
//=============================================================================

#ifndef CATCGMStreamPrivateOption_h
#define CATCGMStreamPrivateOption_h

#include "ExportedByGeometricObjects.h"
#include "CATDataType.h"
#include "CATBoolean.h"
#include "CATCGMStreamVersion.h"

class CATCGMStream;

class ExportedByGeometricObjects CATCGMStreamPrivateOption
{
public:

  CATCGMStreamPrivateOption();
  virtual ~CATCGMStreamPrivateOption();

  CATBoolean IsExplicitSetPolyhedralCompressionMode() const;
  
  /**
  * @nodoc
  * Please find the compression mode information in file PolyhedralInterfaces\ProtectedInterfaces\CATPolyCompressionOptions.h
  */
  void SetPolyhedralCompressionMode(const CATULONG32& iCompressionMode);
  CATULONG32 GetPolyhedralCompressionMode() const;

  void Stream(CATCGMStream* iStr, CATCGMStreamVersion iVersion);
  void Unstream(CATCGMStream* iStr, CATCGMStreamVersion iVersion);

private:
  CATULONG32 _PolyhedralCompressionMode;
  CATBoolean _IsExplicitSet_PolyhedralCompressionMode;
}; 

#endif
