#ifndef CATExpNumericDeclarations_H
#define CATExpNumericDeclarations_H  

/* ============================= Forward declarations ================================ */

//#include "CATExpDynamic.h"
//#include "CATExpInterval.h"
//#include "CATExpFloatRingExtensionTS.h"
// //class CATExpFloatRingExtensionTS;
class CATExpDynamic;
class CATExpInterval;
class CATExpFloatRingExtensionTS;
//class CATExpFPExpansion;
typedef CATExpDynamic CATExpDynamic_t;
typedef CATExpInterval CATExpInterval_t;
typedef CATExpFloatRingExtensionTS CATExpExact_t;
//typedef CATExpFPExpansion CATExpFPExpansion_t;

enum CATExpLevel_t { kCATExpDYNAMIC = 0, kCATExpINTERVAL = 1, kCATExpEXACT = 2, /*kCATExpFPEXPANSION = 3,*/ kCATExpLEVELS_NUMBER };

template <typename NT>
struct CATExpNumberInfo{};

template <> struct CATExpNumberInfo<CATExpDynamic>
{
  static const CATExpLevel_t level = kCATExpDYNAMIC;
};

template <> struct CATExpNumberInfo<CATExpInterval>
{
  static const CATExpLevel_t level = kCATExpINTERVAL;
};

template <> struct CATExpNumberInfo<CATExpFloatRingExtensionTS>
{
  static const CATExpLevel_t level = kCATExpEXACT;
};

//template <> struct CATExpNumberInfo<CATExpFPExpansion>
//{
//  static const CATExpLevel_t level = kCATExpFPEXPANSION;
//};

template <class NT> class CATExpTrinomial;
template <class NT> class CATExpQuadraticNumber;
template <class NT> class CATExpRationalNumber;

enum CATExpNumber_t { CATExpNUMBERUNDEF, CATExpPLAIN, CATExpRATIONAL, CATExpQUADRATIC };

#endif
