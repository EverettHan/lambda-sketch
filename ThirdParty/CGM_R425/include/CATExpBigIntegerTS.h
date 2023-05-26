//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2012-2018
//==============================================================================================================
// Usage notes: (This is a ThreadSafe copy of CATExpBigInteger using an unoptimsed standard allocator
//==============================================================================================================

//==============================================================================================================
// 03/06/2019 : RNO : NOEXCEPT
// 24/05/2018 : RNO : Suppression de l'utilisation d'un allocateur specifique (R420)
// 15/06/2015 - RNO - Version Thread-Safe mais moins rapide en monothread (Poor performance allocator)
// 2012-10-06 - DGA/T6L - Creation
//==============================================================================================================

#ifndef CATExpBigIntegerTS_H
#define CATExpBigIntegerTS_H

#include "CATExpExactArithmetic.h"
#include "CATExpNumericDeclarations.h"
#include "CATExpNumbersOperators.h"

#include <algorithm>
#include <utility>
#include <vector>
#include <tuple>

static const int singleIntWidth = 8 * sizeof(std::uint32_t);

class CATExpFloatRingExtensionTS;

class CATExpBigIntegerTS;
ExportedByCATExpExactArithmetic CATExpBigIntegerTS operator+ (const CATExpBigIntegerTS &big1, const CATExpBigIntegerTS &big2);
ExportedByCATExpExactArithmetic CATExpBigIntegerTS operator- (const CATExpBigIntegerTS &big1, const CATExpBigIntegerTS &big2);



/**
* This class manages arithmetic operations on big integers.
* The limitation of this implementation is the number of recordable integers blocks, which is INT_MAX.
* So the maximum representable number is 2**(32*INT_MAX). If int have 32 bits, this is 2**(32*(2**31-1)) i.e. about 10**20000000000.
* @pre You must define an object of type SmartAllocator before using this class, refering to a huge Array of std::uint32_t you will have allocated, 
* which size is an upper bound on the total number of small integers you will need.
*/

class ExportedByCATExpExactArithmetic CATExpBigIntegerTS
{
public:
  typedef std::vector<std::uint32_t> UIntVector;

  friend CATExpBigIntegerTS::UIntVector OperationCascading 
    (std::uint32_t operation (const std::uint32_t, const std::uint32_t, std::uint32_t &),
    const CATExpBigIntegerTS &big1, const CATExpBigIntegerTS &big2);
  template <bool plus>
  friend CATExpBigIntegerTS Addition (const CATExpBigIntegerTS &big1, const CATExpBigIntegerTS &big2);
  friend CATExpBigIntegerTS::UIntVector MultiplicationCascading(const CATExpBigIntegerTS &big1, const CATExpBigIntegerTS &big2);  
  friend CATExpBigIntegerTS MakeLeftShift(const CATExpBigIntegerTS &big, std::size_t l);
  friend CATExpSign_t compareAbs (const CATExpBigIntegerTS &big1, const CATExpBigIntegerTS &big2);

  friend ExportedByCATExpExactArithmetic CATExpBigIntegerTS operator*
    (const CATExpBigIntegerTS &big1, const CATExpBigIntegerTS &big2);
  friend ExportedByCATExpExactArithmetic CATExpBigIntegerTS operator- (const CATExpBigIntegerTS &big);
  friend inline CATExpBigIntegerTS operator- (CATExpBigIntegerTS &&big)
  {
    CATExpBigIntegerTS result = std::move(big);
    result.sign_ = ! result.sign_;
    return result;
  }

  friend ExportedByCATExpExactArithmetic CATExpFloatRingExtensionTS operator*
    (const CATExpFloatRingExtensionTS &r1, const CATExpFloatRingExtensionTS &r2);

  /**
   * Constructors / Destructor<br>
   */
  
  CATExpBigIntegerTS() noexcept = default;
  ~CATExpBigIntegerTS() = default;
  CATExpBigIntegerTS(const CATExpBigIntegerTS &iOther) = default;
  CATExpBigIntegerTS &operator= (const CATExpBigIntegerTS &iOther) = default;
  CATExpBigIntegerTS(CATExpBigIntegerTS &&iOther) noexcept = default;
  CATExpBigIntegerTS &operator= (CATExpBigIntegerTS &&iOther) noexcept = default;

