// COPYRIGHT DASSAULT SYSTEMES 1999


#ifdef SORT_TYPE

/******************************************************************************/
/* Array sorting API:
 * ------------------
 *   This API fulfills the following tasks:
 *     . Sort any type of basic computer data (generic data type),
 *     . Single and multiple dimension sort functions,
 *     . Indexed sorting.
 *   The sort method is a Quick Sort for all functions. Memory is not managed
 *   within these functions. The caller must ensure enough working space is
 *   available (mainly for Add functions).
 */
/******************************************************************************/
/* Inclusion of this header file:
 * ------------------------------
 *   To properly use these functions, just add the following lines to your
 *   source code:
 *
 *     #define SORT_TYPE    float
 *     #include "Sort.h"
 *
 *     #define SORT_TYPE    unsigned char
 *     #include "Sort.h"
 *
 *   The "Sort.h" header file may be included as many times as it is needed,
 *   once per type to sort. The SORT_TYPE macro parameter MUST be defined before
 *   the header file is included. The source code must have been generated once
 *   in a file looking like this:
 *
 *     #define SORT_TYPE   float
 *     #include "Sort.c"
 *
 *   This must be done once per application wishing to use these sort functions.
 */
/******************************************************************************/
/* Functions memory behavior:
 * --------------------------
 *   Sorting functions may add elements to arrays without checking whether the
 *   allocated memory size is big enough or not. User has to ensure that opera-
 *   tions performed by these functions do not write outside allocated zones.
 *   Indexed sorting functions use twice the size of the array in memory for
 *   temporary storage of indices. This memory is freed after use.
 */
/******************************************************************************/
/* Single dimension functions:
 * ---------------------------
 *   - SingleSort: Performs the sort of a single dimension array. If <pos> is
 *     not NULL, it must have the size of <array> and it will be returned with
 *     new elements positions. Example: If i-th element is x, after the sort,
 *     pos[i] is new x position in array, ie array[pos[i]]=x.
 *   - SingleStrip: Finds and removes equal values in the sorted array. Only
 *     adjacent elements are checked, so the array must have been sorted before.
 *     If -tol<=(array[i+1]-array[i])<=tol, array[i+1] is removed. A zero
 *     tolerancy works for non floating parameters. If <pos> is not NULL, the
 *     information it contains is updated and it points on the reduced resulting
 *     array. <array_size> is updated.
 *   - SingleResearch: Try to find the requested element in the sorted array.
 *     Returns the number of the first encountered occurence of that element in
 *     <array> if it exists. Otherwise, the function returns -1.
 */
/******************************************************************************/
/* Multiple dimension functions:
 * -----------------------------
 *   - MultipleSort: Performs a multiple dimension array sort. Array format is:
 *     A1A2A3...AnB1B2B3...Bn where n is the number of dimensions of the array.
 *     <array_size> is the number of sort_type elements, that is the number of
 *     vectors multiplied by the number of dimensions. Indexed sorting with
 *     <pos> works the same as for the previous function.
 *   - MultipleStrip: Finds and removes equal vectors in the sorted array.
 *     Behaves exactly as the single dimension strip function.
 *   - MultipleSearch: Looks for a given vector in the sorted array. Works as
 *     the single dimension search function.
 */
/******************************************************************************/

#include "SGInfra.h"


ExportedBySGInfra void SingleSort (SORT_TYPE *array,          /* Array of SORT_TYPE elements    */
                                            int array_size,            /* SORT_TYPE elements array size  */
                                            int *pos);                 /* New positions of elements      */

ExportedBySGInfra void SingleStrip (SORT_TYPE *array,         /* Sorted array                   */
                                             int *array_size,          /* SORT_TYPE elements array size  */
                                             int *pos,                 /* New positions of elements      */
                                             SORT_TYPE tolerancy);     /* Equality limit                 */

ExportedBySGInfra int SingleSearch (SORT_TYPE *array,         /* Sorted array                   */
                                             int array_size,           /* SORT_TYPE elements array size  */
                                             SORT_TYPE elt,            /* Element to search in the array */
                                             SORT_TYPE tolerancy);     /* Equality limit                 */


ExportedBySGInfra void MultipleSort (SORT_TYPE *array,        /* Array of SORT_TYPE elements    */
                                              int nb_dim,              /* Number of dimensions for array */
                                              int array_size,          /* SORT_TYPE elements array size  */
                                              int *pos);               /* New positions of elements      */

ExportedBySGInfra void MultipleStrip (SORT_TYPE *array,       /* Sorted array                   */
                                               int nb_dim,             /* Number of dimensions for array */
                                               int *array_size,        /* SORT_TYPE elements array size  */
                                               int *pos,               /* New positions of elements      */
                                               SORT_TYPE tolerancy);   /* Equality limit                 */

ExportedBySGInfra int MultipleSearch (SORT_TYPE *array,       /* Sorted array                   */
                                               int nb_dim,             /* Number of dimensions for array */
                                               int array_size,         /* SORT_TYPE elements array size  */
                                               SORT_TYPE *elt,         /* Element to search in the array */
                                               SORT_TYPE tolerancy);   /* Equality limit                 */


/* This is an optimised version of multiple dimension sort       */
/* We use an array of vector instead of using a single array     */
/* It prevents from constantly copying vectors while moving them */
/* !!! Take great care if you move an old code to this call,     */
/* !!! Because the size of the array is the number of vector and */
/* !!! not the global size of the array. Moreover, the positions */
/* !!! array returned has the size of the number of vectors and  */
/* !!! not the global memory size                                */
ExportedBySGInfra void MultipleSortOpt(SORT_TYPE **array,     /* Array of vetcors of SORT_TYPE elements */
                                                int vector_size,       /* Dimension of vectors */
                                                int array_size,        /* Number of vectors */
                                                int *pos);             /* New positions of vectors */
                                                
ExportedBySGInfra void MultipleStripOpt(SORT_TYPE **array,    /* Array of vetcors of SORT_TYPE elements */
                                                int vector_size,       /* Dimension of vectors */
                                                int *array_size,       /* Number of vectors */
                                                int *pos,              /* New positions of vectors */
                                                SORT_TYPE tolerancy);  /* Equality limit */ 


#endif
