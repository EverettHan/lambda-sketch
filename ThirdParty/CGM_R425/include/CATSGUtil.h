// -*-c++-*-
#if !defined(__CATSGUtil_h)
#define __CATSGUtil_h

#include "SGComposites.h"
typedef double CATSGTickTime;

#define SG_COMPOSITES_MULTIOS
#ifdef SG_COMPOSITES_MULTIOS

#ifdef _WINDOWS_SOURCE
#define SG_COMPOSITES
#endif //_WINDOWS_SOURCE

//#ifndef _EMSCRIPTEN_TESTS
//#define DGE2_SPHERICAL_OCCLUSION
//#endif//!_EMSCRIPTEN_TESTS

#define E_INVALIDSTATE E_FAIL
#define E_UNKNOWNTERMINATION E_FAIL

#include "CATMath.h"
#include "CATMathPointf.h"
#include "CATMathVectorf.h"
#include "CATMathDirectionf.h"

#ifndef _EMSCRIPTEN_TESTS
#include "CAT4x4Matrix.h"
#endif

#include "CATIOAtomics.h"

#include "CATCmpGuid.h"
#include "IUnknown.h"
#include "CATAssert.h"

#include "CATUnicodeString.h"

#include "CATSysDataType.h"
#include "CAT3DBoundingSphere.h"
#include "CATRep.h"
#include "CATSurfacicRep.h"

#include <float.h>
#include <vector>

namespace CATSG
{
    typedef float          real;
    typedef char           int8;
    typedef short          int16;
    typedef CATINT32       int32;
    typedef CATLONG64      int64;
    typedef unsigned char  uint8;
    typedef unsigned short uint16;
    typedef CATUINT32      uint32;
    typedef CATULONG64     uint64;

    // Compilation of this one will fail! Force specification.
    template <typename T>
    struct CATSGNumericLimits
    {
        static T GetMin() {}
        static T GetMax() {}
        static T GetEpsilon() {}
    };

    template <>
    struct CATSGNumericLimits<int8>
    {
        static int8 GetMin() { return -128; } // 0x80 (-2^7)
        static int8 GetMax() { return 127; }  // 0x7f (2^7 - 1)
        static int8 GetEpsilon() { return 0; }
    };
    template <>
    struct CATSGNumericLimits<uint8>
    {
        static uint8 GetMin() { return 0; }
        static uint8 GetMax() { return 255; } // 0xff (2^8 - 1)
        static uint8 GetEpsilon() { return 0; }
    };
    template <>
    struct CATSGNumericLimits<int16>
    {
        static int16 GetMin() { return -32768; } // 0x8000 (-2^15)
        static int16 GetMax() { return 32767; }  // 0x7fff (2^15 - 1)
        static int16 GetEpsilon() { return 0; }
    };
    template <>
    struct CATSGNumericLimits<uint16>
    {
        static uint16 GetMin() { return 0; }
        static uint16 GetMax() { return 65535; } // 0xffff (2^16 - 1)
        static uint16 GetEpsilon() { return 0; }
    };
    template <>
    struct CATSGNumericLimits<int32>
    {
        static int32 GetMin() { return -(int32)2147483648; } // 0x80000000 (-2^31)
        static int32 GetMax() { return 2147483647; }         // 0x7fffffff (2^31 - 1)
        static int32 GetEpsilon() { return 0; }
    };
    template <>
    struct CATSGNumericLimits<uint32>
    {
        static uint32 GetMin() { return 0; }
        static uint32 GetMax() { return 4294967295; } // 0xffffffff (2^32 - 1)
        static uint32 GetEpsilon() { return 0; }
    };
    template <>
    struct CATSGNumericLimits<int64>
    {
        static int64 GetMin() { return static_cast<int64>((1ULL) << 63); } // 0x8000000000000000 (-2^63)
        static int64 GetMax() { return 9223372036854775807LL; }            // 0x7fffffffffffffff (2^63 - 1)
        static int64 GetEpsilon() { return 0; }
    };
    template <>
    struct CATSGNumericLimits<uint64>
    {
        static uint64 GetMin() { return 0; }
        static uint64 GetMax() { return 18446744073709551615uLL; } // 0xffffffffffffffff (2^64 - 1)
        static uint64 GetEpsilon() { return 0; }
    };