  explicit CATExpBigIntegerTS (std::int32_t iValue) ;
  CATExpBigIntegerTS (std::uint32_t iValue, CATExpSign_t isign);
  CATExpBigIntegerTS (std::uint32_t iValue1, std::uint32_t iValue2, CATExpSign_t isign);

  void swap (CATExpBigIntegerTS &iOther) noexcept;

  bool IsPositive() const noexcept  { return (sign_ > 0); }
  bool IsNegative() const noexcept { return (sign_ < 0); }
  bool IsZero() const noexcept  { return (sign_ == 0); }
  
  /*
  * @return -1,0,1 if  respectively negative, zero  or positive
  **/
  CATExpSign_t Sign() const noexcept  { return sign_; }

  /**
  * Flips the object's sign.
  */
  void FlipSign() { sign_ = ! sign_; }

  /**
  * Division by 2**(32*l), i.e. right shift of l blocks; modifies the BigInteger in place,
  *   and the exponent of the corresponding FloatExtension as well.
  */
  void SelfRightBlockShift(int blockShifts, int &exponent);
  

  CATExpBigIntegerTS &operator += (const CATExpBigIntegerTS &iOther)
  {
    *this = *this + iOther;
    return *this;
  }

  CATExpBigIntegerTS &operator -= (const CATExpBigIntegerTS &iOther)
  {
    *this = *this - iOther;
    return *this;
  }

  CATExpBigIntegerTS &operator *= (const CATExpBigIntegerTS &iOther)
  {
    *this = *this * iOther;
    return *this;
  }

  /**
  * Returns how many zeros are on the right, -1 if the number is 0.
  * This can be used by FloatRing to discard them thanks to the exponent.
  */
  int NumberOfRightZeros();
  
  std::size_t size() noexcept  { return array_.size(); }

  // return a couple (value,exp) such that the big integer equals (value * 2**exp). 
  std::pair<double, int> ConvertToDouble() const;
  void ConvertToDouble(double &oValue, int &oExponent) const;

  std::pair<double, int> LowerBound() const;
  std::pair<double, int> UpperBound() const;

  void Visu()  const;

//==============================================================================================================
// Private Part.
//==============================================================================================================

private :
  /**
  * Private constructor to optimize memory management, and avoid copy of data
  */
  CATExpBigIntegerTS (const UIntVector &tab, CATExpSign_t sign)
  : array_(tab), sign_(sign) {}
  
  CATExpBigIntegerTS (UIntVector &&tab, CATExpSign_t sign) noexcept
  : array_(std::move(tab)), sign_(sign) {}

	// fields :
  UIntVector array_;
  CATExpSign_t sign_ = CATExpSIGNUNDEF;
};

inline void CATExpBigIntegerTS::ConvertToDouble(double& oValue, int& oExponent) const
{
  std::tie(oValue, oExponent) = ConvertToDouble();
}

inline void swap (CATExpBigIntegerTS &big1, CATExpBigIntegerTS &big2) noexcept
{ big1.swap(big2); }

/**
* Compares 2 BigIntegers.
* 1 : big1 > big2
* -1 : big1 < big2
* 0 : big1 == big2
*/
CATExpSign_t compare(const CATExpBigIntegerTS &big1, const CATExpBigIntegerTS &big2);

/**
* Compares the absolute values of 2 BigIntegers.
* 1 : |big1| > |big2|
* -1 : |big1| < |big2|
* 0 : |big1| == |big2|
*/
CATExpSign_t compareAbs (const CATExpBigIntegerTS &big1, const CATExpBigIntegerTS &big2);
/**
* comparison operators
*/
inline bool operator == (const CATExpBigIntegerTS &big1, const CATExpBigIntegerTS &big2) { return ( compare (big1, big2) == 0); }
inline bool operator != (const CATExpBigIntegerTS &big1, const CATExpBigIntegerTS &big2) { return ( compare (big1, big2) != 0); }
inline bool operator < (const CATExpBigIntegerTS &big1, const CATExpBigIntegerTS &big2) { return (compare (big1, big2) < 0); }
inline bool operator > (const CATExpBigIntegerTS &big1, const CATExpBigIntegerTS &big2) { return (compare (big1, big2) > 0); }

// convert to double the big integer multiplied by 2 ** Exponent. 
double ConvertToDouble( const CATExpBigIntegerTS &big, int Exponent );
#endif



