// COPYRIGHT DASSAULT SYSTEMES 2001

/*
 * TPA : 07/2001
 *
 * This file generate function prototypes for
 * HeapSort. SORT_TYPE can be void*, int or float.
 *
 * To use this function, put this in your code :
 *    #define SORT_TYPE int
 *    #include CATVisHeapSort
 *    #undef SORT_TYPE
 */


#include "SGInfra.h"


#ifndef CATVisHeapSort_H
#define CATVisHeapSort_H
/** @nodoc */
ExportedBySGInfra extern int _CATVisUseQuickSort;
#endif


#ifdef SORT_TYPE


/*
 * This method perform a traditionnal Heap Sort on the array iArray.
 * The cost is even in the worst case n*log(n). Which is interesting
 * for already sorted array. The tests between two elements are done
 * with the traditionnal <, >, = functions.
 * @param ioArray
 * Input array to sort. The elements of this array will be sorted within this array, 
 * then the input array will be changed.
 * @param iSize
 * Size of the input array.
 * @param oPos
 * New positions of elements after sorting (allocated by the callee).
 */
 ExportedBySGInfra void CATVisHeapSort(SORT_TYPE* ioArray, int iSize, int *oPos, int initPosWithInputPos = 0);

/*
 * This method perform the same sort than the previous,
 * but you can specify the method you want to use to test elements.
 * @param ioArray
 * Input array to sort. The elements of this array will be sorted within this array, 
 * then the input array will be changed.
 * @param iSize
 * Size of the input array.
 * @param iCompare
 * This method must have the prototype :
 * int (*) (SORT_TYPE& a, SORT_TYPE& b)
 * if it returns 0,  then elements are identical
 * if it returns 1,  then a is bigger than b
 * if it returns -1, then a is smaller than b
 * @param oPos
 * New positions of elements after sorting (allocated by the callee).
 */
 ExportedBySGInfra void CATVisHeapSort(SORT_TYPE* iArray, int iSize, int (*iCompare) (SORT_TYPE& a, SORT_TYPE& b),int *oPos, int initPosWithInputPos = 0);



/*
 * Same thing than above but with an array of vectors of SORT_TYPE
 * @param ioArray
 * Input array of SORT_TYPE vectors.
 * @param iVectorSize
 * Size of the vectors in ioArray.
 * @param iNumberOfVectors
 * Number of vectors.
 * @param oPos
 * New positions of elements after sorting,
 * array of size iNumberOfVectors*iVectorSize (allocated by the callee).
 */
 //ExportedBySGInfra void CATVisHeapSortM(SORT_TYPE* ioArray, int iVectorSize, int iNumberOfVectors, int *oPos, int initPosWithInputPos = 0);



/*
 * Same thing than above but with an array of vectors of SORT_TYPE
 * @param ioArray
 * input array of SORT_TYPE vectors.
 * @param iVectorSize
 * Size of the vectors in ioArray.
 * @param iNumberOfVectors
 * Number of vectors.
 * @param iCompareM
 * This method must have the prototype :
 * int (*) (SORT_TYPE* a, SORT_TYPE* b, size s)
 * if it returns 0,  then verctors are identical
 * if it returns 1,  then a is bigger than b
 * if it returns -1, then a is smaller than b
 * @param oPos
 * New positions of elements after sorting,
 * array of size iNumberOfVectors*iVectorSize (allocated by the callee).
 */
 //ExportedBySGInfra void CATVisHeapSortM(SORT_TYPE* ioArray, int iVectorSize, int iNumberOfVectors, int (*iCompareM) (SORT_TYPE* a, SORT_TYPE* b, int size),int *oPos, int initPosWithInputPos = 0);



/*
 * Same thing than above but with an array of pointers to vectors of SORT_TYPE
 * It is faster than the previous version, because the cost of copying data in
 * memory is avoided. Only the pointers are swapped
 * @param ioArray
 * Input array of pointers to SORT_TYPE vectors.
 * @param iVectorSize
 * Size of the vectors in ioArray.
 * @param iNumberOfVectors
 * Number of vectors.
 * @param oPos
 * New positions of elements after sorting,
 * array of size iNumberOfVectors*iVectorSize (allocated by the callee).
 */
 ExportedBySGInfra void CATVisHeapSortMOpt(SORT_TYPE** ioArray, int iVectorSize, int iNumberOfVectors, int *oPos, int initPosWithInputPos = 0);



/*
 * Same thing than above but with an array of pointers to vectors of SORT_TYPE
 * It is faster than the previous version, because the cost of copying data in
 * memory is avoided. Only the pointers are swapped
 * @param ioArray
 * input array of pointers to SORT_TYPE vectors.
 * @param iVectorSize
 * Size of the vectors in ioArray.
 * @param iNumberOfVectors
 * Number of vectors.
 * @param iCompareM
 * This method must have the prototype :
 * int (*) (SORT_TYPE* a, SORT_TYPE* b, size s)
 * if it returns 0,  then verctors are identical
 * if it returns 1,  then a is bigger than b
 * if it returns -1, then a is smaller than b
 * @param oPos
 * New positions of elements after sorting,
 * array of size iNumberOfVectors*iVectorSize (allocated by the callee).
 */
 ExportedBySGInfra void CATVisHeapSortMOpt(SORT_TYPE** ioArray, int iVectorSize, int iNumberOfVectors, int (*iCompareMOpt) (SORT_TYPE* a, SORT_TYPE* b, int size),int *oPos, int initPosWithInputPos = 0);



#endif
