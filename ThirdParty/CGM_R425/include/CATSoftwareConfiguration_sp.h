/* -*-C++-*- */
#ifndef CATSoftwareConfiguration_sp_H
#define CATSoftwareConfiguration_sp_H
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022
//=============================================================================

//=============================================================================
//
// RESPONSABLE  : Q. FREGER (QF2)
//
// DESCRIPTION  : Safe pointer on CATSoftwareConfiguration
//                Multi OS - AIX Compliant
// 
// To Avoid memory leak and core dump due to unsynchronized AddRef/Release.
// Can easely replaced CATSoftwareConfiguration standard pointer everywhere. 
// 
//=============================================================================
#include "CATMathStream.h"
#include "CATGMSafePtr.h"
// inclusion automatique de la config
#include "CATSoftwareConfiguration.h"


// @see CATGMSafePtr.h
typedef CATGMSafePtr<CATSoftwareConfiguration> CATSoftwareConfiguration_sp;


namespace CATGM
{
  // equivalent to  CATGM::MakeSafePtr<CATSoftwareConfiguration>();
  ExportedByCATMathStream CATSoftwareConfiguration_sp  CreateSafeSoftwareConfig() ;

  // equivalent to  CATGM::MakeSafePtr<CATSoftwareConfiguration>(iStreamBuffer, iLength, iConvert);
  ExportedByCATMathStream CATSoftwareConfiguration_sp  CreateSafeSoftwareConfig(const char* iStreamBuffer, int iLength, int iConvert=0);
}

#endif