    template <>
    struct CATSGNumericLimits<float>
    {
        static float GetMin() { return -1e37f; }
        static float GetMax() { return 1e38f; }
        static float GetEpsilon() { return 1e-6f; }
    };
    template <>
    struct CATSGNumericLimits<double>
    {
        static double GetMin() { return -1e307; }
        static double GetMax() { return 1e308; }
        static double GetEpsilon() { return 1e-13f; }
    };

    template <typename T>
    inline T CATSGAbs(const T & /*iT*/)
    {
    }

    template <>
    inline float CATSGAbs<float>(const float &iT)
    {
        unsigned int i = *(unsigned int *)&iT;
        i &= 0x7FFFFFFF;
        return *(float *)&i;
    }

    template <>
    inline double CATSGAbs<double>(const double &iT)
    {
        CATULONG64 i = *(CATULONG64 *)&iT;
        i &= 0x7FFFFFFFFFFFFFFFll;
        return *(double *)&i;
    }

    template <typename T>
    inline T CATSGMax(const T &iT0, const T &iT1)
    {
        return (iT0 < iT1) ? iT1 : iT0;
    }

    template <typename T>
    inline T CATSGMax(const T &iT0, const T &iT1, const T &iT2)
    {
        return CATSGMax<T>(iT0, CATSGMax<T>(iT1, iT2));
    }

    template <typename T>
    inline T CATSGMin(const T &iT0, const T &iT1)
    {
        return (iT0 < iT1) ? iT0 : iT1;
    }

    template <typename T>
    inline T CATSGMin(const T &iT0, const T &iT1, const T &iT2)
    {
        return CATSGMin<T>(iT0, CATSGMin<T>(iT1, iT2));
    }

    template <typename T>
    inline T CATSGSqr(const T &iT)
    {
        return iT * iT;
    }

    template <typename T>
    inline T CATSGSqrt(const T & /*iT*/)
    {
    }

    template <typename T>
    inline T CATSGInvSqrt(const T & /*iT*/)
    {
    }

    template <>
    inline float CATSGSqrt<float>(const float &iT)
    {
        return sqrt(iT);
    }

    template <>
    inline double CATSGSqrt<double>(const double &iT)
    {
        return sqrt(iT);
    }

    template <>
    inline float CATSGInvSqrt(const float &iT)
    {
        if (iT < CATSGNumericLimits<float>::GetEpsilon())
        {
            return CATSGNumericLimits<float>::GetMax();
        }
        return 1.0f / CATSGSqrt(iT);
    }

    template <>
    inline double CATSGInvSqrt(const double &iT)
    {
        if (iT < CATSGNumericLimits<double>::GetEpsilon())
        {
            return CATSGNumericLimits<double>::GetMax();
        }
        return 1.0 / CATSGSqrt(iT);
    }

    template <typename T>
    inline void CATSGSwap(T &iT0, T &iT1)
    {
        T saved = iT0;
        iT0 = iT1;
        iT1 = saved;
    }

    template <typename T>
    inline bool CATSGIsNan(const T & /*iT*/)
    {
        return false;
    }

    /* Care full this implementation requires IEEE compliant architecture */
    template <>
    inline bool CATSGIsNan<float>(const float &iT)
    {
        unsigned int ival = *(unsigned int *)&iT;
        int exp = (ival >> 23) & 255;
        int mantissa = ival & ((1 << 23) - 1);
        return (255 == exp) && (0 != mantissa);
    }

    template <typename T>
    inline bool CATSGApproxEqual(const T & /*iT0*/, const T & /*iT1*/)
    {
        // Make sure to specialize for all your types.
		return false;
    }

    template <>
    inline bool CATSGApproxEqual<int>(const int &iT0, const int &iT1)
    {
        return iT0 == iT1;
    }

    template <>
    inline bool CATSGApproxEqual<float>(const float &iT0, const float &iT1)
    {
        return (CATSGAbs<float>(iT1 - iT0) <= CATSGNumericLimits<float>::GetEpsilon()) ? true : false;
    }

    template <>
    inline bool CATSGApproxEqual<double>(const double &iT0, const double &iT1)
    {
        return (CATSGAbs<double>(iT1 - iT0) <= CATSGNumericLimits<double>::GetEpsilon()) ? true : false;
    }
};

