//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022
//===================================================================
// Creation    : December 2022
// Responsible : QF2
// ==================================================================

#ifndef CATGMBinary_H
#define CATGMBinary_H

#include "CATMathematics.h"
#include "CATCGMVirtual.h"
#include "DSYGMSharedPtr.h"
#include "CATGMDeallocator.h"
#include "CATSysBoolean.h"


class CATGMBinaryImpl;


//======================================================================================
// Class CATGMBinary
// -------------------------------------------------------------------------------------
// Represents a binary raw data, preserve its size and manage its lifecycle.
// 
// - Behave as a shared smart pointer and does *not* duplicate the data.
//   The owned data cannot be modified. This object has been made for carrying binaries
//   through the c++ stack layers - in a single process.
//   tip: Use CATMathStream to create/edit your data. Then, carry them with CATGMBinary.
//        @see CATMathStreamImpl :: GetBinaryCopy()
// 
// - CATGMBinary is open to every one in CGM or DS. 
// 
// - It can be use on AIX/Linux and Windows OS <+> V5 or 3DExp.
// 
// -------------------------------------------------------------------------------------
// Why to use *Unsigned Char* for binary data ? (from StackOverFlow) 
//  -> In C the unsigned char data type is the only data type that has all 
//     the following three properties simultaneously:
//     1. It has no padding bits, that it where all storage bits contribute to the 
//        value of the data.
//     2. No bitwise operation starting from a value of that type, when converted back 
//        into that type, can produce overflow, trap representations or undefined behavior.
//     3. It may alias other data types without violating the "aliasing rules", 
//        that is that access to the same data through a pointer that is 
//        typed differently will be guaranteed to see all modifications.
//
// tip: use reinterpret_cast<T> to convert char* into unsigned char * if necessary.
//======================================================================================
class ExportedByCATMathematics CATGMBinary : public CATCGMVirtual 
{
public:
  /**
  *  Create an empty binary.
  */
  CATGMBinary();
  /*  Destructor */
  virtual ~CATGMBinary();

  CATCGMNewClassArrayDeclare;

  /**
   * CATGMBinary Main Constructor,
   * You have to allocate the data.
   * The deallocator will be called when the CATGMBinary can safely be deleted.
   * CATGMBinary takes ownership of the data (*do not* write/delete it after CATGMBinary is created and before the deallocator is called).
   */
  CATGMBinary(const unsigned char * iData, const size_t iSize, CGM::Deallocator iDeallocFunct); 

  /* Copy Constructor - This does NOT perform any memory copy, but act as smart pointer. */
  CATGMBinary(const CATGMBinary & rhs);
  
 /** Operators = 
  *  This does NOT perform any memory copy, but act as smart pointer.
  */
  CATGMBinary & operator = (const CATGMBinary & rhs);  


#if __cplusplus >= 201103L // if C++11
  /* Move Constructor */
  CATGMBinary(CATGMBinary && rhs);
  /* Move operator = */
  CATGMBinary & operator = (CATGMBinary && rhs);
#endif


public:

  /**
   * Access (const) to the raw data and size (thread-safe as the message is immutable)
   */
  const unsigned char * Data()  const;
  size_t                Size()  const;

  CATBoolean            Empty() const;

 /** 
  *  - Duplication -
  *  Memory is allocated and <tt>this</tt> binary is fully copied into it.
  */
  CATGMBinary     Duplicate(CGM::Deallocator iDeallocFunct = CGM::DeallocateData ) const;
 /* You are responsible for deleting the returned allocated char data. 
  * Nb: returns null if <tt>this</tt> binary is empty. */  
  unsigned char * Duplicate(size_t & oArraySize) const;

 /** 
  *  - Comparison -
  *  Const methods, the data to be compared will remain intact. 
  */
  CATBoolean      IsEqual(const void * idata,  const size_t iSize) const;

  bool operator ==(const CATGMBinary & rhs) const;
  bool operator !=(const CATGMBinary & rhs) const;


private:
  // Internal Data
  size_t                _size; // redondancy for debug

  DSYGMSharedPtr<CATGMBinaryImpl>  _impl;
};


#endif /*CATGMBinary_H*/
