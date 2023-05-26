#ifndef DSYSysFlag_H
#define DSYSysFlag_H
/************************************************************************/
/* Defines                                                              */
/************************************************************************/
#define DSY_CONST_SYSFLAG(f, i3, i2, i1, i0) \
  static const DSYSysFlag f ((i0), (i1), (i2), (i3))

#define DSY_CONST_IFLAG_TO_SYSFLAG(f, i0) \
  static const DSYSysFlag f ((i0))

/************************************************************************/
/* Global includes                                                      */
/************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <string.h>

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/
#include "JS03TRA.h"
#include "CATDataType.h"
#include "DSYSysCommon.h"

/************************************************************************/
/* Functions prototypes                                                 */
/************************************************************************/

/************************************************************************/
/* Classes declaration                                                  */
/************************************************************************/
//===============================================================
// This class is a dummy implementation of a flag object
//===============================================================
/**
 * @class DSYSysFlag
 * @brief This class permits to inline ((64 * 4) - 1 - 1) = 254 different flags
 *        (0x00 and 0xff are not taken into account)
 */
class ExportedByJS03TRA DSYSysFlag
{
  ///////////////////////////////////////////
  ////// Types/Constants/Struct/Enum ////////
  ///////////////////////////////////////////
protected:

  ///////////////////////////////////////////
  ///////////////// Methods /////////////////
  ///////////////////////////////////////////
public:
  /**
   * Constructor (Default).
   * Construct an instance of DSYSysFlag.
   */
  DSYSysFlag();

  /**
   * Constructor.
   * Construct an instance of DSYSysFlag from several intergers.
   * @param i0
   *    First integer (least significant)
   * @param i1
   *    Second integer
   * @param i2
   *    Third integer
   * @param i3
   *    Fourth integer (most significant)
   */
  DSYSysFlag  ( CATULONG64 i0
              , CATULONG64 i1 = DSYSysUI64PostFix(0)
              , CATULONG64 i2 = DSYSysUI64PostFix(0)
              , CATULONG64 i3 = DSYSysUI64PostFix(0));

  /**
   * Copy constructor.
   * Construct an instance from another DSYSysFlag instance.
   */
  DSYSysFlag(const DSYSysFlag& Src);

  /**
   * Destructor.
   */
  virtual ~DSYSysFlag();

  /**
   * Affectation.
   * Copy an instance of DSYSysFlag.
   */
  DSYSysFlag& operator=(const DSYSysFlag& Src);

  /**
   * Equality.
   * Compare with another instance of DSYSysFlag.
   */
  bool operator==(const DSYSysFlag& Src)const;

  /**
   * Difference.
   * Compare with another instance of DSYSysFlag.
   */
  bool operator!=(const DSYSysFlag& Src)const;

  /**
   * Bitwise AND operator.
   */
  DSYSysFlag operator&(const DSYSysFlag& Src) const;

  /**
   * Bitwise AND operator + affectation.
   */
  DSYSysFlag& operator&=(const DSYSysFlag& Src);

  /**
   * Bitwise OR operator.
   */
  DSYSysFlag operator|(const DSYSysFlag& Src) const;

  /**
   * Bitwise OR operator + affectation.
   */
  DSYSysFlag& operator|=(const DSYSysFlag& Src);

  /**
   * Bitwise NOT operator.
   */
  DSYSysFlag operator~(void) const;

  /**
   * Field accessor.
   * Separately access to each single integer.
   */
  CATULONG64 operator[](unsigned int idx) const;

  /**
   * Type conversion.
   * Test if at least one bit is set to 1 over all the inlined integers.
   */
  operator bool(void) const;

  ///////////////////////////////////////////
  ///////////////// Members /////////////////
  ///////////////////////////////////////////
protected:
  /// Inlined integers.
  CATULONG64 m_LargeBits[4];
};

///
inline
DSYSysFlag::DSYSysFlag()
{
  memset(&m_LargeBits, 0x00, sizeof(m_LargeBits));
}

///
inline
DSYSysFlag::DSYSysFlag  ( CATULONG64 i0
                        , CATULONG64 i1/* = DSYSysUI64PostFix(0) */
                        , CATULONG64 i2/* = DSYSysUI64PostFix(0) */
                        , CATULONG64 i3/* = DSYSysUI64PostFix(0) */)
{
  m_LargeBits[3] = i3;
  m_LargeBits[2] = i2;
  m_LargeBits[1] = i1;
  m_LargeBits[0] = i0;
}