typedef CATMathVectorf CATSGColor;

typedef CATSG::uint16 CATSGTableId;
typedef CATSG::uint32 CATSGExtIndex;

struct ExportedBySGComposites CATSGRef
{
    CATSGTableId _tableId;
    CATSGExtIndex _externalIndex;
};

void ExportedBySGComposites CATSGClearRef(CATSGRef &iRef);

void ExportedBySGComposites CATSGSetRef(CATSGRef &iRef, CATSGTableId iTableId, CATSGExtIndex iExternalIndex);

bool ExportedBySGComposites CATSGIsValidRef(const CATSGRef &iRef);

bool ExportedBySGComposites operator==(const CATSGRef &iR0, const CATSGRef &iR1);

bool ExportedBySGComposites operator<(const CATSGRef &iR0, const CATSGRef &iR1);

bool ExportedBySGComposites operator==(const CAT3DBoundingSphere &iS0, const CAT3DBoundingSphere &iS1);

bool ExportedBySGComposites operator!=(const CAT3DBoundingSphere &iS0, const CAT3DBoundingSphere &iS1);

typedef std::vector<CATSGRef> CATSGRefs;
typedef std::vector<CATSGTableId> CATSGTableIds;
typedef std::vector<CATSGExtIndex> CATSGExtIndices;
typedef std::vector<CATUnicodeString> CATUnicodeStringArray;

template <typename T>
struct NAT
{
    static T value()
    {
        // Either the type should provide it
        // or you can specialize the template !
        return T::NaTValue();
    }
};

template <typename T>
struct NAT<T *>
{
    static T *value()
    {
        //You can specialize the template if you want another behaviour for your pointers!
        return NULL;
    }
};

template <>
struct NAT<CATMathPointf>
{
    static CATMathPointf value()
    {
        static const CATMathPointf nullPoint = CATMathPointf();
        return nullPoint;
    }
};

#ifndef _EMSCRIPTEN_TESTS
template <>
struct NAT<CAT4x4Matrix>
{
    static CAT4x4Matrix value()
    {
        static const CAT4x4Matrix identity = CAT4x4Matrix();
        return identity;
    }
};
#endif

template <>
struct NAT<const CAT4x4Matrix *>
{
    static const CAT4x4Matrix *value()
    {
        return NULL;
    }
};

template <>
struct NAT<GUID>
{
    static GUID value()
    {
        // {00000000-0000-0000-0000-000000000000}
        static const GUID nullGUID =
            {0x00000000, 0x0000, 0x0000, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
        return nullGUID;
    }
};

template <>
struct NAT<char> // Note: int8 is char
{
    static char value()
    {
        return '\0';
    }
};

template <>
struct NAT<unsigned char> // Note: uint8 is unsigned char
{
    static unsigned char value()
    {
        return '\0';
    }
};

template <>
struct NAT<CATSG::int16>
{
    static CATSG::int16 value()
    {
        return CATSG::CATSGNumericLimits<CATSG::int16>::GetMin();
    }
};

template <>
struct NAT<CATSG::uint16>
{
    static CATSG::uint16 value()
    {
        return CATSG::CATSGNumericLimits<CATSG::uint16>::GetMax();
    }
};

template <>
struct NAT<CATSG::int32>
{
    static CATSG::int32 value()
    {
        return CATSG::CATSGNumericLimits<CATSG::int32>::GetMin();
    }
};

template <>
struct NAT<CATSG::uint32>
{
    static CATSG::uint32 value()
    {
        return CATSG::CATSGNumericLimits<CATSG::uint32>::GetMax();
    }
};

template <>
struct NAT<CATSG::int64>
{
    static CATSG::int64 value()
    {
        return CATSG::CATSGNumericLimits<CATSG::int64>::GetMin();
    }
};

template <>
struct NAT<CATSG::uint64>
{
    static CATSG::uint64 value()
    {
        return CATSG::CATSGNumericLimits<CATSG::uint64>::GetMax();
    }
};

#ifdef SG_COMPOSITES
template <>
struct NAT<HRESULT>
{
    static HRESULT value()
    {
        return E_INVALIDARG;
    }
};
#endif

template <>
struct NAT<float>
{
    static float value()
    {
        return CATSG::CATSGNumericLimits<float>::GetMax();
    }
};

template <>
struct NAT<double>
{
    static double value()
    {
        return CATSG::CATSGNumericLimits<double>::GetMax();
    }
};

template <>
struct NAT<CATUnicodeString>
{
    static CATUnicodeString value()
    {
        return CATUnicodeString();
    }
};

template <>
struct NAT<CAT3DBoundingSphere>
{
    static CAT3DBoundingSphere value()
    {
        return CAT3DBoundingSphere();
    }
};

template <>
struct NAT<CATSurfacicRep *>
{
    static CATSurfacicRep *value()
    {
        return NULL;
    }
};

template <>
struct NAT<CATRep *>
{
    static CATRep *value()
    {
        return NULL;
    }
};

template <>
struct NAT<CAT3DRep *>
{
    static CAT3DRep *value()
    {
        return NULL;
    }
};

template <>
struct NAT<CATMathDirectionf>
{
    static CATMathDirectionf value()
    {
        return CATMathDirectionf(0, 0, 0);
    }
};

template <>
struct NAT<const char *>
{
    static const char *value()
    {
        return NULL;
    }
};

template <>
struct NAT<void *>
{
    static void *value()
    {
        return NULL;
    }
};

template <>
struct NAT<CATSGRef>
{
    static CATSGRef value()
    {
        return CATSGRef();
    }
};

inline void CATSGCopyGUID(GUID &iDst, const GUID &iSrc)
{
    memcpy(&iDst, &iSrc, sizeof(GUID));
}

template <typename T>
struct Op
{
    static HRESULT Swap(T &iT0, T &iT1)
    {
        T saved = iT0;
        iT0 = iT1;
        iT1 = saved;
        return S_OK;
    }

