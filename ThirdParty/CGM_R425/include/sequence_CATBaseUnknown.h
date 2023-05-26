/* -*-c++-*- */
#ifndef sequence_CATBaseUnknown_ptr_h
#define sequence_CATBaseUnknown_ptr_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
  * @CAA2Required
  *              
  */

#include  "CATOMY.h"
#include "CATBaseUnknown.h"
#include "CATLISTP_CATBaseUnknown.h"

// sequences 
#include "sequence_internal.h"


/**
* Class to define sequence of CATBaseUnknown_ptr.
*/

class ExportedByCATOMY _SEQUENCE_CATBaseUnknown_ptr : public sequence 
{ 
public:
	/**
	* Constructs an empty sequence of CATBaseUnknown_ptr.
	*/
  _SEQUENCE_CATBaseUnknown_ptr ();
  virtual ~_SEQUENCE_CATBaseUnknown_ptr ();
  /**
  * Constructs an empty sequence of CATBaseUnknown_ptr of a given size.
  * @param iMax
  *        size of the sequence.
  */
  _SEQUENCE_CATBaseUnknown_ptr (CATLONG32 iMax);
  /**
  * Constructs a sequence of CATBaseUnknown_ptr of a given size from a data .
  * @param iMax
  *        size of the sequence
  * @param iData
  *        the data to sequence 
  */
  _SEQUENCE_CATBaseUnknown_ptr (CATLONG32 iMax, void* iData);
  /**
  * Initializes a sequence of CATBaseUnknown_ptr of a given size with a given first element.
  * @param iMax
  *        size of the sequence
  * @param iFirstItem
  *        first item of the data to sequence 
  */
  _SEQUENCE_CATBaseUnknown_ptr (CATLONG32 iMax, CATBaseUnknown_ptr iFirstItem ...);
	/**
	* Copy Constructor.
	* @param iFrom
	*        sequence to copy.
	*/
  _SEQUENCE_CATBaseUnknown_ptr (const _SEQUENCE_CATBaseUnknown_ptr& iFrom);
 /**
  * Assignment operator.
  * @param iFrom
  *   the sequence to assign to the current one
  */
  _SEQUENCE_CATBaseUnknown_ptr& operator= (const _SEQUENCE_CATBaseUnknown_ptr& iFrom);

  /** @nodoc */
  CATLONG32 length() const { return length_ ; } 
  /** @nodoc */
  CATLONG32 length(CATLONG32 newLength) { return sequence::length(newLength) ; } 
  /** @nodoc */
  CATLONG32 max() const { return max_ ; } 
   /** @nodoc */
 CATLONG32 max(CATLONG32 newMax) { return sequence::max (newMax, sizeof(CATBaseUnknown_ptr)) ; }

	/**
	* Subscripting operator.
	* @param i
	*        access to element i of the sequence.
    */
  CATBaseUnknown_ptr& operator [] (CATLONG32 i);
	/**
	* Subscripting operator.	
	* @param i
	*        access to element i of the sequence.
    */
  const CATBaseUnknown_ptr& operator [] (CATLONG32 i) const;

  /** Initialize the sequence from a CATList. This is not a concatenation. If the sequence was containing elements, it's flushed before AssignFrom.
   *  - The CATList is flushed, it's empty after AssignTo
   *  - the members of the sequence are addrefed pointers (as long as the members of the input CATList were adderefed, as they should have been...) 
   *
   * @param ioList: The CATList of pointer that the sequence is assign from. It's flushed and empty at completion of the operation 
   */
  void AssignFrom(CATListPtrCATBaseUnknown& ioList);

  /** Convert the sequence into a CATList. This is not a concatenation. If the CATList was containing elements, it's flushed before ConvertTo.
   *  - The sequence is flushed, it's empty after ConvertTo
   *  - the members of the CATList are addrefed pointers (as long as the member of the Sequence were adderefed, as they should have been...) 
   * 
   * @param oList: The CATList of pointer that the sequence is converted to. 
  */
  void ConvertTo (CATListPtrCATBaseUnknown& oList);
};

#endif


