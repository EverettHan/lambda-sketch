
/**
 * @level Private
 * @usage U1
 */

/* DataModelerPrivate.h : COPYRIGHT DASSAULT SYSTEMES 1995 */
// OGM on Nov 28th, 2011
//   Due to some manipulation on pointers in CATIAModelMemory, MemoryCheck tool in unable to identify that memory is correctly managed.
//   In case of broken ODT, some non relevant MLKs are identified. To help MemoryCheck, I will keep real address on dedicated pointers.
//   Those pointers have no functional use, it's only for MemoryCheck.
#ifndef DataModelerPrivate_h
#define DataModelerPrivate_h

   /*-------------------------------------------*/
   /* Declaration Juste par necessite de typage */
   /*-------------------------------------------*/

union  Pindex { struct INDEX  *bloc; double *array; };
union  Pdata  { struct DATA   *bloc; double *array; };

struct MODEL {
    union  Pindex  ind;
    struct JELE   *jel;
    union  Pdata   dat;
    struct MDL    *mdl;
    struct GES    *ges;
    struct TOLER  *tol;
    struct MODEL  *modelprec;
    void          *realIndexPtr ;
    void          *realJelePtr ;
    void          *realDataPtr ;
 };


#endif
