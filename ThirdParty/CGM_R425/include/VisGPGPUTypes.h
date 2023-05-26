#ifndef VISGPGPUTYPES_H_
#define VISGPGPUTYPES_H_

#if defined(__GNUC__) || defined(_AIX_SOURCE)

#define __align__(n) \
        __attribute__((aligned(n)))
#define __annotate__(a) \
        __attribute__((a))
#define __location__(a) \
        __annotate__(a)

#elif defined(_MSC_VER)

#define __align__(n) \
        __declspec(align(n))
#define __annotate__(a) \
        __declspec(a)
#define __location__(a) \
        __annotate__(__##a##__)
#endif


//Scalar types

#if (defined (_WIN32) && defined(_MSC_VER))

/* scalar types  */
typedef signed   __int8   gpgpu_char;
typedef unsigned __int8   gpgpu_uchar;
typedef signed   __int16  gpgpu_short;
typedef unsigned __int16  gpgpu_ushort;
typedef signed   __int32  gpgpu_int;
typedef unsigned __int32  gpgpu_uint;
typedef signed   __int64  gpgpu_long;
typedef unsigned __int64  gpgpu_ulong;
typedef unsigned __int16  gpgpu_half;
#else // !_WIN32
typedef int8_t            gpgpu_char;
typedef uint8_t           gpgpu_uchar;
typedef int16_t           gpgpu_short;
typedef uint16_t          gpgpu_ushort;
typedef int32_t           gpgpu_int;
typedef uint32_t          gpgpu_uint;
typedef int64_t           gpgpu_long;
typedef uint64_t          gpgpu_ulong;
typedef uint16_t          gpgpu_half;
#endif // !_WIN32
typedef float             gpgpu_float;
typedef double            gpgpu_double;



//Vector types internals


template<int A> struct _aligned;
template<> struct __align__(1)   _aligned<1>   { };
template<> struct __align__(2)   _aligned<2>   { };
template<> struct __align__(4)   _aligned<4>   { };
template<> struct __align__(8)   _aligned<8>   { };
template<> struct __align__(16)  _aligned<16>  { };
template<> struct __align__(32)  _aligned<32>  { };
template<> struct __align__(64)  _aligned<64>  { };
template<> struct __align__(128) _aligned<128> { };

template<typename T, int Alignment>
struct internal_1 : _aligned<Alignment>
{
  union
  {
    T s[1];
    struct { T x; };
  };

  internal_1()
  {}

  internal_1(const T & iX)
    :x(iX)
  { }


  internal_1(const internal_1 & iCopy)
  {
    memcpy(s, iCopy.s, 1 * sizeof(T));
  }

  internal_1 & operator=(const internal_1 & iCopy)
  {
    memcpy(s, iCopy.s, 1 * sizeof(T));
    return *this;
  }
};

template<typename T, int Alignment>
struct internal_2 : _aligned<Alignment>
{
  union
  {
    T s[2];
    struct { T x, y; };
  };

  internal_2()
  {}
  internal_2(const T & iX, const T & iY)
    :x(iX), y(iY)
  {}

  internal_2(const internal_2 & iCopy)
  {
    memcpy(s, iCopy.s, 2 * sizeof(T));
  }

  internal_2 & operator=(const internal_2 & iCopy)
  {
    memcpy(s, iCopy.s, 2 * sizeof(T));
    return *this;
  }

};

template<typename T, int Alignment>
struct internal_4 : _aligned<Alignment>
{
  union
  {
    T s[4];
    struct { T x, y, z, w; };
  };

  internal_4()
  {}

  internal_4(const T & iX, const T & iY, const T & iZ, const T & iW)
    :x(iX), y(iY), z(iZ), w(iW)
  {}

  //For 3 components types
  internal_4(const T & iX, const T & iY, const T & iZ)
    :x(iX), y(iY), z(iZ), w(T(0))
  {}


  internal_4(const internal_4 & iCopy)
  {
    memcpy(s, iCopy.s, 4 * sizeof(T));
  }

  internal_4 & operator=(const internal_4 & iCopy)
  {
    memcpy(s, iCopy.s, 4 * sizeof(T));
    return *this;
  }

};

template<typename T, int Alignment>
struct internal_8 : _aligned<Alignment>
{
  union
  {
    T s[8];
    struct { T x, y, z, w; };
  };

  internal_8()
  {}

  internal_8(const T & iX, const T & iY, const T & iZ, const T & iW, const T & iSpacer4, const T & iSpacer5, const T & iSpacer6, const T & iSpacer7)
    :x(iX), y(iY), z(iZ), w(iW)
  {
    s[4] = iSpacer4;
    s[5] = iSpacer5; 
    s[6] = iSpacer6;
    s[7] = iSpacer7;
  }

  internal_8(const internal_8 & iCopy)
  {
    memcpy(s, iCopy.s, 8 * sizeof(T));
  }

  internal_8 & operator=(const internal_8 & iCopy)
  {
    memcpy(s, iCopy.s, 8 * sizeof(T));
    return *this;
  }

};

template<typename T, int Alignment>
struct internal_16 : _aligned<Alignment>
{
  union
  {
    T s[16];
    struct { T x, y, z, w, __spacer4, __spacer5, __spacer6, __spacer7, __spacer8, __spacer9, sa, sb, sc, sd, se, sf; };
  };

  internal_16()
  {}

  internal_16(const T & iX, const T & iY, const T & iZ, const T & iW, const T & iSpacer4, 
             const T & iSpacer5, const T & iSpacer6, const T & iSpacer7, const T & iSpacer8, const T & iSpacer9,
             const T & iSa, const T & iSb, const T & iSc, const T & iSd, const T & iSe, const T & iSf)
    :x(iX), y(iY), z(iZ), w(iW), __spacer4(iSpacer4), __spacer5(iSpacer5), __spacer6(iSpacer6), 
     __spacer7(iSpacer7), __spacer8(iSpacer8), __spacer9(iSpacer9), 
     sa(iSa), sb(iSb), sc(iSc), sd(iSd), se(iSe), sf(iSf)
  {}


  internal_16(const internal_16 & iCopy)
  {
    memcpy(s, iCopy.s, 16 * sizeof(T));
  }

  internal_16 & operator=(const internal_16 & iCopy)
  {
    memcpy(s, iCopy.s, 16 * sizeof(T));
    return *this;
  }

};



typedef internal_1<gpgpu_char,  1>    internal_char1;
typedef internal_1<gpgpu_uchar, 1>    internal_uchar1;
typedef internal_2<gpgpu_char,  2>    internal_char2;
typedef internal_2<gpgpu_uchar, 2>    internal_uchar2;
typedef internal_4<gpgpu_char,  4>    internal_char4;
typedef internal_4<gpgpu_uchar, 4>    internal_uchar4;
typedef internal_char4                internal_char3; //D'apres la spec OpenCL
typedef internal_uchar4               internal_uchar3;
typedef internal_8<gpgpu_char,  8>    internal_char8;
typedef internal_8<gpgpu_uchar, 8>    internal_uchar8;
typedef internal_16<gpgpu_char,  16>  internal_char16;
typedef internal_16<gpgpu_uchar, 16>  internal_uchar16;

typedef internal_1<gpgpu_short,  2>    internal_short1;
typedef internal_1<gpgpu_ushort, 2>    internal_ushort1;
typedef internal_2<gpgpu_short,  4>    internal_short2;
typedef internal_2<gpgpu_ushort, 4>    internal_ushort2;
typedef internal_4<gpgpu_short,  8>    internal_short4;
typedef internal_4<gpgpu_ushort, 8>    internal_ushort4;
typedef internal_short4                internal_short3; //D'apres la spec OpenCL
typedef internal_ushort4               internal_ushort3;
typedef internal_8<gpgpu_short,  16>   internal_short8;
typedef internal_8<gpgpu_ushort, 16>   internal_ushort8;
typedef internal_16<gpgpu_short,  32>  internal_short16;
typedef internal_16<gpgpu_ushort, 32>  internal_ushort16;

typedef internal_1<gpgpu_int,  4>     internal_int1;
typedef internal_1<gpgpu_uint, 4>     internal_uint1;
typedef internal_2<gpgpu_int,  8>     internal_int2;
typedef internal_2<gpgpu_uint, 8>     internal_uint2;
typedef internal_4<gpgpu_int,  16>    internal_int4;
typedef internal_4<gpgpu_uint, 16>    internal_uint4;
typedef internal_int4                 internal_int3; //D'apres la spec OpenCL
typedef internal_uint4                internal_uint3;
typedef internal_8<gpgpu_int,  32>    internal_int8;
typedef internal_8<gpgpu_uint, 32>    internal_uint8;
typedef internal_16<gpgpu_int,  64>   internal_int16;
typedef internal_16<gpgpu_uint, 64>   internal_uint16;

typedef internal_1<gpgpu_float,  4>    internal_float1;
typedef internal_2<gpgpu_float,  8>    internal_float2;
typedef internal_4<gpgpu_float,  16>   internal_float4;
typedef internal_float4                internal_float3; //D'apres la spec OpenCL
typedef internal_8<gpgpu_float,  32>   internal_float8;
typedef internal_16<gpgpu_float, 64>  internal_float16;

typedef internal_1<gpgpu_double,  8>    internal_double1;
typedef internal_2<gpgpu_double,  16>    internal_double2;
typedef internal_4<gpgpu_double,  32>   internal_double4;
typedef internal_double4                internal_double3; //D'apres la spec OpenCL
typedef internal_8<gpgpu_double,  64>   internal_double8;
typedef internal_16<gpgpu_double, 128>  internal_double16;


// Pas de long pour le moment car la taille est differente entre OpenCL et Cuda
// typedef internal_1<gpgpu_long,  2>    internal_long1;
// typedef internal_1<gpgpu_ulong, 2>    internal_ulong1;
// typedef internal_2<gpgpu_long,  4>    internal_long2;
// typedef internal_2<gpgpu_ulong, 4>    internal_ulong2;
// typedef internal_4<gpgpu_long,  8>    internal_long4;
// typedef internal_4<gpgpu_ulong, 8>    internal_ulong4;
// typedef internal_long4                internal_long3; //D'apres la spec OpenCL
// typedef internal_ulong4               internal_ulong3;
// typedef internal_8<gpgpu_long,  16>   internal_long8;
// typedef internal_8<gpgpu_ulong, 16>   internal_ulong8;
// typedef internal_16<gpgpu_long,  32>  internal_long16;
// typedef internal_16<gpgpu_ulong, 32>  internal_ulong16;



//Vector types

typedef internal_char1       gpgpu_char1;
typedef internal_uchar1      gpgpu_uchar1;
typedef internal_char2       gpgpu_char2;
typedef internal_uchar2      gpgpu_uchar2;
typedef internal_char3       gpgpu_char3;
typedef internal_uchar3      gpgpu_uchar3;
typedef internal_char4       gpgpu_char4;
typedef internal_uchar4      gpgpu_uchar4;
typedef internal_char8       gpgpu_char8;
typedef internal_uchar8      gpgpu_uchar8;
typedef internal_char16      gpgpu_char16;
typedef internal_uchar16     gpgpu_uchar16;

typedef internal_short1      gpgpu_short1;
typedef internal_ushort1     gpgpu_ushort1;
typedef internal_short2      gpgpu_short2;
typedef internal_ushort2     gpgpu_ushort2;
typedef internal_short3      gpgpu_short3;
typedef internal_ushort3     gpgpu_ushort3;
typedef internal_short4      gpgpu_short4;
typedef internal_ushort4     gpgpu_ushort4;
typedef internal_short8      gpgpu_short8;
typedef internal_ushort8     gpgpu_ushort8;
typedef internal_short16     gpgpu_short16;
typedef internal_ushort16    gpgpu_ushort16;


typedef internal_int1      gpgpu_int1;
typedef internal_uint1     gpgpu_uint1;
typedef internal_int2      gpgpu_int2;
typedef internal_uint2     gpgpu_uint2;
typedef internal_int3      gpgpu_int3;
typedef internal_uint3     gpgpu_uint3;
typedef internal_int4      gpgpu_int4;
typedef internal_uint4     gpgpu_uint4;
typedef internal_int8      gpgpu_int8;
typedef internal_uint8     gpgpu_uint8;
typedef internal_int16     gpgpu_int16;
typedef internal_uint16    gpgpu_uint16;

typedef internal_float1      gpgpu_float1;
typedef internal_float2      gpgpu_float2;
typedef internal_float3      gpgpu_float3;
typedef internal_float4      gpgpu_float4;
typedef internal_float8      gpgpu_float8;
typedef internal_float16     gpgpu_float16;

typedef internal_double1      gpgpu_double1;
typedef internal_double2      gpgpu_double2;
typedef internal_double3      gpgpu_double3;
typedef internal_double4      gpgpu_double4;
typedef internal_double8      gpgpu_double8;
typedef internal_double16     gpgpu_double16;



// typedef internal_long1      gpgpu_long1;
// typedef internal_ulong1     gpgpu_ulong1;
// typedef internal_long2      gpgpu_long2;
// typedef internal_ulong2     gpgpu_ulong2;
// typedef internal_long3      gpgpu_long3;
// typedef internal_ulong3     gpgpu_ulong3;
// typedef internal_long4      gpgpu_long4;
// typedef internal_ulong4     gpgpu_ulong4;
// typedef internal_long8      gpgpu_long8;
// typedef internal_ulong8     gpgpu_ulong8;
// typedef internal_long16     gpgpu_long16;
// typedef internal_ulong16    gpgpu_ulong16;


/*
typedef internal_longlong1   gpgpu_longlong1;
typedef internal_ulonglong1  gpgpu_ulonglong1;
typedef internal_longlong2   gpgpu_longlong2;
typedef internal_ulonglong2  gpgpu_ulonglong2;
typedef internal_longlong3   gpgpu_longlong3;
typedef internal_ulonglong3  gpgpu_ulonglong3;
typedef internal_longlong4   gpgpu_longlong4;
typedef internal_ulonglong4  gpgpu_ulonglong4;
typedef internal_double1     gpgpu_double1;
typedef internal_double2     gpgpu_double2;
typedef internal_double3     gpgpu_double3;
typedef internal_double4     gpgpu_double4;*/






#endif //VISGPGPUTYPES_H_