    static const int Compare(const T &iT0, const T &iT1)
    {
        int res = 0;
        if (iT0 > iT1)
        {
            res = -1;
        }
        else if (iT1 > iT0)
        {
            res = 1;
        }
        return res;
    }

    static const bool Equal(const T &iT0, const T &iT1)
    {
        return (iT0 == iT1) != 0; //CATUnicodeString::operator== returns int not bool
    }
};

template <typename T>
struct Op<T *>
{
    static HRESULT Swap(T *&iT0, T *&iT1)
    {
        T *saved = iT0;
        iT0 = iT1;
        iT1 = saved;
        return S_OK;
    }

    static const int Compare(const T *const &iT0, const T *const &iT1)
    {
        int res = 0;
        if (*iT0 > *iT1)
        {
            res = -1;
        }
        else if (*iT1 > *iT0)
        {
            res = 1;
        }
        return res;
    }

    static const bool Equal(const T *iT0, const T *iT1)
    {
        return iT0 == iT1;
    }
};

template <>
struct Op<CATMathPointf>
{
    static HRESULT Swap(CATMathPointf &iT0, CATMathPointf &iT1)
    {
        CATMathPointf saved = iT0;
        iT0 = iT1;
        iT1 = saved;
        return S_OK;
    }

    // Lexicographic order.
    static const int Compare(const CATMathPointf &iT0, const CATMathPointf &iT1)
    {
        int res = 0;
        if (iT0.x > iT1.x)
        {
            res = -1;
        }
        else if (iT1.x > iT0.x)
        {
            res = 1;
        }
        else if (iT0.y > iT1.y)
        {
            res = -1;
        }
        else if (iT1.y > iT0.y)
        {
            res = 1;
        }
        else if (iT0.z > iT1.z)
        {
            res = -1;
        }
        else if (iT1.z > iT0.z)
        {
            res = 1;
        }
        return res;
    }

    static const bool Equal(const CATMathPointf &iT0, const CATMathPointf &iT1)
    {
        return ((iT0.x == iT1.x) && (iT0.y == iT1.y) && (iT0.z == iT1.z));
    }
};

template <>
struct Op<CATMathVectorf>
{
    static HRESULT Swap(CATMathVectorf &iT0, CATMathVectorf &iT1)
    {
        CATMathVectorf saved = iT0;
        iT0 = iT1;
        iT1 = saved;
        return S_OK;
    }

