/* -*-c++-*- */

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Required
 */

#ifndef sequence_internal_h
#define sequence_internal_h

#include <stdarg.h>
#include "CATOmxCAAPortability.h" // Avoid cross platform typical build errors.
#include "CATDataType.h"

/** @nodoc */
#ifndef SEQUENCE
#define SEQUENCE(X) _SEQUENCE_##X
#endif
#ifdef _WINDOWS_SOURCE
#undef max
/**
 * Maximum size of the sequence.
 */
#define max max
#endif

/**
* Class to define sequence.
*/

class ExportedByCATOmxKernel sequence 
{
public:
 /**
 * Constructs an empty sequence.
 */
    sequence () ;

 /**
 * Constructs an empty sequence with a given size of data.
 * @param iMax
 *       sequence max size ( iMax*iItemSize)
 * @param iItemSize
 *       size of items defining the sequence.
 */
    sequence (CATLONG32 iMax, CATLONG32 iItemSize=1) ;

 /**
 * Constructs an sequence of a given size of data from a data.
 * @param iMax
 *       sequence max size ( iMax*iItemSize)
 * @param iItemSize
 *       size of items defining the sequence.
 */
    sequence (CATLONG32 iMax, const void* iData, CATLONG32 iItemSize=1) ;

 /**
 * Copy Constructor.
 * @param iFrom
 *        sequence to copy.
 * @param iItemSize
 *		 size of data to copy.
 */
    sequence (const sequence& iFrom, CATLONG32 iItemSize) ;
    ~sequence () ;

 /**
 * Copies a sequence in this one.
 * @param iFrom
 *        sequence to copy.
 * @param iItemSize
 *		 size of data to copy.
 */
    sequence& copy (const sequence& iFrom, CATLONG32 iItemSize=1) ;
    
 /**
 * Gets sequence's size.
 */
 CATLONG32 length() const ;

 /**
 * Modifies sequence length if iNewLength is smaller than max.
 */
    CATLONG32 length(CATLONG32 iNewLength) ;
 /**
 * Gets sequence's max size.
 */
    CATLONG32 max() const ;

 /**
 * Modifies max length of a sequence.
 */
    CATLONG32 max(CATLONG32 newMax, CATLONG32 itemSize=1) ;
    
protected:
    sequence (const sequence& from) ;
    sequence& operator= (const sequence& from) ;

    void exit (const char* text, 
        int param1=0, int param2=0, int param3=0, int param4=0) const ;
    void bound_error(int index) const;

    void boucle(const void* to_copy,int max);
    virtual void Assignation(const void* to_copy,int index);
    
protected:
    CATLONG32  max_ ;
    CATLONG32  length_ ;
    void*  buffer_ ;
};


//Y is the name of the module which contains the implementation of the sequence
/** @nodoc */
#define DEF_SEQUENCE(X, Y)   						\
 class ExportedBy##Y _SEQUENCE_##X : public sequence 			\
        { \
 public:							 	 \
    _SEQUENCE_##X (); \
    _SEQUENCE_##X (CATLONG32 max);	 \
    _SEQUENCE_##X (CATLONG32 max, const void* data); 		 \
    _SEQUENCE_##X (const _SEQUENCE_##X& from); 	 \
    ~_SEQUENCE_##X (); 							\
    _SEQUENCE_##X& operator= (const _SEQUENCE_##X& from);		\
        CATLONG32 length() const; 						\
    CATLONG32 length(CATLONG32 newLength) ;					\
    CATLONG32 max() const;							\
    CATLONG32 max(CATLONG32 newMax); 						\
    X& operator [] (CATLONG32 i); 						\
    const X& operator [] (CATLONG32 i) const;					\
 };								       

#endif

