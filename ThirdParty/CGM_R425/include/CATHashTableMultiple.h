//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2014 => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
#ifndef  CATHashTableMultiple_h
#define  CATHashTableMultiple_h
// ENOVIA
// Version 1 Release 0
// Copyright DASSAULT SYSTEMES 2006-2016
// *****************************************************************
//
//   Identification :
//   ---------------
//
//      RESPONSIBLE : Jean-Luc MEDIONI
//      FUNCTION    : Reconciliator
//      USE         : CATIA & ENOVIA
//
// *****************************************************************
//
//   Description :
//   ------------
//
//  Define an hash table supporting multiple instance of the same key.
//
// *****************************************************************
//
//   Remarks :
//   ---------
//
//   This class has been created by duplicating first CATHashTable code
//
// ****************************************************************
//
//   Story :
//   -------
//
//   Revision 1.0  March 2006   (JLM) Copy & Modify from System/CATHashTable
//
// ****************************************************************
//
// INSIDE class:
// -------------
//
//
//
// ****************************************************************

//#include "PLMExchangeModel.h"

#include "CATCollec.h"
#include "CATHashCodeCollec.h"
#include "CATListPV.h"

// --- * PLMExchangeModel framework

#include "PLMExchangeModel.h"

/**
  * Class to define a hash table.
  * <b>Role</b>:The class collection you will obtain will gain benefits of C++
  * strong type checking, but its designed to reduce executable code size and
  * to fasten heavily used operations. This table is not ordered and contains
  * duplicate elements, but no null elements. 
  * <br>It is up to you to provide the dimension, the hash-code function and the
  * compare function for each instance of hash table. Only the underlying 
  * infrastructure is offered. 
  */
//class ExportedByPLMExchangeModel CATHashTableMultiple : public CATHashCodeCollec
class ExportedByPLMExchangeModel CATHashTableMultiple : public CATHashCodeCollec
{
   public :

    /**
      * Constructs an empty hash table.
      * <br><b>Role</b>:Constructs an empty hash table of dimension iDimension.
      * <br>The hash table contains X buckets, X is defined from iDimension. An item
      * is inserted in a bucked according to its key hash value. 
      * A bucket can contain several items with not the same key.
      * @param iPFH
      *  Pointer on a global hashing function. This function must returned a
      *  key of each element of the table.
      * @param iPFC
      *  Pointer on a global comparison function. This function must return 0
      *  if both instance of the table are equal.
      * @param iDimension
      *  Helps specifying the number of bucket (cells receiving 0 to N items) and
      *  this number will not vary up to the destruction of the hash table.
      *  <br><b>Default value</b>: 29
      */
      CATHashTableMultiple( CATCollec::PFHash iPFH , CATCollec::PFCompare iPFC , int iDimension = 29 ) ;

    /**
      * Constructs a new hash table from an another one.
      * <br><b>Role</b>: This new table as same characteristics and
      * contents is copied.
      * @param iCopy
      * The hash table to duplicate
      */
      CATHashTableMultiple( const CATHashTableMultiple& iCopy ) ;

    /**
      * Destructor.
      * <br><b>Role</b>: Destructor.
      */
      virtual ~CATHashTableMultiple() ;

    /**@nodoc 
      */
      CATHashTableMultiple& operator = ( const CATHashTableMultiple& iCopy );

    /**
      * Inserts an item in the hash table.
      * <br><b>Role</b>:Inserts an item according to its key in the table. The key
      * is computed with the provided hash-code function with iAdd as argument.
      * @param iAdd
      *  Item to insert 
      * @return
      * If the key already exists, nothing is inserted and 0 is returned else iAdd is
      * inserted in a bucket and 1 is returned.
      */
      int Insert( void* iAdd ) ;

    /**
      * Returns the number of bucket in the hash table.
      * <br><b>Role</b>:This number is also the maximum number of items without
      * collisions.
      */
      int Dimension() const { return _Dimension ; }

    /**
      * Returns the count of item in the hash table..
      */
      int Size() const { return _Size ; }

    /**
      * Returns the count of item not directly accessible in a hash table.
      * <br><b>Role</b>: Item directly accessible are those at the first position 
      * in a bucket.
      */
      int Collisions() const  { int collisions = _Size - (_Dimension-_Unused); return collisions ; }

    /**
      * Returns the count of unused buckets in an hash table.
      */
      int Unused() const { return _Unused ; }

    /**@nodoc
      */
      void PrintStats() const ;

    /**
      * Returns the first item from a key corresponding to an another item.
      * @param iLocate
      *  The element to find in the table.
      * @param oBucket
      *  The bucket of the returned item
      * @param oPosition
      *  The position in the bucket of the returned item
      * @return 
      * The item having a key corresponding to iLocate key's or NULL if not found.
      * If iLocate is null, we return the first bucket in the hash-list.
      */
      void* LocatePosition( void * iLocate , int& oBucket , int& oPosition ) const ;

    /**
      * Returns next item from a key corresponding to an another item.
      * @param iLocate
      *  The element to find in the table.
      * @param ioBucket
      *  The bucket of the returned item
      * @param ioPosition
      *  The position in the bucket of the returned item
      * @return 
      * The item having a key corresponding to iLocate key's or NULL if not found.
      */
      void * NextPosition( void * iLocate , int& ioBucket , int& ioPosition ) const ;

    /**
      * Retrieves an item from its Bucket and Position in a hash table.
      * @param iBucket
      * The bucket of the returned item
      * @param iPosition
      * The position in the bucket of the returned item
      * @return 
      * Returns the item having position descibed by the couple of integer (iBucket,iPosition) 
      */
      void * Retrieve( int iBucket, int iPosition ) const ;

    /**
      * Returns the next item given a position in a hash table.
      * <br><b>Role</b>:Iterator of the hash table. To start a loop on all items set 
      * ioBucket to 1 and ioPosition to 0. If the returned value is NULL, you have reached 
      * the end of the table.
      * @param ioBucket
      * The bucket used to find the next item
      * @param ioPosition
      * The position in the  ioBucket used to find the next item
      * @return 
      * The next item next to the given position (iBucket, iPosition).
      */
      void * NextItem( int&  ioBucket, int& ioPosition ) const ;

    /**
      * Removes an item in the hash table.
      * @param iRemove
      * The element to remove
      * @return 
      *  The element removed or NULL if not exists
      */
      void * Remove( void* iRemove ) ;

    /**
      * Removes an item in the hash table.
      * @return 
      *  The element removed or NULL if not exists
      */
      void * RemovePosition( int iBucket , int iPosition ) ;

    /**
      * Removes all elements in the hash table.
      */
      void RemoveAll() ;

   // -----------------------
   // --- DATA MEMBERS    ---
   // -----------------------

   private :
    /** Function to compute Hash key. */
      CATCollec::PFHash        _PFH ;

    /** Function to compare two objects.*/
      CATCollec::PFCompare     _PFC ;

    /** List of buckets (i.e. list of pointers to lists of void pointers). */
      void**                   _Lbuckets ;

    /** List of flags on buckets (0:no item / 1:one item alone / 2:list of items). */
      unsigned char*           _Lflags ;

    /** Number of buckets inside the table. */
      int                      _Dimension ;

    /** Number of items inside the table. */
      int                      _Size ;

    /** Number of unused buckets. */
      int                      _Unused ;
} ;
#endif
 