    // Lexicographic order.
    static const int Compare(const CATMathVectorf &iT0, const CATMathVectorf &iT1)
    {
        int res = 0;
        if (iT0.x > iT1.x)
        {
            res = -1;
        }
        else if (iT1.x > iT0.x)
        {
            res = 1;
        }
        else if (iT0.y > iT1.y)
        {
            res = -1;
        }
        else if (iT1.y > iT0.y)
        {
            res = 1;
        }
        else if (iT0.z > iT1.z)
        {
            res = -1;
        }
        else if (iT1.z > iT0.z)
        {
            res = 1;
        }
        return res;
    }

    static const bool Equal(const CATMathVectorf &iT0, const CATMathVectorf &iT1)
    {
        return ((iT0.x == iT1.x) && (iT0.y == iT1.y) && (iT0.z == iT1.z));
    }
};

#ifndef ZeroMemory
inline void ZeroMemory(void *msg, int size)
{
    memset(msg, 0, size);
}
#endif

inline CATMathVectorf MulScalarP2V(const CATMathPointf &iPoint, const float iScalar)
{
    return CATMathVectorf(iScalar * iPoint.x, iScalar * iPoint.y, iScalar * iPoint.z);
}

inline CATMathPointf MulScalarP2P(const CATMathPointf &iPoint, const float iScalar)
{
    return CATMathPointf(iScalar * iPoint.x, iScalar * iPoint.y, iScalar * iPoint.z);
}

inline CATMathVectorf MulScalarV2V(const CATMathVectorf &iVec, const float iScalar)
{
    return CATMathVectorf(iScalar * iVec.x, iScalar * iVec.y, iScalar * iVec.z);
}

inline CATMathPointf MulScalarV2P(const CATMathVectorf &iVec, const float iScalar)
{
    return CATMathPointf(iScalar * iVec.x, iScalar * iVec.y, iScalar * iVec.z);
}

inline CATMathVectorf P2V(const CATMathPointf &iP)
{
    return CATMathVectorf(iP.x, iP.y, iP.z);
}

/**
 * Example of valid CATIOUri= file://filepath/offset:size
 * Note that the directory separator character is forced to '\' in filepath.
 */
typedef CATUnicodeString CATIOUri;
CATIOUri ExportedBySGComposites CreateUri(const CATUnicodeString &iPrefix,
                                          const CATUnicodeString &iFilePath,
                                          CATULONG64 iOffset = 0,
                                          CATULONG64 iSize = 0);
CATIOUri ExportedBySGComposites CreateUri(const CATUnicodeString &iPrefix,
                                          const CATUnicodeString &iDirectoryPath,
                                          const CATUnicodeString &iFileName,
                                          CATULONG64 iOffset = 0,
                                          CATULONG64 iSize = 0);
inline CATBoolean IsUriValid(const CATIOUri &iUri)
{
    return ((iUri.SearchSubString("://") >= 0) && ((iUri.GetLengthInChar() < 8) || (iUri.SubString(0, 8) != "error://")));
}

template <typename T>
class CATSGNoLifeCycleMgtPolicy
{
public:
    static void Attach(const T & /*iTValue*/, T *const /*iTNewAddr*/) {}
    static void Detach(const T & /*iTValue*/, T *const /*iTOldAddr*/) {}
};

template <typename T>
class CATSGClassLifeCycleMgtPolicy
{
public:
    static void Attach(const T & /*iTValue*/, T *const iTNewAddr)
    {
        new (iTNewAddr) T();
    }
    static void Detach(const T & /*iTValue*/, T *const iTOldAddr)
    {
        iTOldAddr->~T();
    }
};

template <typename T>
class CATSGRefCountedLifeCycleMgtPolicy
{
public:
    static void Attach(const T &iTValue, T *const /*iTNewAddr*/)
    {
        if (iTValue)
            iTValue->AddRef();
    }
    static void Detach(const T &iTValue, T *const /*iTOldAddr*/)
    {
        if (iTValue)
            iTValue->Release();
    }
};

enum ERelativePosition
{
    ERelativePositionUndefined = 0,
    ERelativePositionBefore = 1,
    ERelativePositionSame = 2,
    ERelativePositionAfter = 3
};

template <class T>
struct CATSGTraverse
{
    /**
     * If you return false the travers will be terminated so most of the
     * time your travers function should return true
     */
    virtual bool operator()(T &iT) = 0;
};

template <class T>
struct CATSGConstTraverse
{
    /**
     * If you return false the travers will be terminated so most of the
     * time your travers function should return true
     */
    virtual bool operator()(const T &iT) = 0;
};

// Compilation of this one will fail! Force specification.
template <typename K>
struct Hash
{
    unsigned int operator()(const K &iK) const
    {
        // Remove to force specialization
        return (unsigned int)iK;
    }
};

#ifdef SG_COMPOSITES
template <>
struct Hash<unsigned long>
{
    unsigned int operator()(const unsigned long &iK) const
    {
        return (unsigned int)iK;
    }
};
#endif // SG_COMPOSITES

template <>
struct Hash<CATSG::int8>
{
    unsigned int operator()(const CATSG::int8 &iK) const
    {
        return (unsigned int)(CATSG::uint8)iK;
    }
};

template <>
struct Hash<CATSG::uint8>
{
    unsigned int operator()(const CATSG::uint8 &iK) const
    {
        return (unsigned int)iK;
    }
};

template <>
struct Hash<CATSG::int16>
{
    unsigned int operator()(const CATSG::int16 &iK) const
    {
        return (unsigned int)(CATSG::uint16)iK;
    }
};

template <>
struct Hash<CATSG::uint16>
{
    unsigned int operator()(const CATSG::uint16 &iK) const
    {
        return (unsigned int)iK;
    }
};

template <>
struct Hash<CATSG::int32>
{
    unsigned int operator()(const CATSG::int32 &iK) const
    {
        return (unsigned int)(CATSG::uint32)iK;
    }
};

template <>
struct Hash<CATSG::uint32>
{
    unsigned int operator()(const CATSG::uint32 &iK) const
    {
        return (unsigned int)iK;
    }
};

template <>
struct Hash<CATSG::int64>
{
    unsigned int operator()(const CATSG::int64 &iK) const
    {
        // TODO : change.
        return (unsigned int)(CATSG::uint64)iK;
    }
};

template <>
struct Hash<CATSG::uint64>
{
    unsigned int operator()(const CATSG::uint64 &iK) const
    {
        // TODO : change.
        return (unsigned int)iK;
    }
};

template <>
struct Hash<CATUnicodeString>
{
    unsigned int operator()(const CATUnicodeString &iUnicodeString) const
    {
        return iUnicodeString.ComputeHashKey();
    }
};

template <>
struct Hash<CATRep *>
{
    unsigned int operator()(const CATRep *iRep) const
    {
        // TODO : change.
        return (unsigned int)(CATINTPTR)(iRep);
    }
};

template <>
struct Hash<CATSurfacicRep *>
{
    unsigned int operator()(const CATSurfacicRep *iRep) const
    {
        // TODO : change.
        return (unsigned int)(CATINTPTR)(iRep);
    }
};

template <>
struct Hash<const char *>
{
    unsigned int operator()(const char *iString) const
    {
        // TODO : change.
        return (unsigned int)(CATINTPTR)(iString);
    }
};

template <>
struct Hash<void *>
{
    unsigned int operator()(void *iVoid) const
    {
        // TODO : change.
        return (unsigned int)(CATINTPTR)(iVoid);
    }
};
template <>
struct Hash<const void *>
{
    unsigned int operator()(const void *iVoid) const
    {
        // TODO : change.
        return (unsigned int)(CATINTPTR)(iVoid);
    }
};

template <>
struct Hash<CATSGRef>
{
    unsigned int operator()(const CATSGRef &iRef) const
    {
        // We use this method because:
        //   - we will rarely reach 0x00ff for the table id
        //   - we will rarely reach 0x00ffffff for the external index
        unsigned int result = iRef._tableId;
        result = (result << 24) + (iRef._externalIndex & 0x00ffffff);
        return result;
    }
};

typedef int CATExContext;

enum ECATExContexReserved
{
    ECATExContexReservedDefault = 0,
    ECATExContexReservedNRE = -1,
    ECATExContexReservedOther = 1
};

#endif // SG_COMPOSITES_MULTIOS
#endif // __CATSGUtil_h