///
inline
DSYSysFlag::DSYSysFlag(const DSYSysFlag& Src)
{
  operator=(Src);
}

///
inline
DSYSysFlag::~DSYSysFlag()
{
}

///
inline DSYSysFlag&
DSYSysFlag::operator=(const DSYSysFlag& Src)
{
  memcpy(&m_LargeBits, &Src.m_LargeBits, sizeof(m_LargeBits));
  return *this;
}

///
inline DSYSysFlag
DSYSysFlag::operator&(const DSYSysFlag& Src) const
{
  return DSYSysFlag ( (m_LargeBits[0] & Src.m_LargeBits[0])
                    , (m_LargeBits[1] & Src.m_LargeBits[1])
                    , (m_LargeBits[2] & Src.m_LargeBits[2])
                    , (m_LargeBits[3] & Src.m_LargeBits[3]));
}

///
inline DSYSysFlag&
DSYSysFlag::operator&=(const DSYSysFlag& Src)
{
  m_LargeBits[3] &= Src.m_LargeBits[3];
  m_LargeBits[2] &= Src.m_LargeBits[2];
  m_LargeBits[1] &= Src.m_LargeBits[1];
  m_LargeBits[0] &= Src.m_LargeBits[0];
  return *this;
}

///
inline bool
DSYSysFlag::operator==(const DSYSysFlag& Src) const
{
  return  (  (m_LargeBits[3] == Src.m_LargeBits[3])
          && (m_LargeBits[2] == Src.m_LargeBits[2])
          && (m_LargeBits[1] == Src.m_LargeBits[1])
          && (m_LargeBits[0] == Src.m_LargeBits[0]));
}

 ///
inline bool
DSYSysFlag::operator!=(const DSYSysFlag& Src) const
{
  return  (  (m_LargeBits[3] != Src.m_LargeBits[3])
          || (m_LargeBits[2] != Src.m_LargeBits[2])
          || (m_LargeBits[1] != Src.m_LargeBits[1])
          || (m_LargeBits[0] != Src.m_LargeBits[0]));
}

///
inline DSYSysFlag
DSYSysFlag::operator|(const DSYSysFlag& Src) const
{
  return DSYSysFlag ( (m_LargeBits[0] | Src.m_LargeBits[0])
                    , (m_LargeBits[1] | Src.m_LargeBits[1])
                    , (m_LargeBits[2] | Src.m_LargeBits[2])
                    , (m_LargeBits[3] | Src.m_LargeBits[3]));
}

///
inline DSYSysFlag&
DSYSysFlag::operator|=(const DSYSysFlag& Src)
{
  m_LargeBits[3] |= Src.m_LargeBits[3];
  m_LargeBits[2] |= Src.m_LargeBits[2];
  m_LargeBits[1] |= Src.m_LargeBits[1];
  m_LargeBits[0] |= Src.m_LargeBits[0];
  return *this;
}

///
inline DSYSysFlag
DSYSysFlag::operator~(void) const
{
  return DSYSysFlag ( ~m_LargeBits[0]
                    , ~m_LargeBits[1]
                    , ~m_LargeBits[2]
                    , ~m_LargeBits[3]);
}

///
inline CATULONG64
DSYSysFlag::operator[](unsigned int idx) const
{
  switch( idx )
  {
  case 3:
  case 2:
  case 1:
  case 0:
    return m_LargeBits[idx];
  default:
    return m_LargeBits[0];
  }
}

///
inline
DSYSysFlag::operator bool(void) const
{
  return  (  (m_LargeBits[3] != 0)
          || (m_LargeBits[2] != 0)
          || (m_LargeBits[1] != 0)
          || (m_LargeBits[0] != 0));
}

/************************************************************************/
/* Functions prototypes                                                 */
/************************************************************************/
/** Special flags */
DSY_CONST_SYSFLAG ( DSYSysFlagNull
                  , DSYSysUI64PostFix(0x0000000000000000)
                  , DSYSysUI64PostFix(0x0000000000000000)
                  , DSYSysUI64PostFix(0x0000000000000000)
                  , DSYSysUI64PostFix(0x0000000000000000));
DSY_CONST_SYSFLAG ( DSYSysFlagFull
                  , DSYSysUI64PostFix(0xffffffffffffffff)
                  , DSYSysUI64PostFix(0xffffffffffffffff)
                  , DSYSysUI64PostFix(0xffffffffffffffff)
                  , DSYSysUI64PostFix(0xffffffffffffffff));

#endif  // DSYSysFlag_H
