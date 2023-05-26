/* -*-c++-*- */
//=============================================================================
//
//   sequence_octet : 
// direct implementation of this very often used type of sequence 
//
//=============================================================================

#ifndef sequence_octet_h
#define sequence_octet_h

// COPYRIGHT DASSAULT SYSTEMES 1999
/**
 * @CAA2Required
 */

#include "CATOmx.h"
#include "CATOmxCAAPortability.h" // Avoid cross platform typical build errors.
#include "sequence.h"

/**
* Class to define a sequence of octets.
*/

class ExportedByCATOmxKernel _SEQUENCE_octet : public sequence
{
public:
	/**
	* Constructs an empty sequence of octets.
	*/
  _SEQUENCE_octet();
  /**
	* Constructs an empty sequence of octets .
	* @param iMax
	*       sequence max size 
	*/
  _SEQUENCE_octet( CATLONG32 iMax);
   /**
	* Constructs an sequence of octets from a data.
	* @param iMax
	*       sequence max size 
	*/
  _SEQUENCE_octet( CATLONG32 iMax, const void* data);
 	/**
	* Copy Constructor.
	* @param iFrom
	*        sequence to copy.
	*/
  _SEQUENCE_octet( const _SEQUENCE_octet& iFrom);
  ~_SEQUENCE_octet();

    /**
     * Assignment operator.
     * @param iFrom
	 *   The sequence to assign to the current one
	 * @return 
	 *   The sequence of octet resulting from the assignment
	 */
  _SEQUENCE_octet& operator= ( const _SEQUENCE_octet& iFrom);
	/**
	* Gets sequence's size.
	*/
  CATLONG32 length() const;
	/**
	* Modifies sequence length if iNewLength is smaller than max.
	*/
  CATLONG32 length( CATLONG32 newLength);
	/**
	* Gets sequence's max size.
	*/
  CATLONG32 max() const;
	/**
	* Modifies max length of a sequence.
	*/
  CATLONG32 max( CATLONG32 newMax);
  	/**
	* Subscripting operator.	
    */
  octet& operator[] ( CATLONG32 i);
	/**
	* Subscripting operator.	
    */
  const octet& operator [] (CATLONG32 i) const;

   /**
	* @nodoc 
	* return 1 if sequence are identical otherwise 0 (as for == operator).	
    */
  int compare(const _SEQUENCE_octet&) const ;

  /** @nodoc */
  int operator== (const _SEQUENCE_octet&) const ;
  
  /** @nodoc */
  int operator!= (const _SEQUENCE_octet&) const ;
 
};



#endif


