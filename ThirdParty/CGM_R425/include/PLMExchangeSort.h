//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2015x => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
#ifndef PLMExchangeSort_h
#define PLMExchangeSort_h
// COPYRIGHT DASSAULT SYSTEMES 2015
// *****************************************************************
//
//   Identification :
//   ---------------
//
//      RESPONSIBLE : Jean-Luc MEDIONI
//      FUNCTION    : Exchange Experience 
//      USE         : ENOVIA
//
// *****************************************************************
//
//   Description :
//   ------------
//
//    Class implementing sort services based on Heapsort algoritm.
//
// *****************************************************************
//
//   Remarks :
//   ---------
//
//    Implemented to replace QuickSort when we are in case where QuickSort performance are in o(N*N).
//
/**
  * @level Private
  * @usage U1
  */
//
// ****************************************************************
//
//   Story :
//   -------
//
//   Revision 1.0  July 2015           Author:  Jean-Luc MEDIONI  Objects: Initial Revision based on a disaster case for 3DXML Export
//
// ****************************************************************

// -- PLMExchangeServices
#include "PLMExchangeGlobalServices.h"

// -- System & SpecialAPI
#include "CATSysErrorDef.h"
#include "CATTrace.h"
#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATListOfInt.h"

class CATBaseUnknown             ;
class CATBinary                  ;
class CATTime                    ;
class CATDbBinary                ;
class CATPLMID                   ;
class CATIPLMComponent           ;
class CATListPtrCATIPLMComponent ;
class CATListValCATPLMID         ;
class CATLISTV_CATPLMID          ;

/**
  * Class exposing Heap sort method.
  * <b>role</b>: Sort method enabling to sort array of values or pointer based on HeapSort algorithm to replace qsort when he is in o(N*N).
  */
class ExportedByPLMExchangeGlobalServices PLMExchangeSort
{
   public:

    /**
      * Sort an array of pointers.
      *
      * <br><b>Role</b>: Enable to sort in ascendant mode an array of pointer based on HeapSort (in o[n.log(n)]).
      *
      * @param ixRecordArray [in]
      * Pointer to the first element of the array to be sorted.
      *
      * @param inMaxRecord [in]
      * Number of elements in the array pointed by base.
      *
      * @param inRecordSize [in]
      * Size in bytes of each element in the array.
      *
      * @param functionCompare [in]
      * Function that compares two elements.
      * <p>Taking two pointers as arguments (both converted to const void*), the function defines the order of the elements 
      * by returning (in a stable and transitive manner):</p>
      * <dl>
      * <dt>negative value</dt>  <dd>The element pointed to at first place goes before the element pointed at second place.</dd>
      * <dt>null</dt>            <dd>The two elements are equivalent.</dd>
      * <dt>positive value</dt>  <dd>The element pointed to at first place goes after the element pointed at second place.</dd>
      * <dl>
      *
      * @return
      * This function does not return any value.
      */
      static void HeapSort( void ** ixRecordArray , int inMaxRecord , int (*functionCompare)(const void*, const void*) ) ;

    /**
      * Sort an array of records.
      *
      * <br><b>Role</b>: Enable to sort in ascendant mode an array of records based on HeapSort (in o[n.log(n)]).
      *
      * @param ixRecordArray [in]
      * Pointer to the first element of the array to be sorted.
      *
      * @param inMaxRecord [in]
      * Number of elements in the array pointed by base.
      *
      * @param inRecordSize [in]
      * Size in bytes of each element in the array.
      *
      * @param functionCompare [in]
      * Function that compares two elements.
      * <p>Taking two pointers as arguments (both converted to const void*), the function defines the order of the elements 
      * by returning (in a stable and transitive manner):</p>
      * <dl>
      * <dt>negative value</dt>  <dd>The element pointed to at first place goes before the element pointed at second place.</dd>
      * <dt>null</dt>            <dd>The two elements are equivalent.</dd>
      * <dt>positive value</dt>  <dd>The element pointed to at first place goes after the element pointed at second place.</dd>
      * <dl>
      *
      * @return
      *  Return code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>0</dt>   <dd>Array has been successfully ordered.</dd>
      * <dt>1</dt>   <dd>In valid inputs.</dd>
      * <dt>2</dt>   <dd>Memory allocation issue.</dd>
      * </dl>
      */
      static int HeapSort( void * ixRecordArray , int inMaxRecord , int inRecordSize , int (*functionCompare)(const void*, const void*) ) ;

