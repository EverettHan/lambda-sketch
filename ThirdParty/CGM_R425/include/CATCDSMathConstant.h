// COPYRIGHT DASSAULT SYSTEMES 2010
//=============================================================================
//
// CATCDSMathConstant:
//   Basic mathematical constants
//
//=============================================================================
//
// Usage notes:
//    See climits from http://cpluplus.com
//=============================================================================
//  Oct 2010  Creation                           Evgueni ROUKOLEEVint
//  Apr 2013  Replacement by macros              D5T
//=============================================================================

#ifndef CATCDSMathConstant_H
#define CATCDSMathConstant_H

#include "CATCDSUtilities.h"

#ifdef _SUNOS_SOURCE
#include "limits.h"
#include "sys/types.h"
#endif

#define CATCDSPI       3.14159265358979323846  // pi           
#define CATCDS2PI      6.28318530717958647692  // 2 * pi       
#define CATCDS3PI      9.42477796076937971538  // 3 * pi       
#define CATCDSPIBY2    1.57079632679489661923  // pi / 2       
#define CATCDS3PIBY2   4.71238898038468985769  // 3 * pi / 2   
#define CATCDSPIBY4    0.78539816339744830961  // pi / 4       
#define CATCDS3PIBY4   2.35619449019234492884  // 3 * pi / 4   
#define CATCDSINVPI    0.31830988618379067153  // 1 / pi       
#define CATCDSINV2PI   0.15915494309189533577  // 1 / (2 * pi) 
                                     
#define CATCDSSQRT2    1.41421356237309504880  // sqrt(2)    
#define CATCDSINVSQRT2 0.70710678118654752440  // 1 / sqrt(2)
#define CATCDSSQRT3    1.73205080756887729352  // sqrt(3)    
#define CATCDSINVSQRT3 0.57735026918962576451  // 1 / sqrt(3)

#define CATCDSLOG2     0.69314718055994530941  // log(2)                      

extern ExportedByCATCDSUtilities double const CATCDSdoubleMax;

extern ExportedByCATCDSUtilities long const CATCDSlongMax;
extern ExportedByCATCDSUtilities long const CATCDSlongMin;

extern ExportedByCATCDSUtilities int const CATCDSintMax;
extern ExportedByCATCDSUtilities int const CATCDSintMin;

extern ExportedByCATCDSUtilities short const CATCDSshortMax;
extern ExportedByCATCDSUtilities short const CATCDSshortMin;

extern ExportedByCATCDSUtilities char const CATCDScharMax;
extern ExportedByCATCDSUtilities char const CATCDScharMin;

extern ExportedByCATCDSUtilities unsigned char const CATCDSucharMax;

extern ExportedByCATCDSUtilities unsigned short const CATCDSushortMax;

extern ExportedByCATCDSUtilities unsigned int const CATCDSuintMax;

extern ExportedByCATCDSUtilities unsigned long const CATCDSulongMax;

#include "CATCDSDataType.h"

extern ExportedByCATCDSUtilities std::int32_t const CATCDSint32Max;
extern ExportedByCATCDSUtilities std::int32_t const CATCDSint32Min;

extern ExportedByCATCDSUtilities std::int64_t const CATCDSint64Max;
extern ExportedByCATCDSUtilities std::int64_t const CATCDSint64Min;

extern ExportedByCATCDSUtilities std::uint32_t const CATCDSuint32Max;

extern ExportedByCATCDSUtilities std::uint64_t const CATCDSuint64Max;

#endif // CATCDSMathConstant_H
