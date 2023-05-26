// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATSYPBoxingComparator.h
// Header definition of CATSYPBoxingComparator
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Nov 2011  Creation: qf1
//===================================================================
#ifndef CATSYPBoxingComparator_H
#define CATSYPBoxingComparator_H


template <class Type> struct CATSYPBoxingComparator
{
  /** 
   * Compare two values.
   * Note that if two keys are equal for this function, they must
   * have the same hash code.
   * @param i_key1 the first key
   * @param i_key2 the second key
   * @return !=0 if the key are equal, else 0.
   * @see #ComputeHash
   */
  int AreEqual(const Type &i_value1, const Type &i_value2) {
    return i_value1 == i_value2;
  }
};


#endif