    /**
      * Sort an array of pointers.
      *
      * <br><b>Role</b>: Enable to sort in ascendant mode an array of pointer based on SmoothSort (in o[n.log(n)]).
      *
      * @param ixRecordArray [in]
      * Pointer to the first element of the array to be sorted.
      *
      * @param inMaxRecord [in]
      * Number of elements in the array pointed by base.
      *
      * @param functionCompare [in]
      * Function that compares two elements.
      * <p>Taking two pointers as arguments (both converted to const void*), the function defines the order of the elements 
      * by returning (in a stable and transitive manner):</p>
      * <dl>
      * <dt>negative value</dt>  <dd>The element pointed to at first place goes before the element pointed at second place.</dd>
      * <dt>null</dt>            <dd>The two elements are equivalent.</dd>
      * <dt>positive value</dt>  <dd>The element pointed to at first place goes after the element pointed at second place.</dd>
      * <dl>
      *
      * @return
      * This function does not return any value.
      */
      static void SmoothSort( void ** ixRecordArray , int inMaxRecord , int (*functionCompare)(const void*, const void*) ) ;

    /**
      * Sort an array of pointers.
      *
      * <br><b>Role</b>: Enable to sort in ascendant mode an array of pointer based on SmoothSort (in o[n.log(n)]).
      *
      * @param ixRecordArray [in]
      * Pointer to the first element of the array to be sorted.
      *
      * @param inMaxRecord [in]
      * Number of elements in the array pointed by base.
      *
      * @param inRecordSize [in]
      * Size in bytes of each element in the array.
      *
      * @param functionCompare [in]
      * Function that compares two elements.
      * <p>Taking two pointers as arguments (both converted to const void*), the function defines the order of the elements 
      * by returning (in a stable and transitive manner):</p>
      * <dl>
      * <dt>negative value</dt>  <dd>The element pointed to at first place goes before the element pointed at second place.</dd>
      * <dt>null</dt>            <dd>The two elements are equivalent.</dd>
      * <dt>positive value</dt>  <dd>The element pointed to at first place goes after the element pointed at second place.</dd>
      * <dl>
      *
      * @return
      * This function does not return any value.
      */
      static int SmoothSort( void * ixRecordArray , int inMaxRecord , int inRecordSize , int (*functionCompare)(const void*, const void*) ) ;

   private :
    /**
      * Re-order sub-tree binary tree in such way that it become an heap (the 2 children are higher than root).
      *
      * <br><b>Role</b>: Enable to re-order array such as selected binary sub-tree becomes an heap (the 2 children are higher than root) with
      * the assumption than sub-trees are already order (all the 2 children are higher than root)
      *
      * @param ixRecordArray [in]
      * Pointer to the first element of the array to be sorted.
      *
      * @param inMaxRecord [in]
      * Number of elements in the array pointed by base.
      *
      * @param inCurrentNode [in]
      * Position of the sub-tree to order as an heap.
      *
      * @param functionCompare [in]
      * Function that compares two elements.
      * <p>Taking two pointers as arguments (both converted to const void*), the function defines the order of the elements 
      * by returning (in a stable and transitive manner):</p>
      * <dl>
      * <dt>negative value</dt>  <dd>The element pointed to at first place goes before the element pointed at second place.</dd>
      * <dt>null</dt>            <dd>The two elements are equivalent.</dd>
      * <dt>positive value</dt>  <dd>The element pointed to at first place goes after the element pointed at second place.</dd>
      * <dl>
      *
      * @return
      * This function does not return any value.
      */
      //static void OrderHeap( void ** ixRecordArray , int inCurrentNode , int inMaxRecord , int (*functionCompare)(const void*, const void*) ) ;
} ;

#endif
 
